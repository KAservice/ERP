//---------------------------------------------------------------------------

#ifndef UREM_DMSprProducerConditionH
#define UREM_DMSprProducerConditionH
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
class TREM_DMSprProducerCondition : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Element;
	TIntegerField *TableRECNO;
	TDataSource *DataSourceElement;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_REM_SPRCONDITION;
	TFIBLargeIntField *TableIDBASE_REM_SPRCONDITION;
	TFIBWideStringField *TableGID_REM_SPRCONDITION;
	TFIBLargeIntField *TableIDPR_REM_SPRCONDITION;
	TFIBLargeIntField *TableIDGRP_REM_SPRCONDITION;
	TFIBWideStringField *TableCODE_REM_SPRCONDITION;
	TFIBWideStringField *TableNAME_REM_SPRCONDITION;
	TFIBWideStringField *TableNAME_ENG_REM_SPRCONDITION;
	TFIBLargeIntField *ElementID_REM_SPRCONDITION;
	TFIBLargeIntField *ElementIDBASE_REM_SPRCONDITION;
	TFIBWideStringField *ElementGID_REM_SPRCONDITION;
	TFIBLargeIntField *ElementIDPR_REM_SPRCONDITION;
	TFIBLargeIntField *ElementIDGRP_REM_SPRCONDITION;
	TFIBWideStringField *ElementCODE_REM_SPRCONDITION;
	TFIBWideStringField *ElementNAME_REM_SPRCONDITION;
	TFIBWideStringField *ElementNAME_ENG_REM_SPRCONDITION;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprProducerCondition(TComponent* Owner);

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

		__int64 IdGroupElement;
		__int64 IdGrp;
		bool AllElement;


		void OpenTable(__int64 id_group_element, __int64 id_grp, bool all);
		bool NewElement(__int64 id_group_element, __int64 id_grp);
		bool OpenElement(__int64 id);
		bool DeleteElement(__int64 id);
		bool SaveElement(void);
		void ChancheGrp(__int64 id_new_grp,__int64 id_element);

		__int64 FindPoCodu(__int64 id_group_element, UnicodeString code);
		__int64 FindPoName(__int64 id_group_element, UnicodeString name);
		__int64 FindPoNameEng(__int64 id_group_element, UnicodeString name);
		__int64 GetIdGrp(__int64 id_el);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprProducerCondition *REM_DMSprProducerCondition;
//---------------------------------------------------------------------------
#endif
