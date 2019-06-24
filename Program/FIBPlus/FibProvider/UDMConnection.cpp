//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMConnection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
TDMConnection *DMConnection;
//---------------------------------------------------------------------------
__fastcall TDMConnection::TDMConnection(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMConnection::DataModuleDestroy(TObject *Sender)
{
if (Database->Connected)	{
	//for (i = 0; i < pFIBData->TransactionCount-1; i++) {
	//	if (pFIBTr(pFIBData->Transactions[i]).InTransaction) {
	//	pFIBTr
	//	}
	//}

	//Database->CloseDataSets();
	}
Database->Connected=false;
}
//---------------------------------------------------------------------------

void __fastcall TDMConnection::DataModuleCreate(TObject *Sender)
{
Database->Connected=false;
}
//---------------------------------------------------------------------------
void TDMConnection::DisconnectBase(void)
{
if (Database->Connected)
	{
	//Database->CloseDataSets();
	Database->Connected=false;
	}


}
//----------------------------------------------------------------------------
bool TDMConnection::ConnectBase(void)
{
bool result=false;
flError=false;
TextVipOper="Выполненные операции:";

UnicodeString role_user;

try
		{
		Database->Connected=false;
		Database->DBName=ConnectString;
		Database->ConnectParams->CharSet=CharSet;

		if (UserName=="SYSDBA")
			{
			Database->ConnectParams->UserName=UserName;
			Database->ConnectParams->RoleName=RoleName;
			Database->ConnectParams->Password=Password;
			Database->Connected=true;

            TextVipOper="Подключение SYSDBA - OK";
			}
		else
			{//подключаемся с мин. правами, получаем роль и имя пользователя

			Database->ConnectParams->UserName="USERINFO";
			Database->ConnectParams->RoleName="ROLE_USERINFO";
			Database->ConnectParams->Password="123";
			Database->Connected=true;
			TextVipOper=TextVipOper+" Подключение USERINFO - OK";

			Query->Close();
			Query->SQL->Clear();
			Query->SQL->Add(" select NAME2_USER, IDGRP_USER from SUSER where NAME_USER='"+UserName+"'");
			Query->ExecQuery();
			TextVipOper=TextVipOper+" Получение NAME2 - OK";

			UserName2=Query->FieldByName("NAME2_USER")->AsString;
			__int64 idgrp_user=Query->FieldByName("IDGRP_USER")->AsInt64;
			Query->Close();
			Query->SQL->Clear();
			Query->SQL->Add(" select ROLE_SGRPUSER from SGRPUSER where ID_SGRPUSER="+IntToStr(idgrp_user));
			Query->ExecQuery();
			TextVipOper=TextVipOper+" Получение роли пользователя - OK";

			role_user=Query->FieldByName("ROLE_SGRPUSER")->AsString;

			Database->Connected=false;

			Database->ConnectParams->UserName=UserName2;
			Database->ConnectParams->RoleName=role_user;
			Database->ConnectParams->Password=Password;
			Database->Connected=true;

			TextVipOper=TextVipOper+" Подключение с NAME2 - OK";
			}
		result=true;
		flError=false;
		TextError="Ошибок нет";
        }
catch (Exception &exception)
		{
		flError=true;
		result=false;
		TextError=exception.Message+"  Name:'"+UserName2+"'  Role:'"+role_user
		+"'\n  "+TextVipOper;
		Database->Connected=false;
		}

return result;
}
//-----------------------------------------------------------------------------

