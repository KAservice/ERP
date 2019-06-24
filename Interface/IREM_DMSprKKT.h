#ifndef UIREM_DMSprKKTH
#define UIREM_DMSprKKTH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{E9E71044-3F38-4E44-BAFB-6605A3EDABFC}"))IREM_DMSprKKT : public IMainInterface
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

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBLargeIntField * TableID_REM_SKKT = {read = get_TableID_REM_SKKT , write = set_TableID_REM_SKKT};
   virtual TFIBLargeIntField * get_TableID_REM_SKKT(void)=0;
   virtual void set_TableID_REM_SKKT(TFIBLargeIntField * TableID_REM_SKKT)=0;

   __property TFIBWideStringField * TableNAME_REM_SKKT = {read = get_TableNAME_REM_SKKT , write = set_TableNAME_REM_SKKT};
   virtual TFIBWideStringField * get_TableNAME_REM_SKKT(void)=0;
   virtual void set_TableNAME_REM_SKKT(TFIBWideStringField * TableNAME_REM_SKKT)=0;

   __property TFIBWideStringField * TableSERNUM_REM_SKKT = {read = get_TableSERNUM_REM_SKKT , write = set_TableSERNUM_REM_SKKT};
   virtual TFIBWideStringField * get_TableSERNUM_REM_SKKT(void)=0;
   virtual void set_TableSERNUM_REM_SKKT(TFIBWideStringField * TableSERNUM_REM_SKKT)=0;

   __property TFIBWideStringField * TableNAME_REM_SMODEL = {read = get_TableNAME_REM_SMODEL , write = set_TableNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void)=0;
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)=0;

   __property TFIBWideStringField * TableMESTOUST_REM_SKKT = {read = get_TableMESTOUST_REM_SKKT , write = set_TableMESTOUST_REM_SKKT};
   virtual TFIBWideStringField * get_TableMESTOUST_REM_SKKT(void)=0;
   virtual void set_TableMESTOUST_REM_SKKT(TFIBWideStringField * TableMESTOUST_REM_SKKT)=0;

   __property TFIBLargeIntField * TableIDGRP_REM_SKKT = {read = get_TableIDGRP_REM_SKKT , write = set_TableIDGRP_REM_SKKT};
   virtual TFIBLargeIntField * get_TableIDGRP_REM_SKKT(void)=0;
   virtual void set_TableIDGRP_REM_SKKT(TFIBLargeIntField * TableIDGRP_REM_SKKT)=0;

   __property TFIBLargeIntField * ElementID_REM_SKKT = {read = get_ElementID_REM_SKKT , write = set_ElementID_REM_SKKT};
   virtual TFIBLargeIntField * get_ElementID_REM_SKKT(void)=0;
   virtual void set_ElementID_REM_SKKT(TFIBLargeIntField * ElementID_REM_SKKT)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SKKT = {read = get_ElementIDBASE_REM_SKKT , write = set_ElementIDBASE_REM_SKKT};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SKKT(void)=0;
   virtual void set_ElementIDBASE_REM_SKKT(TFIBLargeIntField * ElementIDBASE_REM_SKKT)=0;

   __property TFIBWideStringField * ElementNAME_REM_SKKT = {read = get_ElementNAME_REM_SKKT , write = set_ElementNAME_REM_SKKT};
   virtual TFIBWideStringField * get_ElementNAME_REM_SKKT(void)=0;
   virtual void set_ElementNAME_REM_SKKT(TFIBWideStringField * ElementNAME_REM_SKKT)=0;

   __property TFIBWideStringField * ElementSERNUM_REM_SKKT = {read = get_ElementSERNUM_REM_SKKT , write = set_ElementSERNUM_REM_SKKT};
   virtual TFIBWideStringField * get_ElementSERNUM_REM_SKKT(void)=0;
   virtual void set_ElementSERNUM_REM_SKKT(TFIBWideStringField * ElementSERNUM_REM_SKKT)=0;

   __property TFIBLargeIntField * ElementIDMODEL_REM_SKKT = {read = get_ElementIDMODEL_REM_SKKT , write = set_ElementIDMODEL_REM_SKKT};
   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SKKT(void)=0;
   virtual void set_ElementIDMODEL_REM_SKKT(TFIBLargeIntField * ElementIDMODEL_REM_SKKT)=0;

   __property TFIBWideStringField * ElementREGNUM_REM_SKKT = {read = get_ElementREGNUM_REM_SKKT , write = set_ElementREGNUM_REM_SKKT};
   virtual TFIBWideStringField * get_ElementREGNUM_REM_SKKT(void)=0;
   virtual void set_ElementREGNUM_REM_SKKT(TFIBWideStringField * ElementREGNUM_REM_SKKT)=0;

   __property TFIBLargeIntField * ElementIDKLIENT_REM_SKKT = {read = get_ElementIDKLIENT_REM_SKKT , write = set_ElementIDKLIENT_REM_SKKT};
   virtual TFIBLargeIntField * get_ElementIDKLIENT_REM_SKKT(void)=0;
   virtual void set_ElementIDKLIENT_REM_SKKT(TFIBLargeIntField * ElementIDKLIENT_REM_SKKT)=0;

   __property TFIBWideStringField * ElementMESTOUST_REM_SKKT = {read = get_ElementMESTOUST_REM_SKKT , write = set_ElementMESTOUST_REM_SKKT};
   virtual TFIBWideStringField * get_ElementMESTOUST_REM_SKKT(void)=0;
   virtual void set_ElementMESTOUST_REM_SKKT(TFIBWideStringField * ElementMESTOUST_REM_SKKT)=0;

   __property TFIBDateField * ElementRELEASE_REM_SKKT = {read = get_ElementRELEASE_REM_SKKT , write = set_ElementRELEASE_REM_SKKT};
   virtual TFIBDateField * get_ElementRELEASE_REM_SKKT(void)=0;
   virtual void set_ElementRELEASE_REM_SKKT(TFIBDateField * ElementRELEASE_REM_SKKT)=0;

   __property TFIBDateField * ElementVVOD_REM_SKKT = {read = get_ElementVVOD_REM_SKKT , write = set_ElementVVOD_REM_SKKT};
   virtual TFIBDateField * get_ElementVVOD_REM_SKKT(void)=0;
   virtual void set_ElementVVOD_REM_SKKT(TFIBDateField * ElementVVOD_REM_SKKT)=0;

   __property TFIBWideStringField * ElementCBKGR_REM_SKKT = {read = get_ElementCBKGR_REM_SKKT , write = set_ElementCBKGR_REM_SKKT};
   virtual TFIBWideStringField * get_ElementCBKGR_REM_SKKT(void)=0;
   virtual void set_ElementCBKGR_REM_SKKT(TFIBWideStringField * ElementCBKGR_REM_SKKT)=0;

   __property TFIBWideStringField * ElementCBKCO_REM_SKKT = {read = get_ElementCBKCO_REM_SKKT , write = set_ElementCBKCO_REM_SKKT};
   virtual TFIBWideStringField * get_ElementCBKCO_REM_SKKT(void)=0;
   virtual void set_ElementCBKCO_REM_SKKT(TFIBWideStringField * ElementCBKCO_REM_SKKT)=0;

   __property TFIBWideStringField * ElementNUMCONTRACT_REM_SKKT = {read = get_ElementNUMCONTRACT_REM_SKKT , write = set_ElementNUMCONTRACT_REM_SKKT};
   virtual TFIBWideStringField * get_ElementNUMCONTRACT_REM_SKKT(void)=0;
   virtual void set_ElementNUMCONTRACT_REM_SKKT(TFIBWideStringField * ElementNUMCONTRACT_REM_SKKT)=0;

   __property TFIBDateField * ElementDATECONTRACT_REM_SKKT = {read = get_ElementDATECONTRACT_REM_SKKT , write = set_ElementDATECONTRACT_REM_SKKT};
   virtual TFIBDateField * get_ElementDATECONTRACT_REM_SKKT(void)=0;
   virtual void set_ElementDATECONTRACT_REM_SKKT(TFIBDateField * ElementDATECONTRACT_REM_SKKT)=0;

   __property TFIBBCDField * ElementSUMCONTRACT_REM_SKKT = {read = get_ElementSUMCONTRACT_REM_SKKT , write = set_ElementSUMCONTRACT_REM_SKKT};
   virtual TFIBBCDField * get_ElementSUMCONTRACT_REM_SKKT(void)=0;
   virtual void set_ElementSUMCONTRACT_REM_SKKT(TFIBBCDField * ElementSUMCONTRACT_REM_SKKT)=0;

   __property TFIBWideStringField * ElementEKLZ_SERNUM_REM_SKKT = {read = get_ElementEKLZ_SERNUM_REM_SKKT , write = set_ElementEKLZ_SERNUM_REM_SKKT};
   virtual TFIBWideStringField * get_ElementEKLZ_SERNUM_REM_SKKT(void)=0;
   virtual void set_ElementEKLZ_SERNUM_REM_SKKT(TFIBWideStringField * ElementEKLZ_SERNUM_REM_SKKT)=0;

   __property TFIBWideStringField * ElementEKLZ_REGNUM_REM_SKKT = {read = get_ElementEKLZ_REGNUM_REM_SKKT , write = set_ElementEKLZ_REGNUM_REM_SKKT};
   virtual TFIBWideStringField * get_ElementEKLZ_REGNUM_REM_SKKT(void)=0;
   virtual void set_ElementEKLZ_REGNUM_REM_SKKT(TFIBWideStringField * ElementEKLZ_REGNUM_REM_SKKT)=0;

   __property TFIBDateField * ElementEKLZ_ACT_REM_SKKT = {read = get_ElementEKLZ_ACT_REM_SKKT , write = set_ElementEKLZ_ACT_REM_SKKT};
   virtual TFIBDateField * get_ElementEKLZ_ACT_REM_SKKT(void)=0;
   virtual void set_ElementEKLZ_ACT_REM_SKKT(TFIBDateField * ElementEKLZ_ACT_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPAS_NUMVER_REM_SKKT = {read = get_ElementPAS_NUMVER_REM_SKKT , write = set_ElementPAS_NUMVER_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPAS_NUMVER_REM_SKKT(void)=0;
   virtual void set_ElementPAS_NUMVER_REM_SKKT(TFIBWideStringField * ElementPAS_NUMVER_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPAS_NUMPAS_REM_SKKT = {read = get_ElementPAS_NUMPAS_REM_SKKT , write = set_ElementPAS_NUMPAS_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPAS_NUMPAS_REM_SKKT(void)=0;
   virtual void set_ElementPAS_NUMPAS_REM_SKKT(TFIBWideStringField * ElementPAS_NUMPAS_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPAS_NUMPU_REM_SKKT = {read = get_ElementPAS_NUMPU_REM_SKKT , write = set_ElementPAS_NUMPU_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPAS_NUMPU_REM_SKKT(void)=0;
   virtual void set_ElementPAS_NUMPU_REM_SKKT(TFIBWideStringField * ElementPAS_NUMPU_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPAS_NUMSP_REM_SKKT = {read = get_ElementPAS_NUMSP_REM_SKKT , write = set_ElementPAS_NUMSP_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPAS_NUMSP_REM_SKKT(void)=0;
   virtual void set_ElementPAS_NUMSP_REM_SKKT(TFIBWideStringField * ElementPAS_NUMSP_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPAS_NUMSPPO_REM_SKKT = {read = get_ElementPAS_NUMSPPO_REM_SKKT , write = set_ElementPAS_NUMSPPO_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPAS_NUMSPPO_REM_SKKT(void)=0;
   virtual void set_ElementPAS_NUMSPPO_REM_SKKT(TFIBWideStringField * ElementPAS_NUMSPPO_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPAS_NUMFP_REM_SKKT = {read = get_ElementPAS_NUMFP_REM_SKKT , write = set_ElementPAS_NUMFP_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPAS_NUMFP_REM_SKKT(void)=0;
   virtual void set_ElementPAS_NUMFP_REM_SKKT(TFIBWideStringField * ElementPAS_NUMFP_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPAS_NUMFPPO_REM_SKKT = {read = get_ElementPAS_NUMFPPO_REM_SKKT , write = set_ElementPAS_NUMFPPO_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPAS_NUMFPPO_REM_SKKT(void)=0;
   virtual void set_ElementPAS_NUMFPPO_REM_SKKT(TFIBWideStringField * ElementPAS_NUMFPPO_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPAS_NUMDO_REM_SKKT = {read = get_ElementPAS_NUMDO_REM_SKKT , write = set_ElementPAS_NUMDO_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPAS_NUMDO_REM_SKKT(void)=0;
   virtual void set_ElementPAS_NUMDO_REM_SKKT(TFIBWideStringField * ElementPAS_NUMDO_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPAS_NUMDOPO_REM_SKKT = {read = get_ElementPAS_NUMDOPO_REM_SKKT , write = set_ElementPAS_NUMDOPO_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPAS_NUMDOPO_REM_SKKT(void)=0;
   virtual void set_ElementPAS_NUMDOPO_REM_SKKT(TFIBWideStringField * ElementPAS_NUMDOPO_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPAS_NUMPPP_REM_SKKT = {read = get_ElementPAS_NUMPPP_REM_SKKT , write = set_ElementPAS_NUMPPP_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPAS_NUMPPP_REM_SKKT(void)=0;
   virtual void set_ElementPAS_NUMPPP_REM_SKKT(TFIBWideStringField * ElementPAS_NUMPPP_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPAS_DOR_REM_SKKT = {read = get_ElementPAS_DOR_REM_SKKT , write = set_ElementPAS_DOR_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPAS_DOR_REM_SKKT(void)=0;
   virtual void set_ElementPAS_DOR_REM_SKKT(TFIBWideStringField * ElementPAS_DOR_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPAS_PRIM_REM_SKKT = {read = get_ElementPAS_PRIM_REM_SKKT , write = set_ElementPAS_PRIM_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPAS_PRIM_REM_SKKT(void)=0;
   virtual void set_ElementPAS_PRIM_REM_SKKT(TFIBWideStringField * ElementPAS_PRIM_REM_SKKT)=0;

   __property TFIBLargeIntField * ElementIDGRP_REM_SKKT = {read = get_ElementIDGRP_REM_SKKT , write = set_ElementIDGRP_REM_SKKT};
   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SKKT(void)=0;
   virtual void set_ElementIDGRP_REM_SKKT(TFIBLargeIntField * ElementIDGRP_REM_SKKT)=0;

   __property TFIBWideStringField * ElementPRIM_REM_SKKT = {read = get_ElementPRIM_REM_SKKT , write = set_ElementPRIM_REM_SKKT};
   virtual TFIBWideStringField * get_ElementPRIM_REM_SKKT(void)=0;
   virtual void set_ElementPRIM_REM_SKKT(TFIBWideStringField * ElementPRIM_REM_SKKT)=0;

   __property TFIBWideStringField * ElementNAME_REM_SMODEL = {read = get_ElementNAME_REM_SMODEL , write = set_ElementNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL(void)=0;
   virtual void set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementOWNER_NAME = {read = get_ElementOWNER_NAME , write = set_ElementOWNER_NAME};
   virtual TFIBWideStringField * get_ElementOWNER_NAME(void)=0;
   virtual void set_ElementOWNER_NAME(TFIBWideStringField * ElementOWNER_NAME)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property bool flChangeData = {read = get_flChangeData , write = set_flChangeData};
   virtual bool get_flChangeData(void)=0;
   virtual void set_flChangeData(bool flChangeData)=0;

   virtual void OpenTable(__int64 id_grp, bool all)=0;
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void ChancheGrp(__int64 new_id_grp)=0;
   virtual __int64 FindPoName(UnicodeString name)=0;
   virtual __int64 GetIdGrpElementa(__int64 id_element)=0;
   virtual void AddNewRecordDv(void)=0;
};
#define IID_IREM_DMSprKKT __uuidof(IREM_DMSprKKT)
#endif
