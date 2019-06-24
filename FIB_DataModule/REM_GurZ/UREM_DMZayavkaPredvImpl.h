#ifndef UREM_DMZayavkaPredvImplH
#define UREM_DMZayavkaPredvImplH
#include "IREM_DMZayavkaPredv.h"
#include "UREM_DMZayavkaPredv.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMZayavkaPredvImpl)) TREM_DMZayavkaPredvImpl : public IREM_DMZayavkaPredv
{
public:
   TREM_DMZayavkaPredvImpl();
   ~TREM_DMZayavkaPredvImpl();
   TREM_DMZayavkaPredv * Object;
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

//IREM_DMZayavkaPredv
   virtual TDataSource * get_DataSourceGurZ(void);
   virtual void set_DataSourceGurZ(TDataSource * DataSourceGurZ);

   virtual TpFIBDataSet * get_GurZ(void);
   virtual void set_GurZ(TpFIBDataSet * GurZ);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TFIBLargeIntField * get_GurZID_REM_Z2(void);
   virtual void set_GurZID_REM_Z2(TFIBLargeIntField * GurZID_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDBASE_REM_Z2(void);
   virtual void set_GurZIDBASE_REM_Z2(TFIBLargeIntField * GurZIDBASE_REM_Z2);

   virtual TFIBWideStringField * get_GurZPREFIKS_REM_Z2(void);
   virtual void set_GurZPREFIKS_REM_Z2(TFIBWideStringField * GurZPREFIKS_REM_Z2);

   virtual TFIBIntegerField * get_GurZNUM_REM_Z2(void);
   virtual void set_GurZNUM_REM_Z2(TFIBIntegerField * GurZNUM_REM_Z2);

   virtual TFIBWideStringField * get_GurZGUID_REM_Z2(void);
   virtual void set_GurZGUID_REM_Z2(TFIBWideStringField * GurZGUID_REM_Z2);

   virtual TFIBDateTimeField * get_GurZPOS_REM_Z2(void);
   virtual void set_GurZPOS_REM_Z2(TFIBDateTimeField * GurZPOS_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDMODEL_REM_Z2(void);
   virtual void set_GurZIDMODEL_REM_Z2(TFIBLargeIntField * GurZIDMODEL_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDPRMODEL_REM_Z2(void);
   virtual void set_GurZIDPRMODEL_REM_Z2(TFIBLargeIntField * GurZIDPRMODEL_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDFIRM_REM_Z2(void);
   virtual void set_GurZIDFIRM_REM_Z2(TFIBLargeIntField * GurZIDFIRM_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDSKLPR_REM_Z2(void);
   virtual void set_GurZIDSKLPR_REM_Z2(TFIBLargeIntField * GurZIDSKLPR_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDKLIENT_REM_Z2(void);
   virtual void set_GurZIDKLIENT_REM_Z2(TFIBLargeIntField * GurZIDKLIENT_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDDILER_REM_Z2(void);
   virtual void set_GurZIDDILER_REM_Z2(TFIBLargeIntField * GurZIDDILER_REM_Z2);

   virtual TFIBWideStringField * get_GurZNAME_REM_Z2(void);
   virtual void set_GurZNAME_REM_Z2(TFIBWideStringField * GurZNAME_REM_Z2);

   virtual TFIBWideStringField * get_GurZDESCR_REM_Z2(void);
   virtual void set_GurZDESCR_REM_Z2(TFIBWideStringField * GurZDESCR_REM_Z2);

   virtual TFIBWideStringField * get_GurZKLIENT_NAME_REM_Z2(void);
   virtual void set_GurZKLIENT_NAME_REM_Z2(TFIBWideStringField * GurZKLIENT_NAME_REM_Z2);

   virtual TFIBWideStringField * get_GurZKLIENT_ADR_REM_Z2(void);
   virtual void set_GurZKLIENT_ADR_REM_Z2(TFIBWideStringField * GurZKLIENT_ADR_REM_Z2);

   virtual TFIBWideStringField * get_GurZKLIENT_PHONE_REM_Z2(void);
   virtual void set_GurZKLIENT_PHONE_REM_Z2(TFIBWideStringField * GurZKLIENT_PHONE_REM_Z2);

   virtual TFIBWideStringField * get_GurZKLIENT_EMAIL_REM_Z2(void);
   virtual void set_GurZKLIENT_EMAIL_REM_Z2(TFIBWideStringField * GurZKLIENT_EMAIL_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDBRAND_REM_Z2(void);
   virtual void set_GurZIDBRAND_REM_Z2(TFIBLargeIntField * GurZIDBRAND_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDPRODUCER_REM_Z2(void);
   virtual void set_GurZIDPRODUCER_REM_Z2(TFIBLargeIntField * GurZIDPRODUCER_REM_Z2);

   virtual TFIBWideStringField * get_GurZNEISPR_REM_Z2(void);
   virtual void set_GurZNEISPR_REM_Z2(TFIBWideStringField * GurZNEISPR_REM_Z2);

   virtual TFIBWideStringField * get_GurZSOST_REM_Z2(void);
   virtual void set_GurZSOST_REM_Z2(TFIBWideStringField * GurZSOST_REM_Z2);

   virtual TFIBWideStringField * get_GurZMODEL_STR_REM_Z2(void);
   virtual void set_GurZMODEL_STR_REM_Z2(TFIBWideStringField * GurZMODEL_STR_REM_Z2);

   virtual TFIBWideStringField * get_GurZSERNUM1_REM_Z2(void);
   virtual void set_GurZSERNUM1_REM_Z2(TFIBWideStringField * GurZSERNUM1_REM_Z2);

   virtual TFIBWideStringField * get_GurZSERNUM2_REM_Z2(void);
   virtual void set_GurZSERNUM2_REM_Z2(TFIBWideStringField * GurZSERNUM2_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDKKT_REM_Z2(void);
   virtual void set_GurZIDKKT_REM_Z2(TFIBLargeIntField * GurZIDKKT_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDHW_REM_Z2(void);
   virtual void set_GurZIDHW_REM_Z2(TFIBLargeIntField * GurZIDHW_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDSELLER_REM_Z2(void);
   virtual void set_GurZIDSELLER_REM_Z2(TFIBLargeIntField * GurZIDSELLER_REM_Z2);

   virtual TFIBWideStringField * get_GurZDOPOPISANIE_REM_Z2(void);
   virtual void set_GurZDOPOPISANIE_REM_Z2(TFIBWideStringField * GurZDOPOPISANIE_REM_Z2);

   virtual TFIBBCDField * get_GurZSUMKLIENTA_REM_Z2(void);
   virtual void set_GurZSUMKLIENTA_REM_Z2(TFIBBCDField * GurZSUMKLIENTA_REM_Z2);

   virtual TFIBBCDField * get_GurZSUMNACHA_REM_Z2(void);
   virtual void set_GurZSUMNACHA_REM_Z2(TFIBBCDField * GurZSUMNACHA_REM_Z2);

   virtual TFIBIntegerField * get_GurZRESULT_REM_Z2(void);
   virtual void set_GurZRESULT_REM_Z2(TFIBIntegerField * GurZRESULT_REM_Z2);

   virtual TFIBWideStringField * get_GurZPRICHINA_REM_Z2(void);
   virtual void set_GurZPRICHINA_REM_Z2(TFIBWideStringField * GurZPRICHINA_REM_Z2);

   virtual TFIBIntegerField * get_GurZPRICHINA_LIST_REM_Z2(void);
   virtual void set_GurZPRICHINA_LIST_REM_Z2(TFIBIntegerField * GurZPRICHINA_LIST_REM_Z2);

   virtual TFIBIntegerField * get_GurZSROK_REM_Z2(void);
   virtual void set_GurZSROK_REM_Z2(TFIBIntegerField * GurZSROK_REM_Z2);

   virtual TFIBLargeIntField * get_GurZIDUSER_REM_Z2(void);
   virtual void set_GurZIDUSER_REM_Z2(TFIBLargeIntField * GurZIDUSER_REM_Z2);

   virtual TFIBWideStringField * get_GurZNAMEFIRM(void);
   virtual void set_GurZNAMEFIRM(TFIBWideStringField * GurZNAMEFIRM);

   virtual TFIBWideStringField * get_GurZNAME_SINFBASE_OBMEN(void);
   virtual void set_GurZNAME_SINFBASE_OBMEN(TFIBWideStringField * GurZNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_GurZNAME_REM_SMODEL(void);
   virtual void set_GurZNAME_REM_SMODEL(TFIBWideStringField * GurZNAME_REM_SMODEL);

   virtual TFIBWideStringField * get_GurZNAME_SKLAD_PR(void);
   virtual void set_GurZNAME_SKLAD_PR(TFIBWideStringField * GurZNAME_SKLAD_PR);

   virtual TFIBWideStringField * get_GurZNAMEKLIENT(void);
   virtual void set_GurZNAMEKLIENT(TFIBWideStringField * GurZNAMEKLIENT);

   virtual TFIBWideStringField * get_GurZNAMEDILER(void);
   virtual void set_GurZNAMEDILER(TFIBWideStringField * GurZNAMEDILER);

   virtual TFIBWideStringField * get_GurZNAME_USER(void);
   virtual void set_GurZNAME_USER(TFIBWideStringField * GurZNAME_USER);

   virtual TFIBWideStringField * get_GurZNAME_SBRAND(void);
   virtual void set_GurZNAME_SBRAND(TFIBWideStringField * GurZNAME_SBRAND);

   virtual TFIBWideStringField * get_GurZNAME_REM_SHARDWARE(void);
   virtual void set_GurZNAME_REM_SHARDWARE(TFIBWideStringField * GurZNAME_REM_SHARDWARE);

   virtual TFIBWideStringField * get_GurZSERNUM_REM_SHARDWARE(void);
   virtual void set_GurZSERNUM_REM_SHARDWARE(TFIBWideStringField * GurZSERNUM_REM_SHARDWARE);

   virtual TFIBWideStringField * get_GurZSERNUM2_REM_SHARDWARE(void);
   virtual void set_GurZSERNUM2_REM_SHARDWARE(TFIBWideStringField * GurZSERNUM2_REM_SHARDWARE);

   virtual TFIBWideStringField * get_GurZNAME_REM_SKKT(void);
   virtual void set_GurZNAME_REM_SKKT(TFIBWideStringField * GurZNAME_REM_SKKT);

   virtual TFIBWideStringField * get_GurZSERNUM_REM_SKKT(void);
   virtual void set_GurZSERNUM_REM_SKKT(TFIBWideStringField * GurZSERNUM_REM_SKKT);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdZ(void);
   virtual void set_IdZ(__int64 IdZ);

   virtual bool get_flChangeData(void);
   virtual void set_flChangeData(bool flChangeData);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 id);
   virtual bool SaveDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual void CloseDoc(void);
};
#define CLSID_TREM_DMZayavkaPredvImpl __uuidof(TREM_DMZayavkaPredvImpl)
#endif
