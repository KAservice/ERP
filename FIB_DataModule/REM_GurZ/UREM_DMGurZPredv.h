//---------------------------------------------------------------------------

#ifndef UREM_DMGurZPredvH
#define UREM_DMGurZPredvH
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
class TREM_DMGurZPredv : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_REM_Z2;
	TFIBLargeIntField *TableIDBASE_REM_Z2;
	TFIBWideStringField *TablePREFIKS_REM_Z2;
	TFIBIntegerField *TableNUM_REM_Z2;
	TFIBWideStringField *TableGUID_REM_Z2;
	TFIBDateTimeField *TablePOS_REM_Z2;
	TFIBLargeIntField *TableIDMODEL_REM_Z2;
	TFIBLargeIntField *TableIDPRMODEL_REM_Z2;
	TFIBLargeIntField *TableIDFIRM_REM_Z2;
	TFIBLargeIntField *TableIDSKLPR_REM_Z2;
	TFIBLargeIntField *TableIDKLIENT_REM_Z2;
	TFIBLargeIntField *TableIDDILER_REM_Z2;
	TFIBWideStringField *TableNAME_REM_Z2;
	TFIBWideStringField *TableDESCR_REM_Z2;
	TFIBWideStringField *TableKLIENT_NAME_REM_Z2;
	TFIBWideStringField *TableKLIENT_ADR_REM_Z2;
	TFIBWideStringField *TableKLIENT_PHONE_REM_Z2;
	TFIBWideStringField *TableKLIENT_EMAIL_REM_Z2;
	TFIBLargeIntField *TableIDBRAND_REM_Z2;
	TFIBLargeIntField *TableIDPRODUCER_REM_Z2;
	TFIBWideStringField *TableNEISPR_REM_Z2;
	TFIBWideStringField *TableSOST_REM_Z2;
	TFIBWideStringField *TableMODEL_STR_REM_Z2;
	TFIBWideStringField *TableSERNUM1_REM_Z2;
	TFIBWideStringField *TableSERNUM2_REM_Z2;
	TFIBLargeIntField *TableIDKKT_REM_Z2;
	TFIBLargeIntField *TableIDHW_REM_Z2;
	TFIBLargeIntField *TableIDSELLER_REM_Z2;
	TFIBWideStringField *TableDOPOPISANIE_REM_Z2;
	TFIBBCDField *TableSUMKLIENTA_REM_Z2;
	TFIBBCDField *TableSUMNACHA_REM_Z2;
	TFIBIntegerField *TableRESULT_REM_Z2;
	TFIBWideStringField *TablePRICHINA_REM_Z2;
	TFIBIntegerField *TablePRICHINA_LIST_REM_Z2;
	TFIBIntegerField *TableSROK_REM_Z2;
	TFIBLargeIntField *TableIDUSER_REM_Z2;
	TFIBWideStringField *TableNAME_SINFBASE_OBMEN;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAME_REM_SMODEL;
	TFIBWideStringField *TableNAME_SKLAD_PR;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAMEDILER;
	TFIBWideStringField *TableNAME_USER;
	TFIBWideStringField *TableNAME_SBRAND;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations


	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

   UnicodeString GetNachaloZapros(void);

public:		// User declarations
		__fastcall TREM_DMGurZPredv(TComponent* Owner);

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
        void OpenTable();
        void UpdateTable(void);
        __int64 IdZ;


        TDateTime PosNach;
		TDateTime PosCon;

		void PoiskPoSerNum1(UnicodeString ser_num);
		void PoiskPoSerNum2(UnicodeString ser_num);
		void PoiskPoKlient(UnicodeString value);
		void PoiskPoModel(UnicodeString value);

		void PoiskPoIdHardware(__int64 id_hw);
        void PoiskPoNumGarDoc(UnicodeString num_gar_doc);
		void OpenTableOtbor(TDateTime pos_start,TDateTime pos_end,int poisk,UnicodeString str_value,__int64 int64_value);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMGurZPredv *REM_DMGurZPredv;
//---------------------------------------------------------------------------
#endif
