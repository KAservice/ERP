#ifndef UDMDocRealImplH
#define UDMDocRealImplH
#include "IDMDocReal.h"
#include "UDMDocReal.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocRealImpl)) TDMDocRealImpl : public IDMDocReal
{
public:
   TDMDocRealImpl();
   ~TDMDocRealImpl();
   TDMDocReal * Object;
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

//IDMDocReal
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

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

   virtual TFIBBCDField * get_DocTKOLREAT(void);
   virtual void set_DocTKOLREAT(TFIBBCDField * DocTKOLREAT);

   virtual TFIBBCDField * get_DocTKFREAT(void);
   virtual void set_DocTKFREAT(TFIBBCDField * DocTKFREAT);

   virtual TFIBBCDField * get_DocTPRICEREAT(void);
   virtual void set_DocTPRICEREAT(TFIBBCDField * DocTPRICEREAT);

   virtual TFIBBCDField * get_DocTSUMREAT(void);
   virtual void set_DocTSUMREAT(TFIBBCDField * DocTSUMREAT);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

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

   virtual TFIBLargeIntField * get_DocIDREA(void);
   virtual void set_DocIDREA(TFIBLargeIntField * DocIDREA);

   virtual TFIBLargeIntField * get_DocIDDOCREA(void);
   virtual void set_DocIDDOCREA(TFIBLargeIntField * DocIDDOCREA);

   virtual TFIBWideStringField * get_DocPRIMREA(void);
   virtual void set_DocPRIMREA(TFIBWideStringField * DocPRIMREA);

   virtual TFIBWideStringField * get_DocGID_DREA(void);
   virtual void set_DocGID_DREA(TFIBWideStringField * DocGID_DREA);

   virtual TFIBLargeIntField * get_DocIDTPRICEREA(void);
   virtual void set_DocIDTPRICEREA(TFIBLargeIntField * DocIDTPRICEREA);

   virtual TFIBLargeIntField * get_DocIDGRPOLREA(void);
   virtual void set_DocIDGRPOLREA(TFIBLargeIntField * DocIDGRPOLREA);

   virtual TFIBLargeIntField * get_DocIDBSCHETREA(void);
   virtual void set_DocIDBSCHETREA(TFIBLargeIntField * DocIDBSCHETREA);

   virtual TFIBLargeIntField * get_DocIDBASE_DREA(void);
   virtual void set_DocIDBASE_DREA(TFIBLargeIntField * DocIDBASE_DREA);

   virtual TFIBWideStringField * get_DocNAME_TPRICE(void);
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE);

   virtual TFIBWideStringField * get_DocNAMEKLIENT(void);
   virtual void set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT);

   virtual TFIBWideStringField * get_DocNAMEBSCHET(void);
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET);

   virtual TFIBLargeIntField * get_DocTIDREAT(void);
   virtual void set_DocTIDREAT(TFIBLargeIntField * DocTIDREAT);

   virtual TFIBLargeIntField * get_DocTIDDOCREAT(void);
   virtual void set_DocTIDDOCREAT(TFIBLargeIntField * DocTIDDOCREAT);

   virtual TFIBLargeIntField * get_DocTIDNOMREAT(void);
   virtual void set_DocTIDNOMREAT(TFIBLargeIntField * DocTIDNOMREAT);

   virtual TFIBLargeIntField * get_DocTIDEDREAT(void);
   virtual void set_DocTIDEDREAT(TFIBLargeIntField * DocTIDEDREAT);

   virtual TFIBWideStringField * get_DocTGID_DREAT(void);
   virtual void set_DocTGID_DREAT(TFIBWideStringField * DocTGID_DREAT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DREAT(void);
   virtual void set_DocTIDBASE_DREAT(TFIBLargeIntField * DocTIDBASE_DREAT);

   virtual TFIBIntegerField * get_DocTNDS_DREAT(void);
   virtual void set_DocTNDS_DREAT(TFIBIntegerField * DocTNDS_DREAT);

   virtual TFIBBCDField * get_DocTSUMNDS_DREAT(void);
   virtual void set_DocTSUMNDS_DREAT(TFIBBCDField * DocTSUMNDS_DREAT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBSmallIntField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_DocIDRSCHETKLIENT_DREA(void);
   virtual void set_DocIDRSCHETKLIENT_DREA(TFIBLargeIntField * DocIDRSCHETKLIENT_DREA);

   virtual TFIBLargeIntField * get_DocIDRSCHETGRPOL_DREA(void);
   virtual void set_DocIDRSCHETGRPOL_DREA(TFIBLargeIntField * DocIDRSCHETGRPOL_DREA);

   virtual TFIBWideStringField * get_DocNAME_RSCHET_KLIENT(void);
   virtual void set_DocNAME_RSCHET_KLIENT(TFIBWideStringField * DocNAME_RSCHET_KLIENT);

   virtual TFIBWideStringField * get_DocNAME_RSCHET_GRPOL(void);
   virtual void set_DocNAME_RSCHET_GRPOL(TFIBWideStringField * DocNAME_RSCHET_GRPOL);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual TFIBBCDField * get_DocTSUMSK_DREAT(void);
   virtual void set_DocTSUMSK_DREAT(TFIBBCDField * DocTSUMSK_DREAT);

   virtual TFIBBCDField * get_DocTPRSK_CARD_DREAT(void);
   virtual void set_DocTPRSK_CARD_DREAT(TFIBBCDField * DocTPRSK_CARD_DREAT);

   virtual TFIBBCDField * get_DocTPRSK_AUTO_DREAT(void);
   virtual void set_DocTPRSK_AUTO_DREAT(TFIBBCDField * DocTPRSK_AUTO_DREAT);

   virtual TFIBBCDField * get_DocTPRSK_HAND_DREAT(void);
   virtual void set_DocTPRSK_HAND_DREAT(TFIBBCDField * DocTPRSK_HAND_DREAT);

   virtual TFIBBCDField * get_DocTPRSK_DREAT(void);
   virtual void set_DocTPRSK_DREAT(TFIBBCDField * DocTPRSK_DREAT);

   virtual TFIBBCDField * get_DocTNO_SK_DREAT(void);
   virtual void set_DocTNO_SK_DREAT(TFIBBCDField * DocTNO_SK_DREAT);

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

   virtual bool get_NoEdit(void);
   virtual void set_NoEdit(bool NoEdit);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual double get_SummaDoc(void);
   virtual void set_SummaDoc(double SummaDoc);

   virtual double get_OldSummaStr(void);
   virtual void set_OldSummaStr(double OldSummaStr);

   virtual double get_NewSummaStr(void);
   virtual void set_NewSummaStr(double NewSummaStr);

   virtual int get_IdSklad(void);
   virtual void set_IdSklad(int IdSklad);

   virtual bool get_AutoRaschet(void);
   virtual void set_AutoRaschet(bool AutoRaschet);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual bool get_SkladRozn(void);
   virtual void set_SkladRozn(bool SkladRozn);

   virtual bool get_NoOtrOstatok(void);
   virtual void set_NoOtrOstatok(bool NoOtrOstatok);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 IdDoc);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual void CloseDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
   virtual __int64 GetIDDocSchetFact(void);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocRealImpl __uuidof(TDMDocRealImpl)
#endif
