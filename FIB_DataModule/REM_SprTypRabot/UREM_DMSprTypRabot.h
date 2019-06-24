//---------------------------------------------------------------------------

#ifndef UREM_DMSprTypRabotH
#define UREM_DMSprTypRabotH
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
class TREM_DMSprTypRabot : public TDataModule
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
	TFIBLargeIntField *TableID_REM_STYPRABOT;
	TFIBWideStringField *TableGID_REM_STYPRABOT;
	TFIBLargeIntField *TableIDBASE_REM_STYPRABOT;
	TFIBLargeIntField *TableIDGRP_REM_STYPRABOT;
	TFIBLargeIntField *TableIDNOM_REM_STYPRABOT;
	TFIBWideStringField *TableNAME_REM_STYPRABOT;
	TFIBWideStringField *TableDESCR_REM_STYPRABOT;
	TFIBWideStringField *TableNAMENOM;
	TFIBWideStringField *TableARTNOM;
	TFIBIntegerField *TableCODENOM;
	TFIBLargeIntField *ElementID_REM_STYPRABOT;
	TFIBWideStringField *ElementGID_REM_STYPRABOT;
	TFIBLargeIntField *ElementIDBASE_REM_STYPRABOT;
	TFIBLargeIntField *ElementIDGRP_REM_STYPRABOT;
	TFIBLargeIntField *ElementIDNOM_REM_STYPRABOT;
	TFIBWideStringField *ElementNAME_REM_STYPRABOT;
	TFIBWideStringField *ElementDESCR_REM_STYPRABOT;
	TFIBWideStringField *ElementNAMENOM;
	TFIBWideStringField *ElementARTNOM;
	TFIBIntegerField *ElementCODENOM;
	TFIBWideStringField *TableNAME_ENG_REM_STYPRABOT;
	TFIBWideStringField *ElementNAME_ENG_REM_STYPRABOT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprTypRabot(TComponent* Owner);

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


		__int64 GetIdGrpTypRabot(__int64 id);
		__int64 FindPoNom(__int64 id_nom);

		__int64 IdGrp;
		bool AllElement;

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprTypRabot *REM_DMSprTypRabot;
//---------------------------------------------------------------------------
#endif
