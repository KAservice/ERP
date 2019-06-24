//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprModel.h"
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

__fastcall TREM_DMSprModel::TREM_DMSprModel(TComponent* Owner)
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
bool TREM_DMSprModel::Init(void)
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
int TREM_DMSprModel::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprModel::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
UnicodeString TREM_DMSprModel::GetTextQuery(__int64 id_grp, bool all)
{
UnicodeString result="";
if(all==true)
		{//без групп
		result=" select                                          \
					REM_SMODEL.*,                                 \
					rem_sprmodel.name_rem_sprmodel,               \
					sbrand.name_sbrand,                           \
				snom.namenom,                                      \
				REM_SMODEL_NEISPR.name_rem_smodel as  NAME_REM_SMODEL_NEISPR,   \
				sproducer.name_sproducer,                                        \
				rem_sactcategory.name_rem_sactcategory,                         \
				rem_stypedevice.name_rem_stypedevice                            \
				from REM_SMODEL                                   \
				left outer join rem_sprmodel on rem_smodel.idprmodel_rem_smodel=rem_sprmodel.id_rem_sprmodel       \
				left outer join sbrand on rem_smodel.idbrand_rem_smodel=sbrand.id_sbrand                           \
				left outer join snom on rem_smodel.idnom_rem_smodel=snom.idnom                                     \
				left outer join rem_smodel as REM_SMODEL_NEISPR on rem_smodel.idmodelneispr_rem_smodel=REM_SMODEL_NEISPR.id_rem_smodel  \
				left outer join sproducer on rem_smodel.idproducer_rem_smodel=sproducer.id_sproducer                                   \
				left outer join rem_sactcategory on rem_smodel.idactcategory_rem_smodel=rem_sactcategory.id_rem_sactcategory           \
				left outer join rem_stypedevice on rem_smodel.idtypedevice_rem_smodel=rem_stypedevice.id_rem_stypedevice               \
					ORDER BY rem_smodel.name_rem_smodel ";

		} //без групп
else
		{ //по группам
		if (id_grp==0)
				{ //корневой каталог
		result=" select                                          \
					REM_SMODEL.* ,                                \
					rem_sprmodel.name_rem_sprmodel,               \
					sbrand.name_sbrand,                           \
				snom.namenom,                                      \
				REM_SMODEL_NEISPR.name_rem_smodel as  NAME_REM_SMODEL_NEISPR ,         \
				sproducer.name_sproducer,                                              \
				rem_sactcategory.name_rem_sactcategory,                                \
				rem_stypedevice.name_rem_stypedevice                                   \
				from REM_SMODEL                                   \
				left outer join rem_sprmodel on rem_smodel.idprmodel_rem_smodel=rem_sprmodel.id_rem_sprmodel       \
				left outer join sbrand on rem_smodel.idbrand_rem_smodel=sbrand.id_sbrand                           \
				left outer join snom on rem_smodel.idnom_rem_smodel=snom.idnom                                     \
				left outer join rem_smodel as REM_SMODEL_NEISPR on rem_smodel.idmodelneispr_rem_smodel=REM_SMODEL_NEISPR.id_rem_smodel  \
				left outer join sproducer on rem_smodel.idproducer_rem_smodel=sproducer.id_sproducer                                    \
				left outer join rem_sactcategory on rem_smodel.idactcategory_rem_smodel=rem_sactcategory.id_rem_sactcategory            \
				left outer join rem_stypedevice on rem_smodel.idtypedevice_rem_smodel=rem_stypedevice.id_rem_stypedevice                \
				where REM_SMODEL.IDGRP_REM_SMODEL IS NULL                                                                     \
					ORDER BY rem_smodel.name_rem_smodel ";
				}
		else    //задана группа
				{
		result=" select                                          \
					REM_SMODEL.*,                                 \
					rem_sprmodel.name_rem_sprmodel,               \
					sbrand.name_sbrand,                           \
				snom.namenom,                                      \
				REM_SMODEL_NEISPR.name_rem_smodel as  NAME_REM_SMODEL_NEISPR,               \
				sproducer.name_sproducer,                                                    \
				rem_sactcategory.name_rem_sactcategory,                                      \
				rem_stypedevice.name_rem_stypedevice                                         \
				from REM_SMODEL                                   \
				left outer join rem_sprmodel on rem_smodel.idprmodel_rem_smodel=rem_sprmodel.id_rem_sprmodel       \
				left outer join sbrand on rem_smodel.idbrand_rem_smodel=sbrand.id_sbrand                           \
				left outer join snom on rem_smodel.idnom_rem_smodel=snom.idnom         \
				left outer join rem_smodel as REM_SMODEL_NEISPR on rem_smodel.idmodelneispr_rem_smodel=REM_SMODEL_NEISPR.id_rem_smodel    \
				left outer join sproducer on rem_smodel.idproducer_rem_smodel=sproducer.id_sproducer                                       \
				left outer join rem_sactcategory on rem_smodel.idactcategory_rem_smodel=rem_sactcategory.id_rem_sactcategory               \
				left outer join rem_stypedevice on rem_smodel.idtypedevice_rem_smodel=rem_stypedevice.id_rem_stypedevice";
				result=result+" where REM_SMODEL.IDGRP_REM_SMODEL="+IntToStr(id_grp);
				result=result+" ORDER BY rem_smodel.name_rem_smodel ";
				}
        } 
return result;


}
//---------------------------------------------------------------------------
void  TREM_DMSprModel::OpenTable(__int64 id_grp,bool all)
{
AllElement=all;
IdGrp=id_grp;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(id_grp,all));
Table->Open();
}

//---------------------------------------------------------------------------

bool  TREM_DMSprModel::NewElement(__int64 id_grp)
{
bool result=false;
Element->Active=false;
Element->Open();
Element->Insert();
if (id_grp!=0)
	{
	ElementIDGRP_REM_SMODEL->AsString=id_grp;
	}
result=true;
return result;
}
//---------------------------------------------------------------------------

int TREM_DMSprModel::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}

//---------------------------------------------------------------------------
bool  TREM_DMSprModel::SaveElement()
{
bool result=false;
__int64 id=glStrToInt64(ElementID_REM_SMODEL->AsString);
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
bool TREM_DMSprModel::DeleteElement(__int64 id)
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
void TREM_DMSprModel::ChancheGrp(__int64 id_new_grp, __int64 id_el)
{
OpenElement(id_el);
Element->Edit();
ElementIDGRP_REM_SMODEL->AsString=id_new_grp;
Element->Post();
SaveElement();
}
//----------------------------------------------------------------------------


__int64 TREM_DMSprModel::GetIDElement(UnicodeString gid)
{
__int64 res=0;
pFIBQuery->Close();
        if (gid!="" || gid!=" " )
				{
				pFIBQuery->SQL->Clear();
				pFIBQuery->SQL->Add("select ID_REM_SMODEL from REM_SMODEL where GID_REM_SMODEL=:PARAM_GID");
				pFIBQuery->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQuery->ExecQuery();
				if (pFIBQuery->RecordCount==1)
                        {
						res=glStrToInt64(pFIBQuery->FieldByName("ID_REM_SMODEL")->AsString);
                        }
				else res=0;
                }
pFIBQuery->Close();

return res;
}
//---------------------------------------------------------------------------
UnicodeString TREM_DMSprModel::GetGIDElement(__int64 id)
{
UnicodeString res="";
pFIBQuery->Close();
        if (id!=0 )
				{
				pFIBQuery->SQL->Clear();
				pFIBQuery->SQL->Add("select GID_REM_SMODEL from REM_SMODEL where ID_REM_SMODEL=:PARAM_ID");
				pFIBQuery->ParamByName("PARAM_ID")->AsString=id;
				pFIBQuery->ExecQuery();
				if (pFIBQuery->RecordCount==1)
                        {
						res=Trim(pFIBQuery->FieldByName("GID_REM_SMODEL")->AsString);
                        }
				else res="";
                }
 pFIBQuery->Close();

return res;
}

//---------------------------------------------------------------------------


__int64 TREM_DMSprModel::GetIdGrpNom(__int64 id)
{
__int64 res;
res=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select IDGRP_REM_SMODEL from REM_SMODEL where ID_REM_SMODEL='"+IntToStr(id)+"'");
pFIBQuery->ExecQuery();
res=glStrToInt64(pFIBQuery->FieldByName("IDGRP_REM_SMODEL")->AsString);
pFIBQuery->Close();
return res;

}  
//----------------------------------------------------------------------------

void __fastcall TREM_DMSprModel::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------
__int64 TREM_DMSprModel::FindPoNom(__int64 id_nom)
{
__int64 result=0;

pFIBQuery->Close();
pFIBQuery->SQL->Clear();
pFIBQuery->SQL->Add("select ID_REM_SMODEL from REM_SMODEL where IDNOM_REM_SMODEL=:PARAM_IDNOM");
pFIBQuery->ParamByName("PARAM_IDNOM")->AsString=id_nom;
pFIBQuery->ExecQuery();
result=glStrToInt64(pFIBQuery->FieldByName("ID_REM_SMODEL")->AsString);
pFIBQuery->Close();

return result;
}
//---------------------------------------------------------------------------
