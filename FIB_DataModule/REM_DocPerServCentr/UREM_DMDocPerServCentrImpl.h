#ifndef UREM_DMDocPerServCentrImplH
#define UREM_DMDocPerServCentrImplH
#include "IREM_DMDocPerServCentr.h"
#include "UREM_DMDocPerServCentr.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocPerServCentrImpl)) TREM_DMDocPerServCentrImpl : public IREM_DMDocPerServCentr
{
public:
   TREM_DMDocPerServCentrImpl();
   ~TREM_DMDocPerServCentrImpl();
   TREM_DMDocPerServCentr * Object;
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

//IREM_DMDocPerServCentr
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

   virtual TFIBLargeIntField * get_DocID_REM_DSCPER(void);
   virtual void set_DocID_REM_DSCPER(TFIBLargeIntField * DocID_REM_DSCPER);

   virtual TFIBLargeIntField * get_DocIDBASE_REM_DSCPER(void);
   virtual void set_DocIDBASE_REM_DSCPER(TFIBLargeIntField * DocIDBASE_REM_DSCPER);

   virtual TFIBWideStringField * get_DocGID_REM_DSCPER(void);
   virtual void set_DocGID_REM_DSCPER(TFIBWideStringField * DocGID_REM_DSCPER);

   virtual TFIBLargeIntField * get_DocIDDOC_REM_DSCPER(void);
   virtual void set_DocIDDOC_REM_DSCPER(TFIBLargeIntField * DocIDDOC_REM_DSCPER);

   virtual TFIBWideStringField * get_DocNUMDOCSC_REM_DSCPER(void);
   virtual void set_DocNUMDOCSC_REM_DSCPER(TFIBWideStringField * DocNUMDOCSC_REM_DSCPER);

   virtual TFIBDateTimeField * get_DocPOSDOCSC_REM_DSCPER(void);
   virtual void set_DocPOSDOCSC_REM_DSCPER(TFIBDateTimeField * DocPOSDOCSC_REM_DSCPER);

   virtual TFIBWideStringField * get_DocPRIM_REM_DSCPER(void);
   virtual void set_DocPRIM_REM_DSCPER(TFIBWideStringField * DocPRIM_REM_DSCPER);

   virtual TFIBLargeIntField * get_DocTID_REM_DSCPERT(void);
   virtual void set_DocTID_REM_DSCPERT(TFIBLargeIntField * DocTID_REM_DSCPERT);

   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DSCPERT(void);
   virtual void set_DocTIDBASE_REM_DSCPERT(TFIBLargeIntField * DocTIDBASE_REM_DSCPERT);

   virtual TFIBWideStringField * get_DocTGID_REM_DSCPERT(void);
   virtual void set_DocTGID_REM_DSCPERT(TFIBWideStringField * DocTGID_REM_DSCPERT);

   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DSCPERT(void);
   virtual void set_DocTIDDOC_REM_DSCPERT(TFIBLargeIntField * DocTIDDOC_REM_DSCPERT);

   virtual TFIBLargeIntField * get_DocTIDZ_REM_DSCPERT(void);
   virtual void set_DocTIDZ_REM_DSCPERT(TFIBLargeIntField * DocTIDZ_REM_DSCPERT);

   virtual TFIBBCDField * get_DocTKOL_REM_DSCPERT(void);
   virtual void set_DocTKOL_REM_DSCPERT(TFIBBCDField * DocTKOL_REM_DSCPERT);

   virtual TFIBWideStringField * get_DocTNAME_REM_Z(void);
   virtual void set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z);

   virtual TFIBIntegerField * get_DocTNUM_REM_Z(void);
   virtual void set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z);

   virtual TFIBDateTimeField * get_DocTPOS_REM_Z(void);
   virtual void set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z);

   virtual TFIBWideStringField * get_DocTSERNUM_REM_Z(void);
   virtual void set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z);

   virtual TFIBWideStringField * get_DocTSERNUM2_REM_Z(void);
   virtual void set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z);

   virtual TFIBWideStringField * get_DocTKLIENT_NAME_REM_Z(void);
   virtual void set_DocTKLIENT_NAME_REM_Z(TFIBWideStringField * DocTKLIENT_NAME_REM_Z);

   virtual TFIBWideStringField * get_DocTMODEL_REM_Z(void);
   virtual void set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z);

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
#define CLSID_TREM_DMDocPerServCentrImpl __uuidof(TREM_DMDocPerServCentrImpl)
#endif
