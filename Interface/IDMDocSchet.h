#ifndef UIDMDocSchetH
#define UIDMDocSchetH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocSchet)) IDMDocSchet : public IMainInterface
{
public:
   __property TDataSource * DataSourceDocAll = {read = get_DataSourceDocAll , write = set_DataSourceDocAll};
   virtual TDataSource * get_DataSourceDocAll(void)=0;
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll)=0;

   __property TDataSource * DataSourceDoc = {read = get_DataSourceDoc , write = set_DataSourceDoc};
   virtual TDataSource * get_DataSourceDoc(void)=0;
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc)=0;

   __property TDataSource * DataSourceDocT = {read = get_DataSourceDocT , write = set_DataSourceDocT};
   virtual TDataSource * get_DataSourceDocT(void)=0;
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT)=0;

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

   __property TFIBBCDField * DocTKOLSCHT = {read = get_DocTKOLSCHT , write = set_DocTKOLSCHT};
   virtual TFIBBCDField * get_DocTKOLSCHT(void)=0;
   virtual void set_DocTKOLSCHT(TFIBBCDField * DocTKOLSCHT)=0;

   __property TFIBBCDField * DocTKFSCHT = {read = get_DocTKFSCHT , write = set_DocTKFSCHT};
   virtual TFIBBCDField * get_DocTKFSCHT(void)=0;
   virtual void set_DocTKFSCHT(TFIBBCDField * DocTKFSCHT)=0;

   __property TFIBBCDField * DocTPRICESCHT = {read = get_DocTPRICESCHT , write = set_DocTPRICESCHT};
   virtual TFIBBCDField * get_DocTPRICESCHT(void)=0;
   virtual void set_DocTPRICESCHT(TFIBBCDField * DocTPRICESCHT)=0;

   __property TFIBBCDField * DocTSUMSCHT = {read = get_DocTSUMSCHT , write = set_DocTSUMSCHT};
   virtual TFIBBCDField * get_DocTSUMSCHT(void)=0;
   virtual void set_DocTSUMSCHT(TFIBBCDField * DocTSUMSCHT)=0;

   __property TFIBIntegerField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBIntegerField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM)=0;

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

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

   __property TFIBBCDField * DocIDSCH = {read = get_DocIDSCH , write = set_DocIDSCH};
   virtual TFIBBCDField * get_DocIDSCH(void)=0;
   virtual void set_DocIDSCH(TFIBBCDField * DocIDSCH)=0;

   __property TFIBBCDField * DocIDDOCSCH = {read = get_DocIDDOCSCH , write = set_DocIDDOCSCH};
   virtual TFIBBCDField * get_DocIDDOCSCH(void)=0;
   virtual void set_DocIDDOCSCH(TFIBBCDField * DocIDDOCSCH)=0;

   __property TFIBBCDField * DocIDBSCHET_DSCH = {read = get_DocIDBSCHET_DSCH , write = set_DocIDBSCHET_DSCH};
   virtual TFIBBCDField * get_DocIDBSCHET_DSCH(void)=0;
   virtual void set_DocIDBSCHET_DSCH(TFIBBCDField * DocIDBSCHET_DSCH)=0;

   __property TFIBBCDField * DocIDTPRICESCH = {read = get_DocIDTPRICESCH , write = set_DocIDTPRICESCH};
   virtual TFIBBCDField * get_DocIDTPRICESCH(void)=0;
   virtual void set_DocIDTPRICESCH(TFIBBCDField * DocIDTPRICESCH)=0;

   __property TFIBBCDField * DocTIDSCHT = {read = get_DocTIDSCHT , write = set_DocTIDSCHT};
   virtual TFIBBCDField * get_DocTIDSCHT(void)=0;
   virtual void set_DocTIDSCHT(TFIBBCDField * DocTIDSCHT)=0;

   __property TFIBBCDField * DocTIDDOCSCHT = {read = get_DocTIDDOCSCHT , write = set_DocTIDDOCSCHT};
   virtual TFIBBCDField * get_DocTIDDOCSCHT(void)=0;
   virtual void set_DocTIDDOCSCHT(TFIBBCDField * DocTIDDOCSCHT)=0;

   __property TFIBBCDField * DocTIDNOMSCHT = {read = get_DocTIDNOMSCHT , write = set_DocTIDNOMSCHT};
   virtual TFIBBCDField * get_DocTIDNOMSCHT(void)=0;
   virtual void set_DocTIDNOMSCHT(TFIBBCDField * DocTIDNOMSCHT)=0;

   __property TFIBBCDField * DocTIDEDSCHT = {read = get_DocTIDEDSCHT , write = set_DocTIDEDSCHT};
   virtual TFIBBCDField * get_DocTIDEDSCHT(void)=0;
   virtual void set_DocTIDEDSCHT(TFIBBCDField * DocTIDEDSCHT)=0;

   __property TFIBBCDField * DocAllIDEXTDOC = {read = get_DocAllIDEXTDOC , write = set_DocAllIDEXTDOC};
   virtual TFIBBCDField * get_DocAllIDEXTDOC(void)=0;
   virtual void set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * DocIDBASE_DSCH = {read = get_DocIDBASE_DSCH , write = set_DocIDBASE_DSCH};
   virtual TFIBBCDField * get_DocIDBASE_DSCH(void)=0;
   virtual void set_DocIDBASE_DSCH(TFIBBCDField * DocIDBASE_DSCH)=0;

   __property TFIBBCDField * DocTIDBASE_DSCHT = {read = get_DocTIDBASE_DSCHT , write = set_DocTIDBASE_DSCHT};
   virtual TFIBBCDField * get_DocTIDBASE_DSCHT(void)=0;
   virtual void set_DocTIDBASE_DSCHT(TFIBBCDField * DocTIDBASE_DSCHT)=0;

   __property TFIBBCDField * DocAllIDBASE_GALLDOC = {read = get_DocAllIDBASE_GALLDOC , write = set_DocAllIDBASE_GALLDOC};
   virtual TFIBBCDField * get_DocAllIDBASE_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC)=0;

   __property TFIBIntegerField * DocTNDS_DSCHT = {read = get_DocTNDS_DSCHT , write = set_DocTNDS_DSCHT};
   virtual TFIBIntegerField * get_DocTNDS_DSCHT(void)=0;
   virtual void set_DocTNDS_DSCHT(TFIBIntegerField * DocTNDS_DSCHT)=0;

   __property TFIBBCDField * DocTSUMNDS_DSCHT = {read = get_DocTSUMNDS_DSCHT , write = set_DocTSUMNDS_DSCHT};
   virtual TFIBBCDField * get_DocTSUMNDS_DSCHT(void)=0;
   virtual void set_DocTSUMNDS_DSCHT(TFIBBCDField * DocTSUMNDS_DSCHT)=0;

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

   __property TFIBWideStringField * DocPRIMSCH = {read = get_DocPRIMSCH , write = set_DocPRIMSCH};
   virtual TFIBWideStringField * get_DocPRIMSCH(void)=0;
   virtual void set_DocPRIMSCH(TFIBWideStringField * DocPRIMSCH)=0;

   __property TFIBWideStringField * DocGID_DSCH = {read = get_DocGID_DSCH , write = set_DocGID_DSCH};
   virtual TFIBWideStringField * get_DocGID_DSCH(void)=0;
   virtual void set_DocGID_DSCH(TFIBWideStringField * DocGID_DSCH)=0;

   __property TFIBWideStringField * DocNAME_TPRICE = {read = get_DocNAME_TPRICE , write = set_DocNAME_TPRICE};
   virtual TFIBWideStringField * get_DocNAME_TPRICE(void)=0;
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)=0;

   __property TFIBWideStringField * DocNAMEBSCHET = {read = get_DocNAMEBSCHET , write = set_DocNAMEBSCHET};
   virtual TFIBWideStringField * get_DocNAMEBSCHET(void)=0;
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)=0;

   __property TFIBWideStringField * DocTGID_DSCHT = {read = get_DocTGID_DSCHT , write = set_DocTGID_DSCHT};
   virtual TFIBWideStringField * get_DocTGID_DSCHT(void)=0;
   virtual void set_DocTGID_DSCHT(TFIBWideStringField * DocTGID_DSCHT)=0;

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

   __property TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC = {read = get_DocAllPREFIKS_NUM_GALLDOC , write = set_DocAllPREFIKS_NUM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)=0;

   __property TFIBBCDField * DocTSUMSK_DSCHT = {read = get_DocTSUMSK_DSCHT , write = set_DocTSUMSK_DSCHT};
   virtual TFIBBCDField * get_DocTSUMSK_DSCHT(void)=0;
   virtual void set_DocTSUMSK_DSCHT(TFIBBCDField * DocTSUMSK_DSCHT)=0;

   __property TFIBBCDField * DocTPRSK_DSCHT = {read = get_DocTPRSK_DSCHT , write = set_DocTPRSK_DSCHT};
   virtual TFIBBCDField * get_DocTPRSK_DSCHT(void)=0;
   virtual void set_DocTPRSK_DSCHT(TFIBBCDField * DocTPRSK_DSCHT)=0;

   __property TFIBSmallIntField * DocTNO_SK_DSCHT = {read = get_DocTNO_SK_DSCHT , write = set_DocTNO_SK_DSCHT};
   virtual TFIBSmallIntField * get_DocTNO_SK_DSCHT(void)=0;
   virtual void set_DocTNO_SK_DSCHT(TFIBSmallIntField * DocTNO_SK_DSCHT)=0;

   __property TFIBBCDField * DocTPRSK_CARD_DSCHT = {read = get_DocTPRSK_CARD_DSCHT , write = set_DocTPRSK_CARD_DSCHT};
   virtual TFIBBCDField * get_DocTPRSK_CARD_DSCHT(void)=0;
   virtual void set_DocTPRSK_CARD_DSCHT(TFIBBCDField * DocTPRSK_CARD_DSCHT)=0;

   __property TFIBBCDField * DocTPRSK_AUTO_DSCHT = {read = get_DocTPRSK_AUTO_DSCHT , write = set_DocTPRSK_AUTO_DSCHT};
   virtual TFIBBCDField * get_DocTPRSK_AUTO_DSCHT(void)=0;
   virtual void set_DocTPRSK_AUTO_DSCHT(TFIBBCDField * DocTPRSK_AUTO_DSCHT)=0;

   __property TFIBBCDField * DocTPRSK_HAND_DSCHT = {read = get_DocTPRSK_HAND_DSCHT , write = set_DocTPRSK_HAND_DSCHT};
   virtual TFIBBCDField * get_DocTPRSK_HAND_DSCHT(void)=0;
   virtual void set_DocTPRSK_HAND_DSCHT(TFIBBCDField * DocTPRSK_HAND_DSCHT)=0;

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
   virtual void CloseDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocSchet __uuidof(IDMDocSchet)
#endif
