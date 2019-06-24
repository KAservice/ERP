#ifndef UDMDocSchetImplH
#define UDMDocSchetImplH
#include "IDMDocSchet.h"
#include "UDMDocSchet.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocSchetImpl)) TDMDocSchetImpl : public IDMDocSchet
{
public:
   TDMDocSchetImpl();
   ~TDMDocSchetImpl();
   TDMDocSchet * Object;
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

//IDMDocSchet
   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

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

   virtual TFIBBCDField * get_DocTKOLSCHT(void);
   virtual void set_DocTKOLSCHT(TFIBBCDField * DocTKOLSCHT);

   virtual TFIBBCDField * get_DocTKFSCHT(void);
   virtual void set_DocTKFSCHT(TFIBBCDField * DocTKFSCHT);

   virtual TFIBBCDField * get_DocTPRICESCHT(void);
   virtual void set_DocTPRICESCHT(TFIBBCDField * DocTPRICESCHT);

   virtual TFIBBCDField * get_DocTSUMSCHT(void);
   virtual void set_DocTSUMSCHT(TFIBBCDField * DocTSUMSCHT);

   virtual TFIBIntegerField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

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

   virtual TFIBBCDField * get_DocIDSCH(void);
   virtual void set_DocIDSCH(TFIBBCDField * DocIDSCH);

   virtual TFIBBCDField * get_DocIDDOCSCH(void);
   virtual void set_DocIDDOCSCH(TFIBBCDField * DocIDDOCSCH);

   virtual TFIBBCDField * get_DocIDBSCHET_DSCH(void);
   virtual void set_DocIDBSCHET_DSCH(TFIBBCDField * DocIDBSCHET_DSCH);

   virtual TFIBBCDField * get_DocIDTPRICESCH(void);
   virtual void set_DocIDTPRICESCH(TFIBBCDField * DocIDTPRICESCH);

   virtual TFIBBCDField * get_DocTIDSCHT(void);
   virtual void set_DocTIDSCHT(TFIBBCDField * DocTIDSCHT);

   virtual TFIBBCDField * get_DocTIDDOCSCHT(void);
   virtual void set_DocTIDDOCSCHT(TFIBBCDField * DocTIDDOCSCHT);

   virtual TFIBBCDField * get_DocTIDNOMSCHT(void);
   virtual void set_DocTIDNOMSCHT(TFIBBCDField * DocTIDNOMSCHT);

   virtual TFIBBCDField * get_DocTIDEDSCHT(void);
   virtual void set_DocTIDEDSCHT(TFIBBCDField * DocTIDEDSCHT);

   virtual TFIBBCDField * get_DocAllIDEXTDOC(void);
   virtual void set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_DocIDBASE_DSCH(void);
   virtual void set_DocIDBASE_DSCH(TFIBBCDField * DocIDBASE_DSCH);

   virtual TFIBBCDField * get_DocTIDBASE_DSCHT(void);
   virtual void set_DocTIDBASE_DSCHT(TFIBBCDField * DocTIDBASE_DSCHT);

   virtual TFIBBCDField * get_DocAllIDBASE_GALLDOC(void);
   virtual void set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC);

   virtual TFIBIntegerField * get_DocTNDS_DSCHT(void);
   virtual void set_DocTNDS_DSCHT(TFIBIntegerField * DocTNDS_DSCHT);

   virtual TFIBBCDField * get_DocTSUMNDS_DSCHT(void);
   virtual void set_DocTSUMNDS_DSCHT(TFIBBCDField * DocTSUMNDS_DSCHT);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

   virtual TFIBWideStringField * get_DocAllGID_DOC(void);
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC);

   virtual TFIBWideStringField * get_DocAllPREFIKSDOC(void);
   virtual void set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC);

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

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocPRIMSCH(void);
   virtual void set_DocPRIMSCH(TFIBWideStringField * DocPRIMSCH);

   virtual TFIBWideStringField * get_DocGID_DSCH(void);
   virtual void set_DocGID_DSCH(TFIBWideStringField * DocGID_DSCH);

   virtual TFIBWideStringField * get_DocNAME_TPRICE(void);
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE);

   virtual TFIBWideStringField * get_DocNAMEBSCHET(void);
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET);

   virtual TFIBWideStringField * get_DocTGID_DSCHT(void);
   virtual void set_DocTGID_DSCHT(TFIBWideStringField * DocTGID_DSCHT);

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

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual TFIBBCDField * get_DocTSUMSK_DSCHT(void);
   virtual void set_DocTSUMSK_DSCHT(TFIBBCDField * DocTSUMSK_DSCHT);

   virtual TFIBBCDField * get_DocTPRSK_DSCHT(void);
   virtual void set_DocTPRSK_DSCHT(TFIBBCDField * DocTPRSK_DSCHT);

   virtual TFIBSmallIntField * get_DocTNO_SK_DSCHT(void);
   virtual void set_DocTNO_SK_DSCHT(TFIBSmallIntField * DocTNO_SK_DSCHT);

   virtual TFIBBCDField * get_DocTPRSK_CARD_DSCHT(void);
   virtual void set_DocTPRSK_CARD_DSCHT(TFIBBCDField * DocTPRSK_CARD_DSCHT);

   virtual TFIBBCDField * get_DocTPRSK_AUTO_DSCHT(void);
   virtual void set_DocTPRSK_AUTO_DSCHT(TFIBBCDField * DocTPRSK_AUTO_DSCHT);

   virtual TFIBBCDField * get_DocTPRSK_HAND_DSCHT(void);
   virtual void set_DocTPRSK_HAND_DSCHT(TFIBBCDField * DocTPRSK_HAND_DSCHT);

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
   virtual void CloseDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocSchetImpl __uuidof(TDMDocSchetImpl)
#endif
