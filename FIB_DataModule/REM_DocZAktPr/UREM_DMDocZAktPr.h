//---------------------------------------------------------------------------

#ifndef UREM_DMDocZAktPrH
#define UREM_DMDocZAktPrH
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
class TREM_DMDocZAktPr : public TDataModule
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
	TFIBLargeIntField *DocID_REM_DZAKTPR;
	TFIBLargeIntField *DocIDBASE_REM_DZAKTPR;
	TFIBWideStringField *DocGID_REM_DZAKTPR;
	TFIBLargeIntField *DocIDDOC_REM_DZAKTPR;
	TFIBLargeIntField *DocIDZ_REM_DZAKTPR;
	TFIBLargeIntField *DocIDTPRICE_REM_DZAKTPR;
	TFIBWideStringField *DocPRIM_REM_DZAKTPR;
	TFIBWideStringField *DocNAME_REM_Z;
	TFIBIntegerField *DocNUM_REM_Z;
	TFIBDateTimeField *DocPOS_REM_Z;
	TFIBWideStringField *DocSERNUM_REM_Z;
	TFIBWideStringField *DocSERNUM2_REM_Z;
	TFIBWideStringField *DocKLIENT_NAME_REM_Z;
	TFIBWideStringField *DocMODEL_REM_Z;
	TFIBWideStringField *DocNAME_REM_SMODEL;
	TFIBLargeIntField *DocTID_REM_DZAKTPRT;
	TFIBLargeIntField *DocTIDBASE_REM_DZAKTPRT;
	TFIBWideStringField *DocTGID_REM_DZAKTPRT;
	TFIBLargeIntField *DocTIDDOC_REM_DZAKTPRT;
	TFIBLargeIntField *DocTIDNOM_REM_DZAKTPRT;
	TFIBLargeIntField *DocTIDED_REM_DZAKTPRT;
	TFIBLargeIntField *DocTIDHW_REM_DZAKTPRT;
	TFIBBCDField *DocTKOL_REM_DZAKTPRT;
	TFIBBCDField *DocTKF_REM_DZAKTPRT;
	TFIBBCDField *DocTPRICE_REM_DZAKTPRT;
	TFIBBCDField *DocTSUM_REM_DZAKTPRT;
	TFIBSmallIntField *DocTDVREG_REM_DZAKTPRT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocTSHED;
	TFIBWideStringField *DocTNAME_REM_SHARDWARE;
	TFIBIntegerField *DocTCODE_REM_SHARDWARE;
	TFIBWideStringField *DocTSERNUM_REM_SHARDWARE;
	TFIBLargeIntField *DocIDPR_REM_DZAKTPR;
	TFIBLargeIntField *DocIDCFC_REM_DZAKTPR;
	TFIBLargeIntField *DocIDDFC_REM_DZAKTPR;
	TFIBLargeIntField *DocIDPRMODEL_REM_DZAKTPR;
	TFIBWideStringField *DocPODO_REM_DZAKTPR;
	TFIBWideStringField *DocPOPOSLE_REM_DZAKTPR;
	TFIBWideStringField *DocDESCR_REM_DZAKTPR;
	TFIBWideStringField *DocPRODAVEC_REM_DZAKTPR;
	TFIBWideStringField *DocNUMGARTALON_REM_DZAKTPR;
	TFIBWideStringField *DocSERNUM3_REM_DZAKTPR;
	TFIBWideStringField *DocSERNUM4_REM_DZAKTPR;
	TFIBWideStringField *DocNUMBAT_REM_DZAKTPR;
	TFIBWideStringField *DocSOST_REM_DZAKTPR;
	TFIBDateField *DocDATEVIPUSK_REM_DZAKTPR;
	TFIBDateField *DocDATE_PRODAGI_REM_DZAKTPR;
	TFIBIntegerField *DocTYPE_REMONT_REM_DZAKTPR;
	TFIBIntegerField *DocKEM_SDANO_REM_DZAKTPR;
	TFIBWideStringField *DocCFC_NAME;
	TFIBWideStringField *DocCFC_CODE;
	TFIBWideStringField *DocDFC_NAME;
	TFIBWideStringField *DocDFC_CODE;
	TFIBWideStringField *DocNAME_SPRODUCER;
	TFIBWideStringField *DocNAME_REM_SPRMODEL;
	TFIBWideStringField *DocCODE_REM_SPRMODEL;
	TFIBWideStringField *DocNEISPR_REM_DZAKTPR;
	TFIBWideStringField *DocNEISPR_REM_Z;
	TFIBLargeIntField *DocAllIDPROJECT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_REM_GALLDOC;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocTIDPRDEFECT_REM_DZAKTPR;
	TFIBWideStringField *DocTCODE_REM_SPRDEFECT;
	TFIBWideStringField *DocTNAME_REM_SPRDEFECT;
	TFIBIntegerField *DocFL_FICTIV_REM_DZAKTPR;
	TFIBWideStringField *DocKLIENT_NAME_REM_DZAKTPR;
	TFIBWideStringField *DocKLIENT_ADR_REM_DZAKTPR;
	TFIBWideStringField *DocKLIENT_PHONE_REM_DZAKTPR;
	TFIBLargeIntField *DocIDDILER_REM_DZAKTPR;
	TFIBWideStringField *DocNAMEKLIENT;
	TFIBWideStringField *DocPOST_ZIP_NAME;
	TFIBSmallIntField *DocFL_OTCHET_POST_REM_DZAKTPR;
	TFIBLargeIntField *DocIDPOST_ZIP_REM_DZAKTPR;
	TFIBSmallIntField *DocFL_NE_OTCH_REM_DZAKTPR;
	TFIBSmallIntField *DocFL_NADO_OTCH_REM_DZAKTPR;
	TFIBSmallIntField *DocFL_PRIG_KREM_REM_DZAKTPR;
	TFIBWideStringField *DocCODE_REM_SMODEL;
	TFIBWideStringField *DocNAME_REM_SPRNEISPR_GRP;
	TFIBDateTimeField *DocPOSPRIEMA_REM_DZAKTPR;
	TFIBLargeIntField *DocIDSELLER_REM_DZAKTPR;
	TFIBWideStringField *DocNAME_SSELLER;
	TFIBWideStringField *DocCFC_NAME_ENG;
	TFIBWideStringField *DocNAME_ENG_REM_SPRNEISPR_GRP;
	TFIBWideStringField *DocKLIENT_EMAIL_REM_DZAKTPR;
	TFIBWideStringField *DocFAMILIYA_REM_DZAKTPR;
	TFIBWideStringField *DocIMYA_REM_DZAKTPR;
	TFIBWideStringField *DocOTCHESTVO_REM_DZAKTPR;
	TFIBLargeIntField *DocTIDPRNEISPR_REM_DZAKTPRT;
	TFIBLargeIntField *DocTIDPRRABOTA_REM_DZAKTPRT;
	TFIBLargeIntField *DocTIDHWOLD_REM_DZAKTPRT;
	TFIBSmallIntField *DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT;
	TFIBWideStringField *DocTNAME_REM_SPRNEISPR;
	TFIBWideStringField *DocTNAME_ENG_REM_SPRNEISPR;
	TFIBWideStringField *DocTCODE_REM_SPRNEISPR;
	TFIBWideStringField *DocTNAME_REM_SPRNEISPR_GRP;
	TFIBWideStringField *DocTNAME_ENG_REM_SPRNEISPR_GRP;
	TFIBWideStringField *DocTNAME_REM_SPRDEFECT_GRP;
	TFIBWideStringField *DocTNAME_ENG_REM_SPRDEFECT_GRP;
	TFIBWideStringField *DocTCODE_REM_SPRRABOTA;
	TFIBWideStringField *DocTNAME_REM_SPRRABOTA;
	TFIBWideStringField *DocTNAME_ENG_REM_SPRRABOTA;
	TFIBWideStringField *DocTNAME_REM_SPRRABOTA_GRP;
	TFIBWideStringField *DocTNAME_ENG_REM_SPRRABOTA_GRP;
	TFIBWideStringField *DocTOLD_NAME_REM_SHARDWARE;
	TFIBIntegerField *DocTOLD_CODE_REM_SHARDWARE;
	TFIBWideStringField *DocTOLD_SERNUM_REM_SHARDWARE;
	TFIBIntegerField *DocTFL_ISP_REM_DZAKTPRT;
	TFIBLargeIntField *DocTIDPRCOND_REM_DZAKTPRT;
	TFIBLargeIntField *DocTIDPRSECTION_REM_DZAKTPRT;
	TFIBWideStringField *DocTCODE_REM_SPRCONDITION;
	TFIBWideStringField *DocTNAME_REM_SPRCONDITION;
	TFIBWideStringField *DocTNAME_ENG_REM_SPRCONDITION;
	TFIBWideStringField *DocTCODE_REM_SPRCOND_GRP;
	TFIBWideStringField *DocTNAME_REM_SPRCOND_GRP;
	TFIBWideStringField *DocTNAME_ENG_REM_SPRCOND_GRP;
	TFIBWideStringField *DocTCODE_REM_SPRSECTION;
	TFIBWideStringField *DocTNAME_REM_SPRSECTION;
	TFIBWideStringField *DocTNAME_ENG_REM_SPRSECTION;
	TFIBWideStringField *DocTCODE_REM_SPRSECTION_GRP;
	TFIBWideStringField *DocTNAME_REM_SPRSECTION_GRP;
	TFIBWideStringField *DocTNAME_ENG_REM_SPRSECTION_GRP;
	TFIBLargeIntField *DocAllIDOBJECT_REM_GALLDOC;
	TFIBWideStringField *DocAllNAME_SOBJECT;
	TFIBLargeIntField *DocTIDTNOM_REM_DZAKTPRT;
	TFIBLargeIntField *DocTIDHW_DONOR_REM_DZAKTPRT;
	TFIBLargeIntField *DocTIDTYP_USEL_REM_DZAKTPRT;
	TFIBWideStringField *DocTDESCR_REM_DZAKTPRT;
	TFIBWideStringField *DocTDONOR_NAME_REM_SHARDWARE;
	TFIBIntegerField *DocTDONOR_CODE_REM_SHARDWARE;
	TFIBWideStringField *DocTDONOR_SERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocTNAME_REM_STYPUSLOV;
	TFIBWideStringField *DocTNAME_STNOM;
	TpFIBDataSet *TypeNom;
	TFIBLargeIntField *TypeNomID_STNOM;
	TFIBWideStringField *TypeNomNAME_STNOM;
	TStringField *DocTNAME_TYPE_NOM_LOOCUP;
	TFIBSmallIntField *DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR;
	TFIBLargeIntField *DocTIDTVZIP_REM_DZAKTPRT;
	TFIBLargeIntField *DocTIDMHRAN_REM_DZAKTPRT;
	TFIBWideStringField *DocTNAME_SMHRAN;
	TFIBWideStringField *DocTNAME_REM_STVZIP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocTKOL_REM_DZAKTPRTChange(TField *Sender);
	void __fastcall DocTPRICE_REM_DZAKTPRTChange(TField *Sender);
	void __fastcall DocTNAME_REM_SPRNEISPRGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall DocTNAME_REM_SPRCONDITIONGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall DocTNAME_REM_SPRSECTIONGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall DocTNAME_REM_SPRDEFECTGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall DocTNAME_REM_SPRRABOTAGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall DocTNAMENOMGetText(TField *Sender, UnicodeString &Text, bool DisplayText);

private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		double OldSummaStr;
		double NewSummaStr;

		double OldSummaMexStr;
		double NewSummaMexStr;
public:		// User declarations
		__fastcall TREM_DMDocZAktPr(TComponent* Owner);

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
extern PACKAGE TREM_DMDocZAktPr *REM_DMDocZAktPr;
//---------------------------------------------------------------------------
#endif
