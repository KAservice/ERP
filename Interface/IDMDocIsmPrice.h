#ifndef UIDMDocIsmPriceH
#define UIDMDocIsmPriceH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocIsmPrice)) IDMDocIsmPrice : public IMainInterface
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

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * DocAll = {read = get_DocAll , write = set_DocAll};
   virtual TpFIBDataSet * get_DocAll(void)=0;
   virtual void set_DocAll(TpFIBDataSet * DocAll)=0;

   __property TpFIBDataSet * Doc = {read = get_Doc , write = set_Doc};
   virtual TpFIBDataSet * get_Doc(void)=0;
   virtual void set_Doc(TpFIBDataSet * Doc)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TFloatField * DocTOLDSUM = {read = get_DocTOLDSUM , write = set_DocTOLDSUM};
   virtual TFloatField * get_DocTOLDSUM(void)=0;
   virtual void set_DocTOLDSUM(TFloatField * DocTOLDSUM)=0;

   __property TFloatField * DocTNEWSUM = {read = get_DocTNEWSUM , write = set_DocTNEWSUM};
   virtual TFloatField * get_DocTNEWSUM(void)=0;
   virtual void set_DocTNEWSUM(TFloatField * DocTNEWSUM)=0;

   __property TFloatField * DocTSUMISM = {read = get_DocTSUMISM , write = set_DocTSUMISM};
   virtual TFloatField * get_DocTSUMISM(void)=0;
   virtual void set_DocTSUMISM(TFloatField * DocTSUMISM)=0;

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

   __property TFIBLargeIntField * DocID_DISMPRICE = {read = get_DocID_DISMPRICE , write = set_DocID_DISMPRICE};
   virtual TFIBLargeIntField * get_DocID_DISMPRICE(void)=0;
   virtual void set_DocID_DISMPRICE(TFIBLargeIntField * DocID_DISMPRICE)=0;

   __property TFIBWideStringField * DocGID_DISMPRICE = {read = get_DocGID_DISMPRICE , write = set_DocGID_DISMPRICE};
   virtual TFIBWideStringField * get_DocGID_DISMPRICE(void)=0;
   virtual void set_DocGID_DISMPRICE(TFIBWideStringField * DocGID_DISMPRICE)=0;

   __property TFIBLargeIntField * DocIDDOC_DISMPRICE = {read = get_DocIDDOC_DISMPRICE , write = set_DocIDDOC_DISMPRICE};
   virtual TFIBLargeIntField * get_DocIDDOC_DISMPRICE(void)=0;
   virtual void set_DocIDDOC_DISMPRICE(TFIBLargeIntField * DocIDDOC_DISMPRICE)=0;

   __property TFIBWideStringField * DocDESCR_DISMPRICE = {read = get_DocDESCR_DISMPRICE , write = set_DocDESCR_DISMPRICE};
   virtual TFIBWideStringField * get_DocDESCR_DISMPRICE(void)=0;
   virtual void set_DocDESCR_DISMPRICE(TFIBWideStringField * DocDESCR_DISMPRICE)=0;

   __property TFIBLargeIntField * DocIDNEWTPRICE_DISMPRICE = {read = get_DocIDNEWTPRICE_DISMPRICE , write = set_DocIDNEWTPRICE_DISMPRICE};
   virtual TFIBLargeIntField * get_DocIDNEWTPRICE_DISMPRICE(void)=0;
   virtual void set_DocIDNEWTPRICE_DISMPRICE(TFIBLargeIntField * DocIDNEWTPRICE_DISMPRICE)=0;

   __property TFIBLargeIntField * DocIDBASE_DISMPRICE = {read = get_DocIDBASE_DISMPRICE , write = set_DocIDBASE_DISMPRICE};
   virtual TFIBLargeIntField * get_DocIDBASE_DISMPRICE(void)=0;
   virtual void set_DocIDBASE_DISMPRICE(TFIBLargeIntField * DocIDBASE_DISMPRICE)=0;

   __property TFIBIntegerField * DocOPER_DISMPRICE = {read = get_DocOPER_DISMPRICE , write = set_DocOPER_DISMPRICE};
   virtual TFIBIntegerField * get_DocOPER_DISMPRICE(void)=0;
   virtual void set_DocOPER_DISMPRICE(TFIBIntegerField * DocOPER_DISMPRICE)=0;

   __property TFIBLargeIntField * DocIDINV_DISMPRICE = {read = get_DocIDINV_DISMPRICE , write = set_DocIDINV_DISMPRICE};
   virtual TFIBLargeIntField * get_DocIDINV_DISMPRICE(void)=0;
   virtual void set_DocIDINV_DISMPRICE(TFIBLargeIntField * DocIDINV_DISMPRICE)=0;

   __property TFIBWideStringField * DocNAME_SINV = {read = get_DocNAME_SINV , write = set_DocNAME_SINV};
   virtual TFIBWideStringField * get_DocNAME_SINV(void)=0;
   virtual void set_DocNAME_SINV(TFIBWideStringField * DocNAME_SINV)=0;

   __property TFIBLargeIntField * DocTID_DISMPRICET = {read = get_DocTID_DISMPRICET , write = set_DocTID_DISMPRICET};
   virtual TFIBLargeIntField * get_DocTID_DISMPRICET(void)=0;
   virtual void set_DocTID_DISMPRICET(TFIBLargeIntField * DocTID_DISMPRICET)=0;

   __property TFIBWideStringField * DocTGID_DISMPRICET = {read = get_DocTGID_DISMPRICET , write = set_DocTGID_DISMPRICET};
   virtual TFIBWideStringField * get_DocTGID_DISMPRICET(void)=0;
   virtual void set_DocTGID_DISMPRICET(TFIBWideStringField * DocTGID_DISMPRICET)=0;

   __property TFIBLargeIntField * DocTIDDOC_DISMPRICET = {read = get_DocTIDDOC_DISMPRICET , write = set_DocTIDDOC_DISMPRICET};
   virtual TFIBLargeIntField * get_DocTIDDOC_DISMPRICET(void)=0;
   virtual void set_DocTIDDOC_DISMPRICET(TFIBLargeIntField * DocTIDDOC_DISMPRICET)=0;

   __property TFIBLargeIntField * DocTIDNOM_DISMPRICET = {read = get_DocTIDNOM_DISMPRICET , write = set_DocTIDNOM_DISMPRICET};
   virtual TFIBLargeIntField * get_DocTIDNOM_DISMPRICET(void)=0;
   virtual void set_DocTIDNOM_DISMPRICET(TFIBLargeIntField * DocTIDNOM_DISMPRICET)=0;

   __property TFIBLargeIntField * DocTIDED_DISMPRICET = {read = get_DocTIDED_DISMPRICET , write = set_DocTIDED_DISMPRICET};
   virtual TFIBLargeIntField * get_DocTIDED_DISMPRICET(void)=0;
   virtual void set_DocTIDED_DISMPRICET(TFIBLargeIntField * DocTIDED_DISMPRICET)=0;

   __property TFIBBCDField * DocTKOL_DISMPRICET = {read = get_DocTKOL_DISMPRICET , write = set_DocTKOL_DISMPRICET};
   virtual TFIBBCDField * get_DocTKOL_DISMPRICET(void)=0;
   virtual void set_DocTKOL_DISMPRICET(TFIBBCDField * DocTKOL_DISMPRICET)=0;

   __property TFIBBCDField * DocTKF_DISMPRICET = {read = get_DocTKF_DISMPRICET , write = set_DocTKF_DISMPRICET};
   virtual TFIBBCDField * get_DocTKF_DISMPRICET(void)=0;
   virtual void set_DocTKF_DISMPRICET(TFIBBCDField * DocTKF_DISMPRICET)=0;

   __property TFIBBCDField * DocTOLDPRICE_DISMPRICET = {read = get_DocTOLDPRICE_DISMPRICET , write = set_DocTOLDPRICE_DISMPRICET};
   virtual TFIBBCDField * get_DocTOLDPRICE_DISMPRICET(void)=0;
   virtual void set_DocTOLDPRICE_DISMPRICET(TFIBBCDField * DocTOLDPRICE_DISMPRICET)=0;

   __property TFIBBCDField * DocTNEWPRICE_DISMPRICET = {read = get_DocTNEWPRICE_DISMPRICET , write = set_DocTNEWPRICE_DISMPRICET};
   virtual TFIBBCDField * get_DocTNEWPRICE_DISMPRICET(void)=0;
   virtual void set_DocTNEWPRICE_DISMPRICET(TFIBBCDField * DocTNEWPRICE_DISMPRICET)=0;

   __property TFIBLargeIntField * DocTIDBASE_DISMPRICET = {read = get_DocTIDBASE_DISMPRICET , write = set_DocTIDBASE_DISMPRICET};
   virtual TFIBLargeIntField * get_DocTIDBASE_DISMPRICET(void)=0;
   virtual void set_DocTIDBASE_DISMPRICET(TFIBLargeIntField * DocTIDBASE_DISMPRICET)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBIntegerField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBIntegerField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM)=0;

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

   __property TFIBBCDField * DocTSEB_PRICE_DISMPRICET = {read = get_DocTSEB_PRICE_DISMPRICET , write = set_DocTSEB_PRICE_DISMPRICET};
   virtual TFIBBCDField * get_DocTSEB_PRICE_DISMPRICET(void)=0;
   virtual void set_DocTSEB_PRICE_DISMPRICET(TFIBBCDField * DocTSEB_PRICE_DISMPRICET)=0;

   __property TFIBBCDField * DocTSEB_SUM_DISMPRICET = {read = get_DocTSEB_SUM_DISMPRICET , write = set_DocTSEB_SUM_DISMPRICET};
   virtual TFIBBCDField * get_DocTSEB_SUM_DISMPRICET(void)=0;
   virtual void set_DocTSEB_SUM_DISMPRICET(TFIBBCDField * DocTSEB_SUM_DISMPRICET)=0;

   __property TFIBBCDField * DocTNAC_SUM_ED = {read = get_DocTNAC_SUM_ED , write = set_DocTNAC_SUM_ED};
   virtual TFIBBCDField * get_DocTNAC_SUM_ED(void)=0;
   virtual void set_DocTNAC_SUM_ED(TFIBBCDField * DocTNAC_SUM_ED)=0;

   __property TFIBBCDField * DocTNAC_SUM = {read = get_DocTNAC_SUM , write = set_DocTNAC_SUM};
   virtual TFIBBCDField * get_DocTNAC_SUM(void)=0;
   virtual void set_DocTNAC_SUM(TFIBBCDField * DocTNAC_SUM)=0;

   __property TFIBBCDField * DocTNAC_NEW_DISMPRICET = {read = get_DocTNAC_NEW_DISMPRICET , write = set_DocTNAC_NEW_DISMPRICET};
   virtual TFIBBCDField * get_DocTNAC_NEW_DISMPRICET(void)=0;
   virtual void set_DocTNAC_NEW_DISMPRICET(TFIBBCDField * DocTNAC_NEW_DISMPRICET)=0;

   __property TFIBBCDField * DocTNAC_OLD_DISMPRICET = {read = get_DocTNAC_OLD_DISMPRICET , write = set_DocTNAC_OLD_DISMPRICET};
   virtual TFIBBCDField * get_DocTNAC_OLD_DISMPRICET(void)=0;
   virtual void set_DocTNAC_OLD_DISMPRICET(TFIBBCDField * DocTNAC_OLD_DISMPRICET)=0;

   __property TFIBWideStringField * DocTSHED = {read = get_DocTSHED , write = set_DocTSHED};
   virtual TFIBWideStringField * get_DocTSHED(void)=0;
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED)=0;

   __property TFIBWideStringField * DocTARTNOM = {read = get_DocTARTNOM , write = set_DocTARTNOM};
   virtual TFIBWideStringField * get_DocTARTNOM(void)=0;
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property bool NewElement = {read = get_NewElement , write = set_NewElement};
   virtual bool get_NewElement(void)=0;
   virtual void set_NewElement(bool NewElement)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property UnicodeString ProsmotrText = {read = get_ProsmotrText , write = set_ProsmotrText};
   virtual UnicodeString get_ProsmotrText(void)=0;
   virtual void set_ProsmotrText(UnicodeString ProsmotrText)=0;

   __property bool NoEdit = {read = get_NoEdit , write = set_NoEdit};
   virtual bool get_NoEdit(void)=0;
   virtual void set_NoEdit(bool NoEdit)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElementaMaster = {read = get_IdElementaMaster , write = set_IdElementaMaster};
   virtual __int64 get_IdElementaMaster(void)=0;
   virtual void set_IdElementaMaster(__int64 IdElementaMaster)=0;

   __property bool IsmPrice = {read = get_IsmPrice , write = set_IsmPrice};
   virtual bool get_IsmPrice(void)=0;
   virtual void set_IsmPrice(bool IsmPrice)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property bool AutoRaschet = {read = get_AutoRaschet , write = set_AutoRaschet};
   virtual bool get_AutoRaschet(void)=0;
   virtual void set_AutoRaschet(bool AutoRaschet)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 IdDoc)=0;
   virtual void ValidateProsmotr(void)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocIsmPrice __uuidof(IDMDocIsmPrice)
#endif
