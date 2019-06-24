//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma link "IB_Services"
#pragma resource "*.dfm"
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDM::DataModuleCreate(TObject *Sender)
{
Database1->Connected=false;
Database2->Connected=false;
}
//---------------------------------------------------------------------------
void __fastcall TDM::DataModuleDestroy(TObject *Sender)
{
Tables->Close();
Fields->Close();

pFIBSecurityService1->Active = false ;
SprUser->Close();

Database1->Connected=false;
Database2->Connected=false;
}
//---------------------------------------------------------------------------


