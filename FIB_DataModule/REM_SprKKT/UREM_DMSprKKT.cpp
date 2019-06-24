//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprKKT.h"
#include "IDMSetup.h"
#include "IREM_DMSprKKTDv.h"
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

__fastcall TREM_DMSprKKT::TREM_DMSprKKT(TComponent* Owner)
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
bool TREM_DMSprKKT::Init(void)
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

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_DMSprKKT::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprKKT::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
Query->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
UnicodeString TREM_DMSprKKT::GetTextQuery(__int64 id_grp, bool all)
{
UnicodeString result="";
if(all==true)
		{//без групп
		result=result+" select rem_skkt.id_rem_skkt,";
		result=result+" rem_skkt.idgrp_rem_skkt,";
		result=result+" rem_skkt.name_rem_skkt,";
		result=result+" rem_skkt.sernum_rem_skkt,";
		result=result+" rem_smodel.name_rem_smodel,";
		result=result+" rem_skkt.mestoust_rem_skkt";
		result=result+" from rem_skkt";
		result=result+" left outer join rem_smodel on rem_skkt.idmodel_rem_skkt=rem_smodel.id_rem_smodel";
		result=result+" ORDER BY NAME_REM_SKKT";
		} //без групп
else
		{ //по группам
		if (id_grp==0)
				{ //корневой каталог
				result=result+" select rem_skkt.id_rem_skkt,";
				result=result+" rem_skkt.idgrp_rem_skkt,";
				result=result+" rem_skkt.name_rem_skkt,";
				result=result+" rem_skkt.sernum_rem_skkt,";
				result=result+" rem_smodel.name_rem_smodel,";
				result=result+" rem_skkt.mestoust_rem_skkt";
				result=result+" from rem_skkt";
				result=result+" left outer join rem_smodel on rem_skkt.idmodel_rem_skkt=rem_smodel.id_rem_smodel";
				result=result+" where rem_skkt.idgrp_rem_skkt is null";
				result=result+" ORDER BY NAME_REM_SKKT";
				}
		else    //задана группа
				{
				result=result+" select rem_skkt.id_rem_skkt,";
				result=result+" rem_skkt.idgrp_rem_skkt,";
				result=result+" rem_skkt.name_rem_skkt,";
				result=result+" rem_skkt.sernum_rem_skkt,";
				result=result+" rem_smodel.name_rem_smodel,";
				result=result+" rem_skkt.mestoust_rem_skkt";
				result=result+" from rem_skkt";
				result=result+" left outer join rem_smodel on rem_skkt.idmodel_rem_skkt=rem_smodel.id_rem_smodel";
				result=result+" where rem_skkt.idgrp_rem_skkt="+IntToStr(IdGrp);
				result=result+" ORDER BY NAME_REM_SKKT";
				}
		}


return result;
}
//---------------------------------------------------------------------------
void  TREM_DMSprKKT::OpenTable(__int64 id_grp,bool all)
{
IdGrp=id_grp;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(id_grp,all));
Table->Open();
}

//---------------------------------------------------------------------------

bool  TREM_DMSprKKT::NewElement(__int64 id_grp)
{
bool result=false;
Element->Active=false;


try
		{
		Element->Open();
		Element->Insert();
		if (id_grp!=0)
			{
			ElementIDGRP_REM_SKKT->AsString=id_grp;
			}
		result=true;
		}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------

int TREM_DMSprKKT::OpenElement(__int64 id)
{
int result=0;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=false;

try
		{
		Element->ParamByName("PARAM_ID")->AsInt64=id;
		Element->Active=true;
		result=Element->RecordCount;
		}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=0;
		}
return result;
}
//----------------------------------------------------------------------------
__int64 TREM_DMSprKKT::FindPoName(UnicodeString name)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(" select REM_SKKT.id_rem_skkt");
Query->SQL->Add(" from REM_SKKT");
Query->SQL->Add(" where rem_skkt.name_rem_skkt=:PARAM_NAME");
Query->ParamByName("PARAM_NAME")->AsString=name;
Query->ExecQuery();
result=Query->FieldByName("id_rem_skkt")->AsInt64;
Query->Close();
return result;
}
//---------------------------------------------------------------------------
bool  TREM_DMSprKKT::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_REM_SKKT->AsString);

try
        {

		Element->ApplyUpdates();
		IBTrUpdate->Commit();


		OpenElement(IdElement);
		AddNewRecordDv();
		res=true;
		}
catch(Exception &exception)
		{
		TextError=exception.Message;
		res=false;
		}

return res;
}
//---------------------------------------------------------------------------
bool TREM_DMSprKKT::DeleteElement(__int64 id)
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
void TREM_DMSprKKT::ChancheGrp(__int64 new_id_grp)
{
OpenElement(glStrToInt64(TableID_REM_SKKT->AsString));
Element->Edit();
ElementIDGRP_REM_SKKT->AsString=new_id_grp;
Element->Post();
SaveElement();
OpenTable(IdGrp,AllElement);
}
//---------------------------------------------------------------------------

__int64 TREM_DMSprKKT::GetIdGrpElementa(__int64 id_element)
{
__int64 res;
res=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select rem_skkt.idgrp_rem_skkt from rem_skkt");
Query->SQL->Add("where rem_skkt.id_rem_skkt=:PARAM_ID");
Query->ParamByName("PARAM_ID")->AsInt64=id_element;
Query->ExecQuery();
res=Query->FieldByName("IDGRP_REM_SKKT")->AsInt64;
Query->Close();
return res;

}
//-----------------------------------------------------------------------------
void TREM_DMSprKKT::AddNewRecordDv(void)
{
if (flChangeData==false) return;

		IREM_DMSprKKTDv * REM_DMSprKKTDv;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprKKTDv.1",IID_IREM_DMSprKKTDv,
													(void**)&REM_DMSprKKTDv);
		REM_DMSprKKTDv->Init(InterfaceMainObject,InterfaceImpl);
		REM_DMSprKKTDv->AddRecordDv(Now(),
						glStrToInt64(ElementID_REM_SKKT->AsString),           //
						glStrToInt64(ElementIDKLIENT_REM_SKKT->AsString),          //
						ElementMESTOUST_REM_SKKT->AsString,       //
						ElementREGNUM_REM_SKKT->AsString,         //
						ElementCBKGR_REM_SKKT->AsString,          //
						ElementCBKCO_REM_SKKT->AsString,          //
						ElementNUMCONTRACT_REM_SKKT->AsString,    //
						ElementDATECONTRACT_REM_SKKT->AsDateTime,
						ElementSUMCONTRACT_REM_SKKT->AsFloat,
						ElementEKLZ_SERNUM_REM_SKKT->AsString,
						ElementEKLZ_REGNUM_REM_SKKT->AsString,
						ElementEKLZ_ACT_REM_SKKT->AsDateTime,
						glStrToInt64(DM_Connection->UserInfoID_USER->AsString)	);

REM_DMSprKKTDv->kanRelease();

}
//УСТАНОВИМ ФЛАГ ИЗМЕНЕНИЯ
//----------------------------------------------------------------------------
void __fastcall TREM_DMSprKKT::ElementREGNUM_REM_SKKTChange(TField *Sender)
{
flChangeData=true;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprKKT::ElementIDKLIENT_REM_SKKTChange(TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprKKT::ElementMESTOUST_REM_SKKTChange(TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprKKT::ElementCBKGR_REM_SKKTChange(TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprKKT::ElementCBKCO_REM_SKKTChange(TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprKKT::ElementNUMCONTRACT_REM_SKKTChange(TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprKKT::ElementDATECONTRACT_REM_SKKTChange(
      TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprKKT::ElementSUMCONTRACT_REM_SKKTChange(TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprKKT::ElementEKLZ_SERNUM_REM_SKKTChange(TField *Sender)
{
flChangeData=true;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprKKT::ElementEKLZ_REGNUM_REM_SKKTChange(TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprKKT::ElementEKLZ_ACT_REM_SKKTChange(TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

