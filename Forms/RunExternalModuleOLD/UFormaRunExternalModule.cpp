//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaRunExternalModule.h"


#include "UDMTableExtPrintForm.h"
#include "UDMExtModule.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "fs_ibasic"
#pragma link "fs_iclassesrtti"
#pragma link "fs_icpp"
#pragma link "fs_iformsrtti"
#pragma link "fs_iinterpreter"
#pragma link "fs_ijs"
#pragma link "fs_ipascal"
#pragma link "frxClass"

#pragma link "frxDesgn"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "frxBarcode"

#pragma link "frxChart"
#pragma link "frxChBox"
#pragma link "frxCross"
#pragma link "frxCrypt"
#pragma link "frxDBSet"
#pragma link "frxDCtrl"
#pragma link "frxGradient"
#pragma link "frxGZip"
#pragma link "frxOLE"
#pragma link "frxRich"

#pragma link "frxExportPDF"
#pragma link "fs_ichartrtti"
#pragma link "fs_idialogsrtti"
#pragma link "fs_iextctrlsrtti"
#pragma link "fs_igraphicsrtti"
#pragma link "fs_iinirtti"
#pragma link "fs_imenusrtti"
#pragma link "frxFIBComponents"
#pragma link "fs_iinterpreter"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaRunExternalModule::TFormaRunExternalModule(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaRunExternalModule::FormCreate(TObject *Sender)
{
List=0;
Residence=0;
IdModule=0;
}
//-----------------------------------------------------------------------
bool TFormaRunExternalModule::Init(void)
{
bool result=false;

frxFIBComponents1->DefaultDatabase=DM_Connection->pFIBData;


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
void __fastcall TFormaRunExternalModule::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
if (List>0) ListDelete();

//необходимо удалить все script модули добавленных классов
DeleteAllModuleClassesScript();

}

//----------------------------------------------------------------------------
void TFormaRunExternalModule::ClearModule(void)
{
if (TypeModule==1 || TypeModule==2)
	{
	fsScript1->Clear();
	//fsScript1->AddRTTI();
	fsScript1->Parent = fsGlobalUnit();
	}

if (TypeModule==3)
	{

	}
}
//----------------------------------------------------------------------------
void TFormaRunExternalModule::LoadModule(void)
{
//если не задан ID должны быть заданы параметры файла
if (IdModule==0)
	{
	FileNameModuleLabel->Caption=FileNameModule;

	//проверим есть ли файл отчета

	// проверим если есть указанный файл
	if(FileExists(FileNameModule)==false)
		{
		UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
		FileNameModule=ProgramCatalog+L"\\ExtModule\\"+FileNameModule;
		if(FileExists(FileNameModule)==false)
			{
			ShowMessage("Не найден файл: "+FileNameModule);
			Close();
			return;
			}
		}

	if (TypeModule==1 || TypeModule==2)
		{
		fsScript1->Lines->LoadFromFile(FileNameModule);
		}

	if (TypeModule==3)
		{
		frxReport1->LoadFromFile(FileNameModule);
		}
	}


if(IdModule>0)
	{
	if (TypeTable==1)   //	1 - модуль объекта
		{
		LoadExtModuleObject(IdModule);
		}

	if (TypeTable==2)   //  2 - внешний модуль из списка внешних модулей
		{
		LoadExtModule(IdModule);
		}
	}

}
//----------------------------------------------------------------------------

void TFormaRunExternalModule::LoadExtModuleObject(__int64 id)
{
//необходимо получить внешний модуль
TDMTableExtPrintForm * dm= new  TDMTableExtPrintForm(Application);
dm->DM_Connection=DM_Connection;
dm->Init();
dm->OpenElement(id);
TypeModule=dm->ElementTYPEMODULE_EXTPRINT_FORM->AsInteger;
FileNameModule=dm->ElementFILE_NAME_EXTPRINT_FORM->AsString;


if (dm->ElementRESIDENCE_EXTPRINT_FORM->AsInteger==0)   //file
	{

	// проверим если есть указанный файл
	if(FileExists(FileNameModule)==false)
		{
		UnicodeString program_catalog=ExtractFileDir(Application->ExeName);
		FileNameModule=program_catalog+L"\\ExtModule\\"+FileNameModule;
		if(FileExists(FileNameModule)==false)
			{
			ShowMessage("Не найден файл: "+FileNameModule);
			Close();
			return;
			}
		}



		if (TypeModule==1 || TypeModule==2)
			{
			fsScript1->Lines->LoadFromFile(FileNameModule);
			}

		if (TypeModule==3)
			{

			frxReport1->LoadFromFile(FileNameModule);
			}
	}


if (dm->ElementRESIDENCE_EXTPRINT_FORM->AsInteger==1)   //BLOB
	{
	TMemoryStream * s=new TMemoryStream;
	dm->ElementBODY_EXTPRINT_FORM->SaveToStream(s);
    s->Position = 0 ;
		if (TypeModule==1 || TypeModule==2)
			{
			fsScript1->Lines->LoadFromStream(s);
			}

		if (TypeModule==3)
			{
			frxReport1->LoadFromStream(s);
			}

		if (TypeModule==4)
			{
			//зададим каталог протоколов
			UnicodeString program_catalog=ExtractFileDir(Application->ExeName);
			if (DirectoryExists(program_catalog+L"\\ExtModule")==false)
				{
				CreateDir(program_catalog+L"\\ExtModule");
				}

			if (DirectoryExists(program_catalog+L"\\ExtModule")==true)
				{
				s->SaveToFile(program_catalog+L"\\ExtModule\\"+FileNameModule);
				}
			}

	delete s;
 	}

delete dm;

}
//---------------------------------------------------------------------------
void TFormaRunExternalModule::LoadExtModule(__int64 id)
{
//необходимо получить внешний модуль
TDMExtModule * dm= new  TDMExtModule(Application);
dm->DM_Connection=DM_Connection;
dm->Init();
dm->OpenElement(id);
TypeModule=dm->ElementTYPE_EXT_MODULE->AsInteger;
FileNameModule=dm->ElementFILE_NAME_EXT_MODULE->AsString;



if (dm->ElementRESIDENCE_EXT_MODULE->AsInteger==0)   //file
	{
	// проверим если есть указанный файл
	if(FileExists(FileNameModule)==false)
		{
		UnicodeString program_catalog=ExtractFileDir(Application->ExeName);
		FileNameModule=program_catalog+L"\\ExtModule\\"+FileNameModule;
		if(FileExists(FileNameModule)==false)
			{
			ShowMessage("Не найден файл: "+FileNameModule);
			Close();
			return;
			}
		}

		if (TypeModule==1 || TypeModule==2)
			{
			fsScript1->Lines->LoadFromFile(FileNameModule);
			}

		if (TypeModule==3)
			{
			frxReport1->LoadFromFile(FileNameModule);
			}
	}


if (dm->ElementRESIDENCE_EXT_MODULE->AsInteger==1)   //BLOB
	{
	TMemoryStream * s=new TMemoryStream;
	dm->ElementBODY_EXT_MODULE->SaveToStream(s);
	s->Position = 0 ;
	
		if (TypeModule==1 || TypeModule==2)
			{
			fsScript1->Lines->LoadFromStream(s);
			}

		if (TypeModule==3)
			{
			frxReport1->LoadFromStream(s);
			}

		if (TypeModule==4)
			{
			//зададим каталог протоколов
			UnicodeString program_catalog=ExtractFileDir(Application->ExeName);
			if (DirectoryExists(program_catalog+L"\\ExtModule")==false)
				{
				CreateDir(program_catalog+L"\\ExtModule");
				}

			if (DirectoryExists(program_catalog+L"\\ExtModule")==true)
				{
				s->SaveToFile(program_catalog+L"\\ExtModule\\"+FileNameModule);
				}
			}


	delete s;  
	}

delete dm;

}

//---------------------------------------------------------------------------
void TFormaRunExternalModule::ExecuteModule(void)
{
if (TypeModule==1 || TypeModule==2)
	{
	RunScript();
	}

if (TypeModule==3)
	{
	OpenFastReport();
	}

if (TypeModule==4)
	{
	RunDllModule();
	}
}
//----------------------------------------------------------------------------
void TFormaRunExternalModule::OpenFastReport(void)
{
if (List>0)
	{
	if (List->Count>0)
		{
		frxUserDataSet1->RangeEndCount=List->Count;
		}
	else
		{
		frxUserDataSet1->RangeEndCount=0;
		}
	}
frxReport1->ShowReport(true);  
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModule::RunScript(void)
{
fsScript1->Parent=fsGlobalUnit();
//добавим класс TScriptDMQueryRead
AddClassesInScript_DMQueryRead();

if (TypeModule==1)
	{
	//надо добавить класс  TScriptSheetEditor
	AddClassesInScript_SheetEditor();
	}

if (TypeModule==2)
	{
	//надо добавить класс  TScriptReportGrid
	AddClassesInScript_ReportGrid();
	}

fsScript1->AddMethod("procedure DestroyForm",CallMetod_DestroyForm);


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
//----------------------------------------------------------------------------
Variant __fastcall TFormaRunExternalModule::CallMetod_DestroyForm(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params)
{
Variant result;
//закрывем форму после завершения работы с модулем
//Visible=true;
Timer1->Interval=1;
Timer1->Enabled=true;
return result;
}
//----------------------------------------------------------------------------
void TFormaRunExternalModule::SetIntegerVariables(UnicodeString name_variables, int value)
{
//		1 script_SpreadSheet
//		2 script_Grid
if (TypeModule==1 || TypeModule==2)
	{
	fsScript1->AddConst(name_variables,"Integer",value);
	}

if (TypeModule==3)  //		3 FastReport
	{
	frxReport1->Variables->Variables[name_variables] = value;
	}
//      4 DLL
}
//----------------------------------------------------------------------------
void TFormaRunExternalModule::SetStringVariables(UnicodeString name_variables, UnicodeString value)
{
//		1 script_SpreadSheet
//		2 script_Grid
if (TypeModule==1 || TypeModule==2)
	{
	fsScript1->AddConst(name_variables,"String",value);
	}

if (TypeModule==3)  //		3 FastReport
	{
	frxReport1->Variables->Variables[name_variables] = value;
	}
}
//----------------------------------------------------------------------------
void TFormaRunExternalModule::SetInt64Variables(UnicodeString name_variables, __int64 value)
{
//		1 script_SpreadSheet
//		2 script_Grid
if (TypeModule==1 || TypeModule==2)
	{
	fsScript1->AddConst(name_variables,"String",value);
	}

if (TypeModule==3)  //		3 FastReport
	{
	frxReport1->Variables->Variables[name_variables] = StrToInt64(value);
	}
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModule::SetDateTimeVariables(UnicodeString name_variables, TDateTime value)
{
//		1 script_SpreadSheet
//		2 script_Grid
if (TypeModule==1 || TypeModule==2)
	{
	fsScript1->AddConst(name_variables,"TDateTime",value);
	}

if (TypeModule==3)  //		3 FastReport
	{
	frxReport1->Variables->Variables[name_variables] = value;
	}
}
//-----------------------------------------------------------------------------

void TFormaRunExternalModule::ListNew(void)
{
List= new TList;

}
//----------------------------------------------------------------------------
void TFormaRunExternalModule::ListDelete(void)
{
for (int i=0;i<List->Count; i++)
	{
	TElementList * el=(TElementList*) List->Items[i];
    delete el;
	}
delete List;
List=0;
}
//----------------------------------------------------------------------------
void TFormaRunExternalModule::ListAddElement(UnicodeString id1, UnicodeString id2, UnicodeString id3, int int_value1)
{
if (List==0) ListNew();
TElementList * el=new TElementList;
el->Id1=id1;
el->Id2=id2;
el->Id3=id3;
el->IntValue1=int_value1;
List->Add(el);
frxUserDataSet1->RangeEndCount = List->Count;
}
//-----------------------------------------------------------------------------


void __fastcall TFormaRunExternalModule::frxReport1ClosePreview(TObject *Sender)
{
//закрывем форму после закрытия fastReport
//Visible=true;
Timer1->Interval=1;
Timer1->Enabled=true;


}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// добавляем внешние классы с помощью script модулей
//---------------------------------------------------------------------------
void TFormaRunExternalModule::DeleteAllModuleClassesScript(void)
{
if (ScriptSheetEditor) delete ScriptSheetEditor;
if (ScriptReportGrid) delete ScriptReportGrid;
if (ScriptDMQueryRead) delete ScriptDMQueryRead;
if (ScriptDMDocRealRozn) delete ScriptDMDocRealRozn;

}
//-----------------------------------------------------------------------------
void TFormaRunExternalModule::AddClassesInScript_SheetEditor(void)
{
ScriptSheetEditor=new TScriptSheetEditor();
ScriptSheetEditor->AddClassesInScript(fsScript1);
}
//----------------------------------------------------------------------------
void TFormaRunExternalModule::AddClassesInScript_ReportGrid(void)
{
ScriptReportGrid=new TScriptReportGrid();
ScriptReportGrid->DM_Connection=DM_Connection;
ScriptReportGrid->Init();
ScriptReportGrid->AddClassesInScript(fsScript1);
// fsScript1->AddClass(__classid(TcxButton), "TWinControl");
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModule::AddClassesInScript_DMQueryRead(void)
{
ScriptDMQueryRead=new TScriptDMQueryRead();
ScriptDMQueryRead->DM_Connection=DM_Connection;
ScriptDMQueryRead->Init();
ScriptDMQueryRead->AddClassesInScript(fsScript1);
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModule::AddClassesInScript_DMDocRealRozn(void)
{
ScriptDMDocRealRozn=new TScriptDMDocRealRozn();
ScriptDMDocRealRozn->DM_Connection=DM_Connection;
ScriptDMDocRealRozn->Init();
ScriptDMDocRealRozn->AddClassesInScript(fsScript1);
}
//----------------------------------------------------------------------------
void TFormaRunExternalModule::RunDllModule(void)
{
FileNameModuleLabel->Caption=FileNameModule;

//проверим есть ли файл отчета
// проверим если есть указанный файл
if(FileExists(FileNameModule)==false)
		{
		UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
		FileNameModule=ProgramCatalog+L"\\ExtModule\\"+FileNameModule;
		if(FileExists(FileNameModule)==false)
			{
			ShowMessage("Не найден файл: "+FileNameModule);
			Close();
			return;
			}
		}

dllIn=LoadLibrary(AnsiString(FileNameModule).c_str());
if(dllIn)
	{
	try
		{
		DllInitPlugin=(DllInitPluginType*)GetProcAddress(dllIn,"_InitPlugin");
		DllDonePlugin=(DllDonePluginType*)GetProcAddress(dllIn,"_DonePlugin");
		DllGetTextError=(DllGetTextErrorType*)GetProcAddress(dllIn,"_GetTextError"); 

		//HANDLE ap=Application->Handle;
		//Ibase::TISC_DB_HANDLE db=DM->pFIBData->Handle;
		//HANDLE h=Handle;

		if (DllInitPlugin(Application->Handle,
					DM_Connection->pFIBData->Handle,
					Handle)==true)
			{   //успешная инициализация
			}
		else
			{
			ShowMessage("Ошибка при инициализации внешнего DLL модуля: "+AnsiString(DllGetTextError()));
			FreeLibrary(dllIn);

			}
		 }
	catch (Exception &exception)
		{
		FreeLibrary(dllIn);
		ShowMessage("Ошибка при инициализации внешнего DLL модуля: "+exception.Message);
		}
	}
else
	{
	ShowMessage("Ошибка при загрузке внешнего DLL модуля! ");
	}
}

//----------------------------------------------------------------------------
void __fastcall TFormaRunExternalModule::EndDLL(TMessage&Message)
{
DllDonePlugin();
FreeLibrary(dllIn);
Close();//после завершения работы с модулем
}
//--------------------------------------------------------------------------

void __fastcall TFormaRunExternalModule::Button1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaRunExternalModule::Timer1Timer(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------



void __fastcall TFormaRunExternalModule::frxUserDataSet1GetValue(const UnicodeString VarName,
          Variant &Value)
{
Value="";
TElementList * el=(TElementList*)List->Items[frxUserDataSet1->RecNo];
  if (VarName=="Id1")
	{
	Value = el->Id1;
	}
  if (VarName=="Id2")
	{
	Value = el->Id2;
	}
  if (VarName=="Id3")
	{
	Value = el->Id3;
	}
  if (VarName=="IntValue1")
	{
	Value = el->IntValue1;
	}
}
//---------------------------------------------------------------------------

