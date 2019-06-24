//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMainForm.h"
#include "UDataModuleMain.h"
#include "UFormaImportGrpNom.h"
#include "UFormaImportNom.h"
#include "UFormaImportEd.h"
#include "UFormaSetEdNom.h"
#include "UFormaImportTypePrice.h"
#include "UFormaImportPrice.h"
#include "UFormaImportGrpKlient.h"
#include "UFormaImportKlient.h"
#include "UFormaImportGrpKKT.h"
#include "UFormaImportKKT.h"
#include "UFormaImportOstTov.h"
#include "UFormaImportOstVs.h"
#include "UFormaImportGrpMainMenu.h"
#include "UFormaImportMainMenu.h"
#include "UFormaImportDiscountCard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
extern TDataModuleMain * glDM;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
glDM=new TDataModuleMain(Application);

FormaViborBase=new TFormaViborBase(Application);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
delete glDM;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
FormaViborBase->FOnCloseForm=EndViborBase;
FormaViborBase->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EndViborBase(TObject *Sender)
{

if (FormaViborBase->OutReady==true)
        {
		glDM->ConnectString=FormaViborBase->ConnectString;
		glDM->PasswordUser=FormaViborBase->PasswordUser;
		glDM->NameUser=FormaViborBase->NameUser;

		if(glDM->GlobConnect()==true)
                {
				Visible=true;
				FormaViborBase->CloseForm=true;
                }
        else
				{
				UnicodeString s="Ошибка при подключении к базе данных: "+glDM->TextError;
				Application->MessageBox(s.c_str(),
				L"Ошибка при подключении к базе данных!", MB_OK + MB_ICONEXCLAMATION);
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
void __fastcall TMainForm::OpenFormImportGrpNomClick(TObject *Sender)
{
TFormaImportGrpNom * f=new TFormaImportGrpNom(Application);

f->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OpenFormImportNomMainMenuClick(TObject *Sender)
{
TFormaImportNom * f=new TFormaImportNom(Application);

f->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OpenFormImportEdMainMenuClick(TObject *Sender)
{
TFormaImportEd * f=new TFormaImportEd(Application);

f->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OpenFormSetEdNomMainMenuClick(TObject *Sender)
{
TFormaSetEdNom * f=new TFormaSetEdNom(Application);

f->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N5Click(TObject *Sender)
{
TFormaImportTypePrice * f=new TFormaImportTypePrice(Application);

f->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N6Click(TObject *Sender)
{
TFormaImportPrice * f=new TFormaImportPrice(Application);

f->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N8Click(TObject *Sender)
{
TFormaImportGrpKlient * f=new TFormaImportGrpKlient(Application);

f->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N9Click(TObject *Sender)
{
TFormaImportKlient * f=new TFormaImportKlient(Application);

f->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N14Click(TObject *Sender)
{
TFormaImportGrpKKT * f=new TFormaImportGrpKKT(Application);

f->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N31Click(TObject *Sender)
{
TFormaImportKKT * f=new TFormaImportKKT(Application);

f->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N11Click(TObject *Sender)
{
TFormaImportOstTov * f=new TFormaImportOstTov(Application);

f->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N12Click(TObject *Sender)
{
TFormaImportOstVs * f=new TFormaImportOstVs(Application);

f->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N18Click(TObject *Sender)
{
TFormaImportGrpMainMenu * f=new TFormaImportGrpMainMenu(Application);

f->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N19Click(TObject *Sender)
{
TFormaImportMainMenu * f=new TFormaImportMainMenu(Application);

f->Show();
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::N15Click(TObject *Sender)
{
TFormaImportDiscountCard * f=new TFormaImportDiscountCard(Application);

f->Show();
}
//---------------------------------------------------------------------------

