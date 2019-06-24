#ifndef UDMDocSchetFactImplH
#define UDMDocSchetFactImplH
#include "IDMDocSchetFact.h"
#include "UDMDocSchetFact.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocSchetFactImpl)) TDMDocSchetFactImpl : public IDMDocSchetFact
{
public:
   TDMDocSchetFactImpl();
   ~TDMDocSchetFactImpl();
   TDMDocSchetFact * Object;
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

//IDMDocSchetFact
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

   virtual TFIBBCDField * get_DocTKOL_DSCHFACTT(void);
   virtual void set_DocTKOL_DSCHFACTT(TFIBBCDField * DocTKOL_DSCHFACTT);

   virtual TFIBBCDField * get_DocTKF_DSCHFACTT(void);
   virtual void set_DocTKF_DSCHFACTT(TFIBBCDField * DocTKF_DSCHFACTT);

   virtual TFIBBCDField * get_DocTPRICE_DSCHFACTT(void);
   virtual void set_DocTPRICE_DSCHFACTT(TFIBBCDField * DocTPRICE_DSCHFACTT);

   virtual TFIBBCDField * get_DocTSUM_DSCHFACTT(void);
   virtual void set_DocTSUM_DSCHFACTT(TFIBBCDField * DocTSUM_DSCHFACTT);

   virtual TFIBIntegerField * get_DocTSTNDS_DSCHFACTT(void);
   virtual void set_DocTSTNDS_DSCHFACTT(TFIBIntegerField * DocTSTNDS_DSCHFACTT);

   virtual TFIBBCDField * get_DocTSUMNDS_DSCHFACTT(void);
   virtual void set_DocTSUMNDS_DSCHFACTT(TFIBBCDField * DocTSUMNDS_DSCHFACTT);

   virtual TFIBIntegerField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_IBQ(void);
   virtual void set_IBQ(TpFIBDataSet * IBQ);

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

   virtual TFIBBCDField * get_DocID_DSCHFACT(void);
   virtual void set_DocID_DSCHFACT(TFIBBCDField * DocID_DSCHFACT);

   virtual TFIBBCDField * get_DocIDDOC_DSCHFACT(void);
   virtual void set_DocIDDOC_DSCHFACT(TFIBBCDField * DocIDDOC_DSCHFACT);

   virtual TFIBBCDField * get_DocIDTPRICE_DSCHFACT(void);
   virtual void set_DocIDTPRICE_DSCHFACT(TFIBBCDField * DocIDTPRICE_DSCHFACT);

   virtual TFIBBCDField * get_DocTID_DSCHFACTT(void);
   virtual void set_DocTID_DSCHFACTT(TFIBBCDField * DocTID_DSCHFACTT);

   virtual TFIBBCDField * get_DocTIDDOC_DSCHFACTT(void);
   virtual void set_DocTIDDOC_DSCHFACTT(TFIBBCDField * DocTIDDOC_DSCHFACTT);

   virtual TFIBBCDField * get_DocTIDNOM_DSCHFACTT(void);
   virtual void set_DocTIDNOM_DSCHFACTT(TFIBBCDField * DocTIDNOM_DSCHFACTT);

   virtual TFIBBCDField * get_DocTIDED_DSCHFACTT(void);
   virtual void set_DocTIDED_DSCHFACTT(TFIBBCDField * DocTIDED_DSCHFACTT);

   virtual TFIBBCDField * get_DocAllIDEXTDOC(void);
   virtual void set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC);

   virtual TFIBBCDField * get_DocIDGRPOL_DSCHFACT(void);
   virtual void set_DocIDGRPOL_DSCHFACT(TFIBBCDField * DocIDGRPOL_DSCHFACT);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_DocIDBASE_DSCHFACT(void);
   virtual void set_DocIDBASE_DSCHFACT(TFIBBCDField * DocIDBASE_DSCHFACT);

   virtual TFIBBCDField * get_DocTIDBASE_DSCHFACTT(void);
   virtual void set_DocTIDBASE_DSCHFACTT(TFIBBCDField * DocTIDBASE_DSCHFACTT);

   virtual TFIBBCDField * get_DocAllIDBASE_GALLDOC(void);
   virtual void set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

   virtual TFIBWideStringField * get_DocAllGID_DOC(void);
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC);

   virtual TFIBWideStringField * get_DocAllPREFIKSDOC(void);
   virtual void set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC);

   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void);
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocGID_DSCHFACT(void);
   virtual void set_DocGID_DSCHFACT(TFIBWideStringField * DocGID_DSCHFACT);

   virtual TFIBWideStringField * get_DocPRIM_DSCHFACT(void);
   virtual void set_DocPRIM_DSCHFACT(TFIBWideStringField * DocPRIM_DSCHFACT);

   virtual TFIBWideStringField * get_DocNAMEKLIENT(void);
   virtual void set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT);

   virtual TFIBWideStringField * get_DocTGID_DSCHFACTT(void);
   virtual void set_DocTGID_DSCHFACTT(TFIBWideStringField * DocTGID_DSCHFACTT);

   virtual TFIBIntegerField * get_DocTNDS_DSCHFACTT(void);
   virtual void set_DocTNDS_DSCHFACTT(TFIBIntegerField * DocTNDS_DSCHFACTT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBBCDField * get_DocAllIDPROJECT_GALLDOC(void);
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBBCDField * DocAllIDPROJECT_GALLDOC);

   virtual TFIBBCDField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBBCDField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_DocNUMPLAT_RASCH_DOC_DSCHFACT(void);
   virtual void set_DocNUMPLAT_RASCH_DOC_DSCHFACT(TFIBWideStringField * DocNUMPLAT_RASCH_DOC_DSCHFACT);

   virtual TFIBDateTimeField * get_DocDATEPLAT_RASCH_DOC_DSCHFACT(void);
   virtual void set_DocDATEPLAT_RASCH_DOC_DSCHFACT(TFIBDateTimeField * DocDATEPLAT_RASCH_DOC_DSCHFACT);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

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
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual void CloseDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocSchetFactImpl __uuidof(TDMDocSchetFactImpl)
#endif
