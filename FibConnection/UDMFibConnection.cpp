//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop



#include "UDMFibConnection.h"
#include "UkanFile.h"
#include "UkanTxtFile.h"
#include "DateUtils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma link "pFIBSQLLog"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TDMFibConnection::TDMFibConnection(TComponent* Owner)
        : TDataModule(Owner)
{
pFIBData->Connected=false;
}
//---------------------------------------------------------------------------
void __fastcall TDMFibConnection::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TDMFibConnection::DataModuleDestroy(TObject *Sender)
{
//if (glUser!=0) delete glUser;
//IBData->Connected=false;

if (pFIBData->Connected)	{
	//for (i = 0; i < pFIBData->TransactionCount-1; i++) {
	//	if (pFIBTr(pFIBData->Transactions[i]).InTransaction) {
	//	pFIBTr
	//	}
	//}

	pFIBData->CloseDataSets();
	pFIBData->Connected=false;
	}
}
//---------------------------------------------------------------------------
void TDMFibConnection::DisconnectBase(void)
{
// if (glUser!=0) delete glUser;
// glUser=0;
//IBData->Connected=false;

if (pFIBData->Connected)
	{ 
	pFIBData->CloseDataSets();
	pFIBData->Connected=false;
	}
}
//-------------------------------------------------------------------------
bool TDMFibConnection::CheckEnableStart(UnicodeString role_user)
{
bool result=false;


return result;		
}
//---------------------------------------------------------------------------
bool TDMFibConnection::GlobConnect(void)
{
bool Res=false;
//glNameUser=NameUser;
TextVipOper="Выполненные операции:";

NameServer=GetNameServer(ConnectString);
UnicodeString role_user;

try
		{
		//
		if (NameUser=="SYSDBA")
			{
			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name="+NameUser);
			pFIBData->DBParams->Add(" lc_ctype=UTF8");
			pFIBData->DBParams->Add(" password="+PasswordUser);
			pFIBData->Connected=true;

            TextVipOper="Подключение SYSDBA - OK";
			}
		else
			{//подключаемся с мин. правами, получаем роль и имя пользователя
			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->ConnectParams->CharSet="UTF8";
			pFIBData->DBParams->Add(" user_name=USERINFO");
			pFIBData->DBParams->Add(" lc_ctype=UTF8");
			pFIBData->DBParams->Add(" sql_role_name=ROLE_USERINFO");
			pFIBData->DBParams->Add(" password=123");
			pFIBData->Connected=true;
			TextVipOper=TextVipOper+" Подключение USERINFO - OK";

			Query->Close();
			Query->SQL->Clear();
			Query->SQL->Add(" select NAME2_USER, IDGRP_USER from SUSER where NAME_USER='"+NameUser+"'");
			Query->ExecQuery();
			TextVipOper=TextVipOper+" Получение NAME2 - OK";

			NameUser2=Query->FieldByName("NAME2_USER")->AsString;
			__int64 idgrp_user=Query->FieldByName("IDGRP_USER")->AsInt64;
			Query->Close();
			Query->SQL->Clear();
			Query->SQL->Add(" select ROLE_SGRPUSER from SGRPUSER where ID_SGRPUSER="+IntToStr(idgrp_user));
			Query->ExecQuery();
			TextVipOper=TextVipOper+" Получение роли пользователя - OK";

			role_user=Query->FieldByName("ROLE_SGRPUSER")->AsString;

			pFIBData->Connected=false;

            CheckEnableStart(role_user);

			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name="+NameUser2);
			pFIBData->DBParams->Add(" lc_ctype=UTF8");
			pFIBData->DBParams->Add(" sql_role_name="+role_user);
			pFIBData->DBParams->Add(" password="+PasswordUser);
			pFIBData->Connected=true;
			TextVipOper=TextVipOper+" Подключение с NAME2 - OK";
			}

		//найдем пользователя
		__int64 id_user=FindPoName(NameUser);
		if(id_user>0)
			{
			OpenUserInfo(id_user);
			Res=true;
			}
		else
			{
			TextError="Ошибка! Не найден пользователь!";
			Res=false;
			}

        GetVersionBase();
        }
catch (Exception &exception)
		{
		Error=true;
		TextError=exception.Message+"  Name:'"+NameUser2+"'  Role:'"+role_user
		+"'\n  "+TextVipOper;
		Res=false;
		pFIBData->Connected=false;
        }

return Res;
}
//---------------------------------------------------------------------------
bool TDMFibConnection::GlobConnect2(void)
{
bool Res=false;

UnicodeString role_user="";
//glNameUser=NameUser;
try
        {
		if (NameUser=="SYSDBA")
			{
			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name="+NameUser);
			pFIBData->DBParams->Add(" lc_ctype=UTF8");
			pFIBData->DBParams->Add(" password="+PasswordUser);
			pFIBData->Connected=true;
			}
		else
			{//подключаемся с мин. правами, получаем роль и имя пользователя
			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name=USERINFO");
			pFIBData->DBParams->Add(" lc_ctype=UTF8");
			pFIBData->DBParams->Add(" sql_role_name=ROLE_USERINFO");
			pFIBData->DBParams->Add(" password=123");
			pFIBData->Connected=true;

			Query->Close();
			Query->SQL->Clear();
			Query->SQL->Add(" select NAME2_USER, IDGRP_USER from SUSER where NAME_USER='"+NameUser+"'");
			Query->ExecQuery();
			NameUser2=Query->FieldByName("NAME2_USER")->AsString;
			__int64 idgrp_user=Query->FieldByName("IDGRP_USER")->AsInt64;
			Query->Close();
			Query->SQL->Clear();
			Query->SQL->Add(" select ROLE_SGRPUSER from SGRPUSER where ID_SGRPUSER="+IntToStr(idgrp_user));
			Query->ExecQuery();
			role_user=Query->FieldByName("ROLE_SGRPUSER")->AsString;

			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name="+NameUser2);
			pFIBData->DBParams->Add(" lc_ctype=UTF8");
			pFIBData->DBParams->Add(" sql_role_name="+role_user);
			pFIBData->DBParams->Add(" password="+PasswordUser);
			pFIBData->Connected=true;
			}

//		if (glUser->FindPoName(NameUser)==1)
//				{
//
//				}

		//найдем пользователя
		__int64 id_user=FindPoName(NameUser);
		if(id_user>0)
			{
			OpenUserInfo(id_user);
			Res=true;
			}
		else
			{
			TextError="Ошибка! Не найден пользователь!";
			Res=false;
			}

		GetVersionBase();

        }
catch (Exception &exception)
        {
        Error=true;
        Res=false;
		TextError=exception.Message+"  Name:'"+NameUser2+"'  Role:'"+role_user
		+"'\n  "+TextVipOper;
		pFIBData->Connected=false;
        TextError=exception.Message;
        }
return Res;
}
//---------------------------------------------------------------------------
bool TDMFibConnection::GlobConnect3(void)
{
bool Res=false;
UnicodeString role_user="";
//glNameUser=NameUser;
try
        {
			//подключаемся с мин. правами, получаем роль и имя пользователя
			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name=USERINFO");
			pFIBData->DBParams->Add(" lc_ctype=UTF8");
			pFIBData->DBParams->Add(" sql_role_name=ROLE_USERINFO");
			pFIBData->DBParams->Add(" password=123");
			pFIBData->Connected=true;

			Query->Close();
			Query->SQL->Clear();
			Query->SQL->Add(" select NAME2_USER, NAME_USER, IDGRP_USER from SUSER where ID_USER='"+IntToStr(CodeUser)+"'");
			Query->ExecQuery();
			NameUser=Query->FieldByName("NAME_USER")->AsString;
			NameUser2=Query->FieldByName("NAME2_USER")->AsString;
			__int64 idgrp_user=Query->FieldByName("IDGRP_USER")->AsInt64;
			Query->Close();
			Query->SQL->Clear();
			Query->SQL->Add(" select ROLE_SGRPUSER from SGRPUSER where ID_SGRPUSER="+IntToStr(idgrp_user));
			Query->ExecQuery();
			role_user=Query->FieldByName("ROLE_SGRPUSER")->AsString;

			pFIBData->Connected=false;
			pFIBData->DBName=ConnectString;
			pFIBData->DBParams->Clear();
			pFIBData->DBParams->Add(" user_name="+NameUser2);
			pFIBData->DBParams->Add(" lc_ctype=UTF8");
			pFIBData->DBParams->Add(" sql_role_name="+role_user);
			pFIBData->DBParams->Add(" password="+PasswordUser);
			pFIBData->Connected=true;

		//найдем пользователя
		__int64 id_user=FindPoName(NameUser);
		if(id_user>0)
			{
			OpenUserInfo(id_user);
			Res=true;
			}
		else
			{
			TextError="Ошибка! Не найден пользователь!";
			Res=false;
			}
			GetVersionBase();

        }
catch (Exception &exception)
        {
        Error=true;
        Res=false;
		TextError=exception.Message+"  Name:'"+NameUser2+"'  Role:'"+role_user
		+"'\n  "+TextVipOper;
		pFIBData->Connected=false;
        TextError=exception.Message;
        }
return Res;
}
//----------------------------------------------------------------------------
UnicodeString TDMFibConnection::GetNameServer(UnicodeString connect_string)
{
UnicodeString result="";
int num=connect_string.Pos(":");
result=connect_string.SetLength(num-1);

return result;
}
//----------------------------------------------------------------------------
UnicodeString TDMFibConnection::GetVersionBase(void)
{
AnsiString result="";
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select * from SYSTEM");
Query->ExecQuery();
UnicodeString HVer=Query->Fields[1]->Name;
UnicodeString LVer=Query->Fields[2]->Name;
Query->Close();
result=HVer.Delete(1,5)+"."+LVer.Delete(1,5);

return result;
}
//---------------------------------------------------------------------------
bool TDMFibConnection::OpenUserInfo(__int64 id)
{
bool result=true;

UserInfo->Active=false;
UserInfo->ParamByName("ID")->AsInt64=id;
UserInfo->Active=true;

return result;
}

//---------------------------------------------------------------------------
__int64 TDMFibConnection::FindPoName(UnicodeString name_user)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_USER from SUSER where NAME_USER='"+name_user+"'");
Query->ExecQuery();
result=Query->FieldByName("ID_USER")->AsInt64;
Query->Close();
OpenUserInfo(result);
return result;
}
//---------------------------------------------------------------------------
__int64 TDMFibConnection::FindPoPassword(UnicodeString password)
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
__int64 TDMFibConnection::GetIdGrpUser(__int64 id_user)
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
TDateTime TDMFibConnection::GetPosNachReport(void)
{
TDateTime result=0;
switch (UserInfoTPOSREPORT_SUSER->AsInteger)
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
		result=Date()-UserInfoKOLDAYREP_SUSER->AsInteger;
		}break;
	}
if (result<Date()-10000)
	{
	result=Date()-DayOf(Date())+1;
	}
return result;
}
//----------------------------------------------------------------------------
TDateTime TDMFibConnection::GetPosNachGurnal(void)
{
TDateTime result=0;
switch (UserInfoTPOSGOURNAL_SUSER->AsInteger)
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
		result=Date()-UserInfoKOLDAYGUR_SUSER->AsInteger;
		}break;
	}
//
if (result<Date()-10000)
	{
	result=Date()-DayOf(Date())+1;
	}
return result;



}
//-----------------------------------------------------------------------------
bool TDMFibConnection::GetPrivDM( int object)
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
Query->ParamByName("PARAM_IDGRP_USER")->AsString=UserInfoIDGRP_USER->AsString;
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

if (TypeApplication!=2)
	{
	ExecPriv=true;
	InsertPriv=true;
	EditPriv=true;
	DeletePriv=true;
	}

return result;
}
//----------------------------------------------------------------------------
bool TDMFibConnection::GetPrivForm(int object)
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
Query->ParamByName("PARAM_IDGRP_USER")->AsString=UserInfoIDGRP_USER->AsString;
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

if (TypeApplication!=2)
	{
	ExecPriv=true;
	InsertPriv=true;
	EditPriv=true;
	DeletePriv=true;
	}

return result;
}
//----------------------------------------------------------------------------
bool TDMFibConnection::OpenARMInfo(int code_arm)
{
bool result=false;
ARMInfo->Active=false;
ARMInfo->ParamByName("PARAM_CODE")->AsInteger=code_arm;
ARMInfo->Active=true;
if (ARMInfo->RecordCount==1)
	{
	result=true;
	}
else
	{
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------
void TDMFibConnection::glSaveProtocol(UnicodeString str)
{
UnicodeString FileNameProtocol="";
if (glCatalogProtocol=="")
		{
		FileNameProtocol=ExtractFileDir(Application->ExeName)+"\\"+ DateToStr(Date())+".txt";
		}
else
		{
		FileNameProtocol=glCatalogProtocol+"\\"+ DateToStr(Date())+".txt";
		}

str=TimeToStr(Time())+" "+NameUser+" "+str;

TkanTxtFile * f=new TkanTxtFile;
f->AddString(FileNameProtocol,str);
delete f;
}
//---------------------------------------------------------------------------
void TDMFibConnection::AddLog(__int64 id_user,
					int type,
					int object,
					int oper,
					UnicodeString message,
					UnicodeString code_object,
					__int64 id_object,
					int subsystem)
{
int application=0;
UnicodeString name_file=ExtractFileName(Application->ExeName);
if (name_file=="PAdmin.exe") {application=1;}
if (name_file=="PArmKas.exe") {application=2;}
if (name_file=="PArmOf.exe") {application=3;}
if (name_file=="DBServ20.dll") {application=4;}
if (name_file=="DBServ10.dll") {application=4;}

try
	{
	pFIBQLog->Close();
	if (id_user!=0) pFIBQLog->ParamByName("IDUSER_LOG")->AsInt64=id_user;
	pFIBQLog->ParamByName("TYPE_LOG")->AsInteger=type;
	pFIBQLog->ParamByName("OBJECT_LOG")->AsInteger=object;
	pFIBQLog->ParamByName("OPER_LOG")->AsInteger=oper;
	pFIBQLog->ParamByName("MESSAGE_LOG")->AsString=message;

	pFIBQLog->ParamByName("APPLICATION_LOG")->AsInteger=application;
	pFIBQLog->ParamByName("CODEOB_LOG")->AsString=code_object;
	pFIBQLog->ParamByName("IDOBJECT_LOG")->AsInt64=id_object;
	pFIBQLog->ParamByName("SUBSYSTEM_LOG")->AsInteger=subsystem;

	pFIBQLog->ExecQuery();
	pFIBTrLog->Commit();
	pFIBQLog->Close();
	}
catch (...) {}
}

//---------------------------------------------------------------------------
UnicodeString TDMFibConnection::Arm_GetParameter(UnicodeString parameter)
{
UnicodeString str_parameter=ARMInfoSTRPAR_SARM->AsString;
UnicodeString result="";
int position=0;
position=str_parameter.Pos(parameter);
if (position!=0)
        {
        str_parameter.Delete(1,position+parameter.Length());
        for(int i=1; i<=str_parameter.Length();i++)
                {
                if (str_parameter[i]==';')
                        {
                         break;
                        }
                else
                        {
                         result=result+str_parameter[i];
                        }
                }
        }
return result;
}
//-----------------------------------------------------------------------------
