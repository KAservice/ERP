#ifndef UIREM_DMZayavkaPredvH
#define UIREM_DMZayavkaPredvH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMZayavkaPredv)) IREM_DMZayavkaPredv : public IMainInterface
{
public:
   __property TDataSource * DataSourceGurZ = {read = get_DataSourceGurZ , write = set_DataSourceGurZ};
   virtual TDataSource * get_DataSourceGurZ(void)=0;
   virtual void set_DataSourceGurZ(TDataSource * DataSourceGurZ)=0;

   __property TpFIBDataSet * GurZ = {read = get_GurZ , write = set_GurZ};
   virtual TpFIBDataSet * get_GurZ(void)=0;
   virtual void set_GurZ(TpFIBDataSet * GurZ)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TFIBLargeIntField * GurZID_REM_Z2 = {read = get_GurZID_REM_Z2 , write = set_GurZID_REM_Z2};
   virtual TFIBLargeIntField * get_GurZID_REM_Z2(void)=0;
   virtual void set_GurZID_REM_Z2(TFIBLargeIntField * GurZID_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDBASE_REM_Z2 = {read = get_GurZIDBASE_REM_Z2 , write = set_GurZIDBASE_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDBASE_REM_Z2(void)=0;
   virtual void set_GurZIDBASE_REM_Z2(TFIBLargeIntField * GurZIDBASE_REM_Z2)=0;

   __property TFIBWideStringField * GurZPREFIKS_REM_Z2 = {read = get_GurZPREFIKS_REM_Z2 , write = set_GurZPREFIKS_REM_Z2};
   virtual TFIBWideStringField * get_GurZPREFIKS_REM_Z2(void)=0;
   virtual void set_GurZPREFIKS_REM_Z2(TFIBWideStringField * GurZPREFIKS_REM_Z2)=0;

   __property TFIBIntegerField * GurZNUM_REM_Z2 = {read = get_GurZNUM_REM_Z2 , write = set_GurZNUM_REM_Z2};
   virtual TFIBIntegerField * get_GurZNUM_REM_Z2(void)=0;
   virtual void set_GurZNUM_REM_Z2(TFIBIntegerField * GurZNUM_REM_Z2)=0;

   __property TFIBWideStringField * GurZGUID_REM_Z2 = {read = get_GurZGUID_REM_Z2 , write = set_GurZGUID_REM_Z2};
   virtual TFIBWideStringField * get_GurZGUID_REM_Z2(void)=0;
   virtual void set_GurZGUID_REM_Z2(TFIBWideStringField * GurZGUID_REM_Z2)=0;

   __property TFIBDateTimeField * GurZPOS_REM_Z2 = {read = get_GurZPOS_REM_Z2 , write = set_GurZPOS_REM_Z2};
   virtual TFIBDateTimeField * get_GurZPOS_REM_Z2(void)=0;
   virtual void set_GurZPOS_REM_Z2(TFIBDateTimeField * GurZPOS_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDMODEL_REM_Z2 = {read = get_GurZIDMODEL_REM_Z2 , write = set_GurZIDMODEL_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDMODEL_REM_Z2(void)=0;
   virtual void set_GurZIDMODEL_REM_Z2(TFIBLargeIntField * GurZIDMODEL_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDPRMODEL_REM_Z2 = {read = get_GurZIDPRMODEL_REM_Z2 , write = set_GurZIDPRMODEL_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDPRMODEL_REM_Z2(void)=0;
   virtual void set_GurZIDPRMODEL_REM_Z2(TFIBLargeIntField * GurZIDPRMODEL_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDFIRM_REM_Z2 = {read = get_GurZIDFIRM_REM_Z2 , write = set_GurZIDFIRM_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDFIRM_REM_Z2(void)=0;
   virtual void set_GurZIDFIRM_REM_Z2(TFIBLargeIntField * GurZIDFIRM_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDSKLPR_REM_Z2 = {read = get_GurZIDSKLPR_REM_Z2 , write = set_GurZIDSKLPR_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDSKLPR_REM_Z2(void)=0;
   virtual void set_GurZIDSKLPR_REM_Z2(TFIBLargeIntField * GurZIDSKLPR_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDKLIENT_REM_Z2 = {read = get_GurZIDKLIENT_REM_Z2 , write = set_GurZIDKLIENT_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDKLIENT_REM_Z2(void)=0;
   virtual void set_GurZIDKLIENT_REM_Z2(TFIBLargeIntField * GurZIDKLIENT_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDDILER_REM_Z2 = {read = get_GurZIDDILER_REM_Z2 , write = set_GurZIDDILER_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDDILER_REM_Z2(void)=0;
   virtual void set_GurZIDDILER_REM_Z2(TFIBLargeIntField * GurZIDDILER_REM_Z2)=0;

   __property TFIBWideStringField * GurZNAME_REM_Z2 = {read = get_GurZNAME_REM_Z2 , write = set_GurZNAME_REM_Z2};
   virtual TFIBWideStringField * get_GurZNAME_REM_Z2(void)=0;
   virtual void set_GurZNAME_REM_Z2(TFIBWideStringField * GurZNAME_REM_Z2)=0;

   __property TFIBWideStringField * GurZDESCR_REM_Z2 = {read = get_GurZDESCR_REM_Z2 , write = set_GurZDESCR_REM_Z2};
   virtual TFIBWideStringField * get_GurZDESCR_REM_Z2(void)=0;
   virtual void set_GurZDESCR_REM_Z2(TFIBWideStringField * GurZDESCR_REM_Z2)=0;

   __property TFIBWideStringField * GurZKLIENT_NAME_REM_Z2 = {read = get_GurZKLIENT_NAME_REM_Z2 , write = set_GurZKLIENT_NAME_REM_Z2};
   virtual TFIBWideStringField * get_GurZKLIENT_NAME_REM_Z2(void)=0;
   virtual void set_GurZKLIENT_NAME_REM_Z2(TFIBWideStringField * GurZKLIENT_NAME_REM_Z2)=0;

   __property TFIBWideStringField * GurZKLIENT_ADR_REM_Z2 = {read = get_GurZKLIENT_ADR_REM_Z2 , write = set_GurZKLIENT_ADR_REM_Z2};
   virtual TFIBWideStringField * get_GurZKLIENT_ADR_REM_Z2(void)=0;
   virtual void set_GurZKLIENT_ADR_REM_Z2(TFIBWideStringField * GurZKLIENT_ADR_REM_Z2)=0;

   __property TFIBWideStringField * GurZKLIENT_PHONE_REM_Z2 = {read = get_GurZKLIENT_PHONE_REM_Z2 , write = set_GurZKLIENT_PHONE_REM_Z2};
   virtual TFIBWideStringField * get_GurZKLIENT_PHONE_REM_Z2(void)=0;
   virtual void set_GurZKLIENT_PHONE_REM_Z2(TFIBWideStringField * GurZKLIENT_PHONE_REM_Z2)=0;

   __property TFIBWideStringField * GurZKLIENT_EMAIL_REM_Z2 = {read = get_GurZKLIENT_EMAIL_REM_Z2 , write = set_GurZKLIENT_EMAIL_REM_Z2};
   virtual TFIBWideStringField * get_GurZKLIENT_EMAIL_REM_Z2(void)=0;
   virtual void set_GurZKLIENT_EMAIL_REM_Z2(TFIBWideStringField * GurZKLIENT_EMAIL_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDBRAND_REM_Z2 = {read = get_GurZIDBRAND_REM_Z2 , write = set_GurZIDBRAND_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDBRAND_REM_Z2(void)=0;
   virtual void set_GurZIDBRAND_REM_Z2(TFIBLargeIntField * GurZIDBRAND_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDPRODUCER_REM_Z2 = {read = get_GurZIDPRODUCER_REM_Z2 , write = set_GurZIDPRODUCER_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDPRODUCER_REM_Z2(void)=0;
   virtual void set_GurZIDPRODUCER_REM_Z2(TFIBLargeIntField * GurZIDPRODUCER_REM_Z2)=0;

   __property TFIBWideStringField * GurZNEISPR_REM_Z2 = {read = get_GurZNEISPR_REM_Z2 , write = set_GurZNEISPR_REM_Z2};
   virtual TFIBWideStringField * get_GurZNEISPR_REM_Z2(void)=0;
   virtual void set_GurZNEISPR_REM_Z2(TFIBWideStringField * GurZNEISPR_REM_Z2)=0;

   __property TFIBWideStringField * GurZSOST_REM_Z2 = {read = get_GurZSOST_REM_Z2 , write = set_GurZSOST_REM_Z2};
   virtual TFIBWideStringField * get_GurZSOST_REM_Z2(void)=0;
   virtual void set_GurZSOST_REM_Z2(TFIBWideStringField * GurZSOST_REM_Z2)=0;

   __property TFIBWideStringField * GurZMODEL_STR_REM_Z2 = {read = get_GurZMODEL_STR_REM_Z2 , write = set_GurZMODEL_STR_REM_Z2};
   virtual TFIBWideStringField * get_GurZMODEL_STR_REM_Z2(void)=0;
   virtual void set_GurZMODEL_STR_REM_Z2(TFIBWideStringField * GurZMODEL_STR_REM_Z2)=0;

   __property TFIBWideStringField * GurZSERNUM1_REM_Z2 = {read = get_GurZSERNUM1_REM_Z2 , write = set_GurZSERNUM1_REM_Z2};
   virtual TFIBWideStringField * get_GurZSERNUM1_REM_Z2(void)=0;
   virtual void set_GurZSERNUM1_REM_Z2(TFIBWideStringField * GurZSERNUM1_REM_Z2)=0;

   __property TFIBWideStringField * GurZSERNUM2_REM_Z2 = {read = get_GurZSERNUM2_REM_Z2 , write = set_GurZSERNUM2_REM_Z2};
   virtual TFIBWideStringField * get_GurZSERNUM2_REM_Z2(void)=0;
   virtual void set_GurZSERNUM2_REM_Z2(TFIBWideStringField * GurZSERNUM2_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDKKT_REM_Z2 = {read = get_GurZIDKKT_REM_Z2 , write = set_GurZIDKKT_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDKKT_REM_Z2(void)=0;
   virtual void set_GurZIDKKT_REM_Z2(TFIBLargeIntField * GurZIDKKT_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDHW_REM_Z2 = {read = get_GurZIDHW_REM_Z2 , write = set_GurZIDHW_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDHW_REM_Z2(void)=0;
   virtual void set_GurZIDHW_REM_Z2(TFIBLargeIntField * GurZIDHW_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDSELLER_REM_Z2 = {read = get_GurZIDSELLER_REM_Z2 , write = set_GurZIDSELLER_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDSELLER_REM_Z2(void)=0;
   virtual void set_GurZIDSELLER_REM_Z2(TFIBLargeIntField * GurZIDSELLER_REM_Z2)=0;

   __property TFIBWideStringField * GurZDOPOPISANIE_REM_Z2 = {read = get_GurZDOPOPISANIE_REM_Z2 , write = set_GurZDOPOPISANIE_REM_Z2};
   virtual TFIBWideStringField * get_GurZDOPOPISANIE_REM_Z2(void)=0;
   virtual void set_GurZDOPOPISANIE_REM_Z2(TFIBWideStringField * GurZDOPOPISANIE_REM_Z2)=0;

   __property TFIBBCDField * GurZSUMKLIENTA_REM_Z2 = {read = get_GurZSUMKLIENTA_REM_Z2 , write = set_GurZSUMKLIENTA_REM_Z2};
   virtual TFIBBCDField * get_GurZSUMKLIENTA_REM_Z2(void)=0;
   virtual void set_GurZSUMKLIENTA_REM_Z2(TFIBBCDField * GurZSUMKLIENTA_REM_Z2)=0;

   __property TFIBBCDField * GurZSUMNACHA_REM_Z2 = {read = get_GurZSUMNACHA_REM_Z2 , write = set_GurZSUMNACHA_REM_Z2};
   virtual TFIBBCDField * get_GurZSUMNACHA_REM_Z2(void)=0;
   virtual void set_GurZSUMNACHA_REM_Z2(TFIBBCDField * GurZSUMNACHA_REM_Z2)=0;

   __property TFIBIntegerField * GurZRESULT_REM_Z2 = {read = get_GurZRESULT_REM_Z2 , write = set_GurZRESULT_REM_Z2};
   virtual TFIBIntegerField * get_GurZRESULT_REM_Z2(void)=0;
   virtual void set_GurZRESULT_REM_Z2(TFIBIntegerField * GurZRESULT_REM_Z2)=0;

   __property TFIBWideStringField * GurZPRICHINA_REM_Z2 = {read = get_GurZPRICHINA_REM_Z2 , write = set_GurZPRICHINA_REM_Z2};
   virtual TFIBWideStringField * get_GurZPRICHINA_REM_Z2(void)=0;
   virtual void set_GurZPRICHINA_REM_Z2(TFIBWideStringField * GurZPRICHINA_REM_Z2)=0;

   __property TFIBIntegerField * GurZPRICHINA_LIST_REM_Z2 = {read = get_GurZPRICHINA_LIST_REM_Z2 , write = set_GurZPRICHINA_LIST_REM_Z2};
   virtual TFIBIntegerField * get_GurZPRICHINA_LIST_REM_Z2(void)=0;
   virtual void set_GurZPRICHINA_LIST_REM_Z2(TFIBIntegerField * GurZPRICHINA_LIST_REM_Z2)=0;

   __property TFIBIntegerField * GurZSROK_REM_Z2 = {read = get_GurZSROK_REM_Z2 , write = set_GurZSROK_REM_Z2};
   virtual TFIBIntegerField * get_GurZSROK_REM_Z2(void)=0;
   virtual void set_GurZSROK_REM_Z2(TFIBIntegerField * GurZSROK_REM_Z2)=0;

   __property TFIBLargeIntField * GurZIDUSER_REM_Z2 = {read = get_GurZIDUSER_REM_Z2 , write = set_GurZIDUSER_REM_Z2};
   virtual TFIBLargeIntField * get_GurZIDUSER_REM_Z2(void)=0;
   virtual void set_GurZIDUSER_REM_Z2(TFIBLargeIntField * GurZIDUSER_REM_Z2)=0;

   __property TFIBWideStringField * GurZNAMEFIRM = {read = get_GurZNAMEFIRM , write = set_GurZNAMEFIRM};
   virtual TFIBWideStringField * get_GurZNAMEFIRM(void)=0;
   virtual void set_GurZNAMEFIRM(TFIBWideStringField * GurZNAMEFIRM)=0;

   __property TFIBWideStringField * GurZNAME_SINFBASE_OBMEN = {read = get_GurZNAME_SINFBASE_OBMEN , write = set_GurZNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_GurZNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_GurZNAME_SINFBASE_OBMEN(TFIBWideStringField * GurZNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * GurZNAME_REM_SMODEL = {read = get_GurZNAME_REM_SMODEL , write = set_GurZNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_GurZNAME_REM_SMODEL(void)=0;
   virtual void set_GurZNAME_REM_SMODEL(TFIBWideStringField * GurZNAME_REM_SMODEL)=0;

   __property TFIBWideStringField * GurZNAME_SKLAD_PR = {read = get_GurZNAME_SKLAD_PR , write = set_GurZNAME_SKLAD_PR};
   virtual TFIBWideStringField * get_GurZNAME_SKLAD_PR(void)=0;
   virtual void set_GurZNAME_SKLAD_PR(TFIBWideStringField * GurZNAME_SKLAD_PR)=0;

   __property TFIBWideStringField * GurZNAMEKLIENT = {read = get_GurZNAMEKLIENT , write = set_GurZNAMEKLIENT};
   virtual TFIBWideStringField * get_GurZNAMEKLIENT(void)=0;
   virtual void set_GurZNAMEKLIENT(TFIBWideStringField * GurZNAMEKLIENT)=0;

   __property TFIBWideStringField * GurZNAMEDILER = {read = get_GurZNAMEDILER , write = set_GurZNAMEDILER};
   virtual TFIBWideStringField * get_GurZNAMEDILER(void)=0;
   virtual void set_GurZNAMEDILER(TFIBWideStringField * GurZNAMEDILER)=0;

   __property TFIBWideStringField * GurZNAME_USER = {read = get_GurZNAME_USER , write = set_GurZNAME_USER};
   virtual TFIBWideStringField * get_GurZNAME_USER(void)=0;
   virtual void set_GurZNAME_USER(TFIBWideStringField * GurZNAME_USER)=0;

   __property TFIBWideStringField * GurZNAME_SBRAND = {read = get_GurZNAME_SBRAND , write = set_GurZNAME_SBRAND};
   virtual TFIBWideStringField * get_GurZNAME_SBRAND(void)=0;
   virtual void set_GurZNAME_SBRAND(TFIBWideStringField * GurZNAME_SBRAND)=0;

   __property TFIBWideStringField * GurZNAME_REM_SHARDWARE = {read = get_GurZNAME_REM_SHARDWARE , write = set_GurZNAME_REM_SHARDWARE};
   virtual TFIBWideStringField * get_GurZNAME_REM_SHARDWARE(void)=0;
   virtual void set_GurZNAME_REM_SHARDWARE(TFIBWideStringField * GurZNAME_REM_SHARDWARE)=0;

   __property TFIBWideStringField * GurZSERNUM_REM_SHARDWARE = {read = get_GurZSERNUM_REM_SHARDWARE , write = set_GurZSERNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_GurZSERNUM_REM_SHARDWARE(void)=0;
   virtual void set_GurZSERNUM_REM_SHARDWARE(TFIBWideStringField * GurZSERNUM_REM_SHARDWARE)=0;

   __property TFIBWideStringField * GurZSERNUM2_REM_SHARDWARE = {read = get_GurZSERNUM2_REM_SHARDWARE , write = set_GurZSERNUM2_REM_SHARDWARE};
   virtual TFIBWideStringField * get_GurZSERNUM2_REM_SHARDWARE(void)=0;
   virtual void set_GurZSERNUM2_REM_SHARDWARE(TFIBWideStringField * GurZSERNUM2_REM_SHARDWARE)=0;

   __property TFIBWideStringField * GurZNAME_REM_SKKT = {read = get_GurZNAME_REM_SKKT , write = set_GurZNAME_REM_SKKT};
   virtual TFIBWideStringField * get_GurZNAME_REM_SKKT(void)=0;
   virtual void set_GurZNAME_REM_SKKT(TFIBWideStringField * GurZNAME_REM_SKKT)=0;

   __property TFIBWideStringField * GurZSERNUM_REM_SKKT = {read = get_GurZSERNUM_REM_SKKT , write = set_GurZSERNUM_REM_SKKT};
   virtual TFIBWideStringField * get_GurZSERNUM_REM_SKKT(void)=0;
   virtual void set_GurZSERNUM_REM_SKKT(TFIBWideStringField * GurZSERNUM_REM_SKKT)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdZ = {read = get_IdZ , write = set_IdZ};
   virtual __int64 get_IdZ(void)=0;
   virtual void set_IdZ(__int64 IdZ)=0;

   __property bool flChangeData = {read = get_flChangeData , write = set_flChangeData};
   virtual bool get_flChangeData(void)=0;
   virtual void set_flChangeData(bool flChangeData)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 id)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual void CloseDoc(void)=0;
};
#define IID_IREM_DMZayavkaPredv __uuidof(IREM_DMZayavkaPredv)
#endif
