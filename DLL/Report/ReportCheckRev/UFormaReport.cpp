//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaReport.h"
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
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxPC"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaReport::TFormaReport(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaReport::FormCreate(TObject *Sender)
{
cxDateEdit1->Date=Date()-DayOf(Date())+1;


}
//---------------------------------------------------------------------------
void TFormaReport::UpdateForm(void)
{
SpisokFirm->Active=false;
SpisokSklad->Active=false;
SpisokInv->Active=false;
SpisokFirm->Active=true;
SpisokSklad->Active=true;
SpisokInv->Active=true;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TFormaReport::FormClose(TObject *Sender, TCloseAction &Action)
{
pFIBDataSet1->Active=false;
SpisokFirm->Active=false;
SpisokSklad->Active=false;
Action=caFree;

}
//---------------------------------------------------------------------------
void __fastcall TFormaReport::FormDestroy(TObject *Sender)
{
if(FOnCloseForm) FOnCloseForm();
}
//--------------------------------------------------------------------------
void __fastcall TFormaReport::cxButton1Click(TObject *Sender)
{
SpisokFirm->First();
SpisokFirm->MoveBy(NameFirmcxLookupComboBox->ItemIndex);

SpisokSklad->First();
SpisokSklad->MoveBy(NameSkladcxLookupComboBox->ItemIndex);

SpisokInv->First();
SpisokInv->MoveBy(NameInvcxLookupComboBox->ItemIndex);

if (cxPageControl1->ActivePage->PageIndex==0)
	{
	pFIBDataSet1->Active=false;
	pFIBDataSet1->ParamByName("PARAM_POS")->AsDateTime=cxDateEdit1->Date;
	pFIBDataSet1->ParamByName("PARAM_IDFIRM")->AsString=SpisokFirmIDFIRM->AsString;
	pFIBDataSet1->ParamByName("PARAM_IDSKLAD")->AsString=SpisokSkladIDSKLAD->AsString;
	pFIBDataSet1->ParamByName("PARAM_IDINV")->AsString=SpisokInvID_SINV->AsString;
	pFIBDataSet1->Active=true;

	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{  
	pFIBDataSet2->Active=false;
	pFIBDataSet2->ParamByName("PARAM_POS")->AsDateTime=cxDateEdit1->Date;
	pFIBDataSet2->ParamByName("PARAM_IDFIRM")->AsString=SpisokFirmIDFIRM->AsString;
	pFIBDataSet2->ParamByName("PARAM_IDSKLAD")->AsString=SpisokSkladIDSKLAD->AsString;
	pFIBDataSet2->ParamByName("PARAM_IDINV")->AsString=SpisokInvID_SINV->AsString;
	pFIBDataSet2->Active=true;

	}






}
//---------------------------------------------------------------------------
void __fastcall TFormaReport::pFIBDataSet1CalcFields(TDataSet *DataSet)
{
pFIBDataSet1RESULT->AsInteger=0;
if (fabs(pFIBDataSet1OUT_KOL_RASNOST->AsFloat)>0.001)

	{
	pFIBDataSet1RESULT->AsInteger=0;
	}
else
	{
	pFIBDataSet1RESULT->AsInteger=1;
	}

pFIBDataSet1RECNO->AsInteger=pFIBDataSet1->RecNo;
}
//---------------------------------------------------------------------------


void __fastcall TFormaReport::cxGrid1DBTableView1RESCustomDrawCell(
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
	ImageList1->GetBitmap(1,ABitmap);
	}
else
	{
	ImageList1->GetBitmap(0,ABitmap);
	}
ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::pFIBDataSet2CalcFields(TDataSet *DataSet)
{
pFIBDataSet2RESULT->AsInteger=0;
if (fabs(pFIBDataSet2OUT_KOL_RASNOST->AsFloat)>0.001)

	{
	pFIBDataSet2RESULT->AsInteger=0;
	}
else
	{
	pFIBDataSet2RESULT->AsInteger=1;
	}

pFIBDataSet2RECNO->AsInteger=pFIBDataSet2->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::cxGrid2DBTableView1RESULTCustomDrawCell(
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
	ImageList1->GetBitmap(1,ABitmap);
	}
else
	{
	ImageList1->GetBitmap(0,ABitmap);
	}
ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------

