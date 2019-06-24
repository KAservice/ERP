//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "URegOstNom.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDMRegOstNom *DMRegOstNom;
//---------------------------------------------------------------------------
__fastcall TDMRegOstNom::TDMRegOstNom(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
