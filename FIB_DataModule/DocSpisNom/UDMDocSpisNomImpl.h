#ifndef UDMDocSpisNomImplH
#define UDMDocSpisNomImplH
#include "IDMDocSpisNom.h"
#include "UDMDocSpisNom.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocSpisNomImpl)) TDMDocSpisNomImpl : public IDMDocSpisNom
{
public:
   TDMDocSpisNomImpl();
   ~TDMDocSpisNomImpl();
   TDMDocSpisNom * Object;
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

//IDMDocSpisNom
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

   virtual TFIBBCDField * get_DocTKOLSPNT(void);
   virtual void set_DocTKOLSPNT(TFIBBCDField * DocTKOLSPNT);

   virtual TFIBBCDField * get_DocTKFSPNT(void);
   virtual void set_DocTKFSPNT(TFIBBCDField * DocTKFSPNT);

   virtual TFIBBCDField * get_DocTPRICESPNT(void);
   virtual void set_DocTPRICESPNT(TFIBBCDField * DocTPRICESPNT);

   virtual TFIBBCDField * get_DocTSUMSPNT(void);
   virtual void set_DocTSUMSPNT(TFIBBCDField * DocTSUMSPNT);

   virtual TFIBIntegerField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBDataSet * get_Grp(void);
   virtual void set_Grp(TpFIBDataSet * Grp);

   virtual TpFIBDataSet * get_El(void);
   virtual void set_El(TpFIBDataSet * El);

   virtual TFIBBCDField * get_GrpSUMMA(void);
   virtual void set_GrpSUMMA(TFIBBCDField * GrpSUMMA);

   virtual TFIBBCDField * get_ElSUMMA(void);
   virtual void set_ElSUMMA(TFIBBCDField * ElSUMMA);

   virtual TFIBFloatField * get_ElSUMKOL(void);
   virtual void set_ElSUMKOL(TFIBFloatField * ElSUMKOL);

   virtual TpFIBDataSet * get_DocOsn(void);
   virtual void set_DocOsn(TpFIBDataSet * DocOsn);

   virtual TFIBIntegerField * get_DocOsnNUMDOC(void);
   virtual void set_DocOsnNUMDOC(TFIBIntegerField * DocOsnNUMDOC);

   virtual TFIBDateTimeField * get_DocOsnPOSDOC(void);
   virtual void set_DocOsnPOSDOC(TFIBDateTimeField * DocOsnPOSDOC);

   virtual TFIBBCDField * get_DocRSUM_DSPN(void);
   virtual void set_DocRSUM_DSPN(TFIBBCDField * DocRSUM_DSPN);

   virtual TFIBBCDField * get_DocTRPRICE_DSPNT(void);
   virtual void set_DocTRPRICE_DSPNT(TFIBBCDField * DocTRPRICE_DSPNT);

   virtual TFIBBCDField * get_DocTRSUM_DSPNT(void);
   virtual void set_DocTRSUM_DSPNT(TFIBBCDField * DocTRSUM_DSPNT);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBBCDField * get_GrpIDGN(void);
   virtual void set_GrpIDGN(TFIBBCDField * GrpIDGN);

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

   virtual TFIBBCDField * get_DocIDSPN(void);
   virtual void set_DocIDSPN(TFIBBCDField * DocIDSPN);

   virtual TFIBBCDField * get_DocIDDOCSPN(void);
   virtual void set_DocIDDOCSPN(TFIBBCDField * DocIDDOCSPN);

   virtual TFIBBCDField * get_DocIDRTPRICE_DSPN(void);
   virtual void set_DocIDRTPRICE_DSPN(TFIBBCDField * DocIDRTPRICE_DSPN);

   virtual TFIBBCDField * get_DocTIDSPNT(void);
   virtual void set_DocTIDSPNT(TFIBBCDField * DocTIDSPNT);

   virtual TFIBBCDField * get_DocTIDDOCSPNT(void);
   virtual void set_DocTIDDOCSPNT(TFIBBCDField * DocTIDDOCSPNT);

   virtual TFIBBCDField * get_DocTIDNOMSPNT(void);
   virtual void set_DocTIDNOMSPNT(TFIBBCDField * DocTIDNOMSPNT);

   virtual TFIBBCDField * get_DocTIDEDSPNT(void);
   virtual void set_DocTIDEDSPNT(TFIBBCDField * DocTIDEDSPNT);

   virtual TFIBBCDField * get_DocAllIDEXTDOC(void);
   virtual void set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC);

   virtual TFIBBCDField * get_DocIDBASE_DSPN(void);
   virtual void set_DocIDBASE_DSPN(TFIBBCDField * DocIDBASE_DSPN);

   virtual TFIBBCDField * get_DocTIDBASE_DSPNT(void);
   virtual void set_DocTIDBASE_DSPNT(TFIBBCDField * DocTIDBASE_DSPNT);

   virtual TFIBBCDField * get_DocAllIDBASE_GALLDOC(void);
   virtual void set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC);

   virtual TFIBWideStringField * get_DocOsnTDOC(void);
   virtual void set_DocOsnTDOC(TFIBWideStringField * DocOsnTDOC);

   virtual TFIBWideStringField * get_GrpNAMEGN(void);
   virtual void set_GrpNAMEGN(TFIBWideStringField * GrpNAMEGN);

   virtual TFIBWideStringField * get_ElNAMENOM(void);
   virtual void set_ElNAMENOM(TFIBWideStringField * ElNAMENOM);

   virtual TFIBWideStringField * get_ElNAMEED(void);
   virtual void set_ElNAMEED(TFIBWideStringField * ElNAMEED);

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

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocPRIMSPN(void);
   virtual void set_DocPRIMSPN(TFIBWideStringField * DocPRIMSPN);

   virtual TFIBWideStringField * get_DocGID_DSPN(void);
   virtual void set_DocGID_DSPN(TFIBWideStringField * DocGID_DSPN);

   virtual TFIBIntegerField * get_DocOPER_DSPN(void);
   virtual void set_DocOPER_DSPN(TFIBIntegerField * DocOPER_DSPN);

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

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual int get_IdSklad(void);
   virtual void set_IdSklad(int IdSklad);

   virtual bool get_SkladRozn(void);
   virtual void set_SkladRozn(bool SkladRozn);

   virtual bool get_NoOtrOstatok(void);
   virtual void set_NoOtrOstatok(bool NoOtrOstatok);

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
   virtual bool AddDataInv(void);
   virtual bool SearchStringPoNom(__int64 id_nom);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocSpisNomImpl __uuidof(TDMDocSpisNomImpl)
#endif
