//---------------------------------------------------------------------------

#ifndef UDMGurDocRecKDRH
#define UDMGurDocRecKDRH
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
class TDMGurDocRecKDR : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TFIBIntegerField *TableNUMDOC;
	TFIBDateTimeField *TablePOSDOC;
	TFIBSmallIntField *TablePRDOC;
	TFIBIntegerField *TableIDDOC;
	TFIBBCDField *TableDOHOD_DREC_KDR;
	TFIBBCDField *TableRASHOD_DREC_KDR;
	TFIBStringField *TableOPERATION_DREC_KDR;
	TFIBStringField *TableNAMEFIRM;
	TFIBStringField *TableNAME_USER;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMGurDocRecKDR(TComponent* Owner);

        void OpenTable();
        void UpdateTable(void);
        int IdDoc;
        TDateTime PosNach;
        TDateTime PosCon;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurDocRecKDR *DMGurDocRecKDR;
//---------------------------------------------------------------------------
#endif
