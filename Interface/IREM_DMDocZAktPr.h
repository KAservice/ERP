#ifndef UIREM_DMDocZAktPrH
#define UIREM_DMDocZAktPrH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMDocZAktPr)) IREM_DMDocZAktPr : public IMainInterface
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

   __property TFIBIntegerField * NumDocMAXNUMBER = {read = get_NumDocMAXNUMBER , write = set_NumDocMAXNUMBER};
   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void)=0;
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)=0;

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

   __property TFIBLargeIntField * DocID_REM_DZAKTPR = {read = get_DocID_REM_DZAKTPR , write = set_DocID_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocID_REM_DZAKTPR(void)=0;
   virtual void set_DocID_REM_DZAKTPR(TFIBLargeIntField * DocID_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * DocIDBASE_REM_DZAKTPR = {read = get_DocIDBASE_REM_DZAKTPR , write = set_DocIDBASE_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocIDBASE_REM_DZAKTPR(void)=0;
   virtual void set_DocIDBASE_REM_DZAKTPR(TFIBLargeIntField * DocIDBASE_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocGID_REM_DZAKTPR = {read = get_DocGID_REM_DZAKTPR , write = set_DocGID_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocGID_REM_DZAKTPR(void)=0;
   virtual void set_DocGID_REM_DZAKTPR(TFIBWideStringField * DocGID_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * DocIDDOC_REM_DZAKTPR = {read = get_DocIDDOC_REM_DZAKTPR , write = set_DocIDDOC_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocIDDOC_REM_DZAKTPR(void)=0;
   virtual void set_DocIDDOC_REM_DZAKTPR(TFIBLargeIntField * DocIDDOC_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * DocIDZ_REM_DZAKTPR = {read = get_DocIDZ_REM_DZAKTPR , write = set_DocIDZ_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocIDZ_REM_DZAKTPR(void)=0;
   virtual void set_DocIDZ_REM_DZAKTPR(TFIBLargeIntField * DocIDZ_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * DocIDTPRICE_REM_DZAKTPR = {read = get_DocIDTPRICE_REM_DZAKTPR , write = set_DocIDTPRICE_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocIDTPRICE_REM_DZAKTPR(void)=0;
   virtual void set_DocIDTPRICE_REM_DZAKTPR(TFIBLargeIntField * DocIDTPRICE_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocPRIM_REM_DZAKTPR = {read = get_DocPRIM_REM_DZAKTPR , write = set_DocPRIM_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocPRIM_REM_DZAKTPR(void)=0;
   virtual void set_DocPRIM_REM_DZAKTPR(TFIBWideStringField * DocPRIM_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocNAME_REM_Z = {read = get_DocNAME_REM_Z , write = set_DocNAME_REM_Z};
   virtual TFIBWideStringField * get_DocNAME_REM_Z(void)=0;
   virtual void set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z)=0;

   __property TFIBIntegerField * DocNUM_REM_Z = {read = get_DocNUM_REM_Z , write = set_DocNUM_REM_Z};
   virtual TFIBIntegerField * get_DocNUM_REM_Z(void)=0;
   virtual void set_DocNUM_REM_Z(TFIBIntegerField * DocNUM_REM_Z)=0;

   __property TFIBDateTimeField * DocPOS_REM_Z = {read = get_DocPOS_REM_Z , write = set_DocPOS_REM_Z};
   virtual TFIBDateTimeField * get_DocPOS_REM_Z(void)=0;
   virtual void set_DocPOS_REM_Z(TFIBDateTimeField * DocPOS_REM_Z)=0;

   __property TFIBWideStringField * DocSERNUM_REM_Z = {read = get_DocSERNUM_REM_Z , write = set_DocSERNUM_REM_Z};
   virtual TFIBWideStringField * get_DocSERNUM_REM_Z(void)=0;
   virtual void set_DocSERNUM_REM_Z(TFIBWideStringField * DocSERNUM_REM_Z)=0;

   __property TFIBWideStringField * DocSERNUM2_REM_Z = {read = get_DocSERNUM2_REM_Z , write = set_DocSERNUM2_REM_Z};
   virtual TFIBWideStringField * get_DocSERNUM2_REM_Z(void)=0;
   virtual void set_DocSERNUM2_REM_Z(TFIBWideStringField * DocSERNUM2_REM_Z)=0;

   __property TFIBWideStringField * DocKLIENT_NAME_REM_Z = {read = get_DocKLIENT_NAME_REM_Z , write = set_DocKLIENT_NAME_REM_Z};
   virtual TFIBWideStringField * get_DocKLIENT_NAME_REM_Z(void)=0;
   virtual void set_DocKLIENT_NAME_REM_Z(TFIBWideStringField * DocKLIENT_NAME_REM_Z)=0;

   __property TFIBWideStringField * DocMODEL_REM_Z = {read = get_DocMODEL_REM_Z , write = set_DocMODEL_REM_Z};
   virtual TFIBWideStringField * get_DocMODEL_REM_Z(void)=0;
   virtual void set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z)=0;

   __property TFIBWideStringField * DocNAME_REM_SMODEL = {read = get_DocNAME_REM_SMODEL , write = set_DocNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_DocNAME_REM_SMODEL(void)=0;
   virtual void set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL)=0;

   __property TFIBLargeIntField * DocTID_REM_DZAKTPRT = {read = get_DocTID_REM_DZAKTPRT , write = set_DocTID_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTID_REM_DZAKTPRT(void)=0;
   virtual void set_DocTID_REM_DZAKTPRT(TFIBLargeIntField * DocTID_REM_DZAKTPRT)=0;

   __property TFIBLargeIntField * DocTIDBASE_REM_DZAKTPRT = {read = get_DocTIDBASE_REM_DZAKTPRT , write = set_DocTIDBASE_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDBASE_REM_DZAKTPRT(TFIBLargeIntField * DocTIDBASE_REM_DZAKTPRT)=0;

   __property TFIBWideStringField * DocTGID_REM_DZAKTPRT = {read = get_DocTGID_REM_DZAKTPRT , write = set_DocTGID_REM_DZAKTPRT};
   virtual TFIBWideStringField * get_DocTGID_REM_DZAKTPRT(void)=0;
   virtual void set_DocTGID_REM_DZAKTPRT(TFIBWideStringField * DocTGID_REM_DZAKTPRT)=0;

   __property TFIBLargeIntField * DocTIDDOC_REM_DZAKTPRT = {read = get_DocTIDDOC_REM_DZAKTPRT , write = set_DocTIDDOC_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDDOC_REM_DZAKTPRT(TFIBLargeIntField * DocTIDDOC_REM_DZAKTPRT)=0;

   __property TFIBLargeIntField * DocTIDNOM_REM_DZAKTPRT = {read = get_DocTIDNOM_REM_DZAKTPRT , write = set_DocTIDNOM_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDNOM_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDNOM_REM_DZAKTPRT(TFIBLargeIntField * DocTIDNOM_REM_DZAKTPRT)=0;

   __property TFIBLargeIntField * DocTIDED_REM_DZAKTPRT = {read = get_DocTIDED_REM_DZAKTPRT , write = set_DocTIDED_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDED_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDED_REM_DZAKTPRT(TFIBLargeIntField * DocTIDED_REM_DZAKTPRT)=0;

   __property TFIBLargeIntField * DocTIDHW_REM_DZAKTPRT = {read = get_DocTIDHW_REM_DZAKTPRT , write = set_DocTIDHW_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDHW_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDHW_REM_DZAKTPRT(TFIBLargeIntField * DocTIDHW_REM_DZAKTPRT)=0;

   __property TFIBBCDField * DocTKOL_REM_DZAKTPRT = {read = get_DocTKOL_REM_DZAKTPRT , write = set_DocTKOL_REM_DZAKTPRT};
   virtual TFIBBCDField * get_DocTKOL_REM_DZAKTPRT(void)=0;
   virtual void set_DocTKOL_REM_DZAKTPRT(TFIBBCDField * DocTKOL_REM_DZAKTPRT)=0;

   __property TFIBBCDField * DocTKF_REM_DZAKTPRT = {read = get_DocTKF_REM_DZAKTPRT , write = set_DocTKF_REM_DZAKTPRT};
   virtual TFIBBCDField * get_DocTKF_REM_DZAKTPRT(void)=0;
   virtual void set_DocTKF_REM_DZAKTPRT(TFIBBCDField * DocTKF_REM_DZAKTPRT)=0;

   __property TFIBBCDField * DocTPRICE_REM_DZAKTPRT = {read = get_DocTPRICE_REM_DZAKTPRT , write = set_DocTPRICE_REM_DZAKTPRT};
   virtual TFIBBCDField * get_DocTPRICE_REM_DZAKTPRT(void)=0;
   virtual void set_DocTPRICE_REM_DZAKTPRT(TFIBBCDField * DocTPRICE_REM_DZAKTPRT)=0;

   __property TFIBBCDField * DocTSUM_REM_DZAKTPRT = {read = get_DocTSUM_REM_DZAKTPRT , write = set_DocTSUM_REM_DZAKTPRT};
   virtual TFIBBCDField * get_DocTSUM_REM_DZAKTPRT(void)=0;
   virtual void set_DocTSUM_REM_DZAKTPRT(TFIBBCDField * DocTSUM_REM_DZAKTPRT)=0;

   __property TFIBSmallIntField * DocTDVREG_REM_DZAKTPRT = {read = get_DocTDVREG_REM_DZAKTPRT , write = set_DocTDVREG_REM_DZAKTPRT};
   virtual TFIBSmallIntField * get_DocTDVREG_REM_DZAKTPRT(void)=0;
   virtual void set_DocTDVREG_REM_DZAKTPRT(TFIBSmallIntField * DocTDVREG_REM_DZAKTPRT)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

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

   __property TFIBWideStringField * DocTNAME_REM_SHARDWARE = {read = get_DocTNAME_REM_SHARDWARE , write = set_DocTNAME_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocTNAME_REM_SHARDWARE(void)=0;
   virtual void set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)=0;

   __property TFIBIntegerField * DocTCODE_REM_SHARDWARE = {read = get_DocTCODE_REM_SHARDWARE , write = set_DocTCODE_REM_SHARDWARE};
   virtual TFIBIntegerField * get_DocTCODE_REM_SHARDWARE(void)=0;
   virtual void set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocTSERNUM_REM_SHARDWARE = {read = get_DocTSERNUM_REM_SHARDWARE , write = set_DocTSERNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocTSERNUM_REM_SHARDWARE(void)=0;
   virtual void set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * DocIDPR_REM_DZAKTPR = {read = get_DocIDPR_REM_DZAKTPR , write = set_DocIDPR_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocIDPR_REM_DZAKTPR(void)=0;
   virtual void set_DocIDPR_REM_DZAKTPR(TFIBLargeIntField * DocIDPR_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * DocIDCFC_REM_DZAKTPR = {read = get_DocIDCFC_REM_DZAKTPR , write = set_DocIDCFC_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocIDCFC_REM_DZAKTPR(void)=0;
   virtual void set_DocIDCFC_REM_DZAKTPR(TFIBLargeIntField * DocIDCFC_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * DocIDDFC_REM_DZAKTPR = {read = get_DocIDDFC_REM_DZAKTPR , write = set_DocIDDFC_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocIDDFC_REM_DZAKTPR(void)=0;
   virtual void set_DocIDDFC_REM_DZAKTPR(TFIBLargeIntField * DocIDDFC_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * DocIDPRMODEL_REM_DZAKTPR = {read = get_DocIDPRMODEL_REM_DZAKTPR , write = set_DocIDPRMODEL_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocIDPRMODEL_REM_DZAKTPR(void)=0;
   virtual void set_DocIDPRMODEL_REM_DZAKTPR(TFIBLargeIntField * DocIDPRMODEL_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocPODO_REM_DZAKTPR = {read = get_DocPODO_REM_DZAKTPR , write = set_DocPODO_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocPODO_REM_DZAKTPR(void)=0;
   virtual void set_DocPODO_REM_DZAKTPR(TFIBWideStringField * DocPODO_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocPOPOSLE_REM_DZAKTPR = {read = get_DocPOPOSLE_REM_DZAKTPR , write = set_DocPOPOSLE_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocPOPOSLE_REM_DZAKTPR(void)=0;
   virtual void set_DocPOPOSLE_REM_DZAKTPR(TFIBWideStringField * DocPOPOSLE_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocDESCR_REM_DZAKTPR = {read = get_DocDESCR_REM_DZAKTPR , write = set_DocDESCR_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocDESCR_REM_DZAKTPR(void)=0;
   virtual void set_DocDESCR_REM_DZAKTPR(TFIBWideStringField * DocDESCR_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocPRODAVEC_REM_DZAKTPR = {read = get_DocPRODAVEC_REM_DZAKTPR , write = set_DocPRODAVEC_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocPRODAVEC_REM_DZAKTPR(void)=0;
   virtual void set_DocPRODAVEC_REM_DZAKTPR(TFIBWideStringField * DocPRODAVEC_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocNUMGARTALON_REM_DZAKTPR = {read = get_DocNUMGARTALON_REM_DZAKTPR , write = set_DocNUMGARTALON_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocNUMGARTALON_REM_DZAKTPR(void)=0;
   virtual void set_DocNUMGARTALON_REM_DZAKTPR(TFIBWideStringField * DocNUMGARTALON_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocSERNUM3_REM_DZAKTPR = {read = get_DocSERNUM3_REM_DZAKTPR , write = set_DocSERNUM3_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocSERNUM3_REM_DZAKTPR(void)=0;
   virtual void set_DocSERNUM3_REM_DZAKTPR(TFIBWideStringField * DocSERNUM3_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocSERNUM4_REM_DZAKTPR = {read = get_DocSERNUM4_REM_DZAKTPR , write = set_DocSERNUM4_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocSERNUM4_REM_DZAKTPR(void)=0;
   virtual void set_DocSERNUM4_REM_DZAKTPR(TFIBWideStringField * DocSERNUM4_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocNUMBAT_REM_DZAKTPR = {read = get_DocNUMBAT_REM_DZAKTPR , write = set_DocNUMBAT_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocNUMBAT_REM_DZAKTPR(void)=0;
   virtual void set_DocNUMBAT_REM_DZAKTPR(TFIBWideStringField * DocNUMBAT_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocSOST_REM_DZAKTPR = {read = get_DocSOST_REM_DZAKTPR , write = set_DocSOST_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocSOST_REM_DZAKTPR(void)=0;
   virtual void set_DocSOST_REM_DZAKTPR(TFIBWideStringField * DocSOST_REM_DZAKTPR)=0;

   __property TFIBDateField * DocDATEVIPUSK_REM_DZAKTPR = {read = get_DocDATEVIPUSK_REM_DZAKTPR , write = set_DocDATEVIPUSK_REM_DZAKTPR};
   virtual TFIBDateField * get_DocDATEVIPUSK_REM_DZAKTPR(void)=0;
   virtual void set_DocDATEVIPUSK_REM_DZAKTPR(TFIBDateField * DocDATEVIPUSK_REM_DZAKTPR)=0;

   __property TFIBDateField * DocDATE_PRODAGI_REM_DZAKTPR = {read = get_DocDATE_PRODAGI_REM_DZAKTPR , write = set_DocDATE_PRODAGI_REM_DZAKTPR};
   virtual TFIBDateField * get_DocDATE_PRODAGI_REM_DZAKTPR(void)=0;
   virtual void set_DocDATE_PRODAGI_REM_DZAKTPR(TFIBDateField * DocDATE_PRODAGI_REM_DZAKTPR)=0;

   __property TFIBIntegerField * DocTYPE_REMONT_REM_DZAKTPR = {read = get_DocTYPE_REMONT_REM_DZAKTPR , write = set_DocTYPE_REMONT_REM_DZAKTPR};
   virtual TFIBIntegerField * get_DocTYPE_REMONT_REM_DZAKTPR(void)=0;
   virtual void set_DocTYPE_REMONT_REM_DZAKTPR(TFIBIntegerField * DocTYPE_REMONT_REM_DZAKTPR)=0;

   __property TFIBIntegerField * DocKEM_SDANO_REM_DZAKTPR = {read = get_DocKEM_SDANO_REM_DZAKTPR , write = set_DocKEM_SDANO_REM_DZAKTPR};
   virtual TFIBIntegerField * get_DocKEM_SDANO_REM_DZAKTPR(void)=0;
   virtual void set_DocKEM_SDANO_REM_DZAKTPR(TFIBIntegerField * DocKEM_SDANO_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocCFC_NAME = {read = get_DocCFC_NAME , write = set_DocCFC_NAME};
   virtual TFIBWideStringField * get_DocCFC_NAME(void)=0;
   virtual void set_DocCFC_NAME(TFIBWideStringField * DocCFC_NAME)=0;

   __property TFIBWideStringField * DocCFC_CODE = {read = get_DocCFC_CODE , write = set_DocCFC_CODE};
   virtual TFIBWideStringField * get_DocCFC_CODE(void)=0;
   virtual void set_DocCFC_CODE(TFIBWideStringField * DocCFC_CODE)=0;

   __property TFIBWideStringField * DocDFC_NAME = {read = get_DocDFC_NAME , write = set_DocDFC_NAME};
   virtual TFIBWideStringField * get_DocDFC_NAME(void)=0;
   virtual void set_DocDFC_NAME(TFIBWideStringField * DocDFC_NAME)=0;

   __property TFIBWideStringField * DocDFC_CODE = {read = get_DocDFC_CODE , write = set_DocDFC_CODE};
   virtual TFIBWideStringField * get_DocDFC_CODE(void)=0;
   virtual void set_DocDFC_CODE(TFIBWideStringField * DocDFC_CODE)=0;

   __property TFIBWideStringField * DocNAME_SPRODUCER = {read = get_DocNAME_SPRODUCER , write = set_DocNAME_SPRODUCER};
   virtual TFIBWideStringField * get_DocNAME_SPRODUCER(void)=0;
   virtual void set_DocNAME_SPRODUCER(TFIBWideStringField * DocNAME_SPRODUCER)=0;

   __property TFIBWideStringField * DocNAME_REM_SPRMODEL = {read = get_DocNAME_REM_SPRMODEL , write = set_DocNAME_REM_SPRMODEL};
   virtual TFIBWideStringField * get_DocNAME_REM_SPRMODEL(void)=0;
   virtual void set_DocNAME_REM_SPRMODEL(TFIBWideStringField * DocNAME_REM_SPRMODEL)=0;

   __property TFIBWideStringField * DocCODE_REM_SPRMODEL = {read = get_DocCODE_REM_SPRMODEL , write = set_DocCODE_REM_SPRMODEL};
   virtual TFIBWideStringField * get_DocCODE_REM_SPRMODEL(void)=0;
   virtual void set_DocCODE_REM_SPRMODEL(TFIBWideStringField * DocCODE_REM_SPRMODEL)=0;

   __property TFIBWideStringField * DocNEISPR_REM_DZAKTPR = {read = get_DocNEISPR_REM_DZAKTPR , write = set_DocNEISPR_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocNEISPR_REM_DZAKTPR(void)=0;
   virtual void set_DocNEISPR_REM_DZAKTPR(TFIBWideStringField * DocNEISPR_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocNEISPR_REM_Z = {read = get_DocNEISPR_REM_Z , write = set_DocNEISPR_REM_Z};
   virtual TFIBWideStringField * get_DocNEISPR_REM_Z(void)=0;
   virtual void set_DocNEISPR_REM_Z(TFIBWideStringField * DocNEISPR_REM_Z)=0;

   __property TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC = {read = get_DocAllIDPROJECT_REM_GALLDOC , write = set_DocAllIDPROJECT_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDPROJECT_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC = {read = get_DocAllIDBUSINOP_REM_GALLDOC , write = set_DocAllIDBUSINOP_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC = {read = get_DocAllPREFIKS_NUM_REM_GALLDOC , write = set_DocAllPREFIKS_NUM_REM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBLargeIntField * DocTIDPRDEFECT_REM_DZAKTPR = {read = get_DocTIDPRDEFECT_REM_DZAKTPR , write = set_DocTIDPRDEFECT_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocTIDPRDEFECT_REM_DZAKTPR(void)=0;
   virtual void set_DocTIDPRDEFECT_REM_DZAKTPR(TFIBLargeIntField * DocTIDPRDEFECT_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocTCODE_REM_SPRDEFECT = {read = get_DocTCODE_REM_SPRDEFECT , write = set_DocTCODE_REM_SPRDEFECT};
   virtual TFIBWideStringField * get_DocTCODE_REM_SPRDEFECT(void)=0;
   virtual void set_DocTCODE_REM_SPRDEFECT(TFIBWideStringField * DocTCODE_REM_SPRDEFECT)=0;

   __property TFIBWideStringField * DocTNAME_REM_SPRDEFECT = {read = get_DocTNAME_REM_SPRDEFECT , write = set_DocTNAME_REM_SPRDEFECT};
   virtual TFIBWideStringField * get_DocTNAME_REM_SPRDEFECT(void)=0;
   virtual void set_DocTNAME_REM_SPRDEFECT(TFIBWideStringField * DocTNAME_REM_SPRDEFECT)=0;

   __property TFIBIntegerField * DocFL_FICTIV_REM_DZAKTPR = {read = get_DocFL_FICTIV_REM_DZAKTPR , write = set_DocFL_FICTIV_REM_DZAKTPR};
   virtual TFIBIntegerField * get_DocFL_FICTIV_REM_DZAKTPR(void)=0;
   virtual void set_DocFL_FICTIV_REM_DZAKTPR(TFIBIntegerField * DocFL_FICTIV_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocKLIENT_NAME_REM_DZAKTPR = {read = get_DocKLIENT_NAME_REM_DZAKTPR , write = set_DocKLIENT_NAME_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocKLIENT_NAME_REM_DZAKTPR(void)=0;
   virtual void set_DocKLIENT_NAME_REM_DZAKTPR(TFIBWideStringField * DocKLIENT_NAME_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocKLIENT_ADR_REM_DZAKTPR = {read = get_DocKLIENT_ADR_REM_DZAKTPR , write = set_DocKLIENT_ADR_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocKLIENT_ADR_REM_DZAKTPR(void)=0;
   virtual void set_DocKLIENT_ADR_REM_DZAKTPR(TFIBWideStringField * DocKLIENT_ADR_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocKLIENT_PHONE_REM_DZAKTPR = {read = get_DocKLIENT_PHONE_REM_DZAKTPR , write = set_DocKLIENT_PHONE_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocKLIENT_PHONE_REM_DZAKTPR(void)=0;
   virtual void set_DocKLIENT_PHONE_REM_DZAKTPR(TFIBWideStringField * DocKLIENT_PHONE_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * DocIDDILER_REM_DZAKTPR = {read = get_DocIDDILER_REM_DZAKTPR , write = set_DocIDDILER_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocIDDILER_REM_DZAKTPR(void)=0;
   virtual void set_DocIDDILER_REM_DZAKTPR(TFIBLargeIntField * DocIDDILER_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocNAMEKLIENT = {read = get_DocNAMEKLIENT , write = set_DocNAMEKLIENT};
   virtual TFIBWideStringField * get_DocNAMEKLIENT(void)=0;
   virtual void set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT)=0;

   __property TFIBWideStringField * DocPOST_ZIP_NAME = {read = get_DocPOST_ZIP_NAME , write = set_DocPOST_ZIP_NAME};
   virtual TFIBWideStringField * get_DocPOST_ZIP_NAME(void)=0;
   virtual void set_DocPOST_ZIP_NAME(TFIBWideStringField * DocPOST_ZIP_NAME)=0;

   __property TFIBSmallIntField * DocFL_OTCHET_POST_REM_DZAKTPR = {read = get_DocFL_OTCHET_POST_REM_DZAKTPR , write = set_DocFL_OTCHET_POST_REM_DZAKTPR};
   virtual TFIBSmallIntField * get_DocFL_OTCHET_POST_REM_DZAKTPR(void)=0;
   virtual void set_DocFL_OTCHET_POST_REM_DZAKTPR(TFIBSmallIntField * DocFL_OTCHET_POST_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * DocIDPOST_ZIP_REM_DZAKTPR = {read = get_DocIDPOST_ZIP_REM_DZAKTPR , write = set_DocIDPOST_ZIP_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocIDPOST_ZIP_REM_DZAKTPR(void)=0;
   virtual void set_DocIDPOST_ZIP_REM_DZAKTPR(TFIBLargeIntField * DocIDPOST_ZIP_REM_DZAKTPR)=0;

   __property TFIBSmallIntField * DocFL_NE_OTCH_REM_DZAKTPR = {read = get_DocFL_NE_OTCH_REM_DZAKTPR , write = set_DocFL_NE_OTCH_REM_DZAKTPR};
   virtual TFIBSmallIntField * get_DocFL_NE_OTCH_REM_DZAKTPR(void)=0;
   virtual void set_DocFL_NE_OTCH_REM_DZAKTPR(TFIBSmallIntField * DocFL_NE_OTCH_REM_DZAKTPR)=0;

   __property TFIBSmallIntField * DocFL_NADO_OTCH_REM_DZAKTPR = {read = get_DocFL_NADO_OTCH_REM_DZAKTPR , write = set_DocFL_NADO_OTCH_REM_DZAKTPR};
   virtual TFIBSmallIntField * get_DocFL_NADO_OTCH_REM_DZAKTPR(void)=0;
   virtual void set_DocFL_NADO_OTCH_REM_DZAKTPR(TFIBSmallIntField * DocFL_NADO_OTCH_REM_DZAKTPR)=0;

   __property TFIBSmallIntField * DocFL_PRIG_KREM_REM_DZAKTPR = {read = get_DocFL_PRIG_KREM_REM_DZAKTPR , write = set_DocFL_PRIG_KREM_REM_DZAKTPR};
   virtual TFIBSmallIntField * get_DocFL_PRIG_KREM_REM_DZAKTPR(void)=0;
   virtual void set_DocFL_PRIG_KREM_REM_DZAKTPR(TFIBSmallIntField * DocFL_PRIG_KREM_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocCODE_REM_SMODEL = {read = get_DocCODE_REM_SMODEL , write = set_DocCODE_REM_SMODEL};
   virtual TFIBWideStringField * get_DocCODE_REM_SMODEL(void)=0;
   virtual void set_DocCODE_REM_SMODEL(TFIBWideStringField * DocCODE_REM_SMODEL)=0;

   __property TFIBWideStringField * DocNAME_REM_SPRNEISPR_GRP = {read = get_DocNAME_REM_SPRNEISPR_GRP , write = set_DocNAME_REM_SPRNEISPR_GRP};
   virtual TFIBWideStringField * get_DocNAME_REM_SPRNEISPR_GRP(void)=0;
   virtual void set_DocNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * DocNAME_REM_SPRNEISPR_GRP)=0;

   __property TFIBDateTimeField * DocPOSPRIEMA_REM_DZAKTPR = {read = get_DocPOSPRIEMA_REM_DZAKTPR , write = set_DocPOSPRIEMA_REM_DZAKTPR};
   virtual TFIBDateTimeField * get_DocPOSPRIEMA_REM_DZAKTPR(void)=0;
   virtual void set_DocPOSPRIEMA_REM_DZAKTPR(TFIBDateTimeField * DocPOSPRIEMA_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * DocIDSELLER_REM_DZAKTPR = {read = get_DocIDSELLER_REM_DZAKTPR , write = set_DocIDSELLER_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_DocIDSELLER_REM_DZAKTPR(void)=0;
   virtual void set_DocIDSELLER_REM_DZAKTPR(TFIBLargeIntField * DocIDSELLER_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocNAME_SSELLER = {read = get_DocNAME_SSELLER , write = set_DocNAME_SSELLER};
   virtual TFIBWideStringField * get_DocNAME_SSELLER(void)=0;
   virtual void set_DocNAME_SSELLER(TFIBWideStringField * DocNAME_SSELLER)=0;

   __property TFIBWideStringField * DocCFC_NAME_ENG = {read = get_DocCFC_NAME_ENG , write = set_DocCFC_NAME_ENG};
   virtual TFIBWideStringField * get_DocCFC_NAME_ENG(void)=0;
   virtual void set_DocCFC_NAME_ENG(TFIBWideStringField * DocCFC_NAME_ENG)=0;

   __property TFIBWideStringField * DocNAME_ENG_REM_SPRNEISPR_GRP = {read = get_DocNAME_ENG_REM_SPRNEISPR_GRP , write = set_DocNAME_ENG_REM_SPRNEISPR_GRP};
   virtual TFIBWideStringField * get_DocNAME_ENG_REM_SPRNEISPR_GRP(void)=0;
   virtual void set_DocNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * DocNAME_ENG_REM_SPRNEISPR_GRP)=0;

   __property TFIBWideStringField * DocKLIENT_EMAIL_REM_DZAKTPR = {read = get_DocKLIENT_EMAIL_REM_DZAKTPR , write = set_DocKLIENT_EMAIL_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocKLIENT_EMAIL_REM_DZAKTPR(void)=0;
   virtual void set_DocKLIENT_EMAIL_REM_DZAKTPR(TFIBWideStringField * DocKLIENT_EMAIL_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocFAMILIYA_REM_DZAKTPR = {read = get_DocFAMILIYA_REM_DZAKTPR , write = set_DocFAMILIYA_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocFAMILIYA_REM_DZAKTPR(void)=0;
   virtual void set_DocFAMILIYA_REM_DZAKTPR(TFIBWideStringField * DocFAMILIYA_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocIMYA_REM_DZAKTPR = {read = get_DocIMYA_REM_DZAKTPR , write = set_DocIMYA_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocIMYA_REM_DZAKTPR(void)=0;
   virtual void set_DocIMYA_REM_DZAKTPR(TFIBWideStringField * DocIMYA_REM_DZAKTPR)=0;

   __property TFIBWideStringField * DocOTCHESTVO_REM_DZAKTPR = {read = get_DocOTCHESTVO_REM_DZAKTPR , write = set_DocOTCHESTVO_REM_DZAKTPR};
   virtual TFIBWideStringField * get_DocOTCHESTVO_REM_DZAKTPR(void)=0;
   virtual void set_DocOTCHESTVO_REM_DZAKTPR(TFIBWideStringField * DocOTCHESTVO_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * DocTIDPRNEISPR_REM_DZAKTPRT = {read = get_DocTIDPRNEISPR_REM_DZAKTPRT , write = set_DocTIDPRNEISPR_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDPRNEISPR_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDPRNEISPR_REM_DZAKTPRT(TFIBLargeIntField * DocTIDPRNEISPR_REM_DZAKTPRT)=0;

   __property TFIBLargeIntField * DocTIDPRRABOTA_REM_DZAKTPRT = {read = get_DocTIDPRRABOTA_REM_DZAKTPRT , write = set_DocTIDPRRABOTA_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDPRRABOTA_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDPRRABOTA_REM_DZAKTPRT(TFIBLargeIntField * DocTIDPRRABOTA_REM_DZAKTPRT)=0;

   __property TFIBLargeIntField * DocTIDHWOLD_REM_DZAKTPRT = {read = get_DocTIDHWOLD_REM_DZAKTPRT , write = set_DocTIDHWOLD_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDHWOLD_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDHWOLD_REM_DZAKTPRT(TFIBLargeIntField * DocTIDHWOLD_REM_DZAKTPRT)=0;

   __property TFIBSmallIntField * DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT = {read = get_DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT , write = set_DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT};
   virtual TFIBSmallIntField * get_DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT(void)=0;
   virtual void set_DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT(TFIBSmallIntField * DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT)=0;

   __property TFIBWideStringField * DocTNAME_REM_SPRNEISPR = {read = get_DocTNAME_REM_SPRNEISPR , write = set_DocTNAME_REM_SPRNEISPR};
   virtual TFIBWideStringField * get_DocTNAME_REM_SPRNEISPR(void)=0;
   virtual void set_DocTNAME_REM_SPRNEISPR(TFIBWideStringField * DocTNAME_REM_SPRNEISPR)=0;

   __property TFIBWideStringField * DocTNAME_ENG_REM_SPRNEISPR = {read = get_DocTNAME_ENG_REM_SPRNEISPR , write = set_DocTNAME_ENG_REM_SPRNEISPR};
   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRNEISPR(void)=0;
   virtual void set_DocTNAME_ENG_REM_SPRNEISPR(TFIBWideStringField * DocTNAME_ENG_REM_SPRNEISPR)=0;

   __property TFIBWideStringField * DocTCODE_REM_SPRNEISPR = {read = get_DocTCODE_REM_SPRNEISPR , write = set_DocTCODE_REM_SPRNEISPR};
   virtual TFIBWideStringField * get_DocTCODE_REM_SPRNEISPR(void)=0;
   virtual void set_DocTCODE_REM_SPRNEISPR(TFIBWideStringField * DocTCODE_REM_SPRNEISPR)=0;

   __property TFIBWideStringField * DocTNAME_REM_SPRNEISPR_GRP = {read = get_DocTNAME_REM_SPRNEISPR_GRP , write = set_DocTNAME_REM_SPRNEISPR_GRP};
   virtual TFIBWideStringField * get_DocTNAME_REM_SPRNEISPR_GRP(void)=0;
   virtual void set_DocTNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * DocTNAME_REM_SPRNEISPR_GRP)=0;

   __property TFIBWideStringField * DocTNAME_ENG_REM_SPRNEISPR_GRP = {read = get_DocTNAME_ENG_REM_SPRNEISPR_GRP , write = set_DocTNAME_ENG_REM_SPRNEISPR_GRP};
   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRNEISPR_GRP(void)=0;
   virtual void set_DocTNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRNEISPR_GRP)=0;

   __property TFIBWideStringField * DocTNAME_REM_SPRDEFECT_GRP = {read = get_DocTNAME_REM_SPRDEFECT_GRP , write = set_DocTNAME_REM_SPRDEFECT_GRP};
   virtual TFIBWideStringField * get_DocTNAME_REM_SPRDEFECT_GRP(void)=0;
   virtual void set_DocTNAME_REM_SPRDEFECT_GRP(TFIBWideStringField * DocTNAME_REM_SPRDEFECT_GRP)=0;

   __property TFIBWideStringField * DocTNAME_ENG_REM_SPRDEFECT_GRP = {read = get_DocTNAME_ENG_REM_SPRDEFECT_GRP , write = set_DocTNAME_ENG_REM_SPRDEFECT_GRP};
   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRDEFECT_GRP(void)=0;
   virtual void set_DocTNAME_ENG_REM_SPRDEFECT_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRDEFECT_GRP)=0;

   __property TFIBWideStringField * DocTCODE_REM_SPRRABOTA = {read = get_DocTCODE_REM_SPRRABOTA , write = set_DocTCODE_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_DocTCODE_REM_SPRRABOTA(void)=0;
   virtual void set_DocTCODE_REM_SPRRABOTA(TFIBWideStringField * DocTCODE_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * DocTNAME_REM_SPRRABOTA = {read = get_DocTNAME_REM_SPRRABOTA , write = set_DocTNAME_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_DocTNAME_REM_SPRRABOTA(void)=0;
   virtual void set_DocTNAME_REM_SPRRABOTA(TFIBWideStringField * DocTNAME_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * DocTNAME_ENG_REM_SPRRABOTA = {read = get_DocTNAME_ENG_REM_SPRRABOTA , write = set_DocTNAME_ENG_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRRABOTA(void)=0;
   virtual void set_DocTNAME_ENG_REM_SPRRABOTA(TFIBWideStringField * DocTNAME_ENG_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * DocTNAME_REM_SPRRABOTA_GRP = {read = get_DocTNAME_REM_SPRRABOTA_GRP , write = set_DocTNAME_REM_SPRRABOTA_GRP};
   virtual TFIBWideStringField * get_DocTNAME_REM_SPRRABOTA_GRP(void)=0;
   virtual void set_DocTNAME_REM_SPRRABOTA_GRP(TFIBWideStringField * DocTNAME_REM_SPRRABOTA_GRP)=0;

   __property TFIBWideStringField * DocTNAME_ENG_REM_SPRRABOTA_GRP = {read = get_DocTNAME_ENG_REM_SPRRABOTA_GRP , write = set_DocTNAME_ENG_REM_SPRRABOTA_GRP};
   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRRABOTA_GRP(void)=0;
   virtual void set_DocTNAME_ENG_REM_SPRRABOTA_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRRABOTA_GRP)=0;

   __property TFIBWideStringField * DocTOLD_NAME_REM_SHARDWARE = {read = get_DocTOLD_NAME_REM_SHARDWARE , write = set_DocTOLD_NAME_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocTOLD_NAME_REM_SHARDWARE(void)=0;
   virtual void set_DocTOLD_NAME_REM_SHARDWARE(TFIBWideStringField * DocTOLD_NAME_REM_SHARDWARE)=0;

   __property TFIBIntegerField * DocTOLD_CODE_REM_SHARDWARE = {read = get_DocTOLD_CODE_REM_SHARDWARE , write = set_DocTOLD_CODE_REM_SHARDWARE};
   virtual TFIBIntegerField * get_DocTOLD_CODE_REM_SHARDWARE(void)=0;
   virtual void set_DocTOLD_CODE_REM_SHARDWARE(TFIBIntegerField * DocTOLD_CODE_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocTOLD_SERNUM_REM_SHARDWARE = {read = get_DocTOLD_SERNUM_REM_SHARDWARE , write = set_DocTOLD_SERNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocTOLD_SERNUM_REM_SHARDWARE(void)=0;
   virtual void set_DocTOLD_SERNUM_REM_SHARDWARE(TFIBWideStringField * DocTOLD_SERNUM_REM_SHARDWARE)=0;

   __property TFIBIntegerField * DocTFL_ISP_REM_DZAKTPRT = {read = get_DocTFL_ISP_REM_DZAKTPRT , write = set_DocTFL_ISP_REM_DZAKTPRT};
   virtual TFIBIntegerField * get_DocTFL_ISP_REM_DZAKTPRT(void)=0;
   virtual void set_DocTFL_ISP_REM_DZAKTPRT(TFIBIntegerField * DocTFL_ISP_REM_DZAKTPRT)=0;

   __property TFIBLargeIntField * DocTIDPRCOND_REM_DZAKTPRT = {read = get_DocTIDPRCOND_REM_DZAKTPRT , write = set_DocTIDPRCOND_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDPRCOND_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDPRCOND_REM_DZAKTPRT(TFIBLargeIntField * DocTIDPRCOND_REM_DZAKTPRT)=0;

   __property TFIBLargeIntField * DocTIDPRSECTION_REM_DZAKTPRT = {read = get_DocTIDPRSECTION_REM_DZAKTPRT , write = set_DocTIDPRSECTION_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDPRSECTION_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDPRSECTION_REM_DZAKTPRT(TFIBLargeIntField * DocTIDPRSECTION_REM_DZAKTPRT)=0;

   __property TFIBWideStringField * DocTCODE_REM_SPRCONDITION = {read = get_DocTCODE_REM_SPRCONDITION , write = set_DocTCODE_REM_SPRCONDITION};
   virtual TFIBWideStringField * get_DocTCODE_REM_SPRCONDITION(void)=0;
   virtual void set_DocTCODE_REM_SPRCONDITION(TFIBWideStringField * DocTCODE_REM_SPRCONDITION)=0;

   __property TFIBWideStringField * DocTNAME_REM_SPRCONDITION = {read = get_DocTNAME_REM_SPRCONDITION , write = set_DocTNAME_REM_SPRCONDITION};
   virtual TFIBWideStringField * get_DocTNAME_REM_SPRCONDITION(void)=0;
   virtual void set_DocTNAME_REM_SPRCONDITION(TFIBWideStringField * DocTNAME_REM_SPRCONDITION)=0;

   __property TFIBWideStringField * DocTNAME_ENG_REM_SPRCONDITION = {read = get_DocTNAME_ENG_REM_SPRCONDITION , write = set_DocTNAME_ENG_REM_SPRCONDITION};
   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRCONDITION(void)=0;
   virtual void set_DocTNAME_ENG_REM_SPRCONDITION(TFIBWideStringField * DocTNAME_ENG_REM_SPRCONDITION)=0;

   __property TFIBWideStringField * DocTCODE_REM_SPRCOND_GRP = {read = get_DocTCODE_REM_SPRCOND_GRP , write = set_DocTCODE_REM_SPRCOND_GRP};
   virtual TFIBWideStringField * get_DocTCODE_REM_SPRCOND_GRP(void)=0;
   virtual void set_DocTCODE_REM_SPRCOND_GRP(TFIBWideStringField * DocTCODE_REM_SPRCOND_GRP)=0;

   __property TFIBWideStringField * DocTNAME_REM_SPRCOND_GRP = {read = get_DocTNAME_REM_SPRCOND_GRP , write = set_DocTNAME_REM_SPRCOND_GRP};
   virtual TFIBWideStringField * get_DocTNAME_REM_SPRCOND_GRP(void)=0;
   virtual void set_DocTNAME_REM_SPRCOND_GRP(TFIBWideStringField * DocTNAME_REM_SPRCOND_GRP)=0;

   __property TFIBWideStringField * DocTNAME_ENG_REM_SPRCOND_GRP = {read = get_DocTNAME_ENG_REM_SPRCOND_GRP , write = set_DocTNAME_ENG_REM_SPRCOND_GRP};
   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRCOND_GRP(void)=0;
   virtual void set_DocTNAME_ENG_REM_SPRCOND_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRCOND_GRP)=0;

   __property TFIBWideStringField * DocTCODE_REM_SPRSECTION = {read = get_DocTCODE_REM_SPRSECTION , write = set_DocTCODE_REM_SPRSECTION};
   virtual TFIBWideStringField * get_DocTCODE_REM_SPRSECTION(void)=0;
   virtual void set_DocTCODE_REM_SPRSECTION(TFIBWideStringField * DocTCODE_REM_SPRSECTION)=0;

   __property TFIBWideStringField * DocTNAME_REM_SPRSECTION = {read = get_DocTNAME_REM_SPRSECTION , write = set_DocTNAME_REM_SPRSECTION};
   virtual TFIBWideStringField * get_DocTNAME_REM_SPRSECTION(void)=0;
   virtual void set_DocTNAME_REM_SPRSECTION(TFIBWideStringField * DocTNAME_REM_SPRSECTION)=0;

   __property TFIBWideStringField * DocTNAME_ENG_REM_SPRSECTION = {read = get_DocTNAME_ENG_REM_SPRSECTION , write = set_DocTNAME_ENG_REM_SPRSECTION};
   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRSECTION(void)=0;
   virtual void set_DocTNAME_ENG_REM_SPRSECTION(TFIBWideStringField * DocTNAME_ENG_REM_SPRSECTION)=0;

   __property TFIBWideStringField * DocTCODE_REM_SPRSECTION_GRP = {read = get_DocTCODE_REM_SPRSECTION_GRP , write = set_DocTCODE_REM_SPRSECTION_GRP};
   virtual TFIBWideStringField * get_DocTCODE_REM_SPRSECTION_GRP(void)=0;
   virtual void set_DocTCODE_REM_SPRSECTION_GRP(TFIBWideStringField * DocTCODE_REM_SPRSECTION_GRP)=0;

   __property TFIBWideStringField * DocTNAME_REM_SPRSECTION_GRP = {read = get_DocTNAME_REM_SPRSECTION_GRP , write = set_DocTNAME_REM_SPRSECTION_GRP};
   virtual TFIBWideStringField * get_DocTNAME_REM_SPRSECTION_GRP(void)=0;
   virtual void set_DocTNAME_REM_SPRSECTION_GRP(TFIBWideStringField * DocTNAME_REM_SPRSECTION_GRP)=0;

   __property TFIBWideStringField * DocTNAME_ENG_REM_SPRSECTION_GRP = {read = get_DocTNAME_ENG_REM_SPRSECTION_GRP , write = set_DocTNAME_ENG_REM_SPRSECTION_GRP};
   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRSECTION_GRP(void)=0;
   virtual void set_DocTNAME_ENG_REM_SPRSECTION_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRSECTION_GRP)=0;

   __property TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC = {read = get_DocAllIDOBJECT_REM_GALLDOC , write = set_DocAllIDOBJECT_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDOBJECT_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDOBJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SOBJECT = {read = get_DocAllNAME_SOBJECT , write = set_DocAllNAME_SOBJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SOBJECT(void)=0;
   virtual void set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT)=0;

   __property TFIBLargeIntField * DocTIDTNOM_REM_DZAKTPRT = {read = get_DocTIDTNOM_REM_DZAKTPRT , write = set_DocTIDTNOM_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDTNOM_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDTNOM_REM_DZAKTPRT(TFIBLargeIntField * DocTIDTNOM_REM_DZAKTPRT)=0;

   __property TFIBLargeIntField * DocTIDHW_DONOR_REM_DZAKTPRT = {read = get_DocTIDHW_DONOR_REM_DZAKTPRT , write = set_DocTIDHW_DONOR_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDHW_DONOR_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDHW_DONOR_REM_DZAKTPRT(TFIBLargeIntField * DocTIDHW_DONOR_REM_DZAKTPRT)=0;

   __property TFIBLargeIntField * DocTIDTYP_USEL_REM_DZAKTPRT = {read = get_DocTIDTYP_USEL_REM_DZAKTPRT , write = set_DocTIDTYP_USEL_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDTYP_USEL_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDTYP_USEL_REM_DZAKTPRT(TFIBLargeIntField * DocTIDTYP_USEL_REM_DZAKTPRT)=0;

   __property TFIBWideStringField * DocTDESCR_REM_DZAKTPRT = {read = get_DocTDESCR_REM_DZAKTPRT , write = set_DocTDESCR_REM_DZAKTPRT};
   virtual TFIBWideStringField * get_DocTDESCR_REM_DZAKTPRT(void)=0;
   virtual void set_DocTDESCR_REM_DZAKTPRT(TFIBWideStringField * DocTDESCR_REM_DZAKTPRT)=0;

   __property TFIBWideStringField * DocTDONOR_NAME_REM_SHARDWARE = {read = get_DocTDONOR_NAME_REM_SHARDWARE , write = set_DocTDONOR_NAME_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocTDONOR_NAME_REM_SHARDWARE(void)=0;
   virtual void set_DocTDONOR_NAME_REM_SHARDWARE(TFIBWideStringField * DocTDONOR_NAME_REM_SHARDWARE)=0;

   __property TFIBIntegerField * DocTDONOR_CODE_REM_SHARDWARE = {read = get_DocTDONOR_CODE_REM_SHARDWARE , write = set_DocTDONOR_CODE_REM_SHARDWARE};
   virtual TFIBIntegerField * get_DocTDONOR_CODE_REM_SHARDWARE(void)=0;
   virtual void set_DocTDONOR_CODE_REM_SHARDWARE(TFIBIntegerField * DocTDONOR_CODE_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocTDONOR_SERNUM_REM_SHARDWARE = {read = get_DocTDONOR_SERNUM_REM_SHARDWARE , write = set_DocTDONOR_SERNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocTDONOR_SERNUM_REM_SHARDWARE(void)=0;
   virtual void set_DocTDONOR_SERNUM_REM_SHARDWARE(TFIBWideStringField * DocTDONOR_SERNUM_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocTNAME_REM_STYPUSLOV = {read = get_DocTNAME_REM_STYPUSLOV , write = set_DocTNAME_REM_STYPUSLOV};
   virtual TFIBWideStringField * get_DocTNAME_REM_STYPUSLOV(void)=0;
   virtual void set_DocTNAME_REM_STYPUSLOV(TFIBWideStringField * DocTNAME_REM_STYPUSLOV)=0;

   __property TFIBWideStringField * DocTNAME_STNOM = {read = get_DocTNAME_STNOM , write = set_DocTNAME_STNOM};
   virtual TFIBWideStringField * get_DocTNAME_STNOM(void)=0;
   virtual void set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)=0;

   __property TpFIBDataSet * TypeNom = {read = get_TypeNom , write = set_TypeNom};
   virtual TpFIBDataSet * get_TypeNom(void)=0;
   virtual void set_TypeNom(TpFIBDataSet * TypeNom)=0;

   __property TFIBLargeIntField * TypeNomID_STNOM = {read = get_TypeNomID_STNOM , write = set_TypeNomID_STNOM};
   virtual TFIBLargeIntField * get_TypeNomID_STNOM(void)=0;
   virtual void set_TypeNomID_STNOM(TFIBLargeIntField * TypeNomID_STNOM)=0;

   __property TFIBWideStringField * TypeNomNAME_STNOM = {read = get_TypeNomNAME_STNOM , write = set_TypeNomNAME_STNOM};
   virtual TFIBWideStringField * get_TypeNomNAME_STNOM(void)=0;
   virtual void set_TypeNomNAME_STNOM(TFIBWideStringField * TypeNomNAME_STNOM)=0;

   __property TStringField * DocTNAME_TYPE_NOM_LOOCUP = {read = get_DocTNAME_TYPE_NOM_LOOCUP , write = set_DocTNAME_TYPE_NOM_LOOCUP};
   virtual TStringField * get_DocTNAME_TYPE_NOM_LOOCUP(void)=0;
   virtual void set_DocTNAME_TYPE_NOM_LOOCUP(TStringField * DocTNAME_TYPE_NOM_LOOCUP)=0;

   __property TFIBSmallIntField * DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR = {read = get_DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR , write = set_DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR};
   virtual TFIBSmallIntField * get_DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR(void)=0;
   virtual void set_DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR(TFIBSmallIntField * DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * DocTIDTVZIP_REM_DZAKTPRT = {read = get_DocTIDTVZIP_REM_DZAKTPRT , write = set_DocTIDTVZIP_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDTVZIP_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDTVZIP_REM_DZAKTPRT(TFIBLargeIntField * DocTIDTVZIP_REM_DZAKTPRT)=0;

   __property TFIBLargeIntField * DocTIDMHRAN_REM_DZAKTPRT = {read = get_DocTIDMHRAN_REM_DZAKTPRT , write = set_DocTIDMHRAN_REM_DZAKTPRT};
   virtual TFIBLargeIntField * get_DocTIDMHRAN_REM_DZAKTPRT(void)=0;
   virtual void set_DocTIDMHRAN_REM_DZAKTPRT(TFIBLargeIntField * DocTIDMHRAN_REM_DZAKTPRT)=0;

   __property TFIBWideStringField * DocTNAME_SMHRAN = {read = get_DocTNAME_SMHRAN , write = set_DocTNAME_SMHRAN};
   virtual TFIBWideStringField * get_DocTNAME_SMHRAN(void)=0;
   virtual void set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN)=0;

   __property TFIBWideStringField * DocTNAME_REM_STVZIP = {read = get_DocTNAME_REM_STVZIP , write = set_DocTNAME_REM_STVZIP};
   virtual TFIBWideStringField * get_DocTNAME_REM_STVZIP(void)=0;
   virtual void set_DocTNAME_REM_STVZIP(TFIBWideStringField * DocTNAME_REM_STVZIP)=0;

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
   virtual void TableAppend(void)=0;
   virtual void TableDelete(void)=0;
};
#define IID_IREM_DMDocZAktPr __uuidof(IREM_DMDocZAktPr)
#endif
