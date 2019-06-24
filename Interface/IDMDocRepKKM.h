#ifndef UIDMDocRepKKMH
#define UIDMDocRepKKMH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocRepKKM)) IDMDocRepKKM : public IMainInterface
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

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

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

   __property TFIBBCDField * DocOPLNAL_DREPKKM = {read = get_DocOPLNAL_DREPKKM , write = set_DocOPLNAL_DREPKKM};
   virtual TFIBBCDField * get_DocOPLNAL_DREPKKM(void)=0;
   virtual void set_DocOPLNAL_DREPKKM(TFIBBCDField * DocOPLNAL_DREPKKM)=0;

   __property TFIBBCDField * DocOPLPC_DREPKKM = {read = get_DocOPLPC_DREPKKM , write = set_DocOPLPC_DREPKKM};
   virtual TFIBBCDField * get_DocOPLPC_DREPKKM(void)=0;
   virtual void set_DocOPLPC_DREPKKM(TFIBBCDField * DocOPLPC_DREPKKM)=0;

   __property TFIBIntegerField * DocNKL_DREPKKM = {read = get_DocNKL_DREPKKM , write = set_DocNKL_DREPKKM};
   virtual TFIBIntegerField * get_DocNKL_DREPKKM(void)=0;
   virtual void set_DocNKL_DREPKKM(TFIBIntegerField * DocNKL_DREPKKM)=0;

   __property TFIBBCDField * DocSK_DREPKKM = {read = get_DocSK_DREPKKM , write = set_DocSK_DREPKKM};
   virtual TFIBBCDField * get_DocSK_DREPKKM(void)=0;
   virtual void set_DocSK_DREPKKM(TFIBBCDField * DocSK_DREPKKM)=0;

   __property TFIBBCDField * DocNAD_DREPKKM = {read = get_DocNAD_DREPKKM , write = set_DocNAD_DREPKKM};
   virtual TFIBBCDField * get_DocNAD_DREPKKM(void)=0;
   virtual void set_DocNAD_DREPKKM(TFIBBCDField * DocNAD_DREPKKM)=0;

   __property TFIBSmallIntField * DocDVREG_DREPKKM = {read = get_DocDVREG_DREPKKM , write = set_DocDVREG_DREPKKM};
   virtual TFIBSmallIntField * get_DocDVREG_DREPKKM(void)=0;
   virtual void set_DocDVREG_DREPKKM(TFIBSmallIntField * DocDVREG_DREPKKM)=0;

   __property TFIBBCDField * DocTPRICE_DREPKKMT = {read = get_DocTPRICE_DREPKKMT , write = set_DocTPRICE_DREPKKMT};
   virtual TFIBBCDField * get_DocTPRICE_DREPKKMT(void)=0;
   virtual void set_DocTPRICE_DREPKKMT(TFIBBCDField * DocTPRICE_DREPKKMT)=0;

   __property TFIBBCDField * DocTKOL_DREPKKMT = {read = get_DocTKOL_DREPKKMT , write = set_DocTKOL_DREPKKMT};
   virtual TFIBBCDField * get_DocTKOL_DREPKKMT(void)=0;
   virtual void set_DocTKOL_DREPKKMT(TFIBBCDField * DocTKOL_DREPKKMT)=0;

   __property TFIBBCDField * DocTKF_DREPKKMT = {read = get_DocTKF_DREPKKMT , write = set_DocTKF_DREPKKMT};
   virtual TFIBBCDField * get_DocTKF_DREPKKMT(void)=0;
   virtual void set_DocTKF_DREPKKMT(TFIBBCDField * DocTKF_DREPKKMT)=0;

   __property TFIBBCDField * DocTSUM_DREPKKMT = {read = get_DocTSUM_DREPKKMT , write = set_DocTSUM_DREPKKMT};
   virtual TFIBBCDField * get_DocTSUM_DREPKKMT(void)=0;
   virtual void set_DocTSUM_DREPKKMT(TFIBBCDField * DocTSUM_DREPKKMT)=0;

   __property TFIBBCDField * DocTSK_DREPKKMT = {read = get_DocTSK_DREPKKMT , write = set_DocTSK_DREPKKMT};
   virtual TFIBBCDField * get_DocTSK_DREPKKMT(void)=0;
   virtual void set_DocTSK_DREPKKMT(TFIBBCDField * DocTSK_DREPKKMT)=0;

   __property TFIBBCDField * DocTNAD_DREPKKMT = {read = get_DocTNAD_DREPKKMT , write = set_DocTNAD_DREPKKMT};
   virtual TFIBBCDField * get_DocTNAD_DREPKKMT(void)=0;
   virtual void set_DocTNAD_DREPKKMT(TFIBBCDField * DocTNAD_DREPKKMT)=0;

   __property TFIBBCDField * DocTPRICEFULL_DREPKKMT = {read = get_DocTPRICEFULL_DREPKKMT , write = set_DocTPRICEFULL_DREPKKMT};
   virtual TFIBBCDField * get_DocTPRICEFULL_DREPKKMT(void)=0;
   virtual void set_DocTPRICEFULL_DREPKKMT(TFIBBCDField * DocTPRICEFULL_DREPKKMT)=0;

   __property TFIBIntegerField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBIntegerField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM)=0;

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

   __property TpFIBDataSet * TableDoc = {read = get_TableDoc , write = set_TableDoc};
   virtual TpFIBDataSet * get_TableDoc(void)=0;
   virtual void set_TableDoc(TpFIBDataSet * TableDoc)=0;

   __property TpFIBDataSet * PayDoc = {read = get_PayDoc , write = set_PayDoc};
   virtual TpFIBDataSet * get_PayDoc(void)=0;
   virtual void set_PayDoc(TpFIBDataSet * PayDoc)=0;

   __property TFIBBCDField * TableDocSUMMA = {read = get_TableDocSUMMA , write = set_TableDocSUMMA};
   virtual TFIBBCDField * get_TableDocSUMMA(void)=0;
   virtual void set_TableDocSUMMA(TFIBBCDField * TableDocSUMMA)=0;

   __property TFIBFloatField * TableDocSUMKOL = {read = get_TableDocSUMKOL , write = set_TableDocSUMKOL};
   virtual TFIBFloatField * get_TableDocSUMKOL(void)=0;
   virtual void set_TableDocSUMKOL(TFIBFloatField * TableDocSUMKOL)=0;

   __property TFIBBCDField * TableDocSUMSK = {read = get_TableDocSUMSK , write = set_TableDocSUMSK};
   virtual TFIBBCDField * get_TableDocSUMSK(void)=0;
   virtual void set_TableDocSUMSK(TFIBBCDField * TableDocSUMSK)=0;

   __property TFIBBCDField * TableDocSUMNAD = {read = get_TableDocSUMNAD , write = set_TableDocSUMNAD};
   virtual TFIBBCDField * get_TableDocSUMNAD(void)=0;
   virtual void set_TableDocSUMNAD(TFIBBCDField * TableDocSUMNAD)=0;

   __property TFIBBCDField * PayDocOPLATANAL = {read = get_PayDocOPLATANAL , write = set_PayDocOPLATANAL};
   virtual TFIBBCDField * get_PayDocOPLATANAL(void)=0;
   virtual void set_PayDocOPLATANAL(TFIBBCDField * PayDocOPLATANAL)=0;

   __property TFIBBCDField * PayDocOPLATAPC = {read = get_PayDocOPLATAPC , write = set_PayDocOPLATAPC};
   virtual TFIBBCDField * get_PayDocOPLATAPC(void)=0;
   virtual void set_PayDocOPLATAPC(TFIBBCDField * PayDocOPLATAPC)=0;

   __property TFIBLargeIntField * TableDocIDNOM = {read = get_TableDocIDNOM , write = set_TableDocIDNOM};
   virtual TFIBLargeIntField * get_TableDocIDNOM(void)=0;
   virtual void set_TableDocIDNOM(TFIBLargeIntField * TableDocIDNOM)=0;

   __property TFIBWideStringField * TableDocNAMENOM = {read = get_TableDocNAMENOM , write = set_TableDocNAMENOM};
   virtual TFIBWideStringField * get_TableDocNAMENOM(void)=0;
   virtual void set_TableDocNAMENOM(TFIBWideStringField * TableDocNAMENOM)=0;

   __property TFIBLargeIntField * TableDocIDED = {read = get_TableDocIDED , write = set_TableDocIDED};
   virtual TFIBLargeIntField * get_TableDocIDED(void)=0;
   virtual void set_TableDocIDED(TFIBLargeIntField * TableDocIDED)=0;

   __property TFIBWideStringField * TableDocNAMEED = {read = get_TableDocNAMEED , write = set_TableDocNAMEED};
   virtual TFIBWideStringField * get_TableDocNAMEED(void)=0;
   virtual void set_TableDocNAMEED(TFIBWideStringField * TableDocNAMEED)=0;

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

   __property TFIBWideStringField * DocAllFNAME_USER = {read = get_DocAllFNAME_USER , write = set_DocAllFNAME_USER};
   virtual TFIBWideStringField * get_DocAllFNAME_USER(void)=0;
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)=0;

   __property TFIBWideStringField * DocAllNAME_SDOG = {read = get_DocAllNAME_SDOG , write = set_DocAllNAME_SDOG};
   virtual TFIBWideStringField * get_DocAllNAME_SDOG(void)=0;
   virtual void set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG)=0;

   __property TFIBWideStringField * DocAllNAMEKLIENT = {read = get_DocAllNAMEKLIENT , write = set_DocAllNAMEKLIENT};
   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void)=0;
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)=0;

   __property TFIBWideStringField * DocAllNAMEFIRM = {read = get_DocAllNAMEFIRM , write = set_DocAllNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void)=0;
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllNAMESKLAD = {read = get_DocAllNAMESKLAD , write = set_DocAllNAMESKLAD};
   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void)=0;
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBLargeIntField * DocID_DREPKKM = {read = get_DocID_DREPKKM , write = set_DocID_DREPKKM};
   virtual TFIBLargeIntField * get_DocID_DREPKKM(void)=0;
   virtual void set_DocID_DREPKKM(TFIBLargeIntField * DocID_DREPKKM)=0;

   __property TFIBWideStringField * DocGID_DREPKKM = {read = get_DocGID_DREPKKM , write = set_DocGID_DREPKKM};
   virtual TFIBWideStringField * get_DocGID_DREPKKM(void)=0;
   virtual void set_DocGID_DREPKKM(TFIBWideStringField * DocGID_DREPKKM)=0;

   __property TFIBLargeIntField * DocIDDOC_DREPKKM = {read = get_DocIDDOC_DREPKKM , write = set_DocIDDOC_DREPKKM};
   virtual TFIBLargeIntField * get_DocIDDOC_DREPKKM(void)=0;
   virtual void set_DocIDDOC_DREPKKM(TFIBLargeIntField * DocIDDOC_DREPKKM)=0;

   __property TFIBLargeIntField * DocIDKKM_DREPKKM = {read = get_DocIDKKM_DREPKKM , write = set_DocIDKKM_DREPKKM};
   virtual TFIBLargeIntField * get_DocIDKKM_DREPKKM(void)=0;
   virtual void set_DocIDKKM_DREPKKM(TFIBLargeIntField * DocIDKKM_DREPKKM)=0;

   __property TFIBWideStringField * DocPRIM_DREPKKM = {read = get_DocPRIM_DREPKKM , write = set_DocPRIM_DREPKKM};
   virtual TFIBWideStringField * get_DocPRIM_DREPKKM(void)=0;
   virtual void set_DocPRIM_DREPKKM(TFIBWideStringField * DocPRIM_DREPKKM)=0;

   __property TFIBLargeIntField * DocIDTPRICE_DREPKKM = {read = get_DocIDTPRICE_DREPKKM , write = set_DocIDTPRICE_DREPKKM};
   virtual TFIBLargeIntField * get_DocIDTPRICE_DREPKKM(void)=0;
   virtual void set_DocIDTPRICE_DREPKKM(TFIBLargeIntField * DocIDTPRICE_DREPKKM)=0;

   __property TFIBLargeIntField * DocIDBASE_DREPKKM = {read = get_DocIDBASE_DREPKKM , write = set_DocIDBASE_DREPKKM};
   virtual TFIBLargeIntField * get_DocIDBASE_DREPKKM(void)=0;
   virtual void set_DocIDBASE_DREPKKM(TFIBLargeIntField * DocIDBASE_DREPKKM)=0;

   __property TFIBLargeIntField * DocIDBSCHET_DREPKKM = {read = get_DocIDBSCHET_DREPKKM , write = set_DocIDBSCHET_DREPKKM};
   virtual TFIBLargeIntField * get_DocIDBSCHET_DREPKKM(void)=0;
   virtual void set_DocIDBSCHET_DREPKKM(TFIBLargeIntField * DocIDBSCHET_DREPKKM)=0;

   __property TFIBWideStringField * DocNAMEKKM = {read = get_DocNAMEKKM , write = set_DocNAMEKKM};
   virtual TFIBWideStringField * get_DocNAMEKKM(void)=0;
   virtual void set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM)=0;

   __property TFIBWideStringField * DocNAME_TPRICE = {read = get_DocNAME_TPRICE , write = set_DocNAME_TPRICE};
   virtual TFIBWideStringField * get_DocNAME_TPRICE(void)=0;
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)=0;

   __property TFIBWideStringField * DocNAMEBSCHET = {read = get_DocNAMEBSCHET , write = set_DocNAMEBSCHET};
   virtual TFIBWideStringField * get_DocNAMEBSCHET(void)=0;
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)=0;

   __property TFIBLargeIntField * DocTID_DREPKKMT = {read = get_DocTID_DREPKKMT , write = set_DocTID_DREPKKMT};
   virtual TFIBLargeIntField * get_DocTID_DREPKKMT(void)=0;
   virtual void set_DocTID_DREPKKMT(TFIBLargeIntField * DocTID_DREPKKMT)=0;

   __property TFIBWideStringField * DocTGID_DREPKKMT = {read = get_DocTGID_DREPKKMT , write = set_DocTGID_DREPKKMT};
   virtual TFIBWideStringField * get_DocTGID_DREPKKMT(void)=0;
   virtual void set_DocTGID_DREPKKMT(TFIBWideStringField * DocTGID_DREPKKMT)=0;

   __property TFIBLargeIntField * DocTIDDOC_DREPKKMT = {read = get_DocTIDDOC_DREPKKMT , write = set_DocTIDDOC_DREPKKMT};
   virtual TFIBLargeIntField * get_DocTIDDOC_DREPKKMT(void)=0;
   virtual void set_DocTIDDOC_DREPKKMT(TFIBLargeIntField * DocTIDDOC_DREPKKMT)=0;

   __property TFIBLargeIntField * DocTIDNOM_DREPKKMT = {read = get_DocTIDNOM_DREPKKMT , write = set_DocTIDNOM_DREPKKMT};
   virtual TFIBLargeIntField * get_DocTIDNOM_DREPKKMT(void)=0;
   virtual void set_DocTIDNOM_DREPKKMT(TFIBLargeIntField * DocTIDNOM_DREPKKMT)=0;

   __property TFIBLargeIntField * DocTIDED_DREPKKMT = {read = get_DocTIDED_DREPKKMT , write = set_DocTIDED_DREPKKMT};
   virtual TFIBLargeIntField * get_DocTIDED_DREPKKMT(void)=0;
   virtual void set_DocTIDED_DREPKKMT(TFIBLargeIntField * DocTIDED_DREPKKMT)=0;

   __property TFIBLargeIntField * DocTIDBASE_DREPKKMT = {read = get_DocTIDBASE_DREPKKMT , write = set_DocTIDBASE_DREPKKMT};
   virtual TFIBLargeIntField * get_DocTIDBASE_DREPKKMT(void)=0;
   virtual void set_DocTIDBASE_DREPKKMT(TFIBLargeIntField * DocTIDBASE_DREPKKMT)=0;

   __property TFIBIntegerField * DocTNDS_DREPKKMT = {read = get_DocTNDS_DREPKKMT , write = set_DocTNDS_DREPKKMT};
   virtual TFIBIntegerField * get_DocTNDS_DREPKKMT(void)=0;
   virtual void set_DocTNDS_DREPKKMT(TFIBIntegerField * DocTNDS_DREPKKMT)=0;

   __property TFIBBCDField * DocTSUMNDS_DREPKKMT = {read = get_DocTSUMNDS_DREPKKMT , write = set_DocTSUMNDS_DREPKKMT};
   virtual TFIBBCDField * get_DocTSUMNDS_DREPKKMT(void)=0;
   virtual void set_DocTSUMNDS_DREPKKMT(TFIBBCDField * DocTSUMNDS_DREPKKMT)=0;

   __property TFIBWideStringField * DocTKRNAMENOM = {read = get_DocTKRNAMENOM , write = set_DocTKRNAMENOM};
   virtual TFIBWideStringField * get_DocTKRNAMENOM(void)=0;
   virtual void set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBWideStringField * DocAllTDOC = {read = get_DocAllTDOC , write = set_DocAllTDOC};
   virtual TFIBWideStringField * get_DocAllTDOC(void)=0;
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)=0;

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

   __property bool NewElement = {read = get_NewElement , write = set_NewElement};
   virtual bool get_NewElement(void)=0;
   virtual void set_NewElement(bool NewElement)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property bool NoEdit = {read = get_NoEdit , write = set_NoEdit};
   virtual bool get_NoEdit(void)=0;
   virtual void set_NoEdit(bool NoEdit)=0;

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
   virtual bool DeleteDoc(__int64 id)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual double Summa(void)=0;
   virtual bool CreateReportKKM(   __int64 id_sklad,__int64 id_kkm,__int64 id_firm,int number_kl ,TDateTime NachInterval,TDateTime ConInterval)=0;
   virtual void GetSumOplata(      __int64 id_sklad,__int64 id_kkm,__int64 id_firm,int number_kl ,TDateTime NachInterval,TDateTime ConInterval )=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocRepKKM __uuidof(IDMDocRepKKM)
#endif
