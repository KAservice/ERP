//---------------------------------------------------------------------------

#ifndef UDMXMessageObmenH
#define UDMXMessageObmenH
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
class TDMXMessageObmen : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBIntegerField *TableOUT_XMESSAGE_OBMEN;
	TFIBIntegerField *TableKOLERR_XMESSAGE_OBMEN;
	TFIBDateTimeField *TablePOS_XMESSAGE_OBMEN;
	TFIBStringField *TableGID_SINFBASE_OBMEN;
	TFIBStringField *TableNAME_SINFBASE_OBMEN;
	TFIBStringField *TableINPATCH_SINFBASE_OBMEN;
	TFIBStringField *TableOUTPATCH_SINFBASE_OBMEN;
	TFIBStringField *TablePREFIKS_SINFBASE_OBMEN;
	TFIBStringField *TablePREFDOC_SINFBASE_OBMEN;
	TFIBIntegerField *TableALLDOC_SINFBASE_OBMEN;
	TIntegerField *TableRECNO;
	TFIBIntegerField *ElementOUT_XMESSAGE_OBMEN;
	TFIBIntegerField *ElementKOLERR_XMESSAGE_OBMEN;
	TFIBDateTimeField *ElementPOS_XMESSAGE_OBMEN;
	TpFIBDataSet *IBQ;
	TpFIBQuery *pFIBQ;
	TFIBSmallIntField *TableOUTNAC_SINFBASE_OBMEN;
	TFIBSmallIntField *TableOUTZPRICE_SINFBASE_OBMEN;
	TFIBStringField *TableGID_XMESSAGE_OBMEN;
	TFIBStringField *ElementGID_XMESSAGE_OBMEN;
	TFIBBCDField *TableID_XMESSAGE_OBMEN;
	TFIBBCDField *TableID_SINFBASE_OBMEN;
	TFIBIntegerField *TableIDTIZM_SINFBASE_OBMEN;
	TFIBBCDField *ElementID_XMESSAGE_OBMEN;
	TFIBIntegerField *TableIDBASE_XMESSAGE_OBMEN;
	TFIBBCDField *ElementIDBASE_XMESSAGE_OBMEN;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall ElementCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMXMessageObmen(TComponent* Owner);


		void OpenTable(__int64 id_base);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_base);
        void SaveElement(void);
		void DeleteElement(__int64 id);

		__int64 GetIDElement(String gid);
		__int64 Id;
		__int64 IdBase;
		__int64 IdTableIsm;
        bool Error;
        String TextError;

        TDateTime PosNach;
        TDateTime PosCon;
        int GetCountUpdateRecord(__int64 id_message);
        enum {PoDate, PoGid} Sort;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMXMessageObmen *DMXMessageObmen;
//---------------------------------------------------------------------------
#endif
