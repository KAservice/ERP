#ifndef UIDMDocVosvratPokH
#define UIDMDocVosvratPokH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocVosvratPok)) IDMDocVosvratPok : public IMainInterface
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

   __property TFIBWideStringField * DocAllNAME_SDOG = {read = get_DocAllNAME_SDOG , write = set_DocAllNAME_SDOG};
   virtual TFIBWideStringField * get_DocAllNAME_SDOG(void)=0;
   virtual void set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBLargeIntField * DocID_DVPOK = {read = get_DocID_DVPOK , write = set_DocID_DVPOK};
   virtual TFIBLargeIntField * get_DocID_DVPOK(void)=0;
   virtual void set_DocID_DVPOK(TFIBLargeIntField * DocID_DVPOK)=0;

   __property TFIBWideStringField * DocGID_DVPOK = {read = get_DocGID_DVPOK , write = set_DocGID_DVPOK};
   virtual TFIBWideStringField * get_DocGID_DVPOK(void)=0;
   virtual void set_DocGID_DVPOK(TFIBWideStringField * DocGID_DVPOK)=0;

   __property TFIBLargeIntField * DocIDDOC_DVPOK = {read = get_DocIDDOC_DVPOK , write = set_DocIDDOC_DVPOK};
   virtual TFIBLargeIntField * get_DocIDDOC_DVPOK(void)=0;
   virtual void set_DocIDDOC_DVPOK(TFIBLargeIntField * DocIDDOC_DVPOK)=0;

   __property TFIBLargeIntField * DocIDTPRICE_DVPOK = {read = get_DocIDTPRICE_DVPOK , write = set_DocIDTPRICE_DVPOK};
   virtual TFIBLargeIntField * get_DocIDTPRICE_DVPOK(void)=0;
   virtual void set_DocIDTPRICE_DVPOK(TFIBLargeIntField * DocIDTPRICE_DVPOK)=0;

   __property TFIBLargeIntField * DocIDRTPRICE_DVPOK = {read = get_DocIDRTPRICE_DVPOK , write = set_DocIDRTPRICE_DVPOK};
   virtual TFIBLargeIntField * get_DocIDRTPRICE_DVPOK(void)=0;
   virtual void set_DocIDRTPRICE_DVPOK(TFIBLargeIntField * DocIDRTPRICE_DVPOK)=0;

   __property TFIBWideStringField * DocDESCR_DVPOK = {read = get_DocDESCR_DVPOK , write = set_DocDESCR_DVPOK};
   virtual TFIBWideStringField * get_DocDESCR_DVPOK(void)=0;
   virtual void set_DocDESCR_DVPOK(TFIBWideStringField * DocDESCR_DVPOK)=0;

   __property TFIBIntegerField * DocOPER_DVPOK = {read = get_DocOPER_DVPOK , write = set_DocOPER_DVPOK};
   virtual TFIBIntegerField * get_DocOPER_DVPOK(void)=0;
   virtual void set_DocOPER_DVPOK(TFIBIntegerField * DocOPER_DVPOK)=0;

   __property TFIBBCDField * DocSUM_DVPOK = {read = get_DocSUM_DVPOK , write = set_DocSUM_DVPOK};
   virtual TFIBBCDField * get_DocSUM_DVPOK(void)=0;
   virtual void set_DocSUM_DVPOK(TFIBBCDField * DocSUM_DVPOK)=0;

   __property TFIBLargeIntField * DocIDBASE_DVPOK = {read = get_DocIDBASE_DVPOK , write = set_DocIDBASE_DVPOK};
   virtual TFIBLargeIntField * get_DocIDBASE_DVPOK(void)=0;
   virtual void set_DocIDBASE_DVPOK(TFIBLargeIntField * DocIDBASE_DVPOK)=0;

   __property TFIBLargeIntField * DocTID_DVPOKT = {read = get_DocTID_DVPOKT , write = set_DocTID_DVPOKT};
   virtual TFIBLargeIntField * get_DocTID_DVPOKT(void)=0;
   virtual void set_DocTID_DVPOKT(TFIBLargeIntField * DocTID_DVPOKT)=0;

   __property TFIBWideStringField * DocTGID_DVPOKT = {read = get_DocTGID_DVPOKT , write = set_DocTGID_DVPOKT};
   virtual TFIBWideStringField * get_DocTGID_DVPOKT(void)=0;
   virtual void set_DocTGID_DVPOKT(TFIBWideStringField * DocTGID_DVPOKT)=0;

   __property TFIBLargeIntField * DocTIDDOC_DVPOKT = {read = get_DocTIDDOC_DVPOKT , write = set_DocTIDDOC_DVPOKT};
   virtual TFIBLargeIntField * get_DocTIDDOC_DVPOKT(void)=0;
   virtual void set_DocTIDDOC_DVPOKT(TFIBLargeIntField * DocTIDDOC_DVPOKT)=0;

   __property TFIBLargeIntField * DocTIDNOM_DVPOKT = {read = get_DocTIDNOM_DVPOKT , write = set_DocTIDNOM_DVPOKT};
   virtual TFIBLargeIntField * get_DocTIDNOM_DVPOKT(void)=0;
   virtual void set_DocTIDNOM_DVPOKT(TFIBLargeIntField * DocTIDNOM_DVPOKT)=0;

   __property TFIBLargeIntField * DocTIDED_DVPOKT = {read = get_DocTIDED_DVPOKT , write = set_DocTIDED_DVPOKT};
   virtual TFIBLargeIntField * get_DocTIDED_DVPOKT(void)=0;
   virtual void set_DocTIDED_DVPOKT(TFIBLargeIntField * DocTIDED_DVPOKT)=0;

   __property TFIBLargeIntField * DocTIDPART_DVPOKT = {read = get_DocTIDPART_DVPOKT , write = set_DocTIDPART_DVPOKT};
   virtual TFIBLargeIntField * get_DocTIDPART_DVPOKT(void)=0;
   virtual void set_DocTIDPART_DVPOKT(TFIBLargeIntField * DocTIDPART_DVPOKT)=0;

   __property TFIBBCDField * DocTKOL_DVPOKT = {read = get_DocTKOL_DVPOKT , write = set_DocTKOL_DVPOKT};
   virtual TFIBBCDField * get_DocTKOL_DVPOKT(void)=0;
   virtual void set_DocTKOL_DVPOKT(TFIBBCDField * DocTKOL_DVPOKT)=0;

   __property TFIBBCDField * DocTKF_DVPOKT = {read = get_DocTKF_DVPOKT , write = set_DocTKF_DVPOKT};
   virtual TFIBBCDField * get_DocTKF_DVPOKT(void)=0;
   virtual void set_DocTKF_DVPOKT(TFIBBCDField * DocTKF_DVPOKT)=0;

   __property TFIBBCDField * DocTPRICE_DVPOKT = {read = get_DocTPRICE_DVPOKT , write = set_DocTPRICE_DVPOKT};
   virtual TFIBBCDField * get_DocTPRICE_DVPOKT(void)=0;
   virtual void set_DocTPRICE_DVPOKT(TFIBBCDField * DocTPRICE_DVPOKT)=0;

   __property TFIBBCDField * DocTSUM_DVPOKT = {read = get_DocTSUM_DVPOKT , write = set_DocTSUM_DVPOKT};
   virtual TFIBBCDField * get_DocTSUM_DVPOKT(void)=0;
   virtual void set_DocTSUM_DVPOKT(TFIBBCDField * DocTSUM_DVPOKT)=0;

   __property TFIBBCDField * DocTRPRICE_DVPOKT = {read = get_DocTRPRICE_DVPOKT , write = set_DocTRPRICE_DVPOKT};
   virtual TFIBBCDField * get_DocTRPRICE_DVPOKT(void)=0;
   virtual void set_DocTRPRICE_DVPOKT(TFIBBCDField * DocTRPRICE_DVPOKT)=0;

   __property TFIBBCDField * DocTRSUM_DVPOKT = {read = get_DocTRSUM_DVPOKT , write = set_DocTRSUM_DVPOKT};
   virtual TFIBBCDField * get_DocTRSUM_DVPOKT(void)=0;
   virtual void set_DocTRSUM_DVPOKT(TFIBBCDField * DocTRSUM_DVPOKT)=0;

   __property TFIBLargeIntField * DocTIDBASE_DVPOKT = {read = get_DocTIDBASE_DVPOKT , write = set_DocTIDBASE_DVPOKT};
   virtual TFIBLargeIntField * get_DocTIDBASE_DVPOKT(void)=0;
   virtual void set_DocTIDBASE_DVPOKT(TFIBLargeIntField * DocTIDBASE_DVPOKT)=0;

   __property TFIBIntegerField * DocTNDS_DVPOKT = {read = get_DocTNDS_DVPOKT , write = set_DocTNDS_DVPOKT};
   virtual TFIBIntegerField * get_DocTNDS_DVPOKT(void)=0;
   virtual void set_DocTNDS_DVPOKT(TFIBIntegerField * DocTNDS_DVPOKT)=0;

   __property TFIBBCDField * DocTSUMNDS_DVPOKT = {read = get_DocTSUMNDS_DVPOKT , write = set_DocTSUMNDS_DVPOKT};
   virtual TFIBBCDField * get_DocTSUMNDS_DVPOKT(void)=0;
   virtual void set_DocTSUMNDS_DVPOKT(TFIBBCDField * DocTSUMNDS_DVPOKT)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBWideStringField * DocKLIENT_NAME_DVPOK = {read = get_DocKLIENT_NAME_DVPOK , write = set_DocKLIENT_NAME_DVPOK};
   virtual TFIBWideStringField * get_DocKLIENT_NAME_DVPOK(void)=0;
   virtual void set_DocKLIENT_NAME_DVPOK(TFIBWideStringField * DocKLIENT_NAME_DVPOK)=0;

   __property TFIBWideStringField * DocKLIENT_ADR_DVPOK = {read = get_DocKLIENT_ADR_DVPOK , write = set_DocKLIENT_ADR_DVPOK};
   virtual TFIBWideStringField * get_DocKLIENT_ADR_DVPOK(void)=0;
   virtual void set_DocKLIENT_ADR_DVPOK(TFIBWideStringField * DocKLIENT_ADR_DVPOK)=0;

   __property TFIBWideStringField * DocKLIENT_PHONE_DVPOK = {read = get_DocKLIENT_PHONE_DVPOK , write = set_DocKLIENT_PHONE_DVPOK};
   virtual TFIBWideStringField * get_DocKLIENT_PHONE_DVPOK(void)=0;
   virtual void set_DocKLIENT_PHONE_DVPOK(TFIBWideStringField * DocKLIENT_PHONE_DVPOK)=0;

   __property TFIBWideStringField * DocKLIENT_PASSPORT_DVPOK = {read = get_DocKLIENT_PASSPORT_DVPOK , write = set_DocKLIENT_PASSPORT_DVPOK};
   virtual TFIBWideStringField * get_DocKLIENT_PASSPORT_DVPOK(void)=0;
   virtual void set_DocKLIENT_PASSPORT_DVPOK(TFIBWideStringField * DocKLIENT_PASSPORT_DVPOK)=0;

   __property TFIBWideStringField * DocPRICHINA_DVPOK = {read = get_DocPRICHINA_DVPOK , write = set_DocPRICHINA_DVPOK};
   virtual TFIBWideStringField * get_DocPRICHINA_DVPOK(void)=0;
   virtual void set_DocPRICHINA_DVPOK(TFIBWideStringField * DocPRICHINA_DVPOK)=0;

   __property TFIBWideStringField * DocNUMDOCSALE_DVPOK = {read = get_DocNUMDOCSALE_DVPOK , write = set_DocNUMDOCSALE_DVPOK};
   virtual TFIBWideStringField * get_DocNUMDOCSALE_DVPOK(void)=0;
   virtual void set_DocNUMDOCSALE_DVPOK(TFIBWideStringField * DocNUMDOCSALE_DVPOK)=0;

   __property TFIBDateTimeField * DocPOSDOCSALE_DVPOK = {read = get_DocPOSDOCSALE_DVPOK , write = set_DocPOSDOCSALE_DVPOK};
   virtual TFIBDateTimeField * get_DocPOSDOCSALE_DVPOK(void)=0;
   virtual void set_DocPOSDOCSALE_DVPOK(TFIBDateTimeField * DocPOSDOCSALE_DVPOK)=0;

   __property TFIBWideStringField * DocNUMDOCKL_DVPOK = {read = get_DocNUMDOCKL_DVPOK , write = set_DocNUMDOCKL_DVPOK};
   virtual TFIBWideStringField * get_DocNUMDOCKL_DVPOK(void)=0;
   virtual void set_DocNUMDOCKL_DVPOK(TFIBWideStringField * DocNUMDOCKL_DVPOK)=0;

   __property TFIBDateTimeField * DocPOSDOCKL_DVPOK = {read = get_DocPOSDOCKL_DVPOK , write = set_DocPOSDOCKL_DVPOK};
   virtual TFIBDateTimeField * get_DocPOSDOCKL_DVPOK(void)=0;
   virtual void set_DocPOSDOCKL_DVPOK(TFIBDateTimeField * DocPOSDOCKL_DVPOK)=0;

   __property TpFIBDataSet * DocOsn = {read = get_DocOsn , write = set_DocOsn};
   virtual TpFIBDataSet * get_DocOsn(void)=0;
   virtual void set_DocOsn(TpFIBDataSet * DocOsn)=0;

   __property TFIBWideStringField * DocOsnTDOC = {read = get_DocOsnTDOC , write = set_DocOsnTDOC};
   virtual TFIBWideStringField * get_DocOsnTDOC(void)=0;
   virtual void set_DocOsnTDOC(TFIBWideStringField * DocOsnTDOC)=0;

   __property TFIBDateTimeField * DocOsnPOSDOC = {read = get_DocOsnPOSDOC , write = set_DocOsnPOSDOC};
   virtual TFIBDateTimeField * get_DocOsnPOSDOC(void)=0;
   virtual void set_DocOsnPOSDOC(TFIBDateTimeField * DocOsnPOSDOC)=0;

   __property TFIBIntegerField * DocOsnNUMDOC = {read = get_DocOsnNUMDOC , write = set_DocOsnNUMDOC};
   virtual TFIBIntegerField * get_DocOsnNUMDOC(void)=0;
   virtual void set_DocOsnNUMDOC(TFIBIntegerField * DocOsnNUMDOC)=0;

   __property TDataSource * DataSourceDocOsn = {read = get_DataSourceDocOsn , write = set_DataSourceDocOsn};
   virtual TDataSource * get_DataSourceDocOsn(void)=0;
   virtual void set_DataSourceDocOsn(TDataSource * DataSourceDocOsn)=0;

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

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property bool IsmPrice = {read = get_IsmPrice , write = set_IsmPrice};
   virtual bool get_IsmPrice(void)=0;
   virtual void set_IsmPrice(bool IsmPrice)=0;

   __property bool IsmSum = {read = get_IsmSum , write = set_IsmSum};
   virtual bool get_IsmSum(void)=0;
   virtual void set_IsmSum(bool IsmSum)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 IdDoc)=0;
   virtual void OpenDocOsn(void)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)=0;
   virtual void AddZakPrice(void)=0;
};
#define IID_IDMDocVosvratPok __uuidof(IDMDocVosvratPok)
#endif
