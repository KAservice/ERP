#ifndef UIDMDocRevH
#define UIDMDocRevH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocRev)) IDMDocRev : public IMainInterface
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

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

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

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBDataSet * IBQPoGrp = {read = get_IBQPoGrp , write = set_IBQPoGrp};
   virtual TpFIBDataSet * get_IBQPoGrp(void)=0;
   virtual void set_IBQPoGrp(TpFIBDataSet * IBQPoGrp)=0;

   __property TpFIBDataSet * IBQ = {read = get_IBQ , write = set_IBQ};
   virtual TpFIBDataSet * get_IBQ(void)=0;
   virtual void set_IBQ(TpFIBDataSet * IBQ)=0;

   __property TFIBIntegerField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBIntegerField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM)=0;

   __property TFIBBCDField * DocTKOL_DREVT = {read = get_DocTKOL_DREVT , write = set_DocTKOL_DREVT};
   virtual TFIBBCDField * get_DocTKOL_DREVT(void)=0;
   virtual void set_DocTKOL_DREVT(TFIBBCDField * DocTKOL_DREVT)=0;

   __property TFIBBCDField * DocTKF_DREVT = {read = get_DocTKF_DREVT , write = set_DocTKF_DREVT};
   virtual TFIBBCDField * get_DocTKF_DREVT(void)=0;
   virtual void set_DocTKF_DREVT(TFIBBCDField * DocTKF_DREVT)=0;

   __property TFIBBCDField * DocTRPRICE_DREVT = {read = get_DocTRPRICE_DREVT , write = set_DocTRPRICE_DREVT};
   virtual TFIBBCDField * get_DocTRPRICE_DREVT(void)=0;
   virtual void set_DocTRPRICE_DREVT(TFIBBCDField * DocTRPRICE_DREVT)=0;

   __property TFIBBCDField * DocTRSUM_DREVT = {read = get_DocTRSUM_DREVT , write = set_DocTRSUM_DREVT};
   virtual TFIBBCDField * get_DocTRSUM_DREVT(void)=0;
   virtual void set_DocTRSUM_DREVT(TFIBBCDField * DocTRSUM_DREVT)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TpFIBDataSet * Ostatki = {read = get_Ostatki , write = set_Ostatki};
   virtual TpFIBDataSet * get_Ostatki(void)=0;
   virtual void set_Ostatki(TpFIBDataSet * Ostatki)=0;

   __property TFIBBCDField * OstatkiKFED = {read = get_OstatkiKFED , write = set_OstatkiKFED};
   virtual TFIBBCDField * get_OstatkiKFED(void)=0;
   virtual void set_OstatkiKFED(TFIBBCDField * OstatkiKFED)=0;

   __property TFIBBCDField * OstatkiSUM = {read = get_OstatkiSUM , write = set_OstatkiSUM};
   virtual TFIBBCDField * get_OstatkiSUM(void)=0;
   virtual void set_OstatkiSUM(TFIBBCDField * OstatkiSUM)=0;

   __property TFIBLargeIntField * OstatkiIDNOM = {read = get_OstatkiIDNOM , write = set_OstatkiIDNOM};
   virtual TFIBLargeIntField * get_OstatkiIDNOM(void)=0;
   virtual void set_OstatkiIDNOM(TFIBLargeIntField * OstatkiIDNOM)=0;

   __property TFIBIntegerField * OstatkiCODENOM = {read = get_OstatkiCODENOM , write = set_OstatkiCODENOM};
   virtual TFIBIntegerField * get_OstatkiCODENOM(void)=0;
   virtual void set_OstatkiCODENOM(TFIBIntegerField * OstatkiCODENOM)=0;

   __property TFIBWideStringField * OstatkiNAMENOM = {read = get_OstatkiNAMENOM , write = set_OstatkiNAMENOM};
   virtual TFIBWideStringField * get_OstatkiNAMENOM(void)=0;
   virtual void set_OstatkiNAMENOM(TFIBWideStringField * OstatkiNAMENOM)=0;

   __property TFIBLargeIntField * OstatkiIDED = {read = get_OstatkiIDED , write = set_OstatkiIDED};
   virtual TFIBLargeIntField * get_OstatkiIDED(void)=0;
   virtual void set_OstatkiIDED(TFIBLargeIntField * OstatkiIDED)=0;

   __property TFIBWideStringField * OstatkiNAMEED = {read = get_OstatkiNAMEED , write = set_OstatkiNAMEED};
   virtual TFIBWideStringField * get_OstatkiNAMEED(void)=0;
   virtual void set_OstatkiNAMEED(TFIBWideStringField * OstatkiNAMEED)=0;

   __property TFIBWideStringField * IBQPoGrpNAMEGN = {read = get_IBQPoGrpNAMEGN , write = set_IBQPoGrpNAMEGN};
   virtual TFIBWideStringField * get_IBQPoGrpNAMEGN(void)=0;
   virtual void set_IBQPoGrpNAMEGN(TFIBWideStringField * IBQPoGrpNAMEGN)=0;

   __property TFIBLargeIntField * IBQPoGrpIDGN = {read = get_IBQPoGrpIDGN , write = set_IBQPoGrpIDGN};
   virtual TFIBLargeIntField * get_IBQPoGrpIDGN(void)=0;
   virtual void set_IBQPoGrpIDGN(TFIBLargeIntField * IBQPoGrpIDGN)=0;

   __property TFIBWideStringField * IBQPoGrpNAMENOM = {read = get_IBQPoGrpNAMENOM , write = set_IBQPoGrpNAMENOM};
   virtual TFIBWideStringField * get_IBQPoGrpNAMENOM(void)=0;
   virtual void set_IBQPoGrpNAMENOM(TFIBWideStringField * IBQPoGrpNAMENOM)=0;

   __property TFIBIntegerField * IBQPoGrpTNOM = {read = get_IBQPoGrpTNOM , write = set_IBQPoGrpTNOM};
   virtual TFIBIntegerField * get_IBQPoGrpTNOM(void)=0;
   virtual void set_IBQPoGrpTNOM(TFIBIntegerField * IBQPoGrpTNOM)=0;

   __property TFIBIntegerField * IBQPoGrpCODENOM = {read = get_IBQPoGrpCODENOM , write = set_IBQPoGrpCODENOM};
   virtual TFIBIntegerField * get_IBQPoGrpCODENOM(void)=0;
   virtual void set_IBQPoGrpCODENOM(TFIBIntegerField * IBQPoGrpCODENOM)=0;

   __property TFIBLargeIntField * IBQPoGrpID_DREVT = {read = get_IBQPoGrpID_DREVT , write = set_IBQPoGrpID_DREVT};
   virtual TFIBLargeIntField * get_IBQPoGrpID_DREVT(void)=0;
   virtual void set_IBQPoGrpID_DREVT(TFIBLargeIntField * IBQPoGrpID_DREVT)=0;

   __property TFIBLargeIntField * IBQPoGrpIDDOC_DREVT = {read = get_IBQPoGrpIDDOC_DREVT , write = set_IBQPoGrpIDDOC_DREVT};
   virtual TFIBLargeIntField * get_IBQPoGrpIDDOC_DREVT(void)=0;
   virtual void set_IBQPoGrpIDDOC_DREVT(TFIBLargeIntField * IBQPoGrpIDDOC_DREVT)=0;

   __property TFIBLargeIntField * IBQPoGrpIDNOM_DREVT = {read = get_IBQPoGrpIDNOM_DREVT , write = set_IBQPoGrpIDNOM_DREVT};
   virtual TFIBLargeIntField * get_IBQPoGrpIDNOM_DREVT(void)=0;
   virtual void set_IBQPoGrpIDNOM_DREVT(TFIBLargeIntField * IBQPoGrpIDNOM_DREVT)=0;

   __property TFIBLargeIntField * IBQPoGrpIDED_DREVT = {read = get_IBQPoGrpIDED_DREVT , write = set_IBQPoGrpIDED_DREVT};
   virtual TFIBLargeIntField * get_IBQPoGrpIDED_DREVT(void)=0;
   virtual void set_IBQPoGrpIDED_DREVT(TFIBLargeIntField * IBQPoGrpIDED_DREVT)=0;

   __property TFIBBCDField * IBQPoGrpKOL_DREVT = {read = get_IBQPoGrpKOL_DREVT , write = set_IBQPoGrpKOL_DREVT};
   virtual TFIBBCDField * get_IBQPoGrpKOL_DREVT(void)=0;
   virtual void set_IBQPoGrpKOL_DREVT(TFIBBCDField * IBQPoGrpKOL_DREVT)=0;

   __property TFIBBCDField * IBQPoGrpKF_DREVT = {read = get_IBQPoGrpKF_DREVT , write = set_IBQPoGrpKF_DREVT};
   virtual TFIBBCDField * get_IBQPoGrpKF_DREVT(void)=0;
   virtual void set_IBQPoGrpKF_DREVT(TFIBBCDField * IBQPoGrpKF_DREVT)=0;

   __property TFIBBCDField * IBQPoGrpRPRICE_DREVT = {read = get_IBQPoGrpRPRICE_DREVT , write = set_IBQPoGrpRPRICE_DREVT};
   virtual TFIBBCDField * get_IBQPoGrpRPRICE_DREVT(void)=0;
   virtual void set_IBQPoGrpRPRICE_DREVT(TFIBBCDField * IBQPoGrpRPRICE_DREVT)=0;

   __property TFIBBCDField * IBQPoGrpRSUM_DREVT = {read = get_IBQPoGrpRSUM_DREVT , write = set_IBQPoGrpRSUM_DREVT};
   virtual TFIBBCDField * get_IBQPoGrpRSUM_DREVT(void)=0;
   virtual void set_IBQPoGrpRSUM_DREVT(TFIBBCDField * IBQPoGrpRSUM_DREVT)=0;

   __property TFIBWideStringField * IBQPoGrpNAMEED = {read = get_IBQPoGrpNAMEED , write = set_IBQPoGrpNAMEED};
   virtual TFIBWideStringField * get_IBQPoGrpNAMEED(void)=0;
   virtual void set_IBQPoGrpNAMEED(TFIBWideStringField * IBQPoGrpNAMEED)=0;

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

   __property TFIBWideStringField * DocAllNAME_USER = {read = get_DocAllNAME_USER , write = set_DocAllNAME_USER};
   virtual TFIBWideStringField * get_DocAllNAME_USER(void)=0;
   virtual void set_DocAllNAME_USER(TFIBWideStringField * DocAllNAME_USER)=0;

   __property TFIBWideStringField * DocAllFNAME_USER = {read = get_DocAllFNAME_USER , write = set_DocAllFNAME_USER};
   virtual TFIBWideStringField * get_DocAllFNAME_USER(void)=0;
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)=0;

   __property TFIBWideStringField * DocAllNAMEFIRM = {read = get_DocAllNAMEFIRM , write = set_DocAllNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void)=0;
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllNAMESKLAD = {read = get_DocAllNAMESKLAD , write = set_DocAllNAMESKLAD};
   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void)=0;
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)=0;

   __property TFIBLargeIntField * DocID_DREV = {read = get_DocID_DREV , write = set_DocID_DREV};
   virtual TFIBLargeIntField * get_DocID_DREV(void)=0;
   virtual void set_DocID_DREV(TFIBLargeIntField * DocID_DREV)=0;

   __property TFIBWideStringField * DocGID_DREV = {read = get_DocGID_DREV , write = set_DocGID_DREV};
   virtual TFIBWideStringField * get_DocGID_DREV(void)=0;
   virtual void set_DocGID_DREV(TFIBWideStringField * DocGID_DREV)=0;

   __property TFIBLargeIntField * DocIDDOC_DREV = {read = get_DocIDDOC_DREV , write = set_DocIDDOC_DREV};
   virtual TFIBLargeIntField * get_DocIDDOC_DREV(void)=0;
   virtual void set_DocIDDOC_DREV(TFIBLargeIntField * DocIDDOC_DREV)=0;

   __property TFIBLargeIntField * DocIDINV_DREV = {read = get_DocIDINV_DREV , write = set_DocIDINV_DREV};
   virtual TFIBLargeIntField * get_DocIDINV_DREV(void)=0;
   virtual void set_DocIDINV_DREV(TFIBLargeIntField * DocIDINV_DREV)=0;

   __property TFIBWideStringField * DocDESCR_DREV = {read = get_DocDESCR_DREV , write = set_DocDESCR_DREV};
   virtual TFIBWideStringField * get_DocDESCR_DREV(void)=0;
   virtual void set_DocDESCR_DREV(TFIBWideStringField * DocDESCR_DREV)=0;

   __property TFIBLargeIntField * DocIDRTPRICE_DREV = {read = get_DocIDRTPRICE_DREV , write = set_DocIDRTPRICE_DREV};
   virtual TFIBLargeIntField * get_DocIDRTPRICE_DREV(void)=0;
   virtual void set_DocIDRTPRICE_DREV(TFIBLargeIntField * DocIDRTPRICE_DREV)=0;

   __property TFIBLargeIntField * DocIDBASE_DREV = {read = get_DocIDBASE_DREV , write = set_DocIDBASE_DREV};
   virtual TFIBLargeIntField * get_DocIDBASE_DREV(void)=0;
   virtual void set_DocIDBASE_DREV(TFIBLargeIntField * DocIDBASE_DREV)=0;

   __property TFIBWideStringField * DocNAME_SINV = {read = get_DocNAME_SINV , write = set_DocNAME_SINV};
   virtual TFIBWideStringField * get_DocNAME_SINV(void)=0;
   virtual void set_DocNAME_SINV(TFIBWideStringField * DocNAME_SINV)=0;

   __property TFIBWideStringField * DocTNAMEGN = {read = get_DocTNAMEGN , write = set_DocTNAMEGN};
   virtual TFIBWideStringField * get_DocTNAMEGN(void)=0;
   virtual void set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN)=0;

   __property TFIBLargeIntField * DocTIDGN = {read = get_DocTIDGN , write = set_DocTIDGN};
   virtual TFIBLargeIntField * get_DocTIDGN(void)=0;
   virtual void set_DocTIDGN(TFIBLargeIntField * DocTIDGN)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBLargeIntField * DocTID_DREVT = {read = get_DocTID_DREVT , write = set_DocTID_DREVT};
   virtual TFIBLargeIntField * get_DocTID_DREVT(void)=0;
   virtual void set_DocTID_DREVT(TFIBLargeIntField * DocTID_DREVT)=0;

   __property TFIBWideStringField * DocTGID_DREVT = {read = get_DocTGID_DREVT , write = set_DocTGID_DREVT};
   virtual TFIBWideStringField * get_DocTGID_DREVT(void)=0;
   virtual void set_DocTGID_DREVT(TFIBWideStringField * DocTGID_DREVT)=0;

   __property TFIBLargeIntField * DocTIDDOC_DREVT = {read = get_DocTIDDOC_DREVT , write = set_DocTIDDOC_DREVT};
   virtual TFIBLargeIntField * get_DocTIDDOC_DREVT(void)=0;
   virtual void set_DocTIDDOC_DREVT(TFIBLargeIntField * DocTIDDOC_DREVT)=0;

   __property TFIBLargeIntField * DocTIDNOM_DREVT = {read = get_DocTIDNOM_DREVT , write = set_DocTIDNOM_DREVT};
   virtual TFIBLargeIntField * get_DocTIDNOM_DREVT(void)=0;
   virtual void set_DocTIDNOM_DREVT(TFIBLargeIntField * DocTIDNOM_DREVT)=0;

   __property TFIBLargeIntField * DocTIDED_DREVT = {read = get_DocTIDED_DREVT , write = set_DocTIDED_DREVT};
   virtual TFIBLargeIntField * get_DocTIDED_DREVT(void)=0;
   virtual void set_DocTIDED_DREVT(TFIBLargeIntField * DocTIDED_DREVT)=0;

   __property TFIBLargeIntField * DocTIDBASE_DREVT = {read = get_DocTIDBASE_DREVT , write = set_DocTIDBASE_DREVT};
   virtual TFIBLargeIntField * get_DocTIDBASE_DREVT(void)=0;
   virtual void set_DocTIDBASE_DREVT(TFIBLargeIntField * DocTIDBASE_DREVT)=0;

   __property TFIBLargeIntField * DocTIDEXT_DOUT_DREVT = {read = get_DocTIDEXT_DOUT_DREVT , write = set_DocTIDEXT_DOUT_DREVT};
   virtual TFIBLargeIntField * get_DocTIDEXT_DOUT_DREVT(void)=0;
   virtual void set_DocTIDEXT_DOUT_DREVT(TFIBLargeIntField * DocTIDEXT_DOUT_DREVT)=0;

   __property TFIBLargeIntField * DocTIDEXT_BASE_DREVT = {read = get_DocTIDEXT_BASE_DREVT , write = set_DocTIDEXT_BASE_DREVT};
   virtual TFIBLargeIntField * get_DocTIDEXT_BASE_DREVT(void)=0;
   virtual void set_DocTIDEXT_BASE_DREVT(TFIBLargeIntField * DocTIDEXT_BASE_DREVT)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocAllFNAMEFIRM = {read = get_DocAllFNAMEFIRM , write = set_DocAllFNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllFNAMEFIRM(void)=0;
   virtual void set_DocAllFNAMEFIRM(TFIBWideStringField * DocAllFNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllPADRFIRM = {read = get_DocAllPADRFIRM , write = set_DocAllPADRFIRM};
   virtual TFIBWideStringField * get_DocAllPADRFIRM(void)=0;
   virtual void set_DocAllPADRFIRM(TFIBWideStringField * DocAllPADRFIRM)=0;

   __property TFIBWideStringField * DocAllINNFIRM = {read = get_DocAllINNFIRM , write = set_DocAllINNFIRM};
   virtual TFIBWideStringField * get_DocAllINNFIRM(void)=0;
   virtual void set_DocAllINNFIRM(TFIBWideStringField * DocAllINNFIRM)=0;

   __property TFIBLargeIntField * DocAllIDPROJECT_GALLDOC = {read = get_DocAllIDPROJECT_GALLDOC , write = set_DocAllIDPROJECT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDPROJECT_GALLDOC(void)=0;
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC = {read = get_DocAllIDBUSINOP_GALLDOC , write = set_DocAllIDBUSINOP_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void)=0;
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBBCDField * DocTUCH_KOL_DREVT = {read = get_DocTUCH_KOL_DREVT , write = set_DocTUCH_KOL_DREVT};
   virtual TFIBBCDField * get_DocTUCH_KOL_DREVT(void)=0;
   virtual void set_DocTUCH_KOL_DREVT(TFIBBCDField * DocTUCH_KOL_DREVT)=0;

   __property TFIBBCDField * DocTUCH_RSUM_DREVT = {read = get_DocTUCH_RSUM_DREVT , write = set_DocTUCH_RSUM_DREVT};
   virtual TFIBBCDField * get_DocTUCH_RSUM_DREVT(void)=0;
   virtual void set_DocTUCH_RSUM_DREVT(TFIBBCDField * DocTUCH_RSUM_DREVT)=0;

   __property TFIBBCDField * DocTUCH_SUM_DREVT = {read = get_DocTUCH_SUM_DREVT , write = set_DocTUCH_SUM_DREVT};
   virtual TFIBBCDField * get_DocTUCH_SUM_DREVT(void)=0;
   virtual void set_DocTUCH_SUM_DREVT(TFIBBCDField * DocTUCH_SUM_DREVT)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC = {read = get_DocAllPREFIKS_NUM_GALLDOC , write = set_DocAllPREFIKS_NUM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)=0;

   __property bool NewElement = {read = get_NewElement , write = set_NewElement};
   virtual bool get_NewElement(void)=0;
   virtual void set_NewElement(bool NewElement)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool NoEdit = {read = get_NoEdit , write = set_NoEdit};
   virtual bool get_NoEdit(void)=0;
   virtual void set_NoEdit(bool NoEdit)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property int IdGrpNom = {read = get_IdGrpNom , write = set_IdGrpNom};
   virtual int get_IdGrpNom(void)=0;
   virtual void set_IdGrpNom(int IdGrpNom)=0;

   __property bool ChangeTable = {read = get_ChangeTable , write = set_ChangeTable};
   virtual bool get_ChangeTable(void)=0;
   virtual void set_ChangeTable(bool ChangeTable)=0;

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
   virtual bool DeleteDoc(__int64 id)=0;
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)=0;
   virtual void AddOstatkiNaSklade(__int64 id_firm, __int64 id_sklad)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocRev __uuidof(IDMDocRev)
#endif
