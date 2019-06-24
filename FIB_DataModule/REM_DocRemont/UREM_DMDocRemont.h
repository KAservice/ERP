//---------------------------------------------------------------------------

#ifndef UREM_DMDocRemontH
#define UREM_DMDocRemontH
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
class TREM_DMDocRemont : public TDataModule
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
	TFIBLargeIntField *DocID_REM_DREMONT;
	TFIBLargeIntField *DocIDDOC_REM_DREMONT;
	TFIBWideStringField *DocPRIM_REM_DREMONT;
	TFIBLargeIntField *DocIDBASE_REM_DREMONT;
	TFIBLargeIntField *DocIDZ_REM_DREMONT;
	TFIBLargeIntField *DocIDTPRICE_REM_DREMONT;
	TFIBWideStringField *DocNAME_REM_Z;
	TFIBLargeIntField *DocTID_REM_DREMONTT;
	TFIBLargeIntField *DocTIDDOC_REM_DREMONTT;
	TFIBLargeIntField *DocTIDBASE_REM_DREMONTT;
	TFIBLargeIntField *DocTIDNOM_REM_DREMONTT;
	TFIBLargeIntField *DocTIDED_REM_DREMONTT;
	TFIBBCDField *DocTKOL_REM_DREMONTT;
	TFIBBCDField *DocTKF_REM_DREMONTT;
	TFIBBCDField *DocTPRICE_REM_DREMONTT;
	TFIBBCDField *DocTSUM_REM_DREMONTT;
	TFIBBCDField *DocTSUMMEX_REM_DREMONTT;
	TFIBBCDField *DocTPRICEMEX_REM_DREMONTT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBIntegerField *DocNUM_REM_Z;
	TFIBDateTimeField *DocPOS_REM_Z;
	TFIBWideStringField *DocSERNUM_REM_Z;
	TFIBWideStringField *DocSERNUM2_REM_Z;
	TFIBWideStringField *DocKLIENT_NAME_REM_Z;
	TFIBWideStringField *DocMODEL_REM_Z;
	TFIBLargeIntField *DocTIDHW_REM_DREMONTT;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTSHED;
	TFIBWideStringField *DocTNAME_REM_SHARDWARE;
	TFIBIntegerField *DocTCODE_REM_SHARDWARE;
	TFIBWideStringField *DocTSERNUM_REM_SHARDWARE;
	TFIBSmallIntField *DocTDVREG_REM_DREMONTT;
	TFIBLargeIntField *DocIDHW_REM_DREMONT;
	TFIBLargeIntField *DocIDKKT_REM_DREMONT;
	TFIBIntegerField *DocTYPE_REMONT_REM_DREMONT;
	TFIBWideStringField *DocNAME_REM_SMODEL;
	TFIBWideStringField *DocNAME_REM_SHARDWARE;
	TFIBWideStringField *DocSERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocSERNUM2_REM_SHARDWARE;
	TFIBWideStringField *DocNAME_REM_SKKT;
	TFIBWideStringField *DocSERNUM_REM_SKKT;
	TFIBSmallIntField *DocTVD_REM_DREMONTT;
	TFIBSmallIntField *DocTREP_PRODUCER_REM_DREMONTT;
	TFIBLargeIntField *DocAllIDPROJECT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_REM_GALLDOC;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocAllIDOBJECT_REM_GALLDOC;
	TFIBWideStringField *DocAllNAME_SOBJECT;
	TpFIBDataSet *TypeNom;
	TFIBLargeIntField *TypeNomID_STNOM;
	TFIBWideStringField *TypeNomNAME_STNOM;
	TFIBLargeIntField *DocTIDHWOLD_REM_DREMONTT;
	TFIBLargeIntField *DocTIDTNOM_REM_DREMONTT;
	TFIBLargeIntField *DocTIDHW_DONOR_REM_DREMONTT;
	TFIBLargeIntField *DocTIDTYP_USEL_REM_DREMONTT;
	TFIBWideStringField *DocTDESCR_REM_DREMONTT;
	TFIBWideStringField *DocTOLD_NAME_REM_SHARDWARE;
	TFIBIntegerField *DocTOLD_CODE_REM_SHARDWARE;
	TFIBWideStringField *DocTOLD_SERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocTDONOR_NAME_REM_SHARDWARE;
	TFIBIntegerField *DocTDONOR_CODE_REM_SHARDWARE;
	TFIBWideStringField *DocTDONOR_SERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocTNAME_REM_STYPUSLOV;
	TFIBWideStringField *DocTNAME_STNOM;
	TStringField *DocTNAME_TYPE_NOM_LOOCUP;
	TFIBLargeIntField *DocTIDMHRAN_REM_DREMONTT;
	TFIBWideStringField *DocTNAME_SMHRAN;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocTKOL_REM_DREMONTTChange(TField *Sender);
	void __fastcall DocTPRICE_REM_DREMONTTChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		double OldSummaStr;
		double NewSummaStr;

		double OldSummaMexStr;
		double NewSummaMexStr;

		void BeforeDeleteDoc(void);
public:		// User declarations
		__fastcall TREM_DMDocRemont(TComponent* Owner);

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
extern PACKAGE TREM_DMDocRemont *REM_DMDocRemont;
//---------------------------------------------------------------------------
#endif
