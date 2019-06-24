#ifndef UIREM_DMGurZPredvH
#define UIREM_DMGurZPredvH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMGurZPredv)) IREM_DMGurZPredv : public IMainInterface
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

   __property TFIBLargeIntField * TableID_REM_Z2 = {read = get_TableID_REM_Z2 , write = set_TableID_REM_Z2};
   virtual TFIBLargeIntField * get_TableID_REM_Z2(void)=0;
   virtual void set_TableID_REM_Z2(TFIBLargeIntField * TableID_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_Z2 = {read = get_TableIDBASE_REM_Z2 , write = set_TableIDBASE_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_Z2(void)=0;
   virtual void set_TableIDBASE_REM_Z2(TFIBLargeIntField * TableIDBASE_REM_Z2)=0;

   __property TFIBWideStringField * TablePREFIKS_REM_Z2 = {read = get_TablePREFIKS_REM_Z2 , write = set_TablePREFIKS_REM_Z2};
   virtual TFIBWideStringField * get_TablePREFIKS_REM_Z2(void)=0;
   virtual void set_TablePREFIKS_REM_Z2(TFIBWideStringField * TablePREFIKS_REM_Z2)=0;

   __property TFIBIntegerField * TableNUM_REM_Z2 = {read = get_TableNUM_REM_Z2 , write = set_TableNUM_REM_Z2};
   virtual TFIBIntegerField * get_TableNUM_REM_Z2(void)=0;
   virtual void set_TableNUM_REM_Z2(TFIBIntegerField * TableNUM_REM_Z2)=0;

   __property TFIBWideStringField * TableGUID_REM_Z2 = {read = get_TableGUID_REM_Z2 , write = set_TableGUID_REM_Z2};
   virtual TFIBWideStringField * get_TableGUID_REM_Z2(void)=0;
   virtual void set_TableGUID_REM_Z2(TFIBWideStringField * TableGUID_REM_Z2)=0;

   __property TFIBDateTimeField * TablePOS_REM_Z2 = {read = get_TablePOS_REM_Z2 , write = set_TablePOS_REM_Z2};
   virtual TFIBDateTimeField * get_TablePOS_REM_Z2(void)=0;
   virtual void set_TablePOS_REM_Z2(TFIBDateTimeField * TablePOS_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDMODEL_REM_Z2 = {read = get_TableIDMODEL_REM_Z2 , write = set_TableIDMODEL_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDMODEL_REM_Z2(void)=0;
   virtual void set_TableIDMODEL_REM_Z2(TFIBLargeIntField * TableIDMODEL_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDPRMODEL_REM_Z2 = {read = get_TableIDPRMODEL_REM_Z2 , write = set_TableIDPRMODEL_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDPRMODEL_REM_Z2(void)=0;
   virtual void set_TableIDPRMODEL_REM_Z2(TFIBLargeIntField * TableIDPRMODEL_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDFIRM_REM_Z2 = {read = get_TableIDFIRM_REM_Z2 , write = set_TableIDFIRM_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDFIRM_REM_Z2(void)=0;
   virtual void set_TableIDFIRM_REM_Z2(TFIBLargeIntField * TableIDFIRM_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDSKLPR_REM_Z2 = {read = get_TableIDSKLPR_REM_Z2 , write = set_TableIDSKLPR_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDSKLPR_REM_Z2(void)=0;
   virtual void set_TableIDSKLPR_REM_Z2(TFIBLargeIntField * TableIDSKLPR_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDKLIENT_REM_Z2 = {read = get_TableIDKLIENT_REM_Z2 , write = set_TableIDKLIENT_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDKLIENT_REM_Z2(void)=0;
   virtual void set_TableIDKLIENT_REM_Z2(TFIBLargeIntField * TableIDKLIENT_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDDILER_REM_Z2 = {read = get_TableIDDILER_REM_Z2 , write = set_TableIDDILER_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDDILER_REM_Z2(void)=0;
   virtual void set_TableIDDILER_REM_Z2(TFIBLargeIntField * TableIDDILER_REM_Z2)=0;

   __property TFIBWideStringField * TableNAME_REM_Z2 = {read = get_TableNAME_REM_Z2 , write = set_TableNAME_REM_Z2};
   virtual TFIBWideStringField * get_TableNAME_REM_Z2(void)=0;
   virtual void set_TableNAME_REM_Z2(TFIBWideStringField * TableNAME_REM_Z2)=0;

   __property TFIBWideStringField * TableDESCR_REM_Z2 = {read = get_TableDESCR_REM_Z2 , write = set_TableDESCR_REM_Z2};
   virtual TFIBWideStringField * get_TableDESCR_REM_Z2(void)=0;
   virtual void set_TableDESCR_REM_Z2(TFIBWideStringField * TableDESCR_REM_Z2)=0;

   __property TFIBWideStringField * TableKLIENT_NAME_REM_Z2 = {read = get_TableKLIENT_NAME_REM_Z2 , write = set_TableKLIENT_NAME_REM_Z2};
   virtual TFIBWideStringField * get_TableKLIENT_NAME_REM_Z2(void)=0;
   virtual void set_TableKLIENT_NAME_REM_Z2(TFIBWideStringField * TableKLIENT_NAME_REM_Z2)=0;

   __property TFIBWideStringField * TableKLIENT_ADR_REM_Z2 = {read = get_TableKLIENT_ADR_REM_Z2 , write = set_TableKLIENT_ADR_REM_Z2};
   virtual TFIBWideStringField * get_TableKLIENT_ADR_REM_Z2(void)=0;
   virtual void set_TableKLIENT_ADR_REM_Z2(TFIBWideStringField * TableKLIENT_ADR_REM_Z2)=0;

   __property TFIBWideStringField * TableKLIENT_PHONE_REM_Z2 = {read = get_TableKLIENT_PHONE_REM_Z2 , write = set_TableKLIENT_PHONE_REM_Z2};
   virtual TFIBWideStringField * get_TableKLIENT_PHONE_REM_Z2(void)=0;
   virtual void set_TableKLIENT_PHONE_REM_Z2(TFIBWideStringField * TableKLIENT_PHONE_REM_Z2)=0;

   __property TFIBWideStringField * TableKLIENT_EMAIL_REM_Z2 = {read = get_TableKLIENT_EMAIL_REM_Z2 , write = set_TableKLIENT_EMAIL_REM_Z2};
   virtual TFIBWideStringField * get_TableKLIENT_EMAIL_REM_Z2(void)=0;
   virtual void set_TableKLIENT_EMAIL_REM_Z2(TFIBWideStringField * TableKLIENT_EMAIL_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDBRAND_REM_Z2 = {read = get_TableIDBRAND_REM_Z2 , write = set_TableIDBRAND_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDBRAND_REM_Z2(void)=0;
   virtual void set_TableIDBRAND_REM_Z2(TFIBLargeIntField * TableIDBRAND_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDPRODUCER_REM_Z2 = {read = get_TableIDPRODUCER_REM_Z2 , write = set_TableIDPRODUCER_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDPRODUCER_REM_Z2(void)=0;
   virtual void set_TableIDPRODUCER_REM_Z2(TFIBLargeIntField * TableIDPRODUCER_REM_Z2)=0;

   __property TFIBWideStringField * TableNEISPR_REM_Z2 = {read = get_TableNEISPR_REM_Z2 , write = set_TableNEISPR_REM_Z2};
   virtual TFIBWideStringField * get_TableNEISPR_REM_Z2(void)=0;
   virtual void set_TableNEISPR_REM_Z2(TFIBWideStringField * TableNEISPR_REM_Z2)=0;

   __property TFIBWideStringField * TableSOST_REM_Z2 = {read = get_TableSOST_REM_Z2 , write = set_TableSOST_REM_Z2};
   virtual TFIBWideStringField * get_TableSOST_REM_Z2(void)=0;
   virtual void set_TableSOST_REM_Z2(TFIBWideStringField * TableSOST_REM_Z2)=0;

   __property TFIBWideStringField * TableMODEL_STR_REM_Z2 = {read = get_TableMODEL_STR_REM_Z2 , write = set_TableMODEL_STR_REM_Z2};
   virtual TFIBWideStringField * get_TableMODEL_STR_REM_Z2(void)=0;
   virtual void set_TableMODEL_STR_REM_Z2(TFIBWideStringField * TableMODEL_STR_REM_Z2)=0;

   __property TFIBWideStringField * TableSERNUM1_REM_Z2 = {read = get_TableSERNUM1_REM_Z2 , write = set_TableSERNUM1_REM_Z2};
   virtual TFIBWideStringField * get_TableSERNUM1_REM_Z2(void)=0;
   virtual void set_TableSERNUM1_REM_Z2(TFIBWideStringField * TableSERNUM1_REM_Z2)=0;

   __property TFIBWideStringField * TableSERNUM2_REM_Z2 = {read = get_TableSERNUM2_REM_Z2 , write = set_TableSERNUM2_REM_Z2};
   virtual TFIBWideStringField * get_TableSERNUM2_REM_Z2(void)=0;
   virtual void set_TableSERNUM2_REM_Z2(TFIBWideStringField * TableSERNUM2_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDKKT_REM_Z2 = {read = get_TableIDKKT_REM_Z2 , write = set_TableIDKKT_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDKKT_REM_Z2(void)=0;
   virtual void set_TableIDKKT_REM_Z2(TFIBLargeIntField * TableIDKKT_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDHW_REM_Z2 = {read = get_TableIDHW_REM_Z2 , write = set_TableIDHW_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDHW_REM_Z2(void)=0;
   virtual void set_TableIDHW_REM_Z2(TFIBLargeIntField * TableIDHW_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDSELLER_REM_Z2 = {read = get_TableIDSELLER_REM_Z2 , write = set_TableIDSELLER_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDSELLER_REM_Z2(void)=0;
   virtual void set_TableIDSELLER_REM_Z2(TFIBLargeIntField * TableIDSELLER_REM_Z2)=0;

   __property TFIBWideStringField * TableDOPOPISANIE_REM_Z2 = {read = get_TableDOPOPISANIE_REM_Z2 , write = set_TableDOPOPISANIE_REM_Z2};
   virtual TFIBWideStringField * get_TableDOPOPISANIE_REM_Z2(void)=0;
   virtual void set_TableDOPOPISANIE_REM_Z2(TFIBWideStringField * TableDOPOPISANIE_REM_Z2)=0;

   __property TFIBBCDField * TableSUMKLIENTA_REM_Z2 = {read = get_TableSUMKLIENTA_REM_Z2 , write = set_TableSUMKLIENTA_REM_Z2};
   virtual TFIBBCDField * get_TableSUMKLIENTA_REM_Z2(void)=0;
   virtual void set_TableSUMKLIENTA_REM_Z2(TFIBBCDField * TableSUMKLIENTA_REM_Z2)=0;

   __property TFIBBCDField * TableSUMNACHA_REM_Z2 = {read = get_TableSUMNACHA_REM_Z2 , write = set_TableSUMNACHA_REM_Z2};
   virtual TFIBBCDField * get_TableSUMNACHA_REM_Z2(void)=0;
   virtual void set_TableSUMNACHA_REM_Z2(TFIBBCDField * TableSUMNACHA_REM_Z2)=0;

   __property TFIBIntegerField * TableRESULT_REM_Z2 = {read = get_TableRESULT_REM_Z2 , write = set_TableRESULT_REM_Z2};
   virtual TFIBIntegerField * get_TableRESULT_REM_Z2(void)=0;
   virtual void set_TableRESULT_REM_Z2(TFIBIntegerField * TableRESULT_REM_Z2)=0;

   __property TFIBWideStringField * TablePRICHINA_REM_Z2 = {read = get_TablePRICHINA_REM_Z2 , write = set_TablePRICHINA_REM_Z2};
   virtual TFIBWideStringField * get_TablePRICHINA_REM_Z2(void)=0;
   virtual void set_TablePRICHINA_REM_Z2(TFIBWideStringField * TablePRICHINA_REM_Z2)=0;

   __property TFIBIntegerField * TablePRICHINA_LIST_REM_Z2 = {read = get_TablePRICHINA_LIST_REM_Z2 , write = set_TablePRICHINA_LIST_REM_Z2};
   virtual TFIBIntegerField * get_TablePRICHINA_LIST_REM_Z2(void)=0;
   virtual void set_TablePRICHINA_LIST_REM_Z2(TFIBIntegerField * TablePRICHINA_LIST_REM_Z2)=0;

   __property TFIBIntegerField * TableSROK_REM_Z2 = {read = get_TableSROK_REM_Z2 , write = set_TableSROK_REM_Z2};
   virtual TFIBIntegerField * get_TableSROK_REM_Z2(void)=0;
   virtual void set_TableSROK_REM_Z2(TFIBIntegerField * TableSROK_REM_Z2)=0;

   __property TFIBLargeIntField * TableIDUSER_REM_Z2 = {read = get_TableIDUSER_REM_Z2 , write = set_TableIDUSER_REM_Z2};
   virtual TFIBLargeIntField * get_TableIDUSER_REM_Z2(void)=0;
   virtual void set_TableIDUSER_REM_Z2(TFIBLargeIntField * TableIDUSER_REM_Z2)=0;

   __property TFIBWideStringField * TableNAME_SINFBASE_OBMEN = {read = get_TableNAME_SINFBASE_OBMEN , write = set_TableNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)=0;

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

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBWideStringField * TableNAME_SBRAND = {read = get_TableNAME_SBRAND , write = set_TableNAME_SBRAND};
   virtual TFIBWideStringField * get_TableNAME_SBRAND(void)=0;
   virtual void set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)=0;

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
#define IID_IREM_DMGurZPredv __uuidof(IREM_DMGurZPredv)
#endif
