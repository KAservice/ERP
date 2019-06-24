//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprHardware.h"
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

__fastcall TREM_DMSprHardware::TREM_DMSprHardware(TComponent* Owner)
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
bool TREM_DMSprHardware::Init(void)
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
int TREM_DMSprHardware::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprHardware::DataModuleDestroy(TObject *Sender)
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
UnicodeString TREM_DMSprHardware::GetTextQuery(__int64 id_grp, bool all)
{
UnicodeString result="";
if(all==true)
		{//без групп
		result=result+" select *";
		result=result+" from REM_SHARDWARE";
		result=result+" ORDER BY NAME_REM_SHARDWARE";
		} //без групп
else
		{ //по группам
		if (id_grp==0)
				{ //корневой каталог
				result=result+"  select *";
				result=result+" from REM_SHARDWARE";
				result=result+" where rem_shardware.idgrp_rem_shardware is null";
				result=result+"  ORDER BY NAME_REM_SHARDWARE";
				}
		else    //задана группа
				{
				result=result+" select *";
				result=result+" from REM_SHARDWARE";
				result=result+" where rem_shardware.idgrp_rem_shardware="+IntToStr(IdGrp);
				result=result+" ORDER BY NAME_REM_SHARDWARE";
				}
		}
return result;
}
//---------------------------------------------------------------------------
void  TREM_DMSprHardware::OpenTable(__int64 id_grp,bool all)
{
IdGrp=id_grp;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
UnicodeString zapros="select *                                              \
					from REM_SHARDWARE_GET_TABLE_FULL (                     \
						:PARAM_IDGRP,                                       \
						:PARAM_FL_ALL,                                      \
						:PARAM_FL_POISK,                                    \
						:PARAM_FL_OST,                                      \
						:PARAM_STR_PARAM,                                   \
						:PARAM_IDFIRM,                                      \
						:PARAM_IDSKLAD,                                     \
						:PARAM_IDTNOM)                                      \
					ORDER BY REM_SHARDWARE_GET_TABLE_FULL.NAME_REM_SHARDWARE";
Table->SelectSQL->Add(zapros);

Table->ParamByName("PARAM_IDGRP")->AsString=id_grp;
if (all==true)
	{
	 Table->ParamByName("PARAM_FL_ALL")->AsInteger=1;
	}
else
	{
	Table->ParamByName("PARAM_FL_ALL")->AsInteger=0;
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

bool  TREM_DMSprHardware::NewElement(__int64 id_grp)
{
bool result=false;
Element->Active=false;

if (flCentralBase==false)
	{
	TextError="Добавлять новые элементы можно только в центральной базе!";
	return result;
	}

try
		{
		Element->Open();
		Element->Append();
		if (id_grp!=0)
			{
			ElementIDGRP_REM_SHARDWARE->AsString=id_grp;
			}

		ElementCODE_REM_SHARDWARE->AsInteger=GetCodeNom()+1;
		Element->Post();

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

int TREM_DMSprHardware::OpenElement(__int64 id)
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
__int64 TREM_DMSprHardware::FindPoName(UnicodeString name)
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
bool  TREM_DMSprHardware::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_REM_SHARDWARE->AsString);

//проверить код на уникальность
if (CheckCode(glStrToInt64(ElementID_REM_SHARDWARE->AsString),
			 ElementCODE_REM_SHARDWARE->AsInteger)==true)
	{
	res=false;
	TextError="Код не уникальный!";
	return res;
	}

try
        {

		Element->ApplyUpdates();
		IBTrUpdate->Commit();

		OpenElement(IdElement);
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
bool TREM_DMSprHardware::DeleteElement(__int64 id)
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
void TREM_DMSprHardware::ChancheGrp(__int64 new_id_grp, __int64 id_el)
{
OpenElement(id_el);
Element->Edit();
ElementIDGRP_REM_SHARDWARE->AsString=new_id_grp;
Element->Post();
SaveElement();
}
//---------------------------------------------------------------------------

__int64 TREM_DMSprHardware::GetIdGrpElementa(__int64 id_element)
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

void __fastcall TREM_DMSprHardware::ElementTDOC_DOCPOSTGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
Text=glGetNameDoc(ElementTDOC_DOCPOST->AsString)+" №"+ElementNUMDOC_DOCPOST->AsString+
				" от "+ElementPOSDOC_DOCPOST->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprHardware::ElementTDOC_DOCSALEGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
Text=glGetNameDoc(ElementTDOC_DOCSALE->AsString)+" №"+ElementNUMDOC_DOCSALE->AsString+
				" от "+ElementPOSDOC_DOCSALE->AsString;
}
//---------------------------------------------------------------------------
int TREM_DMSprHardware::GetCodeNom(void)
{
int result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("SELECT GEN_ID(GEN_REM_SHARDWARE_CODE,1) FROM RDB$DATABASE");
Query->ExecQuery();
result=Query->FieldByName("GEN_ID")->AsInteger;
Query->Close();

return result;
}
//---------------------------------------------------------------------------
bool TREM_DMSprHardware::CheckCode(__int64 id_hw, int code)
{
//возвращает true если код не уникальный
bool result=false;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_REM_SHARDWARE");
Query->SQL->Add(" from rem_SHARDWARE");
Query->SQL->Add(" where CODE_REM_SHARDWARE=:PARAM_CODE");
Query->ParamByName("PARAM_CODE")->AsString=code;
Query->ExecQuery();

		while(!Query->Eof)
			{
			if (id_hw!=glStrToInt64(Query->FieldByName("ID_REM_SHARDWARE")->AsString))
				{
				result=true;
				}
			Query->Next();
			}
Query->Close();
return result;
}
//----------------------------------------------------------------------------
__int64 TREM_DMSprHardware::GetIdPoCodu(int code)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_REM_SHARDWARE");
Query->SQL->Add(" from rem_SHARDWARE");
Query->SQL->Add(" where CODE_REM_SHARDWARE=:PARAM_CODE");
Query->ParamByName("PARAM_CODE")->AsString=code;
Query->ExecQuery();

result=glStrToInt64(Query->FieldByName("ID_REM_SHARDWARE")->AsString);

Query->Close();
return result;
}
//----------------------------------------------------------------------------
//поиск по заводскому номеру
bool TREM_DMSprHardware::Table_FindPoSerNum1Like(__int64 id_grp, bool all, UnicodeString ser_num)
{
bool result=false;

IdGrp=id_grp;
AllElement=all;

UnicodeString zapros="select *                                              \
					from REM_SHARDWARE_GET_TABLE_FULL (                     \
						:PARAM_IDGRP,                                       \
						:PARAM_FL_ALL,                                      \
						:PARAM_FL_POISK,                                    \
						:PARAM_FL_OST,                                      \
						:PARAM_STR_PARAM,                                   \
						:PARAM_IDFIRM,                                      \
						:PARAM_IDSKLAD,                                     \
						:PARAM_IDTNOM)                                      \
					ORDER BY REM_SHARDWARE_GET_TABLE_FULL.NAME_REM_SHARDWARE";

Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_IDGRP")->AsString=id_grp;
if (all==true)
	{
	 Table->ParamByName("PARAM_FL_ALL")->AsInteger=1;
	}
else
	{
	Table->ParamByName("PARAM_FL_ALL")->AsInteger=0;
	}
Table->ParamByName("PARAM_FL_POISK")->AsInteger=1;
Table->ParamByName("PARAM_STR_PARAM")->AsString=ser_num;

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
bool TREM_DMSprHardware::Table_FindPoSerNum2Like(__int64 id_grp, bool all, UnicodeString ser_num)
{
bool result=false;

IdGrp=id_grp;
AllElement=all;

UnicodeString zapros="select *                                              \
					from REM_SHARDWARE_GET_TABLE_FULL (                     \
						:PARAM_IDGRP,                                       \
						:PARAM_FL_ALL,                                      \
						:PARAM_FL_POISK,                                    \
						:PARAM_FL_OST,                                      \
						:PARAM_STR_PARAM,                                   \
						:PARAM_IDFIRM,                                      \
						:PARAM_IDSKLAD,                                     \
						:PARAM_IDTNOM)                                      \
					ORDER BY REM_SHARDWARE_GET_TABLE_FULL.NAME_REM_SHARDWARE";

Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_IDGRP")->AsString=id_grp;
if (all==true)
	{
	 Table->ParamByName("PARAM_FL_ALL")->AsInteger=1;
	}
else
	{
	Table->ParamByName("PARAM_FL_ALL")->AsInteger=0;
	}
Table->ParamByName("PARAM_FL_POISK")->AsInteger=2;
Table->ParamByName("PARAM_STR_PARAM")->AsString=ser_num;

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
bool TREM_DMSprHardware::Table_FindPoSerNumStrLike(__int64 id_grp, bool all, UnicodeString ser_num)
{
bool result=false;

IdGrp=id_grp;
AllElement=all;

UnicodeString zapros="";

if(all==true)
		{//без групп
		zapros=zapros+" select *";
		zapros=zapros+" from REM_SHARDWARE";
		zapros=zapros+" where upper(rem_shardware.sernum_str_rem_shardware) like upper('%"+
						  ser_num+"%')";
		zapros=zapros+" ORDER BY NAME_REM_SHARDWARE";
		} //без групп
else
		{ //по группам
		if (id_grp==0)
				{ //корневой каталог
				zapros=zapros+"  select *";
				zapros=zapros+" from REM_SHARDWARE";
				zapros=zapros+" where rem_shardware.idgrp_rem_shardware is null ";
				zapros=zapros+" and upper(rem_shardware.sernum_str_rem_shardware) like upper('%"+
						  ser_num+"%')";
				zapros=zapros+"  ORDER BY NAME_REM_SHARDWARE";
				}
		else    //задана группа
				{
				zapros=zapros+" select *";
				zapros=zapros+" from REM_SHARDWARE";
				zapros=zapros+" where rem_shardware.idgrp_rem_shardware="+IntToStr(IdGrp);
				zapros=zapros+" and upper(rem_shardware.sernum_str_rem_shardware) like upper('%"+
						  ser_num+"%')";
				zapros=zapros+" ORDER BY NAME_REM_SHARDWARE";
				}
		}

Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(zapros);
Table->Open();

return result;
}
//----------------------------------------------------------------------------
