//---------------------------------------------------------------------------

#ifndef UDMSetupH
#define UDMSetupH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


//---------------------------------------------------------------------------
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>


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
	TFIBBCDField *TableID_SETUP;
	TFIBDateTimeField *TableVALUE_TIMESTAMP_SETUP;
	TFIBDateTimeField *ElementVALUE_TIMESTAMP_SETUP;
	TFIBSmallIntField *TableTYPE_VALUE_SETUP;
	TFIBSmallIntField *ElementTYPE_VALUE_SETUP;
	TFIBWideStringField *TableDESCRIPTION_SETUP;
	TFIBWideStringField *TableVALUE_SETUP;
	TFIBWideStringField *TableGID_SETUP;
	TFIBWideStringField *ElementDESCRIPTION_SETUP;
	TFIBWideStringField *ElementVALUE_SETUP;
	TFIBWideStringField *ElementGID_SETUP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall TableTYPE_VALUE_SETUPGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall TableTYPE_VALUE_SETUPSetText(TField *Sender, const UnicodeString Text);

private:	// User declarations
public:		// User declarations
		__fastcall TDMSetup(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


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
