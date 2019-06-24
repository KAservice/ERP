//---------------------------------------------------------------------------

#ifndef UDMSprObmenTypeDocH
#define UDMSprObmenTypeDocH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TDMSprObmenTypeDoc : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBStringField *TableNAME_STYPEDOC_OBMEN;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_STYPEDOC_OBMEN;
	TFIBBCDField *TableIDBASE_STYPEDOC_OBMEN;
	TFIBStringField *TableGID_STYPEDOC_OBMEN;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprObmenTypeDoc(TComponent* Owner);

		__int64 IdBase;
        bool AllElement;

		void OpenTable(__int64 id_base);
        void NewElement(__int64 id_base);
        void DeleteElement();
        void SaveIsmen();
        void CancelIsmen();

        String TextError;
        bool Error;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprObmenTypeDoc *DMSprObmenTypeDoc;
//---------------------------------------------------------------------------
#endif
