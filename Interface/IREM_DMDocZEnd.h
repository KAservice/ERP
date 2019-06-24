#ifndef UIREM_DMDocZEndH
#define UIREM_DMDocZEndH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMDocZEnd)) IREM_DMDocZEnd : public IMainInterface
{
public:
   __property TDataSource * DataSourceDoc = {read = get_DataSourceDoc , write = set_DataSourceDoc};
   virtual TDataSource * get_DataSourceDoc(void)=0;
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc)=0;

   __property TDataSource * DataSourceDocAll = {read = get_DataSourceDocAll , write = set_DataSourceDocAll};
   virtual TDataSource * get_DataSourceDocAll(void)=0;
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll)=0;

   __property TpFIBDataSet * DocAll = {read = get_DocAll , write = set_DocAll};
   virtual TpFIBDataSet * get_DocAll(void)=0;
   virtual void set_DocAll(TpFIBDataSet * DocAll)=0;

   __property TpFIBDataSet * Doc = {read = get_Doc , write = set_Doc};
   virtual TpFIBDataSet * get_Doc(void)=0;
   virtual void set_Doc(TpFIBDataSet * Doc)=0;

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

   __property TFIBLargeIntField * DocID_REM_DZEND = {read = get_DocID_REM_DZEND , write = set_DocID_REM_DZEND};
   virtual TFIBLargeIntField * get_DocID_REM_DZEND(void)=0;
   virtual void set_DocID_REM_DZEND(TFIBLargeIntField * DocID_REM_DZEND)=0;

   __property TFIBLargeIntField * DocIDBASE_REM_DZEND = {read = get_DocIDBASE_REM_DZEND , write = set_DocIDBASE_REM_DZEND};
   virtual TFIBLargeIntField * get_DocIDBASE_REM_DZEND(void)=0;
   virtual void set_DocIDBASE_REM_DZEND(TFIBLargeIntField * DocIDBASE_REM_DZEND)=0;

   __property TFIBWideStringField * DocGID_REM_DZEND = {read = get_DocGID_REM_DZEND , write = set_DocGID_REM_DZEND};
   virtual TFIBWideStringField * get_DocGID_REM_DZEND(void)=0;
   virtual void set_DocGID_REM_DZEND(TFIBWideStringField * DocGID_REM_DZEND)=0;

   __property TFIBLargeIntField * DocIDDOC_REM_DZEND = {read = get_DocIDDOC_REM_DZEND , write = set_DocIDDOC_REM_DZEND};
   virtual TFIBLargeIntField * get_DocIDDOC_REM_DZEND(void)=0;
   virtual void set_DocIDDOC_REM_DZEND(TFIBLargeIntField * DocIDDOC_REM_DZEND)=0;

   __property TFIBLargeIntField * DocIDZ_REM_DZEND = {read = get_DocIDZ_REM_DZEND , write = set_DocIDZ_REM_DZEND};
   virtual TFIBLargeIntField * get_DocIDZ_REM_DZEND(void)=0;
   virtual void set_DocIDZ_REM_DZEND(TFIBLargeIntField * DocIDZ_REM_DZEND)=0;

   __property TFIBWideStringField * DocPRIM_REM_DZEND = {read = get_DocPRIM_REM_DZEND , write = set_DocPRIM_REM_DZEND};
   virtual TFIBWideStringField * get_DocPRIM_REM_DZEND(void)=0;
   virtual void set_DocPRIM_REM_DZEND(TFIBWideStringField * DocPRIM_REM_DZEND)=0;

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

   __property TFIBWideStringField * DocPOPOSLE_REM_DZEND = {read = get_DocPOPOSLE_REM_DZEND , write = set_DocPOPOSLE_REM_DZEND};
   virtual TFIBWideStringField * get_DocPOPOSLE_REM_DZEND(void)=0;
   virtual void set_DocPOPOSLE_REM_DZEND(TFIBWideStringField * DocPOPOSLE_REM_DZEND)=0;

   __property TFIBLargeIntField * DocIDDFCPR_REM_DZEND = {read = get_DocIDDFCPR_REM_DZEND , write = set_DocIDDFCPR_REM_DZEND};
   virtual TFIBLargeIntField * get_DocIDDFCPR_REM_DZEND(void)=0;
   virtual void set_DocIDDFCPR_REM_DZEND(TFIBLargeIntField * DocIDDFCPR_REM_DZEND)=0;

   __property TFIBLargeIntField * DocIDPRDEFECT_REM_DZEND = {read = get_DocIDPRDEFECT_REM_DZEND , write = set_DocIDPRDEFECT_REM_DZEND};
   virtual TFIBLargeIntField * get_DocIDPRDEFECT_REM_DZEND(void)=0;
   virtual void set_DocIDPRDEFECT_REM_DZEND(TFIBLargeIntField * DocIDPRDEFECT_REM_DZEND)=0;

   __property TFIBWideStringField * DocCODE_REM_SPRNEISPR = {read = get_DocCODE_REM_SPRNEISPR , write = set_DocCODE_REM_SPRNEISPR};
   virtual TFIBWideStringField * get_DocCODE_REM_SPRNEISPR(void)=0;
   virtual void set_DocCODE_REM_SPRNEISPR(TFIBWideStringField * DocCODE_REM_SPRNEISPR)=0;

   __property TFIBWideStringField * DocNAME_REM_SPRNEISPR = {read = get_DocNAME_REM_SPRNEISPR , write = set_DocNAME_REM_SPRNEISPR};
   virtual TFIBWideStringField * get_DocNAME_REM_SPRNEISPR(void)=0;
   virtual void set_DocNAME_REM_SPRNEISPR(TFIBWideStringField * DocNAME_REM_SPRNEISPR)=0;

   __property TFIBWideStringField * DocCODE_REM_SPRDEFECT = {read = get_DocCODE_REM_SPRDEFECT , write = set_DocCODE_REM_SPRDEFECT};
   virtual TFIBWideStringField * get_DocCODE_REM_SPRDEFECT(void)=0;
   virtual void set_DocCODE_REM_SPRDEFECT(TFIBWideStringField * DocCODE_REM_SPRDEFECT)=0;

   __property TFIBWideStringField * DocNAME_REM_SPRDEFECT = {read = get_DocNAME_REM_SPRDEFECT , write = set_DocNAME_REM_SPRDEFECT};
   virtual TFIBWideStringField * get_DocNAME_REM_SPRDEFECT(void)=0;
   virtual void set_DocNAME_REM_SPRDEFECT(TFIBWideStringField * DocNAME_REM_SPRDEFECT)=0;

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
};
#define IID_IREM_DMDocZEnd __uuidof(IREM_DMDocZEnd)
#endif
