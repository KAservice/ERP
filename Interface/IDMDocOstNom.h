#ifndef UIDMDocOstNomH
#define UIDMDocOstNomH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocOstNom)) IDMDocOstNom : public IMainInterface
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

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

   __property TFIBBCDField * DocTKOLOSNT = {read = get_DocTKOLOSNT , write = set_DocTKOLOSNT};
   virtual TFIBBCDField * get_DocTKOLOSNT(void)=0;
   virtual void set_DocTKOLOSNT(TFIBBCDField * DocTKOLOSNT)=0;

   __property TFIBBCDField * DocTKFOSNT = {read = get_DocTKFOSNT , write = set_DocTKFOSNT};
   virtual TFIBBCDField * get_DocTKFOSNT(void)=0;
   virtual void set_DocTKFOSNT(TFIBBCDField * DocTKFOSNT)=0;

   __property TFIBBCDField * DocTPRICEOSNT = {read = get_DocTPRICEOSNT , write = set_DocTPRICEOSNT};
   virtual TFIBBCDField * get_DocTPRICEOSNT(void)=0;
   virtual void set_DocTPRICEOSNT(TFIBBCDField * DocTPRICEOSNT)=0;

   __property TFIBBCDField * DocTSUMOSNT = {read = get_DocTSUMOSNT , write = set_DocTSUMOSNT};
   virtual TFIBBCDField * get_DocTSUMOSNT(void)=0;
   virtual void set_DocTSUMOSNT(TFIBBCDField * DocTSUMOSNT)=0;

   __property TFIBIntegerField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBIntegerField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBDataSet * Grp = {read = get_Grp , write = set_Grp};
   virtual TpFIBDataSet * get_Grp(void)=0;
   virtual void set_Grp(TpFIBDataSet * Grp)=0;

   __property TpFIBDataSet * El = {read = get_El , write = set_El};
   virtual TpFIBDataSet * get_El(void)=0;
   virtual void set_El(TpFIBDataSet * El)=0;

   __property TpFIBDataSet * IBQ = {read = get_IBQ , write = set_IBQ};
   virtual TpFIBDataSet * get_IBQ(void)=0;
   virtual void set_IBQ(TpFIBDataSet * IBQ)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TpFIBDataSet * DocOsn = {read = get_DocOsn , write = set_DocOsn};
   virtual TpFIBDataSet * get_DocOsn(void)=0;
   virtual void set_DocOsn(TpFIBDataSet * DocOsn)=0;

   __property TFIBIntegerField * DocOsnNUMDOC = {read = get_DocOsnNUMDOC , write = set_DocOsnNUMDOC};
   virtual TFIBIntegerField * get_DocOsnNUMDOC(void)=0;
   virtual void set_DocOsnNUMDOC(TFIBIntegerField * DocOsnNUMDOC)=0;

   __property TFIBDateTimeField * DocOsnPOSDOC = {read = get_DocOsnPOSDOC , write = set_DocOsnPOSDOC};
   virtual TFIBDateTimeField * get_DocOsnPOSDOC(void)=0;
   virtual void set_DocOsnPOSDOC(TFIBDateTimeField * DocOsnPOSDOC)=0;

   __property TFIBBCDField * DocRSUM_DOSN = {read = get_DocRSUM_DOSN , write = set_DocRSUM_DOSN};
   virtual TFIBBCDField * get_DocRSUM_DOSN(void)=0;
   virtual void set_DocRSUM_DOSN(TFIBBCDField * DocRSUM_DOSN)=0;

   __property TFIBBCDField * DocTRPRICE_DOSNT = {read = get_DocTRPRICE_DOSNT , write = set_DocTRPRICE_DOSNT};
   virtual TFIBBCDField * get_DocTRPRICE_DOSNT(void)=0;
   virtual void set_DocTRPRICE_DOSNT(TFIBBCDField * DocTRPRICE_DOSNT)=0;

   __property TFIBBCDField * DocTRSUM_DOSNT = {read = get_DocTRSUM_DOSNT , write = set_DocTRSUM_DOSNT};
   virtual TFIBBCDField * get_DocTRSUM_DOSNT(void)=0;
   virtual void set_DocTRSUM_DOSNT(TFIBBCDField * DocTRSUM_DOSNT)=0;

   __property TFIBBCDField * DocTNAC_DOSNT = {read = get_DocTNAC_DOSNT , write = set_DocTNAC_DOSNT};
   virtual TFIBBCDField * get_DocTNAC_DOSNT(void)=0;
   virtual void set_DocTNAC_DOSNT(TFIBBCDField * DocTNAC_DOSNT)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TFIBIntegerField * DocTNDS_DOSNT = {read = get_DocTNDS_DOSNT , write = set_DocTNDS_DOSNT};
   virtual TFIBIntegerField * get_DocTNDS_DOSNT(void)=0;
   virtual void set_DocTNDS_DOSNT(TFIBIntegerField * DocTNDS_DOSNT)=0;

   __property TFIBBCDField * DocTSUMNDS_DOSNT = {read = get_DocTSUMNDS_DOSNT , write = set_DocTSUMNDS_DOSNT};
   virtual TFIBBCDField * get_DocTSUMNDS_DOSNT(void)=0;
   virtual void set_DocTSUMNDS_DOSNT(TFIBBCDField * DocTSUMNDS_DOSNT)=0;

   __property TFIBDateTimeField * DocTSRGODNPART = {read = get_DocTSRGODNPART , write = set_DocTSRGODNPART};
   virtual TFIBDateTimeField * get_DocTSRGODNPART(void)=0;
   virtual void set_DocTSRGODNPART(TFIBDateTimeField * DocTSRGODNPART)=0;

   __property TFIBWideStringField * DocOsnTDOC = {read = get_DocOsnTDOC , write = set_DocOsnTDOC};
   virtual TFIBWideStringField * get_DocOsnTDOC(void)=0;
   virtual void set_DocOsnTDOC(TFIBWideStringField * DocOsnTDOC)=0;

   __property TFIBWideStringField * GrpNAMEGN = {read = get_GrpNAMEGN , write = set_GrpNAMEGN};
   virtual TFIBWideStringField * get_GrpNAMEGN(void)=0;
   virtual void set_GrpNAMEGN(TFIBWideStringField * GrpNAMEGN)=0;

   __property TFIBLargeIntField * GrpIDGN = {read = get_GrpIDGN , write = set_GrpIDGN};
   virtual TFIBLargeIntField * get_GrpIDGN(void)=0;
   virtual void set_GrpIDGN(TFIBLargeIntField * GrpIDGN)=0;

   __property TFIBBCDField * GrpSUMMA = {read = get_GrpSUMMA , write = set_GrpSUMMA};
   virtual TFIBBCDField * get_GrpSUMMA(void)=0;
   virtual void set_GrpSUMMA(TFIBBCDField * GrpSUMMA)=0;

   __property TFIBWideStringField * ElNAMENOM = {read = get_ElNAMENOM , write = set_ElNAMENOM};
   virtual TFIBWideStringField * get_ElNAMENOM(void)=0;
   virtual void set_ElNAMENOM(TFIBWideStringField * ElNAMENOM)=0;

   __property TFIBWideStringField * ElNAMEED = {read = get_ElNAMEED , write = set_ElNAMEED};
   virtual TFIBWideStringField * get_ElNAMEED(void)=0;
   virtual void set_ElNAMEED(TFIBWideStringField * ElNAMEED)=0;

   __property TFIBBCDField * ElSUMMA = {read = get_ElSUMMA , write = set_ElSUMMA};
   virtual TFIBBCDField * get_ElSUMMA(void)=0;
   virtual void set_ElSUMMA(TFIBBCDField * ElSUMMA)=0;

   __property TFIBFloatField * ElSUMKOL = {read = get_ElSUMKOL , write = set_ElSUMKOL};
   virtual TFIBFloatField * get_ElSUMKOL(void)=0;
   virtual void set_ElSUMKOL(TFIBFloatField * ElSUMKOL)=0;

   __property TFIBLargeIntField * DocAllIDDOC = {read = get_DocAllIDDOC , write = set_DocAllIDDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOC(void)=0;
   virtual void set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)=0;

   __property TFIBDateTimeField * DocAllPOSDOC = {read = get_DocAllPOSDOC , write = set_DocAllPOSDOC};
   virtual TFIBDateTimeField * get_DocAllPOSDOC(void)=0;
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)=0;

   __property TFIBSmallIntField * DocAllPRDOC = {read = get_DocAllPRDOC , write = set_DocAllPRDOC};
   virtual TFIBSmallIntField * get_DocAllPRDOC(void)=0;
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)=0;

   __property TFIBWideStringField * DocAllTDOC = {read = get_DocAllTDOC , write = set_DocAllTDOC};
   virtual TFIBWideStringField * get_DocAllTDOC(void)=0;
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)=0;

   __property TFIBIntegerField * DocAllNUMDOC = {read = get_DocAllNUMDOC , write = set_DocAllNUMDOC};
   virtual TFIBIntegerField * get_DocAllNUMDOC(void)=0;
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)=0;

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

   __property TFIBBCDField * DocAllSUMDOC = {read = get_DocAllSUMDOC , write = set_DocAllSUMDOC};
   virtual TFIBBCDField * get_DocAllSUMDOC(void)=0;
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)=0;

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

   __property TFIBWideStringField * DocAllNAMESKLAD = {read = get_DocAllNAMESKLAD , write = set_DocAllNAMESKLAD};
   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void)=0;
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)=0;

   __property TFIBLargeIntField * DocIDOSN = {read = get_DocIDOSN , write = set_DocIDOSN};
   virtual TFIBLargeIntField * get_DocIDOSN(void)=0;
   virtual void set_DocIDOSN(TFIBLargeIntField * DocIDOSN)=0;

   __property TFIBLargeIntField * DocIDDOCOSN = {read = get_DocIDDOCOSN , write = set_DocIDDOCOSN};
   virtual TFIBLargeIntField * get_DocIDDOCOSN(void)=0;
   virtual void set_DocIDDOCOSN(TFIBLargeIntField * DocIDDOCOSN)=0;

   __property TFIBWideStringField * DocPRIMOSN = {read = get_DocPRIMOSN , write = set_DocPRIMOSN};
   virtual TFIBWideStringField * get_DocPRIMOSN(void)=0;
   virtual void set_DocPRIMOSN(TFIBWideStringField * DocPRIMOSN)=0;

   __property TFIBLargeIntField * DocIDTPRICEOSN = {read = get_DocIDTPRICEOSN , write = set_DocIDTPRICEOSN};
   virtual TFIBLargeIntField * get_DocIDTPRICEOSN(void)=0;
   virtual void set_DocIDTPRICEOSN(TFIBLargeIntField * DocIDTPRICEOSN)=0;

   __property TFIBWideStringField * DocGID_DOSN = {read = get_DocGID_DOSN , write = set_DocGID_DOSN};
   virtual TFIBWideStringField * get_DocGID_DOSN(void)=0;
   virtual void set_DocGID_DOSN(TFIBWideStringField * DocGID_DOSN)=0;

   __property TFIBLargeIntField * DocIDRTPRICE_DOSN = {read = get_DocIDRTPRICE_DOSN , write = set_DocIDRTPRICE_DOSN};
   virtual TFIBLargeIntField * get_DocIDRTPRICE_DOSN(void)=0;
   virtual void set_DocIDRTPRICE_DOSN(TFIBLargeIntField * DocIDRTPRICE_DOSN)=0;

   __property TFIBLargeIntField * DocIDBASE_DOSN = {read = get_DocIDBASE_DOSN , write = set_DocIDBASE_DOSN};
   virtual TFIBLargeIntField * get_DocIDBASE_DOSN(void)=0;
   virtual void set_DocIDBASE_DOSN(TFIBLargeIntField * DocIDBASE_DOSN)=0;

   __property TFIBIntegerField * DocOPER_DOSN = {read = get_DocOPER_DOSN , write = set_DocOPER_DOSN};
   virtual TFIBIntegerField * get_DocOPER_DOSN(void)=0;
   virtual void set_DocOPER_DOSN(TFIBIntegerField * DocOPER_DOSN)=0;

   __property TFIBWideStringField * DocNAME_TPRICE = {read = get_DocNAME_TPRICE , write = set_DocNAME_TPRICE};
   virtual TFIBWideStringField * get_DocNAME_TPRICE(void)=0;
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)=0;

   __property TFIBLargeIntField * DocTIDOSNT = {read = get_DocTIDOSNT , write = set_DocTIDOSNT};
   virtual TFIBLargeIntField * get_DocTIDOSNT(void)=0;
   virtual void set_DocTIDOSNT(TFIBLargeIntField * DocTIDOSNT)=0;

   __property TFIBLargeIntField * DocTIDDOCOSNT = {read = get_DocTIDDOCOSNT , write = set_DocTIDDOCOSNT};
   virtual TFIBLargeIntField * get_DocTIDDOCOSNT(void)=0;
   virtual void set_DocTIDDOCOSNT(TFIBLargeIntField * DocTIDDOCOSNT)=0;

   __property TFIBLargeIntField * DocTIDNOMOSNT = {read = get_DocTIDNOMOSNT , write = set_DocTIDNOMOSNT};
   virtual TFIBLargeIntField * get_DocTIDNOMOSNT(void)=0;
   virtual void set_DocTIDNOMOSNT(TFIBLargeIntField * DocTIDNOMOSNT)=0;

   __property TFIBLargeIntField * DocTIDEDOSNT = {read = get_DocTIDEDOSNT , write = set_DocTIDEDOSNT};
   virtual TFIBLargeIntField * get_DocTIDEDOSNT(void)=0;
   virtual void set_DocTIDEDOSNT(TFIBLargeIntField * DocTIDEDOSNT)=0;

   __property TFIBLargeIntField * DocTIDPARTOSNT = {read = get_DocTIDPARTOSNT , write = set_DocTIDPARTOSNT};
   virtual TFIBLargeIntField * get_DocTIDPARTOSNT(void)=0;
   virtual void set_DocTIDPARTOSNT(TFIBLargeIntField * DocTIDPARTOSNT)=0;

   __property TFIBWideStringField * DocTGID_DOSNT = {read = get_DocTGID_DOSNT , write = set_DocTGID_DOSNT};
   virtual TFIBWideStringField * get_DocTGID_DOSNT(void)=0;
   virtual void set_DocTGID_DOSNT(TFIBWideStringField * DocTGID_DOSNT)=0;

   __property TFIBLargeIntField * DocTIDBASE_DOSNT = {read = get_DocTIDBASE_DOSNT , write = set_DocTIDBASE_DOSNT};
   virtual TFIBLargeIntField * get_DocTIDBASE_DOSNT(void)=0;
   virtual void set_DocTIDBASE_DOSNT(TFIBLargeIntField * DocTIDBASE_DOSNT)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBWideStringField * DocTGTDPART = {read = get_DocTGTDPART , write = set_DocTGTDPART};
   virtual TFIBWideStringField * get_DocTGTDPART(void)=0;
   virtual void set_DocTGTDPART(TFIBWideStringField * DocTGTDPART)=0;

   __property TFIBWideStringField * DocTSERTPART = {read = get_DocTSERTPART , write = set_DocTSERTPART};
   virtual TFIBWideStringField * get_DocTSERTPART(void)=0;
   virtual void set_DocTSERTPART(TFIBWideStringField * DocTSERTPART)=0;

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

   __property TpFIBDataSet * TypeNom = {read = get_TypeNom , write = set_TypeNom};
   virtual TpFIBDataSet * get_TypeNom(void)=0;
   virtual void set_TypeNom(TpFIBDataSet * TypeNom)=0;

   __property TFIBLargeIntField * TypeNomID_STNOM = {read = get_TypeNomID_STNOM , write = set_TypeNomID_STNOM};
   virtual TFIBLargeIntField * get_TypeNomID_STNOM(void)=0;
   virtual void set_TypeNomID_STNOM(TFIBLargeIntField * TypeNomID_STNOM)=0;

   __property TFIBWideStringField * TypeNomNAME_STNOM = {read = get_TypeNomNAME_STNOM , write = set_TypeNomNAME_STNOM};
   virtual TFIBWideStringField * get_TypeNomNAME_STNOM(void)=0;
   virtual void set_TypeNomNAME_STNOM(TFIBWideStringField * TypeNomNAME_STNOM)=0;

   __property TFIBLargeIntField * DocTIDTNOM_DOSNT = {read = get_DocTIDTNOM_DOSNT , write = set_DocTIDTNOM_DOSNT};
   virtual TFIBLargeIntField * get_DocTIDTNOM_DOSNT(void)=0;
   virtual void set_DocTIDTNOM_DOSNT(TFIBLargeIntField * DocTIDTNOM_DOSNT)=0;

   __property TStringField * DocTNAME_TYPE_NOM = {read = get_DocTNAME_TYPE_NOM , write = set_DocTNAME_TYPE_NOM};
   virtual TStringField * get_DocTNAME_TYPE_NOM(void)=0;
   virtual void set_DocTNAME_TYPE_NOM(TStringField * DocTNAME_TYPE_NOM)=0;

   __property TFIBLargeIntField * DocAllIDOBJECT_GALLDOC = {read = get_DocAllIDOBJECT_GALLDOC , write = set_DocAllIDOBJECT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDOBJECT_GALLDOC(void)=0;
   virtual void set_DocAllIDOBJECT_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SOBJECT = {read = get_DocAllNAME_SOBJECT , write = set_DocAllNAME_SOBJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SOBJECT(void)=0;
   virtual void set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT)=0;

   __property bool NewElement = {read = get_NewElement , write = set_NewElement};
   virtual bool get_NewElement(void)=0;
   virtual void set_NewElement(bool NewElement)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElementaMaster = {read = get_IdElementaMaster , write = set_IdElementaMaster};
   virtual __int64 get_IdElementaMaster(void)=0;
   virtual void set_IdElementaMaster(__int64 IdElementaMaster)=0;

   __property bool SkladRozn = {read = get_SkladRozn , write = set_SkladRozn};
   virtual bool get_SkladRozn(void)=0;
   virtual void set_SkladRozn(bool SkladRozn)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 id_doc)=0;
   virtual bool SaveDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)=0;
   virtual bool AddDataInv(void)=0;
   virtual bool SearchStringPoNom(__int64 id_nom)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocOstNom __uuidof(IDMDocOstNom)
#endif
