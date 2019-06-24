#ifndef UIREM_DMSprHardwareIspH
#define UIREM_DMSprHardwareIspH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprHardwareIsp)) IREM_DMSprHardwareIsp : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_REM_SHARDWARE_ISP = {read = get_TableID_REM_SHARDWARE_ISP , write = set_TableID_REM_SHARDWARE_ISP};
   virtual TFIBLargeIntField * get_TableID_REM_SHARDWARE_ISP(void)=0;
   virtual void set_TableID_REM_SHARDWARE_ISP(TFIBLargeIntField * TableID_REM_SHARDWARE_ISP)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SHARDWARE_ISP = {read = get_TableIDBASE_REM_SHARDWARE_ISP , write = set_TableIDBASE_REM_SHARDWARE_ISP};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SHARDWARE_ISP(void)=0;
   virtual void set_TableIDBASE_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDBASE_REM_SHARDWARE_ISP)=0;

   __property TFIBLargeIntField * TableIDHW_REM_SHARDWARE_ISP = {read = get_TableIDHW_REM_SHARDWARE_ISP , write = set_TableIDHW_REM_SHARDWARE_ISP};
   virtual TFIBLargeIntField * get_TableIDHW_REM_SHARDWARE_ISP(void)=0;
   virtual void set_TableIDHW_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDHW_REM_SHARDWARE_ISP)=0;

   __property TFIBDateTimeField * TablePOS_REM_SHARDWARE_ISP = {read = get_TablePOS_REM_SHARDWARE_ISP , write = set_TablePOS_REM_SHARDWARE_ISP};
   virtual TFIBDateTimeField * get_TablePOS_REM_SHARDWARE_ISP(void)=0;
   virtual void set_TablePOS_REM_SHARDWARE_ISP(TFIBDateTimeField * TablePOS_REM_SHARDWARE_ISP)=0;

   __property TFIBLargeIntField * TableIDUSER_REM_SHARDWARE_ISP = {read = get_TableIDUSER_REM_SHARDWARE_ISP , write = set_TableIDUSER_REM_SHARDWARE_ISP};
   virtual TFIBLargeIntField * get_TableIDUSER_REM_SHARDWARE_ISP(void)=0;
   virtual void set_TableIDUSER_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDUSER_REM_SHARDWARE_ISP)=0;

   __property TFIBLargeIntField * TableIDTYPEUSEL_REM_SHARDWARE_ISP = {read = get_TableIDTYPEUSEL_REM_SHARDWARE_ISP , write = set_TableIDTYPEUSEL_REM_SHARDWARE_ISP};
   virtual TFIBLargeIntField * get_TableIDTYPEUSEL_REM_SHARDWARE_ISP(void)=0;
   virtual void set_TableIDTYPEUSEL_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDTYPEUSEL_REM_SHARDWARE_ISP)=0;

   __property TFIBBCDField * TableKOL_REM_SHARDWARE_ISP = {read = get_TableKOL_REM_SHARDWARE_ISP , write = set_TableKOL_REM_SHARDWARE_ISP};
   virtual TFIBBCDField * get_TableKOL_REM_SHARDWARE_ISP(void)=0;
   virtual void set_TableKOL_REM_SHARDWARE_ISP(TFIBBCDField * TableKOL_REM_SHARDWARE_ISP)=0;

   __property TFIBWideStringField * TableDESCR_REM_SHARDWARE_ISP = {read = get_TableDESCR_REM_SHARDWARE_ISP , write = set_TableDESCR_REM_SHARDWARE_ISP};
   virtual TFIBWideStringField * get_TableDESCR_REM_SHARDWARE_ISP(void)=0;
   virtual void set_TableDESCR_REM_SHARDWARE_ISP(TFIBWideStringField * TableDESCR_REM_SHARDWARE_ISP)=0;

   __property TFIBSmallIntField * TableFL_OTCH_PR_REM_SHARDWARE_ISP = {read = get_TableFL_OTCH_PR_REM_SHARDWARE_ISP , write = set_TableFL_OTCH_PR_REM_SHARDWARE_ISP};
   virtual TFIBSmallIntField * get_TableFL_OTCH_PR_REM_SHARDWARE_ISP(void)=0;
   virtual void set_TableFL_OTCH_PR_REM_SHARDWARE_ISP(TFIBSmallIntField * TableFL_OTCH_PR_REM_SHARDWARE_ISP)=0;

   __property TFIBSmallIntField * TableFL_REAL_ISP_REM_SHARDWARE_ISP = {read = get_TableFL_REAL_ISP_REM_SHARDWARE_ISP , write = set_TableFL_REAL_ISP_REM_SHARDWARE_ISP};
   virtual TFIBSmallIntField * get_TableFL_REAL_ISP_REM_SHARDWARE_ISP(void)=0;
   virtual void set_TableFL_REAL_ISP_REM_SHARDWARE_ISP(TFIBSmallIntField * TableFL_REAL_ISP_REM_SHARDWARE_ISP)=0;

   __property TFIBLargeIntField * TableIDZ_REM_SHARDWARE_ISP = {read = get_TableIDZ_REM_SHARDWARE_ISP , write = set_TableIDZ_REM_SHARDWARE_ISP};
   virtual TFIBLargeIntField * get_TableIDZ_REM_SHARDWARE_ISP(void)=0;
   virtual void set_TableIDZ_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDZ_REM_SHARDWARE_ISP)=0;

   __property TFIBWideStringField * TableNAME_REM_STYPUSLOV = {read = get_TableNAME_REM_STYPUSLOV , write = set_TableNAME_REM_STYPUSLOV};
   virtual TFIBWideStringField * get_TableNAME_REM_STYPUSLOV(void)=0;
   virtual void set_TableNAME_REM_STYPUSLOV(TFIBWideStringField * TableNAME_REM_STYPUSLOV)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBWideStringField * TableNAME_REM_Z = {read = get_TableNAME_REM_Z , write = set_TableNAME_REM_Z};
   virtual TFIBWideStringField * get_TableNAME_REM_Z(void)=0;
   virtual void set_TableNAME_REM_Z(TFIBWideStringField * TableNAME_REM_Z)=0;

   __property TFIBWideStringField * TablePREFIKS_NUM_REM_Z = {read = get_TablePREFIKS_NUM_REM_Z , write = set_TablePREFIKS_NUM_REM_Z};
   virtual TFIBWideStringField * get_TablePREFIKS_NUM_REM_Z(void)=0;
   virtual void set_TablePREFIKS_NUM_REM_Z(TFIBWideStringField * TablePREFIKS_NUM_REM_Z)=0;

   __property TFIBDateTimeField * TablePOS_REM_Z = {read = get_TablePOS_REM_Z , write = set_TablePOS_REM_Z};
   virtual TFIBDateTimeField * get_TablePOS_REM_Z(void)=0;
   virtual void set_TablePOS_REM_Z(TFIBDateTimeField * TablePOS_REM_Z)=0;

   __property TFIBIntegerField * TableNUM_REM_Z = {read = get_TableNUM_REM_Z , write = set_TableNUM_REM_Z};
   virtual TFIBIntegerField * get_TableNUM_REM_Z(void)=0;
   virtual void set_TableNUM_REM_Z(TFIBIntegerField * TableNUM_REM_Z)=0;

   __property TFIBWideStringField * TableMODEL_REM_Z = {read = get_TableMODEL_REM_Z , write = set_TableMODEL_REM_Z};
   virtual TFIBWideStringField * get_TableMODEL_REM_Z(void)=0;
   virtual void set_TableMODEL_REM_Z(TFIBWideStringField * TableMODEL_REM_Z)=0;

   __property TFIBWideStringField * TableSERNUM_REM_Z = {read = get_TableSERNUM_REM_Z , write = set_TableSERNUM_REM_Z};
   virtual TFIBWideStringField * get_TableSERNUM_REM_Z(void)=0;
   virtual void set_TableSERNUM_REM_Z(TFIBWideStringField * TableSERNUM_REM_Z)=0;

   __property TFIBLargeIntField * ElementID_REM_SHARDWARE_ISP = {read = get_ElementID_REM_SHARDWARE_ISP , write = set_ElementID_REM_SHARDWARE_ISP};
   virtual TFIBLargeIntField * get_ElementID_REM_SHARDWARE_ISP(void)=0;
   virtual void set_ElementID_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementID_REM_SHARDWARE_ISP)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SHARDWARE_ISP = {read = get_ElementIDBASE_REM_SHARDWARE_ISP , write = set_ElementIDBASE_REM_SHARDWARE_ISP};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SHARDWARE_ISP(void)=0;
   virtual void set_ElementIDBASE_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDBASE_REM_SHARDWARE_ISP)=0;

   __property TFIBLargeIntField * ElementIDHW_REM_SHARDWARE_ISP = {read = get_ElementIDHW_REM_SHARDWARE_ISP , write = set_ElementIDHW_REM_SHARDWARE_ISP};
   virtual TFIBLargeIntField * get_ElementIDHW_REM_SHARDWARE_ISP(void)=0;
   virtual void set_ElementIDHW_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDHW_REM_SHARDWARE_ISP)=0;

   __property TFIBDateTimeField * ElementPOS_REM_SHARDWARE_ISP = {read = get_ElementPOS_REM_SHARDWARE_ISP , write = set_ElementPOS_REM_SHARDWARE_ISP};
   virtual TFIBDateTimeField * get_ElementPOS_REM_SHARDWARE_ISP(void)=0;
   virtual void set_ElementPOS_REM_SHARDWARE_ISP(TFIBDateTimeField * ElementPOS_REM_SHARDWARE_ISP)=0;

   __property TFIBLargeIntField * ElementIDUSER_REM_SHARDWARE_ISP = {read = get_ElementIDUSER_REM_SHARDWARE_ISP , write = set_ElementIDUSER_REM_SHARDWARE_ISP};
   virtual TFIBLargeIntField * get_ElementIDUSER_REM_SHARDWARE_ISP(void)=0;
   virtual void set_ElementIDUSER_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDUSER_REM_SHARDWARE_ISP)=0;

   __property TFIBLargeIntField * ElementIDTYPEUSEL_REM_SHARDWARE_ISP = {read = get_ElementIDTYPEUSEL_REM_SHARDWARE_ISP , write = set_ElementIDTYPEUSEL_REM_SHARDWARE_ISP};
   virtual TFIBLargeIntField * get_ElementIDTYPEUSEL_REM_SHARDWARE_ISP(void)=0;
   virtual void set_ElementIDTYPEUSEL_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDTYPEUSEL_REM_SHARDWARE_ISP)=0;

   __property TFIBBCDField * ElementKOL_REM_SHARDWARE_ISP = {read = get_ElementKOL_REM_SHARDWARE_ISP , write = set_ElementKOL_REM_SHARDWARE_ISP};
   virtual TFIBBCDField * get_ElementKOL_REM_SHARDWARE_ISP(void)=0;
   virtual void set_ElementKOL_REM_SHARDWARE_ISP(TFIBBCDField * ElementKOL_REM_SHARDWARE_ISP)=0;

   __property TFIBWideStringField * ElementDESCR_REM_SHARDWARE_ISP = {read = get_ElementDESCR_REM_SHARDWARE_ISP , write = set_ElementDESCR_REM_SHARDWARE_ISP};
   virtual TFIBWideStringField * get_ElementDESCR_REM_SHARDWARE_ISP(void)=0;
   virtual void set_ElementDESCR_REM_SHARDWARE_ISP(TFIBWideStringField * ElementDESCR_REM_SHARDWARE_ISP)=0;

   __property TFIBSmallIntField * ElementFL_OTCH_PR_REM_SHARDWARE_ISP = {read = get_ElementFL_OTCH_PR_REM_SHARDWARE_ISP , write = set_ElementFL_OTCH_PR_REM_SHARDWARE_ISP};
   virtual TFIBSmallIntField * get_ElementFL_OTCH_PR_REM_SHARDWARE_ISP(void)=0;
   virtual void set_ElementFL_OTCH_PR_REM_SHARDWARE_ISP(TFIBSmallIntField * ElementFL_OTCH_PR_REM_SHARDWARE_ISP)=0;

   __property TFIBSmallIntField * ElementFL_REAL_ISP_REM_SHARDWARE_ISP = {read = get_ElementFL_REAL_ISP_REM_SHARDWARE_ISP , write = set_ElementFL_REAL_ISP_REM_SHARDWARE_ISP};
   virtual TFIBSmallIntField * get_ElementFL_REAL_ISP_REM_SHARDWARE_ISP(void)=0;
   virtual void set_ElementFL_REAL_ISP_REM_SHARDWARE_ISP(TFIBSmallIntField * ElementFL_REAL_ISP_REM_SHARDWARE_ISP)=0;

   __property TFIBLargeIntField * ElementIDZ_REM_SHARDWARE_ISP = {read = get_ElementIDZ_REM_SHARDWARE_ISP , write = set_ElementIDZ_REM_SHARDWARE_ISP};
   virtual TFIBLargeIntField * get_ElementIDZ_REM_SHARDWARE_ISP(void)=0;
   virtual void set_ElementIDZ_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDZ_REM_SHARDWARE_ISP)=0;

   __property TFIBWideStringField * ElementNAME_REM_STYPUSLOV = {read = get_ElementNAME_REM_STYPUSLOV , write = set_ElementNAME_REM_STYPUSLOV};
   virtual TFIBWideStringField * get_ElementNAME_REM_STYPUSLOV(void)=0;
   virtual void set_ElementNAME_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_REM_STYPUSLOV)=0;

   __property TFIBWideStringField * ElementNAME_USER = {read = get_ElementNAME_USER , write = set_ElementNAME_USER};
   virtual TFIBWideStringField * get_ElementNAME_USER(void)=0;
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)=0;

   __property TFIBWideStringField * ElementNAME_REM_Z = {read = get_ElementNAME_REM_Z , write = set_ElementNAME_REM_Z};
   virtual TFIBWideStringField * get_ElementNAME_REM_Z(void)=0;
   virtual void set_ElementNAME_REM_Z(TFIBWideStringField * ElementNAME_REM_Z)=0;

   __property TFIBWideStringField * ElementPREFIKS_NUM_REM_Z = {read = get_ElementPREFIKS_NUM_REM_Z , write = set_ElementPREFIKS_NUM_REM_Z};
   virtual TFIBWideStringField * get_ElementPREFIKS_NUM_REM_Z(void)=0;
   virtual void set_ElementPREFIKS_NUM_REM_Z(TFIBWideStringField * ElementPREFIKS_NUM_REM_Z)=0;

   __property TFIBDateTimeField * ElementPOS_REM_Z = {read = get_ElementPOS_REM_Z , write = set_ElementPOS_REM_Z};
   virtual TFIBDateTimeField * get_ElementPOS_REM_Z(void)=0;
   virtual void set_ElementPOS_REM_Z(TFIBDateTimeField * ElementPOS_REM_Z)=0;

   __property TFIBIntegerField * ElementNUM_REM_Z = {read = get_ElementNUM_REM_Z , write = set_ElementNUM_REM_Z};
   virtual TFIBIntegerField * get_ElementNUM_REM_Z(void)=0;
   virtual void set_ElementNUM_REM_Z(TFIBIntegerField * ElementNUM_REM_Z)=0;

   __property TFIBWideStringField * ElementMODEL_REM_Z = {read = get_ElementMODEL_REM_Z , write = set_ElementMODEL_REM_Z};
   virtual TFIBWideStringField * get_ElementMODEL_REM_Z(void)=0;
   virtual void set_ElementMODEL_REM_Z(TFIBWideStringField * ElementMODEL_REM_Z)=0;

   __property TFIBWideStringField * ElementSERNUM_REM_Z = {read = get_ElementSERNUM_REM_Z , write = set_ElementSERNUM_REM_Z};
   virtual TFIBWideStringField * get_ElementSERNUM_REM_Z(void)=0;
   virtual void set_ElementSERNUM_REM_Z(TFIBWideStringField * ElementSERNUM_REM_Z)=0;

   __property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};
   virtual __int64 get_IdOwner(void)=0;
   virtual void set_IdOwner(__int64 IdOwner)=0;

   virtual void OpenTable(__int64 id_owner)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_owner)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IREM_DMSprHardwareIsp __uuidof(IREM_DMSprHardwareIsp)
#endif
