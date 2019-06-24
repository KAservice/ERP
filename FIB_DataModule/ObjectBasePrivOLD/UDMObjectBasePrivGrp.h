//---------------------------------------------------------------------------

#ifndef UDMObjectBasePrivGrpH
#define UDMObjectBasePrivGrpH
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
class TDMObjectBasePrivGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_INTERF_MAINMENU_GRP;
	TFIBBCDField *TableIDBASE_INTERF_MAINMENU_GRP;
	TFIBBCDField *TableIDGRPUSER_INTERF_MAINMENU_GRP;
	TFIBBCDField *TableIDGRP_INTERF_MAINMENU_GRP;
	TFIBBCDField *ElementID_INTERF_MAINMENU_GRP;
	TFIBBCDField *ElementIDBASE_INTERF_MAINMENU_GRP;
	TFIBBCDField *ElementIDGRPUSER_INTERF_MAINMENU_GRP;
	TFIBBCDField *ElementIDGRP_INTERF_MAINMENU_GRP;
	TpFIBDataSet *MenuTable;
	TFIBBCDField *MenuTableOUT_IDGRP_1;
	TFIBBCDField *MenuTableOUT_IDGRP_2;
	TFIBBCDField *MenuTableOUT_IDGRP_3;
	TFIBIntegerField *TableAPPLICATION_INTERF_MAINMENU_GRP;
	TFIBWideStringField *TableNAME_INTERF_MAINMENU_GRP;
	TFIBIntegerField *ElementAPPLICATION_INTERF_MAINMENU_GRP;
	TFIBWideStringField *ElementNAME_INTERF_MAINMENU_GRP;
	TFIBWideStringField *MenuTableOUT_NAMEGRP_1;
	TFIBWideStringField *MenuTableOUT_NAMEGRP_2;
	TFIBWideStringField *MenuTableOUT_NAMEGRP_3;
	TFIBBCDField *MenuTableOUT_IDGRP;
	TFIBBCDField *MenuTableID_INTERF_MAINMENU;
	TFIBBCDField *MenuTableIDGRP_INTERF_MAINMENU;
	TFIBWideStringField *MenuTableNAME_INTERF_MAINMENU;
	TFIBIntegerField *MenuTableMODUL_INTERF_MAINMENU;
	TFIBBCDField *MenuTableIDGRPUSER_INTERF_MAINMENU;
	TFIBIntegerField *MenuTableAPPLICATION_INTERF_MAINMENU;
	TFIBIntegerField *ElementINDEX_INTERF_MAINMENU_GRP;
	TFIBIntegerField *TableINDEX_INTERF_MAINMENU_GRP;
	TFIBWideStringField *MenuTableSHORTCUT_INTERF_MAINMENU;
	TFIBIntegerField *MenuTableINDEX_INTERF_MAINMENU;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMObjectBasePrivGrp(TComponent* Owner);

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

		bool Error;
		AnsiString TextError;

		void OpenMenuTable(int num_application, __int64 id_grp_user);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMObjectBasePrivGrp *DMObjectBasePrivGrp;
//---------------------------------------------------------------------------
#endif
