#ifndef UDMDocRegAdvCustImplH
#define UDMDocRegAdvCustImplH
#include "IDMDocRegAdvCust.h"
#include "UDMDocRegAdvCust.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocRegAdvCustImpl)) TDMDocRegAdvCustImpl : public IDMDocRegAdvCust
{
public:
   TDMDocRegAdvCustImpl();
   ~TDMDocRegAdvCustImpl();
   TDMDocRegAdvCust * Object;
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

//IDMDocRegAdvCust
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

   virtual TFIBDateTimeField * get_DocAllPOSDOC(void);
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC);

   virtual TFIBSmallIntField * get_DocAllPRDOC(void);
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC);

   virtual TFIBIntegerField * get_DocAllNUMDOC(void);
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC);

   virtual TFIBBCDField * get_DocAllSUMDOC(void);
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBSmallIntField * get_DocTTDV_DRG_ADVCUSTT(void);
   virtual void set_DocTTDV_DRG_ADVCUSTT(TFIBSmallIntField * DocTTDV_DRG_ADVCUSTT);

   virtual TFIBSmallIntField * get_DocTOPER_DRG_ADVCUSTT(void);
   virtual void set_DocTOPER_DRG_ADVCUSTT(TFIBSmallIntField * DocTOPER_DRG_ADVCUSTT);

   virtual TFIBBCDField * get_DocTSUM_DRG_ADVCUSTT(void);
   virtual void set_DocTSUM_DRG_ADVCUSTT(TFIBBCDField * DocTSUM_DRG_ADVCUSTT);

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

   virtual TFIBLargeIntField * get_DocID_DRG_ADVCUST(void);
   virtual void set_DocID_DRG_ADVCUST(TFIBLargeIntField * DocID_DRG_ADVCUST);

   virtual TFIBLargeIntField * get_DocIDDOC_DRG_ADVCUST(void);
   virtual void set_DocIDDOC_DRG_ADVCUST(TFIBLargeIntField * DocIDDOC_DRG_ADVCUST);

   virtual TFIBWideStringField * get_DocDESCR_DRG_ADVCUST(void);
   virtual void set_DocDESCR_DRG_ADVCUST(TFIBWideStringField * DocDESCR_DRG_ADVCUST);

   virtual TFIBLargeIntField * get_DocIDBASE_DRG_ADVCUST(void);
   virtual void set_DocIDBASE_DRG_ADVCUST(TFIBLargeIntField * DocIDBASE_DRG_ADVCUST);

   virtual TFIBLargeIntField * get_DocTID_DRG_ADVCUSTT(void);
   virtual void set_DocTID_DRG_ADVCUSTT(TFIBLargeIntField * DocTID_DRG_ADVCUSTT);

   virtual TFIBLargeIntField * get_DocTIDDOC_DRG_ADVCUSTT(void);
   virtual void set_DocTIDDOC_DRG_ADVCUSTT(TFIBLargeIntField * DocTIDDOC_DRG_ADVCUSTT);

   virtual TFIBLargeIntField * get_DocTIDFIRM_DRG_ADVCUSTT(void);
   virtual void set_DocTIDFIRM_DRG_ADVCUSTT(TFIBLargeIntField * DocTIDFIRM_DRG_ADVCUSTT);

   virtual TFIBLargeIntField * get_DocTIDKLIENT_DRG_ADVCUSTT(void);
   virtual void set_DocTIDKLIENT_DRG_ADVCUSTT(TFIBLargeIntField * DocTIDKLIENT_DRG_ADVCUSTT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DRG_ADVCUSTT(void);
   virtual void set_DocTIDBASE_DRG_ADVCUSTT(TFIBLargeIntField * DocTIDBASE_DRG_ADVCUSTT);

   virtual TFIBWideStringField * get_DocTNAMEFIRM(void);
   virtual void set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM);

   virtual TFIBWideStringField * get_DocTNAMEKLIENT(void);
   virtual void set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT);

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
#define CLSID_TDMDocRegAdvCustImpl __uuidof(TDMDocRegAdvCustImpl)
#endif
