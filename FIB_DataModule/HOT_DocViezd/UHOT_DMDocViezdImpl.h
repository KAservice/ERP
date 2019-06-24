#ifndef UHOT_DMDocViezdImplH
#define UHOT_DMDocViezdImplH
#include "IHOT_DMDocViezd.h"
#include "UHOT_DMDocViezd.h"
//---------------------------------------------------------------
class __declspec(uuid("{FB4202D5-2E6A-4A8F-8659-F143B055197E}")) THOT_DMDocViezdImpl : public IHOT_DMDocViezd
{
public:
   THOT_DMDocViezdImpl();
   ~THOT_DMDocViezdImpl();
   THOT_DMDocViezd * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IHOT_DMDocViezd
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void);
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER);

   virtual TFIBDateTimeField * get_DocAllPOS_HOT_GALLDOC(void);
   virtual void set_DocAllPOS_HOT_GALLDOC(TFIBDateTimeField * DocAllPOS_HOT_GALLDOC);

   virtual TFIBSmallIntField * get_DocAllPR_HOT_GALLDOC(void);
   virtual void set_DocAllPR_HOT_GALLDOC(TFIBSmallIntField * DocAllPR_HOT_GALLDOC);

   virtual TFIBBCDField * get_DocAllSUM_HOT_GALLDOC(void);
   virtual void set_DocAllSUM_HOT_GALLDOC(TFIBBCDField * DocAllSUM_HOT_GALLDOC);

   virtual TFIBIntegerField * get_DocAllNUMBER_HOT_GALLDOC(void);
   virtual void set_DocAllNUMBER_HOT_GALLDOC(TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TFIBIntegerField * get_DocTKOLM_HOT_SOSTNF(void);
   virtual void set_DocTKOLM_HOT_SOSTNF(TFIBIntegerField * DocTKOLM_HOT_SOSTNF);

   virtual TFIBDateTimeField * get_DocTPOSNACH_HOT_SOSTNF(void);
   virtual void set_DocTPOSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTPOSNACH_HOT_SOSTNF);

   virtual TFIBDateTimeField * get_DocTPOSCON_HOT_SOSTNF(void);
   virtual void set_DocTPOSCON_HOT_SOSTNF(TFIBDateTimeField * DocTPOSCON_HOT_SOSTNF);

   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TFIBWideStringField * get_DocAllTDOC_HOT_GALLDOC(void);
   virtual void set_DocAllTDOC_HOT_GALLDOC(TFIBWideStringField * DocAllTDOC_HOT_GALLDOC);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocDESCR_HOT_DVIESD(void);
   virtual void set_DocDESCR_HOT_DVIESD(TFIBWideStringField * DocDESCR_HOT_DVIESD);

   virtual TFIBWideStringField * get_DocTNAME_HOT_SNF(void);
   virtual void set_DocTNAME_HOT_SNF(TFIBWideStringField * DocTNAME_HOT_SNF);

   virtual TFIBWideStringField * get_DocTNAME_HOT_SCATNOM(void);
   virtual void set_DocTNAME_HOT_SCATNOM(TFIBWideStringField * DocTNAME_HOT_SCATNOM);

   virtual TFIBWideStringField * get_DocTNAME_HOT_STYPEPOS(void);
   virtual void set_DocTNAME_HOT_STYPEPOS(TFIBWideStringField * DocTNAME_HOT_STYPEPOS);

   virtual TFIBWideStringField * get_DocTNAMEKLIENT(void);
   virtual void set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT);

   virtual TFIBWideStringField * get_DocTNAME_HOT_SSOSTNOM(void);
   virtual void set_DocTNAME_HOT_SSOSTNOM(TFIBWideStringField * DocTNAME_HOT_SSOSTNOM);

   virtual TFIBLargeIntField * get_DocAllID_HOT_GALLDOC(void);
   virtual void set_DocAllID_HOT_GALLDOC(TFIBLargeIntField * DocAllID_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDFIRM_HOT_GALLDOC(void);
   virtual void set_DocAllIDFIRM_HOT_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDKL_HOT_GALLDOC(void);
   virtual void set_DocAllIDKL_HOT_GALLDOC(TFIBLargeIntField * DocAllIDKL_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDUSER_HOT_GALLDOC(void);
   virtual void set_DocAllIDUSER_HOT_GALLDOC(TFIBLargeIntField * DocAllIDUSER_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOCOSN_HOT_GALLDOC(void);
   virtual void set_DocAllIDDOCOSN_HOT_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDBASE_HOT_GALLDOC(void);
   virtual void set_DocAllIDBASE_HOT_GALLDOC(TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocID_HOT_DVIESD(void);
   virtual void set_DocID_HOT_DVIESD(TFIBLargeIntField * DocID_HOT_DVIESD);

   virtual TFIBLargeIntField * get_DocIDDOCH_HOT_DVIESD(void);
   virtual void set_DocIDDOCH_HOT_DVIESD(TFIBLargeIntField * DocIDDOCH_HOT_DVIESD);

   virtual TFIBLargeIntField * get_DocIDBASE_HOT_DVIESD(void);
   virtual void set_DocIDBASE_HOT_DVIESD(TFIBLargeIntField * DocIDBASE_HOT_DVIESD);

   virtual TFIBLargeIntField * get_DocTID_HOT_DVIESDT(void);
   virtual void set_DocTID_HOT_DVIESDT(TFIBLargeIntField * DocTID_HOT_DVIESDT);

   virtual TFIBLargeIntField * get_DocTIDDOCH_HOT_DVIESDT(void);
   virtual void set_DocTIDDOCH_HOT_DVIESDT(TFIBLargeIntField * DocTIDDOCH_HOT_DVIESDT);

   virtual TFIBLargeIntField * get_DocTIDSOST_HOT_DVIESDT(void);
   virtual void set_DocTIDSOST_HOT_DVIESDT(TFIBLargeIntField * DocTIDSOST_HOT_DVIESDT);

   virtual TFIBLargeIntField * get_DocTIDBASE_HOT_DVIESDT(void);
   virtual void set_DocTIDBASE_HOT_DVIESDT(TFIBLargeIntField * DocTIDBASE_HOT_DVIESDT);

   virtual TFIBLargeIntField * get_DocTIDNOMER_HOT_SOSTNF(void);
   virtual void set_DocTIDNOMER_HOT_SOSTNF(TFIBLargeIntField * DocTIDNOMER_HOT_SOSTNF);

   virtual TFIBLargeIntField * get_DocTIDPLAT_HOT_SOSTNF(void);
   virtual void set_DocTIDPLAT_HOT_SOSTNF(TFIBLargeIntField * DocTIDPLAT_HOT_SOSTNF);

   virtual TFIBLargeIntField * get_DocTIDGUEST_HOT_SOSTNF(void);
   virtual void set_DocTIDGUEST_HOT_SOSTNF(TFIBLargeIntField * DocTIDGUEST_HOT_SOSTNF);

   virtual TFIBLargeIntField * get_DocTIDSOST_HOT_SOSTNF(void);
   virtual void set_DocTIDSOST_HOT_SOSTNF(TFIBLargeIntField * DocTIDSOST_HOT_SOSTNF);

   virtual TFIBLargeIntField * get_DocTIDTPOS_HOT_SOSTNF(void);
   virtual void set_DocTIDTPOS_HOT_SOSTNF(TFIBLargeIntField * DocTIDTPOS_HOT_SOSTNF);

   virtual TFIBLargeIntField * get_DocTIDCAT_HOT_SOSTNF(void);
   virtual void set_DocTIDCAT_HOT_SOSTNF(TFIBLargeIntField * DocTIDCAT_HOT_SOSTNF);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 IdDoc);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void CloseDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual void AddString(void);
   virtual void DeleteString(void);
};
#define CLSID_THOT_DMDocViezdImpl __uuidof(THOT_DMDocViezdImpl)
#endif
