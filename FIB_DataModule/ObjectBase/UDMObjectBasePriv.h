//---------------------------------------------------------------------------

#ifndef UDMObjectBasePrivH
#define UDMObjectBasePrivH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


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
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
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
	TFIBLargeIntField *TableID_OBJECT_BASE_PRIV;
	TFIBLargeIntField *TableIDBASE_OBJECT_BASE_PRIV;
	TFIBLargeIntField *TableIDGRPUSER_OBJECT_BASE_PRIV;
	TFIBSmallIntField *TableINS_OBJECT_BASE_PRIV;
	TFIBSmallIntField *TableEDIT_OBJECT_BASE_PRIV;
	TFIBSmallIntField *TableDEL_OBJECT_BASE_PRIV;
	TFIBSmallIntField *TableEXEC_OBJECT_BASE_PRIV;
	TFIBIntegerField *TableNUMBER_OBJECT_BASE_PRIV;
	TFIBLargeIntField *TableIDGRP_OBJECT_BASE_PRIV;
	TFIBLargeIntField *ElementID_OBJECT_BASE_PRIV;
	TFIBLargeIntField *ElementIDBASE_OBJECT_BASE_PRIV;
	TFIBLargeIntField *ElementIDEXT_DOUT_OBJECT_BASE_PRIV;
	TFIBLargeIntField *ElementIDEXT_BASE_OBJECT_BASE_PRIV;
	TFIBLargeIntField *ElementIDGRPUSER_OBJECT_BASE_PRIV;
	TFIBSmallIntField *ElementINS_OBJECT_BASE_PRIV;
	TFIBSmallIntField *ElementEDIT_OBJECT_BASE_PRIV;
	TFIBSmallIntField *ElementDEL_OBJECT_BASE_PRIV;
	TFIBSmallIntField *ElementEXEC_OBJECT_BASE_PRIV;
	TFIBIntegerField *ElementNUMBER_OBJECT_BASE_PRIV;
	TFIBLargeIntField *ElementIDGRP_OBJECT_BASE_PRIV;
	TFIBIntegerField *TableAPPLICATION_OBJECT_BASE_PRIV;
	TFIBIntegerField *ElementAPPLICATION_OBJECT_BASE_PRIV;
	TpFIBQuery *Query;
	TFIBWideStringField *ElementGUID_OBJECT_BASE_PRIV;
	TFIBWideStringField *TableGUID_OBJECT_BASE_PRIV;
	TFIBWideStringField *TableNAME_PROGRAM_MODULE;
	TFIBWideStringField *TablePROGID_PROGRAM_MODULE;
	TFIBWideStringField *TablePATCH_PROGRAM_MODULE;
	TFIBWideStringField *ElementNAME_PROGRAM_MODULE;
	TFIBWideStringField *ElementPROGID_PROGRAM_MODULE;
	TFIBWideStringField *ElementPATCH_PROGRAM_MODULE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TDMObjectBasePriv(TComponent* Owner);

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


		__int64 IdGrpUser;
		__int64 IdGrp;
		int NumApplication;
		bool AllElement;

		void OpenTable(int application, __int64 id_grp_user, __int64 id_grp, bool all);
		bool SaveIsmen();
		void CancelIsmen();
		bool Table_Delete(void);
		bool Table_AppendString(int application, __int64 id_grp_user, __int64 id_grp);

		bool NewElement(int application, __int64 id_grp_user, __int64 id_grp);
		bool OpenElement(__int64 id);
		bool DeleteElement(__int64 id);
		bool InsertElement(int application, __int64 id_grp_user, __int64 id_grp);
		void Element_Edit(void);
		void Element_Post(void);
		bool SaveElement(void);

		void ChancheGrp(__int64 id_new_grp);


		bool GetPrivDM(int application, __int64 id_grp_user, int object);
		//application 1 обычное, 2 WEB
		bool GetPrivForm(__int64 id_grp_user, int object);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMObjectBasePriv *DMObjectBasePriv;
//---------------------------------------------------------------------------
#endif
