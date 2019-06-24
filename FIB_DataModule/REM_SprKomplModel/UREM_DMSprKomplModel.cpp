//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprKomplModel.h"
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
__fastcall TREM_DMSprKomplModel::TREM_DMSprKomplModel(TComponent* Owner)
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
bool TREM_DMSprKomplModel::Init(void)
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
int TREM_DMSprKomplModel::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprKomplModel::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;


}
//---------------------------------------------------------------------------

void TREM_DMSprKomplModel::OpenTable(__int64 id_model)
{

Table->Active=false;
Table->ParamByName("PARAM_IDMODEL")->AsString=id_model;
Table->Active=true;

}
//---------------------------------------------------------------------------

int TREM_DMSprKomplModel::OpenElement(__int64 id)  //возвращает количество элементов
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//----------------------------------------------------------------------------

bool TREM_DMSprKomplModel::NewElement(__int64 id_model)
{
Element->Active=false;
Element->Open();
Element->Insert();
ElementIDMODEL_REM_SKOMPLMODEL->AsString=id_model;

return true;

}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool  TREM_DMSprKomplModel::SaveElement(void)
{
bool result=false;
__int64 id=glStrToInt64(ElementID_REM_SKOMPLMODEL->AsString);
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
//----------------------------------------------------------------------------

bool TREM_DMSprKomplModel::DeleteElement(__int64 id)
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

//----------------------------------------------------------------------------

__int64 TREM_DMSprKomplModel::GetIDElement(String gid)
{
__int64 res=0;

pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select ID_REM_SKOMPLMODEL from REM_SKOMPLMODEL where GID_REM_=:PARAM_GID");
		pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
		pFIBQ->ExecQuery();
		if (pFIBQ->RecordCount==1)
			{
			res=glStrToInt64(pFIBQ->FieldByName("ID_REM_SKOMPLMODEL")->AsString);
			}
		else res=0;

pFIBQ->Close();


return res;
}
//---------------------------------------------------------------------------
UnicodeString TREM_DMSprKomplModel::GetGIDElement(__int64 id)
{
UnicodeString res=0;

if (id==0) return res;

pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select GID_REM_SKOMPLMODEL from REM_SKOMPLMODEL where ID_REM_SKOMPLMODEL=:PARAM_ID");
		pFIBQ->ParamByName("PARAM_ID")->AsString=id;
		pFIBQ->ExecQuery();
		if (pFIBQ->RecordCount==1)
			{
			res=Trim(pFIBQ->FieldByName("GID_REM_SKOMPLMODEL")->AsString);
			}
		else res="";
pFIBQ->Close();

return res;
}
//----------------------------------------------------------------------------

void __fastcall TREM_DMSprKomplModel::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------


