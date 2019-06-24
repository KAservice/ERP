//---------------------------------------------------------------------------

#ifndef UREM_DMZayavkaDvH
#define UREM_DMZayavkaDvH
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
class TREM_DMZayavkaDv : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
		TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_REM_Z_DV;
	TFIBWideStringField *TableGID_REM_Z_DV;
	TFIBDateTimeField *TablePOS_REM_Z_DV;
	TFIBLargeIntField *TableIDZ_REM_Z_DV;
	TFIBSmallIntField *TableOPER_REM_Z_DV;
	TFIBLargeIntField *TableIDSOST_REM_Z_DV;
	TFIBLargeIntField *TableIDTREMONT_REM_Z_DV;
	TFIBLargeIntField *TableIDUSER_REM_Z_DV;
	TFIBBCDField *TableSUM_REM_Z_DV;
	TFIBDateField *TableSROK_REM_Z_DV;
	TFIBSmallIntField *TableOUT_REM_Z_DV;
	TFIBLargeIntField *TableIDTECSKL_REM_Z_DV;
	TFIBLargeIntField *TableIDBASE_REM_Z_DV;
	TFIBWideStringField *TableNAME_STREMONT;
	TFIBWideStringField *TableNAME_REMSSOST;
	TFIBWideStringField *TableNAME_SKLAD_TEC;
	TFIBWideStringField *TableNAME_USER;
	TFIBLargeIntField *ElementID_REM_Z_DV;
	TFIBWideStringField *ElementGID_REM_Z_DV;
	TFIBDateTimeField *ElementPOS_REM_Z_DV;
	TFIBLargeIntField *ElementIDZ_REM_Z_DV;
	TFIBSmallIntField *ElementOPER_REM_Z_DV;
	TFIBLargeIntField *ElementIDSOST_REM_Z_DV;
	TFIBLargeIntField *ElementIDTREMONT_REM_Z_DV;
	TFIBLargeIntField *ElementIDUSER_REM_Z_DV;
	TFIBBCDField *ElementSUM_REM_Z_DV;
	TFIBDateField *ElementSROK_REM_Z_DV;
	TFIBSmallIntField *ElementOUT_REM_Z_DV;
	TFIBLargeIntField *ElementIDTECSKL_REM_Z_DV;
	TFIBLargeIntField *ElementIDBASE_REM_Z_DV;
	TFIBWideStringField *ElementNAME_STREMONT;
	TFIBWideStringField *ElementNAME_REMSSOST;
	TFIBWideStringField *ElementNAME_SKLAD_TEC;
	TFIBWideStringField *ElementNAME_USER;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TREM_DMZayavkaDv(TComponent* Owner);

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
		void OpenTable(__int64 id_z);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_z);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);

		__int64 IdZ;
        __int64 IdBaseZayavki;
		__int64 GetIDElement(UnicodeString gid);
		UnicodeString GetGIDElement(__int64 id);

		bool AddRecordDv(TDateTime pos,
						__int64 id_z,
						int oper,
						__int64 id_sost,
						__int64 id_type_remont,
						__int64 id_user,
						__int64 id_tec_sklad,
						double sum,
						TDate date,
						int out
						);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMZayavkaDv *REM_DMZayavkaDv;
//---------------------------------------------------------------------------
#endif
