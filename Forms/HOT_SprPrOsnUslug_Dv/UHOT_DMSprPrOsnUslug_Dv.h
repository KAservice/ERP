//---------------------------------------------------------------------------

#ifndef UHOT_DMSprPrOsnUslug_DvH
#define UHOT_DMSprPrOsnUslug_DvH
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
class THOT_DMSprPrOsnUslug_Dv : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TpFIBQuery *pFIBQ;
	TFIBIntegerField *TableID_HOT_SNF;
	TFIBStringField *TableGID_HOT_SNF;
	TFIBStringField *TableNAME_HOT_SNF;
	TFIBIntegerField *TableIDOB_HOT_SNF;
	TFIBIntegerField *TableIDCAT_HOT_SNF;
	TFIBIntegerField *TableKOLM_HOT_SNF;
	TFIBDateTimeField *TablePOSIN_HOT_SNF;
	TFIBDateTimeField *TablePOSOUT_HOT_SNF;
	TFIBStringField *TableNAME_HOT_SOBJECT;
	TFIBStringField *TableNAME_HOT_SCATNOM;
	TFIBIntegerField *ElementID_HOT_SNF;
	TFIBStringField *ElementGID_HOT_SNF;
	TFIBStringField *ElementNAME_HOT_SNF;
	TFIBIntegerField *ElementIDOB_HOT_SNF;
	TFIBIntegerField *ElementIDCAT_HOT_SNF;
	TFIBIntegerField *ElementKOLM_HOT_SNF;
	TFIBDateTimeField *ElementPOSIN_HOT_SNF;
	TFIBDateTimeField *ElementPOSOUT_HOT_SNF;
	TFIBStringField *ElementNAME_HOT_SOBJECT;
	TFIBStringField *ElementNAME_HOT_SCATNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall THOT_DMSprPrOsnUslug_Dv(TComponent* Owner);

		void OpenTable(void);
		void UpdateTable(void);

        int OpenElement(int Id);
		bool NewElement(void);
        bool SaveElement(void);
        void CloseElement(void);
        bool DeleteElement(int Id);

        bool Error;
		AnsiString TextError;

		int GetIndexElementaPoID(int id);

		
};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMSprPrOsnUslug_Dv *HOT_DMSprPrOsnUslug_Dv;
//---------------------------------------------------------------------------
#endif
