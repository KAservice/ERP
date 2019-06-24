#ifndef UDMDocRepKKMImplH
#define UDMDocRepKKMImplH
#include "IDMDocRepKKM.h"
#include "UDMDocRepKKM.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocRepKKMImpl)) TDMDocRepKKMImpl : public IDMDocRepKKM
{
public:
   TDMDocRepKKMImpl();
   ~TDMDocRepKKMImpl();
   TDMDocRepKKM * Object;
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

//IDMDocRepKKM
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

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

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

   virtual TFIBBCDField * get_DocOPLNAL_DREPKKM(void);
   virtual void set_DocOPLNAL_DREPKKM(TFIBBCDField * DocOPLNAL_DREPKKM);

   virtual TFIBBCDField * get_DocOPLPC_DREPKKM(void);
   virtual void set_DocOPLPC_DREPKKM(TFIBBCDField * DocOPLPC_DREPKKM);

   virtual TFIBIntegerField * get_DocNKL_DREPKKM(void);
   virtual void set_DocNKL_DREPKKM(TFIBIntegerField * DocNKL_DREPKKM);

   virtual TFIBBCDField * get_DocSK_DREPKKM(void);
   virtual void set_DocSK_DREPKKM(TFIBBCDField * DocSK_DREPKKM);

   virtual TFIBBCDField * get_DocNAD_DREPKKM(void);
   virtual void set_DocNAD_DREPKKM(TFIBBCDField * DocNAD_DREPKKM);

   virtual TFIBSmallIntField * get_DocDVREG_DREPKKM(void);
   virtual void set_DocDVREG_DREPKKM(TFIBSmallIntField * DocDVREG_DREPKKM);

   virtual TFIBBCDField * get_DocTPRICE_DREPKKMT(void);
   virtual void set_DocTPRICE_DREPKKMT(TFIBBCDField * DocTPRICE_DREPKKMT);

   virtual TFIBBCDField * get_DocTKOL_DREPKKMT(void);
   virtual void set_DocTKOL_DREPKKMT(TFIBBCDField * DocTKOL_DREPKKMT);

   virtual TFIBBCDField * get_DocTKF_DREPKKMT(void);
   virtual void set_DocTKF_DREPKKMT(TFIBBCDField * DocTKF_DREPKKMT);

   virtual TFIBBCDField * get_DocTSUM_DREPKKMT(void);
   virtual void set_DocTSUM_DREPKKMT(TFIBBCDField * DocTSUM_DREPKKMT);

   virtual TFIBBCDField * get_DocTSK_DREPKKMT(void);
   virtual void set_DocTSK_DREPKKMT(TFIBBCDField * DocTSK_DREPKKMT);

   virtual TFIBBCDField * get_DocTNAD_DREPKKMT(void);
   virtual void set_DocTNAD_DREPKKMT(TFIBBCDField * DocTNAD_DREPKKMT);

   virtual TFIBBCDField * get_DocTPRICEFULL_DREPKKMT(void);
   virtual void set_DocTPRICEFULL_DREPKKMT(TFIBBCDField * DocTPRICEFULL_DREPKKMT);

   virtual TFIBIntegerField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TpFIBDataSet * get_IBQ(void);
   virtual void set_IBQ(TpFIBDataSet * IBQ);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TpFIBDataSet * get_TableDoc(void);
   virtual void set_TableDoc(TpFIBDataSet * TableDoc);

   virtual TpFIBDataSet * get_PayDoc(void);
   virtual void set_PayDoc(TpFIBDataSet * PayDoc);

   virtual TFIBBCDField * get_TableDocSUMMA(void);
   virtual void set_TableDocSUMMA(TFIBBCDField * TableDocSUMMA);

   virtual TFIBFloatField * get_TableDocSUMKOL(void);
   virtual void set_TableDocSUMKOL(TFIBFloatField * TableDocSUMKOL);

   virtual TFIBBCDField * get_TableDocSUMSK(void);
   virtual void set_TableDocSUMSK(TFIBBCDField * TableDocSUMSK);

   virtual TFIBBCDField * get_TableDocSUMNAD(void);
   virtual void set_TableDocSUMNAD(TFIBBCDField * TableDocSUMNAD);

   virtual TFIBBCDField * get_PayDocOPLATANAL(void);
   virtual void set_PayDocOPLATANAL(TFIBBCDField * PayDocOPLATANAL);

   virtual TFIBBCDField * get_PayDocOPLATAPC(void);
   virtual void set_PayDocOPLATAPC(TFIBBCDField * PayDocOPLATAPC);

   virtual TFIBLargeIntField * get_TableDocIDNOM(void);
   virtual void set_TableDocIDNOM(TFIBLargeIntField * TableDocIDNOM);

   virtual TFIBWideStringField * get_TableDocNAMENOM(void);
   virtual void set_TableDocNAMENOM(TFIBWideStringField * TableDocNAMENOM);

   virtual TFIBLargeIntField * get_TableDocIDED(void);
   virtual void set_TableDocIDED(TFIBLargeIntField * TableDocIDED);

   virtual TFIBWideStringField * get_TableDocNAMEED(void);
   virtual void set_TableDocNAMEED(TFIBWideStringField * TableDocNAMEED);

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

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SDOG(void);
   virtual void set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBLargeIntField * get_DocID_DREPKKM(void);
   virtual void set_DocID_DREPKKM(TFIBLargeIntField * DocID_DREPKKM);

   virtual TFIBWideStringField * get_DocGID_DREPKKM(void);
   virtual void set_DocGID_DREPKKM(TFIBWideStringField * DocGID_DREPKKM);

   virtual TFIBLargeIntField * get_DocIDDOC_DREPKKM(void);
   virtual void set_DocIDDOC_DREPKKM(TFIBLargeIntField * DocIDDOC_DREPKKM);

   virtual TFIBLargeIntField * get_DocIDKKM_DREPKKM(void);
   virtual void set_DocIDKKM_DREPKKM(TFIBLargeIntField * DocIDKKM_DREPKKM);

   virtual TFIBWideStringField * get_DocPRIM_DREPKKM(void);
   virtual void set_DocPRIM_DREPKKM(TFIBWideStringField * DocPRIM_DREPKKM);

   virtual TFIBLargeIntField * get_DocIDTPRICE_DREPKKM(void);
   virtual void set_DocIDTPRICE_DREPKKM(TFIBLargeIntField * DocIDTPRICE_DREPKKM);

   virtual TFIBLargeIntField * get_DocIDBASE_DREPKKM(void);
   virtual void set_DocIDBASE_DREPKKM(TFIBLargeIntField * DocIDBASE_DREPKKM);

   virtual TFIBLargeIntField * get_DocIDBSCHET_DREPKKM(void);
   virtual void set_DocIDBSCHET_DREPKKM(TFIBLargeIntField * DocIDBSCHET_DREPKKM);

   virtual TFIBWideStringField * get_DocNAMEKKM(void);
   virtual void set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM);

   virtual TFIBWideStringField * get_DocNAME_TPRICE(void);
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE);

   virtual TFIBWideStringField * get_DocNAMEBSCHET(void);
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET);

   virtual TFIBLargeIntField * get_DocTID_DREPKKMT(void);
   virtual void set_DocTID_DREPKKMT(TFIBLargeIntField * DocTID_DREPKKMT);

   virtual TFIBWideStringField * get_DocTGID_DREPKKMT(void);
   virtual void set_DocTGID_DREPKKMT(TFIBWideStringField * DocTGID_DREPKKMT);

   virtual TFIBLargeIntField * get_DocTIDDOC_DREPKKMT(void);
   virtual void set_DocTIDDOC_DREPKKMT(TFIBLargeIntField * DocTIDDOC_DREPKKMT);

   virtual TFIBLargeIntField * get_DocTIDNOM_DREPKKMT(void);
   virtual void set_DocTIDNOM_DREPKKMT(TFIBLargeIntField * DocTIDNOM_DREPKKMT);

   virtual TFIBLargeIntField * get_DocTIDED_DREPKKMT(void);
   virtual void set_DocTIDED_DREPKKMT(TFIBLargeIntField * DocTIDED_DREPKKMT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DREPKKMT(void);
   virtual void set_DocTIDBASE_DREPKKMT(TFIBLargeIntField * DocTIDBASE_DREPKKMT);

   virtual TFIBIntegerField * get_DocTNDS_DREPKKMT(void);
   virtual void set_DocTNDS_DREPKKMT(TFIBIntegerField * DocTNDS_DREPKKMT);

   virtual TFIBBCDField * get_DocTSUMNDS_DREPKKMT(void);
   virtual void set_DocTSUMNDS_DREPKKMT(TFIBBCDField * DocTSUMNDS_DREPKKMT);

   virtual TFIBWideStringField * get_DocTKRNAMENOM(void);
   virtual void set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual bool get_NoEdit(void);
   virtual void set_NoEdit(bool NoEdit);

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
   virtual bool DeleteDoc(__int64 id);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual void CloseDoc(void);
   virtual double Summa(void);
   virtual bool CreateReportKKM(   __int64 id_sklad,__int64 id_kkm,__int64 id_firm,int number_kl ,TDateTime NachInterval,TDateTime ConInterval);
   virtual void GetSumOplata(      __int64 id_sklad,__int64 id_kkm,__int64 id_firm,int number_kl ,TDateTime NachInterval,TDateTime ConInterval );
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocRepKKMImpl __uuidof(TDMDocRepKKMImpl)
#endif
