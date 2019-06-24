//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMQueryUpdate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMQueryUpdate::TDMQueryUpdate(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMQueryUpdate::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TDMQueryUpdate::DataModuleDestroy(TObject *Sender)
{
pFIBQ->Close();
}
//---------------------------------------------------------------------------
