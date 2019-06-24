#ifndef UDMDocPrihNaklImplH
#define UDMDocPrihNaklImplH
#include "IDMDocPrihNakl.h"
#include "UDMDocPrihNakl.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocPrihNaklImpl)) TDMDocPrihNaklImpl : public IDMDocPrihNakl
{
public:
   TDMDocPrihNaklImpl();
   ~TDMDocPrihNaklImpl();
   TDMDocPrihNakl * Object;
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

//IDMDocPrihNakl
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

   virtual TFIBBCDField * get_DocTKOLPRNT(void);
   virtual void set_DocTKOLPRNT(TFIBBCDField * DocTKOLPRNT);

   virtual TFIBBCDField * get_DocTKFPRNT(void);
   virtual void set_DocTKFPRNT(TFIBBCDField * DocTKFPRNT);

   virtual TFIBBCDField * get_DocTPRICEPRNT(void);
   virtual void set_DocTPRICEPRNT(TFIBBCDField * DocTPRICEPRNT);

   virtual TFIBBCDField * get_DocTSUMPRNT(void);
   virtual void set_DocTSUMPRNT(TFIBBCDField * DocTSUMPRNT);

   virtual TFIBIntegerField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TFIBBCDField * get_DocTNAC_DPRNT(void);
   virtual void set_DocTNAC_DPRNT(TFIBBCDField * DocTNAC_DPRNT);

   virtual TFIBBCDField * get_DocTRPRICE_DPRNT(void);
   virtual void set_DocTRPRICE_DPRNT(TFIBBCDField * DocTRPRICE_DPRNT);

   virtual TFIBBCDField * get_DocTRSUM_DPRNT(void);
   virtual void set_DocTRSUM_DPRNT(TFIBBCDField * DocTRSUM_DPRNT);

   virtual TFIBBCDField * get_DocRSUM_DPRN(void);
   virtual void set_DocRSUM_DPRN(TFIBBCDField * DocRSUM_DPRN);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBDateTimeField * get_DocPOSDOCPOST_DPRN(void);
   virtual void set_DocPOSDOCPOST_DPRN(TFIBDateTimeField * DocPOSDOCPOST_DPRN);

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

   virtual TFIBLargeIntField * get_DocIDPRN(void);
   virtual void set_DocIDPRN(TFIBLargeIntField * DocIDPRN);

   virtual TFIBLargeIntField * get_DocIDDOCPRN(void);
   virtual void set_DocIDDOCPRN(TFIBLargeIntField * DocIDDOCPRN);

   virtual TFIBWideStringField * get_DocPRIMDOC(void);
   virtual void set_DocPRIMDOC(TFIBWideStringField * DocPRIMDOC);

   virtual TFIBLargeIntField * get_DocIDTPRICE(void);
   virtual void set_DocIDTPRICE(TFIBLargeIntField * DocIDTPRICE);

   virtual TFIBWideStringField * get_DocGID_DPRN(void);
   virtual void set_DocGID_DPRN(TFIBWideStringField * DocGID_DPRN);

   virtual TFIBLargeIntField * get_DocIDRTPRICE_DPRN(void);
   virtual void set_DocIDRTPRICE_DPRN(TFIBLargeIntField * DocIDRTPRICE_DPRN);

   virtual TFIBLargeIntField * get_DocIDBASE_DPRN(void);
   virtual void set_DocIDBASE_DPRN(TFIBLargeIntField * DocIDBASE_DPRN);

   virtual TFIBLargeIntField * get_DocTIDPRNT(void);
   virtual void set_DocTIDPRNT(TFIBLargeIntField * DocTIDPRNT);

   virtual TFIBLargeIntField * get_DocTIDDOCPRNT(void);
   virtual void set_DocTIDDOCPRNT(TFIBLargeIntField * DocTIDDOCPRNT);

   virtual TFIBLargeIntField * get_DocTIDNOMPRNT(void);
   virtual void set_DocTIDNOMPRNT(TFIBLargeIntField * DocTIDNOMPRNT);

   virtual TFIBLargeIntField * get_DocTIDEDPRNT(void);
   virtual void set_DocTIDEDPRNT(TFIBLargeIntField * DocTIDEDPRNT);

   virtual TFIBLargeIntField * get_DocTIDPARTPRNT(void);
   virtual void set_DocTIDPARTPRNT(TFIBLargeIntField * DocTIDPARTPRNT);

   virtual TFIBWideStringField * get_DocTGID_DPRNT(void);
   virtual void set_DocTGID_DPRNT(TFIBWideStringField * DocTGID_DPRNT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DPRNT(void);
   virtual void set_DocTIDBASE_DPRNT(TFIBLargeIntField * DocTIDBASE_DPRNT);

   virtual TFIBIntegerField * get_DocTNDS_DPRNT(void);
   virtual void set_DocTNDS_DPRNT(TFIBIntegerField * DocTNDS_DPRNT);

   virtual TFIBBCDField * get_DocTSUMNDS_DPRNT(void);
   virtual void set_DocTSUMNDS_DPRNT(TFIBBCDField * DocTSUMNDS_DPRNT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocTGTDPART(void);
   virtual void set_DocTGTDPART(TFIBWideStringField * DocTGTDPART);

   virtual TFIBWideStringField * get_DocTSERTPART(void);
   virtual void set_DocTSERTPART(TFIBWideStringField * DocTSERTPART);

   virtual TFIBDateTimeField * get_DocTSRGODNPART(void);
   virtual void set_DocTSRGODNPART(TFIBDateTimeField * DocTSRGODNPART);

   virtual TFIBWideStringField * get_DocNUMDOCPOST_DPRN(void);
   virtual void set_DocNUMDOCPOST_DPRN(TFIBWideStringField * DocNUMDOCPOST_DPRN);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual TFIBBCDField * get_DocTNAC_SUM_ED(void);
   virtual void set_DocTNAC_SUM_ED(TFIBBCDField * DocTNAC_SUM_ED);

   virtual TFIBBCDField * get_DocTNAC_SUM(void);
   virtual void set_DocTNAC_SUM(TFIBBCDField * DocTNAC_SUM);

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
   virtual void CreateNewPart(void);
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
   virtual bool UpdatePrice(void);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocPrihNaklImpl __uuidof(TDMDocPrihNaklImpl)
#endif
