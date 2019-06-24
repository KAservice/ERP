//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UViborBase.h"
#include "UChanche.h"
#include "UDM.h"
#include "UF1.h"
#include "UDMSprUser.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TViborBase *ViborBase;
extern TDM *DM;
extern TDMSprUser *glUser;
//---------------------------------------------------------------------------
__fastcall TViborBase::TViborBase(TComponent* Owner)
        : TForm(Owner)
{
List= new TStringList;
}
//---------------------------------------------------------------------------
void __fastcall TViborBase::FormCreate(TObject *Sender)
{
ListBox1->Clear();
UpdateSpisok();
}
//---------------------------------------------------------------------------
void __fastcall TViborBase::ButtonCancelClick(TObject *Sender)
{
//Application->Terminate();
F1->CloseProgram=true;
F1->Close();

}
//---------------------------------------------------------------------------
void __fastcall TViborBase::ButtonAddClick(TObject *Sender)
{
Application->CreateForm(__classid(TFChanche), &FChanche);
}
//---------------------------------------------------------------------------
void __fastcall TViborBase::ButtonOKClick(TObject *Sender)
{
ZapuskProgramm();
}
//---------------------------------------------------------------------------
void __fastcall TViborBase::ButtonRenameClick(TObject *Sender)
{
if(ListBox1->ItemIndex<0)
        {

        }
else
        {
        Application->CreateForm(__classid(TFChanche), &FChanche);
        FChanche->NameBase->Text=ListBox1->Items->Strings[ListBox1->ItemIndex];
        FChanche->FileName->Text=FindFileName(ListBox1->Items->Strings[ListBox1->ItemIndex]);
        FChanche->OldName=ListBox1->Items->Strings[ListBox1->ItemIndex];
        }
}
//---------------------------------------------------------------------------
void TViborBase::UpdateSpisok()
{
ListBox1->Clear();
try
        {
        List->LoadFromFile("SpBase.txt");
        for(int i=10;i<List->Count;i++)
                {
                 ListBox1->Items->Add(List->Strings[i]);
                 i++;
                }
        }
catch (...)
        {


        }


}
///------------------------------------------------------

String TViborBase::FindFileName(String NameBase)
{
String Res="";
for(int i=10;i<List->Count;i++)
        {
        if(ListBox1->Items->Strings[ListBox1->ItemIndex]
                ==List->Strings[i])
                {
                Res=List->Strings[i+1];

                }
        }

return Res;
}
void __fastcall TViborBase::ListBox1Click(TObject *Sender)
{
if(ListBox1->ItemIndex<0)
        {

        }
else
        {

        LabelFileName->Caption=FindFileName(ListBox1->Items->Strings[ListBox1->ItemIndex]);

        }
}
//---------------------------------------------------------------------------

void __fastcall TViborBase::ButtonDelClick(TObject *Sender)
{
for(int i=10;i<List->Count;i++)
        {
        if(ListBox1->Items->Strings[ListBox1->ItemIndex]
                ==List->Strings[i])
                {
                List->Delete(i);
                List->Delete(i+1);

                }
        }
List->SaveToFile("SpBase.txt");
UpdateSpisok();
}
//---------------------------------------------------------------------------

void __fastcall TViborBase::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;        
}
//---------------------------------------------------------------------------

void __fastcall TViborBase::PasswordKeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN) ZapuskProgramm();
}
//---------------------------------------------------------------------------
void TViborBase::ZapuskProgramm(void)
{
if(ListBox1->ItemIndex<0)
        {

        }
else
        {
        DM->ConnectString=FindFileName(ListBox1->Items->Strings[ListBox1->ItemIndex]);
        DM->PasswordUser="masterkey";  //Password->Text;
        DM->NameUser="SYSDBA";  //;

        if(DM->GlobConnect()==true)
                {
                if (glUser->FindPoName(User->Text)==1)
                        {
                        if (glUser->ElementPASSWORD_USER->AsString==Password->Text)
                                {
                                if (glUser->ElementINTERF_USER->AsInteger>=10)
                                        {
                                        F1->Visible=true;
                                        F1->StatusBar->Panels->Items[0]->Text=User->Text;
                                        F1->StatusBar->Panels->Items[2]->Text=DM->ConnectString;
                                        Close();
                                        }
                                else
                                        {
                                        ShowMessage("Ќеправильное им€ пользовател€ или пароль!");
                                        }

                                }
                         else
                                {
                                ShowMessage("Ќеправильное им€ пользовател€ или пароль!");
                                }
                        }
                else
                        {
                        ShowMessage("Ќеправильное им€ пользовател€ или пароль!");
                        }
                }
        else
                {
                 ShowMessage("Ќеправильно задан путь к базе данных!");
                }
        }


}
//-----------------------------------------------------------------------------
void __fastcall TViborBase::UserKeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN) Password->SetFocus();
}
//---------------------------------------------------------------------------

