//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprMPrig.h"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprMPrig::TDMSprMPrig(TComponent* Owner)
        : TDataModule(Owner)
{
Error=false;
TextError="Ошибок нет!";
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//----------------------------------------------------------------------------
bool TDMSprMPrig::Init(void)
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
Element->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprMPrig::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprMPrig::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprMPrig::OpenTable()
{
Table->Active=false;
Table->Open();
}

//---------------------------------------------------------------------------

void  TDMSprMPrig::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();
}
//---------------------------------------------------------------------------

int TDMSprMPrig::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID_MPRIG")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprMPrig::SaveElement()
{
bool result=false;
try
        {
		Element->ApplyUpdates();
		IBTrUpdate->Commit();
		result=true;
        }
catch(Exception &exception)
        {
				Error=true;
				TextError=exception.Message;
				result=false;
		}
return result;
}
//---------------------------------------------------------------------------
void TDMSprMPrig::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID_MPRIG")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
                }
		catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TDMSprMPrig::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;          
}
//---------------------------------------------------------------------------


