//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


//--------------------------------------------------------------------------
#include "UFormReportGrid.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormReportGrid::TFormReportGrid(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormReportGrid::FormCreate(TObject *Sender)
{
DM=new TDMReportGrid(Application);
}
//---------------------------------------------------------------------------
void __fastcall TFormReportGrid::FormClose(TObject *Sender,
      TCloseAction &Action)
{
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormReportGrid::OpenReport(void)
{
DM->OpenReport();
}
//----------------------------------------------------------------------------
void TFormReportGrid::SetTextQuery(AnsiString zapros)
{
DM->SetTextQuery(zapros);
}
//-----------------------------------------------------------------------------
