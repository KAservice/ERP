//---------------------------------------------------------------------------

#ifndef UDMSprCustomerAccountH
#define UDMSprCustomerAccountH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


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
#include <DBClient.hpp>
//---------------------------------------------------------------------------
class TDMSprCustomerAccount : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_CUST_ACCOUNT;
	TFIBLargeIntField *TableIDBASE_CUST_ACCOUNT;
	TFIBWideStringField *TableGID_CUST_ACCOUNT;
	TFIBLargeIntField *TableIDGRP_CUST_ACCOUNT;
	TFIBWideStringField *TableNAME_CUST_ACCOUNT;
	TFIBWideStringField *TableDESCR_CUST_ACCOUNT;
	TFIBLargeIntField *TableIDUSER_CUST_ACCOUNT;
	TFIBWideStringField *TablePASSWORD_CUST_ACCOUNT;
	TFIBWideStringField *TableLOGIN_CUST_ACCOUNT;
	TFIBLargeIntField *ElementID_CUST_ACCOUNT;
	TFIBLargeIntField *ElementIDBASE_CUST_ACCOUNT;
	TFIBWideStringField *ElementGID_CUST_ACCOUNT;
	TFIBLargeIntField *ElementIDGRP_CUST_ACCOUNT;
	TFIBWideStringField *ElementNAME_CUST_ACCOUNT;
	TFIBWideStringField *ElementDESCR_CUST_ACCOUNT;
	TFIBLargeIntField *ElementIDUSER_CUST_ACCOUNT;
	TFIBWideStringField *ElementPASSWORD_CUST_ACCOUNT;
	TFIBWideStringField *ElementLOGIN_CUST_ACCOUNT;
	TFIBWideStringField *TableNAME_USER;
	TFIBWideStringField *TableNAME_SGRPUSER;
	TFIBLargeIntField *TableIDGRP_USER;
	TFIBWideStringField *ElementNAME_USER;
	TFIBLargeIntField *ElementIDGRP_USER;
	TFIBWideStringField *ElementNAME_SGRPUSER;
        void __fastcall DataModuleDestroy(TObject *Sender);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TDMSprCustomerAccount(TComponent* Owner);

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


		void OpenTable(__int64 id_grp, bool all);
		UnicodeString GetTextQuery(__int64 id_grp, bool all);
		int OpenElement(__int64 id );
		bool NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 id_new_grp,__int64 id_element);

		//поиск
		__int64 FindPoName(UnicodeString name);


		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;

		__int64 GetIdGrp(__int64 id_el);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprCustomerAccount *DMSprCustomerAccount;
//---------------------------------------------------------------------------
#endif
