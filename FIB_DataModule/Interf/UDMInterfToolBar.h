//---------------------------------------------------------------------------

#ifndef UDMInterfToolBarH
#define UDMInterfToolBarH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
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
class TDMInterfToolBar : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Element;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_INTERF_TOOLBAR;
	TFIBLargeIntField *TableIDBASE_INTERF_TOOLBAR;
	TFIBWideStringField *TableNAME_INTERF_TOOLBAR;
	TFIBLargeIntField *TableIDGRPUSER_INTERF_TOOLBAR;
	TFIBIntegerField *TableAPPLICATION_INTERF_TOOLBAR;
	TFIBIntegerField *TableMODUL_INTERF_TOOLBAR;
	TFIBWideStringField *TableHINT_INTERF_TOOLBAR;
	TFIBIntegerField *TableIMAGEINDEX_INTERF_TOOLBAR;
	TFIBIntegerField *TableINDEX_INTERF_TOOLBAR;
	TFIBWideStringField *TableNAME_PROGRAM_MODULE;
	TFIBWideStringField *TablePROGID_PROGRAM_MODULE;
	TFIBWideStringField *TablePATCH_PROGRAM_MODULE;
	TFIBLargeIntField *ElementID_INTERF_TOOLBAR;
	TFIBLargeIntField *ElementIDBASE_INTERF_TOOLBAR;
	TFIBWideStringField *ElementNAME_INTERF_TOOLBAR;
	TFIBLargeIntField *ElementIDGRPUSER_INTERF_TOOLBAR;
	TFIBIntegerField *ElementAPPLICATION_INTERF_TOOLBAR;
	TFIBIntegerField *ElementMODUL_INTERF_TOOLBAR;
	TFIBWideStringField *ElementHINT_INTERF_TOOLBAR;
	TFIBIntegerField *ElementIMAGEINDEX_INTERF_TOOLBAR;
	TFIBIntegerField *ElementINDEX_INTERF_TOOLBAR;
	TFIBWideStringField *ElementNAME_PROGRAM_MODULE;
	TFIBWideStringField *ElementPROGID_PROGRAM_MODULE;
	TFIBWideStringField *ElementPATCH_PROGRAM_MODULE;
	TFIBWideStringField *ElementGUIDMOD_INTERF_TOOLBAR;
	TFIBWideStringField *TableGUIDMOD_INTERF_TOOLBAR;
	TFIBLargeIntField *TableIDMOD_INTERF_TOOLBAR;
	TFIBSmallIntField *TableFL_UPD_FORM_INTERF_TOOLBAR;
	TFIBLargeIntField *TableIDEL_INTERF_TOOLBAR;
	TFIBSmallIntField *TableFL_OPEN_EL_INTERF_TOOLBAR;
	TFIBIntegerField *TableTYPE_IDEL_INTERF_TOOLBAR;
	TFIBLargeIntField *ElementIDMOD_INTERF_TOOLBAR;
	TFIBSmallIntField *ElementFL_UPD_FORM_INTERF_TOOLBAR;
	TFIBLargeIntField *ElementIDEL_INTERF_TOOLBAR;
	TFIBSmallIntField *ElementFL_OPEN_EL_INTERF_TOOLBAR;
	TFIBIntegerField *ElementTYPE_IDEL_INTERF_TOOLBAR;
	TFIBIntegerField *ElementTYPEMOD_PROGRAM_MODULE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMInterfToolBar(TComponent* Owner);

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

		int NumApplication;
		__int64 IdGrpUser;
		__int64 IdGrp;
		bool AllElement;

		void OpenTable(int num_application, __int64 id_grp_user);
		bool SaveIsmen();
		void CancelIsmen();
		bool Table_Delete(void);
		bool Table_AppendString(int num_application, __int64 id_grp_user);

		bool NewElement(int num_application, __int64 id_grp_user);
		bool OpenElement(__int64 id);
		bool DeleteElement(__int64 id);
		bool InsertElement(int num_application, __int64 id_grp_user);
		void Element_Edit(void);
		void Element_Post(void);
		bool SaveElement(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMInterfToolBar *DMInterfToolBar;
//---------------------------------------------------------------------------
#endif
