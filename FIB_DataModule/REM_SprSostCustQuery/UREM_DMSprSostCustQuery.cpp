//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprSostCustQuery.h"
#include "UGlobalFunction.h"
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
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_DMSprSostCustQuery::TREM_DMSprSostCustQuery(TComponent* Owner)
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
bool TREM_DMSprSostCustQuery::Init(void)
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
pFIBQ->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_DMSprSostCustQuery::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprSostCustQuery::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void  TREM_DMSprSostCustQuery::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TREM_DMSprSostCustQuery::NewElement()
{
Element->Active=false;
Element->Open();
Element->Append();

}
//---------------------------------------------------------------------------

int TREM_DMSprSostCustQuery::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TREM_DMSprSostCustQuery::SaveElement()
{
bool result;
__int64 id=glStrToInt64(ElementID_REM_SSOST_CQUERY->AsString);
try
        {
		Element->ApplyUpdToBase();
		IBTrUpdate->Commit();
		Element->CommitUpdToCach();
		OpenElement(id);
		result=true;
        }
catch(Exception &exception)
        {
		IBTrUpdate->Rollback();
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------

void  TREM_DMSprSostCustQuery::CloseElement()
{

		Element->CancelUpdates();
		IBTr->Rollback();
}
//---------------------------------------------------------------------------
bool TREM_DMSprSostCustQuery::DeleteElement(__int64 id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
				Element->ApplyUpdToBase();
				IBTrUpdate->Commit();
				Element->CommitUpdToCach();
				result=true;
				}
        catch(Exception &exception)
                {
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				result=false;
                }
		}
return result;
}
//---------------------------------------------------------------------------

__int64 TREM_DMSprSostCustQuery::GetIDElement(UnicodeString gid)
{
__int64 res=0;




return res;
}
//---------------------------------------------------------------------------
UnicodeString TREM_DMSprSostCustQuery::GetGIDElement(__int64 id)
{
UnicodeString res=0;



return res;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprSostCustQuery::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

int TREM_DMSprSostCustQuery::GetIndexElementaPoID(__int64 id)
{   //индекс начинается с 1, если 0 то не найден элемент
int result=0;
int index=0;
Table->First();
while(!Table->Eof)
	{
	if(glStrToInt64(TableID_REM_SSOST_CQUERY->AsString)==id)
		{
		result=index+1;
		break;
		}
	index++;
	Table->Next();
	}
return result;
}
//----------------------------------------------------------------------------
