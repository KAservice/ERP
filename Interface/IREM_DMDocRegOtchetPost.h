#ifndef UIREM_DMDocRegOtchetPostH
#define UIREM_DMDocRegOtchetPostH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMDocRegOtchetPost)) IREM_DMDocRegOtchetPost : public IMainInterface
{
public:
   __property TDataSource * DataSourceDoc = {read = get_DataSourceDoc , write = set_DataSourceDoc};
   virtual TDataSource * get_DataSourceDoc(void)=0;
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc)=0;

   __property TDataSource * DataSourceDocT = {read = get_DataSourceDocT , write = set_DataSourceDocT};
   virtual TDataSource * get_DataSourceDocT(void)=0;
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT)=0;

   __property TDataSource * DataSourceDocAll = {read = get_DataSourceDocAll , write = set_DataSourceDocAll};
   virtual TDataSource * get_DataSourceDocAll(void)=0;
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll)=0;

   __property TpFIBDataSet * DocAll = {read = get_DocAll , write = set_DocAll};
   virtual TpFIBDataSet * get_DocAll(void)=0;
   virtual void set_DocAll(TpFIBDataSet * DocAll)=0;

   __property TpFIBDataSet * Doc = {read = get_Doc , write = set_Doc};
   virtual TpFIBDataSet * get_Doc(void)=0;
   virtual void set_Doc(TpFIBDataSet * Doc)=0;

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

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBLargeIntField * DocAllID_REM_GALLDOC = {read = get_DocAllID_REM_GALLDOC , write = set_DocAllID_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllID_REM_GALLDOC(void)=0;
   virtual void set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC = {read = get_DocAllIDBASE_REM_GALLDOC , write = set_DocAllIDBASE_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBASE_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC = {read = get_DocAllIDFIRM_REM_GALLDOC , write = set_DocAllIDFIRM_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDFIRM_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC = {read = get_DocAllIDSKLAD_REM_GALLDOC , write = set_DocAllIDSKLAD_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDSKLAD_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC = {read = get_DocAllIDKLIENT_REM_GALLDOC , write = set_DocAllIDKLIENT_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDKLIENT_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC = {read = get_DocAllIDUSER_REM_GALLDOC , write = set_DocAllIDUSER_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDUSER_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)=0;

   __property TFIBDateTimeField * DocAllPOS_REM_GALLDOC = {read = get_DocAllPOS_REM_GALLDOC , write = set_DocAllPOS_REM_GALLDOC};
   virtual TFIBDateTimeField * get_DocAllPOS_REM_GALLDOC(void)=0;
   virtual void set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)=0;

   __property TFIBIntegerField * DocAllNUM_REM_GALLDOC = {read = get_DocAllNUM_REM_GALLDOC , write = set_DocAllNUM_REM_GALLDOC};
   virtual TFIBIntegerField * get_DocAllNUM_REM_GALLDOC(void)=0;
   virtual void set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)=0;

   __property TFIBSmallIntField * DocAllPR_REM_GALLDOC = {read = get_DocAllPR_REM_GALLDOC , write = set_DocAllPR_REM_GALLDOC};
   virtual TFIBSmallIntField * get_DocAllPR_REM_GALLDOC(void)=0;
   virtual void set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)=0;

   __property TFIBWideStringField * DocAllTDOC_REM_GALLDOC = {read = get_DocAllTDOC_REM_GALLDOC , write = set_DocAllTDOC_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllTDOC_REM_GALLDOC(void)=0;
   virtual void set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC = {read = get_DocAllIDDOCOSN_REM_GALLDOC , write = set_DocAllIDDOCOSN_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOCOSN_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)=0;

   __property TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC = {read = get_DocAllTYPEEXTDOC_REM_GALLDOC , write = set_DocAllTYPEEXTDOC_REM_GALLDOC};
   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC_REM_GALLDOC(void)=0;
   virtual void set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC = {read = get_DocAllIDEXTDOC_REM_GALLDOC , write = set_DocAllIDEXTDOC_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDEXTDOC_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)=0;

   __property TFIBBCDField * DocAllSUM_REM_GALLDOC = {read = get_DocAllSUM_REM_GALLDOC , write = set_DocAllSUM_REM_GALLDOC};
   virtual TFIBBCDField * get_DocAllSUM_REM_GALLDOC(void)=0;
   virtual void set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC = {read = get_DocAllIDPROJECT_REM_GALLDOC , write = set_DocAllIDPROJECT_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDPROJECT_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC = {read = get_DocAllIDBUSINOP_REM_GALLDOC , write = set_DocAllIDBUSINOP_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC = {read = get_DocAllPREFIKS_NUM_REM_GALLDOC , write = set_DocAllPREFIKS_NUM_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)=0;

   __property TFIBWideStringField * DocAllFNAME_USER = {read = get_DocAllFNAME_USER , write = set_DocAllFNAME_USER};
   virtual TFIBWideStringField * get_DocAllFNAME_USER(void)=0;
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBLargeIntField * DocID_REM_DRG_OTCHPOST = {read = get_DocID_REM_DRG_OTCHPOST , write = set_DocID_REM_DRG_OTCHPOST};
   virtual TFIBLargeIntField * get_DocID_REM_DRG_OTCHPOST(void)=0;
   virtual void set_DocID_REM_DRG_OTCHPOST(TFIBLargeIntField * DocID_REM_DRG_OTCHPOST)=0;

   __property TFIBLargeIntField * DocIDBASE_REM_DRG_OTCHPOST = {read = get_DocIDBASE_REM_DRG_OTCHPOST , write = set_DocIDBASE_REM_DRG_OTCHPOST};
   virtual TFIBLargeIntField * get_DocIDBASE_REM_DRG_OTCHPOST(void)=0;
   virtual void set_DocIDBASE_REM_DRG_OTCHPOST(TFIBLargeIntField * DocIDBASE_REM_DRG_OTCHPOST)=0;

   __property TFIBLargeIntField * DocIDDOC_REM_DRG_OTCHPOST = {read = get_DocIDDOC_REM_DRG_OTCHPOST , write = set_DocIDDOC_REM_DRG_OTCHPOST};
   virtual TFIBLargeIntField * get_DocIDDOC_REM_DRG_OTCHPOST(void)=0;
   virtual void set_DocIDDOC_REM_DRG_OTCHPOST(TFIBLargeIntField * DocIDDOC_REM_DRG_OTCHPOST)=0;

   __property TFIBWideStringField * DocDESCR_REM_DRG_OTCHPOST = {read = get_DocDESCR_REM_DRG_OTCHPOST , write = set_DocDESCR_REM_DRG_OTCHPOST};
   virtual TFIBWideStringField * get_DocDESCR_REM_DRG_OTCHPOST(void)=0;
   virtual void set_DocDESCR_REM_DRG_OTCHPOST(TFIBWideStringField * DocDESCR_REM_DRG_OTCHPOST)=0;

   __property TFIBLargeIntField * DocTID_REM_DRG_OTCHPOSTT = {read = get_DocTID_REM_DRG_OTCHPOSTT , write = set_DocTID_REM_DRG_OTCHPOSTT};
   virtual TFIBLargeIntField * get_DocTID_REM_DRG_OTCHPOSTT(void)=0;
   virtual void set_DocTID_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTID_REM_DRG_OTCHPOSTT)=0;

   __property TFIBLargeIntField * DocTIDBASE_REM_DRG_OTCHPOSTT = {read = get_DocTIDBASE_REM_DRG_OTCHPOSTT , write = set_DocTIDBASE_REM_DRG_OTCHPOSTT};
   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DRG_OTCHPOSTT(void)=0;
   virtual void set_DocTIDBASE_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDBASE_REM_DRG_OTCHPOSTT)=0;

   __property TFIBLargeIntField * DocTIDDOC_REM_DRG_OTCHPOSTT = {read = get_DocTIDDOC_REM_DRG_OTCHPOSTT , write = set_DocTIDDOC_REM_DRG_OTCHPOSTT};
   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DRG_OTCHPOSTT(void)=0;
   virtual void set_DocTIDDOC_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDDOC_REM_DRG_OTCHPOSTT)=0;

   __property TFIBSmallIntField * DocTTDV_REM_DRG_OTCHPOSTT = {read = get_DocTTDV_REM_DRG_OTCHPOSTT , write = set_DocTTDV_REM_DRG_OTCHPOSTT};
   virtual TFIBSmallIntField * get_DocTTDV_REM_DRG_OTCHPOSTT(void)=0;
   virtual void set_DocTTDV_REM_DRG_OTCHPOSTT(TFIBSmallIntField * DocTTDV_REM_DRG_OTCHPOSTT)=0;

   __property TFIBLargeIntField * DocTIDFIRM_REM_DRG_OTCHPOSTT = {read = get_DocTIDFIRM_REM_DRG_OTCHPOSTT , write = set_DocTIDFIRM_REM_DRG_OTCHPOSTT};
   virtual TFIBLargeIntField * get_DocTIDFIRM_REM_DRG_OTCHPOSTT(void)=0;
   virtual void set_DocTIDFIRM_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDFIRM_REM_DRG_OTCHPOSTT)=0;

   __property TFIBLargeIntField * DocTIDSKLAD_REM_DRG_OTCHPOSTT = {read = get_DocTIDSKLAD_REM_DRG_OTCHPOSTT , write = set_DocTIDSKLAD_REM_DRG_OTCHPOSTT};
   virtual TFIBLargeIntField * get_DocTIDSKLAD_REM_DRG_OTCHPOSTT(void)=0;
   virtual void set_DocTIDSKLAD_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDSKLAD_REM_DRG_OTCHPOSTT)=0;

   __property TFIBLargeIntField * DocTIDPOST_REM_DRG_OTCHPOSTT = {read = get_DocTIDPOST_REM_DRG_OTCHPOSTT , write = set_DocTIDPOST_REM_DRG_OTCHPOSTT};
   virtual TFIBLargeIntField * get_DocTIDPOST_REM_DRG_OTCHPOSTT(void)=0;
   virtual void set_DocTIDPOST_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDPOST_REM_DRG_OTCHPOSTT)=0;

   __property TFIBLargeIntField * DocTIDDOCPOST_REM_DRG_OTCHPOSTT = {read = get_DocTIDDOCPOST_REM_DRG_OTCHPOSTT , write = set_DocTIDDOCPOST_REM_DRG_OTCHPOSTT};
   virtual TFIBLargeIntField * get_DocTIDDOCPOST_REM_DRG_OTCHPOSTT(void)=0;
   virtual void set_DocTIDDOCPOST_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDDOCPOST_REM_DRG_OTCHPOSTT)=0;

   __property TFIBLargeIntField * DocTIDNOM_REM_DRG_OTCHPOSTT = {read = get_DocTIDNOM_REM_DRG_OTCHPOSTT , write = set_DocTIDNOM_REM_DRG_OTCHPOSTT};
   virtual TFIBLargeIntField * get_DocTIDNOM_REM_DRG_OTCHPOSTT(void)=0;
   virtual void set_DocTIDNOM_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDNOM_REM_DRG_OTCHPOSTT)=0;

   __property TFIBBCDField * DocTKOL_REM_DRG_OTCHPOSTT = {read = get_DocTKOL_REM_DRG_OTCHPOSTT , write = set_DocTKOL_REM_DRG_OTCHPOSTT};
   virtual TFIBBCDField * get_DocTKOL_REM_DRG_OTCHPOSTT(void)=0;
   virtual void set_DocTKOL_REM_DRG_OTCHPOSTT(TFIBBCDField * DocTKOL_REM_DRG_OTCHPOSTT)=0;

   __property TFIBBCDField * DocTSUM_REM_DRG_OTCHPOSTT = {read = get_DocTSUM_REM_DRG_OTCHPOSTT , write = set_DocTSUM_REM_DRG_OTCHPOSTT};
   virtual TFIBBCDField * get_DocTSUM_REM_DRG_OTCHPOSTT(void)=0;
   virtual void set_DocTSUM_REM_DRG_OTCHPOSTT(TFIBBCDField * DocTSUM_REM_DRG_OTCHPOSTT)=0;

   __property TFIBWideStringField * DocTNAMEFIRM = {read = get_DocTNAMEFIRM , write = set_DocTNAMEFIRM};
   virtual TFIBWideStringField * get_DocTNAMEFIRM(void)=0;
   virtual void set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM)=0;

   __property TFIBWideStringField * DocTNAMESKLAD = {read = get_DocTNAMESKLAD , write = set_DocTNAMESKLAD};
   virtual TFIBWideStringField * get_DocTNAMESKLAD(void)=0;
   virtual void set_DocTNAMESKLAD(TFIBWideStringField * DocTNAMESKLAD)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBWideStringField * DocTARTNOM = {read = get_DocTARTNOM , write = set_DocTARTNOM};
   virtual TFIBWideStringField * get_DocTARTNOM(void)=0;
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)=0;

   __property TFIBWideStringField * DocTPREFIKS_NUM_REM_GALLDOC = {read = get_DocTPREFIKS_NUM_REM_GALLDOC , write = set_DocTPREFIKS_NUM_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocTPREFIKS_NUM_REM_GALLDOC(void)=0;
   virtual void set_DocTPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocTPREFIKS_NUM_REM_GALLDOC)=0;

   __property TFIBIntegerField * DocTNUM_REM_GALLDOC = {read = get_DocTNUM_REM_GALLDOC , write = set_DocTNUM_REM_GALLDOC};
   virtual TFIBIntegerField * get_DocTNUM_REM_GALLDOC(void)=0;
   virtual void set_DocTNUM_REM_GALLDOC(TFIBIntegerField * DocTNUM_REM_GALLDOC)=0;

   __property TFIBDateTimeField * DocTPOS_REM_GALLDOC = {read = get_DocTPOS_REM_GALLDOC , write = set_DocTPOS_REM_GALLDOC};
   virtual TFIBDateTimeField * get_DocTPOS_REM_GALLDOC(void)=0;
   virtual void set_DocTPOS_REM_GALLDOC(TFIBDateTimeField * DocTPOS_REM_GALLDOC)=0;

   __property TFIBWideStringField * DocTNAMEKLIENT = {read = get_DocTNAMEKLIENT , write = set_DocTNAMEKLIENT};
   virtual TFIBWideStringField * get_DocTNAMEKLIENT(void)=0;
   virtual void set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)=0;

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
#define IID_IREM_DMDocRegOtchetPost __uuidof(IREM_DMDocRegOtchetPost)
#endif
