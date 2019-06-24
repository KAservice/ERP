#ifndef UREM_DMDocOstNomImplH
#define UREM_DMDocOstNomImplH
#include "IREM_DMDocOstNom.h"
#include "UREM_DMDocOstNom.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocOstNomImpl)) TREM_DMDocOstNomImpl : public IREM_DMDocOstNom
{
public:
   TREM_DMDocOstNomImpl();
   ~TREM_DMDocOstNomImpl();
   TREM_DMDocOstNom * Object;
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

//IREM_DMDocOstNom
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

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void);
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER);

   virtual TpFIBDataSet * get_DocOsn(void);
   virtual void set_DocOsn(TpFIBDataSet * DocOsn);

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

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_DocID_REM_DOSN(void);
   virtual void set_DocID_REM_DOSN(TFIBLargeIntField * DocID_REM_DOSN);

   virtual TFIBLargeIntField * get_DocIDBASE_REM_DOSN(void);
   virtual void set_DocIDBASE_REM_DOSN(TFIBLargeIntField * DocIDBASE_REM_DOSN);

   virtual TFIBLargeIntField * get_DocIDDOC_REM_DOSN(void);
   virtual void set_DocIDDOC_REM_DOSN(TFIBLargeIntField * DocIDDOC_REM_DOSN);

   virtual TFIBWideStringField * get_DocGID_REM_DOSN(void);
   virtual void set_DocGID_REM_DOSN(TFIBWideStringField * DocGID_REM_DOSN);

   virtual TFIBLargeIntField * get_DocIDTPRICE_REM_DOSN(void);
   virtual void set_DocIDTPRICE_REM_DOSN(TFIBLargeIntField * DocIDTPRICE_REM_DOSN);

   virtual TFIBLargeIntField * get_DocIDRTPRICE_REM_DOSN(void);
   virtual void set_DocIDRTPRICE_REM_DOSN(TFIBLargeIntField * DocIDRTPRICE_REM_DOSN);

   virtual TFIBBCDField * get_DocRSUM_REM_DOSN(void);
   virtual void set_DocRSUM_REM_DOSN(TFIBBCDField * DocRSUM_REM_DOSN);

   virtual TFIBWideStringField * get_DocPRIM_REM_DOSN(void);
   virtual void set_DocPRIM_REM_DOSN(TFIBWideStringField * DocPRIM_REM_DOSN);

   virtual TDataSource * get_DataSourceDocOsn(void);
   virtual void set_DataSourceDocOsn(TDataSource * DataSourceDocOsn);

   virtual TFIBLargeIntField * get_DocTID_REM_DOSNT(void);
   virtual void set_DocTID_REM_DOSNT(TFIBLargeIntField * DocTID_REM_DOSNT);

   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DOSNT(void);
   virtual void set_DocTIDBASE_REM_DOSNT(TFIBLargeIntField * DocTIDBASE_REM_DOSNT);

   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DOSNT(void);
   virtual void set_DocTIDDOC_REM_DOSNT(TFIBLargeIntField * DocTIDDOC_REM_DOSNT);

   virtual TFIBWideStringField * get_DocTGID_REM_DOSNT(void);
   virtual void set_DocTGID_REM_DOSNT(TFIBWideStringField * DocTGID_REM_DOSNT);

   virtual TFIBLargeIntField * get_DocTIDNOM_REM_DOSNT(void);
   virtual void set_DocTIDNOM_REM_DOSNT(TFIBLargeIntField * DocTIDNOM_REM_DOSNT);

   virtual TFIBLargeIntField * get_DocTIDED_REM_DOSNT(void);
   virtual void set_DocTIDED_REM_DOSNT(TFIBLargeIntField * DocTIDED_REM_DOSNT);

   virtual TFIBLargeIntField * get_DocTIDHW_REM_DOSNT(void);
   virtual void set_DocTIDHW_REM_DOSNT(TFIBLargeIntField * DocTIDHW_REM_DOSNT);

   virtual TFIBBCDField * get_DocTKOL_REM_DOSNT(void);
   virtual void set_DocTKOL_REM_DOSNT(TFIBBCDField * DocTKOL_REM_DOSNT);

   virtual TFIBBCDField * get_DocTKF_REM_DOSNT(void);
   virtual void set_DocTKF_REM_DOSNT(TFIBBCDField * DocTKF_REM_DOSNT);

   virtual TFIBBCDField * get_DocTPRICE_REM_DOSNT(void);
   virtual void set_DocTPRICE_REM_DOSNT(TFIBBCDField * DocTPRICE_REM_DOSNT);

   virtual TFIBBCDField * get_DocTSUM_REM_DOSNT(void);
   virtual void set_DocTSUM_REM_DOSNT(TFIBBCDField * DocTSUM_REM_DOSNT);

   virtual TFIBBCDField * get_DocTRPRICE_REM_DOSNT(void);
   virtual void set_DocTRPRICE_REM_DOSNT(TFIBBCDField * DocTRPRICE_REM_DOSNT);

   virtual TFIBBCDField * get_DocTRSUM_REM_DOSNT(void);
   virtual void set_DocTRSUM_REM_DOSNT(TFIBBCDField * DocTRSUM_REM_DOSNT);

   virtual TFIBIntegerField * get_DocTNDS_REM_DOSNT(void);
   virtual void set_DocTNDS_REM_DOSNT(TFIBIntegerField * DocTNDS_REM_DOSNT);

   virtual TFIBBCDField * get_DocTSUMNDS_REM_DOSNT(void);
   virtual void set_DocTSUMNDS_REM_DOSNT(TFIBBCDField * DocTSUMNDS_REM_DOSNT);

   virtual TFIBSmallIntField * get_DocTDVREG_REM_DOSNT(void);
   virtual void set_DocTDVREG_REM_DOSNT(TFIBSmallIntField * DocTDVREG_REM_DOSNT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual TFIBWideStringField * get_DocTNAME_REM_SHARDWARE(void);
   virtual void set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE);

   virtual TFIBIntegerField * get_DocTCODE_REM_SHARDWARE(void);
   virtual void set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocTSERNUM_REM_SHARDWARE(void);
   virtual void set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocOsnTDOC_REM_GALLDOC(void);
   virtual void set_DocOsnTDOC_REM_GALLDOC(TFIBWideStringField * DocOsnTDOC_REM_GALLDOC);

   virtual TFIBIntegerField * get_DocOsnNUM_REM_GALLDOC(void);
   virtual void set_DocOsnNUM_REM_GALLDOC(TFIBIntegerField * DocOsnNUM_REM_GALLDOC);

   virtual TFIBDateTimeField * get_DocOsnPOS_REM_GALLDOC(void);
   virtual void set_DocOsnPOS_REM_GALLDOC(TFIBDateTimeField * DocOsnPOS_REM_GALLDOC);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDOBJECT_REM_GALLDOC(void);
   virtual void set_DocAllIDOBJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SOBJECT(void);
   virtual void set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT);

   virtual TpFIBDataSet * get_TypeNom(void);
   virtual void set_TypeNom(TpFIBDataSet * TypeNom);

   virtual TFIBLargeIntField * get_TypeNomID_STNOM(void);
   virtual void set_TypeNomID_STNOM(TFIBLargeIntField * TypeNomID_STNOM);

   virtual TFIBWideStringField * get_TypeNomNAME_STNOM(void);
   virtual void set_TypeNomNAME_STNOM(TFIBWideStringField * TypeNomNAME_STNOM);

   virtual TFIBLargeIntField * get_DocTIDTNOM_REM_DOSNT(void);
   virtual void set_DocTIDTNOM_REM_DOSNT(TFIBLargeIntField * DocTIDTNOM_REM_DOSNT);

   virtual TStringField * get_DocTNAME_TYPE_NOM_LOOCUP(void);
   virtual void set_DocTNAME_TYPE_NOM_LOOCUP(TStringField * DocTNAME_TYPE_NOM_LOOCUP);

   virtual TFIBLargeIntField * get_DocTIDMHRAN_REM_DOSNT(void);
   virtual void set_DocTIDMHRAN_REM_DOSNT(TFIBLargeIntField * DocTIDMHRAN_REM_DOSNT);

   virtual TFIBWideStringField * get_DocTNAME_SMHRAN(void);
   virtual void set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElementaMaster(void);
   virtual void set_IdElementaMaster(__int64 IdElementaMaster);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 id_doc);
   virtual bool SaveDoc(void);
   virtual void CloseDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual bool DeleteDoc(__int64 id);
};
#define CLSID_TREM_DMDocOstNomImpl __uuidof(TREM_DMDocOstNomImpl)
#endif
