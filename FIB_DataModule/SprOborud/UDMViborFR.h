//---------------------------------------------------------------------------

#ifndef UDMViborFRH
#define UDMViborFRH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//#include <DB.hpp>
//#include <IBCustomDataSet.hpp>
//#include <IBDatabase.hpp>
//#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDMViborFR : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TFIBBCDField *TableID_OBORUD;
	TFIBBCDField *TableIDARM_SOBORUD;
	TFIBSmallIntField *TableON_START_SOBORUD;
	TFIBWideStringField *TableNAME_OBORUD;
	TFIBWideStringField *TableCOMPNAME_OBORUD;
	TFIBWideStringField *TableCOMNAME_OBORUD;
	TFIBWideStringField *TableTYPE_OBORUD;
	TFIBWideStringField *TableMODEL_OBORUD;
	TFIBWideStringField *TableGID_SOBORUD;
	TFIBWideStringField *TableSTRPAR_SOBORUD;
	TFIBWideStringField *TableMODUL_SOBORUD;
	TFIBWideStringField *TableBAUDRATE_OBORUD;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TDMViborFR(TComponent* Owner);

		IDMFibConnection * DM_Connection;
		IkanCom * InterfaceGlobalCom;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		void OpenTable(__int64 id_arm);

        bool Error;
        String TextError;

        int IdArm;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMViborFR *DMViborFR;
//---------------------------------------------------------------------------
#endif
