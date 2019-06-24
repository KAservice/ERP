#ifndef UDMDocInvImplH
#define UDMDocInvImplH
#include "IDMDocInv.h"
#include "UDMDocInv.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocInvImpl)) TDMDocInvImpl : public IDMDocInv
{
public:
   TDMDocInvImpl();
   ~TDMDocInvImpl();
   TDMDocInv * Object;
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

//IDMDocInv
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

   virtual TFIBIntegerField * get_IBQPoGrpTNOM(void);
   virtual void set_IBQPoGrpTNOM(TFIBIntegerField * IBQPoGrpTNOM);

   virtual TFIBIntegerField * get_IBQPoGrpCODENOM(void);
   virtual void set_IBQPoGrpCODENOM(TFIBIntegerField * IBQPoGrpCODENOM);

   virtual TFIBBCDField * get_IBQPoGrpKF_INVT(void);
   virtual void set_IBQPoGrpKF_INVT(TFIBBCDField * IBQPoGrpKF_INVT);

   virtual TFIBBCDField * get_IBQPoGrpKOLUCH_INVT(void);
   virtual void set_IBQPoGrpKOLUCH_INVT(TFIBBCDField * IBQPoGrpKOLUCH_INVT);

   virtual TFIBBCDField * get_IBQPoGrpKOLFAKT_INVT(void);
   virtual void set_IBQPoGrpKOLFAKT_INVT(TFIBBCDField * IBQPoGrpKOLFAKT_INVT);

   virtual TFIBBCDField * get_IBQPoGrpPRICE_INVT(void);
   virtual void set_IBQPoGrpPRICE_INVT(TFIBBCDField * IBQPoGrpPRICE_INVT);

   virtual TFIBBCDField * get_IBQPoGrpSUMF_INVT(void);
   virtual void set_IBQPoGrpSUMF_INVT(TFIBBCDField * IBQPoGrpSUMF_INVT);

   virtual TpFIBDataSet * get_IBQ(void);
   virtual void set_IBQ(TpFIBDataSet * IBQ);

   virtual TpFIBDataSet * get_GoodsDataSet(void);
   virtual void set_GoodsDataSet(TpFIBDataSet * GoodsDataSet);

   virtual TFIBFloatField * get_GoodsDataSetSUMKOL(void);
   virtual void set_GoodsDataSetSUMKOL(TFIBFloatField * GoodsDataSetSUMKOL);

   virtual TFIBBCDField * get_GoodsDataSetRSUM(void);
   virtual void set_GoodsDataSetRSUM(TFIBBCDField * GoodsDataSetRSUM);

   virtual TFIBIntegerField * get_GoodsDataSetCODENOM(void);
   virtual void set_GoodsDataSetCODENOM(TFIBIntegerField * GoodsDataSetCODENOM);

   virtual TpFIBDataSet * get_OstatkiDataSet(void);
   virtual void set_OstatkiDataSet(TpFIBDataSet * OstatkiDataSet);

   virtual TFIBIntegerField * get_OstatkiDataSetCODENOM(void);
   virtual void set_OstatkiDataSetCODENOM(TFIBIntegerField * OstatkiDataSetCODENOM);

   virtual TFIBBCDField * get_OstatkiDataSetKFED(void);
   virtual void set_OstatkiDataSetKFED(TFIBBCDField * OstatkiDataSetKFED);

   virtual TFIBBCDField * get_OstatkiDataSetSUMKOL(void);
   virtual void set_OstatkiDataSetSUMKOL(TFIBBCDField * OstatkiDataSetSUMKOL);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBBCDField * get_DocTKF_INVT(void);
   virtual void set_DocTKF_INVT(TFIBBCDField * DocTKF_INVT);

   virtual TFIBBCDField * get_DocTKOLUCH_INVT(void);
   virtual void set_DocTKOLUCH_INVT(TFIBBCDField * DocTKOLUCH_INVT);

   virtual TFIBBCDField * get_DocTKOLFAKT_INVT(void);
   virtual void set_DocTKOLFAKT_INVT(TFIBBCDField * DocTKOLFAKT_INVT);

   virtual TFIBBCDField * get_DocTPRICE_INVT(void);
   virtual void set_DocTPRICE_INVT(TFIBBCDField * DocTPRICE_INVT);

   virtual TFIBBCDField * get_DocTSUMF_INVT(void);
   virtual void set_DocTSUMF_INVT(TFIBBCDField * DocTSUMF_INVT);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBBCDField * get_GoodsDataSetIDNOM_DREVT(void);
   virtual void set_GoodsDataSetIDNOM_DREVT(TFIBBCDField * GoodsDataSetIDNOM_DREVT);

   virtual TFIBBCDField * get_GoodsDataSetIDED_DREVT(void);
   virtual void set_GoodsDataSetIDED_DREVT(TFIBBCDField * GoodsDataSetIDED_DREVT);

   virtual TFIBBCDField * get_OstatkiDataSetIDNOM(void);
   virtual void set_OstatkiDataSetIDNOM(TFIBBCDField * OstatkiDataSetIDNOM);

   virtual TFIBBCDField * get_OstatkiDataSetIDED(void);
   virtual void set_OstatkiDataSetIDED(TFIBBCDField * OstatkiDataSetIDED);

   virtual TFIBBCDField * get_IBQPoGrpIDGN(void);
   virtual void set_IBQPoGrpIDGN(TFIBBCDField * IBQPoGrpIDGN);

   virtual TFIBBCDField * get_IBQPoGrpID_INVT(void);
   virtual void set_IBQPoGrpID_INVT(TFIBBCDField * IBQPoGrpID_INVT);

   virtual TFIBBCDField * get_IBQPoGrpIDDOC_INVT(void);
   virtual void set_IBQPoGrpIDDOC_INVT(TFIBBCDField * IBQPoGrpIDDOC_INVT);

   virtual TFIBBCDField * get_IBQPoGrpIDNOM_INVT(void);
   virtual void set_IBQPoGrpIDNOM_INVT(TFIBBCDField * IBQPoGrpIDNOM_INVT);

   virtual TFIBBCDField * get_IBQPoGrpIDED_INVT(void);
   virtual void set_IBQPoGrpIDED_INVT(TFIBBCDField * IBQPoGrpIDED_INVT);

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

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBLargeIntField * get_DocID_INV(void);
   virtual void set_DocID_INV(TFIBLargeIntField * DocID_INV);

   virtual TFIBLargeIntField * get_DocIDDOC_INV(void);
   virtual void set_DocIDDOC_INV(TFIBLargeIntField * DocIDDOC_INV);

   virtual TFIBWideStringField * get_DocPRIM_INV(void);
   virtual void set_DocPRIM_INV(TFIBWideStringField * DocPRIM_INV);

   virtual TFIBWideStringField * get_DocGID_INV(void);
   virtual void set_DocGID_INV(TFIBWideStringField * DocGID_INV);

   virtual TFIBLargeIntField * get_DocIDTPRICE_INV(void);
   virtual void set_DocIDTPRICE_INV(TFIBLargeIntField * DocIDTPRICE_INV);

   virtual TFIBLargeIntField * get_DocIDINV_INV(void);
   virtual void set_DocIDINV_INV(TFIBLargeIntField * DocIDINV_INV);

   virtual TFIBIntegerField * get_DocTYPE_INV(void);
   virtual void set_DocTYPE_INV(TFIBIntegerField * DocTYPE_INV);

   virtual TFIBLargeIntField * get_DocIDBASE_DINV(void);
   virtual void set_DocIDBASE_DINV(TFIBLargeIntField * DocIDBASE_DINV);

   virtual TFIBWideStringField * get_DocNAME_SINV(void);
   virtual void set_DocNAME_SINV(TFIBWideStringField * DocNAME_SINV);

   virtual TFIBWideStringField * get_DocTNAMEGN(void);
   virtual void set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN);

   virtual TFIBLargeIntField * get_DocTIDGN(void);
   virtual void set_DocTIDGN(TFIBLargeIntField * DocTIDGN);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBIntegerField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM);

   virtual TFIBLargeIntField * get_DocTID_INVT(void);
   virtual void set_DocTID_INVT(TFIBLargeIntField * DocTID_INVT);

   virtual TFIBLargeIntField * get_DocTIDDOC_INVT(void);
   virtual void set_DocTIDDOC_INVT(TFIBLargeIntField * DocTIDDOC_INVT);

   virtual TFIBLargeIntField * get_DocTIDNOM_INVT(void);
   virtual void set_DocTIDNOM_INVT(TFIBLargeIntField * DocTIDNOM_INVT);

   virtual TFIBLargeIntField * get_DocTIDED_INVT(void);
   virtual void set_DocTIDED_INVT(TFIBLargeIntField * DocTIDED_INVT);

   virtual TFIBWideStringField * get_DocTGID_INVT(void);
   virtual void set_DocTGID_INVT(TFIBWideStringField * DocTGID_INVT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DINVT(void);
   virtual void set_DocTIDBASE_DINVT(TFIBLargeIntField * DocTIDBASE_DINVT);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocAllFNAMEFIRM(void);
   virtual void set_DocAllFNAMEFIRM(TFIBWideStringField * DocAllFNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllINNFIRM(void);
   virtual void set_DocAllINNFIRM(TFIBWideStringField * DocAllINNFIRM);

   virtual TFIBWideStringField * get_DocAllPADRFIRM(void);
   virtual void set_DocAllPADRFIRM(TFIBWideStringField * DocAllPADRFIRM);

   virtual TFIBWideStringField * get_IBQPoGrpNAMEGN(void);
   virtual void set_IBQPoGrpNAMEGN(TFIBWideStringField * IBQPoGrpNAMEGN);

   virtual TFIBWideStringField * get_IBQPoGrpNAMENOM(void);
   virtual void set_IBQPoGrpNAMENOM(TFIBWideStringField * IBQPoGrpNAMENOM);

   virtual TFIBWideStringField * get_IBQPoGrpNAMEED(void);
   virtual void set_IBQPoGrpNAMEED(TFIBWideStringField * IBQPoGrpNAMEED);

   virtual TFIBWideStringField * get_GoodsDataSetNAMENOM(void);
   virtual void set_GoodsDataSetNAMENOM(TFIBWideStringField * GoodsDataSetNAMENOM);

   virtual TFIBWideStringField * get_GoodsDataSetNAMEED(void);
   virtual void set_GoodsDataSetNAMEED(TFIBWideStringField * GoodsDataSetNAMEED);

   virtual TFIBWideStringField * get_OstatkiDataSetNAMENOM(void);
   virtual void set_OstatkiDataSetNAMENOM(TFIBWideStringField * OstatkiDataSetNAMENOM);

   virtual TFIBWideStringField * get_OstatkiDataSetNAMEED(void);
   virtual void set_OstatkiDataSetNAMEED(TFIBWideStringField * OstatkiDataSetNAMEED);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

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

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElementaMaster(void);
   virtual void set_IdElementaMaster(__int64 IdElementaMaster);

   virtual __int64 get_IdGrpNom(void);
   virtual void set_IdGrpNom(__int64 IdGrpNom);

   virtual bool get_ChangeTable(void);
   virtual void set_ChangeTable(bool ChangeTable);

   virtual bool get_ErrorRaschet(void);
   virtual void set_ErrorRaschet(bool ErrorRaschet);

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
   virtual void AddDataRev(void);
   virtual bool SearchStringPoNom(__int64 id_nom);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocInvImpl __uuidof(TDMDocInvImpl)
#endif
