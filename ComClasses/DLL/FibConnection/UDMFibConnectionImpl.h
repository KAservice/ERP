#ifndef UDMFibConnectionImplH
#define UDMFibConnectionImplH
#include "IDMFibConnection.h"
#include "UDMFibConnection.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMFibConnectionImpl)) TDMFibConnectionImpl : public IDMFibConnection
{
public:
   TDMFibConnectionImpl();
   ~TDMFibConnectionImpl();
   TDMFibConnection * Object;
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

//IDMFibConnection
   virtual TpFIBDatabase * get_pFIBData(void);
   virtual void set_pFIBData(TpFIBDatabase * pFIBData);

   virtual TpFIBTransaction * get_pFIBTr(void);
   virtual void set_pFIBTr(TpFIBTransaction * pFIBTr);

   virtual TpFIBQuery * get_pFIBQLog(void);
   virtual void set_pFIBQLog(TpFIBQuery * pFIBQLog);

   virtual TpFIBTransaction * get_pFIBTrLog(void);
   virtual void set_pFIBTrLog(TpFIBTransaction * pFIBTrLog);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TpFIBDataSet * get_UserInfo(void);
   virtual void set_UserInfo(TpFIBDataSet * UserInfo);

   virtual TFIBSmallIntField * get_UserInfoTPOSREPORT_SUSER(void);
   virtual void set_UserInfoTPOSREPORT_SUSER(TFIBSmallIntField * UserInfoTPOSREPORT_SUSER);

   virtual TFIBSmallIntField * get_UserInfoTPOSGOURNAL_SUSER(void);
   virtual void set_UserInfoTPOSGOURNAL_SUSER(TFIBSmallIntField * UserInfoTPOSGOURNAL_SUSER);

   virtual TFIBSmallIntField * get_UserInfoKOLDAYREP_SUSER(void);
   virtual void set_UserInfoKOLDAYREP_SUSER(TFIBSmallIntField * UserInfoKOLDAYREP_SUSER);

   virtual TFIBSmallIntField * get_UserInfoKOLDAYGUR_SUSER(void);
   virtual void set_UserInfoKOLDAYGUR_SUSER(TFIBSmallIntField * UserInfoKOLDAYGUR_SUSER);

   virtual TFIBBCDField * get_UserInfoID_USER(void);
   virtual void set_UserInfoID_USER(TFIBBCDField * UserInfoID_USER);

   virtual TFIBBCDField * get_UserInfoIDPOD_USER(void);
   virtual void set_UserInfoIDPOD_USER(TFIBBCDField * UserInfoIDPOD_USER);

   virtual TFIBBCDField * get_UserInfoIDFIRM_USER(void);
   virtual void set_UserInfoIDFIRM_USER(TFIBBCDField * UserInfoIDFIRM_USER);

   virtual TFIBBCDField * get_UserInfoIDSKLAD_USER(void);
   virtual void set_UserInfoIDSKLAD_USER(TFIBBCDField * UserInfoIDSKLAD_USER);

   virtual TFIBBCDField * get_UserInfoIDTPRICE_USER(void);
   virtual void set_UserInfoIDTPRICE_USER(TFIBBCDField * UserInfoIDTPRICE_USER);

   virtual TFIBBCDField * get_UserInfoIDTPRICE1_USER(void);
   virtual void set_UserInfoIDTPRICE1_USER(TFIBBCDField * UserInfoIDTPRICE1_USER);

   virtual TFIBBCDField * get_UserInfoIDTPRICE2_USER(void);
   virtual void set_UserInfoIDTPRICE2_USER(TFIBBCDField * UserInfoIDTPRICE2_USER);

   virtual TFIBBCDField * get_UserInfoIDBSCHET_USER(void);
   virtual void set_UserInfoIDBSCHET_USER(TFIBBCDField * UserInfoIDBSCHET_USER);

   virtual TFIBBCDField * get_UserInfoIDGRP_USER(void);
   virtual void set_UserInfoIDGRP_USER(TFIBBCDField * UserInfoIDGRP_USER);

   virtual TFIBBCDField * get_UserInfoIDKASSA_USER(void);
   virtual void set_UserInfoIDKASSA_USER(TFIBBCDField * UserInfoIDKASSA_USER);

   virtual TFIBBCDField * get_UserInfoIDBASE_SUSER(void);
   virtual void set_UserInfoIDBASE_SUSER(TFIBBCDField * UserInfoIDBASE_SUSER);

   virtual TFIBSmallIntField * get_UserInfoREOPEN_GUR_SUSER(void);
   virtual void set_UserInfoREOPEN_GUR_SUSER(TFIBSmallIntField * UserInfoREOPEN_GUR_SUSER);

   virtual TFIBSmallIntField * get_UserInfoREOPEN_SPR_SUSER(void);
   virtual void set_UserInfoREOPEN_SPR_SUSER(TFIBSmallIntField * UserInfoREOPEN_SPR_SUSER);

   virtual TFIBSmallIntField * get_UserInfoSPRNOM_OST_SUSER(void);
   virtual void set_UserInfoSPRNOM_OST_SUSER(TFIBSmallIntField * UserInfoSPRNOM_OST_SUSER);

   virtual TFIBIntegerField * get_UserInfoEDIT_CHUG_DOC_SUSER(void);
   virtual void set_UserInfoEDIT_CHUG_DOC_SUSER(TFIBIntegerField * UserInfoEDIT_CHUG_DOC_SUSER);

   virtual TFIBIntegerField * get_UserInfoDEL_CHUG_DOC_SUSER(void);
   virtual void set_UserInfoDEL_CHUG_DOC_SUSER(TFIBIntegerField * UserInfoDEL_CHUG_DOC_SUSER);

   virtual TFIBSmallIntField * get_UserInfoSHOW_LOG_SUSER(void);
   virtual void set_UserInfoSHOW_LOG_SUSER(TFIBSmallIntField * UserInfoSHOW_LOG_SUSER);

   virtual TFIBSmallIntField * get_UserInfoDETALIED_LOG_SUSER(void);
   virtual void set_UserInfoDETALIED_LOG_SUSER(TFIBSmallIntField * UserInfoDETALIED_LOG_SUSER);

   virtual TFIBSmallIntField * get_UserInfoSAVENAME_SUSER(void);
   virtual void set_UserInfoSAVENAME_SUSER(TFIBSmallIntField * UserInfoSAVENAME_SUSER);

   virtual TFIBWideStringField * get_UserInfoNAME_USER(void);
   virtual void set_UserInfoNAME_USER(TFIBWideStringField * UserInfoNAME_USER);

   virtual TFIBWideStringField * get_UserInfoFNAME_USER(void);
   virtual void set_UserInfoFNAME_USER(TFIBWideStringField * UserInfoFNAME_USER);

   virtual TFIBIntegerField * get_UserInfoINTERF_USER(void);
   virtual void set_UserInfoINTERF_USER(TFIBIntegerField * UserInfoINTERF_USER);

   virtual TFIBWideStringField * get_UserInfoNAMEPOD(void);
   virtual void set_UserInfoNAMEPOD(TFIBWideStringField * UserInfoNAMEPOD);

   virtual TFIBWideStringField * get_UserInfoNAMEFIRM(void);
   virtual void set_UserInfoNAMEFIRM(TFIBWideStringField * UserInfoNAMEFIRM);

   virtual TFIBWideStringField * get_UserInfoNAMESKLAD(void);
   virtual void set_UserInfoNAMESKLAD(TFIBWideStringField * UserInfoNAMESKLAD);

   virtual TFIBWideStringField * get_UserInfoNAME_TPRICE(void);
   virtual void set_UserInfoNAME_TPRICE(TFIBWideStringField * UserInfoNAME_TPRICE);

   virtual TFIBWideStringField * get_UserInfoNAME_SINFBASE_OBMEN(void);
   virtual void set_UserInfoNAME_SINFBASE_OBMEN(TFIBWideStringField * UserInfoNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_UserInfoNAMEBSCHET(void);
   virtual void set_UserInfoNAMEBSCHET(TFIBWideStringField * UserInfoNAMEBSCHET);

   virtual TFIBWideStringField * get_UserInfoNAMEKKM(void);
   virtual void set_UserInfoNAMEKKM(TFIBWideStringField * UserInfoNAMEKKM);

   virtual TFIBWideStringField * get_UserInfoNAME2_USER(void);
   virtual void set_UserInfoNAME2_USER(TFIBWideStringField * UserInfoNAME2_USER);

   virtual TpFIBTransaction * get_TransactionUserInfo(void);
   virtual void set_TransactionUserInfo(TpFIBTransaction * TransactionUserInfo);

   virtual TpFIBTransaction * get_Transaction(void);
   virtual void set_Transaction(TpFIBTransaction * Transaction);

   virtual TpFIBDataSet * get_ARMInfo(void);
   virtual void set_ARMInfo(TpFIBDataSet * ARMInfo);

   virtual TFIBLargeIntField * get_ARMInfoID_SARM(void);
   virtual void set_ARMInfoID_SARM(TFIBLargeIntField * ARMInfoID_SARM);

   virtual TFIBWideStringField * get_ARMInfoNAME_SARM(void);
   virtual void set_ARMInfoNAME_SARM(TFIBWideStringField * ARMInfoNAME_SARM);

   virtual TFIBIntegerField * get_ARMInfoCODE_SARM(void);
   virtual void set_ARMInfoCODE_SARM(TFIBIntegerField * ARMInfoCODE_SARM);

   virtual TFIBLargeIntField * get_ARMInfoIDFIRM_SARM(void);
   virtual void set_ARMInfoIDFIRM_SARM(TFIBLargeIntField * ARMInfoIDFIRM_SARM);

   virtual TFIBLargeIntField * get_ARMInfoIDSKLAD_SARM(void);
   virtual void set_ARMInfoIDSKLAD_SARM(TFIBLargeIntField * ARMInfoIDSKLAD_SARM);

   virtual TFIBLargeIntField * get_ARMInfoIDPODR_SARM(void);
   virtual void set_ARMInfoIDPODR_SARM(TFIBLargeIntField * ARMInfoIDPODR_SARM);

   virtual TFIBLargeIntField * get_ARMInfoIDKKM_SARM(void);
   virtual void set_ARMInfoIDKKM_SARM(TFIBLargeIntField * ARMInfoIDKKM_SARM);

   virtual TFIBWideStringField * get_ARMInfoSTRPAR_SARM(void);
   virtual void set_ARMInfoSTRPAR_SARM(TFIBWideStringField * ARMInfoSTRPAR_SARM);

   virtual TFIBWideStringField * get_ARMInfoNAMEFIRM(void);
   virtual void set_ARMInfoNAMEFIRM(TFIBWideStringField * ARMInfoNAMEFIRM);

   virtual TFIBWideStringField * get_ARMInfoNAMESKLAD(void);
   virtual void set_ARMInfoNAMESKLAD(TFIBWideStringField * ARMInfoNAMESKLAD);

   virtual TFIBWideStringField * get_ARMInfoNAMEKKM(void);
   virtual void set_ARMInfoNAMEKKM(TFIBWideStringField * ARMInfoNAMEKKM);

   virtual TFIBWideStringField * get_ARMInfoNAMEPOD(void);
   virtual void set_ARMInfoNAMEPOD(TFIBWideStringField * ARMInfoNAMEPOD);

   virtual TFIBLargeIntField * get_ARMInfoIDTPRICEPOD(void);
   virtual void set_ARMInfoIDTPRICEPOD(TFIBLargeIntField * ARMInfoIDTPRICEPOD);

   virtual TFIBWideStringField * get_ARMInfoNAME_TPRICE(void);
   virtual void set_ARMInfoNAME_TPRICE(TFIBWideStringField * ARMInfoNAME_TPRICE);

   virtual TFIBWideStringField * get_ARMInfoNAME_SINFBASE_OBMEN(void);
   virtual void set_ARMInfoNAME_SINFBASE_OBMEN(TFIBWideStringField * ARMInfoNAME_SINFBASE_OBMEN);

   virtual TpFIBTransaction * get_TransactionARM(void);
   virtual void set_TransactionARM(TpFIBTransaction * TransactionARM);

   virtual TFIBLargeIntField * get_ARMInfoIDBASE_SARM(void);
   virtual void set_ARMInfoIDBASE_SARM(TFIBLargeIntField * ARMInfoIDBASE_SARM);

   virtual TFIBWideStringField * get_UserInfoNAME_REM_SACTCATEGORY(void);
   virtual void set_UserInfoNAME_REM_SACTCATEGORY(TFIBWideStringField * UserInfoNAME_REM_SACTCATEGORY);

   virtual TFIBLargeIntField * get_ARMInfoIDACTCATEGORY_SARM(void);
   virtual void set_ARMInfoIDACTCATEGORY_SARM(TFIBLargeIntField * ARMInfoIDACTCATEGORY_SARM);

   virtual TFIBWideStringField * get_ARMInfoNAME_REM_SACTCATEGORY(void);
   virtual void set_ARMInfoNAME_REM_SACTCATEGORY(TFIBWideStringField * ARMInfoNAME_REM_SACTCATEGORY);

   virtual TFIBBCDField * get_UserInfoIDACTCATEGORY_SUSER(void);
   virtual void set_UserInfoIDACTCATEGORY_SUSER(TFIBBCDField * UserInfoIDACTCATEGORY_SUSER);

   virtual UnicodeString get_NameServer(void);
   virtual void set_NameServer(UnicodeString NameServer);

   virtual UnicodeString get_ConnectString(void);
   virtual void set_ConnectString(UnicodeString ConnectString);

   virtual UnicodeString get_NameUser(void);
   virtual void set_NameUser(UnicodeString NameUser);

   virtual UnicodeString get_NameUser2(void);
   virtual void set_NameUser2(UnicodeString NameUser2);

   virtual UnicodeString get_PasswordUser(void);
   virtual void set_PasswordUser(UnicodeString PasswordUser);

   virtual UnicodeString get_glCatalogProtocol(void);
   virtual void set_glCatalogProtocol(UnicodeString glCatalogProtocol);

   virtual int get_CodeUser(void);
   virtual void set_CodeUser(int CodeUser);

   virtual UnicodeString get_TextVipOper(void);
   virtual void set_TextVipOper(UnicodeString TextVipOper);

   virtual int get_TypeApplication(void);
   virtual void set_TypeApplication(int TypeApplication);

   virtual bool get_ExecPriv(void);
   virtual void set_ExecPriv(bool ExecPriv);

   virtual bool get_InsertPriv(void);
   virtual void set_InsertPriv(bool InsertPriv);

   virtual bool get_EditPriv(void);
   virtual void set_EditPriv(bool EditPriv);

   virtual bool get_DeletePriv(void);
   virtual void set_DeletePriv(bool DeletePriv);

   virtual bool get_glShowNDS(void);
   virtual void set_glShowNDS(bool glShowNDS);

   virtual bool GlobConnect(void);
   virtual bool GlobConnect2(void);
   virtual bool GlobConnect3(void);
   virtual void DisconnectBase(void);
   virtual UnicodeString GetNameServer(UnicodeString connect_string);
   virtual UnicodeString GetVersionBase(void);
   virtual bool CheckEnableStart(UnicodeString role_user);
   virtual __int64 FindPoName(UnicodeString name_user);
   virtual __int64 FindPoPassword(UnicodeString password);
   virtual __int64 GetIdGrpUser(__int64 id_user);
   virtual TDateTime GetPosNachReport(void);
   virtual TDateTime GetPosNachGurnal(void);
   virtual bool OpenUserInfo(__int64 id);
   virtual bool GetPrivDM(int object);
   virtual bool GetPrivForm(int object);
   virtual bool OpenARMInfo(int code_arm);
   virtual void glSaveProtocol(UnicodeString str);
   virtual void AddLog(__int64 id_user,int type,int object,int oper,UnicodeString message,UnicodeString code_object,__int64 id_object,int subsystem);
   virtual UnicodeString Arm_GetParameter(UnicodeString parameter);
};
#define CLSID_TDMFibConnectionImpl __uuidof(TDMFibConnectionImpl)
#endif
