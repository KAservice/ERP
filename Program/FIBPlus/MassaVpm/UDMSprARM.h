//---------------------------------------------------------------------------

#ifndef UDMSprARMH
#define UDMSprARMH
//---------------------------------------------------------------------------
#include "UDM.h"


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
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMSprARM : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TFIBIntegerField *TableCODE_SARM;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_SARM;
	TFIBBCDField *TableIDFIRM_SARM;
	TFIBBCDField *TableIDSKLAD_SARM;
	TFIBBCDField *TableIDPODR_SARM;
	TFIBBCDField *TableIDKKM_SARM;
	TFIBBCDField *ElementID_SARM;
	TFIBBCDField *ElementIDFIRM_SARM;
	TFIBBCDField *ElementIDSKLAD_SARM;
	TFIBBCDField *ElementIDPODR_SARM;
	TFIBBCDField *ElementIDKKM_SARM;
	TFIBBCDField *ElementIDTPRICEPOD;
	TFIBBCDField *ElementIDBASE_SARM;
	TpFIBQuery *Query;
	TFIBWideStringField *TableGID_SARM;
	TFIBWideStringField *TableNAME_SARM;
	TFIBWideStringField *TableSTRPAR_SARM;
	TFIBWideStringField *ElementGID_SARM;
	TFIBWideStringField *ElementNAME_SARM;
	TFIBIntegerField *ElementCODE_SARM;
	TFIBWideStringField *ElementSTRPAR_SARM;
	TFIBWideStringField *ElementNAMEFIRM;
	TFIBWideStringField *ElementNAMESKLAD;
	TFIBWideStringField *ElementNAMEKKM;
	TFIBWideStringField *ElementNAMEPOD;
	TFIBWideStringField *ElementNAME_SINFBASE_OBMEN;
	TFIBWideStringField *ElementNAME_TPRICE;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall Element1CalcFields(TDataSet *DataSet);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprARM(TComponent* Owner);

		TDM * DM_Connection;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        bool Error;
        AnsiString TextError;
        bool elSave;
        void OpenTable(void);
		int OpenElement(__int64 Id);
        void NewElement(void);
        bool SaveElement(void);
		void DeleteElement(__int64 Id);

        int FindPoCodu(int code);
        int FindPoName(String name);
        AnsiString GetGIDElement(__int64 id);
		AnsiString GetParameter(AnsiString parameter);
		int GetMaxCode(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprARM *DMSprARM;
//---------------------------------------------------------------------------
#endif
