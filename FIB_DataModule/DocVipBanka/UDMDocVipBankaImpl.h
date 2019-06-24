#ifndef UDMDocVipBankaImplH
#define UDMDocVipBankaImplH
#include "IDMDocVipBanka.h"
#include "UDMDocVipBanka.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocVipBankaImpl)) TDMDocVipBankaImpl : public IDMDocVipBanka
{
public:
   TDMDocVipBankaImpl();
   ~TDMDocVipBankaImpl();
   TDMDocVipBanka * Object;
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

//IDMDocVipBanka
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

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

   virtual TFIBBCDField * get_DocAllIDDOC(void);
   virtual void set_DocAllIDDOC(TFIBBCDField * DocAllIDDOC);

   virtual TFIBDateTimeField * get_DocAllPOSDOC(void);
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC);

   virtual TFIBSmallIntField * get_DocAllPRDOC(void);
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC);

   virtual TFIBIntegerField * get_DocAllNUMDOC(void);
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC);

   virtual TFIBBCDField * get_DocAllIDFIRMDOC(void);
   virtual void set_DocAllIDFIRMDOC(TFIBBCDField * DocAllIDFIRMDOC);

   virtual TFIBBCDField * get_DocAllIDSKLDOC(void);
   virtual void set_DocAllIDSKLDOC(TFIBBCDField * DocAllIDSKLDOC);

   virtual TFIBBCDField * get_DocAllIDKLDOC(void);
   virtual void set_DocAllIDKLDOC(TFIBBCDField * DocAllIDKLDOC);

   virtual TFIBBCDField * get_DocAllIDDOGDOC(void);
   virtual void set_DocAllIDDOGDOC(TFIBBCDField * DocAllIDDOGDOC);

   virtual TFIBBCDField * get_DocAllSUMDOC(void);
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC);

   virtual TFIBBCDField * get_DocAllIDUSERDOC(void);
   virtual void set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC);

   virtual TFIBBCDField * get_DocAllIDDOCOSNDOC(void);
   virtual void set_DocAllIDDOCOSNDOC(TFIBBCDField * DocAllIDDOCOSNDOC);

   virtual TFIBBCDField * get_DocAllIDEXTDOC(void);
   virtual void set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC);

   virtual TFIBBCDField * get_DocAllIDBASE_GALLDOC(void);
   virtual void set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBBCDField * get_DocID_DVIPBANK(void);
   virtual void set_DocID_DVIPBANK(TFIBBCDField * DocID_DVIPBANK);

   virtual TFIBBCDField * get_DocIDDOC_DVIPBANK(void);
   virtual void set_DocIDDOC_DVIPBANK(TFIBBCDField * DocIDDOC_DVIPBANK);

   virtual TFIBBCDField * get_DocIDBASE_DVIPBANK(void);
   virtual void set_DocIDBASE_DVIPBANK(TFIBBCDField * DocIDBASE_DVIPBANK);

   virtual TFIBBCDField * get_DocIDBSCHET_DVIPBANK(void);
   virtual void set_DocIDBSCHET_DVIPBANK(TFIBBCDField * DocIDBSCHET_DVIPBANK);

   virtual TFIBBCDField * get_DocTID_DVIPBANKT(void);
   virtual void set_DocTID_DVIPBANKT(TFIBBCDField * DocTID_DVIPBANKT);

   virtual TFIBBCDField * get_DocTIDBASE_DVIPBANKT(void);
   virtual void set_DocTIDBASE_DVIPBANKT(TFIBBCDField * DocTIDBASE_DVIPBANKT);

   virtual TFIBBCDField * get_DocTIDDOC_DVIPBANKT(void);
   virtual void set_DocTIDDOC_DVIPBANKT(TFIBBCDField * DocTIDDOC_DVIPBANKT);

   virtual TFIBBCDField * get_DocTIDKLIENT_DVIPBANKT(void);
   virtual void set_DocTIDKLIENT_DVIPBANKT(TFIBBCDField * DocTIDKLIENT_DVIPBANKT);

   virtual TFIBDateField * get_DocTDATEPP_DVIPBANKT(void);
   virtual void set_DocTDATEPP_DVIPBANKT(TFIBDateField * DocTDATEPP_DVIPBANKT);

   virtual TFIBBCDField * get_DocTPRIHOD_DVIPBANKT(void);
   virtual void set_DocTPRIHOD_DVIPBANKT(TFIBBCDField * DocTPRIHOD_DVIPBANKT);

   virtual TFIBIntegerField * get_DocTPRIHODNDS_DVIPBANKT(void);
   virtual void set_DocTPRIHODNDS_DVIPBANKT(TFIBIntegerField * DocTPRIHODNDS_DVIPBANKT);

   virtual TFIBBCDField * get_DocTPRIHODSUMNDS_DVIPBANKT(void);
   virtual void set_DocTPRIHODSUMNDS_DVIPBANKT(TFIBBCDField * DocTPRIHODSUMNDS_DVIPBANKT);

   virtual TFIBBCDField * get_DocTRASHOD_DVIPBANKT(void);
   virtual void set_DocTRASHOD_DVIPBANKT(TFIBBCDField * DocTRASHOD_DVIPBANKT);

   virtual TFIBIntegerField * get_DocTRASHODNDS_DVIPBANKT(void);
   virtual void set_DocTRASHODNDS_DVIPBANKT(TFIBIntegerField * DocTRASHODNDS_DVIPBANKT);

   virtual TFIBBCDField * get_DocTRASHODSUMNDS_DVIPBANKT(void);
   virtual void set_DocTRASHODSUMNDS_DVIPBANKT(TFIBBCDField * DocTRASHODSUMNDS_DVIPBANKT);

   virtual TFIBIntegerField * get_DocTOPER_DVIPBANKT(void);
   virtual void set_DocTOPER_DVIPBANKT(TFIBIntegerField * DocTOPER_DVIPBANKT);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

   virtual TFIBWideStringField * get_DocAllGID_DOC(void);
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC);

   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void);
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBWideStringField * get_DocPRIM_DVIPBANK(void);
   virtual void set_DocPRIM_DVIPBANK(TFIBWideStringField * DocPRIM_DVIPBANK);

   virtual TFIBWideStringField * get_DocNAMEBSCHET(void);
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET);

   virtual TFIBWideStringField * get_DocTNUMPP_DVIPBANKT(void);
   virtual void set_DocTNUMPP_DVIPBANKT(TFIBWideStringField * DocTNUMPP_DVIPBANKT);

   virtual TFIBWideStringField * get_DocTTEXTPP_DVIPBANKT(void);
   virtual void set_DocTTEXTPP_DVIPBANKT(TFIBWideStringField * DocTTEXTPP_DVIPBANKT);

   virtual TFIBWideStringField * get_DocTNAMEKLIENT(void);
   virtual void set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT);

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

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual bool NewDoc(void);
   virtual bool OpenDoc(__int64 IdDoc);
   virtual bool SaveDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void TableAppend(void);
   virtual void TableDelete(void);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocVipBankaImpl __uuidof(TDMDocVipBankaImpl)
#endif
