//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPrintFormAll.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//------------------------,--------------------------------------------------
__fastcall TPrintFormAll::TPrintFormAll(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrintFormAll::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;        
}
//---------------------------------------------------------------------------





void __fastcall TPrintFormAll::Button2Click(TObject *Sender)
{

try
        {
        F1->FilePrintSetupDlg();
        }
catch (...)
        {
        }
}
//---------------------------------------------------------------------------

void __fastcall TPrintFormAll::Button1Click(TObject *Sender)
{
try
        {
        F1->PrintGridLines=false;
        F1->FilePrint(1) ;
        }
catch (...)
        {
        }
}
//---------------------------------------------------------------------------


void __fastcall TPrintFormAll::ButtonSaveClick(TObject *Sender)
{
if (SaveDialog1->Execute())
        {
        try
                {
                F1->Write (SaveDialog1->FileName+".xls", 4);
                }
        catch (...)
                {

                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TPrintFormAll::ButtonPageSetupClick(TObject *Sender)
{
try
        {
        F1->FilePageSetupDlg();
        }
catch (...)
        {
        }
}
//---------------------------------------------------------------------------

void __fastcall TPrintFormAll::ButtonPrintSetupClick(TObject *Sender)
{
try
        {
        F1->FilePrintSetupDlg();
        }
catch (...)
        {
        }
}
//---------------------------------------------------------------------------

