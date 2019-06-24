//---------------------------------------------------------------------------

#ifndef UREM_DMGurCustQueryDetalH
#define UREM_DMGurCustQueryDetalH
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
class TREM_DMGurCustQueryDetal : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_REM_CQUERY;
	TFIBWideStringField *TableGID_REM_CQUERY;
	TFIBLargeIntField *TableIDBASE_REM_CQUERY;
	TFIBDateTimeField *TablePOS_REM_CQUERY;
	TFIBIntegerField *TableNUM_REM_CQUERY;
	TFIBLargeIntField *TableIDFIRM_REM_CQUERY;
	TFIBLargeIntField *TableIDSKLAD_REM_CQUERY;
	TFIBLargeIntField *TableIDUSER_REM_CQUERY;
	TFIBLargeIntField *TableIDKLIENT_REM_CQUERY;
	TFIBWideStringField *TableKLIENT_NAME_REM_CQUERY;
	TFIBWideStringField *TableKLIENT_ADR_REM_CQUERY;
	TFIBWideStringField *TableKLIENT_PHONE_REM_CQUERY;
	TFIBWideStringField *TableCOMMENTS_REM_CQUERY;
	TFIBSmallIntField *TableRUN_REM_CQUERY;
	TFIBBCDField *TableDO_SUM_REM_CQUERY;
	TFIBBCDField *TableTEC_SUM_REM_CQUERY;
	TFIBBCDField *TableSOGL_SUM_REM_CQUERY;
	TFIBLargeIntField *TableIDZ_REM_CQUERY;
	TFIBLargeIntField *TableIDMODEL_REM_CQUERY;
	TFIBWideStringField *TableNAME_MODEL_REM_CQUERY;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAME_REM_SMODEL;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_USER;
	TFIBLargeIntField *TableIDBRAND_REM_CQUERY;
	TFIBLargeIntField *TableIDPRODUCER_REM_CQUERY;
	TFIBSmallIntField *TableFL_KLIENT_UVEDOML_REM_CQUERY;
	TFIBWideStringField *TableNAME_SBRAND;
	TFIBWideStringField *TableNAME_SPRODUCER;
	TFIBIntegerField *TableNUM_ZAKAZA_REM_CQUERY;
	TFIBDateField *TableDATE_ZAKAZA_REM_CQUERY;
	TFIBIntegerField *TableTYPE_REM_CQUERY;
	TFIBWideStringField *TableNAMENOM_REM_CQUERYT;
	TFIBIntegerField *TableCODENOM;
	TFIBWideStringField *TableARTNOM;
	TFIBWideStringField *TableNAMENOM;
	TFIBBCDField *TableKOL_REM_CQUERYT;
	TFIBBCDField *TableKF_REM_CQUERYT;
	TFIBBCDField *TablePRICE_REM_CQUERYT;
	TFIBBCDField *TableNOM_SUM_STR;
	TFIBIntegerField *TableCODE_SPRNOM;
	TFIBWideStringField *TableART_SPRNOM;
	TFIBWideStringField *TableNAME_SPRNOM;
	TFIBSmallIntField *TableFL_DOSTUPNO_SPRNOM;
	TFIBBCDField *TablePRICE_ZAKUP_SPRNOM;
	TFIBBCDField *TablePRNOM_SUM_STR;
	TFIBLargeIntField *TableID_REM_CQUERYT;
	TFIBWideStringField *TablePRODAVEC_NAME;
	TFIBWideStringField *TableNUM_STR_ZAK_POST_REM_CQUERY;
	TFIBWideStringField *TableNUM_STR_ZAK_SPROV_REM_CQUERY;
	TFIBWideStringField *TableNUMDOCTK_REM_CQUERY;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNAMEKLIENTGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall TableNAMENOMGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall TableNAME_REM_SMODELGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);


private:	// User declarations


	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;



public:		// User declarations
		__fastcall TREM_DMGurCustQueryDetal(TComponent* Owner);

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
		__int64 IdCustQuery;


        TDateTime PosNach;
		TDateTime PosCon;

				//открыть журнал только с выбранной заявкой
		bool OpenTableOnlyZayavka(__int64 id_z);

		void PoiskPoKlient(UnicodeString value);
		void PoiskPoModel(UnicodeString value);


		void OpenTableGur (__int64 id_user, int poisk, TDateTime pos_nach, TDateTime pos_con, UnicodeString value_str, __int64 value_int64);
		void OpenTablePoNumZakaza (__int64 id_user, __int64 id_producer,int number_zakaza, TDate date_zakaza);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMGurCustQueryDetal *REM_DMGurCustQueryDetal;
//---------------------------------------------------------------------------
#endif
