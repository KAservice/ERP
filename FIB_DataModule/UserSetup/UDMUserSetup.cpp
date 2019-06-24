//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMUserSetup.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMUserSetup::TDMUserSetup(TComponent* Owner)
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

void __fastcall TDMUserSetup::DataModuleCreate(TObject *Sender)
{
AnsiString program_catalog=ExtractFileDir(Application->ExeName);
AnsiString file_name=program_catalog+"\\UserSetup.ini";

Ini=new TkanIniFile(file_name);
}
//---------------------------------------------------------------------------
bool TDMUserSetup::Init(void)
{
bool result=false;


result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMUserSetup::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMUserSetup::DataModuleDestroy(TObject *Sender)
{
delete Ini;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TDMUserSetup::SaveSetup(AnsiString form_name, AnsiString name_setup, AnsiString value)
{

Ini->WriteString(form_name, name_setup, value);

}
//----------------------------------------------------------------------------
AnsiString TDMUserSetup::LoadSetup(AnsiString form_name, AnsiString name_setup)
{
AnsiString result="";

result=Ini->ReadString(form_name,name_setup,"");

return result;
}
//---------------------------------------------------------------------------
void TDMUserSetup::SaveSetupBool(AnsiString form_name,AnsiString name_setup, bool value)
{
if (value==true)
	{
	Ini->WriteString(form_name, name_setup, "1");
	}
else
	{
    Ini->WriteString(form_name, name_setup, "0");
	}

}
//---------------------------------------------------------------------------
bool TDMUserSetup::LoadSetupBool(AnsiString form_name, AnsiString name_setup)
{
bool result=false;
AnsiString read_value=Ini->ReadString(form_name,name_setup,"");

if (read_value=="1")
	{
	result=true;
	}
else
	{
	result=false;
	}

return result;
}
//---------------------------------------------------------------------------

void TDMUserSetup::SaveSetupInt(AnsiString form_name,AnsiString name_setup, int value)
{

Ini->WriteString(form_name, name_setup, IntToStr(value));

}
//----------------------------------------------------------------------------
int TDMUserSetup::LoadSetupInt(AnsiString form_name, AnsiString name_setup)
{
int result=false;
AnsiString read_value=Ini->ReadString(form_name,name_setup,"");

if (read_value=="")
	{
	result=0;
	}
else
	{
	result=StrToInt(read_value);
	}

return result;
}
//---------------------------------------------------------------------------
void TDMUserSetup::SaveSetupInt64(AnsiString form_name,AnsiString name_setup, __int64 value)
{

Ini->WriteString(form_name, name_setup, IntToStr(value));

}
//---------------------------------------------------------------------------
__int64 TDMUserSetup::LoadSetupInt64(AnsiString form_name, AnsiString name_setup)
{
__int64 result=false;
AnsiString read_value=Ini->ReadString(form_name,name_setup,"");

if (read_value=="")
	{
	result=0;
	}
else
	{
	result=StrToInt64(read_value);
	}

return result;
}
//----------------------------------------------------------------------------
