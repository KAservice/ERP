//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UZapusk.h"
#include "UChanche.h"
#include "UF.h"
#include "UDM.h"
#include "UCS.h"
#include "UDMSprKKM.h"
#include "UDMSprUser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFZapusk *FZapusk;
extern TDM *DM;
extern TDMSprKKM *KKM;
extern TCS *CS;
extern bool zapusk; 
void glSaveProtocol(String str);
extern TDMSprUser * glUser;
//---------------------------------------------------------------------------
__fastcall TFZapusk::TFZapusk(TComponent* Owner)
        : TForm(Owner)
{
List= new TStringList;
}
//---------------------------------------------------------------------------
void __fastcall TFZapusk::FormCreate(TObject *Sender)
{
ListBox1->Clear();
UpdateSpisok();
}
//---------------------------------------------------------------------------
void __fastcall TFZapusk::ButtonCancelClick(TObject *Sender)
{
Application->Terminate();

}
//---------------------------------------------------------------------------
void __fastcall TFZapusk::ButtonAddClick(TObject *Sender)
{
Application->CreateForm(__classid(TFChanche), &FChanche);
}
//---------------------------------------------------------------------------
void __fastcall TFZapusk::ButtonOKClick(TObject *Sender)
{
if(ListBox1->ItemIndex<0)
        {

        }
else
        {
        DM->ConnectString=FindFileName(ListBox1->Items->Strings[ListBox1->ItemIndex]);
        DM->PasswordUser="masterkey";
        DM->NameUser="SYSDBA";

        if(DM->GlobConnect()==true)
                {
                       if (glUser->FindPoName("CSShtrihMK/"+SetNumber->Text)==1)
                                {
                                if (glUser->ElementPASSWORD_USER->AsString=="12345678")
                                        {
                                        //получим параметры ККМ
                                        if (KKM->FindPoSetNumber(StrToInt(SetNumber->Text))==0)
                                                {
                                                ShowMessage("Не найдена ККМ с заданным сетевым номером!");
                                                }
                                        else
                                                {
                                                F->Visible=true;
                                                F->StatusBar->Panels->Items[0]->Text=glUser->ElementNAME_USER->AsString;
                                                F->StatusBar->Panels->Items[1]->Text=DM->ConnectString;
                                                DM->glCatalogProtocol=KKM->ElementCATPRKKM->AsString;
                                                CS->NamePort=KKM->ElementCOMNAMEKKM->AsString;
                                                CS->OpenPort();
                                                CS->Resume();

                                                Close();
                                                zapusk=true;
                                                }
                                        }
                                else
                                        {
                                        ShowMessage("Неправильное имя пользователя или пароль!");
                                        }
                                }
                       else
                        {
                        ShowMessage("Неправильное имя пользователя или пароль!");
                        }

                }
        else
                {
                 ShowMessage("Неправильно задан путь к базе данных или неверные имя пользователя или пароль!");
                }   
        }

}
//---------------------------------------------------------------------------
void __fastcall TFZapusk::ButtonRenameClick(TObject *Sender)
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
void TFZapusk::UpdateSpisok()
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

String TFZapusk::FindFileName(String NameBase)
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
void __fastcall TFZapusk::ListBox1Click(TObject *Sender)
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

void __fastcall TFZapusk::ButtonDelClick(TObject *Sender)
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


