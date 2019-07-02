//---------------------------------------------------------------------------

#ifndef UScriptSheetEditorH
#define UScriptSheetEditorH
//---------------------------------------------------------------------------
//#include "UFormaRunExternalModule.h"
#include "fs_ibasic.hpp"
#include "USheetEditor.h"
//---------------------------------------------------------------------------
class TScriptSheetEditor : public TObject
{
private:

public:
	TScriptSheetEditor();

	TSheetEditor * SE;
	TcxSSCellObject *TecCell;

	void AddClassesInScript(TfsScript * fs_script);

	Variant __fastcall CallMetod_NewObject(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_DeleteObject(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_AddSheetPage(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_LoadFromFile(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetActiveSheet(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

  //служебные функции

	Variant __fastcall CallMetod_BeginUpdate(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

	Variant __fastcall CallMetod_EndUpdate(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

  //параметры по умолчанию
	Variant __fastcall CallMetod_SetDefaultStyleFontSize(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetDefaultStyleFontName(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetRowsAutoHeight(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetDefaultColWidth(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetDefaultRowHeight(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

  //работа с заголовком
	Variant __fastcall CallMetod_SetHeaderSize(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

  //форматирование текущей €чейки
	Variant __fastcall CallMetod_GetTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetTextTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetHorzTextAlignTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetVertTextAlignTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetFontSizeTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetFontStyleTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetTopBorderTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetBottomBorderTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetLeftBorderTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetRightBorderTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_DeleteTecCell(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);


  //объединение €чеек
	Variant __fastcall CallMetod_SetMergedState(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

  //копирование областей
	Variant __fastcall CallMetod_CopyRect(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_PasteRect(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);



};
//-----------------------------------------------------------------------------
#endif
