//---------------------------------------------------------------------------

#ifndef UDMSprCustomerAccountKLientH
#define UDMSprCustomerAccountKLientH
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
class TDMSprCustomerAccountKlient : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_CUST_KLIENT;
	TFIBLargeIntField *TableIDBASE_CUST_KLIENT;
	TFIBWideStringField *TableGID_CUST_KLIENT;
	TFIBLargeIntField *TableIDACCOUNT_CUST_KLIENT;
	TFIBLargeIntField *TableIDKLIENT_CUST_KLIENT;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBLargeIntField *ElementID_CUST_KLIENT;
	TFIBLargeIntField *ElementIDBASE_CUST_KLIENT;
	TFIBWideStringField *ElementGID_CUST_KLIENT;
	TFIBLargeIntField *ElementIDACCOUNT_CUST_KLIENT;
	TFIBLargeIntField *ElementIDKLIENT_CUST_KLIENT;
	TFIBWideStringField *ElementNAMEKLIENT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprCustomerAccountKlient(TComponent* Owner);

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
        bool Error;
		UnicodeString TextError;


		bool Init(void);
		int Done(void);


		__int64 IdAccount;
		__int64 IdElement;

		void OpenTable(__int64 id_account);
		bool SaveIsmen(void);
		bool CancelIsmen(void);
		bool TableAppend(__int64 id_account);
		bool TableDelete(void);

		bool NewElement(__int64 id_account);
		int OpenElement(__int64 id );
		bool SaveElement(void);
		bool DeleteElement(__int64 id);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprCustomerAccountKlient *DMSprCustomerAccountKlient;
//---------------------------------------------------------------------------
#endif
