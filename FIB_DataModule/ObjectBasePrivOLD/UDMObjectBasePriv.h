//---------------------------------------------------------------------------

#ifndef UDMObjectBasePrivH
#define UDMObjectBasePrivH
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
class TDMObjectBasePriv : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Element;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_INTERF_MAINMENU;
	TFIBBCDField *TableIDBASE_INTERF_MAINMENU;
	TFIBBCDField *TableIDGRP_INTERF_MAINMENU;
	TFIBBCDField *TableIDGRPUSER_INTERF_MAINMENU;
	TFIBBCDField *ElementID_INTERF_MAINMENU;
	TFIBBCDField *ElementIDBASE_INTERF_MAINMENU;
	TFIBBCDField *ElementIDGRP_INTERF_MAINMENU;
	TFIBBCDField *ElementIDGRPUSER_INTERF_MAINMENU;
	TFIBWideStringField *TableNAME_INTERF_MAINMENU;
	TFIBIntegerField *TableMODUL_INTERF_MAINMENU;
	TFIBIntegerField *TableAPPLICATION_INTERF_MAINMENU;
	TFIBWideStringField *TableNAME_SGRPUSER;
	TFIBWideStringField *ElementNAME_INTERF_MAINMENU;
	TFIBIntegerField *ElementMODUL_INTERF_MAINMENU;
	TFIBIntegerField *ElementAPPLICATION_INTERF_MAINMENU;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMObjectBasePriv(TComponent* Owner);
		
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
extern PACKAGE TDMObjectBasePriv *DMObjectBasePriv;
//---------------------------------------------------------------------------
#endif
