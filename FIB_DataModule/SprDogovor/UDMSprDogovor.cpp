//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprDogovor.h"
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
__fastcall TDMSprDogovor::TDMSprDogovor(TComponent* Owner)
        : TDataModule(Owner)
{
flSaveElement=false;
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TDMSprDogovor::Init(void)
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
int TDMSprDogovor::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprDogovor::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TDMSprDogovor::OpenTable(__int64 IdKl)
{
IdKlient=IdKl;
Table->Active=false;
Table->ParamByName("PARAM_IDKLIENT")->AsInt64=IdKlient;
Table->Active=true;


}
//---------------------------------------------------------------------------

int TDMSprDogovor::OpenElement(__int64 Id)  //возвращает количество элементов
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;

if (Res>0) flSaveElement=true;
return Res;
}
//----------------------------------------------------------------------------

void TDMSprDogovor::NewElement(__int64 IdKl)
{
flSaveElement=false;
IdKlient=IdKl;
Element->Active=false;
Element->Open();
Element->Insert();
}
//-----------------------------------------------------------------------------
bool TDMSprDogovor::SaveElement(void)
{
bool result=false;
__int64 id=ElementID_SDOG->AsInt64;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		flSaveElement=true;
		OpenElement(id);
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
//----------------------------------------------------------------------------

void TDMSprDogovor::DeleteElement(__int64 Id)
{
flSaveElement=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
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
                Error=true;
                TextError=exception.Message;
                }
        }
}
//----------------------------------------------------------------------------
void __fastcall TDMSprDogovor::TableCalcFields(TDataSet *DataSet)
{
Table->FieldByName("RECNO")->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprDogovor::ElementNewRecord(TDataSet *DataSet)
{
ElementIDKLIENT_SDOG->AsInt64=IdKlient;
ElementDO_SDOG->AsDateTime=Date();
ElementDATE_SDOG->AsDateTime=Date();

}
//---------------------------------------------------------------------------

