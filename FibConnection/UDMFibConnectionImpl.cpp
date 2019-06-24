//---------------------------------------------------------------------------


#pragma hdrstop

#include "UDMFibConnectionImpl.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------------------
TDMFibConnectionImpl::TDMFibConnectionImpl()
{

DM=new TDMFibConnection(Application);
NumRefs=0;
++NumObject;
}
//----------------------------------------------------------------------------
TDMFibConnectionImpl::~TDMFibConnectionImpl()
{

delete DM;
--NumObject;
}
//----------------------------------------------------------------------------
int TDMFibConnectionImpl::kanQueryInterface(REFIID id_interface, void ** ppv)
{
int result=0;

if (id_interface==IID_IkanUnknown)
	{
	*ppv=static_cast<IkanUnknown*> (this);
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
//---------------------------------------------------------------------------
int TDMFibConnectionImpl::kanAddRef(void)
{

return (++NumRefs);
}
//----------------------------------------------------------------------------
int TDMFibConnectionImpl::kanRelease(void)
{

if (--NumRefs==0)
	{
	delete this;
	return 0;
	}
return NumRefs;
}
//-----------------------------------------------------------------------------
bool TDMFibConnectionImpl::GlobConnect(void)
{
return DM->GlobConnect();
}
//-----------------------------------------------------------------------------
bool TDMFibConnectionImpl::GlobConnect2(void)
{

return DM->GlobConnect2();
}
//-----------------------------------------------------------------------------
bool TDMFibConnectionImpl::GlobConnect3(void)
{

return DM->GlobConnect3();
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::DisconnectBase(void)
{

DM->DisconnectBase();
}
//-----------------------------------------------------------------------------
UnicodeString TDMFibConnectionImpl::GetNameServer(UnicodeString connect_string)
{

return DM->GetNameServer(connect_string);
}
//-----------------------------------------------------------------------------
UnicodeString TDMFibConnectionImpl::GetVersionBase(void)
{

return DM->GetVersionBase() ;
}
//-----------------------------------------------------------------------------
bool TDMFibConnectionImpl::CheckEnableStart(UnicodeString role_user)
{

return DM->CheckEnableStart(role_user);
}
//-----------------------------------------------------------------------------
__int64 TDMFibConnectionImpl::FindPoName(UnicodeString name_user)
{

return DM->FindPoName(name_user);
}
//-----------------------------------------------------------------------------
__int64 TDMFibConnectionImpl::FindPoPassword(UnicodeString password)
{

return DM->FindPoPassword(password);
}
//-----------------------------------------------------------------------------
__int64 TDMFibConnectionImpl::GetIdGrpUser(__int64 id_user)
{

return DM->GetIdGrpUser(id_user);
}
//-----------------------------------------------------------------------------

TDateTime TDMFibConnectionImpl::GetPosNachReport(void)
{

return DM->GetPosNachReport();
}
//-----------------------------------------------------------------------------
TDateTime TDMFibConnectionImpl::GetPosNachGurnal(void)
{

return DM->GetPosNachGurnal();
}
//-----------------------------------------------------------------------------

bool TDMFibConnectionImpl::OpenUserInfo(__int64 id)
{

return DM->OpenUserInfo(id);
}
//-----------------------------------------------------------------------------
bool TDMFibConnectionImpl::GetPrivDM(int object)
{

return DM->GetPrivDM(object);
}
//-----------------------------------------------------------------------------
		//application 1 обычное, 2 WEB
bool TDMFibConnectionImpl::GetPrivForm(int object)
{

return DM->GetPrivForm(object);
}
//-----------------------------------------------------------------------------
bool TDMFibConnectionImpl::OpenARMInfo(int code_arm)
{

return DM->OpenARMInfo(code_arm);
}
//-----------------------------------------------------------------------------


void TDMFibConnectionImpl::glSaveProtocol(UnicodeString str)
{

DM->glSaveProtocol(str);
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::AddLog(__int64 id_user,
					int type,
					int object,
					int oper,
					UnicodeString message,
					UnicodeString code_object,
					__int64 id_object,
					int subsystem)
{

DM->AddLog(id_user,
					type,
					object,
					oper,
					message,
					code_object,
					id_object,
					subsystem);
}
//-----------------------------------------------------------------------------
//type
//1 сообщение
//2 предупреждение
//3 ошибка
//4 запрещенное действие
//object
//1 справочник
//2 документ
//3 журнал
//4 отчет
//5 сервис
//oper
//  1 вставка
//  2 редактирование
//  3 удаление

UnicodeString TDMFibConnectionImpl::Arm_GetParameter(UnicodeString parameter)
{

return DM->Arm_GetParameter(parameter);
}
//-----------------------------------------------------------------------------


  //методы свойств
TpFIBDatabase * TDMFibConnectionImpl::get_pFIBData(void)
{

return DM->pFIBData;
}
//-----------------------------------------------------------------------------
void   TDMFibConnectionImpl::set_pFIBData(TpFIBDatabase * pFIBData)
{

DM->pFIBData=pFIBData;
}
//-----------------------------------------------------------------------------

TpFIBQuery * TDMFibConnectionImpl::get_pFIBQLog(void)
{

return DM->pFIBQLog;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_pFIBQLog(TpFIBQuery *pFIBQLog)
{

DM->pFIBQLog=pFIBQLog;
}
//-----------------------------------------------------------------------------

TpFIBTransaction * TDMFibConnectionImpl::get_pFIBTrLog(void)
{

return DM->pFIBTrLog;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_pFIBTrLog(TpFIBTransaction *pFIBTrLog)
{

DM->pFIBTrLog=pFIBTrLog;
}
//-----------------------------------------------------------------------------

TpFIBQuery *  TDMFibConnectionImpl::get_Query(void)
{

return DM->Query;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_Query(TpFIBQuery *Query)
{

DM->Query=Query;
}
//-----------------------------------------------------------------------------

TpFIBDataSet *TDMFibConnectionImpl::get_UserInfo(void)
{

return DM->UserInfo;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfo(TpFIBDataSet *UserInfo)
{

DM->UserInfo=UserInfo;
}
//-----------------------------------------------------------------------------

TFIBSmallIntField *TDMFibConnectionImpl::get_UserInfoTPOSREPORT_SUSER(void)
{

return DM->UserInfoTPOSREPORT_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoTPOSREPORT_SUSER(TFIBSmallIntField * UserInfoTPOSREPORT_SUSER)
{

DM->UserInfoTPOSREPORT_SUSER=UserInfoTPOSREPORT_SUSER;
}
//-----------------------------------------------------------------------------

TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoTPOSGOURNAL_SUSER(void)
{

return DM->UserInfoTPOSGOURNAL_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoTPOSGOURNAL_SUSER(TFIBSmallIntField *UserInfoTPOSGOURNAL_SUSER)
{

DM->UserInfoTPOSGOURNAL_SUSER=UserInfoTPOSGOURNAL_SUSER;
}
//-----------------------------------------------------------------------------

TFIBSmallIntField *TDMFibConnectionImpl::get_UserInfoKOLDAYREP_SUSER(void)
{

return  DM->UserInfoKOLDAYREP_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoKOLDAYREP_SUSER(TFIBSmallIntField *UserInfoKOLDAYREP_SUSER)
{

DM->UserInfoKOLDAYREP_SUSER=DM->UserInfoKOLDAYREP_SUSER;
}
//-----------------------------------------------------------------------------

TFIBSmallIntField *TDMFibConnectionImpl::get_UserInfoKOLDAYGUR_SUSER(void)
{

return DM->UserInfoKOLDAYGUR_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoKOLDAYGUR_SUSER(void)
{

DM->UserInfoKOLDAYGUR_SUSER=UserInfoKOLDAYGUR_SUSER;
}
//-----------------------------------------------------------------------------

TFIBBCDField * TDMFibConnectionImpl::get_UserInfoID_USER(void)
{

return DM->UserInfoID_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoID_USER(TFIBBCDField *UserInfoID_USER)
{

DM->UserInfoID_USER=UserInfoID_USER;
}
//-----------------------------------------------------------------------------

TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDPOD_USER(void)
{

return DM->UserInfoIDPOD_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDPOD_USER(TFIBBCDField *UserInfoIDPOD_USER)
{

DM->UserInfoIDPOD_USER=UserInfoIDPOD_USER;
}
//-----------------------------------------------------------------------------

TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDFIRM_USER(void)
{

return DM->UserInfoIDFIRM_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDFIRM_USER(TFIBBCDField *UserInfoIDFIRM_USER)
{

DM->UserInfoIDFIRM_USER=UserInfoIDFIRM_USER;
}
//-----------------------------------------------------------------------------

TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDSKLAD_USER(void)
{

return DM->UserInfoIDSKLAD_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDSKLAD_USER(TFIBBCDField *UserInfoIDSKLAD_USER)
{

DM->UserInfoIDSKLAD_USER=UserInfoIDSKLAD_USER;
}
//-----------------------------------------------------------------------------

TFIBBCDField *TDMFibConnectionImpl::get_UserInfoIDTPRICE_USER(void)
{

return DM->UserInfoIDTPRICE_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDTPRICE_USER(TFIBBCDField *UserInfoIDTPRICE_USER)
{

DM->UserInfoIDTPRICE_USER=UserInfoIDTPRICE_USER;
}
//-----------------------------------------------------------------------------

TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDTPRICE1_USER(void)
{

return DM->UserInfoIDTPRICE1_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDTPRICE1_USER(TFIBBCDField *UserInfoIDTPRICE1_USER)
{

DM->UserInfoIDTPRICE1_USER=UserInfoIDTPRICE1_USER;
}
//-----------------------------------------------------------------------------

TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDTPRICE2_USER(void)
{

return DM->UserInfoIDTPRICE2_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDTPRICE2_USER(TFIBBCDField *UserInfoIDTPRICE2_USER)
{

DM->UserInfoIDTPRICE2_USER=UserInfoIDTPRICE2_USER;
}
//-----------------------------------------------------------------------------

TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDBSCHET_USER(void)
{

return DM->UserInfoIDBSCHET_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDBSCHET_USER(TFIBBCDField *UserInfoIDBSCHET_USER)
{

DM->UserInfoIDBSCHET_USER=UserInfoIDBSCHET_USER;
}
//-----------------------------------------------------------------------------

TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDGRP_USER(void)
{

return DM->UserInfoIDGRP_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDGRP_USER(TFIBBCDField *UserInfoIDGRP_USER)
{

DM->UserInfoIDGRP_USER=UserInfoIDGRP_USER;
}
//-----------------------------------------------------------------------------

TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDKASSA_USER(void)
{

return DM->UserInfoIDKASSA_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDKASSA_USER(TFIBBCDField *UserInfoIDKASSA_USER)
{

DM->UserInfoIDKASSA_USER=UserInfoIDKASSA_USER;
}
//-----------------------------------------------------------------------------

TFIBBCDField * TDMFibConnectionImpl::get_UserInfoIDBASE_SUSER(void)
{

return DM->UserInfoIDBASE_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoIDBASE_SUSER(TFIBBCDField *UserInfoIDBASE_SUSER)
{

DM->UserInfoIDBASE_SUSER=UserInfoIDBASE_SUSER;
}
//-----------------------------------------------------------------------------

TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoREOPEN_GUR_SUSER(void)
{

return DM->UserInfoREOPEN_GUR_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoREOPEN_GUR_SUSER(TFIBSmallIntField *UserInfoREOPEN_GUR_SUSER)
{

DM->UserInfoREOPEN_GUR_SUSER=UserInfoREOPEN_GUR_SUSER;
}
//-----------------------------------------------------------------------------

TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoREOPEN_SPR_SUSER(void)
{

return DM->UserInfoREOPEN_SPR_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoREOPEN_SPR_SUSER(TFIBSmallIntField *UserInfoREOPEN_SPR_SUSER)
{

DM->UserInfoREOPEN_SPR_SUSER=UserInfoREOPEN_SPR_SUSER;
}
//-----------------------------------------------------------------------------

TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoSPRNOM_OST_SUSER(void)
{

return DM->UserInfoSPRNOM_OST_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoSPRNOM_OST_SUSER(TFIBSmallIntField *UserInfoSPRNOM_OST_SUSER)
{

DM->UserInfoSPRNOM_OST_SUSER=UserInfoSPRNOM_OST_SUSER;
}
//-----------------------------------------------------------------------------

TFIBIntegerField * TDMFibConnectionImpl::get_UserInfoEDIT_CHUG_DOC_SUSER(void)
{

return DM->UserInfoEDIT_CHUG_DOC_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoEDIT_CHUG_DOC_SUSER(TFIBIntegerField *UserInfoEDIT_CHUG_DOC_SUSER)
{

DM->UserInfoEDIT_CHUG_DOC_SUSER=UserInfoEDIT_CHUG_DOC_SUSER;
}
//-----------------------------------------------------------------------------

TFIBIntegerField * TDMFibConnectionImpl::get_UserInfoDEL_CHUG_DOC_SUSER(void)
{

return DM->UserInfoDEL_CHUG_DOC_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoDEL_CHUG_DOC_SUSER(TFIBIntegerField *UserInfoDEL_CHUG_DOC_SUSER)
{

DM->UserInfoDEL_CHUG_DOC_SUSER=UserInfoDEL_CHUG_DOC_SUSER;
}
//-----------------------------------------------------------------------------

TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoSHOW_LOG_SUSER(void)
{

return DM->UserInfoSHOW_LOG_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoSHOW_LOG_SUSER(TFIBSmallIntField *UserInfoSHOW_LOG_SUSER)
{

DM->UserInfoSHOW_LOG_SUSER=UserInfoSHOW_LOG_SUSER;
}
//-----------------------------------------------------------------------------

TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoDETALIED_LOG_SUSER(void)
{

return DM->UserInfoDETALIED_LOG_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoDETALIED_LOG_SUSER(TFIBSmallIntField *UserInfoDETALIED_LOG_SUSER)
{

DM->UserInfoDETALIED_LOG_SUSER=UserInfoDETALIED_LOG_SUSER;
}
//-----------------------------------------------------------------------------

TFIBSmallIntField * TDMFibConnectionImpl::get_UserInfoSAVENAME_SUSER(void)
{

return DM->UserInfoSAVENAME_SUSER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoSAVENAME_SUSER(TFIBSmallIntField *UserInfoSAVENAME_SUSER)
{

DM->UserInfoSAVENAME_SUSER=UserInfoSAVENAME_SUSER;
}
//-----------------------------------------------------------------------------


TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAME_USER(void)
{

return DM->UserInfoNAME_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAME_USER(TFIBWideStringField *UserInfoNAME_USER)
{

DM->UserInfoNAME_USER=UserInfoNAME_USER;
}
//-----------------------------------------------------------------------------

TFIBWideStringField *  TDMFibConnectionImpl::get_UserInfoFNAME_USER(void)
{

return DM->UserInfoFNAME_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoFNAME_USER(TFIBWideStringField *UserInfoFNAME_USER)
{

DM->UserInfoFNAME_USER=UserInfoFNAME_USER;
}
//-----------------------------------------------------------------------------

TFIBIntegerField *  TDMFibConnectionImpl::get_UserInfoINTERF_USER(void)
{

return DM->UserInfoINTERF_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoINTERF_USER(TFIBIntegerField *UserInfoINTERF_USER)
{

DM->UserInfoINTERF_USER=UserInfoINTERF_USER;
}
//-----------------------------------------------------------------------------

TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAMEPOD(void)
{

return DM->UserInfoNAMEPOD;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAMEPOD(TFIBWideStringField *UserInfoNAMEPOD)
{

DM->UserInfoNAMEPOD=UserInfoNAMEPOD;
}
//-----------------------------------------------------------------------------

TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAMEFIRM(void)
{

return DM->UserInfoNAMEFIRM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAMEFIRM(TFIBWideStringField *UserInfoNAMEFIRM)
{

DM->UserInfoNAMEFIRM=UserInfoNAMEFIRM;
}
//-----------------------------------------------------------------------------

TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAMESKLAD(void)
{

return DM->UserInfoNAMESKLAD;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAMESKLAD(TFIBWideStringField *UserInfoNAMESKLAD)
{

DM->UserInfoNAMESKLAD=UserInfoNAMESKLAD;
}
//-----------------------------------------------------------------------------

TFIBWideStringField *  TDMFibConnectionImpl::get_UserInfoNAME_TPRICE(void)
{

return DM->UserInfoNAME_TPRICE;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAME_TPRICE(TFIBWideStringField *UserInfoNAME_TPRICE)
{

DM->UserInfoNAME_TPRICE=UserInfoNAME_TPRICE;
}
//-----------------------------------------------------------------------------

TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAME_SINFBASE_OBMEN(void)
{

return DM->UserInfoNAME_SINFBASE_OBMEN;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAME_SINFBASE_OBMEN(TFIBWideStringField *UserInfoNAME_SINFBASE_OBMEN)
{

DM->UserInfoNAME_SINFBASE_OBMEN=UserInfoNAME_SINFBASE_OBMEN;
}
//-----------------------------------------------------------------------------

TFIBWideStringField * TDMFibConnectionImpl::get_UserInfoNAMEBSCHET(void)
{

return DM->UserInfoNAMEBSCHET;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAMEBSCHET(TFIBWideStringField *UserInfoNAMEBSCHET)
{

DM->UserInfoNAMEBSCHET=UserInfoNAMEBSCHET;
}
//-----------------------------------------------------------------------------

TFIBWideStringField *  TDMFibConnectionImpl::get_UserInfoNAMEKKM(void)
{

return DM->UserInfoNAMEKKM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAMEKKM(TFIBWideStringField *UserInfoNAMEKKM)
{

DM->UserInfoNAMEKKM=UserInfoNAMEKKM;
}
//-----------------------------------------------------------------------------

TFIBWideStringField *  TDMFibConnectionImpl::get_UserInfoNAME2_USER(void)
{

return DM->UserInfoNAME2_USER;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_UserInfoNAME2_USER(TFIBWideStringField *UserInfoNAME2_USER)
{

DM->UserInfoNAME2_USER=UserInfoNAME2_USER;
}
//-----------------------------------------------------------------------------

TpFIBDataSet * TDMFibConnectionImpl::get_ARMInfo(void)
{

return DM->ARMInfo;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfo(TpFIBDataSet *ARMInfo)
{

DM->ARMInfo=ARMInfo;
}
//-----------------------------------------------------------------------------

TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoID_SARM(void)
{

return DM->ARMInfoID_SARM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoID_SARM(TFIBLargeIntField *ARMInfoID_SARM)
{

DM->ARMInfoID_SARM=ARMInfoID_SARM;
}
//-----------------------------------------------------------------------------

TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAME_SARM(void)
{

return DM->ARMInfoNAME_SARM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAME_SARM(TFIBWideStringField *ARMInfoNAME_SARM)
{

DM->ARMInfoNAME_SARM=ARMInfoNAME_SARM;
}
//-----------------------------------------------------------------------------

TFIBIntegerField * TDMFibConnectionImpl::get_ARMInfoCODE_SARM(void)
{

return DM->ARMInfoCODE_SARM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoCODE_SARM(TFIBIntegerField *ARMInfoCODE_SARM)
{

DM->ARMInfoCODE_SARM=ARMInfoCODE_SARM;
}
//-----------------------------------------------------------------------------

TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDFIRM_SARM(void)
{

return DM->ARMInfoIDFIRM_SARM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDFIRM_SARM(TFIBLargeIntField *ARMInfoIDFIRM_SARM)
{

DM->ARMInfoIDFIRM_SARM=ARMInfoIDFIRM_SARM;
}
//-----------------------------------------------------------------------------

TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDSKLAD_SARM(void)
{

return DM->ARMInfoIDSKLAD_SARM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDSKLAD_SARM (TFIBLargeIntField *ARMInfoIDSKLAD_SARM)
{

DM->ARMInfoIDSKLAD_SARM=ARMInfoIDSKLAD_SARM;
}
//-----------------------------------------------------------------------------

TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDPODR_SARM(void)
{

return DM->ARMInfoIDPODR_SARM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDPODR_SARM(TFIBLargeIntField *ARMInfoIDPODR_SARM)
{

DM->ARMInfoIDPODR_SARM=ARMInfoIDPODR_SARM;
}
//-----------------------------------------------------------------------------

TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDKKM_SARM(void)
{

return DM->ARMInfoIDKKM_SARM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDKKM_SARM(TFIBLargeIntField *ARMInfoIDKKM_SARM)
{

DM->ARMInfoIDKKM_SARM=ARMInfoIDKKM_SARM;
}
//-----------------------------------------------------------------------------

TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoSTRPAR_SARM(void)
{

return DM->ARMInfoSTRPAR_SARM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoSTRPAR_SARM(TFIBWideStringField *ARMInfoSTRPAR_SARM)
{

DM->ARMInfoSTRPAR_SARM=ARMInfoSTRPAR_SARM;
}
//-----------------------------------------------------------------------------

TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAMEFIRM(void)
{

return DM->ARMInfoNAMEFIRM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAMEFIRM(TFIBWideStringField *ARMInfoNAMEFIRM)
{

DM->ARMInfoNAMEFIRM=ARMInfoNAMEFIRM;
}
//-----------------------------------------------------------------------------

TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAMESKLAD(void)
{

return DM->ARMInfoNAMESKLAD;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAMESKLAD(TFIBWideStringField *ARMInfoNAMESKLAD)
{

DM->ARMInfoNAMESKLAD=ARMInfoNAMESKLAD;
}
//-----------------------------------------------------------------------------

TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAMEKKM(void)
{

return DM->ARMInfoNAMEKKM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAMEKKM(TFIBWideStringField *ARMInfoNAMEKKM)
{

DM->ARMInfoNAMEKKM=ARMInfoNAMEKKM;
}
//-----------------------------------------------------------------------------

TFIBWideStringField *  TDMFibConnectionImpl::get_ARMInfoNAMEPOD(void)
{

return DM->ARMInfoNAMEPOD;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAMEPOD(TFIBWideStringField *ARMInfoNAMEPOD)
{

DM->ARMInfoNAMEPOD=ARMInfoNAMEPOD;
}
//-----------------------------------------------------------------------------

TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDTPRICEPOD(void)
{

return DM->ARMInfoIDTPRICEPOD;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDTPRICEPOD(TFIBLargeIntField *ARMInfoIDTPRICEPOD)
{

DM->ARMInfoIDTPRICEPOD=ARMInfoIDTPRICEPOD;
}
//-----------------------------------------------------------------------------

TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAME_TPRICE(void)
{

return DM->ARMInfoNAME_TPRICE;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAME_TPRICE(TFIBWideStringField *ARMInfoNAME_TPRICE)
{

DM->ARMInfoNAME_TPRICE=ARMInfoNAME_TPRICE;
}
//-----------------------------------------------------------------------------

TFIBWideStringField * TDMFibConnectionImpl::get_ARMInfoNAME_SINFBASE_OBMEN(void)
{

return DM->ARMInfoNAME_SINFBASE_OBMEN;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoNAME_SINFBASE_OBMEN(TFIBWideStringField *ARMInfoNAME_SINFBASE_OBMEN)
{

DM->ARMInfoNAME_SINFBASE_OBMEN=ARMInfoNAME_SINFBASE_OBMEN;
}
//-----------------------------------------------------------------------------

TFIBLargeIntField * TDMFibConnectionImpl::get_ARMInfoIDBASE_SARM(void)
{

return DM->ARMInfoIDBASE_SARM;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ARMInfoIDBASE_SARM(TFIBLargeIntField *ARMInfoIDBASE_SARM)
{

DM->ARMInfoIDBASE_SARM=ARMInfoIDBASE_SARM;
}
//-----------------------------------------------------------------------------


UnicodeString  TDMFibConnectionImpl::get_NameServer(void)
{

return DM->NameServer;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_NameServer(UnicodeString NameServer)
{

DM->NameServer=NameServer;
}
//-----------------------------------------------------------------------------

UnicodeString  TDMFibConnectionImpl::get_ConnectString(void)
{

return DM->ConnectString;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ConnectString(UnicodeString ConnectString)
{

DM->ConnectString=ConnectString;
}
//-----------------------------------------------------------------------------

UnicodeString  TDMFibConnectionImpl::get_NameUser(void)
{

return DM->NameUser;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_NameUser(UnicodeString NameUser)
{

DM->NameUser=NameUser;
}
//-----------------------------------------------------------------------------

UnicodeString  TDMFibConnectionImpl::get_NameUser2(void)
{

return DM->NameUser2;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_NameUser2(UnicodeString NameUser2)
{

DM->NameUser2=NameUser2;
}
//-----------------------------------------------------------------------------

UnicodeString  TDMFibConnectionImpl::get_PasswordUser(void)
{

return DM->PasswordUser;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_PasswordUser(UnicodeString PasswordUser)
{

DM->PasswordUser=PasswordUser;
}
//-----------------------------------------------------------------------------

UnicodeString  TDMFibConnectionImpl::get_glCatalogProtocol(void)
{

return DM->glCatalogProtocol;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_glCatalogProtocol(UnicodeString glCatalogProtocol)
{

DM->glCatalogProtocol=glCatalogProtocol;
}
//-----------------------------------------------------------------------------

int  TDMFibConnectionImpl::get_CodeUser(void)
{

return DM->CodeUser;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_CodeUser(int CodeUser)
{

DM->CodeUser=CodeUser;
}
//-----------------------------------------------------------------------------

bool  TDMFibConnectionImpl::get_Error(void)
{

return DM->Error;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_Error(bool Error)
{

DM->Error=Error;
}
//-----------------------------------------------------------------------------

UnicodeString  TDMFibConnectionImpl::get_TextError(void)
{

return DM->TextError;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_TextError(UnicodeString TextError)
{

DM->TextError=TextError;
}
//-----------------------------------------------------------------------------

UnicodeString  TDMFibConnectionImpl::get_TextVipOper(void)
{

return DM->TextVipOper;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_TextVipOper(UnicodeString TextVipOper)
{

DM->TextVipOper=TextVipOper;
}
//-----------------------------------------------------------------------------

int  TDMFibConnectionImpl::get_TypeApplication(void)
{

return DM->TypeApplication;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_TypeApplication(int TypeApplication)
{

DM->TypeApplication=TypeApplication;
}
//-----------------------------------------------------------------------------

bool TDMFibConnectionImpl::get_ExecPriv(void)
{

 return DM->ExecPriv;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_ExecPriv(bool ExecPriv)
{

DM->ExecPriv=ExecPriv;
}
//-----------------------------------------------------------------------------

bool  TDMFibConnectionImpl::get_InsertPriv(void)
{

return DM->InsertPriv;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_InsertPriv(bool InsertPriv)
{

DM->InsertPriv=InsertPriv;
}
//-----------------------------------------------------------------------------

bool TDMFibConnectionImpl::get_EditPriv(void)
{

return DM->EditPriv;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_EditPriv(bool EditPriv)
{

DM->EditPriv=EditPriv;
}
//-----------------------------------------------------------------------------

bool  TDMFibConnectionImpl::get_DeletePriv(void)
{

return DM->DeletePriv;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_DeletePriv(bool DeletePriv)
{

DM->DeletePriv=DeletePriv;
}
//-----------------------------------------------------------------------------

bool  TDMFibConnectionImpl::get_glShowNDS(void)
{

return DM->glShowNDS;
}
//-----------------------------------------------------------------------------
void TDMFibConnectionImpl::set_glShowNDS(bool glShowNDS)
{

DM->glShowNDS=glShowNDS;
}
//-----------------------------------------------------------------------------
