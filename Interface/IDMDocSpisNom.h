#ifndef UIDMDocSpisNomH
#define UIDMDocSpisNomH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocSpisNom)) IDMDocSpisNom : public IMainInterface
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

   __property TFIBBCDField * DocTKOLSPNT = {read = get_DocTKOLSPNT , write = set_DocTKOLSPNT};
   virtual TFIBBCDField * get_DocTKOLSPNT(void)=0;
   virtual void set_DocTKOLSPNT(TFIBBCDField * DocTKOLSPNT)=0;

   __property TFIBBCDField * DocTKFSPNT = {read = get_DocTKFSPNT , write = set_DocTKFSPNT};
   virtual TFIBBCDField * get_DocTKFSPNT(void)=0;
   virtual void set_DocTKFSPNT(TFIBBCDField * DocTKFSPNT)=0;

   __property TFIBBCDField * DocTPRICESPNT = {read = get_DocTPRICESPNT , write = set_DocTPRICESPNT};
   virtual TFIBBCDField * get_DocTPRICESPNT(void)=0;
   virtual void set_DocTPRICESPNT(TFIBBCDField * DocTPRICESPNT)=0;

   __property TFIBBCDField * DocTSUMSPNT = {read = get_DocTSUMSPNT , write = set_DocTSUMSPNT};
   virtual TFIBBCDField * get_DocTSUMSPNT(void)=0;
   virtual void set_DocTSUMSPNT(TFIBBCDField * DocTSUMSPNT)=0;

   __property TFIBIntegerField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBIntegerField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBDataSet * Grp = {read = get_Grp , write = set_Grp};
   virtual TpFIBDataSet * get_Grp(void)=0;
   virtual void set_Grp(TpFIBDataSet * Grp)=0;

   __property TpFIBDataSet * El = {read = get_El , write = set_El};
   virtual TpFIBDataSet * get_El(void)=0;
   virtual void set_El(TpFIBDataSet * El)=0;

   __property TFIBBCDField * GrpSUMMA = {read = get_GrpSUMMA , write = set_GrpSUMMA};
   virtual TFIBBCDField * get_GrpSUMMA(void)=0;
   virtual void set_GrpSUMMA(TFIBBCDField * GrpSUMMA)=0;

   __property TFIBBCDField * ElSUMMA = {read = get_ElSUMMA , write = set_ElSUMMA};
   virtual TFIBBCDField * get_ElSUMMA(void)=0;
   virtual void set_ElSUMMA(TFIBBCDField * ElSUMMA)=0;

   __property TFIBFloatField * ElSUMKOL = {read = get_ElSUMKOL , write = set_ElSUMKOL};
   virtual TFIBFloatField * get_ElSUMKOL(void)=0;
   virtual void set_ElSUMKOL(TFIBFloatField * ElSUMKOL)=0;

   __property TpFIBDataSet * DocOsn = {read = get_DocOsn , write = set_DocOsn};
   virtual TpFIBDataSet * get_DocOsn(void)=0;
   virtual void set_DocOsn(TpFIBDataSet * DocOsn)=0;

   __property TFIBIntegerField * DocOsnNUMDOC = {read = get_DocOsnNUMDOC , write = set_DocOsnNUMDOC};
   virtual TFIBIntegerField * get_DocOsnNUMDOC(void)=0;
   virtual void set_DocOsnNUMDOC(TFIBIntegerField * DocOsnNUMDOC)=0;

   __property TFIBDateTimeField * DocOsnPOSDOC = {read = get_DocOsnPOSDOC , write = set_DocOsnPOSDOC};
   virtual TFIBDateTimeField * get_DocOsnPOSDOC(void)=0;
   virtual void set_DocOsnPOSDOC(TFIBDateTimeField * DocOsnPOSDOC)=0;

   __property TFIBBCDField * DocRSUM_DSPN = {read = get_DocRSUM_DSPN , write = set_DocRSUM_DSPN};
   virtual TFIBBCDField * get_DocRSUM_DSPN(void)=0;
   virtual void set_DocRSUM_DSPN(TFIBBCDField * DocRSUM_DSPN)=0;

   __property TFIBBCDField * DocTRPRICE_DSPNT = {read = get_DocTRPRICE_DSPNT , write = set_DocTRPRICE_DSPNT};
   virtual TFIBBCDField * get_DocTRPRICE_DSPNT(void)=0;
   virtual void set_DocTRPRICE_DSPNT(TFIBBCDField * DocTRPRICE_DSPNT)=0;

   __property TFIBBCDField * DocTRSUM_DSPNT = {read = get_DocTRSUM_DSPNT , write = set_DocTRSUM_DSPNT};
   virtual TFIBBCDField * get_DocTRSUM_DSPNT(void)=0;
   virtual void set_DocTRSUM_DSPNT(TFIBBCDField * DocTRSUM_DSPNT)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TFIBBCDField * GrpIDGN = {read = get_GrpIDGN , write = set_GrpIDGN};
   virtual TFIBBCDField * get_GrpIDGN(void)=0;
   virtual void set_GrpIDGN(TFIBBCDField * GrpIDGN)=0;

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

   __property TFIBBCDField * DocIDSPN = {read = get_DocIDSPN , write = set_DocIDSPN};
   virtual TFIBBCDField * get_DocIDSPN(void)=0;
   virtual void set_DocIDSPN(TFIBBCDField * DocIDSPN)=0;

   __property TFIBBCDField * DocIDDOCSPN = {read = get_DocIDDOCSPN , write = set_DocIDDOCSPN};
   virtual TFIBBCDField * get_DocIDDOCSPN(void)=0;
   virtual void set_DocIDDOCSPN(TFIBBCDField * DocIDDOCSPN)=0;

   __property TFIBBCDField * DocIDRTPRICE_DSPN = {read = get_DocIDRTPRICE_DSPN , write = set_DocIDRTPRICE_DSPN};
   virtual TFIBBCDField * get_DocIDRTPRICE_DSPN(void)=0;
   virtual void set_DocIDRTPRICE_DSPN(TFIBBCDField * DocIDRTPRICE_DSPN)=0;

   __property TFIBBCDField * DocTIDSPNT = {read = get_DocTIDSPNT , write = set_DocTIDSPNT};
   virtual TFIBBCDField * get_DocTIDSPNT(void)=0;
   virtual void set_DocTIDSPNT(TFIBBCDField * DocTIDSPNT)=0;

   __property TFIBBCDField * DocTIDDOCSPNT = {read = get_DocTIDDOCSPNT , write = set_DocTIDDOCSPNT};
   virtual TFIBBCDField * get_DocTIDDOCSPNT(void)=0;
   virtual void set_DocTIDDOCSPNT(TFIBBCDField * DocTIDDOCSPNT)=0;

   __property TFIBBCDField * DocTIDNOMSPNT = {read = get_DocTIDNOMSPNT , write = set_DocTIDNOMSPNT};
   virtual TFIBBCDField * get_DocTIDNOMSPNT(void)=0;
   virtual void set_DocTIDNOMSPNT(TFIBBCDField * DocTIDNOMSPNT)=0;

   __property TFIBBCDField * DocTIDEDSPNT = {read = get_DocTIDEDSPNT , write = set_DocTIDEDSPNT};
   virtual TFIBBCDField * get_DocTIDEDSPNT(void)=0;
   virtual void set_DocTIDEDSPNT(TFIBBCDField * DocTIDEDSPNT)=0;

   __property TFIBBCDField * DocAllIDEXTDOC = {read = get_DocAllIDEXTDOC , write = set_DocAllIDEXTDOC};
   virtual TFIBBCDField * get_DocAllIDEXTDOC(void)=0;
   virtual void set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC)=0;

   __property TFIBBCDField * DocIDBASE_DSPN = {read = get_DocIDBASE_DSPN , write = set_DocIDBASE_DSPN};
   virtual TFIBBCDField * get_DocIDBASE_DSPN(void)=0;
   virtual void set_DocIDBASE_DSPN(TFIBBCDField * DocIDBASE_DSPN)=0;

   __property TFIBBCDField * DocTIDBASE_DSPNT = {read = get_DocTIDBASE_DSPNT , write = set_DocTIDBASE_DSPNT};
   virtual TFIBBCDField * get_DocTIDBASE_DSPNT(void)=0;
   virtual void set_DocTIDBASE_DSPNT(TFIBBCDField * DocTIDBASE_DSPNT)=0;

   __property TFIBBCDField * DocAllIDBASE_GALLDOC = {read = get_DocAllIDBASE_GALLDOC , write = set_DocAllIDBASE_GALLDOC};
   virtual TFIBBCDField * get_DocAllIDBASE_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC)=0;

   __property TFIBWideStringField * DocOsnTDOC = {read = get_DocOsnTDOC , write = set_DocOsnTDOC};
   virtual TFIBWideStringField * get_DocOsnTDOC(void)=0;
   virtual void set_DocOsnTDOC(TFIBWideStringField * DocOsnTDOC)=0;

   __property TFIBWideStringField * GrpNAMEGN = {read = get_GrpNAMEGN , write = set_GrpNAMEGN};
   virtual TFIBWideStringField * get_GrpNAMEGN(void)=0;
   virtual void set_GrpNAMEGN(TFIBWideStringField * GrpNAMEGN)=0;

   __property TFIBWideStringField * ElNAMENOM = {read = get_ElNAMENOM , write = set_ElNAMENOM};
   virtual TFIBWideStringField * get_ElNAMENOM(void)=0;
   virtual void set_ElNAMENOM(TFIBWideStringField * ElNAMENOM)=0;

   __property TFIBWideStringField * ElNAMEED = {read = get_ElNAMEED , write = set_ElNAMEED};
   virtual TFIBWideStringField * get_ElNAMEED(void)=0;
   virtual void set_ElNAMEED(TFIBWideStringField * ElNAMEED)=0;

   __property TFIBWideStringField * DocAllTDOC = {read = get_DocAllTDOC , write = set_DocAllTDOC};
   virtual TFIBWideStringField * get_DocAllTDOC(void)=0;
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)=0;

   __property TFIBWideStringField * DocAllGID_DOC = {read = get_DocAllGID_DOC , write = set_DocAllGID_DOC};
   virtual TFIBWideStringField * get_DocAllGID_DOC(void)=0;
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)=0;

   __property TFIBIntegerField * DocAllTYPEEXTDOC = {read = get_DocAllTYPEEXTDOC , write = set_DocAllTYPEEXTDOC};
   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void)=0;
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)=0;

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

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBWideStringField * DocPRIMSPN = {read = get_DocPRIMSPN , write = set_DocPRIMSPN};
   virtual TFIBWideStringField * get_DocPRIMSPN(void)=0;
   virtual void set_DocPRIMSPN(TFIBWideStringField * DocPRIMSPN)=0;

   __property TFIBWideStringField * DocGID_DSPN = {read = get_DocGID_DSPN , write = set_DocGID_DSPN};
   virtual TFIBWideStringField * get_DocGID_DSPN(void)=0;
   virtual void set_DocGID_DSPN(TFIBWideStringField * DocGID_DSPN)=0;

   __property TFIBIntegerField * DocOPER_DSPN = {read = get_DocOPER_DSPN , write = set_DocOPER_DSPN};
   virtual TFIBIntegerField * get_DocOPER_DSPN(void)=0;
   virtual void set_DocOPER_DSPN(TFIBIntegerField * DocOPER_DSPN)=0;

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

   __property int IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual int get_IdSklad(void)=0;
   virtual void set_IdSklad(int IdSklad)=0;

   __property bool SkladRozn = {read = get_SkladRozn , write = set_SkladRozn};
   virtual bool get_SkladRozn(void)=0;
   virtual void set_SkladRozn(bool SkladRozn)=0;

   __property bool NoOtrOstatok = {read = get_NoOtrOstatok , write = set_NoOtrOstatok};
   virtual bool get_NoOtrOstatok(void)=0;
   virtual void set_NoOtrOstatok(bool NoOtrOstatok)=0;

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
   virtual bool AddDataInv(void)=0;
   virtual bool SearchStringPoNom(__int64 id_nom)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocSpisNom __uuidof(IDMDocSpisNom)
#endif
