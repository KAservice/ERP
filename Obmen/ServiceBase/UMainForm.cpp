//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMainForm.h"
#include "UDataModuleMain.h"
#include "UFormaTableXDataOut.h"
#include "UFormaTableIsm.h"
#include "UFormaAddDataInNewBase.h"
#include "UFormaCreateTriggerLog.h"
#include "UFormaXTableBase.h"
#include "UFormaSetNachValues.h"
#include "UFormaDocRegGoods.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
extern TDataModuleMain *glDM;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
//зададим каталог протоколов
AnsiString ProgramCatalog=ExtractFileDir(Application->ExeName);
if (DirectoryExists(ProgramCatalog+"\\Log")==false)
        {
        CreateDir(ProgramCatalog+"\\Log");
        }

//if (DirectoryExists(ProgramCatalog+"\\Log")==true)
//        {
//        CatalogProtocol=ProgramCatalog+"\\Log";
//		}
		
FormaViborBase=new TFormaViborBase(Application);
glDM=new TDataModuleMain(Application);
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

		if(glDM->Connect()==true)
                {
				Visible=true; 
				StatusBar->Panels->Items[0]->Text=FormaViborBase->NameUser;
				StatusBar->Panels->Items[2]->Text=glDM->ConnectString;
//				StatusBar->Panels->Items[1]->Text=gl_prefiks_ib;
//				StatusBar->Panels->Items[3]->Text=BaseVersion;
//				StatusBar->Panels->Items[4]->Text=ProgramVersion;
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
void __fastcall TMainForm::N6Click(TObject *Sender)
{
TFormaTableXDataOut * form=new TFormaTableXDataOut(Application);
form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OpenTableIsmMainMenuClick(TObject *Sender)
{
TFormaTableIsm * form=new TFormaTableIsm(Application);
form->Show();
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::ActionOpenFormCreateNewBaseExecute(TObject *Sender)
{
TFormaAddDataInNewBase * form=new TFormaAddDataInNewBase(Application);
form->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ActionOpenFormCreateLogExecute(TObject *Sender)
{
TFormaCreateTriggerLog * form=new TFormaCreateTriggerLog(Application);
form->UpdateForm();
form->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ActionOpenFormaXTableBaseExecute(TObject *Sender)
{
TFormaXTableBase * form=new TFormaXTableBase(Application);
form->UpdateForm();
form->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetGeneratorsMainMenuClick(TObject *Sender)
{
TFormaSetNachValues * form=new TFormaSetNachValues(Application);
form->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::GreateServDocClick(TObject *Sender)
{
TFormaDocRegGoods * form=new TFormaDocRegGoods(Application);
form->Show();
}
//---------------------------------------------------------------------------

