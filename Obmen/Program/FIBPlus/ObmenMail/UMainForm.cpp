//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMainForm.h"
#include "inifiles.hpp"
#include "UDM.h"
#include "UDMUribOut.h"
#include "UDMUribIn.h"
#include <fstream.h>
#include "UkanIniFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IdExplicitTLSClientServerBase"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxLabel"
#pragma resource "*.dfm"
TMainForm *MainForm;
extern TDM * glDM;
extern UnicodeString GetVersionProgramFile(void);

bool glPodrProtokol;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
FlagRunAutoObmen=false;
glPodrProtokol=true;
GlobalInterval=600;
IdBaseForObmencxLabel->Caption="ID: не задано";


//зададим каталог протоколов
UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
if (DirectoryExists(ProgramCatalog+"\\Log")==false)
        {
        CreateDir(ProgramCatalog+"\\Log");
        }

if (DirectoryExists(ProgramCatalog+"\\Log")==true)
        {
        CatalogProtocol=ProgramCatalog+"\\Log";
        }

//создадим каталог с файлами обмена
if (DirectoryExists(ProgramCatalog+"\\Files")==false)
		{
		CreateDir(ProgramCatalog+"\\Files");
		}

LocCatalog=ProgramCatalog+"\\Files";

//начальные значения

ConnectString="";
PatchArhivator="";
PatchUnArh="";

NameBaseForObmen="";
IdBaseForObmen=0;

Interval=0;
IntervalAfterError=0;


AutoObmen=false;


LoadSpisokBase();
GetParameterObmen();
UpdateForm();

glDM=new TDM(Application);

Memo1->Lines->Add("Версия программы: "+glDM->GetVersionProgramFile());
glDM->glSaveProtocol("Версия программы:"+glDM->GetVersionProgramFile());
UpdateProgressBar=true;


UnicodeString catalog=ExtractFilePath(Application->ExeName);
UnicodeString file_ini=catalog+GC_FileNameIniSetup;
TkanIniFile * ini=new TkanIniFile(file_ini);


if (ini->ReadString("Main","AutoStart","")=="1")
		{
		AutoObmen=true;
		}

delete ini;

if (AutoObmen==true)
		{

			FlagRunAutoObmen=true;
			Memo1->Lines->Add(TimeToStr(Time())+" Запускаем процедуру автообмена");

			//заполняем список баз

			UnicodeString catalog=ExtractFilePath(Application->ExeName);
			UnicodeString file_ini=catalog+GC_FileNameIni;

			TkanIniFile * ini=new TkanIniFile(file_ini);
			BaseList=new TStringList();
			ini->ReadSections(BaseList);
			Memo1->Lines->Add(TimeToStr(Time())+" Получили список баз. В списке "+IntToStr(BaseList->Count));
			delete ini;

			TecNumberBase=0;

			Memo1->Lines->Add(TimeToStr(Time())+" Запускаем таймер");
			StartTimerIntervalObmena();

		TimerHide->Interval=1;
		TimerHide->Enabled=true;

		}

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
delete glDM;
}
//---------------------------------------------------------------------------
void TMainForm::LoadSpisokBase(void)
{
//заполнить список баз для обмена

UnicodeString catalog=ExtractFilePath(Application->ExeName);
UnicodeString file_ini=catalog+GC_FileNameIni;

TkanIniFile * ini=new TkanIniFile(file_ini);
TStringList * list=new TStringList();
ini->ReadSections(list);

PopupMenuInfBase->Items->Clear();

	for (int i=0; i<list->Count;i++)
		{
		TMenuItem *menu=new TMenuItem(PopupMenuInfBase);
		menu->Caption=ini->ReadString(list->Strings[i],GC_NameIniParameter_NameBaseForObmen,"");
		menu->OnClick = PopupMenuInfBaseClick;
		menu->Tag=ini->ReadIntegerValue(list->Strings[i],GC_NameIniParameter_IdBaseForObmen,0);
		PopupMenuInfBase->Items->Add(menu);
		}

delete list;
delete ini;

if (PopupMenuInfBase->Items->Count > 0)
	{
	TMenuItem * menu=PopupMenuInfBase->Items->Items[0];
	int id= menu->Tag;
	IdBaseForObmen=id;
	IdBaseForObmencxLabel->Caption="ID: "+IntToStr(IdBaseForObmen);
	GetParameterObmen();
	UpdateForm();

	}


}
//----------------------------------------------------------------------------
void __fastcall TMainForm::PopupMenuInfBaseClick(TObject *Sender)
{
int id= ((TMenuItem*)Sender)->Tag;
IdBaseForObmen=id;
IdBaseForObmencxLabel->Caption="ID: "+IntToStr(IdBaseForObmen);
GetParameterObmen();
UpdateForm();
}
//----------------------------------------------------------------------------
void TMainForm::GetParameterObmen(void)
{
UnicodeString catalog=ExtractFilePath(Application->ExeName);
UnicodeString file_ini=catalog+GC_FileNameIni;

TkanIniFile * ini=new TkanIniFile(file_ini);

//параметры базы для обмена
NameBaseForObmen=ini->ReadString(IntToStr(IdBaseForObmen),GC_NameIniParameter_NameBaseForObmen,"");
if (ini->ReadString(IntToStr(IdBaseForObmen),GC_NameIniParameter_IdBaseForObmen,"")=="")
	{
	IdBaseForObmen=0;
	}
else
	{
	IdBaseForObmen=StrToInt64(ini->ReadString(IntToStr(IdBaseForObmen),"InfBaseForObmenIDBase",""));
	}

//параметры подключения к базе
UserName="EXTUSER";//ini->ReadString("User","NameUser","");
PasswordUser=ini->ReadString(IntToStr(IdBaseForObmen),"UserPassword","");
ConnectString=ini->ReadString(IntToStr(IdBaseForObmen),"InfBaseConnectString","");

//архивирование
PatchArhivator=ini->ReadString(IntToStr(IdBaseForObmen), "ArhivatorPatch", "");
PatchUnArh=ini->ReadString(IntToStr(IdBaseForObmen), "ArhivatorPatchUnArh", "");

//параметры автообмена
if (ini->ReadString(IntToStr(IdBaseForObmen), "AutoObmenRun","")=="1")
		{
		AutoObmen=true;
		}
else
		{
		AutoObmen=false;
		}

if (ini->ReadString(IntToStr(IdBaseForObmen), "AutoObmenInterval","").Length()!=0)
	{
	Interval=StrToInt(ini->ReadString(IntToStr(IdBaseForObmen), "AutoObmenInterval","0"));
	}

if (ini->ReadString(IntToStr(IdBaseForObmen), "AutoObmenIntervalAfterError","").Length()!=0)
	{
	Interval=StrToInt(ini->ReadString(IntToStr(IdBaseForObmen), "AutoObmenIntervalAfterError","0"));
	}

//способ обмена
if (ini->ReadString(IntToStr(IdBaseForObmen),GC_NameIniParameter_TypeObmen,"").Length()!=0)
	{
	TypeObmen=StrToInt(ini->ReadString(IntToStr(IdBaseForObmen),GC_NameIniParameter_TypeObmen,"0"));
	}
CatalogObmena=ini->ReadString(IntToStr(IdBaseForObmen),"CatalogObmenaPatch", "");

FTPHost=ini->ReadString(IntToStr(IdBaseForObmen), "FTPHost", "");
FTPPatch=ini->ReadString(IntToStr(IdBaseForObmen), "FTPCatalog", "");
FTPUser=ini->ReadString(IntToStr(IdBaseForObmen), "FTPUser", "");
FTPPassword=ini->ReadString(IntToStr(IdBaseForObmen), "FTPPassword", "");
delete ini;
}
//---------------------------------------------------------------------------
void TMainForm::UpdateForm(void)
{
//GetIdTecBase();
NameBaseForObmenLabel->Caption="Обмен с базой: "+NameBaseForObmen;
StringConnectLabel->Caption="Текущая база: "+ConnectString;
Caption="Модуль обмена между ИБ. Обмен с базой - "+NameBaseForObmen;

}
//----------------------------------------------------------------------------
//настройка параметров
void TMainForm::OpenFormSetupObmen(void)
{
if (FormaSetupObmen==0)
	{
	FormaSetupObmen=new TFormaSetupObmen(Application);
	if (FormaSetupObmen==0) return;
	FormaSetupObmen->FOnCloseForm=CloseFormSetupObmen;
	FormaSetupObmen->IdTecBase=IdTecBase;
	FormaSetupObmen->IdBaseForObmen=IdBaseForObmen;
	FormaSetupObmen->UpdateForm();
	FormaSetupObmen->Show();
	}
}
//----------------------------------------------------------------------------
void TMainForm::OpenFormSetupObmenNewBase(void)
{
if (FormaSetupObmen==0)
	{
	FormaSetupObmen=new TFormaSetupObmen(Application);
	if (FormaSetupObmen==0) return;
	FormaSetupObmen->FOnCloseForm=CloseFormSetupObmen;
	FormaSetupObmen->IdTecBase=IdTecBase;
	FormaSetupObmen->IdBaseForObmen=0;
	FormaSetupObmen->UpdateForm();
	FormaSetupObmen->Show();
	}
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::CloseFormSetupObmen(TObject *Sender)
{
GetParameterObmen();
FormaSetupObmen=0;
LoadSpisokBase();
UpdateForm();
}
//-----------------------------------------------------------------------------
void __fastcall TMainForm::OpenFormSetupMainMenuClick(TObject *Sender)
{
OpenFormSetupObmen();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButtonSetupClick(TObject *Sender)
{
OpenFormSetupObmen();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButtonAddBaseClick(TObject *Sender)
{
OpenFormSetupObmenNewBase();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CreateDataOutMainMenuClick(TObject *Sender)
{
glDM->UserName=UserName;
glDM->PasswordUser=PasswordUser;
glDM->ConnectString=ConnectString;

if (glDM->ConnectInfBase()==true)
	{
	TDMUribOut * dm=new TDMUribOut(Application);
	dm->EventFirstRecord=EventFirstRecord;
	dm->EventNextRecord=EventNextRecord;
	lpKolRecord=dm->lpKolRecord;
	UpdateProgressBar=true;



	if (dm->CreateDataOutTable(IdBaseForObmen)==true)
		{
		ShowMessage("Данные подготовлены!");
		}
	else
		{
		ShowMessage("Ошибка при подготовке данных: "+dm->TextError);
		}
	delete dm;
	}
else
	{
	ShowMessage("Ошибка при подключении к базе данных: "+glDM->TextError);

	}

glDM->DisconnectInfBase();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::CreateFileMainMenuClick(TObject *Sender)
{
glDM->UserName=UserName;
glDM->PasswordUser=PasswordUser;
glDM->ConnectString=ConnectString;

if (glDM->ConnectInfBase()==true)
	{
	TDMUribOut * dm=new TDMUribOut(Application);
	dm->EventFirstRecord=EventFirstRecord;
	dm->EventNextRecord=EventNextRecord;
	lpKolRecord=dm->lpKolRecord;
	UpdateProgressBar=true;

	if (dm->CreateXMLDoc(IdBaseForObmen,false)==true)
		{
		ShowMessage("Файл сформирован!");
		}
	else
		{
		ShowMessage("Ошибка при формировании файла: "+dm->TextError);
		}
	delete dm;
	}
else
	{
	ShowMessage("Ошибка при подключении к базе данных: "+glDM->TextError);

	}

glDM->DisconnectInfBase();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ZagrIsmenMainMenuClick(TObject *Sender)
{

Memo1->Lines->Add(TimeToStr(Time())+"  Попытка загрузить изменения...");
glDM->glSaveProtocol("Попытка загрузить изменения...");
UnicodeString FileNameXML;
if (OpenDialog1->Execute())
		{
		glDM->UserName=UserName;
		glDM->PasswordUser=PasswordUser;
		glDM->ConnectString=ConnectString;

		if (glDM->ConnectInfBase()==true)
			{
			TDMUribIn *DMIn=new TDMUribIn(Application);
			DMIn->EventFirstRecord=EventFirstRecord;
			DMIn->EventNextRecord=EventNextRecord;
			lpKolRecord=DMIn->lpKolRecord;
			UpdateProgressBar=false;
			
			try
				{
				FileNameXML=OpenDialog1->FileName;
				glDM->glSaveProtocol("Загружаем данные из файла:"+FileNameXML);
				DMIn->UpdateDataInfBase(FileNameXML);
				Memo1->Lines->Add(TimeToStr(Time())+"  Изменения загружены!");
				glDM->glSaveProtocol("Изменения загружены!");
				}
			catch (Exception &exception)
				{
				if (DMIn>0) glDM->glSaveProtocol("Ошибка загрузки! "+exception.Message+"\n Загружено записей: "+IntToStr(DMIn->kol_rec));
				}

			delete DMIn;
			glDM->DisconnectInfBase();
			}
		else
			{
			ShowMessage("Ошибка при подключении к базе данных: "+glDM->TextError);
			}
		}
}
//---------------------------------------------------------------------------





//****************************************************************************
//-------------  ОБМЕН  ------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
void TMainForm::CreateDataOut(void)
{
glDM->UserName=UserName;
glDM->PasswordUser=PasswordUser;
glDM->ConnectString=ConnectString;

if (glDM->ConnectInfBase()==true)
	{
	SetOperationObmen(20);
	TDMUribOut * dm=new TDMUribOut(Application);
	dm->EventFirstRecord=EventFirstRecord;
	dm->EventNextRecord=EventNextRecord;
	lpKolRecord=dm->lpKolRecord;
	UpdateProgressBar=true;

	if (dm->CreateDataOutTable(IdBaseForObmen)==true)
		{
		glDM->glSaveProtocol("Данные подготовлены!");
		Memo1->Lines->Add(TimeToStr(Time())+"  Данные подготовлены!");
		}
	else
		{
		glDM->glSaveProtocol("Ошибка при подготовке данных: "+dm->TextError);
		Memo1->Lines->Add(TimeToStr(Time())+"Ошибка при подготовке данных: "+dm->TextError);
		}
	delete dm;
	}
else
	{
	glDM->glSaveProtocol("Ошибка при подключении к базе данных: "+glDM->TextError);
	Memo1->Lines->Add(TimeToStr(Time())+"Ошибка при подключении к базе данных: "+glDM->TextError);
	}

glDM->DisconnectInfBase();
}
//-----------------------------------------------------------------------------
void TMainForm::CreateXMLFile(bool povtor)
{
glDM->UserName=UserName;
glDM->PasswordUser=PasswordUser;
glDM->ConnectString=ConnectString;

if (glDM->ConnectInfBase()==true)
	{
	SetOperationObmen(30);
	TDMUribOut * dm=new TDMUribOut(Application);
	dm->EventFirstRecord=EventFirstRecord;
	dm->EventNextRecord=EventNextRecord;
	lpKolRecord=dm->lpKolRecord;
	UpdateProgressBar=true;

	if (FileExists(OutNameFileXml)==true)
		{
		DeleteFile(OutNameFileXml);
		}

	if (dm->CreateXMLDoc(IdBaseForObmen,povtor)==true)
		{
		glDM->glSaveProtocol("Файл сформирован!");
		Memo1->Lines->Add(TimeToStr(Time())+"  Файл сформирован!");
		}
	else
		{
		glDM->glSaveProtocol("Ошибка при формировании файла: "+dm->TextError);
		}
	delete dm;
	}
else
	{
	glDM->glSaveProtocol("Ошибка при подключении к базе данных: "+glDM->TextError);

	}

glDM->DisconnectInfBase();
}
//-----------------------------------------------------------------------------
bool TMainForm::ArhiveXMLFile(void)
{
bool result=false;
SetOperationObmen(40);
AnsiString program_catalog=ExtractFileDir(Application->ExeName);

Memo1->Lines->Add("Архивируем файл"+OutNameFileXml);
Memo1->Lines->Add("Файл архива"+OutNameFileArh);
glDM->glSaveProtocol("Архивируем файл"+OutNameFileXml);
glDM->glSaveProtocol("Файл архива"+OutNameFileArh);

// проверим если есть указанный файл то его удалим
if (FileExists(OutNameFileArh)==true)
        {
		DeleteFile(OutNameFileArh);
        }

AnsiString  ComandString=Trim(PatchArhivator)
				+" "+OutNameFileArh
				+" "+OutNameFileXml;

STARTUPINFO cif;
ZeroMemory(&cif,sizeof(STARTUPINFO));
PROCESS_INFORMATION pi;
if (CreateProcess(NULL,ComandString.c_str(),
						 NULL,NULL,FALSE,NULL,NULL,NULL,&cif,&pi)==TRUE)
        {
        WaitForSingleObject( pi.hProcess, INFINITE);
		}


// проверим если есть указанный файл
if (FileExists(OutNameFileArh)==true)
	{
	Memo1->Lines->Add("Архивирование  файла - ОК");
	glDM->glSaveProtocol("Архивирование  файла - ОК");
	result=true;
	}
else
	{
	Memo1->Lines->Add("Файл архива не создан");
	glDM->glSaveProtocol("Файл архива не создан");
	result=false;
	}
return result;
}

//-----------------------------------------------------------------------------
bool TMainForm::UnarhiveFile(void)
{
bool result=false;
SetOperationObmen(120);
AnsiString program_catalog=ExtractFileDir(Application->ExeName);

Memo1->Lines->Add("Файл архива"+InNameFileArh);
glDM->glSaveProtocol("Файл архива"+InNameFileArh);

if (FileExists(InNameFileXml)==true)
		{
		DeleteFile(InNameFileXml);
		}

AnsiString  ComandString="";
ComandString=Trim(PatchUnArh)+" "+InNameFileArh
						+" "+program_catalog+"\\Files\\";

glDM->glSaveProtocol(ComandString);

STARTUPINFO cif;
ZeroMemory(&cif,sizeof(STARTUPINFO));
PROCESS_INFORMATION pi;
if (CreateProcess(NULL,ComandString.c_str(),
						 NULL,NULL,FALSE,NULL,NULL,NULL,&cif,&pi)==TRUE)
		{
		WaitForSingleObject( pi.hProcess, INFINITE);
		}

// проверим если есть указанный файл
if (FileExists(InNameFileXml)==true)
	{
	Memo1->Lines->Add("Распаковка  файла - ОК");
	glDM->glSaveProtocol("Распаковка  файла - ОК");
	result=true;
	}
else
	{
	Memo1->Lines->Add("Файл архива не распакован");
	glDM->glSaveProtocol("Файл архива не распакован");
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------
void TMainForm::UpdateBase(void)
{
SetOperationObmen(130);
Memo1->Lines->Add(TimeToStr(Time())+"  Попытка загрузить изменения...");
glDM->glSaveProtocol("Попытка загрузить изменения...");

		glDM->UserName=UserName;
		glDM->PasswordUser=PasswordUser;
		glDM->ConnectString=ConnectString;

		if (glDM->ConnectInfBase()==true)
			{
			TDMUribIn *DMIn=new TDMUribIn(Application);
			DMIn->EventFirstRecord=EventFirstRecord;
			DMIn->EventNextRecord=EventNextRecord;
			lpKolRecord=DMIn->lpKolRecord;
			UpdateProgressBar=false;

			try
				{
				glDM->glSaveProtocol("Загружаем данные из файла:"+InNameFileXml);
				DMIn->UpdateDataInfBase(InNameFileXml);
				Memo1->Lines->Add(TimeToStr(Time())+"  Изменения загружены!");
				glDM->glSaveProtocol("Изменения загружены!");
				SetOperationObmen(140);

                if (AutoObmen==true)
					{ //запускаем таймер для нового обмена
					StartTimerIntervalObmena();
					}

				}
			catch (Exception &exception)
				{
				if (DMIn>0) glDM->glSaveProtocol("Ошибка загрузки! "+exception.Message+"\n Загружено записей: "+IntToStr(DMIn->kol_rec));
				}

			delete DMIn;
			glDM->DisconnectInfBase();
			}
		else
			{
			ShowMessage("Ошибка при подключении к базе данных: "+glDM->TextError);
			}
}
//---------------------------------------------------------------------------
void TMainForm::SetOperationObmen(int operation)
{
if (glDM->Database->Connected==true)
	{
	glDM->glSetOperation(IdBaseForObmen,operation);
	}
else
	{
	glDM->UserName=UserName;
	glDM->PasswordUser=PasswordUser;
	glDM->ConnectString=ConnectString;
	if (glDM->ConnectInfBase()==true)
		{
		glDM->glSetOperation(IdBaseForObmen,operation);
		}
	else
		{
		glDM->glSaveProtocol("Ошибка при подключении к базе данных: "+glDM->TextError);
		}
	glDM->DisconnectInfBase();
	}
}
//----------------------------------------------------------------------------
int TMainForm::GetOperationObmen(__int64 id_base_for_obmen)
{
int result=0;
if (glDM->Database->Connected==true)
	{
	result=glDM->glGetOperation(id_base_for_obmen);
	}
else
	{
	glDM->UserName=UserName;
	glDM->PasswordUser=PasswordUser;
	glDM->ConnectString=ConnectString;
	if (glDM->ConnectInfBase()==true)
		{
		result=glDM->glGetOperation(id_base_for_obmen);
		}
	else
		{
		glDM->glSaveProtocol("Ошибка при подключении к базе данных: "+glDM->TextError);
		}
	glDM->DisconnectInfBase();
	}
return result;
}
//----------------------------------------------------------------------------
void TMainForm::GetIdTecBase(void)
{
glDM->glSaveProtocol("Попытка получить ID текущей базы");
if (glDM->Database->Connected==true)
	{
	//база источник, текущая база
		glDM->Query->Close();
		glDM->Query->SQL->Clear();
		glDM->Query->SQL->Add(" select setup.value_setup from setup where setup.id_setup=3");
		glDM->Query->ExecQuery();
		IdTecBase=StrToInt64(glDM->Query->FieldByName("VALUE_SETUP")->AsString);
		glDM->Query->Close();
	}
else
	{
	glDM->UserName=UserName;
	glDM->PasswordUser=PasswordUser;
	glDM->ConnectString=ConnectString;
	if (glDM->ConnectInfBase()==true)
		{
		//база источник, текущая база
		glDM->Query->Close();
		glDM->Query->SQL->Clear();
		glDM->Query->SQL->Add(" select setup.value_setup from setup where setup.id_setup=3");
		glDM->Query->ExecQuery();
		IdTecBase=StrToInt64(glDM->Query->FieldByName("VALUE_SETUP")->AsString);
		glDM->Query->Close();
		}
	else
		{
		glDM->glSaveProtocol("Ошибка при подключении к базе данных: "+glDM->TextError);
		}
	glDM->DisconnectInfBase();
	}

glDM->glSaveProtocol("ID текущей базы = "+IntToStr(IdTecBase));
}
//----------------------------------------------------------------------------

void __fastcall TMainForm::TestConnectBaseMainMenuClick(TObject *Sender)
{
glDM->UserName=UserName;
glDM->PasswordUser=PasswordUser;
glDM->ConnectString=ConnectString;

if (glDM->ConnectInfBase()==true)
	{
	ShowMessage("Подключение к информационной базе ОК!");
	}
else
	{
	ShowMessage("Ошибка при подключении к базе данных: "+glDM->TextError);

	}

glDM->DisconnectInfBase();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EventNextRecord(TObject *Sender)
{
KolObrabRecord++;
TecKolRecordForProtocol++;
if (TecKolRecordForProtocol>=1000)
	{
	glDM->glSaveProtocol("Обработано записей:"+IntToStr(KolObrabRecord));
	TecKolRecordForProtocol=0;
	}

StatusBar1->Panels->Items[0]->Text="Клиент: обработано "+IntToStr(KolObrabRecord) +" записей ";
if(UpdateProgressBar==true)
	{
	ProgressBar1->StepIt();
	//ProgressBar1->Update();
	//ProgressBar1->Repaint();
	}


}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EventFirstRecord(TObject *Sender)
{
	ProgressBar1->Max=*lpKolRecord;
	ProgressBar1->Step=1;

KolObrabRecord=0;
TecKolRecordForProtocol=0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShowPopupMenuTrayIconClick(TObject *Sender)
{
  //  Восстановление формы.
  MainForm->Visible = true;
  TrayIcon1->Visible=false;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HideMainMenuClick(TObject *Sender)
{
TrayIcon1->Visible=true;
TrayIcon1->Hint=MainForm->Caption;
MainForm->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::TimerHideTimer(TObject *Sender)
{
TimerHide->Interval=0;
TimerHide->Enabled=false;
TrayIcon1->Visible=true;
TrayIcon1->Hint=MainForm->Caption;
MainForm->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{    //запускаем обмен
//сначала проверим есть ли связь с сервером

Timer1->Interval=0;
Timer1->Enabled=false;

if (FlagRunAutoObmen==true)
	{
	if (BaseList->Count > 0)
		{
		IdBaseForObmen=0;


		if (TecNumberBase == (BaseList->Count-1))
			{
			TecNumberBase=0;
			}
		else
			{
			TecNumberBase++;
			}

		UnicodeString catalog=ExtractFilePath(Application->ExeName);
		UnicodeString file_ini=catalog+GC_FileNameIni;

		TkanIniFile * ini=new TkanIniFile(file_ini);
		UnicodeString name_base=ini->ReadString(BaseList->Strings[TecNumberBase],GC_NameIniParameter_NameBaseForObmen,"");
		IdBaseForObmen=ini->ReadIntegerValue(BaseList->Strings[TecNumberBase],GC_NameIniParameter_IdBaseForObmen,0);
		delete ini;


		if (IdBaseForObmen !=0)
			{
			Memo1->Lines->Add(TimeToStr(Time())+" Обмен с базой: "+name_base);
			glDM->glSaveProtocol(" Обмен с базой: "+name_base);

			if (RunComandList(IdBaseForObmen)>0)
				{
				Memo1->Lines->Add(TimeToStr(Time())+" Выполнили загрузку команд. Начинаем выгрузку данных");
				CreateComandExchangeForBase(IdBaseForObmen);
		   		}
			}
		StartTimerIntervalObmena();
		}
	}

}
//---------------------------------------------------------------------------
void TMainForm::StartTimerIntervalObmena(void)
{
Timer1->Interval=GlobalInterval*1000;
Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void TMainForm::StartTimerIntervalObmenaAfterError(void)
{
Timer1->Interval=GlobalInterval*1000;
Timer1->Enabled=true;
}
//-----------------------------------------------------------------------------
///****************************************************************************
//*****************************************************************************
void TMainForm::ZagrusitIsmen(void)
{
//получить настройки обмена
GetIdTecBase();
GetParameterObmen();

if (IdTecBase!=0)
	{
	if (IdBaseForObmen!=0)
		{
		//скопировать в локальный каталог (Files) из каталога обмена файл обмена в зависимости от настроек
		InNameFileXml=LocCatalog+"\\DataFor"+IntToStr(IdTecBase)+".kas";
		if (CopyFileInLocCatalog()==true)
			{
			//обновить файлом
			UpdateBase();
			// надо удалить файл в каталоге обмена
			DeleteVhodFileInCatalogObmena();
			}
		}
	else
		{
		Memo1->Lines->Add(TimeToStr(Time())+" Не задано ID базы для обмена!");
		glDM->glSaveProtocol("Не задано ID базы для обмена!");
		}
	}
else
	{
	Memo1->Lines->Add(TimeToStr(Time())+" Не задано ID текущей базы!");
	glDM->glSaveProtocol("Не задано ID текущей базы!");
	}
}
//----------------------------------------------------------------------------
void TMainForm::VigrusitIsmen(void)
{
//получить настройки обмена
GetIdTecBase();
GetParameterObmen();

if (IdTecBase!=0)
	{
	if (IdBaseForObmen!=0)
		{
		OutNameFileXml=LocCatalog+"\\DataFor"+IntToStr(IdBaseForObmen)+".kas";
		//сформировать файл в локальном каталоге
		CreateDataOut();
		CreateXMLFile(false);

		//скопировать файл обмена из локального каталога (Files) в каталог обмена в зависимости от настроек
		CopyFileInCatalogObmena();
		}
	else
		{
		Memo1->Lines->Add(TimeToStr(Time())+" Не задано ID базы для обмена!");
		glDM->glSaveProtocol("Не задано ID базы для обмена!");
		}
	}
else
	{
	Memo1->Lines->Add(TimeToStr(Time())+" Не задано ID текущей базы!");
	glDM->glSaveProtocol("Не задано ID текущей базы!");
	}
}
//----------------------------------------------------------------------------
bool TMainForm::CopyFileInLocCatalog(void)
{
bool result=false;

	// проверим если есть указанный файл в локальном каталоге то его удалим
	if(FileExists(InNameFileXml)==true)
		{
		DeleteFile(InNameFileXml);
		}

if (TypeObmen==1)
	{ //через каталог обмена

	//копируем файл
	UnicodeString file_name=CatalogObmena+"DataFor"+IntToStr(IdTecBase)+".kas";

	if (CopyFileTo(file_name,InNameFileXml)==true)
		{
		result=true;
		}
	else
		{
		result=false;
		Memo1->Lines->Add(TimeToStr(Time())+" Ошибка копирования файла в локальный каталог!");
		glDM->glSaveProtocol("Ошибка копирования файла в локальный каталог!");
		}
	}

if (TypeObmen==2)
	{ // через FTP
	try
		{

		result=true;
		}
	catch (Exception &exception)
		{
		result=false;
		Memo1->Lines->Add(TimeToStr(Time())+"Ошибка копирования файла с FTP! "+exception.Message);
		glDM->glSaveProtocol("Ошибка копирования файла с FTP! "+exception.Message);
		}


	}

return result;
}
//----------------------------------------------------------------------------
bool TMainForm::CopyFileInCatalogObmena(void)
{
bool result=false;

if (TypeObmen==1)
	{ //через каталог обмена
	// проверим если есть указанный файл в каталоге обмена то его удалим
	UnicodeString file_name=CatalogObmena+"DataFor"+IntToStr(IdBaseForObmen)+".kas";
	if(FileExists(file_name)==true)
		{
		DeleteFile(file_name);
		}
	//копируем файл

	if (CopyFileTo(OutNameFileXml,file_name)==true)
		{
		result=true;
		}
	else
		{
		result=false;
		Memo1->Lines->Add(TimeToStr(Time())+" Ошибка копирования файла в каталог обмена!");
		glDM->glSaveProtocol("Ошибка копирования файла в каталог обмена!");
		}
	}

if (TypeObmen==2)
	{ // через FTP
	try
		{

		result=true;
		}
	catch (Exception &exception)
		{
		result=false;
		Memo1->Lines->Add(TimeToStr(Time())+"Ошибка копирования файла на FTP! "+exception.Message);
		glDM->glSaveProtocol("Ошибка копирования файла на FTP! "+exception.Message);
		}
	}

	
return result;
}
//----------------------------------------------------------------------------
bool TMainForm::DeleteVhodFileInCatalogObmena(void)
{
bool result=false;

if (TypeObmen==1)
	{ //через каталог обмена
	AnsiString file_name=CatalogObmena+"DataFor"+IntToStr(IdTecBase)+".kas";
	if(FileExists(file_name)==true)
		{
		if (DeleteFile(file_name)==true)
			{
			result=true;
			}
		else
			{
			Memo1->Lines->Add(TimeToStr(Time())+" Ошибка при удалении входящего файла в каталоге обмена!");
			glDM->glSaveProtocol("Ошибка при удалении входящего файла в каталоге обмена!");
			}
		}
	else
		{ //нет файла
		result=true;
		}
	}

if (TypeObmen==2)
	{ // через FTP
	try
		{

		result=true;
		}
	catch (Exception &exception)
		{
		result=false;
		Memo1->Lines->Add(TimeToStr(Time())+"Ошибка при удалении входящего файла на FTP! "+exception.Message);
		glDM->glSaveProtocol("Ошибка при удалении входящего файла на FTP! "+exception.Message);
		}
	}

return result;

}
//--------------------------------------------------------------------------
void __fastcall TMainForm::ToolButtonZagrusitFileClick(TObject *Sender)
{
if (RunComandList(IdBaseForObmen)>0)
	{
	CreateComandExchangeForBase(IdBaseForObmen);
	}
}
//---------------------------------------------------------------------------



///////////////////////////////////////////////////////////////////////////////
//новые функции обмена
//----------------------------------------------------------------------------
//загружаем данные
int TMainForm::RunComandList(__int64 id_base_for_obmen)
{
int result=0;
Memo1->Clear();
glDM->glSaveProtocol("Запущена процедура выполнения полученных команд");
GetIdTecBase();

TkanComandExchangeList * comand_list=new TkanComandExchangeList();

glDM->glSaveProtocol("ID текущей базы = "+IntToStr(IdTecBase));
glDM->glSaveProtocol("ID базы для обмена текущей базы = "+IntToStr(id_base_for_obmen));

TkanComandBuilder * cb=new TkanComandBuilder();
cb->LocalCatalog=ExtractFileDir(Application->ExeName);
cb->IdTecBase=IdTecBase;
cb->IdBaseForObmen=id_base_for_obmen;

glDM->glSaveProtocol("Получим список команд");

if (cb->GetListComand(comand_list)==false)
	{
	//ошибка: не удалось получить список команд
	glDM->glSaveProtocol("Не удалось получить список команд. Ошибка:"+cb->TextError);
	result=0;
	}
else
	{
	//проходим по списку команд
	Memo1->Lines->Add(TimeToStr(Time())+" Начинаем обработку списка команд! Необходимо выполнить команд: "
														+IntToStr(comand_list->List->Count));
	glDM->glSaveProtocol("Начинаем обработку команд! Необходимо выполнить команд: "
														+IntToStr(comand_list->List->Count));
	int kol_comand=0;
	if (comand_list->List->Count > 0)
		{
		result=1; //есть команды, успешное выполнение
		}


	for (int i=0; i<comand_list->List->Count;i++)
		{
		TkanComandExchange* tec_comand = comand_list->GetComand(i);

		//выполняем команду
		if (RunComand(tec_comand)==-1)
			{
			kol_comand++;
			//снимаем активность команды
			tec_comand->RunComand=false;
			//если команда выполнена успешно, то удаляем команду из источника
			//с помощю метода Delete, который удаляет команду из первоисточника
			if (cb->DeleteComandFromSource(tec_comand)==true)
				{
                glDM->glSaveProtocol("Команда из источника удалена");
				}
			else
				{//ошибка при удалении команды
				glDM->glSaveProtocol("Ошибка при удалении команды");

				}
			}
		else
			{//если хотя бы одна команда не выполнена
			//не будем отправлять изменения
			//будем загружать до полного успеха
			result=0;
			}

		}

	Memo1->Lines->Add(TimeToStr(Time())+" Выполнено команд: "+IntToStr(kol_comand));
	glDM->glSaveProtocol("Выполнено команд: "+IntToStr(kol_comand));
	}
delete cb;
delete comand_list;

Memo1->Lines->Add(TimeToStr(Time())+" Процедура выполнения команд обмена завершена ");
glDM->glSaveProtocol("Процедура выполнения команд обмена завершена ");
return result;
}
//-----------------------------------------------------------------------------
//выгружаем данные
int TMainForm::CreateComandExchangeForBase(__int64 id_base_for_obmen)
{
int result=0;
//получить настройки обмена
GetIdTecBase();

TkanComandExchange * comand_exchange=new TkanComandExchange();
comand_exchange->NewComand();
comand_exchange->IdTecBase=IdTecBase;
comand_exchange->IdBaseForObmen=id_base_for_obmen;
comand_exchange->LocalCatalog=ExtractFileDir(Application->ExeName);
comand_exchange->TypeComandExchange=comand_exchange->TypeComandExchange_CreateFile;
//создаем файл обмен, включаем его в команду и посылаем команду


if (IdTecBase!=0)
	{
	if (id_base_for_obmen!=0)
		{
		UnicodeString out_name_file_xml=LocCatalog+"\\DataFor"+IntToStr(id_base_for_obmen)+".kas";
		//сформировать файл в локальном каталоге
		glDM->UserName=UserName;
		glDM->PasswordUser=PasswordUser;
		glDM->ConnectString=ConnectString;

		if (glDM->ConnectInfBase()==true)
			{
			TDMUribOut * dm=new TDMUribOut(Application);
			dm->EventFirstRecord=EventFirstRecord;
			dm->EventNextRecord=EventNextRecord;
			lpKolRecord=dm->lpKolRecord;
			UpdateProgressBar=true;

			if (dm->CreateDataOutTable(id_base_for_obmen)==true)
				{
				glDM->glSaveProtocol("Данные подготовлены!");
				Memo1->Lines->Add(TimeToStr(Time())+"  Данные подготовлены!");
				//создаем xml файл

				if (FileExists(out_name_file_xml)==true)
					{
					DeleteFile(out_name_file_xml);
					}

				if (dm->CreateXMLDoc(id_base_for_obmen,false)==true)
					{
					glDM->glSaveProtocol("Файл сформирован!");
					Memo1->Lines->Add(TimeToStr(Time())+"  Файл сформирован!");

					comand_exchange->FileList_AddString(out_name_file_xml);
					//посылаем команду в первоисточник
					Memo1->Lines->Add(TimeToStr(Time())+" Посылаем команду в источник ");
					glDM->glSaveProtocol(" Посылаем команду в источник  ");
					TkanComandBuilder * cb=new TkanComandBuilder();
					cb->LocalCatalog=ExtractFileDir(Application->ExeName);
					cb->IdTecBase=IdTecBase;
					cb->IdBaseForObmen=id_base_for_obmen;

					if (cb->SendComandFromSource(comand_exchange)==true)
						{
						Memo1->Lines->Add(TimeToStr(Time())+" Команда отправлена в источник ");
						glDM->glSaveProtocol(" Команда отправлена в источник  ");
						}
					else
						{
						Memo1->Lines->Add(TimeToStr(Time())+" Ошибка при отправке команды в источник ");
						glDM->glSaveProtocol(" Ошибка при отправке команды в источник  ");
						}
					delete cb;
					}
				else
					{
					glDM->glSaveProtocol("Ошибка при формировании файла: "+dm->TextError);
					}
				}
			else
				{
				glDM->glSaveProtocol("Ошибка при подготовке данных: "+dm->TextError);
				Memo1->Lines->Add(TimeToStr(Time())+"Ошибка при подготовке данных: "+dm->TextError);
				}
			delete dm;
			}
		else
			{
			glDM->glSaveProtocol("Ошибка при подключении к базе данных: "+glDM->TextError);
			Memo1->Lines->Add(TimeToStr(Time())+"Ошибка при подключении к базе данных: "+glDM->TextError);
			}

		glDM->DisconnectInfBase();
		}
	else
		{
		Memo1->Lines->Add(TimeToStr(Time())+" Не задано ID базы для обмена!");
		glDM->glSaveProtocol("Не задано ID базы для обмена!");
		}
	}
else
	{
	Memo1->Lines->Add(TimeToStr(Time())+" Не задано ID текущей базы!");
	glDM->glSaveProtocol("Не задано ID текущей базы!");
	}
delete comand_exchange;


Memo1->Lines->Add(TimeToStr(Time())+" Процедура отправки команд обмена завершена ");
glDM->glSaveProtocol("Процедура отправки команд обмена завершена ");

return result;
}
//------------------------------------------------------------------------------

int TMainForm::RunComand(TkanComandExchange* comand)
{
int result=0;
//если команда Comand_UpdateBase то обновляем текущую базу
//полученным файлом, текущей командой
glDM->glSaveProtocol("Выполняем команду обновления базы");
glDM->glSaveProtocol("ID текущей базы = "+IntToStr(comand->IdTecBase));
glDM->glSaveProtocol("ID базы для обмена= "+IntToStr(comand->IdBaseForObmen));
if (comand->IdTecBase!=0)
	{
	if (comand->IdBaseForObmen!=0)
		{
		//скопировать в локальный каталог (Files) из команды
		// проверим если есть указанный файл в каталоге обмена то его удалим
		UnicodeString file_name=LocCatalog+"\\DataFor"+IntToStr(comand->IdTecBase)+".kas";
		if(FileExists(file_name)==true)
			{
			DeleteFile(file_name);
			}
		//копируем файл
		if (CopyFileTo(comand->FileList_GetString(0),file_name)==true)
			{
			result=true;
			}
		else
			{
			result=false;
			Memo1->Lines->Add(TimeToStr(Time())+" Ошибка копирования файла из команды в каталог обмена!");
			glDM->glSaveProtocol("Ошибка копирования файла из команды в каталог обмена!");
			}

			//обновить файлом
			Memo1->Lines->Add(TimeToStr(Time())+"  Попытка загрузить изменения...");
			glDM->glSaveProtocol("Попытка загрузить изменения...");

			glDM->UserName=UserName;
			glDM->PasswordUser=PasswordUser;
			glDM->ConnectString=ConnectString;

			if (glDM->ConnectInfBase()==true)
				{
				TDMUribIn *DMIn=new TDMUribIn(Application);
				DMIn->EventFirstRecord=EventFirstRecord;
				DMIn->EventNextRecord=EventNextRecord;
				lpKolRecord=DMIn->lpKolRecord;
				UpdateProgressBar=false;

				try
					{
					glDM->glSaveProtocol("Загружаем данные из файла:"+file_name);
					DMIn->UpdateDataInfBase(file_name);
					Memo1->Lines->Add(TimeToStr(Time())+"  Изменения загружены!");
					glDM->glSaveProtocol("Изменения загружены!");
					result=-1;
					}
				catch (Exception &exception)
					{
					if (DMIn>0) glDM->glSaveProtocol("Ошибка загрузки! "+exception.Message+"\n Загружено записей: "+IntToStr(DMIn->kol_rec));
					}

				delete DMIn;
				glDM->DisconnectInfBase();
				}
			else
				{
				glDM->glSaveProtocol("Ошибка при подключении к базе данных: "+glDM->TextError);
				Memo1->Lines->Add("Ошибка при подключении к базе данных: "+glDM->TextError);
				}
		}
	else
		{
		Memo1->Lines->Add(TimeToStr(Time())+" Не задано ID базы для обмена!");
		glDM->glSaveProtocol("Не задано ID базы для обмена!");
		}
	}
else
	{
	Memo1->Lines->Add(TimeToStr(Time())+" Не задано ID текущей базы!");
	glDM->glSaveProtocol("Не задано ID текущей базы!");
	}

return result;
}
//-----------------------------------------------------------------------------


void __fastcall TMainForm::ZagrusitMainMenuClick(TObject *Sender)
{
RunComandList(IdBaseForObmen);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::VigrusitMainMenuClick(TObject *Sender)
{
CreateComandExchangeForBase(IdBaseForObmen);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::RunObmenMainMenuClick(TObject *Sender)
{
if (RunComandList(IdBaseForObmen)>0)
	{
	CreateComandExchangeForBase(IdBaseForObmen);
	}
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::ToolButton5Click(TObject *Sender)
{
FlagRunAutoObmen=true;
Memo1->Lines->Add(TimeToStr(Time())+" Запускаем процедуру автообмена");

//заполняем список баз

UnicodeString catalog=ExtractFilePath(Application->ExeName);
UnicodeString file_ini=catalog+GC_FileNameIni;

TkanIniFile * ini=new TkanIniFile(file_ini);
BaseList=new TStringList();
ini->ReadSections(BaseList);
Memo1->Lines->Add(TimeToStr(Time())+" Получили список баз. В списке "+IntToStr(BaseList->Count));
delete ini;

TecNumberBase=0;

Memo1->Lines->Add(TimeToStr(Time())+" Запускаем таймер");
StartTimerIntervalObmena();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButton6Click(TObject *Sender)
{
FlagRunAutoObmen=false;
Memo1->Lines->Add(TimeToStr(Time())+" Останавливаем процедуру автообмена");
delete BaseList;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MAPI1CheckFullClick(TObject *Sender)
{
glDM->glSaveProtocol("Тест MAPI: MAPI_PEEK!");
TkanMAPI * mapi=new TkanMAPI();
mapi->Init();
//задаем настройки MAPI для получения сообщений
//как минимум адрес почты от кого приходят команды
//получаем список сообщений

TkanMapiMessageList * mes_list=new TkanMapiMessageList();
mapi->GetListMessage(mes_list,"test@test.ru", 3);
delete mapi;
delete mes_list;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MAPICheckTolkoZagolovkiClick(TObject *Sender)
{
glDM->glSaveProtocol("Тест MAPI: MAPI_PEEK | MAPI_ENVELOPE_ONLY!");
TkanMAPI * mapi=new TkanMAPI();
mapi->Init();
//задаем настройки MAPI для получения сообщений
//как минимум адрес почты от кого приходят команды
//получаем список сообщений

TkanMapiMessageList * mes_list=new TkanMapiMessageList();
mapi->GetListMessage(mes_list,"test@test.ru", 1);
delete mapi;
delete mes_list;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MAPICheckBesVlogClick(TObject *Sender)
{
glDM->glSaveProtocol("Тест MAPI: MAPI_PEEK | MAPI_SUPPRESS_ATTACH!");
TkanMAPI * mapi=new TkanMAPI();
mapi->Init();
//задаем настройки MAPI для получения сообщений
//как минимум адрес почты от кого приходят команды
//получаем список сообщений

TkanMapiMessageList * mes_list=new TkanMapiMessageList();
mapi->GetListMessage(mes_list,"test@test.ru", 2);
delete mapi;
delete mes_list;
}
//---------------------------------------------------------------------------

