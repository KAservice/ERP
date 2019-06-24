//---------------------------------------------------------------------------

#ifndef UDMTableNumberDocH
#define UDMTableNumberDocH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"

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
class TDMTableNumberDoc : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TIntegerField *TableRECNO;
	TpFIBQuery *Query;
	TFIBBCDField *TableID_TNUM_DOC;
	TFIBBCDField *ElementID_TNUM_DOC;
	TFIBWideStringField *TableGID_TNUM_DOC;
	TFIBWideStringField *TableDOC_TNUM_DOC;
	TFIBSmallIntField *TableTYPE_TNUM_DOC;
	TFIBWideStringField *ElementGID_TNUM_DOC;
	TFIBWideStringField *ElementDOC_TNUM_DOC;
	TFIBSmallIntField *ElementTYPE_TNUM_DOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableTYPE_TNUM_DOCGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
	void __fastcall TableTYPE_TNUM_DOCSetText(TField *Sender,
          const AnsiString Text);
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TDMTableNumberDoc(TComponent* Owner);


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

		TDateTime GetPosNachNumDoc(AnsiString type_doc);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMTableNumberDoc *DMTableNumberDoc;
//---------------------------------------------------------------------------
#endif
