//---------------------------------------------------------------------------

#ifndef UDMXFieldBaseH
#define UDMXFieldBaseH
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
class TDMXFieldBase : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBIntegerField *TableID_XFIELD_BASE;
	TFIBStringField *TableGID_XFIELD_BASE;
	TFIBIntegerField *TableIDTABLE_XFIELD_BASE;
	TFIBStringField *TableNAME_XFIELD_BASE;
	TFIBIntegerField *TableTYPE_XFIELD_BASE;
	TFIBStringField *TableFIELDFK_XFIELD_BASE;
	TFIBStringField *TableTABLEFK_XFIELD_BASE;
	TFIBStringField *TableGIDFK_XFIELD_BASE;
	TFIBIntegerField *TableFK_XFIELD_BASE;
	TFIBSmallIntField *TableSCALE_XFIELD_BASE;
	TIntegerField *TableRECNO;
	TFIBIntegerField *ElementID_XFIELD_BASE;
	TFIBStringField *ElementGID_XFIELD_BASE;
	TFIBIntegerField *ElementIDTABLE_XFIELD_BASE;
	TFIBStringField *ElementNAME_XFIELD_BASE;
	TFIBIntegerField *ElementTYPE_XFIELD_BASE;
	TFIBStringField *ElementFIELDFK_XFIELD_BASE;
	TFIBStringField *ElementTABLEFK_XFIELD_BASE;
	TFIBStringField *ElementGIDFK_XFIELD_BASE;
	TFIBIntegerField *ElementFK_XFIELD_BASE;
	TFIBSmallIntField *ElementSCALE_XFIELD_BASE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMXFieldBase(TComponent* Owner);

        int Id;
        int IdTable;
        void OpenTable(int id_table);
        int OpenElement(int id);
        void NewElement(int id_table);
        void SaveElement(void);
        void DeleteElement(int id);


        bool Error;
        String TextError;

        bool FindNameField(String name_field);

        //void AddRecordDataOut(int id_base, int id_table_ism) ;
        //int GetIdElement(int id_base, int id_table_ism);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMXFieldBase *DMXFieldBase;
//---------------------------------------------------------------------------
#endif
