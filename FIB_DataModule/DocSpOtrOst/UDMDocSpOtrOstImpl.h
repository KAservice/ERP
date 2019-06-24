#ifndef UDMDocSpOtrOstImplH
#define UDMDocSpOtrOstImplH
#include "IDMDocSpOtrOst.h"
#include "UDMDocSpOtrOst.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocSpOtrOstImpl)) TDMDocSpOtrOstImpl : public IDMDocSpOtrOst
{
public:
   TDMDocSpOtrOstImpl();
   ~TDMDocSpOtrOstImpl();
   TDMDocSpOtrOst * Object;
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

//IDMDocSpOtrOst
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

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBDataSet * get_IBQPoGrp(void);
   virtual void set_IBQPoGrp(TpFIBDataSet * IBQPoGrp);

   virtual TpFIBDataSet * get_IBQ(void);
   virtual void set_IBQ(TpFIBDataSet * IBQ);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBIntegerField * get_IBQPoGrpTNOM(void);
   virtual void set_IBQPoGrpTNOM(TFIBIntegerField * IBQPoGrpTNOM);

   virtual TFIBIntegerField * get_IBQPoGrpCODENOM(void);
   virtual void set_IBQPoGrpCODENOM(TFIBIntegerField * IBQPoGrpCODENOM);

   virtual TFIBBCDField * get_IBQPoGrpKOL_DSPOTROSTT(void);
   virtual void set_IBQPoGrpKOL_DSPOTROSTT(TFIBBCDField * IBQPoGrpKOL_DSPOTROSTT);

   virtual TFIBBCDField * get_IBQPoGrpKF_DSPOTROSTT(void);
   virtual void set_IBQPoGrpKF_DSPOTROSTT(TFIBBCDField * IBQPoGrpKF_DSPOTROSTT);

   virtual TFIBBCDField * get_IBQPoGrpPRICE_DSPOTROSTT(void);
   virtual void set_IBQPoGrpPRICE_DSPOTROSTT(TFIBBCDField * IBQPoGrpPRICE_DSPOTROSTT);

   virtual TFIBBCDField * get_IBQPoGrpSUM_DSPOTROSTT(void);
   virtual void set_IBQPoGrpSUM_DSPOTROSTT(TFIBBCDField * IBQPoGrpSUM_DSPOTROSTT);

   virtual TFIBBCDField * get_IBQPoGrpRPRICE_DSPOTROSTT(void);
   virtual void set_IBQPoGrpRPRICE_DSPOTROSTT(TFIBBCDField * IBQPoGrpRPRICE_DSPOTROSTT);

   virtual TFIBBCDField * get_IBQPoGrpRSUM_DSPOTROSTT(void);
   virtual void set_IBQPoGrpRSUM_DSPOTROSTT(TFIBBCDField * IBQPoGrpRSUM_DSPOTROSTT);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBBCDField * get_IBQPoGrpIDGN(void);
   virtual void set_IBQPoGrpIDGN(TFIBBCDField * IBQPoGrpIDGN);

   virtual TFIBBCDField * get_IBQPoGrpID_DSPOTROSTT(void);
   virtual void set_IBQPoGrpID_DSPOTROSTT(TFIBBCDField * IBQPoGrpID_DSPOTROSTT);

   virtual TFIBBCDField * get_IBQPoGrpIDDOC_DSPOTROSTT(void);
   virtual void set_IBQPoGrpIDDOC_DSPOTROSTT(TFIBBCDField * IBQPoGrpIDDOC_DSPOTROSTT);

   virtual TFIBBCDField * get_IBQPoGrpIDNOM_DSPOTROSTT(void);
   virtual void set_IBQPoGrpIDNOM_DSPOTROSTT(TFIBBCDField * IBQPoGrpIDNOM_DSPOTROSTT);

   virtual TFIBBCDField * get_IBQPoGrpIDED_DSPOTROSTT(void);
   virtual void set_IBQPoGrpIDED_DSPOTROSTT(TFIBBCDField * IBQPoGrpIDED_DSPOTROSTT);

   virtual TFIBBCDField * get_IBQPoGrpIDPART_DSPOTROSTT(void);
   virtual void set_IBQPoGrpIDPART_DSPOTROSTT(TFIBBCDField * IBQPoGrpIDPART_DSPOTROSTT);

   virtual TFIBWideStringField * get_IBQPoGrpNAMEGN(void);
   virtual void set_IBQPoGrpNAMEGN(TFIBWideStringField * IBQPoGrpNAMEGN);

   virtual TFIBWideStringField * get_IBQPoGrpNAMENOM(void);
   virtual void set_IBQPoGrpNAMENOM(TFIBWideStringField * IBQPoGrpNAMENOM);

   virtual TFIBWideStringField * get_IBQPoGrpNAMEED(void);
   virtual void set_IBQPoGrpNAMEED(TFIBWideStringField * IBQPoGrpNAMEED);

   virtual TFIBWideStringField * get_DocTNAMEGN(void);
   virtual void set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

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

   virtual TFIBWideStringField * get_DocAllNAME_USER(void);
   virtual void set_DocAllNAME_USER(TFIBWideStringField * DocAllNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_DocID_DSPOTROST(void);
   virtual void set_DocID_DSPOTROST(TFIBLargeIntField * DocID_DSPOTROST);

   virtual TFIBLargeIntField * get_DocIDDOC_DSPOTROST(void);
   virtual void set_DocIDDOC_DSPOTROST(TFIBLargeIntField * DocIDDOC_DSPOTROST);

   virtual TFIBWideStringField * get_DocGID_DSPOTROST(void);
   virtual void set_DocGID_DSPOTROST(TFIBWideStringField * DocGID_DSPOTROST);

   virtual TFIBWideStringField * get_DocDESCR_DSPOTROST(void);
   virtual void set_DocDESCR_DSPOTROST(TFIBWideStringField * DocDESCR_DSPOTROST);

   virtual TFIBLargeIntField * get_DocIDRTPRICE_DSPOTROST(void);
   virtual void set_DocIDRTPRICE_DSPOTROST(TFIBLargeIntField * DocIDRTPRICE_DSPOTROST);

   virtual TFIBBCDField * get_DocRSUM_DSPOTROST(void);
   virtual void set_DocRSUM_DSPOTROST(TFIBBCDField * DocRSUM_DSPOTROST);

   virtual TFIBLargeIntField * get_DocIDBASE_DSPOTROST(void);
   virtual void set_DocIDBASE_DSPOTROST(TFIBLargeIntField * DocIDBASE_DSPOTROST);

   virtual TFIBLargeIntField * get_DocTIDGN(void);
   virtual void set_DocTIDGN(TFIBLargeIntField * DocTIDGN);

   virtual TFIBIntegerField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBLargeIntField * get_DocTID_DSPOTROSTT(void);
   virtual void set_DocTID_DSPOTROSTT(TFIBLargeIntField * DocTID_DSPOTROSTT);

   virtual TFIBLargeIntField * get_DocTIDDOC_DSPOTROSTT(void);
   virtual void set_DocTIDDOC_DSPOTROSTT(TFIBLargeIntField * DocTIDDOC_DSPOTROSTT);

   virtual TFIBWideStringField * get_DocTGID_DSPOTROSTT(void);
   virtual void set_DocTGID_DSPOTROSTT(TFIBWideStringField * DocTGID_DSPOTROSTT);

   virtual TFIBLargeIntField * get_DocTIDNOM_DSPOTROSTT(void);
   virtual void set_DocTIDNOM_DSPOTROSTT(TFIBLargeIntField * DocTIDNOM_DSPOTROSTT);

   virtual TFIBLargeIntField * get_DocTIDED_DSPOTROSTT(void);
   virtual void set_DocTIDED_DSPOTROSTT(TFIBLargeIntField * DocTIDED_DSPOTROSTT);

   virtual TFIBLargeIntField * get_DocTIDPART_DSPOTROSTT(void);
   virtual void set_DocTIDPART_DSPOTROSTT(TFIBLargeIntField * DocTIDPART_DSPOTROSTT);

   virtual TFIBBCDField * get_DocTKOL_DSPOTROSTT(void);
   virtual void set_DocTKOL_DSPOTROSTT(TFIBBCDField * DocTKOL_DSPOTROSTT);

   virtual TFIBBCDField * get_DocTKF_DSPOTROSTT(void);
   virtual void set_DocTKF_DSPOTROSTT(TFIBBCDField * DocTKF_DSPOTROSTT);

   virtual TFIBBCDField * get_DocTPRICE_DSPOTROSTT(void);
   virtual void set_DocTPRICE_DSPOTROSTT(TFIBBCDField * DocTPRICE_DSPOTROSTT);

   virtual TFIBBCDField * get_DocTSUM_DSPOTROSTT(void);
   virtual void set_DocTSUM_DSPOTROSTT(TFIBBCDField * DocTSUM_DSPOTROSTT);

   virtual TFIBBCDField * get_DocTRPRICE_DSPOTROSTT(void);
   virtual void set_DocTRPRICE_DSPOTROSTT(TFIBBCDField * DocTRPRICE_DSPOTROSTT);

   virtual TFIBBCDField * get_DocTRSUM_DSPOTROSTT(void);
   virtual void set_DocTRSUM_DSPOTROSTT(TFIBBCDField * DocTRSUM_DSPOTROSTT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DSPOTROSTT(void);
   virtual void set_DocTIDBASE_DSPOTROSTT(TFIBLargeIntField * DocTIDBASE_DSPOTROSTT);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_NoEdit(void);
   virtual void set_NoEdit(bool NoEdit);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdGrpNom(void);
   virtual void set_IdGrpNom(__int64 IdGrpNom);

   virtual bool get_ChangeTable(void);
   virtual void set_ChangeTable(bool ChangeTable);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 id_doc);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocSpOtrOstImpl __uuidof(TDMDocSpOtrOstImpl)
#endif
