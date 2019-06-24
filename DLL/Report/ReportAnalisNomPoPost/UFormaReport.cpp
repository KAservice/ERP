//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


//--------------------------------------------------------------------------
#include "UFormaReport.h"
#include "UFormaDialoga.h"



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
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGridChartView"
#pragma link "cxGridDBChartView"
#pragma link "cxPC"
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

#pragma link "cxExportC14"
#include "cxGridExportLink.hpp"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxCheckBox"
#pragma link "cxLabel"
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
//DM=new TDMReportGrid(Application);

//cxGrid1DBBandedTableView1->DataController->DataSource=DM->DataSourceReport;
//cxGrid2DBChartView1->DataController->DataSource=DM->DataSourceReport;


}
//---------------------------------------------------------------------------
void TFormaReport::UpdateForm(void)
{
ReportDataSet->Active=false;
ReportDataSet->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
ReportDataSet->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
ReportDataSet->ParamByName("PARAM_IDGRP")->AsString=IdKlient;
ReportDataSet->Active=true;
cxGrid1DBBandedTableView1->Bands->Items[0]->Caption=NameKlient;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReport::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
Action=caFree;
if(FormaGrafikPoDnyam)FormaGrafikPoDnyam->Close();
if(FormaChart)FormaChart->Close();
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaReport::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//----------------------------------------------------------------------------

void __fastcall TFormaReport::ActionPreeViewExecute(TObject *Sender)
{

	dxComponentPrinter1->ReportLink[0]->Preview(true);

}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionPageSetupExecute(TObject *Sender)
{


	dxComponentPrinter1->ReportLink[0]->PageSetup();

}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionPrintExecute(TObject *Sender)
{

	dxComponentPrinter1->ReportLink[0]->Print(false, NULL);



}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionExportExcelExecute(TObject *Sender)
{

	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid1, true, true,true, "xls");
        }
}
//---------------------------------------------------------------------------


void __fastcall TFormaReport::ReportDataSetCalcFields(TDataSet *DataSet)
{
if (ReportDataSetKOL_DAY->AsInteger!=0)
	{
	ReportDataSetSRED_SALE->AsFloat=ReportDataSetKOL_SALE->AsFloat/
									ReportDataSetKOL_DAY->AsInteger;
	}
else
	{
	ReportDataSetSRED_SALE->AsFloat=0;
	}

if (ReportDataSetCONOSTKOL_PROC->AsFloat>0.001)
	{
	if (ReportDataSetSRED_SALE->AsFloat > 0.001)
		{
		ReportDataSetXVATIT_NA->AsFloat=ReportDataSetCONOSTKOL_PROC->AsFloat/
									ReportDataSetSRED_SALE->AsFloat;
		}
	else
		{
		ReportDataSetXVATIT_NA->AsFloat=0;
		}
	}
else
	{
	ReportDataSetXVATIT_NA->AsFloat=-1000000;
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaReport::ReportDataSetKOL_DAYGetText(TField *Sender,
	  AnsiString &Text, bool DisplayText)
{
Text=ReportDataSetKOL_DAY->AsString+"дн.";
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ReportDataSetNACENKA_PROCGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
Text=FloatToStrF(ReportDataSetNACENKA_PROC->AsFloat,ffFixed,15,2)+"%";
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ReportDataSetXVATIT_NAGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
if (ReportDataSetXVATIT_NA->AsFloat != -1000000)
	{
	if (ReportDataSetXVATIT_NA->AsFloat > 0.001)
		{
		Text= FloatToStrF(ReportDataSetXVATIT_NA->AsFloat,ffFixed,15,2)+"дн.";
		}
	else
		{
		Text="никогда";
		}
	}
else
	{
    Text="";
	}
}
//---------------------------------------------------------------------------

void TFormaReport::OpenReportGrafikPoDnyam(void)
{
if (FormaGrafikPoDnyam==0)
	{
	FormaGrafikPoDnyam=new TFormaGrafikPoDnyam(Application);

	FormaGrafikPoDnyam->PosNach=PosNach;
	FormaGrafikPoDnyam->PosCon=PosCon;
	FormaGrafikPoDnyam->IdFirm=StrToInt64(ReportDataSetIDFIRM_PROC->AsString);
	FormaGrafikPoDnyam->IdSklad=StrToInt64(ReportDataSetIDSKLAD_PROC->AsString);
	FormaGrafikPoDnyam->IdNom=StrToInt64(ReportDataSetIDNOM_PROC->AsString);
	FormaGrafikPoDnyam->FOnCloseForm=EventCloseFormReportGrafikPoDnyam;

		//database
	FormaGrafikPoDnyam->ReportDataSet->Database=DM_Connection->pFIBData;
	FormaGrafikPoDnyam->pFIBTransaction1->DefaultDatabase=DM_Connection->pFIBData;


	FormaGrafikPoDnyam->UpdateForm();
	FormaGrafikPoDnyam->LabelNameFirm->Caption=
			"ФИРМА: "+ReportDataSetNAMEFIRM_PROC->AsString+
			".   СКЛАД: "+ReportDataSetNAMESKLAD_PROC->AsString+
			".   НОМЕНКЛАТУРА: "+ReportDataSetNAMENOM_PROC->AsString+
			".   ЕДИНИЦА: "+ReportDataSetNAMEED_PROC->AsString;

	FormaGrafikPoDnyam->Show();
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaReport::EventCloseFormReportGrafikPoDnyam(TObject *Sender)
{
FormaGrafikPoDnyam=0;

}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionShowGrafikPodayExecute(TObject *Sender)
{
OpenReportGrafikPoDnyam();
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionCheckAllExecute(TObject *Sender)
{
//TcxCustomDataController *dc = cxGrid1DBBandedTableView1->DataController;
//cxGrid1DBBandedTableView1->BeginUpdate();
//for (int i=0; i<dc->RowCount; i++)
//	{
//	dc->Values[i][cxGrid1DBBandedTableView1CHECK->Index]=1;
//	}
//cxGrid1DBBandedTableView1->EndUpdate();


TcxGridViewData * AViewData=cxGrid1DBBandedTableView1->ViewData;
for(int i=0;i<AViewData->RowCount;i++)
	{
	AViewData->Records[i]->Values[cxGrid1DBBandedTableView1CHECK->Index]=1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionClearAllExecute(TObject *Sender)
{
TcxGridViewData * AViewData=cxGrid1DBBandedTableView1->ViewData;
for(int i=0;i<AViewData->RowCount;i++)
	{
	AViewData->Records[i]->Values[cxGrid1DBBandedTableView1CHECK->Index]=0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionShowDiagrammExecute(TObject *Sender)
{
OpenFormChart();
}
//---------------------------------------------------------------------------
void TFormaReport::OpenFormChart(void)
{

if (FormaChart==0)
	{
	FormaChart=new TFormaChart(Application);
	FormaChart->FOnCloseForm=EventCloseFormChart;
	int index_dohod=FormaChart->cxGrid2ChartView1SeriesDOHOD->Index;
	int index_ost_kol=FormaChart->cxGrid2ChartView1SeriesOSTKOL->Index ;
	int index_sale_kol_day=FormaChart->cxGrid2ChartView1SeriesSALE_KOL_DAY->Index;
	int index_firm=FormaChart->cxGrid2ChartView1DataGroupFIRMA->Index;
	int index_sklad=FormaChart->cxGrid2ChartView1DataGroupSKLAD->Index;
	int index_nom=FormaChart->cxGrid2ChartView1DataGroupNOM->Index;

	TcxGridViewData * AViewData=cxGrid1DBBandedTableView1->ViewData;

	FormaChart->cxGrid2ChartView1->BeginUpdate();
	try
		{
		for(int i=0;i<AViewData->RowCount;i++)
			{
			Variant value=AViewData->Records[i]->Values[cxGrid1DBBandedTableView1CHECK->Index];

			int check=value.intVal;

			if (check==1)
				{
				FormaChart->cxGrid2ChartView1->ViewData->CategoryCount =
						FormaChart->cxGrid2ChartView1->ViewData->CategoryCount+1;
				int kol_record=FormaChart->cxGrid2ChartView1->ViewData->CategoryCount;
						//количество записей в таблице, количество блоков диаграмм

				FormaChart->cxGrid2ChartView1->ViewData->Values[index_dohod][kol_record-1] =
						AViewData->Records[i]->Values[cxGrid1DBBandedTableView1DOHOD_PROC->Index];
				FormaChart->cxGrid2ChartView1->ViewData->Values[index_ost_kol][kol_record-1] =
						AViewData->Records[i]->Values[cxGrid1DBBandedTableView1CONOSTKOL_PROC->Index] ;
				FormaChart->cxGrid2ChartView1->ViewData->Values[index_sale_kol_day][kol_record-1] =
						AViewData->Records[i]->Values[cxGrid1DBBandedTableView1SRED_SALE->Index] ;
										// номер в блоке / номер блока
				FormaChart->cxGrid2ChartView1->ViewData->GroupValues[index_firm][kol_record-1]=
						AViewData->Records[i]->Values[cxGrid1DBBandedTableView1NAMEFIRM_PROC->Index] ;
				FormaChart->cxGrid2ChartView1->ViewData->GroupValues[index_sklad][kol_record-1]=
						AViewData->Records[i]->Values[cxGrid1DBBandedTableView1NAMESKLAD_PROC->Index];
				FormaChart->cxGrid2ChartView1->ViewData->GroupValues[index_nom][kol_record-1]=
						AViewData->Records[i]->Values[cxGrid1DBBandedTableView1NAMENOM_PROC->Index];
									// название блока диаграмм
								 // порядк. номер группировки / номер блока
				}
			}
		}
  	__finally
		{
		FormaChart->cxGrid2ChartView1->EndUpdate();
		}

	FormaChart->Show();
	}



}
//---------------------------------------------------------------------------
void __fastcall TFormaReport::EventCloseFormChart(TObject *Sender)
{

FormaChart=0;

}
//-----------------------------------------------------------------------------
