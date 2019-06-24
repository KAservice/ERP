#ifndef UREM_DMDocPrihNaklImplH
#define UREM_DMDocPrihNaklImplH
#include "IREM_DMDocPrihNakl.h"
#include "UREM_DMDocPrihNakl.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocPrihNaklImpl)) TREM_DMDocPrihNaklImpl : public IREM_DMDocPrihNakl
{
public:
   TREM_DMDocPrihNaklImpl();
   ~TREM_DMDocPrihNaklImpl();
   TREM_DMDocPrihNakl * Object;
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

//IREM_DMDocPrihNakl
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

   virtual TFIBLargeIntField * get_DocID_REM_DPRN(void);
   virtual void set_DocID_REM_DPRN(TFIBLargeIntField * DocID_REM_DPRN);

   virtual TFIBLargeIntField * get_DocIDBASE_REM_DPRN(void);
   virtual void set_DocIDBASE_REM_DPRN(TFIBLargeIntField * DocIDBASE_REM_DPRN);

   virtual TFIBLargeIntField * get_DocIDDOC_REM_DPRN(void);
   virtual void set_DocIDDOC_REM_DPRN(TFIBLargeIntField * DocIDDOC_REM_DPRN);

   virtual TFIBWideStringField * get_DocGID_REM_DPRN(void);
   virtual void set_DocGID_REM_DPRN(TFIBWideStringField * DocGID_REM_DPRN);

   virtual TFIBLargeIntField * get_DocIDTPRICE_REM_DPRN(void);
   virtual void set_DocIDTPRICE_REM_DPRN(TFIBLargeIntField * DocIDTPRICE_REM_DPRN);

   virtual TFIBLargeIntField * get_DocIDRTPRICE_REM_DPRN(void);
   virtual void set_DocIDRTPRICE_REM_DPRN(TFIBLargeIntField * DocIDRTPRICE_REM_DPRN);

   virtual TFIBBCDField * get_DocRSUM_REM_DPRN(void);
   virtual void set_DocRSUM_REM_DPRN(TFIBBCDField * DocRSUM_REM_DPRN);

   virtual TFIBWideStringField * get_DocPRIM_REM_DPRN(void);
   virtual void set_DocPRIM_REM_DPRN(TFIBWideStringField * DocPRIM_REM_DPRN);

   virtual TFIBWideStringField * get_DocNUMDOCPOST_REM_DPRN(void);
   virtual void set_DocNUMDOCPOST_REM_DPRN(TFIBWideStringField * DocNUMDOCPOST_REM_DPRN);

   virtual TFIBDateTimeField * get_DocPOSDOCPOST_REM_DPRN(void);
   virtual void set_DocPOSDOCPOST_REM_DPRN(TFIBDateTimeField * DocPOSDOCPOST_REM_DPRN);

   virtual TFIBLargeIntField * get_DocTID_REM_DPRNT(void);
   virtual void set_DocTID_REM_DPRNT(TFIBLargeIntField * DocTID_REM_DPRNT);

   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DPRNT(void);
   virtual void set_DocTIDBASE_REM_DPRNT(TFIBLargeIntField * DocTIDBASE_REM_DPRNT);

   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DPRNT(void);
   virtual void set_DocTIDDOC_REM_DPRNT(TFIBLargeIntField * DocTIDDOC_REM_DPRNT);

   virtual TFIBWideStringField * get_DocTGID_REM_DPRNT(void);
   virtual void set_DocTGID_REM_DPRNT(TFIBWideStringField * DocTGID_REM_DPRNT);

   virtual TFIBLargeIntField * get_DocTIDNOM_REM_DPRNT(void);
   virtual void set_DocTIDNOM_REM_DPRNT(TFIBLargeIntField * DocTIDNOM_REM_DPRNT);

   virtual TFIBLargeIntField * get_DocTIDED_REM_DPRNT(void);
   virtual void set_DocTIDED_REM_DPRNT(TFIBLargeIntField * DocTIDED_REM_DPRNT);

   virtual TFIBLargeIntField * get_DocTIDHW_REM_DPRNT(void);
   virtual void set_DocTIDHW_REM_DPRNT(TFIBLargeIntField * DocTIDHW_REM_DPRNT);

   virtual TFIBBCDField * get_DocTKOL_REM_DPRNT(void);
   virtual void set_DocTKOL_REM_DPRNT(TFIBBCDField * DocTKOL_REM_DPRNT);

   virtual TFIBBCDField * get_DocTKF_REM_DPRNT(void);
   virtual void set_DocTKF_REM_DPRNT(TFIBBCDField * DocTKF_REM_DPRNT);

   virtual TFIBBCDField * get_DocTPRICE_REM_DPRNT(void);
   virtual void set_DocTPRICE_REM_DPRNT(TFIBBCDField * DocTPRICE_REM_DPRNT);

   virtual TFIBBCDField * get_DocTSUM_REM_DPRNT(void);
   virtual void set_DocTSUM_REM_DPRNT(TFIBBCDField * DocTSUM_REM_DPRNT);

   virtual TFIBBCDField * get_DocTNAC_REM_DPRNT(void);
   virtual void set_DocTNAC_REM_DPRNT(TFIBBCDField * DocTNAC_REM_DPRNT);

   virtual TFIBBCDField * get_DocTRPRICE_REM_DPRNT(void);
   virtual void set_DocTRPRICE_REM_DPRNT(TFIBBCDField * DocTRPRICE_REM_DPRNT);

   virtual TFIBBCDField * get_DocTRSUM_REM_DPRNT(void);
   virtual void set_DocTRSUM_REM_DPRNT(TFIBBCDField * DocTRSUM_REM_DPRNT);

   virtual TFIBIntegerField * get_DocTNDS_REM_DPRNT(void);
   virtual void set_DocTNDS_REM_DPRNT(TFIBIntegerField * DocTNDS_REM_DPRNT);

   virtual TFIBBCDField * get_DocTSUMNDS_REM_DPRNT(void);
   virtual void set_DocTSUMNDS_REM_DPRNT(TFIBBCDField * DocTSUMNDS_REM_DPRNT);

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

   virtual TFIBIntegerField * get_DocTCODE_REM_SHARDWARE(void);
   virtual void set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocTSERNUM_REM_SHARDWARE(void);
   virtual void set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBWideStringField * get_DocTNAME_REM_SHARDWARE(void);
   virtual void set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_DocTDVREG_REM_DPRNT(void);
   virtual void set_DocTDVREG_REM_DPRNT(TFIBSmallIntField * DocTDVREG_REM_DPRNT);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC);

   virtual TFIBSmallIntField * get_DocFL_TREB_OTCHET_REM_DPRN(void);
   virtual void set_DocFL_TREB_OTCHET_REM_DPRN(TFIBSmallIntField * DocFL_TREB_OTCHET_REM_DPRN);

   virtual TFIBSmallIntField * get_DocFL_OTV_HRAN_REM_DPRN(void);
   virtual void set_DocFL_OTV_HRAN_REM_DPRN(TFIBSmallIntField * DocFL_OTV_HRAN_REM_DPRN);

   virtual TFIBLargeIntField * get_DocTIDCQT_REM_DPRNT(void);
   virtual void set_DocTIDCQT_REM_DPRNT(TFIBLargeIntField * DocTIDCQT_REM_DPRNT);

   virtual TFIBSmallIntField * get_DocTFL_ADD_IN_SOBORUD_SNOM(void);
   virtual void set_DocTFL_ADD_IN_SOBORUD_SNOM(TFIBSmallIntField * DocTFL_ADD_IN_SOBORUD_SNOM);

   virtual TFIBLargeIntField * get_DocTID_REM_CQUERY(void);
   virtual void set_DocTID_REM_CQUERY(TFIBLargeIntField * DocTID_REM_CQUERY);

   virtual TFIBWideStringField * get_DocTNAME_REM_CQUERY(void);
   virtual void set_DocTNAME_REM_CQUERY(TFIBWideStringField * DocTNAME_REM_CQUERY);

   virtual TFIBIntegerField * get_DocTNUM_REM_CQUERY(void);
   virtual void set_DocTNUM_REM_CQUERY(TFIBIntegerField * DocTNUM_REM_CQUERY);

   virtual TFIBDateTimeField * get_DocTPOS_REM_CQUERY(void);
   virtual void set_DocTPOS_REM_CQUERY(TFIBDateTimeField * DocTPOS_REM_CQUERY);

   virtual TFIBWideStringField * get_DocTKLIENT_NAME_REM_CQUERY(void);
   virtual void set_DocTKLIENT_NAME_REM_CQUERY(TFIBWideStringField * DocTKLIENT_NAME_REM_CQUERY);

   virtual TFIBWideStringField * get_DocTNAME_MODEL_REM_CQUERY(void);
   virtual void set_DocTNAME_MODEL_REM_CQUERY(TFIBWideStringField * DocTNAME_MODEL_REM_CQUERY);

   virtual TFIBWideStringField * get_DocTNUM_STR_ZAK_POST_REM_CQUERY(void);
   virtual void set_DocTNUM_STR_ZAK_POST_REM_CQUERY(TFIBWideStringField * DocTNUM_STR_ZAK_POST_REM_CQUERY);

   virtual TFIBLargeIntField * get_DocTID_REM_Z(void);
   virtual void set_DocTID_REM_Z(TFIBLargeIntField * DocTID_REM_Z);

   virtual TFIBWideStringField * get_DocTNAME_REM_Z(void);
   virtual void set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z);

   virtual TFIBWideStringField * get_DocTPREFIKS_NUM_REM_Z(void);
   virtual void set_DocTPREFIKS_NUM_REM_Z(TFIBWideStringField * DocTPREFIKS_NUM_REM_Z);

   virtual TFIBIntegerField * get_DocTNUM_REM_Z(void);
   virtual void set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z);

   virtual TFIBDateTimeField * get_DocTPOS_REM_Z(void);
   virtual void set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z);

   virtual TFIBWideStringField * get_DocTMODEL_REM_Z(void);
   virtual void set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z);

   virtual TFIBWideStringField * get_DocTSERNUM_REM_Z(void);
   virtual void set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z);

   virtual TFIBWideStringField * get_DocTSERNUM2_REM_Z(void);
   virtual void set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z);

   virtual TFIBWideStringField * get_DocTSTR_CODE_VIGR_REM_Z_1(void);
   virtual void set_DocTSTR_CODE_VIGR_REM_Z_1(TFIBWideStringField * DocTSTR_CODE_VIGR_REM_Z_1);

   virtual TFIBLargeIntField * get_DocTIDTNOM_REM_DPRNT(void);
   virtual void set_DocTIDTNOM_REM_DPRNT(TFIBLargeIntField * DocTIDTNOM_REM_DPRNT);

   virtual TFIBLargeIntField * get_DocTIDMHRAN_REM_DPRNT(void);
   virtual void set_DocTIDMHRAN_REM_DPRNT(TFIBLargeIntField * DocTIDMHRAN_REM_DPRNT);

   virtual TFIBWideStringField * get_DocTNAME_SMHRAN(void);
   virtual void set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN);

   virtual TFIBWideStringField * get_DocTNAME_STNOM(void);
   virtual void set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM);

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
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual double Summa(void);
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
};
#define CLSID_TREM_DMDocPrihNaklImpl __uuidof(TREM_DMDocPrihNaklImpl)
#endif
