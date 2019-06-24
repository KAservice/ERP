#ifndef UIREM_DMSprDefectModelNeisprH
#define UIREM_DMSprDefectModelNeisprH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprDefectModelNeispr)) IREM_DMSprDefectModelNeispr : public IMainInterface
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

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_REM_SDEFECT_MODNE = {read = get_TableID_REM_SDEFECT_MODNE , write = set_TableID_REM_SDEFECT_MODNE};
   virtual TFIBLargeIntField * get_TableID_REM_SDEFECT_MODNE(void)=0;
   virtual void set_TableID_REM_SDEFECT_MODNE(TFIBLargeIntField * TableID_REM_SDEFECT_MODNE)=0;

   __property TFIBWideStringField * TableGID_REM_SDEFECT_MODNE = {read = get_TableGID_REM_SDEFECT_MODNE , write = set_TableGID_REM_SDEFECT_MODNE};
   virtual TFIBWideStringField * get_TableGID_REM_SDEFECT_MODNE(void)=0;
   virtual void set_TableGID_REM_SDEFECT_MODNE(TFIBWideStringField * TableGID_REM_SDEFECT_MODNE)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SDEFECT_MODNE = {read = get_TableIDBASE_REM_SDEFECT_MODNE , write = set_TableIDBASE_REM_SDEFECT_MODNE};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SDEFECT_MODNE(void)=0;
   virtual void set_TableIDBASE_REM_SDEFECT_MODNE(TFIBLargeIntField * TableIDBASE_REM_SDEFECT_MODNE)=0;

   __property TFIBLargeIntField * TableIDNEISMOD_REM_SDEFECT_MODNE = {read = get_TableIDNEISMOD_REM_SDEFECT_MODNE , write = set_TableIDNEISMOD_REM_SDEFECT_MODNE};
   virtual TFIBLargeIntField * get_TableIDNEISMOD_REM_SDEFECT_MODNE(void)=0;
   virtual void set_TableIDNEISMOD_REM_SDEFECT_MODNE(TFIBLargeIntField * TableIDNEISMOD_REM_SDEFECT_MODNE)=0;

   __property TFIBWideStringField * TableNAME_REM_SDEFECT_MODNE = {read = get_TableNAME_REM_SDEFECT_MODNE , write = set_TableNAME_REM_SDEFECT_MODNE};
   virtual TFIBWideStringField * get_TableNAME_REM_SDEFECT_MODNE(void)=0;
   virtual void set_TableNAME_REM_SDEFECT_MODNE(TFIBWideStringField * TableNAME_REM_SDEFECT_MODNE)=0;

   __property TFIBWideStringField * TableDESCR_REM_SDEFECT_MODNE = {read = get_TableDESCR_REM_SDEFECT_MODNE , write = set_TableDESCR_REM_SDEFECT_MODNE};
   virtual TFIBWideStringField * get_TableDESCR_REM_SDEFECT_MODNE(void)=0;
   virtual void set_TableDESCR_REM_SDEFECT_MODNE(TFIBWideStringField * TableDESCR_REM_SDEFECT_MODNE)=0;

   __property TFIBLargeIntField * TableIDTDEF_REM_SDEFECT_MODNE = {read = get_TableIDTDEF_REM_SDEFECT_MODNE , write = set_TableIDTDEF_REM_SDEFECT_MODNE};
   virtual TFIBLargeIntField * get_TableIDTDEF_REM_SDEFECT_MODNE(void)=0;
   virtual void set_TableIDTDEF_REM_SDEFECT_MODNE(TFIBLargeIntField * TableIDTDEF_REM_SDEFECT_MODNE)=0;

   __property TFIBWideStringField * TableNAME_REM_STYPDEFECT = {read = get_TableNAME_REM_STYPDEFECT , write = set_TableNAME_REM_STYPDEFECT};
   virtual TFIBWideStringField * get_TableNAME_REM_STYPDEFECT(void)=0;
   virtual void set_TableNAME_REM_STYPDEFECT(TFIBWideStringField * TableNAME_REM_STYPDEFECT)=0;

   __property TFIBWideStringField * TableCODE_REM_STYPDEFECT = {read = get_TableCODE_REM_STYPDEFECT , write = set_TableCODE_REM_STYPDEFECT};
   virtual TFIBWideStringField * get_TableCODE_REM_STYPDEFECT(void)=0;
   virtual void set_TableCODE_REM_STYPDEFECT(TFIBWideStringField * TableCODE_REM_STYPDEFECT)=0;

   __property TFIBLargeIntField * ElementID_REM_SDEFECT_MODNE = {read = get_ElementID_REM_SDEFECT_MODNE , write = set_ElementID_REM_SDEFECT_MODNE};
   virtual TFIBLargeIntField * get_ElementID_REM_SDEFECT_MODNE(void)=0;
   virtual void set_ElementID_REM_SDEFECT_MODNE(TFIBLargeIntField * ElementID_REM_SDEFECT_MODNE)=0;

   __property TFIBWideStringField * ElementGID_REM_SDEFECT_MODNE = {read = get_ElementGID_REM_SDEFECT_MODNE , write = set_ElementGID_REM_SDEFECT_MODNE};
   virtual TFIBWideStringField * get_ElementGID_REM_SDEFECT_MODNE(void)=0;
   virtual void set_ElementGID_REM_SDEFECT_MODNE(TFIBWideStringField * ElementGID_REM_SDEFECT_MODNE)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SDEFECT_MODNE = {read = get_ElementIDBASE_REM_SDEFECT_MODNE , write = set_ElementIDBASE_REM_SDEFECT_MODNE};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SDEFECT_MODNE(void)=0;
   virtual void set_ElementIDBASE_REM_SDEFECT_MODNE(TFIBLargeIntField * ElementIDBASE_REM_SDEFECT_MODNE)=0;

   __property TFIBLargeIntField * ElementIDNEISMOD_REM_SDEFECT_MODNE = {read = get_ElementIDNEISMOD_REM_SDEFECT_MODNE , write = set_ElementIDNEISMOD_REM_SDEFECT_MODNE};
   virtual TFIBLargeIntField * get_ElementIDNEISMOD_REM_SDEFECT_MODNE(void)=0;
   virtual void set_ElementIDNEISMOD_REM_SDEFECT_MODNE(TFIBLargeIntField * ElementIDNEISMOD_REM_SDEFECT_MODNE)=0;

   __property TFIBWideStringField * ElementNAME_REM_SDEFECT_MODNE = {read = get_ElementNAME_REM_SDEFECT_MODNE , write = set_ElementNAME_REM_SDEFECT_MODNE};
   virtual TFIBWideStringField * get_ElementNAME_REM_SDEFECT_MODNE(void)=0;
   virtual void set_ElementNAME_REM_SDEFECT_MODNE(TFIBWideStringField * ElementNAME_REM_SDEFECT_MODNE)=0;

   __property TFIBWideStringField * ElementDESCR_REM_SDEFECT_MODNE = {read = get_ElementDESCR_REM_SDEFECT_MODNE , write = set_ElementDESCR_REM_SDEFECT_MODNE};
   virtual TFIBWideStringField * get_ElementDESCR_REM_SDEFECT_MODNE(void)=0;
   virtual void set_ElementDESCR_REM_SDEFECT_MODNE(TFIBWideStringField * ElementDESCR_REM_SDEFECT_MODNE)=0;

   __property TFIBLargeIntField * ElementIDTDEF_REM_SDEFECT_MODNE = {read = get_ElementIDTDEF_REM_SDEFECT_MODNE , write = set_ElementIDTDEF_REM_SDEFECT_MODNE};
   virtual TFIBLargeIntField * get_ElementIDTDEF_REM_SDEFECT_MODNE(void)=0;
   virtual void set_ElementIDTDEF_REM_SDEFECT_MODNE(TFIBLargeIntField * ElementIDTDEF_REM_SDEFECT_MODNE)=0;

   __property TFIBWideStringField * ElementNAME_REM_STYPDEFECT = {read = get_ElementNAME_REM_STYPDEFECT , write = set_ElementNAME_REM_STYPDEFECT};
   virtual TFIBWideStringField * get_ElementNAME_REM_STYPDEFECT(void)=0;
   virtual void set_ElementNAME_REM_STYPDEFECT(TFIBWideStringField * ElementNAME_REM_STYPDEFECT)=0;

   __property TFIBWideStringField * ElementCODE_REM_STYPDEFECT = {read = get_ElementCODE_REM_STYPDEFECT , write = set_ElementCODE_REM_STYPDEFECT};
   virtual TFIBWideStringField * get_ElementCODE_REM_STYPDEFECT(void)=0;
   virtual void set_ElementCODE_REM_STYPDEFECT(TFIBWideStringField * ElementCODE_REM_STYPDEFECT)=0;

   virtual void OpenTable(__int64 id_model_neispr)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_model_neispr)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IREM_DMSprDefectModelNeispr __uuidof(IREM_DMSprDefectModelNeispr)
#endif
