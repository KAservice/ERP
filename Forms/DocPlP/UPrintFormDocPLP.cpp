//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPrintFormDocPLP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TPrintFormDocPLP::TPrintFormDocPLP(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrintFormDocPLP::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;        
}
//---------------------------------------------------------------------------

void __fastcall TPrintFormDocPLP::Button1Click(TObject *Sender)
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

void __fastcall TPrintFormDocPLP::Button3Click(TObject *Sender)
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

void __fastcall TPrintFormDocPLP::ButtonSaveClick(TObject *Sender)
{
F1->Write ("C:\\Menu.xls", 4);
}
//---------------------------------------------------------------------------


