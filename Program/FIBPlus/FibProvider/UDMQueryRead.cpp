//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMQueryRead.h"
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
__fastcall TDMQueryRead::TDMQueryRead(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMQueryRead::DataModuleDestroy(TObject *Sender)
{
Query->Close();
}
//---------------------------------------------------------------------------
void TDMQueryRead::CloseQuery(void)
{

Query->Close();

}
//---------------------------------------------------------------------------
void TDMQueryRead::ClearTextSQL(void)
{

Query->SQL->Clear();

}
//---------------------------------------------------------------------------
void TDMQueryRead::SetTextSQL(UnicodeString text_sql)
{

Query->SQL->Text=text_sql;

}
//---------------------------------------------------------------------------
bool TDMQueryRead::SetStringParamQuery(UnicodeString param_name, UnicodeString param_value)
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
bool TDMQueryRead::ExecQuery(void)
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
bool TDMQueryRead::ExecProc(void)
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
bool TDMQueryRead::NextRecord(void)
{

Query->Next();
return true;
}
//---------------------------------------------------------------------------

bool TDMQueryRead::GetRecord(void)
{


return false;
}
//---------------------------------------------------------------------------
UnicodeString TDMQueryRead::GetStringValueField(UnicodeString field_name)
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

bool TDMQueryRead::StartTransaction(void)
{


return false;
}
//---------------------------------------------------------------------------
bool TDMQueryRead::CommitTransaction(void)
{


return false;
}
//---------------------------------------------------------------------------
bool TDMQueryRead::RollbackTransaction(void)
{


return false;
}
//---------------------------------------------------------------------------

