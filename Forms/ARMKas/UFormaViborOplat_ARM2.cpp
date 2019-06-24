//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaViborOplat_ARM2.h"
#include "UGlobalFunction.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCalc"
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
#pragma link "cxLabel"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaViborOplat_ARM2::TFormaViborOplat_ARM2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborOplat_ARM2::FormCreate(TObject *Sender)
{
OutReady=false;
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborOplat_ARM2::FormClose(TObject *Sender,
      TCloseAction &Action)
{
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaViborOplat_ARM2::UpdateForm(void)
{
cxGrid1->SetFocus();
cxGrid1TableView1NAL->Focused=true;
cxGrid1TableView1->Controller->FocusedRowIndex=0;
}
//---------------------------------------------------------------------------


void __fastcall TFormaViborOplat_ARM2::cxGrid1TableView1NALPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;

if (DisplayValue.IsNull()!=true
		&&  dc->Values[dc->FocusedRowIndex][cxGrid1TableView1SUMCHECK->Index].IsNull()!=true
		&&	dc->Values[dc->FocusedRowIndex][cxGrid1TableView1OPLPLATCARD->Index].IsNull()!=true)
	{
	dc->Values[dc->FocusedRowIndex][cxGrid1TableView1SDACHA->Index]=
			 DisplayValue-
			 dc->Values[dc->FocusedRowIndex][cxGrid1TableView1SUMCHECK->Index]+
			 dc->Values[dc->FocusedRowIndex][cxGrid1TableView1OPLPLATCARD->Index];
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborOplat_ARM2::cxGrid1TableView1OPLPLATCARDPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;


if (dc->Values[dc->FocusedRowIndex][cxGrid1TableView1NAL->Index].IsNull()!=true
		&&  dc->Values[dc->FocusedRowIndex][cxGrid1TableView1SUMCHECK->Index].IsNull()!=true
		&&	DisplayValue.IsNull()!=true)
	{
	double v1=DisplayValue;
	double v2=dc->Values[dc->FocusedRowIndex][cxGrid1TableView1SUMCHECK->Index];  

	if (glCompareDoubleValue(v1, v2, 3) < 1)
		{
		dc->Values[dc->FocusedRowIndex][cxGrid1TableView1SDACHA->Index]=
			 dc->Values[dc->FocusedRowIndex][cxGrid1TableView1NAL->Index]-
			 dc->Values[dc->FocusedRowIndex][cxGrid1TableView1SUMCHECK->Index]+
			 DisplayValue;
		}
	else
		{
		Error=true;
		ErrorText="Сумма оплаты платежной картой не может быть больше суммы чека!";
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaViborOplat_ARM2::ActionCloseExecute(TObject *Sender)
{
OutReady=false;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborOplat_ARM2::ActionPrintExecute(TObject *Sender)
{
OutReady=true;
try {if(FOnPrintCheck) FOnPrintCheck(this); } catch (...){}
}
//---------------------------------------------------------------------------

