//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaRunFastScript.h"
#include "USheetEditor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "fs_iinterpreter"
#pragma link "fs_icpp"
#pragma link "fs_ibasic"
#pragma link "fs_ijs"
#pragma link "fs_ipascal"
#pragma link "fs_iclassesrtti"
#pragma link "fs_iformsrtti"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaRunFastScript::TFormaRunFastScript(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaRunFastScript::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TFormaRunFastScript::FormClose(TObject *Sender,
      TCloseAction &Action)
{
//Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaRunFastScript::ClearScript(void)
{
fsScript1->Clear();
//fsScript1->AddRTTI();
fsScript1->Parent = fsGlobalUnit();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void TFormaRunFastScript::RunScript(void)
{
FileNameScriptLabel->Caption=FileNameScript;

//проверим есть ли файл скрипта
// проверим если есть указанный файл
if(FileExists(FileNameScript)==false)
		{
		AnsiString ProgramCatalog=ExtractFileDir(Application->ExeName);
		FileNameScript=ProgramCatalog+"\\Scripts\\"+FileNameScript;
		if(FileExists(FileNameScript)==false)
			{
			ShowMessage("Не найден файл: "+FileNameScript);
			Close();
			return;
			}
		}

fsScript1->Lines->LoadFromFile(FileNameScript);




//компилируем скрипт
try
	{
	if (!fsScript1->Compile())
		{
		ShowMessage("Ошибка при компиляции скрипта: "+fsScript1->ErrorMsg+
								" Позиция ошибки: " +fsScript1->ErrorPos);
		Close();
		return;
		}
	}
catch(Exception &exception)
	{
	ShowMessage("Ошибка при компиляции скрипта: "+exception.Message+
								" " +fsScript1->ErrorMsg+
								" Позиция ошибки" +fsScript1->ErrorPos);
	}


try
	{
	fsScript1->Execute();
	}
catch(Exception &exception)
	{
	ShowMessage("Ошибка при выполнении скрипта: "+exception.Message+
								" Позиция ошибки: " +fsScript1->ErrorPos);
	}

}

//---------------------------------------------------------------------------
Variant __fastcall TFormaRunFastScript::ObrabotchikCreateFormSheetEditor(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const AnsiString MethodName,
										   Variant &Params)
{
Variant result;


ShowMessage("Вызван метод: "+MethodName);
//SheetEditor=new TSheetEditor(Application);

return result;
}

//----------------------------------------------------------------------------

