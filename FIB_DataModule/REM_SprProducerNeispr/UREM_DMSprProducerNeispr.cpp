//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprProducerNeispr.h"
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
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_DMSprProducerNeispr::TREM_DMSprProducerNeispr(TComponent* Owner)
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
bool TREM_DMSprProducerNeispr::Init(void)
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
Query->Database=DM_Connection->pFIBData;

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
int TREM_DMSprProducerNeispr::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprProducerNeispr::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TREM_DMSprProducerNeispr::OpenTable(__int64 id_group_element, __int64 id_grp,  bool all)
{
IdGroupElement=id_group_element;
IdGrp=id_grp;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
if(all==true)
		{
				UnicodeString zapros="select  rem_sprneispr.id_rem_sprneispr,      \
											rem_sprneispr.code_rem_sprneispr,      \
											rem_sprneispr.name_rem_sprneispr,      \
											rem_sprneispr.idpr_rem_sprneispr,       \
											rem_sprneispr.idgrp_rem_sprneispr,      \
											rem_sprneispr.idneispr_rem_sprneispr,   \
											rem_sneispr.name_rem_sneispr,           \
											rem_sprneispr.NAME_ENG_REM_SPRNEISPR     \
										from rem_sprneispr                         \
										left outer join rem_sneispr on rem_sprneispr.idneispr_rem_sprneispr=rem_sneispr.id_rem_sneispr                  \
										where                                                                                                           \
											rem_sprneispr.idpr_rem_sprneispr=:PARAM_ID_GROUP_ELEMENT \
										order by rem_sprneispr.name_rem_sprneispr";
				Table->SelectSQL->Add(zapros);
				Table->ParamByName("PARAM_ID_GROUP_ELEMENT")->AsInt64=id_group_element;
		}
else
		{
		if (id_grp==0)
				{
				UnicodeString zapros="select  rem_sprneispr.id_rem_sprneispr,      \
											rem_sprneispr.code_rem_sprneispr,      \
											rem_sprneispr.name_rem_sprneispr,      \
											rem_sprneispr.idpr_rem_sprneispr,       \
											rem_sprneispr.idgrp_rem_sprneispr,      \
											rem_sprneispr.idneispr_rem_sprneispr,   \
											rem_sneispr.name_rem_sneispr,           \
											rem_sprneispr.NAME_ENG_REM_SPRNEISPR     \
										from rem_sprneispr                         \
										left outer join rem_sneispr on rem_sprneispr.idneispr_rem_sprneispr=rem_sneispr.id_rem_sneispr                  \
										where                                                                                                           \
											rem_sprneispr.idpr_rem_sprneispr=:PARAM_ID_GROUP_ELEMENT and rem_sprneispr.idgrp_rem_sprneispr is null \
										order by rem_sprneispr.name_rem_sprneispr";
				Table->SelectSQL->Add(zapros);
				Table->ParamByName("PARAM_ID_GROUP_ELEMENT")->AsInt64=id_group_element;
                }
        else
				{
				UnicodeString zapros="select  rem_sprneispr.id_rem_sprneispr,      \
											rem_sprneispr.code_rem_sprneispr,      \
											rem_sprneispr.name_rem_sprneispr,      \
											rem_sprneispr.idpr_rem_sprneispr,       \
											rem_sprneispr.idgrp_rem_sprneispr,      \
											rem_sprneispr.idneispr_rem_sprneispr,   \
											rem_sneispr.name_rem_sneispr,           \
											rem_sprneispr.NAME_ENG_REM_SPRNEISPR   \
										from rem_sprneispr                         \
										left outer join rem_sneispr on rem_sprneispr.idneispr_rem_sprneispr=rem_sneispr.id_rem_sneispr                  \
										where                                                                                                           \
											rem_sprneispr.idpr_rem_sprneispr=:PARAM_ID_GROUP_ELEMENT and rem_sprneispr.idgrp_rem_sprneispr=:PARAM_IDGRP \
										order by rem_sprneispr.name_rem_sprneispr";
				Table->SelectSQL->Add(zapros);
				Table->ParamByName("PARAM_ID_GROUP_ELEMENT")->AsInt64=id_group_element;
				Table->ParamByName("PARAM_IDGRP")->AsInt64=id_grp;
                }
        }

Table->Open();
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
bool  TREM_DMSprProducerNeispr::NewElement(__int64 id_group_element, __int64 id_grp)
{
bool result=true;
IdGroupElement=id_group_element;
IdGrp=id_grp;
Element->Open();
Element->Append();

return result;
}
//----------------------------------------------------------------------------
bool TREM_DMSprProducerNeispr::OpenElement(__int64 id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        result=true;
        }
return result;
}
//---------------------------------------------------------------------------
bool TREM_DMSprProducerNeispr::DeleteElement(__int64 id)
{
bool result=true;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
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
void __fastcall TREM_DMSprProducerNeispr::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void TREM_DMSprProducerNeispr::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
OpenElement(id_element);
Element->Edit();
ElementIDGRP_REM_SPRNEISPR->AsString=id_new_grp;
Element->Post();
SaveElement();
}
//-----------------------------------------------------------------------------

bool  TREM_DMSprProducerNeispr::SaveElement(void)
{
bool result;
__int64 id=glStrToInt64(ElementID_REM_SPRNEISPR->AsString);
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
void __fastcall TREM_DMSprProducerNeispr::ElementNewRecord(TDataSet *DataSet)
{

ElementIDPR_REM_SPRNEISPR->AsString=IdGroupElement;
if (IdGrp !=0)
	{
	ElementIDGRP_REM_SPRNEISPR->AsString=IdGrp;
	}
}

//---------------------------------------------------------------------------
__int64 TREM_DMSprProducerNeispr::FindPoCodu(__int64 id_group_element, UnicodeString code)
{

__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select rem_sprneispr.id_rem_sprneispr from rem_sprneispr where rem_sprneispr.idpr_rem_sprneispr=:PARAM_IDGROUP_ELEMENT and rem_sprneispr.code_rem_sprneispr=:PARAM_CODE");
Query->ParamByName("PARAM_CODE")->AsString=code;
Query->ParamByName("PARAM_IDGROUP_ELEMENT")->AsString=id_group_element;
Query->ExecQuery();
result=Query->FieldByName("id_rem_sprneispr")->AsInt64;
Query->Close();
return result;

}
//-----------------------------------------------------------------------------
__int64 TREM_DMSprProducerNeispr::FindPoName(__int64 id_group_element, UnicodeString name)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select rem_sprneispr.id_rem_sprneispr from rem_sprneispr where rem_sprneispr.idpr_rem_sprneispr=:PARAM_IDGROUP_ELEMENT and rem_sprneispr.name_rem_sprneispr=:PARAM_NAME");
Query->ParamByName("PARAM_NAME")->AsString=name;
Query->ParamByName("PARAM_IDGROUP_ELEMENT")->AsString=id_group_element;
Query->ExecQuery();
result=Query->FieldByName("id_rem_sprneispr")->AsInt64;
Query->Close();
return result;
}
//----------------------------------------------------------------------------
__int64 TREM_DMSprProducerNeispr::FindPoNameEng(__int64 id_group_element, UnicodeString name)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select rem_sprneispr.id_rem_sprneispr from rem_sprneispr where rem_sprneispr.idpr_rem_sprneispr=:PARAM_IDGROUP_ELEMENT and rem_sprneispr.name_eng_rem_sprneispr=:PARAM_NAME");
Query->ParamByName("PARAM_NAME")->AsString=name;
Query->ParamByName("PARAM_IDGROUP_ELEMENT")->AsString=id_group_element;
Query->ExecQuery();
result=Query->FieldByName("id_rem_sprneispr")->AsInt64;
Query->Close();
return result;

}
//---------------------------------------------------------------------------
__int64 TREM_DMSprProducerNeispr::GetIdGrp(__int64 id_el)
{
__int64 result=0;
//Query->Close();
//Query->SQL->Clear();
//Query->SQL->Add("select rem_sprneispr.id_rem_sprneispr from rem_sprneispr where rem_sprneispr.idpr_rem_sprneispr=:PARAM_IDGROUP_ELEMENT and rem_sprneispr.code_rem_sprneispr=:PARAM_CODE");
//Query->ParamByName("PARAM_CODE")->AsString=code;
//Query->ParamByName("PARAM_IDGROUP_ELEMENT")->AsString=id_group_element;
//Query->ExecQuery();
//result=Query->FieldByName("id_rem_sprneispr")->AsInt64;
//Query->Close();
return result;

}
//-----------------------------------------------------------------------------
