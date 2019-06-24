//---------------------------------------------------------------------------

#ifndef UREM_DMDocVosvratPokH
#define UREM_DMDocVosvratPokH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMSprPrice.h"

//--------------------------------------------------------------------------

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
class TREM_DMDocVosvratPok : public TDataModule
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
	TFIBLargeIntField *DocAllIDPROJECT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_REM_GALLDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TpFIBDataSet *DocOsn;
	TDataSource *DataSourceDocOsn;
	TFIBLargeIntField *DocID_REM_DVPOK;
	TFIBLargeIntField *DocIDBASE_REM_DVPOK;
	TFIBWideStringField *DocGID_REM_DVPOK;
	TFIBLargeIntField *DocIDDOC_REM_DVPOK;
	TFIBLargeIntField *DocIDTYPEPRICE_REM_DVPOK;
	TFIBLargeIntField *DocIDRTYPEPRICE_REM_DVPOK;
	TFIBLargeIntField *DocIDCARD_REM_DVPOK;
	TFIBWideStringField *DocKLIENT_NAME_REM_DVPOK;
	TFIBWideStringField *DocKLIENT_ADR_REM_DVPOK;
	TFIBWideStringField *DocKLIENT_PHONE_REM_DVPOK;
	TFIBWideStringField *DocKLIENT_PASSPORT_REM_DVPOK;
	TFIBWideStringField *DocPRICHINA_REM_DVPOK;
	TFIBWideStringField *DocDESCR_REM_DVPOK;
	TFIBWideStringField *DocNUMDOCSALE_REM_DVPOK;
	TFIBDateTimeField *DocPOSDOCSALE_REM_DVPOK;
	TFIBWideStringField *DocNUMDOCKL_REM_DVPOK;
	TFIBDateTimeField *DocPOSDOCKL_REM_DVPOK;
	TFIBWideStringField *DocNAME_SDISCOUNT_CARD;
	TFIBWideStringField *DocOsnTDOC_REM_GALLDOC;
	TFIBDateTimeField *DocOsnPOS_REM_GALLDOC;
	TFIBIntegerField *DocOsnNUM_REM_GALLDOC;
	TFIBLargeIntField *DocTID_REM_DVPOKT;
	TFIBLargeIntField *DocTIDBASE_REM_DVPOKT;
	TFIBWideStringField *DocTGID_REM_DVPOKT;
	TFIBLargeIntField *DocTIDDOC_REM_DVPOKT;
	TFIBLargeIntField *DocTIDNOM_REM_DVPOKT;
	TFIBLargeIntField *DocTIDED_REM_DVPOKT;
	TFIBLargeIntField *DocTIDHW_REM_DVPOKT;
	TFIBSmallIntField *DocTDVREG_REM_DVPOKT;
	TFIBBCDField *DocTKOL_REM_DVPOKT;
	TFIBBCDField *DocTKF_REM_DVPOKT;
	TFIBBCDField *DocTPRICE_REM_DVPOKT;
	TFIBBCDField *DocTSUM_REM_DVPOKT;
	TFIBIntegerField *DocTNDS_REM_DVPOKT;
	TFIBBCDField *DocTSUMNDS_REM_DVPOKT;
	TFIBBCDField *DocTPRSK_REM_DVPOKT;
	TFIBBCDField *DocTSUMSK_REM_DVPOKT;
	TFIBBCDField *DocTPRSK_CARD_REM_DVPOKT;
	TFIBBCDField *DocTPRSK_AUTO_REM_DVPOKT;
	TFIBBCDField *DocTPRSK_HAND_REM_DVPOKT;
	TFIBSmallIntField *DocTNO_SK_REM_DVPOKT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTSHED;
	TFIBWideStringField *DocTNAME_REM_SHARDWARE;
	TFIBIntegerField *DocTCODE_REM_SHARDWARE;
	TFIBWideStringField *DocTSERNUM_REM_SHARDWARE;
	TIntegerField *DocTRECNO;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLAD_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocTKOL_REM_DVPOKTChange(TField *Sender);
	void __fastcall DocTPRICE_REM_DVPOKTChange(TField *Sender);
private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		double SummaDoc;
		double TekSummaDoc;
		double OldSummaStr;
		double NewSummaStr;

		double OldRSummaStr;
		double NewRSummaStr;
public:		// User declarations
		__fastcall TREM_DMDocVosvratPok(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;


		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;
		UnicodeString TextError;
		bool Init(void);
		int Done(void);




		void NewDoc(void);
        void CopyDoc(__int64 id_doc);
		void OpenDoc(__int64 id);
		void OpenDocOsn(void);

		bool SaveDoc(void);
        bool DvRegDoc(void);
		bool CancelDvRegDoc(void);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
		bool DeleteDoc(__int64 id);
        double Summa(void);

		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца



		__int64 IdTypePrice;


        bool IsmPrice;
        bool IsmSum;

		__int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
		bool SkladRozn;
		bool EnableDvReg;
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMDocVosvratPok *REM_DMDocVosvratPok;
//---------------------------------------------------------------------------
#endif
