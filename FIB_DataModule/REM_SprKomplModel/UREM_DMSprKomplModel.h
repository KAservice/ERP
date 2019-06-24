//---------------------------------------------------------------------------

#ifndef UREM_DMSprKomplModelH
#define UREM_DMSprKomplModelH
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
class TREM_DMSprKomplModel : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_REM_SKOMPLMODEL;
	TFIBWideStringField *TableGID_REM_SKOMPLMODEL;
	TFIBLargeIntField *TableIDMODEL_REM_SKOMPLMODEL;
	TFIBWideStringField *TableNAME_REM_SKOMPLMODEL;
	TFIBBCDField *TableKOL_REM_SKOMPLMODEL;
	TFIBSmallIntField *TableNEISP_REM_SKOMPLMODEL;
	TFIBSmallIntField *TableOSN_REM_SKOMPLMODEL;
	TFIBLargeIntField *TableIDBASE_REM_SKOMPLMODEL;
	TFIBLargeIntField *ElementID_REM_SKOMPLMODEL;
	TFIBWideStringField *ElementGID_REM_SKOMPLMODEL;
	TFIBLargeIntField *ElementIDMODEL_REM_SKOMPLMODEL;
	TFIBWideStringField *ElementNAME_REM_SKOMPLMODEL;
	TFIBBCDField *ElementKOL_REM_SKOMPLMODEL;
	TFIBSmallIntField *ElementNEISP_REM_SKOMPLMODEL;
	TFIBSmallIntField *ElementOSN_REM_SKOMPLMODEL;
	TFIBLargeIntField *ElementIDBASE_REM_SKOMPLMODEL;
	TFIBLargeIntField *TableIDTYPUSLA_REM_SKOMPLMODEL;
	TFIBWideStringField *TablePARTNUM_REM_SKOMPLMODEL;
	TFIBWideStringField *TableDESCR_REM_SKOMPLMODEL;
	TFIBLargeIntField *TableIDNOM_REM_SKOMPLMODEL;
	TFIBLargeIntField *TableIDPRNOM_REM_SKOMPLMODEL;
	TFIBWideStringField *TableNAME_REM_STYPUSLOV;
	TFIBIntegerField *TableCODENOM;
	TFIBWideStringField *TableARTNOM;
	TFIBWideStringField *TableNAMENOM;
	TFIBIntegerField *TableCODE_SPRNOM;
	TFIBWideStringField *TableART_SPRNOM;
	TFIBWideStringField *TableNAME_SPRNOM;
	TFIBLargeIntField *ElementIDTYPUSLA_REM_SKOMPLMODEL;
	TFIBWideStringField *ElementPARTNUM_REM_SKOMPLMODEL;
	TFIBWideStringField *ElementDESCR_REM_SKOMPLMODEL;
	TFIBLargeIntField *ElementIDNOM_REM_SKOMPLMODEL;
	TFIBLargeIntField *ElementIDPRNOM_REM_SKOMPLMODEL;
	TFIBWideStringField *ElementNAME_REM_STYPUSLOV;
	TFIBIntegerField *ElementCODENOM;
	TFIBWideStringField *ElementARTNOM;
	TFIBWideStringField *ElementNAMENOM;
	TFIBIntegerField *ElementCODE_SPRNOM;
	TFIBWideStringField *ElementART_SPRNOM;
	TFIBWideStringField *ElementNAME_SPRNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TREM_DMSprKomplModel(TComponent* Owner);

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

		void OpenTable(__int64 id_model);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_model);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
        __int64 GetIDElement(String gid);
		UnicodeString GetGIDElement(__int64 id);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprKomplModel *REM_DMSprKomplModel;
//---------------------------------------------------------------------------
#endif
