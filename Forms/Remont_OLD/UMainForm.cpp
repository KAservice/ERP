//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//--------------------------------------------------------------------------
#include "UMainForm.h"
#include "UDM.h"
#include "UDMSprUser.h"
//ключ защиты
#include "grdapi.h"
#include "UAbout.h"
#include "UDMSetup.h"
#include "UDMQueryRead.h"
#include "UREM_FormaSpiskaSprNeispr.h"
#include "UREM_FormaSpiskaSprModel.h"
#include "UREM_FormaSpiskaSprTypeRem.h"
#include "UREM_FormaSpiskaSprSost.h"
#include "UREM_FormaGurZ.h"

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
extern TDM *DM;
extern TDMSprUser * glUser;
extern String gl_prefiks_ib;
extern bool gl_add_table_ism;
AnsiString BaseVersion;
AnsiString ProgramVersion;
int glRegNumber; //unsigned long
int glNumberARM;
extern bool glError;
extern bool glDemo;
extern AnsiString GetVersionProgramFile(void);
extern void AddLog(int id_user, int type, int object, int oper, AnsiString message);
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
ProgramVersion="2.2" ;
DM=new TDM(Application);

FormaViborBase=new TFormaViborBase(Application);
glDemo=false;
//AnsiString ProgramCatalog=ExtractFileDir(Application->ExeName);
//Application->HelpFile=ProgramCatalog+"\\PAdminHelp.chm";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
if(DM->pFIBData->Connected==true)
	{
	AddLog( glUser->ElementID_USER->AsInteger, 1, 0, 0, "Завершение работы Remont.exe");
	}
//if (glScaner) if(glScaner->ConnectScaner) glScaner->Disconnect();

delete DM;
//delete glUser;
GrdLogout(grd,0);
GrdCloseHandle(grd);
GrdCleanup();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
FormaViborBase->FOnCloseForm=EndViborBase;
FormaViborBase->ShowModal();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TMainForm::EndViborBase(TObject *Sender)
{

if (FormaViborBase->OutReady==true)
        {
        DM->ConnectString=FormaViborBase->ConnectString;
		DM->PasswordUser=FormaViborBase->PasswordUser;
		DM->NameUser=FormaViborBase->NameUser;

        if(DM->GlobConnect()==true)
                {
				if (glUser->FindPoName(FormaViborBase->NameUser)==1)
						{
						}
				else
						{
						ShowMessage("Не найден пользователь в справочнике пользователей! Необходимо завершить работу!");
						}
				AddLog( glUser->ElementID_USER->AsInteger, 1, 0, 0, "Запуск программы Remont.exe");
//						if (glUser->ElementPASSWORD_USER->AsString==FormaViborBase->PasswordUser)
//								{
//								if (glUser->ElementINTERF_USER->AsInteger>=10)
//										{
										Visible=true;
										glNumberARM=FormaViborBase->NumberARM;

                                        StatusBar->Panels->Items[0]->Text=FormaViborBase->NameUser;
                                        StatusBar->Panels->Items[2]->Text=DM->ConnectString;
                                        StatusBar->Panels->Items[1]->Text=gl_prefiks_ib;
                                        StatusBar->Panels->Items[3]->Text=BaseVersion;
                                        StatusBar->Panels->Items[4]->Text=ProgramVersion;
										FormaViborBase->CloseForm=true;
										CheckKey();
//                                        }
//								else
//										{
//										ShowMessage("Неправильное имя пользователя или пароль!");
//										FormaViborBase->CloseForm=false;
//										}

//                                }
//						 else
//								{
//								ShowMessage("Неправильное имя пользователя или пароль!");
//								FormaViborBase->CloseForm=false;
//								}
//						}
//				else
//						{
//					ShowMessage("Не найден пользователь в справочнике пользователей!");
//					FormaViborBase->CloseForm=false;
//						}
                }
        else
				{
				AnsiString s="Ошибка при подключении к базе данных: "+DM->TextError;
				Application->MessageBox(s.c_str(),
				"Ошибка при подключении к базе данных!", MB_OK + MB_ICONEXCLAMATION);
				FormaViborBase->CloseForm=false;
				}

		}
else
		{
		//закрываем программу
		Close();

		}
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::OpenFormAboutClick(TObject *Sender)
{
TFormAbout * form=new TFormAbout(Application);
if (!form) return;
//настройка формы
form->NameProgramLabel->Caption="Модуль \"Сервисный центр\" ";
form->VerProgLabel->Caption="Версия программы: "+ProgramVersion;

form->VerBaseLabel->Caption="Версия базы: "+BaseVersion;

form->GrPosledLabel->Visible=false;

if (glDemo==true)
	{
	form->DemoLabel->Visible=true;
	}
else
	{
	form->DemoLabel->Visible=false;
	}
//получим версию файла
form->VerFileLabel->Caption="Версия файла: "+GetVersionProgramFile();
//регистрационный номер
form->RegNumberLabel->Caption="Регистрационный номер: "+IntToStr(glRegNumber)
	+" ("+IntToHex(glRegNumber, 8)+")";

form->UpdateForm();
form->ShowModal();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TMainForm::CheckKey(void)
{
GrdStartup(GrdFMR_Local | GrdFMR_Remote );         //   && 

grd=GrdCreateHandle(0, GrdCHM_SingleThread, 0);
GrdSetAccessCodes(grd, 2103077223, 1365184227,2585575258, 5244555225);
GrdSetFindMode(grd,
			GrdFMR_Local | GrdFMR_Remote,        //локальный ключ   и сетвой ключ     GrdFMR_Local &&
			GrdFM_NProg,
			1,                   //номер программы
			0,
			0,
			0,
			0,
			0,
			GrdFMM_ALL,
			GrdFMI_ALL );

unsigned long  id_key=0;
GrdFind(grd,
			GrdF_First,
			&id_key,
			0);
GrdLogin(grd,
			0xFFFFFFFF,
			GrdLM_PerStation );

if (id_key==0) glDemo=true;
glRegNumber=id_key;
//GrdLogout(grd,0);
//GrdCloseHandle(grd);
//GrdCleanup();
}
//---------------------------------------------------------------------------
bool TMainForm::CheckEnableNew(void)
{
bool result=true;
if (glDemo==true)
	{ //проверим количество документов в базе данных
	TDMQueryRead *q=new TDMQueryRead(Application);
	q->pFIBQ->SQL->Clear();
	q->pFIBQ->SQL->Add(" select MAX(IDDOC) as MAXID from GALLDOC");
	q->pFIBQ->ExecQuery();
	if (q->pFIBQ->FieldByName("MAXID")->AsInteger>200)
		{
		result=false;
		}
	else
		{
		result=true;
		}
	delete q;
	}
return result;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::OpenSprNeisprClick(TObject *Sender)
{
TREM_FormaSpiskaSprNeispr * SprNeispr=new TREM_FormaSpiskaSprNeispr(Application);
if (!SprNeispr) return;
//настройка формы

SprNeispr->UpdateForm();
SprNeispr->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OpenSprModelClick(TObject *Sender)
{
TREM_FormaSpiskaSprModel * Spr=new TREM_FormaSpiskaSprModel(Application);
if (!Spr) return;
//настройка формы

Spr->UpdateForm();
Spr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OpenSprTRemontClick(TObject *Sender)
{
TREM_FormaSpiskaSprTypeRemont * Spr=new TREM_FormaSpiskaSprTypeRemont(Application);
if (!Spr) return;
//настройка формы

//Spr->UpdateForm();
Spr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OpenSprSostClick(TObject *Sender)
{
TREM_FormaSpiskaSprSost * Spr=new TREM_FormaSpiskaSprSost(Application);
if (!Spr) return;
//настройка формы

//Spr->UpdateForm();
Spr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OpenGurnalZClick(TObject *Sender)
{
TREM_FormaGurZ * GurZ=new TREM_FormaGurZ(Application);
if (!GurZ) return;
//настройка формы

GurZ->Show();
}
//---------------------------------------------------------------------------

