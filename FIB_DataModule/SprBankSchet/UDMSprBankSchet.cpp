//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprBankSchet.h"
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
__fastcall TDMSprBankSchet::TDMSprBankSchet(TComponent* Owner)
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
bool TDMSprBankSchet::Init(void)
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
//----------------------------------------------------------------------------
int TDMSprBankSchet::Done(void)
{

return -1;
}
//--------------------------------------------------------------------------------
void TDMSprBankSchet::OpenTable()
{
Table->Active=false;
Table->ParamByName("IDFIRM")->AsInt64=IdFirm;
Table->Active=true;

}
//---------------------------------------------------------------------------

int TDMSprBankSchet::OpenElement(__int64 Id)  //возвращает количество элементов
{
Element->Active=false;

Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//----------------------------------------------------------------------------

void TDMSprBankSchet::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();

}
//-----------------------------------------------------------------------------

bool TDMSprBankSchet::SaveElement(void)
{
bool result;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		result=true;
        }
catch(Exception &exception)
	{
	TextError=exception.Message;
	//IBTrUpdate->Rollback();
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------

void TDMSprBankSchet::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
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
			TextError=exception.Message;
			IBTrUpdate->Rollback();
			}
        }
}
//----------------------------------------------------------------------------
void __fastcall TDMSprBankSchet::DataModuleDestroy(TObject *Sender)
{
Element->Active=false;
Table->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------



void __fastcall TDMSprBankSchet::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprBankSchet::ElementNewRecord(TDataSet *DataSet)
{
ElementIDFIRMBSCHET->AsInt64=IdFirm;
}
//---------------------------------------------------------------------------

