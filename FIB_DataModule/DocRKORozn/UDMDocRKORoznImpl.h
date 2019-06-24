#ifndef UDMDocRKORoznImplH
#define UDMDocRKORoznImplH
#include "IDMDocRKORozn.h"
#include "UDMDocRKORozn.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocRKORoznImpl)) TDMDocRKORoznImpl : public IDMDocRKORozn
{
public:
   TDMDocRKORoznImpl();
   ~TDMDocRKORoznImpl();
   TDMDocRKORozn * Object;
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

//IDMDocRKORozn
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TFIBDateTimeField * get_DocAllPOSDOC(void);
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC);

   virtual TFIBSmallIntField * get_DocAllPRDOC(void);
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC);

   virtual TFIBIntegerField * get_DocAllNUMDOC(void);
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC);

   virtual TFIBBCDField * get_DocAllSUMDOC(void);
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC);

   virtual TFIBIntegerField * get_DocOPERATION_DRKOROZN(void);
   virtual void set_DocOPERATION_DRKOROZN(TFIBIntegerField * DocOPERATION_DRKOROZN);

   virtual TpFIBDataSet * get_pFIBQAdvance(void);
   virtual void set_pFIBQAdvance(TpFIBDataSet * pFIBQAdvance);

   virtual TFIBBCDField * get_pFIBQAdvanceSUM_RGADVCUST(void);
   virtual void set_pFIBQAdvanceSUM_RGADVCUST(TFIBBCDField * pFIBQAdvanceSUM_RGADVCUST);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBIntegerField * get_DocNDS_DRKOROZN(void);
   virtual void set_DocNDS_DRKOROZN(TFIBIntegerField * DocNDS_DRKOROZN);

   virtual TFIBBCDField * get_DocSUMNDS_DRKOROZN(void);
   virtual void set_DocSUMNDS_DRKOROZN(TFIBBCDField * DocSUMNDS_DRKOROZN);

   virtual TFIBLargeIntField * get_DocAllIDDOC(void);
   virtual void set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC);

   virtual TFIBLargeIntField * get_DocAllIDFIRMDOC(void);
   virtual void set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC);

   virtual TFIBLargeIntField * get_DocAllIDSKLDOC(void);
   virtual void set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC);

   virtual TFIBLargeIntField * get_DocAllIDKLDOC(void);
   virtual void set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOGDOC(void);
   virtual void set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC);

   virtual TFIBLargeIntField * get_DocAllIDUSERDOC(void);
   virtual void set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOCOSNDOC(void);
   virtual void set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC);

   virtual TFIBLargeIntField * get_DocAllIDEXTDOC(void);
   virtual void set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC);

   virtual TFIBLargeIntField * get_DocAllIDBASE_GALLDOC(void);
   virtual void set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDPROJECT_GALLDOC(void);
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC);

   virtual TFIBLargeIntField * get_DocID_DRKOROZN(void);
   virtual void set_DocID_DRKOROZN(TFIBLargeIntField * DocID_DRKOROZN);

   virtual TFIBLargeIntField * get_DocIDDOC_DRKOROZN(void);
   virtual void set_DocIDDOC_DRKOROZN(TFIBLargeIntField * DocIDDOC_DRKOROZN);

   virtual TFIBLargeIntField * get_DocIDKKM_DRKOROZN(void);
   virtual void set_DocIDKKM_DRKOROZN(TFIBLargeIntField * DocIDKKM_DRKOROZN);

   virtual TFIBLargeIntField * get_DocIDBASE_DRKOROZN(void);
   virtual void set_DocIDBASE_DRKOROZN(TFIBLargeIntField * DocIDBASE_DRKOROZN);

   virtual TFIBLargeIntField * get_DocIDCARD_DRKOROZN(void);
   virtual void set_DocIDCARD_DRKOROZN(TFIBLargeIntField * DocIDCARD_DRKOROZN);

   virtual TFIBWideStringField * get_DocAllGID_DOC(void);
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC);

   virtual TFIBWideStringField * get_DocAllPREFIKSDOC(void);
   virtual void set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC);

   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void);
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocAllNAME_SDOG(void);
   virtual void set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG);

   virtual TFIBWideStringField * get_DocGID_DRKOROZN(void);
   virtual void set_DocGID_DRKOROZN(TFIBWideStringField * DocGID_DRKOROZN);

   virtual TFIBWideStringField * get_DocVIDAT_DRKOROZN(void);
   virtual void set_DocVIDAT_DRKOROZN(TFIBWideStringField * DocVIDAT_DRKOROZN);

   virtual TFIBWideStringField * get_DocOSN_DRKOROZN(void);
   virtual void set_DocOSN_DRKOROZN(TFIBWideStringField * DocOSN_DRKOROZN);

   virtual TFIBWideStringField * get_DocPRIM_DRKOROZN(void);
   virtual void set_DocPRIM_DRKOROZN(TFIBWideStringField * DocPRIM_DRKOROZN);

   virtual TFIBIntegerField * get_DocNCHECK_DRKOROZN(void);
   virtual void set_DocNCHECK_DRKOROZN(TFIBIntegerField * DocNCHECK_DRKOROZN);

   virtual TFIBIntegerField * get_DocNKL_DRKOROZN(void);
   virtual void set_DocNKL_DRKOROZN(TFIBIntegerField * DocNKL_DRKOROZN);

   virtual TFIBWideStringField * get_DocMODEL_DRKOROZN(void);
   virtual void set_DocMODEL_DRKOROZN(TFIBWideStringField * DocMODEL_DRKOROZN);

   virtual TFIBWideStringField * get_DocREGNUM_DRKOROZN(void);
   virtual void set_DocREGNUM_DRKOROZN(TFIBWideStringField * DocREGNUM_DRKOROZN);

   virtual TFIBWideStringField * get_DocSAVNUM_DRKOROZN(void);
   virtual void set_DocSAVNUM_DRKOROZN(TFIBWideStringField * DocSAVNUM_DRKOROZN);

   virtual TFIBWideStringField * get_DocNAMEKKM(void);
   virtual void set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM);

   virtual TFIBWideStringField * get_DocNAME_SDISCOUNT_CARD(void);
   virtual void set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 IdDoc);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void CloseDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocRKORoznImpl __uuidof(TDMDocRKORoznImpl)
#endif
