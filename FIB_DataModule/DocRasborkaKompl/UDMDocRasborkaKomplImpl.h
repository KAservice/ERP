#ifndef UDMDocRasborkaKomplImplH
#define UDMDocRasborkaKomplImplH
#include "IDMDocRasborkaKompl.h"
#include "UDMDocRasborkaKompl.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocRasborkaKomplImpl)) TDMDocRasborkaKomplImpl : public IDMDocRasborkaKompl
{
public:
   TDMDocRasborkaKomplImpl();
   ~TDMDocRasborkaKomplImpl();
   TDMDocRasborkaKompl * Object;
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

//IDMDocRasborkaKompl
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

   virtual TFIBBCDField * get_DocKF_DRASBKOMPL(void);
   virtual void set_DocKF_DRASBKOMPL(TFIBBCDField * DocKF_DRASBKOMPL);

   virtual TFIBBCDField * get_DocKOL_DRASBKOMPL(void);
   virtual void set_DocKOL_DRASBKOMPL(TFIBBCDField * DocKOL_DRASBKOMPL);

   virtual TFIBBCDField * get_DocRPRICE_DRASBKOMPL(void);
   virtual void set_DocRPRICE_DRASBKOMPL(TFIBBCDField * DocRPRICE_DRASBKOMPL);

   virtual TFIBBCDField * get_DocTKF_DRASBKOMPLT(void);
   virtual void set_DocTKF_DRASBKOMPLT(TFIBBCDField * DocTKF_DRASBKOMPLT);

   virtual TFIBBCDField * get_DocTKOL_DRASBKOMPLT(void);
   virtual void set_DocTKOL_DRASBKOMPLT(TFIBBCDField * DocTKOL_DRASBKOMPLT);

   virtual TFIBBCDField * get_DocTRPRICE_DRASBKOMPLT(void);
   virtual void set_DocTRPRICE_DRASBKOMPLT(TFIBBCDField * DocTRPRICE_DRASBKOMPLT);

   virtual TFIBBCDField * get_DocTRSUM_DRASBKOMPLT(void);
   virtual void set_DocTRSUM_DRASBKOMPLT(TFIBBCDField * DocTRSUM_DRASBKOMPLT);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBBCDField * get_DocTKFSEB_DRASBKOMPLT(void);
   virtual void set_DocTKFSEB_DRASBKOMPLT(TFIBBCDField * DocTKFSEB_DRASBKOMPLT);

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

   virtual TFIBLargeIntField * get_DocID_DRASBKOMPL(void);
   virtual void set_DocID_DRASBKOMPL(TFIBLargeIntField * DocID_DRASBKOMPL);

   virtual TFIBLargeIntField * get_DocIDBASE_DRASBKOMPL(void);
   virtual void set_DocIDBASE_DRASBKOMPL(TFIBLargeIntField * DocIDBASE_DRASBKOMPL);

   virtual TFIBLargeIntField * get_DocIDDOC_DRASBKOMPL(void);
   virtual void set_DocIDDOC_DRASBKOMPL(TFIBLargeIntField * DocIDDOC_DRASBKOMPL);

   virtual TFIBLargeIntField * get_DocIDNOM_DRASBKOMPL(void);
   virtual void set_DocIDNOM_DRASBKOMPL(TFIBLargeIntField * DocIDNOM_DRASBKOMPL);

   virtual TFIBLargeIntField * get_DocIDED_DRASBKOMPL(void);
   virtual void set_DocIDED_DRASBKOMPL(TFIBLargeIntField * DocIDED_DRASBKOMPL);

   virtual TFIBWideStringField * get_DocDESCR_DRASBKOMPL(void);
   virtual void set_DocDESCR_DRASBKOMPL(TFIBWideStringField * DocDESCR_DRASBKOMPL);

   virtual TFIBLargeIntField * get_DocIDRTPRICE_DRASBKOMPL(void);
   virtual void set_DocIDRTPRICE_DRASBKOMPL(TFIBLargeIntField * DocIDRTPRICE_DRASBKOMPL);

   virtual TFIBWideStringField * get_DocNAMENOM(void);
   virtual void set_DocNAMENOM(TFIBWideStringField * DocNAMENOM);

   virtual TFIBWideStringField * get_DocNAMEED(void);
   virtual void set_DocNAMEED(TFIBWideStringField * DocNAMEED);

   virtual TFIBLargeIntField * get_DocTID_DRASBKOMPLT(void);
   virtual void set_DocTID_DRASBKOMPLT(TFIBLargeIntField * DocTID_DRASBKOMPLT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DRASBKOMPLT(void);
   virtual void set_DocTIDBASE_DRASBKOMPLT(TFIBLargeIntField * DocTIDBASE_DRASBKOMPLT);

   virtual TFIBLargeIntField * get_DocTIDDOC_DRASBKOMPLT(void);
   virtual void set_DocTIDDOC_DRASBKOMPLT(TFIBLargeIntField * DocTIDDOC_DRASBKOMPLT);

   virtual TFIBLargeIntField * get_DocTIDNOM_DRASBKOMPLT(void);
   virtual void set_DocTIDNOM_DRASBKOMPLT(TFIBLargeIntField * DocTIDNOM_DRASBKOMPLT);

   virtual TFIBLargeIntField * get_DocTIDED_DRASBKOMPLT(void);
   virtual void set_DocTIDED_DRASBKOMPLT(TFIBLargeIntField * DocTIDED_DRASBKOMPLT);

   virtual TFIBLargeIntField * get_DocTIDPART_DRASBKOMPLT(void);
   virtual void set_DocTIDPART_DRASBKOMPLT(TFIBLargeIntField * DocTIDPART_DRASBKOMPLT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocAllGID_DOC(void);
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

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
#define CLSID_TDMDocRasborkaKomplImpl __uuidof(TDMDocRasborkaKomplImpl)
#endif
