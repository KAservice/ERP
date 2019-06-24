#ifndef UDMDocPKOImplH
#define UDMDocPKOImplH
#include "IDMDocPKO.h"
#include "UDMDocPKO.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocPKOImpl)) TDMDocPKOImpl : public IDMDocPKO
{
public:
   TDMDocPKOImpl();
   ~TDMDocPKOImpl();
   TDMDocPKO * Object;
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

//IDMDocPKO
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

   virtual TFIBSmallIntField * get_DocADDKDRPKO(void);
   virtual void set_DocADDKDRPKO(TFIBSmallIntField * DocADDKDRPKO);

   virtual TFIBBCDField * get_DocSUMUSNPKO(void);
   virtual void set_DocSUMUSNPKO(TFIBBCDField * DocSUMUSNPKO);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TFIBIntegerField * get_DocNKLPKO(void);
   virtual void set_DocNKLPKO(TFIBIntegerField * DocNKLPKO);

   virtual TFIBIntegerField * get_DocNCHECKPKO(void);
   virtual void set_DocNCHECKPKO(TFIBIntegerField * DocNCHECKPKO);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBIntegerField * get_DocNDS_DPKO(void);
   virtual void set_DocNDS_DPKO(TFIBIntegerField * DocNDS_DPKO);

   virtual TFIBBCDField * get_DocSUMNDS_DPKO(void);
   virtual void set_DocSUMNDS_DPKO(TFIBBCDField * DocSUMNDS_DPKO);

   virtual TFIBLargeIntField * get_DocAllIDDOC(void);
   virtual void set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

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

   virtual TFIBWideStringField * get_DocAllGID_DOC(void);
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC);

   virtual TFIBWideStringField * get_DocAllPREFIKSDOC(void);
   virtual void set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOCOSNDOC(void);
   virtual void set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC);

   virtual TFIBLargeIntField * get_DocAllIDEXTDOC(void);
   virtual void set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC);

   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void);
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC);

   virtual TFIBLargeIntField * get_DocAllIDBASE_GALLDOC(void);
   virtual void set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDPROJECT_GALLDOC(void);
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBLargeIntField * get_DocIDPKO(void);
   virtual void set_DocIDPKO(TFIBLargeIntField * DocIDPKO);

   virtual TFIBLargeIntField * get_DocIDDOCPKO(void);
   virtual void set_DocIDDOCPKO(TFIBLargeIntField * DocIDDOCPKO);

   virtual TFIBLargeIntField * get_DocIDKKMPKO(void);
   virtual void set_DocIDKKMPKO(TFIBLargeIntField * DocIDKKMPKO);

   virtual TFIBLargeIntField * get_DocIDKLPKO(void);
   virtual void set_DocIDKLPKO(TFIBLargeIntField * DocIDKLPKO);

   virtual TFIBWideStringField * get_DocPROTPKO(void);
   virtual void set_DocPROTPKO(TFIBWideStringField * DocPROTPKO);

   virtual TFIBWideStringField * get_DocOSNPKO(void);
   virtual void set_DocOSNPKO(TFIBWideStringField * DocOSNPKO);

   virtual TFIBWideStringField * get_DocPRILPKO(void);
   virtual void set_DocPRILPKO(TFIBWideStringField * DocPRILPKO);

   virtual TFIBWideStringField * get_DocGID_DPKO(void);
   virtual void set_DocGID_DPKO(TFIBWideStringField * DocGID_DPKO);

   virtual TFIBIntegerField * get_DocOPERATIONPKO(void);
   virtual void set_DocOPERATIONPKO(TFIBIntegerField * DocOPERATIONPKO);

   virtual TFIBWideStringField * get_DocMODELPKO(void);
   virtual void set_DocMODELPKO(TFIBWideStringField * DocMODELPKO);

   virtual TFIBWideStringField * get_DocREGNUMPKO(void);
   virtual void set_DocREGNUMPKO(TFIBWideStringField * DocREGNUMPKO);

   virtual TFIBWideStringField * get_DocSAVNUMPKO(void);
   virtual void set_DocSAVNUMPKO(TFIBWideStringField * DocSAVNUMPKO);

   virtual TFIBLargeIntField * get_DocIDBASE_DPKO(void);
   virtual void set_DocIDBASE_DPKO(TFIBLargeIntField * DocIDBASE_DPKO);

   virtual TFIBWideStringField * get_DocNAMEKKM(void);
   virtual void set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual TFIBWideStringField * get_DocKORRSCHET_DPKO(void);
   virtual void set_DocKORRSCHET_DPKO(TFIBWideStringField * DocKORRSCHET_DPKO);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElementaMaster(void);
   virtual void set_IdElementaMaster(__int64 IdElementaMaster);

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
#define CLSID_TDMDocPKOImpl __uuidof(TDMDocPKOImpl)
#endif
