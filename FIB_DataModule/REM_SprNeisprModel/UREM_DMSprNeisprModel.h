//---------------------------------------------------------------------------

#ifndef UREM_DMSprNeisprModelH
#define UREM_DMSprNeisprModelH
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
class TREM_DMSprNeisprModel : public TDataModule
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
	TFIBLargeIntField *TableID_REM_SNEISPMODEL;
	TFIBWideStringField *TableGID_REM_SNEISPMODEL;
	TFIBLargeIntField *TableIDBASE_REM_SNEISPMODEL;
	TFIBWideStringField *TableDESCR_REM_SNEISPMODEL;
	TFIBLargeIntField *TableIDMODEL_REM_SNEISPMODEL;
	TFIBLargeIntField *TableIDNEISPR_REM_SNEISPMODEL;
	TFIBWideStringField *TableNAME_REM_SNEISPR;
	TFIBLargeIntField *ElementID_REM_SNEISPMODEL;
	TFIBWideStringField *ElementGID_REM_SNEISPMODEL;
	TFIBLargeIntField *ElementIDBASE_REM_SNEISPMODEL;
	TFIBWideStringField *ElementDESCR_REM_SNEISPMODEL;
	TFIBLargeIntField *ElementIDMODEL_REM_SNEISPMODEL;
	TFIBLargeIntField *ElementIDNEISPR_REM_SNEISPMODEL;
	TFIBWideStringField *ElementNAME_REM_SNEISPR;
	TFIBWideStringField *TableNAME_REM_SNEISPMODEL;
	TFIBWideStringField *ElementNAME_REM_SNEISPMODEL;
	TFIBLargeIntField *ElementIDMODELNEISPR_REM_SNEISPMODEL;
	TFIBWideStringField *ElementNAME_REM_SMODEL;
	TFIBLargeIntField *TableIDMODELNEISPR_REM_SNEISPMODEL;
	TFIBWideStringField *TableNAME_REM_SMODEL;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TREM_DMSprNeisprModel(TComponent* Owner);

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
extern PACKAGE TREM_DMSprNeisprModel *REM_DMSprNeisprModel;
//---------------------------------------------------------------------------
#endif
