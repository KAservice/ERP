#ifndef UREM_DMCustQueryImplH
#define UREM_DMCustQueryImplH
#include "IREM_DMCustQuery.h"
#include "UREM_DMCustQuery.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMCustQueryImpl)) TREM_DMCustQueryImpl : public IREM_DMCustQuery
{
public:
   TREM_DMCustQueryImpl();
   ~TREM_DMCustQueryImpl();
   TREM_DMCustQuery * Object;
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

//IREM_DMCustQuery
   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TFIBLargeIntField * get_DocID_REM_CQUERY(void);
   virtual void set_DocID_REM_CQUERY(TFIBLargeIntField * DocID_REM_CQUERY);

   virtual TFIBWideStringField * get_DocGID_REM_CQUERY(void);
   virtual void set_DocGID_REM_CQUERY(TFIBWideStringField * DocGID_REM_CQUERY);

   virtual TFIBLargeIntField * get_DocIDBASE_REM_CQUERY(void);
   virtual void set_DocIDBASE_REM_CQUERY(TFIBLargeIntField * DocIDBASE_REM_CQUERY);

   virtual TFIBDateTimeField * get_DocPOS_REM_CQUERY(void);
   virtual void set_DocPOS_REM_CQUERY(TFIBDateTimeField * DocPOS_REM_CQUERY);

   virtual TFIBIntegerField * get_DocNUM_REM_CQUERY(void);
   virtual void set_DocNUM_REM_CQUERY(TFIBIntegerField * DocNUM_REM_CQUERY);

   virtual TFIBLargeIntField * get_DocIDFIRM_REM_CQUERY(void);
   virtual void set_DocIDFIRM_REM_CQUERY(TFIBLargeIntField * DocIDFIRM_REM_CQUERY);

   virtual TFIBLargeIntField * get_DocIDSKLAD_REM_CQUERY(void);
   virtual void set_DocIDSKLAD_REM_CQUERY(TFIBLargeIntField * DocIDSKLAD_REM_CQUERY);

   virtual TFIBLargeIntField * get_DocIDUSER_REM_CQUERY(void);
   virtual void set_DocIDUSER_REM_CQUERY(TFIBLargeIntField * DocIDUSER_REM_CQUERY);

   virtual TFIBLargeIntField * get_DocIDKLIENT_REM_CQUERY(void);
   virtual void set_DocIDKLIENT_REM_CQUERY(TFIBLargeIntField * DocIDKLIENT_REM_CQUERY);

   virtual TFIBWideStringField * get_DocKLIENT_NAME_REM_CQUERY(void);
   virtual void set_DocKLIENT_NAME_REM_CQUERY(TFIBWideStringField * DocKLIENT_NAME_REM_CQUERY);

   virtual TFIBWideStringField * get_DocKLIENT_ADR_REM_CQUERY(void);
   virtual void set_DocKLIENT_ADR_REM_CQUERY(TFIBWideStringField * DocKLIENT_ADR_REM_CQUERY);

   virtual TFIBWideStringField * get_DocKLIENT_PHONE_REM_CQUERY(void);
   virtual void set_DocKLIENT_PHONE_REM_CQUERY(TFIBWideStringField * DocKLIENT_PHONE_REM_CQUERY);

   virtual TFIBWideStringField * get_DocCOMMENTS_REM_CQUERY(void);
   virtual void set_DocCOMMENTS_REM_CQUERY(TFIBWideStringField * DocCOMMENTS_REM_CQUERY);

   virtual TFIBSmallIntField * get_DocRUN_REM_CQUERY(void);
   virtual void set_DocRUN_REM_CQUERY(TFIBSmallIntField * DocRUN_REM_CQUERY);

   virtual TFIBBCDField * get_DocDO_SUM_REM_CQUERY(void);
   virtual void set_DocDO_SUM_REM_CQUERY(TFIBBCDField * DocDO_SUM_REM_CQUERY);

   virtual TFIBBCDField * get_DocTEC_SUM_REM_CQUERY(void);
   virtual void set_DocTEC_SUM_REM_CQUERY(TFIBBCDField * DocTEC_SUM_REM_CQUERY);

   virtual TFIBBCDField * get_DocSOGL_SUM_REM_CQUERY(void);
   virtual void set_DocSOGL_SUM_REM_CQUERY(TFIBBCDField * DocSOGL_SUM_REM_CQUERY);

   virtual TFIBLargeIntField * get_DocIDZ_REM_CQUERY(void);
   virtual void set_DocIDZ_REM_CQUERY(TFIBLargeIntField * DocIDZ_REM_CQUERY);

   virtual TFIBLargeIntField * get_DocIDMODEL_REM_CQUERY(void);
   virtual void set_DocIDMODEL_REM_CQUERY(TFIBLargeIntField * DocIDMODEL_REM_CQUERY);

   virtual TFIBWideStringField * get_DocNAME_MODEL_REM_CQUERY(void);
   virtual void set_DocNAME_MODEL_REM_CQUERY(TFIBWideStringField * DocNAME_MODEL_REM_CQUERY);

   virtual TFIBWideStringField * get_DocNAMEFIRM(void);
   virtual void set_DocNAMEFIRM(TFIBWideStringField * DocNAMEFIRM);

   virtual TFIBWideStringField * get_DocNAME_SINFBASE_OBMEN(void);
   virtual void set_DocNAME_SINFBASE_OBMEN(TFIBWideStringField * DocNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocNAME_REM_SMODEL(void);
   virtual void set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL);

   virtual TFIBWideStringField * get_DocNAMESKLAD(void);
   virtual void set_DocNAMESKLAD(TFIBWideStringField * DocNAMESKLAD);

   virtual TFIBWideStringField * get_DocNAMEKLIENT(void);
   virtual void set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT);

   virtual TFIBWideStringField * get_DocNAME_REM_Z(void);
   virtual void set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z);

   virtual TFIBIntegerField * get_DocNUM_REM_Z(void);
   virtual void set_DocNUM_REM_Z(TFIBIntegerField * DocNUM_REM_Z);

   virtual TFIBDateTimeField * get_DocPOS_REM_Z(void);
   virtual void set_DocPOS_REM_Z(TFIBDateTimeField * DocPOS_REM_Z);

   virtual TFIBWideStringField * get_DocKLIENT_NAME_REM_Z(void);
   virtual void set_DocKLIENT_NAME_REM_Z(TFIBWideStringField * DocKLIENT_NAME_REM_Z);

   virtual TFIBWideStringField * get_DocMODEL_REM_Z(void);
   virtual void set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z);

   virtual TFIBWideStringField * get_DocNAME_USER(void);
   virtual void set_DocNAME_USER(TFIBWideStringField * DocNAME_USER);

   virtual TFIBLargeIntField * get_DocTID_REM_CQUERYT(void);
   virtual void set_DocTID_REM_CQUERYT(TFIBLargeIntField * DocTID_REM_CQUERYT);

   virtual TFIBWideStringField * get_DocTGID_REM_CQUERYT(void);
   virtual void set_DocTGID_REM_CQUERYT(TFIBWideStringField * DocTGID_REM_CQUERYT);

   virtual TFIBLargeIntField * get_DocTIDBASE_REM_CQUERYT(void);
   virtual void set_DocTIDBASE_REM_CQUERYT(TFIBLargeIntField * DocTIDBASE_REM_CQUERYT);

   virtual TFIBLargeIntField * get_DocTIDCQ_REM_CQUERYT(void);
   virtual void set_DocTIDCQ_REM_CQUERYT(TFIBLargeIntField * DocTIDCQ_REM_CQUERYT);

   virtual TFIBLargeIntField * get_DocTIDNOM_REM_CQUERYT(void);
   virtual void set_DocTIDNOM_REM_CQUERYT(TFIBLargeIntField * DocTIDNOM_REM_CQUERYT);

   virtual TFIBLargeIntField * get_DocTIDED_REM_CQUERYT(void);
   virtual void set_DocTIDED_REM_CQUERYT(TFIBLargeIntField * DocTIDED_REM_CQUERYT);

   virtual TFIBLargeIntField * get_DocTIDSOST_REM_CQUERYT(void);
   virtual void set_DocTIDSOST_REM_CQUERYT(TFIBLargeIntField * DocTIDSOST_REM_CQUERYT);

   virtual TFIBWideStringField * get_DocTNAMENOM_REM_CQUERYT(void);
   virtual void set_DocTNAMENOM_REM_CQUERYT(TFIBWideStringField * DocTNAMENOM_REM_CQUERYT);

   virtual TFIBBCDField * get_DocTKOL_REM_CQUERYT(void);
   virtual void set_DocTKOL_REM_CQUERYT(TFIBBCDField * DocTKOL_REM_CQUERYT);

   virtual TFIBBCDField * get_DocTKF_REM_CQUERYT(void);
   virtual void set_DocTKF_REM_CQUERYT(TFIBBCDField * DocTKF_REM_CQUERYT);

   virtual TFIBBCDField * get_DocTPRICE_REM_CQUERYT(void);
   virtual void set_DocTPRICE_REM_CQUERYT(TFIBBCDField * DocTPRICE_REM_CQUERYT);

   virtual TFIBBCDField * get_DocTSUM_REM_CQUERYT(void);
   virtual void set_DocTSUM_REM_CQUERYT(TFIBBCDField * DocTSUM_REM_CQUERYT);

   virtual TFIBBCDField * get_DocTPRICE_DO_REM_CQUERYT(void);
   virtual void set_DocTPRICE_DO_REM_CQUERYT(TFIBBCDField * DocTPRICE_DO_REM_CQUERYT);

   virtual TFIBBCDField * get_DocTPRICE_TEC_REM_CQUERYT(void);
   virtual void set_DocTPRICE_TEC_REM_CQUERYT(TFIBBCDField * DocTPRICE_TEC_REM_CQUERYT);

   virtual TFIBBCDField * get_DocTPRICE_SOGL_REM_CQUERYT(void);
   virtual void set_DocTPRICE_SOGL_REM_CQUERYT(TFIBBCDField * DocTPRICE_SOGL_REM_CQUERYT);

   virtual TFIBIntegerField * get_DocTSROK_POST_REM_CQUERYT(void);
   virtual void set_DocTSROK_POST_REM_CQUERYT(TFIBIntegerField * DocTSROK_POST_REM_CQUERYT);

   virtual TFIBDateTimeField * get_DocTPOS_POST_REM_CQUERYT(void);
   virtual void set_DocTPOS_POST_REM_CQUERYT(TFIBDateTimeField * DocTPOS_POST_REM_CQUERYT);

   virtual TFIBSmallIntField * get_DocTRUN_REM_CQUERYT(void);
   virtual void set_DocTRUN_REM_CQUERYT(TFIBSmallIntField * DocTRUN_REM_CQUERYT);

   virtual TFIBWideStringField * get_DocTCOMMENTS_REM_CQUERYT(void);
   virtual void set_DocTCOMMENTS_REM_CQUERYT(TFIBWideStringField * DocTCOMMENTS_REM_CQUERYT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocTNAME_REM_SSOST_CQUERY(void);
   virtual void set_DocTNAME_REM_SSOST_CQUERY(TFIBWideStringField * DocTNAME_REM_SSOST_CQUERY);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void);
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER);

   virtual TFIBSmallIntField * get_DocTACT_REM_CQUERYT(void);
   virtual void set_DocTACT_REM_CQUERYT(TFIBSmallIntField * DocTACT_REM_CQUERYT);

   virtual TFIBLargeIntField * get_DocTIDPRNOM_REM_CQUERYT(void);
   virtual void set_DocTIDPRNOM_REM_CQUERYT(TFIBLargeIntField * DocTIDPRNOM_REM_CQUERYT);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual TFIBWideStringField * get_DocTART_SPRNOM(void);
   virtual void set_DocTART_SPRNOM(TFIBWideStringField * DocTART_SPRNOM);

   virtual TFIBIntegerField * get_DocTCODE_SPRNOM(void);
   virtual void set_DocTCODE_SPRNOM(TFIBIntegerField * DocTCODE_SPRNOM);

   virtual TFIBWideStringField * get_DocTNAME_SPRNOM(void);
   virtual void set_DocTNAME_SPRNOM(TFIBWideStringField * DocTNAME_SPRNOM);

   virtual TFIBLargeIntField * get_DocIDBRAND_REM_CQUERY(void);
   virtual void set_DocIDBRAND_REM_CQUERY(TFIBLargeIntField * DocIDBRAND_REM_CQUERY);

   virtual TFIBLargeIntField * get_DocIDPRODUCER_REM_CQUERY(void);
   virtual void set_DocIDPRODUCER_REM_CQUERY(TFIBLargeIntField * DocIDPRODUCER_REM_CQUERY);

   virtual TFIBSmallIntField * get_DocFL_KLIENT_UVEDOML_REM_CQUERY(void);
   virtual void set_DocFL_KLIENT_UVEDOML_REM_CQUERY(TFIBSmallIntField * DocFL_KLIENT_UVEDOML_REM_CQUERY);

   virtual TFIBWideStringField * get_DocNAME_SBRAND(void);
   virtual void set_DocNAME_SBRAND(TFIBWideStringField * DocNAME_SBRAND);

   virtual TFIBWideStringField * get_DocNAME_SPRODUCER(void);
   virtual void set_DocNAME_SPRODUCER(TFIBWideStringField * DocNAME_SPRODUCER);

   virtual TFIBIntegerField * get_DocNUM_ZAKAZA_REM_CQUERY(void);
   virtual void set_DocNUM_ZAKAZA_REM_CQUERY(TFIBIntegerField * DocNUM_ZAKAZA_REM_CQUERY);

   virtual TFIBDateField * get_DocDATE_ZAKAZA_REM_CQUERY(void);
   virtual void set_DocDATE_ZAKAZA_REM_CQUERY(TFIBDateField * DocDATE_ZAKAZA_REM_CQUERY);

   virtual TFIBLargeIntField * get_DocIDHW_REM_CQUERY(void);
   virtual void set_DocIDHW_REM_CQUERY(TFIBLargeIntField * DocIDHW_REM_CQUERY);

   virtual TFIBIntegerField * get_DocTYPE_REM_CQUERY(void);
   virtual void set_DocTYPE_REM_CQUERY(TFIBIntegerField * DocTYPE_REM_CQUERY);

   virtual TFIBWideStringField * get_DocNAME_REM_SHARDWARE(void);
   virtual void set_DocNAME_REM_SHARDWARE(TFIBWideStringField * DocNAME_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocSERNUM_REM_SHARDWARE(void);
   virtual void set_DocSERNUM_REM_SHARDWARE(TFIBWideStringField * DocSERNUM_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocSERNUM2_REM_SHARDWARE(void);
   virtual void set_DocSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocSERNUM2_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_DocIDPRMODEL_REM_CQUERY(void);
   virtual void set_DocIDPRMODEL_REM_CQUERY(TFIBLargeIntField * DocIDPRMODEL_REM_CQUERY);

   virtual TFIBDateTimeField * get_DocPOSTUPILO_REM_CQUERY(void);
   virtual void set_DocPOSTUPILO_REM_CQUERY(TFIBDateTimeField * DocPOSTUPILO_REM_CQUERY);

   virtual TFIBWideStringField * get_DocCODE_REM_SMODEL(void);
   virtual void set_DocCODE_REM_SMODEL(TFIBWideStringField * DocCODE_REM_SMODEL);

   virtual TFIBWideStringField * get_DocNAME_REM_SPRMODEL(void);
   virtual void set_DocNAME_REM_SPRMODEL(TFIBWideStringField * DocNAME_REM_SPRMODEL);

   virtual TFIBWideStringField * get_DocCODE_REM_SPRMODEL(void);
   virtual void set_DocCODE_REM_SPRMODEL(TFIBWideStringField * DocCODE_REM_SPRMODEL);

   virtual TFIBDateField * get_DocPLAN_POSTAVKI_REM_CQUERY(void);
   virtual void set_DocPLAN_POSTAVKI_REM_CQUERY(TFIBDateField * DocPLAN_POSTAVKI_REM_CQUERY);

   virtual TFIBDateTimeField * get_DocZAKAZANO_REM_CQUERY(void);
   virtual void set_DocZAKAZANO_REM_CQUERY(TFIBDateTimeField * DocZAKAZANO_REM_CQUERY);

   virtual TFIBDateTimeField * get_DocOTPRAVLENO_REM_CQUERY(void);
   virtual void set_DocOTPRAVLENO_REM_CQUERY(TFIBDateTimeField * DocOTPRAVLENO_REM_CQUERY);

   virtual TFIBWideStringField * get_DocTART_REM_CQUERYT(void);
   virtual void set_DocTART_REM_CQUERYT(TFIBWideStringField * DocTART_REM_CQUERYT);

   virtual TFIBWideStringField * get_DocNAME_REM_CQUERY(void);
   virtual void set_DocNAME_REM_CQUERY(TFIBWideStringField * DocNAME_REM_CQUERY);

   virtual TFIBWideStringField * get_DocNUM_STR_ZAK_POST_REM_CQUERY(void);
   virtual void set_DocNUM_STR_ZAK_POST_REM_CQUERY(TFIBWideStringField * DocNUM_STR_ZAK_POST_REM_CQUERY);

   virtual TFIBSmallIntField * get_DocTFL_ADD_IN_SOBORUD_SNOM(void);
   virtual void set_DocTFL_ADD_IN_SOBORUD_SNOM(TFIBSmallIntField * DocTFL_ADD_IN_SOBORUD_SNOM);

   virtual TFIBDateTimeField * get_DocPOS_ZAK_POST_REM_CQUERY(void);
   virtual void set_DocPOS_ZAK_POST_REM_CQUERY(TFIBDateTimeField * DocPOS_ZAK_POST_REM_CQUERY);

   virtual TFIBWideStringField * get_DocNUM_STR_ZAK_SPROV_REM_CQUERY(void);
   virtual void set_DocNUM_STR_ZAK_SPROV_REM_CQUERY(TFIBWideStringField * DocNUM_STR_ZAK_SPROV_REM_CQUERY);

   virtual TFIBDateTimeField * get_DocPOS_ZAK_SPROV_REM_CQUERY(void);
   virtual void set_DocPOS_ZAK_SPROV_REM_CQUERY(TFIBDateTimeField * DocPOS_ZAK_SPROV_REM_CQUERY);

   virtual TFIBWideStringField * get_DocNUM_DOC_OTPR_POST_REM_CQUERY(void);
   virtual void set_DocNUM_DOC_OTPR_POST_REM_CQUERY(TFIBWideStringField * DocNUM_DOC_OTPR_POST_REM_CQUERY);

   virtual TFIBDateTimeField * get_DocPOS_DOC_OTPR_POST_REM_CQUERY(void);
   virtual void set_DocPOS_DOC_OTPR_POST_REM_CQUERY(TFIBDateTimeField * DocPOS_DOC_OTPR_POST_REM_CQUERY);

   virtual TFIBWideStringField * get_DocNUMDOCTK_REM_CQUERY(void);
   virtual void set_DocNUMDOCTK_REM_CQUERY(TFIBWideStringField * DocNUMDOCTK_REM_CQUERY);

   virtual TFIBWideStringField * get_DocTK_REM_CQUERY(void);
   virtual void set_DocTK_REM_CQUERY(TFIBWideStringField * DocTK_REM_CQUERY);

   virtual TFIBLargeIntField * get_DocIDPRODAVEC_REM_CQUERY(void);
   virtual void set_DocIDPRODAVEC_REM_CQUERY(TFIBLargeIntField * DocIDPRODAVEC_REM_CQUERY);

   virtual TFIBWideStringField * get_DocPRODAVEC_NAME(void);
   virtual void set_DocPRODAVEC_NAME(TFIBWideStringField * DocPRODAVEC_NAME);

   virtual TFIBWideStringField * get_DocTSER_NUM_REM_CQUERYT(void);
   virtual void set_DocTSER_NUM_REM_CQUERYT(TFIBWideStringField * DocTSER_NUM_REM_CQUERYT);

   virtual TFIBWideStringField * get_DocTUCH_SER_NUM_REM_CQUERYT(void);
   virtual void set_DocTUCH_SER_NUM_REM_CQUERYT(TFIBWideStringField * DocTUCH_SER_NUM_REM_CQUERYT);

   virtual TFIBWideStringField * get_DocTREF_REM_CQUERYT(void);
   virtual void set_DocTREF_REM_CQUERYT(TFIBWideStringField * DocTREF_REM_CQUERYT);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdCQ(void);
   virtual void set_IdCQ(__int64 IdCQ);

   virtual bool get_flChangeData(void);
   virtual void set_flChangeData(bool flChangeData);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 id);
   virtual bool SaveDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual void CloseDoc(void);
   virtual void AddNewRecordDv(void);
};
#define CLSID_TREM_DMCustQueryImpl __uuidof(TREM_DMCustQueryImpl)
#endif
