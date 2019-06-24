//---------------------------------------------------------------------------

#ifndef UDMSprObmenPriceH
#define UDMSprObmenPriceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
//---------------------------------------------------------------------------
class TDMSprObmenPrice : public TDataModule
{
__published:	// IDE-managed Components
        TIBTransaction *IBTr;
        TDataSource *DataSourceTable;
        TIBDataSet *Table;
        TIntegerField *TableID_SSKLAD_OBMEN;
        TIBStringField *TableGID_SSKLAD_OBMEN;
        TIntegerField *TableIDBASE_SSKLAD_OBMEN;
        TIntegerField *TableIDSKLAD_SSKLAD_OBMEN;
        TIntegerField *TableRECNO;
        TIBStringField *TableNAMESKLAD;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall TableNewRecord(TDataSet *DataSet);
        void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprObmenPrice(TComponent* Owner);

        int IdBase;
        bool AllElement;

        void OpenTable(int id_base);
        void NewElement(int id_base);
        void DeleteElement();
        void SaveIsmen();
        void CancelIsmen();


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprObmenPrice *DMSprObmenPrice;
//---------------------------------------------------------------------------
#endif
