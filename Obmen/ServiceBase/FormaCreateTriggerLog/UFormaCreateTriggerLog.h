//---------------------------------------------------------------------------

#ifndef UFormaCreateTriggerLogH
#define UFormaCreateTriggerLogH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Dialogs.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include "pFIBScripter.hpp"
//---------------------------------------------------------------------------
class TFormaCreateTriggerLog : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TPanel *Panel1;
	TDBGrid *DBGrid2;
	TPanel *Panel2;
	TDBGrid *DBGrid1;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *NameFieldEdit;
	TEdit *NameDomainEdit;
	TButton *ButtonAddField;
	TButton *ButtondelField;
	TButton *ButtonCreateStrTable;
	TDataSource *DataSource1;
	TDataSource *DataSource2;
	TRichEdit *RichEdit1;
	TGroupBox *GroupBox1;
	TButton *ButtonCreateTriggerAfterInsert;
	TButton *ButtonCreateTriggerAfterUpdate;
	TButton *ButtonCreatetriggerAfterDelete;
	TLabel *Label7;
	TTabSheet *TabSheet3;
	TGroupBox *GroupBox2;
	TButton *ButtonCreateALLTriggerAfterInsert;
	TButton *ButtonCreateALLTriggerAfterUpdate;
	TButton *ButtonCreateAllTriggerAfterDelete;
	TGroupBox *GroupBox3;
	TButton *ButtonDeleteALLTriggerAfterInsert;
	TButton *ButtonDeleteALLTriggerAfterUpdate;
	TButton *ButtonDeleteTriggerAfterDelete;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *Tables;
	TIntegerField *TablesRECNO;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TpFIBQuery *QueryUpdate;
	TpFIBDataSet *Fields;
	TpFIBScripter *IBScript1;
	TGroupBox *GroupBox4;
	TEdit *TableNameEdit;
	TButton *Button1;
	TButton *Button3;
	TButton *Button2;
	TButton *Button5;
	TButton *Button6;
	TButton *Button4;
	TLabel *Label1;
	TLabel *Label2;
	TButton *ButtonClear;
	TFIBWideStringField *TablesFIELD_NAME;
	TFIBWideStringField *TablesTABLE_NAME;
	TFIBWideStringField *FieldsRDBFIELD_NAME;
	TFIBWideStringField *FieldsRDBFIELD_SOURCE;
	TFIBSmallIntField *FieldsRDBFIELD_SCALE;
	TFIBSmallIntField *FieldsRDBFIELD_TYPE;
	TFIBSmallIntField *FieldsRDBFIELD_PRECISION;
	TButton *ButtonSetGenMaxValue;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonAddFieldClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ButtondelFieldClick(TObject *Sender);
	void __fastcall ButtonCreateStrTableClick(TObject *Sender);
	void __fastcall ButtonCreateTriggerAfterInsertClick(TObject *Sender);
	void __fastcall ButtonCreateTriggerAfterUpdateClick(TObject *Sender);
	void __fastcall ButtonCreatetriggerAfterDeleteClick(TObject *Sender);
	void __fastcall ButtonCreateALLTriggerAfterInsertClick(TObject *Sender);
	void __fastcall ButtonDeleteALLTriggerAfterInsertClick(TObject *Sender);
	void __fastcall ButtonCreateALLTriggerAfterUpdateClick(TObject *Sender);
	void __fastcall ButtonDeleteALLTriggerAfterUpdateClick(TObject *Sender);
	void __fastcall ButtonCreateAllTriggerAfterDeleteClick(TObject *Sender);
	void __fastcall ButtonDeleteTriggerAfterDeleteClick(TObject *Sender);
	void __fastcall TablesCalcFields(TDataSet *DataSet);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall ButtonSetGenMaxValueClick(TObject *Sender);
private:	// User declarations


	bool CheckTypeFieldLongString(UnicodeString name_domain);
	bool CheckTypeFieldBlob(UnicodeString name_domain);


public:		// User declarations
	__fastcall TFormaCreateTriggerLog(TComponent* Owner);

	AnsiString GetZaprosAfterInsert(AnsiString name_table, AnsiString name_field_pk) ;
	AnsiString GetZaprosAfterUpdate(AnsiString name_table, AnsiString name_field_pk) ;
	AnsiString GetZaprosAfterDelete(AnsiString name_table, AnsiString name_field_pk) ;
	int GetTypeTable(AnsiString name_table);
	bool CheckTableForGreateTrigger(AnsiString name_table);
	bool CheckFieldForGreateTrigger(AnsiString name_field);

	void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaCreateTriggerLog *FormaCreateTriggerLog;
//---------------------------------------------------------------------------
#endif
