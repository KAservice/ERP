#ifndef UIDMDocCheckH
#define UIDMDocCheckH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocCheck)) IDMDocCheck : public IMainInterface
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

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBDataSet * SpisokTypePrice = {read = get_SpisokTypePrice , write = set_SpisokTypePrice};
   virtual TpFIBDataSet * get_SpisokTypePrice(void)=0;
   virtual void set_SpisokTypePrice(TpFIBDataSet * SpisokTypePrice)=0;

   __property TFIBIntegerField * SpisokTypePriceID_TPRICE = {read = get_SpisokTypePriceID_TPRICE , write = set_SpisokTypePriceID_TPRICE};
   virtual TFIBIntegerField * get_SpisokTypePriceID_TPRICE(void)=0;
   virtual void set_SpisokTypePriceID_TPRICE(TFIBIntegerField * SpisokTypePriceID_TPRICE)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TpFIBDataSet * DocOsn = {read = get_DocOsn , write = set_DocOsn};
   virtual TpFIBDataSet * get_DocOsn(void)=0;
   virtual void set_DocOsn(TpFIBDataSet * DocOsn)=0;

   __property TDataSource * DataSourceDocOsn = {read = get_DataSourceDocOsn , write = set_DataSourceDocOsn};
   virtual TDataSource * get_DataSourceDocOsn(void)=0;
   virtual void set_DataSourceDocOsn(TDataSource * DataSourceDocOsn)=0;

   __property TpFIBDataSet * DocOpl = {read = get_DocOpl , write = set_DocOpl};
   virtual TpFIBDataSet * get_DocOpl(void)=0;
   virtual void set_DocOpl(TpFIBDataSet * DocOpl)=0;

   __property TDataSource * DataSourceDocOpl = {read = get_DataSourceDocOpl , write = set_DataSourceDocOpl};
   virtual TDataSource * get_DataSourceDocOpl(void)=0;
   virtual void set_DataSourceDocOpl(TDataSource * DataSourceDocOpl)=0;

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

   __property TFIBWideStringField * DocAllNAME_SDOG = {read = get_DocAllNAME_SDOG , write = set_DocAllNAME_SDOG};
   virtual TFIBWideStringField * get_DocAllNAME_SDOG(void)=0;
   virtual void set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG)=0;

   __property TFIBWideStringField * DocAllNAMEKLIENT = {read = get_DocAllNAMEKLIENT , write = set_DocAllNAMEKLIENT};
   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void)=0;
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocAllNAMEFIRM = {read = get_DocAllNAMEFIRM , write = set_DocAllNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void)=0;
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllNAMESKLAD = {read = get_DocAllNAMESKLAD , write = set_DocAllNAMESKLAD};
   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void)=0;
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocOsnTDOC = {read = get_DocOsnTDOC , write = set_DocOsnTDOC};
   virtual TFIBWideStringField * get_DocOsnTDOC(void)=0;
   virtual void set_DocOsnTDOC(TFIBWideStringField * DocOsnTDOC)=0;

   __property TFIBDateTimeField * DocOsnPOSDOC = {read = get_DocOsnPOSDOC , write = set_DocOsnPOSDOC};
   virtual TFIBDateTimeField * get_DocOsnPOSDOC(void)=0;
   virtual void set_DocOsnPOSDOC(TFIBDateTimeField * DocOsnPOSDOC)=0;

   __property TFIBIntegerField * DocOsnNUMDOC = {read = get_DocOsnNUMDOC , write = set_DocOsnNUMDOC};
   virtual TFIBIntegerField * get_DocOsnNUMDOC(void)=0;
   virtual void set_DocOsnNUMDOC(TFIBIntegerField * DocOsnNUMDOC)=0;

   __property TIntegerField * DocOplRECNO = {read = get_DocOplRECNO , write = set_DocOplRECNO};
   virtual TIntegerField * get_DocOplRECNO(void)=0;
   virtual void set_DocOplRECNO(TIntegerField * DocOplRECNO)=0;

   __property TFIBLargeIntField * DocIDCHK = {read = get_DocIDCHK , write = set_DocIDCHK};
   virtual TFIBLargeIntField * get_DocIDCHK(void)=0;
   virtual void set_DocIDCHK(TFIBLargeIntField * DocIDCHK)=0;

   __property TFIBLargeIntField * DocIDDOCCHK = {read = get_DocIDDOCCHK , write = set_DocIDDOCCHK};
   virtual TFIBLargeIntField * get_DocIDDOCCHK(void)=0;
   virtual void set_DocIDDOCCHK(TFIBLargeIntField * DocIDDOCCHK)=0;

   __property TFIBLargeIntField * DocIDKKMCHK = {read = get_DocIDKKMCHK , write = set_DocIDKKMCHK};
   virtual TFIBLargeIntField * get_DocIDKKMCHK(void)=0;
   virtual void set_DocIDKKMCHK(TFIBLargeIntField * DocIDKKMCHK)=0;

   __property TFIBLargeIntField * DocIDTPRICE = {read = get_DocIDTPRICE , write = set_DocIDTPRICE};
   virtual TFIBLargeIntField * get_DocIDTPRICE(void)=0;
   virtual void set_DocIDTPRICE(TFIBLargeIntField * DocIDTPRICE)=0;

   __property TFIBIntegerField * DocNCHECKCHK = {read = get_DocNCHECKCHK , write = set_DocNCHECKCHK};
   virtual TFIBIntegerField * get_DocNCHECKCHK(void)=0;
   virtual void set_DocNCHECKCHK(TFIBIntegerField * DocNCHECKCHK)=0;

   __property TFIBIntegerField * DocNKLCHK = {read = get_DocNKLCHK , write = set_DocNKLCHK};
   virtual TFIBIntegerField * get_DocNKLCHK(void)=0;
   virtual void set_DocNKLCHK(TFIBIntegerField * DocNKLCHK)=0;

   __property TFIBIntegerField * DocOPERCHK = {read = get_DocOPERCHK , write = set_DocOPERCHK};
   virtual TFIBIntegerField * get_DocOPERCHK(void)=0;
   virtual void set_DocOPERCHK(TFIBIntegerField * DocOPERCHK)=0;

   __property TFIBBCDField * DocOPLNALCHK = {read = get_DocOPLNALCHK , write = set_DocOPLNALCHK};
   virtual TFIBBCDField * get_DocOPLNALCHK(void)=0;
   virtual void set_DocOPLNALCHK(TFIBBCDField * DocOPLNALCHK)=0;

   __property TFIBBCDField * DocOPLPCCHK = {read = get_DocOPLPCCHK , write = set_DocOPLPCCHK};
   virtual TFIBBCDField * get_DocOPLPCCHK(void)=0;
   virtual void set_DocOPLPCCHK(TFIBBCDField * DocOPLPCCHK)=0;

   __property TFIBBCDField * DocNALCHK = {read = get_DocNALCHK , write = set_DocNALCHK};
   virtual TFIBBCDField * get_DocNALCHK(void)=0;
   virtual void set_DocNALCHK(TFIBBCDField * DocNALCHK)=0;

   __property TFIBWideStringField * DocPRIMCHK = {read = get_DocPRIMCHK , write = set_DocPRIMCHK};
   virtual TFIBWideStringField * get_DocPRIMCHK(void)=0;
   virtual void set_DocPRIMCHK(TFIBWideStringField * DocPRIMCHK)=0;

   __property TFIBWideStringField * DocGID_DCHK = {read = get_DocGID_DCHK , write = set_DocGID_DCHK};
   virtual TFIBWideStringField * get_DocGID_DCHK(void)=0;
   virtual void set_DocGID_DCHK(TFIBWideStringField * DocGID_DCHK)=0;

   __property TFIBSmallIntField * DocDVREGCHK = {read = get_DocDVREGCHK , write = set_DocDVREGCHK};
   virtual TFIBSmallIntField * get_DocDVREGCHK(void)=0;
   virtual void set_DocDVREGCHK(TFIBSmallIntField * DocDVREGCHK)=0;

   __property TFIBWideStringField * DocSAVNUMCHK = {read = get_DocSAVNUMCHK , write = set_DocSAVNUMCHK};
   virtual TFIBWideStringField * get_DocSAVNUMCHK(void)=0;
   virtual void set_DocSAVNUMCHK(TFIBWideStringField * DocSAVNUMCHK)=0;

   __property TFIBWideStringField * DocMODELCHK = {read = get_DocMODELCHK , write = set_DocMODELCHK};
   virtual TFIBWideStringField * get_DocMODELCHK(void)=0;
   virtual void set_DocMODELCHK(TFIBWideStringField * DocMODELCHK)=0;

   __property TFIBWideStringField * DocREGNUMCHK = {read = get_DocREGNUMCHK , write = set_DocREGNUMCHK};
   virtual TFIBWideStringField * get_DocREGNUMCHK(void)=0;
   virtual void set_DocREGNUMCHK(TFIBWideStringField * DocREGNUMCHK)=0;

   __property TFIBLargeIntField * DocIDDCARDCHK = {read = get_DocIDDCARDCHK , write = set_DocIDDCARDCHK};
   virtual TFIBLargeIntField * get_DocIDDCARDCHK(void)=0;
   virtual void set_DocIDDCARDCHK(TFIBLargeIntField * DocIDDCARDCHK)=0;

   __property TFIBLargeIntField * DocIDBASE_DCHK = {read = get_DocIDBASE_DCHK , write = set_DocIDBASE_DCHK};
   virtual TFIBLargeIntField * get_DocIDBASE_DCHK(void)=0;
   virtual void set_DocIDBASE_DCHK(TFIBLargeIntField * DocIDBASE_DCHK)=0;

   __property TFIBBCDField * DocSDACHA_DCHK = {read = get_DocSDACHA_DCHK , write = set_DocSDACHA_DCHK};
   virtual TFIBBCDField * get_DocSDACHA_DCHK(void)=0;
   virtual void set_DocSDACHA_DCHK(TFIBBCDField * DocSDACHA_DCHK)=0;

   __property TFIBLargeIntField * DocIDBSCHET_DCHK = {read = get_DocIDBSCHET_DCHK , write = set_DocIDBSCHET_DCHK};
   virtual TFIBLargeIntField * get_DocIDBSCHET_DCHK(void)=0;
   virtual void set_DocIDBSCHET_DCHK(TFIBLargeIntField * DocIDBSCHET_DCHK)=0;

   __property TFIBBCDField * DocOPLPLATCARD_DCHK = {read = get_DocOPLPLATCARD_DCHK , write = set_DocOPLPLATCARD_DCHK};
   virtual TFIBBCDField * get_DocOPLPLATCARD_DCHK(void)=0;
   virtual void set_DocOPLPLATCARD_DCHK(TFIBBCDField * DocOPLPLATCARD_DCHK)=0;

   __property TFIBBCDField * DocOPLCREDITCARD_DCHK = {read = get_DocOPLCREDITCARD_DCHK , write = set_DocOPLCREDITCARD_DCHK};
   virtual TFIBBCDField * get_DocOPLCREDITCARD_DCHK(void)=0;
   virtual void set_DocOPLCREDITCARD_DCHK(TFIBBCDField * DocOPLCREDITCARD_DCHK)=0;

   __property TFIBBCDField * DocOPLPLATCARD_ALL_DCHK = {read = get_DocOPLPLATCARD_ALL_DCHK , write = set_DocOPLPLATCARD_ALL_DCHK};
   virtual TFIBBCDField * get_DocOPLPLATCARD_ALL_DCHK(void)=0;
   virtual void set_DocOPLPLATCARD_ALL_DCHK(TFIBBCDField * DocOPLPLATCARD_ALL_DCHK)=0;

   __property TFIBBCDField * DocOPLCREDITCARD_ALL_DCHK = {read = get_DocOPLCREDITCARD_ALL_DCHK , write = set_DocOPLCREDITCARD_ALL_DCHK};
   virtual TFIBBCDField * get_DocOPLCREDITCARD_ALL_DCHK(void)=0;
   virtual void set_DocOPLCREDITCARD_ALL_DCHK(TFIBBCDField * DocOPLCREDITCARD_ALL_DCHK)=0;

   __property TFIBWideStringField * DocNAMEKKM = {read = get_DocNAMEKKM , write = set_DocNAMEKKM};
   virtual TFIBWideStringField * get_DocNAMEKKM(void)=0;
   virtual void set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM)=0;

   __property TFIBWideStringField * DocNAME_SDISCOUNT_CARD = {read = get_DocNAME_SDISCOUNT_CARD , write = set_DocNAME_SDISCOUNT_CARD};
   virtual TFIBWideStringField * get_DocNAME_SDISCOUNT_CARD(void)=0;
   virtual void set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD)=0;

   __property TFIBWideStringField * DocNAMEBSCHET = {read = get_DocNAMEBSCHET , write = set_DocNAMEBSCHET};
   virtual TFIBWideStringField * get_DocNAMEBSCHET(void)=0;
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)=0;

   __property TFIBLargeIntField * DocTIDCHKT = {read = get_DocTIDCHKT , write = set_DocTIDCHKT};
   virtual TFIBLargeIntField * get_DocTIDCHKT(void)=0;
   virtual void set_DocTIDCHKT(TFIBLargeIntField * DocTIDCHKT)=0;

   __property TFIBLargeIntField * DocTIDDOCCHKT = {read = get_DocTIDDOCCHKT , write = set_DocTIDDOCCHKT};
   virtual TFIBLargeIntField * get_DocTIDDOCCHKT(void)=0;
   virtual void set_DocTIDDOCCHKT(TFIBLargeIntField * DocTIDDOCCHKT)=0;

   __property TFIBLargeIntField * DocTIDNOMCHKT = {read = get_DocTIDNOMCHKT , write = set_DocTIDNOMCHKT};
   virtual TFIBLargeIntField * get_DocTIDNOMCHKT(void)=0;
   virtual void set_DocTIDNOMCHKT(TFIBLargeIntField * DocTIDNOMCHKT)=0;

   __property TFIBLargeIntField * DocTIDEDCHKT = {read = get_DocTIDEDCHKT , write = set_DocTIDEDCHKT};
   virtual TFIBLargeIntField * get_DocTIDEDCHKT(void)=0;
   virtual void set_DocTIDEDCHKT(TFIBLargeIntField * DocTIDEDCHKT)=0;

   __property TFIBBCDField * DocTKOLCHKT = {read = get_DocTKOLCHKT , write = set_DocTKOLCHKT};
   virtual TFIBBCDField * get_DocTKOLCHKT(void)=0;
   virtual void set_DocTKOLCHKT(TFIBBCDField * DocTKOLCHKT)=0;

   __property TFIBBCDField * DocTKFCHKT = {read = get_DocTKFCHKT , write = set_DocTKFCHKT};
   virtual TFIBBCDField * get_DocTKFCHKT(void)=0;
   virtual void set_DocTKFCHKT(TFIBBCDField * DocTKFCHKT)=0;

   __property TFIBBCDField * DocTPRICECHKT = {read = get_DocTPRICECHKT , write = set_DocTPRICECHKT};
   virtual TFIBBCDField * get_DocTPRICECHKT(void)=0;
   virtual void set_DocTPRICECHKT(TFIBBCDField * DocTPRICECHKT)=0;

   __property TFIBBCDField * DocTSUMCHKT = {read = get_DocTSUMCHKT , write = set_DocTSUMCHKT};
   virtual TFIBBCDField * get_DocTSUMCHKT(void)=0;
   virtual void set_DocTSUMCHKT(TFIBBCDField * DocTSUMCHKT)=0;

   __property TFIBBCDField * DocTSKCHKT = {read = get_DocTSKCHKT , write = set_DocTSKCHKT};
   virtual TFIBBCDField * get_DocTSKCHKT(void)=0;
   virtual void set_DocTSKCHKT(TFIBBCDField * DocTSKCHKT)=0;

   __property TFIBBCDField * DocTNADCHKT = {read = get_DocTNADCHKT , write = set_DocTNADCHKT};
   virtual TFIBBCDField * get_DocTNADCHKT(void)=0;
   virtual void set_DocTNADCHKT(TFIBBCDField * DocTNADCHKT)=0;

   __property TFIBBCDField * DocTPRSKCHKT = {read = get_DocTPRSKCHKT , write = set_DocTPRSKCHKT};
   virtual TFIBBCDField * get_DocTPRSKCHKT(void)=0;
   virtual void set_DocTPRSKCHKT(TFIBBCDField * DocTPRSKCHKT)=0;

   __property TFIBBCDField * DocTPRNADCHKT = {read = get_DocTPRNADCHKT , write = set_DocTPRNADCHKT};
   virtual TFIBBCDField * get_DocTPRNADCHKT(void)=0;
   virtual void set_DocTPRNADCHKT(TFIBBCDField * DocTPRNADCHKT)=0;

   __property TFIBWideStringField * DocTGID_DCHKT = {read = get_DocTGID_DCHKT , write = set_DocTGID_DCHKT};
   virtual TFIBWideStringField * get_DocTGID_DCHKT(void)=0;
   virtual void set_DocTGID_DCHKT(TFIBWideStringField * DocTGID_DCHKT)=0;

   __property TFIBLargeIntField * DocTIDBASE_DCHKT = {read = get_DocTIDBASE_DCHKT , write = set_DocTIDBASE_DCHKT};
   virtual TFIBLargeIntField * get_DocTIDBASE_DCHKT(void)=0;
   virtual void set_DocTIDBASE_DCHKT(TFIBLargeIntField * DocTIDBASE_DCHKT)=0;

   __property TFIBBCDField * DocTPRSK_CARD_DCHKT = {read = get_DocTPRSK_CARD_DCHKT , write = set_DocTPRSK_CARD_DCHKT};
   virtual TFIBBCDField * get_DocTPRSK_CARD_DCHKT(void)=0;
   virtual void set_DocTPRSK_CARD_DCHKT(TFIBBCDField * DocTPRSK_CARD_DCHKT)=0;

   __property TFIBBCDField * DocTPRSK_AUTO_DCHKT = {read = get_DocTPRSK_AUTO_DCHKT , write = set_DocTPRSK_AUTO_DCHKT};
   virtual TFIBBCDField * get_DocTPRSK_AUTO_DCHKT(void)=0;
   virtual void set_DocTPRSK_AUTO_DCHKT(TFIBBCDField * DocTPRSK_AUTO_DCHKT)=0;

   __property TFIBIntegerField * DocTNDS_DCHKT = {read = get_DocTNDS_DCHKT , write = set_DocTNDS_DCHKT};
   virtual TFIBIntegerField * get_DocTNDS_DCHKT(void)=0;
   virtual void set_DocTNDS_DCHKT(TFIBIntegerField * DocTNDS_DCHKT)=0;

   __property TFIBBCDField * DocTSUMNDS_DCHKT = {read = get_DocTSUMNDS_DCHKT , write = set_DocTSUMNDS_DCHKT};
   virtual TFIBBCDField * get_DocTSUMNDS_DCHKT(void)=0;
   virtual void set_DocTSUMNDS_DCHKT(TFIBBCDField * DocTSUMNDS_DCHKT)=0;

   __property TFIBWideStringField * DocTKRNAMENOM = {read = get_DocTKRNAMENOM , write = set_DocTKRNAMENOM};
   virtual TFIBWideStringField * get_DocTKRNAMENOM(void)=0;
   virtual void set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBSmallIntField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBSmallIntField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBLargeIntField * DocOplID_DCHK_OPL = {read = get_DocOplID_DCHK_OPL , write = set_DocOplID_DCHK_OPL};
   virtual TFIBLargeIntField * get_DocOplID_DCHK_OPL(void)=0;
   virtual void set_DocOplID_DCHK_OPL(TFIBLargeIntField * DocOplID_DCHK_OPL)=0;

   __property TFIBLargeIntField * DocOplIDBASE_DCHK_OPL = {read = get_DocOplIDBASE_DCHK_OPL , write = set_DocOplIDBASE_DCHK_OPL};
   virtual TFIBLargeIntField * get_DocOplIDBASE_DCHK_OPL(void)=0;
   virtual void set_DocOplIDBASE_DCHK_OPL(TFIBLargeIntField * DocOplIDBASE_DCHK_OPL)=0;

   __property TFIBLargeIntField * DocOplIDCARD_DCHK_OPL = {read = get_DocOplIDCARD_DCHK_OPL , write = set_DocOplIDCARD_DCHK_OPL};
   virtual TFIBLargeIntField * get_DocOplIDCARD_DCHK_OPL(void)=0;
   virtual void set_DocOplIDCARD_DCHK_OPL(TFIBLargeIntField * DocOplIDCARD_DCHK_OPL)=0;

   __property TFIBBCDField * DocOplSUMPLAT_DCHK_OPL = {read = get_DocOplSUMPLAT_DCHK_OPL , write = set_DocOplSUMPLAT_DCHK_OPL};
   virtual TFIBBCDField * get_DocOplSUMPLAT_DCHK_OPL(void)=0;
   virtual void set_DocOplSUMPLAT_DCHK_OPL(TFIBBCDField * DocOplSUMPLAT_DCHK_OPL)=0;

   __property TFIBBCDField * DocOplSUMCREDIT_DCHK_OPL = {read = get_DocOplSUMCREDIT_DCHK_OPL , write = set_DocOplSUMCREDIT_DCHK_OPL};
   virtual TFIBBCDField * get_DocOplSUMCREDIT_DCHK_OPL(void)=0;
   virtual void set_DocOplSUMCREDIT_DCHK_OPL(TFIBBCDField * DocOplSUMCREDIT_DCHK_OPL)=0;

   __property TFIBLargeIntField * DocOplIDDOC_DCHK_OPL = {read = get_DocOplIDDOC_DCHK_OPL , write = set_DocOplIDDOC_DCHK_OPL};
   virtual TFIBLargeIntField * get_DocOplIDDOC_DCHK_OPL(void)=0;
   virtual void set_DocOplIDDOC_DCHK_OPL(TFIBLargeIntField * DocOplIDDOC_DCHK_OPL)=0;

   __property TFIBWideStringField * DocOplNAME_SDISCOUNT_CARD = {read = get_DocOplNAME_SDISCOUNT_CARD , write = set_DocOplNAME_SDISCOUNT_CARD};
   virtual TFIBWideStringField * get_DocOplNAME_SDISCOUNT_CARD(void)=0;
   virtual void set_DocOplNAME_SDISCOUNT_CARD(TFIBWideStringField * DocOplNAME_SDISCOUNT_CARD)=0;

   __property TFloatField * DocALLOPL = {read = get_DocALLOPL , write = set_DocALLOPL};
   virtual TFloatField * get_DocALLOPL(void)=0;
   virtual void set_DocALLOPL(TFloatField * DocALLOPL)=0;

   __property TFIBWideStringField * SpisokTypePriceNAME_TPRICE = {read = get_SpisokTypePriceNAME_TPRICE , write = set_SpisokTypePriceNAME_TPRICE};
   virtual TFIBWideStringField * get_SpisokTypePriceNAME_TPRICE(void)=0;
   virtual void set_SpisokTypePriceNAME_TPRICE(TFIBWideStringField * SpisokTypePriceNAME_TPRICE)=0;

   __property TFIBWideStringField * SpisokTypePriceGID_STPRICE = {read = get_SpisokTypePriceGID_STPRICE , write = set_SpisokTypePriceGID_STPRICE};
   virtual TFIBWideStringField * get_SpisokTypePriceGID_STPRICE(void)=0;
   virtual void set_SpisokTypePriceGID_STPRICE(TFIBWideStringField * SpisokTypePriceGID_STPRICE)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBWideStringField * DocTARTNOM = {read = get_DocTARTNOM , write = set_DocTARTNOM};
   virtual TFIBWideStringField * get_DocTARTNOM(void)=0;
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)=0;

   __property TFIBWideStringField * DocTSHED = {read = get_DocTSHED , write = set_DocTSHED};
   virtual TFIBWideStringField * get_DocTSHED(void)=0;
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED)=0;

   __property TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC = {read = get_DocAllIDBUSINOP_GALLDOC , write = set_DocAllIDBUSINOP_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void)=0;
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBBCDField * DocOPL_OTHER_DCHK = {read = get_DocOPL_OTHER_DCHK , write = set_DocOPL_OTHER_DCHK};
   virtual TFIBBCDField * get_DocOPL_OTHER_DCHK(void)=0;
   virtual void set_DocOPL_OTHER_DCHK(TFIBBCDField * DocOPL_OTHER_DCHK)=0;

   __property TFIBBCDField * DocTPRSK_HAND_DCHKT = {read = get_DocTPRSK_HAND_DCHKT , write = set_DocTPRSK_HAND_DCHKT};
   virtual TFIBBCDField * get_DocTPRSK_HAND_DCHKT(void)=0;
   virtual void set_DocTPRSK_HAND_DCHKT(TFIBBCDField * DocTPRSK_HAND_DCHKT)=0;

   __property TFIBSmallIntField * DocTNO_SK_DCHKT = {read = get_DocTNO_SK_DCHKT , write = set_DocTNO_SK_DCHKT};
   virtual TFIBSmallIntField * get_DocTNO_SK_DCHKT(void)=0;
   virtual void set_DocTNO_SK_DCHKT(TFIBSmallIntField * DocTNO_SK_DCHKT)=0;

   __property TFIBLargeIntField * DocTIDGRPNOM = {read = get_DocTIDGRPNOM , write = set_DocTIDGRPNOM};
   virtual TFIBLargeIntField * get_DocTIDGRPNOM(void)=0;
   virtual void set_DocTIDGRPNOM(TFIBLargeIntField * DocTIDGRPNOM)=0;

   __property TFIBLargeIntField * DocTIDVID_SNOM = {read = get_DocTIDVID_SNOM , write = set_DocTIDVID_SNOM};
   virtual TFIBLargeIntField * get_DocTIDVID_SNOM(void)=0;
   virtual void set_DocTIDVID_SNOM(TFIBLargeIntField * DocTIDVID_SNOM)=0;

   __property TFIBWideStringField * DocTNAMEGN = {read = get_DocTNAMEGN , write = set_DocTNAMEGN};
   virtual TFIBWideStringField * get_DocTNAMEGN(void)=0;
   virtual void set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN)=0;

   __property TFIBWideStringField * DocTNAME_SVIDNOM = {read = get_DocTNAME_SVIDNOM , write = set_DocTNAME_SVIDNOM};
   virtual TFIBWideStringField * get_DocTNAME_SVIDNOM(void)=0;
   virtual void set_DocTNAME_SVIDNOM(TFIBWideStringField * DocTNAME_SVIDNOM)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC = {read = get_DocAllPREFIKS_NUM_GALLDOC , write = set_DocAllPREFIKS_NUM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)=0;




//	TFIBLargeIntField *DocTIDTNOM_DCHKT;
//	TFIBLargeIntField *DocTIDDEPARTMENT_DCHKT;
//	TFIBIntegerField *DocTNUMOTDKKT_SDEPARTMENT;
//	TFIBWideStringField *DocTNAME_SDEPARTMENT;
//	TFIBWideStringField *DocTNAME_STNOM;
//	TFIBWideStringField *DocFISCALSIGN_DCHK;
//	TFIBWideStringField *DocPHONE_DCHK;
//	TFIBWideStringField *DocEMAIL_DCHK;



   __property TFIBLargeIntField * DocTIDTNOM_DCHKT = {read = get_DocTIDTNOM_DCHKT , write = set_DocTIDTNOM_DCHKT};
   virtual TFIBLargeIntField * get_DocTIDTNOM_DCHKT(void)=0;
   virtual void set_DocTIDTNOM_DCHKT(TFIBLargeIntField * DocTIDTNOM_DCHKT)=0;

   __property TFIBLargeIntField * DocTIDDEPARTMENT_DCHKT = {read = get_DocTIDDEPARTMENT_DCHKT , write = set_DocTIDDEPARTMENT_DCHKT};
   virtual TFIBLargeIntField * get_DocTIDDEPARTMENT_DCHKT(void)=0;
   virtual void set_DocTIDDEPARTMENT_DCHKT(TFIBLargeIntField * DocTIDDEPARTMENT_DCHKT)=0;

   __property TFIBIntegerField * DocTNUMOTDKKT_SDEPARTMENT = {read = get_DocTNUMOTDKKT_SDEPARTMENT , write = set_DocTNUMOTDKKT_SDEPARTMENT};
   virtual TFIBIntegerField * get_DocTNUMOTDKKT_SDEPARTMENT(void)=0;
   virtual void set_DocTNUMOTDKKT_SDEPARTMENT(TFIBIntegerField * DocTNUMOTDKKT_SDEPARTMENT)=0;


   __property TFIBWideStringField * DocTNAME_SDEPARTMENT = {read = get_DocTNAME_SDEPARTMENT , write = set_DocTNAME_SDEPARTMENT};
   virtual TFIBWideStringField * get_DocTNAME_SDEPARTMENT(void)=0;
   virtual void set_DocTNAME_SDEPARTMENT(TFIBWideStringField * DocTNAME_SDEPARTMENT)=0;

	  __property TFIBWideStringField * DocTNAME_STNOM = {read = get_DocTNAME_STNOM , write = set_DocTNAME_STNOM};
   virtual TFIBWideStringField * get_DocTNAME_STNOM(void)=0;
   virtual void set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)=0;

	  __property TFIBWideStringField * DocFISCALSIGN_DCHK = {read = get_DocFISCALSIGN_DCHK , write = set_DocFISCALSIGN_DCHK};
   virtual TFIBWideStringField * get_DocFISCALSIGN_DCHK(void)=0;
   virtual void set_DocFISCALSIGN_DCHK(TFIBWideStringField * DocFISCALSIGN_DCHK)=0;

	  __property TFIBWideStringField * DocPHONE_DCHK = {read = get_DocPHONE_DCHK , write = set_DocPHONE_DCHK};
   virtual TFIBWideStringField * get_DocPHONE_DCHK(void)=0;
   virtual void set_DocPHONE_DCHK(TFIBWideStringField * DocPHONE_DCHK)=0;

	  __property TFIBWideStringField * DocEMAIL_DCHK = {read = get_DocEMAIL_DCHK , write = set_DocEMAIL_DCHK};
   virtual TFIBWideStringField * get_DocEMAIL_DCHK(void)=0;
   virtual void set_DocEMAIL_DCHK(TFIBWideStringField * DocEMAIL_DCHK)=0;





   __property bool NewElement = {read = get_NewElement , write = set_NewElement};
   virtual bool get_NewElement(void)=0;
   virtual void set_NewElement(bool NewElement)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property UnicodeString ProsmotrText = {read = get_ProsmotrText , write = set_ProsmotrText};
   virtual UnicodeString get_ProsmotrText(void)=0;
   virtual void set_ProsmotrText(UnicodeString ProsmotrText)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElementaMaster = {read = get_IdElementaMaster , write = set_IdElementaMaster};
   virtual __int64 get_IdElementaMaster(void)=0;
   virtual void set_IdElementaMaster(__int64 IdElementaMaster)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property int Operation = {read = get_Operation , write = set_Operation};
   virtual int get_Operation(void)=0;
   virtual void set_Operation(int Operation)=0;

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
   virtual bool OpenDoc(__int64 IdDoc)=0;
   virtual void OpenDocOsn(void)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool BeforeSaveDoc(void)=0;
   virtual bool AfterSaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual void ValidateProsmotr(void)=0;
   virtual void AdddRecordInGurOperDiscountCard(void)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocCheck __uuidof(IDMDocCheck)
#endif
