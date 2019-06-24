#ifndef UDMDocSborkaKomplImplH
#define UDMDocSborkaKomplImplH
#include "IDMDocSborkaKompl.h"
#include "UDMDocSborkaKompl.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocSborkaKomplImpl)) TDMDocSborkaKomplImpl : public IDMDocSborkaKompl
{
public:
   TDMDocSborkaKomplImpl();
   ~TDMDocSborkaKomplImpl();
   TDMDocSborkaKompl * Object;
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

//IDMDocSborkaKompl
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

   virtual TFIBBCDField * get_DocID_DSBKOMPL(void);
   virtual void set_DocID_DSBKOMPL(TFIBBCDField * DocID_DSBKOMPL);

   virtual TFIBBCDField * get_DocIDBASE_DSBKOMPL(void);
   virtual void set_DocIDBASE_DSBKOMPL(TFIBBCDField * DocIDBASE_DSBKOMPL);

   virtual TFIBBCDField * get_DocIDDOC_DSBKOMPL(void);
   virtual void set_DocIDDOC_DSBKOMPL(TFIBBCDField * DocIDDOC_DSBKOMPL);

   virtual TFIBBCDField * get_DocIDNOM_DSBKOMPL(void);
   virtual void set_DocIDNOM_DSBKOMPL(TFIBBCDField * DocIDNOM_DSBKOMPL);

   virtual TFIBBCDField * get_DocIDED_DSBKOMPL(void);
   virtual void set_DocIDED_DSBKOMPL(TFIBBCDField * DocIDED_DSBKOMPL);

   virtual TFIBBCDField * get_DocKF_DSBKOMPL(void);
   virtual void set_DocKF_DSBKOMPL(TFIBBCDField * DocKF_DSBKOMPL);

   virtual TFIBBCDField * get_DocKOL_DSBKOMPL(void);
   virtual void set_DocKOL_DSBKOMPL(TFIBBCDField * DocKOL_DSBKOMPL);

   virtual TFIBBCDField * get_DocRPRICE_DSBKOMPL(void);
   virtual void set_DocRPRICE_DSBKOMPL(TFIBBCDField * DocRPRICE_DSBKOMPL);

   virtual TFIBBCDField * get_DocTID_DSBKOMPLT(void);
   virtual void set_DocTID_DSBKOMPLT(TFIBBCDField * DocTID_DSBKOMPLT);

   virtual TFIBBCDField * get_DocTIDBASE_DSBKOMPLT(void);
   virtual void set_DocTIDBASE_DSBKOMPLT(TFIBBCDField * DocTIDBASE_DSBKOMPLT);

   virtual TFIBBCDField * get_DocTIDDOC_DSBKOMPLT(void);
   virtual void set_DocTIDDOC_DSBKOMPLT(TFIBBCDField * DocTIDDOC_DSBKOMPLT);

   virtual TFIBBCDField * get_DocTIDNOM_DSBKOMPLT(void);
   virtual void set_DocTIDNOM_DSBKOMPLT(TFIBBCDField * DocTIDNOM_DSBKOMPLT);

   virtual TFIBBCDField * get_DocTIDED_DSBKOMPLT(void);
   virtual void set_DocTIDED_DSBKOMPLT(TFIBBCDField * DocTIDED_DSBKOMPLT);

   virtual TFIBBCDField * get_DocTKF_DSBKOMPLT(void);
   virtual void set_DocTKF_DSBKOMPLT(TFIBBCDField * DocTKF_DSBKOMPLT);

   virtual TFIBBCDField * get_DocTKOL_DSBKOMPLT(void);
   virtual void set_DocTKOL_DSBKOMPLT(TFIBBCDField * DocTKOL_DSBKOMPLT);

   virtual TFIBBCDField * get_DocTRPRICE_DSBKOMPLT(void);
   virtual void set_DocTRPRICE_DSBKOMPLT(TFIBBCDField * DocTRPRICE_DSBKOMPLT);

   virtual TFIBBCDField * get_DocTRSUM_DSBKOMPLT(void);
   virtual void set_DocTRSUM_DSBKOMPLT(TFIBBCDField * DocTRSUM_DSBKOMPLT);

   virtual TFIBBCDField * get_DocIDRTPRICE_DSBKOMPL(void);
   virtual void set_DocIDRTPRICE_DSBKOMPL(TFIBBCDField * DocIDRTPRICE_DSBKOMPL);

   virtual TFIBBCDField * get_DocIDPART_DSBKOMPL(void);
   virtual void set_DocIDPART_DSBKOMPL(TFIBBCDField * DocIDPART_DSBKOMPL);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

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

   virtual TFIBWideStringField * get_DocDESCR_DSBKOMPL(void);
   virtual void set_DocDESCR_DSBKOMPL(TFIBWideStringField * DocDESCR_DSBKOMPL);

   virtual TFIBWideStringField * get_DocNAMENOM(void);
   virtual void set_DocNAMENOM(TFIBWideStringField * DocNAMENOM);

   virtual TFIBWideStringField * get_DocNAMEED(void);
   virtual void set_DocNAMEED(TFIBWideStringField * DocNAMEED);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

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

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_SkladRozn(void);
   virtual void set_SkladRozn(bool SkladRozn);

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
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocSborkaKomplImpl __uuidof(TDMDocSborkaKomplImpl)
#endif
