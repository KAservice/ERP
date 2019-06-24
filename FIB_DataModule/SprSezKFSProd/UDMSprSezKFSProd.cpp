//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprSezKFSProd.h"
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
__fastcall TDMSprSezKFSProd::TDMSprSezKFSProd(TComponent* Owner)
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
bool TDMSprSezKFSProd::Init(void)
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


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprSezKFSProd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprSezKFSProd::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprSezKFSProd::OpenTable(__int64 idSProd)
{
IdSProd=idSProd;
Table->Active=false;
Table->ParamByName("PARAM_IDSPROD")->AsInt64=idSProd;
Table->Open();
}

//---------------------------------------------------------------------------

void  TDMSprSezKFSProd::NewElement(__int64 idSProd)
{
IdSProd=idSProd;
Table->Insert();

}
//---------------------------------------------------------------------------

void  TDMSprSezKFSProd::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenTable(IdSProd);
        }
        catch(Exception &exception)
				{
				//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------

void  TDMSprSezKFSProd::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
		//IBTrUpdate->Commit();
        OpenTable(IdSProd);
        }
        catch(Exception &exception)
				{
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
                }
}
//---------------------------------------------------------------------------
void TDMSprSezKFSProd::DeleteElement()
{
Table->Delete();
}
//-----------------------------------------------------------------------------


void __fastcall TDMSprSezKFSProd::TableNewRecord(TDataSet *DataSet)
{
TableIDSSPROD_SSEZKF_SPROD->AsInt64=IdSProd;

}
//---------------------------------------------------------------------------

