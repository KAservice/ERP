#ifndef UDMDocVosvratPostImplH
#define UDMDocVosvratPostImplH
#include "IDMDocVosvratPost.h"
#include "UDMDocVosvratPost.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocVosvratPostImpl)) TDMDocVosvratPostImpl : public IDMDocVosvratPost
{
public:
   TDMDocVosvratPostImpl();
   ~TDMDocVosvratPostImpl();
   TDMDocVosvratPost * Object;
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

//IDMDocVosvratPost
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

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

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

   virtual TFIBDateTimeField * get_DocAllPOSDOC(void);
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC);

   virtual TFIBSmallIntField * get_DocAllPRDOC(void);
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

   virtual TFIBIntegerField * get_DocAllNUMDOC(void);
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC);

   virtual TFIBLargeIntField * get_DocAllIDFIRMDOC(void);
   virtual void set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC);

   virtual TFIBLargeIntField * get_DocAllIDSKLDOC(void);
   virtual void set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC);

   virtual TFIBLargeIntField * get_DocAllIDKLDOC(void);
   virtual void set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOGDOC(void);
   virtual void set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC);

   virtual TFIBBCDField * get_DocAllSUMDOC(void);
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC);

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

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

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

   virtual TFIBWideStringField * get_DocAllTDOC_OSN(void);
   virtual void set_DocAllTDOC_OSN(TFIBWideStringField * DocAllTDOC_OSN);

   virtual TFIBIntegerField * get_DocAllNUMDOC_OSN(void);
   virtual void set_DocAllNUMDOC_OSN(TFIBIntegerField * DocAllNUMDOC_OSN);

   virtual TFIBDateTimeField * get_DocAllPOSDOC_OSN(void);
   virtual void set_DocAllPOSDOC_OSN(TFIBDateTimeField * DocAllPOSDOC_OSN);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_DocIDVPO(void);
   virtual void set_DocIDVPO(TFIBLargeIntField * DocIDVPO);

   virtual TFIBLargeIntField * get_DocIDDOCVPO(void);
   virtual void set_DocIDDOCVPO(TFIBLargeIntField * DocIDDOCVPO);

   virtual TFIBWideStringField * get_DocPRIMVPO(void);
   virtual void set_DocPRIMVPO(TFIBWideStringField * DocPRIMVPO);

   virtual TFIBWideStringField * get_DocGID_DVPO(void);
   virtual void set_DocGID_DVPO(TFIBWideStringField * DocGID_DVPO);

   virtual TFIBLargeIntField * get_DocIDTPRICE_DVPO(void);
   virtual void set_DocIDTPRICE_DVPO(TFIBLargeIntField * DocIDTPRICE_DVPO);

   virtual TFIBLargeIntField * get_DocIDBASE_DVPO(void);
   virtual void set_DocIDBASE_DVPO(TFIBLargeIntField * DocIDBASE_DVPO);

   virtual TFIBLargeIntField * get_DocIDRTPRICE_DVPO(void);
   virtual void set_DocIDRTPRICE_DVPO(TFIBLargeIntField * DocIDRTPRICE_DVPO);

   virtual TFIBIntegerField * get_DocOPER_DVPO(void);
   virtual void set_DocOPER_DVPO(TFIBIntegerField * DocOPER_DVPO);

   virtual TFIBWideStringField * get_DocNUMDOCPOST_DVPO(void);
   virtual void set_DocNUMDOCPOST_DVPO(TFIBWideStringField * DocNUMDOCPOST_DVPO);

   virtual TFIBDateTimeField * get_DocPOSDOCPOST_DVPO(void);
   virtual void set_DocPOSDOCPOST_DVPO(TFIBDateTimeField * DocPOSDOCPOST_DVPO);

   virtual TFIBWideStringField * get_DocNAME_TPRICE(void);
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE);

   virtual TFIBLargeIntField * get_DocTIDVPOT(void);
   virtual void set_DocTIDVPOT(TFIBLargeIntField * DocTIDVPOT);

   virtual TFIBLargeIntField * get_DocTIDDOCVPOT(void);
   virtual void set_DocTIDDOCVPOT(TFIBLargeIntField * DocTIDDOCVPOT);

   virtual TFIBLargeIntField * get_DocTIDNOMVPOT(void);
   virtual void set_DocTIDNOMVPOT(TFIBLargeIntField * DocTIDNOMVPOT);

   virtual TFIBLargeIntField * get_DocTIDEDVPOT(void);
   virtual void set_DocTIDEDVPOT(TFIBLargeIntField * DocTIDEDVPOT);

   virtual TFIBBCDField * get_DocTKOLVPOT(void);
   virtual void set_DocTKOLVPOT(TFIBBCDField * DocTKOLVPOT);

   virtual TFIBBCDField * get_DocTKFVPOT(void);
   virtual void set_DocTKFVPOT(TFIBBCDField * DocTKFVPOT);

   virtual TFIBBCDField * get_DocTPRICEVPOT(void);
   virtual void set_DocTPRICEVPOT(TFIBBCDField * DocTPRICEVPOT);

   virtual TFIBBCDField * get_DocTSUMVPOT(void);
   virtual void set_DocTSUMVPOT(TFIBBCDField * DocTSUMVPOT);

   virtual TFIBWideStringField * get_DocTGID_DVPOT(void);
   virtual void set_DocTGID_DVPOT(TFIBWideStringField * DocTGID_DVPOT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DVPOT(void);
   virtual void set_DocTIDBASE_DVPOT(TFIBLargeIntField * DocTIDBASE_DVPOT);

   virtual TFIBBCDField * get_DocTRPRICE_DVPOT(void);
   virtual void set_DocTRPRICE_DVPOT(TFIBBCDField * DocTRPRICE_DVPOT);

   virtual TFIBBCDField * get_DocTRSUM_DVPOT(void);
   virtual void set_DocTRSUM_DVPOT(TFIBBCDField * DocTRSUM_DVPOT);

   virtual TFIBIntegerField * get_DocTNDS_DVPOT(void);
   virtual void set_DocTNDS_DVPOT(TFIBIntegerField * DocTNDS_DVPOT);

   virtual TFIBBCDField * get_DocTSUMNDS_DVPOT(void);
   virtual void set_DocTSUMNDS_DVPOT(TFIBBCDField * DocTSUMNDS_DVPOT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBSmallIntField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM);

   virtual TFIBLargeIntField * get_DocIDGRPOL_DVPO(void);
   virtual void set_DocIDGRPOL_DVPO(TFIBLargeIntField * DocIDGRPOL_DVPO);

   virtual TFIBLargeIntField * get_DocIDBSCHET_DVPO(void);
   virtual void set_DocIDBSCHET_DVPO(TFIBLargeIntField * DocIDBSCHET_DVPO);

   virtual TFIBLargeIntField * get_DocIDRSCHETKLIENT_DVPO(void);
   virtual void set_DocIDRSCHETKLIENT_DVPO(TFIBLargeIntField * DocIDRSCHETKLIENT_DVPO);

   virtual TFIBLargeIntField * get_DocIDRSCHETGRPOL_DVPO(void);
   virtual void set_DocIDRSCHETGRPOL_DVPO(TFIBLargeIntField * DocIDRSCHETGRPOL_DVPO);

   virtual TFIBWideStringField * get_DocNAMEKLIENT(void);
   virtual void set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT);

   virtual TFIBWideStringField * get_DocNAMEBSCHET(void);
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET);

   virtual TFIBWideStringField * get_DocNAME_RSCHET_KLIENT(void);
   virtual void set_DocNAME_RSCHET_KLIENT(TFIBWideStringField * DocNAME_RSCHET_KLIENT);

   virtual TFIBWideStringField * get_DocNAME_RSCHET_GRPOL(void);
   virtual void set_DocNAME_RSCHET_GRPOL(TFIBWideStringField * DocNAME_RSCHET_GRPOL);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

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
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocVosvratPostImpl __uuidof(TDMDocVosvratPostImpl)
#endif
