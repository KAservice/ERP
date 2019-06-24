//---------------------------------------------------------------------------

#ifndef UREM_DMSprTypePriceH
#define UREM_DMSprTypePriceH
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
class TREM_DMSprTypeRemont : public TDataModule
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
	TFIBStringField *TableGID_SSKLAD;
	TIntegerField *TableRECNO;
	TFIBIntegerField *ElementIDSKLAD;
	TFIBStringField *ElementNAMESKLAD;
	TFIBStringField *ElementMOLSKLAD;
	TFIBStringField *ElementADRSKLAD;
	TFIBIntegerField *ElementTSKLAD;
	TFIBStringField *ElementGID_SSKLAD;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableIDSKLAD;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TREM_DMSprTypeRemont(TComponent* Owner);




        void OpenTable(void);
        int OpenElement(int Id);
        void NewElement(void);
        bool SaveElement(void);
        void CloseElement(void);
        void DeleteElement(int Id);

        int GetIDElement(String gid);
		AnsiString GetGIDElement(int id);

        bool Error;
		AnsiString TextError;

		int GetIndexElementaPoID(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprTypeRemont *REM_DMSprTypeRemont;
//---------------------------------------------------------------------------
#endif
