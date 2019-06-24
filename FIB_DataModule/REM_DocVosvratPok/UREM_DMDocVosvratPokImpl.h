#ifndef UREM_DMDocVosvratPokImplH
#define UREM_DMDocVosvratPokImplH
#include "IREM_DMDocVosvratPok.h"
#include "UREM_DMDocVosvratPok.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocVosvratPokImpl)) TREM_DMDocVosvratPokImpl : public IREM_DMDocVosvratPok
{
public:
   TREM_DMDocVosvratPokImpl();
   ~TREM_DMDocVosvratPokImpl();
   TREM_DMDocVosvratPok * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IREM_DMDocVosvratPok
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBLargeIntField * get_DocAllID_REM_GALLDOC(void);
   virtual void set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDBASE_REM_GALLDOC(void);
   virtual void set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDFIRM_REM_GALLDOC(void);
   virtual void set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDSKLAD_REM_GALLDOC(void);
   virtual void set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDKLIENT_REM_GALLDOC(void);
   virtual void set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDUSER_REM_GALLDOC(void);
   virtual void set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC);

   virtual TFIBDateTimeField * get_DocAllPOS_REM_GALLDOC(void);
   virtual void set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC);

   virtual TFIBIntegerField * get_DocAllNUM_REM_GALLDOC(void);
   virtual void set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC);

   virtual TFIBSmallIntField * get_DocAllPR_REM_GALLDOC(void);
   virtual void set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocAllTDOC_REM_GALLDOC(void);
   virtual void set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOCOSN_REM_GALLDOC(void);
   virtual void set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC);

   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC_REM_GALLDOC(void);
   virtual void set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDEXTDOC_REM_GALLDOC(void);
   virtual void set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC);

   virtual TFIBBCDField * get_DocAllSUM_REM_GALLDOC(void);
   virtual void set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDPROJECT_REM_GALLDOC(void);
   virtual void set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_REM_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TpFIBDataSet * get_DocOsn(void);
   virtual void set_DocOsn(TpFIBDataSet * DocOsn);

   virtual TDataSource * get_DataSourceDocOsn(void);
   virtual void set_DataSourceDocOsn(TDataSource * DataSourceDocOsn);

   virtual TFIBLargeIntField * get_DocID_REM_DVPOK(void);
   virtual void set_DocID_REM_DVPOK(TFIBLargeIntField * DocID_REM_DVPOK);

   virtual TFIBLargeIntField * get_DocIDBASE_REM_DVPOK(void);
   virtual void set_DocIDBASE_REM_DVPOK(TFIBLargeIntField * DocIDBASE_REM_DVPOK);

   virtual TFIBWideStringField * get_DocGID_REM_DVPOK(void);
   virtual void set_DocGID_REM_DVPOK(TFIBWideStringField * DocGID_REM_DVPOK);

   virtual TFIBLargeIntField * get_DocIDDOC_REM_DVPOK(void);
   virtual void set_DocIDDOC_REM_DVPOK(TFIBLargeIntField * DocIDDOC_REM_DVPOK);

   virtual TFIBLargeIntField * get_DocIDTYPEPRICE_REM_DVPOK(void);
   virtual void set_DocIDTYPEPRICE_REM_DVPOK(TFIBLargeIntField * DocIDTYPEPRICE_REM_DVPOK);

   virtual TFIBLargeIntField * get_DocIDRTYPEPRICE_REM_DVPOK(void);
   virtual void set_DocIDRTYPEPRICE_REM_DVPOK(TFIBLargeIntField * DocIDRTYPEPRICE_REM_DVPOK);

   virtual TFIBLargeIntField * get_DocIDCARD_REM_DVPOK(void);
   virtual void set_DocIDCARD_REM_DVPOK(TFIBLargeIntField * DocIDCARD_REM_DVPOK);

   virtual TFIBWideStringField * get_DocKLIENT_NAME_REM_DVPOK(void);
   virtual void set_DocKLIENT_NAME_REM_DVPOK(TFIBWideStringField * DocKLIENT_NAME_REM_DVPOK);

   virtual TFIBWideStringField * get_DocKLIENT_ADR_REM_DVPOK(void);
   virtual void set_DocKLIENT_ADR_REM_DVPOK(TFIBWideStringField * DocKLIENT_ADR_REM_DVPOK);

   virtual TFIBWideStringField * get_DocKLIENT_PHONE_REM_DVPOK(void);
   virtual void set_DocKLIENT_PHONE_REM_DVPOK(TFIBWideStringField * DocKLIENT_PHONE_REM_DVPOK);

   virtual TFIBWideStringField * get_DocKLIENT_PASSPORT_REM_DVPOK(void);
   virtual void set_DocKLIENT_PASSPORT_REM_DVPOK(TFIBWideStringField * DocKLIENT_PASSPORT_REM_DVPOK);

   virtual TFIBWideStringField * get_DocPRICHINA_REM_DVPOK(void);
   virtual void set_DocPRICHINA_REM_DVPOK(TFIBWideStringField * DocPRICHINA_REM_DVPOK);

   virtual TFIBWideStringField * get_DocDESCR_REM_DVPOK(void);
   virtual void set_DocDESCR_REM_DVPOK(TFIBWideStringField * DocDESCR_REM_DVPOK);

   virtual TFIBWideStringField * get_DocNUMDOCSALE_REM_DVPOK(void);
   virtual void set_DocNUMDOCSALE_REM_DVPOK(TFIBWideStringField * DocNUMDOCSALE_REM_DVPOK);

   virtual TFIBDateTimeField * get_DocPOSDOCSALE_REM_DVPOK(void);
   virtual void set_DocPOSDOCSALE_REM_DVPOK(TFIBDateTimeField * DocPOSDOCSALE_REM_DVPOK);

   virtual TFIBWideStringField * get_DocNUMDOCKL_REM_DVPOK(void);
   virtual void set_DocNUMDOCKL_REM_DVPOK(TFIBWideStringField * DocNUMDOCKL_REM_DVPOK);

   virtual TFIBDateTimeField * get_DocPOSDOCKL_REM_DVPOK(void);
   virtual void set_DocPOSDOCKL_REM_DVPOK(TFIBDateTimeField * DocPOSDOCKL_REM_DVPOK);

   virtual TFIBWideStringField * get_DocNAME_SDISCOUNT_CARD(void);
   virtual void set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD);

   virtual TFIBWideStringField * get_DocOsnTDOC_REM_GALLDOC(void);
   virtual void set_DocOsnTDOC_REM_GALLDOC(TFIBWideStringField * DocOsnTDOC_REM_GALLDOC);

   virtual TFIBDateTimeField * get_DocOsnPOS_REM_GALLDOC(void);
   virtual void set_DocOsnPOS_REM_GALLDOC(TFIBDateTimeField * DocOsnPOS_REM_GALLDOC);

   virtual TFIBIntegerField * get_DocOsnNUM_REM_GALLDOC(void);
   virtual void set_DocOsnNUM_REM_GALLDOC(TFIBIntegerField * DocOsnNUM_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocTID_REM_DVPOKT(void);
   virtual void set_DocTID_REM_DVPOKT(TFIBLargeIntField * DocTID_REM_DVPOKT);

   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DVPOKT(void);
   virtual void set_DocTIDBASE_REM_DVPOKT(TFIBLargeIntField * DocTIDBASE_REM_DVPOKT);

   virtual TFIBWideStringField * get_DocTGID_REM_DVPOKT(void);
   virtual void set_DocTGID_REM_DVPOKT(TFIBWideStringField * DocTGID_REM_DVPOKT);

   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DVPOKT(void);
   virtual void set_DocTIDDOC_REM_DVPOKT(TFIBLargeIntField * DocTIDDOC_REM_DVPOKT);

   virtual TFIBLargeIntField * get_DocTIDNOM_REM_DVPOKT(void);
   virtual void set_DocTIDNOM_REM_DVPOKT(TFIBLargeIntField * DocTIDNOM_REM_DVPOKT);

   virtual TFIBLargeIntField * get_DocTIDED_REM_DVPOKT(void);
   virtual void set_DocTIDED_REM_DVPOKT(TFIBLargeIntField * DocTIDED_REM_DVPOKT);

   virtual TFIBLargeIntField * get_DocTIDHW_REM_DVPOKT(void);
   virtual void set_DocTIDHW_REM_DVPOKT(TFIBLargeIntField * DocTIDHW_REM_DVPOKT);

   virtual TFIBSmallIntField * get_DocTDVREG_REM_DVPOKT(void);
   virtual void set_DocTDVREG_REM_DVPOKT(TFIBSmallIntField * DocTDVREG_REM_DVPOKT);

   virtual TFIBBCDField * get_DocTKOL_REM_DVPOKT(void);
   virtual void set_DocTKOL_REM_DVPOKT(TFIBBCDField * DocTKOL_REM_DVPOKT);

   virtual TFIBBCDField * get_DocTKF_REM_DVPOKT(void);
   virtual void set_DocTKF_REM_DVPOKT(TFIBBCDField * DocTKF_REM_DVPOKT);

   virtual TFIBBCDField * get_DocTPRICE_REM_DVPOKT(void);
   virtual void set_DocTPRICE_REM_DVPOKT(TFIBBCDField * DocTPRICE_REM_DVPOKT);

   virtual TFIBBCDField * get_DocTSUM_REM_DVPOKT(void);
   virtual void set_DocTSUM_REM_DVPOKT(TFIBBCDField * DocTSUM_REM_DVPOKT);

   virtual TFIBIntegerField * get_DocTNDS_REM_DVPOKT(void);
   virtual void set_DocTNDS_REM_DVPOKT(TFIBIntegerField * DocTNDS_REM_DVPOKT);

   virtual TFIBBCDField * get_DocTSUMNDS_REM_DVPOKT(void);
   virtual void set_DocTSUMNDS_REM_DVPOKT(TFIBBCDField * DocTSUMNDS_REM_DVPOKT);

   virtual TFIBBCDField * get_DocTPRSK_REM_DVPOKT(void);
   virtual void set_DocTPRSK_REM_DVPOKT(TFIBBCDField * DocTPRSK_REM_DVPOKT);

   virtual TFIBBCDField * get_DocTSUMSK_REM_DVPOKT(void);
   virtual void set_DocTSUMSK_REM_DVPOKT(TFIBBCDField * DocTSUMSK_REM_DVPOKT);

   virtual TFIBBCDField * get_DocTPRSK_CARD_REM_DVPOKT(void);
   virtual void set_DocTPRSK_CARD_REM_DVPOKT(TFIBBCDField * DocTPRSK_CARD_REM_DVPOKT);

   virtual TFIBBCDField * get_DocTPRSK_AUTO_REM_DVPOKT(void);
   virtual void set_DocTPRSK_AUTO_REM_DVPOKT(TFIBBCDField * DocTPRSK_AUTO_REM_DVPOKT);

   virtual TFIBBCDField * get_DocTPRSK_HAND_REM_DVPOKT(void);
   virtual void set_DocTPRSK_HAND_REM_DVPOKT(TFIBBCDField * DocTPRSK_HAND_REM_DVPOKT);

   virtual TFIBSmallIntField * get_DocTNO_SK_REM_DVPOKT(void);
   virtual void set_DocTNO_SK_REM_DVPOKT(TFIBSmallIntField * DocTNO_SK_REM_DVPOKT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual TFIBWideStringField * get_DocTNAME_REM_SHARDWARE(void);
   virtual void set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE);

   virtual TFIBIntegerField * get_DocTCODE_REM_SHARDWARE(void);
   virtual void set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocTSERNUM_REM_SHARDWARE(void);
   virtual void set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElementaMaster(void);
   virtual void set_IdElementaMaster(__int64 IdElementaMaster);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual bool get_IsmPrice(void);
   virtual void set_IsmPrice(bool IsmPrice);

   virtual bool get_IsmSum(void);
   virtual void set_IsmSum(bool IsmSum);

   virtual bool get_SkladRozn(void);
   virtual void set_SkladRozn(bool SkladRozn);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual void NewDoc(void);
   virtual void CopyDoc(__int64 id_doc);
   virtual void OpenDoc(__int64 id);
   virtual void OpenDocOsn(void);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual double Summa(void);
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
};
#define CLSID_TREM_DMDocVosvratPokImpl __uuidof(TREM_DMDocVosvratPokImpl)
#endif
