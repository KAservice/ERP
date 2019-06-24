//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPrintFormDocRKO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TPrintFormDocRKO::TPrintFormDocRKO(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrintFormDocRKO::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;        
}
//---------------------------------------------------------------------------

void __fastcall TPrintFormDocRKO::Button1Click(TObject *Sender)
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

void __fastcall TPrintFormDocRKO::Button3Click(TObject *Sender)
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

void __fastcall TPrintFormDocRKO::ButtonSaveClick(TObject *Sender)
{
F1->Write ("C:\\Menu.xls", 4);
}
//---------------------------------------------------------------------------


