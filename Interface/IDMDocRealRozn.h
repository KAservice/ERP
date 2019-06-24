#ifndef UIDMDocRealRoznH
#define UIDMDocRealRoznH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocRealRozn)) IDMDocRealRozn : public IMainInterface
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

   __property TDataSource * DataSourcePay = {read = get_DataSourcePay , write = set_DataSourcePay};
   virtual TDataSource * get_DataSourcePay(void)=0;
   virtual void set_DataSourcePay(TDataSource * DataSourcePay)=0;

   __property TpFIBDataSet * DocAll = {read = get_DocAll , write = set_DocAll};
   virtual TpFIBDataSet * get_DocAll(void)=0;
   virtual void set_DocAll(TpFIBDataSet * DocAll)=0;

   __property TpFIBDataSet * Doc = {read = get_Doc , write = set_Doc};
   virtual TpFIBDataSet * get_Doc(void)=0;
   virtual void set_Doc(TpFIBDataSet * Doc)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

   __property TpFIBDataSet * Pay = {read = get_Pay , write = set_Pay};
   virtual TpFIBDataSet * get_Pay(void)=0;
   virtual void set_Pay(TpFIBDataSet * Pay)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TFIBBCDField * DocFIRSTSUM_DREALROZN = {read = get_DocFIRSTSUM_DREALROZN , write = set_DocFIRSTSUM_DREALROZN};
   virtual TFIBBCDField * get_DocFIRSTSUM_DREALROZN(void)=0;
   virtual void set_DocFIRSTSUM_DREALROZN(TFIBBCDField * DocFIRSTSUM_DREALROZN)=0;

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

   __property TFIBBCDField * DocTKOL_DREALROZNT = {read = get_DocTKOL_DREALROZNT , write = set_DocTKOL_DREALROZNT};
   virtual TFIBBCDField * get_DocTKOL_DREALROZNT(void)=0;
   virtual void set_DocTKOL_DREALROZNT(TFIBBCDField * DocTKOL_DREALROZNT)=0;

   __property TFIBBCDField * DocTKF_DREALROZNT = {read = get_DocTKF_DREALROZNT , write = set_DocTKF_DREALROZNT};
   virtual TFIBBCDField * get_DocTKF_DREALROZNT(void)=0;
   virtual void set_DocTKF_DREALROZNT(TFIBBCDField * DocTKF_DREALROZNT)=0;

   __property TFIBBCDField * DocTPRICE_DREALROZNT = {read = get_DocTPRICE_DREALROZNT , write = set_DocTPRICE_DREALROZNT};
   virtual TFIBBCDField * get_DocTPRICE_DREALROZNT(void)=0;
   virtual void set_DocTPRICE_DREALROZNT(TFIBBCDField * DocTPRICE_DREALROZNT)=0;

   __property TFIBBCDField * DocTSUM_DREALROZNT = {read = get_DocTSUM_DREALROZNT , write = set_DocTSUM_DREALROZNT};
   virtual TFIBBCDField * get_DocTSUM_DREALROZNT(void)=0;
   virtual void set_DocTSUM_DREALROZNT(TFIBBCDField * DocTSUM_DREALROZNT)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBDateField * PayDO_DREALROZN_PAY = {read = get_PayDO_DREALROZN_PAY , write = set_PayDO_DREALROZN_PAY};
   virtual TFIBDateField * get_PayDO_DREALROZN_PAY(void)=0;
   virtual void set_PayDO_DREALROZN_PAY(TFIBDateField * PayDO_DREALROZN_PAY)=0;

   __property TFIBBCDField * PaySUM_DREALROZN_PAY = {read = get_PaySUM_DREALROZN_PAY , write = set_PaySUM_DREALROZN_PAY};
   virtual TFIBBCDField * get_PaySUM_DREALROZN_PAY(void)=0;
   virtual void set_PaySUM_DREALROZN_PAY(TFIBBCDField * PaySUM_DREALROZN_PAY)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TIntegerField * PayRECNO = {read = get_PayRECNO , write = set_PayRECNO};
   virtual TIntegerField * get_PayRECNO(void)=0;
   virtual void set_PayRECNO(TIntegerField * PayRECNO)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TFIBBCDField * DocTPRICEFULL_DREALROZNT = {read = get_DocTPRICEFULL_DREALROZNT , write = set_DocTPRICEFULL_DREALROZNT};
   virtual TFIBBCDField * get_DocTPRICEFULL_DREALROZNT(void)=0;
   virtual void set_DocTPRICEFULL_DREALROZNT(TFIBBCDField * DocTPRICEFULL_DREALROZNT)=0;

   __property TFIBBCDField * DocTPRSK_DREALROZNT = {read = get_DocTPRSK_DREALROZNT , write = set_DocTPRSK_DREALROZNT};
   virtual TFIBBCDField * get_DocTPRSK_DREALROZNT(void)=0;
   virtual void set_DocTPRSK_DREALROZNT(TFIBBCDField * DocTPRSK_DREALROZNT)=0;

   __property TFIBBCDField * DocTSUMSK_DREALROZNT = {read = get_DocTSUMSK_DREALROZNT , write = set_DocTSUMSK_DREALROZNT};
   virtual TFIBBCDField * get_DocTSUMSK_DREALROZNT(void)=0;
   virtual void set_DocTSUMSK_DREALROZNT(TFIBBCDField * DocTSUMSK_DREALROZNT)=0;

   __property TFIBBCDField * DocTPRNAD_DREALROZNT = {read = get_DocTPRNAD_DREALROZNT , write = set_DocTPRNAD_DREALROZNT};
   virtual TFIBBCDField * get_DocTPRNAD_DREALROZNT(void)=0;
   virtual void set_DocTPRNAD_DREALROZNT(TFIBBCDField * DocTPRNAD_DREALROZNT)=0;

   __property TFIBBCDField * DocTSUMNAD_DREALROZNT = {read = get_DocTSUMNAD_DREALROZNT , write = set_DocTSUMNAD_DREALROZNT};
   virtual TFIBBCDField * get_DocTSUMNAD_DREALROZNT(void)=0;
   virtual void set_DocTSUMNAD_DREALROZNT(TFIBBCDField * DocTSUMNAD_DREALROZNT)=0;

   __property TFIBIntegerField * DocTNDS_DREALROZNT = {read = get_DocTNDS_DREALROZNT , write = set_DocTNDS_DREALROZNT};
   virtual TFIBIntegerField * get_DocTNDS_DREALROZNT(void)=0;
   virtual void set_DocTNDS_DREALROZNT(TFIBIntegerField * DocTNDS_DREALROZNT)=0;

   __property TFIBBCDField * DocTSUMNDS_DREALROZNT = {read = get_DocTSUMNDS_DREALROZNT , write = set_DocTSUMNDS_DREALROZNT};
   virtual TFIBBCDField * get_DocTSUMNDS_DREALROZNT(void)=0;
   virtual void set_DocTSUMNDS_DREALROZNT(TFIBBCDField * DocTSUMNDS_DREALROZNT)=0;

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

   __property TFIBWideStringField * DocAllNAME_SDOG = {read = get_DocAllNAME_SDOG , write = set_DocAllNAME_SDOG};
   virtual TFIBWideStringField * get_DocAllNAME_SDOG(void)=0;
   virtual void set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBLargeIntField * DocID_DREALROZN = {read = get_DocID_DREALROZN , write = set_DocID_DREALROZN};
   virtual TFIBLargeIntField * get_DocID_DREALROZN(void)=0;
   virtual void set_DocID_DREALROZN(TFIBLargeIntField * DocID_DREALROZN)=0;

   __property TFIBLargeIntField * DocIDDOC_DREALROZN = {read = get_DocIDDOC_DREALROZN , write = set_DocIDDOC_DREALROZN};
   virtual TFIBLargeIntField * get_DocIDDOC_DREALROZN(void)=0;
   virtual void set_DocIDDOC_DREALROZN(TFIBLargeIntField * DocIDDOC_DREALROZN)=0;

   __property TFIBWideStringField * DocGID_DREALROZN = {read = get_DocGID_DREALROZN , write = set_DocGID_DREALROZN};
   virtual TFIBWideStringField * get_DocGID_DREALROZN(void)=0;
   virtual void set_DocGID_DREALROZN(TFIBWideStringField * DocGID_DREALROZN)=0;

   __property TFIBLargeIntField * DocIDTPRICE_DREALROZN = {read = get_DocIDTPRICE_DREALROZN , write = set_DocIDTPRICE_DREALROZN};
   virtual TFIBLargeIntField * get_DocIDTPRICE_DREALROZN(void)=0;
   virtual void set_DocIDTPRICE_DREALROZN(TFIBLargeIntField * DocIDTPRICE_DREALROZN)=0;

   __property TFIBWideStringField * DocPRIM_DREALROZN = {read = get_DocPRIM_DREALROZN , write = set_DocPRIM_DREALROZN};
   virtual TFIBWideStringField * get_DocPRIM_DREALROZN(void)=0;
   virtual void set_DocPRIM_DREALROZN(TFIBWideStringField * DocPRIM_DREALROZN)=0;

   __property TFIBLargeIntField * DocIDKKM_DREALROZN = {read = get_DocIDKKM_DREALROZN , write = set_DocIDKKM_DREALROZN};
   virtual TFIBLargeIntField * get_DocIDKKM_DREALROZN(void)=0;
   virtual void set_DocIDKKM_DREALROZN(TFIBLargeIntField * DocIDKKM_DREALROZN)=0;

   __property TFIBLargeIntField * DocIDDCARD_DREALROZN = {read = get_DocIDDCARD_DREALROZN , write = set_DocIDDCARD_DREALROZN};
   virtual TFIBLargeIntField * get_DocIDDCARD_DREALROZN(void)=0;
   virtual void set_DocIDDCARD_DREALROZN(TFIBLargeIntField * DocIDDCARD_DREALROZN)=0;

   __property TFIBLargeIntField * DocIDBASE_DREALROZN = {read = get_DocIDBASE_DREALROZN , write = set_DocIDBASE_DREALROZN};
   virtual TFIBLargeIntField * get_DocIDBASE_DREALROZN(void)=0;
   virtual void set_DocIDBASE_DREALROZN(TFIBLargeIntField * DocIDBASE_DREALROZN)=0;

   __property TFIBWideStringField * DocNAME_TPRICE = {read = get_DocNAME_TPRICE , write = set_DocNAME_TPRICE};
   virtual TFIBWideStringField * get_DocNAME_TPRICE(void)=0;
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)=0;

   __property TFIBWideStringField * DocNAMEKKM = {read = get_DocNAMEKKM , write = set_DocNAMEKKM};
   virtual TFIBWideStringField * get_DocNAMEKKM(void)=0;
   virtual void set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM)=0;

   __property TFIBLargeIntField * DocTID_DREALROZNT = {read = get_DocTID_DREALROZNT , write = set_DocTID_DREALROZNT};
   virtual TFIBLargeIntField * get_DocTID_DREALROZNT(void)=0;
   virtual void set_DocTID_DREALROZNT(TFIBLargeIntField * DocTID_DREALROZNT)=0;

   __property TFIBLargeIntField * DocTIDDOC_DREALROZNT = {read = get_DocTIDDOC_DREALROZNT , write = set_DocTIDDOC_DREALROZNT};
   virtual TFIBLargeIntField * get_DocTIDDOC_DREALROZNT(void)=0;
   virtual void set_DocTIDDOC_DREALROZNT(TFIBLargeIntField * DocTIDDOC_DREALROZNT)=0;

   __property TFIBWideStringField * DocTGID_DREALROZNT = {read = get_DocTGID_DREALROZNT , write = set_DocTGID_DREALROZNT};
   virtual TFIBWideStringField * get_DocTGID_DREALROZNT(void)=0;
   virtual void set_DocTGID_DREALROZNT(TFIBWideStringField * DocTGID_DREALROZNT)=0;

   __property TFIBLargeIntField * DocTIDNOM_DREALROZNT = {read = get_DocTIDNOM_DREALROZNT , write = set_DocTIDNOM_DREALROZNT};
   virtual TFIBLargeIntField * get_DocTIDNOM_DREALROZNT(void)=0;
   virtual void set_DocTIDNOM_DREALROZNT(TFIBLargeIntField * DocTIDNOM_DREALROZNT)=0;

   __property TFIBLargeIntField * DocTIDED_DREALROZNT = {read = get_DocTIDED_DREALROZNT , write = set_DocTIDED_DREALROZNT};
   virtual TFIBLargeIntField * get_DocTIDED_DREALROZNT(void)=0;
   virtual void set_DocTIDED_DREALROZNT(TFIBLargeIntField * DocTIDED_DREALROZNT)=0;

   __property TFIBLargeIntField * DocTIDBASE_DREALROZNT = {read = get_DocTIDBASE_DREALROZNT , write = set_DocTIDBASE_DREALROZNT};
   virtual TFIBLargeIntField * get_DocTIDBASE_DREALROZNT(void)=0;
   virtual void set_DocTIDBASE_DREALROZNT(TFIBLargeIntField * DocTIDBASE_DREALROZNT)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBSmallIntField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBSmallIntField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM)=0;

   __property TFIBLargeIntField * PayID_DREALROZN_PAY = {read = get_PayID_DREALROZN_PAY , write = set_PayID_DREALROZN_PAY};
   virtual TFIBLargeIntField * get_PayID_DREALROZN_PAY(void)=0;
   virtual void set_PayID_DREALROZN_PAY(TFIBLargeIntField * PayID_DREALROZN_PAY)=0;

   __property TFIBLargeIntField * PayIDDOC_DREALROZN_PAY = {read = get_PayIDDOC_DREALROZN_PAY , write = set_PayIDDOC_DREALROZN_PAY};
   virtual TFIBLargeIntField * get_PayIDDOC_DREALROZN_PAY(void)=0;
   virtual void set_PayIDDOC_DREALROZN_PAY(TFIBLargeIntField * PayIDDOC_DREALROZN_PAY)=0;

   __property TFIBWideStringField * PayGID_DREALROZN_PAY = {read = get_PayGID_DREALROZN_PAY , write = set_PayGID_DREALROZN_PAY};
   virtual TFIBWideStringField * get_PayGID_DREALROZN_PAY(void)=0;
   virtual void set_PayGID_DREALROZN_PAY(TFIBWideStringField * PayGID_DREALROZN_PAY)=0;

   __property TFIBLargeIntField * PayIDBASE_DREALROZN_PAY = {read = get_PayIDBASE_DREALROZN_PAY , write = set_PayIDBASE_DREALROZN_PAY};
   virtual TFIBLargeIntField * get_PayIDBASE_DREALROZN_PAY(void)=0;
   virtual void set_PayIDBASE_DREALROZN_PAY(TFIBLargeIntField * PayIDBASE_DREALROZN_PAY)=0;

   __property TFIBWideStringField * DocAllTDOC = {read = get_DocAllTDOC , write = set_DocAllTDOC};
   virtual TFIBWideStringField * get_DocAllTDOC(void)=0;
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)=0;

   __property TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC = {read = get_DocAllIDBUSINOP_GALLDOC , write = set_DocAllIDBUSINOP_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void)=0;
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC = {read = get_DocAllPREFIKS_NUM_GALLDOC , write = set_DocAllPREFIKS_NUM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)=0;

   __property TFIBBCDField * DocTPRSK_CARD_DREALROZNT = {read = get_DocTPRSK_CARD_DREALROZNT , write = set_DocTPRSK_CARD_DREALROZNT};
   virtual TFIBBCDField * get_DocTPRSK_CARD_DREALROZNT(void)=0;
   virtual void set_DocTPRSK_CARD_DREALROZNT(TFIBBCDField * DocTPRSK_CARD_DREALROZNT)=0;

   __property TFIBBCDField * DocTPRSK_AUTO_DREALROZNT = {read = get_DocTPRSK_AUTO_DREALROZNT , write = set_DocTPRSK_AUTO_DREALROZNT};
   virtual TFIBBCDField * get_DocTPRSK_AUTO_DREALROZNT(void)=0;
   virtual void set_DocTPRSK_AUTO_DREALROZNT(TFIBBCDField * DocTPRSK_AUTO_DREALROZNT)=0;

   __property TFIBBCDField * DocTPRSK_HAND_DREALROZNT = {read = get_DocTPRSK_HAND_DREALROZNT , write = set_DocTPRSK_HAND_DREALROZNT};
   virtual TFIBBCDField * get_DocTPRSK_HAND_DREALROZNT(void)=0;
   virtual void set_DocTPRSK_HAND_DREALROZNT(TFIBBCDField * DocTPRSK_HAND_DREALROZNT)=0;

   __property TFIBSmallIntField * DocTNO_SK_DREALROZNT = {read = get_DocTNO_SK_DREALROZNT , write = set_DocTNO_SK_DREALROZNT};
   virtual TFIBSmallIntField * get_DocTNO_SK_DREALROZNT(void)=0;
   virtual void set_DocTNO_SK_DREALROZNT(TFIBSmallIntField * DocTNO_SK_DREALROZNT)=0;

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

   __property bool NoEdit = {read = get_NoEdit , write = set_NoEdit};
   virtual bool get_NoEdit(void)=0;
   virtual void set_NoEdit(bool NoEdit)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property bool AutoRaschet = {read = get_AutoRaschet , write = set_AutoRaschet};
   virtual bool get_AutoRaschet(void)=0;
   virtual void set_AutoRaschet(bool AutoRaschet)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   __property bool SkladRozn = {read = get_SkladRozn , write = set_SkladRozn};
   virtual bool get_SkladRozn(void)=0;
   virtual void set_SkladRozn(bool SkladRozn)=0;

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
   virtual void CloseDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocRealRozn __uuidof(IDMDocRealRozn)
#endif
