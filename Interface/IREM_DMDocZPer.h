#ifndef UIREM_DMDocZPerH
#define UIREM_DMDocZPerH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMDocZPer)) IREM_DMDocZPer : public IMainInterface
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

   __property TFIBLargeIntField * DocID_REM_DZPER = {read = get_DocID_REM_DZPER , write = set_DocID_REM_DZPER};
   virtual TFIBLargeIntField * get_DocID_REM_DZPER(void)=0;
   virtual void set_DocID_REM_DZPER(TFIBLargeIntField * DocID_REM_DZPER)=0;

   __property TFIBLargeIntField * DocIDBASE_REM_DZPER = {read = get_DocIDBASE_REM_DZPER , write = set_DocIDBASE_REM_DZPER};
   virtual TFIBLargeIntField * get_DocIDBASE_REM_DZPER(void)=0;
   virtual void set_DocIDBASE_REM_DZPER(TFIBLargeIntField * DocIDBASE_REM_DZPER)=0;

   __property TFIBWideStringField * DocGID_REM_DZPER = {read = get_DocGID_REM_DZPER , write = set_DocGID_REM_DZPER};
   virtual TFIBWideStringField * get_DocGID_REM_DZPER(void)=0;
   virtual void set_DocGID_REM_DZPER(TFIBWideStringField * DocGID_REM_DZPER)=0;

   __property TFIBLargeIntField * DocIDDOC_REM_DZPER = {read = get_DocIDDOC_REM_DZPER , write = set_DocIDDOC_REM_DZPER};
   virtual TFIBLargeIntField * get_DocIDDOC_REM_DZPER(void)=0;
   virtual void set_DocIDDOC_REM_DZPER(TFIBLargeIntField * DocIDDOC_REM_DZPER)=0;

   __property TFIBLargeIntField * DocIDSKLADPOL_REM_DZPER = {read = get_DocIDSKLADPOL_REM_DZPER , write = set_DocIDSKLADPOL_REM_DZPER};
   virtual TFIBLargeIntField * get_DocIDSKLADPOL_REM_DZPER(void)=0;
   virtual void set_DocIDSKLADPOL_REM_DZPER(TFIBLargeIntField * DocIDSKLADPOL_REM_DZPER)=0;

   __property TFIBWideStringField * DocPRIM_REM_DZPER = {read = get_DocPRIM_REM_DZPER , write = set_DocPRIM_REM_DZPER};
   virtual TFIBWideStringField * get_DocPRIM_REM_DZPER(void)=0;
   virtual void set_DocPRIM_REM_DZPER(TFIBWideStringField * DocPRIM_REM_DZPER)=0;

   __property TFIBWideStringField * DocNAMESKLAD = {read = get_DocNAMESKLAD , write = set_DocNAMESKLAD};
   virtual TFIBWideStringField * get_DocNAMESKLAD(void)=0;
   virtual void set_DocNAMESKLAD(TFIBWideStringField * DocNAMESKLAD)=0;

   __property TFIBLargeIntField * DocTID_REM_DZPERT = {read = get_DocTID_REM_DZPERT , write = set_DocTID_REM_DZPERT};
   virtual TFIBLargeIntField * get_DocTID_REM_DZPERT(void)=0;
   virtual void set_DocTID_REM_DZPERT(TFIBLargeIntField * DocTID_REM_DZPERT)=0;

   __property TFIBLargeIntField * DocTIDBASE_REM_DZPERT = {read = get_DocTIDBASE_REM_DZPERT , write = set_DocTIDBASE_REM_DZPERT};
   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DZPERT(void)=0;
   virtual void set_DocTIDBASE_REM_DZPERT(TFIBLargeIntField * DocTIDBASE_REM_DZPERT)=0;

   __property TFIBWideStringField * DocTGID_REM_DZPERT = {read = get_DocTGID_REM_DZPERT , write = set_DocTGID_REM_DZPERT};
   virtual TFIBWideStringField * get_DocTGID_REM_DZPERT(void)=0;
   virtual void set_DocTGID_REM_DZPERT(TFIBWideStringField * DocTGID_REM_DZPERT)=0;

   __property TFIBLargeIntField * DocTIDDOC_REM_DZPERT = {read = get_DocTIDDOC_REM_DZPERT , write = set_DocTIDDOC_REM_DZPERT};
   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DZPERT(void)=0;
   virtual void set_DocTIDDOC_REM_DZPERT(TFIBLargeIntField * DocTIDDOC_REM_DZPERT)=0;

   __property TFIBLargeIntField * DocTIDZ_REM_DZPERT = {read = get_DocTIDZ_REM_DZPERT , write = set_DocTIDZ_REM_DZPERT};
   virtual TFIBLargeIntField * get_DocTIDZ_REM_DZPERT(void)=0;
   virtual void set_DocTIDZ_REM_DZPERT(TFIBLargeIntField * DocTIDZ_REM_DZPERT)=0;

   __property TFIBBCDField * DocTKOL_REM_DZPERT = {read = get_DocTKOL_REM_DZPERT , write = set_DocTKOL_REM_DZPERT};
   virtual TFIBBCDField * get_DocTKOL_REM_DZPERT(void)=0;
   virtual void set_DocTKOL_REM_DZPERT(TFIBBCDField * DocTKOL_REM_DZPERT)=0;

   __property TFIBWideStringField * DocTNAME_REM_Z = {read = get_DocTNAME_REM_Z , write = set_DocTNAME_REM_Z};
   virtual TFIBWideStringField * get_DocTNAME_REM_Z(void)=0;
   virtual void set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z)=0;

   __property TFIBIntegerField * DocTNUM_REM_Z = {read = get_DocTNUM_REM_Z , write = set_DocTNUM_REM_Z};
   virtual TFIBIntegerField * get_DocTNUM_REM_Z(void)=0;
   virtual void set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z)=0;

   __property TFIBDateTimeField * DocTPOS_REM_Z = {read = get_DocTPOS_REM_Z , write = set_DocTPOS_REM_Z};
   virtual TFIBDateTimeField * get_DocTPOS_REM_Z(void)=0;
   virtual void set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z)=0;

   __property TFIBWideStringField * DocTSERNUM_REM_Z = {read = get_DocTSERNUM_REM_Z , write = set_DocTSERNUM_REM_Z};
   virtual TFIBWideStringField * get_DocTSERNUM_REM_Z(void)=0;
   virtual void set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z)=0;

   __property TFIBWideStringField * DocTSERNUM2_REM_Z = {read = get_DocTSERNUM2_REM_Z , write = set_DocTSERNUM2_REM_Z};
   virtual TFIBWideStringField * get_DocTSERNUM2_REM_Z(void)=0;
   virtual void set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z)=0;

   __property TFIBWideStringField * DocTKLIENT_NAME_REM_Z = {read = get_DocTKLIENT_NAME_REM_Z , write = set_DocTKLIENT_NAME_REM_Z};
   virtual TFIBWideStringField * get_DocTKLIENT_NAME_REM_Z(void)=0;
   virtual void set_DocTKLIENT_NAME_REM_Z(TFIBWideStringField * DocTKLIENT_NAME_REM_Z)=0;

   __property TFIBWideStringField * DocTMODEL_REM_Z = {read = get_DocTMODEL_REM_Z , write = set_DocTMODEL_REM_Z};
   virtual TFIBWideStringField * get_DocTMODEL_REM_Z(void)=0;
   virtual void set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z)=0;

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

   __property TFIBIntegerField * DocOPER_DOC_DZPER = {read = get_DocOPER_DOC_DZPER , write = set_DocOPER_DOC_DZPER};
   virtual TFIBIntegerField * get_DocOPER_DOC_DZPER(void)=0;
   virtual void set_DocOPER_DOC_DZPER(TFIBIntegerField * DocOPER_DOC_DZPER)=0;

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
#define IID_IREM_DMDocZPer __uuidof(IREM_DMDocZPer)
#endif
