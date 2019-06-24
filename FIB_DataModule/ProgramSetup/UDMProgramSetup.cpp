//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMProgramSetup.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMProgramSetup::TDMProgramSetup(TComponent* Owner)
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
void __fastcall TDMProgramSetup::DataModuleCreate(TObject *Sender)
{
AnsiString program_catalog=ExtractFileDir(Application->ExeName);
AnsiString file_name=program_catalog+"\\ProgramSetup.ini";

Ini=new TkanIniFile(file_name);
}
//---------------------------------------------------------------------------
bool TDMProgramSetup::Init(void)
{
bool result=false;


result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMProgramSetup::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMProgramSetup::DataModuleDestroy(TObject *Sender)
{
delete Ini;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TDMProgramSetup::SaveSetup(UnicodeString group_name, UnicodeString name_setup, UnicodeString value)
{

Ini->WriteString(group_name, name_setup, value);

}
//----------------------------------------------------------------------------
UnicodeString TDMProgramSetup::LoadSetup(UnicodeString group_name, UnicodeString name_setup)
{
UnicodeString result="";

result=Ini->ReadString(group_name,name_setup,"");

return result;
}
//---------------------------------------------------------------------------
void TDMProgramSetup::SaveSetupBool(UnicodeString group_name,UnicodeString name_setup, bool value)
{
if (value==true)
	{
	Ini->WriteString(group_name, name_setup, "1");
	}
else
	{
	Ini->WriteString(group_name, name_setup, "0");
	}

}
//---------------------------------------------------------------------------
bool TDMProgramSetup::LoadSetupBool(UnicodeString group_name, UnicodeString name_setup)
{
bool result=false;
UnicodeString read_value=Ini->ReadString(group_name,name_setup,"");

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

void TDMProgramSetup::SaveSetupInt(UnicodeString group_name,UnicodeString name_setup, int value)
{

Ini->WriteString(group_name, name_setup, IntToStr(value));

}
//----------------------------------------------------------------------------
int TDMProgramSetup::LoadSetupInt(UnicodeString group_name, UnicodeString name_setup)
{
int result=false;
UnicodeString read_value=Ini->ReadString(group_name,name_setup,"");

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
void TDMProgramSetup::SaveSetupInt64(UnicodeString group_name,UnicodeString name_setup, __int64 value)
{

Ini->WriteString(group_name, name_setup, IntToStr(value));

}
//---------------------------------------------------------------------------
__int64 TDMProgramSetup::LoadSetupInt64(UnicodeString group_name, UnicodeString name_setup)
{
__int64 result=false;
UnicodeString read_value=Ini->ReadString(group_name,name_setup,"");

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

