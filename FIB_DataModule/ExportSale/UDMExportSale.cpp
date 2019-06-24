//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMExportSale.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMExportSale::TDMExportSale(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMExportSale::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TDMExportSale::DataModuleDestroy(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
