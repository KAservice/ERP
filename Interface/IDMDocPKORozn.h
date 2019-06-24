#ifndef UIDMDocPKORoznH
#define UIDMDocPKORoznH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocPKORozn)) IDMDocPKORozn : public IMainInterface
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

   __property TFIBDateTimeField * DocAllPOSDOC = {read = get_DocAllPOSDOC , write = set_DocAllPOSDOC};
   virtual TFIBDateTimeField * get_DocAllPOSDOC(void)=0;
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)=0;

   __property TFIBSmallIntField * DocAllPRDOC = {read = get_DocAllPRDOC , write = set_DocAllPRDOC};
   virtual TFIBSmallIntField * get_DocAllPRDOC(void)=0;
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)=0;

   __property TFIBIntegerField * DocAllNUMDOC = {read = get_DocAllNUMDOC , write = set_DocAllNUMDOC};
   virtual TFIBIntegerField * get_DocAllNUMDOC(void)=0;
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)=0;

   __property TFIBBCDField * DocAllSUMDOC = {read = get_DocAllSUMDOC , write = set_DocAllSUMDOC};
   virtual TFIBBCDField * get_DocAllSUMDOC(void)=0;
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)=0;

   __property TFIBIntegerField * DocOPERATION_DPKOROZN = {read = get_DocOPERATION_DPKOROZN , write = set_DocOPERATION_DPKOROZN};
   virtual TFIBIntegerField * get_DocOPERATION_DPKOROZN(void)=0;
   virtual void set_DocOPERATION_DPKOROZN(TFIBIntegerField * DocOPERATION_DPKOROZN)=0;

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TFIBIntegerField * DocNDS_DPKOROZN = {read = get_DocNDS_DPKOROZN , write = set_DocNDS_DPKOROZN};
   virtual TFIBIntegerField * get_DocNDS_DPKOROZN(void)=0;
   virtual void set_DocNDS_DPKOROZN(TFIBIntegerField * DocNDS_DPKOROZN)=0;

   __property TFIBBCDField * DocSUMNDS_DPKOROZN = {read = get_DocSUMNDS_DPKOROZN , write = set_DocSUMNDS_DPKOROZN};
   virtual TFIBBCDField * get_DocSUMNDS_DPKOROZN(void)=0;
   virtual void set_DocSUMNDS_DPKOROZN(TFIBBCDField * DocSUMNDS_DPKOROZN)=0;

   __property TFIBLargeIntField * DocAllIDDOC = {read = get_DocAllIDDOC , write = set_DocAllIDDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOC(void)=0;
   virtual void set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)=0;

   __property TFIBWideStringField * DocAllTDOC = {read = get_DocAllTDOC , write = set_DocAllTDOC};
   virtual TFIBWideStringField * get_DocAllTDOC(void)=0;
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)=0;

   __property TFIBLargeIntField * DocAllIDFIRMDOC = {read = get_DocAllIDFIRMDOC , write = set_DocAllIDFIRMDOC};
   virtual TFIBLargeIntField * get_DocAllIDFIRMDOC(void)=0;
   virtual void set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)=0;

   __property TFIBLargeIntField * DocAllIDSKLDOC = {read = get_DocAllIDSKLDOC , write = set_DocAllIDSKLDOC};
   virtual TFIBLargeIntField * get_DocAllIDSKLDOC(void)=0;
   virtual void set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)=0;

   __property TFIBLargeIntField * DocAllIDKLDOC = {read = get_DocAllIDKLDOC , write = set_DocAllIDKLDOC};
   virtual TFIBLargeIntField * get_DocAllIDKLDOC(void)=0;
   virtual void set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)=0;

   __property TFIBLargeIntField * DocAllIDDOGDOC = {read = get_DocAllIDDOGDOC , write = set_DocAllIDDOGDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOGDOC(void)=0;
   virtual void set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)=0;

   __property TFIBLargeIntField * DocAllIDUSERDOC = {read = get_DocAllIDUSERDOC , write = set_DocAllIDUSERDOC};
   virtual TFIBLargeIntField * get_DocAllIDUSERDOC(void)=0;
   virtual void set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)=0;

   __property TFIBWideStringField * DocAllGID_DOC = {read = get_DocAllGID_DOC , write = set_DocAllGID_DOC};
   virtual TFIBWideStringField * get_DocAllGID_DOC(void)=0;
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)=0;

   __property TFIBWideStringField * DocAllPREFIKSDOC = {read = get_DocAllPREFIKSDOC , write = set_DocAllPREFIKSDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKSDOC(void)=0;
   virtual void set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)=0;

   __property TFIBLargeIntField * DocAllIDDOCOSNDOC = {read = get_DocAllIDDOCOSNDOC , write = set_DocAllIDDOCOSNDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOCOSNDOC(void)=0;
   virtual void set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)=0;

   __property TFIBLargeIntField * DocAllIDEXTDOC = {read = get_DocAllIDEXTDOC , write = set_DocAllIDEXTDOC};
   virtual TFIBLargeIntField * get_DocAllIDEXTDOC(void)=0;
   virtual void set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)=0;

   __property TFIBIntegerField * DocAllTYPEEXTDOC = {read = get_DocAllTYPEEXTDOC , write = set_DocAllTYPEEXTDOC};
   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void)=0;
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)=0;

   __property TFIBLargeIntField * DocAllIDBASE_GALLDOC = {read = get_DocAllIDBASE_GALLDOC , write = set_DocAllIDBASE_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBASE_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDPROJECT_GALLDOC = {read = get_DocAllIDPROJECT_GALLDOC , write = set_DocAllIDPROJECT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDPROJECT_GALLDOC(void)=0;
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)=0;

   __property TFIBWideStringField * DocAllFNAME_USER = {read = get_DocAllFNAME_USER , write = set_DocAllFNAME_USER};
   virtual TFIBWideStringField * get_DocAllFNAME_USER(void)=0;
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocAllNAMEFIRM = {read = get_DocAllNAMEFIRM , write = set_DocAllNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void)=0;
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllNAMEKLIENT = {read = get_DocAllNAMEKLIENT , write = set_DocAllNAMEKLIENT};
   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void)=0;
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)=0;

   __property TFIBWideStringField * DocAllNAME_SDOG = {read = get_DocAllNAME_SDOG , write = set_DocAllNAME_SDOG};
   virtual TFIBWideStringField * get_DocAllNAME_SDOG(void)=0;
   virtual void set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG)=0;

   __property TFIBLargeIntField * DocID_DPKOROZN = {read = get_DocID_DPKOROZN , write = set_DocID_DPKOROZN};
   virtual TFIBLargeIntField * get_DocID_DPKOROZN(void)=0;
   virtual void set_DocID_DPKOROZN(TFIBLargeIntField * DocID_DPKOROZN)=0;

   __property TFIBLargeIntField * DocIDDOC_DPKOROZN = {read = get_DocIDDOC_DPKOROZN , write = set_DocIDDOC_DPKOROZN};
   virtual TFIBLargeIntField * get_DocIDDOC_DPKOROZN(void)=0;
   virtual void set_DocIDDOC_DPKOROZN(TFIBLargeIntField * DocIDDOC_DPKOROZN)=0;

   __property TFIBWideStringField * DocGID_DPKOROZN = {read = get_DocGID_DPKOROZN , write = set_DocGID_DPKOROZN};
   virtual TFIBWideStringField * get_DocGID_DPKOROZN(void)=0;
   virtual void set_DocGID_DPKOROZN(TFIBWideStringField * DocGID_DPKOROZN)=0;

   __property TFIBLargeIntField * DocIDKKM_DPKOROZN = {read = get_DocIDKKM_DPKOROZN , write = set_DocIDKKM_DPKOROZN};
   virtual TFIBLargeIntField * get_DocIDKKM_DPKOROZN(void)=0;
   virtual void set_DocIDKKM_DPKOROZN(TFIBLargeIntField * DocIDKKM_DPKOROZN)=0;

   __property TFIBWideStringField * DocPRIM_DPKOROZN = {read = get_DocPRIM_DPKOROZN , write = set_DocPRIM_DPKOROZN};
   virtual TFIBWideStringField * get_DocPRIM_DPKOROZN(void)=0;
   virtual void set_DocPRIM_DPKOROZN(TFIBWideStringField * DocPRIM_DPKOROZN)=0;

   __property TFIBWideStringField * DocPROT_DPKOROZN = {read = get_DocPROT_DPKOROZN , write = set_DocPROT_DPKOROZN};
   virtual TFIBWideStringField * get_DocPROT_DPKOROZN(void)=0;
   virtual void set_DocPROT_DPKOROZN(TFIBWideStringField * DocPROT_DPKOROZN)=0;

   __property TFIBWideStringField * DocOSN_DPKOROZN = {read = get_DocOSN_DPKOROZN , write = set_DocOSN_DPKOROZN};
   virtual TFIBWideStringField * get_DocOSN_DPKOROZN(void)=0;
   virtual void set_DocOSN_DPKOROZN(TFIBWideStringField * DocOSN_DPKOROZN)=0;

   __property TFIBIntegerField * DocNUMCHECK_DPKOROZN = {read = get_DocNUMCHECK_DPKOROZN , write = set_DocNUMCHECK_DPKOROZN};
   virtual TFIBIntegerField * get_DocNUMCHECK_DPKOROZN(void)=0;
   virtual void set_DocNUMCHECK_DPKOROZN(TFIBIntegerField * DocNUMCHECK_DPKOROZN)=0;

   __property TFIBIntegerField * DocNUMKL_DPKOROZN = {read = get_DocNUMKL_DPKOROZN , write = set_DocNUMKL_DPKOROZN};
   virtual TFIBIntegerField * get_DocNUMKL_DPKOROZN(void)=0;
   virtual void set_DocNUMKL_DPKOROZN(TFIBIntegerField * DocNUMKL_DPKOROZN)=0;

   __property TFIBIntegerField * DocNKL_DPKOROZN = {read = get_DocNKL_DPKOROZN , write = set_DocNKL_DPKOROZN};
   virtual TFIBIntegerField * get_DocNKL_DPKOROZN(void)=0;
   virtual void set_DocNKL_DPKOROZN(TFIBIntegerField * DocNKL_DPKOROZN)=0;

   __property TFIBIntegerField * DocNCHECK_DPKOROZN = {read = get_DocNCHECK_DPKOROZN , write = set_DocNCHECK_DPKOROZN};
   virtual TFIBIntegerField * get_DocNCHECK_DPKOROZN(void)=0;
   virtual void set_DocNCHECK_DPKOROZN(TFIBIntegerField * DocNCHECK_DPKOROZN)=0;

   __property TFIBWideStringField * DocMODEL_DPKOROZN = {read = get_DocMODEL_DPKOROZN , write = set_DocMODEL_DPKOROZN};
   virtual TFIBWideStringField * get_DocMODEL_DPKOROZN(void)=0;
   virtual void set_DocMODEL_DPKOROZN(TFIBWideStringField * DocMODEL_DPKOROZN)=0;

   __property TFIBWideStringField * DocREGNUM_DPKOROZN = {read = get_DocREGNUM_DPKOROZN , write = set_DocREGNUM_DPKOROZN};
   virtual TFIBWideStringField * get_DocREGNUM_DPKOROZN(void)=0;
   virtual void set_DocREGNUM_DPKOROZN(TFIBWideStringField * DocREGNUM_DPKOROZN)=0;

   __property TFIBWideStringField * DocSAVNUM_DPKOROZN = {read = get_DocSAVNUM_DPKOROZN , write = set_DocSAVNUM_DPKOROZN};
   virtual TFIBWideStringField * get_DocSAVNUM_DPKOROZN(void)=0;
   virtual void set_DocSAVNUM_DPKOROZN(TFIBWideStringField * DocSAVNUM_DPKOROZN)=0;

   __property TFIBLargeIntField * DocIDBASE_DPKOROZN = {read = get_DocIDBASE_DPKOROZN , write = set_DocIDBASE_DPKOROZN};
   virtual TFIBLargeIntField * get_DocIDBASE_DPKOROZN(void)=0;
   virtual void set_DocIDBASE_DPKOROZN(TFIBLargeIntField * DocIDBASE_DPKOROZN)=0;

   __property TFIBLargeIntField * DocIDCARD_DPKOROZN = {read = get_DocIDCARD_DPKOROZN , write = set_DocIDCARD_DPKOROZN};
   virtual TFIBLargeIntField * get_DocIDCARD_DPKOROZN(void)=0;
   virtual void set_DocIDCARD_DPKOROZN(TFIBLargeIntField * DocIDCARD_DPKOROZN)=0;

   __property TFIBWideStringField * DocNAMEKKM = {read = get_DocNAMEKKM , write = set_DocNAMEKKM};
   virtual TFIBWideStringField * get_DocNAMEKKM(void)=0;
   virtual void set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM)=0;

   __property TFIBWideStringField * DocNAME_SDISCOUNT_CARD = {read = get_DocNAME_SDISCOUNT_CARD , write = set_DocNAME_SDISCOUNT_CARD};
   virtual TFIBWideStringField * get_DocNAME_SDISCOUNT_CARD(void)=0;
   virtual void set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD)=0;

   __property TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC = {read = get_DocAllIDBUSINOP_GALLDOC , write = set_DocAllIDBUSINOP_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void)=0;
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC = {read = get_DocAllPREFIKS_NUM_GALLDOC , write = set_DocAllPREFIKS_NUM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)=0;

   __property bool NewElement = {read = get_NewElement , write = set_NewElement};
   virtual bool get_NewElement(void)=0;
   virtual void set_NewElement(bool NewElement)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 IdDoc)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocPKORozn __uuidof(IDMDocPKORozn)
#endif
