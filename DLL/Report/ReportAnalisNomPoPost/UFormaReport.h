//---------------------------------------------------------------------------

#ifndef UFormaReportH
#define UFormaReportH
//---------------------------------------------------------------------------
#include "UFormaGrafikPoDnyam.h"
#include "UFormaChart.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGridChartView.hpp"
#include "cxGridDBChartView.hpp"
#include "cxPC.hpp"
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "dxBkgnd.hpp"
#include "dxPrnDev.hpp"
#include "dxPrnPg.hpp"
#include "dxPSCompsProvider.hpp"
#include "dxPSCore.hpp"
#include "dxPScxCommon.hpp"
#include "dxPScxGrid6Lnk.hpp"
#include "dxPSEdgePatterns.hpp"
#include "dxPSEngn.hpp"
#include "dxPSFillPatterns.hpp"
#include "dxPSGlbl.hpp"
#include "dxPSUtl.hpp"
#include "dxWrap.hpp"
#include <Dialogs.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "cxCheckBox.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaReport : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TcxButton *cxButtonClose;
	TcxPageControl *cxPageControl1;
	TcxStyleRepository *cxStyleRepository1;
	TcxStyle *cxStyle1;
	TControlBar *ControlBar1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TImageList *imgStandart;
	TActionList *ActionList1;
	TAction *ActionPrint;
	TAction *ActionPreeView;
	TAction *ActionPageSetup;
	TdxComponentPrinter *dxComponentPrinter1;
	TAction *ActionExportExcel;
	TSaveDialog *SaveDialog1;
	TToolButton *ToolButton4;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBBandedTableView *cxGrid1DBBandedTableView1;
	TcxGridDBChartView *cxGrid1DBChartView1;
	TcxGridDBChartDataGroup *cxGrid1DBChartView1DataGroup1;
	TcxGridDBChartSeries *cxGrid1DBChartView1Series1;
	TcxGridLevel *cxGrid1Level1;
	TdxGridReportLink *dxComponentPrinter1Link1;
	TpFIBDataSet *ReportDataSet;
	TpFIBTransaction *pFIBTransaction1;
	TDataSource *DataSourceReport;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMEFIRM_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMESKLAD_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMENOM_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMEED_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NACHOSTKOL_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NACHOSTSUM_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1PRIHODKOL_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1PRIHODSUM_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RASHODKOL_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RASHODSUM_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CONOSTKOL_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CONOSTSUM_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1SUM2_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1DOHOD_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NACENKA_PROC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1KOL_DAY;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1KOL_SALE;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CHECK;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1SRED_SALE;
	TFloatField *ReportDataSetSRED_SALE;
	TcxStyle *cxStyle2;
	TcxStyle *cxStyle3;
	TcxStyle *cxStyle4;
	TcxStyle *cxStyle5;
	TcxStyle *cxStyle6;
	TFloatField *ReportDataSetXVATIT_NA;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1Column2;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1Column3;
	TIntegerField *ReportDataSetCHECK;
	TToolButton *ToolButtonOpenRepPoDay;
	TToolButton *ToolButton6;
	TcxStyle *cxStyle7;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDFIRM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDSKLAD;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDNOM;
	TToolButton *ToolButtonCheckAll;
	TToolButton *ToolButtonCheckClear;
	TToolButton *ToolButtonCreateDiagramm;
	TAction *ActionCheckAll;
	TAction *ActionClearAll;
	TAction *ActionShowGrafikPoday;
	TAction *ActionShowDiagramm;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMEGRP;
	TcxStyle *cxStyle8;
	TFIBWideStringField *ReportDataSetNAMEFIRM_PROC;
	TFIBLargeIntField *ReportDataSetIDFIRM_PROC;
	TFIBWideStringField *ReportDataSetNAMESKLAD_PROC;
	TFIBLargeIntField *ReportDataSetIDSKLAD_PROC;
	TFIBWideStringField *ReportDataSetNAMEGRP_PROC;
	TFIBLargeIntField *ReportDataSetIDGRP_PROC;
	TFIBWideStringField *ReportDataSetNAMENOM_PROC;
	TFIBLargeIntField *ReportDataSetIDNOM_PROC;
	TFIBWideStringField *ReportDataSetNAMEED_PROC;
	TFIBLargeIntField *ReportDataSetIDED_PROC;
	TFIBBCDField *ReportDataSetNACHOSTKOL_PROC;
	TFIBBCDField *ReportDataSetNACHOSTSUM_PROC;
	TFIBBCDField *ReportDataSetPRIHODKOL_PROC;
	TFIBBCDField *ReportDataSetPRIHODSUM_PROC;
	TFIBBCDField *ReportDataSetRASHODKOL_PROC;
	TFIBBCDField *ReportDataSetRASHODSUM_PROC;
	TFIBBCDField *ReportDataSetCONOSTKOL_PROC;
	TFIBBCDField *ReportDataSetCONOSTSUM_PROC;
	TFIBBCDField *ReportDataSetSUM2_PROC;
	TFIBBCDField *ReportDataSetDOHOD_PROC;
	TFIBBCDField *ReportDataSetNACENKA_PROC;
	TFIBIntegerField *ReportDataSetKOL_DAY;
	TFIBBCDField *ReportDataSetKOL_SALE;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall ActionPreeViewExecute(TObject *Sender);
	void __fastcall ActionPageSetupExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall ActionExportExcelExecute(TObject *Sender);
	void __fastcall ReportDataSetCalcFields(TDataSet *DataSet);
	void __fastcall ReportDataSetKOL_DAYGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
	void __fastcall ReportDataSetNACENKA_PROCGetText(TField *Sender,
          AnsiString &Text, bool DisplayText);
	void __fastcall ReportDataSetXVATIT_NAGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
	void __fastcall ActionShowGrafikPodayExecute(TObject *Sender);
	void __fastcall ActionCheckAllExecute(TObject *Sender);
	void __fastcall ActionClearAllExecute(TObject *Sender);
	void __fastcall ActionShowDiagrammExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaReport(TComponent* Owner);

		IDMFibConnection * DM_Connection;

	void UpdateForm(void);

	TDateTime PosNach;
	TDateTime PosCon;
	__int64 IdKlient;
	AnsiString NameKlient;

	TNotifyEvent FOnCloseForm;

	TFormaGrafikPoDnyam  * FormaGrafikPoDnyam;
	void OpenReportGrafikPoDnyam(void);
	void __fastcall EventCloseFormReportGrafikPoDnyam(TObject *Sender);

	TFormaChart *FormaChart;
	void OpenFormChart(void);
	void __fastcall EventCloseFormChart(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReport *FormaReport;
//---------------------------------------------------------------------------
#endif
