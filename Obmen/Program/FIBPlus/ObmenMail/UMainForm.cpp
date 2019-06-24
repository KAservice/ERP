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
IdBaseForObmencxLabel->Caption="ID: �� ������";


//������� ������� ����������
UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
if (DirectoryExists(ProgramCatalog+"\\Log")==false)
        {
        CreateDir(ProgramCatalog+"\\Log");
        }

if (DirectoryExists(ProgramCatalog+"\\Log")==true)
        {
        CatalogProtocol=ProgramCatalog+"\\Log";
        }

//�������� ������� � ������� ������
if (DirectoryExists(ProgramCatalog+"\\Files")==false)
		{
		CreateDir(ProgramCatalog+"\\Files");
		}

LocCatalog=ProgramCatalog+"\\Files";

//��������� ��������

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

Memo1->Lines->Add("������ ���������: "+glDM->GetVersionProgramFile());
glDM->glSaveProtocol("������ ���������:"+glDM->GetVersionProgramFile());
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
			Memo1->Lines->Add(TimeToStr(Time())+" ��������� ��������� ����������");

			//��������� ������ ���

			UnicodeString catalog=ExtractFilePath(Application->ExeName);
			UnicodeString file_ini=catalog+GC_FileNameIni;

			TkanIniFile * ini=new TkanIniFile(file_ini);
			BaseList=new TStringList();
			ini->ReadSections(BaseList);
			Memo1->Lines->Add(TimeToStr(Time())+" �������� ������ ���. � ������ "+IntToStr(BaseList->Count));
			delete ini;

			TecNumberBase=0;

			Memo1->Lines->Add(TimeToStr(Time())+" ��������� ������");
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
//��������� ������ ��� ��� ������

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

//��������� ���� ��� ������
NameBaseForObmen=ini->ReadString(IntToStr(IdBaseForObmen),GC_NameIniParameter_NameBaseForObmen,"");
if (ini->ReadString(IntToStr(IdBaseForObmen),GC_NameIniParameter_IdBaseForObmen,"")=="")
	{
	IdBaseForObmen=0;
	}
else
	{
	IdBaseForObmen=StrToInt64(ini->ReadString(IntToStr(IdBaseForObmen),"InfBaseForObmenIDBase",""));
	}

//��������� ����������� � ����
UserName="EXTUSER";//ini->ReadString("User","NameUser","");
PasswordUser=ini->ReadString(IntToStr(IdBaseForObmen),"UserPassword","");
ConnectString=ini->ReadString(IntToStr(IdBaseForObmen),"InfBaseConnectString","");

//�������������
PatchArhivator=ini->ReadString(IntToStr(IdBaseForObmen), "ArhivatorPatch", "");
PatchUnArh=ini->ReadString(IntToStr(IdBaseForObmen), "ArhivatorPatchUnArh", "");

//��������� ����������
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

//������ ������
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
NameBaseForObmenLabel->Caption="����� � �����: "+NameBaseForObmen;
StringConnectLabel->Caption="������� ����: "+ConnectString;
Caption="������ ������ ����� ��. ����� � ����� - "+NameBaseForObmen;

}
//----------------------------------------------------------------------------
//��������� ����������
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
		ShowMessage("������ ������������!");
		}
	else
		{
		ShowMessage("������ ��� ���������� ������: "+dm->TextError);
		}
	delete dm;
	}
else
	{
	ShowMessage("������ ��� ����������� � ���� ������: "+glDM->TextError);

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
		ShowMessage("���� �����������!");
		}
	else
		{
		ShowMessage("������ ��� ������������ �����: "+dm->TextError);
		}
	delete dm;
	}
else
	{
	ShowMessage("������ ��� ����������� � ���� ������: "+glDM->TextError);

	}

glDM->DisconnectInfBase();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ZagrIsmenMainMenuClick(TObject *Sender)
{

Memo1->Lines->Add(TimeToStr(Time())+"  ������� ��������� ���������...");
glDM->glSaveProtocol("������� ��������� ���������...");
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
				glDM->glSaveProtocol("��������� ������ �� �����:"+FileNameXML);
				DMIn->UpdateDataInfBase(FileNameXML);
				Memo1->Lines->Add(TimeToStr(Time())+"  ��������� ���������!");
				glDM->glSaveProtocol("��������� ���������!");
				}
			catch (Exception &exception)
				{
				if (DMIn>0) glDM->glSaveProtocol("������ ��������! "+exception.Message+"\n ��������� �������: "+IntToStr(DMIn->kol_rec));
				}

			delete DMIn;
			glDM->DisconnectInfBase();
			}
		else
			{
			ShowMessage("������ ��� ����������� � ���� ������: "+glDM->TextError);
			}
		}
}
//---------------------------------------------------------------------------





//****************************************************************************
//-------------  �����  ------------------------------------------------------
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
		glDM->glSaveProtocol("������ ������������!");
		Memo1->Lines->Add(TimeToStr(Time())+"  ������ ������������!");
		}
	else
		{
		glDM->glSaveProtocol("������ ��� ���������� ������: "+dm->TextError);
		Memo1->Lines->Add(TimeToStr(Time())+"������ ��� ���������� ������: "+dm->TextError);
		}
	delete dm;
	}
else
	{
	glDM->glSaveProtocol("������ ��� ����������� � ���� ������: "+glDM->TextError);
	Memo1->Lines->Add(TimeToStr(Time())+"������ ��� ����������� � ���� ������: "+glDM->TextError);
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
		glDM->glSaveProtocol("���� �����������!");
		Memo1->Lines->Add(TimeToStr(Time())+"  ���� �����������!");
		}
	else
		{
		glDM->glSaveProtocol("������ ��� ������������ �����: "+dm->TextError);
		}
	delete dm;
	}
else
	{
	glDM->glSaveProtocol("������ ��� ����������� � ���� ������: "+glDM->TextError);

	}

glDM->DisconnectInfBase();
}
//-----------------------------------------------------------------------------
bool TMainForm::ArhiveXMLFile(void)
{
bool result=false;
SetOperationObmen(40);
AnsiString program_catalog=ExtractFileDir(Application->ExeName);

Memo1->Lines->Add("���������� ����"+OutNameFileXml);
Memo1->Lines->Add("���� ������"+OutNameFileArh);
glDM->glSaveProtocol("���������� ����"+OutNameFileXml);
glDM->glSaveProtocol("���� ������"+OutNameFileArh);

// �������� ���� ���� ��������� ���� �� ��� ������
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


// �������� ���� ���� ��������� ����
if (FileExists(OutNameFileArh)==true)
	{
	Memo1->Lines->Add("�������������  ����� - ��");
	glDM->glSaveProtocol("�������������  ����� - ��");
	result=true;
	}
else
	{
	Memo1->Lines->Add("���� ������ �� ������");
	glDM->glSaveProtocol("���� ������ �� ������");
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

Memo1->Lines->Add("���� ������"+InNameFileArh);
glDM->glSaveProtocol("���� ������"+InNameFileArh);

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

// �������� ���� ���� ��������� ����
if (FileExists(InNameFileXml)==true)
	{
	Memo1->Lines->Add("����������  ����� - ��");
	glDM->glSaveProtocol("����������  ����� - ��");
	result=true;
	}
else
	{
	Memo1->Lines->Add("���� ������ �� ����������");
	glDM->glSaveProtocol("���� ������ �� ����������");
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------
void TMainForm::UpdateBase(void)
{
SetOperationObmen(130);
Memo1->Lines->Add(TimeToStr(Time())+"  ������� ��������� ���������...");
glDM->glSaveProtocol("������� ��������� ���������...");

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
				glDM->glSaveProtocol("��������� ������ �� �����:"+InNameFileXml);
				DMIn->UpdateDataInfBase(InNameFileXml);
				Memo1->Lines->Add(TimeToStr(Time())+"  ��������� ���������!");
				glDM->glSaveProtocol("��������� ���������!");
				SetOperationObmen(140);

                if (AutoObmen==true)
					{ //��������� ������ ��� ������ ������
					StartTimerIntervalObmena();
					}

				}
			catch (Exception &exception)
				{
				if (DMIn>0) glDM->glSaveProtocol("������ ��������! "+exception.Message+"\n ��������� �������: "+IntToStr(DMIn->kol_rec));
				}

			delete DMIn;
			glDM->DisconnectInfBase();
			}
		else
			{
			ShowMessage("������ ��� ����������� � ���� ������: "+glDM->TextError);
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
		glDM->glSaveProtocol("������ ��� ����������� � ���� ������: "+glDM->TextError);
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
		glDM->glSaveProtocol("������ ��� ����������� � ���� ������: "+glDM->TextError);
		}
	glDM->DisconnectInfBase();
	}
return result;
}
//----------------------------------------------------------------------------
void TMainForm::GetIdTecBase(void)
{
glDM->glSaveProtocol("������� �������� ID ������� ����");
if (glDM->Database->Connected==true)
	{
	//���� ��������, ������� ����
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
		//���� ��������, ������� ����
		glDM->Query->Close();
		glDM->Query->SQL->Clear();
		glDM->Query->SQL->Add(" select setup.value_setup from setup where setup.id_setup=3");
		glDM->Query->ExecQuery();
		IdTecBase=StrToInt64(glDM->Query->FieldByName("VALUE_SETUP")->AsString);
		glDM->Query->Close();
		}
	else
		{
		glDM->glSaveProtocol("������ ��� ����������� � ���� ������: "+glDM->TextError);
		}
	glDM->DisconnectInfBase();
	}

glDM->glSaveProtocol("ID ������� ���� = "+IntToStr(IdTecBase));
}
//----------------------------------------------------------------------------

void __fastcall TMainForm::TestConnectBaseMainMenuClick(TObject *Sender)
{
glDM->UserName=UserName;
glDM->PasswordUser=PasswordUser;
glDM->ConnectString=ConnectString;

if (glDM->ConnectInfBase()==true)
	{
	ShowMessage("����������� � �������������� ���� ��!");
	}
else
	{
	ShowMessage("������ ��� ����������� � ���� ������: "+glDM->TextError);

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
	glDM->glSaveProtocol("���������� �������:"+IntToStr(KolObrabRecord));
	TecKolRecordForProtocol=0;
	}

StatusBar1->Panels->Items[0]->Text="������: ���������� "+IntToStr(KolObrabRecord) +" ������� ";
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
  //  �������������� �����.
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
{    //��������� �����
//������� �������� ���� �� ����� � ��������

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
			Memo1->Lines->Add(TimeToStr(Time())+" ����� � �����: "+name_base);
			glDM->glSaveProtocol(" ����� � �����: "+name_base);

			if (RunComandList(IdBaseForObmen)>0)
				{
				Memo1->Lines->Add(TimeToStr(Time())+" ��������� �������� ������. �������� �������� ������");
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
//�������� ��������� ������
GetIdTecBase();
GetParameterObmen();

if (IdTecBase!=0)
	{
	if (IdBaseForObmen!=0)
		{
		//����������� � ��������� ������� (Files) �� �������� ������ ���� ������ � ����������� �� ��������
		InNameFileXml=LocCatalog+"\\DataFor"+IntToStr(IdTecBase)+".kas";
		if (CopyFileInLocCatalog()==true)
			{
			//�������� ������
			UpdateBase();
			// ���� ������� ���� � �������� ������
			DeleteVhodFileInCatalogObmena();
			}
		}
	else
		{
		Memo1->Lines->Add(TimeToStr(Time())+" �� ������ ID ���� ��� ������!");
		glDM->glSaveProtocol("�� ������ ID ���� ��� ������!");
		}
	}
else
	{
	Memo1->Lines->Add(TimeToStr(Time())+" �� ������ ID ������� ����!");
	glDM->glSaveProtocol("�� ������ ID ������� ����!");
	}
}
//----------------------------------------------------------------------------
void TMainForm::VigrusitIsmen(void)
{
//�������� ��������� ������
GetIdTecBase();
GetParameterObmen();

if (IdTecBase!=0)
	{
	if (IdBaseForObmen!=0)
		{
		OutNameFileXml=LocCatalog+"\\DataFor"+IntToStr(IdBaseForObmen)+".kas";
		//������������ ���� � ��������� ��������
		CreateDataOut();
		CreateXMLFile(false);

		//����������� ���� ������ �� ���������� �������� (Files) � ������� ������ � ����������� �� ��������
		CopyFileInCatalogObmena();
		}
	else
		{
		Memo1->Lines->Add(TimeToStr(Time())+" �� ������ ID ���� ��� ������!");
		glDM->glSaveProtocol("�� ������ ID ���� ��� ������!");
		}
	}
else
	{
	Memo1->Lines->Add(TimeToStr(Time())+" �� ������ ID ������� ����!");
	glDM->glSaveProtocol("�� ������ ID ������� ����!");
	}
}
//----------------------------------------------------------------------------
bool TMainForm::CopyFileInLocCatalog(void)
{
bool result=false;

	// �������� ���� ���� ��������� ���� � ��������� �������� �� ��� ������
	if(FileExists(InNameFileXml)==true)
		{
		DeleteFile(InNameFileXml);
		}

if (TypeObmen==1)
	{ //����� ������� ������

	//�������� ����
	UnicodeString file_name=CatalogObmena+"DataFor"+IntToStr(IdTecBase)+".kas";

	if (CopyFileTo(file_name,InNameFileXml)==true)
		{
		result=true;
		}
	else
		{
		result=false;
		Memo1->Lines->Add(TimeToStr(Time())+" ������ ����������� ����� � ��������� �������!");
		glDM->glSaveProtocol("������ ����������� ����� � ��������� �������!");
		}
	}

if (TypeObmen==2)
	{ // ����� FTP
	try
		{

		result=true;
		}
	catch (Exception &exception)
		{
		result=false;
		Memo1->Lines->Add(TimeToStr(Time())+"������ ����������� ����� � FTP! "+exception.Message);
		glDM->glSaveProtocol("������ ����������� ����� � FTP! "+exception.Message);
		}


	}

return result;
}
//----------------------------------------------------------------------------
bool TMainForm::CopyFileInCatalogObmena(void)
{
bool result=false;

if (TypeObmen==1)
	{ //����� ������� ������
	// �������� ���� ���� ��������� ���� � �������� ������ �� ��� ������
	UnicodeString file_name=CatalogObmena+"DataFor"+IntToStr(IdBaseForObmen)+".kas";
	if(FileExists(file_name)==true)
		{
		DeleteFile(file_name);
		}
	//�������� ����

	if (CopyFileTo(OutNameFileXml,file_name)==true)
		{
		result=true;
		}
	else
		{
		result=false;
		Memo1->Lines->Add(TimeToStr(Time())+" ������ ����������� ����� � ������� ������!");
		glDM->glSaveProtocol("������ ����������� ����� � ������� ������!");
		}
	}

if (TypeObmen==2)
	{ // ����� FTP
	try
		{

		result=true;
		}
	catch (Exception &exception)
		{
		result=false;
		Memo1->Lines->Add(TimeToStr(Time())+"������ ����������� ����� �� FTP! "+exception.Message);
		glDM->glSaveProtocol("������ ����������� ����� �� FTP! "+exception.Message);
		}
	}

	
return result;
}
//----------------------------------------------------------------------------
bool TMainForm::DeleteVhodFileInCatalogObmena(void)
{
bool result=false;

if (TypeObmen==1)
	{ //����� ������� ������
	AnsiString file_name=CatalogObmena+"DataFor"+IntToStr(IdTecBase)+".kas";
	if(FileExists(file_name)==true)
		{
		if (DeleteFile(file_name)==true)
			{
			result=true;
			}
		else
			{
			Memo1->Lines->Add(TimeToStr(Time())+" ������ ��� �������� ��������� ����� � �������� ������!");
			glDM->glSaveProtocol("������ ��� �������� ��������� ����� � �������� ������!");
			}
		}
	else
		{ //��� �����
		result=true;
		}
	}

if (TypeObmen==2)
	{ // ����� FTP
	try
		{

		result=true;
		}
	catch (Exception &exception)
		{
		result=false;
		Memo1->Lines->Add(TimeToStr(Time())+"������ ��� �������� ��������� ����� �� FTP! "+exception.Message);
		glDM->glSaveProtocol("������ ��� �������� ��������� ����� �� FTP! "+exception.Message);
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
//����� ������� ������
//----------------------------------------------------------------------------
//��������� ������
int TMainForm::RunComandList(__int64 id_base_for_obmen)
{
int result=0;
Memo1->Clear();
glDM->glSaveProtocol("�������� ��������� ���������� ���������� ������");
GetIdTecBase();

TkanComandExchangeList * comand_list=new TkanComandExchangeList();

glDM->glSaveProtocol("ID ������� ���� = "+IntToStr(IdTecBase));
glDM->glSaveProtocol("ID ���� ��� ������ ������� ���� = "+IntToStr(id_base_for_obmen));

TkanComandBuilder * cb=new TkanComandBuilder();
cb->LocalCatalog=ExtractFileDir(Application->ExeName);
cb->IdTecBase=IdTecBase;
cb->IdBaseForObmen=id_base_for_obmen;

glDM->glSaveProtocol("������� ������ ������");

if (cb->GetListComand(comand_list)==false)
	{
	//������: �� ������� �������� ������ ������
	glDM->glSaveProtocol("�� ������� �������� ������ ������. ������:"+cb->TextError);
	result=0;
	}
else
	{
	//�������� �� ������ ������
	Memo1->Lines->Add(TimeToStr(Time())+" �������� ��������� ������ ������! ���������� ��������� ������: "
														+IntToStr(comand_list->List->Count));
	glDM->glSaveProtocol("�������� ��������� ������! ���������� ��������� ������: "
														+IntToStr(comand_list->List->Count));
	int kol_comand=0;
	if (comand_list->List->Count > 0)
		{
		result=1; //���� �������, �������� ����������
		}


	for (int i=0; i<comand_list->List->Count;i++)
		{
		TkanComandExchange* tec_comand = comand_list->GetComand(i);

		//��������� �������
		if (RunComand(tec_comand)==-1)
			{
			kol_comand++;
			//������� ���������� �������
			tec_comand->RunComand=false;
			//���� ������� ��������� �������, �� ������� ������� �� ���������
			//� ������ ������ Delete, ������� ������� ������� �� ��������������
			if (cb->DeleteComandFromSource(tec_comand)==true)
				{
                glDM->glSaveProtocol("������� �� ��������� �������");
				}
			else
				{//������ ��� �������� �������
				glDM->glSaveProtocol("������ ��� �������� �������");

				}
			}
		else
			{//���� ���� �� ���� ������� �� ���������
			//�� ����� ���������� ���������
			//����� ��������� �� ������� ������
			result=0;
			}

		}

	Memo1->Lines->Add(TimeToStr(Time())+" ��������� ������: "+IntToStr(kol_comand));
	glDM->glSaveProtocol("��������� ������: "+IntToStr(kol_comand));
	}
delete cb;
delete comand_list;

Memo1->Lines->Add(TimeToStr(Time())+" ��������� ���������� ������ ������ ��������� ");
glDM->glSaveProtocol("��������� ���������� ������ ������ ��������� ");
return result;
}
//-----------------------------------------------------------------------------
//��������� ������
int TMainForm::CreateComandExchangeForBase(__int64 id_base_for_obmen)
{
int result=0;
//�������� ��������� ������
GetIdTecBase();

TkanComandExchange * comand_exchange=new TkanComandExchange();
comand_exchange->NewComand();
comand_exchange->IdTecBase=IdTecBase;
comand_exchange->IdBaseForObmen=id_base_for_obmen;
comand_exchange->LocalCatalog=ExtractFileDir(Application->ExeName);
comand_exchange->TypeComandExchange=comand_exchange->TypeComandExchange_CreateFile;
//������� ���� �����, �������� ��� � ������� � �������� �������


if (IdTecBase!=0)
	{
	if (id_base_for_obmen!=0)
		{
		UnicodeString out_name_file_xml=LocCatalog+"\\DataFor"+IntToStr(id_base_for_obmen)+".kas";
		//������������ ���� � ��������� ��������
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
				glDM->glSaveProtocol("������ ������������!");
				Memo1->Lines->Add(TimeToStr(Time())+"  ������ ������������!");
				//������� xml ����

				if (FileExists(out_name_file_xml)==true)
					{
					DeleteFile(out_name_file_xml);
					}

				if (dm->CreateXMLDoc(id_base_for_obmen,false)==true)
					{
					glDM->glSaveProtocol("���� �����������!");
					Memo1->Lines->Add(TimeToStr(Time())+"  ���� �����������!");

					comand_exchange->FileList_AddString(out_name_file_xml);
					//�������� ������� � �������������
					Memo1->Lines->Add(TimeToStr(Time())+" �������� ������� � �������� ");
					glDM->glSaveProtocol(" �������� ������� � ��������  ");
					TkanComandBuilder * cb=new TkanComandBuilder();
					cb->LocalCatalog=ExtractFileDir(Application->ExeName);
					cb->IdTecBase=IdTecBase;
					cb->IdBaseForObmen=id_base_for_obmen;

					if (cb->SendComandFromSource(comand_exchange)==true)
						{
						Memo1->Lines->Add(TimeToStr(Time())+" ������� ���������� � �������� ");
						glDM->glSaveProtocol(" ������� ���������� � ��������  ");
						}
					else
						{
						Memo1->Lines->Add(TimeToStr(Time())+" ������ ��� �������� ������� � �������� ");
						glDM->glSaveProtocol(" ������ ��� �������� ������� � ��������  ");
						}
					delete cb;
					}
				else
					{
					glDM->glSaveProtocol("������ ��� ������������ �����: "+dm->TextError);
					}
				}
			else
				{
				glDM->glSaveProtocol("������ ��� ���������� ������: "+dm->TextError);
				Memo1->Lines->Add(TimeToStr(Time())+"������ ��� ���������� ������: "+dm->TextError);
				}
			delete dm;
			}
		else
			{
			glDM->glSaveProtocol("������ ��� ����������� � ���� ������: "+glDM->TextError);
			Memo1->Lines->Add(TimeToStr(Time())+"������ ��� ����������� � ���� ������: "+glDM->TextError);
			}

		glDM->DisconnectInfBase();
		}
	else
		{
		Memo1->Lines->Add(TimeToStr(Time())+" �� ������ ID ���� ��� ������!");
		glDM->glSaveProtocol("�� ������ ID ���� ��� ������!");
		}
	}
else
	{
	Memo1->Lines->Add(TimeToStr(Time())+" �� ������ ID ������� ����!");
	glDM->glSaveProtocol("�� ������ ID ������� ����!");
	}
delete comand_exchange;


Memo1->Lines->Add(TimeToStr(Time())+" ��������� �������� ������ ������ ��������� ");
glDM->glSaveProtocol("��������� �������� ������ ������ ��������� ");

return result;
}
//------------------------------------------------------------------------------

int TMainForm::RunComand(TkanComandExchange* comand)
{
int result=0;
//���� ������� Comand_UpdateBase �� ��������� ������� ����
//���������� ������, ������� ��������
glDM->glSaveProtocol("��������� ������� ���������� ����");
glDM->glSaveProtocol("ID ������� ���� = "+IntToStr(comand->IdTecBase));
glDM->glSaveProtocol("ID ���� ��� ������= "+IntToStr(comand->IdBaseForObmen));
if (comand->IdTecBase!=0)
	{
	if (comand->IdBaseForObmen!=0)
		{
		//����������� � ��������� ������� (Files) �� �������
		// �������� ���� ���� ��������� ���� � �������� ������ �� ��� ������
		UnicodeString file_name=LocCatalog+"\\DataFor"+IntToStr(comand->IdTecBase)+".kas";
		if(FileExists(file_name)==true)
			{
			DeleteFile(file_name);
			}
		//�������� ����
		if (CopyFileTo(comand->FileList_GetString(0),file_name)==true)
			{
			result=true;
			}
		else
			{
			result=false;
			Memo1->Lines->Add(TimeToStr(Time())+" ������ ����������� ����� �� ������� � ������� ������!");
			glDM->glSaveProtocol("������ ����������� ����� �� ������� � ������� ������!");
			}

			//�������� ������
			Memo1->Lines->Add(TimeToStr(Time())+"  ������� ��������� ���������...");
			glDM->glSaveProtocol("������� ��������� ���������...");

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
					glDM->glSaveProtocol("��������� ������ �� �����:"+file_name);
					DMIn->UpdateDataInfBase(file_name);
					Memo1->Lines->Add(TimeToStr(Time())+"  ��������� ���������!");
					glDM->glSaveProtocol("��������� ���������!");
					result=-1;
					}
				catch (Exception &exception)
					{
					if (DMIn>0) glDM->glSaveProtocol("������ ��������! "+exception.Message+"\n ��������� �������: "+IntToStr(DMIn->kol_rec));
					}

				delete DMIn;
				glDM->DisconnectInfBase();
				}
			else
				{
				glDM->glSaveProtocol("������ ��� ����������� � ���� ������: "+glDM->TextError);
				Memo1->Lines->Add("������ ��� ����������� � ���� ������: "+glDM->TextError);
				}
		}
	else
		{
		Memo1->Lines->Add(TimeToStr(Time())+" �� ������ ID ���� ��� ������!");
		glDM->glSaveProtocol("�� ������ ID ���� ��� ������!");
		}
	}
else
	{
	Memo1->Lines->Add(TimeToStr(Time())+" �� ������ ID ������� ����!");
	glDM->glSaveProtocol("�� ������ ID ������� ����!");
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
Memo1->Lines->Add(TimeToStr(Time())+" ��������� ��������� ����������");

//��������� ������ ���

UnicodeString catalog=ExtractFilePath(Application->ExeName);
UnicodeString file_ini=catalog+GC_FileNameIni;

TkanIniFile * ini=new TkanIniFile(file_ini);
BaseList=new TStringList();
ini->ReadSections(BaseList);
Memo1->Lines->Add(TimeToStr(Time())+" �������� ������ ���. � ������ "+IntToStr(BaseList->Count));
delete ini;

TecNumberBase=0;

Memo1->Lines->Add(TimeToStr(Time())+" ��������� ������");
StartTimerIntervalObmena();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButton6Click(TObject *Sender)
{
FlagRunAutoObmen=false;
Memo1->Lines->Add(TimeToStr(Time())+" ������������� ��������� ����������");
delete BaseList;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MAPI1CheckFullClick(TObject *Sender)
{
glDM->glSaveProtocol("���� MAPI: MAPI_PEEK!");
TkanMAPI * mapi=new TkanMAPI();
mapi->Init();
//������ ��������� MAPI ��� ��������� ���������
//��� ������� ����� ����� �� ���� �������� �������
//�������� ������ ���������

TkanMapiMessageList * mes_list=new TkanMapiMessageList();
mapi->GetListMessage(mes_list,"test@test.ru", 3);
delete mapi;
delete mes_list;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MAPICheckTolkoZagolovkiClick(TObject *Sender)
{
glDM->glSaveProtocol("���� MAPI: MAPI_PEEK | MAPI_ENVELOPE_ONLY!");
TkanMAPI * mapi=new TkanMAPI();
mapi->Init();
//������ ��������� MAPI ��� ��������� ���������
//��� ������� ����� ����� �� ���� �������� �������
//�������� ������ ���������

TkanMapiMessageList * mes_list=new TkanMapiMessageList();
mapi->GetListMessage(mes_list,"test@test.ru", 1);
delete mapi;
delete mes_list;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MAPICheckBesVlogClick(TObject *Sender)
{
glDM->glSaveProtocol("���� MAPI: MAPI_PEEK | MAPI_SUPPRESS_ATTACH!");
TkanMAPI * mapi=new TkanMAPI();
mapi->Init();
//������ ��������� MAPI ��� ��������� ���������
//��� ������� ����� ����� �� ���� �������� �������
//�������� ������ ���������

TkanMapiMessageList * mes_list=new TkanMapiMessageList();
mapi->GetListMessage(mes_list,"test@test.ru", 2);
delete mapi;
delete mes_list;
}
//---------------------------------------------------------------------------

