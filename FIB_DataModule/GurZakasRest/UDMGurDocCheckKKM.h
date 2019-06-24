//---------------------------------------------------------------------------

#ifndef UDMGurDocCheckKKMH
#define UDMGurDocCheckKKMH
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
class TDMGurZakRest : public TDataModule
{
__published:	// IDE-managed Components
        TIBQuery *Table;
        TIBTransaction *IBTr;
        TDataSource *DataSourceTable;
        TIntegerField *TableNUMDOC;
        TDateTimeField *TablePOSDOC;
        TSmallintField *TablePRDOC;
        TIBBCDField *TableSUMDOC;
        TIntegerField *TableIDDOC;
        TIBStringField *TableNAMEKKM;
        TIBStringField *TableNAMEFIRM;
        TIBStringField *TableNAMESKLAD;
        TIBStringField *TableNAMEKLIENT;
        TIBStringField *TableNAME_USER;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMGurZakRest(TComponent* Owner);

        void OpenTable();
        void UpdateTable(void);
        int IdDoc;
        TDateTime PosNach;
        TDateTime PosCon;

        int IdKKM;
        int NumberKL;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurZakRest *DMGurZakRest;
//---------------------------------------------------------------------------
#endif
