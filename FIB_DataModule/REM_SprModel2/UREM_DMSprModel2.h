//---------------------------------------------------------------------------

#ifndef UREM_DMSprModel2H
#define UREM_DMSprModel2H
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
//---------------------------------------------------------------------------
class TREM_DMSprModel2 : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourcePodr;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_REM_SMODEL2;
	TFIBWideStringField *TableGID_REM_SMODEL2;
	TFIBLargeIntField *TableIDBASE_REM_SMODEL2;
	TFIBWideStringField *TableNAME_REM_SMODEL2;
	TFIBLargeIntField *TableIDTYPEDEV_REM_SMODEL2;
	TFIBLargeIntField *TableIDMODEL_REM_SMODEL2;
	TFIBLargeIntField *TableIDGRP_REM_SMODEL2;
	TFIBWideStringField *TableSTRCODE_REM_SMODEL;
	TFIBWideStringField *TableNAME_REM_SMODEL;
	TFIBLargeIntField *ElementID_REM_SMODEL2;
	TFIBWideStringField *ElementGID_REM_SMODEL2;
	TFIBLargeIntField *ElementIDBASE_REM_SMODEL2;
	TFIBWideStringField *ElementNAME_REM_SMODEL2;
	TFIBLargeIntField *ElementIDTYPEDEV_REM_SMODEL2;
	TFIBLargeIntField *ElementIDMODEL_REM_SMODEL2;
	TFIBLargeIntField *ElementIDGRP_REM_SMODEL2;
	TFIBWideStringField *ElementSTRCODE_REM_SMODEL;
	TFIBWideStringField *ElementNAME_REM_SMODEL;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprModel2(TComponent* Owner);

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
		__int64 IdElement;
		bool AllElement;



		bool NewElement(__int64 id_group_element, __int64 id_grp);
		bool InsertElement(__int64 id_group_element, __int64 id_grp, __int64 id_model);
		bool OpenElement(__int64 id);
		bool DeleteElement(__int64 id);
		bool SaveElement(void);
		bool ChancheGrp(__int64 id_new_grp,__int64 id_element);



		bool OpenTable(__int64 id_group_element, __int64 id_grp, bool all);
		bool TableSaveIsmen(void);
		bool TableCancelIsmen(void);
		bool TableNewElement(__int64 id_group_element, __int64 id_grp);
		bool TableAppend(void);
		bool TableDelete(void);
		bool TableEdit(void);
		bool TablePost(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprModel2 *REM_DMSprModel2;
//---------------------------------------------------------------------------
#endif
