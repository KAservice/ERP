#ifndef UDMDocVosvratPokImplH
#define UDMDocVosvratPokImplH
#include "IDMDocVosvratPok.h"
#include "UDMDocVosvratPok.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocVosvratPokImpl)) TDMDocVosvratPokImpl : public IDMDocVosvratPok
{
public:
   TDMDocVosvratPokImpl();
   ~TDMDocVosvratPokImpl();
   TDMDocVosvratPok * Object;
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

//IDMDocVosvratPok
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

   virtual TFIBWideStringField * get_DocAllNAME_SDOG(void);
   virtual void set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_DocID_DVPOK(void);
   virtual void set_DocID_DVPOK(TFIBLargeIntField * DocID_DVPOK);

   virtual TFIBWideStringField * get_DocGID_DVPOK(void);
   virtual void set_DocGID_DVPOK(TFIBWideStringField * DocGID_DVPOK);

   virtual TFIBLargeIntField * get_DocIDDOC_DVPOK(void);
   virtual void set_DocIDDOC_DVPOK(TFIBLargeIntField * DocIDDOC_DVPOK);

   virtual TFIBLargeIntField * get_DocIDTPRICE_DVPOK(void);
   virtual void set_DocIDTPRICE_DVPOK(TFIBLargeIntField * DocIDTPRICE_DVPOK);

   virtual TFIBLargeIntField * get_DocIDRTPRICE_DVPOK(void);
   virtual void set_DocIDRTPRICE_DVPOK(TFIBLargeIntField * DocIDRTPRICE_DVPOK);

   virtual TFIBWideStringField * get_DocDESCR_DVPOK(void);
   virtual void set_DocDESCR_DVPOK(TFIBWideStringField * DocDESCR_DVPOK);

   virtual TFIBIntegerField * get_DocOPER_DVPOK(void);
   virtual void set_DocOPER_DVPOK(TFIBIntegerField * DocOPER_DVPOK);

   virtual TFIBBCDField * get_DocSUM_DVPOK(void);
   virtual void set_DocSUM_DVPOK(TFIBBCDField * DocSUM_DVPOK);

   virtual TFIBLargeIntField * get_DocIDBASE_DVPOK(void);
   virtual void set_DocIDBASE_DVPOK(TFIBLargeIntField * DocIDBASE_DVPOK);

   virtual TFIBLargeIntField * get_DocTID_DVPOKT(void);
   virtual void set_DocTID_DVPOKT(TFIBLargeIntField * DocTID_DVPOKT);

   virtual TFIBWideStringField * get_DocTGID_DVPOKT(void);
   virtual void set_DocTGID_DVPOKT(TFIBWideStringField * DocTGID_DVPOKT);

   virtual TFIBLargeIntField * get_DocTIDDOC_DVPOKT(void);
   virtual void set_DocTIDDOC_DVPOKT(TFIBLargeIntField * DocTIDDOC_DVPOKT);

   virtual TFIBLargeIntField * get_DocTIDNOM_DVPOKT(void);
   virtual void set_DocTIDNOM_DVPOKT(TFIBLargeIntField * DocTIDNOM_DVPOKT);

   virtual TFIBLargeIntField * get_DocTIDED_DVPOKT(void);
   virtual void set_DocTIDED_DVPOKT(TFIBLargeIntField * DocTIDED_DVPOKT);

   virtual TFIBLargeIntField * get_DocTIDPART_DVPOKT(void);
   virtual void set_DocTIDPART_DVPOKT(TFIBLargeIntField * DocTIDPART_DVPOKT);

   virtual TFIBBCDField * get_DocTKOL_DVPOKT(void);
   virtual void set_DocTKOL_DVPOKT(TFIBBCDField * DocTKOL_DVPOKT);

   virtual TFIBBCDField * get_DocTKF_DVPOKT(void);
   virtual void set_DocTKF_DVPOKT(TFIBBCDField * DocTKF_DVPOKT);

   virtual TFIBBCDField * get_DocTPRICE_DVPOKT(void);
   virtual void set_DocTPRICE_DVPOKT(TFIBBCDField * DocTPRICE_DVPOKT);

   virtual TFIBBCDField * get_DocTSUM_DVPOKT(void);
   virtual void set_DocTSUM_DVPOKT(TFIBBCDField * DocTSUM_DVPOKT);

   virtual TFIBBCDField * get_DocTRPRICE_DVPOKT(void);
   virtual void set_DocTRPRICE_DVPOKT(TFIBBCDField * DocTRPRICE_DVPOKT);

   virtual TFIBBCDField * get_DocTRSUM_DVPOKT(void);
   virtual void set_DocTRSUM_DVPOKT(TFIBBCDField * DocTRSUM_DVPOKT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DVPOKT(void);
   virtual void set_DocTIDBASE_DVPOKT(TFIBLargeIntField * DocTIDBASE_DVPOKT);

   virtual TFIBIntegerField * get_DocTNDS_DVPOKT(void);
   virtual void set_DocTNDS_DVPOKT(TFIBIntegerField * DocTNDS_DVPOKT);

   virtual TFIBBCDField * get_DocTSUMNDS_DVPOKT(void);
   virtual void set_DocTSUMNDS_DVPOKT(TFIBBCDField * DocTSUMNDS_DVPOKT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocKLIENT_NAME_DVPOK(void);
   virtual void set_DocKLIENT_NAME_DVPOK(TFIBWideStringField * DocKLIENT_NAME_DVPOK);

   virtual TFIBWideStringField * get_DocKLIENT_ADR_DVPOK(void);
   virtual void set_DocKLIENT_ADR_DVPOK(TFIBWideStringField * DocKLIENT_ADR_DVPOK);

   virtual TFIBWideStringField * get_DocKLIENT_PHONE_DVPOK(void);
   virtual void set_DocKLIENT_PHONE_DVPOK(TFIBWideStringField * DocKLIENT_PHONE_DVPOK);

   virtual TFIBWideStringField * get_DocKLIENT_PASSPORT_DVPOK(void);
   virtual void set_DocKLIENT_PASSPORT_DVPOK(TFIBWideStringField * DocKLIENT_PASSPORT_DVPOK);

   virtual TFIBWideStringField * get_DocPRICHINA_DVPOK(void);
   virtual void set_DocPRICHINA_DVPOK(TFIBWideStringField * DocPRICHINA_DVPOK);

   virtual TFIBWideStringField * get_DocNUMDOCSALE_DVPOK(void);
   virtual void set_DocNUMDOCSALE_DVPOK(TFIBWideStringField * DocNUMDOCSALE_DVPOK);

   virtual TFIBDateTimeField * get_DocPOSDOCSALE_DVPOK(void);
   virtual void set_DocPOSDOCSALE_DVPOK(TFIBDateTimeField * DocPOSDOCSALE_DVPOK);

   virtual TFIBWideStringField * get_DocNUMDOCKL_DVPOK(void);
   virtual void set_DocNUMDOCKL_DVPOK(TFIBWideStringField * DocNUMDOCKL_DVPOK);

   virtual TFIBDateTimeField * get_DocPOSDOCKL_DVPOK(void);
   virtual void set_DocPOSDOCKL_DVPOK(TFIBDateTimeField * DocPOSDOCKL_DVPOK);

   virtual TpFIBDataSet * get_DocOsn(void);
   virtual void set_DocOsn(TpFIBDataSet * DocOsn);

   virtual TFIBWideStringField * get_DocOsnTDOC(void);
   virtual void set_DocOsnTDOC(TFIBWideStringField * DocOsnTDOC);

   virtual TFIBDateTimeField * get_DocOsnPOSDOC(void);
   virtual void set_DocOsnPOSDOC(TFIBDateTimeField * DocOsnPOSDOC);

   virtual TFIBIntegerField * get_DocOsnNUMDOC(void);
   virtual void set_DocOsnNUMDOC(TFIBIntegerField * DocOsnNUMDOC);

   virtual TDataSource * get_DataSourceDocOsn(void);
   virtual void set_DataSourceDocOsn(TDataSource * DataSourceDocOsn);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual bool get_IsmPrice(void);
   virtual void set_IsmPrice(bool IsmPrice);

   virtual bool get_IsmSum(void);
   virtual void set_IsmSum(bool IsmSum);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 IdDoc);
   virtual void OpenDocOsn(void);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
   virtual void AddZakPrice(void);
};
#define CLSID_TDMDocVosvratPokImpl __uuidof(TDMDocVosvratPokImpl)
#endif
