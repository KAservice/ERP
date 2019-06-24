//---------------------------------------------------------------------------

#ifndef UDMSRSchetH
#define UDMSRSchetH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <IBDatabase.hpp>
//---------------------------------------------------------------------------
class TDMSprRaschSchet : public TDataModule
{
__published:	// IDE-managed Components
        TIBQuery *Table;
        TIBTransaction *IBTr;
        TIBDataSet *Element;
        TDataSource *DataSourceTable;
        TDataSource *DSourceIBDSSBSchet;
        TIntegerField *ElementIDBSCHET;
        TIBStringField *ElementNAMEBSCHET;
        TIBStringField *ElementNUMBSCHET;
        TIntegerField *ElementIDBANKBSCHET;
        TIntegerField *ElementIDFIRMBSCHET;
        TIBStringField *ElementNAMEBANK;
        TIntegerField *TableIDBSCHET;
        TIBStringField *TableNAMEBSCHET;
        TIBStringField *TableNUMBSCHET;
        TIntegerField *TableIDBANKBSCHET;
        TIntegerField *TableIDFIRMBSCHET;
        TIntegerField *TableIDBANK;
        TIBStringField *TableNAMEBANK;
        TIBStringField *TableBIKBANK;
        TIBStringField *TableGORBANK;
        TIBStringField *TableKSBANK;
        TIntegerField *TableRECNO;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprRaschSchet(TComponent* Owner);


        void OpenTable();
        int IdFirm;
        int OpenElement(int Id);  //возвращает количество элементов
        void NewElement();
        void SaveElement(void);
        void DeleteElement(int Id);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprRaschSchet *DMSprRaschSchet;
//---------------------------------------------------------------------------
#endif
