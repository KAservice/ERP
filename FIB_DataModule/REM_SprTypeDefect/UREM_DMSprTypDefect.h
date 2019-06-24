//---------------------------------------------------------------------------

#ifndef UREM_DMSprTypDefectH
#define UREM_DMSprTypDefectH
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
class TREM_DMSprTypDefect : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQuery;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_REM_STYPDEFECT;
	TFIBWideStringField *TableGID_REM_STYPDEFECT;
	TFIBWideStringField *TableNAME_REM_STYPDEFECT;
	TFIBWideStringField *TableCODE_REM_STYPDEFECT;
	TFIBWideStringField *TableDESCR_REM_STYPDEFECT;
	TFIBLargeIntField *TableIDGRP_REM_STYPDEFECT;
	TFIBLargeIntField *ElementID_REM_STYPDEFECT;
	TFIBWideStringField *ElementGID_REM_STYPDEFECT;
	TFIBLargeIntField *ElementIDBASE_REM_STYPDEFECT;
	TFIBWideStringField *ElementNAME_REM_STYPDEFECT;
	TFIBWideStringField *ElementCODE_REM_STYPDEFECT;
	TFIBWideStringField *ElementDESCR_REM_STYPDEFECT;
	TFIBLargeIntField *ElementIDGRP_REM_STYPDEFECT;
	TFIBWideStringField *TableNAME_ENG_REM_STYPDEFECT;
	TFIBWideStringField *ElementNAME_ENG_REM_STYPDEFECT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprTypDefect(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);



		//Текущий интерфейс

		UnicodeString GetTextQuery(__int64 id_grp, bool all);
		void OpenTable(__int64 id_grp, bool all);
		int OpenElement(__int64 id);
		bool NewElement(__int64 id_grp);
		bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 id_new_grp, __int64 id_el);


		__int64 GetIdGrpNom(__int64 id);

		__int64 IdGrp;
		bool AllElement;

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprTypDefect *REM_DMSprTypDefect;
//---------------------------------------------------------------------------
#endif
