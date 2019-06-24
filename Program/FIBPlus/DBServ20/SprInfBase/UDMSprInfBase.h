//---------------------------------------------------------------------------

#ifndef UDMSprInfBaseH
#define UDMSprInfBaseH
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
class TDMSprInfBase : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBStringField *TableNAME_SINFBASE_OBMEN;
	TIntegerField *TableRECNO;
	TFIBStringField *ElementNAME_SINFBASE_OBMEN;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableID_SINFBASE_OBMEN;
	TFIBIntegerField *TableIDTIZM_SINFBASE_OBMEN;
	TFIBBCDField *ElementID_SINFBASE_OBMEN;
	TFIBIntegerField *ElementIDTIZM_SINFBASE_OBMEN;
	TFIBStringField *TableGID_SINFBASE_OBMEN;
	TpFIBDataSet *BaseForObmen;
	TFIBBCDField *TableID_SBASE_FOR_OBMEN;
	TFIBBCDField *TableIDBASE_SBASE_FOR_OBMEN;
	TFIBBCDField *TableIDBASEROD_SBASE_FOR_OBMEN;
	TFIBBCDField *TableIDBASEOBMEN_SBASE_FOR_OBMEN;
	TFIBStringField *FIBStringField1;
	TIntegerField *IntegerField1;
	TDataSource *DataSourceBaseForObmen;
	TFIBStringField *ElementGID_SINFBASE_OBMEN;
	TFIBSmallIntField *ElementNOACT_SINFBASE_OBMEN;
	TFIBSmallIntField *TableNOACT_SINFBASE_OBMEN;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprInfBase(TComponent* Owner);

        __int64 Id;
        bool Error;
		String TextError;

		__int64 GetIdPoPrefiks(AnsiString prefiks);
        __int64 GetIdPoName(AnsiString name);

        void OpenTable(void);
		int  OpenElement(__int64 id);
        void NewElement(void);
        bool SaveElement(void);
		void DeleteElement(__int64 id);



};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprInfBase *DMSprInfBase;
//---------------------------------------------------------------------------
#endif
