#ifndef UIDMDocRegOstNomH
#define UIDMDocRegOstNomH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocRegOstNom)) IDMDocRegOstNom : public IMainInterface
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

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBSmallIntField * DocTTDV_DRG_OSTNOMT = {read = get_DocTTDV_DRG_OSTNOMT , write = set_DocTTDV_DRG_OSTNOMT};
   virtual TFIBSmallIntField * get_DocTTDV_DRG_OSTNOMT(void)=0;
   virtual void set_DocTTDV_DRG_OSTNOMT(TFIBSmallIntField * DocTTDV_DRG_OSTNOMT)=0;

   __property TFIBBCDField * DocTKOL_DRG_OSTNOMT = {read = get_DocTKOL_DRG_OSTNOMT , write = set_DocTKOL_DRG_OSTNOMT};
   virtual TFIBBCDField * get_DocTKOL_DRG_OSTNOMT(void)=0;
   virtual void set_DocTKOL_DRG_OSTNOMT(TFIBBCDField * DocTKOL_DRG_OSTNOMT)=0;

   __property TFIBBCDField * DocTSUM_DRG_OSTNOMT = {read = get_DocTSUM_DRG_OSTNOMT , write = set_DocTSUM_DRG_OSTNOMT};
   virtual TFIBBCDField * get_DocTSUM_DRG_OSTNOMT(void)=0;
   virtual void set_DocTSUM_DRG_OSTNOMT(TFIBBCDField * DocTSUM_DRG_OSTNOMT)=0;

   __property TFIBSmallIntField * DocTOPER_DRG_OSTNOMT = {read = get_DocTOPER_DRG_OSTNOMT , write = set_DocTOPER_DRG_OSTNOMT};
   virtual TFIBSmallIntField * get_DocTOPER_DRG_OSTNOMT(void)=0;
   virtual void set_DocTOPER_DRG_OSTNOMT(TFIBSmallIntField * DocTOPER_DRG_OSTNOMT)=0;

   __property TFIBLargeIntField * DocAllIDDOC = {read = get_DocAllIDDOC , write = set_DocAllIDDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOC(void)=0;
   virtual void set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)=0;

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

   __property TFIBLargeIntField * DocID_DRG_OSTNOM = {read = get_DocID_DRG_OSTNOM , write = set_DocID_DRG_OSTNOM};
   virtual TFIBLargeIntField * get_DocID_DRG_OSTNOM(void)=0;
   virtual void set_DocID_DRG_OSTNOM(TFIBLargeIntField * DocID_DRG_OSTNOM)=0;

   __property TFIBLargeIntField * DocIDDOC_DRG_OSTNOM = {read = get_DocIDDOC_DRG_OSTNOM , write = set_DocIDDOC_DRG_OSTNOM};
   virtual TFIBLargeIntField * get_DocIDDOC_DRG_OSTNOM(void)=0;
   virtual void set_DocIDDOC_DRG_OSTNOM(TFIBLargeIntField * DocIDDOC_DRG_OSTNOM)=0;

   __property TFIBWideStringField * DocDESCR_DRG_OSTNOM = {read = get_DocDESCR_DRG_OSTNOM , write = set_DocDESCR_DRG_OSTNOM};
   virtual TFIBWideStringField * get_DocDESCR_DRG_OSTNOM(void)=0;
   virtual void set_DocDESCR_DRG_OSTNOM(TFIBWideStringField * DocDESCR_DRG_OSTNOM)=0;

   __property TFIBLargeIntField * DocIDBASE_DRG_OSTNOM = {read = get_DocIDBASE_DRG_OSTNOM , write = set_DocIDBASE_DRG_OSTNOM};
   virtual TFIBLargeIntField * get_DocIDBASE_DRG_OSTNOM(void)=0;
   virtual void set_DocIDBASE_DRG_OSTNOM(TFIBLargeIntField * DocIDBASE_DRG_OSTNOM)=0;

   __property TFIBLargeIntField * DocTID_DRG_OSTNOMT = {read = get_DocTID_DRG_OSTNOMT , write = set_DocTID_DRG_OSTNOMT};
   virtual TFIBLargeIntField * get_DocTID_DRG_OSTNOMT(void)=0;
   virtual void set_DocTID_DRG_OSTNOMT(TFIBLargeIntField * DocTID_DRG_OSTNOMT)=0;

   __property TFIBLargeIntField * DocTIDDOC_DRG_OSTNOMT = {read = get_DocTIDDOC_DRG_OSTNOMT , write = set_DocTIDDOC_DRG_OSTNOMT};
   virtual TFIBLargeIntField * get_DocTIDDOC_DRG_OSTNOMT(void)=0;
   virtual void set_DocTIDDOC_DRG_OSTNOMT(TFIBLargeIntField * DocTIDDOC_DRG_OSTNOMT)=0;

   __property TFIBLargeIntField * DocTIDFIRM_DRG_OSTNOMT = {read = get_DocTIDFIRM_DRG_OSTNOMT , write = set_DocTIDFIRM_DRG_OSTNOMT};
   virtual TFIBLargeIntField * get_DocTIDFIRM_DRG_OSTNOMT(void)=0;
   virtual void set_DocTIDFIRM_DRG_OSTNOMT(TFIBLargeIntField * DocTIDFIRM_DRG_OSTNOMT)=0;

   __property TFIBLargeIntField * DocTIDSKLAD_DRG_OSTNOMT = {read = get_DocTIDSKLAD_DRG_OSTNOMT , write = set_DocTIDSKLAD_DRG_OSTNOMT};
   virtual TFIBLargeIntField * get_DocTIDSKLAD_DRG_OSTNOMT(void)=0;
   virtual void set_DocTIDSKLAD_DRG_OSTNOMT(TFIBLargeIntField * DocTIDSKLAD_DRG_OSTNOMT)=0;

   __property TFIBLargeIntField * DocTIDNOM_DRG_OSTNOMT = {read = get_DocTIDNOM_DRG_OSTNOMT , write = set_DocTIDNOM_DRG_OSTNOMT};
   virtual TFIBLargeIntField * get_DocTIDNOM_DRG_OSTNOMT(void)=0;
   virtual void set_DocTIDNOM_DRG_OSTNOMT(TFIBLargeIntField * DocTIDNOM_DRG_OSTNOMT)=0;

   __property TFIBLargeIntField * DocTIDPART_DRG_OSTNOMT = {read = get_DocTIDPART_DRG_OSTNOMT , write = set_DocTIDPART_DRG_OSTNOMT};
   virtual TFIBLargeIntField * get_DocTIDPART_DRG_OSTNOMT(void)=0;
   virtual void set_DocTIDPART_DRG_OSTNOMT(TFIBLargeIntField * DocTIDPART_DRG_OSTNOMT)=0;

   __property TFIBLargeIntField * DocTIDBASE_DRG_OSTNOMT = {read = get_DocTIDBASE_DRG_OSTNOMT , write = set_DocTIDBASE_DRG_OSTNOMT};
   virtual TFIBLargeIntField * get_DocTIDBASE_DRG_OSTNOMT(void)=0;
   virtual void set_DocTIDBASE_DRG_OSTNOMT(TFIBLargeIntField * DocTIDBASE_DRG_OSTNOMT)=0;

   __property TFIBWideStringField * DocTNAMEFIRM = {read = get_DocTNAMEFIRM , write = set_DocTNAMEFIRM};
   virtual TFIBWideStringField * get_DocTNAMEFIRM(void)=0;
   virtual void set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM)=0;

   __property TFIBWideStringField * DocTNAMESKLAD = {read = get_DocTNAMESKLAD , write = set_DocTNAMESKLAD};
   virtual TFIBWideStringField * get_DocTNAMESKLAD(void)=0;
   virtual void set_DocTNAMESKLAD(TFIBWideStringField * DocTNAMESKLAD)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTDOCPART = {read = get_DocTDOCPART , write = set_DocTDOCPART};
   virtual TFIBWideStringField * get_DocTDOCPART(void)=0;
   virtual void set_DocTDOCPART(TFIBWideStringField * DocTDOCPART)=0;

   __property TFIBWideStringField * DocAllTDOC = {read = get_DocAllTDOC , write = set_DocAllTDOC};
   virtual TFIBWideStringField * get_DocAllTDOC(void)=0;
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)=0;

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
#define IID_IDMDocRegOstNom __uuidof(IDMDocRegOstNom)
#endif
