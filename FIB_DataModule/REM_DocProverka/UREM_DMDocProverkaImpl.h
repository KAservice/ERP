#ifndef UREM_DMDocProverkaImplH
#define UREM_DMDocProverkaImplH
#include "IREM_DMDocProverka.h"
#include "UREM_DMDocProverka.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocProverkaImpl)) TREM_DMDocProverkaImpl : public IREM_DMDocProverka
{
public:
   TREM_DMDocProverkaImpl();
   ~TREM_DMDocProverkaImpl();
   TREM_DMDocProverka * Object;
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

//IREM_DMDocProverka
   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void);
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER);

   virtual TFIBLargeIntField * get_DocAllID_REM_GUR_PROV(void);
   virtual void set_DocAllID_REM_GUR_PROV(TFIBLargeIntField * DocAllID_REM_GUR_PROV);

   virtual TFIBLargeIntField * get_DocAllIDBASE_REM_GUR_PROV(void);
   virtual void set_DocAllIDBASE_REM_GUR_PROV(TFIBLargeIntField * DocAllIDBASE_REM_GUR_PROV);

   virtual TFIBDateTimeField * get_DocAllPOS_REM_GUR_PROV(void);
   virtual void set_DocAllPOS_REM_GUR_PROV(TFIBDateTimeField * DocAllPOS_REM_GUR_PROV);

   virtual TFIBIntegerField * get_DocAllNUM_REM_GUR_PROV(void);
   virtual void set_DocAllNUM_REM_GUR_PROV(TFIBIntegerField * DocAllNUM_REM_GUR_PROV);

   virtual TFIBWideStringField * get_DocAllDESCR_REM_GUR_PROV(void);
   virtual void set_DocAllDESCR_REM_GUR_PROV(TFIBWideStringField * DocAllDESCR_REM_GUR_PROV);

   virtual TFIBLargeIntField * get_DocAllIDDOC_REM_GUR_PROV(void);
   virtual void set_DocAllIDDOC_REM_GUR_PROV(TFIBLargeIntField * DocAllIDDOC_REM_GUR_PROV);

   virtual TFIBLargeIntField * get_DocAllIDUSER_REM_GUR_PROV(void);
   virtual void set_DocAllIDUSER_REM_GUR_PROV(TFIBLargeIntField * DocAllIDUSER_REM_GUR_PROV);

   virtual TFIBIntegerField * get_DocAllRES_REM_GUR_PROV(void);
   virtual void set_DocAllRES_REM_GUR_PROV(TFIBIntegerField * DocAllRES_REM_GUR_PROV);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocAllNAME_USER_DOC(void);
   virtual void set_DocAllNAME_USER_DOC(TFIBWideStringField * DocAllNAME_USER_DOC);

   virtual TFIBWideStringField * get_DocAllNAME_USER_PROV(void);
   virtual void set_DocAllNAME_USER_PROV(TFIBWideStringField * DocAllNAME_USER_PROV);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC);

   virtual TFIBSmallIntField * get_DocAllPR_REM_GALLDOC(void);
   virtual void set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC);

   virtual TFIBIntegerField * get_DocAllNUM_REM_GALLDOC(void);
   virtual void set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC);

   virtual TFIBDateTimeField * get_DocAllPOS_REM_GALLDOC(void);
   virtual void set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocAllTDOC_REM_GALLDOC(void);
   virtual void set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool NewDoc(void);
   virtual bool OpenDoc(__int64 id);
   virtual bool SaveDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TREM_DMDocProverkaImpl __uuidof(TREM_DMDocProverkaImpl)
#endif
