#ifndef UDMDocOtchetPostImplH
#define UDMDocOtchetPostImplH
#include "IDMDocOtchetPost.h"
#include "UDMDocOtchetPost.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocOtchetPostImpl)) TDMDocOtchetPostImpl : public IDMDocOtchetPost
{
public:
   TDMDocOtchetPostImpl();
   ~TDMDocOtchetPostImpl();
   TDMDocOtchetPost * Object;
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

//IDMDocOtchetPost
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

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

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

   virtual TFIBLargeIntField * get_DocID_DOTCHPOST(void);
   virtual void set_DocID_DOTCHPOST(TFIBLargeIntField * DocID_DOTCHPOST);

   virtual TFIBLargeIntField * get_DocIDBASE_DOTCHPOST(void);
   virtual void set_DocIDBASE_DOTCHPOST(TFIBLargeIntField * DocIDBASE_DOTCHPOST);

   virtual TFIBWideStringField * get_DocGID_DOTCHPOST(void);
   virtual void set_DocGID_DOTCHPOST(TFIBWideStringField * DocGID_DOTCHPOST);

   virtual TFIBWideStringField * get_DocPRIM_DOTCHPOST(void);
   virtual void set_DocPRIM_DOTCHPOST(TFIBWideStringField * DocPRIM_DOTCHPOST);

   virtual TFIBLargeIntField * get_DocIDDOC_DOTCHPOST(void);
   virtual void set_DocIDDOC_DOTCHPOST(TFIBLargeIntField * DocIDDOC_DOTCHPOST);

   virtual TFIBLargeIntField * get_DocTID_DOTCHPOSTT(void);
   virtual void set_DocTID_DOTCHPOSTT(TFIBLargeIntField * DocTID_DOTCHPOSTT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DOTCHPOSTT(void);
   virtual void set_DocTIDBASE_DOTCHPOSTT(TFIBLargeIntField * DocTIDBASE_DOTCHPOSTT);

   virtual TFIBWideStringField * get_DocTGID_DOTCHPOSTT(void);
   virtual void set_DocTGID_DOTCHPOSTT(TFIBWideStringField * DocTGID_DOTCHPOSTT);

   virtual TFIBLargeIntField * get_DocTIDDOC_DOTCHPOSTT(void);
   virtual void set_DocTIDDOC_DOTCHPOSTT(TFIBLargeIntField * DocTIDDOC_DOTCHPOSTT);

   virtual TFIBLargeIntField * get_DocTIDNOM_DOTCHPOSTT(void);
   virtual void set_DocTIDNOM_DOTCHPOSTT(TFIBLargeIntField * DocTIDNOM_DOTCHPOSTT);

   virtual TFIBLargeIntField * get_DocTIDED_DOTCHPOSTT(void);
   virtual void set_DocTIDED_DOTCHPOSTT(TFIBLargeIntField * DocTIDED_DOTCHPOSTT);

   virtual TFIBBCDField * get_DocTKOL_DOTCHPOSTT(void);
   virtual void set_DocTKOL_DOTCHPOSTT(TFIBBCDField * DocTKOL_DOTCHPOSTT);

   virtual TFIBBCDField * get_DocTKF_DOTCHPOSTT(void);
   virtual void set_DocTKF_DOTCHPOSTT(TFIBBCDField * DocTKF_DOTCHPOSTT);

   virtual TFIBBCDField * get_DocTPRICE_DOTCHPOSTT(void);
   virtual void set_DocTPRICE_DOTCHPOSTT(TFIBBCDField * DocTPRICE_DOTCHPOSTT);

   virtual TFIBBCDField * get_DocTSUM_DOTCHPOSTT(void);
   virtual void set_DocTSUM_DOTCHPOSTT(TFIBBCDField * DocTSUM_DOTCHPOSTT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBSmallIntField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual TFIBLargeIntField * get_DocIDTPRICE_DOTCHPOST(void);
   virtual void set_DocIDTPRICE_DOTCHPOST(TFIBLargeIntField * DocIDTPRICE_DOTCHPOST);

   virtual TFIBWideStringField * get_DocNAME_TPRICE(void);
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElementaMaster(void);
   virtual void set_IdElementaMaster(__int64 IdElementaMaster);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual bool get_IsmPrice(void);
   virtual void set_IsmPrice(bool IsmPrice);

   virtual bool get_IsmSum(void);
   virtual void set_IsmSum(bool IsmSum);

   virtual bool get_SkladRozn(void);
   virtual void set_SkladRozn(bool SkladRozn);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual void NewDoc(void);
   virtual void CopyDoc(__int64 id_doc);
   virtual void OpenDoc(__int64 id);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual double Summa(void);
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
   virtual bool UpdatePrice(void);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocOtchetPostImpl __uuidof(TDMDocOtchetPostImpl)
#endif
