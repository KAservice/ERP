//---------------------------------------------------------------------------

#ifndef UREM_DMGurZH
#define UREM_DMGurZH
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
class TREM_DMGurZ : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_REM_Z;
	TFIBWideStringField *TableGID_REM_Z;
	TFIBWideStringField *TablePREFIKS_REM_Z;
	TFIBIntegerField *TableNUM_REM_Z;
	TFIBDateTimeField *TablePOS_REM_Z;
	TFIBLargeIntField *TableIDBASE_REM_Z;
	TFIBLargeIntField *TableIDMODEL_REM_Z;
	TFIBLargeIntField *TableIDSKLPR_REM_Z;
	TFIBLargeIntField *TableIDKLIENT_REM_Z;
	TFIBLargeIntField *TableIDDILER_REM_Z;
	TFIBWideStringField *TableSERNUM_REM_Z;
	TFIBWideStringField *TableNAME_REM_Z;
	TFIBWideStringField *TableDESCR_REM_Z;
	TFIBLargeIntField *TableIDTYPEREM_REM_Z;
	TFIBLargeIntField *TableIDSOST_REM_Z;
	TFIBLargeIntField *TableIDTECSKL_REM_Z;
	TFIBLargeIntField *TableIDUSER_REM_Z;
	TFIBIntegerField *TableOPER_REM_Z;
	TFIBBCDField *TableSUM_REM_Z;
	TFIBDateField *TableSROK_REM_Z;
	TFIBIntegerField *TableOUT_REM_Z;
	TFIBLargeIntField *TableIDFIRM_REM_Z;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAME_REM_SMODEL;
	TFIBWideStringField *TableNAME_SKLAD_PR;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAMEDILER;
	TFIBWideStringField *TableNAME_STREMONT;
	TFIBWideStringField *TableNAME_REMSSOST;
	TFIBWideStringField *TableNAME_SKLAD_TEC;
	TFIBWideStringField *TableNAME_USER;
	TFIBWideStringField *TableKLIENT_NAME_REM_Z;
	TFIBWideStringField *TableMODEL_REM_Z;
	TFIBWideStringField *TableSERNUM2_REM_Z;
	TFIBIntegerField *TableFL_KLIENT_UVEDOML_REM_Z;
	TFIBIntegerField *TableFL_TREB_KONS_KL_REM_Z;
	TFIBIntegerField *TableFL_KL_OTV_NA_ZAPROS_REM_Z;
	TFIBWideStringField *TablePREFIKS_NUM_REM_Z;
	TFIBWideStringField *TableNAME_SINFBASE_OBMEN;
	TFIBLargeIntField *TableIDBRAND_REM_Z;
	TFIBSmallIntField *TableFL_POVTOR_REM_Z;
	TFIBSmallIntField *TableFL_ADDREPORT_REM_Z;
	TFIBWideStringField *TableNUM_GARDOC_REM_Z;
	TFIBWideStringField *TableNAME_SBRAND;
	TFIBIntegerField *TableFL_FICTIV_REM_Z;
	TFIBSmallIntField *TableFL_NE_OTCH_REM_Z;
	TFIBSmallIntField *TableFL_NADO_OTCH_REM_Z;
	TFIBSmallIntField *TableSOST_CQUERY;
	TFIBLargeIntField *TableID_REM_CQUERY;
	TIntegerField *TableSROK_REMONTA;
	TIntegerField *TableSROK_REMONTA_NOW;
	TFIBDateTimeField *TablePOSOUT_REM_Z;
	TFIBDateTimeField *TablePOSREMONT_REM_Z;
	TFIBSmallIntField *TableGOTOVO_K_VIDACHE_REM_Z;
	TFIBWideStringField *TableNAME_SKLAD_OST;
	TFIBLargeIntField *TableIDREC_RGOTPRZ;
	TFIBLargeIntField *TableIDDOC_VIDACHA_HW;
	TFIBLargeIntField *TableIDDOC_VOSVRAT_HW;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations


	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

   UnicodeString GetNachaloZapros(void);

public:		// User declarations
		__fastcall TREM_DMGurZ(TComponent* Owner);

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
extern PACKAGE TREM_DMGurZ *REM_DMGurZ;
//---------------------------------------------------------------------------
#endif
