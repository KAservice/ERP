#ifndef UIREM_DMGurZH
#define UIREM_DMGurZH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMGurZ)) IREM_DMGurZ : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_REM_Z = {read = get_TableID_REM_Z , write = set_TableID_REM_Z};
   virtual TFIBLargeIntField * get_TableID_REM_Z(void)=0;
   virtual void set_TableID_REM_Z(TFIBLargeIntField * TableID_REM_Z)=0;

   __property TFIBWideStringField * TableGID_REM_Z = {read = get_TableGID_REM_Z , write = set_TableGID_REM_Z};
   virtual TFIBWideStringField * get_TableGID_REM_Z(void)=0;
   virtual void set_TableGID_REM_Z(TFIBWideStringField * TableGID_REM_Z)=0;

   __property TFIBWideStringField * TablePREFIKS_REM_Z = {read = get_TablePREFIKS_REM_Z , write = set_TablePREFIKS_REM_Z};
   virtual TFIBWideStringField * get_TablePREFIKS_REM_Z(void)=0;
   virtual void set_TablePREFIKS_REM_Z(TFIBWideStringField * TablePREFIKS_REM_Z)=0;

   __property TFIBIntegerField * TableNUM_REM_Z = {read = get_TableNUM_REM_Z , write = set_TableNUM_REM_Z};
   virtual TFIBIntegerField * get_TableNUM_REM_Z(void)=0;
   virtual void set_TableNUM_REM_Z(TFIBIntegerField * TableNUM_REM_Z)=0;

   __property TFIBDateTimeField * TablePOS_REM_Z = {read = get_TablePOS_REM_Z , write = set_TablePOS_REM_Z};
   virtual TFIBDateTimeField * get_TablePOS_REM_Z(void)=0;
   virtual void set_TablePOS_REM_Z(TFIBDateTimeField * TablePOS_REM_Z)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_Z = {read = get_TableIDBASE_REM_Z , write = set_TableIDBASE_REM_Z};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_Z(void)=0;
   virtual void set_TableIDBASE_REM_Z(TFIBLargeIntField * TableIDBASE_REM_Z)=0;

   __property TFIBLargeIntField * TableIDMODEL_REM_Z = {read = get_TableIDMODEL_REM_Z , write = set_TableIDMODEL_REM_Z};
   virtual TFIBLargeIntField * get_TableIDMODEL_REM_Z(void)=0;
   virtual void set_TableIDMODEL_REM_Z(TFIBLargeIntField * TableIDMODEL_REM_Z)=0;

   __property TFIBLargeIntField * TableIDSKLPR_REM_Z = {read = get_TableIDSKLPR_REM_Z , write = set_TableIDSKLPR_REM_Z};
   virtual TFIBLargeIntField * get_TableIDSKLPR_REM_Z(void)=0;
   virtual void set_TableIDSKLPR_REM_Z(TFIBLargeIntField * TableIDSKLPR_REM_Z)=0;

   __property TFIBLargeIntField * TableIDKLIENT_REM_Z = {read = get_TableIDKLIENT_REM_Z , write = set_TableIDKLIENT_REM_Z};
   virtual TFIBLargeIntField * get_TableIDKLIENT_REM_Z(void)=0;
   virtual void set_TableIDKLIENT_REM_Z(TFIBLargeIntField * TableIDKLIENT_REM_Z)=0;

   __property TFIBLargeIntField * TableIDDILER_REM_Z = {read = get_TableIDDILER_REM_Z , write = set_TableIDDILER_REM_Z};
   virtual TFIBLargeIntField * get_TableIDDILER_REM_Z(void)=0;
   virtual void set_TableIDDILER_REM_Z(TFIBLargeIntField * TableIDDILER_REM_Z)=0;

   __property TFIBWideStringField * TableSERNUM_REM_Z = {read = get_TableSERNUM_REM_Z , write = set_TableSERNUM_REM_Z};
   virtual TFIBWideStringField * get_TableSERNUM_REM_Z(void)=0;
   virtual void set_TableSERNUM_REM_Z(TFIBWideStringField * TableSERNUM_REM_Z)=0;

   __property TFIBWideStringField * TableNAME_REM_Z = {read = get_TableNAME_REM_Z , write = set_TableNAME_REM_Z};
   virtual TFIBWideStringField * get_TableNAME_REM_Z(void)=0;
   virtual void set_TableNAME_REM_Z(TFIBWideStringField * TableNAME_REM_Z)=0;

   __property TFIBWideStringField * TableDESCR_REM_Z = {read = get_TableDESCR_REM_Z , write = set_TableDESCR_REM_Z};
   virtual TFIBWideStringField * get_TableDESCR_REM_Z(void)=0;
   virtual void set_TableDESCR_REM_Z(TFIBWideStringField * TableDESCR_REM_Z)=0;

   __property TFIBLargeIntField * TableIDTYPEREM_REM_Z = {read = get_TableIDTYPEREM_REM_Z , write = set_TableIDTYPEREM_REM_Z};
   virtual TFIBLargeIntField * get_TableIDTYPEREM_REM_Z(void)=0;
   virtual void set_TableIDTYPEREM_REM_Z(TFIBLargeIntField * TableIDTYPEREM_REM_Z)=0;

   __property TFIBLargeIntField * TableIDSOST_REM_Z = {read = get_TableIDSOST_REM_Z , write = set_TableIDSOST_REM_Z};
   virtual TFIBLargeIntField * get_TableIDSOST_REM_Z(void)=0;
   virtual void set_TableIDSOST_REM_Z(TFIBLargeIntField * TableIDSOST_REM_Z)=0;

   __property TFIBLargeIntField * TableIDTECSKL_REM_Z = {read = get_TableIDTECSKL_REM_Z , write = set_TableIDTECSKL_REM_Z};
   virtual TFIBLargeIntField * get_TableIDTECSKL_REM_Z(void)=0;
   virtual void set_TableIDTECSKL_REM_Z(TFIBLargeIntField * TableIDTECSKL_REM_Z)=0;

   __property TFIBLargeIntField * TableIDUSER_REM_Z = {read = get_TableIDUSER_REM_Z , write = set_TableIDUSER_REM_Z};
   virtual TFIBLargeIntField * get_TableIDUSER_REM_Z(void)=0;
   virtual void set_TableIDUSER_REM_Z(TFIBLargeIntField * TableIDUSER_REM_Z)=0;

   __property TFIBIntegerField * TableOPER_REM_Z = {read = get_TableOPER_REM_Z , write = set_TableOPER_REM_Z};
   virtual TFIBIntegerField * get_TableOPER_REM_Z(void)=0;
   virtual void set_TableOPER_REM_Z(TFIBIntegerField * TableOPER_REM_Z)=0;

   __property TFIBBCDField * TableSUM_REM_Z = {read = get_TableSUM_REM_Z , write = set_TableSUM_REM_Z};
   virtual TFIBBCDField * get_TableSUM_REM_Z(void)=0;
   virtual void set_TableSUM_REM_Z(TFIBBCDField * TableSUM_REM_Z)=0;

   __property TFIBDateField * TableSROK_REM_Z = {read = get_TableSROK_REM_Z , write = set_TableSROK_REM_Z};
   virtual TFIBDateField * get_TableSROK_REM_Z(void)=0;
   virtual void set_TableSROK_REM_Z(TFIBDateField * TableSROK_REM_Z)=0;

   __property TFIBIntegerField * TableOUT_REM_Z = {read = get_TableOUT_REM_Z , write = set_TableOUT_REM_Z};
   virtual TFIBIntegerField * get_TableOUT_REM_Z(void)=0;
   virtual void set_TableOUT_REM_Z(TFIBIntegerField * TableOUT_REM_Z)=0;

   __property TFIBLargeIntField * TableIDFIRM_REM_Z = {read = get_TableIDFIRM_REM_Z , write = set_TableIDFIRM_REM_Z};
   virtual TFIBLargeIntField * get_TableIDFIRM_REM_Z(void)=0;
   virtual void set_TableIDFIRM_REM_Z(TFIBLargeIntField * TableIDFIRM_REM_Z)=0;

   __property TFIBWideStringField * TableNAMEFIRM = {read = get_TableNAMEFIRM , write = set_TableNAMEFIRM};
   virtual TFIBWideStringField * get_TableNAMEFIRM(void)=0;
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)=0;

   __property TFIBWideStringField * TableNAME_REM_SMODEL = {read = get_TableNAME_REM_SMODEL , write = set_TableNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void)=0;
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)=0;

   __property TFIBWideStringField * TableNAME_SKLAD_PR = {read = get_TableNAME_SKLAD_PR , write = set_TableNAME_SKLAD_PR};
   virtual TFIBWideStringField * get_TableNAME_SKLAD_PR(void)=0;
   virtual void set_TableNAME_SKLAD_PR(TFIBWideStringField * TableNAME_SKLAD_PR)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableNAMEDILER = {read = get_TableNAMEDILER , write = set_TableNAMEDILER};
   virtual TFIBWideStringField * get_TableNAMEDILER(void)=0;
   virtual void set_TableNAMEDILER(TFIBWideStringField * TableNAMEDILER)=0;

   __property TFIBWideStringField * TableNAME_STREMONT = {read = get_TableNAME_STREMONT , write = set_TableNAME_STREMONT};
   virtual TFIBWideStringField * get_TableNAME_STREMONT(void)=0;
   virtual void set_TableNAME_STREMONT(TFIBWideStringField * TableNAME_STREMONT)=0;

   __property TFIBWideStringField * TableNAME_REMSSOST = {read = get_TableNAME_REMSSOST , write = set_TableNAME_REMSSOST};
   virtual TFIBWideStringField * get_TableNAME_REMSSOST(void)=0;
   virtual void set_TableNAME_REMSSOST(TFIBWideStringField * TableNAME_REMSSOST)=0;

   __property TFIBWideStringField * TableNAME_SKLAD_TEC = {read = get_TableNAME_SKLAD_TEC , write = set_TableNAME_SKLAD_TEC};
   virtual TFIBWideStringField * get_TableNAME_SKLAD_TEC(void)=0;
   virtual void set_TableNAME_SKLAD_TEC(TFIBWideStringField * TableNAME_SKLAD_TEC)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBWideStringField * TableKLIENT_NAME_REM_Z = {read = get_TableKLIENT_NAME_REM_Z , write = set_TableKLIENT_NAME_REM_Z};
   virtual TFIBWideStringField * get_TableKLIENT_NAME_REM_Z(void)=0;
   virtual void set_TableKLIENT_NAME_REM_Z(TFIBWideStringField * TableKLIENT_NAME_REM_Z)=0;

   __property TFIBWideStringField * TableMODEL_REM_Z = {read = get_TableMODEL_REM_Z , write = set_TableMODEL_REM_Z};
   virtual TFIBWideStringField * get_TableMODEL_REM_Z(void)=0;
   virtual void set_TableMODEL_REM_Z(TFIBWideStringField * TableMODEL_REM_Z)=0;

   __property TFIBWideStringField * TableSERNUM2_REM_Z = {read = get_TableSERNUM2_REM_Z , write = set_TableSERNUM2_REM_Z};
   virtual TFIBWideStringField * get_TableSERNUM2_REM_Z(void)=0;
   virtual void set_TableSERNUM2_REM_Z(TFIBWideStringField * TableSERNUM2_REM_Z)=0;

   __property TFIBIntegerField * TableFL_KLIENT_UVEDOML_REM_Z = {read = get_TableFL_KLIENT_UVEDOML_REM_Z , write = set_TableFL_KLIENT_UVEDOML_REM_Z};
   virtual TFIBIntegerField * get_TableFL_KLIENT_UVEDOML_REM_Z(void)=0;
   virtual void set_TableFL_KLIENT_UVEDOML_REM_Z(TFIBIntegerField * TableFL_KLIENT_UVEDOML_REM_Z)=0;

   __property TFIBIntegerField * TableFL_TREB_KONS_KL_REM_Z = {read = get_TableFL_TREB_KONS_KL_REM_Z , write = set_TableFL_TREB_KONS_KL_REM_Z};
   virtual TFIBIntegerField * get_TableFL_TREB_KONS_KL_REM_Z(void)=0;
   virtual void set_TableFL_TREB_KONS_KL_REM_Z(TFIBIntegerField * TableFL_TREB_KONS_KL_REM_Z)=0;

   __property TFIBIntegerField * TableFL_KL_OTV_NA_ZAPROS_REM_Z = {read = get_TableFL_KL_OTV_NA_ZAPROS_REM_Z , write = set_TableFL_KL_OTV_NA_ZAPROS_REM_Z};
   virtual TFIBIntegerField * get_TableFL_KL_OTV_NA_ZAPROS_REM_Z(void)=0;
   virtual void set_TableFL_KL_OTV_NA_ZAPROS_REM_Z(TFIBIntegerField * TableFL_KL_OTV_NA_ZAPROS_REM_Z)=0;

   __property TFIBWideStringField * TablePREFIKS_NUM_REM_Z = {read = get_TablePREFIKS_NUM_REM_Z , write = set_TablePREFIKS_NUM_REM_Z};
   virtual TFIBWideStringField * get_TablePREFIKS_NUM_REM_Z(void)=0;
   virtual void set_TablePREFIKS_NUM_REM_Z(TFIBWideStringField * TablePREFIKS_NUM_REM_Z)=0;

   __property TFIBWideStringField * TableNAME_SINFBASE_OBMEN = {read = get_TableNAME_SINFBASE_OBMEN , write = set_TableNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)=0;

   __property TFIBLargeIntField * TableIDBRAND_REM_Z = {read = get_TableIDBRAND_REM_Z , write = set_TableIDBRAND_REM_Z};
   virtual TFIBLargeIntField * get_TableIDBRAND_REM_Z(void)=0;
   virtual void set_TableIDBRAND_REM_Z(TFIBLargeIntField * TableIDBRAND_REM_Z)=0;

   __property TFIBSmallIntField * TableFL_POVTOR_REM_Z = {read = get_TableFL_POVTOR_REM_Z , write = set_TableFL_POVTOR_REM_Z};
   virtual TFIBSmallIntField * get_TableFL_POVTOR_REM_Z(void)=0;
   virtual void set_TableFL_POVTOR_REM_Z(TFIBSmallIntField * TableFL_POVTOR_REM_Z)=0;

   __property TFIBSmallIntField * TableFL_ADDREPORT_REM_Z = {read = get_TableFL_ADDREPORT_REM_Z , write = set_TableFL_ADDREPORT_REM_Z};
   virtual TFIBSmallIntField * get_TableFL_ADDREPORT_REM_Z(void)=0;
   virtual void set_TableFL_ADDREPORT_REM_Z(TFIBSmallIntField * TableFL_ADDREPORT_REM_Z)=0;

   __property TFIBWideStringField * TableNUM_GARDOC_REM_Z = {read = get_TableNUM_GARDOC_REM_Z , write = set_TableNUM_GARDOC_REM_Z};
   virtual TFIBWideStringField * get_TableNUM_GARDOC_REM_Z(void)=0;
   virtual void set_TableNUM_GARDOC_REM_Z(TFIBWideStringField * TableNUM_GARDOC_REM_Z)=0;

   __property TFIBWideStringField * TableNAME_SBRAND = {read = get_TableNAME_SBRAND , write = set_TableNAME_SBRAND};
   virtual TFIBWideStringField * get_TableNAME_SBRAND(void)=0;
   virtual void set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)=0;

   __property TFIBIntegerField * TableFL_FICTIV_REM_Z = {read = get_TableFL_FICTIV_REM_Z , write = set_TableFL_FICTIV_REM_Z};
   virtual TFIBIntegerField * get_TableFL_FICTIV_REM_Z(void)=0;
   virtual void set_TableFL_FICTIV_REM_Z(TFIBIntegerField * TableFL_FICTIV_REM_Z)=0;

   __property TFIBSmallIntField * TableFL_NE_OTCH_REM_Z = {read = get_TableFL_NE_OTCH_REM_Z , write = set_TableFL_NE_OTCH_REM_Z};
   virtual TFIBSmallIntField * get_TableFL_NE_OTCH_REM_Z(void)=0;
   virtual void set_TableFL_NE_OTCH_REM_Z(TFIBSmallIntField * TableFL_NE_OTCH_REM_Z)=0;

   __property TFIBSmallIntField * TableFL_NADO_OTCH_REM_Z = {read = get_TableFL_NADO_OTCH_REM_Z , write = set_TableFL_NADO_OTCH_REM_Z};
   virtual TFIBSmallIntField * get_TableFL_NADO_OTCH_REM_Z(void)=0;
   virtual void set_TableFL_NADO_OTCH_REM_Z(TFIBSmallIntField * TableFL_NADO_OTCH_REM_Z)=0;

   __property TFIBSmallIntField * TableSOST_CQUERY = {read = get_TableSOST_CQUERY , write = set_TableSOST_CQUERY};
   virtual TFIBSmallIntField * get_TableSOST_CQUERY(void)=0;
   virtual void set_TableSOST_CQUERY(TFIBSmallIntField * TableSOST_CQUERY)=0;

   __property TFIBLargeIntField * TableID_REM_CQUERY = {read = get_TableID_REM_CQUERY , write = set_TableID_REM_CQUERY};
   virtual TFIBLargeIntField * get_TableID_REM_CQUERY(void)=0;
   virtual void set_TableID_REM_CQUERY(TFIBLargeIntField * TableID_REM_CQUERY)=0;

   __property TIntegerField * TableSROK_REMONTA = {read = get_TableSROK_REMONTA , write = set_TableSROK_REMONTA};
   virtual TIntegerField * get_TableSROK_REMONTA(void)=0;
   virtual void set_TableSROK_REMONTA(TIntegerField * TableSROK_REMONTA)=0;

   __property TIntegerField * TableSROK_REMONTA_NOW = {read = get_TableSROK_REMONTA_NOW , write = set_TableSROK_REMONTA_NOW};
   virtual TIntegerField * get_TableSROK_REMONTA_NOW(void)=0;
   virtual void set_TableSROK_REMONTA_NOW(TIntegerField * TableSROK_REMONTA_NOW)=0;

   __property TFIBDateTimeField * TablePOSOUT_REM_Z = {read = get_TablePOSOUT_REM_Z , write = set_TablePOSOUT_REM_Z};
   virtual TFIBDateTimeField * get_TablePOSOUT_REM_Z(void)=0;
   virtual void set_TablePOSOUT_REM_Z(TFIBDateTimeField * TablePOSOUT_REM_Z)=0;

   __property TFIBDateTimeField * TablePOSREMONT_REM_Z = {read = get_TablePOSREMONT_REM_Z , write = set_TablePOSREMONT_REM_Z};
   virtual TFIBDateTimeField * get_TablePOSREMONT_REM_Z(void)=0;
   virtual void set_TablePOSREMONT_REM_Z(TFIBDateTimeField * TablePOSREMONT_REM_Z)=0;

   __property TFIBSmallIntField * TableGOTOVO_K_VIDACHE_REM_Z = {read = get_TableGOTOVO_K_VIDACHE_REM_Z , write = set_TableGOTOVO_K_VIDACHE_REM_Z};
   virtual TFIBSmallIntField * get_TableGOTOVO_K_VIDACHE_REM_Z(void)=0;
   virtual void set_TableGOTOVO_K_VIDACHE_REM_Z(TFIBSmallIntField * TableGOTOVO_K_VIDACHE_REM_Z)=0;

   __property TFIBWideStringField * TableNAME_SKLAD_OST = {read = get_TableNAME_SKLAD_OST , write = set_TableNAME_SKLAD_OST};
   virtual TFIBWideStringField * get_TableNAME_SKLAD_OST(void)=0;
   virtual void set_TableNAME_SKLAD_OST(TFIBWideStringField * TableNAME_SKLAD_OST)=0;

   __property TFIBLargeIntField * TableIDREC_RGOTPRZ = {read = get_TableIDREC_RGOTPRZ , write = set_TableIDREC_RGOTPRZ};
   virtual TFIBLargeIntField * get_TableIDREC_RGOTPRZ(void)=0;
   virtual void set_TableIDREC_RGOTPRZ(TFIBLargeIntField * TableIDREC_RGOTPRZ)=0;

   __property TFIBLargeIntField * TableIDDOC_VIDACHA_HW = {read = get_TableIDDOC_VIDACHA_HW , write = set_TableIDDOC_VIDACHA_HW};
   virtual TFIBLargeIntField * get_TableIDDOC_VIDACHA_HW(void)=0;
   virtual void set_TableIDDOC_VIDACHA_HW(TFIBLargeIntField * TableIDDOC_VIDACHA_HW)=0;

   __property TFIBLargeIntField * TableIDDOC_VOSVRAT_HW = {read = get_TableIDDOC_VOSVRAT_HW , write = set_TableIDDOC_VOSVRAT_HW};
   virtual TFIBLargeIntField * get_TableIDDOC_VOSVRAT_HW(void)=0;
   virtual void set_TableIDDOC_VOSVRAT_HW(TFIBLargeIntField * TableIDDOC_VOSVRAT_HW)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdZ = {read = get_IdZ , write = set_IdZ};
   virtual __int64 get_IdZ(void)=0;
   virtual void set_IdZ(__int64 IdZ)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   virtual void OpenTable()=0;
   virtual void UpdateTable(void)=0;
   virtual void PoiskPoSerNum1(UnicodeString ser_num)=0;
   virtual void PoiskPoSerNum2(UnicodeString ser_num)=0;
   virtual void PoiskPoKlient(UnicodeString value)=0;
   virtual void PoiskPoModel(UnicodeString value)=0;
   virtual void PoiskPoIdHardware(__int64 id_hw)=0;
   virtual void PoiskPoNumGarDoc(UnicodeString num_gar_doc)=0;
   virtual void OpenTableOtbor(TDateTime pos_start,TDateTime pos_end,int poisk,UnicodeString str_value,__int64 int64_value)=0;
};
#define IID_IREM_DMGurZ __uuidof(IREM_DMGurZ)
#endif
