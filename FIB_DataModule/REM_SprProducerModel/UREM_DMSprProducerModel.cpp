//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprProducerModel.h"
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
__fastcall TREM_DMSprProducerModel::TREM_DMSprProducerModel(TComponent* Owner)
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
bool TREM_DMSprProducerModel::Init(void)
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
int TREM_DMSprProducerModel::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprProducerModel::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TREM_DMSprProducerModel::OpenTable(__int64 id_group_element, __int64 id_grp,  bool all)
{
IdGroupElement=id_group_element;
IdGrp=id_grp;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
if(all==true)
		{
				UnicodeString zapros="select  rem_sprmodel.id_rem_sprmodel,               \
												rem_sprmodel.code_rem_sprmodel,            \
												rem_sprmodel.name_rem_sprmodel,            \
												rem_sprmodel.idpr_rem_sprmodel,            \
												rem_sprmodel.idgrp_rem_sprmodel,            \
												rem_smodel.name_rem_smodel ,                \
												sbrand.name_sbrand,                         \
												sproducer.name_sproducer,                   \
												rem_sactcategory.name_rem_sactcategory,     \
												rem_stypedevice.name_rem_stypedevice         \
										from rem_sprmodel                                      \
										left outer join rem_smodel on rem_sprmodel.idmodel_rem_sprmodel=rem_smodel.id_rem_smodel     \
										left outer join sbrand on rem_sprmodel.idbrand_rem_sprmodel=sbrand.id_sbrand                                         \
										left outer join sproducer on rem_sprmodel.idpr_rem_sprmodel=sproducer.id_sproducer                                    \
										left outer join rem_sactcategory on rem_sprmodel.idactcategory_rem_sprmodel=rem_sactcategory.id_rem_sactcategory      \
										left outer join rem_stypedevice on rem_sprmodel.idtypedevice_rem_sprmodel=rem_stypedevice.id_rem_stypedevice         \
										where                                                                                        \
											rem_sprmodel.idpr_rem_sprmodel=:PARAM_ID_GROUP_ELEMENT      \
										order by rem_sprmodel.name_rem_sprmodel";
				Table->SelectSQL->Add(zapros);
				Table->ParamByName("PARAM_ID_GROUP_ELEMENT")->AsInt64=id_group_element;
		}
else
		{
		if (id_grp==0)
				{
				UnicodeString zapros="select  rem_sprmodel.id_rem_sprmodel,               \
												rem_sprmodel.code_rem_sprmodel,            \
												rem_sprmodel.name_rem_sprmodel,            \
												rem_sprmodel.idpr_rem_sprmodel,            \
												rem_sprmodel.idgrp_rem_sprmodel,            \
												rem_smodel.name_rem_smodel   ,              \
												sbrand.name_sbrand,                         \
												sproducer.name_sproducer,                   \
												rem_sactcategory.name_rem_sactcategory,     \
												rem_stypedevice.name_rem_stypedevice        \
										from rem_sprmodel                                      \
										left outer join rem_smodel on rem_sprmodel.idmodel_rem_sprmodel=rem_smodel.id_rem_smodel     \
										left outer join sbrand on rem_sprmodel.idbrand_rem_sprmodel=sbrand.id_sbrand                                       \
										left outer join sproducer on rem_sprmodel.idpr_rem_sprmodel=sproducer.id_sproducer                                 \
										left outer join rem_sactcategory on rem_sprmodel.idactcategory_rem_sprmodel=rem_sactcategory.id_rem_sactcategory   \
										left outer join rem_stypedevice on rem_sprmodel.idtypedevice_rem_sprmodel=rem_stypedevice.id_rem_stypedevice       \
										where                                                                                        \
											rem_sprmodel.idpr_rem_sprmodel=:PARAM_ID_GROUP_ELEMENT and rem_sprmodel.idgrp_rem_sprmodel is null      \
										order by rem_sprmodel.name_rem_sprmodel";
				Table->SelectSQL->Add(zapros);
				Table->ParamByName("PARAM_ID_GROUP_ELEMENT")->AsInt64=id_group_element;
                }
        else
				{
				UnicodeString zapros="select  rem_sprmodel.id_rem_sprmodel,               \
												rem_sprmodel.code_rem_sprmodel,            \
												rem_sprmodel.name_rem_sprmodel,            \
												rem_sprmodel.idpr_rem_sprmodel,            \
												rem_sprmodel.idgrp_rem_sprmodel,            \
												rem_smodel.name_rem_smodel         ,        \
												sbrand.name_sbrand,                         \
												sproducer.name_sproducer,                   \
												rem_sactcategory.name_rem_sactcategory,     \
												rem_stypedevice.name_rem_stypedevice        \
										from rem_sprmodel                                      \
										left outer join rem_smodel on rem_sprmodel.idmodel_rem_sprmodel=rem_smodel.id_rem_smodel     \
										left outer join sbrand on rem_sprmodel.idbrand_rem_sprmodel=sbrand.id_sbrand                 \
										left outer join sproducer on rem_sprmodel.idpr_rem_sprmodel=sproducer.id_sproducer           \
										left outer join rem_sactcategory on rem_sprmodel.idactcategory_rem_sprmodel=rem_sactcategory.id_rem_sactcategory \
										left outer join rem_stypedevice on rem_sprmodel.idtypedevice_rem_sprmodel=rem_stypedevice.id_rem_stypedevice     \
										where                                                                                        \                   \
											rem_sprmodel.idpr_rem_sprmodel=:PARAM_ID_GROUP_ELEMENT and rem_sprmodel.idgrp_rem_sprmodel=:PARAM_IDGRP      \
										order by rem_sprmodel.name_rem_sprmodel";
				Table->SelectSQL->Add(zapros);
				Table->ParamByName("PARAM_ID_GROUP_ELEMENT")->AsInt64=id_group_element;
				Table->ParamByName("PARAM_IDGRP")->AsInt64=id_grp;
                }
        }

Table->Open();
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
bool  TREM_DMSprProducerModel::NewElement(__int64 id_group_element, __int64 id_grp)
{
bool result=true;
IdGroupElement=id_group_element;
IdGrp=id_grp;
Element->Open();
Element->Append();

return result;
}
//----------------------------------------------------------------------------
bool TREM_DMSprProducerModel::OpenElement(__int64 id)
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
bool TREM_DMSprProducerModel::DeleteElement(__int64 id)
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
void __fastcall TREM_DMSprProducerModel::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void TREM_DMSprProducerModel::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
OpenElement(id_element);
Element->Edit();
ElementIDGRP_REM_SPRMODEL->AsString=id_new_grp;
Element->Post();
SaveElement();
}
//-----------------------------------------------------------------------------

bool  TREM_DMSprProducerModel::SaveElement(void)
{
bool result;
__int64 id=glStrToInt64(ElementID_REM_SPRMODEL->AsString);
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
void __fastcall TREM_DMSprProducerModel::ElementNewRecord(TDataSet *DataSet)
{
ElementIDPR_REM_SPRMODEL->AsString=IdGroupElement;
ElementIDGRP_REM_SPRMODEL->AsString=IdGrp;
}
//---------------------------------------------------------------------------

