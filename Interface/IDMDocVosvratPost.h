#ifndef UIDMDocVosvratPostH
#define UIDMDocVosvratPostH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocVosvratPost)) IDMDocVosvratPost : public IMainInterface
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

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

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

   __property TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC = {read = get_DocAllIDBUSINOP_GALLDOC , write = set_DocAllIDBUSINOP_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void)=0;
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)=0;

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

   __property TFIBWideStringField * DocAllTDOC_OSN = {read = get_DocAllTDOC_OSN , write = set_DocAllTDOC_OSN};
   virtual TFIBWideStringField * get_DocAllTDOC_OSN(void)=0;
   virtual void set_DocAllTDOC_OSN(TFIBWideStringField * DocAllTDOC_OSN)=0;

   __property TFIBIntegerField * DocAllNUMDOC_OSN = {read = get_DocAllNUMDOC_OSN , write = set_DocAllNUMDOC_OSN};
   virtual TFIBIntegerField * get_DocAllNUMDOC_OSN(void)=0;
   virtual void set_DocAllNUMDOC_OSN(TFIBIntegerField * DocAllNUMDOC_OSN)=0;

   __property TFIBDateTimeField * DocAllPOSDOC_OSN = {read = get_DocAllPOSDOC_OSN , write = set_DocAllPOSDOC_OSN};
   virtual TFIBDateTimeField * get_DocAllPOSDOC_OSN(void)=0;
   virtual void set_DocAllPOSDOC_OSN(TFIBDateTimeField * DocAllPOSDOC_OSN)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBLargeIntField * DocIDVPO = {read = get_DocIDVPO , write = set_DocIDVPO};
   virtual TFIBLargeIntField * get_DocIDVPO(void)=0;
   virtual void set_DocIDVPO(TFIBLargeIntField * DocIDVPO)=0;

   __property TFIBLargeIntField * DocIDDOCVPO = {read = get_DocIDDOCVPO , write = set_DocIDDOCVPO};
   virtual TFIBLargeIntField * get_DocIDDOCVPO(void)=0;
   virtual void set_DocIDDOCVPO(TFIBLargeIntField * DocIDDOCVPO)=0;

   __property TFIBWideStringField * DocPRIMVPO = {read = get_DocPRIMVPO , write = set_DocPRIMVPO};
   virtual TFIBWideStringField * get_DocPRIMVPO(void)=0;
   virtual void set_DocPRIMVPO(TFIBWideStringField * DocPRIMVPO)=0;

   __property TFIBWideStringField * DocGID_DVPO = {read = get_DocGID_DVPO , write = set_DocGID_DVPO};
   virtual TFIBWideStringField * get_DocGID_DVPO(void)=0;
   virtual void set_DocGID_DVPO(TFIBWideStringField * DocGID_DVPO)=0;

   __property TFIBLargeIntField * DocIDTPRICE_DVPO = {read = get_DocIDTPRICE_DVPO , write = set_DocIDTPRICE_DVPO};
   virtual TFIBLargeIntField * get_DocIDTPRICE_DVPO(void)=0;
   virtual void set_DocIDTPRICE_DVPO(TFIBLargeIntField * DocIDTPRICE_DVPO)=0;

   __property TFIBLargeIntField * DocIDBASE_DVPO = {read = get_DocIDBASE_DVPO , write = set_DocIDBASE_DVPO};
   virtual TFIBLargeIntField * get_DocIDBASE_DVPO(void)=0;
   virtual void set_DocIDBASE_DVPO(TFIBLargeIntField * DocIDBASE_DVPO)=0;

   __property TFIBLargeIntField * DocIDRTPRICE_DVPO = {read = get_DocIDRTPRICE_DVPO , write = set_DocIDRTPRICE_DVPO};
   virtual TFIBLargeIntField * get_DocIDRTPRICE_DVPO(void)=0;
   virtual void set_DocIDRTPRICE_DVPO(TFIBLargeIntField * DocIDRTPRICE_DVPO)=0;

   __property TFIBIntegerField * DocOPER_DVPO = {read = get_DocOPER_DVPO , write = set_DocOPER_DVPO};
   virtual TFIBIntegerField * get_DocOPER_DVPO(void)=0;
   virtual void set_DocOPER_DVPO(TFIBIntegerField * DocOPER_DVPO)=0;

   __property TFIBWideStringField * DocNUMDOCPOST_DVPO = {read = get_DocNUMDOCPOST_DVPO , write = set_DocNUMDOCPOST_DVPO};
   virtual TFIBWideStringField * get_DocNUMDOCPOST_DVPO(void)=0;
   virtual void set_DocNUMDOCPOST_DVPO(TFIBWideStringField * DocNUMDOCPOST_DVPO)=0;

   __property TFIBDateTimeField * DocPOSDOCPOST_DVPO = {read = get_DocPOSDOCPOST_DVPO , write = set_DocPOSDOCPOST_DVPO};
   virtual TFIBDateTimeField * get_DocPOSDOCPOST_DVPO(void)=0;
   virtual void set_DocPOSDOCPOST_DVPO(TFIBDateTimeField * DocPOSDOCPOST_DVPO)=0;

   __property TFIBWideStringField * DocNAME_TPRICE = {read = get_DocNAME_TPRICE , write = set_DocNAME_TPRICE};
   virtual TFIBWideStringField * get_DocNAME_TPRICE(void)=0;
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)=0;

   __property TFIBLargeIntField * DocTIDVPOT = {read = get_DocTIDVPOT , write = set_DocTIDVPOT};
   virtual TFIBLargeIntField * get_DocTIDVPOT(void)=0;
   virtual void set_DocTIDVPOT(TFIBLargeIntField * DocTIDVPOT)=0;

   __property TFIBLargeIntField * DocTIDDOCVPOT = {read = get_DocTIDDOCVPOT , write = set_DocTIDDOCVPOT};
   virtual TFIBLargeIntField * get_DocTIDDOCVPOT(void)=0;
   virtual void set_DocTIDDOCVPOT(TFIBLargeIntField * DocTIDDOCVPOT)=0;

   __property TFIBLargeIntField * DocTIDNOMVPOT = {read = get_DocTIDNOMVPOT , write = set_DocTIDNOMVPOT};
   virtual TFIBLargeIntField * get_DocTIDNOMVPOT(void)=0;
   virtual void set_DocTIDNOMVPOT(TFIBLargeIntField * DocTIDNOMVPOT)=0;

   __property TFIBLargeIntField * DocTIDEDVPOT = {read = get_DocTIDEDVPOT , write = set_DocTIDEDVPOT};
   virtual TFIBLargeIntField * get_DocTIDEDVPOT(void)=0;
   virtual void set_DocTIDEDVPOT(TFIBLargeIntField * DocTIDEDVPOT)=0;

   __property TFIBBCDField * DocTKOLVPOT = {read = get_DocTKOLVPOT , write = set_DocTKOLVPOT};
   virtual TFIBBCDField * get_DocTKOLVPOT(void)=0;
   virtual void set_DocTKOLVPOT(TFIBBCDField * DocTKOLVPOT)=0;

   __property TFIBBCDField * DocTKFVPOT = {read = get_DocTKFVPOT , write = set_DocTKFVPOT};
   virtual TFIBBCDField * get_DocTKFVPOT(void)=0;
   virtual void set_DocTKFVPOT(TFIBBCDField * DocTKFVPOT)=0;

   __property TFIBBCDField * DocTPRICEVPOT = {read = get_DocTPRICEVPOT , write = set_DocTPRICEVPOT};
   virtual TFIBBCDField * get_DocTPRICEVPOT(void)=0;
   virtual void set_DocTPRICEVPOT(TFIBBCDField * DocTPRICEVPOT)=0;

   __property TFIBBCDField * DocTSUMVPOT = {read = get_DocTSUMVPOT , write = set_DocTSUMVPOT};
   virtual TFIBBCDField * get_DocTSUMVPOT(void)=0;
   virtual void set_DocTSUMVPOT(TFIBBCDField * DocTSUMVPOT)=0;

   __property TFIBWideStringField * DocTGID_DVPOT = {read = get_DocTGID_DVPOT , write = set_DocTGID_DVPOT};
   virtual TFIBWideStringField * get_DocTGID_DVPOT(void)=0;
   virtual void set_DocTGID_DVPOT(TFIBWideStringField * DocTGID_DVPOT)=0;

   __property TFIBLargeIntField * DocTIDBASE_DVPOT = {read = get_DocTIDBASE_DVPOT , write = set_DocTIDBASE_DVPOT};
   virtual TFIBLargeIntField * get_DocTIDBASE_DVPOT(void)=0;
   virtual void set_DocTIDBASE_DVPOT(TFIBLargeIntField * DocTIDBASE_DVPOT)=0;

   __property TFIBBCDField * DocTRPRICE_DVPOT = {read = get_DocTRPRICE_DVPOT , write = set_DocTRPRICE_DVPOT};
   virtual TFIBBCDField * get_DocTRPRICE_DVPOT(void)=0;
   virtual void set_DocTRPRICE_DVPOT(TFIBBCDField * DocTRPRICE_DVPOT)=0;

   __property TFIBBCDField * DocTRSUM_DVPOT = {read = get_DocTRSUM_DVPOT , write = set_DocTRSUM_DVPOT};
   virtual TFIBBCDField * get_DocTRSUM_DVPOT(void)=0;
   virtual void set_DocTRSUM_DVPOT(TFIBBCDField * DocTRSUM_DVPOT)=0;

   __property TFIBIntegerField * DocTNDS_DVPOT = {read = get_DocTNDS_DVPOT , write = set_DocTNDS_DVPOT};
   virtual TFIBIntegerField * get_DocTNDS_DVPOT(void)=0;
   virtual void set_DocTNDS_DVPOT(TFIBIntegerField * DocTNDS_DVPOT)=0;

   __property TFIBBCDField * DocTSUMNDS_DVPOT = {read = get_DocTSUMNDS_DVPOT , write = set_DocTSUMNDS_DVPOT};
   virtual TFIBBCDField * get_DocTSUMNDS_DVPOT(void)=0;
   virtual void set_DocTSUMNDS_DVPOT(TFIBBCDField * DocTSUMNDS_DVPOT)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBSmallIntField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBSmallIntField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM)=0;

   __property TFIBLargeIntField * DocIDGRPOL_DVPO = {read = get_DocIDGRPOL_DVPO , write = set_DocIDGRPOL_DVPO};
   virtual TFIBLargeIntField * get_DocIDGRPOL_DVPO(void)=0;
   virtual void set_DocIDGRPOL_DVPO(TFIBLargeIntField * DocIDGRPOL_DVPO)=0;

   __property TFIBLargeIntField * DocIDBSCHET_DVPO = {read = get_DocIDBSCHET_DVPO , write = set_DocIDBSCHET_DVPO};
   virtual TFIBLargeIntField * get_DocIDBSCHET_DVPO(void)=0;
   virtual void set_DocIDBSCHET_DVPO(TFIBLargeIntField * DocIDBSCHET_DVPO)=0;

   __property TFIBLargeIntField * DocIDRSCHETKLIENT_DVPO = {read = get_DocIDRSCHETKLIENT_DVPO , write = set_DocIDRSCHETKLIENT_DVPO};
   virtual TFIBLargeIntField * get_DocIDRSCHETKLIENT_DVPO(void)=0;
   virtual void set_DocIDRSCHETKLIENT_DVPO(TFIBLargeIntField * DocIDRSCHETKLIENT_DVPO)=0;

   __property TFIBLargeIntField * DocIDRSCHETGRPOL_DVPO = {read = get_DocIDRSCHETGRPOL_DVPO , write = set_DocIDRSCHETGRPOL_DVPO};
   virtual TFIBLargeIntField * get_DocIDRSCHETGRPOL_DVPO(void)=0;
   virtual void set_DocIDRSCHETGRPOL_DVPO(TFIBLargeIntField * DocIDRSCHETGRPOL_DVPO)=0;

   __property TFIBWideStringField * DocNAMEKLIENT = {read = get_DocNAMEKLIENT , write = set_DocNAMEKLIENT};
   virtual TFIBWideStringField * get_DocNAMEKLIENT(void)=0;
   virtual void set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT)=0;

   __property TFIBWideStringField * DocNAMEBSCHET = {read = get_DocNAMEBSCHET , write = set_DocNAMEBSCHET};
   virtual TFIBWideStringField * get_DocNAMEBSCHET(void)=0;
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)=0;

   __property TFIBWideStringField * DocNAME_RSCHET_KLIENT = {read = get_DocNAME_RSCHET_KLIENT , write = set_DocNAME_RSCHET_KLIENT};
   virtual TFIBWideStringField * get_DocNAME_RSCHET_KLIENT(void)=0;
   virtual void set_DocNAME_RSCHET_KLIENT(TFIBWideStringField * DocNAME_RSCHET_KLIENT)=0;

   __property TFIBWideStringField * DocNAME_RSCHET_GRPOL = {read = get_DocNAME_RSCHET_GRPOL , write = set_DocNAME_RSCHET_GRPOL};
   virtual TFIBWideStringField * get_DocNAME_RSCHET_GRPOL(void)=0;
   virtual void set_DocNAME_RSCHET_GRPOL(TFIBWideStringField * DocNAME_RSCHET_GRPOL)=0;

   __property TFIBWideStringField * DocTARTNOM = {read = get_DocTARTNOM , write = set_DocTARTNOM};
   virtual TFIBWideStringField * get_DocTARTNOM(void)=0;
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBWideStringField * DocTSHED = {read = get_DocTSHED , write = set_DocTSHED};
   virtual TFIBWideStringField * get_DocTSHED(void)=0;
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED)=0;

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
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocVosvratPost __uuidof(IDMDocVosvratPost)
#endif
