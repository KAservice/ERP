#ifndef UIREM_DMDocProverkaH
#define UIREM_DMDocProverkaH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMDocProverka)) IREM_DMDocProverka : public IMainInterface
{
public:
   __property TDataSource * DataSourceDocAll = {read = get_DataSourceDocAll , write = set_DataSourceDocAll};
   virtual TDataSource * get_DataSourceDocAll(void)=0;
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll)=0;

   __property TpFIBDataSet * DocAll = {read = get_DocAll , write = set_DocAll};
   virtual TpFIBDataSet * get_DocAll(void)=0;
   virtual void set_DocAll(TpFIBDataSet * DocAll)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

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

   __property TFIBIntegerField * NumDocMAXNUMBER = {read = get_NumDocMAXNUMBER , write = set_NumDocMAXNUMBER};
   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void)=0;
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)=0;

   __property TFIBLargeIntField * DocAllID_REM_GUR_PROV = {read = get_DocAllID_REM_GUR_PROV , write = set_DocAllID_REM_GUR_PROV};
   virtual TFIBLargeIntField * get_DocAllID_REM_GUR_PROV(void)=0;
   virtual void set_DocAllID_REM_GUR_PROV(TFIBLargeIntField * DocAllID_REM_GUR_PROV)=0;

   __property TFIBLargeIntField * DocAllIDBASE_REM_GUR_PROV = {read = get_DocAllIDBASE_REM_GUR_PROV , write = set_DocAllIDBASE_REM_GUR_PROV};
   virtual TFIBLargeIntField * get_DocAllIDBASE_REM_GUR_PROV(void)=0;
   virtual void set_DocAllIDBASE_REM_GUR_PROV(TFIBLargeIntField * DocAllIDBASE_REM_GUR_PROV)=0;

   __property TFIBDateTimeField * DocAllPOS_REM_GUR_PROV = {read = get_DocAllPOS_REM_GUR_PROV , write = set_DocAllPOS_REM_GUR_PROV};
   virtual TFIBDateTimeField * get_DocAllPOS_REM_GUR_PROV(void)=0;
   virtual void set_DocAllPOS_REM_GUR_PROV(TFIBDateTimeField * DocAllPOS_REM_GUR_PROV)=0;

   __property TFIBIntegerField * DocAllNUM_REM_GUR_PROV = {read = get_DocAllNUM_REM_GUR_PROV , write = set_DocAllNUM_REM_GUR_PROV};
   virtual TFIBIntegerField * get_DocAllNUM_REM_GUR_PROV(void)=0;
   virtual void set_DocAllNUM_REM_GUR_PROV(TFIBIntegerField * DocAllNUM_REM_GUR_PROV)=0;

   __property TFIBWideStringField * DocAllDESCR_REM_GUR_PROV = {read = get_DocAllDESCR_REM_GUR_PROV , write = set_DocAllDESCR_REM_GUR_PROV};
   virtual TFIBWideStringField * get_DocAllDESCR_REM_GUR_PROV(void)=0;
   virtual void set_DocAllDESCR_REM_GUR_PROV(TFIBWideStringField * DocAllDESCR_REM_GUR_PROV)=0;

   __property TFIBLargeIntField * DocAllIDDOC_REM_GUR_PROV = {read = get_DocAllIDDOC_REM_GUR_PROV , write = set_DocAllIDDOC_REM_GUR_PROV};
   virtual TFIBLargeIntField * get_DocAllIDDOC_REM_GUR_PROV(void)=0;
   virtual void set_DocAllIDDOC_REM_GUR_PROV(TFIBLargeIntField * DocAllIDDOC_REM_GUR_PROV)=0;

   __property TFIBLargeIntField * DocAllIDUSER_REM_GUR_PROV = {read = get_DocAllIDUSER_REM_GUR_PROV , write = set_DocAllIDUSER_REM_GUR_PROV};
   virtual TFIBLargeIntField * get_DocAllIDUSER_REM_GUR_PROV(void)=0;
   virtual void set_DocAllIDUSER_REM_GUR_PROV(TFIBLargeIntField * DocAllIDUSER_REM_GUR_PROV)=0;

   __property TFIBIntegerField * DocAllRES_REM_GUR_PROV = {read = get_DocAllRES_REM_GUR_PROV , write = set_DocAllRES_REM_GUR_PROV};
   virtual TFIBIntegerField * get_DocAllRES_REM_GUR_PROV(void)=0;
   virtual void set_DocAllRES_REM_GUR_PROV(TFIBIntegerField * DocAllRES_REM_GUR_PROV)=0;

   __property TFIBWideStringField * DocAllNAMEFIRM = {read = get_DocAllNAMEFIRM , write = set_DocAllNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void)=0;
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllNAMESKLAD = {read = get_DocAllNAMESKLAD , write = set_DocAllNAMESKLAD};
   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void)=0;
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)=0;

   __property TFIBWideStringField * DocAllNAMEKLIENT = {read = get_DocAllNAMEKLIENT , write = set_DocAllNAMEKLIENT};
   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void)=0;
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)=0;

   __property TFIBWideStringField * DocAllNAME_USER_DOC = {read = get_DocAllNAME_USER_DOC , write = set_DocAllNAME_USER_DOC};
   virtual TFIBWideStringField * get_DocAllNAME_USER_DOC(void)=0;
   virtual void set_DocAllNAME_USER_DOC(TFIBWideStringField * DocAllNAME_USER_DOC)=0;

   __property TFIBWideStringField * DocAllNAME_USER_PROV = {read = get_DocAllNAME_USER_PROV , write = set_DocAllNAME_USER_PROV};
   virtual TFIBWideStringField * get_DocAllNAME_USER_PROV(void)=0;
   virtual void set_DocAllNAME_USER_PROV(TFIBWideStringField * DocAllNAME_USER_PROV)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC = {read = get_DocAllPREFIKS_NUM_REM_GALLDOC , write = set_DocAllPREFIKS_NUM_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)=0;

   __property TFIBSmallIntField * DocAllPR_REM_GALLDOC = {read = get_DocAllPR_REM_GALLDOC , write = set_DocAllPR_REM_GALLDOC};
   virtual TFIBSmallIntField * get_DocAllPR_REM_GALLDOC(void)=0;
   virtual void set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)=0;

   __property TFIBIntegerField * DocAllNUM_REM_GALLDOC = {read = get_DocAllNUM_REM_GALLDOC , write = set_DocAllNUM_REM_GALLDOC};
   virtual TFIBIntegerField * get_DocAllNUM_REM_GALLDOC(void)=0;
   virtual void set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)=0;

   __property TFIBDateTimeField * DocAllPOS_REM_GALLDOC = {read = get_DocAllPOS_REM_GALLDOC , write = set_DocAllPOS_REM_GALLDOC};
   virtual TFIBDateTimeField * get_DocAllPOS_REM_GALLDOC(void)=0;
   virtual void set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)=0;

   __property TFIBWideStringField * DocAllTDOC_REM_GALLDOC = {read = get_DocAllTDOC_REM_GALLDOC , write = set_DocAllTDOC_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllTDOC_REM_GALLDOC(void)=0;
   virtual void set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   virtual bool NewDoc(void)=0;
   virtual bool OpenDoc(__int64 id)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IREM_DMDocProverka __uuidof(IREM_DMDocProverka)
#endif
