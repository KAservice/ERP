//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


//--------------------------------------------------------------------------
#include "UFormaReport.h"
#include "inifiles.hpp"


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

#pragma link "cxExportC11"
#include "cxGridExportLink.hpp"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxCheckBox"
#pragma link "cxLabel"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxLookupEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma link "cxMemo"
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

AlcGrpFileName="AlcGroup.ini";
ProducerFileName="Producer.ini";
PostFileName="Samplier.ini";
}
//---------------------------------------------------------------------------
void TFormaReport::UpdateForm(void)
{
SpisokFirm->Active=false;
SpisokSklad->Active=false;
SpisokTypePrice->Active=false;

SpisokFirm->Active=true;
SpisokSklad->Active=true;
SpisokTypePrice->Active=true;



PosNachcxDateEdit->Date=Date()-DayOf(Date())+1;

}
//---------------------------------------------------------------------------
void __fastcall TFormaReport::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
SpisokFirm->Active=false;
SpisokSklad->Active=false;
SpisokTypePrice->Active=false;


if(prForm)prForm->Close();

Action=caFree; 
}
//----------------------------------------------------------------------------
void __fastcall TFormaReport::FormDestroy(TObject *Sender)
{
try {if(FOnCloseForm) FOnCloseForm(); } catch (...){}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaReport::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//----------------------------------------------------------------------------

void __fastcall TFormaReport::ActionPreeViewExecute(TObject *Sender)
{

if (cxPageControl1->ActivePage->PageIndex==0)
	{
	dxComponentPrinter1->ReportLink[0]->Preview(true);
	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{
	dxComponentPrinter1->ReportLink[1]->Preview(true);
	}

if (cxPageControl1->ActivePage->PageIndex==2)
	{
	dxComponentPrinter1->ReportLink[2]->Preview(true);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionPageSetupExecute(TObject *Sender)
{


if (cxPageControl1->ActivePage->PageIndex==0)
	{
	dxComponentPrinter1->ReportLink[0]->PageSetup();
	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{
	dxComponentPrinter1->ReportLink[1]->PageSetup();
	}

if (cxPageControl1->ActivePage->PageIndex==2)
	{
	dxComponentPrinter1->ReportLink[2]->PageSetup();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionPrintExecute(TObject *Sender)
{
if (cxPageControl1->ActivePage->PageIndex==0)
	{
	dxComponentPrinter1->ReportLink[0]->Print(false, NULL);
	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{
	dxComponentPrinter1->ReportLink[1]->Print(false, NULL);
	}

if (cxPageControl1->ActivePage->PageIndex==2)
	{
	dxComponentPrinter1->ReportLink[2]->Print(false, NULL);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionExportExcelExecute(TObject *Sender)
{

if (cxPageControl1->ActivePage->PageIndex==0)
	{
	SaveDialog1->FileName="Items_"+FormatDateTime("ddmmyy",Date())+"_"+
								FormatDateTime("hhmm",Time());
	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid1, true, true,true, "xls");
		}

	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{
			SaveDialog1->FileName="StockPrice_"+FormatDateTime("ddmmyy",Date())+"_"+
								FormatDateTime("hhmm",Time());

	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid2, true, true,true, "xls");
		}
	}

if (cxPageControl1->ActivePage->PageIndex==2)
	{
		SaveDialog1->FileName="SaleOut_"+FormatDateTime("ddmmyy",Date())+"_"+
								FormatDateTime("hhmm",Time());
	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid3, true, true,true, "xls");
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaReport::EventCloseFormPrint(TObject *Sender)
{
prForm=0; 
}

//-----------------------------------------------------------------------------

void __fastcall TFormaReport::cxButtonPrintRasdel1Click(TObject *Sender)
{
//CreateReportRasdel1();
//
//
//numCol=1;
//numRow=1;
//
//Rasdel1_NachOstBasEd=0;
//Rasdel1_PrihodBasEd=0;
//Rasdel1_RashodBasEd=0;
//Rasdel1_ConOstBasEd=0;
//
//Rasdel1_NachOstFisEd=0;
//Rasdel1_PrihodFisEd=0;
//Rasdel1_RashodFisEd=0;
//Rasdel1_ConOstFisEd=0;
//
//prForm=new TSheetEditor2(Application);
//
//prForm->SS->BeginUpdate();
//prForm->FOnCloseForm=EventCloseFormPrint;
//
//
//Rasdel1_OutputHeader();
//
//TcxCustomDataController *dc = Rasdel1cxGridTableView1->DataController;
//
//for (int i=0;i<dc->RecordCount;i++)
//	{
//	Rasdel1_OutputString(i);
//
//	Rasdel1_NachOstBasEd=Rasdel1_NachOstBasEd+
//								dc->Values[i][Rasdel1cxGridTableView1NACHOST->Index];
//	Rasdel1_PrihodBasEd=Rasdel1_PrihodBasEd+
//								dc->Values[i][Rasdel1cxGridTableView1PRIHOD->Index];
//	Rasdel1_RashodBasEd=Rasdel1_RashodBasEd+
//								dc->Values[i][Rasdel1cxGridTableView1RASHOD->Index];
//	Rasdel1_ConOstBasEd=Rasdel1_ConOstBasEd+
//								dc->Values[i][Rasdel1cxGridTableView1CONOST->Index];
//
//	Rasdel1_NachOstFisEd=Rasdel1_NachOstFisEd+
//								dc->Values[i][Rasdel1cxGridTableView1FISED_NACHOST->Index];
//	Rasdel1_PrihodFisEd=Rasdel1_PrihodFisEd+
//								dc->Values[i][Rasdel1cxGridTableView1FISED_PRIHOD->Index];
//	Rasdel1_RashodFisEd=Rasdel1_RashodFisEd	+
//								dc->Values[i][Rasdel1cxGridTableView1FISED_RASHOD->Index];
//	Rasdel1_ConOstFisEd=Rasdel1_ConOstFisEd+
//								dc->Values[i][Rasdel1cxGridTableView1FISED_CONOST->Index];
//	}
//
//
//Rasdel1_OutputFooter();
//
//prForm->SS->EndUpdate();
}
//---------------------------------------------------------------------------
void TFormaReport::Rasdel1_OutputHeader(void)
{
//SpisokFirm->First();
//SpisokFirm->MoveBy(NameFirmcxLookupComboBox->ItemIndex);
//
//SpisokSklad->First();
//SpisokSklad->MoveBy(NameSkladcxLookupComboBox->ItemIndex);
//
//Query->Close();
//Query->SQL->Clear();
//Query->SQL->Add("select * from SFIRM where IDFIRM="+IntToStr(SpisokFirmIDFIRM->AsInt64));
//Query->ExecQuery();
//
//
////if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
//
//
//prForm->SS->DefaultStyle->Font->Size=10;
//prForm->SS->DefaultStyle->Font->Name="Arial";
//prForm->SS->RowsAutoHeight=true;
//
//
//TcxSSHeader *cHeader;
//		cHeader = prForm->SS->ActiveSheet->Cols;
//		cHeader->Size[0] = 30;
//		cHeader->Size[1] = 200;
//
//TcxSSCellObject *cell;
//TRect rect;
//
//
//numCol=1;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="Данные об организации:";
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Size = 10;
//delete cell;
//numRow++;
//
//prForm->SS->ActiveSheet->Rows->Size[numRow]=30;
//numCol=1;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+1;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="Наименование";
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Size = 8;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+4;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=Query->FieldByName("FNAMEFIRM")->AsString;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numRow++;
//
//
//
//numCol=1;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+1;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="ИНН, ОКПО";
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Size = 8;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+4;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="ИНН "+Query->FieldByName("INNFIRM")->AsString+"  ОКПО "+
//				Query->FieldByName("OKPOSFIRM")->AsString;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numRow++;
//
//numCol=1;
//prForm->SS->ActiveSheet->Rows->Size[numRow]=30;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+1;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="Юридический адрес, телефон, e-mail, (адрес государственной регистрации)";
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Size = 8;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+4;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=Query->FieldByName("UADRFIRM")->AsString+"  Телефон: "+
//				Query->FieldByName("TELFIRM")->AsString;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numRow++;
//
//numCol=1;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+1;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="Серия, номер, дата получения, срок действия лицензии, кем выдана";
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Size = 8;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//prForm->SS->ActiveSheet->Rows->Size[numRow]=30;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+4;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numRow++;
//numRow++;
//
//numCol=4;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+2;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="ДЕКЛАРАЦИЯ";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 16;
//delete cell;
//
//numRow++;
//numCol=1;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+3;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="о розничной продаже алкогольной продукции за ";
//cell->Style->HorzTextAlign = haRIGHT;
//delete cell;
//
//numCol=5;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+3;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//
//numRow++;
//numCol=5;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+3;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="(отчетный период: 1 квартал, полугодие, 9 месяцев, год)";
//cell->Style->Font->Size = 8;
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaTOP;
//delete cell;
//
//numRow++;
//numRow++;
//
//numCol=4;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+2;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="Раздел I";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 12;
//delete cell;
//
//numRow++;
//
//numCol=2;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+5;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//Query->Close();
//Query->SQL->Clear();
//Query->SQL->Add("select * from SSKLAD where IDSKLAD="+IntToStr(SpisokSkladIDSKLAD->AsInt64));
//Query->ExecQuery();
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=Query->FieldByName("NAMESKLAD")->AsString+", "+
//								Query->FieldByName("ADRSKLAD")->AsString;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numRow++;
//numCol=2;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol+5;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="(наименование и местонахождение территориально обособленного объекта)*";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 8;
//delete cell;
//
//
//numRow++;
//numRow++;
////табличная часть
//prForm->SS->ActiveSheet->Rows->Size[numRow]=40;
//numCol=1;
//		rect.Left = numCol;
//		rect.Top = numRow;
//		rect.Right = numCol;
//		rect.Bottom = numRow+1;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="Вид продукции";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//delete cell;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//		rect.Left = numCol+1;
//		rect.Top = numRow;
//		rect.Right = numCol;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="Остаток на начало отчетного периода";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//
//		rect.Left = numCol+1;
//		rect.Top = numRow;
//		rect.Right = numCol;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="Поступило продукции за отчетный период";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//
//		rect.Left = numCol+1;
//		rect.Top = numRow;
//		rect.Right = numCol;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="Реализовано продукции за отчетный период";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//
//		rect.Left = numCol+1;
//		rect.Top = numRow;
//		rect.Right = numCol;
//		rect.Bottom = numRow;
//		prForm->SS->ActiveSheet->SetMergedState(rect, true);
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="Остаток на конец отчетного периода";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//
//numRow++;
//numCol=2;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="бутылок";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="литров";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="бутылок";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="литров";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="бутылок";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="литров";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="бутылок";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="литров";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//
//numRow++;
//numCol=1;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="1";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="2";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="3";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="4";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="5";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="6";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="7";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="8";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="9";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//
//numRow++;
//
//Query->Close();
}
//---------------------------------------------------------------------------
void TFormaReport::Rasdel1_OutputString(int index_string)
{
//TcxSSCellObject *cell;
//TcxCustomDataController *dc = Rasdel1cxGridTableView1->DataController;
//
//numCol=1;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=dc->Values[index_string][Rasdel1cxGridTableView1NAMEGRP->Index];
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//double val=dc->Values[index_string][Rasdel1cxGridTableView1NACHOST->Index];
//cell->Text=FloatToStrF(val,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//val=dc->Values[index_string][Rasdel1cxGridTableView1FISED_NACHOST->Index];
//cell->Text=FloatToStrF(val,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//val=dc->Values[index_string][Rasdel1cxGridTableView1PRIHOD->Index];
//cell->Text=FloatToStrF(val,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//val=dc->Values[index_string][Rasdel1cxGridTableView1FISED_PRIHOD->Index];
//cell->Text=FloatToStrF(val,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//val=dc->Values[index_string][Rasdel1cxGridTableView1RASHOD->Index];
//cell->Text=FloatToStrF(val,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//val=dc->Values[index_string][Rasdel1cxGridTableView1FISED_RASHOD->Index];
//cell->Text=FloatToStrF(val,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//val=dc->Values[index_string][Rasdel1cxGridTableView1CONOST->Index];
//cell->Text=FloatToStrF(val,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//val=dc->Values[index_string][Rasdel1cxGridTableView1FISED_CONOST->Index];
//cell->Text=FloatToStrF(val,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//
//
//numRow++;
}
//----------------------------------------------------------------------------
void TFormaReport::Rasdel1_OutputFooter(void)
{
//TcxSSCellObject *cell;
//
//
//
//numCol=1;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="ВСЕГО";
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=FloatToStrF(Rasdel1_NachOstBasEd,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=FloatToStrF(Rasdel1_NachOstFisEd,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=FloatToStrF(Rasdel1_PrihodBasEd,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=FloatToStrF(Rasdel1_PrihodFisEd,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=FloatToStrF(Rasdel1_RashodBasEd,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=FloatToStrF(Rasdel1_RashodFisEd,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=FloatToStrF(Rasdel1_ConOstBasEd,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=FloatToStrF(Rasdel1_ConOstFisEd,ffFixed,15,0);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 10;
//cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;
//
//numRow++;
//
//numCol=1;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="* - раздел I декларации заполняется на отдельных бланках по организации в целом и раздельно по каждому территориально обособленному объекту";
//cell->Style->Font->Size =8;
//
//delete cell;
}
//----------------------------------------------------------------------------
void __fastcall TFormaReport::cxButtonUpdateClick(TObject *Sender)
{
SpisokFirm->First();
SpisokFirm->MoveBy(NameFirmcxLookupComboBox->ItemIndex);

SpisokSklad->First();
SpisokSklad->MoveBy(NameSkladcxLookupComboBox->ItemIndex);

SpisokTypePrice->First();
SpisokTypePrice->MoveBy(NameTypePricecxLookupComboBox->ItemIndex);


if (cxPageControl1->ActivePage->PageIndex==0)
	{
	SprNom->Active=false;
	SprNom->Active=true;
	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{  
	OstNom->Active=false;
	OstNom->ParamByName("PARAM_POSNACH")->AsDateTime=PosNachcxDateEdit->Date;
	OstNom->ParamByName("PARAM_POSCON")->AsDateTime=PosNachcxDateEdit->Date+EncodeTime(23,59,59,999);
	OstNom->ParamByName("PARAM_IDFIRM")->AsString=SpisokFirmIDFIRM->AsString;
	OstNom->ParamByName("PARAM_IDSKLAD")->AsString=SpisokSkladIDSKLAD->AsString;
	OstNom->ParamByName("PARAM_IDTYPE_PRICE")->AsString=SpisokTypePriceID_TPRICE->AsString;
	OstNom->Active=true;

	}

if (cxPageControl1->ActivePage->PageIndex==2)
	{  
	ReportSale->Active=false;
	ReportSale->ParamByName("PARAM_POSNACH")->AsDateTime=PosNachcxDateEdit->Date;
	ReportSale->ParamByName("PARAM_POSCON")->AsDateTime=PosNachcxDateEdit->Date+EncodeTime(23,59,59,999);
	ReportSale->ParamByName("PARAM_IDFIRM")->AsString=SpisokFirmIDFIRM->AsString;
	ReportSale->ParamByName("PARAM_IDSKLAD")->AsString=SpisokSkladIDSKLAD->AsString;
	ReportSale->Active=true;

	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::SprNomCalcFields(TDataSet *DataSet)
{
SprNomRECNO->AsInteger=SprNom->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ReportSaleCalcFields(TDataSet *DataSet)
{
ReportSaleRECNO->AsInteger=ReportSale->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::OstNomCalcFields(TDataSet *DataSet)
{
OstNomRECNO->AsInteger=OstNom->RecNo;
}
//---------------------------------------------------------------------------


