//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMQueryUpdate.h"
#include "UDMConnection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
extern TDMConnection *DMConnection;
//---------------------------------------------------------------------------
__fastcall TDMQueryUpdate::TDMQueryUpdate(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMQueryUpdate::DataModuleDestroy(TObject *Sender)
{
Query->Close();
}
//---------------------------------------------------------------------------
void TDMQueryUpdate::CloseQuery(void)
{

Query->Close();

}
//---------------------------------------------------------------------------
void TDMQueryUpdate::ClearTextSQL(void)
{

Query->SQL->Clear();

}
//---------------------------------------------------------------------------
void TDMQueryUpdate::SetTextSQL(UnicodeString text_sql)
{

Query->SQL->Text=text_sql;

}
//---------------------------------------------------------------------------
bool TDMQueryUpdate::SetStringParamQuery(UnicodeString param_name, UnicodeString param_value)
{
bool result=false;
try
		{
		Query->ParamByName(param_name)->AsString=param_value;
		flError=false;
		result=true;
		TextError="Ошибок нет";
		}
catch(Exception &exception)
				{
				flError=true;
				result=false;
				TextError=exception.Message;
				}
return result;
}
//---------------------------------------------------------------------------
bool TDMQueryUpdate::ExecQuery(void)
{
bool result=false;
try
		{
		Query->ExecQuery();
		flError=false;
		result=true;
		TextError="Ошибок нет";
		}
catch(Exception &exception)
				{
				flError=true;
				result=false;
				TextError=exception.Message;
				}
return result;


}
//---------------------------------------------------------------------------
bool TDMQueryUpdate::ExecProc(void)
{
bool result=false;
try
		{
		Query->ExecProc();
		flError=false;
		result=true;
		TextError="Ошибок нет";
		}
catch(Exception &exception)
				{
				flError=true;
				result=false;
				TextError=exception.Message;
				}
return result;


}
//---------------------------------------------------------------------------
bool TDMQueryUpdate::NextRecord(void)
{

Query->Next();
return true;
}
//---------------------------------------------------------------------------

bool TDMQueryUpdate::GetRecord(void)
{


return false;
}
//---------------------------------------------------------------------------
UnicodeString TDMQueryUpdate::GetStringValueField(UnicodeString field_name)
{
UnicodeString result="";
try
		{
		result=Query->FieldByName(field_name)->AsString;
		flError=false;
		TextError="Ошибок нет";
		}
catch(Exception &exception)
				{
				flError=true;
				TextError=exception.Message;
				}
return result;
}
//---------------------------------------------------------------------------

bool TDMQueryUpdate::StartTransaction(void)
{
bool result=false;
try
		{
		Transaction->StartTransaction();
		result=true;
		flError=false;
		TextError="Ошибок нет";
		}
catch(Exception &exception)
				{
				flError=true;
				TextError=exception.Message;
				}
return result;
}
//---------------------------------------------------------------------------
bool TDMQueryUpdate::CommitTransaction(void)
{
bool result=false;
try
		{
		Transaction->Commit();
		result=true;
		flError=false;
		TextError="Ошибок нет";
		}
catch(Exception &exception)
				{
				flError=true;
				TextError=exception.Message;
				}
return result;
}
//---------------------------------------------------------------------------
bool TDMQueryUpdate::RollbackTransaction(void)
{
bool result=false;
try
		{
		Transaction->Rollback();
		result=true;
		flError=false;
		TextError="Ошибок нет";
		}
catch(Exception &exception)
				{
				flError=true;
				TextError=exception.Message;
				}
return result;
}
//---------------------------------------------------------------------------
