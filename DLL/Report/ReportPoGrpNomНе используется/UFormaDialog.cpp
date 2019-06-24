//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDialog.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDialog::TFormaDialog(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialog::FormClose(TObject *Sender, TCloseAction &Action)
{
pFIBDataSet1->Active=false;
Action=caFree;

}
//---------------------------------------------------------------------------
void __fastcall TFormaDialog::FormDestroy(TObject *Sender)
{
if(FOnCloseForm) FOnCloseForm();
}
//---------------------------------------------------------------------------
void TFormaDialog::RunReport()
{
pFIBDataSet1->Active=true;


}
//--------------------------------------------------------------------------
