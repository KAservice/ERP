//---------------------------------------------------------------------------

#ifndef UDMSprOborudH
#define UDMSprOborudH
//---------------------------------------------------------------------------

#include "UDM.h"

//---------------------------------------------------------------------------
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
class TDMSprOborud : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBSmallIntField *TableON_START_SOBORUD;
	TFIBSmallIntField *ElementON_START_SOBORUD;
	TFIBBCDField *TableID_OBORUD;
	TFIBBCDField *TableIDARM_SOBORUD;
	TFIBBCDField *ElementID_OBORUD;
	TFIBBCDField *ElementIDARM_SOBORUD;
	TFIBWideStringField *TableNAME_OBORUD;
	TFIBWideStringField *TableCOMPNAME_OBORUD;
	TFIBWideStringField *TableCOMNAME_OBORUD;
	TFIBWideStringField *TableBAUDRATE_OBORUD;
	TFIBWideStringField *TableMODEL_OBORUD;
	TFIBWideStringField *TableGID_SOBORUD;
	TFIBWideStringField *TableSTRPAR_SOBORUD;
	TFIBWideStringField *TableMODUL_SOBORUD;
	TFIBBCDField *TableIDBASE_SOBORUD;
	TFIBWideStringField *ElementNAME_OBORUD;
	TFIBWideStringField *ElementCOMPNAME_OBORUD;
	TFIBWideStringField *ElementCOMNAME_OBORUD;
	TFIBWideStringField *ElementTYPE_OBORUD;
	TFIBWideStringField *ElementMODEL_OBORUD;
	TFIBWideStringField *ElementGID_SOBORUD;
	TFIBWideStringField *ElementSTRPAR_SOBORUD;
	TFIBWideStringField *ElementMODUL_SOBORUD;
	TFIBBCDField *ElementIDBASE_SOBORUD;
	TFIBWideStringField *TableTYPE_OBORUD;
	TFIBWideStringField *ElementBAUDRATE_OBORUD;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprOborud(TComponent* Owner);

		TDM * DM_Connection;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		void OpenTable(__int64 id_kkm);
		void OpenTablePoTypeOborud(__int64 id_kkm, UnicodeString type_oborud);
		int OpenElement(__int64 Id);
		void NewElement(__int64 id_kkm);
        bool SaveElement(void);
		void DeleteElement(__int64 Id);

        bool Error;
        UnicodeString TextError;

        __int64 IdKKM;
		UnicodeString GetParameter(UnicodeString parameter);
		UnicodeString GetParameterPoTable(UnicodeString parameter);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprOborud *DMSprOborud;
//---------------------------------------------------------------------------
#endif
