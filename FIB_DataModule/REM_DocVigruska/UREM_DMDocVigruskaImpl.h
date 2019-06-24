#ifndef UREM_DMDocVigruskaImplH
#define UREM_DMDocVigruskaImplH
#include "IREM_DMDocVigruska.h"
#include "UREM_DMDocVigruska.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocVigruskaImpl)) TREM_DMDocVigruskaImpl : public IREM_DMDocVigruska
{
public:
   TREM_DMDocVigruskaImpl();
   ~TREM_DMDocVigruskaImpl();
   TREM_DMDocVigruska * Object;
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

//IREM_DMDocVigruska
   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

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

   virtual TFIBLargeIntField * get_DocAllID_REM_GUR_VIGR(void);
   virtual void set_DocAllID_REM_GUR_VIGR(TFIBLargeIntField * DocAllID_REM_GUR_VIGR);

   virtual TFIBLargeIntField * get_DocAllIDBASE_REM_GUR_VIGR(void);
   virtual void set_DocAllIDBASE_REM_GUR_VIGR(TFIBLargeIntField * DocAllIDBASE_REM_GUR_VIGR);

   virtual TFIBLargeIntField * get_DocAllIDUSER_REM_GUR_VIGR(void);
   virtual void set_DocAllIDUSER_REM_GUR_VIGR(TFIBLargeIntField * DocAllIDUSER_REM_GUR_VIGR);

   virtual TFIBDateTimeField * get_DocAllPOS_REM_GUR_VIGR(void);
   virtual void set_DocAllPOS_REM_GUR_VIGR(TFIBDateTimeField * DocAllPOS_REM_GUR_VIGR);

   virtual TFIBIntegerField * get_DocAllNUM_REM_GUR_VIGR(void);
   virtual void set_DocAllNUM_REM_GUR_VIGR(TFIBIntegerField * DocAllNUM_REM_GUR_VIGR);

   virtual TFIBWideStringField * get_DocAllGUID_TRANSACTION_REM_GUR_VIGR(void);
   virtual void set_DocAllGUID_TRANSACTION_REM_GUR_VIGR(TFIBWideStringField * DocAllGUID_TRANSACTION_REM_GUR_VIGR);

   virtual TFIBWideStringField * get_DocAllCODE_STR_VIGR_REM_GUR_VIGR(void);
   virtual void set_DocAllCODE_STR_VIGR_REM_GUR_VIGR(TFIBWideStringField * DocAllCODE_STR_VIGR_REM_GUR_VIGR);

   virtual TFIBWideStringField * get_DocAllGUID_VIGR_REM_GUR_VIGR(void);
   virtual void set_DocAllGUID_VIGR_REM_GUR_VIGR(TFIBWideStringField * DocAllGUID_VIGR_REM_GUR_VIGR);

   virtual TFIBLargeIntField * get_DocAllIDKLIENT_REM_GUR_VIGR(void);
   virtual void set_DocAllIDKLIENT_REM_GUR_VIGR(TFIBLargeIntField * DocAllIDKLIENT_REM_GUR_VIGR);

   virtual TFIBLargeIntField * get_DocAllIDPRODUCER_REM_GUR_VIGR(void);
   virtual void set_DocAllIDPRODUCER_REM_GUR_VIGR(TFIBLargeIntField * DocAllIDPRODUCER_REM_GUR_VIGR);

   virtual TFIBWideStringField * get_DocAllNAME_SPRODUCER(void);
   virtual void set_DocAllNAME_SPRODUCER(TFIBWideStringField * DocAllNAME_SPRODUCER);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocAllNAME_USER(void);
   virtual void set_DocAllNAME_USER(TFIBWideStringField * DocAllNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBLargeIntField * get_DocTID_REM_GUR_VIGRT(void);
   virtual void set_DocTID_REM_GUR_VIGRT(TFIBLargeIntField * DocTID_REM_GUR_VIGRT);

   virtual TFIBLargeIntField * get_DocTIDBASE_REM_GUR_VIGRT(void);
   virtual void set_DocTIDBASE_REM_GUR_VIGRT(TFIBLargeIntField * DocTIDBASE_REM_GUR_VIGRT);

   virtual TFIBLargeIntField * get_DocTIDDOC_REM_GUR_VIGRT(void);
   virtual void set_DocTIDDOC_REM_GUR_VIGRT(TFIBLargeIntField * DocTIDDOC_REM_GUR_VIGRT);

   virtual TFIBLargeIntField * get_DocTIDDOCVIGR_REM_GUR_VIGRT(void);
   virtual void set_DocTIDDOCVIGR_REM_GUR_VIGRT(TFIBLargeIntField * DocTIDDOCVIGR_REM_GUR_VIGRT);

   virtual TFIBWideStringField * get_DocTNAMEFIRM(void);
   virtual void set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM);

   virtual TFIBWideStringField * get_DocTNAMESKLAD(void);
   virtual void set_DocTNAMESKLAD(TFIBWideStringField * DocTNAMESKLAD);

   virtual TFIBWideStringField * get_DocTNAMEKLIENT(void);
   virtual void set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT);

   virtual TFIBWideStringField * get_DocTNAME_SINFBASE_OBMEN(void);
   virtual void set_DocTNAME_SINFBASE_OBMEN(TFIBWideStringField * DocTNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocTPREFIKS_NUM_REM_GALLDOC(void);
   virtual void set_DocTPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocTPREFIKS_NUM_REM_GALLDOC);

   virtual TFIBSmallIntField * get_DocTPR_REM_GALLDOC(void);
   virtual void set_DocTPR_REM_GALLDOC(TFIBSmallIntField * DocTPR_REM_GALLDOC);

   virtual TFIBIntegerField * get_DocTNUM_REM_GALLDOC(void);
   virtual void set_DocTNUM_REM_GALLDOC(TFIBIntegerField * DocTNUM_REM_GALLDOC);

   virtual TFIBDateTimeField * get_DocTPOS_REM_GALLDOC(void);
   virtual void set_DocTPOS_REM_GALLDOC(TFIBDateTimeField * DocTPOS_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocTTDOC_REM_GALLDOC(void);
   virtual void set_DocTTDOC_REM_GALLDOC(TFIBWideStringField * DocTTDOC_REM_GALLDOC);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBWideStringField * get_DocTOUT_INFO(void);
   virtual void set_DocTOUT_INFO(TFIBWideStringField * DocTOUT_INFO);

   virtual TFIBLargeIntField * get_DocTOUT_IDZ(void);
   virtual void set_DocTOUT_IDZ(TFIBLargeIntField * DocTOUT_IDZ);

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
#define CLSID_TREM_DMDocVigruskaImpl __uuidof(TREM_DMDocVigruskaImpl)
#endif
