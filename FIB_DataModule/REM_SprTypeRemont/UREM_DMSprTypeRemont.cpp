//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprTypeRemont.h"
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
__fastcall TREM_DMSprTypeRemont::TREM_DMSprTypeRemont(TComponent* Owner)
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
bool TREM_DMSprTypeRemont::Init(void)
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
int TREM_DMSprTypeRemont::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprTypeRemont::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void  TREM_DMSprTypeRemont::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TREM_DMSprTypeRemont::NewElement()
{
Element->Active=false;
Element->Open();
Element->Append();

}
//---------------------------------------------------------------------------

int TREM_DMSprTypeRemont::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TREM_DMSprTypeRemont::SaveElement()
{
bool result;
__int64 id=glStrToInt64(ElementID_STREMONT->AsString);
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

void  TREM_DMSprTypeRemont::CloseElement()
{

        Element->CancelUpdates();
        IBTr->Rollback();   
}
//---------------------------------------------------------------------------
bool TREM_DMSprTypeRemont::DeleteElement(__int64 id)
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

__int64 TREM_DMSprTypeRemont::GetIDElement(UnicodeString gid)
{
__int64 res=0;

        if (gid!="" || gid!=" " )
				{
				pFIBQ->Close();
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select ID_STREMONT from REM_STREMONT where GID_STREMONT=:PARAM_GID");
				pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
                        {
						res=glStrToInt64(pFIBQ->FieldByName("ID_STREMONT")->AsString);
						}
				else res=0;
                }
				pFIBQ->Close();


return res;
}
//---------------------------------------------------------------------------
UnicodeString TREM_DMSprTypeRemont::GetGIDElement(__int64 id)
{
UnicodeString res=0;

		if (id!=0 )
				{
				pFIBQ->Close();
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select GID_STREMONT from STREMONT where ID_STREMONT=:PARAM_ID");
				pFIBQ->ParamByName("PARAM_ID")->AsString=id;
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
                        {
						res=Trim(pFIBQ->FieldByName("GID_STREMONT")->AsString);
                        }
				else res="";
				pFIBQ->Close();
                }



return res;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprTypeRemont::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

int TREM_DMSprTypeRemont::GetIndexElementaPoID(__int64 id)
{   //индекс начинается с 1, если 0 то не найден элемент
int result=0;
int index=0;
Table->First();
while(!Table->Eof)
	{
	if(glStrToInt64(TableID_STREMONT->AsString)==id)
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

