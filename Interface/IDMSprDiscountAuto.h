#ifndef UIDMSprDiscountAutoH
#define UIDMSprDiscountAutoH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprDiscountAuto)) IDMSprDiscountAuto : public IMainInterface
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

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBDataSet * TableDiscountAuto = {read = get_TableDiscountAuto , write = set_TableDiscountAuto};
   virtual TpFIBDataSet * get_TableDiscountAuto(void)=0;
   virtual void set_TableDiscountAuto(TpFIBDataSet * TableDiscountAuto)=0;

   __property TFIBLargeIntField * TableID_SDISCOUNT_AUTO = {read = get_TableID_SDISCOUNT_AUTO , write = set_TableID_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_TableID_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableID_SDISCOUNT_AUTO(TFIBLargeIntField * TableID_SDISCOUNT_AUTO)=0;

   __property TFIBWideStringField * TableGID_SDISCOUNT_AUTO = {read = get_TableGID_SDISCOUNT_AUTO , write = set_TableGID_SDISCOUNT_AUTO};
   virtual TFIBWideStringField * get_TableGID_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableGID_SDISCOUNT_AUTO(TFIBWideStringField * TableGID_SDISCOUNT_AUTO)=0;

   __property TFIBWideStringField * TableNAME_SDISCOUNT_AUTO = {read = get_TableNAME_SDISCOUNT_AUTO , write = set_TableNAME_SDISCOUNT_AUTO};
   virtual TFIBWideStringField * get_TableNAME_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableNAME_SDISCOUNT_AUTO(TFIBWideStringField * TableNAME_SDISCOUNT_AUTO)=0;

   __property TFIBSmallIntField * TableACT_SDISCOUNT_AUTO = {read = get_TableACT_SDISCOUNT_AUTO , write = set_TableACT_SDISCOUNT_AUTO};
   virtual TFIBSmallIntField * get_TableACT_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableACT_SDISCOUNT_AUTO(TFIBSmallIntField * TableACT_SDISCOUNT_AUTO)=0;

   __property TFIBDateTimeField * TableNACH_SDISCOUNT_AUTO = {read = get_TableNACH_SDISCOUNT_AUTO , write = set_TableNACH_SDISCOUNT_AUTO};
   virtual TFIBDateTimeField * get_TableNACH_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableNACH_SDISCOUNT_AUTO(TFIBDateTimeField * TableNACH_SDISCOUNT_AUTO)=0;

   __property TFIBDateTimeField * TableCON_SDISCOUNT_AUTO = {read = get_TableCON_SDISCOUNT_AUTO , write = set_TableCON_SDISCOUNT_AUTO};
   virtual TFIBDateTimeField * get_TableCON_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableCON_SDISCOUNT_AUTO(TFIBDateTimeField * TableCON_SDISCOUNT_AUTO)=0;

   __property TFIBBCDField * TablePRSK_SDISCOUNT_AUTO = {read = get_TablePRSK_SDISCOUNT_AUTO , write = set_TablePRSK_SDISCOUNT_AUTO};
   virtual TFIBBCDField * get_TablePRSK_SDISCOUNT_AUTO(void)=0;
   virtual void set_TablePRSK_SDISCOUNT_AUTO(TFIBBCDField * TablePRSK_SDISCOUNT_AUTO)=0;

   __property TFIBBCDField * TableSUM_SDISCOUNT_AUTO = {read = get_TableSUM_SDISCOUNT_AUTO , write = set_TableSUM_SDISCOUNT_AUTO};
   virtual TFIBBCDField * get_TableSUM_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableSUM_SDISCOUNT_AUTO(TFIBBCDField * TableSUM_SDISCOUNT_AUTO)=0;

   __property TFIBTimeField * TableTIME_NACH_SDISCOUNT_AUTO = {read = get_TableTIME_NACH_SDISCOUNT_AUTO , write = set_TableTIME_NACH_SDISCOUNT_AUTO};
   virtual TFIBTimeField * get_TableTIME_NACH_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableTIME_NACH_SDISCOUNT_AUTO(TFIBTimeField * TableTIME_NACH_SDISCOUNT_AUTO)=0;

   __property TFIBTimeField * TableTIME_CON_SDISCOUNT_AUTO = {read = get_TableTIME_CON_SDISCOUNT_AUTO , write = set_TableTIME_CON_SDISCOUNT_AUTO};
   virtual TFIBTimeField * get_TableTIME_CON_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableTIME_CON_SDISCOUNT_AUTO(TFIBTimeField * TableTIME_CON_SDISCOUNT_AUTO)=0;

   __property TFIBSmallIntField * TableDAY_SDISCOUNT_AUTO = {read = get_TableDAY_SDISCOUNT_AUTO , write = set_TableDAY_SDISCOUNT_AUTO};
   virtual TFIBSmallIntField * get_TableDAY_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDAY_SDISCOUNT_AUTO(TFIBSmallIntField * TableDAY_SDISCOUNT_AUTO)=0;

   __property TFIBLargeIntField * TableIDVIDNOM_SDISCOUNT_AUTO = {read = get_TableIDVIDNOM_SDISCOUNT_AUTO , write = set_TableIDVIDNOM_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_TableIDVIDNOM_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableIDVIDNOM_SDISCOUNT_AUTO(TFIBLargeIntField * TableIDVIDNOM_SDISCOUNT_AUTO)=0;

   __property TFIBLargeIntField * TableIDSKLAD_SDISCOUNT_AUTO = {read = get_TableIDSKLAD_SDISCOUNT_AUTO , write = set_TableIDSKLAD_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_TableIDSKLAD_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableIDSKLAD_SDISCOUNT_AUTO(TFIBLargeIntField * TableIDSKLAD_SDISCOUNT_AUTO)=0;

   __property TFIBLargeIntField * TableIDBASE_SDISCOUNT_AUTO = {read = get_TableIDBASE_SDISCOUNT_AUTO , write = set_TableIDBASE_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_TableIDBASE_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableIDBASE_SDISCOUNT_AUTO(TFIBLargeIntField * TableIDBASE_SDISCOUNT_AUTO)=0;

   __property TFIBSmallIntField * TableNUM_SKIDKI_SDISCOUNT_AUTO = {read = get_TableNUM_SKIDKI_SDISCOUNT_AUTO , write = set_TableNUM_SKIDKI_SDISCOUNT_AUTO};
   virtual TFIBSmallIntField * get_TableNUM_SKIDKI_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableNUM_SKIDKI_SDISCOUNT_AUTO(TFIBSmallIntField * TableNUM_SKIDKI_SDISCOUNT_AUTO)=0;

   __property TFIBLargeIntField * TableIDGRPNOM_SDISCOUNT_AUTO = {read = get_TableIDGRPNOM_SDISCOUNT_AUTO , write = set_TableIDGRPNOM_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_TableIDGRPNOM_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableIDGRPNOM_SDISCOUNT_AUTO(TFIBLargeIntField * TableIDGRPNOM_SDISCOUNT_AUTO)=0;

   __property TFIBIntegerField * TableTYPE_ACTION_SDISCOUNT_AUTO = {read = get_TableTYPE_ACTION_SDISCOUNT_AUTO , write = set_TableTYPE_ACTION_SDISCOUNT_AUTO};
   virtual TFIBIntegerField * get_TableTYPE_ACTION_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableTYPE_ACTION_SDISCOUNT_AUTO(TFIBIntegerField * TableTYPE_ACTION_SDISCOUNT_AUTO)=0;

   __property TFIBWideStringField * TableMESSAGE_SDISCOUNT_AUTO = {read = get_TableMESSAGE_SDISCOUNT_AUTO , write = set_TableMESSAGE_SDISCOUNT_AUTO};
   virtual TFIBWideStringField * get_TableMESSAGE_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableMESSAGE_SDISCOUNT_AUTO(TFIBWideStringField * TableMESSAGE_SDISCOUNT_AUTO)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   __property TFIBWideStringField * TableNAMEGN = {read = get_TableNAMEGN , write = set_TableNAMEGN};
   virtual TFIBWideStringField * get_TableNAMEGN(void)=0;
   virtual void set_TableNAMEGN(TFIBWideStringField * TableNAMEGN)=0;

   __property TFIBWideStringField * TableNAME_SVIDNOM = {read = get_TableNAME_SVIDNOM , write = set_TableNAME_SVIDNOM};
   virtual TFIBWideStringField * get_TableNAME_SVIDNOM(void)=0;
   virtual void set_TableNAME_SVIDNOM(TFIBWideStringField * TableNAME_SVIDNOM)=0;

   __property TFIBLargeIntField * ElementID_SDISCOUNT_AUTO = {read = get_ElementID_SDISCOUNT_AUTO , write = set_ElementID_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_ElementID_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementID_SDISCOUNT_AUTO(TFIBLargeIntField * ElementID_SDISCOUNT_AUTO)=0;

   __property TFIBWideStringField * ElementGID_SDISCOUNT_AUTO = {read = get_ElementGID_SDISCOUNT_AUTO , write = set_ElementGID_SDISCOUNT_AUTO};
   virtual TFIBWideStringField * get_ElementGID_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementGID_SDISCOUNT_AUTO(TFIBWideStringField * ElementGID_SDISCOUNT_AUTO)=0;

   __property TFIBWideStringField * ElementNAME_SDISCOUNT_AUTO = {read = get_ElementNAME_SDISCOUNT_AUTO , write = set_ElementNAME_SDISCOUNT_AUTO};
   virtual TFIBWideStringField * get_ElementNAME_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementNAME_SDISCOUNT_AUTO(TFIBWideStringField * ElementNAME_SDISCOUNT_AUTO)=0;

   __property TFIBSmallIntField * ElementACT_SDISCOUNT_AUTO = {read = get_ElementACT_SDISCOUNT_AUTO , write = set_ElementACT_SDISCOUNT_AUTO};
   virtual TFIBSmallIntField * get_ElementACT_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementACT_SDISCOUNT_AUTO(TFIBSmallIntField * ElementACT_SDISCOUNT_AUTO)=0;

   __property TFIBDateTimeField * ElementNACH_SDISCOUNT_AUTO = {read = get_ElementNACH_SDISCOUNT_AUTO , write = set_ElementNACH_SDISCOUNT_AUTO};
   virtual TFIBDateTimeField * get_ElementNACH_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementNACH_SDISCOUNT_AUTO(TFIBDateTimeField * ElementNACH_SDISCOUNT_AUTO)=0;

   __property TFIBDateTimeField * ElementCON_SDISCOUNT_AUTO = {read = get_ElementCON_SDISCOUNT_AUTO , write = set_ElementCON_SDISCOUNT_AUTO};
   virtual TFIBDateTimeField * get_ElementCON_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementCON_SDISCOUNT_AUTO(TFIBDateTimeField * ElementCON_SDISCOUNT_AUTO)=0;

   __property TFIBBCDField * ElementPRSK_SDISCOUNT_AUTO = {read = get_ElementPRSK_SDISCOUNT_AUTO , write = set_ElementPRSK_SDISCOUNT_AUTO};
   virtual TFIBBCDField * get_ElementPRSK_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementPRSK_SDISCOUNT_AUTO(TFIBBCDField * ElementPRSK_SDISCOUNT_AUTO)=0;

   __property TFIBBCDField * ElementSUM_SDISCOUNT_AUTO = {read = get_ElementSUM_SDISCOUNT_AUTO , write = set_ElementSUM_SDISCOUNT_AUTO};
   virtual TFIBBCDField * get_ElementSUM_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementSUM_SDISCOUNT_AUTO(TFIBBCDField * ElementSUM_SDISCOUNT_AUTO)=0;

   __property TFIBTimeField * ElementTIME_NACH_SDISCOUNT_AUTO = {read = get_ElementTIME_NACH_SDISCOUNT_AUTO , write = set_ElementTIME_NACH_SDISCOUNT_AUTO};
   virtual TFIBTimeField * get_ElementTIME_NACH_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementTIME_NACH_SDISCOUNT_AUTO(TFIBTimeField * ElementTIME_NACH_SDISCOUNT_AUTO)=0;

   __property TFIBTimeField * ElementTIME_CON_SDISCOUNT_AUTO = {read = get_ElementTIME_CON_SDISCOUNT_AUTO , write = set_ElementTIME_CON_SDISCOUNT_AUTO};
   virtual TFIBTimeField * get_ElementTIME_CON_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementTIME_CON_SDISCOUNT_AUTO(TFIBTimeField * ElementTIME_CON_SDISCOUNT_AUTO)=0;

   __property TFIBSmallIntField * ElementDAY_SDISCOUNT_AUTO = {read = get_ElementDAY_SDISCOUNT_AUTO , write = set_ElementDAY_SDISCOUNT_AUTO};
   virtual TFIBSmallIntField * get_ElementDAY_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementDAY_SDISCOUNT_AUTO(TFIBSmallIntField * ElementDAY_SDISCOUNT_AUTO)=0;

   __property TFIBLargeIntField * ElementIDVIDNOM_SDISCOUNT_AUTO = {read = get_ElementIDVIDNOM_SDISCOUNT_AUTO , write = set_ElementIDVIDNOM_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_ElementIDVIDNOM_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementIDVIDNOM_SDISCOUNT_AUTO(TFIBLargeIntField * ElementIDVIDNOM_SDISCOUNT_AUTO)=0;

   __property TFIBLargeIntField * ElementIDSKLAD_SDISCOUNT_AUTO = {read = get_ElementIDSKLAD_SDISCOUNT_AUTO , write = set_ElementIDSKLAD_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_ElementIDSKLAD_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementIDSKLAD_SDISCOUNT_AUTO(TFIBLargeIntField * ElementIDSKLAD_SDISCOUNT_AUTO)=0;

   __property TFIBLargeIntField * ElementIDBASE_SDISCOUNT_AUTO = {read = get_ElementIDBASE_SDISCOUNT_AUTO , write = set_ElementIDBASE_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_ElementIDBASE_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementIDBASE_SDISCOUNT_AUTO(TFIBLargeIntField * ElementIDBASE_SDISCOUNT_AUTO)=0;

   __property TFIBSmallIntField * ElementNUM_SKIDKI_SDISCOUNT_AUTO = {read = get_ElementNUM_SKIDKI_SDISCOUNT_AUTO , write = set_ElementNUM_SKIDKI_SDISCOUNT_AUTO};
   virtual TFIBSmallIntField * get_ElementNUM_SKIDKI_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementNUM_SKIDKI_SDISCOUNT_AUTO(TFIBSmallIntField * ElementNUM_SKIDKI_SDISCOUNT_AUTO)=0;

   __property TFIBLargeIntField * ElementIDGRPNOM_SDISCOUNT_AUTO = {read = get_ElementIDGRPNOM_SDISCOUNT_AUTO , write = set_ElementIDGRPNOM_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_ElementIDGRPNOM_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementIDGRPNOM_SDISCOUNT_AUTO(TFIBLargeIntField * ElementIDGRPNOM_SDISCOUNT_AUTO)=0;

   __property TFIBIntegerField * ElementTYPE_ACTION_SDISCOUNT_AUTO = {read = get_ElementTYPE_ACTION_SDISCOUNT_AUTO , write = set_ElementTYPE_ACTION_SDISCOUNT_AUTO};
   virtual TFIBIntegerField * get_ElementTYPE_ACTION_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementTYPE_ACTION_SDISCOUNT_AUTO(TFIBIntegerField * ElementTYPE_ACTION_SDISCOUNT_AUTO)=0;

   __property TFIBWideStringField * ElementMESSAGE_SDISCOUNT_AUTO = {read = get_ElementMESSAGE_SDISCOUNT_AUTO , write = set_ElementMESSAGE_SDISCOUNT_AUTO};
   virtual TFIBWideStringField * get_ElementMESSAGE_SDISCOUNT_AUTO(void)=0;
   virtual void set_ElementMESSAGE_SDISCOUNT_AUTO(TFIBWideStringField * ElementMESSAGE_SDISCOUNT_AUTO)=0;

   __property TFIBWideStringField * ElementNAMESKLAD = {read = get_ElementNAMESKLAD , write = set_ElementNAMESKLAD};
   virtual TFIBWideStringField * get_ElementNAMESKLAD(void)=0;
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)=0;

   __property TFIBWideStringField * ElementNAMEGN = {read = get_ElementNAMEGN , write = set_ElementNAMEGN};
   virtual TFIBWideStringField * get_ElementNAMEGN(void)=0;
   virtual void set_ElementNAMEGN(TFIBWideStringField * ElementNAMEGN)=0;

   __property TFIBWideStringField * ElementNAME_SVIDNOM = {read = get_ElementNAME_SVIDNOM , write = set_ElementNAME_SVIDNOM};
   virtual TFIBWideStringField * get_ElementNAME_SVIDNOM(void)=0;
   virtual void set_ElementNAME_SVIDNOM(TFIBWideStringField * ElementNAME_SVIDNOM)=0;

   __property TFIBLargeIntField * TableDiscountAutoID_SDISCOUNT_AUTO = {read = get_TableDiscountAutoID_SDISCOUNT_AUTO , write = set_TableDiscountAutoID_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_TableDiscountAutoID_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoID_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoID_SDISCOUNT_AUTO)=0;

   __property TFIBWideStringField * TableDiscountAutoGID_SDISCOUNT_AUTO = {read = get_TableDiscountAutoGID_SDISCOUNT_AUTO , write = set_TableDiscountAutoGID_SDISCOUNT_AUTO};
   virtual TFIBWideStringField * get_TableDiscountAutoGID_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoGID_SDISCOUNT_AUTO(TFIBWideStringField * TableDiscountAutoGID_SDISCOUNT_AUTO)=0;

   __property TFIBWideStringField * TableDiscountAutoNAME_SDISCOUNT_AUTO = {read = get_TableDiscountAutoNAME_SDISCOUNT_AUTO , write = set_TableDiscountAutoNAME_SDISCOUNT_AUTO};
   virtual TFIBWideStringField * get_TableDiscountAutoNAME_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoNAME_SDISCOUNT_AUTO(TFIBWideStringField * TableDiscountAutoNAME_SDISCOUNT_AUTO)=0;

   __property TFIBSmallIntField * TableDiscountAutoACT_SDISCOUNT_AUTO = {read = get_TableDiscountAutoACT_SDISCOUNT_AUTO , write = set_TableDiscountAutoACT_SDISCOUNT_AUTO};
   virtual TFIBSmallIntField * get_TableDiscountAutoACT_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoACT_SDISCOUNT_AUTO(TFIBSmallIntField * TableDiscountAutoACT_SDISCOUNT_AUTO)=0;

   __property TFIBDateTimeField * TableDiscountAutoNACH_SDISCOUNT_AUTO = {read = get_TableDiscountAutoNACH_SDISCOUNT_AUTO , write = set_TableDiscountAutoNACH_SDISCOUNT_AUTO};
   virtual TFIBDateTimeField * get_TableDiscountAutoNACH_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoNACH_SDISCOUNT_AUTO(TFIBDateTimeField * TableDiscountAutoNACH_SDISCOUNT_AUTO)=0;

   __property TFIBDateTimeField * TableDiscountAutoCON_SDISCOUNT_AUTO = {read = get_TableDiscountAutoCON_SDISCOUNT_AUTO , write = set_TableDiscountAutoCON_SDISCOUNT_AUTO};
   virtual TFIBDateTimeField * get_TableDiscountAutoCON_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoCON_SDISCOUNT_AUTO(TFIBDateTimeField * TableDiscountAutoCON_SDISCOUNT_AUTO)=0;

   __property TFIBBCDField * TableDiscountAutoPRSK_SDISCOUNT_AUTO = {read = get_TableDiscountAutoPRSK_SDISCOUNT_AUTO , write = set_TableDiscountAutoPRSK_SDISCOUNT_AUTO};
   virtual TFIBBCDField * get_TableDiscountAutoPRSK_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoPRSK_SDISCOUNT_AUTO(TFIBBCDField * TableDiscountAutoPRSK_SDISCOUNT_AUTO)=0;

   __property TFIBBCDField * TableDiscountAutoSUM_SDISCOUNT_AUTO = {read = get_TableDiscountAutoSUM_SDISCOUNT_AUTO , write = set_TableDiscountAutoSUM_SDISCOUNT_AUTO};
   virtual TFIBBCDField * get_TableDiscountAutoSUM_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoSUM_SDISCOUNT_AUTO(TFIBBCDField * TableDiscountAutoSUM_SDISCOUNT_AUTO)=0;

   __property TFIBTimeField * TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO = {read = get_TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO , write = set_TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO};
   virtual TFIBTimeField * get_TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO(TFIBTimeField * TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO)=0;

   __property TFIBTimeField * TableDiscountAutoTIME_CON_SDISCOUNT_AUTO = {read = get_TableDiscountAutoTIME_CON_SDISCOUNT_AUTO , write = set_TableDiscountAutoTIME_CON_SDISCOUNT_AUTO};
   virtual TFIBTimeField * get_TableDiscountAutoTIME_CON_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoTIME_CON_SDISCOUNT_AUTO(TFIBTimeField * TableDiscountAutoTIME_CON_SDISCOUNT_AUTO)=0;

   __property TFIBSmallIntField * TableDiscountAutoDAY_SDISCOUNT_AUTO = {read = get_TableDiscountAutoDAY_SDISCOUNT_AUTO , write = set_TableDiscountAutoDAY_SDISCOUNT_AUTO};
   virtual TFIBSmallIntField * get_TableDiscountAutoDAY_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoDAY_SDISCOUNT_AUTO(TFIBSmallIntField * TableDiscountAutoDAY_SDISCOUNT_AUTO)=0;

   __property TFIBLargeIntField * TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO = {read = get_TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO , write = set_TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO)=0;

   __property TFIBLargeIntField * TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO = {read = get_TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO , write = set_TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO)=0;

   __property TFIBLargeIntField * TableDiscountAutoIDBASE_SDISCOUNT_AUTO = {read = get_TableDiscountAutoIDBASE_SDISCOUNT_AUTO , write = set_TableDiscountAutoIDBASE_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_TableDiscountAutoIDBASE_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoIDBASE_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoIDBASE_SDISCOUNT_AUTO)=0;

   __property TFIBSmallIntField * TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO = {read = get_TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO , write = set_TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO};
   virtual TFIBSmallIntField * get_TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO(TFIBSmallIntField * TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO)=0;

   __property TFIBLargeIntField * TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO = {read = get_TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO , write = set_TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO};
   virtual TFIBLargeIntField * get_TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO)=0;

   __property TFIBIntegerField * TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO = {read = get_TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO , write = set_TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO};
   virtual TFIBIntegerField * get_TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO(TFIBIntegerField * TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO)=0;

   __property TFIBWideStringField * TableDiscountAutoMESSAGE_SDISCOUNT_AUTO = {read = get_TableDiscountAutoMESSAGE_SDISCOUNT_AUTO , write = set_TableDiscountAutoMESSAGE_SDISCOUNT_AUTO};
   virtual TFIBWideStringField * get_TableDiscountAutoMESSAGE_SDISCOUNT_AUTO(void)=0;
   virtual void set_TableDiscountAutoMESSAGE_SDISCOUNT_AUTO(TFIBWideStringField * TableDiscountAutoMESSAGE_SDISCOUNT_AUTO)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual __int64 GetIDElement(UnicodeString gid)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
   virtual void OpenTableDiscountAuto(__int64 id_sklad)=0;
};
#define IID_IDMSprDiscountAuto __uuidof(IDMSprDiscountAuto)
#endif
