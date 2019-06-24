//---------------------------------------------------------------------------

#ifndef UREM_DMSprProducerSectionH
#define UREM_DMSprProducerSectionH
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
class TREM_DMSprProducerSection : public TDataModule
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
	TFIBLargeIntField *TableID_REM_SPRSECTION;
	TFIBLargeIntField *TableIDBASE_REM_SPRSECTION;
	TFIBLargeIntField *TableIDGRP_REM_SPRSECTION;
	TFIBLargeIntField *TableIDPR_REM_SPRSECTION;
	TFIBWideStringField *TableCODE_REM_SPRSECTION;
	TFIBWideStringField *TableNAME_REM_SPRSECTION;
	TFIBWideStringField *TableNAME_ENG_REM_SPRSECTION;
	TFIBLargeIntField *ElementID_REM_SPRSECTION;
	TFIBLargeIntField *ElementIDBASE_REM_SPRSECTION;
	TFIBLargeIntField *ElementIDGRP_REM_SPRSECTION;
	TFIBLargeIntField *ElementIDPR_REM_SPRSECTION;
	TFIBWideStringField *ElementCODE_REM_SPRSECTION;
	TFIBWideStringField *ElementNAME_REM_SPRSECTION;
	TFIBWideStringField *ElementNAME_ENG_REM_SPRSECTION;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprProducerSection(TComponent* Owner);

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
extern PACKAGE TREM_DMSprProducerSection *REM_DMSprProducerSection;
//---------------------------------------------------------------------------
#endif
