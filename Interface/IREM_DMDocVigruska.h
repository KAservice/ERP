#ifndef UIREM_DMDocVigruskaH
#define UIREM_DMDocVigruskaH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMDocVigruska)) IREM_DMDocVigruska : public IMainInterface
{
public:
   __property TDataSource * DataSourceDocT = {read = get_DataSourceDocT , write = set_DataSourceDocT};
   virtual TDataSource * get_DataSourceDocT(void)=0;
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT)=0;

   __property TDataSource * DataSourceDocAll = {read = get_DataSourceDocAll , write = set_DataSourceDocAll};
   virtual TDataSource * get_DataSourceDocAll(void)=0;
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll)=0;

   __property TpFIBDataSet * DocAll = {read = get_DocAll , write = set_DocAll};
   virtual TpFIBDataSet * get_DocAll(void)=0;
   virtual void set_DocAll(TpFIBDataSet * DocAll)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TFIBLargeIntField * DocAllID_REM_GUR_VIGR = {read = get_DocAllID_REM_GUR_VIGR , write = set_DocAllID_REM_GUR_VIGR};
   virtual TFIBLargeIntField * get_DocAllID_REM_GUR_VIGR(void)=0;
   virtual void set_DocAllID_REM_GUR_VIGR(TFIBLargeIntField * DocAllID_REM_GUR_VIGR)=0;

   __property TFIBLargeIntField * DocAllIDBASE_REM_GUR_VIGR = {read = get_DocAllIDBASE_REM_GUR_VIGR , write = set_DocAllIDBASE_REM_GUR_VIGR};
   virtual TFIBLargeIntField * get_DocAllIDBASE_REM_GUR_VIGR(void)=0;
   virtual void set_DocAllIDBASE_REM_GUR_VIGR(TFIBLargeIntField * DocAllIDBASE_REM_GUR_VIGR)=0;

   __property TFIBLargeIntField * DocAllIDUSER_REM_GUR_VIGR = {read = get_DocAllIDUSER_REM_GUR_VIGR , write = set_DocAllIDUSER_REM_GUR_VIGR};
   virtual TFIBLargeIntField * get_DocAllIDUSER_REM_GUR_VIGR(void)=0;
   virtual void set_DocAllIDUSER_REM_GUR_VIGR(TFIBLargeIntField * DocAllIDUSER_REM_GUR_VIGR)=0;

   __property TFIBDateTimeField * DocAllPOS_REM_GUR_VIGR = {read = get_DocAllPOS_REM_GUR_VIGR , write = set_DocAllPOS_REM_GUR_VIGR};
   virtual TFIBDateTimeField * get_DocAllPOS_REM_GUR_VIGR(void)=0;
   virtual void set_DocAllPOS_REM_GUR_VIGR(TFIBDateTimeField * DocAllPOS_REM_GUR_VIGR)=0;

   __property TFIBIntegerField * DocAllNUM_REM_GUR_VIGR = {read = get_DocAllNUM_REM_GUR_VIGR , write = set_DocAllNUM_REM_GUR_VIGR};
   virtual TFIBIntegerField * get_DocAllNUM_REM_GUR_VIGR(void)=0;
   virtual void set_DocAllNUM_REM_GUR_VIGR(TFIBIntegerField * DocAllNUM_REM_GUR_VIGR)=0;

   __property TFIBWideStringField * DocAllGUID_TRANSACTION_REM_GUR_VIGR = {read = get_DocAllGUID_TRANSACTION_REM_GUR_VIGR , write = set_DocAllGUID_TRANSACTION_REM_GUR_VIGR};
   virtual TFIBWideStringField * get_DocAllGUID_TRANSACTION_REM_GUR_VIGR(void)=0;
   virtual void set_DocAllGUID_TRANSACTION_REM_GUR_VIGR(TFIBWideStringField * DocAllGUID_TRANSACTION_REM_GUR_VIGR)=0;

   __property TFIBWideStringField * DocAllCODE_STR_VIGR_REM_GUR_VIGR = {read = get_DocAllCODE_STR_VIGR_REM_GUR_VIGR , write = set_DocAllCODE_STR_VIGR_REM_GUR_VIGR};
   virtual TFIBWideStringField * get_DocAllCODE_STR_VIGR_REM_GUR_VIGR(void)=0;
   virtual void set_DocAllCODE_STR_VIGR_REM_GUR_VIGR(TFIBWideStringField * DocAllCODE_STR_VIGR_REM_GUR_VIGR)=0;

   __property TFIBWideStringField * DocAllGUID_VIGR_REM_GUR_VIGR = {read = get_DocAllGUID_VIGR_REM_GUR_VIGR , write = set_DocAllGUID_VIGR_REM_GUR_VIGR};
   virtual TFIBWideStringField * get_DocAllGUID_VIGR_REM_GUR_VIGR(void)=0;
   virtual void set_DocAllGUID_VIGR_REM_GUR_VIGR(TFIBWideStringField * DocAllGUID_VIGR_REM_GUR_VIGR)=0;

   __property TFIBLargeIntField * DocAllIDKLIENT_REM_GUR_VIGR = {read = get_DocAllIDKLIENT_REM_GUR_VIGR , write = set_DocAllIDKLIENT_REM_GUR_VIGR};
   virtual TFIBLargeIntField * get_DocAllIDKLIENT_REM_GUR_VIGR(void)=0;
   virtual void set_DocAllIDKLIENT_REM_GUR_VIGR(TFIBLargeIntField * DocAllIDKLIENT_REM_GUR_VIGR)=0;

   __property TFIBLargeIntField * DocAllIDPRODUCER_REM_GUR_VIGR = {read = get_DocAllIDPRODUCER_REM_GUR_VIGR , write = set_DocAllIDPRODUCER_REM_GUR_VIGR};
   virtual TFIBLargeIntField * get_DocAllIDPRODUCER_REM_GUR_VIGR(void)=0;
   virtual void set_DocAllIDPRODUCER_REM_GUR_VIGR(TFIBLargeIntField * DocAllIDPRODUCER_REM_GUR_VIGR)=0;

   __property TFIBWideStringField * DocAllNAME_SPRODUCER = {read = get_DocAllNAME_SPRODUCER , write = set_DocAllNAME_SPRODUCER};
   virtual TFIBWideStringField * get_DocAllNAME_SPRODUCER(void)=0;
   virtual void set_DocAllNAME_SPRODUCER(TFIBWideStringField * DocAllNAME_SPRODUCER)=0;

   __property TFIBWideStringField * DocAllNAMEKLIENT = {read = get_DocAllNAMEKLIENT , write = set_DocAllNAMEKLIENT};
   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void)=0;
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)=0;

   __property TFIBWideStringField * DocAllNAME_USER = {read = get_DocAllNAME_USER , write = set_DocAllNAME_USER};
   virtual TFIBWideStringField * get_DocAllNAME_USER(void)=0;
   virtual void set_DocAllNAME_USER(TFIBWideStringField * DocAllNAME_USER)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBLargeIntField * DocTID_REM_GUR_VIGRT = {read = get_DocTID_REM_GUR_VIGRT , write = set_DocTID_REM_GUR_VIGRT};
   virtual TFIBLargeIntField * get_DocTID_REM_GUR_VIGRT(void)=0;
   virtual void set_DocTID_REM_GUR_VIGRT(TFIBLargeIntField * DocTID_REM_GUR_VIGRT)=0;

   __property TFIBLargeIntField * DocTIDBASE_REM_GUR_VIGRT = {read = get_DocTIDBASE_REM_GUR_VIGRT , write = set_DocTIDBASE_REM_GUR_VIGRT};
   virtual TFIBLargeIntField * get_DocTIDBASE_REM_GUR_VIGRT(void)=0;
   virtual void set_DocTIDBASE_REM_GUR_VIGRT(TFIBLargeIntField * DocTIDBASE_REM_GUR_VIGRT)=0;

   __property TFIBLargeIntField * DocTIDDOC_REM_GUR_VIGRT = {read = get_DocTIDDOC_REM_GUR_VIGRT , write = set_DocTIDDOC_REM_GUR_VIGRT};
   virtual TFIBLargeIntField * get_DocTIDDOC_REM_GUR_VIGRT(void)=0;
   virtual void set_DocTIDDOC_REM_GUR_VIGRT(TFIBLargeIntField * DocTIDDOC_REM_GUR_VIGRT)=0;

   __property TFIBLargeIntField * DocTIDDOCVIGR_REM_GUR_VIGRT = {read = get_DocTIDDOCVIGR_REM_GUR_VIGRT , write = set_DocTIDDOCVIGR_REM_GUR_VIGRT};
   virtual TFIBLargeIntField * get_DocTIDDOCVIGR_REM_GUR_VIGRT(void)=0;
   virtual void set_DocTIDDOCVIGR_REM_GUR_VIGRT(TFIBLargeIntField * DocTIDDOCVIGR_REM_GUR_VIGRT)=0;

   __property TFIBWideStringField * DocTNAMEFIRM = {read = get_DocTNAMEFIRM , write = set_DocTNAMEFIRM};
   virtual TFIBWideStringField * get_DocTNAMEFIRM(void)=0;
   virtual void set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM)=0;

   __property TFIBWideStringField * DocTNAMESKLAD = {read = get_DocTNAMESKLAD , write = set_DocTNAMESKLAD};
   virtual TFIBWideStringField * get_DocTNAMESKLAD(void)=0;
   virtual void set_DocTNAMESKLAD(TFIBWideStringField * DocTNAMESKLAD)=0;

   __property TFIBWideStringField * DocTNAMEKLIENT = {read = get_DocTNAMEKLIENT , write = set_DocTNAMEKLIENT};
   virtual TFIBWideStringField * get_DocTNAMEKLIENT(void)=0;
   virtual void set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)=0;

   __property TFIBWideStringField * DocTNAME_SINFBASE_OBMEN = {read = get_DocTNAME_SINFBASE_OBMEN , write = set_DocTNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocTNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocTNAME_SINFBASE_OBMEN(TFIBWideStringField * DocTNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocTPREFIKS_NUM_REM_GALLDOC = {read = get_DocTPREFIKS_NUM_REM_GALLDOC , write = set_DocTPREFIKS_NUM_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocTPREFIKS_NUM_REM_GALLDOC(void)=0;
   virtual void set_DocTPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocTPREFIKS_NUM_REM_GALLDOC)=0;

   __property TFIBSmallIntField * DocTPR_REM_GALLDOC = {read = get_DocTPR_REM_GALLDOC , write = set_DocTPR_REM_GALLDOC};
   virtual TFIBSmallIntField * get_DocTPR_REM_GALLDOC(void)=0;
   virtual void set_DocTPR_REM_GALLDOC(TFIBSmallIntField * DocTPR_REM_GALLDOC)=0;

   __property TFIBIntegerField * DocTNUM_REM_GALLDOC = {read = get_DocTNUM_REM_GALLDOC , write = set_DocTNUM_REM_GALLDOC};
   virtual TFIBIntegerField * get_DocTNUM_REM_GALLDOC(void)=0;
   virtual void set_DocTNUM_REM_GALLDOC(TFIBIntegerField * DocTNUM_REM_GALLDOC)=0;

   __property TFIBDateTimeField * DocTPOS_REM_GALLDOC = {read = get_DocTPOS_REM_GALLDOC , write = set_DocTPOS_REM_GALLDOC};
   virtual TFIBDateTimeField * get_DocTPOS_REM_GALLDOC(void)=0;
   virtual void set_DocTPOS_REM_GALLDOC(TFIBDateTimeField * DocTPOS_REM_GALLDOC)=0;

   __property TFIBWideStringField * DocTTDOC_REM_GALLDOC = {read = get_DocTTDOC_REM_GALLDOC , write = set_DocTTDOC_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocTTDOC_REM_GALLDOC(void)=0;
   virtual void set_DocTTDOC_REM_GALLDOC(TFIBWideStringField * DocTTDOC_REM_GALLDOC)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBWideStringField * DocTOUT_INFO = {read = get_DocTOUT_INFO , write = set_DocTOUT_INFO};
   virtual TFIBWideStringField * get_DocTOUT_INFO(void)=0;
   virtual void set_DocTOUT_INFO(TFIBWideStringField * DocTOUT_INFO)=0;

   __property TFIBLargeIntField * DocTOUT_IDZ = {read = get_DocTOUT_IDZ , write = set_DocTOUT_IDZ};
   virtual TFIBLargeIntField * get_DocTOUT_IDZ(void)=0;
   virtual void set_DocTOUT_IDZ(TFIBLargeIntField * DocTOUT_IDZ)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   virtual bool NewDoc(void)=0;
   virtual bool OpenDoc(__int64 IdDoc)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void TableAppend(void)=0;
   virtual void TableDelete(void)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IREM_DMDocVigruska __uuidof(IREM_DMDocVigruska)
#endif
