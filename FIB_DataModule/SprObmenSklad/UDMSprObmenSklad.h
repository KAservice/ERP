//---------------------------------------------------------------------------

#ifndef UDMSprObmenSkladH
#define UDMSprObmenSkladH
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
class TDMSprObmenSklad : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBStringField *TableNAMESKLAD;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_SSKLAD_OBMEN;
	TFIBBCDField *TableIDBASE_SSKLAD_OBMEN;
	TFIBBCDField *TableIDSKLAD_SSKLAD_OBMEN;
	TFIBStringField *TableGID_SSKLAD_OBMEN;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall Table1NewRecord(TDataSet *DataSet);
        void __fastcall Table1CalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprObmenSklad(TComponent* Owner);

		__int64 IdBase;
        bool AllElement;

		void OpenTable(__int64 id_base);
        void NewElement(__int64 id_base);
        void DeleteElement();
        void SaveIsmen();
        void CancelIsmen();

        bool Error;
        AnsiString TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprObmenSklad *DMSprObmenSklad;
//---------------------------------------------------------------------------
#endif
