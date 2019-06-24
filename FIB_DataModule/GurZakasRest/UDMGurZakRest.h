//---------------------------------------------------------------------------

#ifndef UDMGurZakRestH
#define UDMGurZakRestH
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
        TIntegerField *TableID_ZAK;
        TIntegerField *TableIDOB_ZAK;
        TIBBCDField *TableSUM_ZAK;
        TSmallintField *TableSOST_ZAK;
        TIntegerField *TableIDKLIENT_ZAK;
        TIntegerField *TableIDUSER_ZAK;
        TIBStringField *TableNAMEKLIENT;
        TIBStringField *TableNAME_USER;
        TIBStringField *TableNAME_STROB;
        TIntegerField *TableID_STROB;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMGurZakRest(TComponent* Owner);

        void OpenTable();
        void UpdateTable(void);
        int IdZakaz;
        bool AllUser;
        int IdUser;


};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurZakRest *DMGurZakRest;
//---------------------------------------------------------------------------
#endif
