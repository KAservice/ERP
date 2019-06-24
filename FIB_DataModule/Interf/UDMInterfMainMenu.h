//---------------------------------------------------------------------------

#ifndef UDMInterfMainMenuH
#define UDMInterfMainMenuH
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
class TDMInterfMainMenu : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_INTERF_MAINMENU;
	TFIBLargeIntField *TableIDBASE_INTERF_MAINMENU;
	TFIBLargeIntField *TableIDGRP_INTERF_MAINMENU;
	TFIBWideStringField *TableNAME_INTERF_MAINMENU;
	TFIBIntegerField *TableMODUL_INTERF_MAINMENU;
	TFIBLargeIntField *TableIDGRPUSER_INTERF_MAINMENU;
	TFIBIntegerField *TableAPPLICATION_INTERF_MAINMENU;
	TFIBWideStringField *TableSHORTCUT_INTERF_MAINMENU;
	TFIBIntegerField *TableINDEX_INTERF_MAINMENU;
	TFIBWideStringField *TableNAME_SGRPUSER;
	TFIBWideStringField *TableNAME_PROGRAM_MODULE;
	TFIBWideStringField *TablePROGID_PROGRAM_MODULE;
	TFIBWideStringField *TablePATCH_PROGRAM_MODULE;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *ElementID_INTERF_MAINMENU;
	TFIBLargeIntField *ElementIDBASE_INTERF_MAINMENU;
	TFIBLargeIntField *ElementIDGRP_INTERF_MAINMENU;
	TFIBWideStringField *ElementNAME_INTERF_MAINMENU;
	TFIBIntegerField *ElementMODUL_INTERF_MAINMENU;
	TFIBLargeIntField *ElementIDGRPUSER_INTERF_MAINMENU;
	TFIBIntegerField *ElementAPPLICATION_INTERF_MAINMENU;
	TFIBWideStringField *ElementSHORTCUT_INTERF_MAINMENU;
	TFIBIntegerField *ElementINDEX_INTERF_MAINMENU;
	TFIBWideStringField *ElementNAME_PROGRAM_MODULE;
	TFIBWideStringField *ElementPROGID_PROGRAM_MODULE;
	TFIBWideStringField *ElementPATCH_PROGRAM_MODULE;
	TFIBSmallIntField *TableFL_UPD_FORM_INTERF_MAINMENU;
	TFIBSmallIntField *TableFL_NEW_DOC_INTERF_MAINMENU;
	TFIBLargeIntField *TableIDEL_INTERF_MAINMENU;
	TFIBSmallIntField *TableFL_OPEN_EL_INTERF_MAINMENU;
	TFIBSmallIntField *ElementFL_UPD_FORM_INTERF_MAINMENU;
	TFIBSmallIntField *ElementFL_NEW_DOC_INTERF_MAINMENU;
	TFIBLargeIntField *ElementIDEL_INTERF_MAINMENU;
	TFIBSmallIntField *ElementFL_OPEN_EL_INTERF_MAINMENU;
	TFIBWideStringField *TableGUIDMOD_INTERF_MAINMENU;
	TFIBIntegerField *TableTYPE_IDEL_INTERF_MAINMENU;
	TFIBWideStringField *ElementGUIDMOD_INTERF_MAINMENU;
	TFIBIntegerField *ElementTYPE_IDEL_INTERF_MAINMENU;
	TFIBLargeIntField *TableIDMOD_INTERF_MAINMENU;
	TFIBIntegerField *TableTYPEMOD_PROGRAM_MODULE;
	TFIBLargeIntField *ElementIDMOD_INTERF_MAINMENU;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMInterfMainMenu(TComponent* Owner);

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
		AnsiString TextError;

		int NumApplication;
		__int64 IdGrpUser;
		__int64 IdGrp;
		bool AllElement;

		void OpenTable(int num_application, __int64 id_grp_user, __int64 id_grp, bool all);
		bool SaveIsmen();
		void CancelIsmen();
		bool Table_Delete(void);
		bool Table_AppendString(int num_application, __int64 id_grp_user, __int64 id_grp);

		bool NewElement(int num_application, __int64 id_grp_user, __int64 id_grp);
		bool OpenElement(__int64 id);
		bool DeleteElement(__int64 id);
		bool InsertElement(int num_application, __int64 id_grp_user, __int64 id_grp);
		void Element_Edit(void);
		void Element_Post(void);
		bool SaveElement(void);

		void ChancheGrp(__int64 id_new_grp);



};
//---------------------------------------------------------------------------
extern PACKAGE TDMInterfMainMenu *DMInterfMainMenu;
//---------------------------------------------------------------------------
#endif
