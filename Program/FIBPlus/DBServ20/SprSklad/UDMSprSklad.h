//---------------------------------------------------------------------------

#ifndef UDMSprSkladH
#define UDMSprSkladH
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
class TDMSprSklad : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBStringField *TableNAMESKLAD;
	TFIBStringField *TableMOLSKLAD;
	TFIBStringField *TableADRSKLAD;
	TFIBIntegerField *TableTSKLAD;
	TIntegerField *TableRECNO;
	TFIBStringField *ElementNAMESKLAD;
	TFIBStringField *ElementMOLSKLAD;
	TFIBStringField *ElementADRSKLAD;
	TFIBIntegerField *ElementTSKLAD;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableIDSKLAD;
	TFIBBCDField *ElementIDSKLAD;
	TFIBStringField *TableGID_SSKLAD;
	TFIBStringField *ElementGID_SSKLAD;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprSklad(TComponent* Owner);

        bool Error;
		AnsiString TextError;

        void OpenTable(void);
		int OpenElement(__int64 Id);
        void NewElement(void);
        bool SaveElement(void);
        void CloseElement(void);
		void DeleteElement(__int64 Id);

		__int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);
		int GetIndexElementaPoID(__int64 id);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprSklad *DMSprSklad;
//---------------------------------------------------------------------------
#endif
