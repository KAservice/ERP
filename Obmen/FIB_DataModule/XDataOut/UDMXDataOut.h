//---------------------------------------------------------------------------

#ifndef UDMXDataOutH
#define UDMXDataOutH
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
class TDMXDataOut : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableID_XDATA_OUT;
	TFIBBCDField *TableIDTISM_XDATA_OUT;
	TFIBBCDField *TableIDBASE_XDATA_OUT;
	TFIBSmallIntField *TableTYPE_XDATA_OUT;
	TFIBSmallIntField *TableRESULT_XDATA_OUT;
	TFIBBCDField *ElementID_XDATA_OUT;
	TFIBBCDField *ElementIDTISM_XDATA_OUT;
	TFIBBCDField *ElementIDBASE_XDATA_OUT;
	TFIBSmallIntField *ElementTYPE_XDATA_OUT;
	TFIBSmallIntField *ElementRESULT_XDATA_OUT;
	TIntegerField *TableRECNO;
	TFIBWideStringField *TableGID_XDATA_OUT;
	TFIBWideStringField *ElementGID_XDATA_OUT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMXDataOut(TComponent* Owner);


		void OpenTable(__int64 id_base);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_base, __int64 id_table_ism);
        bool SaveElement(void);
		void DeleteElement(__int64 id);


		__int64 Id;
	    __int64 IdBase;
		__int64 IdTableIsm;
		bool Error;
        UnicodeString TextError;

		bool AddRecordDataOut(__int64 id_base,
								__int64 id_table_ism,
								int type,
								int result) ;

		__int64 GetIdElement(__int64 id_base, __int64 id_table_ism);
		__int64 GetMaxIdTableIsm(__int64 id_base);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMXDataOut *DMXDataOut;
//---------------------------------------------------------------------------
#endif
