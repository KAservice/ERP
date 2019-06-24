#ifndef UDMDocPerImplH
#define UDMDocPerImplH
#include "IDMDocPer.h"
#include "UDMDocPer.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocPerImpl)) TDMDocPerImpl : public IDMDocPer
{
public:
   TDMDocPerImpl();
   ~TDMDocPerImpl();
   TDMDocPer * Object;
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

//IDMDocPer
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

   virtual TFIBBCDField * get_DocTKOLPERT(void);
   virtual void set_DocTKOLPERT(TFIBBCDField * DocTKOLPERT);

   virtual TFIBBCDField * get_DocTKFPERT(void);
   virtual void set_DocTKFPERT(TFIBBCDField * DocTKFPERT);

   virtual TFIBBCDField * get_DocTPRICEPERT(void);
   virtual void set_DocTPRICEPERT(TFIBBCDField * DocTPRICEPERT);

   virtual TFIBBCDField * get_DocTSUMPERT(void);
   virtual void set_DocTSUMPERT(TFIBBCDField * DocTSUMPERT);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBDataSet * get_Firma(void);
   virtual void set_Firma(TpFIBDataSet * Firma);

   virtual TpFIBDataSet * get_Sklad(void);
   virtual void set_Sklad(TpFIBDataSet * Sklad);

   virtual TpFIBDataSet * get_SkladPol(void);
   virtual void set_SkladPol(TpFIBDataSet * SkladPol);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBBCDField * get_DocTNAC_DPERT(void);
   virtual void set_DocTNAC_DPERT(TFIBBCDField * DocTNAC_DPERT);

   virtual TFIBIntegerField * get_DocTNDS_DPERT(void);
   virtual void set_DocTNDS_DPERT(TFIBIntegerField * DocTNDS_DPERT);

   virtual TFIBBCDField * get_DocTSUMNDS_DPERT(void);
   virtual void set_DocTSUMNDS_DPERT(TFIBBCDField * DocTSUMNDS_DPERT);

   virtual TFIBLargeIntField * get_SkladPolIDSKLAD(void);
   virtual void set_SkladPolIDSKLAD(TFIBLargeIntField * SkladPolIDSKLAD);

   virtual TFIBWideStringField * get_SkladPolNAMESKLAD(void);
   virtual void set_SkladPolNAMESKLAD(TFIBWideStringField * SkladPolNAMESKLAD);

   virtual TFIBWideStringField * get_SkladPolMOLSKLAD(void);
   virtual void set_SkladPolMOLSKLAD(TFIBWideStringField * SkladPolMOLSKLAD);

   virtual TFIBWideStringField * get_SkladPolADRSKLAD(void);
   virtual void set_SkladPolADRSKLAD(TFIBWideStringField * SkladPolADRSKLAD);

   virtual TFIBIntegerField * get_SkladPolTSKLAD(void);
   virtual void set_SkladPolTSKLAD(TFIBIntegerField * SkladPolTSKLAD);

   virtual TFIBWideStringField * get_SkladPolGID_SSKLAD(void);
   virtual void set_SkladPolGID_SSKLAD(TFIBWideStringField * SkladPolGID_SSKLAD);

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

   virtual TFIBLargeIntField * get_DocIDPER(void);
   virtual void set_DocIDPER(TFIBLargeIntField * DocIDPER);

   virtual TFIBLargeIntField * get_DocIDDOCPER(void);
   virtual void set_DocIDDOCPER(TFIBLargeIntField * DocIDDOCPER);

   virtual TFIBLargeIntField * get_DocIDSKLPOLPER(void);
   virtual void set_DocIDSKLPOLPER(TFIBLargeIntField * DocIDSKLPOLPER);

   virtual TFIBWideStringField * get_DocPRIMPER(void);
   virtual void set_DocPRIMPER(TFIBWideStringField * DocPRIMPER);

   virtual TFIBWideStringField * get_DocGID_DPER(void);
   virtual void set_DocGID_DPER(TFIBWideStringField * DocGID_DPER);

   virtual TFIBLargeIntField * get_DocIDRTPRICE_DPER(void);
   virtual void set_DocIDRTPRICE_DPER(TFIBLargeIntField * DocIDRTPRICE_DPER);

   virtual TFIBLargeIntField * get_DocIDBASE_DPER(void);
   virtual void set_DocIDBASE_DPER(TFIBLargeIntField * DocIDBASE_DPER);

   virtual TFIBWideStringField * get_DocNAMESKLAD(void);
   virtual void set_DocNAMESKLAD(TFIBWideStringField * DocNAMESKLAD);

   virtual TFIBLargeIntField * get_DocTIDPERT(void);
   virtual void set_DocTIDPERT(TFIBLargeIntField * DocTIDPERT);

   virtual TFIBLargeIntField * get_DocTIDDOCPERT(void);
   virtual void set_DocTIDDOCPERT(TFIBLargeIntField * DocTIDDOCPERT);

   virtual TFIBLargeIntField * get_DocTIDNOMPERT(void);
   virtual void set_DocTIDNOMPERT(TFIBLargeIntField * DocTIDNOMPERT);

   virtual TFIBLargeIntField * get_DocTIDEDPERT(void);
   virtual void set_DocTIDEDPERT(TFIBLargeIntField * DocTIDEDPERT);

   virtual TFIBWideStringField * get_DocTGID_DPERT(void);
   virtual void set_DocTGID_DPERT(TFIBWideStringField * DocTGID_DPERT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DPERT(void);
   virtual void set_DocTIDBASE_DPERT(TFIBLargeIntField * DocTIDBASE_DPERT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBSmallIntField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM);

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

   virtual TFIBBCDField * get_DocTSEB_PRICE_DPERT(void);
   virtual void set_DocTSEB_PRICE_DPERT(TFIBBCDField * DocTSEB_PRICE_DPERT);

   virtual TFIBBCDField * get_DocTSEB_SUM_DPERT(void);
   virtual void set_DocTSEB_SUM_DPERT(TFIBBCDField * DocTSEB_SUM_DPERT);

   virtual TFIBBCDField * get_DocTNAC_SUM_ED(void);
   virtual void set_DocTNAC_SUM_ED(TFIBBCDField * DocTNAC_SUM_ED);

   virtual TFIBBCDField * get_DocTNAC_SUM(void);
   virtual void set_DocTNAC_SUM(TFIBBCDField * DocTNAC_SUM);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElementaMaster(void);
   virtual void set_IdElementaMaster(__int64 IdElementaMaster);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual bool get_SkladPolRozn(void);
   virtual void set_SkladPolRozn(bool SkladPolRozn);

   virtual bool get_SkladOtprRozn(void);
   virtual void set_SkladOtprRozn(bool SkladOtprRozn);

   virtual bool get_NoOtrOstatok(void);
   virtual void set_NoOtrOstatok(bool NoOtrOstatok);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 IdDoc);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual void CloseDoc(void);
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocPerImpl __uuidof(TDMDocPerImpl)
#endif
