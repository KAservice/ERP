//---------------------------------------------------------------------------

#ifndef UDMSprNumTelH
#define UDMSprNumTelH
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
class TDMSprNumTel : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_NUMTEL;
	TFIBBCDField *TableIDKLIENT_NUMTEL;
	TFIBBCDField *ElementID_NUMTEL;
	TFIBBCDField *ElementIDKLIENT_NUMTEL;
	TFIBWideStringField *TableCODE_NUMTEL;
	TFIBWideStringField *TableNUMBER_NUMTEL;
	TFIBWideStringField *TableGID_SNUMTEL;
	TFIBWideStringField *ElementCODE_NUMTEL;
	TFIBWideStringField *ElementNUMBER_NUMTEL;
	TFIBWideStringField *ElementGID_SNUMTEL;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprNumTel(TComponent* Owner);

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
extern PACKAGE TDMSprNumTel *DMSprNumTel;
//---------------------------------------------------------------------------
#endif
