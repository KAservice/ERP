//---------------------------------------------------------------------------

#ifndef UREM_DMGurVigrusokH
#define UREM_DMGurVigrusokH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

//---------------------------------------------------------------------------

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
class TREM_DMGurVigrusok : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *IBQ;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_REM_GUR_VIGR;
	TFIBLargeIntField *TableIDBASE_REM_GUR_VIGR;
	TFIBLargeIntField *TableIDUSER_REM_GUR_VIGR;
	TFIBDateTimeField *TablePOS_REM_GUR_VIGR;
	TFIBIntegerField *TableNUM_REM_GUR_VIGR;
	TFIBWideStringField *TableGUID_TRANSACTION_REM_GUR_VIGR;
	TFIBWideStringField *TableCODE_STR_VIGR_REM_GUR_VIGR;
	TFIBWideStringField *TableGUID_VIGR_REM_GUR_VIGR;
	TFIBLargeIntField *TableIDKLIENT_REM_GUR_VIGR;
	TFIBLargeIntField *TableIDPRODUCER_REM_GUR_VIGR;
	TFIBWideStringField *TableNAME_SPRODUCER;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_USER;
	TFIBWideStringField *TableNAME_SINFBASE_OBMEN;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TREM_DMGurVigrusok(TComponent* Owner);

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

		TDateTime PosNach;
		TDateTime PosCon;
		__int64 IdDoc;
		__int64 IdKlient;
		__int64 IdSklad;
		__int64 IdFirm;
		UnicodeString   StringTypeDoc;
		bool OtborVkl;

        void OpenTable();
		void UpdateTable(void);



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMGurVigrusok *REM_DMGurVigrusok;
//---------------------------------------------------------------------------
#endif
