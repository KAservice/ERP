#ifndef UDMDocPlPImplH
#define UDMDocPlPImplH
#include "IDMDocPlP.h"
#include "UDMDocPlP.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocPlPImpl)) TDMDocPlPImpl : public IDMDocPlP
{
public:
   TDMDocPlPImpl();
   ~TDMDocPlPImpl();
   TDMDocPLP * Object;
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

//IDMDocPlP
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

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

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

   virtual TFIBLargeIntField * get_DocIDPLP(void);
   virtual void set_DocIDPLP(TFIBLargeIntField * DocIDPLP);

   virtual TFIBLargeIntField * get_DocIDDOCPLP(void);
   virtual void set_DocIDDOCPLP(TFIBLargeIntField * DocIDDOCPLP);

   virtual TFIBLargeIntField * get_DocIDBSCHPLP(void);
   virtual void set_DocIDBSCHPLP(TFIBLargeIntField * DocIDBSCHPLP);

   virtual TFIBLargeIntField * get_DocIDRSCHPLP(void);
   virtual void set_DocIDRSCHPLP(TFIBLargeIntField * DocIDRSCHPLP);

   virtual TFIBIntegerField * get_DocVIDPLP(void);
   virtual void set_DocVIDPLP(TFIBIntegerField * DocVIDPLP);

   virtual TFIBIntegerField * get_DocOCHPLP(void);
   virtual void set_DocOCHPLP(TFIBIntegerField * DocOCHPLP);

   virtual TFIBDateField * get_DocSROKPLP(void);
   virtual void set_DocSROKPLP(TFIBDateField * DocSROKPLP);

   virtual TFIBWideStringField * get_DocNASNPLP(void);
   virtual void set_DocNASNPLP(TFIBWideStringField * DocNASNPLP);

   virtual TFIBWideStringField * get_DocGID_DPLP(void);
   virtual void set_DocGID_DPLP(TFIBWideStringField * DocGID_DPLP);

   virtual TFIBIntegerField * get_DocADDKDRPLP(void);
   virtual void set_DocADDKDRPLP(TFIBIntegerField * DocADDKDRPLP);

   virtual TFIBIntegerField * get_DocOPERATIONPLP(void);
   virtual void set_DocOPERATIONPLP(TFIBIntegerField * DocOPERATIONPLP);

   virtual TFIBBCDField * get_DocSUMUSNPLP(void);
   virtual void set_DocSUMUSNPLP(TFIBBCDField * DocSUMUSNPLP);

   virtual TFIBWideStringField * get_DocNALOG_STATUS_PLP(void);
   virtual void set_DocNALOG_STATUS_PLP(TFIBWideStringField * DocNALOG_STATUS_PLP);

   virtual TFIBWideStringField * get_DocNALOG_OSN_PLP(void);
   virtual void set_DocNALOG_OSN_PLP(TFIBWideStringField * DocNALOG_OSN_PLP);

   virtual TFIBWideStringField * get_DocNALOG_NUM_PLP(void);
   virtual void set_DocNALOG_NUM_PLP(TFIBWideStringField * DocNALOG_NUM_PLP);

   virtual TFIBWideStringField * get_DocNALOG_TPLAT_PLP(void);
   virtual void set_DocNALOG_TPLAT_PLP(TFIBWideStringField * DocNALOG_TPLAT_PLP);

   virtual TFIBWideStringField * get_DocNALOG_KBK_PLP(void);
   virtual void set_DocNALOG_KBK_PLP(TFIBWideStringField * DocNALOG_KBK_PLP);

   virtual TFIBWideStringField * get_DocNALOG_OKATO_PLP(void);
   virtual void set_DocNALOG_OKATO_PLP(TFIBWideStringField * DocNALOG_OKATO_PLP);

   virtual TFIBWideStringField * get_DocNALOG_PERIOD_PLP(void);
   virtual void set_DocNALOG_PERIOD_PLP(TFIBWideStringField * DocNALOG_PERIOD_PLP);

   virtual TFIBDateField * get_DocNALOG_DATE_PLP(void);
   virtual void set_DocNALOG_DATE_PLP(TFIBDateField * DocNALOG_DATE_PLP);

   virtual TFIBLargeIntField * get_DocIDBASE_DPLP(void);
   virtual void set_DocIDBASE_DPLP(TFIBLargeIntField * DocIDBASE_DPLP);

   virtual TFIBIntegerField * get_DocNDS_DPLP(void);
   virtual void set_DocNDS_DPLP(TFIBIntegerField * DocNDS_DPLP);

   virtual TFIBBCDField * get_DocSUMNDS_DPLP(void);
   virtual void set_DocSUMNDS_DPLP(TFIBBCDField * DocSUMNDS_DPLP);

   virtual TFIBWideStringField * get_DocNAMEBSCHET(void);
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET);

   virtual TFIBWideStringField * get_DocNAMERSCHET(void);
   virtual void set_DocNAMERSCHET(TFIBWideStringField * DocNAMERSCHET);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

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
   virtual void OpenDoc(__int64 id);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void CloseDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocPlPImpl __uuidof(TDMDocPlPImpl)
#endif
