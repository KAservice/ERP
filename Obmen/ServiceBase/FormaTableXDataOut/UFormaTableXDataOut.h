//---------------------------------------------------------------------------

#ifndef UFormaTableXDataOutH
#define UFormaTableXDataOutH
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
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
#include <DB.hpp>
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "cxCalendar.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaTableXDataOut : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TToolBar *ToolBar1;
	TToolButton *ToolButtonUpdateForm;
	TLabel *Label1;
	TpFIBDataSet *Table;
	TpFIBTransaction *pFIBTransaction1;
	TDataSource *DataSourceTable;
	TpFIBDataSet *BaseList;
	TDataSource *DataSourceBaseList;
	TcxDateEdit *NachcxDateEdit;
	TcxDateEdit *ConcxDateEdit;
	TcxLookupComboBox *NameBasecxLookupComboBox;
	TcxGridDBColumn *cxGrid1DBTableView1ID_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView1POS_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView1OPERATION_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView1TYPE_OBJECT_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView1USER_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_TABLE_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_FIELD_ID_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView1VALUE_FIELD_ID_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView1IDBASE_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView1IDEXT_BASE_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView1IDEXT_DATAOUT_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView1IDEXT_DOUT_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView1ID_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView1GID_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView1IDTISM_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView1IDBASE_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView1TYPE_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView1RESULT_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView1IDEXT_DOUT_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView1IDEXT_BASE_XDATA_OUT;
	TcxGridDBBandedTableView *cxGrid1DBBandedTableView1;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1ID_XTISM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1POS_XTISM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OPERATION_XTISM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1TYPE_OBJECT_XTISM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1USER_XTISM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_TABLE_XTISM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_FIELD_ID_XTISM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1VALUE_FIELD_ID_XTISM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDBASE_XTISM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDEXT_BASE_XTISM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDEXT_DATAOUT_XTISM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDEXT_DOUT_XTISM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1ID_XDATA_OUT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1GID_XDATA_OUT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDTISM_XDATA_OUT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDBASE_XDATA_OUT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1TYPE_XDATA_OUT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RESULT_XDATA_OUT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDEXT_DOUT_XDATA_OUT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDEXT_BASE_XDATA_OUT;
	TcxGridDBTableView *cxGrid1DBTableView2;
	TcxGridDBColumn *cxGrid1DBTableView2ID_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView2POS_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView2OPERATION_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView2TYPE_OBJECT_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView2USER_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView2NAME_TABLE_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView2NAME_FIELD_ID_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView2VALUE_FIELD_ID_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView2IDBASE_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView2IDEXT_BASE_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView2IDEXT_DATAOUT_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView2IDEXT_DOUT_XTISM;
	TcxGridDBColumn *cxGrid1DBTableView2ID_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView2GID_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView2IDTISM_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView2IDBASE_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView2TYPE_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView2RESULT_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView2IDEXT_DOUT_XDATA_OUT;
	TcxGridDBColumn *cxGrid1DBTableView2IDEXT_BASE_XDATA_OUT;
	TFIBBCDField *BaseListID_SINFBASE_OBMEN;
	TFIBWideStringField *BaseListGID_SINFBASE_OBMEN;
	TFIBWideStringField *BaseListNAME_SINFBASE_OBMEN;
	TFIBWideStringField *BaseListPREFIKS_SINFBASE_OBMEN;
	TFIBIntegerField *BaseListIDTIZM_SINFBASE_OBMEN;
	TFIBBCDField *BaseListIDBASE_SINFBASE_OBMEN;
	TFIBSmallIntField *BaseListNOACT_SINFBASE_OBMEN;
	TFIBBCDField *TableID_XTISM;
	TFIBDateTimeField *TablePOS_XTISM;
	TFIBIntegerField *TableOPERATION_XTISM;
	TFIBIntegerField *TableTYPE_OBJECT_XTISM;
	TFIBWideStringField *TableUSER_XTISM;
	TFIBWideStringField *TableNAME_TABLE_XTISM;
	TFIBWideStringField *TableNAME_FIELD_ID_XTISM;
	TFIBBCDField *TableVALUE_FIELD_ID_XTISM;
	TFIBBCDField *TableIDBASE_XTISM;
	TFIBBCDField *TableIDEXT_BASE_XTISM;
	TFIBBCDField *TableIDEXT_DATAOUT_XTISM;
	TFIBBCDField *TableIDEXT_DOUT_XTISM;
	TFIBBCDField *TableID_XDATA_OUT;
	TFIBWideStringField *TableGID_XDATA_OUT;
	TFIBBCDField *TableIDTISM_XDATA_OUT;
	TFIBBCDField *TableIDBASE_XDATA_OUT;
	TFIBSmallIntField *TableTYPE_XDATA_OUT;
	TFIBSmallIntField *TableRESULT_XDATA_OUT;
	TFIBBCDField *TableIDEXT_DOUT_XDATA_OUT;
	TFIBBCDField *TableIDEXT_BASE_XDATA_OUT;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ToolButtonUpdateFormClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaTableXDataOut(TComponent* Owner);


	void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaTableXDataOut *FormaTableXDataOut;
//---------------------------------------------------------------------------
#endif
