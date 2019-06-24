//---------------------------------------------------------------------------

#ifndef UREM_DMSprNeisprH
#define UREM_DMSprNeisprH
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
class TREM_DMSprNeispr : public TDataModule
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
	TFIBLargeIntField *TableID_REM_SNEISPR;
	TFIBWideStringField *TableGID_REM_SNEISPR;
	TFIBLargeIntField *TableIDGRP_REM_SNEISPR;
	TFIBWideStringField *TableNAME_REM_SNEISPR;
	TFIBLargeIntField *TableIDBASE_REM_SNEISPR;
	TFIBLargeIntField *ElementID_REM_SNEISPR;
	TFIBWideStringField *ElementGID_REM_SNEISPR;
	TFIBLargeIntField *ElementIDGRP_REM_SNEISPR;
	TFIBWideStringField *ElementNAME_REM_SNEISPR;
	TFIBLargeIntField *ElementIDBASE_REM_SNEISPR;
	TFIBWideStringField *TableNAME_ENG_REM_SNEISPR;
	TFIBWideStringField *ElementNAME_ENG_REM_SNEISPR;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprNeispr(TComponent* Owner);

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
		void ChancheGrp(__int64 id_new_grp);

		__int64 GetIDElement(UnicodeString gid);
		UnicodeString GetGIDElement(__int64 id);
		__int64 GetIdGrpNom(__int64 id);

		__int64 IdGrp;
		bool AllElement;

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprNeispr *REM_DMSprNeispr;
//---------------------------------------------------------------------------
#endif
