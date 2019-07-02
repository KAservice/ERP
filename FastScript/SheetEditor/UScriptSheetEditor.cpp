//---------------------------------------------------------------------------


#pragma hdrstop

#include "UScriptSheetEditor.h"  
//---------------------------------------------------------------------------

#include "fs_iinterpreter.hpp"
#include "fs_icpp.hpp"
#include "fs_ibasic.hpp"
#include "fs_ijs.hpp"
#include "fs_ipascal.hpp"
#include "USheetEditor.h"


#pragma package(smart_init)
//-------------------------------------------------------------------
TScriptSheetEditor::TScriptSheetEditor()
{

}
//-----------------------------------------------------------------------------
void TScriptSheetEditor::AddClassesInScript(TfsScript * fs_script)
{
TfsClassVariable * cl=fs_script->AddClass(__classid(TScriptSheetEditor), "TObject");
  cl->AddMethod("procedure NewObject",CallMetod_NewObject);
  cl->AddMethod("procedure DeleteObject",CallMetod_DeleteObject);
  cl->AddMethod("procedure AddSheetPage(name_sheet : String)",CallMetod_AddSheetPage);
  cl->AddMethod("procedure LoadFromFile(template_file_name : String)",CallMetod_LoadFromFile);
  //PrintForm->SS->Pages[0]->GetCellObject(x,y);
  cl->AddMethod("procedure SetActiveSheet(number_sheet : Integer)",CallMetod_SetActiveSheet);

  //служебные функции
  cl->AddMethod("procedure BeginUpdate",CallMetod_BeginUpdate);
  cl->AddMethod("procedure EndUpdate",CallMetod_EndUpdate);

  //параметры по умолчанию
  cl->AddMethod("procedure SetDefaultStyleFontSize(size_font : Integer)",CallMetod_SetDefaultStyleFontSize);
  cl->AddMethod("procedure SetDefaultStyleFontName(name_font : String)",CallMetod_SetDefaultStyleFontName);
  cl->AddMethod("procedure SetRowsAutoHeight(value : Boolean)",CallMetod_SetRowsAutoHeight);
  cl->AddMethod("procedure SetDefaultColWidth(value : Integer)",CallMetod_SetDefaultColWidth);
  cl->AddMethod("procedure SetDefaultRowHeight(value : Integer)",CallMetod_SetDefaultRowHeight);

  //работа с заголовком
  cl->AddMethod("procedure SetHeaderSize(number_column : Integer, size : Integer)",CallMetod_SetHeaderSize);

  //форматирование текущей €чейки
  cl->AddMethod("procedure GetTecCell(x : Integer, y : Integer)",CallMetod_GetTecCell);
  cl->AddMethod("procedure SetTextTecCell(text : String)",CallMetod_SetTextTecCell);
  cl->AddMethod("procedure SetHorzTextAlignTecCell(align : Integer)",CallMetod_SetHorzTextAlignTecCell);
  cl->AddMethod("procedure SetVertTextAlignTecCell(align : Integer)",CallMetod_SetVertTextAlignTecCell);
  cl->AddMethod("procedure SetFontSizeTecCell(size : Integer)",CallMetod_SetFontSizeTecCell);
  cl->AddMethod("procedure SetFontStyleTecCell(style : Integer)",CallMetod_SetFontStyleTecCell);
  cl->AddMethod("procedure SetTopBorderTecCell(type_border : Integer)",CallMetod_SetTopBorderTecCell);
  cl->AddMethod("procedure SetBottomBorderTecCell(type_border : Integer)",CallMetod_SetBottomBorderTecCell);
  cl->AddMethod("procedure SetLeftBorderTecCell(type_border : Integer)",CallMetod_SetLeftBorderTecCell);
  cl->AddMethod("procedure SetRightBorderTecCell(type_border : Integer)",CallMetod_SetRightBorderTecCell);
  cl->AddMethod("procedure DeleteTecCell",CallMetod_DeleteTecCell);

  //объединение €чеек
  cl->AddMethod("procedure SetMergedState(left : Integer, right : Integer, top : Integer, bottom : Integer)",CallMetod_SetMergedState);

  //копирование областей
  cl->AddMethod("procedure CopyRect(left : Integer, right : Integer, top : Integer, bottom : Integer)",CallMetod_CopyRect);
  cl->AddMethod("procedure PasteRect(left : Integer, top : Integer)",CallMetod_PasteRect);
}
//----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_NewObject(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;

SE=new TSheetEditor(Application);

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_DeleteObject(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;

delete SE;

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_AddSheetPage(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
AnsiString name_sheet= VarToStr(Params.GetElement(0));

SE->SS->AddSheetPage(name_sheet);

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_LoadFromFile(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
String name_file= VarToStr(Params.GetElement(0));

// проверим если есть указанный файл
if(FileExists(name_file)==false)
		{
		AnsiString ProgramCatalog=ExtractFileDir(Application->ExeName);
		name_file=ProgramCatalog+"\\ExtModule\\"+name_file;
		if(FileExists(name_file)==false)
			{
			ShowMessage("Ќе найден файл: "+name_file);
			return result;
			}
		}

SE->SS->LoadFromFile(name_file);

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetActiveSheet(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result=0;

int number_sheet=StrToInt(VarToStr(Params.GetElement(0)));
SE->SS->ActivePage=number_sheet;
return result;
}
//-----------------------------------------------------------------------------
  //служебные функции

Variant __fastcall TScriptSheetEditor::CallMetod_BeginUpdate(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{

Variant result;
SE->SS->BeginUpdate();
return result;
}
//-----------------------------------------------------------------------------

Variant __fastcall TScriptSheetEditor::CallMetod_EndUpdate(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
SE->SS->EndUpdate();  
return result;
}
//-----------------------------------------------------------------------------

  //параметры по умолчанию
Variant __fastcall TScriptSheetEditor::CallMetod_SetDefaultStyleFontSize(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int size=StrToInt(VarToStr(Params.GetElement(0)));
SE->SS->DefaultStyle->Font->Size=size;
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetDefaultStyleFontName(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
String name_font= VarToStr(Params.GetElement(0));
SE->SS->DefaultStyle->Font->Name=name_font;  
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetRowsAutoHeight(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int value=StrToInt(VarToStr(Params.GetElement(0)));

if (value==0)
	{
	SE->SS->RowsAutoHeight=false;
	}
else
	{
    SE->SS->RowsAutoHeight=true;
	}

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetDefaultColWidth(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int value=StrToInt(VarToStr(Params.GetElement(0)));
SE->SS->DefaultColWidth=value;
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetDefaultRowHeight(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int value=StrToInt(VarToStr(Params.GetElement(0)));
SE->SS->DefaultRowHeight=value;   
return result;
}
//-----------------------------------------------------------------------------

  //работа с заголовком
Variant __fastcall TScriptSheetEditor::CallMetod_SetHeaderSize(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int number=StrToInt(VarToStr(Params.GetElement(0)));
int size=StrToInt(VarToStr(Params.GetElement(1)));

TcxSSHeader *cHeader=SE->SS->ActiveSheet->Cols;
cHeader->Size[number] = size;

return result;
}
//-----------------------------------------------------------------------------

  //форматирование текущей €чейки
Variant __fastcall TScriptSheetEditor::CallMetod_GetTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int x=StrToInt(VarToStr(Params.GetElement(0)));
int y=StrToInt(VarToStr(Params.GetElement(1)));
TecCell = SE->SS->ActiveSheet->GetCellObject(x,y);
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetTextTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
String text= VarToStr(Params.GetElement(0));
TecCell->Text=text;
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetHorzTextAlignTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int value=StrToInt(VarToStr(Params.GetElement(0)));

if (value==1)
	{
	TecCell->Style->HorzTextAlign = haLEFT;
	}
if (value==2)
	{
	TecCell->Style->HorzTextAlign = haCENTER;
	} 
if (value==3)
	{
	TecCell->Style->HorzTextAlign = haRIGHT;
	}

if (value==4)
	{
	TecCell->Style->HorzTextAlign = haJUSTIFY;
	}

if (value==5)
	{
	TecCell->Style->HorzTextAlign = haFILL;
	}

if (value==6)
	{
	TecCell->Style->HorzTextAlign = haGENERAL;
	}
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetVertTextAlignTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int value=StrToInt(VarToStr(Params.GetElement(0)));

if (value==1)
	{
	TecCell->Style->VertTextAlign = vaTOP;
	}
if (value==2)
	{
	TecCell->Style->VertTextAlign = vaCENTER;
	} 
if (value==3)
	{
	TecCell->Style->VertTextAlign = vaBOTTOM;
	}

if (value==4)
	{
	TecCell->Style->VertTextAlign = vaJUSTIFY;
	}
return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetFontSizeTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int value=StrToInt(VarToStr(Params.GetElement(0)));
TecCell->Style->Font->Size = value;

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetFontStyleTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int value=StrToInt(VarToStr(Params.GetElement(0)));
if (value==1)
	{
	TecCell->Style->Font->Style = TFontStyles() << fsBold;
	}

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetTopBorderTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int value=StrToInt(VarToStr(Params.GetElement(0)));

if (value==1) 	{TecCell->Style->Borders->Edges [eTop]->Style=lsDefault;}
if (value==2)   {TecCell->Style->Borders->Edges [eTop]->Style=lsDotted;	}
if (value==3)   {TecCell->Style->Borders->Edges [eTop]->Style=lsDashed;	}
if (value==4)   {TecCell->Style->Borders->Edges [eTop]->Style=lsDashDotDot;	}
if (value==5)  	{TecCell->Style->Borders->Edges [eTop]->Style=lsDashDot;	}
if (value==6)   {TecCell->Style->Borders->Edges [eTop]->Style=lsSlantedDashDot;	}
if (value==7)   {TecCell->Style->Borders->Edges [eTop]->Style=lsThin;}
if (value==8)   {TecCell->Style->Borders->Edges [eTop]->Style=lsMediumDashDotDot;}
if (value==9)   {TecCell->Style->Borders->Edges [eTop]->Style=lsHair;}
if (value==10)  {TecCell->Style->Borders->Edges [eTop]->Style=lsMediumDashDot; }
if (value==11)  {TecCell->Style->Borders->Edges [eTop]->Style=lsMediumDashed;  }
if (value==12)  {TecCell->Style->Borders->Edges [eTop]->Style=lsMedium; }
if (value==13)  {TecCell->Style->Borders->Edges [eTop]->Style=lsThick;	}
//if (value==14)  {TecCell->Style->Borders->Edges [eTop]->Style=lsDouble;	}
if (value==15)  {TecCell->Style->Borders->Edges [eTop]->Style=lsNone;	}

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetBottomBorderTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int value=StrToInt(VarToStr(Params.GetElement(0)));

if (value==1) 	{TecCell->Style->Borders->Edges [eBottom]->Style=lsDefault;}
if (value==2)   {TecCell->Style->Borders->Edges [eBottom]->Style=lsDotted;	}
if (value==3)   {TecCell->Style->Borders->Edges [eBottom]->Style=lsDashed;	}
if (value==4)   {TecCell->Style->Borders->Edges [eBottom]->Style=lsDashDotDot;	}
if (value==5)  	{TecCell->Style->Borders->Edges [eBottom]->Style=lsDashDot;	}
if (value==6)   {TecCell->Style->Borders->Edges [eBottom]->Style=lsSlantedDashDot;	}
if (value==7)   {TecCell->Style->Borders->Edges [eBottom]->Style=lsThin;}
if (value==8)   {TecCell->Style->Borders->Edges [eBottom]->Style=lsMediumDashDotDot;}
if (value==9)   {TecCell->Style->Borders->Edges [eBottom]->Style=lsHair;}
if (value==10)  {TecCell->Style->Borders->Edges [eBottom]->Style=lsMediumDashDot; }
if (value==11)  {TecCell->Style->Borders->Edges [eBottom]->Style=lsMediumDashed;  }
if (value==12)  {TecCell->Style->Borders->Edges [eBottom]->Style=lsMedium; }
if (value==13)  {TecCell->Style->Borders->Edges [eBottom]->Style=lsThick;	}
//if (value==14)  {TecCell->Style->Borders->Edges [eBottom]->Style=lsDouble;	}
if (value==15)  {TecCell->Style->Borders->Edges [eBottom]->Style=lsNone;	}

return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetLeftBorderTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int value=StrToInt(VarToStr(Params.GetElement(0)));

if (value==1) 	{TecCell->Style->Borders->Edges [eLeft]->Style=lsDefault;}
if (value==2)   {TecCell->Style->Borders->Edges [eLeft]->Style=lsDotted;	}
if (value==3)   {TecCell->Style->Borders->Edges [eLeft]->Style=lsDashed;	}
if (value==4)   {TecCell->Style->Borders->Edges [eLeft]->Style=lsDashDotDot;	}
if (value==5)  	{TecCell->Style->Borders->Edges [eLeft]->Style=lsDashDot;	}
if (value==6)   {TecCell->Style->Borders->Edges [eLeft]->Style=lsSlantedDashDot;	}
if (value==7)   {TecCell->Style->Borders->Edges [eLeft]->Style=lsThin;}
if (value==8)   {TecCell->Style->Borders->Edges [eLeft]->Style=lsMediumDashDotDot;}
if (value==9)   {TecCell->Style->Borders->Edges [eLeft]->Style=lsHair;}
if (value==10)  {TecCell->Style->Borders->Edges [eLeft]->Style=lsMediumDashDot; }
if (value==11)  {TecCell->Style->Borders->Edges [eLeft]->Style=lsMediumDashed;  }
if (value==12)  {TecCell->Style->Borders->Edges [eLeft]->Style=lsMedium; }
if (value==13)  {TecCell->Style->Borders->Edges [eLeft]->Style=lsThick;	}
//if (value==14)  {TecCell->Style->Borders->Edges [eLeft]->Style=lsDouble;	}
if (value==15)  {TecCell->Style->Borders->Edges [eLeft]->Style=lsNone;	}


return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_SetRightBorderTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int value=StrToInt(VarToStr(Params.GetElement(0)));

if (value==1) 	{TecCell->Style->Borders->Edges [eRight]->Style=lsDefault;}
if (value==2)   {TecCell->Style->Borders->Edges [eRight]->Style=lsDotted;	}
if (value==3)   {TecCell->Style->Borders->Edges [eRight]->Style=lsDashed;	}
if (value==4)   {TecCell->Style->Borders->Edges [eRight]->Style=lsDashDotDot;}
if (value==5)  	{TecCell->Style->Borders->Edges [eRight]->Style=lsDashDot;	}
if (value==6)   {TecCell->Style->Borders->Edges [eRight]->Style=lsSlantedDashDot; }
if (value==7)   {TecCell->Style->Borders->Edges [eRight]->Style=lsThin;}
if (value==8)   {TecCell->Style->Borders->Edges [eRight]->Style=lsMediumDashDotDot;}
if (value==9)   {TecCell->Style->Borders->Edges [eRight]->Style=lsHair;}
if (value==10)  {TecCell->Style->Borders->Edges [eRight]->Style=lsMediumDashDot; }
if (value==11)  {TecCell->Style->Borders->Edges [eRight]->Style=lsMediumDashed;  }
if (value==12)  {TecCell->Style->Borders->Edges [eRight]->Style=lsMedium; }
if (value==13)  {TecCell->Style->Borders->Edges [eRight]->Style=lsThick;  }
//if (value==14)  {TecCell->Style->Borders->Edges [eRight]->Style=lsDouble; }
if (value==15)  {TecCell->Style->Borders->Edges [eRight]->Style=lsNone;	}


return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_DeleteTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;

delete TecCell;

return result;
}
//-----------------------------------------------------------------------------

  //объединение €чеек
Variant __fastcall TScriptSheetEditor::CallMetod_SetMergedState(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int left=StrToInt(VarToStr(Params.GetElement(0)));
int right=StrToInt(VarToStr(Params.GetElement(1)));
int top=StrToInt(VarToStr(Params.GetElement(2)));
int bottom=StrToInt(VarToStr(Params.GetElement(3)));

TRect rect;
rect.Left = left;
rect.Top = top;
rect.Right = right;
rect.Bottom = bottom;
SE->SS->ActiveSheet->SetMergedState(rect, true);

return result;
}
//-----------------------------------------------------------------------------

  //копирование областей
Variant __fastcall TScriptSheetEditor::CallMetod_CopyRect(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int left=StrToInt(VarToStr(Params.GetElement(0)));
int right=StrToInt(VarToStr(Params.GetElement(1)));
int top=StrToInt(VarToStr(Params.GetElement(2)));
int bottom=StrToInt(VarToStr(Params.GetElement(3)));

TRect rect;
rect.Left = left;
rect.Top = top;
rect.Right = right;
rect.Bottom = bottom;
SE->SS->ActiveSheet->Copy(rect, false);


return result;
}
//-----------------------------------------------------------------------------
Variant __fastcall TScriptSheetEditor::CallMetod_PasteRect(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
int x=StrToInt(VarToStr(Params.GetElement(0)));
int y=StrToInt(VarToStr(Params.GetElement(1)));
TPoint p;
p.x=x;
p.y=y;
SE->SS->ActiveSheet->Paste(p);


return result;
}
//-----------------------------------------------------------------------------
