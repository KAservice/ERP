#ifndef UIDMDocSchetFactH
#define UIDMDocSchetFactH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocSchetFact)) IDMDocSchetFact : public IMainInterface
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

   __property TFIBBCDField * DocTKOL_DSCHFACTT = {read = get_DocTKOL_DSCHFACTT , write = set_DocTKOL_DSCHFACTT};
   virtual TFIBBCDField * get_DocTKOL_DSCHFACTT(void)=0;
   virtual void set_DocTKOL_DSCHFACTT(TFIBBCDField * DocTKOL_DSCHFACTT)=0;

   __property TFIBBCDField * DocTKF_DSCHFACTT = {read = get_DocTKF_DSCHFACTT , write = set_DocTKF_DSCHFACTT};
   virtual TFIBBCDField * get_DocTKF_DSCHFACTT(void)=0;
   virtual void set_DocTKF_DSCHFACTT(TFIBBCDField * DocTKF_DSCHFACTT)=0;

   __property TFIBBCDField * DocTPRICE_DSCHFACTT = {read = get_DocTPRICE_DSCHFACTT , write = set_DocTPRICE_DSCHFACTT};
   virtual TFIBBCDField * get_DocTPRICE_DSCHFACTT(void)=0;
   virtual void set_DocTPRICE_DSCHFACTT(TFIBBCDField * DocTPRICE_DSCHFACTT)=0;

   __property TFIBBCDField * DocTSUM_DSCHFACTT = {read = get_DocTSUM_DSCHFACTT , write = set_DocTSUM_DSCHFACTT};
   virtual TFIBBCDField * get_DocTSUM_DSCHFACTT(void)=0;
   virtual void set_DocTSUM_DSCHFACTT(TFIBBCDField * DocTSUM_DSCHFACTT)=0;

   __property TFIBIntegerField * DocTSTNDS_DSCHFACTT = {read = get_DocTSTNDS_DSCHFACTT , write = set_DocTSTNDS_DSCHFACTT};
   virtual TFIBIntegerField * get_DocTSTNDS_DSCHFACTT(void)=0;
   virtual void set_DocTSTNDS_DSCHFACTT(TFIBIntegerField * DocTSTNDS_DSCHFACTT)=0;

   __property TFIBBCDField * DocTSUMNDS_DSCHFACTT = {read = get_DocTSUMNDS_DSCHFACTT , write = set_DocTSUMNDS_DSCHFACTT};
   virtual TFIBBCDField * get_DocTSUMNDS_DSCHFACTT(void)=0;
   virtual void set_DocTSUMNDS_DSCHFACTT(TFIBBCDField * DocTSUMNDS_DSCHFACTT)=0;

   __property TFIBIntegerField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBIntegerField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBDataSet * IBQ = {read = get_IBQ , write = set_IBQ};
   virtual TpFIBDataSet * get_IBQ(void)=0;
   virtual void set_IBQ(TpFIBDataSet * IBQ)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TFIBBCDField * DocAllIDDOC = {read = get_DocAllIDDOC , write = set_DocAllIDDOC};
   virtual TFIBBCDField * get_DocAllIDDOC(void)=0;
   virtual void set_DocAllIDDOC(TFIBBCDField * DocAllIDDOC)=0;

   __property TFIBBCDField * DocAllIDFIRMDOC = {read = get_DocAllIDFIRMDOC , write = set_DocAllIDFIRMDOC};
   virtual TFIBBCDField * get_DocAllIDFIRMDOC(void)=0;
   virtual void set_DocAllIDFIRMDOC(TFIBBCDField * DocAllIDFIRMDOC)=0;

   __property TFIBBCDField * DocAllIDSKLDOC = {read = get_DocAllIDSKLDOC , write = set_DocAllIDSKLDOC};
   virtual TFIBBCDField * get_DocAllIDSKLDOC(void)=0;
   virtual void set_DocAllIDSKLDOC(TFIBBCDField * DocAllIDSKLDOC)=0;

   __property TFIBBCDField * DocAllIDKLDOC = {read = get_DocAllIDKLDOC , write = set_DocAllIDKLDOC};
   virtual TFIBBCDField * get_DocAllIDKLDOC(void)=0;
   virtual void set_DocAllIDKLDOC(TFIBBCDField * DocAllIDKLDOC)=0;

   __property TFIBBCDField * DocAllIDDOGDOC = {read = get_DocAllIDDOGDOC , write = set_DocAllIDDOGDOC};
   virtual TFIBBCDField * get_DocAllIDDOGDOC(void)=0;
   virtual void set_DocAllIDDOGDOC(TFIBBCDField * DocAllIDDOGDOC)=0;

   __property TFIBBCDField * DocAllIDUSERDOC = {read = get_DocAllIDUSERDOC , write = set_DocAllIDUSERDOC};
   virtual TFIBBCDField * get_DocAllIDUSERDOC(void)=0;
   virtual void set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC)=0;

   __property TFIBBCDField * DocAllIDDOCOSNDOC = {read = get_DocAllIDDOCOSNDOC , write = set_DocAllIDDOCOSNDOC};
   virtual TFIBBCDField * get_DocAllIDDOCOSNDOC(void)=0;
   virtual void set_DocAllIDDOCOSNDOC(TFIBBCDField * DocAllIDDOCOSNDOC)=0;

   __property TFIBBCDField * DocID_DSCHFACT = {read = get_DocID_DSCHFACT , write = set_DocID_DSCHFACT};
   virtual TFIBBCDField * get_DocID_DSCHFACT(void)=0;
   virtual void set_DocID_DSCHFACT(TFIBBCDField * DocID_DSCHFACT)=0;

   __property TFIBBCDField * DocIDDOC_DSCHFACT = {read = get_DocIDDOC_DSCHFACT , write = set_DocIDDOC_DSCHFACT};
   virtual TFIBBCDField * get_DocIDDOC_DSCHFACT(void)=0;
   virtual void set_DocIDDOC_DSCHFACT(TFIBBCDField * DocIDDOC_DSCHFACT)=0;

   __property TFIBBCDField * DocIDTPRICE_DSCHFACT = {read = get_DocIDTPRICE_DSCHFACT , write = set_DocIDTPRICE_DSCHFACT};
   virtual TFIBBCDField * get_DocIDTPRICE_DSCHFACT(void)=0;
   virtual void set_DocIDTPRICE_DSCHFACT(TFIBBCDField * DocIDTPRICE_DSCHFACT)=0;

   __property TFIBBCDField * DocTID_DSCHFACTT = {read = get_DocTID_DSCHFACTT , write = set_DocTID_DSCHFACTT};
   virtual TFIBBCDField * get_DocTID_DSCHFACTT(void)=0;
   virtual void set_DocTID_DSCHFACTT(TFIBBCDField * DocTID_DSCHFACTT)=0;

   __property TFIBBCDField * DocTIDDOC_DSCHFACTT = {read = get_DocTIDDOC_DSCHFACTT , write = set_DocTIDDOC_DSCHFACTT};
   virtual TFIBBCDField * get_DocTIDDOC_DSCHFACTT(void)=0;
   virtual void set_DocTIDDOC_DSCHFACTT(TFIBBCDField * DocTIDDOC_DSCHFACTT)=0;

   __property TFIBBCDField * DocTIDNOM_DSCHFACTT = {read = get_DocTIDNOM_DSCHFACTT , write = set_DocTIDNOM_DSCHFACTT};
   virtual TFIBBCDField * get_DocTIDNOM_DSCHFACTT(void)=0;
   virtual void set_DocTIDNOM_DSCHFACTT(TFIBBCDField * DocTIDNOM_DSCHFACTT)=0;

   __property TFIBBCDField * DocTIDED_DSCHFACTT = {read = get_DocTIDED_DSCHFACTT , write = set_DocTIDED_DSCHFACTT};
   virtual TFIBBCDField * get_DocTIDED_DSCHFACTT(void)=0;
   virtual void set_DocTIDED_DSCHFACTT(TFIBBCDField * DocTIDED_DSCHFACTT)=0;

   __property TFIBBCDField * DocAllIDEXTDOC = {read = get_DocAllIDEXTDOC , write = set_DocAllIDEXTDOC};
   virtual TFIBBCDField * get_DocAllIDEXTDOC(void)=0;
   virtual void set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC)=0;

   __property TFIBBCDField * DocIDGRPOL_DSCHFACT = {read = get_DocIDGRPOL_DSCHFACT , write = set_DocIDGRPOL_DSCHFACT};
   virtual TFIBBCDField * get_DocIDGRPOL_DSCHFACT(void)=0;
   virtual void set_DocIDGRPOL_DSCHFACT(TFIBBCDField * DocIDGRPOL_DSCHFACT)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * DocIDBASE_DSCHFACT = {read = get_DocIDBASE_DSCHFACT , write = set_DocIDBASE_DSCHFACT};
   virtual TFIBBCDField * get_DocIDBASE_DSCHFACT(void)=0;
   virtual void set_DocIDBASE_DSCHFACT(TFIBBCDField * DocIDBASE_DSCHFACT)=0;

   __property TFIBBCDField * DocTIDBASE_DSCHFACTT = {read = get_DocTIDBASE_DSCHFACTT , write = set_DocTIDBASE_DSCHFACTT};
   virtual TFIBBCDField * get_DocTIDBASE_DSCHFACTT(void)=0;
   virtual void set_DocTIDBASE_DSCHFACTT(TFIBBCDField * DocTIDBASE_DSCHFACTT)=0;

   __property TFIBBCDField * DocAllIDBASE_GALLDOC = {read = get_DocAllIDBASE_GALLDOC , write = set_DocAllIDBASE_GALLDOC};
   virtual TFIBBCDField * get_DocAllIDBASE_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC)=0;

   __property TFIBWideStringField * DocAllTDOC = {read = get_DocAllTDOC , write = set_DocAllTDOC};
   virtual TFIBWideStringField * get_DocAllTDOC(void)=0;
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)=0;

   __property TFIBWideStringField * DocAllGID_DOC = {read = get_DocAllGID_DOC , write = set_DocAllGID_DOC};
   virtual TFIBWideStringField * get_DocAllGID_DOC(void)=0;
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)=0;

   __property TFIBWideStringField * DocAllPREFIKSDOC = {read = get_DocAllPREFIKSDOC , write = set_DocAllPREFIKSDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKSDOC(void)=0;
   virtual void set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)=0;

   __property TFIBIntegerField * DocAllTYPEEXTDOC = {read = get_DocAllTYPEEXTDOC , write = set_DocAllTYPEEXTDOC};
   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void)=0;
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)=0;

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

   __property TFIBWideStringField * DocAllFNAME_USER = {read = get_DocAllFNAME_USER , write = set_DocAllFNAME_USER};
   virtual TFIBWideStringField * get_DocAllFNAME_USER(void)=0;
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)=0;

   __property TFIBWideStringField * DocGID_DSCHFACT = {read = get_DocGID_DSCHFACT , write = set_DocGID_DSCHFACT};
   virtual TFIBWideStringField * get_DocGID_DSCHFACT(void)=0;
   virtual void set_DocGID_DSCHFACT(TFIBWideStringField * DocGID_DSCHFACT)=0;

   __property TFIBWideStringField * DocPRIM_DSCHFACT = {read = get_DocPRIM_DSCHFACT , write = set_DocPRIM_DSCHFACT};
   virtual TFIBWideStringField * get_DocPRIM_DSCHFACT(void)=0;
   virtual void set_DocPRIM_DSCHFACT(TFIBWideStringField * DocPRIM_DSCHFACT)=0;

   __property TFIBWideStringField * DocNAMEKLIENT = {read = get_DocNAMEKLIENT , write = set_DocNAMEKLIENT};
   virtual TFIBWideStringField * get_DocNAMEKLIENT(void)=0;
   virtual void set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT)=0;

   __property TFIBWideStringField * DocTGID_DSCHFACTT = {read = get_DocTGID_DSCHFACTT , write = set_DocTGID_DSCHFACTT};
   virtual TFIBWideStringField * get_DocTGID_DSCHFACTT(void)=0;
   virtual void set_DocTGID_DSCHFACTT(TFIBWideStringField * DocTGID_DSCHFACTT)=0;

   __property TFIBIntegerField * DocTNDS_DSCHFACTT = {read = get_DocTNDS_DSCHFACTT , write = set_DocTNDS_DSCHFACTT};
   virtual TFIBIntegerField * get_DocTNDS_DSCHFACTT(void)=0;
   virtual void set_DocTNDS_DSCHFACTT(TFIBIntegerField * DocTNDS_DSCHFACTT)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBBCDField * DocAllIDPROJECT_GALLDOC = {read = get_DocAllIDPROJECT_GALLDOC , write = set_DocAllIDPROJECT_GALLDOC};
   virtual TFIBBCDField * get_DocAllIDPROJECT_GALLDOC(void)=0;
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBBCDField * DocAllIDPROJECT_GALLDOC)=0;

   __property TFIBBCDField * DocAllIDBUSINOP_GALLDOC = {read = get_DocAllIDBUSINOP_GALLDOC , write = set_DocAllIDBUSINOP_GALLDOC};
   virtual TFIBBCDField * get_DocAllIDBUSINOP_GALLDOC(void)=0;
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBBCDField * DocAllIDBUSINOP_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBWideStringField * DocNUMPLAT_RASCH_DOC_DSCHFACT = {read = get_DocNUMPLAT_RASCH_DOC_DSCHFACT , write = set_DocNUMPLAT_RASCH_DOC_DSCHFACT};
   virtual TFIBWideStringField * get_DocNUMPLAT_RASCH_DOC_DSCHFACT(void)=0;
   virtual void set_DocNUMPLAT_RASCH_DOC_DSCHFACT(TFIBWideStringField * DocNUMPLAT_RASCH_DOC_DSCHFACT)=0;

   __property TFIBDateTimeField * DocDATEPLAT_RASCH_DOC_DSCHFACT = {read = get_DocDATEPLAT_RASCH_DOC_DSCHFACT , write = set_DocDATEPLAT_RASCH_DOC_DSCHFACT};
   virtual TFIBDateTimeField * get_DocDATEPLAT_RASCH_DOC_DSCHFACT(void)=0;
   virtual void set_DocDATEPLAT_RASCH_DOC_DSCHFACT(TFIBDateTimeField * DocDATEPLAT_RASCH_DOC_DSCHFACT)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC = {read = get_DocAllPREFIKS_NUM_GALLDOC , write = set_DocAllPREFIKS_NUM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)=0;

   __property TFIBWideStringField * DocTARTNOM = {read = get_DocTARTNOM , write = set_DocTARTNOM};
   virtual TFIBWideStringField * get_DocTARTNOM(void)=0;
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBWideStringField * DocTSHED = {read = get_DocTSHED , write = set_DocTSHED};
   virtual TFIBWideStringField * get_DocTSHED(void)=0;
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED)=0;

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
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocSchetFact __uuidof(IDMDocSchetFact)
#endif
