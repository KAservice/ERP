#ifndef UREM_DMDocOtprPostImplH
#define UREM_DMDocOtprPostImplH
#include "IREM_DMDocOtprPost.h"
#include "UREM_DMDocOtprPost.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocOtprPostImpl)) TREM_DMDocOtprPostImpl : public IREM_DMDocOtprPost
{
public:
   TREM_DMDocOtprPostImpl();
   ~TREM_DMDocOtprPostImpl();
   TREM_DMDocOtprPost * Object;
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

//IREM_DMDocOtprPost
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

   virtual TFIBLargeIntField * get_DocAllID_REM_GALLDOC(void);
   virtual void set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDBASE_REM_GALLDOC(void);
   virtual void set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDFIRM_REM_GALLDOC(void);
   virtual void set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDSKLAD_REM_GALLDOC(void);
   virtual void set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDKLIENT_REM_GALLDOC(void);
   virtual void set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDUSER_REM_GALLDOC(void);
   virtual void set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC);

   virtual TFIBDateTimeField * get_DocAllPOS_REM_GALLDOC(void);
   virtual void set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC);

   virtual TFIBIntegerField * get_DocAllNUM_REM_GALLDOC(void);
   virtual void set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC);

   virtual TFIBSmallIntField * get_DocAllPR_REM_GALLDOC(void);
   virtual void set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocAllTDOC_REM_GALLDOC(void);
   virtual void set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOCOSN_REM_GALLDOC(void);
   virtual void set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC);

   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC_REM_GALLDOC(void);
   virtual void set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDEXTDOC_REM_GALLDOC(void);
   virtual void set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC);

   virtual TFIBBCDField * get_DocAllSUM_REM_GALLDOC(void);
   virtual void set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDPROJECT_REM_GALLDOC(void);
   virtual void set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_REM_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC);

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

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocID_REM_DOTPRPOST(void);
   virtual void set_DocID_REM_DOTPRPOST(TFIBLargeIntField * DocID_REM_DOTPRPOST);

   virtual TFIBLargeIntField * get_DocIDBASE_REM_DOTPRPOST(void);
   virtual void set_DocIDBASE_REM_DOTPRPOST(TFIBLargeIntField * DocIDBASE_REM_DOTPRPOST);

   virtual TFIBLargeIntField * get_DocIDDOC_REM_DOTPRPOST(void);
   virtual void set_DocIDDOC_REM_DOTPRPOST(TFIBLargeIntField * DocIDDOC_REM_DOTPRPOST);

   virtual TFIBLargeIntField * get_DocIDTPRICE_REM_DOTPRPOST(void);
   virtual void set_DocIDTPRICE_REM_DOTPRPOST(TFIBLargeIntField * DocIDTPRICE_REM_DOTPRPOST);

   virtual TFIBLargeIntField * get_DocIDBRAND_REM_DOTPRPOST(void);
   virtual void set_DocIDBRAND_REM_DOTPRPOST(TFIBLargeIntField * DocIDBRAND_REM_DOTPRPOST);

   virtual TFIBLargeIntField * get_DocIDPRODUCER_REM_DOTPRPOST(void);
   virtual void set_DocIDPRODUCER_REM_DOTPRPOST(TFIBLargeIntField * DocIDPRODUCER_REM_DOTPRPOST);

   virtual TFIBWideStringField * get_DocTK_REM_DOTPRPOST(void);
   virtual void set_DocTK_REM_DOTPRPOST(TFIBWideStringField * DocTK_REM_DOTPRPOST);

   virtual TFIBWideStringField * get_DocNUMDOCTK_REM_DOTPRPOST(void);
   virtual void set_DocNUMDOCTK_REM_DOTPRPOST(TFIBWideStringField * DocNUMDOCTK_REM_DOTPRPOST);

   virtual TFIBDateField * get_DocPLANDOSTAVKI_REM_DOTPRPOST(void);
   virtual void set_DocPLANDOSTAVKI_REM_DOTPRPOST(TFIBDateField * DocPLANDOSTAVKI_REM_DOTPRPOST);

   virtual TFIBWideStringField * get_DocNAME_SBRAND(void);
   virtual void set_DocNAME_SBRAND(TFIBWideStringField * DocNAME_SBRAND);

   virtual TFIBWideStringField * get_DocNAME_SPRODUCER(void);
   virtual void set_DocNAME_SPRODUCER(TFIBWideStringField * DocNAME_SPRODUCER);

   virtual TFIBLargeIntField * get_DocTID_REM_DOTPRPOSTT(void);
   virtual void set_DocTID_REM_DOTPRPOSTT(TFIBLargeIntField * DocTID_REM_DOTPRPOSTT);

   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DOTPRPOSTT(void);
   virtual void set_DocTIDBASE_REM_DOTPRPOSTT(TFIBLargeIntField * DocTIDBASE_REM_DOTPRPOSTT);

   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DOTPRPOSTT(void);
   virtual void set_DocTIDDOC_REM_DOTPRPOSTT(TFIBLargeIntField * DocTIDDOC_REM_DOTPRPOSTT);

   virtual TFIBLargeIntField * get_DocTIDNOM_REM_DOTPRPOSTT(void);
   virtual void set_DocTIDNOM_REM_DOTPRPOSTT(TFIBLargeIntField * DocTIDNOM_REM_DOTPRPOSTT);

   virtual TFIBLargeIntField * get_DocTIDED_REM_DOTPRPOSTT(void);
   virtual void set_DocTIDED_REM_DOTPRPOSTT(TFIBLargeIntField * DocTIDED_REM_DOTPRPOSTT);

   virtual TFIBBCDField * get_DocTKOL_REM_DOTPRPOSTT(void);
   virtual void set_DocTKOL_REM_DOTPRPOSTT(TFIBBCDField * DocTKOL_REM_DOTPRPOSTT);

   virtual TFIBBCDField * get_DocTKF_REM_DOTPRPOSTT(void);
   virtual void set_DocTKF_REM_DOTPRPOSTT(TFIBBCDField * DocTKF_REM_DOTPRPOSTT);

   virtual TFIBBCDField * get_DocTPRICE_REM_DOTPRPOSTT(void);
   virtual void set_DocTPRICE_REM_DOTPRPOSTT(TFIBBCDField * DocTPRICE_REM_DOTPRPOSTT);

   virtual TFIBBCDField * get_DocTSUM_REM_DOTPRPOSTT(void);
   virtual void set_DocTSUM_REM_DOTPRPOSTT(TFIBBCDField * DocTSUM_REM_DOTPRPOSTT);

   virtual TFIBLargeIntField * get_DocTIDCQT_REM_DOTPRPOSTT(void);
   virtual void set_DocTIDCQT_REM_DOTPRPOSTT(TFIBLargeIntField * DocTIDCQT_REM_DOTPRPOSTT);

   virtual TFIBLargeIntField * get_DocTIDPRNOM_REM_DOTPRPOSTT(void);
   virtual void set_DocTIDPRNOM_REM_DOTPRPOSTT(TFIBLargeIntField * DocTIDPRNOM_REM_DOTPRPOSTT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBSmallIntField * get_DocTFL_ADD_IN_SOBORUD_SNOM(void);
   virtual void set_DocTFL_ADD_IN_SOBORUD_SNOM(TFIBSmallIntField * DocTFL_ADD_IN_SOBORUD_SNOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual TFIBLargeIntField * get_DocTID_REM_CQUERY(void);
   virtual void set_DocTID_REM_CQUERY(TFIBLargeIntField * DocTID_REM_CQUERY);

   virtual TFIBWideStringField * get_DocTNAME_REM_CQUERY(void);
   virtual void set_DocTNAME_REM_CQUERY(TFIBWideStringField * DocTNAME_REM_CQUERY);

   virtual TFIBIntegerField * get_DocTNUM_REM_CQUERY(void);
   virtual void set_DocTNUM_REM_CQUERY(TFIBIntegerField * DocTNUM_REM_CQUERY);

   virtual TFIBDateTimeField * get_DocTPOS_REM_CQUERY(void);
   virtual void set_DocTPOS_REM_CQUERY(TFIBDateTimeField * DocTPOS_REM_CQUERY);

   virtual TFIBWideStringField * get_DocTKLIENT_NAME_REM_CQUERY(void);
   virtual void set_DocTKLIENT_NAME_REM_CQUERY(TFIBWideStringField * DocTKLIENT_NAME_REM_CQUERY);

   virtual TFIBWideStringField * get_DocTNAME_MODEL_REM_CQUERY(void);
   virtual void set_DocTNAME_MODEL_REM_CQUERY(TFIBWideStringField * DocTNAME_MODEL_REM_CQUERY);

   virtual TFIBWideStringField * get_DocTNUM_STR_ZAK_POST_REM_CQUERY(void);
   virtual void set_DocTNUM_STR_ZAK_POST_REM_CQUERY(TFIBWideStringField * DocTNUM_STR_ZAK_POST_REM_CQUERY);

   virtual TFIBLargeIntField * get_DocTID_REM_Z(void);
   virtual void set_DocTID_REM_Z(TFIBLargeIntField * DocTID_REM_Z);

   virtual TFIBWideStringField * get_DocTNAME_REM_Z(void);
   virtual void set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z);

   virtual TFIBWideStringField * get_DocTPREFIKS_NUM_REM_Z(void);
   virtual void set_DocTPREFIKS_NUM_REM_Z(TFIBWideStringField * DocTPREFIKS_NUM_REM_Z);

   virtual TFIBIntegerField * get_DocTNUM_REM_Z(void);
   virtual void set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z);

   virtual TFIBDateTimeField * get_DocTPOS_REM_Z(void);
   virtual void set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z);

   virtual TFIBWideStringField * get_DocTMODEL_REM_Z(void);
   virtual void set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z);

   virtual TFIBWideStringField * get_DocTSERNUM_REM_Z(void);
   virtual void set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z);

   virtual TFIBWideStringField * get_DocTSERNUM2_REM_Z(void);
   virtual void set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z);

   virtual TFIBWideStringField * get_DocTSTR_CODE_VIGR_REM_Z_1(void);
   virtual void set_DocTSTR_CODE_VIGR_REM_Z_1(TFIBWideStringField * DocTSTR_CODE_VIGR_REM_Z_1);

   virtual TFIBWideStringField * get_DocTNAME_REM_SPRMODEL(void);
   virtual void set_DocTNAME_REM_SPRMODEL(TFIBWideStringField * DocTNAME_REM_SPRMODEL);

   virtual TFIBWideStringField * get_DocTART_SPRNOM(void);
   virtual void set_DocTART_SPRNOM(TFIBWideStringField * DocTART_SPRNOM);

   virtual TFIBWideStringField * get_DocTNAME_SPRNOM(void);
   virtual void set_DocTNAME_SPRNOM(TFIBWideStringField * DocTNAME_SPRNOM);

   virtual TFIBSmallIntField * get_DocTFL_DOSTUPNO_SPRNOM(void);
   virtual void set_DocTFL_DOSTUPNO_SPRNOM(TFIBSmallIntField * DocTFL_DOSTUPNO_SPRNOM);

   virtual TFIBWideStringField * get_DocTMODEL_STR_SPRNOM(void);
   virtual void set_DocTMODEL_STR_SPRNOM(TFIBWideStringField * DocTMODEL_STR_SPRNOM);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBWideStringField * get_DocTART_REM_CQUERYT(void);
   virtual void set_DocTART_REM_CQUERYT(TFIBWideStringField * DocTART_REM_CQUERYT);

   virtual TFIBWideStringField * get_DocTNAMENOM_REM_CQUERYT(void);
   virtual void set_DocTNAMENOM_REM_CQUERYT(TFIBWideStringField * DocTNAMENOM_REM_CQUERYT);

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

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual bool NewDoc(void);
   virtual bool OpenDoc(__int64 id);
   virtual bool SaveDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual bool TableAppend(void);
   virtual bool TableDelete(void);
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TREM_DMDocOtprPostImpl __uuidof(TREM_DMDocOtprPostImpl)
#endif
