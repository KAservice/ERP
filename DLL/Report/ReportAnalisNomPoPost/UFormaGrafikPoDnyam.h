//---------------------------------------------------------------------------

#ifndef UFormaGrafikPoDnyamH
#define UFormaGrafikPoDnyamH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
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
#include "cxGridChartView.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBChartView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxStyles.hpp"
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
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaGrafikPoDnyam : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList1;
	TAction *ActionPrint;
	TAction *ActionPreeView;
	TAction *ActionPageSetup;
	TAction *ActionExportExcel;
	TSaveDialog *SaveDialog1;
	TImageList *imgStandart;
	TcxStyleRepository *cxStyleRepository1;
	TcxStyle *cxStyle1;
	TcxStyle *cxStyle2;
	TcxStyle *cxStyle3;
	TcxStyle *cxStyle4;
	TcxStyle *cxStyle5;
	TcxStyle *cxStyle6;
	TdxComponentPrinter *dxComponentPrinter1;
	TControlBar *ControlBar1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton4;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TPanel *Panel2;
	TcxButton *cxButtonClose;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBChartView *cxGrid1DBChartView1;
	TpFIBDataSet *ReportDataSet;
	TpFIBTransaction *pFIBTransaction1;
	TDataSource *DataSourceReport;
	TcxGridDBChartSeries *cxGrid1DBChartView1Series1;
	TcxGridDBChartSeries *cxGrid1DBChartView1Series2;
	TcxGridDBChartDataGroup *cxGrid1DBChartView1DataGroup1;
	TdxGridReportLink *dxComponentPrinter1Link1;
	TPanel *Panel1;
	TLabel *LabelNameFirm;
	TFIBDateField *ReportDataSetOUT_DATE;
	TFIBBCDField *ReportDataSetOUT_PRIHOD;
	TFIBBCDField *ReportDataSetOUT_RASHOD;
	TFIBBCDField *ReportDataSetOUT_TEC_OSTATOK;
	TFIBIntegerField *ReportDataSetOUT_KOL_DAY;
	TFIBBCDField *ReportDataSetOUT_SALE;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall ActionPreeViewExecute(TObject *Sender);
	void __fastcall ActionPageSetupExecute(TObject *Sender);
	void __fastcall ActionExportExcelExecute(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaGrafikPoDnyam(TComponent* Owner);



	void UpdateForm(void);

	TDateTime PosNach;
	TDateTime PosCon;
	__int64 IdFirm;
	__int64 IdSklad;
	__int64 IdNom;
	AnsiString NameFirm;
	AnsiString NameSklad;
	AnsiString NameNom;

	TNotifyEvent FOnCloseForm;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaGrafikPoDnyam *FormaGrafikPoDnyam;
//---------------------------------------------------------------------------
#endif
