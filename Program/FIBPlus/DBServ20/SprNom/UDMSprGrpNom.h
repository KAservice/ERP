//---------------------------------------------------------------------------

#ifndef UDMSprGrpNomH
#define UDMSprGrpNomH
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
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMSprGrpNom : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBStringField *TableNAMEGN;
	TIntegerField *TableRECNO;
	TFIBStringField *ElementNAMEGN;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableIDGN;
	TFIBBCDField *TableIDGRPGN;
	TFIBBCDField *ElementIDGN;
	TFIBBCDField *ElementIDGRPGN;
	TFIBStringField *TableGID_SGRPNOM;
	TFIBStringField *ElementGID_SGRPNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprGrpNom(TComponent* Owner);

        void OpenTable(void);
		int OpenElement(__int64 Id);
		void NewElement(__int64 IdGrp);
        bool SaveElement(void);
		bool DeleteElement(__int64 Id);

		__int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);
        bool Error;
		AnsiString TextError;

		__int64 FindPoName(AnsiString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprGrpNom *DMSprGrpNom;
//---------------------------------------------------------------------------
#endif
