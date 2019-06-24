//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaGur.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaGur::TFormaGur(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaGur::FormCreate(TObject *Sender)
{
cxDateEdit1->Date=Date()-DayOf(Date())+1;
cxDateEdit2->Date=Date()+EncodeTime(23,59,59,999);

}
//---------------------------------------------------------------------------
void __fastcall TFormaGur::FormClose(TObject *Sender, TCloseAction &Action)
{
pFIBDataSet1->Active=false;
Action=caFree;

}
//---------------------------------------------------------------------------
void __fastcall TFormaGur::FormDestroy(TObject *Sender)
{
if(FOnCloseForm) FOnCloseForm();
}
//--------------------------------------------------------------------------
void __fastcall TFormaGur::cxButton1Click(TObject *Sender)
{
pFIBDataSet1->Active=false;
pFIBDataSet1->ParamByName("PARAM_POSNACH")->AsDateTime=cxDateEdit1->Date;
pFIBDataSet1->ParamByName("PARAM_POSCON")->AsDateTime=cxDateEdit2->Date;
pFIBDataSet1->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaGur::pFIBDataSet1CalcFields(TDataSet *DataSet)
{
pFIBDataSet1ERROR->AsInteger=0;
if (fabs(pFIBDataSet1OUT_SUM_REG->AsFloat-(pFIBDataSet1OUT_SUM_CHECK->AsFloat+
				pFIBDataSet1OUT_SUM_DISCOUNT->AsFloat))>0.01)

	{
    pFIBDataSet1ERROR->AsInteger=1;
	}

pFIBDataSet1RASNOST->AsFloat=pFIBDataSet1OUT_SUM_REG->AsFloat-
					(pFIBDataSet1OUT_SUM_CHECK->AsFloat+
						pFIBDataSet1OUT_SUM_DISCOUNT->AsFloat );
}
//---------------------------------------------------------------------------

void __fastcall TFormaGur::cxGrid1DBTableView1ERRORCustomDrawCell(
      TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
      TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)
{
AnsiString ATextToDraw;
if (dynamic_cast<TcxGridTableDataCellViewInfo *>(AViewInfo) != NULL)
	{
	ATextToDraw = AViewInfo->GridRecord->DisplayTexts[AViewInfo->Item->Index];
	}
else
	{
	ATextToDraw = VarAsType(AViewInfo->Item->Caption, varString);
	}

TRect ARec = AViewInfo->Bounds;
Graphics::TBitmap *ABitmap = new Graphics::TBitmap();
if (ATextToDraw==1)
	{
	ImageList1->GetBitmap(0,ABitmap);
	}
else
	{
	ImageList1->GetBitmap(1,ABitmap);
	}
ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------

