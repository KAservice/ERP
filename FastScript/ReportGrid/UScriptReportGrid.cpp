//---------------------------------------------------------------------------


#pragma hdrstop

#include "UScriptReportGrid.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TScriptReportGrid::TScriptReportGrid()
{

}
//-----------------------------------------------------------------------
bool TScriptReportGrid::Init(void)
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
void TScriptReportGrid::AddClassesInScript(TfsScript * fs_script)
{
TfsClassVariable * cl=fs_script->AddClass(__classid(TScriptReportGrid), "TObject");
UnicodeString text_func="";
  cl->AddMethod("procedure NewObject",CallMetod_NewObject);
  cl->AddMethod("procedure DeleteObject",CallMetod_DeleteObject);
  cl->AddMethod("procedure SetTextQuery(text_query : String)",CallMetod_SetTextQuery);

  text_func="procedure AddColumn(";
  text_func=text_func+ " field_name : String, ";
  text_func=text_func+ " caption : String, ";
  text_func=text_func+ " width : Integer, ";
  text_func=text_func+ " group_index : Integer, ";
  text_func=text_func+ " group_sum : Boolean, ";
  text_func=text_func+ " format_group_sum : String, ";
  text_func=text_func+ " footer_sum : Boolean, ";
  text_func=text_func+ " format_footer_sum : String ";
  text_func=text_func+ ")";
  cl->AddMethod(text_func,CallMetod_AddColumn);

  text_func="procedure CreateSeries(";
  text_func=text_func+ " name_field : String, ";
  text_func=text_func+ " display_text : String ";
  text_func=text_func+ ")";
  cl->AddMethod(text_func,CallMetod_CreateSeries);

  text_func="procedure AddDataGroups(";
  text_func=text_func+ " name_field : String, ";
  text_func=text_func+ " display_text : String ";
  text_func=text_func+ ")";
  cl->AddMethod(text_func,CallMetod_AddDataGroups);

  cl->AddMethod("procedure OpenReport",CallMetod_OpenReport);


}
//----------------------------------------------------------------------------
Variant __fastcall TScriptReportGrid::CallMetod_NewObject(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;

ReportGrid=new TFormaReportGrid(Application);
ReportGrid->DM_Connection=DM_Connection;
ReportGrid->Init();
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptReportGrid::CallMetod_DeleteObject(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;

delete ReportGrid;

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptReportGrid::CallMetod_SetTextQuery(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
AnsiString zapros= VarToStr(Params.GetElement(0));
ReportGrid->SetTextQuery(zapros);

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptReportGrid::CallMetod_AddColumn(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;

bool group_sum=(bool)VarAsType(Params.GetElement(4),varBoolean);// group_sum
bool footer_sum=(bool)VarAsType(Params.GetElement(6),varBoolean);// footer_sum


	ReportGrid->AddColumn( VarToStr(Params.GetElement(0)),// field_name
						   VarToStr(Params.GetElement(1)),// caption
						   StrToInt(VarToStr(Params.GetElement(2))),// width
						   StrToInt(VarToStr(Params.GetElement(3))),// group_index
						   group_sum,// group_sum
						   VarToStr(Params.GetElement(5)),// format_group_sum
						   footer_sum,// footer_sum
						   VarToStr(Params.GetElement(7))// format_footer_sum
						   );
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptReportGrid::CallMetod_CreateSeries(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;


	ReportGrid->CreateSeries( VarToStr(Params.GetElement(0)),// name_field
								VarToStr(Params.GetElement(1))// display_text
								);
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptReportGrid::CallMetod_AddDataGroups(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;

ReportGrid->AddDataGroups( VarToStr(Params.GetElement(0)),// name_field
								VarToStr(Params.GetElement(1))// display_text
								);

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptReportGrid::CallMetod_OpenReport(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;

ReportGrid->OpenReport();

return result;
}										   
//-----------------------------------------------------------------------------
