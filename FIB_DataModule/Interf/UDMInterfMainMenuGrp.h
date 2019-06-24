//---------------------------------------------------------------------------

#ifndef UDMInterfMainMenuGrpH
#define UDMInterfMainMenuGrpH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <Classes.hpp>
#include <DB.hpp>


//----------------------------------------------------------------------------

//---------------------------------------------------------------------------
class TDMInterfMainMenuGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *MenuTable;
	TFIBLargeIntField *TableID_INTERF_MAINMENU_GRP;
	TFIBLargeIntField *TableIDBASE_INTERF_MAINMENU_GRP;
	TFIBIntegerField *TableAPPLICATION_INTERF_MAINMENU_GRP;
	TFIBLargeIntField *TableIDGRPUSER_INTERF_MAINMENU_GRP;
	TFIBWideStringField *TableNAME_INTERF_MAINMENU_GRP;
	TFIBLargeIntField *TableIDGRP_INTERF_MAINMENU_GRP;
	TFIBIntegerField *TableINDEX_INTERF_MAINMENU_GRP;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *ElementID_INTERF_MAINMENU_GRP;
	TFIBLargeIntField *ElementIDBASE_INTERF_MAINMENU_GRP;
	TFIBIntegerField *ElementAPPLICATION_INTERF_MAINMENU_GRP;
	TFIBLargeIntField *ElementIDGRPUSER_INTERF_MAINMENU_GRP;
	TFIBWideStringField *ElementNAME_INTERF_MAINMENU_GRP;
	TFIBLargeIntField *ElementIDGRP_INTERF_MAINMENU_GRP;
	TFIBIntegerField *ElementINDEX_INTERF_MAINMENU_GRP;
	TFIBLargeIntField *MenuTableOUT_IDGRP_1;
	TFIBWideStringField *MenuTableOUT_NAMEGRP_1;
	TFIBLargeIntField *MenuTableOUT_IDGRP_2;
	TFIBWideStringField *MenuTableOUT_NAMEGRP_2;
	TFIBLargeIntField *MenuTableOUT_IDGRP_3;
	TFIBWideStringField *MenuTableOUT_NAMEGRP_3;
	TFIBLargeIntField *MenuTableOUT_IDGRP;
	TFIBLargeIntField *MenuTableID_INTERF_MAINMENU;
	TFIBLargeIntField *MenuTableIDBASE_INTERF_MAINMENU;
	TFIBLargeIntField *MenuTableIDGRP_INTERF_MAINMENU;
	TFIBWideStringField *MenuTableNAME_INTERF_MAINMENU;
	TFIBIntegerField *MenuTableMODUL_INTERF_MAINMENU;
	TFIBLargeIntField *MenuTableIDGRPUSER_INTERF_MAINMENU;
	TFIBIntegerField *MenuTableAPPLICATION_INTERF_MAINMENU;
	TFIBWideStringField *MenuTableSHORTCUT_INTERF_MAINMENU;
	TFIBIntegerField *MenuTableINDEX_INTERF_MAINMENU;
	TFIBWideStringField *MenuTableGUIDMOD_INTERF_MAINMENU;
	TFIBSmallIntField *MenuTableFL_UPD_FORM_INTERF_MAINMENU;
	TFIBSmallIntField *MenuTableFL_NEW_DOC_INTERF_MAINMENU;
	TFIBLargeIntField *MenuTableIDEL_INTERF_MAINMENU;
	TFIBSmallIntField *MenuTableFL_OPEN_EL_INTERF_MAINMENU;
	TFIBIntegerField *MenuTableTYPE_IDEL_INTERF_MAINMENU;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TDMInterfMainMenuGrp(TComponent* Owner);

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

		void OpenTable(int num_application, __int64 id_grp_user);
        void Table_First(void);
		void Table_Next(void);


		int OpenElement(__int64 id);
		void NewElement(int num_application,__int64 id_grp_user, __int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void Element_Edit(void);
		void Element_Post(void);



		__int64 IdGrpUser;
		int NumApplication;

		void OpenMenuTable(int num_application, __int64 id_grp_user);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMInterfMainMenuGrp *DMInterfMainMenuGrp;
//---------------------------------------------------------------------------
#endif
