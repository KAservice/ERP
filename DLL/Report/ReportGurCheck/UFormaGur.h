//---------------------------------------------------------------------------

#ifndef UFormaGurH
#define UFormaGurH
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
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaGur : public TForm
{
__published:	// IDE-managed Components
	TpFIBDatabase *pFIBDatabase1;
	TpFIBTransaction *pFIBTransaction1;
	TpFIBDataSet *pFIBDataSet1;
	TDataSource *DataSource1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TPanel *Panel1;
	TLabel *Label1;
	TcxDateEdit *cxDateEdit1;
	TcxDateEdit *cxDateEdit2;
	TLabel *Label2;
	TcxButton *cxButton1;
	TFIBStringField *pFIBDataSet1NAMEFIRM;
	TFIBStringField *pFIBDataSet1NAMESKLAD;
	TFIBIntegerField *pFIBDataSet1NUMDOC;
	TFIBDateTimeField *pFIBDataSet1POSDOC;
	TFIBBCDField *pFIBDataSet1OUT_IDDOC;
	TFIBBCDField *pFIBDataSet1OUT_SUM_REG;
	TFIBBCDField *pFIBDataSet1OUT_SUM_CHECK;
	TFIBBCDField *pFIBDataSet1OUT_SUM_DISCOUNT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEFIRM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMESKLAD;
	TcxGridDBColumn *cxGrid1DBTableView1NUMDOC;
	TcxGridDBColumn *cxGrid1DBTableView1POSDOC;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_SUM_REG;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_SUM_CHECK;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_SUM_DISCOUNT;
	TcxGridDBColumn *cxGrid1DBTableView1ERROR;
	TImageList *ImageList1;
	TcxStyleRepository *cxStyleRepository1;
	TcxStyle *cxStyle1;
	TIntegerField *pFIBDataSet1ERROR;
	TFloatField *pFIBDataSet1RASNOST;
	TcxGridDBColumn *cxGrid1DBTableView1RASNOST;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall pFIBDataSet1CalcFields(TDataSet *DataSet);
	void __fastcall cxGrid1DBTableView1ERRORCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaGur(TComponent* Owner);



		typedef void (*FOnCloseFormType)(void);
	FOnCloseFormType FOnCloseForm;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaGur *FormaGur;
//---------------------------------------------------------------------------
#endif
