//---------------------------------------------------------------------------

#ifndef UDMSprCustomerUserH
#define UDMSprCustomerUserH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "IB_Services.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>



//---------------------------------------------------------------------------
class TDMSprCustomerUser : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Table;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_CUST_USER;
	TFIBLargeIntField *TableIDBASE_CUST_USER;
	TFIBWideStringField *TableGID_CUST_USER;
	TFIBLargeIntField *TableIDACCOUNT_CUST_USER;
	TFIBLargeIntField *TableIDGRP_CUST_USER;
	TFIBWideStringField *TableNAME_CUST_USER;
	TFIBWideStringField *TableLOGIN_CUST_USER;
	TFIBWideStringField *TablePASSWORD_CUST_USER;
	TFIBLargeIntField *ElementID_CUST_USER;
	TFIBLargeIntField *ElementIDBASE_CUST_USER;
	TFIBWideStringField *ElementGID_CUST_USER;
	TFIBLargeIntField *ElementIDACCOUNT_CUST_USER;
	TFIBLargeIntField *ElementIDGRP_CUST_USER;
	TFIBWideStringField *ElementNAME_CUST_USER;
	TFIBWideStringField *ElementLOGIN_CUST_USER;
	TFIBWideStringField *ElementPASSWORD_CUST_USER;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations


bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TDMSprCustomerUser(TComponent* Owner);

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
		__int64 IdGrp;
		bool AllElement;

		UnicodeString GetTextQuery(__int64 id_account,__int64 id_grp, bool all);
		void OpenTable(__int64 id_account,__int64 id_grp,bool all);
		int OpenElement(__int64 id);
		bool NewElement(__int64 id_account,__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);

		__int64 FindPoName(UnicodeString NameUser);
        __int64 FindPoPassword(UnicodeString Password);




		__int64 GetIdGrpUser(__int64 id_user);
		void ChancheGrp(__int64 id_new_grp,__int64 id_element);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprCustomerUser *DMSprCustomerUser;
//---------------------------------------------------------------------------
#endif
