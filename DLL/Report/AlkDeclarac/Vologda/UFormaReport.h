//---------------------------------------------------------------------------

#ifndef UFormaReportH
#define UFormaReportH
//---------------------------------------------------------------------------
#include "USheetEditor2.h"
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
#include "cxLookAndFeels.hpp"
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
	TpFIBDataSet *ReportDataSet;
	TpFIBTransaction *pFIBTransaction1;
	TDataSource *DataSourceReport;
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
	TpFIBDataSet *SpisokFirm;
	TpFIBDataSet *SpisokSklad;
	TpFIBDataSet *SpisokGrp;
	TDataSource *DataSourceFirma;
	TDataSource *DataSourceSklad;
	TDataSource *DataSourceGrp;
	TcxLookupComboBox *NameFirmcxLookupComboBox;
	TcxLookupComboBox *NameSkladcxLookupComboBox;
	TcxLookupComboBox *NameGrpcxLookupComboBox;
	TcxDateEdit *PosNachcxDateEdit;
	TcxDateEdit *PosConcxDateEdit;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TcxButton *cxButtonRunReportPoGrp;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBBandedTableView *cxGrid1DBBandedTableView1;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OUT_NAMEPOST;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OUT_NAME_PRODUCER;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OUT_NACHOSTKOL;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OUT_PRIHODKOL;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OUT_RASHODKOL;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OUT_CONOSTKOL;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OUT_NACHOSTKOL_FISED;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OUT_PRIHODKOL_FISED;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OUT_RASHODKOL_FISED;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OUT_CONOSTKOL_FISED;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1Column1;
	TcxGridLevel *cxGrid1Level1;
	TcxGridDBTableView *cxGrid2DBTableView1;
	TcxGridLevel *cxGrid2Level1;
	TcxGrid *cxGrid2;
	TpFIBDataSet *ReportPoNom;
	TDataSource *DataSourceReportPoNom;
	TcxGridDBBandedTableView *cxGrid2DBBandedTableView1;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_NAMEPOST;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_NAME_PRODUCER;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_NAMENOM;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_NACHOSTKOL;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_PRIHODKOL;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_RASHODKOL;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_CONOSTKOL;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_NAME_BASEED;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_KF2_BASEED;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_NAME_FISED;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_KF2_FISED;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_NACHOSTKOL_FISED;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_PRIHODKOL_FISED;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_RASHODKOL_FISED;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1OUT_CONOSTKOL_FISED;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1Column1;
	TdxGridReportLink *dxComponentPrinter1Link1;
	TdxGridReportLink *dxComponentPrinter1Link2;
	TcxTabSheet *cxTabSheet3;
	TGroupBox *GroupBox1;
	TToolBar *ToolBar2;
	TToolButton *ToolButton10;
	TToolButton *AlcGrpAddToolButton;
	TToolButton *AlcGrpDeleteToolButton;
	TcxGrid *AlcGrpcxGrid;
	TcxGridDBTableView *AlcGrpcxGridDBTableView1;
	TcxGridTableView *AlcGrpcxGridTableView1;
	TcxGridColumn *AlcGrpcxGridTableView1NAME;
	TcxGridLevel *AlcGrpcxGridLevel1;
	TToolButton *AlcGrpRefreshToolButton;
	TGroupBox *TovGrpGroupBox;
	TToolBar *ToolBar3;
	TToolButton *ToolButton5;
	TToolButton *TovGrpAddToolButton;
	TToolButton *TovGrpDeleteToolButton;
	TToolButton *TovGrpSaveToolButton;
	TToolButton *TovGrpRefreshToolButton;
	TcxGrid *TovGrpcxGrid;
	TcxGridDBTableView *cxGridDBTableView1;
	TcxGridTableView *cxGridTableView1;
	TcxGridColumn *cxGridColumn1;
	TcxGridLevel *TovGrpcxGridLevel1;
	TcxGridTableView *TovGrpcxGridTableView1;
	TcxGridColumn *TovGrpcxGridTableView1NAME;
	TcxGridColumn *TovGrpcxGridTableView1ID;
	TpFIBDataSet *GrpDataSet;
	TcxLookupComboBox *cxLookupComboBox1;
	TLabel *Label6;
	TLabel *Label7;
	TcxLookupComboBox *NameKlientcxLookupComboBox;
	TpFIBDataSet *SpisokGrpKlient;
	TpFIBDataSet *SpisokKlient;
	TDataSource *DataSourceSpisokKlient;
	TDataSource *DataSourceGrpKlient;
	TpFIBDataSet *KlientDataSet;
	TGroupBox *GroupBox2;
	TToolBar *ToolBar4;
	TToolButton *ToolButton7;
	TToolButton *ProducerAddToolButton;
	TToolButton *ProducerDeleteToolButton;
	TToolButton *ProducerSaveToolButton;
	TToolButton *ProducerRefreshToolButton;
	TcxGrid *ProducercxGrid;
	TcxGridDBTableView *cxGridDBTableView2;
	TcxGridTableView *cxGridTableView2;
	TcxGridColumn *cxGridColumn2;
	TcxGridTableView *ProducercxGridTableView;
	TcxGridLevel *ProducercxGridLevel1;
	TcxGridColumn *ProducercxGridTableViewID;
	TcxGridColumn *ProducercxGridTableViewNAME;
	TGroupBox *GroupBox3;
	TToolBar *ToolBar5;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TcxGrid *PostcxGrid;
	TcxGridDBTableView *cxGridDBTableView3;
	TcxGridTableView *cxGridTableView3;
	TcxGridColumn *cxGridColumn3;
	TcxGridTableView *PostcxGridTableView;
	TcxGridLevel *PostcxGridLevel;
	TcxGridColumn *PostcxGridTableViewID;
	TcxGridColumn *PostcxGridTableViewNAME;
	TcxTabSheet *cxTabSheet4;
	TpFIBDataSet *ReportRasdel1;
	TcxGridDBTableView *Rasdel1cxGridDBTableView1;
	TcxGridLevel *Rasdel1cxGridLevel1;
	TcxGrid *Rasdel1cxGrid;
	TcxGridTableView *Rasdel1cxGridTableView1;
	TcxGridColumn *Rasdel1cxGridTableView1NAMEGRP;
	TcxGridColumn *Rasdel1cxGridTableView1NACHOST;
	TcxGridColumn *Rasdel1cxGridTableView1FISED_NACHOST;
	TcxGridColumn *Rasdel1cxGridTableView1PRIHOD;
	TcxGridColumn *Rasdel1cxGridTableView1FISED_PRIHOD;
	TcxGridColumn *Rasdel1cxGridTableView1RASHOD;
	TcxGridColumn *Rasdel1cxGridTableView1FISED_RASHOD;
	TcxGridColumn *Rasdel1cxGridTableView1CONOST;
	TcxGridColumn *Rasdel1cxGridTableView1FISED_CONOST;
	TcxButton *cxButtonCreateRasdel1;
	TcxStyle *cxStyle8;
	TcxTabSheet *cxTabSheet5;
	TcxGridDBTableView *Rasdel2cxGridDBTableView1;
	TcxGridLevel *Rasdel2cxGridLevel1;
	TcxGrid *Rasdel2cxGrid;
	TcxGridTableView *Rasdel2cxGridTableView1;
	TcxGridColumn *Rasdel2cxGridTableView1NAMEGRP;
	TcxGridColumn *Rasdel2cxGridTableView1NAME_POST;
	TcxGridColumn *Rasdel2cxGridTableView1NAME_PRODUCER;
	TcxGridColumn *Rasdel2cxGridTableView1PRIHOD;
	TcxGridColumn *Rasdel2cxGridTableView1FISED_PRIHOD;
	TcxButton *cxButtonCreateRasdel2;
	TpFIBDataSet *ReportRasdel2;
	TcxGridColumn *Rasdel2cxGridTableView1IDPOST;
	TcxGridColumn *Rasdel2cxGridTableView1IDPRODUCER;
	TcxGridColumn *Rasdel2cxGridTableView1OBL_PRODUCERPOST;
	TcxGridColumn *Rasdel2cxGridTableView1OBL_POST;
	TcxButton *cxButtonPrintRasdel2;
	TcxButton *cxButtonPrintRasdel1;
	TpFIBQuery *Query;
	TFIBLargeIntField *SpisokFirmIDFIRM;
	TFIBWideStringField *SpisokFirmNAMEFIRM;
	TFIBLargeIntField *SpisokSkladIDSKLAD;
	TFIBWideStringField *SpisokSkladNAMESKLAD;
	TFIBLargeIntField *SpisokGrpIDGN;
	TFIBWideStringField *SpisokGrpNAMEGN;
	TFIBLargeIntField *SpisokGrpKlientIDGRPKL;
	TFIBWideStringField *SpisokGrpKlientNAMEGRPKL;
	TFIBLargeIntField *SpisokKlientIDKLIENT;
	TFIBWideStringField *SpisokKlientNAMEKLIENT;
	TFIBWideStringField *GrpDataSetNAMEGN;
	TFIBWideStringField *KlientDataSetNAMEKLIENT;
	TFIBWideStringField *ReportRasdel1OUT_NAMEPOST;
	TFIBLargeIntField *ReportRasdel1OUT_IDPOST;
	TFIBWideStringField *ReportRasdel1OUT_NAME_PRODUCER;
	TFIBLargeIntField *ReportRasdel1OUT_IDPRODUCER;
	TFIBBCDField *ReportRasdel1OUT_NACHOSTKOL;
	TFIBBCDField *ReportRasdel1OUT_PRIHODKOL;
	TFIBBCDField *ReportRasdel1OUT_RASHODKOL;
	TFIBBCDField *ReportRasdel1OUT_CONOSTKOL;
	TFIBBCDField *ReportRasdel1OUT_NACHOSTKOL_FISED;
	TFIBBCDField *ReportRasdel1OUT_PRIHODKOL_FISED;
	TFIBBCDField *ReportRasdel1OUT_RASHODKOL_FISED;
	TFIBBCDField *ReportRasdel1OUT_CONOSTKOL_FISED;
	TFIBWideStringField *ReportRasdel2OUT_NAMEPOST;
	TFIBLargeIntField *ReportRasdel2OUT_IDPOST;
	TFIBWideStringField *ReportRasdel2OUT_NAME_PRODUCER;
	TFIBLargeIntField *ReportRasdel2OUT_IDPRODUCER;
	TFIBBCDField *ReportRasdel2OUT_NACHOSTKOL;
	TFIBBCDField *ReportRasdel2OUT_PRIHODKOL;
	TFIBBCDField *ReportRasdel2OUT_RASHODKOL;
	TFIBBCDField *ReportRasdel2OUT_CONOSTKOL;
	TFIBBCDField *ReportRasdel2OUT_NACHOSTKOL_FISED;
	TFIBBCDField *ReportRasdel2OUT_PRIHODKOL_FISED;
	TFIBBCDField *ReportRasdel2OUT_RASHODKOL_FISED;
	TFIBBCDField *ReportRasdel2OUT_CONOSTKOL_FISED;
	TFIBWideStringField *ReportDataSetOUT_NAMEPOST;
	TFIBLargeIntField *ReportDataSetOUT_IDPOST;
	TFIBWideStringField *ReportDataSetOUT_NAME_PRODUCER;
	TFIBLargeIntField *ReportDataSetOUT_IDPRODUCER;
	TFIBBCDField *ReportDataSetOUT_NACHOSTKOL;
	TFIBBCDField *ReportDataSetOUT_PRIHODKOL;
	TFIBBCDField *ReportDataSetOUT_RASHODKOL;
	TFIBBCDField *ReportDataSetOUT_CONOSTKOL;
	TFIBBCDField *ReportDataSetOUT_NACHOSTKOL_FISED;
	TFIBBCDField *ReportDataSetOUT_PRIHODKOL_FISED;
	TFIBBCDField *ReportDataSetOUT_RASHODKOL_FISED;
	TFIBBCDField *ReportDataSetOUT_CONOSTKOL_FISED;
	TFIBWideStringField *ReportPoNomOUT_NAMEPOST;
	TFIBLargeIntField *ReportPoNomOUT_IDPOST;
	TFIBWideStringField *ReportPoNomOUT_NAME_PRODUCER;
	TFIBLargeIntField *ReportPoNomOUT_IDPRODUCER;
	TFIBWideStringField *ReportPoNomOUT_NAMENOM;
	TFIBLargeIntField *ReportPoNomOUT_IDNOM;
	TFIBBCDField *ReportPoNomOUT_NACHOSTKOL;
	TFIBBCDField *ReportPoNomOUT_PRIHODKOL;
	TFIBBCDField *ReportPoNomOUT_RASHODKOL;
	TFIBBCDField *ReportPoNomOUT_CONOSTKOL;
	TFIBWideStringField *ReportPoNomOUT_NAME_BASEED;
	TFIBBCDField *ReportPoNomOUT_KF2_BASEED;
	TFIBWideStringField *ReportPoNomOUT_NAME_FISED;
	TFIBBCDField *ReportPoNomOUT_KF2_FISED;
	TFIBBCDField *ReportPoNomOUT_NACHOSTKOL_FISED;
	TFIBBCDField *ReportPoNomOUT_PRIHODKOL_FISED;
	TFIBBCDField *ReportPoNomOUT_RASHODKOL_FISED;
	TFIBBCDField *ReportPoNomOUT_CONOSTKOL_FISED;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall ActionPreeViewExecute(TObject *Sender);
	void __fastcall ActionPageSetupExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall ActionExportExcelExecute(TObject *Sender);
	void __fastcall cxButtonRunReportPoGrpClick(TObject *Sender);
	void __fastcall AlcGrpRefreshToolButtonClick(TObject *Sender);
	void __fastcall AlcGrpAddToolButtonClick(TObject *Sender);
	void __fastcall AlcGrpDeleteToolButtonClick(TObject *Sender);
	void __fastcall TovGrpRefreshToolButtonClick(TObject *Sender);
	void __fastcall TovGrpAddToolButtonClick(TObject *Sender);
	void __fastcall TovGrpSaveToolButtonClick(TObject *Sender);
	void __fastcall TovGrpDeleteToolButtonClick(TObject *Sender);
	void __fastcall AlcGrpcxGridTableView1CellClick(TcxCustomGridTableView *Sender,
          TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
          TShiftState AShift, bool &AHandled);
	void __fastcall cxLookupComboBox1PropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall ProducerAddToolButtonClick(TObject *Sender);
	void __fastcall ProducerDeleteToolButtonClick(TObject *Sender);
	void __fastcall ProducerRefreshToolButtonClick(TObject *Sender);
	void __fastcall ProducerSaveToolButtonClick(TObject *Sender);
	void __fastcall ToolButton13Click(TObject *Sender);
	void __fastcall ToolButton9Click(TObject *Sender);
	void __fastcall ToolButton11Click(TObject *Sender);
	void __fastcall ToolButton12Click(TObject *Sender);
	void __fastcall cxButtonCreateRasdel1Click(TObject *Sender);
	void __fastcall cxButtonCreateRasdel2Click(TObject *Sender);
	void __fastcall cxButtonPrintRasdel2Click(TObject *Sender);
	void __fastcall cxButtonPrintRasdel1Click(TObject *Sender);
private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму





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
public:		// User declarations
	__fastcall TFormaReport(TComponent* Owner);



			typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//из этой формы открыта другая для выбора
		//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
		int ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);


		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReport *FormaReport;
//---------------------------------------------------------------------------
#endif
