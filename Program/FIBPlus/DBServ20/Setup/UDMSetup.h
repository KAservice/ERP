//---------------------------------------------------------------------------

#ifndef UDMSetupH
#define UDMSetupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <IBSQL.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMSetup : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBQuery *pFIBQKolPrDoc;
	TFIBBCDField *ElementID_SETUP;
	TFIBStringField *ElementDESCRIPTION_SETUP;
	TFIBStringField *ElementVALUE_SETUP;
	TFIBBCDField *TableID_SETUP;
	TFIBStringField *TableDESCRIPTION_SETUP;
	TFIBStringField *TableVALUE_SETUP;
	TFIBStringField *TableGID_SETUP;
	TFIBStringField *ElementGID_SETUP;
	TFIBDateTimeField *TableVALUE_TIMESTAMP_SETUP;
	TFIBDateTimeField *ElementVALUE_TIMESTAMP_SETUP;
	TFIBSmallIntField *TableTYPE_VALUE_SETUP;
	TFIBSmallIntField *ElementTYPE_VALUE_SETUP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableTYPE_VALUE_SETUPGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
	void __fastcall TableTYPE_VALUE_SETUPSetText(TField *Sender,
          const AnsiString Text);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSetup(TComponent* Owner);

        void OpenTable(void);
        void SaveIsmen();
        void CancelIsmen();

		int OpenElement(__int64 Id);
        void NewElement(void);
        void SaveElement(void);
        void DeleteElement(__int64 Id);
        bool Error;
        String TextError;

        void ProveritPosled( TDateTime  posDoc);
        int  GetKolProvDoc( TDateTime  posDoc);
        bool ProveritPosZapretaRed( TDateTime  posDoc);

		void ProveritPosledHotel( TDateTime  posDoc);
		int  GetKolProvDocHotel( TDateTime  posDoc);
		bool ProveritPosZapretaRedHotel( TDateTime  posDoc);

		void ProveritPosledRemont( TDateTime  posDoc);
		int  GetKolProvDocRemont( TDateTime  posDoc);
		bool ProveritPosZapretaRedRemont( TDateTime  posDoc);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSetup *DMSetup;
//---------------------------------------------------------------------------
#endif
