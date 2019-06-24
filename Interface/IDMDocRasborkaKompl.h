#ifndef UIDMDocRasborkaKomplH
#define UIDMDocRasborkaKomplH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocRasborkaKompl)) IDMDocRasborkaKompl : public IMainInterface
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

   __property TFIBBCDField * DocKF_DRASBKOMPL = {read = get_DocKF_DRASBKOMPL , write = set_DocKF_DRASBKOMPL};
   virtual TFIBBCDField * get_DocKF_DRASBKOMPL(void)=0;
   virtual void set_DocKF_DRASBKOMPL(TFIBBCDField * DocKF_DRASBKOMPL)=0;

   __property TFIBBCDField * DocKOL_DRASBKOMPL = {read = get_DocKOL_DRASBKOMPL , write = set_DocKOL_DRASBKOMPL};
   virtual TFIBBCDField * get_DocKOL_DRASBKOMPL(void)=0;
   virtual void set_DocKOL_DRASBKOMPL(TFIBBCDField * DocKOL_DRASBKOMPL)=0;

   __property TFIBBCDField * DocRPRICE_DRASBKOMPL = {read = get_DocRPRICE_DRASBKOMPL , write = set_DocRPRICE_DRASBKOMPL};
   virtual TFIBBCDField * get_DocRPRICE_DRASBKOMPL(void)=0;
   virtual void set_DocRPRICE_DRASBKOMPL(TFIBBCDField * DocRPRICE_DRASBKOMPL)=0;

   __property TFIBBCDField * DocTKF_DRASBKOMPLT = {read = get_DocTKF_DRASBKOMPLT , write = set_DocTKF_DRASBKOMPLT};
   virtual TFIBBCDField * get_DocTKF_DRASBKOMPLT(void)=0;
   virtual void set_DocTKF_DRASBKOMPLT(TFIBBCDField * DocTKF_DRASBKOMPLT)=0;

   __property TFIBBCDField * DocTKOL_DRASBKOMPLT = {read = get_DocTKOL_DRASBKOMPLT , write = set_DocTKOL_DRASBKOMPLT};
   virtual TFIBBCDField * get_DocTKOL_DRASBKOMPLT(void)=0;
   virtual void set_DocTKOL_DRASBKOMPLT(TFIBBCDField * DocTKOL_DRASBKOMPLT)=0;

   __property TFIBBCDField * DocTRPRICE_DRASBKOMPLT = {read = get_DocTRPRICE_DRASBKOMPLT , write = set_DocTRPRICE_DRASBKOMPLT};
   virtual TFIBBCDField * get_DocTRPRICE_DRASBKOMPLT(void)=0;
   virtual void set_DocTRPRICE_DRASBKOMPLT(TFIBBCDField * DocTRPRICE_DRASBKOMPLT)=0;

   __property TFIBBCDField * DocTRSUM_DRASBKOMPLT = {read = get_DocTRSUM_DRASBKOMPLT , write = set_DocTRSUM_DRASBKOMPLT};
   virtual TFIBBCDField * get_DocTRSUM_DRASBKOMPLT(void)=0;
   virtual void set_DocTRSUM_DRASBKOMPLT(TFIBBCDField * DocTRSUM_DRASBKOMPLT)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBBCDField * DocTKFSEB_DRASBKOMPLT = {read = get_DocTKFSEB_DRASBKOMPLT , write = set_DocTKFSEB_DRASBKOMPLT};
   virtual TFIBBCDField * get_DocTKFSEB_DRASBKOMPLT(void)=0;
   virtual void set_DocTKFSEB_DRASBKOMPLT(TFIBBCDField * DocTKFSEB_DRASBKOMPLT)=0;

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

   __property TFIBWideStringField * DocAllNAMESKLAD = {read = get_DocAllNAMESKLAD , write = set_DocAllNAMESKLAD};
   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void)=0;
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)=0;

   __property TFIBLargeIntField * DocID_DRASBKOMPL = {read = get_DocID_DRASBKOMPL , write = set_DocID_DRASBKOMPL};
   virtual TFIBLargeIntField * get_DocID_DRASBKOMPL(void)=0;
   virtual void set_DocID_DRASBKOMPL(TFIBLargeIntField * DocID_DRASBKOMPL)=0;

   __property TFIBLargeIntField * DocIDBASE_DRASBKOMPL = {read = get_DocIDBASE_DRASBKOMPL , write = set_DocIDBASE_DRASBKOMPL};
   virtual TFIBLargeIntField * get_DocIDBASE_DRASBKOMPL(void)=0;
   virtual void set_DocIDBASE_DRASBKOMPL(TFIBLargeIntField * DocIDBASE_DRASBKOMPL)=0;

   __property TFIBLargeIntField * DocIDDOC_DRASBKOMPL = {read = get_DocIDDOC_DRASBKOMPL , write = set_DocIDDOC_DRASBKOMPL};
   virtual TFIBLargeIntField * get_DocIDDOC_DRASBKOMPL(void)=0;
   virtual void set_DocIDDOC_DRASBKOMPL(TFIBLargeIntField * DocIDDOC_DRASBKOMPL)=0;

   __property TFIBLargeIntField * DocIDNOM_DRASBKOMPL = {read = get_DocIDNOM_DRASBKOMPL , write = set_DocIDNOM_DRASBKOMPL};
   virtual TFIBLargeIntField * get_DocIDNOM_DRASBKOMPL(void)=0;
   virtual void set_DocIDNOM_DRASBKOMPL(TFIBLargeIntField * DocIDNOM_DRASBKOMPL)=0;

   __property TFIBLargeIntField * DocIDED_DRASBKOMPL = {read = get_DocIDED_DRASBKOMPL , write = set_DocIDED_DRASBKOMPL};
   virtual TFIBLargeIntField * get_DocIDED_DRASBKOMPL(void)=0;
   virtual void set_DocIDED_DRASBKOMPL(TFIBLargeIntField * DocIDED_DRASBKOMPL)=0;

   __property TFIBWideStringField * DocDESCR_DRASBKOMPL = {read = get_DocDESCR_DRASBKOMPL , write = set_DocDESCR_DRASBKOMPL};
   virtual TFIBWideStringField * get_DocDESCR_DRASBKOMPL(void)=0;
   virtual void set_DocDESCR_DRASBKOMPL(TFIBWideStringField * DocDESCR_DRASBKOMPL)=0;

   __property TFIBLargeIntField * DocIDRTPRICE_DRASBKOMPL = {read = get_DocIDRTPRICE_DRASBKOMPL , write = set_DocIDRTPRICE_DRASBKOMPL};
   virtual TFIBLargeIntField * get_DocIDRTPRICE_DRASBKOMPL(void)=0;
   virtual void set_DocIDRTPRICE_DRASBKOMPL(TFIBLargeIntField * DocIDRTPRICE_DRASBKOMPL)=0;

   __property TFIBWideStringField * DocNAMENOM = {read = get_DocNAMENOM , write = set_DocNAMENOM};
   virtual TFIBWideStringField * get_DocNAMENOM(void)=0;
   virtual void set_DocNAMENOM(TFIBWideStringField * DocNAMENOM)=0;

   __property TFIBWideStringField * DocNAMEED = {read = get_DocNAMEED , write = set_DocNAMEED};
   virtual TFIBWideStringField * get_DocNAMEED(void)=0;
   virtual void set_DocNAMEED(TFIBWideStringField * DocNAMEED)=0;

   __property TFIBLargeIntField * DocTID_DRASBKOMPLT = {read = get_DocTID_DRASBKOMPLT , write = set_DocTID_DRASBKOMPLT};
   virtual TFIBLargeIntField * get_DocTID_DRASBKOMPLT(void)=0;
   virtual void set_DocTID_DRASBKOMPLT(TFIBLargeIntField * DocTID_DRASBKOMPLT)=0;

   __property TFIBLargeIntField * DocTIDBASE_DRASBKOMPLT = {read = get_DocTIDBASE_DRASBKOMPLT , write = set_DocTIDBASE_DRASBKOMPLT};
   virtual TFIBLargeIntField * get_DocTIDBASE_DRASBKOMPLT(void)=0;
   virtual void set_DocTIDBASE_DRASBKOMPLT(TFIBLargeIntField * DocTIDBASE_DRASBKOMPLT)=0;

   __property TFIBLargeIntField * DocTIDDOC_DRASBKOMPLT = {read = get_DocTIDDOC_DRASBKOMPLT , write = set_DocTIDDOC_DRASBKOMPLT};
   virtual TFIBLargeIntField * get_DocTIDDOC_DRASBKOMPLT(void)=0;
   virtual void set_DocTIDDOC_DRASBKOMPLT(TFIBLargeIntField * DocTIDDOC_DRASBKOMPLT)=0;

   __property TFIBLargeIntField * DocTIDNOM_DRASBKOMPLT = {read = get_DocTIDNOM_DRASBKOMPLT , write = set_DocTIDNOM_DRASBKOMPLT};
   virtual TFIBLargeIntField * get_DocTIDNOM_DRASBKOMPLT(void)=0;
   virtual void set_DocTIDNOM_DRASBKOMPLT(TFIBLargeIntField * DocTIDNOM_DRASBKOMPLT)=0;

   __property TFIBLargeIntField * DocTIDED_DRASBKOMPLT = {read = get_DocTIDED_DRASBKOMPLT , write = set_DocTIDED_DRASBKOMPLT};
   virtual TFIBLargeIntField * get_DocTIDED_DRASBKOMPLT(void)=0;
   virtual void set_DocTIDED_DRASBKOMPLT(TFIBLargeIntField * DocTIDED_DRASBKOMPLT)=0;

   __property TFIBLargeIntField * DocTIDPART_DRASBKOMPLT = {read = get_DocTIDPART_DRASBKOMPLT , write = set_DocTIDPART_DRASBKOMPLT};
   virtual TFIBLargeIntField * get_DocTIDPART_DRASBKOMPLT(void)=0;
   virtual void set_DocTIDPART_DRASBKOMPLT(TFIBLargeIntField * DocTIDPART_DRASBKOMPLT)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBWideStringField * DocAllGID_DOC = {read = get_DocAllGID_DOC , write = set_DocAllGID_DOC};
   virtual TFIBWideStringField * get_DocAllGID_DOC(void)=0;
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)=0;

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

   __property TFIBWideStringField * DocTARTNOM = {read = get_DocTARTNOM , write = set_DocTARTNOM};
   virtual TFIBWideStringField * get_DocTARTNOM(void)=0;
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBWideStringField * DocTSHED = {read = get_DocTSHED , write = set_DocTSHED};
   virtual TFIBWideStringField * get_DocTSHED(void)=0;
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool SkladRozn = {read = get_SkladRozn , write = set_SkladRozn};
   virtual bool get_SkladRozn(void)=0;
   virtual void set_SkladRozn(bool SkladRozn)=0;

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
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocRasborkaKompl __uuidof(IDMDocRasborkaKompl)
#endif
