#ifndef UDMDocRevImplH
#define UDMDocRevImplH
#include "IDMDocRev.h"
#include "UDMDocRev.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocRevImpl)) TDMDocRevImpl : public IDMDocRev
{
public:
   TDMDocRevImpl();
   ~TDMDocRevImpl();
   TDMDocRev * Object;
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

//IDMDocRev
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

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TFIBDateTimeField * get_DocAllPOSDOC(void);
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC);

   virtual TFIBSmallIntField * get_DocAllPRDOC(void);
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC);

   virtual TFIBIntegerField * get_DocAllNUMDOC(void);
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC);

   virtual TFIBBCDField * get_DocAllSUMDOC(void);
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBDataSet * get_IBQPoGrp(void);
   virtual void set_IBQPoGrp(TpFIBDataSet * IBQPoGrp);

   virtual TpFIBDataSet * get_IBQ(void);
   virtual void set_IBQ(TpFIBDataSet * IBQ);

   virtual TFIBIntegerField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM);

   virtual TFIBBCDField * get_DocTKOL_DREVT(void);
   virtual void set_DocTKOL_DREVT(TFIBBCDField * DocTKOL_DREVT);

   virtual TFIBBCDField * get_DocTKF_DREVT(void);
   virtual void set_DocTKF_DREVT(TFIBBCDField * DocTKF_DREVT);

   virtual TFIBBCDField * get_DocTRPRICE_DREVT(void);
   virtual void set_DocTRPRICE_DREVT(TFIBBCDField * DocTRPRICE_DREVT);

   virtual TFIBBCDField * get_DocTRSUM_DREVT(void);
   virtual void set_DocTRSUM_DREVT(TFIBBCDField * DocTRSUM_DREVT);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TpFIBDataSet * get_Ostatki(void);
   virtual void set_Ostatki(TpFIBDataSet * Ostatki);

   virtual TFIBBCDField * get_OstatkiKFED(void);
   virtual void set_OstatkiKFED(TFIBBCDField * OstatkiKFED);

   virtual TFIBBCDField * get_OstatkiSUM(void);
   virtual void set_OstatkiSUM(TFIBBCDField * OstatkiSUM);

   virtual TFIBLargeIntField * get_OstatkiIDNOM(void);
   virtual void set_OstatkiIDNOM(TFIBLargeIntField * OstatkiIDNOM);

   virtual TFIBIntegerField * get_OstatkiCODENOM(void);
   virtual void set_OstatkiCODENOM(TFIBIntegerField * OstatkiCODENOM);

   virtual TFIBWideStringField * get_OstatkiNAMENOM(void);
   virtual void set_OstatkiNAMENOM(TFIBWideStringField * OstatkiNAMENOM);

   virtual TFIBLargeIntField * get_OstatkiIDED(void);
   virtual void set_OstatkiIDED(TFIBLargeIntField * OstatkiIDED);

   virtual TFIBWideStringField * get_OstatkiNAMEED(void);
   virtual void set_OstatkiNAMEED(TFIBWideStringField * OstatkiNAMEED);

   virtual TFIBWideStringField * get_IBQPoGrpNAMEGN(void);
   virtual void set_IBQPoGrpNAMEGN(TFIBWideStringField * IBQPoGrpNAMEGN);

   virtual TFIBLargeIntField * get_IBQPoGrpIDGN(void);
   virtual void set_IBQPoGrpIDGN(TFIBLargeIntField * IBQPoGrpIDGN);

   virtual TFIBWideStringField * get_IBQPoGrpNAMENOM(void);
   virtual void set_IBQPoGrpNAMENOM(TFIBWideStringField * IBQPoGrpNAMENOM);

   virtual TFIBIntegerField * get_IBQPoGrpTNOM(void);
   virtual void set_IBQPoGrpTNOM(TFIBIntegerField * IBQPoGrpTNOM);

   virtual TFIBIntegerField * get_IBQPoGrpCODENOM(void);
   virtual void set_IBQPoGrpCODENOM(TFIBIntegerField * IBQPoGrpCODENOM);

   virtual TFIBLargeIntField * get_IBQPoGrpID_DREVT(void);
   virtual void set_IBQPoGrpID_DREVT(TFIBLargeIntField * IBQPoGrpID_DREVT);

   virtual TFIBLargeIntField * get_IBQPoGrpIDDOC_DREVT(void);
   virtual void set_IBQPoGrpIDDOC_DREVT(TFIBLargeIntField * IBQPoGrpIDDOC_DREVT);

   virtual TFIBLargeIntField * get_IBQPoGrpIDNOM_DREVT(void);
   virtual void set_IBQPoGrpIDNOM_DREVT(TFIBLargeIntField * IBQPoGrpIDNOM_DREVT);

   virtual TFIBLargeIntField * get_IBQPoGrpIDED_DREVT(void);
   virtual void set_IBQPoGrpIDED_DREVT(TFIBLargeIntField * IBQPoGrpIDED_DREVT);

   virtual TFIBBCDField * get_IBQPoGrpKOL_DREVT(void);
   virtual void set_IBQPoGrpKOL_DREVT(TFIBBCDField * IBQPoGrpKOL_DREVT);

   virtual TFIBBCDField * get_IBQPoGrpKF_DREVT(void);
   virtual void set_IBQPoGrpKF_DREVT(TFIBBCDField * IBQPoGrpKF_DREVT);

   virtual TFIBBCDField * get_IBQPoGrpRPRICE_DREVT(void);
   virtual void set_IBQPoGrpRPRICE_DREVT(TFIBBCDField * IBQPoGrpRPRICE_DREVT);

   virtual TFIBBCDField * get_IBQPoGrpRSUM_DREVT(void);
   virtual void set_IBQPoGrpRSUM_DREVT(TFIBBCDField * IBQPoGrpRSUM_DREVT);

   virtual TFIBWideStringField * get_IBQPoGrpNAMEED(void);
   virtual void set_IBQPoGrpNAMEED(TFIBWideStringField * IBQPoGrpNAMEED);

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

   virtual TFIBWideStringField * get_DocAllNAME_USER(void);
   virtual void set_DocAllNAME_USER(TFIBWideStringField * DocAllNAME_USER);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBLargeIntField * get_DocID_DREV(void);
   virtual void set_DocID_DREV(TFIBLargeIntField * DocID_DREV);

   virtual TFIBWideStringField * get_DocGID_DREV(void);
   virtual void set_DocGID_DREV(TFIBWideStringField * DocGID_DREV);

   virtual TFIBLargeIntField * get_DocIDDOC_DREV(void);
   virtual void set_DocIDDOC_DREV(TFIBLargeIntField * DocIDDOC_DREV);

   virtual TFIBLargeIntField * get_DocIDINV_DREV(void);
   virtual void set_DocIDINV_DREV(TFIBLargeIntField * DocIDINV_DREV);

   virtual TFIBWideStringField * get_DocDESCR_DREV(void);
   virtual void set_DocDESCR_DREV(TFIBWideStringField * DocDESCR_DREV);

   virtual TFIBLargeIntField * get_DocIDRTPRICE_DREV(void);
   virtual void set_DocIDRTPRICE_DREV(TFIBLargeIntField * DocIDRTPRICE_DREV);

   virtual TFIBLargeIntField * get_DocIDBASE_DREV(void);
   virtual void set_DocIDBASE_DREV(TFIBLargeIntField * DocIDBASE_DREV);

   virtual TFIBWideStringField * get_DocNAME_SINV(void);
   virtual void set_DocNAME_SINV(TFIBWideStringField * DocNAME_SINV);

   virtual TFIBWideStringField * get_DocTNAMEGN(void);
   virtual void set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN);

   virtual TFIBLargeIntField * get_DocTIDGN(void);
   virtual void set_DocTIDGN(TFIBLargeIntField * DocTIDGN);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBLargeIntField * get_DocTID_DREVT(void);
   virtual void set_DocTID_DREVT(TFIBLargeIntField * DocTID_DREVT);

   virtual TFIBWideStringField * get_DocTGID_DREVT(void);
   virtual void set_DocTGID_DREVT(TFIBWideStringField * DocTGID_DREVT);

   virtual TFIBLargeIntField * get_DocTIDDOC_DREVT(void);
   virtual void set_DocTIDDOC_DREVT(TFIBLargeIntField * DocTIDDOC_DREVT);

   virtual TFIBLargeIntField * get_DocTIDNOM_DREVT(void);
   virtual void set_DocTIDNOM_DREVT(TFIBLargeIntField * DocTIDNOM_DREVT);

   virtual TFIBLargeIntField * get_DocTIDED_DREVT(void);
   virtual void set_DocTIDED_DREVT(TFIBLargeIntField * DocTIDED_DREVT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DREVT(void);
   virtual void set_DocTIDBASE_DREVT(TFIBLargeIntField * DocTIDBASE_DREVT);

   virtual TFIBLargeIntField * get_DocTIDEXT_DOUT_DREVT(void);
   virtual void set_DocTIDEXT_DOUT_DREVT(TFIBLargeIntField * DocTIDEXT_DOUT_DREVT);

   virtual TFIBLargeIntField * get_DocTIDEXT_BASE_DREVT(void);
   virtual void set_DocTIDEXT_BASE_DREVT(TFIBLargeIntField * DocTIDEXT_BASE_DREVT);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllFNAMEFIRM(void);
   virtual void set_DocAllFNAMEFIRM(TFIBWideStringField * DocAllFNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllPADRFIRM(void);
   virtual void set_DocAllPADRFIRM(TFIBWideStringField * DocAllPADRFIRM);

   virtual TFIBWideStringField * get_DocAllINNFIRM(void);
   virtual void set_DocAllINNFIRM(TFIBWideStringField * DocAllINNFIRM);

   virtual TFIBLargeIntField * get_DocAllIDPROJECT_GALLDOC(void);
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBBCDField * get_DocTUCH_KOL_DREVT(void);
   virtual void set_DocTUCH_KOL_DREVT(TFIBBCDField * DocTUCH_KOL_DREVT);

   virtual TFIBBCDField * get_DocTUCH_RSUM_DREVT(void);
   virtual void set_DocTUCH_RSUM_DREVT(TFIBBCDField * DocTUCH_RSUM_DREVT);

   virtual TFIBBCDField * get_DocTUCH_SUM_DREVT(void);
   virtual void set_DocTUCH_SUM_DREVT(TFIBBCDField * DocTUCH_SUM_DREVT);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_NoEdit(void);
   virtual void set_NoEdit(bool NoEdit);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual int get_IdGrpNom(void);
   virtual void set_IdGrpNom(int IdGrpNom);

   virtual bool get_ChangeTable(void);
   virtual void set_ChangeTable(bool ChangeTable);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 IdDoc);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
   virtual void AddOstatkiNaSklade(__int64 id_firm, __int64 id_sklad);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocRevImpl __uuidof(TDMDocRevImpl)
#endif
