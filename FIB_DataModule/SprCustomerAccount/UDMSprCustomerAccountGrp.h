//---------------------------------------------------------------------------

#ifndef UDMSprCustomerAccountGrpH
#define UDMSprCustomerAccountGrpH
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
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMSprCustomerAccountGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_CUST_ACCOUNT_GRP;
	TFIBLargeIntField *TableIDBASE_CUST_ACCOUNT_GRP;
	TFIBWideStringField *TableGID_CUST_ACCOUNT_GRP;
	TFIBLargeIntField *TableIDGRP_CUST_ACCOUNT_GRP;
	TFIBWideStringField *TableNAME_CUST_ACCOUNT_GRP;
	TFIBLargeIntField *ElementID_CUST_ACCOUNT_GRP;
	TFIBLargeIntField *ElementIDBASE_CUST_ACCOUNT_GRP;
	TFIBWideStringField *ElementGID_CUST_ACCOUNT_GRP;
	TFIBLargeIntField *ElementIDGRP_CUST_ACCOUNT_GRP;
	TFIBWideStringField *ElementNAME_CUST_ACCOUNT_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprCustomerAccountGrp(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Error;
		UnicodeString TextError;

		bool Init(void);
		int Done(void);


        void OpenTable(void);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);


		__int64 FindPoName(UnicodeString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprCustomerAccountGrp *DMSprCustomerAccountGrp;
//---------------------------------------------------------------------------
#endif
