#ifndef UREM_DMDocZAktPrImplH
#define UREM_DMDocZAktPrImplH
#include "IREM_DMDocZAktPr.h"
#include "UREM_DMDocZAktPr.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocZAktPrImpl)) TREM_DMDocZAktPrImpl : public IREM_DMDocZAktPr
{
public:
   TREM_DMDocZAktPrImpl();
   ~TREM_DMDocZAktPrImpl();
   TREM_DMDocZAktPr * Object;
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

//IREM_DMDocZAktPr
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

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

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

   virtual TFIBLargeIntField * get_DocID_REM_DZAKTPR(void);
   virtual void set_DocID_REM_DZAKTPR(TFIBLargeIntField * DocID_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_DocIDBASE_REM_DZAKTPR(void);
   virtual void set_DocIDBASE_REM_DZAKTPR(TFIBLargeIntField * DocIDBASE_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocGID_REM_DZAKTPR(void);
   virtual void set_DocGID_REM_DZAKTPR(TFIBWideStringField * DocGID_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_DocIDDOC_REM_DZAKTPR(void);
   virtual void set_DocIDDOC_REM_DZAKTPR(TFIBLargeIntField * DocIDDOC_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_DocIDZ_REM_DZAKTPR(void);
   virtual void set_DocIDZ_REM_DZAKTPR(TFIBLargeIntField * DocIDZ_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_DocIDTPRICE_REM_DZAKTPR(void);
   virtual void set_DocIDTPRICE_REM_DZAKTPR(TFIBLargeIntField * DocIDTPRICE_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocPRIM_REM_DZAKTPR(void);
   virtual void set_DocPRIM_REM_DZAKTPR(TFIBWideStringField * DocPRIM_REM_DZAKTPR);

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

   virtual TFIBLargeIntField * get_DocTID_REM_DZAKTPRT(void);
   virtual void set_DocTID_REM_DZAKTPRT(TFIBLargeIntField * DocTID_REM_DZAKTPRT);

   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DZAKTPRT(void);
   virtual void set_DocTIDBASE_REM_DZAKTPRT(TFIBLargeIntField * DocTIDBASE_REM_DZAKTPRT);

   virtual TFIBWideStringField * get_DocTGID_REM_DZAKTPRT(void);
   virtual void set_DocTGID_REM_DZAKTPRT(TFIBWideStringField * DocTGID_REM_DZAKTPRT);

   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DZAKTPRT(void);
   virtual void set_DocTIDDOC_REM_DZAKTPRT(TFIBLargeIntField * DocTIDDOC_REM_DZAKTPRT);

   virtual TFIBLargeIntField * get_DocTIDNOM_REM_DZAKTPRT(void);
   virtual void set_DocTIDNOM_REM_DZAKTPRT(TFIBLargeIntField * DocTIDNOM_REM_DZAKTPRT);

   virtual TFIBLargeIntField * get_DocTIDED_REM_DZAKTPRT(void);
   virtual void set_DocTIDED_REM_DZAKTPRT(TFIBLargeIntField * DocTIDED_REM_DZAKTPRT);

   virtual TFIBLargeIntField * get_DocTIDHW_REM_DZAKTPRT(void);
   virtual void set_DocTIDHW_REM_DZAKTPRT(TFIBLargeIntField * DocTIDHW_REM_DZAKTPRT);

   virtual TFIBBCDField * get_DocTKOL_REM_DZAKTPRT(void);
   virtual void set_DocTKOL_REM_DZAKTPRT(TFIBBCDField * DocTKOL_REM_DZAKTPRT);

   virtual TFIBBCDField * get_DocTKF_REM_DZAKTPRT(void);
   virtual void set_DocTKF_REM_DZAKTPRT(TFIBBCDField * DocTKF_REM_DZAKTPRT);

   virtual TFIBBCDField * get_DocTPRICE_REM_DZAKTPRT(void);
   virtual void set_DocTPRICE_REM_DZAKTPRT(TFIBBCDField * DocTPRICE_REM_DZAKTPRT);

   virtual TFIBBCDField * get_DocTSUM_REM_DZAKTPRT(void);
   virtual void set_DocTSUM_REM_DZAKTPRT(TFIBBCDField * DocTSUM_REM_DZAKTPRT);

   virtual TFIBSmallIntField * get_DocTDVREG_REM_DZAKTPRT(void);
   virtual void set_DocTDVREG_REM_DZAKTPRT(TFIBSmallIntField * DocTDVREG_REM_DZAKTPRT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual TFIBWideStringField * get_DocTNAME_REM_SHARDWARE(void);
   virtual void set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE);

   virtual TFIBIntegerField * get_DocTCODE_REM_SHARDWARE(void);
   virtual void set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocTSERNUM_REM_SHARDWARE(void);
   virtual void set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_DocIDPR_REM_DZAKTPR(void);
   virtual void set_DocIDPR_REM_DZAKTPR(TFIBLargeIntField * DocIDPR_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_DocIDCFC_REM_DZAKTPR(void);
   virtual void set_DocIDCFC_REM_DZAKTPR(TFIBLargeIntField * DocIDCFC_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_DocIDDFC_REM_DZAKTPR(void);
   virtual void set_DocIDDFC_REM_DZAKTPR(TFIBLargeIntField * DocIDDFC_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_DocIDPRMODEL_REM_DZAKTPR(void);
   virtual void set_DocIDPRMODEL_REM_DZAKTPR(TFIBLargeIntField * DocIDPRMODEL_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocPODO_REM_DZAKTPR(void);
   virtual void set_DocPODO_REM_DZAKTPR(TFIBWideStringField * DocPODO_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocPOPOSLE_REM_DZAKTPR(void);
   virtual void set_DocPOPOSLE_REM_DZAKTPR(TFIBWideStringField * DocPOPOSLE_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocDESCR_REM_DZAKTPR(void);
   virtual void set_DocDESCR_REM_DZAKTPR(TFIBWideStringField * DocDESCR_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocPRODAVEC_REM_DZAKTPR(void);
   virtual void set_DocPRODAVEC_REM_DZAKTPR(TFIBWideStringField * DocPRODAVEC_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocNUMGARTALON_REM_DZAKTPR(void);
   virtual void set_DocNUMGARTALON_REM_DZAKTPR(TFIBWideStringField * DocNUMGARTALON_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocSERNUM3_REM_DZAKTPR(void);
   virtual void set_DocSERNUM3_REM_DZAKTPR(TFIBWideStringField * DocSERNUM3_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocSERNUM4_REM_DZAKTPR(void);
   virtual void set_DocSERNUM4_REM_DZAKTPR(TFIBWideStringField * DocSERNUM4_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocNUMBAT_REM_DZAKTPR(void);
   virtual void set_DocNUMBAT_REM_DZAKTPR(TFIBWideStringField * DocNUMBAT_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocSOST_REM_DZAKTPR(void);
   virtual void set_DocSOST_REM_DZAKTPR(TFIBWideStringField * DocSOST_REM_DZAKTPR);

   virtual TFIBDateField * get_DocDATEVIPUSK_REM_DZAKTPR(void);
   virtual void set_DocDATEVIPUSK_REM_DZAKTPR(TFIBDateField * DocDATEVIPUSK_REM_DZAKTPR);

   virtual TFIBDateField * get_DocDATE_PRODAGI_REM_DZAKTPR(void);
   virtual void set_DocDATE_PRODAGI_REM_DZAKTPR(TFIBDateField * DocDATE_PRODAGI_REM_DZAKTPR);

   virtual TFIBIntegerField * get_DocTYPE_REMONT_REM_DZAKTPR(void);
   virtual void set_DocTYPE_REMONT_REM_DZAKTPR(TFIBIntegerField * DocTYPE_REMONT_REM_DZAKTPR);

   virtual TFIBIntegerField * get_DocKEM_SDANO_REM_DZAKTPR(void);
   virtual void set_DocKEM_SDANO_REM_DZAKTPR(TFIBIntegerField * DocKEM_SDANO_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocCFC_NAME(void);
   virtual void set_DocCFC_NAME(TFIBWideStringField * DocCFC_NAME);

   virtual TFIBWideStringField * get_DocCFC_CODE(void);
   virtual void set_DocCFC_CODE(TFIBWideStringField * DocCFC_CODE);

   virtual TFIBWideStringField * get_DocDFC_NAME(void);
   virtual void set_DocDFC_NAME(TFIBWideStringField * DocDFC_NAME);

   virtual TFIBWideStringField * get_DocDFC_CODE(void);
   virtual void set_DocDFC_CODE(TFIBWideStringField * DocDFC_CODE);

   virtual TFIBWideStringField * get_DocNAME_SPRODUCER(void);
   virtual void set_DocNAME_SPRODUCER(TFIBWideStringField * DocNAME_SPRODUCER);

   virtual TFIBWideStringField * get_DocNAME_REM_SPRMODEL(void);
   virtual void set_DocNAME_REM_SPRMODEL(TFIBWideStringField * DocNAME_REM_SPRMODEL);

   virtual TFIBWideStringField * get_DocCODE_REM_SPRMODEL(void);
   virtual void set_DocCODE_REM_SPRMODEL(TFIBWideStringField * DocCODE_REM_SPRMODEL);

   virtual TFIBWideStringField * get_DocNEISPR_REM_DZAKTPR(void);
   virtual void set_DocNEISPR_REM_DZAKTPR(TFIBWideStringField * DocNEISPR_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocNEISPR_REM_Z(void);
   virtual void set_DocNEISPR_REM_Z(TFIBWideStringField * DocNEISPR_REM_Z);

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

   virtual TFIBLargeIntField * get_DocTIDPRDEFECT_REM_DZAKTPR(void);
   virtual void set_DocTIDPRDEFECT_REM_DZAKTPR(TFIBLargeIntField * DocTIDPRDEFECT_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocTCODE_REM_SPRDEFECT(void);
   virtual void set_DocTCODE_REM_SPRDEFECT(TFIBWideStringField * DocTCODE_REM_SPRDEFECT);

   virtual TFIBWideStringField * get_DocTNAME_REM_SPRDEFECT(void);
   virtual void set_DocTNAME_REM_SPRDEFECT(TFIBWideStringField * DocTNAME_REM_SPRDEFECT);

   virtual TFIBIntegerField * get_DocFL_FICTIV_REM_DZAKTPR(void);
   virtual void set_DocFL_FICTIV_REM_DZAKTPR(TFIBIntegerField * DocFL_FICTIV_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocKLIENT_NAME_REM_DZAKTPR(void);
   virtual void set_DocKLIENT_NAME_REM_DZAKTPR(TFIBWideStringField * DocKLIENT_NAME_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocKLIENT_ADR_REM_DZAKTPR(void);
   virtual void set_DocKLIENT_ADR_REM_DZAKTPR(TFIBWideStringField * DocKLIENT_ADR_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocKLIENT_PHONE_REM_DZAKTPR(void);
   virtual void set_DocKLIENT_PHONE_REM_DZAKTPR(TFIBWideStringField * DocKLIENT_PHONE_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_DocIDDILER_REM_DZAKTPR(void);
   virtual void set_DocIDDILER_REM_DZAKTPR(TFIBLargeIntField * DocIDDILER_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocNAMEKLIENT(void);
   virtual void set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT);

   virtual TFIBWideStringField * get_DocPOST_ZIP_NAME(void);
   virtual void set_DocPOST_ZIP_NAME(TFIBWideStringField * DocPOST_ZIP_NAME);

   virtual TFIBSmallIntField * get_DocFL_OTCHET_POST_REM_DZAKTPR(void);
   virtual void set_DocFL_OTCHET_POST_REM_DZAKTPR(TFIBSmallIntField * DocFL_OTCHET_POST_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_DocIDPOST_ZIP_REM_DZAKTPR(void);
   virtual void set_DocIDPOST_ZIP_REM_DZAKTPR(TFIBLargeIntField * DocIDPOST_ZIP_REM_DZAKTPR);

   virtual TFIBSmallIntField * get_DocFL_NE_OTCH_REM_DZAKTPR(void);
   virtual void set_DocFL_NE_OTCH_REM_DZAKTPR(TFIBSmallIntField * DocFL_NE_OTCH_REM_DZAKTPR);

   virtual TFIBSmallIntField * get_DocFL_NADO_OTCH_REM_DZAKTPR(void);
   virtual void set_DocFL_NADO_OTCH_REM_DZAKTPR(TFIBSmallIntField * DocFL_NADO_OTCH_REM_DZAKTPR);

   virtual TFIBSmallIntField * get_DocFL_PRIG_KREM_REM_DZAKTPR(void);
   virtual void set_DocFL_PRIG_KREM_REM_DZAKTPR(TFIBSmallIntField * DocFL_PRIG_KREM_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocCODE_REM_SMODEL(void);
   virtual void set_DocCODE_REM_SMODEL(TFIBWideStringField * DocCODE_REM_SMODEL);

   virtual TFIBWideStringField * get_DocNAME_REM_SPRNEISPR_GRP(void);
   virtual void set_DocNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * DocNAME_REM_SPRNEISPR_GRP);

   virtual TFIBDateTimeField * get_DocPOSPRIEMA_REM_DZAKTPR(void);
   virtual void set_DocPOSPRIEMA_REM_DZAKTPR(TFIBDateTimeField * DocPOSPRIEMA_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_DocIDSELLER_REM_DZAKTPR(void);
   virtual void set_DocIDSELLER_REM_DZAKTPR(TFIBLargeIntField * DocIDSELLER_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocNAME_SSELLER(void);
   virtual void set_DocNAME_SSELLER(TFIBWideStringField * DocNAME_SSELLER);

   virtual TFIBWideStringField * get_DocCFC_NAME_ENG(void);
   virtual void set_DocCFC_NAME_ENG(TFIBWideStringField * DocCFC_NAME_ENG);

   virtual TFIBWideStringField * get_DocNAME_ENG_REM_SPRNEISPR_GRP(void);
   virtual void set_DocNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * DocNAME_ENG_REM_SPRNEISPR_GRP);

   virtual TFIBWideStringField * get_DocKLIENT_EMAIL_REM_DZAKTPR(void);
   virtual void set_DocKLIENT_EMAIL_REM_DZAKTPR(TFIBWideStringField * DocKLIENT_EMAIL_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocFAMILIYA_REM_DZAKTPR(void);
   virtual void set_DocFAMILIYA_REM_DZAKTPR(TFIBWideStringField * DocFAMILIYA_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocIMYA_REM_DZAKTPR(void);
   virtual void set_DocIMYA_REM_DZAKTPR(TFIBWideStringField * DocIMYA_REM_DZAKTPR);

   virtual TFIBWideStringField * get_DocOTCHESTVO_REM_DZAKTPR(void);
   virtual void set_DocOTCHESTVO_REM_DZAKTPR(TFIBWideStringField * DocOTCHESTVO_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_DocTIDPRNEISPR_REM_DZAKTPRT(void);
   virtual void set_DocTIDPRNEISPR_REM_DZAKTPRT(TFIBLargeIntField * DocTIDPRNEISPR_REM_DZAKTPRT);

   virtual TFIBLargeIntField * get_DocTIDPRRABOTA_REM_DZAKTPRT(void);
   virtual void set_DocTIDPRRABOTA_REM_DZAKTPRT(TFIBLargeIntField * DocTIDPRRABOTA_REM_DZAKTPRT);

   virtual TFIBLargeIntField * get_DocTIDHWOLD_REM_DZAKTPRT(void);
   virtual void set_DocTIDHWOLD_REM_DZAKTPRT(TFIBLargeIntField * DocTIDHWOLD_REM_DZAKTPRT);

   virtual TFIBSmallIntField * get_DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT(void);
   virtual void set_DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT(TFIBSmallIntField * DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT);

   virtual TFIBWideStringField * get_DocTNAME_REM_SPRNEISPR(void);
   virtual void set_DocTNAME_REM_SPRNEISPR(TFIBWideStringField * DocTNAME_REM_SPRNEISPR);

   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRNEISPR(void);
   virtual void set_DocTNAME_ENG_REM_SPRNEISPR(TFIBWideStringField * DocTNAME_ENG_REM_SPRNEISPR);

   virtual TFIBWideStringField * get_DocTCODE_REM_SPRNEISPR(void);
   virtual void set_DocTCODE_REM_SPRNEISPR(TFIBWideStringField * DocTCODE_REM_SPRNEISPR);

   virtual TFIBWideStringField * get_DocTNAME_REM_SPRNEISPR_GRP(void);
   virtual void set_DocTNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * DocTNAME_REM_SPRNEISPR_GRP);

   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRNEISPR_GRP(void);
   virtual void set_DocTNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRNEISPR_GRP);

   virtual TFIBWideStringField * get_DocTNAME_REM_SPRDEFECT_GRP(void);
   virtual void set_DocTNAME_REM_SPRDEFECT_GRP(TFIBWideStringField * DocTNAME_REM_SPRDEFECT_GRP);

   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRDEFECT_GRP(void);
   virtual void set_DocTNAME_ENG_REM_SPRDEFECT_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRDEFECT_GRP);

   virtual TFIBWideStringField * get_DocTCODE_REM_SPRRABOTA(void);
   virtual void set_DocTCODE_REM_SPRRABOTA(TFIBWideStringField * DocTCODE_REM_SPRRABOTA);

   virtual TFIBWideStringField * get_DocTNAME_REM_SPRRABOTA(void);
   virtual void set_DocTNAME_REM_SPRRABOTA(TFIBWideStringField * DocTNAME_REM_SPRRABOTA);

   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRRABOTA(void);
   virtual void set_DocTNAME_ENG_REM_SPRRABOTA(TFIBWideStringField * DocTNAME_ENG_REM_SPRRABOTA);

   virtual TFIBWideStringField * get_DocTNAME_REM_SPRRABOTA_GRP(void);
   virtual void set_DocTNAME_REM_SPRRABOTA_GRP(TFIBWideStringField * DocTNAME_REM_SPRRABOTA_GRP);

   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRRABOTA_GRP(void);
   virtual void set_DocTNAME_ENG_REM_SPRRABOTA_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRRABOTA_GRP);

   virtual TFIBWideStringField * get_DocTOLD_NAME_REM_SHARDWARE(void);
   virtual void set_DocTOLD_NAME_REM_SHARDWARE(TFIBWideStringField * DocTOLD_NAME_REM_SHARDWARE);

   virtual TFIBIntegerField * get_DocTOLD_CODE_REM_SHARDWARE(void);
   virtual void set_DocTOLD_CODE_REM_SHARDWARE(TFIBIntegerField * DocTOLD_CODE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocTOLD_SERNUM_REM_SHARDWARE(void);
   virtual void set_DocTOLD_SERNUM_REM_SHARDWARE(TFIBWideStringField * DocTOLD_SERNUM_REM_SHARDWARE);

   virtual TFIBIntegerField * get_DocTFL_ISP_REM_DZAKTPRT(void);
   virtual void set_DocTFL_ISP_REM_DZAKTPRT(TFIBIntegerField * DocTFL_ISP_REM_DZAKTPRT);

   virtual TFIBLargeIntField * get_DocTIDPRCOND_REM_DZAKTPRT(void);
   virtual void set_DocTIDPRCOND_REM_DZAKTPRT(TFIBLargeIntField * DocTIDPRCOND_REM_DZAKTPRT);

   virtual TFIBLargeIntField * get_DocTIDPRSECTION_REM_DZAKTPRT(void);
   virtual void set_DocTIDPRSECTION_REM_DZAKTPRT(TFIBLargeIntField * DocTIDPRSECTION_REM_DZAKTPRT);

   virtual TFIBWideStringField * get_DocTCODE_REM_SPRCONDITION(void);
   virtual void set_DocTCODE_REM_SPRCONDITION(TFIBWideStringField * DocTCODE_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_DocTNAME_REM_SPRCONDITION(void);
   virtual void set_DocTNAME_REM_SPRCONDITION(TFIBWideStringField * DocTNAME_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRCONDITION(void);
   virtual void set_DocTNAME_ENG_REM_SPRCONDITION(TFIBWideStringField * DocTNAME_ENG_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_DocTCODE_REM_SPRCOND_GRP(void);
   virtual void set_DocTCODE_REM_SPRCOND_GRP(TFIBWideStringField * DocTCODE_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_DocTNAME_REM_SPRCOND_GRP(void);
   virtual void set_DocTNAME_REM_SPRCOND_GRP(TFIBWideStringField * DocTNAME_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRCOND_GRP(void);
   virtual void set_DocTNAME_ENG_REM_SPRCOND_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_DocTCODE_REM_SPRSECTION(void);
   virtual void set_DocTCODE_REM_SPRSECTION(TFIBWideStringField * DocTCODE_REM_SPRSECTION);

   virtual TFIBWideStringField * get_DocTNAME_REM_SPRSECTION(void);
   virtual void set_DocTNAME_REM_SPRSECTION(TFIBWideStringField * DocTNAME_REM_SPRSECTION);

   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRSECTION(void);
   virtual void set_DocTNAME_ENG_REM_SPRSECTION(TFIBWideStringField * DocTNAME_ENG_REM_SPRSECTION);

   virtual TFIBWideStringField * get_DocTCODE_REM_SPRSECTION_GRP(void);
   virtual void set_DocTCODE_REM_SPRSECTION_GRP(TFIBWideStringField * DocTCODE_REM_SPRSECTION_GRP);

   virtual TFIBWideStringField * get_DocTNAME_REM_SPRSECTION_GRP(void);
   virtual void set_DocTNAME_REM_SPRSECTION_GRP(TFIBWideStringField * DocTNAME_REM_SPRSECTION_GRP);

   virtual TFIBWideStringField * get_DocTNAME_ENG_REM_SPRSECTION_GRP(void);
   virtual void set_DocTNAME_ENG_REM_SPRSECTION_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRSECTION_GRP);

   virtual TFIBLargeIntField * get_DocAllIDOBJECT_REM_GALLDOC(void);
   virtual void set_DocAllIDOBJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SOBJECT(void);
   virtual void set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT);

   virtual TFIBLargeIntField * get_DocTIDTNOM_REM_DZAKTPRT(void);
   virtual void set_DocTIDTNOM_REM_DZAKTPRT(TFIBLargeIntField * DocTIDTNOM_REM_DZAKTPRT);

   virtual TFIBLargeIntField * get_DocTIDHW_DONOR_REM_DZAKTPRT(void);
   virtual void set_DocTIDHW_DONOR_REM_DZAKTPRT(TFIBLargeIntField * DocTIDHW_DONOR_REM_DZAKTPRT);

   virtual TFIBLargeIntField * get_DocTIDTYP_USEL_REM_DZAKTPRT(void);
   virtual void set_DocTIDTYP_USEL_REM_DZAKTPRT(TFIBLargeIntField * DocTIDTYP_USEL_REM_DZAKTPRT);

   virtual TFIBWideStringField * get_DocTDESCR_REM_DZAKTPRT(void);
   virtual void set_DocTDESCR_REM_DZAKTPRT(TFIBWideStringField * DocTDESCR_REM_DZAKTPRT);

   virtual TFIBWideStringField * get_DocTDONOR_NAME_REM_SHARDWARE(void);
   virtual void set_DocTDONOR_NAME_REM_SHARDWARE(TFIBWideStringField * DocTDONOR_NAME_REM_SHARDWARE);

   virtual TFIBIntegerField * get_DocTDONOR_CODE_REM_SHARDWARE(void);
   virtual void set_DocTDONOR_CODE_REM_SHARDWARE(TFIBIntegerField * DocTDONOR_CODE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocTDONOR_SERNUM_REM_SHARDWARE(void);
   virtual void set_DocTDONOR_SERNUM_REM_SHARDWARE(TFIBWideStringField * DocTDONOR_SERNUM_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocTNAME_REM_STYPUSLOV(void);
   virtual void set_DocTNAME_REM_STYPUSLOV(TFIBWideStringField * DocTNAME_REM_STYPUSLOV);

   virtual TFIBWideStringField * get_DocTNAME_STNOM(void);
   virtual void set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM);

   virtual TpFIBDataSet * get_TypeNom(void);
   virtual void set_TypeNom(TpFIBDataSet * TypeNom);

   virtual TFIBLargeIntField * get_TypeNomID_STNOM(void);
   virtual void set_TypeNomID_STNOM(TFIBLargeIntField * TypeNomID_STNOM);

   virtual TFIBWideStringField * get_TypeNomNAME_STNOM(void);
   virtual void set_TypeNomNAME_STNOM(TFIBWideStringField * TypeNomNAME_STNOM);

   virtual TStringField * get_DocTNAME_TYPE_NOM_LOOCUP(void);
   virtual void set_DocTNAME_TYPE_NOM_LOOCUP(TStringField * DocTNAME_TYPE_NOM_LOOCUP);

   virtual TFIBSmallIntField * get_DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR(void);
   virtual void set_DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR(TFIBSmallIntField * DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_DocTIDTVZIP_REM_DZAKTPRT(void);
   virtual void set_DocTIDTVZIP_REM_DZAKTPRT(TFIBLargeIntField * DocTIDTVZIP_REM_DZAKTPRT);

   virtual TFIBLargeIntField * get_DocTIDMHRAN_REM_DZAKTPRT(void);
   virtual void set_DocTIDMHRAN_REM_DZAKTPRT(TFIBLargeIntField * DocTIDMHRAN_REM_DZAKTPRT);

   virtual TFIBWideStringField * get_DocTNAME_SMHRAN(void);
   virtual void set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN);

   virtual TFIBWideStringField * get_DocTNAME_REM_STVZIP(void);
   virtual void set_DocTNAME_REM_STVZIP(TFIBWideStringField * DocTNAME_REM_STVZIP);

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
#define CLSID_TREM_DMDocZAktPrImpl __uuidof(TREM_DMDocZAktPrImpl)
#endif
