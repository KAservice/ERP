//---------------------------------------------------------------------------

#ifndef UREM_DMCustQueryDvH
#define UREM_DMCustQueryDvH
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
class TREM_DMCustQueryDv : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
		TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_REM_CQUERYT_DV;
	TFIBWideStringField *TableGID_REM_CQUERYT_DV;
	TFIBLargeIntField *TableIDBASE_REM_CQUERYT_DV;
	TFIBLargeIntField *TableIDCQT_REM_CQUERYT_DV;
	TFIBLargeIntField *TableIDUSER_REM_CQUERYT_DV;
	TFIBLargeIntField *TableIDSOST_REM_CQUERYT_DV;
	TFIBDateTimeField *TablePOS_REM_CQUERYT_DV;
	TFIBWideStringField *TableNAME_REM_SSOST_CQUERY;
	TFIBWideStringField *TableNAME_USER;
	TFIBLargeIntField *ElementID_REM_CQUERYT_DV;
	TFIBWideStringField *ElementGID_REM_CQUERYT_DV;
	TFIBLargeIntField *ElementIDBASE_REM_CQUERYT_DV;
	TFIBLargeIntField *ElementIDCQT_REM_CQUERYT_DV;
	TFIBLargeIntField *ElementIDUSER_REM_CQUERYT_DV;
	TFIBLargeIntField *ElementIDSOST_REM_CQUERYT_DV;
	TFIBDateTimeField *ElementPOS_REM_CQUERYT_DV;
	TFIBWideStringField *ElementNAME_REM_SSOST_CQUERY;
	TFIBWideStringField *ElementNAME_USER;
	TFIBSmallIntField *TableRUN_REM_CQUERY_DV;
	TFIBSmallIntField *TableACT_REM_CQUERY_DV;
	TFIBSmallIntField *ElementRUN_REM_CQUERY_DV;
	TFIBSmallIntField *ElementACT_REM_CQUERY_DV;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TREM_DMCustQueryDv(TComponent* Owner);

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
        bool Prosmotr;
		void OpenTable(__int64 id_cqt);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_cqt);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);

		__int64 IdCustQueryT;

		__int64 GetIDElement(UnicodeString gid);
		UnicodeString GetGIDElement(__int64 id);

		bool AddRecordDv(TDateTime pos,
						__int64 id_cqt,
						__int64 id_sost,
						__int64 id_user,
						int act,
						int run
						);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMCustQueryDv *REM_DMCustQueryDv;
//---------------------------------------------------------------------------
#endif
