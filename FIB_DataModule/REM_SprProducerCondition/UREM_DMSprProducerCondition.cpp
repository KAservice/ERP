//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprProducerCondition.h"
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
__fastcall TREM_DMSprProducerCondition::TREM_DMSprProducerCondition(TComponent* Owner)
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
bool TREM_DMSprProducerCondition::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//������� ����������
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//������� ��������� COM ������� ��� �������� ����� ��������
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

//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_DMSprProducerCondition::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprProducerCondition::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TREM_DMSprProducerCondition::OpenTable(__int64 id_group_element, __int64 id_grp,  bool all)
{
IdGroupElement=id_group_element;
IdGrp=id_grp;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
if(all==true)
		{
				UnicodeString zapros="select  rem_sprcondition.*                                                                                            \
									from rem_sprcondition                                                                                                    \
									where                                                                                                                 \
										rem_sprcondition.idpr_rem_sprcondition=:PARAM_ID_GROUP_ELEMENT      \
									order by rem_sprcondition.name_rem_sprcondition";
				Table->SelectSQL->Add(zapros);
				Table->ParamByName("PARAM_ID_GROUP_ELEMENT")->AsInt64=id_group_element;
		}
else
		{
		if (id_grp==0)
				{
				UnicodeString zapros="select  rem_sprcondition.*                                                                                           \
									from rem_sprcondition                                                                                                \
									where                                                                                                               \
										rem_sprcondition.idpr_rem_sprcondition=:PARAM_ID_GROUP_ELEMENT and rem_sprcondition.idgrp_rem_sprcondition is null          \
									order by rem_sprcondition.name_rem_sprcondition";
				Table->SelectSQL->Add(zapros);
				Table->ParamByName("PARAM_ID_GROUP_ELEMENT")->AsInt64=id_group_element;
                }
        else
				{
				UnicodeString zapros="select  rem_sprcondition.*                                                                                           \
									from rem_sprcondition                                                                                                  \
									where                                                                                                                \
										rem_sprcondition.idpr_rem_sprcondition=:PARAM_ID_GROUP_ELEMENT and rem_sprcondition.idgrp_rem_sprcondition=:PARAM_IDGRP     \
									order by rem_sprcondition.name_rem_sprcondition";
				Table->SelectSQL->Add(zapros);
				Table->ParamByName("PARAM_ID_GROUP_ELEMENT")->AsInt64=id_group_element;
				Table->ParamByName("PARAM_IDGRP")->AsInt64=id_grp;
                }
        }

Table->Open();
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
bool  TREM_DMSprProducerCondition::NewElement(__int64 id_group_element, __int64 id_grp)
{
bool result=true;
IdGroupElement=id_group_element;
IdGrp=id_grp;
Element->Open();
Element->Append();

return result;
}
//----------------------------------------------------------------------------
bool TREM_DMSprProducerCondition::OpenElement(__int64 id)
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
bool TREM_DMSprProducerCondition::DeleteElement(__int64 id)
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
void __fastcall TREM_DMSprProducerCondition::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void TREM_DMSprProducerCondition::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
OpenElement(id_element);
Element->Edit();
ElementIDGRP_REM_SPRCONDITION->AsString=id_new_grp;
Element->Post();
SaveElement();
}
//-----------------------------------------------------------------------------

bool  TREM_DMSprProducerCondition::SaveElement(void)
{
bool result;
__int64 id=glStrToInt64(ElementID_REM_SPRCONDITION->AsString);
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
void __fastcall TREM_DMSprProducerCondition::ElementNewRecord(TDataSet *DataSet)
{
ElementIDPR_REM_SPRCONDITION->AsString=IdGroupElement;
if (IdGrp !=0)
	{
	ElementIDGRP_REM_SPRCONDITION->AsString=IdGrp;
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__int64 TREM_DMSprProducerCondition::FindPoCodu(__int64 id_group_element, UnicodeString code)
{

__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select rem_sprcondition.id_rem_sprcondition from rem_sprcondition where rem_sprcondition.idpr_rem_sprcondition=:PARAM_IDGROUP_ELEMENT and rem_sprcondition.code_rem_sprcondition=:PARAM_CODE");
Query->ParamByName("PARAM_CODE")->AsString=code;
Query->ParamByName("PARAM_IDGROUP_ELEMENT")->AsString=id_group_element;
Query->ExecQuery();
result=Query->FieldByName("id_rem_sprcondition")->AsInt64;
Query->Close();
return result;

}
//-----------------------------------------------------------------------------
__int64 TREM_DMSprProducerCondition::FindPoName(__int64 id_group_element, UnicodeString name)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select rem_sprcondition.id_rem_sprcondition from rem_sprcondition where rem_sprcondition.idpr_rem_sprcondition=:PARAM_IDGROUP_ELEMENT and rem_sprcondition.name_rem_sprcondition=:PARAM_NAME");
Query->ParamByName("PARAM_NAME")->AsString=name;
Query->ParamByName("PARAM_IDGROUP_ELEMENT")->AsString=id_group_element;
Query->ExecQuery();
result=Query->FieldByName("id_rem_sprcondition")->AsInt64;
Query->Close();
return result;
}
//----------------------------------------------------------------------------
__int64 TREM_DMSprProducerCondition::FindPoNameEng(__int64 id_group_element, UnicodeString name)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select rem_sprcondition.id_rem_sprcondition from rem_sprcondition where rem_sprcondition.idpr_rem_sprcondition=:PARAM_IDGROUP_ELEMENT and rem_sprcondition.name_eng_rem_sprcondition=:PARAM_NAME");
Query->ParamByName("PARAM_NAME")->AsString=name;
Query->ParamByName("PARAM_IDGROUP_ELEMENT")->AsString=id_group_element;
Query->ExecQuery();
result=Query->FieldByName("id_rem_sprcondition")->AsInt64;
Query->Close();
return result;

}
//---------------------------------------------------------------------------
__int64 TREM_DMSprProducerCondition::GetIdGrp(__int64 id_el)
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
