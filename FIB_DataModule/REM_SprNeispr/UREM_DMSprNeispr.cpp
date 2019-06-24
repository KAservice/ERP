//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprNeispr.h"
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

__fastcall TREM_DMSprNeispr::TREM_DMSprNeispr(TComponent* Owner)
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
bool TREM_DMSprNeispr::Init(void)
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
pFIBQuery->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_DMSprNeispr::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprNeispr::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
UnicodeString TREM_DMSprNeispr::GetTextQuery(__int64 id_grp, bool all)
{
UnicodeString result="";
if(all==true)
		{//без групп
		result=result+" select *";
		result=result+" from REM_SNEISPR";
		result=result+" ORDER BY NAME_REM_SNEISPR"; 
		} //без групп
else
		{ //по группам
		if (id_grp==0)
				{ //корневой каталог
				result=result+" select * ";
				result=result+" from REM_SNEISPR";
				result=result+" where IDGRP_REM_SNEISPR IS NULL";
				result=result+" ORDER BY NAME_REM_SNEISPR"; 
				}
		else    //задана группа
				{
				result=result+" select * ";
				result=result+" from REM_SNEISPR";
				result=result+" where IDGRP_REM_SNEISPR="+IntToStr(id_grp);
				result=result+" ORDER BY NAME_REM_SNEISPR";
				}
        } 
return result;
}
//---------------------------------------------------------------------------
void  TREM_DMSprNeispr::OpenTable(__int64 id_grp,bool all)
{
AllElement=all;
IdGrp=id_grp;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(id_grp,all));
Table->Open();
}

//---------------------------------------------------------------------------

bool  TREM_DMSprNeispr::NewElement(__int64 id_grp)
{
bool result=false;
Element->Active=false;
Element->Open();
Element->Insert();
if (id_grp!=0)
	{
	ElementIDGRP_REM_SNEISPR->AsString=id_grp;
	}
result=true;
return result;
}
//---------------------------------------------------------------------------

int TREM_DMSprNeispr::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}

//---------------------------------------------------------------------------
bool  TREM_DMSprNeispr::SaveElement()
{
bool result=false;
__int64 id=glStrToInt64(ElementID_REM_SNEISPR->AsString);
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
bool TREM_DMSprNeispr::DeleteElement(__int64 id)
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
void TREM_DMSprNeispr::ChancheGrp(__int64 id_new_grp)
{
OpenElement(glStrToInt64(TableID_REM_SNEISPR->AsString));
Element->Edit();
ElementIDGRP_REM_SNEISPR->AsString=id_new_grp;
Element->Post();
SaveElement();
OpenTable(IdGrp,AllElement);
}
//----------------------------------------------------------------------------


__int64 TREM_DMSprNeispr::GetIDElement(UnicodeString gid)
{
__int64 res=0;
pFIBQuery->Close();
        if (gid!="" || gid!=" " )
				{
				pFIBQuery->SQL->Clear();
				pFIBQuery->SQL->Add("select ID_REM_SNEISPR from REM_SNEISPR where GID_REM_SNEISPR=:PARAM_GID");
				pFIBQuery->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQuery->ExecQuery();
				if (pFIBQuery->RecordCount==1)
                        {
						res=glStrToInt64(pFIBQuery->FieldByName("ID_REM_SNEISPR")->AsString);
                        }
				else res=0;
                }
pFIBQuery->Close();

return res;
}
//---------------------------------------------------------------------------
UnicodeString TREM_DMSprNeispr::GetGIDElement(__int64 id)
{
UnicodeString res="";
pFIBQuery->Close();
        if (id!=0 )
				{
				pFIBQuery->SQL->Clear();
				pFIBQuery->SQL->Add("select GID_REM_SNEISPR from REM_SNEISPR where ID_REM_SNEISPR=:PARAM_ID");
				pFIBQuery->ParamByName("PARAM_ID")->AsString=id;
				pFIBQuery->ExecQuery();
				if (pFIBQuery->RecordCount==1)
                        {
						res=Trim(pFIBQuery->FieldByName("GID_REM_SNEISPR")->AsString);
                        }
				else res="";
                }
 pFIBQuery->Close();

return res;
}

//---------------------------------------------------------------------------


__int64 TREM_DMSprNeispr::GetIdGrpNom(__int64 id)
{
__int64 res;
res=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select IDGRP_REM_SNEISPR from REM_SNEISPR where ID_REM_SNEISPR='"+IntToStr(id)+"'");
pFIBQuery->ExecQuery();
res=glStrToInt64(pFIBQuery->FieldByName("IDGRP_REM_SNEISPR")->AsString);
pFIBQuery->Close();
return res;

}  
//----------------------------------------------------------------------------

void __fastcall TREM_DMSprNeispr::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

