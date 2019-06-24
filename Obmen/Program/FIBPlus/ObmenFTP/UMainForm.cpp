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
#pragma resource "*.dfm"
TMainForm *MainForm;
extern TDM * glDM;
extern UnicodeString GetVersionProgramFile(void);
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
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

GetParameterObmen();
UpdateForm();

glDM=new TDM(Application);

Memo1->Lines->Add("������ ���������: "+glDM->GetVersionProgramFile());
glDM->glSaveProtocol("������ ���������:"+glDM->GetVersionProgramFile());
UpdateProgressBar=true;


if (AutoObmen==true)
		{ //��������� ������
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
void TMainForm::GetParameterObmen(void)
{
UnicodeString file_ini=Application->ExeName;
file_ini=file_ini.SetLength(file_ini.Length()-4)+".ini";
TkanIniFile * ini=new TkanIniFile(file_ini);

//��������� ���� ��� ������
NameBaseForObmen=ini->ReadString("InfBaseForObmen","NameBase","");
if (ini->ReadString("InfBaseForObmen","IDBase","")=="")
	{
	IdBaseForObmen=0;
	}
else
	{
	IdBaseForObmen=StrToInt64(ini->ReadString("InfBaseForObmen","IDBase",""));
	}

//��������� ����������� � ����
UserName="EXTUSER";//ini->ReadString("User","NameUser","");
PasswordUser=ini->ReadString("User","Password","");
ConnectString=ini->ReadString("InfBase","ConnectString","");

//�������������
PatchArhivator=ini->ReadString("Arhivator", "Patch", "");
PatchUnArh=ini->ReadString("Arhivator", "PatchUnArh", "");

//��������� ����������
if (ini->ReadString("AutoObmen", "Run","")=="1")
		{
		AutoObmen=true;
		}
else
		{
		AutoObmen=false;
		}

if (ini->ReadString("AutoObmen", "Interval","").Length()!=0)
	{
	Interval=StrToInt(ini->ReadString("AutoObmen", "Interval","0"));
	}

if (ini->ReadString("AutoObmen", "IntervalAfterError","").Length()!=0)
	{
	Interval=StrToInt(ini->ReadString("AutoObmen", "IntervalAfterError","0"));
	}

//������ ������
if (ini->ReadString("TypeObmen", "Value","").Length()!=0)
	{
	TypeObmen=StrToInt(ini->ReadString("TypeObmen", "Value","0"));
	}
CatalogObmena=ini->ReadString("CatalogObmena","Patch", "");

FTPHost=ini->ReadString("FTP", "Host", "");
FTPPatch=ini->ReadString("FTP", "Catalog", "");
FTPUser=ini->ReadString("FTP", "User", "");
FTPPassword=ini->ReadString("FTP", "Password", "");
delete ini;






}
//---------------------------------------------------------------------------
void TMainForm::UpdateForm(void)
{

StringConnectLabel->Caption="������� ����: "+ConnectString;



NameBaseForObmenLabel->Caption="���� ��� ������: "+NameBaseForObmen;

MainForm->Caption="������ ������: "+NameBaseForObmen;


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
	FormaSetupObmen->Show();
	}
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::CloseFormSetupObmen(TObject *Sender)
{
GetParameterObmen();
FormaSetupObmen=0;
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


}
//---------------------------------------------------------------------------
void TMainForm::StartTimerIntervalObmena(void)
{
Timer1->Interval=Interval*6000;
Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void TMainForm::StartTimerIntervalObmenaAfterError(void)
{
Timer1->Interval=Interval*6000;
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
		InNameFileXml=LocCatalog+"\\DataFor"+IntToStr(IdTecBase)+".xml";
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
		OutNameFileXml=LocCatalog+"\\DataFor"+IntToStr(IdBaseForObmen)+".xml";
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
	UnicodeString file_name=CatalogObmena+"DataFor"+IntToStr(IdTecBase)+".xml";

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
		IdFTP1->Host = FTPHost;
		IdFTP1->Username = FTPUser;
		IdFTP1->Password = FTPPassword;
		IdFTP1->Connect();


		IdFTP1->Get(FTPPatch+"//DataFor"+IntToStr(IdTecBase)+".xml",InNameFileXml,true);
		IdFTP1->Disconnect();
		result=true;
		}
	catch (Exception &exception)
		{
		result=false;
		IdFTP1->Disconnect();
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
	UnicodeString file_name=CatalogObmena+"DataFor"+IntToStr(IdBaseForObmen)+".xml";
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
		IdFTP1->Host = FTPHost;
		IdFTP1->Username = FTPUser;
		IdFTP1->Password = FTPPassword;
		IdFTP1->Connect();
		//���� ��������� ����� ��� ���� ����
		//���� ���� �������

		IdFTP1->Put(OutNameFileXml,FTPPatch+"//DataFor"+IntToStr(IdBaseForObmen)+".xml",false);
		IdFTP1->Disconnect();
		result=true;
		}
	catch (Exception &exception)
		{
		result=false;
		IdFTP1->Disconnect();
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
	AnsiString file_name=CatalogObmena+"DataFor"+IntToStr(IdTecBase)+".xml";
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
		IdFTP1->Host = FTPHost;
		IdFTP1->Username = FTPUser;
		IdFTP1->Password = FTPPassword;
		IdFTP1->Connect();
		 //����� ��������� ���������
		 //����� ��� ���

		 
		IdFTP1->Delete(FTPPatch+"//DataFor"+IntToStr(IdTecBase)+".xml");
		IdFTP1->Disconnect();
		result=true;
		}
	catch (Exception &exception)
		{
		IdFTP1->Disconnect();
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
ZagrusitIsmen();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButtonCreateFileClick(TObject *Sender)
{
VigrusitIsmen();
}
//---------------------------------------------------------------------------

