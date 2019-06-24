#ifndef UIDMDocPlPH
#define UIDMDocPlPH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocPlP)) IDMDocPlP : public IMainInterface
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

   __property TFIBLargeIntField * DocIDPLP = {read = get_DocIDPLP , write = set_DocIDPLP};
   virtual TFIBLargeIntField * get_DocIDPLP(void)=0;
   virtual void set_DocIDPLP(TFIBLargeIntField * DocIDPLP)=0;

   __property TFIBLargeIntField * DocIDDOCPLP = {read = get_DocIDDOCPLP , write = set_DocIDDOCPLP};
   virtual TFIBLargeIntField * get_DocIDDOCPLP(void)=0;
   virtual void set_DocIDDOCPLP(TFIBLargeIntField * DocIDDOCPLP)=0;

   __property TFIBLargeIntField * DocIDBSCHPLP = {read = get_DocIDBSCHPLP , write = set_DocIDBSCHPLP};
   virtual TFIBLargeIntField * get_DocIDBSCHPLP(void)=0;
   virtual void set_DocIDBSCHPLP(TFIBLargeIntField * DocIDBSCHPLP)=0;

   __property TFIBLargeIntField * DocIDRSCHPLP = {read = get_DocIDRSCHPLP , write = set_DocIDRSCHPLP};
   virtual TFIBLargeIntField * get_DocIDRSCHPLP(void)=0;
   virtual void set_DocIDRSCHPLP(TFIBLargeIntField * DocIDRSCHPLP)=0;

   __property TFIBIntegerField * DocVIDPLP = {read = get_DocVIDPLP , write = set_DocVIDPLP};
   virtual TFIBIntegerField * get_DocVIDPLP(void)=0;
   virtual void set_DocVIDPLP(TFIBIntegerField * DocVIDPLP)=0;

   __property TFIBIntegerField * DocOCHPLP = {read = get_DocOCHPLP , write = set_DocOCHPLP};
   virtual TFIBIntegerField * get_DocOCHPLP(void)=0;
   virtual void set_DocOCHPLP(TFIBIntegerField * DocOCHPLP)=0;

   __property TFIBDateField * DocSROKPLP = {read = get_DocSROKPLP , write = set_DocSROKPLP};
   virtual TFIBDateField * get_DocSROKPLP(void)=0;
   virtual void set_DocSROKPLP(TFIBDateField * DocSROKPLP)=0;

   __property TFIBWideStringField * DocNASNPLP = {read = get_DocNASNPLP , write = set_DocNASNPLP};
   virtual TFIBWideStringField * get_DocNASNPLP(void)=0;
   virtual void set_DocNASNPLP(TFIBWideStringField * DocNASNPLP)=0;

   __property TFIBWideStringField * DocGID_DPLP = {read = get_DocGID_DPLP , write = set_DocGID_DPLP};
   virtual TFIBWideStringField * get_DocGID_DPLP(void)=0;
   virtual void set_DocGID_DPLP(TFIBWideStringField * DocGID_DPLP)=0;

   __property TFIBIntegerField * DocADDKDRPLP = {read = get_DocADDKDRPLP , write = set_DocADDKDRPLP};
   virtual TFIBIntegerField * get_DocADDKDRPLP(void)=0;
   virtual void set_DocADDKDRPLP(TFIBIntegerField * DocADDKDRPLP)=0;

   __property TFIBIntegerField * DocOPERATIONPLP = {read = get_DocOPERATIONPLP , write = set_DocOPERATIONPLP};
   virtual TFIBIntegerField * get_DocOPERATIONPLP(void)=0;
   virtual void set_DocOPERATIONPLP(TFIBIntegerField * DocOPERATIONPLP)=0;

   __property TFIBBCDField * DocSUMUSNPLP = {read = get_DocSUMUSNPLP , write = set_DocSUMUSNPLP};
   virtual TFIBBCDField * get_DocSUMUSNPLP(void)=0;
   virtual void set_DocSUMUSNPLP(TFIBBCDField * DocSUMUSNPLP)=0;

   __property TFIBWideStringField * DocNALOG_STATUS_PLP = {read = get_DocNALOG_STATUS_PLP , write = set_DocNALOG_STATUS_PLP};
   virtual TFIBWideStringField * get_DocNALOG_STATUS_PLP(void)=0;
   virtual void set_DocNALOG_STATUS_PLP(TFIBWideStringField * DocNALOG_STATUS_PLP)=0;

   __property TFIBWideStringField * DocNALOG_OSN_PLP = {read = get_DocNALOG_OSN_PLP , write = set_DocNALOG_OSN_PLP};
   virtual TFIBWideStringField * get_DocNALOG_OSN_PLP(void)=0;
   virtual void set_DocNALOG_OSN_PLP(TFIBWideStringField * DocNALOG_OSN_PLP)=0;

   __property TFIBWideStringField * DocNALOG_NUM_PLP = {read = get_DocNALOG_NUM_PLP , write = set_DocNALOG_NUM_PLP};
   virtual TFIBWideStringField * get_DocNALOG_NUM_PLP(void)=0;
   virtual void set_DocNALOG_NUM_PLP(TFIBWideStringField * DocNALOG_NUM_PLP)=0;

   __property TFIBWideStringField * DocNALOG_TPLAT_PLP = {read = get_DocNALOG_TPLAT_PLP , write = set_DocNALOG_TPLAT_PLP};
   virtual TFIBWideStringField * get_DocNALOG_TPLAT_PLP(void)=0;
   virtual void set_DocNALOG_TPLAT_PLP(TFIBWideStringField * DocNALOG_TPLAT_PLP)=0;

   __property TFIBWideStringField * DocNALOG_KBK_PLP = {read = get_DocNALOG_KBK_PLP , write = set_DocNALOG_KBK_PLP};
   virtual TFIBWideStringField * get_DocNALOG_KBK_PLP(void)=0;
   virtual void set_DocNALOG_KBK_PLP(TFIBWideStringField * DocNALOG_KBK_PLP)=0;

   __property TFIBWideStringField * DocNALOG_OKATO_PLP = {read = get_DocNALOG_OKATO_PLP , write = set_DocNALOG_OKATO_PLP};
   virtual TFIBWideStringField * get_DocNALOG_OKATO_PLP(void)=0;
   virtual void set_DocNALOG_OKATO_PLP(TFIBWideStringField * DocNALOG_OKATO_PLP)=0;

   __property TFIBWideStringField * DocNALOG_PERIOD_PLP = {read = get_DocNALOG_PERIOD_PLP , write = set_DocNALOG_PERIOD_PLP};
   virtual TFIBWideStringField * get_DocNALOG_PERIOD_PLP(void)=0;
   virtual void set_DocNALOG_PERIOD_PLP(TFIBWideStringField * DocNALOG_PERIOD_PLP)=0;

   __property TFIBDateField * DocNALOG_DATE_PLP = {read = get_DocNALOG_DATE_PLP , write = set_DocNALOG_DATE_PLP};
   virtual TFIBDateField * get_DocNALOG_DATE_PLP(void)=0;
   virtual void set_DocNALOG_DATE_PLP(TFIBDateField * DocNALOG_DATE_PLP)=0;

   __property TFIBLargeIntField * DocIDBASE_DPLP = {read = get_DocIDBASE_DPLP , write = set_DocIDBASE_DPLP};
   virtual TFIBLargeIntField * get_DocIDBASE_DPLP(void)=0;
   virtual void set_DocIDBASE_DPLP(TFIBLargeIntField * DocIDBASE_DPLP)=0;

   __property TFIBIntegerField * DocNDS_DPLP = {read = get_DocNDS_DPLP , write = set_DocNDS_DPLP};
   virtual TFIBIntegerField * get_DocNDS_DPLP(void)=0;
   virtual void set_DocNDS_DPLP(TFIBIntegerField * DocNDS_DPLP)=0;

   __property TFIBBCDField * DocSUMNDS_DPLP = {read = get_DocSUMNDS_DPLP , write = set_DocSUMNDS_DPLP};
   virtual TFIBBCDField * get_DocSUMNDS_DPLP(void)=0;
   virtual void set_DocSUMNDS_DPLP(TFIBBCDField * DocSUMNDS_DPLP)=0;

   __property TFIBWideStringField * DocNAMEBSCHET = {read = get_DocNAMEBSCHET , write = set_DocNAMEBSCHET};
   virtual TFIBWideStringField * get_DocNAMEBSCHET(void)=0;
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)=0;

   __property TFIBWideStringField * DocNAMERSCHET = {read = get_DocNAMERSCHET , write = set_DocNAMERSCHET};
   virtual TFIBWideStringField * get_DocNAMERSCHET(void)=0;
   virtual void set_DocNAMERSCHET(TFIBWideStringField * DocNAMERSCHET)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocAllNAMEFIRM = {read = get_DocAllNAMEFIRM , write = set_DocAllNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void)=0;
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllNAMEKLIENT = {read = get_DocAllNAMEKLIENT , write = set_DocAllNAMEKLIENT};
   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void)=0;
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)=0;

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

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 id)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocPlP __uuidof(IDMDocPlP)
#endif
