#ifndef UIDMDocRKOH
#define UIDMDocRKOH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocRKO)) IDMDocRKO : public IMainInterface
{
public:
   __property TDataSource * DataSourceDoc = {read = get_DataSourceDoc , write = set_DataSourceDoc};
   virtual TDataSource * get_DataSourceDoc(void)=0;
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc)=0;

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

   __property TFIBSmallIntField * DocADDKDRRKO = {read = get_DocADDKDRRKO , write = set_DocADDKDRRKO};
   virtual TFIBSmallIntField * get_DocADDKDRRKO(void)=0;
   virtual void set_DocADDKDRRKO(TFIBSmallIntField * DocADDKDRRKO)=0;

   __property TFIBBCDField * DocSUMUSNRKO = {read = get_DocSUMUSNRKO , write = set_DocSUMUSNRKO};
   virtual TFIBBCDField * get_DocSUMUSNRKO(void)=0;
   virtual void set_DocSUMUSNRKO(TFIBBCDField * DocSUMUSNRKO)=0;

   __property TFIBSmallIntField * DocOPERATIONRKO = {read = get_DocOPERATIONRKO , write = set_DocOPERATIONRKO};
   virtual TFIBSmallIntField * get_DocOPERATIONRKO(void)=0;
   virtual void set_DocOPERATIONRKO(TFIBSmallIntField * DocOPERATIONRKO)=0;

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

   __property TFIBBCDField * DocIDRKO = {read = get_DocIDRKO , write = set_DocIDRKO};
   virtual TFIBBCDField * get_DocIDRKO(void)=0;
   virtual void set_DocIDRKO(TFIBBCDField * DocIDRKO)=0;

   __property TFIBBCDField * DocIDDOCRKO = {read = get_DocIDDOCRKO , write = set_DocIDDOCRKO};
   virtual TFIBBCDField * get_DocIDDOCRKO(void)=0;
   virtual void set_DocIDDOCRKO(TFIBBCDField * DocIDDOCRKO)=0;

   __property TFIBBCDField * DocIDKKMRKO = {read = get_DocIDKKMRKO , write = set_DocIDKKMRKO};
   virtual TFIBBCDField * get_DocIDKKMRKO(void)=0;
   virtual void set_DocIDKKMRKO(TFIBBCDField * DocIDKKMRKO)=0;

   __property TFIBBCDField * DocIDKLRKO = {read = get_DocIDKLRKO , write = set_DocIDKLRKO};
   virtual TFIBBCDField * get_DocIDKLRKO(void)=0;
   virtual void set_DocIDKLRKO(TFIBBCDField * DocIDKLRKO)=0;

   __property TFIBBCDField * DocAllIDEXTDOC = {read = get_DocAllIDEXTDOC , write = set_DocAllIDEXTDOC};
   virtual TFIBBCDField * get_DocAllIDEXTDOC(void)=0;
   virtual void set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC)=0;

   __property TFIBBCDField * DocIDBASE_DRKO = {read = get_DocIDBASE_DRKO , write = set_DocIDBASE_DRKO};
   virtual TFIBBCDField * get_DocIDBASE_DRKO(void)=0;
   virtual void set_DocIDBASE_DRKO(TFIBBCDField * DocIDBASE_DRKO)=0;

   __property TFIBBCDField * DocAllIDBASE_GALLDOC = {read = get_DocAllIDBASE_GALLDOC , write = set_DocAllIDBASE_GALLDOC};
   virtual TFIBBCDField * get_DocAllIDBASE_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC)=0;

   __property TFIBIntegerField * DocNDS_DRKO = {read = get_DocNDS_DRKO , write = set_DocNDS_DRKO};
   virtual TFIBIntegerField * get_DocNDS_DRKO(void)=0;
   virtual void set_DocNDS_DRKO(TFIBIntegerField * DocNDS_DRKO)=0;

   __property TFIBBCDField * DocSUMNDS_DRKO = {read = get_DocSUMNDS_DRKO , write = set_DocSUMNDS_DRKO};
   virtual TFIBBCDField * get_DocSUMNDS_DRKO(void)=0;
   virtual void set_DocSUMNDS_DRKO(TFIBBCDField * DocSUMNDS_DRKO)=0;

   __property TFIBWideStringField * DocAllGID_DOC = {read = get_DocAllGID_DOC , write = set_DocAllGID_DOC};
   virtual TFIBWideStringField * get_DocAllGID_DOC(void)=0;
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)=0;

   __property TFIBWideStringField * DocAllFNAME_USER = {read = get_DocAllFNAME_USER , write = set_DocAllFNAME_USER};
   virtual TFIBWideStringField * get_DocAllFNAME_USER(void)=0;
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocAllNAMEFIRM = {read = get_DocAllNAMEFIRM , write = set_DocAllNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void)=0;
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllNAMEKLIENT = {read = get_DocAllNAMEKLIENT , write = set_DocAllNAMEKLIENT};
   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void)=0;
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)=0;

   __property TFIBWideStringField * DocVIDATRKO = {read = get_DocVIDATRKO , write = set_DocVIDATRKO};
   virtual TFIBWideStringField * get_DocVIDATRKO(void)=0;
   virtual void set_DocVIDATRKO(TFIBWideStringField * DocVIDATRKO)=0;

   __property TFIBWideStringField * DocOSNRKO = {read = get_DocOSNRKO , write = set_DocOSNRKO};
   virtual TFIBWideStringField * get_DocOSNRKO(void)=0;
   virtual void set_DocOSNRKO(TFIBWideStringField * DocOSNRKO)=0;

   __property TFIBWideStringField * DocPRILRKO = {read = get_DocPRILRKO , write = set_DocPRILRKO};
   virtual TFIBWideStringField * get_DocPRILRKO(void)=0;
   virtual void set_DocPRILRKO(TFIBWideStringField * DocPRILRKO)=0;

   __property TFIBWideStringField * DocDOCPOLRKO = {read = get_DocDOCPOLRKO , write = set_DocDOCPOLRKO};
   virtual TFIBWideStringField * get_DocDOCPOLRKO(void)=0;
   virtual void set_DocDOCPOLRKO(TFIBWideStringField * DocDOCPOLRKO)=0;

   __property TFIBWideStringField * DocGID_DRKO = {read = get_DocGID_DRKO , write = set_DocGID_DRKO};
   virtual TFIBWideStringField * get_DocGID_DRKO(void)=0;
   virtual void set_DocGID_DRKO(TFIBWideStringField * DocGID_DRKO)=0;

   __property TFIBIntegerField * DocNKLRKO = {read = get_DocNKLRKO , write = set_DocNKLRKO};
   virtual TFIBIntegerField * get_DocNKLRKO(void)=0;
   virtual void set_DocNKLRKO(TFIBIntegerField * DocNKLRKO)=0;

   __property TFIBIntegerField * DocNCHECKRKO = {read = get_DocNCHECKRKO , write = set_DocNCHECKRKO};
   virtual TFIBIntegerField * get_DocNCHECKRKO(void)=0;
   virtual void set_DocNCHECKRKO(TFIBIntegerField * DocNCHECKRKO)=0;

   __property TFIBWideStringField * DocMODELRKO = {read = get_DocMODELRKO , write = set_DocMODELRKO};
   virtual TFIBWideStringField * get_DocMODELRKO(void)=0;
   virtual void set_DocMODELRKO(TFIBWideStringField * DocMODELRKO)=0;

   __property TFIBWideStringField * DocREGNUMRKO = {read = get_DocREGNUMRKO , write = set_DocREGNUMRKO};
   virtual TFIBWideStringField * get_DocREGNUMRKO(void)=0;
   virtual void set_DocREGNUMRKO(TFIBWideStringField * DocREGNUMRKO)=0;

   __property TFIBWideStringField * DocSAVNUMRKO = {read = get_DocSAVNUMRKO , write = set_DocSAVNUMRKO};
   virtual TFIBWideStringField * get_DocSAVNUMRKO(void)=0;
   virtual void set_DocSAVNUMRKO(TFIBWideStringField * DocSAVNUMRKO)=0;

   __property TFIBWideStringField * DocNAMEKKM = {read = get_DocNAMEKKM , write = set_DocNAMEKKM};
   virtual TFIBWideStringField * get_DocNAMEKKM(void)=0;
   virtual void set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM)=0;

   __property TFIBWideStringField * DocAllTDOC = {read = get_DocAllTDOC , write = set_DocAllTDOC};
   virtual TFIBWideStringField * get_DocAllTDOC(void)=0;
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)=0;

   __property TFIBIntegerField * DocAllTYPEEXTDOC = {read = get_DocAllTYPEEXTDOC , write = set_DocAllTYPEEXTDOC};
   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void)=0;
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)=0;

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

   __property TFIBWideStringField * DocKORRSCHET_DRKO = {read = get_DocKORRSCHET_DRKO , write = set_DocKORRSCHET_DRKO};
   virtual TFIBWideStringField * get_DocKORRSCHET_DRKO(void)=0;
   virtual void set_DocKORRSCHET_DRKO(TFIBWideStringField * DocKORRSCHET_DRKO)=0;

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
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocRKO __uuidof(IDMDocRKO)
#endif
