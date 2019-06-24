#ifndef UIDMDocVipBankaH
#define UIDMDocVipBankaH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocVipBanka)) IDMDocVipBanka : public IMainInterface
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

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TFIBBCDField * DocAllIDDOC = {read = get_DocAllIDDOC , write = set_DocAllIDDOC};
   virtual TFIBBCDField * get_DocAllIDDOC(void)=0;
   virtual void set_DocAllIDDOC(TFIBBCDField * DocAllIDDOC)=0;

   __property TFIBDateTimeField * DocAllPOSDOC = {read = get_DocAllPOSDOC , write = set_DocAllPOSDOC};
   virtual TFIBDateTimeField * get_DocAllPOSDOC(void)=0;
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)=0;

   __property TFIBSmallIntField * DocAllPRDOC = {read = get_DocAllPRDOC , write = set_DocAllPRDOC};
   virtual TFIBSmallIntField * get_DocAllPRDOC(void)=0;
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)=0;

   __property TFIBIntegerField * DocAllNUMDOC = {read = get_DocAllNUMDOC , write = set_DocAllNUMDOC};
   virtual TFIBIntegerField * get_DocAllNUMDOC(void)=0;
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)=0;

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

   __property TFIBBCDField * DocAllSUMDOC = {read = get_DocAllSUMDOC , write = set_DocAllSUMDOC};
   virtual TFIBBCDField * get_DocAllSUMDOC(void)=0;
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)=0;

   __property TFIBBCDField * DocAllIDUSERDOC = {read = get_DocAllIDUSERDOC , write = set_DocAllIDUSERDOC};
   virtual TFIBBCDField * get_DocAllIDUSERDOC(void)=0;
   virtual void set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC)=0;

   __property TFIBBCDField * DocAllIDDOCOSNDOC = {read = get_DocAllIDDOCOSNDOC , write = set_DocAllIDDOCOSNDOC};
   virtual TFIBBCDField * get_DocAllIDDOCOSNDOC(void)=0;
   virtual void set_DocAllIDDOCOSNDOC(TFIBBCDField * DocAllIDDOCOSNDOC)=0;

   __property TFIBBCDField * DocAllIDEXTDOC = {read = get_DocAllIDEXTDOC , write = set_DocAllIDEXTDOC};
   virtual TFIBBCDField * get_DocAllIDEXTDOC(void)=0;
   virtual void set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC)=0;

   __property TFIBBCDField * DocAllIDBASE_GALLDOC = {read = get_DocAllIDBASE_GALLDOC , write = set_DocAllIDBASE_GALLDOC};
   virtual TFIBBCDField * get_DocAllIDBASE_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBBCDField * DocID_DVIPBANK = {read = get_DocID_DVIPBANK , write = set_DocID_DVIPBANK};
   virtual TFIBBCDField * get_DocID_DVIPBANK(void)=0;
   virtual void set_DocID_DVIPBANK(TFIBBCDField * DocID_DVIPBANK)=0;

   __property TFIBBCDField * DocIDDOC_DVIPBANK = {read = get_DocIDDOC_DVIPBANK , write = set_DocIDDOC_DVIPBANK};
   virtual TFIBBCDField * get_DocIDDOC_DVIPBANK(void)=0;
   virtual void set_DocIDDOC_DVIPBANK(TFIBBCDField * DocIDDOC_DVIPBANK)=0;

   __property TFIBBCDField * DocIDBASE_DVIPBANK = {read = get_DocIDBASE_DVIPBANK , write = set_DocIDBASE_DVIPBANK};
   virtual TFIBBCDField * get_DocIDBASE_DVIPBANK(void)=0;
   virtual void set_DocIDBASE_DVIPBANK(TFIBBCDField * DocIDBASE_DVIPBANK)=0;

   __property TFIBBCDField * DocIDBSCHET_DVIPBANK = {read = get_DocIDBSCHET_DVIPBANK , write = set_DocIDBSCHET_DVIPBANK};
   virtual TFIBBCDField * get_DocIDBSCHET_DVIPBANK(void)=0;
   virtual void set_DocIDBSCHET_DVIPBANK(TFIBBCDField * DocIDBSCHET_DVIPBANK)=0;

   __property TFIBBCDField * DocTID_DVIPBANKT = {read = get_DocTID_DVIPBANKT , write = set_DocTID_DVIPBANKT};
   virtual TFIBBCDField * get_DocTID_DVIPBANKT(void)=0;
   virtual void set_DocTID_DVIPBANKT(TFIBBCDField * DocTID_DVIPBANKT)=0;

   __property TFIBBCDField * DocTIDBASE_DVIPBANKT = {read = get_DocTIDBASE_DVIPBANKT , write = set_DocTIDBASE_DVIPBANKT};
   virtual TFIBBCDField * get_DocTIDBASE_DVIPBANKT(void)=0;
   virtual void set_DocTIDBASE_DVIPBANKT(TFIBBCDField * DocTIDBASE_DVIPBANKT)=0;

   __property TFIBBCDField * DocTIDDOC_DVIPBANKT = {read = get_DocTIDDOC_DVIPBANKT , write = set_DocTIDDOC_DVIPBANKT};
   virtual TFIBBCDField * get_DocTIDDOC_DVIPBANKT(void)=0;
   virtual void set_DocTIDDOC_DVIPBANKT(TFIBBCDField * DocTIDDOC_DVIPBANKT)=0;

   __property TFIBBCDField * DocTIDKLIENT_DVIPBANKT = {read = get_DocTIDKLIENT_DVIPBANKT , write = set_DocTIDKLIENT_DVIPBANKT};
   virtual TFIBBCDField * get_DocTIDKLIENT_DVIPBANKT(void)=0;
   virtual void set_DocTIDKLIENT_DVIPBANKT(TFIBBCDField * DocTIDKLIENT_DVIPBANKT)=0;

   __property TFIBDateField * DocTDATEPP_DVIPBANKT = {read = get_DocTDATEPP_DVIPBANKT , write = set_DocTDATEPP_DVIPBANKT};
   virtual TFIBDateField * get_DocTDATEPP_DVIPBANKT(void)=0;
   virtual void set_DocTDATEPP_DVIPBANKT(TFIBDateField * DocTDATEPP_DVIPBANKT)=0;

   __property TFIBBCDField * DocTPRIHOD_DVIPBANKT = {read = get_DocTPRIHOD_DVIPBANKT , write = set_DocTPRIHOD_DVIPBANKT};
   virtual TFIBBCDField * get_DocTPRIHOD_DVIPBANKT(void)=0;
   virtual void set_DocTPRIHOD_DVIPBANKT(TFIBBCDField * DocTPRIHOD_DVIPBANKT)=0;

   __property TFIBIntegerField * DocTPRIHODNDS_DVIPBANKT = {read = get_DocTPRIHODNDS_DVIPBANKT , write = set_DocTPRIHODNDS_DVIPBANKT};
   virtual TFIBIntegerField * get_DocTPRIHODNDS_DVIPBANKT(void)=0;
   virtual void set_DocTPRIHODNDS_DVIPBANKT(TFIBIntegerField * DocTPRIHODNDS_DVIPBANKT)=0;

   __property TFIBBCDField * DocTPRIHODSUMNDS_DVIPBANKT = {read = get_DocTPRIHODSUMNDS_DVIPBANKT , write = set_DocTPRIHODSUMNDS_DVIPBANKT};
   virtual TFIBBCDField * get_DocTPRIHODSUMNDS_DVIPBANKT(void)=0;
   virtual void set_DocTPRIHODSUMNDS_DVIPBANKT(TFIBBCDField * DocTPRIHODSUMNDS_DVIPBANKT)=0;

   __property TFIBBCDField * DocTRASHOD_DVIPBANKT = {read = get_DocTRASHOD_DVIPBANKT , write = set_DocTRASHOD_DVIPBANKT};
   virtual TFIBBCDField * get_DocTRASHOD_DVIPBANKT(void)=0;
   virtual void set_DocTRASHOD_DVIPBANKT(TFIBBCDField * DocTRASHOD_DVIPBANKT)=0;

   __property TFIBIntegerField * DocTRASHODNDS_DVIPBANKT = {read = get_DocTRASHODNDS_DVIPBANKT , write = set_DocTRASHODNDS_DVIPBANKT};
   virtual TFIBIntegerField * get_DocTRASHODNDS_DVIPBANKT(void)=0;
   virtual void set_DocTRASHODNDS_DVIPBANKT(TFIBIntegerField * DocTRASHODNDS_DVIPBANKT)=0;

   __property TFIBBCDField * DocTRASHODSUMNDS_DVIPBANKT = {read = get_DocTRASHODSUMNDS_DVIPBANKT , write = set_DocTRASHODSUMNDS_DVIPBANKT};
   virtual TFIBBCDField * get_DocTRASHODSUMNDS_DVIPBANKT(void)=0;
   virtual void set_DocTRASHODSUMNDS_DVIPBANKT(TFIBBCDField * DocTRASHODSUMNDS_DVIPBANKT)=0;

   __property TFIBIntegerField * DocTOPER_DVIPBANKT = {read = get_DocTOPER_DVIPBANKT , write = set_DocTOPER_DVIPBANKT};
   virtual TFIBIntegerField * get_DocTOPER_DVIPBANKT(void)=0;
   virtual void set_DocTOPER_DVIPBANKT(TFIBIntegerField * DocTOPER_DVIPBANKT)=0;

   __property TFIBWideStringField * DocAllTDOC = {read = get_DocAllTDOC , write = set_DocAllTDOC};
   virtual TFIBWideStringField * get_DocAllTDOC(void)=0;
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)=0;

   __property TFIBWideStringField * DocAllGID_DOC = {read = get_DocAllGID_DOC , write = set_DocAllGID_DOC};
   virtual TFIBWideStringField * get_DocAllGID_DOC(void)=0;
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)=0;

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

   __property TFIBWideStringField * DocPRIM_DVIPBANK = {read = get_DocPRIM_DVIPBANK , write = set_DocPRIM_DVIPBANK};
   virtual TFIBWideStringField * get_DocPRIM_DVIPBANK(void)=0;
   virtual void set_DocPRIM_DVIPBANK(TFIBWideStringField * DocPRIM_DVIPBANK)=0;

   __property TFIBWideStringField * DocNAMEBSCHET = {read = get_DocNAMEBSCHET , write = set_DocNAMEBSCHET};
   virtual TFIBWideStringField * get_DocNAMEBSCHET(void)=0;
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)=0;

   __property TFIBWideStringField * DocTNUMPP_DVIPBANKT = {read = get_DocTNUMPP_DVIPBANKT , write = set_DocTNUMPP_DVIPBANKT};
   virtual TFIBWideStringField * get_DocTNUMPP_DVIPBANKT(void)=0;
   virtual void set_DocTNUMPP_DVIPBANKT(TFIBWideStringField * DocTNUMPP_DVIPBANKT)=0;

   __property TFIBWideStringField * DocTTEXTPP_DVIPBANKT = {read = get_DocTTEXTPP_DVIPBANKT , write = set_DocTTEXTPP_DVIPBANKT};
   virtual TFIBWideStringField * get_DocTTEXTPP_DVIPBANKT(void)=0;
   virtual void set_DocTTEXTPP_DVIPBANKT(TFIBWideStringField * DocTTEXTPP_DVIPBANKT)=0;

   __property TFIBWideStringField * DocTNAMEKLIENT = {read = get_DocTNAMEKLIENT , write = set_DocTNAMEKLIENT};
   virtual TFIBWideStringField * get_DocTNAMEKLIENT(void)=0;
   virtual void set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)=0;

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

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   virtual bool NewDoc(void)=0;
   virtual bool OpenDoc(__int64 IdDoc)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void TableAppend(void)=0;
   virtual void TableDelete(void)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocVipBanka __uuidof(IDMDocVipBanka)
#endif
