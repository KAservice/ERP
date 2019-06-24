//---------------------------------------------------------------------------

#ifndef UREM_DMDocZOperH
#define UREM_DMDocZOperH
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
class TREM_DMDocZOper : public TDataModule
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
	TFIBLargeIntField *DocID_REM_DZOPER;
	TFIBLargeIntField *DocIDBASE_REM_DZOPER;
	TFIBWideStringField *DocGID_REM_DZOPER;
	TFIBLargeIntField *DocIDDOC_REM_DZOPER;
	TFIBLargeIntField *DocIDZ_REM_DZOPER;
	TFIBLargeIntField *DocIDTPRICE_REM_DZOPER;
	TFIBWideStringField *DocPRIM_REM_DZOPER;
	TFIBWideStringField *DocNAME_REM_Z;
	TFIBIntegerField *DocNUM_REM_Z;
	TFIBDateTimeField *DocPOS_REM_Z;
	TFIBWideStringField *DocSERNUM_REM_Z;
	TFIBWideStringField *DocSERNUM2_REM_Z;
	TFIBWideStringField *DocKLIENT_NAME_REM_Z;
	TFIBWideStringField *DocMODEL_REM_Z;
	TFIBWideStringField *DocNAME_REM_SMODEL;
	TFIBLargeIntField *DocTID_REM_DZOPERT;
	TFIBLargeIntField *DocTIDBASE_REM_DZOPERT;
	TFIBWideStringField *DocTGID_REM_DZOPERT;
	TFIBLargeIntField *DocTIDDOC_REM_DZOPERT;
	TFIBLargeIntField *DocTIDNOM_REM_DZOPERT;
	TFIBLargeIntField *DocTIDED_REM_DZOPERT;
	TFIBLargeIntField *DocTIDHW_REM_DZOPERT;
	TFIBBCDField *DocTKOL_REM_DZOPERT;
	TFIBBCDField *DocTKF_REM_DZOPERT;
	TFIBBCDField *DocTPRICE_REM_DZOPERT;
	TFIBBCDField *DocTSUM_REM_DZOPERT;
	TFIBSmallIntField *DocTDVREG_REM_DZOPERT;
	TFIBWideStringField *DocTSTR_NAMENOM_REM_DZOPERT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocTSHED;
	TFIBWideStringField *DocTNAME_REM_SHARDWARE;
	TFIBIntegerField *DocTCODE_REM_SHARDWARE;
	TFIBLargeIntField *DocAllIDPROJECT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_REM_GALLDOC;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocTIDHWOLD_REM_DZOPERT;
	TFIBLargeIntField *DocTIDTNOM_REM_DZOPERT;
	TFIBLargeIntField *DocTIDHW_DONOR_REM_DZOPERT;
	TFIBLargeIntField *DocTIDTYP_USEL_REM_DZOPERT;
	TFIBLargeIntField *DocTIDMHRAN_REM_DZOPERT;
	TFIBWideStringField *DocTSERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocTOLD_NAME_REM_SHARDWARE;
	TFIBIntegerField *DocTOLD_CODE_REM_SHARDWARE;
	TFIBWideStringField *DocTOLD_SERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocTDONOR_NAME_REM_SHARDWARE;
	TFIBIntegerField *DocTDONOR_CODE_REM_SHARDWARE;
	TFIBWideStringField *DocTDONOR_SERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocTNAME_STNOM;
	TFIBWideStringField *DocTNAME_SMHRAN;
	TFIBWideStringField *DocTNAME_REM_STYPUSLOV;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocTKOL_REM_DZOPERTChange(TField *Sender);
	void __fastcall DocTPRICE_REM_DZOPERTChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		double OldSummaStr;
		double NewSummaStr;

		double OldSummaMexStr;
		double NewSummaMexStr;
public:		// User declarations
		__fastcall TREM_DMDocZOper(TComponent* Owner);

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
extern PACKAGE TREM_DMDocZOper *REM_DMDocZOper;
//---------------------------------------------------------------------------
#endif
