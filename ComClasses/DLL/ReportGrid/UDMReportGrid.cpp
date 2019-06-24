//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMReportGrid.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMReportGrid::TDMReportGrid(TComponent* Owner)
	: TDataModule(Owner)
{

DM_Connection=0;

}
//---------------------------------------------------------------------------
bool TDMReportGrid::Init(void)
{
bool result=false;


Tr->DefaultDatabase=DM_Connection->pFIBData;

Report->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMReportGrid::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMReportGrid::DataModuleDestroy(TObject *Sender)
{
Report->Active=false;
}
//---------------------------------------------------------------------------
void TDMReportGrid::SetTextQuery(AnsiString zapros)
{
Report->Active=false;
Report->SelectSQL->Clear();
Report->SelectSQL->Add(zapros);
}
//----------------------------------------------------------------------------
void TDMReportGrid::OpenReport(void)
{
Report->Active=true;
}
//----------------------------------------------------------------------------
