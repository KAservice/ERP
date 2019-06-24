//---------------------------------------------------------------------------

#ifndef UFormaReportH
#define UFormaReportH
//---------------------------------------------------------------------------
#include "USheetEditor2.h"
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
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include "cxMemo.hpp"
//---------------------------------------------------------------------------
class TFormaReport : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TcxButton *cxButtonClose;
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
	TpFIBTransaction *pFIBTransaction1;
	TcxStyle *cxStyle2;
	TcxStyle *cxStyle3;
	TcxStyle *cxStyle4;
	TcxStyle *cxStyle5;
	TcxStyle *cxStyle6;
	TToolButton *ToolButtonOpenRepPoDay;
	TToolButton *ToolButton6;
	TcxStyle *cxStyle7;
	TToolButton *ToolButtonCheckAll;
	TToolButton *ToolButtonCheckClear;
	TToolButton *ToolButtonCreateDiagramm;
	TAction *ActionCheckAll;
	TAction *ActionClearAll;
	TAction *ActionShowGrafikPoday;
	TAction *ActionShowDiagramm;
	TpFIBDatabase *pFIBDatabase1;
	TcxButton *cxButtonUpdate;
	TcxStyle *cxStyle8;
	TpFIBDataSet *SprKlient;
	TDataSource *DataSourceSpr;
	TdxGridReportLink *dxComponentPrinter1Link1;
	TdxGridReportLink *dxComponentPrinter1Link2;
	TdxGridReportLink *dxComponentPrinter1Link3;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TFIBStringField *SprKlientNAMEKLIENT;
	TFIBStringField *SprKlientADRKLIENT;
	TFIBStringField *SprKlientTELKLIENT;
	TFIBStringField *SprKlientEMAIL_SKLIENT;
	TFIBIntegerField *SprKlientCODE_SDISCOUNT_CARD;
	TFIBStringField *SprKlientSHCODE_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1ADRKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1TELKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1EMAIL_SKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid1DBTableView1SHCODE_SDISCOUNT_CARD;
	TIntegerField *SprKlientRECNO;
	TFIBStringField *SprKlientKRNAME_SKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1KRNAME_SKLIENT;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall ActionPreeViewExecute(TObject *Sender);
	void __fastcall ActionPageSetupExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall ActionExportExcelExecute(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall cxButtonPrintRasdel1Click(TObject *Sender);
	void __fastcall cxButtonUpdateClick(TObject *Sender);
	void __fastcall SprKlientCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaReport(TComponent* Owner);

	void UpdateForm(void);

	TDateTime PosNach;
	TDateTime PosCon;
	__int64 IdGrp;
	AnsiString NameGrp;

		typedef void (*FOnCloseFormType)(void);
	FOnCloseFormType FOnCloseForm;



	AnsiString AlcGrpFileName;

	AnsiString DeleteSymbol(AnsiString s);
	void UpdateSpisokTovGrp(void);

	AnsiString ProducerFileName;
	void UpdateSpisokProducer(void);

	AnsiString PostFileName;
	void UpdateSpisokPost(void);

	void CreateReportRasdel1(void);
	void CreateReportRasdel2(void);

	TSheetEditor2 * prForm;
	int numCol;
	int numRow;
	TStringList * GetSpisokProducer(void);
	TStringList * GetSpisokSupplier(void);

	TStringList * GetSpisokSupplierNoVolObl(void);

	AnsiString GetNameKlient(AnsiString id);

	void OutputHeader(void);
	void OutputPunkt1(TStringList * producer_list);
	double AllPunkt2BasEd;
	double AllPunkt2FisEd;
	double AllPunkt2BasEdPoPost;
	double AllPunkt2FisEdPoPost;

    void OutputPunkt2(TStringList * supplier_list, TStringList * producer_list);
	void OutputPunkt2PoProducer(__int64 id_supplier, TStringList * producer_list);

	double AllPunkt3BasEd;
	double AllPunkt3FisEd;
	double AllPunkt3BasEdPoPost;
	double AllPunkt3FisEdPoPost;
	void OutputPunkt3(TStringList * supplier_list, TStringList * producer_list);
	void OutputPunkt3PoProducer(__int64 id_supplier, TStringList * producer_list);


	void OutputPunkt4(TStringList * supplier_list, TStringList * producer_list);

	double KolBasEd_Vol;
	double KolBasEd_NoVol;
	double KolFisEd_Vol;
	double KolFisEd_NoVol;

	double PoPost_KolBasEd_Vol;
	double PoPost_KolBasEd_NoVol;
	double PoPost_KolFisEd_Vol;
	double PoPost_KolFisEd_NoVol;

	 void OutputStringRasdel4(void);
	 void OutputZagStringRasdel4(void);
	 void OutputPodvalStringRasdel4(void);
	 AnsiString NameKlient;

	//void OutputPunkt3PoProducer(__int64 id_supplier, TStringList * producer_list);

	double VsegoKolBasEd_Vol;
	double VsegoKolBasEd_NoVol;
	double VsegoKolFisEd_Vol;
	double VsegoKolFisEd_NoVol;

	void OutputVsegoRasdel5(void);
	void OutputItogoRasdel6(void);

	void OutputPodval(void);


	void Rasdel1_OutputHeader(void);
	void Rasdel1_OutputString(int index_string);
	void Rasdel1_OutputFooter(void);

	double Rasdel1_NachOstBasEd;
	double Rasdel1_PrihodBasEd;
	double Rasdel1_RashodBasEd;
	double Rasdel1_ConOstBasEd;

	double Rasdel1_NachOstFisEd;
	double Rasdel1_PrihodFisEd;
	double Rasdel1_RashodFisEd;
	double Rasdel1_ConOstFisEd;

	void __fastcall EventCloseFormPrint(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReport *FormaReport;
//---------------------------------------------------------------------------
#endif
