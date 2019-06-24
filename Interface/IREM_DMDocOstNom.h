#ifndef UIREM_DMDocOstNomH
#define UIREM_DMDocOstNomH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMDocOstNom)) IREM_DMDocOstNom : public IMainInterface
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

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TFIBIntegerField * NumDocMAXNUMBER = {read = get_NumDocMAXNUMBER , write = set_NumDocMAXNUMBER};
   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void)=0;
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)=0;

   __property TpFIBDataSet * DocOsn = {read = get_DocOsn , write = set_DocOsn};
   virtual TpFIBDataSet * get_DocOsn(void)=0;
   virtual void set_DocOsn(TpFIBDataSet * DocOsn)=0;

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

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBLargeIntField * DocID_REM_DOSN = {read = get_DocID_REM_DOSN , write = set_DocID_REM_DOSN};
   virtual TFIBLargeIntField * get_DocID_REM_DOSN(void)=0;
   virtual void set_DocID_REM_DOSN(TFIBLargeIntField * DocID_REM_DOSN)=0;

   __property TFIBLargeIntField * DocIDBASE_REM_DOSN = {read = get_DocIDBASE_REM_DOSN , write = set_DocIDBASE_REM_DOSN};
   virtual TFIBLargeIntField * get_DocIDBASE_REM_DOSN(void)=0;
   virtual void set_DocIDBASE_REM_DOSN(TFIBLargeIntField * DocIDBASE_REM_DOSN)=0;

   __property TFIBLargeIntField * DocIDDOC_REM_DOSN = {read = get_DocIDDOC_REM_DOSN , write = set_DocIDDOC_REM_DOSN};
   virtual TFIBLargeIntField * get_DocIDDOC_REM_DOSN(void)=0;
   virtual void set_DocIDDOC_REM_DOSN(TFIBLargeIntField * DocIDDOC_REM_DOSN)=0;

   __property TFIBWideStringField * DocGID_REM_DOSN = {read = get_DocGID_REM_DOSN , write = set_DocGID_REM_DOSN};
   virtual TFIBWideStringField * get_DocGID_REM_DOSN(void)=0;
   virtual void set_DocGID_REM_DOSN(TFIBWideStringField * DocGID_REM_DOSN)=0;

   __property TFIBLargeIntField * DocIDTPRICE_REM_DOSN = {read = get_DocIDTPRICE_REM_DOSN , write = set_DocIDTPRICE_REM_DOSN};
   virtual TFIBLargeIntField * get_DocIDTPRICE_REM_DOSN(void)=0;
   virtual void set_DocIDTPRICE_REM_DOSN(TFIBLargeIntField * DocIDTPRICE_REM_DOSN)=0;

   __property TFIBLargeIntField * DocIDRTPRICE_REM_DOSN = {read = get_DocIDRTPRICE_REM_DOSN , write = set_DocIDRTPRICE_REM_DOSN};
   virtual TFIBLargeIntField * get_DocIDRTPRICE_REM_DOSN(void)=0;
   virtual void set_DocIDRTPRICE_REM_DOSN(TFIBLargeIntField * DocIDRTPRICE_REM_DOSN)=0;

   __property TFIBBCDField * DocRSUM_REM_DOSN = {read = get_DocRSUM_REM_DOSN , write = set_DocRSUM_REM_DOSN};
   virtual TFIBBCDField * get_DocRSUM_REM_DOSN(void)=0;
   virtual void set_DocRSUM_REM_DOSN(TFIBBCDField * DocRSUM_REM_DOSN)=0;

   __property TFIBWideStringField * DocPRIM_REM_DOSN = {read = get_DocPRIM_REM_DOSN , write = set_DocPRIM_REM_DOSN};
   virtual TFIBWideStringField * get_DocPRIM_REM_DOSN(void)=0;
   virtual void set_DocPRIM_REM_DOSN(TFIBWideStringField * DocPRIM_REM_DOSN)=0;

   __property TDataSource * DataSourceDocOsn = {read = get_DataSourceDocOsn , write = set_DataSourceDocOsn};
   virtual TDataSource * get_DataSourceDocOsn(void)=0;
   virtual void set_DataSourceDocOsn(TDataSource * DataSourceDocOsn)=0;

   __property TFIBLargeIntField * DocTID_REM_DOSNT = {read = get_DocTID_REM_DOSNT , write = set_DocTID_REM_DOSNT};
   virtual TFIBLargeIntField * get_DocTID_REM_DOSNT(void)=0;
   virtual void set_DocTID_REM_DOSNT(TFIBLargeIntField * DocTID_REM_DOSNT)=0;

   __property TFIBLargeIntField * DocTIDBASE_REM_DOSNT = {read = get_DocTIDBASE_REM_DOSNT , write = set_DocTIDBASE_REM_DOSNT};
   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DOSNT(void)=0;
   virtual void set_DocTIDBASE_REM_DOSNT(TFIBLargeIntField * DocTIDBASE_REM_DOSNT)=0;

   __property TFIBLargeIntField * DocTIDDOC_REM_DOSNT = {read = get_DocTIDDOC_REM_DOSNT , write = set_DocTIDDOC_REM_DOSNT};
   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DOSNT(void)=0;
   virtual void set_DocTIDDOC_REM_DOSNT(TFIBLargeIntField * DocTIDDOC_REM_DOSNT)=0;

   __property TFIBWideStringField * DocTGID_REM_DOSNT = {read = get_DocTGID_REM_DOSNT , write = set_DocTGID_REM_DOSNT};
   virtual TFIBWideStringField * get_DocTGID_REM_DOSNT(void)=0;
   virtual void set_DocTGID_REM_DOSNT(TFIBWideStringField * DocTGID_REM_DOSNT)=0;

   __property TFIBLargeIntField * DocTIDNOM_REM_DOSNT = {read = get_DocTIDNOM_REM_DOSNT , write = set_DocTIDNOM_REM_DOSNT};
   virtual TFIBLargeIntField * get_DocTIDNOM_REM_DOSNT(void)=0;
   virtual void set_DocTIDNOM_REM_DOSNT(TFIBLargeIntField * DocTIDNOM_REM_DOSNT)=0;

   __property TFIBLargeIntField * DocTIDED_REM_DOSNT = {read = get_DocTIDED_REM_DOSNT , write = set_DocTIDED_REM_DOSNT};
   virtual TFIBLargeIntField * get_DocTIDED_REM_DOSNT(void)=0;
   virtual void set_DocTIDED_REM_DOSNT(TFIBLargeIntField * DocTIDED_REM_DOSNT)=0;

   __property TFIBLargeIntField * DocTIDHW_REM_DOSNT = {read = get_DocTIDHW_REM_DOSNT , write = set_DocTIDHW_REM_DOSNT};
   virtual TFIBLargeIntField * get_DocTIDHW_REM_DOSNT(void)=0;
   virtual void set_DocTIDHW_REM_DOSNT(TFIBLargeIntField * DocTIDHW_REM_DOSNT)=0;

   __property TFIBBCDField * DocTKOL_REM_DOSNT = {read = get_DocTKOL_REM_DOSNT , write = set_DocTKOL_REM_DOSNT};
   virtual TFIBBCDField * get_DocTKOL_REM_DOSNT(void)=0;
   virtual void set_DocTKOL_REM_DOSNT(TFIBBCDField * DocTKOL_REM_DOSNT)=0;

   __property TFIBBCDField * DocTKF_REM_DOSNT = {read = get_DocTKF_REM_DOSNT , write = set_DocTKF_REM_DOSNT};
   virtual TFIBBCDField * get_DocTKF_REM_DOSNT(void)=0;
   virtual void set_DocTKF_REM_DOSNT(TFIBBCDField * DocTKF_REM_DOSNT)=0;

   __property TFIBBCDField * DocTPRICE_REM_DOSNT = {read = get_DocTPRICE_REM_DOSNT , write = set_DocTPRICE_REM_DOSNT};
   virtual TFIBBCDField * get_DocTPRICE_REM_DOSNT(void)=0;
   virtual void set_DocTPRICE_REM_DOSNT(TFIBBCDField * DocTPRICE_REM_DOSNT)=0;

   __property TFIBBCDField * DocTSUM_REM_DOSNT = {read = get_DocTSUM_REM_DOSNT , write = set_DocTSUM_REM_DOSNT};
   virtual TFIBBCDField * get_DocTSUM_REM_DOSNT(void)=0;
   virtual void set_DocTSUM_REM_DOSNT(TFIBBCDField * DocTSUM_REM_DOSNT)=0;

   __property TFIBBCDField * DocTRPRICE_REM_DOSNT = {read = get_DocTRPRICE_REM_DOSNT , write = set_DocTRPRICE_REM_DOSNT};
   virtual TFIBBCDField * get_DocTRPRICE_REM_DOSNT(void)=0;
   virtual void set_DocTRPRICE_REM_DOSNT(TFIBBCDField * DocTRPRICE_REM_DOSNT)=0;

   __property TFIBBCDField * DocTRSUM_REM_DOSNT = {read = get_DocTRSUM_REM_DOSNT , write = set_DocTRSUM_REM_DOSNT};
   virtual TFIBBCDField * get_DocTRSUM_REM_DOSNT(void)=0;
   virtual void set_DocTRSUM_REM_DOSNT(TFIBBCDField * DocTRSUM_REM_DOSNT)=0;

   __property TFIBIntegerField * DocTNDS_REM_DOSNT = {read = get_DocTNDS_REM_DOSNT , write = set_DocTNDS_REM_DOSNT};
   virtual TFIBIntegerField * get_DocTNDS_REM_DOSNT(void)=0;
   virtual void set_DocTNDS_REM_DOSNT(TFIBIntegerField * DocTNDS_REM_DOSNT)=0;

   __property TFIBBCDField * DocTSUMNDS_REM_DOSNT = {read = get_DocTSUMNDS_REM_DOSNT , write = set_DocTSUMNDS_REM_DOSNT};
   virtual TFIBBCDField * get_DocTSUMNDS_REM_DOSNT(void)=0;
   virtual void set_DocTSUMNDS_REM_DOSNT(TFIBBCDField * DocTSUMNDS_REM_DOSNT)=0;

   __property TFIBSmallIntField * DocTDVREG_REM_DOSNT = {read = get_DocTDVREG_REM_DOSNT , write = set_DocTDVREG_REM_DOSNT};
   virtual TFIBSmallIntField * get_DocTDVREG_REM_DOSNT(void)=0;
   virtual void set_DocTDVREG_REM_DOSNT(TFIBSmallIntField * DocTDVREG_REM_DOSNT)=0;

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

   __property TFIBWideStringField * DocTNAME_REM_SHARDWARE = {read = get_DocTNAME_REM_SHARDWARE , write = set_DocTNAME_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocTNAME_REM_SHARDWARE(void)=0;
   virtual void set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)=0;

   __property TFIBIntegerField * DocTCODE_REM_SHARDWARE = {read = get_DocTCODE_REM_SHARDWARE , write = set_DocTCODE_REM_SHARDWARE};
   virtual TFIBIntegerField * get_DocTCODE_REM_SHARDWARE(void)=0;
   virtual void set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocTSERNUM_REM_SHARDWARE = {read = get_DocTSERNUM_REM_SHARDWARE , write = set_DocTSERNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocTSERNUM_REM_SHARDWARE(void)=0;
   virtual void set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocOsnTDOC_REM_GALLDOC = {read = get_DocOsnTDOC_REM_GALLDOC , write = set_DocOsnTDOC_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocOsnTDOC_REM_GALLDOC(void)=0;
   virtual void set_DocOsnTDOC_REM_GALLDOC(TFIBWideStringField * DocOsnTDOC_REM_GALLDOC)=0;

   __property TFIBIntegerField * DocOsnNUM_REM_GALLDOC = {read = get_DocOsnNUM_REM_GALLDOC , write = set_DocOsnNUM_REM_GALLDOC};
   virtual TFIBIntegerField * get_DocOsnNUM_REM_GALLDOC(void)=0;
   virtual void set_DocOsnNUM_REM_GALLDOC(TFIBIntegerField * DocOsnNUM_REM_GALLDOC)=0;

   __property TFIBDateTimeField * DocOsnPOS_REM_GALLDOC = {read = get_DocOsnPOS_REM_GALLDOC , write = set_DocOsnPOS_REM_GALLDOC};
   virtual TFIBDateTimeField * get_DocOsnPOS_REM_GALLDOC(void)=0;
   virtual void set_DocOsnPOS_REM_GALLDOC(TFIBDateTimeField * DocOsnPOS_REM_GALLDOC)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC = {read = get_DocAllPREFIKS_NUM_REM_GALLDOC , write = set_DocAllPREFIKS_NUM_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC = {read = get_DocAllIDOBJECT_REM_GALLDOC , write = set_DocAllIDOBJECT_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDOBJECT_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDOBJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SOBJECT = {read = get_DocAllNAME_SOBJECT , write = set_DocAllNAME_SOBJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SOBJECT(void)=0;
   virtual void set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT)=0;

   __property TpFIBDataSet * TypeNom = {read = get_TypeNom , write = set_TypeNom};
   virtual TpFIBDataSet * get_TypeNom(void)=0;
   virtual void set_TypeNom(TpFIBDataSet * TypeNom)=0;

   __property TFIBLargeIntField * TypeNomID_STNOM = {read = get_TypeNomID_STNOM , write = set_TypeNomID_STNOM};
   virtual TFIBLargeIntField * get_TypeNomID_STNOM(void)=0;
   virtual void set_TypeNomID_STNOM(TFIBLargeIntField * TypeNomID_STNOM)=0;

   __property TFIBWideStringField * TypeNomNAME_STNOM = {read = get_TypeNomNAME_STNOM , write = set_TypeNomNAME_STNOM};
   virtual TFIBWideStringField * get_TypeNomNAME_STNOM(void)=0;
   virtual void set_TypeNomNAME_STNOM(TFIBWideStringField * TypeNomNAME_STNOM)=0;

   __property TFIBLargeIntField * DocTIDTNOM_REM_DOSNT = {read = get_DocTIDTNOM_REM_DOSNT , write = set_DocTIDTNOM_REM_DOSNT};
   virtual TFIBLargeIntField * get_DocTIDTNOM_REM_DOSNT(void)=0;
   virtual void set_DocTIDTNOM_REM_DOSNT(TFIBLargeIntField * DocTIDTNOM_REM_DOSNT)=0;

   __property TStringField * DocTNAME_TYPE_NOM_LOOCUP = {read = get_DocTNAME_TYPE_NOM_LOOCUP , write = set_DocTNAME_TYPE_NOM_LOOCUP};
   virtual TStringField * get_DocTNAME_TYPE_NOM_LOOCUP(void)=0;
   virtual void set_DocTNAME_TYPE_NOM_LOOCUP(TStringField * DocTNAME_TYPE_NOM_LOOCUP)=0;

   __property TFIBLargeIntField * DocTIDMHRAN_REM_DOSNT = {read = get_DocTIDMHRAN_REM_DOSNT , write = set_DocTIDMHRAN_REM_DOSNT};
   virtual TFIBLargeIntField * get_DocTIDMHRAN_REM_DOSNT(void)=0;
   virtual void set_DocTIDMHRAN_REM_DOSNT(TFIBLargeIntField * DocTIDMHRAN_REM_DOSNT)=0;

   __property TFIBWideStringField * DocTNAME_SMHRAN = {read = get_DocTNAME_SMHRAN , write = set_DocTNAME_SMHRAN};
   virtual TFIBWideStringField * get_DocTNAME_SMHRAN(void)=0;
   virtual void set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN)=0;

   __property bool NewElement = {read = get_NewElement , write = set_NewElement};
   virtual bool get_NewElement(void)=0;
   virtual void set_NewElement(bool NewElement)=0;

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

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 id_doc)=0;
   virtual bool SaveDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
};
#define IID_IREM_DMDocOstNom __uuidof(IREM_DMDocOstNom)
#endif
