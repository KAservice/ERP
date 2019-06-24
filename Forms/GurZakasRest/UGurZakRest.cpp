//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UGurZakRest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormaGurZakRest *FormaGurZakRest;
//---------------------------------------------------------------------------
__fastcall TFormaGurZakRest::TFormaGurZakRest(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurZakRest::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurZakRest::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaGurZakRest::UpdateForm(void)
{

//

}
//---------------------------------------------------------------------------
