#include "vcl.h"
#pragma hdrstop


#include "UDMFibConnectionImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMFibConnectionImpl::TDMFibConnectionImpl()           
{                                            
Object=new TDMFibConnection(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMFibConnectionImpl::~TDMFibConnectionImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMFibConnectionImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMFibConnectionImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
 {                                                                         
int result=0;                                                             
if (id_interface==IID_IkanUnknown)                                        
   {                                                                     
   *ppv=static_cast<IkanUnknown*> (this);                                 
   result=-1;                                                             
   }                                                                      
else if (id_interface==IID_IMainInterface)                        
   {                                                                     
   *ppv=static_cast<IMainInterface*> (this);                                
   result=-1;                                                            
   }  
else if (id_interface==IID_IDMFibConnection)                        
   {                                                                     
   *ppv=static_cast<IDMFibConnection*> (this);                                
   result=-1;                                                            
   }                                                                     
else                                                                     
   {                                                                     
   *ppv=NULL;                                                            
   result=1;                                                             
   return result;                                                        
   }                                                                     
kanAddRef();                       
return result;                                                           
}                                                                       
//---------------------------------------------------------------
int TDMFibConnectionImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMFibConnectionImpl::kanRelease(void)                                  
{                                                                      
if (--NumRefs==0)                                                     
   {                                                                  
   delete this;                                                       
   return 0;                                                       
   }                                                                  
return NumRefs;                                                       
}                                                                     
//---------------------------------------------------------------

//IMainInterface 
int  TDMFibConnectionImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMFibConnectionImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMFibConnectionImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
//kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
Object->ClsIdImpl=CLSID_TDMFibConnectionImpl;
//Object->InterfaceMainObject=i_main_object;
//Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMFibConnectionImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMFibConnection
TpFIBDatabase * TDMFibConnectionImpl::get_pFIBData(void)
{
return Object->pFIBData;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_pFIBData(TpFIBDatabase * pFIBData)
{
Object->pFIBData=pFIBData;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMFibConnectionImpl::get_pFIBTr(void)
{
return Object->pFIBTr;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_pFIBTr(TpFIBTransaction * pFIBTr)
{
Object->pFIBTr=pFIBTr;
}
//---------------------------------------------------------------
TpFIBQuery * TDMFibConnectionImpl::get_pFIBQLog(void)
{
return Object->pFIBQLog;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_pFIBQLog(TpFIBQuery * pFIBQLog)
{
Object->pFIBQLog=pFIBQLog;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMFibConnectionImpl::get_pFIBTrLog(void)
{
return Object->pFIBTrLog;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_pFIBTrLog(TpFIBTransaction * pFIBTrLog)
{
Object->pFIBTrLog=pFIBTrLog;
}
//---------------------------------------------------------------
TpFIBQuery * TDMFibConnectionImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMFibConnectionImpl::get_UserInfo(void)
{
return Object->UserInfo;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfo(TpFIBDataSet * UserInfo)
{
Object->UserInfo=UserInfo;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoTPOSREPORT_SUSER(void)
{
return Object->UserInfoTPOSREPORT_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoTPOSREPORT_SUSER(TFIBSmallIntField * UserInfoTPOSREPORT_SUSER)
{
Object->UserInfoTPOSREPORT_SUSER=UserInfoTPOSREPORT_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoTPOSGOURNAL_SUSER(void)
{
return Object->UserInfoTPOSGOURNAL_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoTPOSGOURNAL_SUSER(TFIBSmallIntField * UserInfoTPOSGOURNAL_SUSER)
{
Object->UserInfoTPOSGOURNAL_SUSER=UserInfoTPOSGOURNAL_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoKOLDAYREP_SUSER(void)
{
return Object->UserInfoKOLDAYREP_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoKOLDAYREP_SUSER(TFIBSmallIntField * UserInfoKOLDAYREP_SUSER)
{
Object->UserInfoKOLDAYREP_SUSER=UserInfoKOLDAYREP_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoKOLDAYGUR_SUSER(void)
{
return Object->UserInfoKOLDAYGUR_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoKOLDAYGUR_SUSER(TFIBSmallIntField * UserInfoKOLDAYGUR_SUSER)
{
Object->UserInfoKOLDAYGUR_SUSER=UserInfoKOLDAYGUR_SUSER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMFibConnectionImpl::get_UserInfoID_USER(void)
{
return Object->UserInfoID_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoID_USER(TFIBBCDField * UserInfoID_USER)
{
Object->UserInfoID_USER=UserInfoID_USER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDPOD_USER(void)
{
return Object->UserInfoIDPOD_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDPOD_USER(TFIBBCDField * UserInfoIDPOD_USER)
{
Object->UserInfoIDPOD_USER=UserInfoIDPOD_USER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDFIRM_USER(void)
{
return Object->UserInfoIDFIRM_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDFIRM_USER(TFIBBCDField * UserInfoIDFIRM_USER)
{
Object->UserInfoIDFIRM_USER=UserInfoIDFIRM_USER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDSKLAD_USER(void)
{
return Object->UserInfoIDSKLAD_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDSKLAD_USER(TFIBBCDField * UserInfoIDSKLAD_USER)
{
Object->UserInfoIDSKLAD_USER=UserInfoIDSKLAD_USER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDTPRICE_USER(void)
{
return Object->UserInfoIDTPRICE_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDTPRICE_USER(TFIBBCDField * UserInfoIDTPRICE_USER)
{
Object->UserInfoIDTPRICE_USER=UserInfoIDTPRICE_USER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDTPRICE1_USER(void)
{
return Object->UserInfoIDTPRICE1_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDTPRICE1_USER(TFIBBCDField * UserInfoIDTPRICE1_USER)
{
Object->UserInfoIDTPRICE1_USER=UserInfoIDTPRICE1_USER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDTPRICE2_USER(void)
{
return Object->UserInfoIDTPRICE2_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDTPRICE2_USER(TFIBBCDField * UserInfoIDTPRICE2_USER)
{
Object->UserInfoIDTPRICE2_USER=UserInfoIDTPRICE2_USER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDBSCHET_USER(void)
{
return Object->UserInfoIDBSCHET_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDBSCHET_USER(TFIBBCDField * UserInfoIDBSCHET_USER)
{
Object->UserInfoIDBSCHET_USER=UserInfoIDBSCHET_USER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDGRP_USER(void)
{
return Object->UserInfoIDGRP_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDGRP_USER(TFIBBCDField * UserInfoIDGRP_USER)
{
Object->UserInfoIDGRP_USER=UserInfoIDGRP_USER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDKASSA_USER(void)
{
return Object->UserInfoIDKASSA_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDKASSA_USER(TFIBBCDField * UserInfoIDKASSA_USER)
{
Object->UserInfoIDKASSA_USER=UserInfoIDKASSA_USER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDBASE_SUSER(void)
{
return Object->UserInfoIDBASE_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDBASE_SUSER(TFIBBCDField * UserInfoIDBASE_SUSER)
{
Object->UserInfoIDBASE_SUSER=UserInfoIDBASE_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoREOPEN_GUR_SUSER(void)
{
return Object->UserInfoREOPEN_GUR_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoREOPEN_GUR_SUSER(TFIBSmallIntField * UserInfoREOPEN_GUR_SUSER)
{
Object->UserInfoREOPEN_GUR_SUSER=UserInfoREOPEN_GUR_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoREOPEN_SPR_SUSER(void)
{
return Object->UserInfoREOPEN_SPR_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoREOPEN_SPR_SUSER(TFIBSmallIntField * UserInfoREOPEN_SPR_SUSER)
{
Object->UserInfoREOPEN_SPR_SUSER=UserInfoREOPEN_SPR_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoSPRNOM_OST_SUSER(void)
{
return Object->UserInfoSPRNOM_OST_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoSPRNOM_OST_SUSER(TFIBSmallIntField * UserInfoSPRNOM_OST_SUSER)
{
Object->UserInfoSPRNOM_OST_SUSER=UserInfoSPRNOM_OST_SUSER;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMFibConnectionImpl::get_UserInfoEDIT_CHUG_DOC_SUSER(void)
{
return Object->UserInfoEDIT_CHUG_DOC_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoEDIT_CHUG_DOC_SUSER(TFIBIntegerField * UserInfoEDIT_CHUG_DOC_SUSER)
{
Object->UserInfoEDIT_CHUG_DOC_SUSER=UserInfoEDIT_CHUG_DOC_SUSER;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMFibConnectionImpl::get_UserInfoDEL_CHUG_DOC_SUSER(void)
{
return Object->UserInfoDEL_CHUG_DOC_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoDEL_CHUG_DOC_SUSER(TFIBIntegerField * UserInfoDEL_CHUG_DOC_SUSER)
{
Object->UserInfoDEL_CHUG_DOC_SUSER=UserInfoDEL_CHUG_DOC_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoSHOW_LOG_SUSER(void)
{
return Object->UserInfoSHOW_LOG_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoSHOW_LOG_SUSER(TFIBSmallIntField * UserInfoSHOW_LOG_SUSER)
{
Object->UserInfoSHOW_LOG_SUSER=UserInfoSHOW_LOG_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoDETALIED_LOG_SUSER(void)
{
return Object->UserInfoDETALIED_LOG_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoDETALIED_LOG_SUSER(TFIBSmallIntField * UserInfoDETALIED_LOG_SUSER)
{
Object->UserInfoDETALIED_LOG_SUSER=UserInfoDETALIED_LOG_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoSAVENAME_SUSER(void)
{
return Object->UserInfoSAVENAME_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoSAVENAME_SUSER(TFIBSmallIntField * UserInfoSAVENAME_SUSER)
{
Object->UserInfoSAVENAME_SUSER=UserInfoSAVENAME_SUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAME_USER(void)
{
return Object->UserInfoNAME_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAME_USER(TFIBWideStringField * UserInfoNAME_USER)
{
Object->UserInfoNAME_USER=UserInfoNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoFNAME_USER(void)
{
return Object->UserInfoFNAME_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoFNAME_USER(TFIBWideStringField * UserInfoFNAME_USER)
{
Object->UserInfoFNAME_USER=UserInfoFNAME_USER;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMFibConnectionImpl::get_UserInfoINTERF_USER(void)
{
return Object->UserInfoINTERF_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoINTERF_USER(TFIBIntegerField * UserInfoINTERF_USER)
{
Object->UserInfoINTERF_USER=UserInfoINTERF_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAMEPOD(void)
{
return Object->UserInfoNAMEPOD;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAMEPOD(TFIBWideStringField * UserInfoNAMEPOD)
{
Object->UserInfoNAMEPOD=UserInfoNAMEPOD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAMEFIRM(void)
{
return Object->UserInfoNAMEFIRM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAMEFIRM(TFIBWideStringField * UserInfoNAMEFIRM)
{
Object->UserInfoNAMEFIRM=UserInfoNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAMESKLAD(void)
{
return Object->UserInfoNAMESKLAD;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAMESKLAD(TFIBWideStringField * UserInfoNAMESKLAD)
{
Object->UserInfoNAMESKLAD=UserInfoNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAME_TPRICE(void)
{
return Object->UserInfoNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAME_TPRICE(TFIBWideStringField * UserInfoNAME_TPRICE)
{
Object->UserInfoNAME_TPRICE=UserInfoNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAME_SINFBASE_OBMEN(void)
{
return Object->UserInfoNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAME_SINFBASE_OBMEN(TFIBWideStringField * UserInfoNAME_SINFBASE_OBMEN)
{
Object->UserInfoNAME_SINFBASE_OBMEN=UserInfoNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAMEBSCHET(void)
{
return Object->UserInfoNAMEBSCHET;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAMEBSCHET(TFIBWideStringField * UserInfoNAMEBSCHET)
{
Object->UserInfoNAMEBSCHET=UserInfoNAMEBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAMEKKM(void)
{
return Object->UserInfoNAMEKKM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAMEKKM(TFIBWideStringField * UserInfoNAMEKKM)
{
Object->UserInfoNAMEKKM=UserInfoNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAME2_USER(void)
{
return Object->UserInfoNAME2_USER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAME2_USER(TFIBWideStringField * UserInfoNAME2_USER)
{
Object->UserInfoNAME2_USER=UserInfoNAME2_USER;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMFibConnectionImpl::get_TransactionUserInfo(void)
{
return Object->TransactionUserInfo;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_TransactionUserInfo(TpFIBTransaction * TransactionUserInfo)
{
Object->TransactionUserInfo=TransactionUserInfo;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMFibConnectionImpl::get_Transaction(void)
{
return Object->Transaction;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_Transaction(TpFIBTransaction * Transaction)
{
Object->Transaction=Transaction;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMFibConnectionImpl::get_ARMInfo(void)
{
return Object->ARMInfo;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfo(TpFIBDataSet * ARMInfo)
{
Object->ARMInfo=ARMInfo;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoID_SARM(void)
{
return Object->ARMInfoID_SARM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoID_SARM(TFIBLargeIntField * ARMInfoID_SARM)
{
Object->ARMInfoID_SARM=ARMInfoID_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAME_SARM(void)
{
return Object->ARMInfoNAME_SARM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAME_SARM(TFIBWideStringField * ARMInfoNAME_SARM)
{
Object->ARMInfoNAME_SARM=ARMInfoNAME_SARM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMFibConnectionImpl::get_ARMInfoCODE_SARM(void)
{
return Object->ARMInfoCODE_SARM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoCODE_SARM(TFIBIntegerField * ARMInfoCODE_SARM)
{
Object->ARMInfoCODE_SARM=ARMInfoCODE_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDFIRM_SARM(void)
{
return Object->ARMInfoIDFIRM_SARM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDFIRM_SARM(TFIBLargeIntField * ARMInfoIDFIRM_SARM)
{
Object->ARMInfoIDFIRM_SARM=ARMInfoIDFIRM_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDSKLAD_SARM(void)
{
return Object->ARMInfoIDSKLAD_SARM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDSKLAD_SARM(TFIBLargeIntField * ARMInfoIDSKLAD_SARM)
{
Object->ARMInfoIDSKLAD_SARM=ARMInfoIDSKLAD_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDPODR_SARM(void)
{
return Object->ARMInfoIDPODR_SARM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDPODR_SARM(TFIBLargeIntField * ARMInfoIDPODR_SARM)
{
Object->ARMInfoIDPODR_SARM=ARMInfoIDPODR_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDKKM_SARM(void)
{
return Object->ARMInfoIDKKM_SARM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDKKM_SARM(TFIBLargeIntField * ARMInfoIDKKM_SARM)
{
Object->ARMInfoIDKKM_SARM=ARMInfoIDKKM_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoSTRPAR_SARM(void)
{
return Object->ARMInfoSTRPAR_SARM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoSTRPAR_SARM(TFIBWideStringField * ARMInfoSTRPAR_SARM)
{
Object->ARMInfoSTRPAR_SARM=ARMInfoSTRPAR_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAMEFIRM(void)
{
return Object->ARMInfoNAMEFIRM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAMEFIRM(TFIBWideStringField * ARMInfoNAMEFIRM)
{
Object->ARMInfoNAMEFIRM=ARMInfoNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAMESKLAD(void)
{
return Object->ARMInfoNAMESKLAD;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAMESKLAD(TFIBWideStringField * ARMInfoNAMESKLAD)
{
Object->ARMInfoNAMESKLAD=ARMInfoNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAMEKKM(void)
{
return Object->ARMInfoNAMEKKM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAMEKKM(TFIBWideStringField * ARMInfoNAMEKKM)
{
Object->ARMInfoNAMEKKM=ARMInfoNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAMEPOD(void)
{
return Object->ARMInfoNAMEPOD;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAMEPOD(TFIBWideStringField * ARMInfoNAMEPOD)
{
Object->ARMInfoNAMEPOD=ARMInfoNAMEPOD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDTPRICEPOD(void)
{
return Object->ARMInfoIDTPRICEPOD;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDTPRICEPOD(TFIBLargeIntField * ARMInfoIDTPRICEPOD)
{
Object->ARMInfoIDTPRICEPOD=ARMInfoIDTPRICEPOD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAME_TPRICE(void)
{
return Object->ARMInfoNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAME_TPRICE(TFIBWideStringField * ARMInfoNAME_TPRICE)
{
Object->ARMInfoNAME_TPRICE=ARMInfoNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAME_SINFBASE_OBMEN(void)
{
return Object->ARMInfoNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAME_SINFBASE_OBMEN(TFIBWideStringField * ARMInfoNAME_SINFBASE_OBMEN)
{
Object->ARMInfoNAME_SINFBASE_OBMEN=ARMInfoNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMFibConnectionImpl::get_TransactionARM(void)
{
return Object->TransactionARM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_TransactionARM(TpFIBTransaction * TransactionARM)
{
Object->TransactionARM=TransactionARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDBASE_SARM(void)
{
return Object->ARMInfoIDBASE_SARM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDBASE_SARM(TFIBLargeIntField * ARMInfoIDBASE_SARM)
{
Object->ARMInfoIDBASE_SARM=ARMInfoIDBASE_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAME_REM_SACTCATEGORY(void)
{
return Object->UserInfoNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAME_REM_SACTCATEGORY(TFIBWideStringField * UserInfoNAME_REM_SACTCATEGORY)
{
Object->UserInfoNAME_REM_SACTCATEGORY=UserInfoNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDACTCATEGORY_SARM(void)
{
return Object->ARMInfoIDACTCATEGORY_SARM;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDACTCATEGORY_SARM(TFIBLargeIntField * ARMInfoIDACTCATEGORY_SARM)
{
Object->ARMInfoIDACTCATEGORY_SARM=ARMInfoIDACTCATEGORY_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAME_REM_SACTCATEGORY(void)
{
return Object->ARMInfoNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAME_REM_SACTCATEGORY(TFIBWideStringField * ARMInfoNAME_REM_SACTCATEGORY)
{
Object->ARMInfoNAME_REM_SACTCATEGORY=ARMInfoNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDACTCATEGORY_SUSER(void)
{
return Object->UserInfoIDACTCATEGORY_SUSER;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDACTCATEGORY_SUSER(TFIBBCDField * UserInfoIDACTCATEGORY_SUSER)
{
Object->UserInfoIDACTCATEGORY_SUSER=UserInfoIDACTCATEGORY_SUSER;
}
//---------------------------------------------------------------
UnicodeString TDMFibConnectionImpl::get_NameServer(void)
{
return Object->NameServer;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_NameServer(UnicodeString NameServer)
{
Object->NameServer=NameServer;
}
//---------------------------------------------------------------
UnicodeString TDMFibConnectionImpl::get_ConnectString(void)
{
return Object->ConnectString;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ConnectString(UnicodeString ConnectString)
{
Object->ConnectString=ConnectString;
}
//---------------------------------------------------------------
UnicodeString TDMFibConnectionImpl::get_NameUser(void)
{
return Object->NameUser;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_NameUser(UnicodeString NameUser)
{
Object->NameUser=NameUser;
}
//---------------------------------------------------------------
UnicodeString TDMFibConnectionImpl::get_NameUser2(void)
{
return Object->NameUser2;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_NameUser2(UnicodeString NameUser2)
{
Object->NameUser2=NameUser2;
}
//---------------------------------------------------------------
UnicodeString TDMFibConnectionImpl::get_PasswordUser(void)
{
return Object->PasswordUser;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_PasswordUser(UnicodeString PasswordUser)
{
Object->PasswordUser=PasswordUser;
}
//---------------------------------------------------------------
UnicodeString TDMFibConnectionImpl::get_glCatalogProtocol(void)
{
return Object->glCatalogProtocol;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_glCatalogProtocol(UnicodeString glCatalogProtocol)
{
Object->glCatalogProtocol=glCatalogProtocol;
}
//---------------------------------------------------------------
int TDMFibConnectionImpl::get_CodeUser(void)
{
return Object->CodeUser;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_CodeUser(int CodeUser)
{
Object->CodeUser=CodeUser;
}
//---------------------------------------------------------------
UnicodeString TDMFibConnectionImpl::get_TextVipOper(void)
{
return Object->TextVipOper;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_TextVipOper(UnicodeString TextVipOper)
{
Object->TextVipOper=TextVipOper;
}
//---------------------------------------------------------------
int TDMFibConnectionImpl::get_TypeApplication(void)
{
return Object->TypeApplication;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_TypeApplication(int TypeApplication)
{
Object->TypeApplication=TypeApplication;
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::get_ExecPriv(void)
{
return Object->ExecPriv;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_ExecPriv(bool ExecPriv)
{
Object->ExecPriv=ExecPriv;
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::get_InsertPriv(void)
{
return Object->InsertPriv;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_InsertPriv(bool InsertPriv)
{
Object->InsertPriv=InsertPriv;
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::get_EditPriv(void)
{
return Object->EditPriv;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_EditPriv(bool EditPriv)
{
Object->EditPriv=EditPriv;
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::get_DeletePriv(void)
{
return Object->DeletePriv;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_DeletePriv(bool DeletePriv)
{
Object->DeletePriv=DeletePriv;
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::get_glShowNDS(void)
{
return Object->glShowNDS;
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::set_glShowNDS(bool glShowNDS)
{
Object->glShowNDS=glShowNDS;
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::GlobConnect(void)
{
return Object->GlobConnect();
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::GlobConnect2(void)
{
return Object->GlobConnect2();
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::GlobConnect3(void)
{
return Object->GlobConnect3();
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::DisconnectBase(void)
{
return Object->DisconnectBase();
}
//---------------------------------------------------------------
UnicodeString TDMFibConnectionImpl::GetNameServer(UnicodeString connect_string)
{
return Object->GetNameServer(connect_string);
}
//---------------------------------------------------------------
UnicodeString TDMFibConnectionImpl::GetVersionBase(void)
{
return Object->GetVersionBase();
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::CheckEnableStart(UnicodeString role_user)
{
return Object->CheckEnableStart(role_user);
}
//---------------------------------------------------------------
__int64 TDMFibConnectionImpl::FindPoName(UnicodeString name_user)
{
return Object->FindPoName(name_user);
}
//---------------------------------------------------------------
__int64 TDMFibConnectionImpl::FindPoPassword(UnicodeString password)
{
return Object->FindPoPassword(password);
}
//---------------------------------------------------------------
__int64 TDMFibConnectionImpl::GetIdGrpUser(__int64 id_user)
{
return Object->GetIdGrpUser(id_user);
}
//---------------------------------------------------------------
TDateTime TDMFibConnectionImpl::GetPosNachReport(void)
{
return Object->GetPosNachReport();
}
//---------------------------------------------------------------
TDateTime TDMFibConnectionImpl::GetPosNachGurnal(void)
{
return Object->GetPosNachGurnal();
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::OpenUserInfo(__int64 id)
{
return Object->OpenUserInfo(id);
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::GetPrivDM(int object)
{
return Object->GetPrivDM(object);
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::GetPrivForm(int object)
{
return Object->GetPrivForm(object);
}
//---------------------------------------------------------------
bool TDMFibConnectionImpl::OpenARMInfo(int code_arm)
{
return Object->OpenARMInfo(code_arm);
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::glSaveProtocol(UnicodeString str)
{
return Object->glSaveProtocol(str);
}
//---------------------------------------------------------------
void TDMFibConnectionImpl::AddLog(__int64 id_user,int type,int object,int oper,UnicodeString message,UnicodeString code_object,__int64 id_object,int subsystem)
{
return Object->AddLog(id_user,type,object,oper,message,code_object,id_object,subsystem);
}
//---------------------------------------------------------------
UnicodeString TDMFibConnectionImpl::Arm_GetParameter(UnicodeString parameter)
{
return Object->Arm_GetParameter(parameter);
}
//---------------------------------------------------------------
