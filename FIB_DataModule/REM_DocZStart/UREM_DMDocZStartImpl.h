#ifndef UREM_DMDocZStartImplH
#define UREM_DMDocZStartImplH
#include "IREM_DMDocZStart.h"
#include "UREM_DMDocZStart.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocZStartImpl)) TREM_DMDocZStartImpl : public IREM_DMDocZStart
{
public:
   TREM_DMDocZStartImpl();
   ~TREM_DMDocZStartImpl();
   TREM_DMDocZStart * Object;
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

//IREM_DMDocZStart
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

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

   virtual TFIBLargeIntField * get_DocID_REM_DZSTART(void);
   virtual void set_DocID_REM_DZSTART(TFIBLargeIntField * DocID_REM_DZSTART);

   virtual TFIBLargeIntField * get_DocIDBASE_REM_DZSTART(void);
   virtual void set_DocIDBASE_REM_DZSTART(TFIBLargeIntField * DocIDBASE_REM_DZSTART);

   virtual TFIBWideStringField * get_DocGID_REM_DZSTART(void);
   virtual void set_DocGID_REM_DZSTART(TFIBWideStringField * DocGID_REM_DZSTART);

   virtual TFIBLargeIntField * get_DocIDDOC_REM_DZSTART(void);
   virtual void set_DocIDDOC_REM_DZSTART(TFIBLargeIntField * DocIDDOC_REM_DZSTART);

   virtual TFIBLargeIntField * get_DocIDZ_REM_DZSTART(void);
   virtual void set_DocIDZ_REM_DZSTART(TFIBLargeIntField * DocIDZ_REM_DZSTART);

   virtual TFIBWideStringField * get_DocPRIM_REM_DZSTART(void);
   virtual void set_DocPRIM_REM_DZSTART(TFIBWideStringField * DocPRIM_REM_DZSTART);

   virtual TFIBWideStringField * get_DocNAME_REM_Z(void);
   virtual void set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z);

   virtual TFIBIntegerField * get_DocNUM_REM_Z(void);
   virtual void set_DocNUM_REM_Z(TFIBIntegerField * DocNUM_REM_Z);

   virtual TFIBDateTimeField * get_DocPOS_REM_Z(void);
   virtual void set_DocPOS_REM_Z(TFIBDateTimeField * DocPOS_REM_Z);

   virtual TFIBWideStringField * get_DocSERNUM_REM_Z(void);
   virtual void set_DocSERNUM_REM_Z(TFIBWideStringField * DocSERNUM_REM_Z);

   virtual TFIBWideStringField * get_DocSERNUM2_REM_Z(void);
   virtual void set_DocSERNUM2_REM_Z(TFIBWideStringField * DocSERNUM2_REM_Z);

   virtual TFIBWideStringField * get_DocKLIENT_NAME_REM_Z(void);
   virtual void set_DocKLIENT_NAME_REM_Z(TFIBWideStringField * DocKLIENT_NAME_REM_Z);

   virtual TFIBWideStringField * get_DocMODEL_REM_Z(void);
   virtual void set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z);

   virtual TFIBWideStringField * get_DocNAME_REM_SMODEL(void);
   virtual void set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL);

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

   virtual TFIBLargeIntField * get_DocIDPR_REM_DZSTART(void);
   virtual void set_DocIDPR_REM_DZSTART(TFIBLargeIntField * DocIDPR_REM_DZSTART);

   virtual TFIBLargeIntField * get_DocIDCFCPR_REM_DZSTART(void);
   virtual void set_DocIDCFCPR_REM_DZSTART(TFIBLargeIntField * DocIDCFCPR_REM_DZSTART);

   virtual TFIBLargeIntField * get_DocIDNEISPR_REM_DZSTART(void);
   virtual void set_DocIDNEISPR_REM_DZSTART(TFIBLargeIntField * DocIDNEISPR_REM_DZSTART);

   virtual TFIBLargeIntField * get_DocIDPRMODEL_REM_DZSTART(void);
   virtual void set_DocIDPRMODEL_REM_DZSTART(TFIBLargeIntField * DocIDPRMODEL_REM_DZSTART);

   virtual TFIBWideStringField * get_DocPODO_REM_DZSTART(void);
   virtual void set_DocPODO_REM_DZSTART(TFIBWideStringField * DocPODO_REM_DZSTART);

   virtual TFIBWideStringField * get_DocPRODAVEC_REM_DZSTART(void);
   virtual void set_DocPRODAVEC_REM_DZSTART(TFIBWideStringField * DocPRODAVEC_REM_DZSTART);

   virtual TFIBWideStringField * get_DocSERNUM3_REM_DZSTART(void);
   virtual void set_DocSERNUM3_REM_DZSTART(TFIBWideStringField * DocSERNUM3_REM_DZSTART);

   virtual TFIBWideStringField * get_DocSERNUM4_REM_DZSTART(void);
   virtual void set_DocSERNUM4_REM_DZSTART(TFIBWideStringField * DocSERNUM4_REM_DZSTART);

   virtual TFIBWideStringField * get_DocNUMBAT_REM_DZSTART(void);
   virtual void set_DocNUMBAT_REM_DZSTART(TFIBWideStringField * DocNUMBAT_REM_DZSTART);

   virtual TFIBWideStringField * get_DocSOST_REM_DZSTART(void);
   virtual void set_DocSOST_REM_DZSTART(TFIBWideStringField * DocSOST_REM_DZSTART);

   virtual TFIBDateField * get_DocDATEVIPUSK_REM_DZSTART(void);
   virtual void set_DocDATEVIPUSK_REM_DZSTART(TFIBDateField * DocDATEVIPUSK_REM_DZSTART);

   virtual TFIBDateField * get_DocDATE_PRODAGI_REM_DZSTART(void);
   virtual void set_DocDATE_PRODAGI_REM_DZSTART(TFIBDateField * DocDATE_PRODAGI_REM_DZSTART);

   virtual TFIBIntegerField * get_DocKEM_SDANO_REM_DZSTART(void);
   virtual void set_DocKEM_SDANO_REM_DZSTART(TFIBIntegerField * DocKEM_SDANO_REM_DZSTART);

   virtual TFIBIntegerField * get_DocTYPE_REMONT_REM_DZSTART(void);
   virtual void set_DocTYPE_REMONT_REM_DZSTART(TFIBIntegerField * DocTYPE_REMONT_REM_DZSTART);

   virtual TFIBWideStringField * get_DocNAME_SPRODUCER(void);
   virtual void set_DocNAME_SPRODUCER(TFIBWideStringField * DocNAME_SPRODUCER);

   virtual TFIBWideStringField * get_DocNAME_REM_SPRNEISPR(void);
   virtual void set_DocNAME_REM_SPRNEISPR(TFIBWideStringField * DocNAME_REM_SPRNEISPR);

   virtual TFIBWideStringField * get_DocCODE_REM_SPRNEISPR(void);
   virtual void set_DocCODE_REM_SPRNEISPR(TFIBWideStringField * DocCODE_REM_SPRNEISPR);

   virtual TFIBWideStringField * get_DocNAME_REM_SNEISPR(void);
   virtual void set_DocNAME_REM_SNEISPR(TFIBWideStringField * DocNAME_REM_SNEISPR);

   virtual TFIBWideStringField * get_DocNAME_REM_SPRMODEL(void);
   virtual void set_DocNAME_REM_SPRMODEL(TFIBWideStringField * DocNAME_REM_SPRMODEL);

   virtual TFIBWideStringField * get_DocCODE_REM_SPRMODEL(void);
   virtual void set_DocCODE_REM_SPRMODEL(TFIBWideStringField * DocCODE_REM_SPRMODEL);

   virtual TFIBWideStringField * get_DocNUM_GARDOC_REM_Z(void);
   virtual void set_DocNUM_GARDOC_REM_Z(TFIBWideStringField * DocNUM_GARDOC_REM_Z);

   virtual TFIBLargeIntField * get_DocIDSELLER_REM_DZSTART(void);
   virtual void set_DocIDSELLER_REM_DZSTART(TFIBLargeIntField * DocIDSELLER_REM_DZSTART);

   virtual TFIBWideStringField * get_DocNAME_REM_SPRNEISPR_GRP(void);
   virtual void set_DocNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * DocNAME_REM_SPRNEISPR_GRP);

   virtual TFIBWideStringField * get_DocNAME_ENG_REM_SPRNEISPR_GRP(void);
   virtual void set_DocNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * DocNAME_ENG_REM_SPRNEISPR_GRP);

   virtual TFIBWideStringField * get_DocNAME_ENG_REM_SNEISPR(void);
   virtual void set_DocNAME_ENG_REM_SNEISPR(TFIBWideStringField * DocNAME_ENG_REM_SNEISPR);

   virtual TFIBWideStringField * get_DocNAME_REM_SGRPNEISPR(void);
   virtual void set_DocNAME_REM_SGRPNEISPR(TFIBWideStringField * DocNAME_REM_SGRPNEISPR);

   virtual TFIBWideStringField * get_DocNAME_ENG_REM_SGRPNEISPR(void);
   virtual void set_DocNAME_ENG_REM_SGRPNEISPR(TFIBWideStringField * DocNAME_ENG_REM_SGRPNEISPR);

   virtual TFIBWideStringField * get_DocNAME_SSELLER(void);
   virtual void set_DocNAME_SSELLER(TFIBWideStringField * DocNAME_SSELLER);

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
};
#define CLSID_TREM_DMDocZStartImpl __uuidof(TREM_DMDocZStartImpl)
#endif
