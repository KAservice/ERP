//---------------------------------------------------------------------------

#ifndef UDMSprCustomerMainMenuH
#define UDMSprCustomerMainMenuH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
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
//---------------------------------------------------------------------------
class TDMSprCustomerMainMenu : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_CUST_MAINMENU;
	TFIBLargeIntField *TableIDBASE_CUST_MAINMENU;
	TFIBWideStringField *TableGID_CUST_MAINMENU;
	TFIBLargeIntField *TableIDACCOUNT_CUST_MAINMENU;
	TFIBLargeIntField *TableIDGRPUSER_CUST_MAINMENU;
	TFIBLargeIntField *TableIDGRP_CUST_MAINMENU;
	TFIBWideStringField *TableNAME_CUST_MAINMENU;
	TFIBIntegerField *TableINDEX_CUST_MAINMENU;
	TFIBWideStringField *TableGUID_CUST_MAINMENU;
	TFIBWideStringField *TableGUIDMOD_CUST_MAINMENU;
	TFIBLargeIntField *TableIDMOD_CUST_MAINMENU;
	TFIBSmallIntField *TableFL_OPEN_EL_CUST_MAINMENU;
	TFIBLargeIntField *TableIDEL_CUST_MAINMENU;
	TFIBWideStringField *TableNAME_PROGRAM_MODULE;
	TFIBWideStringField *TablePROGID_PROGRAM_MODULE;
	TFIBWideStringField *TablePATCH_PROGRAM_MODULE;
	TFIBIntegerField *TableTYPEMOD_PROGRAM_MODULE;
	TFIBLargeIntField *ElementID_CUST_MAINMENU;
	TFIBLargeIntField *ElementIDBASE_CUST_MAINMENU;
	TFIBWideStringField *ElementGID_CUST_MAINMENU;
	TFIBLargeIntField *ElementIDACCOUNT_CUST_MAINMENU;
	TFIBLargeIntField *ElementIDGRPUSER_CUST_MAINMENU;
	TFIBLargeIntField *ElementIDGRP_CUST_MAINMENU;
	TFIBWideStringField *ElementNAME_CUST_MAINMENU;
	TFIBIntegerField *ElementINDEX_CUST_MAINMENU;
	TFIBWideStringField *ElementGUID_CUST_MAINMENU;
	TFIBWideStringField *ElementGUIDMOD_CUST_MAINMENU;
	TFIBLargeIntField *ElementIDMOD_CUST_MAINMENU;
	TFIBSmallIntField *ElementFL_OPEN_EL_CUST_MAINMENU;
	TFIBLargeIntField *ElementIDEL_CUST_MAINMENU;
	TFIBWideStringField *ElementNAME_PROGRAM_MODULE;
	TFIBWideStringField *ElementPROGID_PROGRAM_MODULE;
	TFIBWideStringField *ElementPATCH_PROGRAM_MODULE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprCustomerMainMenu(TComponent* Owner);

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		bool Error;
		UnicodeString TextError;

		__int64 IdAccount;
		__int64 IdGrpUser;
		__int64 IdGrp;
		bool AllElement;

		void OpenTable(__int64 id_account, __int64 id_grp_user, __int64 id_grp, bool all);
		bool SaveIsmen();
		void CancelIsmen();
		bool Table_Delete(void);
		bool Table_AppendString(__int64 id_account, __int64 id_grp_user, __int64 id_grp);

		bool NewElement(__int64 id_account, __int64 id_grp_user, __int64 id_grp);
		bool OpenElement(__int64 id);
		bool DeleteElement(__int64 id);
		bool InsertElement(__int64 id_account, __int64 id_grp_user, __int64 id_grp);
		void Element_Edit(void);
		void Element_Post(void);
		bool SaveElement(void);

		void ChancheGrp(__int64 id_new_grp);



};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprCustomerMainMenu *DMSprCustomerMainMenu;
//---------------------------------------------------------------------------
#endif
