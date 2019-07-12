//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaRunExternalModule.h"
#include "IDMQueryUpdate.h"
#include "IDMQueryRead.h"

#include "UDMTableExtPrintForm.h"
#include "UDMExtModule.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IkasDMSpr.h"
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
#pragma link "frxExportRTF"
#pragma link "frxExportXLS"
#pragma link "frxExportImage"
#pragma link "frxExportMail"
#pragma link "frxExportODF"
#pragma link "frxExportText"
#pragma link "frxExportXML"
#pragma resource "*.dfm"

extern UnicodeString glCurrencyPropis(double Value);
extern UnicodeString glIntegerValuePropis(int Value);
//---------------------------------------------------------------------------
__fastcall TFormaRunExternalModule::TFormaRunExternalModule(TComponent* Owner)
	: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
ConnectFR=false;
FR_Error=false;
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
int result=0;

if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

frxFIBComponents1->DefaultDatabase=DM_Connection->pFIBData;

AddMyGlobalFunctionInFastReport();

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
int TFormaRunExternalModule::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaRunExternalModule::FormClose(TObject *Sender, TCloseAction &Action)
{

if (ConnectFR==true)
	{
    DeleteObjectFR ();
	}
Action=caFree;
if (List>0) ListDelete();

//необходимо удалить все script модули добавленных классов
DeleteAllModuleClassesScript();

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
int TFormaRunExternalModule::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_ViborFR)
		{

		if (type_event==1)
				{
				EndViborOborud();
				}
		FormaViborOborud=0;
		}
return -1;
}
//---------------------------------------------------------------------------
void TFormaRunExternalModule::ClearModule(void)
{
if (TypeModule==1 || TypeModule==2)
	{
	fsScript1->Clear();
	//fsScript1->AddRTTI();
	fsScript1->Parent = fsGlobalUnit();
	}

if (TypeModule==3  || TypeModule==5)
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

	if (TypeModule==3  || TypeModule==5)
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

//если тип модуля 4 то загружаем настройки оборудования
//выбираем устройство на котором печатать
//если локальный принтер то создаем объект ФР, подключаемся к нему и печатаем
//и отключаемся
//если сервер печати передаем ему ID формы и ID объекта который печатать


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

		if (TypeModule==3 || TypeModule==5)
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

		if (TypeModule==3 || TypeModule==5)
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

		if (TypeModule==3  || TypeModule==5)
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

		if (TypeModule==3  || TypeModule==5)
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

if (TypeModule==5)
	{
	//создадим объект ФР и подключим
	OpenFormViborOborud();
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

AddMyGlobalFunctionInFastReport();
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

if (TypeModule==3 || TypeModule==5)  //		3 FastReport
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

if (TypeModule==3 || TypeModule==5)  //		3 FastReport
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

if (TypeModule==3 || TypeModule==5)  //		3 FastReport
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

if (TypeModule==3 || TypeModule==5)  //		3 FastReport
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
//Close();
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
void TFormaRunExternalModule::AddMyGlobalFunctionInFastReport(void)
{

frxReport1->AddFunction("function glCurrencyPropis(value : Double) : String",
						"MyGlobalFunction",
						"Вещественное число прописью");

frxReport1->AddFunction("function glIntegerValuePropis(value : Integer) : String",
						"MyGlobalFunction",
						"Целое число прописью");

frxReport1->AddFunction("function glGetNameDoc(value : String) : String",
						"MyGlobalFunction",
						"Получить название документа по коду");


AddFunctionFRInFastReport();
}
//-------------------------------------------------------------------------

Variant __fastcall TFormaRunExternalModule::frxReport1UserFunction(const UnicodeString MethodName,
          Variant &Params)
{
Variant result;
bool result_bool=false;
if (MethodName == "GLCURRENCYPROPIS")
	{
	result=glCurrencyPropis(StrToFloat(VarToStr(Params.GetElement(0))));
	}

if (MethodName == "GLINTEGERVALUEPROPIS")
	{
	result=glIntegerValuePropis(StrToInt(VarToStr(Params.GetElement(0))));
	}

if (MethodName == "GLGETNAMEDOC")
	{
	result=glGetNameDoc(VarToStr(Params.GetElement(0)));
	}

if (MethodName == "KASFRPRINTSTRING")
	{
	if (ConnectFR==true && FR_Error==false)
		{
		UnicodeString str=" "; Variant str_v=Params.GetElement(0);
		if (str_v.IsNull() == true) {} else  {str=VarToStr(str_v);}

		int size_font=0; Variant size_font_v = Params.GetElement(1);
		if (size_font_v.IsNull() == true) {} else  {size_font=StrToInt(VarToStr(size_font_v));}

		int girn=0; Variant girn_v = Params.GetElement(2);
		if (girn_v.IsNull() == true) {} else  {girn=StrToInt(VarToStr(girn_v));}

		int alligment=0; Variant alligment_v = Params.GetElement(3);
		if (alligment_v.IsNull() == true) {} else  {alligment=StrToInt(VarToStr(alligment_v));}

		bool ch_lenta=false; Variant ch_lenta_v = Params.GetElement(4);
		if (ch_lenta_v.IsNull() == true) {} else  {ch_lenta=StrToInt(VarToStr(ch_lenta_v));}

		bool kontr_lenta=false; Variant kontr_lenta_v = Params.GetElement(5);
		if (kontr_lenta_v.IsNull() == true) {} else  {kontr_lenta=StrToInt(VarToStr(kontr_lenta_v));}

		bool word_wrap=false; Variant word_wrap_v = Params.GetElement(6);
		if (word_wrap_v.IsNull() == true) {} else  {word_wrap=StrToInt(VarToStr(word_wrap_v));}

		Memo1->Lines->Add("KASFRPRINTSTRING  "+str);

		result_bool=FR->PrintString(str,
								size_font,  //1234
								girn,  //1-жирный 0 обычный
								alligment,   //0 лево 1 центр 2 право
								ch_lenta,   //на чековой ленте         bool
								kontr_lenta,    //на контрольной ленте    bool
								word_wrap );  //перенос bool

		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}
		}
	}

if (MethodName == "KASFRGETSOSTKKM")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		Memo1->Lines->Add("KASFRGETSOSTKKM  ");
		result_bool=FR->GetSostKKM();

		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}

		}

	}

if (MethodName == "KASFRPROVVOSMPRINTCHECK")
	{
	//ShowMessage("if (MethodName == KASFRPROVVOSMPRINTCHECK)");
		if (ConnectFR==true  && FR_Error==false)
		{
		Memo1->Lines->Add("KASFRPROVVOSMPRINTCHECK ");
		result_bool=FR->ProvVosmPrintCheck();
	   //	ShowMessage("выполнили if (MethodName == KASFRPROVVOSMPRINTCHECK)");

		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}
		if (result_bool==true)
			{
			Memo1->Lines->Add("Результат: true");
			}
		if (result_bool==false)
			{
			Memo1->Lines->Add("Результат: false");
			}


		}


	result=result_bool;
	}

if (MethodName == "KASFRPRINTFISCALCHECK")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		Memo1->Lines->Add("KASFRPRINTFISCALCHECK "+
											FloatToStr(double(Params.GetElement(0)))+" "+
											IntToStr(int(Params.GetElement(1)))+"  "+
											FloatToStr(double(Params.GetElement(2)))+" "+
											FloatToStr(double(Params.GetElement(3)))+" "+
											FloatToStr(double(Params.GetElement(4)))+" "+
											FloatToStr(double(Params.GetElement(5)))+" "+
											FloatToStr(int(Params.GetElement(6))) );

		result_bool=FR->PrintFiscalCheck(double(Params.GetElement(0)),
								int(Params.GetElement(1)),
								double(Params.GetElement(2)),
								double(Params.GetElement(3)),
								double(Params.GetElement(4)),
								double(Params.GetElement(5)),
								int(Params.GetElement(6)) );
		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}


		}
	}


if (MethodName == "KASFRPRINTNOFISCALCHECK")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
				Memo1->Lines->Add("KASFRPRINTFISCALCHECK "+
											FloatToStr(double(Params.GetElement(0)))+" "+
											IntToStr(int(Params.GetElement(1)))+"  "+
											FloatToStr(double(Params.GetElement(2)))+" "+
											FloatToStr(double(Params.GetElement(3)))+" "+
											FloatToStr(double(Params.GetElement(4)))+" "+
											FloatToStr(double(Params.GetElement(5)))+" "+
											FloatToStr(int(Params.GetElement(6))) );
		result_bool=FR->PrintNoFiscalCheck(double(Params.GetElement(0)),
								int(Params.GetElement(1)),
								double(Params.GetElement(2)),
								double(Params.GetElement(3)),
								double(Params.GetElement(4)),
								double(Params.GetElement(5)),
								int(Params.GetElement(6)) );
		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}

		}
	}

if (MethodName == "KASFRCUT")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		Memo1->Lines->Add("KASFRCUT");
		result_bool=FR->Cut(int(Params.GetElement(0)));

		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}
		}
	}

if (MethodName == "KASFRPRINTLINE")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		Memo1->Lines->Add("KASFRPRINTLINE ");
		result_bool=FR->PrintLine();

		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}

		}
	}

if (MethodName == "KASFROPENNOFISCALCHECK")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		Memo1->Lines->Add("KASFROPENNOFISCALCHECK");
		result_bool=FR->OpenNoFiscalCheck();

		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}
		}
	}

if (MethodName == "KASFRCLOSENOFISCALCHECK")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		Memo1->Lines->Add("KASFRCLOSENOFISCALCHECK");
		result_bool=FR->CloseNoFiscalCheck();

		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}
		}
	}

if (MethodName == "KASFRSETPARAMETERCHECKINDOC")
	{
	Memo1->Lines->Add("KASFRSETPARAMETERCHECKINDOC");
	if (ConnectFR==true  && FR_Error==false)
		{
		result_bool=SetParameterCheckInDoc(glStrToInt64(VarToStr(Params.GetElement(0))));
		}
	}

if (MethodName == "KASFRGETPARAMETERCHECKINDOC")
	{
	Memo1->Lines->Add("KASFRGETPARAMETERCHECKINDOC");
	result=GetParameterCheckInDoc(glStrToInt64(VarToStr(Params.GetElement(0))));
	}


if (MethodName == "KASFRINITDOCUMENT")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		Memo1->Lines->Add("KASFRINITDOCUMENT");
		UnicodeString s="";
		result_bool=FR->InitDocument(int(Params.GetElement(0)));

//		Variant value=frxReport1->Variables->Variables["TaxVariant"];
//		if (value.IsNull()==false) {FR->TaxVariant=value.AsType(varInteger); s=s+" TaxVariant "+IntToStr(FR->TaxVariant);}

		Memo1->Lines->Add("KASFRINITDOCUMENT: "+s);
		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}
		}
	}

if (MethodName == "KASFRADDFISCALSTRING")
	{

	if (ConnectFR==true  && FR_Error==false)
		{
		Memo1->Lines->Add("KASFRADDFISCALSTRING");
		UnicodeString s="TypeFiscalString=1";

		FR->TypeFiscalString=1;   //1-фиск строка 2- текстовая строка 3-штрих код

		Variant value=frxReport1->Variables->Variables["NameNom"];
		if (value.IsNull()==false) {FR->NameNom=value.AsType(varString);s=s+" NameNom "+FR->NameNom;}

		value=frxReport1->Variables->Variables["Quantity"];
		if (value.IsNull()==false) {FR->Quantity=value.AsType(varDouble);s=s+" Quantity "+FloatToStr(FR->Quantity);}

		value=frxReport1->Variables->Variables["Price"];
		if (value.IsNull()==false) {FR->Price=value.AsType(varDouble);s=s+" Price "+FloatToStr(FR->Price);}

		value=frxReport1->Variables->Variables["Amount"];
		if (value.IsNull()==false) {FR->Amount=value.AsType(varDouble);s=s+" Amount "+FloatToStr(FR->Amount);}

		value=frxReport1->Variables->Variables["Department"];
		if (value.IsNull()==false) {FR->Department=value.AsType(varInteger); s=s+" Department "+IntToStr(FR->Department);}

		value=frxReport1->Variables->Variables["Tax"];
		if (value.IsNull()==false) {FR->Tax=value.AsType(varInteger);s=s+" Tax "+IntToStr(FR->Tax);}

		Memo1->Lines->Add("AddFiscalString: "+s);

		result_bool=FR->AddFiscalString();

		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}
		}
	}

if (MethodName == "KASFRCREATEHEADERFISCALCHECK")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		Memo1->Lines->Add("KASFRCREATEHEADERFISCALCHECK");
		result_bool=FR->CreateHeaderFiscalCheck();

		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}
		}
	}

if (MethodName == "KASFRCREATEFOOTERFISCALCHECK")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		Memo1->Lines->Add("KASFRCREATEFOOTERFISCALCHECK");
		result_bool=FR->CreateFooterFiscalCheck();

		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}
		}
	}

if (MethodName == "KASFRRUNCOMMAND")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		UnicodeString param2=" "; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=VarToStr(param2_v);}

		int param3=0; Variant param3_v=Params.GetElement(2);
		if (param3_v.IsNull() == true) {} else  {param3=param3_v.AsType(varInteger);}


		Memo1->Lines->Add("KASFRCREATEDOCFROMXML command_name:\n"+
											param1+" \nxml_doc"+
											param2+" \ntype_doc"+
											IntToStr(param3)+"\n");


		result_bool=FR->RunCommand(param1, param2, param3);

		if (result_bool==false)
			{
			FR_Error=true;
			Memo1->Lines->Add("Ошибка: "+FR->TextError);
			}
		if (result_bool==true)
			{
			Memo1->Lines->Add("Результат: true");
			}
		if (result_bool==false)
			{
			Memo1->Lines->Add("Результат: false");
			}


		}
	}

 if (MethodName == "KASFRRETURNXMLRESULTLASTMETHOD")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		Memo1->Lines->Add("KASFRRETUTNXMLRESULTLASTMETHOD ");


		result=FR->ReturnXmlResultLastMethod();
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}


		}
	}

if (MethodName == "KASFRSETSTRINGPARAMETER")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		int param2=0; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=param2_v.AsType(varInteger);}

		UnicodeString param3=" "; Variant param3_v=Params.GetElement(2);
		if (param3_v.IsNull() == true) {} else  {param3=VarToStr(param3_v);}

		Memo1->Lines->Add("KASFRSETSTRINGPARAMETER command_name:\n");

		result=FR->SetStringParameter(param1, param2, param3);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRGETSTRINGPARAMETER")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		int param2=0; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=param2_v.AsType(varInteger);}


		Memo1->Lines->Add("KASFRGETSTRINGPARAMETER command_name:\n");

		result=FR->GetStringParameter(param1, param2);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRSETINTEGERPARAMETER")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		int param2=0; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=param2_v.AsType(varInteger);}

		int param3=0; Variant param3_v=Params.GetElement(2);
		if (param3_v.IsNull() == true) {} else  {param3=param3_v.AsType(varInteger);}

		Memo1->Lines->Add("KASFRSETINTEGERPARAMETER command_name:\n");

		result=FR->SetIntegerParameter(param1, param2, param3);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRGETINTEGERPARAMETER")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		int param2=0; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=param2_v.AsType(varInteger);}


		Memo1->Lines->Add("KASFRGETINTEGERPARAMETER command_name:\n");

		result=FR->GetIntegerParameter(param1, param2);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRSETDOUBLEPARAMETER")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		int param2=0; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=param2_v.AsType(varInteger);}

		double param3=0; Variant param3_v=Params.GetElement(2);
		if (param3_v.IsNull() == true) {} else  {param3=param3_v.AsType(varDouble);}

		Memo1->Lines->Add("KASFRSETDOUBLEPARAMETER command_name:\n");

		result=FR->SetDoubleParameter(param1, param2, param3);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRGETDOUBLEPARAMETER")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		int param2=0; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=param2_v.AsType(varInteger);}


		Memo1->Lines->Add("KASFRGETDOUBLEPARAMETER command_name:\n");

		result=FR->GetDoubleParameter(param1, param2);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRSETBOOLEANPARAMETER")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		int param2=0; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=param2_v.AsType(varInteger);}

		bool param3=0; Variant param3_v=Params.GetElement(2);
		if (param3_v.IsNull() == true) {} else  {param3=param3_v.AsType(varBoolean);}

		Memo1->Lines->Add("KASFRSETBOOLEANPARAMETER command_name:\n");

		result=FR->SetBooleanParameter(param1, param2, param3);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRGETBOOLEANPARAMETER")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		int param2=0; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=param2_v.AsType(varInteger);}


		Memo1->Lines->Add("KASFRGETBOOLEANPARAMETER command_name:\n");

		result=FR->GetBooleanParameter(param1, param2);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}



//	virtual bool SetDateTimeParameter(UnicodeString param_name, int number, TDateTime value)=0;
//	virtual TDateTime GetDateTimeParameter(UnicodeString param_name, int number)=0;

if (MethodName == "KASFRSETXMLPARAMETER")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		int param2=0; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=param2_v.AsType(varInteger);}

		UnicodeString param3=" "; Variant param3_v=Params.GetElement(2);
		if (param3_v.IsNull() == true) {} else  {param3=VarToStr(param3_v);}

		int param4=0; Variant param4_v=Params.GetElement(3);
		if (param4_v.IsNull() == true) {} else  {param4=param4_v.AsType(varInteger);}

		Memo1->Lines->Add("KASFRSETXMLPARAMETER command_name:\n");

		result=FR->SetXmlParameter(param1, param2, param3, param4);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRGETXMLPARAMETER")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		int param2=0; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=param2_v.AsType(varInteger);}

		int param3=0; Variant param3_v=Params.GetElement(2);
		if (param3_v.IsNull() == true) {} else  {param3=param3_v.AsType(varInteger);}

		Memo1->Lines->Add("KASFRGETXMLPARAMETER command_name:\n");

		result=FR->GetXmlParameter(param1, param2, param3);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRSETIDDEVICEPARAMETER")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		int param2=0; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=param2_v.AsType(varInteger);}

		UnicodeString param3=" "; Variant param3_v=Params.GetElement(2);
		if (param3_v.IsNull() == true) {} else  {param3=VarToStr(param3_v);}

		int param4=0; Variant param4_v=Params.GetElement(3);
		if (param4_v.IsNull() == true) {} else  {param4=param4_v.AsType(varInteger);}

		Memo1->Lines->Add("KASFRSETIDDEVICEPARAMETER command_name:\n");

		result=FR->SetIdDeviceParameter(param1, param2, param3, param4);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRGETIDDEVICEPARAMETER")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		int param2=0; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=param2_v.AsType(varInteger);}

		int param3=0; Variant param3_v=Params.GetElement(2);
		if (param3_v.IsNull() == true) {} else  {param3=param3_v.AsType(varInteger);}

		Memo1->Lines->Add("KASFRGETIDDEVICEPARAMETER command_name:\n");

		result=FR->GetIDDeviceParameter(param1, param2, param3);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRADDSTRINGXML")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}


		Memo1->Lines->Add("KASFRADDSTRINGXML :\n");

		FR->AddStringXml(param1);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}


if (MethodName == "KASFRADDATTRIBUTEXML")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		UnicodeString param2=" "; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=VarToStr(param2_v);}

		int param3=0; Variant param3_v=Params.GetElement(2);
		if (param3_v.IsNull() == true) {} else  {param3=param3_v.AsType(varInteger);}

		Memo1->Lines->Add("KASFRADDATTRIBUTEXML command_name:\n");

		FR->AddAttribyteXml(param1, param2, param3);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRADDELEMENTXML")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		UnicodeString param2=" "; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=VarToStr(param2_v);}

		int param3=0; Variant param3_v=Params.GetElement(2);
		if (param3_v.IsNull() == true) {} else  {param3=param3_v.AsType(varInteger);}

		Memo1->Lines->Add("KASFRADDELEMENTXML command_name:\n");

		FR->AddElementXml(param1, param2, param3);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}

if (MethodName == "KASFRADDSTRINGFORPRINTXML")
	{
	if (ConnectFR==true  && FR_Error==false)
		{
		UnicodeString param1=" "; Variant param1_v=Params.GetElement(0);
		if (param1_v.IsNull() == true) {} else  {param1=VarToStr(param1_v);}

		UnicodeString param2=" "; Variant param2_v=Params.GetElement(1);
		if (param2_v.IsNull() == true) {} else  {param2=VarToStr(param2_v);}

		UnicodeString param3=" "; Variant param3_v=Params.GetElement(2);
		if (param3_v.IsNull() == true) {} else  {param3=VarToStr(param3_v);}

		int param4=0; Variant param4_v=Params.GetElement(3);
		if (param4_v.IsNull() == true) {} else  {param4=param4_v.AsType(varInteger);}

		int param5=0; Variant param5_v=Params.GetElement(4);
		if (param5_v.IsNull() == true) {} else  {param5=param5_v.AsType(varInteger);}

		int param6=0; Variant param6_v=Params.GetElement(5);
		if (param6_v.IsNull() == true) {} else  {param6=param6_v.AsType(varInteger);}

		bool param7=0; Variant param7_v=Params.GetElement(6);
		if (param7_v.IsNull() == true) {} else  {param7=param7_v.AsType(varBoolean);}

		Memo1->Lines->Add("KASFRADDSTRINGFORPRINTXML command_name:\n");

		FR->AddStringForPrintXml(param1, param2, param3, param4, param5, param6, param7);
//		if (result_bool==false)
//			{
//			FR_Error=true;
//			Memo1->Lines->Add("Ошибка: "+FR->TextError);
//			}
		}
	}



return result;
}
//---------------------------------------------------------------------------

void TFormaRunExternalModule::OpenFormViborOborud(void)
{

   if (FormaViborOborud == 0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborOborud.1",IID_IFormaViborOborud,
													(void**)&FormaViborOborud);
	FormaViborOborud->Init(InterfaceMainObject,InterfaceImpl);
    FormaViborOborud->NumberProcVibor=ER_ViborFR;
	FormaViborOborud->IdArm=glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString);
	FormaViborOborud->TypeOborud="fr";
	FormaViborOborud->UpdateForm();
	FormaViborOborud->DM->Table->Last();
	if (FormaViborOborud->DM->Table->RecordCount==0)
		{
		FormaViborOborud->kanRelease();
		FormaViborOborud=0;
		Memo1->Lines->Add("Нет настроенных принтеров");
		//ShowMessage("Нет настроенных принтеров");
		}
	else if (FormaViborOborud->DM->Table->RecordCount==1)
		{
		IdOborud=glStrToInt64(FormaViborOborud->DM->TableID_OBORUD->AsString);
		FormaViborOborud->kanRelease();
		FormaViborOborud=0;
		if (CreateObjectFR()==true)
			{

			}
		else
			{
			Memo1->Lines->Add("Ошибка при создании или подключении фискального регистратора / принтера.");
			//ShowMessage("Ошибка при создании или подключении фискального регистратора / принтера.");
			}
		OpenFastReport();
		}
	else
		{

		}

	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaRunExternalModule::EndViborOborud(void)
{

	IdOborud=glStrToInt64(FormaViborOborud->DM->TableID_OBORUD->AsString);
		if (CreateObjectFR()==true)
			{

			}
		else
			{
			Memo1->Lines->Add("Ошибка при создании или подключении фискального регистратора / принтера. ");
			//ShowMessage("Ошибка при создании или подключении фискального регистратора / принтера.");
			}
		OpenFastReport();
		FormaViborOborud=0;
}
//---------------------------------------------------------------------------
bool TFormaRunExternalModule::CreateObjectFR (void)
{
bool result=false;
__int64 id_arm=glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString);

// принтер выбран, надо создать объект и подключить
if (IdOborud ==0 || id_arm==0)
	{
	 result=false;
	 return result;
	}

	IDMSprOborud * oborud;
	InterfaceGlobalCom->kanCreateObject(ProgId_DMSprOborud,IID_IDMSprOborud,
													(void**)&oborud);
	oborud->Init(InterfaceMainObject,InterfaceImpl);
	oborud->OpenElement(IdOborud);

	AnsiString prog_id=oborud->ElementPROGID_SOBORUD->AsString;;
	Memo1->Lines->Add("Создаем объект ФР: "+prog_id);
	InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
													(void**)&FR);
    FR->Modul=oborud->ElementMODUL_SOBORUD->AsString;
	FR->Init(InterfaceMainObject,InterfaceImpl);

		int number_port=0;
		if (oborud->ElementCOMNAME_OBORUD->AsString!="")
			{
			number_port=StrToFloat(oborud->ElementCOMNAME_OBORUD->AsString);
			}
		AnsiString baud_rate=oborud->ElementBAUDRATE_OBORUD->AsString;

		AnsiString password=oborud->GetParameter("password");



				IkasDMSpr * oborud_param;
				InterfaceGlobalCom->kanCreateObject(ProgId_DMSprOborudParam,IID_IkasDMSpr,
																 (void**)&oborud_param);
				oborud_param->Init(InterfaceMainObject,0);
				oborud_param->IdOwner=glStrToInt64(oborud->ElementID_OBORUD->AsString);
				oborud_param->OpenTable(0);
				//установим параметры подключения
				oborud_param->First(0);
				while(!oborud_param->GetEof(0))
					{
					TkasVariant * kv=new TkasVariant;
					InitKasVariant(kv); //

					wchar_t * wchar_t_for_kas_variant;
					int type_value=0;

					if (oborud_param->GetValueFieldAsBool("ON_CONNECT_SOBORUD_PAR", 0)==true &&
									oborud_param->GetValueFieldAsBool("BEFORE_CONNECT_SOBORUD_PAR", 0)==true)
						{ //устанавливаем данный параметр
						type_value=oborud_param->GetValueFieldAsInt("TYPE_PARAMETER_SOBORUD_PAR", 0);
						UnicodeString s="Устанавливаем параметр: "+oborud_param->GetValueFieldAsString("NAME_SOBORUD_PAR", 0)+" тип:"+IntToStr(type_value);

						if (type_value == 1) //int
							{
							kv->type=1;
							int  int_for_kas_variant =  oborud_param->GetValueFieldAsInt("VALUE_SOBORUD_PAR", 0);
							kv->int_value=int_for_kas_variant;
							s=s+" значение: "+IntToStr(kv->int_value);
							}
						if (type_value == 2) //string
							{
							kv->type=2;
							UnicodeString string_for_kas_variant = oborud_param->GetValueFieldAsString("VALUE_SOBORUD_PAR", 0);

							int length = wcslen(string_for_kas_variant.c_str());

							wchar_t_for_kas_variant = new wchar_t[length + 1];
							wcscpy(wchar_t_for_kas_variant,string_for_kas_variant.c_str());

							kv->string_value=wchar_t_for_kas_variant;
							kv->len_string=wcslen(kv->string_value);
							s=s+" значение: "+UnicodeString(kv->string_value);
							}
						if (type_value == 4) //booulean
							{
							kv->type=4;
							bool bool_for_kas_variant = oborud_param->GetValueFieldAsBool("VALUE_SOBORUD_PAR", 0);
							kv->bool_value = bool_for_kas_variant;
							if (kv->bool_value==true) {s=s+" значение: true";}
                            if (kv->bool_value==false) {s=s+" значение: false";}
							}

						Memo1->Lines->Add(s);

						UnicodeString name_parameter = oborud_param->GetValueFieldAsString("NAME_SOBORUD_PAR", 0);

						if (FR->SetParameter(name_parameter, kv) == false)
							{
							ShowMessage("Ошибка при установке параметра подключения");
							}
						}
					oborud_param->Next(0);
					delete kv;

					if (type_value == 2) {delete wchar_t_for_kas_variant;}

					}



	oborud->kanRelease();

	Memo1->Lines->Add("Подключаем ФР: порт "+IntToStr(number_port)+" пароль на связь"+password+" скорость " +baud_rate);

	if (FR->Connect(number_port, baud_rate, password)==true)
		{
		ConnectFR=true;
		result=true;
		Memo1->Lines->Add("Подключение к ФР: ОК");
		}
	else
		{
		result=false;
		ConnectFR=false;
		//ShowMessage("Ошибка при подключении фискального регистратора: "+FR->TextError);
		Memo1->Lines->Add("Ошибка подключения к ФР: "+FR->TextError+"  "+FR->TextErrorNoConnect);
		FR->kanRelease();
		}

return result;
}
//----------------------------------------------------------------------------



bool TFormaRunExternalModule::DeleteObjectFR (void)
{
bool result=false;
Memo1->Lines->Add("Отключение ФР");
FR->Disconnect();
FR->Done();
FR->kanRelease();
FR=0;

return result;
}
//----------------------------------------------------------------------------
void TFormaRunExternalModule::AddFunctionFRInFastReport(void)
{
frxReport1->AddFunction("function kasFRPrintString(str : String, size_font : Integer, girn : Integer, alignment : Integer, ch_lenta : Boolean, kontr_lenta : Boolean, word_wrap : Boolean) : Boolean",
						"kasFunctionFR",
						"Напечатать строку");

frxReport1->AddFunction("function kasFRGetSostKKM() : Boolean",
						"kasFunctionFR",
						"Получить состояние ККМ");

frxReport1->AddFunction("function kasFRProvVosmPrintCheck() : Boolean",
						"kasFunctionFR",
						"Проверить возможность печати чека");

frxReport1->AddFunction("function kasFRPrintFiscalCheck(sum : Double, department : Integer, oplata_nal : Double, oplata_bank_card : Double, oplata_plat_card : Double, oplata_credit_card : Double, operation : Integer) : Boolean",
						"kasFunctionFR",
						"Напечатать фискальный чек");

frxReport1->AddFunction("function kasFRPrintNoFiscalCheck(sum : Double, department : Integer, oplata_nal : Double, oplata_bank_card : Double, oplata_plat_card : Double, oplata_credit_card : Double, operation : Integer) : Boolean",
						"kasFunctionFR",
						"Напечатать нефискальный чек");

frxReport1->AddFunction("function kasFRCut(type_cut : Integer) : Boolean",
						"kasFunctionFR",
						"Отрезать чек");

frxReport1->AddFunction("function kasFRPrintLine() : Boolean",
						"kasFunctionFR",
						"Напечатать линию");

frxReport1->AddFunction("function kasFROpenNoFiscalCheck() : Boolean",
						"kasFunctionFR",
						"Открыть нефискальный чек");

frxReport1->AddFunction("function kasFRCloseNoFiscalCheck() : Boolean",
						"kasFunctionFR",
						"Закрыть нефискальный чек");

frxReport1->AddFunction("function kasFRSetParameterCheckInDoc(id_doc: String) : Boolean",
						"kasFunctionFR",
						"Обновить параметры чека в документе");

frxReport1->AddFunction("function kasFRGetParameterCheckInDoc(id_doc: String) : Integer",
						"kasFunctionFR",
						"Проверить можно ли печатать чек к данному документу.");


frxReport1->AddFunction("function kasFRInitDocument(type_doc : Integer) : Boolean",
						"kasFunctionFR",
						"Инициализировать документ");

frxReport1->AddFunction("function kasFRAddFiscalString() : Boolean",
						"kasFunctionFR",
						"Добавить фискальную строку");

frxReport1->AddFunction("function kasFRCreateHeaderFiscalCheck() : Boolean",
						"kasFunctionFR",
						"Создать заголовок фискального чека");

frxReport1->AddFunction("function kasFRCreateFooterFiscalCheck() : Boolean",
						"kasFunctionFR",
						"Создать подвал фискального чека");


//******************************************************************************
frxReport1->AddFunction("function kasFRRunCommand(command : String, xml_doc : String, type_doc : Integer) : Boolean",
						"kasFunctionFR",
						"Выполнить команду");


frxReport1->AddFunction("function kasFRReturnXmlResultLastMethod() : String",
						"kasFunctionFR",
						"ReturnXmlResultLastMethod");

frxReport1->AddFunction("function kasFRSetStringParameter(param_name : String, number : Integer, value : String) : Boolean",
						"kasFunctionFR",
						"kasFRSetStringParameter");

frxReport1->AddFunction("function kasFRGetStringParameter(param_name : String, number : Integer) : String",
						"kasFunctionFR",
						"kasFRGetStringParameter");

frxReport1->AddFunction("function kasFRSetIntegerParameter(param_name : String, number : Integer, value : Integer) : Boolean",
						"kasFunctionFR",
						"kasFRSetIntegerParameter");

frxReport1->AddFunction("function kasFRGetIntegerParameter(param_name : String, number : Integer) : Integer",
						"kasFunctionFR",
						"kasFRGetIntegerParameter");

frxReport1->AddFunction("function kasFRSetDoubleParameter(param_name : String, number : Integer, value : Double) : Boolean",
						"kasFunctionFR",
						"kasFRSetDoubleParameter");

frxReport1->AddFunction("function kasFRGetDoubleParameter(param_name : String, number : Integer) : Double",
						"kasFunctionFR",
						"kasFRGetDoubleParameter");

frxReport1->AddFunction("function kasFRSetBooleanParameter(param_name : String, number : Integer, value : Boolean) : Boolean",
						"kasFunctionFR",
						"kasFRSetBooleanParameter");

frxReport1->AddFunction("function kasFRGetBooleanParameter(param_name : String, number : Integer) : Boolean",
						"kasFunctionFR",
						"kasFRGetBooleanParameter");

//	virtual bool SetDateTimeParameter(UnicodeString param_name, int number, TDateTime value)=0;
//	virtual TDateTime GetDateTimeParameter(UnicodeString param_name, int number)=0;

frxReport1->AddFunction("function kasFRSetXmlParameter(param_name : String, number : Integer, xml_value : String, type_source_xml : Integer) : Boolean",
						"kasFunctionFR",
						"kasFRSetXmlParameter");

frxReport1->AddFunction("function kasFRGetXmlParameter(param_name : String, number : Integer, type_source_xml : Integer) : String",
						"kasFunctionFR",
						"kasFRGetXmlParameter");

frxReport1->AddFunction("function kasFRSetIdDeviceParameter(param_name : String, number : Integer, id_device : String, type_source_id_device : Integer) : Boolean",
						"kasFunctionFR",
						"kasFRSetIdDeviceParameter");

frxReport1->AddFunction("function kasFRGetIDDeviceParameter(param_name : String, number : Integer, type_source_id_device : Integer) : String",
						"kasFunctionFR",
						"kasFRGetIDDeviceParameter");


	//формирование xml файла


frxReport1->AddFunction("function kasFRAddStringXml(str_xml : String) : void",      //просто готовая строка
						"kasFunctionFR",
						"kasFRAddStringXml");

frxReport1->AddFunction("function kasFRAddAttributeXml(attribyte : String, value : String, type_value : Integer ) : void",  //тип для форматирования, например для удаления запятых в числах
						"kasFunctionFR",
						"kasFRAddStringXml");

frxReport1->AddFunction("function kasFRAddElementXml(element : String, value : String, type_value : Integer ) : void",
						"kasFunctionFR",
						"kasFRAddAttribyteXml");

frxReport1->AddFunction("function kasFRAddStringForPrintXml(element : String, attribyte : String, value : String, size_font : Integer, style : Integer, alignment : Integer, word_wrap : Boolean) : void",
						"kasFunctionFR",
						"kasFRAddStringForPrintXml");


}
//-----------------------------------------------------------------------------
bool TFormaRunExternalModule::SetParameterCheckInDoc(__int64 id_doc)
{
bool result;

	if (ConnectFR==true  && FR_Error==false)
		{

IDMQueryUpdate * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryUpdate.1",IID_IDMQueryUpdate, (void**)&dm);
dm->Init(InterfaceMainObject,0);
try {
	dm->pFIBQ->Close();
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("execute procedure doc_set_param_check_kkm (:PARAM_IDDOC,:PARAM_NUMCHECK,:PARAM_NUMKL,:PARAM_NAMEKKM,:PARAM_SERNUM,:PARAM_REGNUM)");

	dm->pFIBQ->ParamByName("PARAM_IDDOC")->AsString=id_doc;
	dm->pFIBQ->ParamByName("PARAM_NUMCHECK")->AsInteger=FR->NumberCheck;
	dm->pFIBQ->ParamByName("PARAM_NUMKL")->AsInteger=FR->NumberKL;
	dm->pFIBQ->ParamByName("PARAM_NAMEKKM")->AsString=FR->ModelKKM;
	dm->pFIBQ->ParamByName("PARAM_SERNUM")->AsString=FR->SerialNumberKKM;
	dm->pFIBQ->ParamByName("PARAM_REGNUM")->AsString=FR->RegNumberKKM;

	Memo1->Lines->Add("Устанавливаем параметры чека ККМ: ID"+IntToStr(id_doc)+"  номер: "+FR->NumberCheck+"  номер КЛ: "+FR->NumberKL+
											"  модель: "+FR->ModelKKM+"  сер. номер: "+FR->SerialNumberKKM+"  рег. номер: "+FR->RegNumberKKM);

	dm->pFIBQ->ExecQuery();
	dm->pFIBQ->Close();
	dm->pFIBTr->Commit();

	Memo1->Lines->Add("Результат: ОК");
	result=true;
	}
catch(Exception &exception)
				{
				dm->pFIBTr->Rollback();
				TextError=exception.Message;
				Memo1->Lines->Add("Результат: ошибка: "+exception.Message);
				result=false;
				}
dm->kanRelease();
		}
return result;
}
//-----------------------------------------------------------------------------
int TFormaRunExternalModule::GetParameterCheckInDoc(__int64 id_doc)
{
int result=0;
Memo1->Lines->Add("Получаем возможно ли печатать чек ID"+IntToStr(id_doc));

IDMQueryRead * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead, (void**)&dm);
dm->Init(InterfaceMainObject,0);

	dm->pFIBQ->Close();
	dm->pFIBQ->SQL->Clear();
	dm->pFIBQ->SQL->Add("execute procedure DOC_GET_PARAM_CHECK_KKM (:PARAM_IDDOC)");
	dm->pFIBQ->ParamByName("PARAM_IDDOC")->AsString=id_doc;
	dm->pFIBQ->ExecQuery();
	result=dm->pFIBQ->FieldByName("OUT_RES")->AsInteger;

	dm->pFIBQ->Close();

dm->kanRelease();

Memo1->Lines->Add("Результат: "+IntToStr(result));


return result;
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModule::InitKasVariant(TkasVariant * kv)
{
kv->type=0;
kv->int_value=0;
kv->string_value=L"";
kv->dbl_value=0;
kv->bool_value=0;
kv->day=0;
kv->month=0;
kv->year=0;
kv->hour=0;
kv->min=0;
kv->sec=0;
kv->len_string=0;
}
//--------------------------------------------------------------------------
