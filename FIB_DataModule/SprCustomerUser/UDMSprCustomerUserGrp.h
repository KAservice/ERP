//---------------------------------------------------------------------------

#ifndef UDMSprCustomerUserGrpH
#define UDMSprCustomerUserGrpH
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
class TDMSprCustomerUserGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *TableID_CUST_USER_GRP;
	TFIBLargeIntField *TableIDBASE_CUST_USER_GRP;
	TFIBWideStringField *TableGID_CUST_USER_GRP;
	TFIBLargeIntField *TableIDGRP_CUST_USER_GRP;
	TFIBLargeIntField *TableIDACCOUNT_CUST_USER_GRP;
	TFIBWideStringField *TableNAME_CUST_USER_GRP;
	TFIBLargeIntField *ElementID_CUST_USER_GRP;
	TFIBLargeIntField *ElementIDBASE_CUST_USER_GRP;
	TFIBWideStringField *ElementGID_CUST_USER_GRP;
	TFIBLargeIntField *ElementIDGRP_CUST_USER_GRP;
	TFIBLargeIntField *ElementIDACCOUNT_CUST_USER_GRP;
	TFIBWideStringField *ElementNAME_CUST_USER_GRP;
		void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations


bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprCustomerUserGrp(TComponent* Owner);


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
		int OpenElement(__int64 id);
		void NewElement(__int64 id_account, __int64 id_grp);
		bool SaveElement(void);
		void DeleteElement(__int64 id);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprCustomerUserGrp *DMSprCustomerUserGrp;
//---------------------------------------------------------------------------
#endif
