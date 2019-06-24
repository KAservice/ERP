#ifndef UIDMFibConnectionH
#define UIDMFibConnectionH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMFibConnection)) IDMFibConnection : public IMainInterface
{
public:
   __property TpFIBDatabase * pFIBData = {read = get_pFIBData , write = set_pFIBData};
   virtual TpFIBDatabase * get_pFIBData(void)=0;
   virtual void set_pFIBData(TpFIBDatabase * pFIBData)=0;

   __property TpFIBTransaction * pFIBTr = {read = get_pFIBTr , write = set_pFIBTr};
   virtual TpFIBTransaction * get_pFIBTr(void)=0;
   virtual void set_pFIBTr(TpFIBTransaction * pFIBTr)=0;

   __property TpFIBQuery * pFIBQLog = {read = get_pFIBQLog , write = set_pFIBQLog};
   virtual TpFIBQuery * get_pFIBQLog(void)=0;
   virtual void set_pFIBQLog(TpFIBQuery * pFIBQLog)=0;

   __property TpFIBTransaction * pFIBTrLog = {read = get_pFIBTrLog , write = set_pFIBTrLog};
   virtual TpFIBTransaction * get_pFIBTrLog(void)=0;
   virtual void set_pFIBTrLog(TpFIBTransaction * pFIBTrLog)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TpFIBDataSet * UserInfo = {read = get_UserInfo , write = set_UserInfo};
   virtual TpFIBDataSet * get_UserInfo(void)=0;
   virtual void set_UserInfo(TpFIBDataSet * UserInfo)=0;

   __property TFIBSmallIntField * UserInfoTPOSREPORT_SUSER = {read = get_UserInfoTPOSREPORT_SUSER , write = set_UserInfoTPOSREPORT_SUSER};
   virtual TFIBSmallIntField * get_UserInfoTPOSREPORT_SUSER(void)=0;
   virtual void set_UserInfoTPOSREPORT_SUSER(TFIBSmallIntField * UserInfoTPOSREPORT_SUSER)=0;

   __property TFIBSmallIntField * UserInfoTPOSGOURNAL_SUSER = {read = get_UserInfoTPOSGOURNAL_SUSER , write = set_UserInfoTPOSGOURNAL_SUSER};
   virtual TFIBSmallIntField * get_UserInfoTPOSGOURNAL_SUSER(void)=0;
   virtual void set_UserInfoTPOSGOURNAL_SUSER(TFIBSmallIntField * UserInfoTPOSGOURNAL_SUSER)=0;

   __property TFIBSmallIntField * UserInfoKOLDAYREP_SUSER = {read = get_UserInfoKOLDAYREP_SUSER , write = set_UserInfoKOLDAYREP_SUSER};
   virtual TFIBSmallIntField * get_UserInfoKOLDAYREP_SUSER(void)=0;
   virtual void set_UserInfoKOLDAYREP_SUSER(TFIBSmallIntField * UserInfoKOLDAYREP_SUSER)=0;

   __property TFIBSmallIntField * UserInfoKOLDAYGUR_SUSER = {read = get_UserInfoKOLDAYGUR_SUSER , write = set_UserInfoKOLDAYGUR_SUSER};
   virtual TFIBSmallIntField * get_UserInfoKOLDAYGUR_SUSER(void)=0;
   virtual void set_UserInfoKOLDAYGUR_SUSER(TFIBSmallIntField * UserInfoKOLDAYGUR_SUSER)=0;

   __property TFIBBCDField * UserInfoID_USER = {read = get_UserInfoID_USER , write = set_UserInfoID_USER};
   virtual TFIBBCDField * get_UserInfoID_USER(void)=0;
   virtual void set_UserInfoID_USER(TFIBBCDField * UserInfoID_USER)=0;

   __property TFIBBCDField * UserInfoIDPOD_USER = {read = get_UserInfoIDPOD_USER , write = set_UserInfoIDPOD_USER};
   virtual TFIBBCDField * get_UserInfoIDPOD_USER(void)=0;
   virtual void set_UserInfoIDPOD_USER(TFIBBCDField * UserInfoIDPOD_USER)=0;

   __property TFIBBCDField * UserInfoIDFIRM_USER = {read = get_UserInfoIDFIRM_USER , write = set_UserInfoIDFIRM_USER};
   virtual TFIBBCDField * get_UserInfoIDFIRM_USER(void)=0;
   virtual void set_UserInfoIDFIRM_USER(TFIBBCDField * UserInfoIDFIRM_USER)=0;

   __property TFIBBCDField * UserInfoIDSKLAD_USER = {read = get_UserInfoIDSKLAD_USER , write = set_UserInfoIDSKLAD_USER};
   virtual TFIBBCDField * get_UserInfoIDSKLAD_USER(void)=0;
   virtual void set_UserInfoIDSKLAD_USER(TFIBBCDField * UserInfoIDSKLAD_USER)=0;

   __property TFIBBCDField * UserInfoIDTPRICE_USER = {read = get_UserInfoIDTPRICE_USER , write = set_UserInfoIDTPRICE_USER};
   virtual TFIBBCDField * get_UserInfoIDTPRICE_USER(void)=0;
   virtual void set_UserInfoIDTPRICE_USER(TFIBBCDField * UserInfoIDTPRICE_USER)=0;

   __property TFIBBCDField * UserInfoIDTPRICE1_USER = {read = get_UserInfoIDTPRICE1_USER , write = set_UserInfoIDTPRICE1_USER};
   virtual TFIBBCDField * get_UserInfoIDTPRICE1_USER(void)=0;
   virtual void set_UserInfoIDTPRICE1_USER(TFIBBCDField * UserInfoIDTPRICE1_USER)=0;

   __property TFIBBCDField * UserInfoIDTPRICE2_USER = {read = get_UserInfoIDTPRICE2_USER , write = set_UserInfoIDTPRICE2_USER};
   virtual TFIBBCDField * get_UserInfoIDTPRICE2_USER(void)=0;
   virtual void set_UserInfoIDTPRICE2_USER(TFIBBCDField * UserInfoIDTPRICE2_USER)=0;

   __property TFIBBCDField * UserInfoIDBSCHET_USER = {read = get_UserInfoIDBSCHET_USER , write = set_UserInfoIDBSCHET_USER};
   virtual TFIBBCDField * get_UserInfoIDBSCHET_USER(void)=0;
   virtual void set_UserInfoIDBSCHET_USER(TFIBBCDField * UserInfoIDBSCHET_USER)=0;

   __property TFIBBCDField * UserInfoIDGRP_USER = {read = get_UserInfoIDGRP_USER , write = set_UserInfoIDGRP_USER};
   virtual TFIBBCDField * get_UserInfoIDGRP_USER(void)=0;
   virtual void set_UserInfoIDGRP_USER(TFIBBCDField * UserInfoIDGRP_USER)=0;

   __property TFIBBCDField * UserInfoIDKASSA_USER = {read = get_UserInfoIDKASSA_USER , write = set_UserInfoIDKASSA_USER};
   virtual TFIBBCDField * get_UserInfoIDKASSA_USER(void)=0;
   virtual void set_UserInfoIDKASSA_USER(TFIBBCDField * UserInfoIDKASSA_USER)=0;

   __property TFIBBCDField * UserInfoIDBASE_SUSER = {read = get_UserInfoIDBASE_SUSER , write = set_UserInfoIDBASE_SUSER};
   virtual TFIBBCDField * get_UserInfoIDBASE_SUSER(void)=0;
   virtual void set_UserInfoIDBASE_SUSER(TFIBBCDField * UserInfoIDBASE_SUSER)=0;

   __property TFIBSmallIntField * UserInfoREOPEN_GUR_SUSER = {read = get_UserInfoREOPEN_GUR_SUSER , write = set_UserInfoREOPEN_GUR_SUSER};
   virtual TFIBSmallIntField * get_UserInfoREOPEN_GUR_SUSER(void)=0;
   virtual void set_UserInfoREOPEN_GUR_SUSER(TFIBSmallIntField * UserInfoREOPEN_GUR_SUSER)=0;

   __property TFIBSmallIntField * UserInfoREOPEN_SPR_SUSER = {read = get_UserInfoREOPEN_SPR_SUSER , write = set_UserInfoREOPEN_SPR_SUSER};
   virtual TFIBSmallIntField * get_UserInfoREOPEN_SPR_SUSER(void)=0;
   virtual void set_UserInfoREOPEN_SPR_SUSER(TFIBSmallIntField * UserInfoREOPEN_SPR_SUSER)=0;

   __property TFIBSmallIntField * UserInfoSPRNOM_OST_SUSER = {read = get_UserInfoSPRNOM_OST_SUSER , write = set_UserInfoSPRNOM_OST_SUSER};
   virtual TFIBSmallIntField * get_UserInfoSPRNOM_OST_SUSER(void)=0;
   virtual void set_UserInfoSPRNOM_OST_SUSER(TFIBSmallIntField * UserInfoSPRNOM_OST_SUSER)=0;

   __property TFIBIntegerField * UserInfoEDIT_CHUG_DOC_SUSER = {read = get_UserInfoEDIT_CHUG_DOC_SUSER , write = set_UserInfoEDIT_CHUG_DOC_SUSER};
   virtual TFIBIntegerField * get_UserInfoEDIT_CHUG_DOC_SUSER(void)=0;
   virtual void set_UserInfoEDIT_CHUG_DOC_SUSER(TFIBIntegerField * UserInfoEDIT_CHUG_DOC_SUSER)=0;

   __property TFIBIntegerField * UserInfoDEL_CHUG_DOC_SUSER = {read = get_UserInfoDEL_CHUG_DOC_SUSER , write = set_UserInfoDEL_CHUG_DOC_SUSER};
   virtual TFIBIntegerField * get_UserInfoDEL_CHUG_DOC_SUSER(void)=0;
   virtual void set_UserInfoDEL_CHUG_DOC_SUSER(TFIBIntegerField * UserInfoDEL_CHUG_DOC_SUSER)=0;

   __property TFIBSmallIntField * UserInfoSHOW_LOG_SUSER = {read = get_UserInfoSHOW_LOG_SUSER , write = set_UserInfoSHOW_LOG_SUSER};
   virtual TFIBSmallIntField * get_UserInfoSHOW_LOG_SUSER(void)=0;
   virtual void set_UserInfoSHOW_LOG_SUSER(TFIBSmallIntField * UserInfoSHOW_LOG_SUSER)=0;

   __property TFIBSmallIntField * UserInfoDETALIED_LOG_SUSER = {read = get_UserInfoDETALIED_LOG_SUSER , write = set_UserInfoDETALIED_LOG_SUSER};
   virtual TFIBSmallIntField * get_UserInfoDETALIED_LOG_SUSER(void)=0;
   virtual void set_UserInfoDETALIED_LOG_SUSER(TFIBSmallIntField * UserInfoDETALIED_LOG_SUSER)=0;

   __property TFIBSmallIntField * UserInfoSAVENAME_SUSER = {read = get_UserInfoSAVENAME_SUSER , write = set_UserInfoSAVENAME_SUSER};
   virtual TFIBSmallIntField * get_UserInfoSAVENAME_SUSER(void)=0;
   virtual void set_UserInfoSAVENAME_SUSER(TFIBSmallIntField * UserInfoSAVENAME_SUSER)=0;

   __property TFIBWideStringField * UserInfoNAME_USER = {read = get_UserInfoNAME_USER , write = set_UserInfoNAME_USER};
   virtual TFIBWideStringField * get_UserInfoNAME_USER(void)=0;
   virtual void set_UserInfoNAME_USER(TFIBWideStringField * UserInfoNAME_USER)=0;

   __property TFIBWideStringField * UserInfoFNAME_USER = {read = get_UserInfoFNAME_USER , write = set_UserInfoFNAME_USER};
   virtual TFIBWideStringField * get_UserInfoFNAME_USER(void)=0;
   virtual void set_UserInfoFNAME_USER(TFIBWideStringField * UserInfoFNAME_USER)=0;

   __property TFIBIntegerField * UserInfoINTERF_USER = {read = get_UserInfoINTERF_USER , write = set_UserInfoINTERF_USER};
   virtual TFIBIntegerField * get_UserInfoINTERF_USER(void)=0;
   virtual void set_UserInfoINTERF_USER(TFIBIntegerField * UserInfoINTERF_USER)=0;

   __property TFIBWideStringField * UserInfoNAMEPOD = {read = get_UserInfoNAMEPOD , write = set_UserInfoNAMEPOD};
   virtual TFIBWideStringField * get_UserInfoNAMEPOD(void)=0;
   virtual void set_UserInfoNAMEPOD(TFIBWideStringField * UserInfoNAMEPOD)=0;

   __property TFIBWideStringField * UserInfoNAMEFIRM = {read = get_UserInfoNAMEFIRM , write = set_UserInfoNAMEFIRM};
   virtual TFIBWideStringField * get_UserInfoNAMEFIRM(void)=0;
   virtual void set_UserInfoNAMEFIRM(TFIBWideStringField * UserInfoNAMEFIRM)=0;

   __property TFIBWideStringField * UserInfoNAMESKLAD = {read = get_UserInfoNAMESKLAD , write = set_UserInfoNAMESKLAD};
   virtual TFIBWideStringField * get_UserInfoNAMESKLAD(void)=0;
   virtual void set_UserInfoNAMESKLAD(TFIBWideStringField * UserInfoNAMESKLAD)=0;

   __property TFIBWideStringField * UserInfoNAME_TPRICE = {read = get_UserInfoNAME_TPRICE , write = set_UserInfoNAME_TPRICE};
   virtual TFIBWideStringField * get_UserInfoNAME_TPRICE(void)=0;
   virtual void set_UserInfoNAME_TPRICE(TFIBWideStringField * UserInfoNAME_TPRICE)=0;

   __property TFIBWideStringField * UserInfoNAME_SINFBASE_OBMEN = {read = get_UserInfoNAME_SINFBASE_OBMEN , write = set_UserInfoNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_UserInfoNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_UserInfoNAME_SINFBASE_OBMEN(TFIBWideStringField * UserInfoNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * UserInfoNAMEBSCHET = {read = get_UserInfoNAMEBSCHET , write = set_UserInfoNAMEBSCHET};
   virtual TFIBWideStringField * get_UserInfoNAMEBSCHET(void)=0;
   virtual void set_UserInfoNAMEBSCHET(TFIBWideStringField * UserInfoNAMEBSCHET)=0;

   __property TFIBWideStringField * UserInfoNAMEKKM = {read = get_UserInfoNAMEKKM , write = set_UserInfoNAMEKKM};
   virtual TFIBWideStringField * get_UserInfoNAMEKKM(void)=0;
   virtual void set_UserInfoNAMEKKM(TFIBWideStringField * UserInfoNAMEKKM)=0;

   __property TFIBWideStringField * UserInfoNAME2_USER = {read = get_UserInfoNAME2_USER , write = set_UserInfoNAME2_USER};
   virtual TFIBWideStringField * get_UserInfoNAME2_USER(void)=0;
   virtual void set_UserInfoNAME2_USER(TFIBWideStringField * UserInfoNAME2_USER)=0;

   __property TpFIBTransaction * TransactionUserInfo = {read = get_TransactionUserInfo , write = set_TransactionUserInfo};
   virtual TpFIBTransaction * get_TransactionUserInfo(void)=0;
   virtual void set_TransactionUserInfo(TpFIBTransaction * TransactionUserInfo)=0;

   __property TpFIBTransaction * Transaction = {read = get_Transaction , write = set_Transaction};
   virtual TpFIBTransaction * get_Transaction(void)=0;
   virtual void set_Transaction(TpFIBTransaction * Transaction)=0;

   __property TpFIBDataSet * ARMInfo = {read = get_ARMInfo , write = set_ARMInfo};
   virtual TpFIBDataSet * get_ARMInfo(void)=0;
   virtual void set_ARMInfo(TpFIBDataSet * ARMInfo)=0;

   __property TFIBLargeIntField * ARMInfoID_SARM = {read = get_ARMInfoID_SARM , write = set_ARMInfoID_SARM};
   virtual TFIBLargeIntField * get_ARMInfoID_SARM(void)=0;
   virtual void set_ARMInfoID_SARM(TFIBLargeIntField * ARMInfoID_SARM)=0;

   __property TFIBWideStringField * ARMInfoNAME_SARM = {read = get_ARMInfoNAME_SARM , write = set_ARMInfoNAME_SARM};
   virtual TFIBWideStringField * get_ARMInfoNAME_SARM(void)=0;
   virtual void set_ARMInfoNAME_SARM(TFIBWideStringField * ARMInfoNAME_SARM)=0;

   __property TFIBIntegerField * ARMInfoCODE_SARM = {read = get_ARMInfoCODE_SARM , write = set_ARMInfoCODE_SARM};
   virtual TFIBIntegerField * get_ARMInfoCODE_SARM(void)=0;
   virtual void set_ARMInfoCODE_SARM(TFIBIntegerField * ARMInfoCODE_SARM)=0;

   __property TFIBLargeIntField * ARMInfoIDFIRM_SARM = {read = get_ARMInfoIDFIRM_SARM , write = set_ARMInfoIDFIRM_SARM};
   virtual TFIBLargeIntField * get_ARMInfoIDFIRM_SARM(void)=0;
   virtual void set_ARMInfoIDFIRM_SARM(TFIBLargeIntField * ARMInfoIDFIRM_SARM)=0;

   __property TFIBLargeIntField * ARMInfoIDSKLAD_SARM = {read = get_ARMInfoIDSKLAD_SARM , write = set_ARMInfoIDSKLAD_SARM};
   virtual TFIBLargeIntField * get_ARMInfoIDSKLAD_SARM(void)=0;
   virtual void set_ARMInfoIDSKLAD_SARM(TFIBLargeIntField * ARMInfoIDSKLAD_SARM)=0;

   __property TFIBLargeIntField * ARMInfoIDPODR_SARM = {read = get_ARMInfoIDPODR_SARM , write = set_ARMInfoIDPODR_SARM};
   virtual TFIBLargeIntField * get_ARMInfoIDPODR_SARM(void)=0;
   virtual void set_ARMInfoIDPODR_SARM(TFIBLargeIntField * ARMInfoIDPODR_SARM)=0;

   __property TFIBLargeIntField * ARMInfoIDKKM_SARM = {read = get_ARMInfoIDKKM_SARM , write = set_ARMInfoIDKKM_SARM};
   virtual TFIBLargeIntField * get_ARMInfoIDKKM_SARM(void)=0;
   virtual void set_ARMInfoIDKKM_SARM(TFIBLargeIntField * ARMInfoIDKKM_SARM)=0;

   __property TFIBWideStringField * ARMInfoSTRPAR_SARM = {read = get_ARMInfoSTRPAR_SARM , write = set_ARMInfoSTRPAR_SARM};
   virtual TFIBWideStringField * get_ARMInfoSTRPAR_SARM(void)=0;
   virtual void set_ARMInfoSTRPAR_SARM(TFIBWideStringField * ARMInfoSTRPAR_SARM)=0;

   __property TFIBWideStringField * ARMInfoNAMEFIRM = {read = get_ARMInfoNAMEFIRM , write = set_ARMInfoNAMEFIRM};
   virtual TFIBWideStringField * get_ARMInfoNAMEFIRM(void)=0;
   virtual void set_ARMInfoNAMEFIRM(TFIBWideStringField * ARMInfoNAMEFIRM)=0;

   __property TFIBWideStringField * ARMInfoNAMESKLAD = {read = get_ARMInfoNAMESKLAD , write = set_ARMInfoNAMESKLAD};
   virtual TFIBWideStringField * get_ARMInfoNAMESKLAD(void)=0;
   virtual void set_ARMInfoNAMESKLAD(TFIBWideStringField * ARMInfoNAMESKLAD)=0;

   __property TFIBWideStringField * ARMInfoNAMEKKM = {read = get_ARMInfoNAMEKKM , write = set_ARMInfoNAMEKKM};
   virtual TFIBWideStringField * get_ARMInfoNAMEKKM(void)=0;
   virtual void set_ARMInfoNAMEKKM(TFIBWideStringField * ARMInfoNAMEKKM)=0;

   __property TFIBWideStringField * ARMInfoNAMEPOD = {read = get_ARMInfoNAMEPOD , write = set_ARMInfoNAMEPOD};
   virtual TFIBWideStringField * get_ARMInfoNAMEPOD(void)=0;
   virtual void set_ARMInfoNAMEPOD(TFIBWideStringField * ARMInfoNAMEPOD)=0;

   __property TFIBLargeIntField * ARMInfoIDTPRICEPOD = {read = get_ARMInfoIDTPRICEPOD , write = set_ARMInfoIDTPRICEPOD};
   virtual TFIBLargeIntField * get_ARMInfoIDTPRICEPOD(void)=0;
   virtual void set_ARMInfoIDTPRICEPOD(TFIBLargeIntField * ARMInfoIDTPRICEPOD)=0;

   __property TFIBWideStringField * ARMInfoNAME_TPRICE = {read = get_ARMInfoNAME_TPRICE , write = set_ARMInfoNAME_TPRICE};
   virtual TFIBWideStringField * get_ARMInfoNAME_TPRICE(void)=0;
   virtual void set_ARMInfoNAME_TPRICE(TFIBWideStringField * ARMInfoNAME_TPRICE)=0;

   __property TFIBWideStringField * ARMInfoNAME_SINFBASE_OBMEN = {read = get_ARMInfoNAME_SINFBASE_OBMEN , write = set_ARMInfoNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_ARMInfoNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_ARMInfoNAME_SINFBASE_OBMEN(TFIBWideStringField * ARMInfoNAME_SINFBASE_OBMEN)=0;

   __property TpFIBTransaction * TransactionARM = {read = get_TransactionARM , write = set_TransactionARM};
   virtual TpFIBTransaction * get_TransactionARM(void)=0;
   virtual void set_TransactionARM(TpFIBTransaction * TransactionARM)=0;

   __property TFIBLargeIntField * ARMInfoIDBASE_SARM = {read = get_ARMInfoIDBASE_SARM , write = set_ARMInfoIDBASE_SARM};
   virtual TFIBLargeIntField * get_ARMInfoIDBASE_SARM(void)=0;
   virtual void set_ARMInfoIDBASE_SARM(TFIBLargeIntField * ARMInfoIDBASE_SARM)=0;

   __property TFIBWideStringField * UserInfoNAME_REM_SACTCATEGORY = {read = get_UserInfoNAME_REM_SACTCATEGORY , write = set_UserInfoNAME_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_UserInfoNAME_REM_SACTCATEGORY(void)=0;
   virtual void set_UserInfoNAME_REM_SACTCATEGORY(TFIBWideStringField * UserInfoNAME_REM_SACTCATEGORY)=0;

   __property TFIBLargeIntField * ARMInfoIDACTCATEGORY_SARM = {read = get_ARMInfoIDACTCATEGORY_SARM , write = set_ARMInfoIDACTCATEGORY_SARM};
   virtual TFIBLargeIntField * get_ARMInfoIDACTCATEGORY_SARM(void)=0;
   virtual void set_ARMInfoIDACTCATEGORY_SARM(TFIBLargeIntField * ARMInfoIDACTCATEGORY_SARM)=0;

   __property TFIBWideStringField * ARMInfoNAME_REM_SACTCATEGORY = {read = get_ARMInfoNAME_REM_SACTCATEGORY , write = set_ARMInfoNAME_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_ARMInfoNAME_REM_SACTCATEGORY(void)=0;
   virtual void set_ARMInfoNAME_REM_SACTCATEGORY(TFIBWideStringField * ARMInfoNAME_REM_SACTCATEGORY)=0;

   __property TFIBBCDField * UserInfoIDACTCATEGORY_SUSER = {read = get_UserInfoIDACTCATEGORY_SUSER , write = set_UserInfoIDACTCATEGORY_SUSER};
   virtual TFIBBCDField * get_UserInfoIDACTCATEGORY_SUSER(void)=0;
   virtual void set_UserInfoIDACTCATEGORY_SUSER(TFIBBCDField * UserInfoIDACTCATEGORY_SUSER)=0;

   __property UnicodeString NameServer = {read = get_NameServer , write = set_NameServer};
   virtual UnicodeString get_NameServer(void)=0;
   virtual void set_NameServer(UnicodeString NameServer)=0;

   __property UnicodeString ConnectString = {read = get_ConnectString , write = set_ConnectString};
   virtual UnicodeString get_ConnectString(void)=0;
   virtual void set_ConnectString(UnicodeString ConnectString)=0;

   __property UnicodeString NameUser = {read = get_NameUser , write = set_NameUser};
   virtual UnicodeString get_NameUser(void)=0;
   virtual void set_NameUser(UnicodeString NameUser)=0;

   __property UnicodeString NameUser2 = {read = get_NameUser2 , write = set_NameUser2};
   virtual UnicodeString get_NameUser2(void)=0;
   virtual void set_NameUser2(UnicodeString NameUser2)=0;

   __property UnicodeString PasswordUser = {read = get_PasswordUser , write = set_PasswordUser};
   virtual UnicodeString get_PasswordUser(void)=0;
   virtual void set_PasswordUser(UnicodeString PasswordUser)=0;

   __property UnicodeString glCatalogProtocol = {read = get_glCatalogProtocol , write = set_glCatalogProtocol};
   virtual UnicodeString get_glCatalogProtocol(void)=0;
   virtual void set_glCatalogProtocol(UnicodeString glCatalogProtocol)=0;

   __property int CodeUser = {read = get_CodeUser , write = set_CodeUser};
   virtual int get_CodeUser(void)=0;
   virtual void set_CodeUser(int CodeUser)=0;

   __property UnicodeString TextVipOper = {read = get_TextVipOper , write = set_TextVipOper};
   virtual UnicodeString get_TextVipOper(void)=0;
   virtual void set_TextVipOper(UnicodeString TextVipOper)=0;

   __property int TypeApplication = {read = get_TypeApplication , write = set_TypeApplication};
   virtual int get_TypeApplication(void)=0;
   virtual void set_TypeApplication(int TypeApplication)=0;

   __property bool ExecPriv = {read = get_ExecPriv , write = set_ExecPriv};
   virtual bool get_ExecPriv(void)=0;
   virtual void set_ExecPriv(bool ExecPriv)=0;

   __property bool InsertPriv = {read = get_InsertPriv , write = set_InsertPriv};
   virtual bool get_InsertPriv(void)=0;
   virtual void set_InsertPriv(bool InsertPriv)=0;

   __property bool EditPriv = {read = get_EditPriv , write = set_EditPriv};
   virtual bool get_EditPriv(void)=0;
   virtual void set_EditPriv(bool EditPriv)=0;

   __property bool DeletePriv = {read = get_DeletePriv , write = set_DeletePriv};
   virtual bool get_DeletePriv(void)=0;
   virtual void set_DeletePriv(bool DeletePriv)=0;

   __property bool glShowNDS = {read = get_glShowNDS , write = set_glShowNDS};
   virtual bool get_glShowNDS(void)=0;
   virtual void set_glShowNDS(bool glShowNDS)=0;

   virtual bool GlobConnect(void)=0;
   virtual bool GlobConnect2(void)=0;
   virtual bool GlobConnect3(void)=0;
   virtual void DisconnectBase(void)=0;
   virtual UnicodeString GetNameServer(UnicodeString connect_string)=0;
   virtual UnicodeString GetVersionBase(void)=0;
   virtual bool CheckEnableStart(UnicodeString role_user)=0;
   virtual __int64 FindPoName(UnicodeString name_user)=0;
   virtual __int64 FindPoPassword(UnicodeString password)=0;
   virtual __int64 GetIdGrpUser(__int64 id_user)=0;
   virtual TDateTime GetPosNachReport(void)=0;
   virtual TDateTime GetPosNachGurnal(void)=0;
   virtual bool OpenUserInfo(__int64 id)=0;
   virtual bool GetPrivDM(int object)=0;
   virtual bool GetPrivForm(int object)=0;
   virtual bool OpenARMInfo(int code_arm)=0;
   virtual void glSaveProtocol(UnicodeString str)=0;
   virtual void AddLog(__int64 id_user,int type,int object,int oper,UnicodeString message,UnicodeString code_object,__int64 id_object,int subsystem)=0;
   virtual UnicodeString Arm_GetParameter(UnicodeString parameter)=0;
};
#define IID_IDMFibConnection __uuidof(IDMFibConnection)
#endif
