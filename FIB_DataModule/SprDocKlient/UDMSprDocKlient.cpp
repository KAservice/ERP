//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprDocKlient.h"
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
__fastcall TDMSprDocKlient::TDMSprDocKlient(TComponent* Owner)
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
bool TDMSprDocKlient::Init(void)
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
int TDMSprDocKlient::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprDocKlient::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TDMSprDocKlient::OpenTable(__int64 IdKl)
{
IdKlient=IdKl;
Table->Active=false;
Table->ParamByName("PARAM_IDKLIENT")->AsInt64=IdKlient;
Table->Active=true;

}
//---------------------------------------------------------------------------

int TDMSprDocKlient::OpenElement(__int64 Id)  //возвращает количество элементов
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//----------------------------------------------------------------------------

void TDMSprDocKlient::NewElement(__int64 IdKl)
{
IdKlient=IdKl;
Element->Active=false;
Element->Open();
Element->Insert();

}
//-----------------------------------------------------------------------------
bool TDMSprDocKlient::SaveElement(void)
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
//----------------------------------------------------------------------------

void TDMSprDocKlient::DeleteElement(__int64 Id)
{
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
				IBTrUpdate->Rollback();
                Error=true;
				TextError=exception.Message;
                }
        }
}
//----------------------------------------------------------------------------

void __fastcall TDMSprDocKlient::TableCalcFields(TDataSet *DataSet)
{
Table->FieldByName("RECNO")->AsInteger=Table->RecNo;		
}
//---------------------------------------------------------------------------

void __fastcall TDMSprDocKlient::ElementNewRecord(TDataSet *DataSet)
{
ElementIDKLIENT_SDOCKLIENT->AsInt64=IdKlient;


}
//---------------------------------------------------------------------------


