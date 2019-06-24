#ifndef UIREM_DMSprGrpHardwareH
#define UIREM_DMSprGrpHardwareH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{54EC5B11-3898-4D93-95A9-A27DD3BF62F2}")) IREM_DMSprGrpHardware : public IMainInterface
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

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBLargeIntField * TableID_REM_SGRP_HARDWARE = {read = get_TableID_REM_SGRP_HARDWARE , write = set_TableID_REM_SGRP_HARDWARE};
   virtual TFIBLargeIntField * get_TableID_REM_SGRP_HARDWARE(void)=0;
   virtual void set_TableID_REM_SGRP_HARDWARE(TFIBLargeIntField * TableID_REM_SGRP_HARDWARE)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SGRP_HARDWARE = {read = get_TableIDBASE_REM_SGRP_HARDWARE , write = set_TableIDBASE_REM_SGRP_HARDWARE};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SGRP_HARDWARE(void)=0;
   virtual void set_TableIDBASE_REM_SGRP_HARDWARE(TFIBLargeIntField * TableIDBASE_REM_SGRP_HARDWARE)=0;

   __property TFIBWideStringField * TableNAME_REM_SGRP_HARDWARE = {read = get_TableNAME_REM_SGRP_HARDWARE , write = set_TableNAME_REM_SGRP_HARDWARE};
   virtual TFIBWideStringField * get_TableNAME_REM_SGRP_HARDWARE(void)=0;
   virtual void set_TableNAME_REM_SGRP_HARDWARE(TFIBWideStringField * TableNAME_REM_SGRP_HARDWARE)=0;

   __property TFIBLargeIntField * TableIDGRP_REM_SGRP_HARDWARE = {read = get_TableIDGRP_REM_SGRP_HARDWARE , write = set_TableIDGRP_REM_SGRP_HARDWARE};
   virtual TFIBLargeIntField * get_TableIDGRP_REM_SGRP_HARDWARE(void)=0;
   virtual void set_TableIDGRP_REM_SGRP_HARDWARE(TFIBLargeIntField * TableIDGRP_REM_SGRP_HARDWARE)=0;

   __property TFIBLargeIntField * ElementID_REM_SGRP_HARDWARE = {read = get_ElementID_REM_SGRP_HARDWARE , write = set_ElementID_REM_SGRP_HARDWARE};
   virtual TFIBLargeIntField * get_ElementID_REM_SGRP_HARDWARE(void)=0;
   virtual void set_ElementID_REM_SGRP_HARDWARE(TFIBLargeIntField * ElementID_REM_SGRP_HARDWARE)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SGRP_HARDWARE = {read = get_ElementIDBASE_REM_SGRP_HARDWARE , write = set_ElementIDBASE_REM_SGRP_HARDWARE};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SGRP_HARDWARE(void)=0;
   virtual void set_ElementIDBASE_REM_SGRP_HARDWARE(TFIBLargeIntField * ElementIDBASE_REM_SGRP_HARDWARE)=0;

   __property TFIBWideStringField * ElementNAME_REM_SGRP_HARDWARE = {read = get_ElementNAME_REM_SGRP_HARDWARE , write = set_ElementNAME_REM_SGRP_HARDWARE};
   virtual TFIBWideStringField * get_ElementNAME_REM_SGRP_HARDWARE(void)=0;
   virtual void set_ElementNAME_REM_SGRP_HARDWARE(TFIBWideStringField * ElementNAME_REM_SGRP_HARDWARE)=0;

   __property TFIBLargeIntField * ElementIDGRP_REM_SGRP_HARDWARE = {read = get_ElementIDGRP_REM_SGRP_HARDWARE , write = set_ElementIDGRP_REM_SGRP_HARDWARE};
   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SGRP_HARDWARE(void)=0;
   virtual void set_ElementIDGRP_REM_SGRP_HARDWARE(TFIBLargeIntField * ElementIDGRP_REM_SGRP_HARDWARE)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 FindPoName(AnsiString name)=0;
};
#define IID_IREM_DMSprGrpHardware __uuidof(IREM_DMSprGrpHardware)
#endif
