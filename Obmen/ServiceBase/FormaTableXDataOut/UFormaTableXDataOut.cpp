//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaTableXDataOut.h"
#include "UDataModuleMain.h"
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
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxCalendar"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaTableXDataOut::TFormaTableXDataOut(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaTableXDataOut::FormCreate(TObject *Sender)
{
BaseList->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaTableXDataOut::FormClose(TObject *Sender,
      TCloseAction &Action)
{
BaseList->Active=false;
Table->Active=false;
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaTableXDataOut::UpdateForm(void)
{
Table->Active=false;
Table->ParamByName("PARAM_NACH")->AsDateTime=NachcxDateEdit->Date;
Table->ParamByName("PARAM_CON")->AsDateTime=ConcxDateEdit->Date;

BaseList->First();
BaseList->MoveBy(NameBasecxLookupComboBox->ItemIndex);
Table->ParamByName("PARAM_IDBASE")->AsString=BaseListID_SINFBASE_OBMEN->AsString;
Table->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TFormaTableXDataOut::ToolButtonUpdateFormClick(TObject *Sender)
{
UpdateForm();
}
//---------------------------------------------------------------------------

