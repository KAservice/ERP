//---------------------------------------------------------------------------

#ifndef UDMSprDocKlientH
#define UDMSprDocKlientH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

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
class TDMSprDocKlient : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateField *TableDATEVID_SDOCKLIENT;
	TIntegerField *TableRECNO;
	TFIBDateField *ElementDATEVID_SDOCKLIENT;
	TFIBBCDField *TableID_SDOCKLIENT;
	TFIBBCDField *TableIDKLIENT_SDOCKLIENT;
	TFIBBCDField *ElementID_SDOCKLIENT;
	TFIBBCDField *ElementIDKLIENT_SDOCKLIENT;
	TFIBWideStringField *TableNAME_SDOCKLIENT;
	TFIBWideStringField *TableSER_SDOCKLIENT;
	TFIBWideStringField *TableNUM_SDOCKLIENT;
	TFIBWideStringField *TableVID_SDOCKLIENT;
	TFIBWideStringField *TableGID_SDOCKLIENT;
	TFIBBCDField *TableIDBASE_SDOCKLIENT;
	TFIBWideStringField *ElementNAME_SDOCKLIENT;
	TFIBWideStringField *ElementSER_SDOCKLIENT;
	TFIBWideStringField *ElementNUM_SDOCKLIENT;
	TFIBWideStringField *ElementVID_SDOCKLIENT;
	TFIBWideStringField *ElementGID_SDOCKLIENT;
	TFIBBCDField *ElementIDBASE_SDOCKLIENT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprDocKlient(TComponent* Owner);


	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		void OpenTable(__int64 IdKl);
		int OpenElement(__int64 Id);  //возвращает количество элементов
		void NewElement(__int64 IdKl);
        bool SaveElement(void);
		void DeleteElement(__int64 Id);

        __int64 IdKlient;
        bool Error;
        String TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprDocKlient *DMSprDocKlient;
//---------------------------------------------------------------------------
#endif
