#ifndef UIREM_DMDocAktH
#define UIREM_DMDocAktH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMDocAkt)) IREM_DMDocAkt : public IMainInterface
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

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBLargeIntField * DocID_REM_DAKT = {read = get_DocID_REM_DAKT , write = set_DocID_REM_DAKT};
   virtual TFIBLargeIntField * get_DocID_REM_DAKT(void)=0;
   virtual void set_DocID_REM_DAKT(TFIBLargeIntField * DocID_REM_DAKT)=0;

   __property TFIBLargeIntField * DocIDBASE_REM_DAKT = {read = get_DocIDBASE_REM_DAKT , write = set_DocIDBASE_REM_DAKT};
   virtual TFIBLargeIntField * get_DocIDBASE_REM_DAKT(void)=0;
   virtual void set_DocIDBASE_REM_DAKT(TFIBLargeIntField * DocIDBASE_REM_DAKT)=0;

   __property TFIBWideStringField * DocGID_REM_DAKT = {read = get_DocGID_REM_DAKT , write = set_DocGID_REM_DAKT};
   virtual TFIBWideStringField * get_DocGID_REM_DAKT(void)=0;
   virtual void set_DocGID_REM_DAKT(TFIBWideStringField * DocGID_REM_DAKT)=0;

   __property TFIBLargeIntField * DocIDDOC_REM_DAKT = {read = get_DocIDDOC_REM_DAKT , write = set_DocIDDOC_REM_DAKT};
   virtual TFIBLargeIntField * get_DocIDDOC_REM_DAKT(void)=0;
   virtual void set_DocIDDOC_REM_DAKT(TFIBLargeIntField * DocIDDOC_REM_DAKT)=0;

   __property TFIBLargeIntField * DocIDZ_REM_DAKT = {read = get_DocIDZ_REM_DAKT , write = set_DocIDZ_REM_DAKT};
   virtual TFIBLargeIntField * get_DocIDZ_REM_DAKT(void)=0;
   virtual void set_DocIDZ_REM_DAKT(TFIBLargeIntField * DocIDZ_REM_DAKT)=0;

   __property TFIBLargeIntField * DocIDHW_REM_DAKT = {read = get_DocIDHW_REM_DAKT , write = set_DocIDHW_REM_DAKT};
   virtual TFIBLargeIntField * get_DocIDHW_REM_DAKT(void)=0;
   virtual void set_DocIDHW_REM_DAKT(TFIBLargeIntField * DocIDHW_REM_DAKT)=0;

   __property TFIBLargeIntField * DocIDKKT_REM_DAKT = {read = get_DocIDKKT_REM_DAKT , write = set_DocIDKKT_REM_DAKT};
   virtual TFIBLargeIntField * get_DocIDKKT_REM_DAKT(void)=0;
   virtual void set_DocIDKKT_REM_DAKT(TFIBLargeIntField * DocIDKKT_REM_DAKT)=0;

   __property TFIBWideStringField * DocPRIM_REM_DAKT = {read = get_DocPRIM_REM_DAKT , write = set_DocPRIM_REM_DAKT};
   virtual TFIBWideStringField * get_DocPRIM_REM_DAKT(void)=0;
   virtual void set_DocPRIM_REM_DAKT(TFIBWideStringField * DocPRIM_REM_DAKT)=0;

   __property TFIBSmallIntField * DocKL_SOGLASEN_REM_DAKT = {read = get_DocKL_SOGLASEN_REM_DAKT , write = set_DocKL_SOGLASEN_REM_DAKT};
   virtual TFIBSmallIntField * get_DocKL_SOGLASEN_REM_DAKT(void)=0;
   virtual void set_DocKL_SOGLASEN_REM_DAKT(TFIBSmallIntField * DocKL_SOGLASEN_REM_DAKT)=0;

   __property TFIBSmallIntField * DocPODPISAN_REM_DAKT = {read = get_DocPODPISAN_REM_DAKT , write = set_DocPODPISAN_REM_DAKT};
   virtual TFIBSmallIntField * get_DocPODPISAN_REM_DAKT(void)=0;
   virtual void set_DocPODPISAN_REM_DAKT(TFIBSmallIntField * DocPODPISAN_REM_DAKT)=0;

   __property TFIBIntegerField * DocTYPE_REM_DAKT = {read = get_DocTYPE_REM_DAKT , write = set_DocTYPE_REM_DAKT};
   virtual TFIBIntegerField * get_DocTYPE_REM_DAKT(void)=0;
   virtual void set_DocTYPE_REM_DAKT(TFIBIntegerField * DocTYPE_REM_DAKT)=0;

   __property TFIBWideStringField * DocNAME_REM_SHARDWARE = {read = get_DocNAME_REM_SHARDWARE , write = set_DocNAME_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocNAME_REM_SHARDWARE(void)=0;
   virtual void set_DocNAME_REM_SHARDWARE(TFIBWideStringField * DocNAME_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocSERNUM_REM_SHARDWARE = {read = get_DocSERNUM_REM_SHARDWARE , write = set_DocSERNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocSERNUM_REM_SHARDWARE(void)=0;
   virtual void set_DocSERNUM_REM_SHARDWARE(TFIBWideStringField * DocSERNUM_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocSERNUM2_REM_SHARDWARE = {read = get_DocSERNUM2_REM_SHARDWARE , write = set_DocSERNUM2_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocSERNUM2_REM_SHARDWARE(void)=0;
   virtual void set_DocSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocSERNUM2_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocNAME_REM_SKKT = {read = get_DocNAME_REM_SKKT , write = set_DocNAME_REM_SKKT};
   virtual TFIBWideStringField * get_DocNAME_REM_SKKT(void)=0;
   virtual void set_DocNAME_REM_SKKT(TFIBWideStringField * DocNAME_REM_SKKT)=0;

   __property TFIBWideStringField * DocSERNUM_REM_SKKT = {read = get_DocSERNUM_REM_SKKT , write = set_DocSERNUM_REM_SKKT};
   virtual TFIBWideStringField * get_DocSERNUM_REM_SKKT(void)=0;
   virtual void set_DocSERNUM_REM_SKKT(TFIBWideStringField * DocSERNUM_REM_SKKT)=0;

   __property TFIBWideStringField * DocSERNUM_REM_Z = {read = get_DocSERNUM_REM_Z , write = set_DocSERNUM_REM_Z};
   virtual TFIBWideStringField * get_DocSERNUM_REM_Z(void)=0;
   virtual void set_DocSERNUM_REM_Z(TFIBWideStringField * DocSERNUM_REM_Z)=0;

   __property TFIBWideStringField * DocSERNUM2_REM_Z = {read = get_DocSERNUM2_REM_Z , write = set_DocSERNUM2_REM_Z};
   virtual TFIBWideStringField * get_DocSERNUM2_REM_Z(void)=0;
   virtual void set_DocSERNUM2_REM_Z(TFIBWideStringField * DocSERNUM2_REM_Z)=0;

   __property TFIBWideStringField * DocMODEL_REM_Z = {read = get_DocMODEL_REM_Z , write = set_DocMODEL_REM_Z};
   virtual TFIBWideStringField * get_DocMODEL_REM_Z(void)=0;
   virtual void set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z)=0;

   __property TFIBWideStringField * DocNAME_REM_SMODEL = {read = get_DocNAME_REM_SMODEL , write = set_DocNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_DocNAME_REM_SMODEL(void)=0;
   virtual void set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL)=0;

   __property TFIBLargeIntField * DocTID_REM_DAKTT = {read = get_DocTID_REM_DAKTT , write = set_DocTID_REM_DAKTT};
   virtual TFIBLargeIntField * get_DocTID_REM_DAKTT(void)=0;
   virtual void set_DocTID_REM_DAKTT(TFIBLargeIntField * DocTID_REM_DAKTT)=0;

   __property TFIBLargeIntField * DocTIDBASE_REM_DAKTT = {read = get_DocTIDBASE_REM_DAKTT , write = set_DocTIDBASE_REM_DAKTT};
   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DAKTT(void)=0;
   virtual void set_DocTIDBASE_REM_DAKTT(TFIBLargeIntField * DocTIDBASE_REM_DAKTT)=0;

   __property TFIBWideStringField * DocTGID_REM_DAKTT = {read = get_DocTGID_REM_DAKTT , write = set_DocTGID_REM_DAKTT};
   virtual TFIBWideStringField * get_DocTGID_REM_DAKTT(void)=0;
   virtual void set_DocTGID_REM_DAKTT(TFIBWideStringField * DocTGID_REM_DAKTT)=0;

   __property TFIBLargeIntField * DocTIDDOC_REM_DAKTT = {read = get_DocTIDDOC_REM_DAKTT , write = set_DocTIDDOC_REM_DAKTT};
   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DAKTT(void)=0;
   virtual void set_DocTIDDOC_REM_DAKTT(TFIBLargeIntField * DocTIDDOC_REM_DAKTT)=0;

   __property TFIBIntegerField * DocTINDEX_REM_DAKTT = {read = get_DocTINDEX_REM_DAKTT , write = set_DocTINDEX_REM_DAKTT};
   virtual TFIBIntegerField * get_DocTINDEX_REM_DAKTT(void)=0;
   virtual void set_DocTINDEX_REM_DAKTT(TFIBIntegerField * DocTINDEX_REM_DAKTT)=0;

   __property TFIBWideStringField * DocTTEXT_REM_DAKTT = {read = get_DocTTEXT_REM_DAKTT , write = set_DocTTEXT_REM_DAKTT};
   virtual TFIBWideStringField * get_DocTTEXT_REM_DAKTT(void)=0;
   virtual void set_DocTTEXT_REM_DAKTT(TFIBWideStringField * DocTTEXT_REM_DAKTT)=0;

   __property TFIBWideStringField * DocNAME_REM_Z = {read = get_DocNAME_REM_Z , write = set_DocNAME_REM_Z};
   virtual TFIBWideStringField * get_DocNAME_REM_Z(void)=0;
   virtual void set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z)=0;

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

   __property TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC = {read = get_DocAllIDOBJECT_REM_GALLDOC , write = set_DocAllIDOBJECT_REM_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDOBJECT_REM_GALLDOC(void)=0;
   virtual void set_DocAllIDOBJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SOBJECT = {read = get_DocAllNAME_SOBJECT , write = set_DocAllNAME_SOBJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SOBJECT(void)=0;
   virtual void set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT)=0;

   __property TFIBWideStringField * DocNUM_U_PROISV_REM_DAKT = {read = get_DocNUM_U_PROISV_REM_DAKT , write = set_DocNUM_U_PROISV_REM_DAKT};
   virtual TFIBWideStringField * get_DocNUM_U_PROISV_REM_DAKT(void)=0;
   virtual void set_DocNUM_U_PROISV_REM_DAKT(TFIBWideStringField * DocNUM_U_PROISV_REM_DAKT)=0;

   __property TFIBWideStringField * DocNEISPR_KLIENTA_REM_DAKT = {read = get_DocNEISPR_KLIENTA_REM_DAKT , write = set_DocNEISPR_KLIENTA_REM_DAKT};
   virtual TFIBWideStringField * get_DocNEISPR_KLIENTA_REM_DAKT(void)=0;
   virtual void set_DocNEISPR_KLIENTA_REM_DAKT(TFIBWideStringField * DocNEISPR_KLIENTA_REM_DAKT)=0;

   __property TFIBWideStringField * DocNEISPR_SC_REM_DAKT = {read = get_DocNEISPR_SC_REM_DAKT , write = set_DocNEISPR_SC_REM_DAKT};
   virtual TFIBWideStringField * get_DocNEISPR_SC_REM_DAKT(void)=0;
   virtual void set_DocNEISPR_SC_REM_DAKT(TFIBWideStringField * DocNEISPR_SC_REM_DAKT)=0;

   __property TFIBIntegerField * DocFL_FULL_KOMPL_REM_DAKT = {read = get_DocFL_FULL_KOMPL_REM_DAKT , write = set_DocFL_FULL_KOMPL_REM_DAKT};
   virtual TFIBIntegerField * get_DocFL_FULL_KOMPL_REM_DAKT(void)=0;
   virtual void set_DocFL_FULL_KOMPL_REM_DAKT(TFIBIntegerField * DocFL_FULL_KOMPL_REM_DAKT)=0;

   __property TFIBWideStringField * DocNEKOMPL_STR_REM_DAKT = {read = get_DocNEKOMPL_STR_REM_DAKT , write = set_DocNEKOMPL_STR_REM_DAKT};
   virtual TFIBWideStringField * get_DocNEKOMPL_STR_REM_DAKT(void)=0;
   virtual void set_DocNEKOMPL_STR_REM_DAKT(TFIBWideStringField * DocNEKOMPL_STR_REM_DAKT)=0;

   __property TFIBWideStringField * DocKOMPL_STR_REM_DAKT = {read = get_DocKOMPL_STR_REM_DAKT , write = set_DocKOMPL_STR_REM_DAKT};
   virtual TFIBWideStringField * get_DocKOMPL_STR_REM_DAKT(void)=0;
   virtual void set_DocKOMPL_STR_REM_DAKT(TFIBWideStringField * DocKOMPL_STR_REM_DAKT)=0;

   __property TFIBIntegerField * DocFL_MEXPOVR_REM_DAKT = {read = get_DocFL_MEXPOVR_REM_DAKT , write = set_DocFL_MEXPOVR_REM_DAKT};
   virtual TFIBIntegerField * get_DocFL_MEXPOVR_REM_DAKT(void)=0;
   virtual void set_DocFL_MEXPOVR_REM_DAKT(TFIBIntegerField * DocFL_MEXPOVR_REM_DAKT)=0;

   __property TFIBWideStringField * DocMEXPOVR_STR_REM_DAKT = {read = get_DocMEXPOVR_STR_REM_DAKT , write = set_DocMEXPOVR_STR_REM_DAKT};
   virtual TFIBWideStringField * get_DocMEXPOVR_STR_REM_DAKT(void)=0;
   virtual void set_DocMEXPOVR_STR_REM_DAKT(TFIBWideStringField * DocMEXPOVR_STR_REM_DAKT)=0;

   __property TFIBWideStringField * DocNEISPR_BLOK_REM_DAKT = {read = get_DocNEISPR_BLOK_REM_DAKT , write = set_DocNEISPR_BLOK_REM_DAKT};
   virtual TFIBWideStringField * get_DocNEISPR_BLOK_REM_DAKT(void)=0;
   virtual void set_DocNEISPR_BLOK_REM_DAKT(TFIBWideStringField * DocNEISPR_BLOK_REM_DAKT)=0;

   __property TFIBIntegerField * DocFL_PRICHINA_ACTA_REM_DAKT = {read = get_DocFL_PRICHINA_ACTA_REM_DAKT , write = set_DocFL_PRICHINA_ACTA_REM_DAKT};
   virtual TFIBIntegerField * get_DocFL_PRICHINA_ACTA_REM_DAKT(void)=0;
   virtual void set_DocFL_PRICHINA_ACTA_REM_DAKT(TFIBIntegerField * DocFL_PRICHINA_ACTA_REM_DAKT)=0;

   __property TFIBWideStringField * DocPRICHINA_ACTA_DR_STR_REM_DAKT = {read = get_DocPRICHINA_ACTA_DR_STR_REM_DAKT , write = set_DocPRICHINA_ACTA_DR_STR_REM_DAKT};
   virtual TFIBWideStringField * get_DocPRICHINA_ACTA_DR_STR_REM_DAKT(void)=0;
   virtual void set_DocPRICHINA_ACTA_DR_STR_REM_DAKT(TFIBWideStringField * DocPRICHINA_ACTA_DR_STR_REM_DAKT)=0;

   __property TFIBIntegerField * DocFL_PRICHINA_SOST_REM_DAKT = {read = get_DocFL_PRICHINA_SOST_REM_DAKT , write = set_DocFL_PRICHINA_SOST_REM_DAKT};
   virtual TFIBIntegerField * get_DocFL_PRICHINA_SOST_REM_DAKT(void)=0;
   virtual void set_DocFL_PRICHINA_SOST_REM_DAKT(TFIBIntegerField * DocFL_PRICHINA_SOST_REM_DAKT)=0;

   __property TFIBIntegerField * DocFL_MESTONAX_REM_DAKT = {read = get_DocFL_MESTONAX_REM_DAKT , write = set_DocFL_MESTONAX_REM_DAKT};
   virtual TFIBIntegerField * get_DocFL_MESTONAX_REM_DAKT(void)=0;
   virtual void set_DocFL_MESTONAX_REM_DAKT(TFIBIntegerField * DocFL_MESTONAX_REM_DAKT)=0;

   __property TFIBWideStringField * DocISD_NAME_REM_DAKT = {read = get_DocISD_NAME_REM_DAKT , write = set_DocISD_NAME_REM_DAKT};
   virtual TFIBWideStringField * get_DocISD_NAME_REM_DAKT(void)=0;
   virtual void set_DocISD_NAME_REM_DAKT(TFIBWideStringField * DocISD_NAME_REM_DAKT)=0;

   __property TFIBDateField * DocISD_DATE_PRODAGI_REM_DAKT = {read = get_DocISD_DATE_PRODAGI_REM_DAKT , write = set_DocISD_DATE_PRODAGI_REM_DAKT};
   virtual TFIBDateField * get_DocISD_DATE_PRODAGI_REM_DAKT(void)=0;
   virtual void set_DocISD_DATE_PRODAGI_REM_DAKT(TFIBDateField * DocISD_DATE_PRODAGI_REM_DAKT)=0;

   __property TFIBWideStringField * DocISD_MODEL_REM_DAKT = {read = get_DocISD_MODEL_REM_DAKT , write = set_DocISD_MODEL_REM_DAKT};
   virtual TFIBWideStringField * get_DocISD_MODEL_REM_DAKT(void)=0;
   virtual void set_DocISD_MODEL_REM_DAKT(TFIBWideStringField * DocISD_MODEL_REM_DAKT)=0;

   __property TFIBWideStringField * DocISD_SERNUM1_REM_DAKT = {read = get_DocISD_SERNUM1_REM_DAKT , write = set_DocISD_SERNUM1_REM_DAKT};
   virtual TFIBWideStringField * get_DocISD_SERNUM1_REM_DAKT(void)=0;
   virtual void set_DocISD_SERNUM1_REM_DAKT(TFIBWideStringField * DocISD_SERNUM1_REM_DAKT)=0;

   __property TFIBWideStringField * DocISD_SERNUM2_REM_DAKT = {read = get_DocISD_SERNUM2_REM_DAKT , write = set_DocISD_SERNUM2_REM_DAKT};
   virtual TFIBWideStringField * get_DocISD_SERNUM2_REM_DAKT(void)=0;
   virtual void set_DocISD_SERNUM2_REM_DAKT(TFIBWideStringField * DocISD_SERNUM2_REM_DAKT)=0;

   __property TFIBWideStringField * DocISD_SERNUM3_REM_DAKT = {read = get_DocISD_SERNUM3_REM_DAKT , write = set_DocISD_SERNUM3_REM_DAKT};
   virtual TFIBWideStringField * get_DocISD_SERNUM3_REM_DAKT(void)=0;
   virtual void set_DocISD_SERNUM3_REM_DAKT(TFIBWideStringField * DocISD_SERNUM3_REM_DAKT)=0;

   __property TFIBWideStringField * DocISD_NUMUP_REM_DAKT = {read = get_DocISD_NUMUP_REM_DAKT , write = set_DocISD_NUMUP_REM_DAKT};
   virtual TFIBWideStringField * get_DocISD_NUMUP_REM_DAKT(void)=0;
   virtual void set_DocISD_NUMUP_REM_DAKT(TFIBWideStringField * DocISD_NUMUP_REM_DAKT)=0;

   __property TFIBWideStringField * DocISD_NUMTEXLIST_REM_DAKT = {read = get_DocISD_NUMTEXLIST_REM_DAKT , write = set_DocISD_NUMTEXLIST_REM_DAKT};
   virtual TFIBWideStringField * get_DocISD_NUMTEXLIST_REM_DAKT(void)=0;
   virtual void set_DocISD_NUMTEXLIST_REM_DAKT(TFIBWideStringField * DocISD_NUMTEXLIST_REM_DAKT)=0;

   __property TFIBWideStringField * DocPRODAVEC_NAME_REM_DAKT = {read = get_DocPRODAVEC_NAME_REM_DAKT , write = set_DocPRODAVEC_NAME_REM_DAKT};
   virtual TFIBWideStringField * get_DocPRODAVEC_NAME_REM_DAKT(void)=0;
   virtual void set_DocPRODAVEC_NAME_REM_DAKT(TFIBWideStringField * DocPRODAVEC_NAME_REM_DAKT)=0;

   __property TFIBWideStringField * DocPRODAVEC_TEL_REM_DAKT = {read = get_DocPRODAVEC_TEL_REM_DAKT , write = set_DocPRODAVEC_TEL_REM_DAKT};
   virtual TFIBWideStringField * get_DocPRODAVEC_TEL_REM_DAKT(void)=0;
   virtual void set_DocPRODAVEC_TEL_REM_DAKT(TFIBWideStringField * DocPRODAVEC_TEL_REM_DAKT)=0;

   __property TFIBWideStringField * DocKLIENT_NAME_REM_DAKT = {read = get_DocKLIENT_NAME_REM_DAKT , write = set_DocKLIENT_NAME_REM_DAKT};
   virtual TFIBWideStringField * get_DocKLIENT_NAME_REM_DAKT(void)=0;
   virtual void set_DocKLIENT_NAME_REM_DAKT(TFIBWideStringField * DocKLIENT_NAME_REM_DAKT)=0;

   __property TFIBWideStringField * DocKLIENT_ADR_REM_DAKT = {read = get_DocKLIENT_ADR_REM_DAKT , write = set_DocKLIENT_ADR_REM_DAKT};
   virtual TFIBWideStringField * get_DocKLIENT_ADR_REM_DAKT(void)=0;
   virtual void set_DocKLIENT_ADR_REM_DAKT(TFIBWideStringField * DocKLIENT_ADR_REM_DAKT)=0;

   __property TFIBWideStringField * DocKLIENT_PHONE_REM_DAKT = {read = get_DocKLIENT_PHONE_REM_DAKT , write = set_DocKLIENT_PHONE_REM_DAKT};
   virtual TFIBWideStringField * get_DocKLIENT_PHONE_REM_DAKT(void)=0;
   virtual void set_DocKLIENT_PHONE_REM_DAKT(TFIBWideStringField * DocKLIENT_PHONE_REM_DAKT)=0;

   __property TFIBWideStringField * DocPRICHINA_SOST_DR_REM_DAKT = {read = get_DocPRICHINA_SOST_DR_REM_DAKT , write = set_DocPRICHINA_SOST_DR_REM_DAKT};
   virtual TFIBWideStringField * get_DocPRICHINA_SOST_DR_REM_DAKT(void)=0;
   virtual void set_DocPRICHINA_SOST_DR_REM_DAKT(TFIBWideStringField * DocPRICHINA_SOST_DR_REM_DAKT)=0;

   __property TFIBWideStringField * DocPRODAVEC_ADR_REM_DAKT = {read = get_DocPRODAVEC_ADR_REM_DAKT , write = set_DocPRODAVEC_ADR_REM_DAKT};
   virtual TFIBWideStringField * get_DocPRODAVEC_ADR_REM_DAKT(void)=0;
   virtual void set_DocPRODAVEC_ADR_REM_DAKT(TFIBWideStringField * DocPRODAVEC_ADR_REM_DAKT)=0;

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
#define IID_IREM_DMDocAkt __uuidof(IREM_DMDocAkt)
#endif
