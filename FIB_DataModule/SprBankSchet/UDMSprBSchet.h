//---------------------------------------------------------------------------

#ifndef UDMSprBSchetH
#define UDMSprBSchetH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <IBDatabase.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TDMSprBSchet : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableIDBSCHET;
	TFIBBCDField *TableIDBANKBSCHET;
	TFIBBCDField *TableIDFIRMBSCHET;
	TFIBBCDField *ElementIDBSCHET;
	TFIBBCDField *ElementIDBANKBSCHET;
	TFIBBCDField *ElementIDFIRMBSCHET;
	TFIBBCDField *ElementIDBANK;
	TFIBWideStringField *TableNAMEBSCHET;
	TFIBWideStringField *TableNUMBSCHET;
	TFIBWideStringField *TableGID_SBSCHET;
	TFIBWideStringField *TableNAMEBANK;
	TFIBWideStringField *TableBIKBANK;
	TFIBWideStringField *TableGORBANK;
	TFIBWideStringField *TableKSBANK;
	TFIBWideStringField *ElementNAMEBSCHET;
	TFIBWideStringField *ElementNUMBSCHET;
	TFIBWideStringField *ElementGID_SBSCHET;
	TFIBWideStringField *ElementNAMEBANK;
	TFIBWideStringField *ElementBIKBANK;
	TFIBWideStringField *ElementGORBANK;
	TFIBWideStringField *ElementKSBANK;
	TFIBWideStringField *ElementGID_SBANK;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprBSchet(TComponent* Owner);


	IDMFibConnection * DM_Connection;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        void OpenTable();
        __int64 IdFirm;
		int OpenElement(__int64 Id);  //возвращает количество элементов
        void NewElement();
        bool SaveElement(void);
		void DeleteElement(__int64 Id);
		bool Error;
		AnsiString TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprBSchet *DMSprBSchet;
//---------------------------------------------------------------------------
#endif
