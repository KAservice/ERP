#ifndef UREM_DMZayavkaImplH
#define UREM_DMZayavkaImplH
#include "IREM_DMZayavka.h"
#include "UREM_DMZayavka.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMZayavkaImpl)) TREM_DMZayavkaImpl : public IREM_DMZayavka
{
public:
   TREM_DMZayavkaImpl();
   ~TREM_DMZayavkaImpl();
   TREM_DMZayavka * Object;
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

//IREM_DMZayavka
   virtual TDataSource * get_DataSourceGurZKompl(void);
   virtual void set_DataSourceGurZKompl(TDataSource * DataSourceGurZKompl);

   virtual TDataSource * get_DataSourceGurZNeispr(void);
   virtual void set_DataSourceGurZNeispr(TDataSource * DataSourceGurZNeispr);

   virtual TDataSource * get_DataSourceGurZ(void);
   virtual void set_DataSourceGurZ(TDataSource * DataSourceGurZ);

   virtual TpFIBDataSet * get_GurZ(void);
   virtual void set_GurZ(TpFIBDataSet * GurZ);

   virtual TpFIBDataSet * get_GurZKompl(void);
   virtual void set_GurZKompl(TpFIBDataSet * GurZKompl);

   virtual TpFIBDataSet * get_GurZNeispr(void);
   virtual void set_GurZNeispr(TpFIBDataSet * GurZNeispr);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TIntegerField * get_GurZKomplRECNO(void);
   virtual void set_GurZKomplRECNO(TIntegerField * GurZKomplRECNO);

   virtual TIntegerField * get_GurZNeisprRECNO(void);
   virtual void set_GurZNeisprRECNO(TIntegerField * GurZNeisprRECNO);

   virtual TFIBLargeIntField * get_GurZID_REM_Z(void);
   virtual void set_GurZID_REM_Z(TFIBLargeIntField * GurZID_REM_Z);

   virtual TFIBWideStringField * get_GurZGID_REM_Z(void);
   virtual void set_GurZGID_REM_Z(TFIBWideStringField * GurZGID_REM_Z);

   virtual TFIBWideStringField * get_GurZPREFIKS_REM_Z(void);
   virtual void set_GurZPREFIKS_REM_Z(TFIBWideStringField * GurZPREFIKS_REM_Z);

   virtual TFIBIntegerField * get_GurZNUM_REM_Z(void);
   virtual void set_GurZNUM_REM_Z(TFIBIntegerField * GurZNUM_REM_Z);

   virtual TFIBDateTimeField * get_GurZPOS_REM_Z(void);
   virtual void set_GurZPOS_REM_Z(TFIBDateTimeField * GurZPOS_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDBASE_REM_Z(void);
   virtual void set_GurZIDBASE_REM_Z(TFIBLargeIntField * GurZIDBASE_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDMODEL_REM_Z(void);
   virtual void set_GurZIDMODEL_REM_Z(TFIBLargeIntField * GurZIDMODEL_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDSKLPR_REM_Z(void);
   virtual void set_GurZIDSKLPR_REM_Z(TFIBLargeIntField * GurZIDSKLPR_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDKLIENT_REM_Z(void);
   virtual void set_GurZIDKLIENT_REM_Z(TFIBLargeIntField * GurZIDKLIENT_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDDILER_REM_Z(void);
   virtual void set_GurZIDDILER_REM_Z(TFIBLargeIntField * GurZIDDILER_REM_Z);

   virtual TFIBWideStringField * get_GurZNAME_REM_Z(void);
   virtual void set_GurZNAME_REM_Z(TFIBWideStringField * GurZNAME_REM_Z);

   virtual TFIBWideStringField * get_GurZDESCR_REM_Z(void);
   virtual void set_GurZDESCR_REM_Z(TFIBWideStringField * GurZDESCR_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDTYPEREM_REM_Z(void);
   virtual void set_GurZIDTYPEREM_REM_Z(TFIBLargeIntField * GurZIDTYPEREM_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDSOST_REM_Z(void);
   virtual void set_GurZIDSOST_REM_Z(TFIBLargeIntField * GurZIDSOST_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDTECSKL_REM_Z(void);
   virtual void set_GurZIDTECSKL_REM_Z(TFIBLargeIntField * GurZIDTECSKL_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDUSER_REM_Z(void);
   virtual void set_GurZIDUSER_REM_Z(TFIBLargeIntField * GurZIDUSER_REM_Z);

   virtual TFIBIntegerField * get_GurZOPER_REM_Z(void);
   virtual void set_GurZOPER_REM_Z(TFIBIntegerField * GurZOPER_REM_Z);

   virtual TFIBBCDField * get_GurZSUM_REM_Z(void);
   virtual void set_GurZSUM_REM_Z(TFIBBCDField * GurZSUM_REM_Z);

   virtual TFIBDateField * get_GurZSROK_REM_Z(void);
   virtual void set_GurZSROK_REM_Z(TFIBDateField * GurZSROK_REM_Z);

   virtual TFIBSmallIntField * get_GurZOUT_REM_Z(void);
   virtual void set_GurZOUT_REM_Z(TFIBSmallIntField * GurZOUT_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDFIRM_REM_Z(void);
   virtual void set_GurZIDFIRM_REM_Z(TFIBLargeIntField * GurZIDFIRM_REM_Z);

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

   virtual TFIBWideStringField * get_GurZNAME_STREMONT(void);
   virtual void set_GurZNAME_STREMONT(TFIBWideStringField * GurZNAME_STREMONT);

   virtual TFIBWideStringField * get_GurZNAME_REMSSOST(void);
   virtual void set_GurZNAME_REMSSOST(TFIBWideStringField * GurZNAME_REMSSOST);

   virtual TFIBWideStringField * get_GurZNAME_SKLAD_TEC(void);
   virtual void set_GurZNAME_SKLAD_TEC(TFIBWideStringField * GurZNAME_SKLAD_TEC);

   virtual TFIBWideStringField * get_GurZNAME_USER(void);
   virtual void set_GurZNAME_USER(TFIBWideStringField * GurZNAME_USER);

   virtual TFIBLargeIntField * get_GurZKomplID_REM_ZKOMPL(void);
   virtual void set_GurZKomplID_REM_ZKOMPL(TFIBLargeIntField * GurZKomplID_REM_ZKOMPL);

   virtual TFIBWideStringField * get_GurZKomplGID_REM_ZKOMPL(void);
   virtual void set_GurZKomplGID_REM_ZKOMPL(TFIBWideStringField * GurZKomplGID_REM_ZKOMPL);

   virtual TFIBWideStringField * get_GurZKomplPREFIKS_REM_ZKOMPL(void);
   virtual void set_GurZKomplPREFIKS_REM_ZKOMPL(TFIBWideStringField * GurZKomplPREFIKS_REM_ZKOMPL);

   virtual TFIBLargeIntField * get_GurZKomplIDZ_REM_ZKOMPL(void);
   virtual void set_GurZKomplIDZ_REM_ZKOMPL(TFIBLargeIntField * GurZKomplIDZ_REM_ZKOMPL);

   virtual TFIBLargeIntField * get_GurZKomplIDKOMPL_REM_ZKOMPL(void);
   virtual void set_GurZKomplIDKOMPL_REM_ZKOMPL(TFIBLargeIntField * GurZKomplIDKOMPL_REM_ZKOMPL);

   virtual TFIBBCDField * get_GurZKomplKOL_REM_ZKOMPL(void);
   virtual void set_GurZKomplKOL_REM_ZKOMPL(TFIBBCDField * GurZKomplKOL_REM_ZKOMPL);

   virtual TFIBLargeIntField * get_GurZKomplIDBASE_REM_ZKOMPL(void);
   virtual void set_GurZKomplIDBASE_REM_ZKOMPL(TFIBLargeIntField * GurZKomplIDBASE_REM_ZKOMPL);

   virtual TFIBWideStringField * get_GurZKomplNAME_REM_SKOMPLMODEL(void);
   virtual void set_GurZKomplNAME_REM_SKOMPLMODEL(TFIBWideStringField * GurZKomplNAME_REM_SKOMPLMODEL);

   virtual TFIBLargeIntField * get_GurZNeisprID_REM_ZNEISPR(void);
   virtual void set_GurZNeisprID_REM_ZNEISPR(TFIBLargeIntField * GurZNeisprID_REM_ZNEISPR);

   virtual TFIBWideStringField * get_GurZNeisprGID_REM_ZNEISPR(void);
   virtual void set_GurZNeisprGID_REM_ZNEISPR(TFIBWideStringField * GurZNeisprGID_REM_ZNEISPR);

   virtual TFIBWideStringField * get_GurZNeisprPREFIKS_REM_ZNEISPR(void);
   virtual void set_GurZNeisprPREFIKS_REM_ZNEISPR(TFIBWideStringField * GurZNeisprPREFIKS_REM_ZNEISPR);

   virtual TFIBLargeIntField * get_GurZNeisprIDZ_REM_ZNEISPR(void);
   virtual void set_GurZNeisprIDZ_REM_ZNEISPR(TFIBLargeIntField * GurZNeisprIDZ_REM_ZNEISPR);

   virtual TFIBLargeIntField * get_GurZNeisprIDNEISPR_REM_ZNEISPR(void);
   virtual void set_GurZNeisprIDNEISPR_REM_ZNEISPR(TFIBLargeIntField * GurZNeisprIDNEISPR_REM_ZNEISPR);

   virtual TFIBLargeIntField * get_GurZNeisprIDBASE_REM_ZNEISPR(void);
   virtual void set_GurZNeisprIDBASE_REM_ZNEISPR(TFIBLargeIntField * GurZNeisprIDBASE_REM_ZNEISPR);

   virtual TFIBWideStringField * get_GurZNeisprNAME_REM_SNEISPR(void);
   virtual void set_GurZNeisprNAME_REM_SNEISPR(TFIBWideStringField * GurZNeisprNAME_REM_SNEISPR);

   virtual TFIBWideStringField * get_GurZNEISPR_REM_Z(void);
   virtual void set_GurZNEISPR_REM_Z(TFIBWideStringField * GurZNEISPR_REM_Z);

   virtual TFIBWideStringField * get_GurZKLIENT_NAME_REM_Z(void);
   virtual void set_GurZKLIENT_NAME_REM_Z(TFIBWideStringField * GurZKLIENT_NAME_REM_Z);

   virtual TFIBWideStringField * get_GurZKLIENT_ADR_REM_Z(void);
   virtual void set_GurZKLIENT_ADR_REM_Z(TFIBWideStringField * GurZKLIENT_ADR_REM_Z);

   virtual TFIBWideStringField * get_GurZKLIENT_PHONE_REM_Z(void);
   virtual void set_GurZKLIENT_PHONE_REM_Z(TFIBWideStringField * GurZKLIENT_PHONE_REM_Z);

   virtual TFIBWideStringField * get_GurZKOMPLECT_REM_Z(void);
   virtual void set_GurZKOMPLECT_REM_Z(TFIBWideStringField * GurZKOMPLECT_REM_Z);

   virtual TFIBWideStringField * get_GurZMODEL_REM_Z(void);
   virtual void set_GurZMODEL_REM_Z(TFIBWideStringField * GurZMODEL_REM_Z);

   virtual TFIBWideStringField * get_GurZSOST_REM_Z(void);
   virtual void set_GurZSOST_REM_Z(TFIBWideStringField * GurZSOST_REM_Z);

   virtual TFIBWideStringField * get_GurZSERNUM2_REM_Z(void);
   virtual void set_GurZSERNUM2_REM_Z(TFIBWideStringField * GurZSERNUM2_REM_Z);

   virtual TFIBWideStringField * get_GurZSERNUM_REM_Z(void);
   virtual void set_GurZSERNUM_REM_Z(TFIBWideStringField * GurZSERNUM_REM_Z);

   virtual TFIBWideStringField * get_GurZCOMENTS_REM_Z(void);
   virtual void set_GurZCOMENTS_REM_Z(TFIBWideStringField * GurZCOMENTS_REM_Z);

   virtual TFIBDateTimeField * get_GurZPOSOUT_REM_Z(void);
   virtual void set_GurZPOSOUT_REM_Z(TFIBDateTimeField * GurZPOSOUT_REM_Z);

   virtual TFIBDateTimeField * get_GurZPOSREMONT_REM_Z(void);
   virtual void set_GurZPOSREMONT_REM_Z(TFIBDateTimeField * GurZPOSREMONT_REM_Z);

   virtual TFIBIntegerField * get_GurZWARRANTY_REM_Z(void);
   virtual void set_GurZWARRANTY_REM_Z(TFIBIntegerField * GurZWARRANTY_REM_Z);

   virtual TpFIBDataSet * get_DopUsl(void);
   virtual void set_DopUsl(TpFIBDataSet * DopUsl);

   virtual TDataSource * get_DataSourceDopUsl(void);
   virtual void set_DataSourceDopUsl(TDataSource * DataSourceDopUsl);

   virtual TFIBLargeIntField * get_DopUslID_REM_ZDOPUSL(void);
   virtual void set_DopUslID_REM_ZDOPUSL(TFIBLargeIntField * DopUslID_REM_ZDOPUSL);

   virtual TFIBWideStringField * get_DopUslGID_REM_ZDOPUSL(void);
   virtual void set_DopUslGID_REM_ZDOPUSL(TFIBWideStringField * DopUslGID_REM_ZDOPUSL);

   virtual TFIBLargeIntField * get_DopUslIDBASE_REM_ZDOPUSL(void);
   virtual void set_DopUslIDBASE_REM_ZDOPUSL(TFIBLargeIntField * DopUslIDBASE_REM_ZDOPUSL);

   virtual TFIBLargeIntField * get_DopUslIDZ_REM_ZDOPUSL(void);
   virtual void set_DopUslIDZ_REM_ZDOPUSL(TFIBLargeIntField * DopUslIDZ_REM_ZDOPUSL);

   virtual TFIBLargeIntField * get_DopUslIDNOM_REM_ZDOPUSL(void);
   virtual void set_DopUslIDNOM_REM_ZDOPUSL(TFIBLargeIntField * DopUslIDNOM_REM_ZDOPUSL);

   virtual TFIBLargeIntField * get_DopUslIDED_REM_ZDOPUSL(void);
   virtual void set_DopUslIDED_REM_ZDOPUSL(TFIBLargeIntField * DopUslIDED_REM_ZDOPUSL);

   virtual TFIBBCDField * get_DopUslKOL_REM_ZDOPUSL(void);
   virtual void set_DopUslKOL_REM_ZDOPUSL(TFIBBCDField * DopUslKOL_REM_ZDOPUSL);

   virtual TFIBBCDField * get_DopUslKF_REM_ZDOPUSL(void);
   virtual void set_DopUslKF_REM_ZDOPUSL(TFIBBCDField * DopUslKF_REM_ZDOPUSL);

   virtual TFIBBCDField * get_DopUslPRICE_REM_ZDOPUSL(void);
   virtual void set_DopUslPRICE_REM_ZDOPUSL(TFIBBCDField * DopUslPRICE_REM_ZDOPUSL);

   virtual TFIBBCDField * get_DopUslSUM_REM_ZDOPUSL(void);
   virtual void set_DopUslSUM_REM_ZDOPUSL(TFIBBCDField * DopUslSUM_REM_ZDOPUSL);

   virtual TFIBWideStringField * get_DopUslTEXTNOM_REM_ZDOPUSL(void);
   virtual void set_DopUslTEXTNOM_REM_ZDOPUSL(TFIBWideStringField * DopUslTEXTNOM_REM_ZDOPUSL);

   virtual TFIBWideStringField * get_DopUslNAMENOM(void);
   virtual void set_DopUslNAMENOM(TFIBWideStringField * DopUslNAMENOM);

   virtual TFIBWideStringField * get_DopUslNAMEED(void);
   virtual void set_DopUslNAMEED(TFIBWideStringField * DopUslNAMEED);

   virtual TpFIBDataSet * get_PerformedWork(void);
   virtual void set_PerformedWork(TpFIBDataSet * PerformedWork);

   virtual TDataSource * get_DataSourcePerformedWork(void);
   virtual void set_DataSourcePerformedWork(TDataSource * DataSourcePerformedWork);

   virtual TFIBLargeIntField * get_PerformedWorkID_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkID_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkID_REM_ZPERFWORK);

   virtual TFIBWideStringField * get_PerformedWorkGID_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkGID_REM_ZPERFWORK(TFIBWideStringField * PerformedWorkGID_REM_ZPERFWORK);

   virtual TFIBLargeIntField * get_PerformedWorkIDBASE_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkIDBASE_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDBASE_REM_ZPERFWORK);

   virtual TFIBLargeIntField * get_PerformedWorkIDZ_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkIDZ_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDZ_REM_ZPERFWORK);

   virtual TFIBLargeIntField * get_PerformedWorkIDNOM_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkIDNOM_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDNOM_REM_ZPERFWORK);

   virtual TFIBLargeIntField * get_PerformedWorkIDED_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkIDED_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDED_REM_ZPERFWORK);

   virtual TFIBBCDField * get_PerformedWorkKOL_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkKOL_REM_ZPERFWORK(TFIBBCDField * PerformedWorkKOL_REM_ZPERFWORK);

   virtual TFIBBCDField * get_PerformedWorkKF_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkKF_REM_ZPERFWORK(TFIBBCDField * PerformedWorkKF_REM_ZPERFWORK);

   virtual TFIBBCDField * get_PerformedWorkPRICE_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkPRICE_REM_ZPERFWORK(TFIBBCDField * PerformedWorkPRICE_REM_ZPERFWORK);

   virtual TFIBBCDField * get_PerformedWorkSUM_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkSUM_REM_ZPERFWORK(TFIBBCDField * PerformedWorkSUM_REM_ZPERFWORK);

   virtual TFIBWideStringField * get_PerformedWorkTEXTNOM_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkTEXTNOM_REM_ZPERFWORK(TFIBWideStringField * PerformedWorkTEXTNOM_REM_ZPERFWORK);

   virtual TFIBDateTimeField * get_PerformedWorkPOS_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkPOS_REM_ZPERFWORK(TFIBDateTimeField * PerformedWorkPOS_REM_ZPERFWORK);

   virtual TFIBSmallIntField * get_PerformedWorkRESULT_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkRESULT_REM_ZPERFWORK(TFIBSmallIntField * PerformedWorkRESULT_REM_ZPERFWORK);

   virtual TFIBSmallIntField * get_PerformedWorkADDACT_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkADDACT_REM_ZPERFWORK(TFIBSmallIntField * PerformedWorkADDACT_REM_ZPERFWORK);

   virtual TFIBSmallIntField * get_PerformedWorkSHOWFORUSER_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkSHOWFORUSER_REM_ZPERFWORK(TFIBSmallIntField * PerformedWorkSHOWFORUSER_REM_ZPERFWORK);

   virtual TFIBWideStringField * get_PerformedWorkNAMENOM(void);
   virtual void set_PerformedWorkNAMENOM(TFIBWideStringField * PerformedWorkNAMENOM);

   virtual TFIBWideStringField * get_PerformedWorkNAMEED(void);
   virtual void set_PerformedWorkNAMEED(TFIBWideStringField * PerformedWorkNAMEED);

   virtual TFIBLargeIntField * get_PerformedWorkIDUSER_REM_ZPERFWORK(void);
   virtual void set_PerformedWorkIDUSER_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDUSER_REM_ZPERFWORK);

   virtual TFIBWideStringField * get_PerformedWorkNAME_USER(void);
   virtual void set_PerformedWorkNAME_USER(TFIBWideStringField * PerformedWorkNAME_USER);

   virtual TFIBLargeIntField * get_GurZIDMEXANIK_REM_Z(void);
   virtual void set_GurZIDMEXANIK_REM_Z(TFIBLargeIntField * GurZIDMEXANIK_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDBRAND_REM_Z(void);
   virtual void set_GurZIDBRAND_REM_Z(TFIBLargeIntField * GurZIDBRAND_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDACTCAT_REM_Z(void);
   virtual void set_GurZIDACTCAT_REM_Z(TFIBLargeIntField * GurZIDACTCAT_REM_Z);

   virtual TFIBWideStringField * get_GurZGUID_REM_Z(void);
   virtual void set_GurZGUID_REM_Z(TFIBWideStringField * GurZGUID_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDZOSN_REM_Z(void);
   virtual void set_GurZIDZOSN_REM_Z(TFIBLargeIntField * GurZIDZOSN_REM_Z);

   virtual TFIBSmallIntField * get_GurZFL_POVTOR_REM_Z(void);
   virtual void set_GurZFL_POVTOR_REM_Z(TFIBSmallIntField * GurZFL_POVTOR_REM_Z);

   virtual TFIBWideStringField * get_GurZDILER_NUMZ_REM_Z(void);
   virtual void set_GurZDILER_NUMZ_REM_Z(TFIBWideStringField * GurZDILER_NUMZ_REM_Z);

   virtual TFIBDateTimeField * get_GurZDILER_POSZ_REM_Z(void);
   virtual void set_GurZDILER_POSZ_REM_Z(TFIBDateTimeField * GurZDILER_POSZ_REM_Z);

   virtual TFIBWideStringField * get_GurZDILER_GUIDZ_REM_Z(void);
   virtual void set_GurZDILER_GUIDZ_REM_Z(TFIBWideStringField * GurZDILER_GUIDZ_REM_Z);

   virtual TFIBWideStringField * get_GurZSC_NUMZ_REM_Z(void);
   virtual void set_GurZSC_NUMZ_REM_Z(TFIBWideStringField * GurZSC_NUMZ_REM_Z);

   virtual TFIBDateTimeField * get_GurZSC_POSZ_REM_Z(void);
   virtual void set_GurZSC_POSZ_REM_Z(TFIBDateTimeField * GurZSC_POSZ_REM_Z);

   virtual TFIBWideStringField * get_GurZSC_GUIDZ_REM_Z(void);
   virtual void set_GurZSC_GUIDZ_REM_Z(TFIBWideStringField * GurZSC_GUIDZ_REM_Z);

   virtual TFIBSmallIntField * get_GurZFL_ADDREPORT_REM_Z(void);
   virtual void set_GurZFL_ADDREPORT_REM_Z(TFIBSmallIntField * GurZFL_ADDREPORT_REM_Z);

   virtual TFIBWideStringField * get_GurZSERNUM_STR_REM_Z(void);
   virtual void set_GurZSERNUM_STR_REM_Z(TFIBWideStringField * GurZSERNUM_STR_REM_Z);

   virtual TFIBWideStringField * get_GurZNAME_MEXANIK(void);
   virtual void set_GurZNAME_MEXANIK(TFIBWideStringField * GurZNAME_MEXANIK);

   virtual TFIBWideStringField * get_GurZNAME_SBRAND(void);
   virtual void set_GurZNAME_SBRAND(TFIBWideStringField * GurZNAME_SBRAND);

   virtual TFIBWideStringField * get_GurZNAME_REM_SACTCATEGORY(void);
   virtual void set_GurZNAME_REM_SACTCATEGORY(TFIBWideStringField * GurZNAME_REM_SACTCATEGORY);

   virtual TFIBLargeIntField * get_GurZIDHW_REM_Z(void);
   virtual void set_GurZIDHW_REM_Z(TFIBLargeIntField * GurZIDHW_REM_Z);

   virtual TFIBLargeIntField * get_GurZIDKKT_REM_Z(void);
   virtual void set_GurZIDKKT_REM_Z(TFIBLargeIntField * GurZIDKKT_REM_Z);

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

   virtual TFIBIntegerField * get_GurZFL_KLIENT_UVEDOML_REM_Z(void);
   virtual void set_GurZFL_KLIENT_UVEDOML_REM_Z(TFIBIntegerField * GurZFL_KLIENT_UVEDOML_REM_Z);

   virtual TFIBIntegerField * get_GurZFL_TREB_KONS_KL_REM_Z(void);
   virtual void set_GurZFL_TREB_KONS_KL_REM_Z(TFIBIntegerField * GurZFL_TREB_KONS_KL_REM_Z);

   virtual TFIBIntegerField * get_GurZFL_KL_OTV_NA_ZAPROS_REM_Z(void);
   virtual void set_GurZFL_KL_OTV_NA_ZAPROS_REM_Z(TFIBIntegerField * GurZFL_KL_OTV_NA_ZAPROS_REM_Z);

   virtual TFIBWideStringField * get_GurZPREFIKS_NUM_REM_Z(void);
   virtual void set_GurZPREFIKS_NUM_REM_Z(TFIBWideStringField * GurZPREFIKS_NUM_REM_Z);

   virtual TFIBWideStringField * get_GurZNUM_GARDOC_REM_Z(void);
   virtual void set_GurZNUM_GARDOC_REM_Z(TFIBWideStringField * GurZNUM_GARDOC_REM_Z);

   virtual TFIBIntegerField * get_GurZFL_FICTIV_REM_Z(void);
   virtual void set_GurZFL_FICTIV_REM_Z(TFIBIntegerField * GurZFL_FICTIV_REM_Z);

   virtual TFIBSmallIntField * get_GurZFL_NE_OTCH_REM_Z(void);
   virtual void set_GurZFL_NE_OTCH_REM_Z(TFIBSmallIntField * GurZFL_NE_OTCH_REM_Z);

   virtual TFIBSmallIntField * get_GurZFL_NADO_OTCH_REM_Z(void);
   virtual void set_GurZFL_NADO_OTCH_REM_Z(TFIBSmallIntField * GurZFL_NADO_OTCH_REM_Z);

   virtual TFIBSmallIntField * get_GurZFL_ISM_GARDOC_REM_Z(void);
   virtual void set_GurZFL_ISM_GARDOC_REM_Z(TFIBSmallIntField * GurZFL_ISM_GARDOC_REM_Z);

   virtual TFIBSmallIntField * get_GurZFL_ISM_SERNUM_REM_Z(void);
   virtual void set_GurZFL_ISM_SERNUM_REM_Z(TFIBSmallIntField * GurZFL_ISM_SERNUM_REM_Z);

   virtual TFIBSmallIntField * get_GurZFL_ISM_SERNUM2_REM_Z(void);
   virtual void set_GurZFL_ISM_SERNUM2_REM_Z(TFIBSmallIntField * GurZFL_ISM_SERNUM2_REM_Z);

   virtual TFIBWideStringField * get_GurZNUM_GARDOC_NEW_REM_Z(void);
   virtual void set_GurZNUM_GARDOC_NEW_REM_Z(TFIBWideStringField * GurZNUM_GARDOC_NEW_REM_Z);

   virtual TFIBWideStringField * get_GurZSERNUM_NEW_REM_Z(void);
   virtual void set_GurZSERNUM_NEW_REM_Z(TFIBWideStringField * GurZSERNUM_NEW_REM_Z);

   virtual TFIBWideStringField * get_GurZSERNUM2_NEW_REM_Z(void);
   virtual void set_GurZSERNUM2_NEW_REM_Z(TFIBWideStringField * GurZSERNUM2_NEW_REM_Z);

   virtual TFIBSmallIntField * get_GurZGOTOVO_K_VIDACHE_REM_Z(void);
   virtual void set_GurZGOTOVO_K_VIDACHE_REM_Z(TFIBSmallIntField * GurZGOTOVO_K_VIDACHE_REM_Z);

   virtual TDataSource * get_DataSourceGurZ_1(void);
   virtual void set_DataSourceGurZ_1(TDataSource * DataSourceGurZ_1);

   virtual TpFIBDataSet * get_GurZ_1(void);
   virtual void set_GurZ_1(TpFIBDataSet * GurZ_1);

   virtual TFIBLargeIntField * get_GurZ_1ID_REM_Z_1(void);
   virtual void set_GurZ_1ID_REM_Z_1(TFIBLargeIntField * GurZ_1ID_REM_Z_1);

   virtual TFIBLargeIntField * get_GurZ_1IDBASE_REM_Z_1(void);
   virtual void set_GurZ_1IDBASE_REM_Z_1(TFIBLargeIntField * GurZ_1IDBASE_REM_Z_1);

   virtual TFIBLargeIntField * get_GurZ_1IDZ_REM_Z_1(void);
   virtual void set_GurZ_1IDZ_REM_Z_1(TFIBLargeIntField * GurZ_1IDZ_REM_Z_1);

   virtual TFIBLargeIntField * get_GurZ_1IDPRMODEL_REM_Z_1(void);
   virtual void set_GurZ_1IDPRMODEL_REM_Z_1(TFIBLargeIntField * GurZ_1IDPRMODEL_REM_Z_1);

   virtual TFIBLargeIntField * get_GurZ_1IDPRODUCER_REM_Z_1(void);
   virtual void set_GurZ_1IDPRODUCER_REM_Z_1(TFIBLargeIntField * GurZ_1IDPRODUCER_REM_Z_1);

   virtual TFIBIntegerField * get_GurZ_1FL_VKL_REM_Z_1(void);
   virtual void set_GurZ_1FL_VKL_REM_Z_1(TFIBIntegerField * GurZ_1FL_VKL_REM_Z_1);

   virtual TFIBIntegerField * get_GurZ_1FL_ZIP_REM_Z_1(void);
   virtual void set_GurZ_1FL_ZIP_REM_Z_1(TFIBIntegerField * GurZ_1FL_ZIP_REM_Z_1);

   virtual TFIBIntegerField * get_GurZ_1FL_DEFECT_DEMO_REM_Z_1(void);
   virtual void set_GurZ_1FL_DEFECT_DEMO_REM_Z_1(TFIBIntegerField * GurZ_1FL_DEFECT_DEMO_REM_Z_1);

   virtual TFIBIntegerField * get_GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1(void);
   virtual void set_GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1(TFIBIntegerField * GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1);

   virtual TFIBLargeIntField * get_GurZ_1IDSELLER_REM_Z_1(void);
   virtual void set_GurZ_1IDSELLER_REM_Z_1(TFIBLargeIntField * GurZ_1IDSELLER_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1KLIENT_EMAIL_REM_Z_1(void);
   virtual void set_GurZ_1KLIENT_EMAIL_REM_Z_1(TFIBWideStringField * GurZ_1KLIENT_EMAIL_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1KLIENT_DOP_INFO_REM_Z_1(void);
   virtual void set_GurZ_1KLIENT_DOP_INFO_REM_Z_1(TFIBWideStringField * GurZ_1KLIENT_DOP_INFO_REM_Z_1);

   virtual TFIBLargeIntField * get_GurZ_1IDADRKV_REM_Z_1(void);
   virtual void set_GurZ_1IDADRKV_REM_Z_1(TFIBLargeIntField * GurZ_1IDADRKV_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1NAME_SPRODUCER(void);
   virtual void set_GurZ_1NAME_SPRODUCER(TFIBWideStringField * GurZ_1NAME_SPRODUCER);

   virtual TFIBWideStringField * get_GurZ_1NAME_REM_SPRMODEL(void);
   virtual void set_GurZ_1NAME_REM_SPRMODEL(TFIBWideStringField * GurZ_1NAME_REM_SPRMODEL);

   virtual TFIBWideStringField * get_GurZ_1NAME_SSELLER(void);
   virtual void set_GurZ_1NAME_SSELLER(TFIBWideStringField * GurZ_1NAME_SSELLER);

   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_DOM(void);
   virtual void set_GurZ_1NAME_SADR_DOM(TFIBWideStringField * GurZ_1NAME_SADR_DOM);

   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_STREET(void);
   virtual void set_GurZ_1NAME_SADR_STREET(TFIBWideStringField * GurZ_1NAME_SADR_STREET);

   virtual TFIBWideStringField * get_GurZ_1POSTCODE_SADR_STREET(void);
   virtual void set_GurZ_1POSTCODE_SADR_STREET(TFIBWideStringField * GurZ_1POSTCODE_SADR_STREET);

   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_NASPUNKT(void);
   virtual void set_GurZ_1NAME_SADR_NASPUNKT(TFIBWideStringField * GurZ_1NAME_SADR_NASPUNKT);

   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_REGION(void);
   virtual void set_GurZ_1NAME_SADR_REGION(TFIBWideStringField * GurZ_1NAME_SADR_REGION);

   virtual TFIBWideStringField * get_GurZ_1CODE_SADR_REGION(void);
   virtual void set_GurZ_1CODE_SADR_REGION(TFIBWideStringField * GurZ_1CODE_SADR_REGION);

   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_KV(void);
   virtual void set_GurZ_1NAME_SADR_KV(TFIBWideStringField * GurZ_1NAME_SADR_KV);

   virtual TFIBIntegerField * get_GurZ_1FL_PLOMBA_SET_REM_Z_1(void);
   virtual void set_GurZ_1FL_PLOMBA_SET_REM_Z_1(TFIBIntegerField * GurZ_1FL_PLOMBA_SET_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1TEXT_PLOMBA_REM_Z_1(void);
   virtual void set_GurZ_1TEXT_PLOMBA_REM_Z_1(TFIBWideStringField * GurZ_1TEXT_PLOMBA_REM_Z_1);

   virtual TFIBIntegerField * get_GurZ_1FL_PROBLEM_DEVICE_REM_Z_1(void);
   virtual void set_GurZ_1FL_PROBLEM_DEVICE_REM_Z_1(TFIBIntegerField * GurZ_1FL_PROBLEM_DEVICE_REM_Z_1);

   virtual TFIBIntegerField * get_GurZ_1FL_PROBLEM_KLIENT_REM_Z_1(void);
   virtual void set_GurZ_1FL_PROBLEM_KLIENT_REM_Z_1(TFIBIntegerField * GurZ_1FL_PROBLEM_KLIENT_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1NEISPR_ENG_REM_Z_1(void);
   virtual void set_GurZ_1NEISPR_ENG_REM_Z_1(TFIBWideStringField * GurZ_1NEISPR_ENG_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1DEFECT_ENG_REM_Z_1(void);
   virtual void set_GurZ_1DEFECT_ENG_REM_Z_1(TFIBWideStringField * GurZ_1DEFECT_ENG_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1SOLUTION_ENG_REM_Z_1(void);
   virtual void set_GurZ_1SOLUTION_ENG_REM_Z_1(TFIBWideStringField * GurZ_1SOLUTION_ENG_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1STR_CODE_VIGR_REM_Z_1(void);
   virtual void set_GurZ_1STR_CODE_VIGR_REM_Z_1(TFIBWideStringField * GurZ_1STR_CODE_VIGR_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_STROEN(void);
   virtual void set_GurZ_1NAME_SADR_STROEN(TFIBWideStringField * GurZ_1NAME_SADR_STROEN);

   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_RAYON(void);
   virtual void set_GurZ_1NAME_SADR_RAYON(TFIBWideStringField * GurZ_1NAME_SADR_RAYON);

   virtual TFIBIntegerField * get_GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1(void);
   virtual void set_GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1(TFIBIntegerField * GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1);

   virtual TFIBWideStringField * get_GurZNeisprNAME_ENG_REM_SNEISPR(void);
   virtual void set_GurZNeisprNAME_ENG_REM_SNEISPR(TFIBWideStringField * GurZNeisprNAME_ENG_REM_SNEISPR);

   virtual TFIBWideStringField * get_GurZNeisprNAME_REM_SGRPNEISPR(void);
   virtual void set_GurZNeisprNAME_REM_SGRPNEISPR(TFIBWideStringField * GurZNeisprNAME_REM_SGRPNEISPR);

   virtual TFIBWideStringField * get_GurZNeisprNAME_ENG_REM_SGRPNEISPR(void);
   virtual void set_GurZNeisprNAME_ENG_REM_SGRPNEISPR(TFIBWideStringField * GurZNeisprNAME_ENG_REM_SGRPNEISPR);

   virtual TFIBWideStringField * get_GurZ_1FAMILIYA_REM_Z_1(void);
   virtual void set_GurZ_1FAMILIYA_REM_Z_1(TFIBWideStringField * GurZ_1FAMILIYA_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1IMYA_REM_Z_1(void);
   virtual void set_GurZ_1IMYA_REM_Z_1(TFIBWideStringField * GurZ_1IMYA_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1OTCHESTVO_REM_Z_1(void);
   virtual void set_GurZ_1OTCHESTVO_REM_Z_1(TFIBWideStringField * GurZ_1OTCHESTVO_REM_Z_1);

   virtual TFIBDateField * get_GurZ_1DATE_VIPUSK_REM_Z_1(void);
   virtual void set_GurZ_1DATE_VIPUSK_REM_Z_1(TFIBDateField * GurZ_1DATE_VIPUSK_REM_Z_1);

   virtual TFIBDateField * get_GurZ_1DATE_PRODAGI_REM_Z_1(void);
   virtual void set_GurZ_1DATE_PRODAGI_REM_Z_1(TFIBDateField * GurZ_1DATE_PRODAGI_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1PODO_REM_Z_1(void);
   virtual void set_GurZ_1PODO_REM_Z_1(TFIBWideStringField * GurZ_1PODO_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1POPOSLE_REM_Z_1(void);
   virtual void set_GurZ_1POPOSLE_REM_Z_1(TFIBWideStringField * GurZ_1POPOSLE_REM_Z_1);

   virtual TFIBLargeIntField * get_GurZ_1IDPRNEISPR_REM_Z_1(void);
   virtual void set_GurZ_1IDPRNEISPR_REM_Z_1(TFIBLargeIntField * GurZ_1IDPRNEISPR_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1PARTNUM_REM_Z_1(void);
   virtual void set_GurZ_1PARTNUM_REM_Z_1(TFIBWideStringField * GurZ_1PARTNUM_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1REFERENCE_REM_Z_1(void);
   virtual void set_GurZ_1REFERENCE_REM_Z_1(TFIBWideStringField * GurZ_1REFERENCE_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1SWCODE_REM_Z_1(void);
   virtual void set_GurZ_1SWCODE_REM_Z_1(TFIBWideStringField * GurZ_1SWCODE_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1HWCODE_REM_Z_1(void);
   virtual void set_GurZ_1HWCODE_REM_Z_1(TFIBWideStringField * GurZ_1HWCODE_REM_Z_1);

   virtual TFIBIntegerField * get_GurZ_1KEMSDANO_REM_Z_1(void);
   virtual void set_GurZ_1KEMSDANO_REM_Z_1(TFIBIntegerField * GurZ_1KEMSDANO_REM_Z_1);

   virtual TFIBDateTimeField * get_GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1(void);
   virtual void set_GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1(TFIBDateTimeField * GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1SERNUM3_REM_Z_1(void);
   virtual void set_GurZ_1SERNUM3_REM_Z_1(TFIBWideStringField * GurZ_1SERNUM3_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1SERNUM4_REM_Z_1(void);
   virtual void set_GurZ_1SERNUM4_REM_Z_1(TFIBWideStringField * GurZ_1SERNUM4_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1NUMBAT_REM_Z_1(void);
   virtual void set_GurZ_1NUMBAT_REM_Z_1(TFIBWideStringField * GurZ_1NUMBAT_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1NAME_REM_SPRNEISPR(void);
   virtual void set_GurZ_1NAME_REM_SPRNEISPR(TFIBWideStringField * GurZ_1NAME_REM_SPRNEISPR);

   virtual TFIBWideStringField * get_GurZ_1NAME_ENG_REM_SPRNEISPR(void);
   virtual void set_GurZ_1NAME_ENG_REM_SPRNEISPR(TFIBWideStringField * GurZ_1NAME_ENG_REM_SPRNEISPR);

   virtual TFIBWideStringField * get_GurZ_1CODE_REM_SPRNEISPR(void);
   virtual void set_GurZ_1CODE_REM_SPRNEISPR(TFIBWideStringField * GurZ_1CODE_REM_SPRNEISPR);

   virtual TFIBWideStringField * get_GurZ_1NAME_REM_SPRNEISPR_GRP(void);
   virtual void set_GurZ_1NAME_REM_SPRNEISPR_GRP(TFIBWideStringField * GurZ_1NAME_REM_SPRNEISPR_GRP);

   virtual TFIBWideStringField * get_GurZ_1NAME_ENG_REM_SPRNEISPR_GRP(void);
   virtual void set_GurZ_1NAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * GurZ_1NAME_ENG_REM_SPRNEISPR_GRP);

   virtual TFIBSmallIntField * get_GurZ_1FL_ISM_SERNUM3_REM_Z_1(void);
   virtual void set_GurZ_1FL_ISM_SERNUM3_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_SERNUM3_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1SERNUM3_NEW_REM_Z_1(void);
   virtual void set_GurZ_1SERNUM3_NEW_REM_Z_1(TFIBWideStringField * GurZ_1SERNUM3_NEW_REM_Z_1);

   virtual TFIBSmallIntField * get_GurZ_1FL_ISM_SERNUM4_REM_Z_1(void);
   virtual void set_GurZ_1FL_ISM_SERNUM4_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_SERNUM4_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1SERNUM4_NEW_REM_Z_1(void);
   virtual void set_GurZ_1SERNUM4_NEW_REM_Z_1(TFIBWideStringField * GurZ_1SERNUM4_NEW_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1FL_ISM_REFERENCE_REM_Z_1(void);
   virtual void set_GurZ_1FL_ISM_REFERENCE_REM_Z_1(TFIBWideStringField * GurZ_1FL_ISM_REFERENCE_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1REFERENCE_NEW_REM_Z_1(void);
   virtual void set_GurZ_1REFERENCE_NEW_REM_Z_1(TFIBWideStringField * GurZ_1REFERENCE_NEW_REM_Z_1);

   virtual TFIBSmallIntField * get_GurZ_1FL_ISM_HWCODE_REM_Z_1(void);
   virtual void set_GurZ_1FL_ISM_HWCODE_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_HWCODE_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1HWCODE_NEW_REM_Z_1(void);
   virtual void set_GurZ_1HWCODE_NEW_REM_Z_1(TFIBWideStringField * GurZ_1HWCODE_NEW_REM_Z_1);

   virtual TFIBSmallIntField * get_GurZ_1FL_ISM_SWCODE_REM_Z_1(void);
   virtual void set_GurZ_1FL_ISM_SWCODE_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_SWCODE_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1SWCODE_NEW_REM_Z_1(void);
   virtual void set_GurZ_1SWCODE_NEW_REM_Z_1(TFIBWideStringField * GurZ_1SWCODE_NEW_REM_Z_1);

   virtual TFIBSmallIntField * get_GurZ_1FL_ISM_PARTNUM_REM_Z_1(void);
   virtual void set_GurZ_1FL_ISM_PARTNUM_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_PARTNUM_REM_Z_1);

   virtual TFIBWideStringField * get_GurZ_1PARTNUM_NEW_REM_Z_1(void);
   virtual void set_GurZ_1PARTNUM_NEW_REM_Z_1(TFIBWideStringField * GurZ_1PARTNUM_NEW_REM_Z_1);

   virtual TDataSource * get_DataSourcePrNeispr(void);
   virtual void set_DataSourcePrNeispr(TDataSource * DataSourcePrNeispr);

   virtual TpFIBDataSet * get_GurZPrNeispr(void);
   virtual void set_GurZPrNeispr(TpFIBDataSet * GurZPrNeispr);

   virtual TFIBLargeIntField * get_GurZPrNeisprID_REM_ZPRNEISPR(void);
   virtual void set_GurZPrNeisprID_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprID_REM_ZPRNEISPR);

   virtual TFIBLargeIntField * get_GurZPrNeisprIDBASE_REM_ZPRNEISPR(void);
   virtual void set_GurZPrNeisprIDBASE_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprIDBASE_REM_ZPRNEISPR);

   virtual TFIBWideStringField * get_GurZPrNeisprGID_REM_ZPRNEISPR(void);
   virtual void set_GurZPrNeisprGID_REM_ZPRNEISPR(TFIBWideStringField * GurZPrNeisprGID_REM_ZPRNEISPR);

   virtual TFIBLargeIntField * get_GurZPrNeisprIDPRCOND_REM_ZPRNEISPR(void);
   virtual void set_GurZPrNeisprIDPRCOND_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprIDPRCOND_REM_ZPRNEISPR);

   virtual TFIBLargeIntField * get_GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR(void);
   virtual void set_GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR);

   virtual TFIBLargeIntField * get_GurZPrNeisprIDZ_REM_ZPRNEISPR(void);
   virtual void set_GurZPrNeisprIDZ_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprIDZ_REM_ZPRNEISPR);

   virtual TFIBWideStringField * get_GurZPrNeisprNAME_REM_SPRNEISPR(void);
   virtual void set_GurZPrNeisprNAME_REM_SPRNEISPR(TFIBWideStringField * GurZPrNeisprNAME_REM_SPRNEISPR);

   virtual TFIBWideStringField * get_GurZPrNeisprCODE_REM_SPRNEISPR(void);
   virtual void set_GurZPrNeisprCODE_REM_SPRNEISPR(TFIBWideStringField * GurZPrNeisprCODE_REM_SPRNEISPR);

   virtual TFIBWideStringField * get_GurZPrNeisprNAME_ENG_REM_SPRNEISPR(void);
   virtual void set_GurZPrNeisprNAME_ENG_REM_SPRNEISPR(TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRNEISPR);

   virtual TFIBWideStringField * get_GurZPrNeisprNAME_REM_SPRNEISPR_GRP(void);
   virtual void set_GurZPrNeisprNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * GurZPrNeisprNAME_REM_SPRNEISPR_GRP);

   virtual TFIBWideStringField * get_GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP(void);
   virtual void set_GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP);

   virtual TFIBWideStringField * get_GurZPrNeisprCODE_REM_SPRCONDITION(void);
   virtual void set_GurZPrNeisprCODE_REM_SPRCONDITION(TFIBWideStringField * GurZPrNeisprCODE_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_GurZPrNeisprNAME_REM_SPRCONDITION(void);
   virtual void set_GurZPrNeisprNAME_REM_SPRCONDITION(TFIBWideStringField * GurZPrNeisprNAME_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_GurZPrNeisprNAME_ENG_REM_SPRCONDITION(void);
   virtual void set_GurZPrNeisprNAME_ENG_REM_SPRCONDITION(TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_GurZPrNeisprCODE_REM_SPRCOND_GRP(void);
   virtual void set_GurZPrNeisprCODE_REM_SPRCOND_GRP(TFIBWideStringField * GurZPrNeisprCODE_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_GurZPrNeisprNAME_REM_SPRCOND_GRP(void);
   virtual void set_GurZPrNeisprNAME_REM_SPRCOND_GRP(TFIBWideStringField * GurZPrNeisprNAME_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP(void);
   virtual void set_GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP(TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP);

   virtual TIntegerField * get_GurZPrNeisprRECNO(void);
   virtual void set_GurZPrNeisprRECNO(TIntegerField * GurZPrNeisprRECNO);

   virtual TFIBBCDField * get_GurZ_1PREDOPLATA_REM_Z_1(void);
   virtual void set_GurZ_1PREDOPLATA_REM_Z_1(TFIBBCDField * GurZ_1PREDOPLATA_REM_Z_1);

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
   virtual void AddNewRecordDv(void);
};
#define CLSID_TREM_DMZayavkaImpl __uuidof(TREM_DMZayavkaImpl)
#endif
