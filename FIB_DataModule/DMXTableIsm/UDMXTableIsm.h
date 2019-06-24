//---------------------------------------------------------------------------

#ifndef UDMXTableIsmH
#define UDMXTableIsmH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
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
class TDMXTableIsm : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *TablePOS_XTISM;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_XTISM;
	TFIBIntegerField *TableIDREC_XTISM;
	TFIBSmallIntField *TableOPERATION_XTISM;
	TFIBSmallIntField *TableTYPE_OBJECT_XTISM;
	TFIBWideStringField *TableUSER_XTISM;
	TFIBWideStringField *TableNAME_TABLE_XTISM;
	TFIBWideStringField *TableNAME_FIELD_ID_XTISM;
	TFIBBCDField *TableVALUE_FIELD_ID_XTISM;
	TFIBBCDField *TableIDBASE_XTISM;
	TFIBBCDField *TableIDEXT_BASE_XTISM;
	TFIBBCDField *ElementID_XTISM;
	TFIBDateTimeField *ElementPOS_XTISM;
	TFIBSmallIntField *ElementOPERATION_XTISM;
	TFIBSmallIntField *ElementTYPE_OBJECT_XTISM;
	TFIBWideStringField *ElementUSER_XTISM;
	TFIBWideStringField *ElementNAME_TABLE_XTISM;
	TFIBWideStringField *ElementNAME_FIELD_ID_XTISM;
	TFIBBCDField *ElementVALUE_FIELD_ID_XTISM;
	TFIBBCDField *ElementIDBASE_XTISM;
	TFIBBCDField *ElementIDEXT_BASE_XTISM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMXTableIsm(TComponent* Owner);

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


		void OpenTable(__int64 id_max);
		int OpenElement(__int64 id);
        void NewElement(void);
		void SaveElement(void);
		void DeleteElement(__int64 id);


		__int64 Id;
        bool Error;
        String TextError;



      __int64 GetMaxID(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMXTableIsm *DMXTableIsm;
//---------------------------------------------------------------------------
#endif
