//---------------------------------------------------------------------------


#pragma hdrstop

#include "UScriptDMDocRealRozn.h"
#include "fs_iinterpreter.hpp"
#include "fs_icpp.hpp"
#include "fs_ibasic.hpp"
#include "fs_ijs.hpp"
#include "fs_ipascal.hpp"
#include "USheetEditor.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"


#pragma package(smart_init)
//-------------------------------------------------------------------
TScriptDMDocRealRozn::TScriptDMDocRealRozn()
{


}
//-----------------------------------------------------------------------
bool TScriptDMDocRealRozn::Init(void)
{
bool result=false;



//ÏĞÈÂÅËÅÃÈÈ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//-----------------------------------------------------------------------------
void TScriptDMDocRealRozn::AddClassesInScript(TfsScript * fs_script)
{
TfsClassVariable * cl=fs_script->AddClass(__classid(TScriptDMDocRealRozn), "TObject");

  cl->AddMethod("function DocAllGetRekvisit(name_field : Variant) : String",CallMetod_DocAllGetRekvisit);
  cl->AddMethod("function DocGetRekvisit(name_field : Variant) : String",CallMetod_DocGetRekvisit);
  cl->AddMethod("function DocTGetRekvisit(name_field : Variant) : String",CallMetod_DocTGetRekvisit);
  cl->AddMethod("function PayGetRekvisit(name_field : Variant) : String",CallMetod_PayGetRekvisit);
  cl->AddMethod("procedure DocTFirst",CallMetod_DocTFirst);
  cl->AddMethod("procedure DocTNext",CallMetod_DocTNext);
  cl->AddMethod("function DocTEof() : Boolean",CallMetod_DocTEof);
  cl->AddMethod("procedure PayFirst",CallMetod_PayFirst);
  cl->AddMethod("procedure PayNext",CallMetod_PayNext);
  cl->AddMethod("function PayEof() : Boolean",CallMetod_PayEof);
}
//----------------------------------------------------------------------------
Variant __fastcall TScriptDMDocRealRozn::CallMetod_DocAllGetRekvisit(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
AnsiString value="";
String name_field= VarToStr(Params.GetElement(0));
value=DM->DocAll->FieldByName(name_field)->AsString;
result=value;
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptDMDocRealRozn::CallMetod_DocGetRekvisit(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
AnsiString value="";
String name_field= VarToStr(Params.GetElement(0));
value=DM->Doc->FieldByName(name_field)->AsString;
result=value;
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptDMDocRealRozn::CallMetod_DocTGetRekvisit(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
AnsiString value="";
String name_field= VarToStr(Params.GetElement(0));
value=DM->DocT->FieldByName(name_field)->AsString;
result=value;
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptDMDocRealRozn::CallMetod_PayGetRekvisit(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
AnsiString value="";
String name_field= VarToStr(Params.GetElement(0));
value=DM->Pay->FieldByName(name_field)->AsString;
result=value;
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptDMDocRealRozn::CallMetod_DocTFirst(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;

DM->DocT->First();
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptDMDocRealRozn::CallMetod_DocTNext(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
DM->DocT->Next();

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptDMDocRealRozn::CallMetod_DocTEof(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
result=DM->DocT->Eof;
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptDMDocRealRozn::CallMetod_PayFirst(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
DM->Pay->First();
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptDMDocRealRozn::CallMetod_PayNext(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
DM->Pay->Next();
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptDMDocRealRozn::CallMetod_PayEof(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
result=DM->Pay->Eof;
return result;
}
//-----------------------------------------------------------------------------
