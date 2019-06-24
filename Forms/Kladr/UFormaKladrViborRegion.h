//---------------------------------------------------------------------------

#ifndef UFormaKladrViborRegionH
#define UFormaKladrViborRegionH
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
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaKladrViborRegion : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TDataSource *DataSource1;
	TcxButton *cxButtonClose;
	TADODataSet *Table;
	TStringField *TableNAME;
	TStringField *TableSOCR;
	TStringField *TableCODE;
	TStringField *TableINDEX;
	TStringField *TableGNINMB;
	TStringField *TableUNO;
	TStringField *TableOCATD;
	TStringField *TableSTATUS;
	TcxGridDBColumn *cxGrid1DBTableView1NAME;
	TcxGridDBColumn *cxGrid1DBTableView1SOCR;
	TcxGridDBColumn *cxGrid1DBTableView1CODE;
	TcxGridDBColumn *cxGrid1DBTableView1INDEX;
	TcxGridDBColumn *cxGrid1DBTableView1GNINMB;
	TcxGridDBColumn *cxGrid1DBTableView1UNO;
	TcxGridDBColumn *cxGrid1DBTableView1OCATD;
	TcxGridDBColumn *cxGrid1DBTableView1STATUS;
	TIntegerField *TableRECNO;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxLabel *NameObjectcxLabel;
	TADODataSet *ADODataSet1;
	TStringField *ADODataSet1CODE;
	TActionList *ActionList;
	TAction *ActionClose;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall cxGrid1DBTableView1CellDblClick(TcxCustomGridTableView *Sender,
          TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
          TShiftState AShift, bool &AHandled);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaKladrViborRegion(TComponent* Owner);

	void UpdateForm(void);
	TNotifyEvent FOnCloseForm;

	bool OutReady;

	void OpenTableRegion(void);
	void OpenTableRayon(void);
	void OpenTableGorod(void);
	void OpenTableNasPunkt(void);

	int Object;//1-регионы, 2-районы, 3-города, 4-населенные пункты.

	UnicodeString NameRegion;
	UnicodeString NameRayon;
	UnicodeString NameGorod;
	UnicodeString NameNasPunkt;

	UnicodeString GetCodeObjectPoName(void);
	
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaKladrViborRegion *FormaKladrViborRegion;
//---------------------------------------------------------------------------
#endif
