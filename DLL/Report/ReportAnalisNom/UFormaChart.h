//---------------------------------------------------------------------------

#ifndef UFormaChartH
#define UFormaChartH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
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
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
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
#include <DB.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaChart : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TcxButton *cxButtonClose;
	TdxComponentPrinter *dxComponentPrinter1;
	TcxStyleRepository *cxStyleRepository1;
	TcxStyle *cxStyle1;
	TImageList *imgStandart;
	TSaveDialog *SaveDialog1;
	TActionList *ActionList1;
	TAction *ActionPrint;
	TAction *ActionPreeView;
	TAction *ActionPageSetup;
	TAction *ActionExportExcel;
	TPanel *Panel1;
	TControlBar *ControlBar1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton4;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TcxGrid *cxGrid2;
	TcxGridLevel *cxGrid2Level1;
	TcxGridChartView *cxGrid2ChartView1;
	TcxGridChartSeries *cxGrid2ChartView1SeriesDOHOD;
	TcxGridChartDataGroup *cxGrid2ChartView1DataGroupNOM;
	TcxGridChartSeries *cxGrid2ChartView1SeriesOSTKOL;
	TcxGridChartSeries *cxGrid2ChartView1SeriesSALE_KOL_DAY;
	TdxGridReportLink *dxComponentPrinter1Link1;
	TcxGridChartDataGroup *cxGrid2ChartView1DataGroupSKLAD;
	TcxGridChartDataGroup *cxGrid2ChartView1DataGroupFIRMA;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall ActionPreeViewExecute(TObject *Sender);
	void __fastcall ActionPageSetupExecute(TObject *Sender);
	void __fastcall ActionExportExcelExecute(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaChart(TComponent* Owner);

		void UpdateForm(void);

	TNotifyEvent FOnCloseForm;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaChart *FormaChart;
//---------------------------------------------------------------------------
#endif
