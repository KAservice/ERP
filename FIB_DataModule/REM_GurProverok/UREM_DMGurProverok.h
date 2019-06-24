//---------------------------------------------------------------------------

#ifndef UREM_DMGurProverokH
#define UREM_DMGurProverokH
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
class TREM_DMGurProverok : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *IBQ;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_REM_GUR_PROV;
	TFIBLargeIntField *TableIDBASE_REM_GUR_PROV;
	TFIBDateTimeField *TablePOS_REM_GUR_PROV;
	TFIBIntegerField *TableNUM_REM_GUR_PROV;
	TFIBWideStringField *TableDESCR_REM_GUR_PROV;
	TFIBLargeIntField *TableIDDOC_REM_GUR_PROV;
	TFIBLargeIntField *TableIDUSER_REM_GUR_PROV;
	TFIBIntegerField *TableRES_REM_GUR_PROV;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_USER_DOC;
	TFIBWideStringField *TableNAME_USER_PROV;
	TFIBWideStringField *TableNAME_SINFBASE_OBMEN;
	TFIBWideStringField *TablePREFIKS_NUM_REM_GALLDOC;
	TFIBSmallIntField *TablePR_REM_GALLDOC;
	TFIBIntegerField *TableNUM_REM_GALLDOC;
	TFIBDateTimeField *TablePOS_REM_GALLDOC;
	TFIBWideStringField *TableTDOC_REM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableTDOC_REM_GALLDOCGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TREM_DMGurProverok(TComponent* Owner);

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
extern PACKAGE TREM_DMGurProverok *REM_DMGurProverok;
//---------------------------------------------------------------------------
#endif
