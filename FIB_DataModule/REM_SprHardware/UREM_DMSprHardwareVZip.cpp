//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprHardwareVZip.h"
#include "UGlobalFunction.h"
#include "UGlobalConstant.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IDMSetup.h"
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

__fastcall TREM_DMSprHardwareVZip::TREM_DMSprHardwareVZip(TComponent* Owner)
		: TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
flCentralBase=false;
}
//----------------------------------------------------------------------------
bool TREM_DMSprHardwareVZip::Init(void)
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



Table->Database=DM_Connection->pFIBData;
Query->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;



IDMSetup * setup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
												 (void**)&setup);
setup->Init(InterfaceMainObject,0);
setup->OpenElement(2);
if (setup->ElementVALUE_SETUP->AsString=="1")
	{
	flCentralBase=true;
	}
else
	{
	flCentralBase=false;
	}
setup->kanRelease();

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_DMSprHardwareVZip::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprHardwareVZip::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Query->Close();

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void  TREM_DMSprHardwareVZip::OpenTable(__int64 id_grp,bool all)
{
IdGrp=id_grp;
AllElement=all;
Table->Active=false;

Table->ParamByName("PARAM_IDGRP")->AsString=id_grp;
if (all==true)
	{
	 Table->ParamByName("PARAM_FL_ALL_GRP")->AsInteger=1;
	}
else
	{
	Table->ParamByName("PARAM_FL_ALL_GRP")->AsInteger=0;
	}


//						:PARAM_FL_POISK,
//						:PARAM_FL_OST,
//						:PARAM_STR_PARAM,
//						:PARAM_IDFIRM,
//						:PARAM_IDSKLAD,
//						:PARAM_IDTNOM


Table->Open();
}

//---------------------------------------------------------------------------
__int64 TREM_DMSprHardwareVZip::FindPoName(UnicodeString name)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(" select REM_SHARDWARE.id_rem_shardware");
Query->SQL->Add(" from REM_SHARDWARE");
Query->SQL->Add(" where rem_shardware.name_rem_shardware=:PARAM_NAME");
Query->ParamByName("PARAM_NAME")->AsString=name;
Query->ExecQuery();
result=Query->FieldByName("id_rem_shardware")->AsInt64;
Query->Close();
return result;
}
//---------------------------------------------------------------------------


__int64 TREM_DMSprHardwareVZip::GetIdGrpElementa(__int64 id_element)
{
__int64 res;
res=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select rem_shardware.idgrp_rem_shardware from rem_shardware");
Query->SQL->Add("where rem_shardware.id_rem_shardware=:PARAM_ID");
Query->ParamByName("PARAM_ID")->AsInt64=id_element;
Query->ExecQuery();
res=Query->FieldByName("IDGRP_REM_SHARDWARE")->AsInt64;
Query->Close();
return res;

}
//-----------------------------------------------------------------------------


//поиск по заводскому номеру
bool TREM_DMSprHardwareVZip::Table_FindPoSerNum1Like(__int64 id_grp, bool all, UnicodeString ser_num)
{
bool result=false;
Table->Active=false;

IdGrp=id_grp;
AllElement=all;

Table->ParamByName("PARAM_IDGRP")->AsString=id_grp;
if (all==true)
	{
	 Table->ParamByName("PARAM_FL_ALL_GRP")->AsInteger=1;
	}
else
	{
	Table->ParamByName("PARAM_FL_ALL_GRP")->AsInteger=0;
	}
Table->ParamByName("PARAM_FL_POISK")->AsInteger=1;
Table->ParamByName("PARAM_STR_FOR_POISK")->AsString=ser_num;

//						:PARAM_FL_POISK,
//						:PARAM_FL_OST,
//						:PARAM_STR_PARAM,
//						:PARAM_IDFIRM,
//						:PARAM_IDSKLAD,
//						:PARAM_IDTNOM


Table->Open();


return result;
}
//----------------------------------------------------------------------------
//поиск по заводскому номеру2
bool TREM_DMSprHardwareVZip::Table_FindPoSerNum2Like(__int64 id_grp, bool all, UnicodeString ser_num)
{
bool result=false;
Table->Active=false;

IdGrp=id_grp;
AllElement=all;


Table->ParamByName("PARAM_IDGRP")->AsString=id_grp;
if (all==true)
	{
	 Table->ParamByName("PARAM_FL_ALL_GRP")->AsInteger=1;
	}
else
	{
	Table->ParamByName("PARAM_FL_ALL_GRP")->AsInteger=0;
	}
Table->ParamByName("PARAM_FL_POISK")->AsInteger=2;
Table->ParamByName("PARAM_STR_FOR_POISK")->AsString=ser_num;

//						:PARAM_FL_POISK,
//						:PARAM_FL_OST,
//						:PARAM_STR_PARAM,
//						:PARAM_IDFIRM,
//						:PARAM_IDSKLAD,
//						:PARAM_IDTNOM


Table->Open();


return result;
}
//----------------------------------------------------------------------------
//поиск по заводскому номеру строка
bool TREM_DMSprHardwareVZip::Table_FindPoSerNumStrLike(__int64 id_grp, bool all, UnicodeString ser_num)
{
bool result=false;

//IdGrp=id_grp;
//AllElement=all;
//
//UnicodeString zapros="";
//
//if(all==true)
//		{//без групп
//		zapros=zapros+" select *";
//		zapros=zapros+" from REM_SHARDWARE";
//		zapros=zapros+" where upper(rem_shardware.sernum_str_rem_shardware) like upper('%"+
//						  ser_num+"%')";
//		zapros=zapros+" ORDER BY NAME_REM_SHARDWARE";
//		} //без групп
//else
//		{ //по группам
//		if (id_grp==0)
//				{ //корневой каталог
//				zapros=zapros+"  select *";
//				zapros=zapros+" from REM_SHARDWARE";
//				zapros=zapros+" where rem_shardware.idgrp_rem_shardware is null ";
//				zapros=zapros+" and upper(rem_shardware.sernum_str_rem_shardware) like upper('%"+
//						  ser_num+"%')";
//				zapros=zapros+"  ORDER BY NAME_REM_SHARDWARE";
//				}
//		else    //задана группа
//				{
//				zapros=zapros+" select *";
//				zapros=zapros+" from REM_SHARDWARE";
//				zapros=zapros+" where rem_shardware.idgrp_rem_shardware="+IntToStr(IdGrp);
//				zapros=zapros+" and upper(rem_shardware.sernum_str_rem_shardware) like upper('%"+
//						  ser_num+"%')";
//				zapros=zapros+" ORDER BY NAME_REM_SHARDWARE";
//				}
//		}
//
//Table->Active=false;
//Table->SelectSQL->Clear();
//Table->SelectSQL->Add(zapros);
//Table->Open();

return result;
}
//----------------------------------------------------------------------------
