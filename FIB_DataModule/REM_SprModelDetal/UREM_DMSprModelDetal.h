//---------------------------------------------------------------------------

#ifndef UREM_DMSprModelDetalH
#define UREM_DMSprModelDetalH
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
class TREM_DMSprModelDetal : public TDataModule
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
	TFIBLargeIntField *TableID_REM_SMODEL_DETAL;
	TFIBWideStringField *TableGID_REM_SMODEL_DETAL;
	TFIBLargeIntField *TableIDBASE_REM_SMODEL_DETAL;
	TFIBLargeIntField *TableIDMODEL_REM_SMODEL_DETAL;
	TFIBLargeIntField *TableIDTYPUSLA_REM_SMODEL_DETAL;
	TFIBLargeIntField *TableIDNOM_REM_SMODEL_DETAL;
	TFIBLargeIntField *TableIDPRNOM_REM_SMODEL_DETAL;
	TFIBWideStringField *TableNAME_REM_SMODEL_DETAL;
	TFIBWideStringField *TablePARTNUM_REM_SMODEL_DETAL;
	TFIBWideStringField *TableDESCR_REM_SMODEL_DETAL;
	TFIBBCDField *TableKOL_REM_SMODEL_DETAL;
	TFIBWideStringField *TableNAME_REM_STYPUSLOV;
	TFIBIntegerField *TableCODENOM;
	TFIBWideStringField *TableARTNOM;
	TFIBWideStringField *TableNAMENOM;
	TFIBIntegerField *TableCODE_SPRNOM;
	TFIBWideStringField *TableART_SPRNOM;
	TFIBWideStringField *TableNAME_SPRNOM;
	TFIBLargeIntField *ElementID_REM_SMODEL_DETAL;
	TFIBWideStringField *ElementGID_REM_SMODEL_DETAL;
	TFIBLargeIntField *ElementIDBASE_REM_SMODEL_DETAL;
	TFIBLargeIntField *ElementIDMODEL_REM_SMODEL_DETAL;
	TFIBLargeIntField *ElementIDTYPUSLA_REM_SMODEL_DETAL;
	TFIBLargeIntField *ElementIDNOM_REM_SMODEL_DETAL;
	TFIBLargeIntField *ElementIDPRNOM_REM_SMODEL_DETAL;
	TFIBWideStringField *ElementNAME_REM_SMODEL_DETAL;
	TFIBWideStringField *ElementPARTNUM_REM_SMODEL_DETAL;
	TFIBWideStringField *ElementDESCR_REM_SMODEL_DETAL;
	TFIBBCDField *ElementKOL_REM_SMODEL_DETAL;
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
		__fastcall TREM_DMSprModelDetal(TComponent* Owner);

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


};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprModelDetal *REM_DMSprModelDetal;
//---------------------------------------------------------------------------
#endif
