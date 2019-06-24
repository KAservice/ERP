#ifndef UIREM_DMSprHardwareH
#define UIREM_DMSprHardwareH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprHardware)) IREM_DMSprHardware : public IMainInterface
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

   __property TFIBLargeIntField * TableID_REM_SHARDWARE = {read = get_TableID_REM_SHARDWARE , write = set_TableID_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_TableID_REM_SHARDWARE(void)=0;
   virtual void set_TableID_REM_SHARDWARE(TFIBLargeIntField * TableID_REM_SHARDWARE)=0;

   __property TFIBWideStringField * TableNAME_REM_SHARDWARE = {read = get_TableNAME_REM_SHARDWARE , write = set_TableNAME_REM_SHARDWARE};
   virtual TFIBWideStringField * get_TableNAME_REM_SHARDWARE(void)=0;
   virtual void set_TableNAME_REM_SHARDWARE(TFIBWideStringField * TableNAME_REM_SHARDWARE)=0;

   __property TFIBWideStringField * TableSERNUM_REM_SHARDWARE = {read = get_TableSERNUM_REM_SHARDWARE , write = set_TableSERNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_TableSERNUM_REM_SHARDWARE(void)=0;
   virtual void set_TableSERNUM_REM_SHARDWARE(TFIBWideStringField * TableSERNUM_REM_SHARDWARE)=0;

   __property TFIBIntegerField * TableCODE_REM_SHARDWARE = {read = get_TableCODE_REM_SHARDWARE , write = set_TableCODE_REM_SHARDWARE};
   virtual TFIBIntegerField * get_TableCODE_REM_SHARDWARE(void)=0;
   virtual void set_TableCODE_REM_SHARDWARE(TFIBIntegerField * TableCODE_REM_SHARDWARE)=0;

   __property TFIBIntegerField * TableSROKWARRANTY_REM_SHARDWARE = {read = get_TableSROKWARRANTY_REM_SHARDWARE , write = set_TableSROKWARRANTY_REM_SHARDWARE};
   virtual TFIBIntegerField * get_TableSROKWARRANTY_REM_SHARDWARE(void)=0;
   virtual void set_TableSROKWARRANTY_REM_SHARDWARE(TFIBIntegerField * TableSROKWARRANTY_REM_SHARDWARE)=0;

   __property TFIBWideStringField * TableSERNUM2_REM_SHARDWARE = {read = get_TableSERNUM2_REM_SHARDWARE , write = set_TableSERNUM2_REM_SHARDWARE};
   virtual TFIBWideStringField * get_TableSERNUM2_REM_SHARDWARE(void)=0;
   virtual void set_TableSERNUM2_REM_SHARDWARE(TFIBWideStringField * TableSERNUM2_REM_SHARDWARE)=0;

   __property TFIBWideStringField * TableSERNUM_STR_REM_SHARDWARE = {read = get_TableSERNUM_STR_REM_SHARDWARE , write = set_TableSERNUM_STR_REM_SHARDWARE};
   virtual TFIBWideStringField * get_TableSERNUM_STR_REM_SHARDWARE(void)=0;
   virtual void set_TableSERNUM_STR_REM_SHARDWARE(TFIBWideStringField * TableSERNUM_STR_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * TableFL_NECOND_REM_SHARDWARE = {read = get_TableFL_NECOND_REM_SHARDWARE , write = set_TableFL_NECOND_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_TableFL_NECOND_REM_SHARDWARE(void)=0;
   virtual void set_TableFL_NECOND_REM_SHARDWARE(TFIBSmallIntField * TableFL_NECOND_REM_SHARDWARE)=0;

   __property TFIBBCDField * TablePRICE_REM_SHARDWARE = {read = get_TablePRICE_REM_SHARDWARE , write = set_TablePRICE_REM_SHARDWARE};
   virtual TFIBBCDField * get_TablePRICE_REM_SHARDWARE(void)=0;
   virtual void set_TablePRICE_REM_SHARDWARE(TFIBBCDField * TablePRICE_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * TableFL_FICT_REMONT_REM_SHARDWARE = {read = get_TableFL_FICT_REMONT_REM_SHARDWARE , write = set_TableFL_FICT_REMONT_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_TableFL_FICT_REMONT_REM_SHARDWARE(void)=0;
   virtual void set_TableFL_FICT_REMONT_REM_SHARDWARE(TFIBSmallIntField * TableFL_FICT_REMONT_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * TableFL_REMONT_REM_SHARDWARE = {read = get_TableFL_REMONT_REM_SHARDWARE , write = set_TableFL_REMONT_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_TableFL_REMONT_REM_SHARDWARE(void)=0;
   virtual void set_TableFL_REMONT_REM_SHARDWARE(TFIBSmallIntField * TableFL_REMONT_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * TableFL_ACT_REM_SHARDWARE = {read = get_TableFL_ACT_REM_SHARDWARE , write = set_TableFL_ACT_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_TableFL_ACT_REM_SHARDWARE(void)=0;
   virtual void set_TableFL_ACT_REM_SHARDWARE(TFIBSmallIntField * TableFL_ACT_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementID_REM_SHARDWARE = {read = get_ElementID_REM_SHARDWARE , write = set_ElementID_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementID_REM_SHARDWARE(void)=0;
   virtual void set_ElementID_REM_SHARDWARE(TFIBLargeIntField * ElementID_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SHARDWARE = {read = get_ElementIDBASE_REM_SHARDWARE , write = set_ElementIDBASE_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SHARDWARE(void)=0;
   virtual void set_ElementIDBASE_REM_SHARDWARE(TFIBLargeIntField * ElementIDBASE_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementNAME_REM_SHARDWARE = {read = get_ElementNAME_REM_SHARDWARE , write = set_ElementNAME_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementNAME_REM_SHARDWARE(void)=0;
   virtual void set_ElementNAME_REM_SHARDWARE(TFIBWideStringField * ElementNAME_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementIDGRP_REM_SHARDWARE = {read = get_ElementIDGRP_REM_SHARDWARE , write = set_ElementIDGRP_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SHARDWARE(void)=0;
   virtual void set_ElementIDGRP_REM_SHARDWARE(TFIBLargeIntField * ElementIDGRP_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementIDMODEL_REM_SHARDWARE = {read = get_ElementIDMODEL_REM_SHARDWARE , write = set_ElementIDMODEL_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SHARDWARE(void)=0;
   virtual void set_ElementIDMODEL_REM_SHARDWARE(TFIBLargeIntField * ElementIDMODEL_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementIDPOST_REM_SHARDWARE = {read = get_ElementIDPOST_REM_SHARDWARE , write = set_ElementIDPOST_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementIDPOST_REM_SHARDWARE(void)=0;
   virtual void set_ElementIDPOST_REM_SHARDWARE(TFIBLargeIntField * ElementIDPOST_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * ElementTYPESYSPOST_REM_SHARDWARE = {read = get_ElementTYPESYSPOST_REM_SHARDWARE , write = set_ElementTYPESYSPOST_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_ElementTYPESYSPOST_REM_SHARDWARE(void)=0;
   virtual void set_ElementTYPESYSPOST_REM_SHARDWARE(TFIBSmallIntField * ElementTYPESYSPOST_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementIDDOCPOST_REM_SHARDWARE = {read = get_ElementIDDOCPOST_REM_SHARDWARE , write = set_ElementIDDOCPOST_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementIDDOCPOST_REM_SHARDWARE(void)=0;
   virtual void set_ElementIDDOCPOST_REM_SHARDWARE(TFIBLargeIntField * ElementIDDOCPOST_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementSERNUM_REM_SHARDWARE = {read = get_ElementSERNUM_REM_SHARDWARE , write = set_ElementSERNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementSERNUM_REM_SHARDWARE(void)=0;
   virtual void set_ElementSERNUM_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM_REM_SHARDWARE)=0;

   __property TFIBDateField * ElementWARRANTY_REM_SHARDWARE = {read = get_ElementWARRANTY_REM_SHARDWARE , write = set_ElementWARRANTY_REM_SHARDWARE};
   virtual TFIBDateField * get_ElementWARRANTY_REM_SHARDWARE(void)=0;
   virtual void set_ElementWARRANTY_REM_SHARDWARE(TFIBDateField * ElementWARRANTY_REM_SHARDWARE)=0;

   __property TFIBDateField * ElementSALE_REM_SHARDWARE = {read = get_ElementSALE_REM_SHARDWARE , write = set_ElementSALE_REM_SHARDWARE};
   virtual TFIBDateField * get_ElementSALE_REM_SHARDWARE(void)=0;
   virtual void set_ElementSALE_REM_SHARDWARE(TFIBDateField * ElementSALE_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementIDVLAD_REM_SHARDWARE = {read = get_ElementIDVLAD_REM_SHARDWARE , write = set_ElementIDVLAD_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementIDVLAD_REM_SHARDWARE(void)=0;
   virtual void set_ElementIDVLAD_REM_SHARDWARE(TFIBLargeIntField * ElementIDVLAD_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementNAMEVLAD_REM_SHARDWARE = {read = get_ElementNAMEVLAD_REM_SHARDWARE , write = set_ElementNAMEVLAD_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementNAMEVLAD_REM_SHARDWARE(void)=0;
   virtual void set_ElementNAMEVLAD_REM_SHARDWARE(TFIBWideStringField * ElementNAMEVLAD_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * ElementTYPESYSSALE_REM_SHARDWARE = {read = get_ElementTYPESYSSALE_REM_SHARDWARE , write = set_ElementTYPESYSSALE_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_ElementTYPESYSSALE_REM_SHARDWARE(void)=0;
   virtual void set_ElementTYPESYSSALE_REM_SHARDWARE(TFIBSmallIntField * ElementTYPESYSSALE_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementIDDOCSALE_REM_SHARDWARE = {read = get_ElementIDDOCSALE_REM_SHARDWARE , write = set_ElementIDDOCSALE_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementIDDOCSALE_REM_SHARDWARE(void)=0;
   virtual void set_ElementIDDOCSALE_REM_SHARDWARE(TFIBLargeIntField * ElementIDDOCSALE_REM_SHARDWARE)=0;

   __property TFIBIntegerField * ElementCODE_REM_SHARDWARE = {read = get_ElementCODE_REM_SHARDWARE , write = set_ElementCODE_REM_SHARDWARE};
   virtual TFIBIntegerField * get_ElementCODE_REM_SHARDWARE(void)=0;
   virtual void set_ElementCODE_REM_SHARDWARE(TFIBIntegerField * ElementCODE_REM_SHARDWARE)=0;

   __property TFIBIntegerField * ElementSROKWARRANTY_REM_SHARDWARE = {read = get_ElementSROKWARRANTY_REM_SHARDWARE , write = set_ElementSROKWARRANTY_REM_SHARDWARE};
   virtual TFIBIntegerField * get_ElementSROKWARRANTY_REM_SHARDWARE(void)=0;
   virtual void set_ElementSROKWARRANTY_REM_SHARDWARE(TFIBIntegerField * ElementSROKWARRANTY_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementIDDOCREM_SALE_REM_SHARDWARE = {read = get_ElementIDDOCREM_SALE_REM_SHARDWARE , write = set_ElementIDDOCREM_SALE_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementIDDOCREM_SALE_REM_SHARDWARE(void)=0;
   virtual void set_ElementIDDOCREM_SALE_REM_SHARDWARE(TFIBLargeIntField * ElementIDDOCREM_SALE_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementSERNUM2_REM_SHARDWARE = {read = get_ElementSERNUM2_REM_SHARDWARE , write = set_ElementSERNUM2_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementSERNUM2_REM_SHARDWARE(void)=0;
   virtual void set_ElementSERNUM2_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM2_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementSERNUM_STR_REM_SHARDWARE = {read = get_ElementSERNUM_STR_REM_SHARDWARE , write = set_ElementSERNUM_STR_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementSERNUM_STR_REM_SHARDWARE(void)=0;
   virtual void set_ElementSERNUM_STR_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM_STR_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * ElementFL_NECOND_REM_SHARDWARE = {read = get_ElementFL_NECOND_REM_SHARDWARE , write = set_ElementFL_NECOND_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_ElementFL_NECOND_REM_SHARDWARE(void)=0;
   virtual void set_ElementFL_NECOND_REM_SHARDWARE(TFIBSmallIntField * ElementFL_NECOND_REM_SHARDWARE)=0;

   __property TFIBBCDField * ElementPRICE_REM_SHARDWARE = {read = get_ElementPRICE_REM_SHARDWARE , write = set_ElementPRICE_REM_SHARDWARE};
   virtual TFIBBCDField * get_ElementPRICE_REM_SHARDWARE(void)=0;
   virtual void set_ElementPRICE_REM_SHARDWARE(TFIBBCDField * ElementPRICE_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementPRICHINA_REM_SHARDWARE = {read = get_ElementPRICHINA_REM_SHARDWARE , write = set_ElementPRICHINA_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementPRICHINA_REM_SHARDWARE(void)=0;
   virtual void set_ElementPRICHINA_REM_SHARDWARE(TFIBWideStringField * ElementPRICHINA_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementPRIM_REM_SHARDWARE = {read = get_ElementPRIM_REM_SHARDWARE , write = set_ElementPRIM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementPRIM_REM_SHARDWARE(void)=0;
   virtual void set_ElementPRIM_REM_SHARDWARE(TFIBWideStringField * ElementPRIM_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * ElementFL_FICT_REMONT_REM_SHARDWARE = {read = get_ElementFL_FICT_REMONT_REM_SHARDWARE , write = set_ElementFL_FICT_REMONT_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_ElementFL_FICT_REMONT_REM_SHARDWARE(void)=0;
   virtual void set_ElementFL_FICT_REMONT_REM_SHARDWARE(TFIBSmallIntField * ElementFL_FICT_REMONT_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * ElementFL_REMONT_REM_SHARDWARE = {read = get_ElementFL_REMONT_REM_SHARDWARE , write = set_ElementFL_REMONT_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_ElementFL_REMONT_REM_SHARDWARE(void)=0;
   virtual void set_ElementFL_REMONT_REM_SHARDWARE(TFIBSmallIntField * ElementFL_REMONT_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementIDPRODUCER_REM_SHARDWARE = {read = get_ElementIDPRODUCER_REM_SHARDWARE , write = set_ElementIDPRODUCER_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementIDPRODUCER_REM_SHARDWARE(void)=0;
   virtual void set_ElementIDPRODUCER_REM_SHARDWARE(TFIBLargeIntField * ElementIDPRODUCER_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementIDBRAND_REM_SHARDWARE = {read = get_ElementIDBRAND_REM_SHARDWARE , write = set_ElementIDBRAND_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementIDBRAND_REM_SHARDWARE(void)=0;
   virtual void set_ElementIDBRAND_REM_SHARDWARE(TFIBLargeIntField * ElementIDBRAND_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementIDZ_REM_SHARDWARE = {read = get_ElementIDZ_REM_SHARDWARE , write = set_ElementIDZ_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementIDZ_REM_SHARDWARE(void)=0;
   virtual void set_ElementIDZ_REM_SHARDWARE(TFIBLargeIntField * ElementIDZ_REM_SHARDWARE)=0;

   __property TFIBIntegerField * ElementTYPE_ELEMENTA_REM_SHARDWARE = {read = get_ElementTYPE_ELEMENTA_REM_SHARDWARE , write = set_ElementTYPE_ELEMENTA_REM_SHARDWARE};
   virtual TFIBIntegerField * get_ElementTYPE_ELEMENTA_REM_SHARDWARE(void)=0;
   virtual void set_ElementTYPE_ELEMENTA_REM_SHARDWARE(TFIBIntegerField * ElementTYPE_ELEMENTA_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * ElementFL_ACT_REM_SHARDWARE = {read = get_ElementFL_ACT_REM_SHARDWARE , write = set_ElementFL_ACT_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_ElementFL_ACT_REM_SHARDWARE(void)=0;
   virtual void set_ElementFL_ACT_REM_SHARDWARE(TFIBSmallIntField * ElementFL_ACT_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * ElementFL_UTILIZ_REM_SHARDWARE = {read = get_ElementFL_UTILIZ_REM_SHARDWARE , write = set_ElementFL_UTILIZ_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_ElementFL_UTILIZ_REM_SHARDWARE(void)=0;
   virtual void set_ElementFL_UTILIZ_REM_SHARDWARE(TFIBSmallIntField * ElementFL_UTILIZ_REM_SHARDWARE)=0;

   __property TFIBDateTimeField * ElementPOS_POST_REM_SHARDWARE = {read = get_ElementPOS_POST_REM_SHARDWARE , write = set_ElementPOS_POST_REM_SHARDWARE};
   virtual TFIBDateTimeField * get_ElementPOS_POST_REM_SHARDWARE(void)=0;
   virtual void set_ElementPOS_POST_REM_SHARDWARE(TFIBDateTimeField * ElementPOS_POST_REM_SHARDWARE)=0;

   __property TFIBDateTimeField * ElementPOS_UTILIZ_REM_SHARDWARE = {read = get_ElementPOS_UTILIZ_REM_SHARDWARE , write = set_ElementPOS_UTILIZ_REM_SHARDWARE};
   virtual TFIBDateTimeField * get_ElementPOS_UTILIZ_REM_SHARDWARE(void)=0;
   virtual void set_ElementPOS_UTILIZ_REM_SHARDWARE(TFIBDateTimeField * ElementPOS_UTILIZ_REM_SHARDWARE)=0;

   __property TFIBDateTimeField * ElementPOS_HRAN_DO_REM_SHARDWARE = {read = get_ElementPOS_HRAN_DO_REM_SHARDWARE , write = set_ElementPOS_HRAN_DO_REM_SHARDWARE};
   virtual TFIBDateTimeField * get_ElementPOS_HRAN_DO_REM_SHARDWARE(void)=0;
   virtual void set_ElementPOS_HRAN_DO_REM_SHARDWARE(TFIBDateTimeField * ElementPOS_HRAN_DO_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * ElementIDPRMODEL_REM_SHARDWARE = {read = get_ElementIDPRMODEL_REM_SHARDWARE , write = set_ElementIDPRMODEL_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_ElementIDPRMODEL_REM_SHARDWARE(void)=0;
   virtual void set_ElementIDPRMODEL_REM_SHARDWARE(TFIBLargeIntField * ElementIDPRMODEL_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementNAME_REM_SMODEL = {read = get_ElementNAME_REM_SMODEL , write = set_ElementNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL(void)=0;
   virtual void set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementSUPPLIER_NAME = {read = get_ElementSUPPLIER_NAME , write = set_ElementSUPPLIER_NAME};
   virtual TFIBWideStringField * get_ElementSUPPLIER_NAME(void)=0;
   virtual void set_ElementSUPPLIER_NAME(TFIBWideStringField * ElementSUPPLIER_NAME)=0;

   __property TFIBWideStringField * ElementOWNER_NAME = {read = get_ElementOWNER_NAME , write = set_ElementOWNER_NAME};
   virtual TFIBWideStringField * get_ElementOWNER_NAME(void)=0;
   virtual void set_ElementOWNER_NAME(TFIBWideStringField * ElementOWNER_NAME)=0;

   __property TFIBWideStringField * ElementTDOC_DOCPOST = {read = get_ElementTDOC_DOCPOST , write = set_ElementTDOC_DOCPOST};
   virtual TFIBWideStringField * get_ElementTDOC_DOCPOST(void)=0;
   virtual void set_ElementTDOC_DOCPOST(TFIBWideStringField * ElementTDOC_DOCPOST)=0;

   __property TFIBDateTimeField * ElementPOSDOC_DOCPOST = {read = get_ElementPOSDOC_DOCPOST , write = set_ElementPOSDOC_DOCPOST};
   virtual TFIBDateTimeField * get_ElementPOSDOC_DOCPOST(void)=0;
   virtual void set_ElementPOSDOC_DOCPOST(TFIBDateTimeField * ElementPOSDOC_DOCPOST)=0;

   __property TFIBIntegerField * ElementNUMDOC_DOCPOST = {read = get_ElementNUMDOC_DOCPOST , write = set_ElementNUMDOC_DOCPOST};
   virtual TFIBIntegerField * get_ElementNUMDOC_DOCPOST(void)=0;
   virtual void set_ElementNUMDOC_DOCPOST(TFIBIntegerField * ElementNUMDOC_DOCPOST)=0;

   __property TFIBWideStringField * ElementTDOC_DOCSALE = {read = get_ElementTDOC_DOCSALE , write = set_ElementTDOC_DOCSALE};
   virtual TFIBWideStringField * get_ElementTDOC_DOCSALE(void)=0;
   virtual void set_ElementTDOC_DOCSALE(TFIBWideStringField * ElementTDOC_DOCSALE)=0;

   __property TFIBDateTimeField * ElementPOSDOC_DOCSALE = {read = get_ElementPOSDOC_DOCSALE , write = set_ElementPOSDOC_DOCSALE};
   virtual TFIBDateTimeField * get_ElementPOSDOC_DOCSALE(void)=0;
   virtual void set_ElementPOSDOC_DOCSALE(TFIBDateTimeField * ElementPOSDOC_DOCSALE)=0;

   __property TFIBIntegerField * ElementNUMDOC_DOCSALE = {read = get_ElementNUMDOC_DOCSALE , write = set_ElementNUMDOC_DOCSALE};
   virtual TFIBIntegerField * get_ElementNUMDOC_DOCSALE(void)=0;
   virtual void set_ElementNUMDOC_DOCSALE(TFIBIntegerField * ElementNUMDOC_DOCSALE)=0;

   __property TFIBWideStringField * ElementNAME_SBRAND = {read = get_ElementNAME_SBRAND , write = set_ElementNAME_SBRAND};
   virtual TFIBWideStringField * get_ElementNAME_SBRAND(void)=0;
   virtual void set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND)=0;

   __property TFIBWideStringField * ElementNAME_SPRODUCER = {read = get_ElementNAME_SPRODUCER , write = set_ElementNAME_SPRODUCER};
   virtual TFIBWideStringField * get_ElementNAME_SPRODUCER(void)=0;
   virtual void set_ElementNAME_SPRODUCER(TFIBWideStringField * ElementNAME_SPRODUCER)=0;

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

   __property TFIBWideStringField * ElementNAME_REM_SPRMODEL = {read = get_ElementNAME_REM_SPRMODEL , write = set_ElementNAME_REM_SPRMODEL};
   virtual TFIBWideStringField * get_ElementNAME_REM_SPRMODEL(void)=0;
   virtual void set_ElementNAME_REM_SPRMODEL(TFIBWideStringField * ElementNAME_REM_SPRMODEL)=0;

   __property TFIBWideStringField * TableNAME_ENG_REM_SHARDWARE = {read = get_TableNAME_ENG_REM_SHARDWARE , write = set_TableNAME_ENG_REM_SHARDWARE};
   virtual TFIBWideStringField * get_TableNAME_ENG_REM_SHARDWARE(void)=0;
   virtual void set_TableNAME_ENG_REM_SHARDWARE(TFIBWideStringField * TableNAME_ENG_REM_SHARDWARE)=0;

   __property TFIBWideStringField * TableARTIKUL_REM_SHARDWARE = {read = get_TableARTIKUL_REM_SHARDWARE , write = set_TableARTIKUL_REM_SHARDWARE};
   virtual TFIBWideStringField * get_TableARTIKUL_REM_SHARDWARE(void)=0;
   virtual void set_TableARTIKUL_REM_SHARDWARE(TFIBWideStringField * TableARTIKUL_REM_SHARDWARE)=0;

   __property TFIBWideStringField * TablePARTNUM_REM_SHARDWARE = {read = get_TablePARTNUM_REM_SHARDWARE , write = set_TablePARTNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_TablePARTNUM_REM_SHARDWARE(void)=0;
   virtual void set_TablePARTNUM_REM_SHARDWARE(TFIBWideStringField * TablePARTNUM_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementSERNUM3_REM_SHARDWARE = {read = get_ElementSERNUM3_REM_SHARDWARE , write = set_ElementSERNUM3_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementSERNUM3_REM_SHARDWARE(void)=0;
   virtual void set_ElementSERNUM3_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM3_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementSERNUM4_REM_SHARDWARE = {read = get_ElementSERNUM4_REM_SHARDWARE , write = set_ElementSERNUM4_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementSERNUM4_REM_SHARDWARE(void)=0;
   virtual void set_ElementSERNUM4_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM4_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementNUMBAT_REM_SHARDWARE = {read = get_ElementNUMBAT_REM_SHARDWARE , write = set_ElementNUMBAT_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementNUMBAT_REM_SHARDWARE(void)=0;
   virtual void set_ElementNUMBAT_REM_SHARDWARE(TFIBWideStringField * ElementNUMBAT_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementNUMGARTALON_REM_SHARDWARE = {read = get_ElementNUMGARTALON_REM_SHARDWARE , write = set_ElementNUMGARTALON_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementNUMGARTALON_REM_SHARDWARE(void)=0;
   virtual void set_ElementNUMGARTALON_REM_SHARDWARE(TFIBWideStringField * ElementNUMGARTALON_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementSWCODE_REM_SHARDWARE = {read = get_ElementSWCODE_REM_SHARDWARE , write = set_ElementSWCODE_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementSWCODE_REM_SHARDWARE(void)=0;
   virtual void set_ElementSWCODE_REM_SHARDWARE(TFIBWideStringField * ElementSWCODE_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementHWCODE_REM_SHARDWARE = {read = get_ElementHWCODE_REM_SHARDWARE , write = set_ElementHWCODE_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementHWCODE_REM_SHARDWARE(void)=0;
   virtual void set_ElementHWCODE_REM_SHARDWARE(TFIBWideStringField * ElementHWCODE_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementVERPO_REM_SHARDWARE = {read = get_ElementVERPO_REM_SHARDWARE , write = set_ElementVERPO_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementVERPO_REM_SHARDWARE(void)=0;
   virtual void set_ElementVERPO_REM_SHARDWARE(TFIBWideStringField * ElementVERPO_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementPARTNUM_REM_SHARDWARE = {read = get_ElementPARTNUM_REM_SHARDWARE , write = set_ElementPARTNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementPARTNUM_REM_SHARDWARE(void)=0;
   virtual void set_ElementPARTNUM_REM_SHARDWARE(TFIBWideStringField * ElementPARTNUM_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementMTM_REM_SHARDWARE = {read = get_ElementMTM_REM_SHARDWARE , write = set_ElementMTM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementMTM_REM_SHARDWARE(void)=0;
   virtual void set_ElementMTM_REM_SHARDWARE(TFIBWideStringField * ElementMTM_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementFRU_REM_SHARDWARE = {read = get_ElementFRU_REM_SHARDWARE , write = set_ElementFRU_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementFRU_REM_SHARDWARE(void)=0;
   virtual void set_ElementFRU_REM_SHARDWARE(TFIBWideStringField * ElementFRU_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementNAME_ENG_REM_SHARDWARE = {read = get_ElementNAME_ENG_REM_SHARDWARE , write = set_ElementNAME_ENG_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementNAME_ENG_REM_SHARDWARE(void)=0;
   virtual void set_ElementNAME_ENG_REM_SHARDWARE(TFIBWideStringField * ElementNAME_ENG_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementCRU_REM_SHARDWARE = {read = get_ElementCRU_REM_SHARDWARE , write = set_ElementCRU_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementCRU_REM_SHARDWARE(void)=0;
   virtual void set_ElementCRU_REM_SHARDWARE(TFIBWideStringField * ElementCRU_REM_SHARDWARE)=0;

   __property TFIBWideStringField * ElementARTIKUL_REM_SHARDWARE = {read = get_ElementARTIKUL_REM_SHARDWARE , write = set_ElementARTIKUL_REM_SHARDWARE};
   virtual TFIBWideStringField * get_ElementARTIKUL_REM_SHARDWARE(void)=0;
   virtual void set_ElementARTIKUL_REM_SHARDWARE(TFIBWideStringField * ElementARTIKUL_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * TableOUT_IDFIRM = {read = get_TableOUT_IDFIRM , write = set_TableOUT_IDFIRM};
   virtual TFIBLargeIntField * get_TableOUT_IDFIRM(void)=0;
   virtual void set_TableOUT_IDFIRM(TFIBLargeIntField * TableOUT_IDFIRM)=0;

   __property TFIBWideStringField * TableOUT_NAME_FIRM = {read = get_TableOUT_NAME_FIRM , write = set_TableOUT_NAME_FIRM};
   virtual TFIBWideStringField * get_TableOUT_NAME_FIRM(void)=0;
   virtual void set_TableOUT_NAME_FIRM(TFIBWideStringField * TableOUT_NAME_FIRM)=0;

   __property TFIBLargeIntField * TableOUT_IDSKLAD = {read = get_TableOUT_IDSKLAD , write = set_TableOUT_IDSKLAD};
   virtual TFIBLargeIntField * get_TableOUT_IDSKLAD(void)=0;
   virtual void set_TableOUT_IDSKLAD(TFIBLargeIntField * TableOUT_IDSKLAD)=0;

   __property TFIBWideStringField * TableOUT_NAME_SKLAD = {read = get_TableOUT_NAME_SKLAD , write = set_TableOUT_NAME_SKLAD};
   virtual TFIBWideStringField * get_TableOUT_NAME_SKLAD(void)=0;
   virtual void set_TableOUT_NAME_SKLAD(TFIBWideStringField * TableOUT_NAME_SKLAD)=0;

   __property TFIBLargeIntField * TableOUT_IDTNOM = {read = get_TableOUT_IDTNOM , write = set_TableOUT_IDTNOM};
   virtual TFIBLargeIntField * get_TableOUT_IDTNOM(void)=0;
   virtual void set_TableOUT_IDTNOM(TFIBLargeIntField * TableOUT_IDTNOM)=0;

   __property TFIBWideStringField * TableOUT_NAME_TYPE_NOM = {read = get_TableOUT_NAME_TYPE_NOM , write = set_TableOUT_NAME_TYPE_NOM};
   virtual TFIBWideStringField * get_TableOUT_NAME_TYPE_NOM(void)=0;
   virtual void set_TableOUT_NAME_TYPE_NOM(TFIBWideStringField * TableOUT_NAME_TYPE_NOM)=0;

   __property TFIBBCDField * TableOUT_OST = {read = get_TableOUT_OST , write = set_TableOUT_OST};
   virtual TFIBBCDField * get_TableOUT_OST(void)=0;
   virtual void set_TableOUT_OST(TFIBBCDField * TableOUT_OST)=0;

   __property TFIBLargeIntField * TableIDGRP_REM_SHARDWARE = {read = get_TableIDGRP_REM_SHARDWARE , write = set_TableIDGRP_REM_SHARDWARE};
   virtual TFIBLargeIntField * get_TableIDGRP_REM_SHARDWARE(void)=0;
   virtual void set_TableIDGRP_REM_SHARDWARE(TFIBLargeIntField * TableIDGRP_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * TableOUT_IDMHRAN = {read = get_TableOUT_IDMHRAN , write = set_TableOUT_IDMHRAN};
   virtual TFIBLargeIntField * get_TableOUT_IDMHRAN(void)=0;
   virtual void set_TableOUT_IDMHRAN(TFIBLargeIntField * TableOUT_IDMHRAN)=0;

   __property TFIBWideStringField * TableOUT_NAME_MHRAN = {read = get_TableOUT_NAME_MHRAN , write = set_TableOUT_NAME_MHRAN};
   virtual TFIBWideStringField * get_TableOUT_NAME_MHRAN(void)=0;
   virtual void set_TableOUT_NAME_MHRAN(TFIBWideStringField * TableOUT_NAME_MHRAN)=0;

   __property TFIBSmallIntField * TableOUT_FL_OTCH_PROIZV = {read = get_TableOUT_FL_OTCH_PROIZV , write = set_TableOUT_FL_OTCH_PROIZV};
   virtual TFIBSmallIntField * get_TableOUT_FL_OTCH_PROIZV(void)=0;
   virtual void set_TableOUT_FL_OTCH_PROIZV(TFIBSmallIntField * TableOUT_FL_OTCH_PROIZV)=0;

   __property TFIBSmallIntField * TableOUT_FL_NO_RAZBOR = {read = get_TableOUT_FL_NO_RAZBOR , write = set_TableOUT_FL_NO_RAZBOR};
   virtual TFIBSmallIntField * get_TableOUT_FL_NO_RAZBOR(void)=0;
   virtual void set_TableOUT_FL_NO_RAZBOR(TFIBSmallIntField * TableOUT_FL_NO_RAZBOR)=0;

   __property TFIBSmallIntField * ElementFL_OTCH_PROIZV_REM_SHARDWARE = {read = get_ElementFL_OTCH_PROIZV_REM_SHARDWARE , write = set_ElementFL_OTCH_PROIZV_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_ElementFL_OTCH_PROIZV_REM_SHARDWARE(void)=0;
   virtual void set_ElementFL_OTCH_PROIZV_REM_SHARDWARE(TFIBSmallIntField * ElementFL_OTCH_PROIZV_REM_SHARDWARE)=0;

   __property TFIBSmallIntField * ElementFL_NO_RAZBOR_REM_SHARDWARE = {read = get_ElementFL_NO_RAZBOR_REM_SHARDWARE , write = set_ElementFL_NO_RAZBOR_REM_SHARDWARE};
   virtual TFIBSmallIntField * get_ElementFL_NO_RAZBOR_REM_SHARDWARE(void)=0;
   virtual void set_ElementFL_NO_RAZBOR_REM_SHARDWARE(TFIBSmallIntField * ElementFL_NO_RAZBOR_REM_SHARDWARE)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_grp, bool all)=0;
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void ChancheGrp(__int64 new_id_grp, __int64 id_el)=0;
   virtual __int64 FindPoName(UnicodeString name)=0;
   virtual __int64 GetIdGrpElementa(__int64 id_element)=0;
   virtual __int64 GetIdPoCodu(int code)=0;
   virtual bool Table_FindPoSerNum1Like(__int64 id_grp, bool all, UnicodeString ser_num)=0;
   virtual bool Table_FindPoSerNum2Like(__int64 id_grp, bool all, UnicodeString ser_num)=0;
   virtual bool Table_FindPoSerNumStrLike(__int64 id_grp, bool all, UnicodeString ser_num)=0;
};
#define IID_IREM_DMSprHardware __uuidof(IREM_DMSprHardware)
#endif
