//---------------------------------------------------------------------------

#ifndef UREM_DMSprKKTDvH
#define UREM_DMSprKKTDvH
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
class TREM_DMSprKKTDv : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_REM_SKKT_DV;
	TFIBLargeIntField *TableIDBASE_REM_SKKT_DV;
	TFIBLargeIntField *TableIDKKT_REM_SKKT_DV;
	TFIBDateTimeField *TablePOS_REM_SKKT_DV;
	TFIBLargeIntField *TableIDKLIENT_REM_SKKT_DV;
	TFIBWideStringField *TableMESTOUST_REM_SKKT_DV;
	TFIBWideStringField *TableREGNUM_REM_SKKT_DV;
	TFIBWideStringField *TableCBKGR_REM_SKKT_DV;
	TFIBWideStringField *TableCBKCO_REM_SKKT_DV;
	TFIBWideStringField *TableNUMCONTRACT_REM_SKKT_DV;
	TFIBDateField *TableDATECONTRACT_REM_SKKT_DV;
	TFIBBCDField *TableSUMCONTRACT_REM_SKKT_DV;
	TFIBWideStringField *TableEKLZ_SERNUM_REM_SKKT_DV;
	TFIBWideStringField *TableEKLZ_REGNUM_REM_SKKT_DV;
	TFIBDateField *TableEKLZ_ACT_REM_SKKT_DV;
	TFIBLargeIntField *TableIDUSER_REM_SKKT_DV;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_USER;
	TFIBLargeIntField *ElementID_REM_SKKT_DV;
	TFIBLargeIntField *ElementIDBASE_REM_SKKT_DV;
	TFIBLargeIntField *ElementIDKKT_REM_SKKT_DV;
	TFIBDateTimeField *ElementPOS_REM_SKKT_DV;
	TFIBLargeIntField *ElementIDKLIENT_REM_SKKT_DV;
	TFIBWideStringField *ElementMESTOUST_REM_SKKT_DV;
	TFIBWideStringField *ElementREGNUM_REM_SKKT_DV;
	TFIBWideStringField *ElementCBKGR_REM_SKKT_DV;
	TFIBWideStringField *ElementCBKCO_REM_SKKT_DV;
	TFIBWideStringField *ElementNUMCONTRACT_REM_SKKT_DV;
	TFIBDateField *ElementDATECONTRACT_REM_SKKT_DV;
	TFIBBCDField *ElementSUMCONTRACT_REM_SKKT_DV;
	TFIBWideStringField *ElementEKLZ_SERNUM_REM_SKKT_DV;
	TFIBWideStringField *ElementEKLZ_REGNUM_REM_SKKT_DV;
	TFIBDateField *ElementEKLZ_ACT_REM_SKKT_DV;
	TFIBLargeIntField *ElementIDUSER_REM_SKKT_DV;
	TFIBWideStringField *ElementNAMEKLIENT;
	TFIBWideStringField *ElementNAME_USER;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprKKTDv(TComponent* Owner);

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

		void OpenTable(__int64 id_owner);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_owner);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);

		__int64 IdOwner;

		bool AddRecordDv(TDateTime pos,             //
						__int64 id_owner,           //
						__int64 id_klient,          //
						UnicodeString mesto_ust,       //
						UnicodeString reg_num,         //
						UnicodeString svk_gr,          //
						UnicodeString svk_so,          //
						UnicodeString num_contract,    //
						TDate date_contract,
						double sum_contract,
						UnicodeString eklz_ser_num,
						UnicodeString eklz_reg_num,
						TDate eklz_act,
						__int64 id_user
						);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprKKTDv *REM_DMSprKKTDv;
//---------------------------------------------------------------------------
#endif
