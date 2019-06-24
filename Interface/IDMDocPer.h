#ifndef UIDMDocPerH
#define UIDMDocPerH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocPer)) IDMDocPer : public IMainInterface
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

   __property TFIBBCDField * DocTKOLPERT = {read = get_DocTKOLPERT , write = set_DocTKOLPERT};
   virtual TFIBBCDField * get_DocTKOLPERT(void)=0;
   virtual void set_DocTKOLPERT(TFIBBCDField * DocTKOLPERT)=0;

   __property TFIBBCDField * DocTKFPERT = {read = get_DocTKFPERT , write = set_DocTKFPERT};
   virtual TFIBBCDField * get_DocTKFPERT(void)=0;
   virtual void set_DocTKFPERT(TFIBBCDField * DocTKFPERT)=0;

   __property TFIBBCDField * DocTPRICEPERT = {read = get_DocTPRICEPERT , write = set_DocTPRICEPERT};
   virtual TFIBBCDField * get_DocTPRICEPERT(void)=0;
   virtual void set_DocTPRICEPERT(TFIBBCDField * DocTPRICEPERT)=0;

   __property TFIBBCDField * DocTSUMPERT = {read = get_DocTSUMPERT , write = set_DocTSUMPERT};
   virtual TFIBBCDField * get_DocTSUMPERT(void)=0;
   virtual void set_DocTSUMPERT(TFIBBCDField * DocTSUMPERT)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBDataSet * Firma = {read = get_Firma , write = set_Firma};
   virtual TpFIBDataSet * get_Firma(void)=0;
   virtual void set_Firma(TpFIBDataSet * Firma)=0;

   __property TpFIBDataSet * Sklad = {read = get_Sklad , write = set_Sklad};
   virtual TpFIBDataSet * get_Sklad(void)=0;
   virtual void set_Sklad(TpFIBDataSet * Sklad)=0;

   __property TpFIBDataSet * SkladPol = {read = get_SkladPol , write = set_SkladPol};
   virtual TpFIBDataSet * get_SkladPol(void)=0;
   virtual void set_SkladPol(TpFIBDataSet * SkladPol)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TFIBBCDField * DocTNAC_DPERT = {read = get_DocTNAC_DPERT , write = set_DocTNAC_DPERT};
   virtual TFIBBCDField * get_DocTNAC_DPERT(void)=0;
   virtual void set_DocTNAC_DPERT(TFIBBCDField * DocTNAC_DPERT)=0;

   __property TFIBIntegerField * DocTNDS_DPERT = {read = get_DocTNDS_DPERT , write = set_DocTNDS_DPERT};
   virtual TFIBIntegerField * get_DocTNDS_DPERT(void)=0;
   virtual void set_DocTNDS_DPERT(TFIBIntegerField * DocTNDS_DPERT)=0;

   __property TFIBBCDField * DocTSUMNDS_DPERT = {read = get_DocTSUMNDS_DPERT , write = set_DocTSUMNDS_DPERT};
   virtual TFIBBCDField * get_DocTSUMNDS_DPERT(void)=0;
   virtual void set_DocTSUMNDS_DPERT(TFIBBCDField * DocTSUMNDS_DPERT)=0;

   __property TFIBLargeIntField * SkladPolIDSKLAD = {read = get_SkladPolIDSKLAD , write = set_SkladPolIDSKLAD};
   virtual TFIBLargeIntField * get_SkladPolIDSKLAD(void)=0;
   virtual void set_SkladPolIDSKLAD(TFIBLargeIntField * SkladPolIDSKLAD)=0;

   __property TFIBWideStringField * SkladPolNAMESKLAD = {read = get_SkladPolNAMESKLAD , write = set_SkladPolNAMESKLAD};
   virtual TFIBWideStringField * get_SkladPolNAMESKLAD(void)=0;
   virtual void set_SkladPolNAMESKLAD(TFIBWideStringField * SkladPolNAMESKLAD)=0;

   __property TFIBWideStringField * SkladPolMOLSKLAD = {read = get_SkladPolMOLSKLAD , write = set_SkladPolMOLSKLAD};
   virtual TFIBWideStringField * get_SkladPolMOLSKLAD(void)=0;
   virtual void set_SkladPolMOLSKLAD(TFIBWideStringField * SkladPolMOLSKLAD)=0;

   __property TFIBWideStringField * SkladPolADRSKLAD = {read = get_SkladPolADRSKLAD , write = set_SkladPolADRSKLAD};
   virtual TFIBWideStringField * get_SkladPolADRSKLAD(void)=0;
   virtual void set_SkladPolADRSKLAD(TFIBWideStringField * SkladPolADRSKLAD)=0;

   __property TFIBIntegerField * SkladPolTSKLAD = {read = get_SkladPolTSKLAD , write = set_SkladPolTSKLAD};
   virtual TFIBIntegerField * get_SkladPolTSKLAD(void)=0;
   virtual void set_SkladPolTSKLAD(TFIBIntegerField * SkladPolTSKLAD)=0;

   __property TFIBWideStringField * SkladPolGID_SSKLAD = {read = get_SkladPolGID_SSKLAD , write = set_SkladPolGID_SSKLAD};
   virtual TFIBWideStringField * get_SkladPolGID_SSKLAD(void)=0;
   virtual void set_SkladPolGID_SSKLAD(TFIBWideStringField * SkladPolGID_SSKLAD)=0;

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

   __property TFIBWideStringField * DocAllNAMESKLAD = {read = get_DocAllNAMESKLAD , write = set_DocAllNAMESKLAD};
   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void)=0;
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)=0;

   __property TFIBLargeIntField * DocIDPER = {read = get_DocIDPER , write = set_DocIDPER};
   virtual TFIBLargeIntField * get_DocIDPER(void)=0;
   virtual void set_DocIDPER(TFIBLargeIntField * DocIDPER)=0;

   __property TFIBLargeIntField * DocIDDOCPER = {read = get_DocIDDOCPER , write = set_DocIDDOCPER};
   virtual TFIBLargeIntField * get_DocIDDOCPER(void)=0;
   virtual void set_DocIDDOCPER(TFIBLargeIntField * DocIDDOCPER)=0;

   __property TFIBLargeIntField * DocIDSKLPOLPER = {read = get_DocIDSKLPOLPER , write = set_DocIDSKLPOLPER};
   virtual TFIBLargeIntField * get_DocIDSKLPOLPER(void)=0;
   virtual void set_DocIDSKLPOLPER(TFIBLargeIntField * DocIDSKLPOLPER)=0;

   __property TFIBWideStringField * DocPRIMPER = {read = get_DocPRIMPER , write = set_DocPRIMPER};
   virtual TFIBWideStringField * get_DocPRIMPER(void)=0;
   virtual void set_DocPRIMPER(TFIBWideStringField * DocPRIMPER)=0;

   __property TFIBWideStringField * DocGID_DPER = {read = get_DocGID_DPER , write = set_DocGID_DPER};
   virtual TFIBWideStringField * get_DocGID_DPER(void)=0;
   virtual void set_DocGID_DPER(TFIBWideStringField * DocGID_DPER)=0;

   __property TFIBLargeIntField * DocIDRTPRICE_DPER = {read = get_DocIDRTPRICE_DPER , write = set_DocIDRTPRICE_DPER};
   virtual TFIBLargeIntField * get_DocIDRTPRICE_DPER(void)=0;
   virtual void set_DocIDRTPRICE_DPER(TFIBLargeIntField * DocIDRTPRICE_DPER)=0;

   __property TFIBLargeIntField * DocIDBASE_DPER = {read = get_DocIDBASE_DPER , write = set_DocIDBASE_DPER};
   virtual TFIBLargeIntField * get_DocIDBASE_DPER(void)=0;
   virtual void set_DocIDBASE_DPER(TFIBLargeIntField * DocIDBASE_DPER)=0;

   __property TFIBWideStringField * DocNAMESKLAD = {read = get_DocNAMESKLAD , write = set_DocNAMESKLAD};
   virtual TFIBWideStringField * get_DocNAMESKLAD(void)=0;
   virtual void set_DocNAMESKLAD(TFIBWideStringField * DocNAMESKLAD)=0;

   __property TFIBLargeIntField * DocTIDPERT = {read = get_DocTIDPERT , write = set_DocTIDPERT};
   virtual TFIBLargeIntField * get_DocTIDPERT(void)=0;
   virtual void set_DocTIDPERT(TFIBLargeIntField * DocTIDPERT)=0;

   __property TFIBLargeIntField * DocTIDDOCPERT = {read = get_DocTIDDOCPERT , write = set_DocTIDDOCPERT};
   virtual TFIBLargeIntField * get_DocTIDDOCPERT(void)=0;
   virtual void set_DocTIDDOCPERT(TFIBLargeIntField * DocTIDDOCPERT)=0;

   __property TFIBLargeIntField * DocTIDNOMPERT = {read = get_DocTIDNOMPERT , write = set_DocTIDNOMPERT};
   virtual TFIBLargeIntField * get_DocTIDNOMPERT(void)=0;
   virtual void set_DocTIDNOMPERT(TFIBLargeIntField * DocTIDNOMPERT)=0;

   __property TFIBLargeIntField * DocTIDEDPERT = {read = get_DocTIDEDPERT , write = set_DocTIDEDPERT};
   virtual TFIBLargeIntField * get_DocTIDEDPERT(void)=0;
   virtual void set_DocTIDEDPERT(TFIBLargeIntField * DocTIDEDPERT)=0;

   __property TFIBWideStringField * DocTGID_DPERT = {read = get_DocTGID_DPERT , write = set_DocTGID_DPERT};
   virtual TFIBWideStringField * get_DocTGID_DPERT(void)=0;
   virtual void set_DocTGID_DPERT(TFIBWideStringField * DocTGID_DPERT)=0;

   __property TFIBLargeIntField * DocTIDBASE_DPERT = {read = get_DocTIDBASE_DPERT , write = set_DocTIDBASE_DPERT};
   virtual TFIBLargeIntField * get_DocTIDBASE_DPERT(void)=0;
   virtual void set_DocTIDBASE_DPERT(TFIBLargeIntField * DocTIDBASE_DPERT)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBSmallIntField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBSmallIntField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM)=0;

   __property TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC = {read = get_DocAllIDBUSINOP_GALLDOC , write = set_DocAllIDBUSINOP_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void)=0;
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBWideStringField * DocTARTNOM = {read = get_DocTARTNOM , write = set_DocTARTNOM};
   virtual TFIBWideStringField * get_DocTARTNOM(void)=0;
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)=0;

   __property TFIBWideStringField * DocTSHED = {read = get_DocTSHED , write = set_DocTSHED};
   virtual TFIBWideStringField * get_DocTSHED(void)=0;
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC = {read = get_DocAllPREFIKS_NUM_GALLDOC , write = set_DocAllPREFIKS_NUM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)=0;

   __property TFIBBCDField * DocTSEB_PRICE_DPERT = {read = get_DocTSEB_PRICE_DPERT , write = set_DocTSEB_PRICE_DPERT};
   virtual TFIBBCDField * get_DocTSEB_PRICE_DPERT(void)=0;
   virtual void set_DocTSEB_PRICE_DPERT(TFIBBCDField * DocTSEB_PRICE_DPERT)=0;

   __property TFIBBCDField * DocTSEB_SUM_DPERT = {read = get_DocTSEB_SUM_DPERT , write = set_DocTSEB_SUM_DPERT};
   virtual TFIBBCDField * get_DocTSEB_SUM_DPERT(void)=0;
   virtual void set_DocTSEB_SUM_DPERT(TFIBBCDField * DocTSEB_SUM_DPERT)=0;

   __property TFIBBCDField * DocTNAC_SUM_ED = {read = get_DocTNAC_SUM_ED , write = set_DocTNAC_SUM_ED};
   virtual TFIBBCDField * get_DocTNAC_SUM_ED(void)=0;
   virtual void set_DocTNAC_SUM_ED(TFIBBCDField * DocTNAC_SUM_ED)=0;

   __property TFIBBCDField * DocTNAC_SUM = {read = get_DocTNAC_SUM , write = set_DocTNAC_SUM};
   virtual TFIBBCDField * get_DocTNAC_SUM(void)=0;
   virtual void set_DocTNAC_SUM(TFIBBCDField * DocTNAC_SUM)=0;

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

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   __property bool SkladPolRozn = {read = get_SkladPolRozn , write = set_SkladPolRozn};
   virtual bool get_SkladPolRozn(void)=0;
   virtual void set_SkladPolRozn(bool SkladPolRozn)=0;

   __property bool SkladOtprRozn = {read = get_SkladOtprRozn , write = set_SkladOtprRozn};
   virtual bool get_SkladOtprRozn(void)=0;
   virtual void set_SkladOtprRozn(bool SkladOtprRozn)=0;

   __property bool NoOtrOstatok = {read = get_NoOtrOstatok , write = set_NoOtrOstatok};
   virtual bool get_NoOtrOstatok(void)=0;
   virtual void set_NoOtrOstatok(bool NoOtrOstatok)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 IdDoc)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual void CloseDoc(void)=0;
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocPer __uuidof(IDMDocPer)
#endif
