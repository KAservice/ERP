//---------------------------------------------------------------------------

#ifndef UREM_DMGurZAktPrH
#define UREM_DMGurZAktPrH
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
class TREM_DMGurZAktPr : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBQuery *pFIBQ;
	TFIBDateTimeField *TablePOS_REM_GALLDOC;
	TFIBIntegerField *TableNUM_REM_GALLDOC;
	TFIBDateTimeField *TablePOS_REM_Z;
	TFIBWideStringField *TablePREFIKS_NUM_REM_Z;
	TFIBIntegerField *TableNUM_REM_Z;
	TFIBWideStringField *TableNUM_GARDOC_REM_Z;
	TFIBWideStringField *TableSERNUM_REM_Z;
	TFIBWideStringField *TableSERNUM2_REM_Z;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_USER;
	TFIBWideStringField *TableNAME_SINFBASE_OBMEN;
	TFIBWideStringField *TableKLIENT_NAME_REM_DZAKTPR;
	TFIBWideStringField *TableKLIENT_ADR_REM_DZAKTPR;
	TFIBWideStringField *TableKLIENT_PHONE_REM_DZAKTPR;
	TFIBLargeIntField *TableIDDOC_REM_DZAKTPR;
	TFIBIntegerField *TableFL_FICTIV_REM_DZAKTPR;
	TFIBSmallIntField *TablePR_REM_GALLDOC;
	TFIBWideStringField *TablePREFIKS_NUM_REM_GALLDOC;
	TFIBBCDField *TableSUM_REM_GALLDOC;
	TFIBWideStringField *TableNAME_REM_SPRMODEL;
	TFIBWideStringField *TableNUMGARTALON_REM_DZAKTPR;
	TFIBSmallIntField *TableFL_POVTOR_REM_Z;
	TFIBSmallIntField *TableFL_ADDREPORT_REM_Z;
	TFIBIntegerField *TableFL_FICTIV_REM_Z;
	TFIBSmallIntField *TableFL_NE_OTCH_REM_Z;
	TFIBSmallIntField *TableFL_NADO_OTCH_REM_Z;
	TFIBSmallIntField *TableFL_NE_OTCH_REM_DZAKTPR;
	TFIBSmallIntField *TableFL_NADO_OTCH_REM_DZAKTPR;
	TIntegerField *TableSROK_REMONTA;
	TIntegerField *TableSROK_REMONTA_NOW;
	TIntegerField *TableSROK_REMONTA_IS_DOC;
	TFIBDateTimeField *TablePOSPRIEMA_REM_DZAKTPR;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TREM_DMGurZAktPr(TComponent* Owner);

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

        void OpenTable();
		void UpdateTable(void);



		//открыть журнал только с выбранным оборудованием
		bool OpenTableOnlyHardware(__int64 id_hw);

		//открыть журнал только с выбранной заявкой
		bool OpenTableOnlyZayavka(__int64 id_z);

		void PoiskPoSerNum1(UnicodeString ser_num);
		void PoiskPoSerNum2(UnicodeString ser_num);
		void PoiskPoKlient(UnicodeString value);
		void PoiskPoModel(UnicodeString value);

		void PoiskPoIdHardware(__int64 id_hw);
        void PoiskPoNumGarDoc(UnicodeString num_gar_doc);


};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMGurZAktPr *REM_DMGurZAktPr;
//---------------------------------------------------------------------------
#endif
