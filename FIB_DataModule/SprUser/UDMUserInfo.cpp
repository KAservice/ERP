//---------------------------------------------------------------------------
#include "glPCH.h"
#pragma hdrstop

#include "UDMUserInfo.h"

#include "DateUtils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "pFIBQuery"
#pragma link "IB_Services"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMUserInfo::TDMUserInfo(TComponent* Owner, TDM * dm_connection)
        : TDataModule(Owner)
{
DM_Connection=dm_connection;
Transaction->DefaultDatabase=DM_Connection->pFIBData;
Element->Database=DM_Connection->pFIBData;
Query->Database=DM_Connection->pFIBData;


}
//---------------------------------------------------------------------------
void __fastcall TDMUserInfo::DataModuleDestroy(TObject *Sender)
{
Element->Active=false;
}

//---------------------------------------------------------------------------

bool TDMUserInfo::OpenElement(__int64 id)
{
bool result=true;

Element->Active=false;
Element->ParamByName("ID")->AsInt64=id;
Element->Active=true;

return result;
}

//---------------------------------------------------------------------------
__int64 TDMUserInfo::FindPoName(UnicodeString name_user)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_USER from SUSER where NAME_USER='"+name_user+"'");
Query->ExecQuery();
result=Query->FieldByName("ID_USER")->AsInt64;
Query->Close();
OpenElement(result);
return result;
}
//---------------------------------------------------------------------------
__int64 TDMUserInfo::FindPoPassword(UnicodeString password)
{
__int64 result;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_USER from SUSER where PASSWORD_USER='"+password+"'");
Query->ExecQuery();
result=Query->FieldByName("ID_USER")->AsInt64;
Query->Close();
return result;
}
//---------------------------------------------------------------------------
__int64 TDMUserInfo::GetIdGrpUser(__int64 id_user)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select IDGRP_USER from SUSER where ID_USER='"+IntToStr(id_user)+"'");
Query->ExecQuery();
result=Query->FieldByName("IDGRP_USER")->AsInt64;
Query->Close();
return result;
}
//----------------------------------------------------------------------------
TDateTime TDMUserInfo::GetPosNachReport(void)
{
TDateTime result=0;
switch (ElementTPOSREPORT_SUSER->AsInteger)
	{
	case 0:  //не задан
		{
		result=Date()-DayOf(Date())+1;
		}break;
	case 1:  //начало года
		{

		}break;
	case 2:   //начало квартала
		{

		}break;
	case 3:   //начало месяца
		{
        result=Date()-DayOf(Date())+1;
		}break;
	case 4:  //начало дня
		{
        result=Date();
		}break;

	case 5:   //количество дней
		{
		result=Date()-ElementKOLDAYREP_SUSER->AsInteger;
		}break;
	}
if (result<Date()-10000)
	{
	result=Date()-DayOf(Date())+1;
	}
return result;
}
//----------------------------------------------------------------------------
TDateTime TDMUserInfo::GetPosNachGurnal(void)
{
TDateTime result=0;
switch (ElementTPOSGOURNAL_SUSER->AsInteger)
	{
	case 0:  //не задан
		{
		result=Date()-DayOf(Date())+1;
		}break;
	case 1:  //начало года
		{

		}break;
	case 2:   //начало квартала
		{

		}break;
	case 3:   //начало месяца
		{
        result=Date()-DayOf(Date())+1;
		}break;
	case 4:  //начало дня
		{
        result=Date();
		}break;

	case 5:   //количество дней
		{
		result=Date()-ElementKOLDAYGUR_SUSER->AsInteger;
		}break;
	}

if (result<Date()-10000)
	{
	result=Date()-DayOf(Date())+1;
	}
return result;



}
//-----------------------------------------------------------------------------
bool TDMUserInfo::GetPrivDM( int object)
{
bool result=false;
ExecPriv=false;
InsertPriv=false;
EditPriv=false;
DeletePriv=false;

Query->Close();

UnicodeString zapros="select object_base_priv.exec_object_base_priv, \
							object_base_priv.ins_object_base_priv,                       \
							object_base_priv.edit_object_base_priv,                      \
							object_base_priv.del_object_base_priv      \
							from object_base_priv                                                \
						where object_base_priv.idgrpuser_object_base_priv=:PARAM_IDGRP_USER  \
							and object_base_priv.application_object_base_priv=:PARAM_APPL    \
							and object_base_priv.number_object_base_priv=:PARAM_OBJECT";

Query->SQL->Clear();
Query->SQL->Add(zapros);
Query->ParamByName("PARAM_IDGRP_USER")->AsString=ElementIDGRP_USER->AsString;
Query->ParamByName("PARAM_APPL")->AsInteger=TypeApplication;
Query->ParamByName("PARAM_OBJECT")->AsInteger=object;

try
	{
	Query->ExecQuery();
	if (Query->FieldByName("EXEC_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		ExecPriv=true;
		}

	if (Query->FieldByName("INS_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		InsertPriv=true;
		}

	if (Query->FieldByName("EDIT_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		EditPriv=true;
		}

	if (Query->FieldByName("DEL_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		DeletePriv=true;
		}
	result=true;
	}
catch(Exception &exception)
	{
	TextError=exception.Message;
	result=false;
	}


Query->Close();

return result;
}
//----------------------------------------------------------------------------
bool TDMUserInfo::GetPrivForm(int object)
{
bool result=false;
ExecPriv=false;
InsertPriv=false;
EditPriv=false;
DeletePriv=false;

Query->Close();

UnicodeString zapros="select object_base_priv.exec_object_base_priv, \
							object_base_priv.ins_object_base_priv,                       \
							object_base_priv.edit_object_base_priv,                      \
							object_base_priv.del_object_base_priv      \
							from object_base_priv                                                \
						where object_base_priv.idgrpuser_object_base_priv=:PARAM_IDGRP_USER  \
							and object_base_priv.number_object_base_priv=:PARAM_OBJECT";

Query->SQL->Clear();
Query->SQL->Add(zapros);
Query->ParamByName("PARAM_IDGRP_USER")->AsString=ElementIDGRP_USER->AsString;
Query->ParamByName("PARAM_OBJECT")->AsInteger=object;

try
	{
	Query->ExecQuery();
	if (Query->FieldByName("EXEC_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		ExecPriv=true;
		}

	if (Query->FieldByName("INS_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		InsertPriv=true;
		}

	if (Query->FieldByName("EDIT_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		EditPriv=true;
		}

	if (Query->FieldByName("DEL_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		DeletePriv=true;
		}
	result=true;
	}
catch(Exception &exception)
	{
	TextError=exception.Message;
	result=false;
	}

Query->Close();
return result;
}
//-----------------------------------------------------------------------------



