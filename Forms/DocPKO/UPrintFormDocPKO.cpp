//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPrintFormDocPKO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TPrintFormDocPKO::TPrintFormDocPKO(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrintFormDocPKO::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;        
}
//---------------------------------------------------------------------------

void __fastcall TPrintFormDocPKO::Button1Click(TObject *Sender)
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

void __fastcall TPrintFormDocPKO::Button3Click(TObject *Sender)
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

void __fastcall TPrintFormDocPKO::ButtonSaveClick(TObject *Sender)
{
F1->Write ("C:\\Menu.xls", 4);
}
//---------------------------------------------------------------------------


