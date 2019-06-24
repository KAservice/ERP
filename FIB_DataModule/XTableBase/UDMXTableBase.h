//---------------------------------------------------------------------------

#ifndef UDMXTableBaseH
#define UDMXTableBaseH
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
class TDMXTableBase : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBIntegerField *TableID_XTABLE_BASE;
	TFIBStringField *TableGID_XTABLE_BASE;
	TFIBStringField *TableNAMETAB_XTABLE_BASE;
	TFIBStringField *TableNAMEPK_XTABLE_BASE;
	TFIBStringField *TableNAMEGID_XTABLE_BASE;
	TFIBStringField *TableNAMEIDDOC_XTABLE_BASE;
	TIntegerField *TableRECNO;
	TFIBIntegerField *ElementID_XTABLE_BASE;
	TFIBStringField *ElementGID_XTABLE_BASE;
	TFIBStringField *ElementNAMETAB_XTABLE_BASE;
	TFIBStringField *ElementNAMEPK_XTABLE_BASE;
	TFIBStringField *ElementNAMEGID_XTABLE_BASE;
	TFIBStringField *ElementNAMEIDDOC_XTABLE_BASE;
	TFIBStringField *ElementNAMEPREFIKS_XTABLE_BASE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMXTableBase(TComponent* Owner);

        int Id;
        void OpenTable(void);
        int OpenElement(int id);
        void NewElement(void);
        void SaveElement(void);
        void DeleteElement(int id);


        bool Error;
        String TextError;

        //void AddRecordDataOut(int id_base, int id_table_ism) ;
        int GetElementPoName(String name_table);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMXTableBase *DMXTableBase;
//---------------------------------------------------------------------------
#endif
