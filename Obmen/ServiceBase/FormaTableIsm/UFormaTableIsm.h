//---------------------------------------------------------------------------

#ifndef UFormaTableIsmH
#define UFormaTableIsmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "cxCheckBox.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaTableIsm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TDBGrid *DBGridFields;
	TDBGrid *DBGridTables;
	TpFIBDataSet *Tables;
	TpFIBDataSet *Fields;
	TpFIBTransaction *pFIBTransaction1;
	TDataSource *DataSourceTables;
	TDataSource *DataSourceFields;
	TPanel *Panel1;
	TcxDateEdit *PosNach;
	TcxDateEdit *PosCon;
	TToolBar *ToolBar1;
	TToolButton *ToolButtonUpdate;
	TcxTextEdit *NameTable;
	TcxCheckBox *OnlyTablecxCheckBox;
	TcxCheckBox *OnlyUsercxCheckBox;
	TcxTextEdit *NameUser;
	TcxCheckBox *OnlyRecordcxCheckBox;
	TcxTextEdit *NumberRecord;
	TFIBBCDField *TablesID_XTISM;
	TFIBDateTimeField *TablesPOS_XTISM;
	TFIBIntegerField *TablesOPERATION_XTISM;
	TFIBIntegerField *TablesTYPE_OBJECT_XTISM;
	TFIBWideStringField *TablesUSER_XTISM;
	TFIBWideStringField *TablesNAME_TABLE_XTISM;
	TFIBWideStringField *TablesNAME_FIELD_ID_XTISM;
	TFIBBCDField *TablesVALUE_FIELD_ID_XTISM;
	TFIBBCDField *TablesIDBASE_XTISM;
	TFIBBCDField *TablesIDEXT_BASE_XTISM;
	TFIBBCDField *TablesIDEXT_DATAOUT_XTISM;
	TFIBBCDField *TablesIDEXT_DOUT_XTISM;
	TFIBBCDField *FieldsID_XTISM_FIELDS;
	TFIBBCDField *FieldsIDXTISM_XTISM_FIELDS;
	TFIBWideStringField *FieldsFIELD_NAME_XTISM_FIELDS;
	TFIBWideStringField *FieldsOLD_VALUE_XTISM_FIELDS;
	TFIBWideStringField *FieldsNEW_VALUE_XTISM_FIELDS;
	TFIBBCDField *FieldsIDBASE_XTISM_FIELDS;
	TFIBBCDField *FieldsIDEXT_DOUT_XTISM_FIELDS;
	TFIBBCDField *FieldsIDEXT_BASE_XTISM_FIELDS;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ToolButtonUpdateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaTableIsm(TComponent* Owner);



	void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaTableIsm *FormaTableIsm;
//---------------------------------------------------------------------------
#endif
