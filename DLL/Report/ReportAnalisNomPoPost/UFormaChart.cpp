//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaChart.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxStyles"
#pragma link "dxBkgnd"
#pragma link "dxPrnDev"
#pragma link "dxPrnPg"
#pragma link "dxPSCompsProvider"
#pragma link "dxPSCore"
#pragma link "dxPScxCommon"
#pragma link "dxPScxGrid6Lnk"
#pragma link "dxPSEdgePatterns"
#pragma link "dxPSEngn"
#pragma link "dxPSFillPatterns"
#pragma link "dxPSGlbl"
#pragma link "dxPSUtl"
#pragma link "dxWrap"
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
#pragma link "cxGridChartView"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBChartView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
#pragma link "cxExportC14"
#include "cxGridExportLink.hpp"
//---------------------------------------------------------------------------
__fastcall TFormaChart::TFormaChart(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaChart::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TFormaChart::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
}
//---------------------------------------------------------------------------
void __fastcall TFormaChart::ActionPrintExecute(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->Print(false, NULL);	
}
//---------------------------------------------------------------------------

void __fastcall TFormaChart::ActionPreeViewExecute(TObject *Sender)
{
	dxComponentPrinter1->ReportLink[0]->Preview(true);	
}
//---------------------------------------------------------------------------

void __fastcall TFormaChart::ActionPageSetupExecute(TObject *Sender)
{
	dxComponentPrinter1->ReportLink[0]->PageSetup();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaChart::ActionExportExcelExecute(TObject *Sender)
{
	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid2, true, true,true, "xls");
        }	
}
//---------------------------------------------------------------------------

void __fastcall TFormaChart::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

