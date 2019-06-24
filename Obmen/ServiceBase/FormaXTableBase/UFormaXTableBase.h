//---------------------------------------------------------------------------

#ifndef UFormaXTableBaseH
#define UFormaXTableBaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
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
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtons.hpp"
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormaXTableBase : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TpFIBDataSet *Table;
	TpFIBTransaction *pFIBTransaction1;
	TDataSource *DataSourceTable;
	TIntegerField *TableRECNO;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1ID_XTABLE_BASE;
	TcxGridDBColumn *cxGrid1DBTableView1NAMETAB_XTABLE_BASE;
	TcxGridDBColumn *cxGrid1DBTableView1DESCR_XTABLE_BASE;
	TcxGridDBColumn *cxGrid1DBTableView1TYPE_OBJECT_XTABLE_BASE;
	TcxGridDBColumn *cxGrid1DBTableView1GID_XTABLE_BASE;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEPK_XTABLE_BASE;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEGID_XTABLE_BASE;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEIDDOC_XTABLE_BASE;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEPREFIKS_XTABLE_BASE;
	TcxGridDBColumn *cxGrid1DBTableView1IDBASE_XTABLE_BASE;
	TcxGridDBColumn *cxGrid1DBTableView1IDEXT_DOUT_XTABLE_BASE;
	TcxGridDBColumn *cxGrid1DBTableView1IDEXT_BASE_XTABLE_BASE;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TpFIBTransaction *pFIBTransactionUpdate;
	TcxButton *cxButtonSaveIsm;
	TcxButton *cxButtonCancel;
	TLabel *Label1;
	TFIBBCDField *TableID_XTABLE_BASE;
	TFIBWideStringField *TableNAMETAB_XTABLE_BASE;
	TFIBWideStringField *TableDESCR_XTABLE_BASE;
	TFIBSmallIntField *TableTYPE_OBJECT_XTABLE_BASE;
	TFIBWideStringField *TableGID_XTABLE_BASE;
	TFIBWideStringField *TableNAMEPK_XTABLE_BASE;
	TFIBWideStringField *TableNAMEGID_XTABLE_BASE;
	TFIBWideStringField *TableNAMEIDDOC_XTABLE_BASE;
	TFIBWideStringField *TableNAMEPREFIKS_XTABLE_BASE;
	TFIBBCDField *TableIDBASE_XTABLE_BASE;
	TFIBBCDField *TableIDEXT_DOUT_XTABLE_BASE;
	TFIBBCDField *TableIDEXT_BASE_XTABLE_BASE;
	TcxButton *cxButton1;
	TSaveDialog *SaveDialog1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall cxButtonSaveIsmClick(TObject *Sender);
	void __fastcall cxButtonCancelClick(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaXTableBase(TComponent* Owner);

	void UpdateForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaXTableBase *FormaXTableBase;
//---------------------------------------------------------------------------
#endif
