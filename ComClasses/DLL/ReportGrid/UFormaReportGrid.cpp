//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop


//--------------------------------------------------------------------------
#include "UFormaReportGrid.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
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
//#pragma link "dxPScxGrid6Lnk"
#pragma link "dxPSEdgePatterns"
#pragma link "dxPSEngn"
#pragma link "dxPSFillPatterns"
#pragma link "dxPSGlbl"
#pragma link "dxPSUtl"
#pragma link "dxWrap"

#pragma link "cxExportC14"
#include "cxGridExportLink.hpp"
#pragma link "cxLookAndFeels"
#pragma link "cxGrid"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportGrid::TFormaReportGrid(TComponent* Owner)
	: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TFormaReportGrid::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

DM=new TDMReportGrid(Application);
DM->DM_Connection=DM_Connection;
DM->Init();

cxGrid1DBBandedTableView1->DataController->DataSource=DM->DataSourceReport;
cxGrid2DBChartView1->DataController->DataSource=DM->DataSourceReport;



//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaReportGrid::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportGrid::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
//получим ICallBack для передачи события в вызывающую форму
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		}
	i_callback->kanRelease();
	}


delete DM;
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TFormaReportGrid::OpenReport(void)
{


DM->OpenReport();
}
//----------------------------------------------------------------------------
void TFormaReportGrid::AddColumn(AnsiString field_name,
					AnsiString caption,
					int width,
					int group_index,
					bool group_sum,
					AnsiString format_group_sum,
					bool footer_sum,
					AnsiString format_footer_sum)
{
//cxGrid1DBBandedTableView1->OptionsView->GroupSummaryLayout=gslAlignWithColumnsAndDistribute;


ADBColumn = cxGrid1DBBandedTableView1->CreateColumn();
ADBColumn->DataBinding->FieldName =field_name;
//ADBColumn->Name = "cxGrid1DBBandedTableView1NAMEFIRM";
ADBColumn->Caption=caption;
ADBColumn->Width=width;
ADBColumn->GroupIndex=group_index;
if (group_index>=0)
	{
	ADBColumn->Visible=false;
	}
//ADBColumn->Styles->Content=cxStyle1;
//ADBColumn->Styles->GroupSummary=cxStyle1;
//ADBColumn->Styles->Header=cxStyle1;
//ADBColumn->Styles->Footer=cxStyle1;

if (footer_sum==true)
	{
	TcxDataSummary * summary = cxGrid1DBBandedTableView1->DataController->Summary;
	summary->BeginUpdate();
	try {
		SummaryItem = (TcxGridDBTableSummaryItem *)(summary->FooterSummaryItems->Add());
		SummaryItem->FieldName =field_name;
		SummaryItem->Column=ADBColumn;
		SummaryItem->Kind = skSum;
		SummaryItem->Format = format_footer_sum;
		SummaryItem->Position = spFooter;
		}
	__finally
		{
		summary->EndUpdate();
		}
	}

if (group_sum==true)
	{
	TcxDataSummary * summary = cxGrid1DBBandedTableView1->DataController->Summary;
	summary->BeginUpdate();
	try {
		//group
		SummaryGroup=(TcxGridDBTableSummaryItem *) summary->DefaultGroupSummaryItems->Add();
		SummaryGroup->Column = ADBColumn;
		SummaryGroup->FieldName =field_name;
		SummaryGroup->Kind = skSum;
		SummaryGroup->Position = spGroup;
		SummaryGroup->Format = format_group_sum;
		}
	__finally
		{
		summary->EndUpdate();
		}
	}
}
//----------------------------------------------------------------------------
void TFormaReportGrid::SetTextQuery(AnsiString zapros)
{
DM->SetTextQuery(zapros);
}
//-----------------------------------------------------------------------------
void __fastcall TFormaReportGrid::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void TFormaReportGrid::CreateSeries(AnsiString name_field, AnsiString display_text)
{
  TcxGridDBChartSeries *ADBSeries;

  ADBSeries = cxGrid2DBChartView1->CreateSeries();
  ADBSeries->DataBinding->FieldName = name_field;
  ADBSeries->DisplayText=display_text;


}
//----------------------------------------------------------------------------
void TFormaReportGrid::AddDataGroups(AnsiString name_field, AnsiString display_text)
{
TcxGridDBChartDataGroup * group;

   group=cxGrid2DBChartView1->CreateDataGroup();
   group->DataBinding->FieldName=name_field;
   group->DisplayText=display_text;
}
//----------------------------------------------------------------------------
void TFormaReportGrid::SetCaptionReport(AnsiString text)
{
cxGrid1DBBandedTableView1->Bands->Items[0]->Caption=text;

}
//-----------------------------------------------------------------------------
void TFormaReportGrid::SetFontColorContentTecColumn(int style)
{


//ADBColumn->Styles->Content->Font->Color=color;

}
//----------------------------------------------------------------------------

void __fastcall TFormaReportGrid::ActionPreeViewExecute(TObject *Sender)
{
if (cxPageControl1->ActivePage->PageIndex==0)
	{
	dxComponentPrinter1->ReportLink[0]->Preview(true);
	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{
	dxComponentPrinter1->ReportLink[1]->Preview(true);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportGrid::ActionPageSetupExecute(TObject *Sender)
{

if (cxPageControl1->ActivePage->PageIndex==0)
	{
	dxComponentPrinter1->ReportLink[0]->PageSetup();
	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{
	dxComponentPrinter1->ReportLink[1]->PageSetup();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportGrid::ActionPrintExecute(TObject *Sender)
{

if (cxPageControl1->ActivePage->PageIndex==0)
	{
	dxComponentPrinter1->ReportLink[0]->Print(false, NULL);
	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{
	dxComponentPrinter1->ReportLink[1]->Print(false, NULL);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportGrid::ActionExportExcelExecute(TObject *Sender)
{

if (cxPageControl1->ActivePage->PageIndex==0)
	{
	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid1, true, true,true, "xls");
		}     
	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{
	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid2, true, true,true, "xls");
		}     
	}
}
//---------------------------------------------------------------------------
int TFormaReportGrid::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return-1;

}

