//---------------------------------------------------------------------------


#pragma hdrstop

#include "UScriptDMQueryRead.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"



//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TScriptDMQueryRead::TScriptDMQueryRead()
{


}
//-----------------------------------------------------------------------
bool TScriptDMQueryRead::Init(void)
{
bool result=false;



//ÏÐÈÂÅËÅÃÈÈ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//-----------------------------------------------------------------------------
void TScriptDMQueryRead::AddClassesInScript(TfsScript * fs_script)
{
TfsClassVariable * cl=fs_script->AddClass(__classid(TScriptDMQueryRead), "TObject");
  cl->AddMethod("procedure NewObject",CallMetod_NewObject);
  cl->AddMethod("procedure DeleteObject",CallMetod_DeleteObject);


  cl->AddMethod("function GetRekvisit(name_field : Variant) : String",CallMetod_GetRekvisit);
  cl->AddMethod("procedure First",CallMetod_First);
  cl->AddMethod("procedure Next",CallMetod_Next);
  cl->AddMethod("function Eof() : Boolean",CallMetod_Eof);
  cl->AddMethod("procedure SetSQLText(zapros : String)",CallMetod_SetSQLText);
  cl->AddMethod("procedure Close",CallMetod_Close);
  cl->AddMethod("function ExecQuery() : Boolean",CallMetod_ExecQuery);
  cl->AddMethod("function GetTextError() : String",CallMetod_GetTextError);
}
//----------------------------------------------------------------------------
Variant __fastcall TScriptDMQueryRead::CallMetod_NewObject(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
DM=new TDMQueryRead(Application);
DM->DM_Connection=DM_Connection;
DM->Init();
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptDMQueryRead::CallMetod_DeleteObject(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
delete DM;
return result;
}
//---------------------------------------------------------------------------
Variant __fastcall TScriptDMQueryRead::CallMetod_GetRekvisit(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
AnsiString value="";
String name_field= VarToStr(Params.GetElement(0));
value=DM->pFIBQ->FieldByName(name_field)->AsString;
result=value;
return result;
}
//----------------------------------------------------------------------------
Variant __fastcall TScriptDMQueryRead::CallMetod_First(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
//DM->pFIBQ->First();
return result;
}
//----------------------------------------------------------------------------
Variant __fastcall TScriptDMQueryRead::CallMetod_Next(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
DM->pFIBQ->Next();
return result;
}
//----------------------------------------------------------------------------
Variant __fastcall TScriptDMQueryRead::CallMetod_Eof(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
result=DM->pFIBQ->Eof;
return result;
}
//----------------------------------------------------------------------------
Variant __fastcall TScriptDMQueryRead::CallMetod_SetSQLText(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
String sql= VarToStr(Params.GetElement(0));
DM->pFIBQ->SQL->Clear();
DM->pFIBQ->SQL->Add(sql);
return result;
}
//----------------------------------------------------------------------------
Variant __fastcall TScriptDMQueryRead::CallMetod_ExecQuery(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result=false;
try
	{
	DM->pFIBQ->ExecQuery();
	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	}
return result;
}
//----------------------------------------------------------------------------
Variant __fastcall TScriptDMQueryRead::CallMetod_Close(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result=false;

DM->pFIBQ->Close();

return result;
}
//----------------------------------------------------------------------------
Variant __fastcall TScriptDMQueryRead::CallMetod_GetTextError(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
result=TextError;
return result;
}
//----------------------------------------------------------------------------