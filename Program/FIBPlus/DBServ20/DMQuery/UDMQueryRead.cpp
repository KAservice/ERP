//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMQueryRead.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMQueryRead::TDMQueryRead(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMQueryRead::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TDMQueryRead::DataModuleDestroy(TObject *Sender)
{
pFIBQ->Close();
}
//---------------------------------------------------------------------------
