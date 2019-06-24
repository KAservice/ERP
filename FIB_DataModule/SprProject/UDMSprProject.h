//---------------------------------------------------------------------------

#ifndef UDMSprProjectH
#define UDMSprProjectH
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
class TDMSprProject : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *TableID_SPROJECT;
	TFIBBCDField *TableIDGRP_SPROJECT;
	TFIBBCDField *ElementID_SPROJECT;
	TFIBBCDField *ElementIDGRP_SPROJECT;
	TFIBIntegerField *ElementCODE_SPROJECT;
	TpFIBDataSet *Code;
	TFIBIntegerField *CodeMAXCODE;
	TFIBIntegerField *TableCODE_SPROJECT;
	TFIBWideStringField *TableNAME_SPROJECT;
	TFIBWideStringField *ElementNAME_SPROJECT;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprProject(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


		AnsiString GetTextQuery(__int64 id_grp, bool all) ;
		void OpenTable(__int64 id_grp, bool all);
		int OpenElement(__int64 id );
		bool NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 new_id_grp);

		//поиск
		__int64 FindPoCodu(int code);
		__int64 FindPoName(AnsiString name);

		__int64 IdGrp;
		bool AllElement;
		__int64 IdElement;

        bool Error;
        String TextError;

		__int64 GetIdGrpProject(__int64 id_project);

		int GetCodeProject(void);   //код генерируется только в центарльной базе
		bool CheckCode(__int64 id_project, int code);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprProject *DMSprProject;
//---------------------------------------------------------------------------
#endif
