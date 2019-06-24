#ifndef UIREM_DMDocPrihNaklH
#define UIREM_DMDocPrihNaklH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMDocPrihNakl)) IREM_DMDocPrihNakl : public IMainInterface
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

   __property TFIBWideStringField * DocAllFNAME_USER = {read = get_DocAllFNAME_USER , write = set_DocAllFNAME_USER};
   virtual TFIBWideStringField * get_DocAllFNAME_USER(void)=0;
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocAllNAMEFIRM = {read = get_DocAllNAMEFIRM , write = set_DocAllNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void)=0;
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllNAMESKLAD = {read = get_DocAllNAMESKLAD , write = set_DocAllNAMESKLAD};
   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void)=0;
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)=0;

   __property TFIBWideStringField * DocAllNAMEKLIENT = {read = get_DocAllNAMEKLIENT , write = set_DocAllNAMEKLIENT};
   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void)=0;
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBLargeIntField * DocID_REM_DPRN = {read = get_DocID_REM_DPRN , write = set_DocID_REM_DPRN};
   virtual TFIBLargeIntField * get_DocID_REM_DPRN(void)=0;
   virtual void set_DocID_REM_DPRN(TFIBLargeIntField * DocID_REM_DPRN)=0;

   __property TFIBLargeIntField * DocIDBASE_REM_DPRN = {read = get_DocIDBASE_REM_DPRN , write = set_DocIDBASE_REM_DPRN};
   virtual TFIBLargeIntField * get_DocIDBASE_REM_DPRN(void)=0;
   virtual void set_DocIDBASE_REM_DPRN(TFIBLargeIntField * DocIDBASE_REM_DPRN)=0;

   __property TFIBLargeIntField * DocIDDOC_REM_DPRN = {read = get_DocIDDOC_REM_DPRN , write = set_DocIDDOC_REM_DPRN};
   virtual TFIBLargeIntField * get_DocIDDOC_REM_DPRN(void)=0;
   virtual void set_DocIDDOC_REM_DPRN(TFIBLargeIntField * DocIDDOC_REM_DPRN)=0;

   __property TFIBWideStringField * DocGID_REM_DPRN = {read = get_DocGID_REM_DPRN , write = set_DocGID_REM_DPRN};
   virtual TFIBWideStringField * get_DocGID_REM_DPRN(void)=0;
   virtual void set_DocGID_REM_DPRN(TFIBWideStringField * DocGID_REM_DPRN)=0;

   __property TFIBLargeIntField * DocIDTPRICE_REM_DPRN = {read = get_DocIDTPRICE_REM_DPRN , write = set_DocIDTPRICE_REM_DPRN};
   virtual TFIBLargeIntField * get_DocIDTPRICE_REM_DPRN(void)=0;
   virtual void set_DocIDTPRICE_REM_DPRN(TFIBLargeIntField * DocIDTPRICE_REM_DPRN)=0;

   __property TFIBLargeIntField * DocIDRTPRICE_REM_DPRN = {read = get_DocIDRTPRICE_REM_DPRN , write = set_DocIDRTPRICE_REM_DPRN};
   virtual TFIBLargeIntField * get_DocIDRTPRICE_REM_DPRN(void)=0;
   virtual void set_DocIDRTPRICE_REM_DPRN(TFIBLargeIntField * DocIDRTPRICE_REM_DPRN)=0;

   __property TFIBBCDField * DocRSUM_REM_DPRN = {read = get_DocRSUM_REM_DPRN , write = set_DocRSUM_REM_DPRN};
   virtual TFIBBCDField * get_DocRSUM_REM_DPRN(void)=0;
   virtual void set_DocRSUM_REM_DPRN(TFIBBCDField * DocRSUM_REM_DPRN)=0;

   __property TFIBWideStringField * DocPRIM_REM_DPRN = {read = get_DocPRIM_REM_DPRN , write = set_DocPRIM_REM_DPRN};
   virtual TFIBWideStringField * get_DocPRIM_REM_DPRN(void)=0;
   virtual void set_DocPRIM_REM_DPRN(TFIBWideStringField * DocPRIM_REM_DPRN)=0;

   __property TFIBWideStringField * DocNUMDOCPOST_REM_DPRN = {read = get_DocNUMDOCPOST_REM_DPRN , write = set_DocNUMDOCPOST_REM_DPRN};
   virtual TFIBWideStringField * get_DocNUMDOCPOST_REM_DPRN(void)=0;
   virtual void set_DocNUMDOCPOST_REM_DPRN(TFIBWideStringField * DocNUMDOCPOST_REM_DPRN)=0;

   __property TFIBDateTimeField * DocPOSDOCPOST_REM_DPRN = {read = get_DocPOSDOCPOST_REM_DPRN , write = set_DocPOSDOCPOST_REM_DPRN};
   virtual TFIBDateTimeField * get_DocPOSDOCPOST_REM_DPRN(void)=0;
   virtual void set_DocPOSDOCPOST_REM_DPRN(TFIBDateTimeField * DocPOSDOCPOST_REM_DPRN)=0;

   __property TFIBLargeIntField * DocTID_REM_DPRNT = {read = get_DocTID_REM_DPRNT , write = set_DocTID_REM_DPRNT};
   virtual TFIBLargeIntField * get_DocTID_REM_DPRNT(void)=0;
   virtual void set_DocTID_REM_DPRNT(TFIBLargeIntField * DocTID_REM_DPRNT)=0;

   __property TFIBLargeIntField * DocTIDBASE_REM_DPRNT = {read = get_DocTIDBASE_REM_DPRNT , write = set_DocTIDBASE_REM_DPRNT};
   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DPRNT(void)=0;
   virtual void set_DocTIDBASE_REM_DPRNT(TFIBLargeIntField * DocTIDBASE_REM_DPRNT)=0;

   __property TFIBLargeIntField * DocTIDDOC_REM_DPRNT = {read = get_DocTIDDOC_REM_DPRNT , write = set_DocTIDDOC_REM_DPRNT};
   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DPRNT(void)=0;
   virtual void set_DocTIDDOC_REM_DPRNT(TFIBLargeIntField * DocTIDDOC_REM_DPRNT)=0;

   __property TFIBWideStringField * DocTGID_REM_DPRNT = {read = get_DocTGID_REM_DPRNT , write = set_DocTGID_REM_DPRNT};
   virtual TFIBWideStringField * get_DocTGID_REM_DPRNT(void)=0;
   virtual void set_DocTGID_REM_DPRNT(TFIBWideStringField * DocTGID_REM_DPRNT)=0;

   __property TFIBLargeIntField * DocTIDNOM_REM_DPRNT = {read = get_DocTIDNOM_REM_DPRNT , write = set_DocTIDNOM_REM_DPRNT};
   virtual TFIBLargeIntField * get_DocTIDNOM_REM_DPRNT(void)=0;
   virtual void set_DocTIDNOM_REM_DPRNT(TFIBLargeIntField * DocTIDNOM_REM_DPRNT)=0;

   __property TFIBLargeIntField * DocTIDED_REM_DPRNT = {read = get_DocTIDED_REM_DPRNT , write = set_DocTIDED_REM_DPRNT};
   virtual TFIBLargeIntField * get_DocTIDED_REM_DPRNT(void)=0;
   virtual void set_DocTIDED_REM_DPRNT(TFIBLargeIntField * DocTIDED_REM_DPRNT)=0;

   __property TFIBLargeIntField * DocTIDHW_REM_DPRNT = {read = get_DocTIDHW_REM_DPRNT , write = set_DocTIDHW_REM_DPRNT};
   virtual TFIBLargeIntField * get_DocTIDHW_REM_DPRNT(void)=0;
   virtual void set_DocTIDHW_REM_DPRNT(TFIBLargeIntField * DocTIDHW_REM_DPRNT)=0;

   __property TFIBBCDField * DocTKOL_REM_DPRNT = {read = get_DocTKOL_REM_DPRNT , write = set_DocTKOL_REM_DPRNT};
   virtual TFIBBCDField * get_DocTKOL_REM_DPRNT(void)=0;
   virtual void set_DocTKOL_REM_DPRNT(TFIBBCDField * DocTKOL_REM_DPRNT)=0;

   __property TFIBBCDField * DocTKF_REM_DPRNT = {read = get_DocTKF_REM_DPRNT , write = set_DocTKF_REM_DPRNT};
   virtual TFIBBCDField * get_DocTKF_REM_DPRNT(void)=0;
   virtual void set_DocTKF_REM_DPRNT(TFIBBCDField * DocTKF_REM_DPRNT)=0;

   __property TFIBBCDField * DocTPRICE_REM_DPRNT = {read = get_DocTPRICE_REM_DPRNT , write = set_DocTPRICE_REM_DPRNT};
   virtual TFIBBCDField * get_DocTPRICE_REM_DPRNT(void)=0;
   virtual void set_DocTPRICE_REM_DPRNT(TFIBBCDField * DocTPRICE_REM_DPRNT)=0;

   __property TFIBBCDField * DocTSUM_REM_DPRNT = {read = get_DocTSUM_REM_DPRNT , write = set_DocTSUM_REM_DPRNT};
   virtual TFIBBCDField * get_DocTSUM_REM_DPRNT(void)=0;
   virtual void set_DocTSUM_REM_DPRNT(TFIBBCDField * DocTSUM_REM_DPRNT)=0;

   __property TFIBBCDField * DocTNAC_REM_DPRNT = {read = get_DocTNAC_REM_DPRNT , write = set_DocTNAC_REM_DPRNT};
   virtual TFIBBCDField * get_DocTNAC_REM_DPRNT(void)=0;
   virtual void set_DocTNAC_REM_DPRNT(TFIBBCDField * DocTNAC_REM_DPRNT)=0;

   __property TFIBBCDField * DocTRPRICE_REM_DPRNT = {read = get_DocTRPRICE_REM_DPRNT , write = set_DocTRPRICE_REM_DPRNT};
   virtual TFIBBCDField * get_DocTRPRICE_REM_DPRNT(void)=0;
   virtual void set_DocTRPRICE_REM_DPRNT(TFIBBCDField * DocTRPRICE_REM_DPRNT)=0;

   __property TFIBBCDField * DocTRSUM_REM_DPRNT = {read = get_DocTRSUM_REM_DPRNT , write = set_DocTRSUM_REM_DPRNT};
   virtual TFIBBCDField * get_DocTRSUM_REM_DPRNT(void)=0;
   virtual void set_DocTRSUM_REM_DPRNT(TFIBBCDField * DocTRSUM_REM_DPRNT)=0;

   __property TFIBIntegerField * DocTNDS_REM_DPRNT = {read = get_DocTNDS_REM_DPRNT , write = set_DocTNDS_REM_DPRNT};
   virtual TFIBIntegerField * get_DocTNDS_REM_DPRNT(void)=0;
   virtual void set_DocTNDS_REM_DPRNT(TFIBIntegerField * DocTNDS_REM_DPRNT)=0;

   __property TFIBBCDField * DocTSUMNDS_REM_DPRNT = {read = get_DocTSUMNDS_REM_DPRNT , write = set_DocTSUMNDS_REM_DPRNT};
   virtual TFIBBCDField * get_DocTSUMNDS_REM_DPRNT(void)=0;
   virtual void set_DocTSUMNDS_REM_DPRNT(TFIBBCDField * DocTSUMNDS_REM_DPRNT)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBWideStringField * DocTARTNOM = {read = get_DocTARTNOM , write = set_DocTARTNOM};
   virtual TFIBWideStringField * get_DocTARTNOM(void)=0;
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)=0;

   __property TFIBWideStringField * DocTSHED = {read = get_DocTSHED , write = set_DocTSHED};
   virtual TFIBWideStringField * get_DocTSHED(void)=0;
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED)=0;

   __property TFIBIntegerField * DocTCODE_REM_SHARDWARE = {read = get_DocTCODE_REM_SHARDWARE , write = set_DocTCODE_REM_SHARDWARE};
   virtual TFIBIntegerField * get_DocTCODE_REM_SHARDWARE(void)=0;
   virtual void set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocTSERNUM_REM_SHARDWARE = {read = get_DocTSERNUM_REM_SHARDWARE , write = set_DocTSERNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocTSERNUM_REM_SHARDWARE(void)=0;
   virtual void set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBWideStringField * DocTNAME_REM_SHARDWARE = {read = get_DocTNAME_REM_SHARDWARE , write = set_DocTNAME_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocTNAME_REM_SHARDWARE(void)=0;
   virtual void set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * DocTDVREG_REM_DPRNT = {read = get_DocTDVREG_REM_DPRNT , write = set_DocTDVREG_REM_DPRNT};
   virtual TFIBSmallIntField * get_DocTDVREG_REM_DPRNT(void)=0;
   virtual void set_DocTDVREG_REM_DPRNT(TFIBSmallIntField * DocTDVREG_REM_DPRNT)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC = {read = get_DocAllPREFIKS_NUM_REM_GALLDOC , write = set_DocAllPREFIKS_NUM_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)=0;

   __property TFIBSmallIntField * DocFL_TREB_OTCHET_REM_DPRN = {read = get_DocFL_TREB_OTCHET_REM_DPRN , write = set_DocFL_TREB_OTCHET_REM_DPRN};
   virtual TFIBSmallIntField * get_DocFL_TREB_OTCHET_REM_DPRN(void)=0;
   virtual void set_DocFL_TREB_OTCHET_REM_DPRN(TFIBSmallIntField * DocFL_TREB_OTCHET_REM_DPRN)=0;

   __property TFIBSmallIntField * DocFL_OTV_HRAN_REM_DPRN = {read = get_DocFL_OTV_HRAN_REM_DPRN , write = set_DocFL_OTV_HRAN_REM_DPRN};
   virtual TFIBSmallIntField * get_DocFL_OTV_HRAN_REM_DPRN(void)=0;
   virtual void set_DocFL_OTV_HRAN_REM_DPRN(TFIBSmallIntField * DocFL_OTV_HRAN_REM_DPRN)=0;

   __property TFIBLargeIntField * DocTIDCQT_REM_DPRNT = {read = get_DocTIDCQT_REM_DPRNT , write = set_DocTIDCQT_REM_DPRNT};
   virtual TFIBLargeIntField * get_DocTIDCQT_REM_DPRNT(void)=0;
   virtual void set_DocTIDCQT_REM_DPRNT(TFIBLargeIntField * DocTIDCQT_REM_DPRNT)=0;

   __property TFIBSmallIntField * DocTFL_ADD_IN_SOBORUD_SNOM = {read = get_DocTFL_ADD_IN_SOBORUD_SNOM , write = set_DocTFL_ADD_IN_SOBORUD_SNOM};
   virtual TFIBSmallIntField * get_DocTFL_ADD_IN_SOBORUD_SNOM(void)=0;
   virtual void set_DocTFL_ADD_IN_SOBORUD_SNOM(TFIBSmallIntField * DocTFL_ADD_IN_SOBORUD_SNOM)=0;

   __property TFIBLargeIntField * DocTID_REM_CQUERY = {read = get_DocTID_REM_CQUERY , write = set_DocTID_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocTID_REM_CQUERY(void)=0;
   virtual void set_DocTID_REM_CQUERY(TFIBLargeIntField * DocTID_REM_CQUERY)=0;

   __property TFIBWideStringField * DocTNAME_REM_CQUERY = {read = get_DocTNAME_REM_CQUERY , write = set_DocTNAME_REM_CQUERY};
   virtual TFIBWideStringField * get_DocTNAME_REM_CQUERY(void)=0;
   virtual void set_DocTNAME_REM_CQUERY(TFIBWideStringField * DocTNAME_REM_CQUERY)=0;

   __property TFIBIntegerField * DocTNUM_REM_CQUERY = {read = get_DocTNUM_REM_CQUERY , write = set_DocTNUM_REM_CQUERY};
   virtual TFIBIntegerField * get_DocTNUM_REM_CQUERY(void)=0;
   virtual void set_DocTNUM_REM_CQUERY(TFIBIntegerField * DocTNUM_REM_CQUERY)=0;

   __property TFIBDateTimeField * DocTPOS_REM_CQUERY = {read = get_DocTPOS_REM_CQUERY , write = set_DocTPOS_REM_CQUERY};
   virtual TFIBDateTimeField * get_DocTPOS_REM_CQUERY(void)=0;
   virtual void set_DocTPOS_REM_CQUERY(TFIBDateTimeField * DocTPOS_REM_CQUERY)=0;

   __property TFIBWideStringField * DocTKLIENT_NAME_REM_CQUERY = {read = get_DocTKLIENT_NAME_REM_CQUERY , write = set_DocTKLIENT_NAME_REM_CQUERY};
   virtual TFIBWideStringField * get_DocTKLIENT_NAME_REM_CQUERY(void)=0;
   virtual void set_DocTKLIENT_NAME_REM_CQUERY(TFIBWideStringField * DocTKLIENT_NAME_REM_CQUERY)=0;

   __property TFIBWideStringField * DocTNAME_MODEL_REM_CQUERY = {read = get_DocTNAME_MODEL_REM_CQUERY , write = set_DocTNAME_MODEL_REM_CQUERY};
   virtual TFIBWideStringField * get_DocTNAME_MODEL_REM_CQUERY(void)=0;
   virtual void set_DocTNAME_MODEL_REM_CQUERY(TFIBWideStringField * DocTNAME_MODEL_REM_CQUERY)=0;

   __property TFIBWideStringField * DocTNUM_STR_ZAK_POST_REM_CQUERY = {read = get_DocTNUM_STR_ZAK_POST_REM_CQUERY , write = set_DocTNUM_STR_ZAK_POST_REM_CQUERY};
   virtual TFIBWideStringField * get_DocTNUM_STR_ZAK_POST_REM_CQUERY(void)=0;
   virtual void set_DocTNUM_STR_ZAK_POST_REM_CQUERY(TFIBWideStringField * DocTNUM_STR_ZAK_POST_REM_CQUERY)=0;

   __property TFIBLargeIntField * DocTID_REM_Z = {read = get_DocTID_REM_Z , write = set_DocTID_REM_Z};
   virtual TFIBLargeIntField * get_DocTID_REM_Z(void)=0;
   virtual void set_DocTID_REM_Z(TFIBLargeIntField * DocTID_REM_Z)=0;

   __property TFIBWideStringField * DocTNAME_REM_Z = {read = get_DocTNAME_REM_Z , write = set_DocTNAME_REM_Z};
   virtual TFIBWideStringField * get_DocTNAME_REM_Z(void)=0;
   virtual void set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z)=0;

   __property TFIBWideStringField * DocTPREFIKS_NUM_REM_Z = {read = get_DocTPREFIKS_NUM_REM_Z , write = set_DocTPREFIKS_NUM_REM_Z};
   virtual TFIBWideStringField * get_DocTPREFIKS_NUM_REM_Z(void)=0;
   virtual void set_DocTPREFIKS_NUM_REM_Z(TFIBWideStringField * DocTPREFIKS_NUM_REM_Z)=0;

   __property TFIBIntegerField * DocTNUM_REM_Z = {read = get_DocTNUM_REM_Z , write = set_DocTNUM_REM_Z};
   virtual TFIBIntegerField * get_DocTNUM_REM_Z(void)=0;
   virtual void set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z)=0;

   __property TFIBDateTimeField * DocTPOS_REM_Z = {read = get_DocTPOS_REM_Z , write = set_DocTPOS_REM_Z};
   virtual TFIBDateTimeField * get_DocTPOS_REM_Z(void)=0;
   virtual void set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z)=0;

   __property TFIBWideStringField * DocTMODEL_REM_Z = {read = get_DocTMODEL_REM_Z , write = set_DocTMODEL_REM_Z};
   virtual TFIBWideStringField * get_DocTMODEL_REM_Z(void)=0;
   virtual void set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z)=0;

   __property TFIBWideStringField * DocTSERNUM_REM_Z = {read = get_DocTSERNUM_REM_Z , write = set_DocTSERNUM_REM_Z};
   virtual TFIBWideStringField * get_DocTSERNUM_REM_Z(void)=0;
   virtual void set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z)=0;

   __property TFIBWideStringField * DocTSERNUM2_REM_Z = {read = get_DocTSERNUM2_REM_Z , write = set_DocTSERNUM2_REM_Z};
   virtual TFIBWideStringField * get_DocTSERNUM2_REM_Z(void)=0;
   virtual void set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z)=0;

   __property TFIBWideStringField * DocTSTR_CODE_VIGR_REM_Z_1 = {read = get_DocTSTR_CODE_VIGR_REM_Z_1 , write = set_DocTSTR_CODE_VIGR_REM_Z_1};
   virtual TFIBWideStringField * get_DocTSTR_CODE_VIGR_REM_Z_1(void)=0;
   virtual void set_DocTSTR_CODE_VIGR_REM_Z_1(TFIBWideStringField * DocTSTR_CODE_VIGR_REM_Z_1)=0;

   __property TFIBLargeIntField * DocTIDTNOM_REM_DPRNT = {read = get_DocTIDTNOM_REM_DPRNT , write = set_DocTIDTNOM_REM_DPRNT};
   virtual TFIBLargeIntField * get_DocTIDTNOM_REM_DPRNT(void)=0;
   virtual void set_DocTIDTNOM_REM_DPRNT(TFIBLargeIntField * DocTIDTNOM_REM_DPRNT)=0;

   __property TFIBLargeIntField * DocTIDMHRAN_REM_DPRNT = {read = get_DocTIDMHRAN_REM_DPRNT , write = set_DocTIDMHRAN_REM_DPRNT};
   virtual TFIBLargeIntField * get_DocTIDMHRAN_REM_DPRNT(void)=0;
   virtual void set_DocTIDMHRAN_REM_DPRNT(TFIBLargeIntField * DocTIDMHRAN_REM_DPRNT)=0;

   __property TFIBWideStringField * DocTNAME_SMHRAN = {read = get_DocTNAME_SMHRAN , write = set_DocTNAME_SMHRAN};
   virtual TFIBWideStringField * get_DocTNAME_SMHRAN(void)=0;
   virtual void set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN)=0;

   __property TFIBWideStringField * DocTNAME_STNOM = {read = get_DocTNAME_STNOM , write = set_DocTNAME_STNOM};
   virtual TFIBWideStringField * get_DocTNAME_STNOM(void)=0;
   virtual void set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElementaMaster = {read = get_IdElementaMaster , write = set_IdElementaMaster};
   virtual __int64 get_IdElementaMaster(void)=0;
   virtual void set_IdElementaMaster(__int64 IdElementaMaster)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property bool IsmPrice = {read = get_IsmPrice , write = set_IsmPrice};
   virtual bool get_IsmPrice(void)=0;
   virtual void set_IsmPrice(bool IsmPrice)=0;

   __property bool IsmSum = {read = get_IsmSum , write = set_IsmSum};
   virtual bool get_IsmSum(void)=0;
   virtual void set_IsmSum(bool IsmSum)=0;

   __property bool SkladRozn = {read = get_SkladRozn , write = set_SkladRozn};
   virtual bool get_SkladRozn(void)=0;
   virtual void set_SkladRozn(bool SkladRozn)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   virtual void NewDoc(void)=0;
   virtual void CopyDoc(__int64 id_doc)=0;
   virtual void OpenDoc(__int64 id)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual double Summa(void)=0;
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)=0;
};
#define IID_IREM_DMDocPrihNakl __uuidof(IREM_DMDocPrihNakl)
#endif
