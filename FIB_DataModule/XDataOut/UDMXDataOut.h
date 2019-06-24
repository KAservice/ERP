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
	TFIBIntegerField *TableID_XDATA_OUT;
	TFIBStringField *TableGID_XDATA_OUT;
	TFIBIntegerField *TableIDTISM_XDATA_OUT;
	TFIBIntegerField *TableIDBASE_XDATA_OUT;
	TFIBIntegerField *TableIDMESSAGE_XDATA_OUT;
	TIntegerField *TableRECNO;
	TFIBIntegerField *ElementID_XDATA_OUT;
	TFIBStringField *ElementGID_XDATA_OUT;
	TFIBIntegerField *ElementIDTISM_XDATA_OUT;
	TFIBIntegerField *ElementIDBASE_XDATA_OUT;
	TFIBIntegerField *ElementIDMESSAGE_XDATA_OUT;
	TpFIBQuery *pFIBQ;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMXDataOut(TComponent* Owner);


        void OpenTable(int id_base);
        int OpenElement(int id);
        void NewElement(int id_base, int id_table_ism);
        void SaveElement(void);
        void DeleteElement(int id);


        int Id;
        int IdBase;
        int IdTableIsm;
        bool Error;
        String TextError;

        void AddRecordDataOut(int id_base, int id_table_ism, int id_message) ;
        int GetIdElement(int id_base, int id_table_ism);
        int GetMaxIdTableIsm(int id_base);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMXDataOut *DMXDataOut;
//---------------------------------------------------------------------------
#endif
