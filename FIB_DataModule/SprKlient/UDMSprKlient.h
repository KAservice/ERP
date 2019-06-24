//---------------------------------------------------------------------------

#ifndef UDMSprKlientH
#define UDMSprKlientH
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
class TDMSprKlient : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableIDKLIENT;
	TFIBBCDField *TableIDGRPKLIENT;
	TFIBBCDField *ElementIDKLIENT;
	TFIBBCDField *ElementIDTPRICEKLIENT;
	TFIBBCDField *ElementIDGRPKLIENT;
	TFIBBCDField *ElementIDVIDKLIENT;
	TFIBBCDField *ElementIDCOUNTRYKLIENT;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *ElementMAXCREDIT_SKLIENT;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableINNKLIENT;
	TFIBWideStringField *TableTELKLIENT;
	TFIBWideStringField *TableADRKLIENT;
	TFIBWideStringField *ElementNAMEKLIENT;
	TFIBWideStringField *ElementFNAME;
	TFIBWideStringField *ElementADRKLIENT;
	TFIBWideStringField *ElementTELKLIENT;
	TFIBWideStringField *ElementINNKLIENT;
	TFIBWideStringField *ElementKPPKLIENT;
	TFIBIntegerField *ElementTKLIENT;
	TFIBWideStringField *ElementGID_SKLIENT;
	TFIBWideStringField *ElementOKPOKLIENT;
	TFIBBCDField *ElementIDBASE_SKLIENT;
	TFIBWideStringField *ElementKRNAME_SKLIENT;
	TFIBWideStringField *ElementDESCR_SKLIENT;
	TFIBWideStringField *ElementMESSAGE_SKLIENT;
	TFIBWideStringField *ElementEMAIL_SKLIENT;
	TFIBWideStringField *ElementWWW_SKLIENT;
	TFIBWideStringField *ElementNAME_SVIDKLIENT;
	TFIBWideStringField *ElementNAME_SCOUNTRY;
	TFIBWideStringField *ElementYUR_ADRESS_SKLIENT;
	TFIBWideStringField *ElementPOCHT_ADRRESS_SKLIENT;
	TFIBWideStringField *ElementFAMILIYA_SKLIENT;
	TFIBWideStringField *ElementIMYA_SKLIENT;
	TFIBWideStringField *ElementOTCHESTVO_SKLIENT;
	TFIBIntegerField *ElementTYPE_POISK_SKLIENT;
	TFIBBCDField *ElementIDGRPNOM_SKLIENT;
	TFIBBCDField *ElementIDGRPHW_SKLIENT;
	TFIBWideStringField *ElementNAMEGN;
	TFIBWideStringField *ElementNAME_REM_SGRP_HARDWARE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations


bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TDMSprKlient(TComponent* Owner);

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







		bool OpenTable(__int64 id_grp, bool all);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 new_grp);

		__int64 Id;
		__int64 IdGroup;
        bool AllElement;


		bool elSave;


		__int64 FindPoName(String Name);
		__int64 GetIDKlientPoName(AnsiString name);
		__int64 GetIdGrpKlient(__int64 id_klient);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprKlient *DMSprKlient;
//---------------------------------------------------------------------------
#endif
