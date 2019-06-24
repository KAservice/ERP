//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UChanche.h"
#include "UZapusk.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFChanche *FChanche;
//---------------------------------------------------------------------------
__fastcall TFChanche::TFChanche(TComponent* Owner)
        : TForm(Owner)
{
OldName="";
}
//---------------------------------------------------------------------------
void __fastcall TFChanche::ButtonCancelClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFChanche::ButtonOKClick(TObject *Sender)
{
if(FZapusk->List->Count<10)
        {
        for(int i=FZapusk->List->Count;i<10;i++)
                {
                FZapusk->List->Add(IntToStr(i));
                }

        }


if (OldName=="")
        {
        FZapusk->List->Add(NameBase->Text);
        FZapusk->List->Add(FileName->Text);
        }
else
        {

        for(int i=10;i<FZapusk->List->Count;i++)
                {
                if(OldName==FZapusk->List->Strings[i])
                        {
                        FZapusk->List->Strings[i]=NameBase->Text;
                        FZapusk->List->Strings[i+1]=FileName->Text;
                        }

                }

        }
FZapusk->List->SaveToFile("SpBase.txt");
FZapusk->UpdateSpisok();
Close();
}
//---------------------------------------------------------------------------
