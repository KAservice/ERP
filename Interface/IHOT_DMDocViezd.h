#ifndef UIHOT_DMDocViezdH
#define UIHOT_DMDocViezdH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{3A5E602C-BE44-4205-A5FC-EE6FD5E1FBD4}")) IHOT_DMDocViezd : public IMainInterface
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

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TFIBIntegerField * NumDocMAXNUMBER = {read = get_NumDocMAXNUMBER , write = set_NumDocMAXNUMBER};
   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void)=0;
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)=0;

   __property TFIBDateTimeField * DocAllPOS_HOT_GALLDOC = {read = get_DocAllPOS_HOT_GALLDOC , write = set_DocAllPOS_HOT_GALLDOC};
   virtual TFIBDateTimeField * get_DocAllPOS_HOT_GALLDOC(void)=0;
   virtual void set_DocAllPOS_HOT_GALLDOC(TFIBDateTimeField * DocAllPOS_HOT_GALLDOC)=0;

   __property TFIBSmallIntField * DocAllPR_HOT_GALLDOC = {read = get_DocAllPR_HOT_GALLDOC , write = set_DocAllPR_HOT_GALLDOC};
   virtual TFIBSmallIntField * get_DocAllPR_HOT_GALLDOC(void)=0;
   virtual void set_DocAllPR_HOT_GALLDOC(TFIBSmallIntField * DocAllPR_HOT_GALLDOC)=0;

   __property TFIBBCDField * DocAllSUM_HOT_GALLDOC = {read = get_DocAllSUM_HOT_GALLDOC , write = set_DocAllSUM_HOT_GALLDOC};
   virtual TFIBBCDField * get_DocAllSUM_HOT_GALLDOC(void)=0;
   virtual void set_DocAllSUM_HOT_GALLDOC(TFIBBCDField * DocAllSUM_HOT_GALLDOC)=0;

   __property TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC = {read = get_DocAllNUMBER_HOT_GALLDOC , write = set_DocAllNUMBER_HOT_GALLDOC};
   virtual TFIBIntegerField * get_DocAllNUMBER_HOT_GALLDOC(void)=0;
   virtual void set_DocAllNUMBER_HOT_GALLDOC(TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

   __property TFIBIntegerField * DocTKOLM_HOT_SOSTNF = {read = get_DocTKOLM_HOT_SOSTNF , write = set_DocTKOLM_HOT_SOSTNF};
   virtual TFIBIntegerField * get_DocTKOLM_HOT_SOSTNF(void)=0;
   virtual void set_DocTKOLM_HOT_SOSTNF(TFIBIntegerField * DocTKOLM_HOT_SOSTNF)=0;

   __property TFIBDateTimeField * DocTPOSNACH_HOT_SOSTNF = {read = get_DocTPOSNACH_HOT_SOSTNF , write = set_DocTPOSNACH_HOT_SOSTNF};
   virtual TFIBDateTimeField * get_DocTPOSNACH_HOT_SOSTNF(void)=0;
   virtual void set_DocTPOSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTPOSNACH_HOT_SOSTNF)=0;

   __property TFIBDateTimeField * DocTPOSCON_HOT_SOSTNF = {read = get_DocTPOSCON_HOT_SOSTNF , write = set_DocTPOSCON_HOT_SOSTNF};
   virtual TFIBDateTimeField * get_DocTPOSCON_HOT_SOSTNF(void)=0;
   virtual void set_DocTPOSCON_HOT_SOSTNF(TFIBDateTimeField * DocTPOSCON_HOT_SOSTNF)=0;

   __property TDataSource * DataSourceDocT = {read = get_DataSourceDocT , write = set_DataSourceDocT};
   virtual TDataSource * get_DataSourceDocT(void)=0;
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT)=0;

   __property TFIBWideStringField * DocAllTDOC_HOT_GALLDOC = {read = get_DocAllTDOC_HOT_GALLDOC , write = set_DocAllTDOC_HOT_GALLDOC};
   virtual TFIBWideStringField * get_DocAllTDOC_HOT_GALLDOC(void)=0;
   virtual void set_DocAllTDOC_HOT_GALLDOC(TFIBWideStringField * DocAllTDOC_HOT_GALLDOC)=0;

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

   __property TFIBWideStringField * DocDESCR_HOT_DVIESD = {read = get_DocDESCR_HOT_DVIESD , write = set_DocDESCR_HOT_DVIESD};
   virtual TFIBWideStringField * get_DocDESCR_HOT_DVIESD(void)=0;
   virtual void set_DocDESCR_HOT_DVIESD(TFIBWideStringField * DocDESCR_HOT_DVIESD)=0;

   __property TFIBWideStringField * DocTNAME_HOT_SNF = {read = get_DocTNAME_HOT_SNF , write = set_DocTNAME_HOT_SNF};
   virtual TFIBWideStringField * get_DocTNAME_HOT_SNF(void)=0;
   virtual void set_DocTNAME_HOT_SNF(TFIBWideStringField * DocTNAME_HOT_SNF)=0;

   __property TFIBWideStringField * DocTNAME_HOT_SCATNOM = {read = get_DocTNAME_HOT_SCATNOM , write = set_DocTNAME_HOT_SCATNOM};
   virtual TFIBWideStringField * get_DocTNAME_HOT_SCATNOM(void)=0;
   virtual void set_DocTNAME_HOT_SCATNOM(TFIBWideStringField * DocTNAME_HOT_SCATNOM)=0;

   __property TFIBWideStringField * DocTNAME_HOT_STYPEPOS = {read = get_DocTNAME_HOT_STYPEPOS , write = set_DocTNAME_HOT_STYPEPOS};
   virtual TFIBWideStringField * get_DocTNAME_HOT_STYPEPOS(void)=0;
   virtual void set_DocTNAME_HOT_STYPEPOS(TFIBWideStringField * DocTNAME_HOT_STYPEPOS)=0;

   __property TFIBWideStringField * DocTNAMEKLIENT = {read = get_DocTNAMEKLIENT , write = set_DocTNAMEKLIENT};
   virtual TFIBWideStringField * get_DocTNAMEKLIENT(void)=0;
   virtual void set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)=0;

   __property TFIBWideStringField * DocTNAME_HOT_SSOSTNOM = {read = get_DocTNAME_HOT_SSOSTNOM , write = set_DocTNAME_HOT_SSOSTNOM};
   virtual TFIBWideStringField * get_DocTNAME_HOT_SSOSTNOM(void)=0;
   virtual void set_DocTNAME_HOT_SSOSTNOM(TFIBWideStringField * DocTNAME_HOT_SSOSTNOM)=0;

   __property TFIBLargeIntField * DocAllID_HOT_GALLDOC = {read = get_DocAllID_HOT_GALLDOC , write = set_DocAllID_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllID_HOT_GALLDOC(void)=0;
   virtual void set_DocAllID_HOT_GALLDOC(TFIBLargeIntField * DocAllID_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDFIRM_HOT_GALLDOC = {read = get_DocAllIDFIRM_HOT_GALLDOC , write = set_DocAllIDFIRM_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDFIRM_HOT_GALLDOC(void)=0;
   virtual void set_DocAllIDFIRM_HOT_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDKL_HOT_GALLDOC = {read = get_DocAllIDKL_HOT_GALLDOC , write = set_DocAllIDKL_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDKL_HOT_GALLDOC(void)=0;
   virtual void set_DocAllIDKL_HOT_GALLDOC(TFIBLargeIntField * DocAllIDKL_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDUSER_HOT_GALLDOC = {read = get_DocAllIDUSER_HOT_GALLDOC , write = set_DocAllIDUSER_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDUSER_HOT_GALLDOC(void)=0;
   virtual void set_DocAllIDUSER_HOT_GALLDOC(TFIBLargeIntField * DocAllIDUSER_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDDOCOSN_HOT_GALLDOC = {read = get_DocAllIDDOCOSN_HOT_GALLDOC , write = set_DocAllIDDOCOSN_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOCOSN_HOT_GALLDOC(void)=0;
   virtual void set_DocAllIDDOCOSN_HOT_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC = {read = get_DocAllIDBASE_HOT_GALLDOC , write = set_DocAllIDBASE_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBASE_HOT_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_HOT_GALLDOC(TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocID_HOT_DVIESD = {read = get_DocID_HOT_DVIESD , write = set_DocID_HOT_DVIESD};
   virtual TFIBLargeIntField * get_DocID_HOT_DVIESD(void)=0;
   virtual void set_DocID_HOT_DVIESD(TFIBLargeIntField * DocID_HOT_DVIESD)=0;

   __property TFIBLargeIntField * DocIDDOCH_HOT_DVIESD = {read = get_DocIDDOCH_HOT_DVIESD , write = set_DocIDDOCH_HOT_DVIESD};
   virtual TFIBLargeIntField * get_DocIDDOCH_HOT_DVIESD(void)=0;
   virtual void set_DocIDDOCH_HOT_DVIESD(TFIBLargeIntField * DocIDDOCH_HOT_DVIESD)=0;

   __property TFIBLargeIntField * DocIDBASE_HOT_DVIESD = {read = get_DocIDBASE_HOT_DVIESD , write = set_DocIDBASE_HOT_DVIESD};
   virtual TFIBLargeIntField * get_DocIDBASE_HOT_DVIESD(void)=0;
   virtual void set_DocIDBASE_HOT_DVIESD(TFIBLargeIntField * DocIDBASE_HOT_DVIESD)=0;

   __property TFIBLargeIntField * DocTID_HOT_DVIESDT = {read = get_DocTID_HOT_DVIESDT , write = set_DocTID_HOT_DVIESDT};
   virtual TFIBLargeIntField * get_DocTID_HOT_DVIESDT(void)=0;
   virtual void set_DocTID_HOT_DVIESDT(TFIBLargeIntField * DocTID_HOT_DVIESDT)=0;

   __property TFIBLargeIntField * DocTIDDOCH_HOT_DVIESDT = {read = get_DocTIDDOCH_HOT_DVIESDT , write = set_DocTIDDOCH_HOT_DVIESDT};
   virtual TFIBLargeIntField * get_DocTIDDOCH_HOT_DVIESDT(void)=0;
   virtual void set_DocTIDDOCH_HOT_DVIESDT(TFIBLargeIntField * DocTIDDOCH_HOT_DVIESDT)=0;

   __property TFIBLargeIntField * DocTIDSOST_HOT_DVIESDT = {read = get_DocTIDSOST_HOT_DVIESDT , write = set_DocTIDSOST_HOT_DVIESDT};
   virtual TFIBLargeIntField * get_DocTIDSOST_HOT_DVIESDT(void)=0;
   virtual void set_DocTIDSOST_HOT_DVIESDT(TFIBLargeIntField * DocTIDSOST_HOT_DVIESDT)=0;

   __property TFIBLargeIntField * DocTIDBASE_HOT_DVIESDT = {read = get_DocTIDBASE_HOT_DVIESDT , write = set_DocTIDBASE_HOT_DVIESDT};
   virtual TFIBLargeIntField * get_DocTIDBASE_HOT_DVIESDT(void)=0;
   virtual void set_DocTIDBASE_HOT_DVIESDT(TFIBLargeIntField * DocTIDBASE_HOT_DVIESDT)=0;

   __property TFIBLargeIntField * DocTIDNOMER_HOT_SOSTNF = {read = get_DocTIDNOMER_HOT_SOSTNF , write = set_DocTIDNOMER_HOT_SOSTNF};
   virtual TFIBLargeIntField * get_DocTIDNOMER_HOT_SOSTNF(void)=0;
   virtual void set_DocTIDNOMER_HOT_SOSTNF(TFIBLargeIntField * DocTIDNOMER_HOT_SOSTNF)=0;

   __property TFIBLargeIntField * DocTIDPLAT_HOT_SOSTNF = {read = get_DocTIDPLAT_HOT_SOSTNF , write = set_DocTIDPLAT_HOT_SOSTNF};
   virtual TFIBLargeIntField * get_DocTIDPLAT_HOT_SOSTNF(void)=0;
   virtual void set_DocTIDPLAT_HOT_SOSTNF(TFIBLargeIntField * DocTIDPLAT_HOT_SOSTNF)=0;

   __property TFIBLargeIntField * DocTIDGUEST_HOT_SOSTNF = {read = get_DocTIDGUEST_HOT_SOSTNF , write = set_DocTIDGUEST_HOT_SOSTNF};
   virtual TFIBLargeIntField * get_DocTIDGUEST_HOT_SOSTNF(void)=0;
   virtual void set_DocTIDGUEST_HOT_SOSTNF(TFIBLargeIntField * DocTIDGUEST_HOT_SOSTNF)=0;

   __property TFIBLargeIntField * DocTIDSOST_HOT_SOSTNF = {read = get_DocTIDSOST_HOT_SOSTNF , write = set_DocTIDSOST_HOT_SOSTNF};
   virtual TFIBLargeIntField * get_DocTIDSOST_HOT_SOSTNF(void)=0;
   virtual void set_DocTIDSOST_HOT_SOSTNF(TFIBLargeIntField * DocTIDSOST_HOT_SOSTNF)=0;

   __property TFIBLargeIntField * DocTIDTPOS_HOT_SOSTNF = {read = get_DocTIDTPOS_HOT_SOSTNF , write = set_DocTIDTPOS_HOT_SOSTNF};
   virtual TFIBLargeIntField * get_DocTIDTPOS_HOT_SOSTNF(void)=0;
   virtual void set_DocTIDTPOS_HOT_SOSTNF(TFIBLargeIntField * DocTIDTPOS_HOT_SOSTNF)=0;

   __property TFIBLargeIntField * DocTIDCAT_HOT_SOSTNF = {read = get_DocTIDCAT_HOT_SOSTNF , write = set_DocTIDCAT_HOT_SOSTNF};
   virtual TFIBLargeIntField * get_DocTIDCAT_HOT_SOSTNF(void)=0;
   virtual void set_DocTIDCAT_HOT_SOSTNF(TFIBLargeIntField * DocTIDCAT_HOT_SOSTNF)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 IdDoc)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual void AddString(void)=0;
   virtual void DeleteString(void)=0;
};
#define IID_IHOT_DMDocViezd __uuidof(IHOT_DMDocViezd)
#endif
