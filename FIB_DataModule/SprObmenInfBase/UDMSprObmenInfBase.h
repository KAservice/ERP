//---------------------------------------------------------------------------

#ifndef UDMSprObmenInfBaseH
#define UDMSprObmenInfBaseH
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
class TDMSprObmenInfBase : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBStringField *TableNAME_TPRICE;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_STYPEPRICE_OBMEN;
	TFIBBCDField *TableIDBASE_STYPEPRICE_OBMEN;
	TFIBBCDField *TableIDTPRICE_STYPEPRICE_OBMEN;
	TFIBStringField *TableGID_STYPEPRICE_OBMEN;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprObmenInfBase(TComponent* Owner);

		__int64 IdBase;
        bool AllElement;

		void OpenTable(__int64 id_base);
        void NewElement(__int64 id_base);
        void DeleteElement();
        void SaveIsmen();
        void CancelIsmen();
        
        bool Error;
        String TextError;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprObmenInfBase *DMSprObmenInfBase;
//---------------------------------------------------------------------------
#endif
