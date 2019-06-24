//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprGrafikPlat.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TDMSprGrafikPlat::TDMSprGrafikPlat(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TDMSprGrafikPlat::Init(void)
{
bool result=false;
if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}
IBTr->DefaultDatabase=DM_Connection->pFIBData;
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;


Table->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprGrafikPlat::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprGrafikPlat::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprGrafikPlat::OpenTable(__int64 idDogovor)
{
IdDogovor=idDogovor;
Table->Active=false;
Table->ParamByName("PARAM_IDDOG")->AsInt64=idDogovor;
Table->Open();
}

//---------------------------------------------------------------------------

void  TDMSprGrafikPlat::NewElement(__int64 idDogovor)
{
IdDogovor=idDogovor;
Table->Insert();

}
//---------------------------------------------------------------------------

void  TDMSprGrafikPlat::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenTable(IdDogovor);
        }
catch(Exception &exception)
        {
		  //		IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
        }
}
//---------------------------------------------------------------------------

void  TDMSprGrafikPlat::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
        OpenTable(IdDogovor);
        }
catch(Exception &exception)
        {
				//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
        }
}
//---------------------------------------------------------------------------
void TDMSprGrafikPlat::DeleteElement()
{
Table->Delete();
}
//-----------------------------------------------------------------------------


void __fastcall TDMSprGrafikPlat::TableNewRecord(TDataSet *DataSet)
{
TableIDDOG_SGRPLAT->AsInt64=IdDogovor;

}
//---------------------------------------------------------------------------

