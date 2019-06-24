//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprMod.h"
#include "UGlobalConstant.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprMod::TDMSprMod(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//----------------------------------------------------------------------------
bool TDMSprMod::Init(void)
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
int TDMSprMod::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprMod::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprMod::OpenTable(__int64 Nom)
{
IdNom=Nom;
Table->Active=false;
Table->ParamByName("PARAM_IDNOM")->AsInt64=Nom;
Table->Open();
}

//---------------------------------------------------------------------------

void  TDMSprMod::NewElement(__int64 Nom)
{
IdNom=Nom;
Table->Insert();

}
//---------------------------------------------------------------------------

void  TDMSprMod::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		if (IBTrUpdate->Active==true) IBTrUpdate->Commit();
        OpenTable(IdNom);
        }
catch(Exception &exception)
        {
				Error=true;
				TextError=exception.Message;
        }
}
//---------------------------------------------------------------------------

void  TDMSprMod::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
	   //	IBTrUpdate->Commit();
        OpenTable(IdNom);
        }
catch(Exception &exception)
		{
		//		IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
        }
}
//---------------------------------------------------------------------------
void TDMSprMod::DeleteElement()
{
Table->Delete();
}
//-----------------------------------------------------------------------------


void __fastcall TDMSprMod::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprMod::TableNewRecord(TDataSet *DataSet)
{
TableIDNOM_MOD->AsInt64=IdNom;

}
//---------------------------------------------------------------------------

