//---------------------------------------------------------------------------
#include "glPCH.h"
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
bool TDMQueryRead::Init(void)
{
bool result=false;

Transaction->DefaultDatabase=DM_Connection->pFIBData;
Query->Database=DM_Connection->pFIBData;

pFIBTr->DefaultDatabase=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;

result=true;

return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMQueryRead::DataModuleDestroy(TObject *Sender)
{
pFIBQ->Close();
Query->Close();
}
//---------------------------------------------------------------------------
