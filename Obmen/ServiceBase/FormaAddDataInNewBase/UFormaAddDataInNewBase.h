//---------------------------------------------------------------------------

#ifndef UFormaAddDataInNewBaseH
#define UFormaAddDataInNewBaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxTextEdit.hpp"
#include <ExtCtrls.hpp>
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookupEdit.hpp"
#include "cxMaskEdit.hpp"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxCalc.hpp"
#include <Dialogs.hpp>
#include "cxLookAndFeels.hpp"
#include "cxCheckBox.hpp"
//---------------------------------------------------------------------------
class TFormaAddDataInNewBase : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TcxTextEdit *NameServercxTextEdit;
	TcxTextEdit *FilecxTextEdit;
	TcxTextEdit *NameUsercxTextEdit;
	TcxTextEdit *PasswordUsercxTextEdit;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxLookupComboBox *NameBasecxLookupComboBox;
	TLabel *Label1;
	TpFIBDataSet *BaseList;
	TDataSource *DataSourceBaseList;
	TpFIBTransaction *pFIBTransaction1;
	TpFIBDataSet *TableTypePrice;
	TFIBBCDField *TableTypePriceID_XTPRICE_FOR_OBMEN;
	TFIBBCDField *TableTypePriceIDBASE_OBMEN_XTPRICE_FOR_OBMEN;
	TFIBBCDField *TableTypePriceIDTPRICE_XTPRICE_FOR_OBMEN;
	TMemo *Memo1;
	TpFIBQuery *Query;
	TpFIBDataSet *TableBaseForObmen;
	TpFIBQuery *QueryUpdate;
	TpFIBTransaction *pFIBTrUpdate;
	TpFIBDatabase *NewDataBase;
	TcxButton *cxButtonAddData;
	TcxCalcEdit *CodeNom1cxCalcEdit;
	TcxCalcEdit *CodeNom2cxCalcEdit;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel6;
	TcxLabel *cxLabel7;
	TcxCalcEdit *CodeEd1cxCalcEdit;
	TcxCalcEdit *CodeEd2cxCalcEdit;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel9;
	TcxCalcEdit *CodeCard1cxCalcEdit;
	TcxCalcEdit *CodeCard2cxCalcEdit;
	TcxLabel *cxLabel10;
	TpFIBDataSet *TableGenerators;
	TpFIBTransaction *NewBaseTrRead;
	TpFIBDataSet *TableConstraints;
	TcxButton *cxButtonViborFile;
	TOpenDialog *OpenDialog1;
	TpFIBDataSet *XSetupObmen;
	TFIBBCDField *XSetupObmenID_XSETUP_OBMEN;
	TFIBBCDField *XSetupObmenIDBASE_OBMEN_XSETUP_OBMEN;
	TFIBBCDField *XSetupObmenIDTISM_XSETUP_OBMEN;
	TFIBSmallIntField *XSetupObmenALLDOC_XSETUP_OBMEN;
	TFIBSmallIntField *XSetupObmenOUTNAC_XSETUP_OBMEN;
	TFIBSmallIntField *XSetupObmenOUTZPRICE_XSETUP_OBMEN;
	TFIBSmallIntField *XSetupObmenNOEDIT_XSETUP_OBMEN;
	TFIBBCDField *XSetupObmenIDBASE_XSETUP_OBMEN;
	TFIBBCDField *XSetupObmenIDEXT_DOUT_XSETUP_OBMEN;
	TFIBBCDField *XSetupObmenIDEXT_BASE_XSETUP_OBMEN;
	TFIBBCDField *XSetupObmenIDFIRST_DO_XSETUP_OBMEN;
	TFIBIntegerField *XSetupObmenOPER_XSETUP_OBMEN;
	TFIBBCDField *BaseListID_SINFBASE_OBMEN;
	TFIBWideStringField *BaseListGID_SINFBASE_OBMEN;
	TFIBWideStringField *BaseListNAME_SINFBASE_OBMEN;
	TFIBWideStringField *BaseListPREFIKS_SINFBASE_OBMEN;
	TFIBIntegerField *BaseListIDTIZM_SINFBASE_OBMEN;
	TFIBBCDField *BaseListIDBASE_SINFBASE_OBMEN;
	TFIBSmallIntField *BaseListNOACT_SINFBASE_OBMEN;
	TLabel *Label2;
	TcxButton *cxButtonDeleteConstraints;
	TFIBBCDField *TableBaseForObmenID_XBASE_FOR_OBMEN;
	TFIBBCDField *TableBaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN;
	TFIBBCDField *TableBaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN;
	TFIBBCDField *TableBaseForObmenIDBASE_XBASE_FOR_OBMEN;
	TcxCheckBox *MoveDoccxCheckBox;
	TpFIBTransaction *IBTr;
	TDataSource *DataSource1;
	TpFIBDataSet *Tables;
	TIntegerField *TablesRECNO;
	TFIBWideStringField *TablesFIELD_NAME;
	TFIBWideStringField *TablesTABLE_NAME;
	TpFIBDataSet *Fields;
	TFIBWideStringField *FieldsRDBFIELD_NAME;
	TFIBWideStringField *FieldsRDBFIELD_SOURCE;
	TFIBSmallIntField *FieldsRDBFIELD_SCALE;
	TFIBSmallIntField *FieldsRDBFIELD_TYPE;
	TFIBSmallIntField *FieldsRDBFIELD_PRECISION;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonAddDataClick(TObject *Sender);
	void __fastcall cxButtonViborFileClick(TObject *Sender);
	void __fastcall cxButtonDeleteConstraintsClick(TObject *Sender);
private:	// User declarations

	bool CheckTableForOutput(UnicodeString name_table);
	bool CheckTypeFieldLongString(UnicodeString name_domain);
	bool CheckTypeFieldBlob(UnicodeString name_domain);

	int CheckTypeTable(void);

public:		// User declarations
	__fastcall TFormaAddDataInNewBase(TComponent* Owner);

	__int64 IdBaseForObmen;

	int NumRecord;

	bool Error;
	AnsiString TextError;

	bool DeleteConstraints(void);

	bool CheckRecordForOutput(AnsiString name_table);
	bool CheckFieldForOutput(String name_field, String name_table) ;
	bool AddDataAllSpr(__int64 id_base);
	void OutputTable(AnsiString table_name);
	void OutputDoc(AnsiString table_name);

	bool SetValuesGenerator(void);
	bool SetValuesGeneratorCodeElement(void);

	bool SetPrefiksInfBase (__int64 id_base);
	bool OtklLoggir(void);
	bool VklLoggir(void);

	void SaveProtocol(AnsiString s);

	void DeleteNachData(void);
	void RunQueryDelete(AnsiString name_table);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaAddDataInNewBase *FormaAddDataInNewBase;
//---------------------------------------------------------------------------
#endif
