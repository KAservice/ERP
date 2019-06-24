//---------------------------------------------------------------------------

#ifndef UFormaReportGridH
#define UFormaReportGridH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDMReportGrid.h"
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
//#include "cxGrid.hpp"
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
#include "cxLookAndFeels.hpp"
#include "cxGrid.hpp"
//---------------------------------------------------------------------------
class TFormaReportGrid : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TcxButton *cxButtonClose;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBBandedTableView *cxGrid1DBBandedTableView1;
	TcxGridDBChartView *cxGrid1DBChartView1;
	TcxGridDBChartDataGroup *cxGrid1DBChartView1DataGroup1;
	TcxGridDBChartSeries *cxGrid1DBChartView1Series1;
	TcxGridLevel *cxGrid1Level1;
	TcxGridDBTableView *cxGrid2DBTableView1;
	TcxGrid *cxGrid2;
	TcxGridLevel *cxGrid2Level1;
	TcxGridDBChartView *cxGrid2DBChartView1;
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
	TdxGridReportLink *dxComponentPrinter1Link1;
	TdxGridReportLink *dxComponentPrinter1Link2;
	TAction *ActionExportExcel;
	TSaveDialog *SaveDialog1;
	TToolButton *ToolButton4;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall ActionPreeViewExecute(TObject *Sender);
	void __fastcall ActionPageSetupExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall ActionExportExcelExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaReportGrid(TComponent* Owner);

	IDMFibConnection * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	TDMReportGrid * DM;

	void OpenReport(void);
	void SetTextQuery(AnsiString zapros);

	TcxGridDBBandedColumn *ADBColumn;
	TcxGridDBTableSummaryItem *SummaryItem;
	TcxGridDBTableSummaryItem  *SummaryGroup;

	void AddColumn(AnsiString field_name,
					AnsiString caption,
					int width,
					int group_index,
					bool group_sum,
					AnsiString format_group_sum,
					bool footer_sum,
					AnsiString format_footer_sum);
	void CreateSeries(AnsiString name_field, AnsiString display_text);
	void AddDataGroups(AnsiString name_field, AnsiString display_text);
	void SetCaptionReport(AnsiString text);
	void SetFontColorContentTecColumn(int style);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportGrid *FormaReportGrid;
//---------------------------------------------------------------------------
#endif
