#ifndef UIREM_DMDocPerH
#define UIREM_DMDocPerH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMDocPer)) IREM_DMDocPer : public IMainInterface
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

   __property TFIBIntegerField * NumDocMAXNUMBER = {read = get_NumDocMAXNUMBER , write = set_NumDocMAXNUMBER};
   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void)=0;
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)=0;

   __property TpFIBDataSet * SpisokTypePrice = {read = get_SpisokTypePrice , write = set_SpisokTypePrice};
   virtual TpFIBDataSet * get_SpisokTypePrice(void)=0;
   virtual void set_SpisokTypePrice(TpFIBDataSet * SpisokTypePrice)=0;

   __property TFIBIntegerField * SpisokTypePriceID_TPRICE = {read = get_SpisokTypePriceID_TPRICE , write = set_SpisokTypePriceID_TPRICE};
   virtual TFIBIntegerField * get_SpisokTypePriceID_TPRICE(void)=0;
   virtual void set_SpisokTypePriceID_TPRICE(TFIBIntegerField * SpisokTypePriceID_TPRICE)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TpFIBDataSet * DocOsn = {read = get_DocOsn , write = set_DocOsn};
   virtual TpFIBDataSet * get_DocOsn(void)=0;
   virtual void set_DocOsn(TpFIBDataSet * DocOsn)=0;

   __property TDataSource * DataSourceDocOsn = {read = get_DataSourceDocOsn , write = set_DataSourceDocOsn};
   virtual TDataSource * get_DataSourceDocOsn(void)=0;
   virtual void set_DataSourceDocOsn(TDataSource * DataSourceDocOsn)=0;

   __property TFIBWideStringField * SpisokTypePriceNAME_TPRICE = {read = get_SpisokTypePriceNAME_TPRICE , write = set_SpisokTypePriceNAME_TPRICE};
   virtual TFIBWideStringField * get_SpisokTypePriceNAME_TPRICE(void)=0;
   virtual void set_SpisokTypePriceNAME_TPRICE(TFIBWideStringField * SpisokTypePriceNAME_TPRICE)=0;

   __property TFIBWideStringField * SpisokTypePriceGID_STPRICE = {read = get_SpisokTypePriceGID_STPRICE , write = set_SpisokTypePriceGID_STPRICE};
   virtual TFIBWideStringField * get_SpisokTypePriceGID_STPRICE(void)=0;
   virtual void set_SpisokTypePriceGID_STPRICE(TFIBWideStringField * SpisokTypePriceGID_STPRICE)=0;

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

   __property TFIBWideStringField * DocOsnTDOC_REM_GALLDOC = {read = get_DocOsnTDOC_REM_GALLDOC , write = set_DocOsnTDOC_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocOsnTDOC_REM_GALLDOC(void)=0;
   virtual void set_DocOsnTDOC_REM_GALLDOC(TFIBWideStringField * DocOsnTDOC_REM_GALLDOC)=0;

   __property TFIBDateTimeField * DocOsnPOS_REM_GALLDOC = {read = get_DocOsnPOS_REM_GALLDOC , write = set_DocOsnPOS_REM_GALLDOC};
   virtual TFIBDateTimeField * get_DocOsnPOS_REM_GALLDOC(void)=0;
   virtual void set_DocOsnPOS_REM_GALLDOC(TFIBDateTimeField * DocOsnPOS_REM_GALLDOC)=0;

   __property TFIBIntegerField * DocOsnNUM_REM_GALLDOC = {read = get_DocOsnNUM_REM_GALLDOC , write = set_DocOsnNUM_REM_GALLDOC};
   virtual TFIBIntegerField * get_DocOsnNUM_REM_GALLDOC(void)=0;
   virtual void set_DocOsnNUM_REM_GALLDOC(TFIBIntegerField * DocOsnNUM_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocID_REM_DPER = {read = get_DocID_REM_DPER , write = set_DocID_REM_DPER};
   virtual TFIBLargeIntField * get_DocID_REM_DPER(void)=0;
   virtual void set_DocID_REM_DPER(TFIBLargeIntField * DocID_REM_DPER)=0;

   __property TFIBLargeIntField * DocIDBASE_REM_DPER = {read = get_DocIDBASE_REM_DPER , write = set_DocIDBASE_REM_DPER};
   virtual TFIBLargeIntField * get_DocIDBASE_REM_DPER(void)=0;
   virtual void set_DocIDBASE_REM_DPER(TFIBLargeIntField * DocIDBASE_REM_DPER)=0;

   __property TFIBLargeIntField * DocIDDOC_REM_DPER = {read = get_DocIDDOC_REM_DPER , write = set_DocIDDOC_REM_DPER};
   virtual TFIBLargeIntField * get_DocIDDOC_REM_DPER(void)=0;
   virtual void set_DocIDDOC_REM_DPER(TFIBLargeIntField * DocIDDOC_REM_DPER)=0;

   __property TFIBWideStringField * DocGID_REM_DPER = {read = get_DocGID_REM_DPER , write = set_DocGID_REM_DPER};
   virtual TFIBWideStringField * get_DocGID_REM_DPER(void)=0;
   virtual void set_DocGID_REM_DPER(TFIBWideStringField * DocGID_REM_DPER)=0;

   __property TFIBLargeIntField * DocIDRTPRICE_REM_DPER = {read = get_DocIDRTPRICE_REM_DPER , write = set_DocIDRTPRICE_REM_DPER};
   virtual TFIBLargeIntField * get_DocIDRTPRICE_REM_DPER(void)=0;
   virtual void set_DocIDRTPRICE_REM_DPER(TFIBLargeIntField * DocIDRTPRICE_REM_DPER)=0;

   __property TFIBLargeIntField * DocIDSKLPOL_REM_DPER = {read = get_DocIDSKLPOL_REM_DPER , write = set_DocIDSKLPOL_REM_DPER};
   virtual TFIBLargeIntField * get_DocIDSKLPOL_REM_DPER(void)=0;
   virtual void set_DocIDSKLPOL_REM_DPER(TFIBLargeIntField * DocIDSKLPOL_REM_DPER)=0;

   __property TFIBWideStringField * DocPRIM_REM_DPER = {read = get_DocPRIM_REM_DPER , write = set_DocPRIM_REM_DPER};
   virtual TFIBWideStringField * get_DocPRIM_REM_DPER(void)=0;
   virtual void set_DocPRIM_REM_DPER(TFIBWideStringField * DocPRIM_REM_DPER)=0;

   __property TFIBLargeIntField * DocTID_REM_DPERT = {read = get_DocTID_REM_DPERT , write = set_DocTID_REM_DPERT};
   virtual TFIBLargeIntField * get_DocTID_REM_DPERT(void)=0;
   virtual void set_DocTID_REM_DPERT(TFIBLargeIntField * DocTID_REM_DPERT)=0;

   __property TFIBLargeIntField * DocTIDBASE_REM_DPERT = {read = get_DocTIDBASE_REM_DPERT , write = set_DocTIDBASE_REM_DPERT};
   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DPERT(void)=0;
   virtual void set_DocTIDBASE_REM_DPERT(TFIBLargeIntField * DocTIDBASE_REM_DPERT)=0;

   __property TFIBLargeIntField * DocTIDDOC_REM_DPERT = {read = get_DocTIDDOC_REM_DPERT , write = set_DocTIDDOC_REM_DPERT};
   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DPERT(void)=0;
   virtual void set_DocTIDDOC_REM_DPERT(TFIBLargeIntField * DocTIDDOC_REM_DPERT)=0;

   __property TFIBWideStringField * DocTGID_REM_DPERT = {read = get_DocTGID_REM_DPERT , write = set_DocTGID_REM_DPERT};
   virtual TFIBWideStringField * get_DocTGID_REM_DPERT(void)=0;
   virtual void set_DocTGID_REM_DPERT(TFIBWideStringField * DocTGID_REM_DPERT)=0;

   __property TFIBLargeIntField * DocTIDNOM_REM_DPERT = {read = get_DocTIDNOM_REM_DPERT , write = set_DocTIDNOM_REM_DPERT};
   virtual TFIBLargeIntField * get_DocTIDNOM_REM_DPERT(void)=0;
   virtual void set_DocTIDNOM_REM_DPERT(TFIBLargeIntField * DocTIDNOM_REM_DPERT)=0;

   __property TFIBLargeIntField * DocTIDED_REM_DPERT = {read = get_DocTIDED_REM_DPERT , write = set_DocTIDED_REM_DPERT};
   virtual TFIBLargeIntField * get_DocTIDED_REM_DPERT(void)=0;
   virtual void set_DocTIDED_REM_DPERT(TFIBLargeIntField * DocTIDED_REM_DPERT)=0;

   __property TFIBLargeIntField * DocTIDHW_REM_DPERT = {read = get_DocTIDHW_REM_DPERT , write = set_DocTIDHW_REM_DPERT};
   virtual TFIBLargeIntField * get_DocTIDHW_REM_DPERT(void)=0;
   virtual void set_DocTIDHW_REM_DPERT(TFIBLargeIntField * DocTIDHW_REM_DPERT)=0;

   __property TFIBBCDField * DocTKOL_REM_DPERT = {read = get_DocTKOL_REM_DPERT , write = set_DocTKOL_REM_DPERT};
   virtual TFIBBCDField * get_DocTKOL_REM_DPERT(void)=0;
   virtual void set_DocTKOL_REM_DPERT(TFIBBCDField * DocTKOL_REM_DPERT)=0;

   __property TFIBBCDField * DocTKF_REM_DPERT = {read = get_DocTKF_REM_DPERT , write = set_DocTKF_REM_DPERT};
   virtual TFIBBCDField * get_DocTKF_REM_DPERT(void)=0;
   virtual void set_DocTKF_REM_DPERT(TFIBBCDField * DocTKF_REM_DPERT)=0;

   __property TFIBBCDField * DocTRPRICE_REM_DPERT = {read = get_DocTRPRICE_REM_DPERT , write = set_DocTRPRICE_REM_DPERT};
   virtual TFIBBCDField * get_DocTRPRICE_REM_DPERT(void)=0;
   virtual void set_DocTRPRICE_REM_DPERT(TFIBBCDField * DocTRPRICE_REM_DPERT)=0;

   __property TFIBBCDField * DocTRSUM_REM_DPERT = {read = get_DocTRSUM_REM_DPERT , write = set_DocTRSUM_REM_DPERT};
   virtual TFIBBCDField * get_DocTRSUM_REM_DPERT(void)=0;
   virtual void set_DocTRSUM_REM_DPERT(TFIBBCDField * DocTRSUM_REM_DPERT)=0;

   __property TFIBBCDField * DocTNAC_REM_DPERT = {read = get_DocTNAC_REM_DPERT , write = set_DocTNAC_REM_DPERT};
   virtual TFIBBCDField * get_DocTNAC_REM_DPERT(void)=0;
   virtual void set_DocTNAC_REM_DPERT(TFIBBCDField * DocTNAC_REM_DPERT)=0;

   __property TFIBSmallIntField * DocTDVREG_REM_DPERT = {read = get_DocTDVREG_REM_DPERT , write = set_DocTDVREG_REM_DPERT};
   virtual TFIBSmallIntField * get_DocTDVREG_REM_DPERT(void)=0;
   virtual void set_DocTDVREG_REM_DPERT(TFIBSmallIntField * DocTDVREG_REM_DPERT)=0;

   __property TFIBWideStringField * DocTKRNAMENOM = {read = get_DocTKRNAMENOM , write = set_DocTKRNAMENOM};
   virtual TFIBWideStringField * get_DocTKRNAMENOM(void)=0;
   virtual void set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBSmallIntField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBSmallIntField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBWideStringField * DocTARTNOM = {read = get_DocTARTNOM , write = set_DocTARTNOM};
   virtual TFIBWideStringField * get_DocTARTNOM(void)=0;
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBWideStringField * DocTSHED = {read = get_DocTSHED , write = set_DocTSHED};
   virtual TFIBWideStringField * get_DocTSHED(void)=0;
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED)=0;

   __property TFIBLargeIntField * DocTIDGRPNOM = {read = get_DocTIDGRPNOM , write = set_DocTIDGRPNOM};
   virtual TFIBLargeIntField * get_DocTIDGRPNOM(void)=0;
   virtual void set_DocTIDGRPNOM(TFIBLargeIntField * DocTIDGRPNOM)=0;

   __property TFIBLargeIntField * DocTIDVID_SNOM = {read = get_DocTIDVID_SNOM , write = set_DocTIDVID_SNOM};
   virtual TFIBLargeIntField * get_DocTIDVID_SNOM(void)=0;
   virtual void set_DocTIDVID_SNOM(TFIBLargeIntField * DocTIDVID_SNOM)=0;

   __property TFIBWideStringField * DocTNAMEGN = {read = get_DocTNAMEGN , write = set_DocTNAMEGN};
   virtual TFIBWideStringField * get_DocTNAMEGN(void)=0;
   virtual void set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN)=0;

   __property TFIBWideStringField * DocTNAME_SVIDNOM = {read = get_DocTNAME_SVIDNOM , write = set_DocTNAME_SVIDNOM};
   virtual TFIBWideStringField * get_DocTNAME_SVIDNOM(void)=0;
   virtual void set_DocTNAME_SVIDNOM(TFIBWideStringField * DocTNAME_SVIDNOM)=0;

   __property TFIBWideStringField * DocTNAME_REM_SHARDWARE = {read = get_DocTNAME_REM_SHARDWARE , write = set_DocTNAME_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocTNAME_REM_SHARDWARE(void)=0;
   virtual void set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)=0;

   __property TFIBIntegerField * DocTCODE_REM_SHARDWARE = {read = get_DocTCODE_REM_SHARDWARE , write = set_DocTCODE_REM_SHARDWARE};
   virtual TFIBIntegerField * get_DocTCODE_REM_SHARDWARE(void)=0;
   virtual void set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocTSERNUM_REM_SHARDWARE = {read = get_DocTSERNUM_REM_SHARDWARE , write = set_DocTSERNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocTSERNUM_REM_SHARDWARE(void)=0;
   virtual void set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBWideStringField * DocNAMESKLAD = {read = get_DocNAMESKLAD , write = set_DocNAMESKLAD};
   virtual TFIBWideStringField * get_DocNAMESKLAD(void)=0;
   virtual void set_DocNAMESKLAD(TFIBWideStringField * DocNAMESKLAD)=0;

   __property TFIBSmallIntField * DocTDVREG_POL_REM_DPERT = {read = get_DocTDVREG_POL_REM_DPERT , write = set_DocTDVREG_POL_REM_DPERT};
   virtual TFIBSmallIntField * get_DocTDVREG_POL_REM_DPERT(void)=0;
   virtual void set_DocTDVREG_POL_REM_DPERT(TFIBSmallIntField * DocTDVREG_POL_REM_DPERT)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC = {read = get_DocAllPREFIKS_NUM_REM_GALLDOC , write = set_DocAllPREFIKS_NUM_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocTIDTNOM_REM_DPERT = {read = get_DocTIDTNOM_REM_DPERT , write = set_DocTIDTNOM_REM_DPERT};
   virtual TFIBLargeIntField * get_DocTIDTNOM_REM_DPERT(void)=0;
   virtual void set_DocTIDTNOM_REM_DPERT(TFIBLargeIntField * DocTIDTNOM_REM_DPERT)=0;

   __property TFIBLargeIntField * DocTIDMHRAN_OTPR_REM_DPERT = {read = get_DocTIDMHRAN_OTPR_REM_DPERT , write = set_DocTIDMHRAN_OTPR_REM_DPERT};
   virtual TFIBLargeIntField * get_DocTIDMHRAN_OTPR_REM_DPERT(void)=0;
   virtual void set_DocTIDMHRAN_OTPR_REM_DPERT(TFIBLargeIntField * DocTIDMHRAN_OTPR_REM_DPERT)=0;

   __property TFIBLargeIntField * DocTIDMHRAN_POL_REM_DPERT = {read = get_DocTIDMHRAN_POL_REM_DPERT , write = set_DocTIDMHRAN_POL_REM_DPERT};
   virtual TFIBLargeIntField * get_DocTIDMHRAN_POL_REM_DPERT(void)=0;
   virtual void set_DocTIDMHRAN_POL_REM_DPERT(TFIBLargeIntField * DocTIDMHRAN_POL_REM_DPERT)=0;

   __property TFIBWideStringField * DocTNAME_SMHRAN_POL = {read = get_DocTNAME_SMHRAN_POL , write = set_DocTNAME_SMHRAN_POL};
   virtual TFIBWideStringField * get_DocTNAME_SMHRAN_POL(void)=0;
   virtual void set_DocTNAME_SMHRAN_POL(TFIBWideStringField * DocTNAME_SMHRAN_POL)=0;

   __property TFIBWideStringField * DocTNAME_STNOM = {read = get_DocTNAME_STNOM , write = set_DocTNAME_STNOM};
   virtual TFIBWideStringField * get_DocTNAME_STNOM(void)=0;
   virtual void set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)=0;

   __property TFIBWideStringField * DocTNAME_SMHRAN_OTPR = {read = get_DocTNAME_SMHRAN_OTPR , write = set_DocTNAME_SMHRAN_OTPR};
   virtual TFIBWideStringField * get_DocTNAME_SMHRAN_OTPR(void)=0;
   virtual void set_DocTNAME_SMHRAN_OTPR(TFIBWideStringField * DocTNAME_SMHRAN_OTPR)=0;

   __property bool NewElement = {read = get_NewElement , write = set_NewElement};
   virtual bool get_NewElement(void)=0;
   virtual void set_NewElement(bool NewElement)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property UnicodeString ProsmotrText = {read = get_ProsmotrText , write = set_ProsmotrText};
   virtual UnicodeString get_ProsmotrText(void)=0;
   virtual void set_ProsmotrText(UnicodeString ProsmotrText)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AutoRaschet = {read = get_AutoRaschet , write = set_AutoRaschet};
   virtual bool get_AutoRaschet(void)=0;
   virtual void set_AutoRaschet(bool AutoRaschet)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   __property bool SkladRozn = {read = get_SkladRozn , write = set_SkladRozn};
   virtual bool get_SkladRozn(void)=0;
   virtual void set_SkladRozn(bool SkladRozn)=0;

   __property bool NoOtrOstatok = {read = get_NoOtrOstatok , write = set_NoOtrOstatok};
   virtual bool get_NoOtrOstatok(void)=0;
   virtual void set_NoOtrOstatok(bool NoOtrOstatok)=0;

   virtual void NewDoc(void)=0;
   virtual bool OpenDoc(__int64 IdDoc)=0;
   virtual void OpenDocOsn(void)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool BeforeSaveDoc(void)=0;
   virtual bool AfterSaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual void ValidateProsmotr(void)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IREM_DMDocPer __uuidof(IREM_DMDocPer)
#endif
