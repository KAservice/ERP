#ifndef UREM_DMDocVidachaHWImplH
#define UREM_DMDocVidachaHWImplH
#include "IREM_DMDocVidachaHW.h"
#include "UREM_DMDocVidachaHW.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocVidachaHWImpl)) TREM_DMDocVidachaHWImpl : public IREM_DMDocVidachaHW
{
public:
   TREM_DMDocVidachaHWImpl();
   ~TREM_DMDocVidachaHWImpl();
   TREM_DMDocVidachaHW * Object;
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

//IREM_DMDocVidachaHW
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

   virtual TFIBLargeIntField * get_DocID_REM_DVIDACHA_HW(void);
   virtual void set_DocID_REM_DVIDACHA_HW(TFIBLargeIntField * DocID_REM_DVIDACHA_HW);

   virtual TFIBLargeIntField * get_DocIDBASE_REM_DVIDACHA_HW(void);
   virtual void set_DocIDBASE_REM_DVIDACHA_HW(TFIBLargeIntField * DocIDBASE_REM_DVIDACHA_HW);

   virtual TFIBWideStringField * get_DocGID_REM_DVIDACHA_HW(void);
   virtual void set_DocGID_REM_DVIDACHA_HW(TFIBWideStringField * DocGID_REM_DVIDACHA_HW);

   virtual TFIBLargeIntField * get_DocIDDOC_REM_DVIDACHA_HW(void);
   virtual void set_DocIDDOC_REM_DVIDACHA_HW(TFIBLargeIntField * DocIDDOC_REM_DVIDACHA_HW);

   virtual TFIBWideStringField * get_DocKLIENT_NAME_REM_DVIDACHA_HW(void);
   virtual void set_DocKLIENT_NAME_REM_DVIDACHA_HW(TFIBWideStringField * DocKLIENT_NAME_REM_DVIDACHA_HW);

   virtual TFIBWideStringField * get_DocKLIENT_ADR_REM_DVIDACHA_HW(void);
   virtual void set_DocKLIENT_ADR_REM_DVIDACHA_HW(TFIBWideStringField * DocKLIENT_ADR_REM_DVIDACHA_HW);

   virtual TFIBWideStringField * get_DocKLIENT_PHONE_REM_DVIDACHA_HW(void);
   virtual void set_DocKLIENT_PHONE_REM_DVIDACHA_HW(TFIBWideStringField * DocKLIENT_PHONE_REM_DVIDACHA_HW);

   virtual TFIBWideStringField * get_DocKLIENT_PASSPORT_REM_DVIDACHA_HW(void);
   virtual void set_DocKLIENT_PASSPORT_REM_DVIDACHA_HW(TFIBWideStringField * DocKLIENT_PASSPORT_REM_DVIDACHA_HW);

   virtual TFIBWideStringField * get_DocPRIM_REM_DVIDACHA_HW(void);
   virtual void set_DocPRIM_REM_DVIDACHA_HW(TFIBWideStringField * DocPRIM_REM_DVIDACHA_HW);

   virtual TFIBLargeIntField * get_DocIDZ_REM_DVIDACHA_HW(void);
   virtual void set_DocIDZ_REM_DVIDACHA_HW(TFIBLargeIntField * DocIDZ_REM_DVIDACHA_HW);

   virtual TFIBLargeIntField * get_DocIDHW_REM_DVIDACHA_HW(void);
   virtual void set_DocIDHW_REM_DVIDACHA_HW(TFIBLargeIntField * DocIDHW_REM_DVIDACHA_HW);

   virtual TFIBLargeIntField * get_DocIDKKT_REM_DVIDACHA_HW(void);
   virtual void set_DocIDKKT_REM_DVIDACHA_HW(TFIBLargeIntField * DocIDKKT_REM_DVIDACHA_HW);

   virtual TFIBWideStringField * get_DocNAME_REM_SHARDWARE(void);
   virtual void set_DocNAME_REM_SHARDWARE(TFIBWideStringField * DocNAME_REM_SHARDWARE);

   virtual TFIBIntegerField * get_DocCODE_REM_SHARDWARE(void);
   virtual void set_DocCODE_REM_SHARDWARE(TFIBIntegerField * DocCODE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocSERNUM_REM_SHARDWARE(void);
   virtual void set_DocSERNUM_REM_SHARDWARE(TFIBWideStringField * DocSERNUM_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocSERNUM2_REM_SHARDWARE(void);
   virtual void set_DocSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocSERNUM2_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocNAME_REM_SMODEL(void);
   virtual void set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL);

   virtual TFIBWideStringField * get_DocCODE_REM_SMODEL(void);
   virtual void set_DocCODE_REM_SMODEL(TFIBWideStringField * DocCODE_REM_SMODEL);

   virtual TFIBWideStringField * get_DocCODE_REM_SPRMODEL(void);
   virtual void set_DocCODE_REM_SPRMODEL(TFIBWideStringField * DocCODE_REM_SPRMODEL);

   virtual TFIBWideStringField * get_DocNAME_REM_SPRMODEL(void);
   virtual void set_DocNAME_REM_SPRMODEL(TFIBWideStringField * DocNAME_REM_SPRMODEL);

   virtual TFIBWideStringField * get_DocNAME_REM_Z(void);
   virtual void set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z);

   virtual TFIBWideStringField * get_DocPREFIKS_NUM_REM_Z(void);
   virtual void set_DocPREFIKS_NUM_REM_Z(TFIBWideStringField * DocPREFIKS_NUM_REM_Z);

   virtual TFIBIntegerField * get_DocNUM_REM_Z(void);
   virtual void set_DocNUM_REM_Z(TFIBIntegerField * DocNUM_REM_Z);

   virtual TFIBDateTimeField * get_DocPOS_REM_Z(void);
   virtual void set_DocPOS_REM_Z(TFIBDateTimeField * DocPOS_REM_Z);

   virtual TFIBWideStringField * get_DocMODEL_REM_Z(void);
   virtual void set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z);

   virtual TFIBWideStringField * get_DocSERNUM_REM_Z(void);
   virtual void set_DocSERNUM_REM_Z(TFIBWideStringField * DocSERNUM_REM_Z);

   virtual TFIBWideStringField * get_DocSERNUM2_REM_Z(void);
   virtual void set_DocSERNUM2_REM_Z(TFIBWideStringField * DocSERNUM2_REM_Z);

   virtual TFIBLargeIntField * get_DocTID_REM_DVIDACHA_HWT(void);
   virtual void set_DocTID_REM_DVIDACHA_HWT(TFIBLargeIntField * DocTID_REM_DVIDACHA_HWT);

   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DVIDACHA_HWT(void);
   virtual void set_DocTIDBASE_REM_DVIDACHA_HWT(TFIBLargeIntField * DocTIDBASE_REM_DVIDACHA_HWT);

   virtual TFIBWideStringField * get_DocTGID_REM_DVIDACHA_HWT(void);
   virtual void set_DocTGID_REM_DVIDACHA_HWT(TFIBWideStringField * DocTGID_REM_DVIDACHA_HWT);

   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DVIDACHA_HWT(void);
   virtual void set_DocTIDDOC_REM_DVIDACHA_HWT(TFIBLargeIntField * DocTIDDOC_REM_DVIDACHA_HWT);

   virtual TFIBLargeIntField * get_DocTIDHW_REM_DVIDACHA_HWT(void);
   virtual void set_DocTIDHW_REM_DVIDACHA_HWT(TFIBLargeIntField * DocTIDHW_REM_DVIDACHA_HWT);

   virtual TFIBBCDField * get_DocTKF_REM_DVIDACHA_HWT(void);
   virtual void set_DocTKF_REM_DVIDACHA_HWT(TFIBBCDField * DocTKF_REM_DVIDACHA_HWT);

   virtual TFIBBCDField * get_DocTKOL_REM_DVIDACHA_HWT(void);
   virtual void set_DocTKOL_REM_DVIDACHA_HWT(TFIBBCDField * DocTKOL_REM_DVIDACHA_HWT);

   virtual TFIBWideStringField * get_DocTPOVREGD_REM_DVIDACHA_HWT(void);
   virtual void set_DocTPOVREGD_REM_DVIDACHA_HWT(TFIBWideStringField * DocTPOVREGD_REM_DVIDACHA_HWT);

   virtual TFIBWideStringField * get_DocTNAME_REM_SHARDWARE(void);
   virtual void set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE);

   virtual TFIBIntegerField * get_DocTCODE_REM_SHARDWARE(void);
   virtual void set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocTSERNUM_REM_SHARDWARE(void);
   virtual void set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocTSERNUM2_REM_SHARDWARE(void);
   virtual void set_DocTSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM2_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocTNAME_REM_SMODEL(void);
   virtual void set_DocTNAME_REM_SMODEL(TFIBWideStringField * DocTNAME_REM_SMODEL);

   virtual TFIBWideStringField * get_DocTCODE_REM_SMODEL(void);
   virtual void set_DocTCODE_REM_SMODEL(TFIBWideStringField * DocTCODE_REM_SMODEL);

   virtual TFIBWideStringField * get_DocTCODE_REM_SPRMODEL(void);
   virtual void set_DocTCODE_REM_SPRMODEL(TFIBWideStringField * DocTCODE_REM_SPRMODEL);

   virtual TFIBWideStringField * get_DocTNAME_REM_SPRMODEL(void);
   virtual void set_DocTNAME_REM_SPRMODEL(TFIBWideStringField * DocTNAME_REM_SPRMODEL);

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
#define CLSID_TREM_DMDocVidachaHWImpl __uuidof(TREM_DMDocVidachaHWImpl)
#endif
