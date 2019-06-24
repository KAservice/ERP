//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprTypRabot.h"
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

__fastcall TREM_DMSprTypRabot::TREM_DMSprTypRabot(TComponent* Owner)
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
bool TREM_DMSprTypRabot::Init(void)
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
int TREM_DMSprTypRabot::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprTypRabot::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
UnicodeString TREM_DMSprTypRabot::GetTextQuery(__int64 id_grp, bool all)
{
UnicodeString result="";
if(all==true)
		{//без групп
		result=" select                                                             \
					rem_styprabot.*,                                                \
					snom.namenom,                                                   \
					snom.artnom,                                                    \
					snom.codenom                                                    \
					from rem_styprabot                                              \
					left outer join snom on rem_styprabot.idnom_rem_styprabot=snom.idnom   \
					ORDER BY rem_styprabot.name_rem_styprabot ";

		} //без групп
else
		{ //по группам
		if (id_grp==0)
				{ //корневой каталог
		result=" select                                                             \
					rem_styprabot.*,                                                \
					snom.namenom,                                                   \
					snom.artnom,                                                    \
					snom.codenom                                                    \
					from rem_styprabot                                              \
					left outer join snom on rem_styprabot.idnom_rem_styprabot=snom.idnom   \
					where rem_styprabot.idgrp_rem_styprabot is null                        \
					ORDER BY rem_styprabot.name_rem_styprabot ";
				}
		else    //задана группа
				{
				result=" select                                                             \
					rem_styprabot.*,                                                \
					snom.namenom,                                                   \
					snom.artnom,                                                    \
					snom.codenom                                                    \
					from rem_styprabot                                              \
					left outer join snom on rem_styprabot.idnom_rem_styprabot=snom.idnom  ";
				result=result+" where rem_styprabot.idgrp_rem_styprabot="+IntToStr(id_grp);
				result=result+" ORDER BY rem_styprabot.name_rem_styprabot ";
				}
        } 
return result;


}
//---------------------------------------------------------------------------
void  TREM_DMSprTypRabot::OpenTable(__int64 id_grp,bool all)
{
AllElement=all;
IdGrp=id_grp;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(id_grp,all));
Table->Open();
}

//---------------------------------------------------------------------------

bool  TREM_DMSprTypRabot::NewElement(__int64 id_grp)
{
bool result=false;
Element->Active=false;
Element->Open();
Element->Insert();
if (id_grp!=0)
	{
	ElementIDGRP_REM_STYPRABOT->AsString=id_grp;
	}
result=true;
return result;
}
//---------------------------------------------------------------------------

int TREM_DMSprTypRabot::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}

//---------------------------------------------------------------------------
bool  TREM_DMSprTypRabot::SaveElement()
{
bool result=false;
__int64 id=glStrToInt64(ElementID_REM_STYPRABOT->AsString);
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
bool TREM_DMSprTypRabot::DeleteElement(__int64 id)
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
void TREM_DMSprTypRabot::ChancheGrp(__int64 id_new_grp, __int64 id_el)
{
OpenElement(id_el);
Element->Edit();
ElementIDGRP_REM_STYPRABOT->AsString=id_new_grp;
Element->Post();
SaveElement();
}
//----------------------------------------------------------------------------



//---------------------------------------------------------------------------


__int64 TREM_DMSprTypRabot::GetIdGrpTypRabot(__int64 id)
{
__int64 res;
res=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select rem_styprabot.idgrp_rem_styprabot from rem_styprabot where rem_styprabot.id_rem_styprabot='"+IntToStr(id)+"'");
pFIBQuery->ExecQuery();
res=glStrToInt64(pFIBQuery->FieldByName("idgrp_rem_styprabot")->AsString);
pFIBQuery->Close();
return res;

}  
//----------------------------------------------------------------------------

void __fastcall TREM_DMSprTypRabot::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------
__int64 TREM_DMSprTypRabot::FindPoNom(__int64 id_nom)
{
__int64 result=0;

pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select rem_styprabot.id_rem_styprabot from rem_styprabot where rem_styprabot.idnom_rem_styprabot=:PARAM_IDNOM");
pFIBQuery->ParamByName("PARAM_IDNOM")->AsString=id_nom;
pFIBQuery->ExecQuery();
result=glStrToInt64(pFIBQuery->FieldByName("id_rem_styprabot")->AsString);
pFIBQuery->Close();

return result;
}
//---------------------------------------------------------------------------
