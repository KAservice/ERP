//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPrintPrihNakl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TPrintFormDocPrihNakl::TPrintFormDocPrihNakl(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrintFormDocPrihNakl::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;        
}
//---------------------------------------------------------------------------
