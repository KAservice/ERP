#ifndef UDMDocRKOImplH
#define UDMDocRKOImplH
#include "IDMDocRKO.h"
#include "UDMDocRKO.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocRKOImpl)) TDMDocRKOImpl : public IDMDocRKO
{
public:
   TDMDocRKOImpl();
   ~TDMDocRKOImpl();
   TDMDocRKO * Object;
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

//IDMDocRKO
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

   virtual TFIBDateTimeField * get_DocAllPOSDOC(void);
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC);

   virtual TFIBSmallIntField * get_DocAllPRDOC(void);
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC);

   virtual TFIBIntegerField * get_DocAllNUMDOC(void);
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC);

   virtual TFIBBCDField * get_DocAllSUMDOC(void);
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC);

   virtual TFIBSmallIntField * get_DocADDKDRRKO(void);
   virtual void set_DocADDKDRRKO(TFIBSmallIntField * DocADDKDRRKO);

   virtual TFIBBCDField * get_DocSUMUSNRKO(void);
   virtual void set_DocSUMUSNRKO(TFIBBCDField * DocSUMUSNRKO);

   virtual TFIBSmallIntField * get_DocOPERATIONRKO(void);
   virtual void set_DocOPERATIONRKO(TFIBSmallIntField * DocOPERATIONRKO);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBBCDField * get_DocAllIDDOC(void);
   virtual void set_DocAllIDDOC(TFIBBCDField * DocAllIDDOC);

   virtual TFIBBCDField * get_DocAllIDFIRMDOC(void);
   virtual void set_DocAllIDFIRMDOC(TFIBBCDField * DocAllIDFIRMDOC);

   virtual TFIBBCDField * get_DocAllIDSKLDOC(void);
   virtual void set_DocAllIDSKLDOC(TFIBBCDField * DocAllIDSKLDOC);

   virtual TFIBBCDField * get_DocAllIDKLDOC(void);
   virtual void set_DocAllIDKLDOC(TFIBBCDField * DocAllIDKLDOC);

   virtual TFIBBCDField * get_DocAllIDDOGDOC(void);
   virtual void set_DocAllIDDOGDOC(TFIBBCDField * DocAllIDDOGDOC);

   virtual TFIBBCDField * get_DocAllIDUSERDOC(void);
   virtual void set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC);

   virtual TFIBBCDField * get_DocAllIDDOCOSNDOC(void);
   virtual void set_DocAllIDDOCOSNDOC(TFIBBCDField * DocAllIDDOCOSNDOC);

   virtual TFIBBCDField * get_DocIDRKO(void);
   virtual void set_DocIDRKO(TFIBBCDField * DocIDRKO);

   virtual TFIBBCDField * get_DocIDDOCRKO(void);
   virtual void set_DocIDDOCRKO(TFIBBCDField * DocIDDOCRKO);

   virtual TFIBBCDField * get_DocIDKKMRKO(void);
   virtual void set_DocIDKKMRKO(TFIBBCDField * DocIDKKMRKO);

   virtual TFIBBCDField * get_DocIDKLRKO(void);
   virtual void set_DocIDKLRKO(TFIBBCDField * DocIDKLRKO);

   virtual TFIBBCDField * get_DocAllIDEXTDOC(void);
   virtual void set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC);

   virtual TFIBBCDField * get_DocIDBASE_DRKO(void);
   virtual void set_DocIDBASE_DRKO(TFIBBCDField * DocIDBASE_DRKO);

   virtual TFIBBCDField * get_DocAllIDBASE_GALLDOC(void);
   virtual void set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC);

   virtual TFIBIntegerField * get_DocNDS_DRKO(void);
   virtual void set_DocNDS_DRKO(TFIBIntegerField * DocNDS_DRKO);

   virtual TFIBBCDField * get_DocSUMNDS_DRKO(void);
   virtual void set_DocSUMNDS_DRKO(TFIBBCDField * DocSUMNDS_DRKO);

   virtual TFIBWideStringField * get_DocAllGID_DOC(void);
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocVIDATRKO(void);
   virtual void set_DocVIDATRKO(TFIBWideStringField * DocVIDATRKO);

   virtual TFIBWideStringField * get_DocOSNRKO(void);
   virtual void set_DocOSNRKO(TFIBWideStringField * DocOSNRKO);

   virtual TFIBWideStringField * get_DocPRILRKO(void);
   virtual void set_DocPRILRKO(TFIBWideStringField * DocPRILRKO);

   virtual TFIBWideStringField * get_DocDOCPOLRKO(void);
   virtual void set_DocDOCPOLRKO(TFIBWideStringField * DocDOCPOLRKO);

   virtual TFIBWideStringField * get_DocGID_DRKO(void);
   virtual void set_DocGID_DRKO(TFIBWideStringField * DocGID_DRKO);

   virtual TFIBIntegerField * get_DocNKLRKO(void);
   virtual void set_DocNKLRKO(TFIBIntegerField * DocNKLRKO);

   virtual TFIBIntegerField * get_DocNCHECKRKO(void);
   virtual void set_DocNCHECKRKO(TFIBIntegerField * DocNCHECKRKO);

   virtual TFIBWideStringField * get_DocMODELRKO(void);
   virtual void set_DocMODELRKO(TFIBWideStringField * DocMODELRKO);

   virtual TFIBWideStringField * get_DocREGNUMRKO(void);
   virtual void set_DocREGNUMRKO(TFIBWideStringField * DocREGNUMRKO);

   virtual TFIBWideStringField * get_DocSAVNUMRKO(void);
   virtual void set_DocSAVNUMRKO(TFIBWideStringField * DocSAVNUMRKO);

   virtual TFIBWideStringField * get_DocNAMEKKM(void);
   virtual void set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void);
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC);

   virtual TFIBBCDField * get_DocAllIDPROJECT_GALLDOC(void);
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBBCDField * DocAllIDPROJECT_GALLDOC);

   virtual TFIBBCDField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBBCDField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual TFIBWideStringField * get_DocKORRSCHET_DRKO(void);
   virtual void set_DocKORRSCHET_DRKO(TFIBWideStringField * DocKORRSCHET_DRKO);

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
#define CLSID_TDMDocRKOImpl __uuidof(TDMDocRKOImpl)
#endif
