#ifndef UREM_DMDocAktImplH
#define UREM_DMDocAktImplH
#include "IREM_DMDocAkt.h"
#include "UREM_DMDocAkt.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocAktImpl)) TREM_DMDocAktImpl : public IREM_DMDocAkt
{
public:
   TREM_DMDocAktImpl();
   ~TREM_DMDocAktImpl();
   TREM_DMDocAkt * Object;
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

//IREM_DMDocAkt
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

   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void);
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER);

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

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBLargeIntField * get_DocID_REM_DAKT(void);
   virtual void set_DocID_REM_DAKT(TFIBLargeIntField * DocID_REM_DAKT);

   virtual TFIBLargeIntField * get_DocIDBASE_REM_DAKT(void);
   virtual void set_DocIDBASE_REM_DAKT(TFIBLargeIntField * DocIDBASE_REM_DAKT);

   virtual TFIBWideStringField * get_DocGID_REM_DAKT(void);
   virtual void set_DocGID_REM_DAKT(TFIBWideStringField * DocGID_REM_DAKT);

   virtual TFIBLargeIntField * get_DocIDDOC_REM_DAKT(void);
   virtual void set_DocIDDOC_REM_DAKT(TFIBLargeIntField * DocIDDOC_REM_DAKT);

   virtual TFIBLargeIntField * get_DocIDZ_REM_DAKT(void);
   virtual void set_DocIDZ_REM_DAKT(TFIBLargeIntField * DocIDZ_REM_DAKT);

   virtual TFIBLargeIntField * get_DocIDHW_REM_DAKT(void);
   virtual void set_DocIDHW_REM_DAKT(TFIBLargeIntField * DocIDHW_REM_DAKT);

   virtual TFIBLargeIntField * get_DocIDKKT_REM_DAKT(void);
   virtual void set_DocIDKKT_REM_DAKT(TFIBLargeIntField * DocIDKKT_REM_DAKT);

   virtual TFIBWideStringField * get_DocPRIM_REM_DAKT(void);
   virtual void set_DocPRIM_REM_DAKT(TFIBWideStringField * DocPRIM_REM_DAKT);

   virtual TFIBSmallIntField * get_DocKL_SOGLASEN_REM_DAKT(void);
   virtual void set_DocKL_SOGLASEN_REM_DAKT(TFIBSmallIntField * DocKL_SOGLASEN_REM_DAKT);

   virtual TFIBSmallIntField * get_DocPODPISAN_REM_DAKT(void);
   virtual void set_DocPODPISAN_REM_DAKT(TFIBSmallIntField * DocPODPISAN_REM_DAKT);

   virtual TFIBIntegerField * get_DocTYPE_REM_DAKT(void);
   virtual void set_DocTYPE_REM_DAKT(TFIBIntegerField * DocTYPE_REM_DAKT);

   virtual TFIBWideStringField * get_DocNAME_REM_SHARDWARE(void);
   virtual void set_DocNAME_REM_SHARDWARE(TFIBWideStringField * DocNAME_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocSERNUM_REM_SHARDWARE(void);
   virtual void set_DocSERNUM_REM_SHARDWARE(TFIBWideStringField * DocSERNUM_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocSERNUM2_REM_SHARDWARE(void);
   virtual void set_DocSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocSERNUM2_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocNAME_REM_SKKT(void);
   virtual void set_DocNAME_REM_SKKT(TFIBWideStringField * DocNAME_REM_SKKT);

   virtual TFIBWideStringField * get_DocSERNUM_REM_SKKT(void);
   virtual void set_DocSERNUM_REM_SKKT(TFIBWideStringField * DocSERNUM_REM_SKKT);

   virtual TFIBWideStringField * get_DocSERNUM_REM_Z(void);
   virtual void set_DocSERNUM_REM_Z(TFIBWideStringField * DocSERNUM_REM_Z);

   virtual TFIBWideStringField * get_DocSERNUM2_REM_Z(void);
   virtual void set_DocSERNUM2_REM_Z(TFIBWideStringField * DocSERNUM2_REM_Z);

   virtual TFIBWideStringField * get_DocMODEL_REM_Z(void);
   virtual void set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z);

   virtual TFIBWideStringField * get_DocNAME_REM_SMODEL(void);
   virtual void set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL);

   virtual TFIBLargeIntField * get_DocTID_REM_DAKTT(void);
   virtual void set_DocTID_REM_DAKTT(TFIBLargeIntField * DocTID_REM_DAKTT);

   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DAKTT(void);
   virtual void set_DocTIDBASE_REM_DAKTT(TFIBLargeIntField * DocTIDBASE_REM_DAKTT);

   virtual TFIBWideStringField * get_DocTGID_REM_DAKTT(void);
   virtual void set_DocTGID_REM_DAKTT(TFIBWideStringField * DocTGID_REM_DAKTT);

   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DAKTT(void);
   virtual void set_DocTIDDOC_REM_DAKTT(TFIBLargeIntField * DocTIDDOC_REM_DAKTT);

   virtual TFIBIntegerField * get_DocTINDEX_REM_DAKTT(void);
   virtual void set_DocTINDEX_REM_DAKTT(TFIBIntegerField * DocTINDEX_REM_DAKTT);

   virtual TFIBWideStringField * get_DocTTEXT_REM_DAKTT(void);
   virtual void set_DocTTEXT_REM_DAKTT(TFIBWideStringField * DocTTEXT_REM_DAKTT);

   virtual TFIBWideStringField * get_DocNAME_REM_Z(void);
   virtual void set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z);

   virtual TFIBLargeIntField * get_DocAllIDPROJECT_REM_GALLDOC(void);
   virtual void set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_REM_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_DocAllIDOBJECT_REM_GALLDOC(void);
   virtual void set_DocAllIDOBJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SOBJECT(void);
   virtual void set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT);

   virtual TFIBWideStringField * get_DocNUM_U_PROISV_REM_DAKT(void);
   virtual void set_DocNUM_U_PROISV_REM_DAKT(TFIBWideStringField * DocNUM_U_PROISV_REM_DAKT);

   virtual TFIBWideStringField * get_DocNEISPR_KLIENTA_REM_DAKT(void);
   virtual void set_DocNEISPR_KLIENTA_REM_DAKT(TFIBWideStringField * DocNEISPR_KLIENTA_REM_DAKT);

   virtual TFIBWideStringField * get_DocNEISPR_SC_REM_DAKT(void);
   virtual void set_DocNEISPR_SC_REM_DAKT(TFIBWideStringField * DocNEISPR_SC_REM_DAKT);

   virtual TFIBIntegerField * get_DocFL_FULL_KOMPL_REM_DAKT(void);
   virtual void set_DocFL_FULL_KOMPL_REM_DAKT(TFIBIntegerField * DocFL_FULL_KOMPL_REM_DAKT);

   virtual TFIBWideStringField * get_DocNEKOMPL_STR_REM_DAKT(void);
   virtual void set_DocNEKOMPL_STR_REM_DAKT(TFIBWideStringField * DocNEKOMPL_STR_REM_DAKT);

   virtual TFIBWideStringField * get_DocKOMPL_STR_REM_DAKT(void);
   virtual void set_DocKOMPL_STR_REM_DAKT(TFIBWideStringField * DocKOMPL_STR_REM_DAKT);

   virtual TFIBIntegerField * get_DocFL_MEXPOVR_REM_DAKT(void);
   virtual void set_DocFL_MEXPOVR_REM_DAKT(TFIBIntegerField * DocFL_MEXPOVR_REM_DAKT);

   virtual TFIBWideStringField * get_DocMEXPOVR_STR_REM_DAKT(void);
   virtual void set_DocMEXPOVR_STR_REM_DAKT(TFIBWideStringField * DocMEXPOVR_STR_REM_DAKT);

   virtual TFIBWideStringField * get_DocNEISPR_BLOK_REM_DAKT(void);
   virtual void set_DocNEISPR_BLOK_REM_DAKT(TFIBWideStringField * DocNEISPR_BLOK_REM_DAKT);

   virtual TFIBIntegerField * get_DocFL_PRICHINA_ACTA_REM_DAKT(void);
   virtual void set_DocFL_PRICHINA_ACTA_REM_DAKT(TFIBIntegerField * DocFL_PRICHINA_ACTA_REM_DAKT);

   virtual TFIBWideStringField * get_DocPRICHINA_ACTA_DR_STR_REM_DAKT(void);
   virtual void set_DocPRICHINA_ACTA_DR_STR_REM_DAKT(TFIBWideStringField * DocPRICHINA_ACTA_DR_STR_REM_DAKT);

   virtual TFIBIntegerField * get_DocFL_PRICHINA_SOST_REM_DAKT(void);
   virtual void set_DocFL_PRICHINA_SOST_REM_DAKT(TFIBIntegerField * DocFL_PRICHINA_SOST_REM_DAKT);

   virtual TFIBIntegerField * get_DocFL_MESTONAX_REM_DAKT(void);
   virtual void set_DocFL_MESTONAX_REM_DAKT(TFIBIntegerField * DocFL_MESTONAX_REM_DAKT);

   virtual TFIBWideStringField * get_DocISD_NAME_REM_DAKT(void);
   virtual void set_DocISD_NAME_REM_DAKT(TFIBWideStringField * DocISD_NAME_REM_DAKT);

   virtual TFIBDateField * get_DocISD_DATE_PRODAGI_REM_DAKT(void);
   virtual void set_DocISD_DATE_PRODAGI_REM_DAKT(TFIBDateField * DocISD_DATE_PRODAGI_REM_DAKT);

   virtual TFIBWideStringField * get_DocISD_MODEL_REM_DAKT(void);
   virtual void set_DocISD_MODEL_REM_DAKT(TFIBWideStringField * DocISD_MODEL_REM_DAKT);

   virtual TFIBWideStringField * get_DocISD_SERNUM1_REM_DAKT(void);
   virtual void set_DocISD_SERNUM1_REM_DAKT(TFIBWideStringField * DocISD_SERNUM1_REM_DAKT);

   virtual TFIBWideStringField * get_DocISD_SERNUM2_REM_DAKT(void);
   virtual void set_DocISD_SERNUM2_REM_DAKT(TFIBWideStringField * DocISD_SERNUM2_REM_DAKT);

   virtual TFIBWideStringField * get_DocISD_SERNUM3_REM_DAKT(void);
   virtual void set_DocISD_SERNUM3_REM_DAKT(TFIBWideStringField * DocISD_SERNUM3_REM_DAKT);

   virtual TFIBWideStringField * get_DocISD_NUMUP_REM_DAKT(void);
   virtual void set_DocISD_NUMUP_REM_DAKT(TFIBWideStringField * DocISD_NUMUP_REM_DAKT);

   virtual TFIBWideStringField * get_DocISD_NUMTEXLIST_REM_DAKT(void);
   virtual void set_DocISD_NUMTEXLIST_REM_DAKT(TFIBWideStringField * DocISD_NUMTEXLIST_REM_DAKT);

   virtual TFIBWideStringField * get_DocPRODAVEC_NAME_REM_DAKT(void);
   virtual void set_DocPRODAVEC_NAME_REM_DAKT(TFIBWideStringField * DocPRODAVEC_NAME_REM_DAKT);

   virtual TFIBWideStringField * get_DocPRODAVEC_TEL_REM_DAKT(void);
   virtual void set_DocPRODAVEC_TEL_REM_DAKT(TFIBWideStringField * DocPRODAVEC_TEL_REM_DAKT);

   virtual TFIBWideStringField * get_DocKLIENT_NAME_REM_DAKT(void);
   virtual void set_DocKLIENT_NAME_REM_DAKT(TFIBWideStringField * DocKLIENT_NAME_REM_DAKT);

   virtual TFIBWideStringField * get_DocKLIENT_ADR_REM_DAKT(void);
   virtual void set_DocKLIENT_ADR_REM_DAKT(TFIBWideStringField * DocKLIENT_ADR_REM_DAKT);

   virtual TFIBWideStringField * get_DocKLIENT_PHONE_REM_DAKT(void);
   virtual void set_DocKLIENT_PHONE_REM_DAKT(TFIBWideStringField * DocKLIENT_PHONE_REM_DAKT);

   virtual TFIBWideStringField * get_DocPRICHINA_SOST_DR_REM_DAKT(void);
   virtual void set_DocPRICHINA_SOST_DR_REM_DAKT(TFIBWideStringField * DocPRICHINA_SOST_DR_REM_DAKT);

   virtual TFIBWideStringField * get_DocPRODAVEC_ADR_REM_DAKT(void);
   virtual void set_DocPRODAVEC_ADR_REM_DAKT(TFIBWideStringField * DocPRODAVEC_ADR_REM_DAKT);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool NewDoc(void);
   virtual bool OpenDoc(__int64 id);
   virtual bool SaveDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void TableAppend(void);
   virtual void TableDelete(void);
};
#define CLSID_TREM_DMDocAktImpl __uuidof(TREM_DMDocAktImpl)
#endif
