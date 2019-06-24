//---------------------------------------------------------------------------

#ifndef UREM_DMSprDefectModelNeisprH
#define UREM_DMSprDefectModelNeisprH
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
class TREM_DMSprDefectModelNeispr : public TDataModule
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
	TFIBLargeIntField *TableID_REM_SDEFECT_MODNE;
	TFIBWideStringField *TableGID_REM_SDEFECT_MODNE;
	TFIBLargeIntField *TableIDBASE_REM_SDEFECT_MODNE;
	TFIBLargeIntField *TableIDNEISMOD_REM_SDEFECT_MODNE;
	TFIBWideStringField *TableNAME_REM_SDEFECT_MODNE;
	TFIBWideStringField *TableDESCR_REM_SDEFECT_MODNE;
	TFIBLargeIntField *TableIDTDEF_REM_SDEFECT_MODNE;
	TFIBWideStringField *TableNAME_REM_STYPDEFECT;
	TFIBWideStringField *TableCODE_REM_STYPDEFECT;
	TFIBLargeIntField *ElementID_REM_SDEFECT_MODNE;
	TFIBWideStringField *ElementGID_REM_SDEFECT_MODNE;
	TFIBLargeIntField *ElementIDBASE_REM_SDEFECT_MODNE;
	TFIBLargeIntField *ElementIDNEISMOD_REM_SDEFECT_MODNE;
	TFIBWideStringField *ElementNAME_REM_SDEFECT_MODNE;
	TFIBWideStringField *ElementDESCR_REM_SDEFECT_MODNE;
	TFIBLargeIntField *ElementIDTDEF_REM_SDEFECT_MODNE;
	TFIBWideStringField *ElementNAME_REM_STYPDEFECT;
	TFIBWideStringField *ElementCODE_REM_STYPDEFECT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TREM_DMSprDefectModelNeispr(TComponent* Owner);

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

		void OpenTable(__int64 id_model_neispr);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_model_neispr);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);


};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprDefectModelNeispr *REM_DMSprDefectModelNeispr;
//---------------------------------------------------------------------------
#endif
