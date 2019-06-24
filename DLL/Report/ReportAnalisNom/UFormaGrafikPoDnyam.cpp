//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaGrafikPoDnyam.h"
#include "UFormaDialoga.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
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
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxExportC14"
#include "cxGridExportLink.hpp"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaGrafikPoDnyam::TFormaGrafikPoDnyam(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaGrafikPoDnyam::FormCreate(TObject *Sender)
{
//	
}
//---------------------------------------------------------------------------
void __fastcall TFormaGrafikPoDnyam::FormClose(TObject *Sender,
      TCloseAction &Action)
{
ReportDataSet->Active=false;
Action=caFree;
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
}
//---------------------------------------------------------------------------
void TFormaGrafikPoDnyam::UpdateForm(void)
{
ReportDataSet->Active=false;
ReportDataSet->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
ReportDataSet->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
ReportDataSet->ParamByName("PARAM_IDFIRM")->AsString=IdFirm;
ReportDataSet->ParamByName("PARAM_IDSKLAD")->AsString=IdSklad;
ReportDataSet->ParamByName("PARAM_IDNOM")->AsString=IdNom;
ReportDataSet->Active=true;

}
//----------------------------------------------------------------------------
void __fastcall TFormaGrafikPoDnyam::ActionPrintExecute(TObject *Sender)
{
	dxComponentPrinter1->ReportLink[0]->Print(false, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TFormaGrafikPoDnyam::ActionPreeViewExecute(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->Preview(true);
}
//---------------------------------------------------------------------------

void __fastcall TFormaGrafikPoDnyam::ActionPageSetupExecute(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->PageSetup();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGrafikPoDnyam::ActionExportExcelExecute(TObject *Sender)
{
	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid1, true, true,true, "xls");
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaGrafikPoDnyam::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

