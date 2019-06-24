//---------------------------------------------------------------------------

#ifndef UFormaReportH
#define UFormaReportH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
#include "cxClasses.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxStyles.hpp"
#include "cxTextEdit.hpp"
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ImgList.hpp>
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxPC.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaReport : public TForm
{
__published:	// IDE-managed Components
	TpFIBDatabase *pFIBDatabase1;
	TpFIBTransaction *pFIBTransaction1;
	TpFIBDataSet *pFIBDataSet1;
	TDataSource *DataSource1;
	TPanel *Panel1;
	TLabel *Label1;
	TcxDateEdit *cxDateEdit1;
	TcxButton *cxButton1;
	TImageList *ImageList1;
	TcxStyleRepository *cxStyleRepository1;
	TcxStyle *cxStyle1;
	TFIBBCDField *pFIBDataSet1OUT_IDNOM;
	TFIBBCDField *pFIBDataSet1OUT_IDED;
	TFIBBCDField *pFIBDataSet1OUT_RPRICE;
	TFIBBCDField *pFIBDataSet1OUT_KOL_REV;
	TFIBBCDField *pFIBDataSet1OUT_KOL_RGGOODS;
	TFIBBCDField *pFIBDataSet1OUT_KOL_RASNOST;
	TFIBStringField *pFIBDataSet1OUT_NAMENOM;
	TIntegerField *pFIBDataSet1RESULT;
	TpFIBDataSet *SpisokFirm;
	TFIBBCDField *SpisokFirmIDFIRM;
	TFIBStringField *SpisokFirmNAMEFIRM;
	TDataSource *DataSourceFirma;
	TDataSource *DataSourceSklad;
	TpFIBDataSet *SpisokSklad;
	TFIBBCDField *SpisokSkladIDSKLAD;
	TFIBStringField *SpisokSkladNAMESKLAD;
	TcxLookupComboBox *NameFirmcxLookupComboBox;
	TLabel *Label3;
	TLabel *Label4;
	TcxLookupComboBox *NameSkladcxLookupComboBox;
	TpFIBDataSet *SpisokInv;
	TDataSource *DataSourceInv;
	TLabel *Label2;
	TFIBBCDField *SpisokInvID_SINV;
	TFIBStringField *SpisokInvNAME_SINV;
	TcxLookupComboBox *NameInvcxLookupComboBox;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1RES;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_RPRICE;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_KOL_REV;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_KOL_RGGOODS;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_KOL_RASNOST;
	TcxGridLevel *cxGrid1Level1;
	TIntegerField *pFIBDataSet1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TpFIBDataSet *pFIBDataSet2;
	TFIBBCDField *pFIBDataSet2OUT_IDNOM;
	TFIBStringField *pFIBDataSet2OUT_NAMENOM;
	TFIBBCDField *pFIBDataSet2OUT_IDED;
	TFIBStringField *pFIBDataSet2OUT_NAMEED;
	TFIBBCDField *pFIBDataSet2OUT_RPRICE;
	TFIBBCDField *pFIBDataSet2OUT_KOL_RGGOODS;
	TFIBBCDField *pFIBDataSet2OUT_KOL_REV;
	TFIBBCDField *pFIBDataSet2OUT_KOL_RASNOST;
	TIntegerField *pFIBDataSet2RESULT;
	TIntegerField *pFIBDataSet2RECNO;
	TDataSource *DataSource2;
	TcxGridDBTableView *cxGrid2DBTableView1;
	TcxGridLevel *cxGrid2Level1;
	TcxGrid *cxGrid2;
	TcxGridDBColumn *cxGrid2DBTableView1OUT_NAMENOM;
	TcxGridDBColumn *cxGrid2DBTableView1OUT_NAMEED;
	TcxGridDBColumn *cxGrid2DBTableView1OUT_RPRICE;
	TcxGridDBColumn *cxGrid2DBTableView1OUT_KOL_RGGOODS;
	TcxGridDBColumn *cxGrid2DBTableView1OUT_KOL_REV;
	TcxGridDBColumn *cxGrid2DBTableView1OUT_KOL_RASNOST;
	TcxGridDBColumn *cxGrid2DBTableView1RESULT;
	TcxGridDBColumn *cxGrid2DBTableView1RECNO;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall pFIBDataSet1CalcFields(TDataSet *DataSet);
	void __fastcall cxGrid1DBTableView1RESCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
	void __fastcall pFIBDataSet2CalcFields(TDataSet *DataSet);
	void __fastcall cxGrid2DBTableView1RESULTCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaReport(TComponent* Owner);



		typedef void (*FOnCloseFormType)(void);
	FOnCloseFormType FOnCloseForm;

	void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReport *FormaReport;
//---------------------------------------------------------------------------
#endif
