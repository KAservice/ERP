//---------------------------------------------------------------------------

#ifndef UREM_DMDocVidachaHWH
#define UREM_DMDocVidachaHWH
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
class TREM_DMDocVidachaHW : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocT;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBDataSet *DocT;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TpFIBQuery *pFIBQ;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBIntegerField *NumDocMAXNUMBER;
	TIntegerField *DocTRECNO;
	TFIBLargeIntField *DocAllID_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBASE_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDFIRM_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDSKLAD_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDKLIENT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDUSER_REM_GALLDOC;
	TFIBDateTimeField *DocAllPOS_REM_GALLDOC;
	TFIBIntegerField *DocAllNUM_REM_GALLDOC;
	TFIBSmallIntField *DocAllPR_REM_GALLDOC;
	TFIBWideStringField *DocAllTDOC_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDDOCOSN_REM_GALLDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDEXTDOC_REM_GALLDOC;
	TFIBBCDField *DocAllSUM_REM_GALLDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBLargeIntField *DocAllIDPROJECT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_REM_GALLDOC;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocID_REM_DVIDACHA_HW;
	TFIBLargeIntField *DocIDBASE_REM_DVIDACHA_HW;
	TFIBWideStringField *DocGID_REM_DVIDACHA_HW;
	TFIBLargeIntField *DocIDDOC_REM_DVIDACHA_HW;
	TFIBWideStringField *DocKLIENT_NAME_REM_DVIDACHA_HW;
	TFIBWideStringField *DocKLIENT_ADR_REM_DVIDACHA_HW;
	TFIBWideStringField *DocKLIENT_PHONE_REM_DVIDACHA_HW;
	TFIBWideStringField *DocKLIENT_PASSPORT_REM_DVIDACHA_HW;
	TFIBWideStringField *DocPRIM_REM_DVIDACHA_HW;
	TFIBLargeIntField *DocIDZ_REM_DVIDACHA_HW;
	TFIBLargeIntField *DocIDHW_REM_DVIDACHA_HW;
	TFIBLargeIntField *DocIDKKT_REM_DVIDACHA_HW;
	TFIBWideStringField *DocNAME_REM_SHARDWARE;
	TFIBIntegerField *DocCODE_REM_SHARDWARE;
	TFIBWideStringField *DocSERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocSERNUM2_REM_SHARDWARE;
	TFIBWideStringField *DocNAME_REM_SMODEL;
	TFIBWideStringField *DocCODE_REM_SMODEL;
	TFIBWideStringField *DocCODE_REM_SPRMODEL;
	TFIBWideStringField *DocNAME_REM_SPRMODEL;
	TFIBWideStringField *DocNAME_REM_Z;
	TFIBWideStringField *DocPREFIKS_NUM_REM_Z;
	TFIBIntegerField *DocNUM_REM_Z;
	TFIBDateTimeField *DocPOS_REM_Z;
	TFIBWideStringField *DocMODEL_REM_Z;
	TFIBWideStringField *DocSERNUM_REM_Z;
	TFIBWideStringField *DocSERNUM2_REM_Z;
	TFIBLargeIntField *DocTID_REM_DVIDACHA_HWT;
	TFIBLargeIntField *DocTIDBASE_REM_DVIDACHA_HWT;
	TFIBWideStringField *DocTGID_REM_DVIDACHA_HWT;
	TFIBLargeIntField *DocTIDDOC_REM_DVIDACHA_HWT;
	TFIBLargeIntField *DocTIDHW_REM_DVIDACHA_HWT;
	TFIBBCDField *DocTKF_REM_DVIDACHA_HWT;
	TFIBBCDField *DocTKOL_REM_DVIDACHA_HWT;
	TFIBWideStringField *DocTPOVREGD_REM_DVIDACHA_HWT;
	TFIBWideStringField *DocTNAME_REM_SHARDWARE;
	TFIBIntegerField *DocTCODE_REM_SHARDWARE;
	TFIBWideStringField *DocTSERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocTSERNUM2_REM_SHARDWARE;
	TFIBWideStringField *DocTNAME_REM_SMODEL;
	TFIBWideStringField *DocTCODE_REM_SMODEL;
	TFIBWideStringField *DocTCODE_REM_SPRMODEL;
	TFIBWideStringField *DocTNAME_REM_SPRMODEL;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		double OldSummaStr;
		double NewSummaStr;

		double OldSummaMexStr;
		double NewSummaMexStr;
public:		// User declarations
		__fastcall TREM_DMDocVidachaHW(TComponent* Owner);

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

		__int64 IdDoc;           //идентификатор текущей записи
		bool Prosmotr;    //только просмотр

		bool NewDoc(void);
		bool OpenDoc(__int64 id);
		bool SaveDoc(void);
		bool DeleteDoc(__int64 id);

        bool DvRegDoc(void);
		bool CancelDvRegDoc(void);

		void TableAppend(void);
		void TableDelete(void);





};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMDocVidachaHW *REM_DMDocVidachaHW;
//---------------------------------------------------------------------------
#endif
