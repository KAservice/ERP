#ifndef UREM_DMDocRegOtchetPostImplH
#define UREM_DMDocRegOtchetPostImplH
#include "IREM_DMDocRegOtchetPost.h"
#include "UREM_DMDocRegOtchetPost.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocRegOtchetPostImpl)) TREM_DMDocRegOtchetPostImpl : public IREM_DMDocRegOtchetPost
{
public:
   TREM_DMDocRegOtchetPostImpl();
   ~TREM_DMDocRegOtchetPostImpl();
   TREM_DMDocRegOtchetPost * Object;
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

//IREM_DMDocRegOtchetPost
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

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

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

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_DocID_REM_DRG_OTCHPOST(void);
   virtual void set_DocID_REM_DRG_OTCHPOST(TFIBLargeIntField * DocID_REM_DRG_OTCHPOST);

   virtual TFIBLargeIntField * get_DocIDBASE_REM_DRG_OTCHPOST(void);
   virtual void set_DocIDBASE_REM_DRG_OTCHPOST(TFIBLargeIntField * DocIDBASE_REM_DRG_OTCHPOST);

   virtual TFIBLargeIntField * get_DocIDDOC_REM_DRG_OTCHPOST(void);
   virtual void set_DocIDDOC_REM_DRG_OTCHPOST(TFIBLargeIntField * DocIDDOC_REM_DRG_OTCHPOST);

   virtual TFIBWideStringField * get_DocDESCR_REM_DRG_OTCHPOST(void);
   virtual void set_DocDESCR_REM_DRG_OTCHPOST(TFIBWideStringField * DocDESCR_REM_DRG_OTCHPOST);

   virtual TFIBLargeIntField * get_DocTID_REM_DRG_OTCHPOSTT(void);
   virtual void set_DocTID_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTID_REM_DRG_OTCHPOSTT);

   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DRG_OTCHPOSTT(void);
   virtual void set_DocTIDBASE_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDBASE_REM_DRG_OTCHPOSTT);

   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DRG_OTCHPOSTT(void);
   virtual void set_DocTIDDOC_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDDOC_REM_DRG_OTCHPOSTT);

   virtual TFIBSmallIntField * get_DocTTDV_REM_DRG_OTCHPOSTT(void);
   virtual void set_DocTTDV_REM_DRG_OTCHPOSTT(TFIBSmallIntField * DocTTDV_REM_DRG_OTCHPOSTT);

   virtual TFIBLargeIntField * get_DocTIDFIRM_REM_DRG_OTCHPOSTT(void);
   virtual void set_DocTIDFIRM_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDFIRM_REM_DRG_OTCHPOSTT);

   virtual TFIBLargeIntField * get_DocTIDSKLAD_REM_DRG_OTCHPOSTT(void);
   virtual void set_DocTIDSKLAD_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDSKLAD_REM_DRG_OTCHPOSTT);

   virtual TFIBLargeIntField * get_DocTIDPOST_REM_DRG_OTCHPOSTT(void);
   virtual void set_DocTIDPOST_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDPOST_REM_DRG_OTCHPOSTT);

   virtual TFIBLargeIntField * get_DocTIDDOCPOST_REM_DRG_OTCHPOSTT(void);
   virtual void set_DocTIDDOCPOST_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDDOCPOST_REM_DRG_OTCHPOSTT);

   virtual TFIBLargeIntField * get_DocTIDNOM_REM_DRG_OTCHPOSTT(void);
   virtual void set_DocTIDNOM_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDNOM_REM_DRG_OTCHPOSTT);

   virtual TFIBBCDField * get_DocTKOL_REM_DRG_OTCHPOSTT(void);
   virtual void set_DocTKOL_REM_DRG_OTCHPOSTT(TFIBBCDField * DocTKOL_REM_DRG_OTCHPOSTT);

   virtual TFIBBCDField * get_DocTSUM_REM_DRG_OTCHPOSTT(void);
   virtual void set_DocTSUM_REM_DRG_OTCHPOSTT(TFIBBCDField * DocTSUM_REM_DRG_OTCHPOSTT);

   virtual TFIBWideStringField * get_DocTNAMEFIRM(void);
   virtual void set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM);

   virtual TFIBWideStringField * get_DocTNAMESKLAD(void);
   virtual void set_DocTNAMESKLAD(TFIBWideStringField * DocTNAMESKLAD);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBWideStringField * get_DocTPREFIKS_NUM_REM_GALLDOC(void);
   virtual void set_DocTPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocTPREFIKS_NUM_REM_GALLDOC);

   virtual TFIBIntegerField * get_DocTNUM_REM_GALLDOC(void);
   virtual void set_DocTNUM_REM_GALLDOC(TFIBIntegerField * DocTNUM_REM_GALLDOC);

   virtual TFIBDateTimeField * get_DocTPOS_REM_GALLDOC(void);
   virtual void set_DocTPOS_REM_GALLDOC(TFIBDateTimeField * DocTPOS_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocTNAMEKLIENT(void);
   virtual void set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual bool NewDoc(void);
   virtual bool OpenDoc(__int64 IdDoc);
   virtual bool SaveDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void TableAppend(void);
   virtual void TableDelete(void);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TREM_DMDocRegOtchetPostImpl __uuidof(TREM_DMDocRegOtchetPostImpl)
#endif
