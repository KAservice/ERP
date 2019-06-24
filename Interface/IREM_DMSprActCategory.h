#ifndef UIREM_DMSprActCategoryH
#define UIREM_DMSprActCategoryH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprActCategory)) IREM_DMSprActCategory : public IMainInterface
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

   __property TFIBLargeIntField * TableID_REM_SACTCATEGORY = {read = get_TableID_REM_SACTCATEGORY , write = set_TableID_REM_SACTCATEGORY};
   virtual TFIBLargeIntField * get_TableID_REM_SACTCATEGORY(void)=0;
   virtual void set_TableID_REM_SACTCATEGORY(TFIBLargeIntField * TableID_REM_SACTCATEGORY)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SACTCATEGORY = {read = get_TableIDBASE_REM_SACTCATEGORY , write = set_TableIDBASE_REM_SACTCATEGORY};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SACTCATEGORY(void)=0;
   virtual void set_TableIDBASE_REM_SACTCATEGORY(TFIBLargeIntField * TableIDBASE_REM_SACTCATEGORY)=0;

   __property TFIBWideStringField * TableGID_REM_SACTCATEGORY = {read = get_TableGID_REM_SACTCATEGORY , write = set_TableGID_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_TableGID_REM_SACTCATEGORY(void)=0;
   virtual void set_TableGID_REM_SACTCATEGORY(TFIBWideStringField * TableGID_REM_SACTCATEGORY)=0;

   __property TFIBWideStringField * TableNAME_REM_SACTCATEGORY = {read = get_TableNAME_REM_SACTCATEGORY , write = set_TableNAME_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_TableNAME_REM_SACTCATEGORY(void)=0;
   virtual void set_TableNAME_REM_SACTCATEGORY(TFIBWideStringField * TableNAME_REM_SACTCATEGORY)=0;

   __property TFIBLargeIntField * ElementID_REM_SACTCATEGORY = {read = get_ElementID_REM_SACTCATEGORY , write = set_ElementID_REM_SACTCATEGORY};
   virtual TFIBLargeIntField * get_ElementID_REM_SACTCATEGORY(void)=0;
   virtual void set_ElementID_REM_SACTCATEGORY(TFIBLargeIntField * ElementID_REM_SACTCATEGORY)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SACTCATEGORY = {read = get_ElementIDBASE_REM_SACTCATEGORY , write = set_ElementIDBASE_REM_SACTCATEGORY};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SACTCATEGORY(void)=0;
   virtual void set_ElementIDBASE_REM_SACTCATEGORY(TFIBLargeIntField * ElementIDBASE_REM_SACTCATEGORY)=0;

   __property TFIBWideStringField * ElementGID_REM_SACTCATEGORY = {read = get_ElementGID_REM_SACTCATEGORY , write = set_ElementGID_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_ElementGID_REM_SACTCATEGORY(void)=0;
   virtual void set_ElementGID_REM_SACTCATEGORY(TFIBWideStringField * ElementGID_REM_SACTCATEGORY)=0;

   __property TFIBWideStringField * ElementNAME_REM_SACTCATEGORY = {read = get_ElementNAME_REM_SACTCATEGORY , write = set_ElementNAME_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_ElementNAME_REM_SACTCATEGORY(void)=0;
   virtual void set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IREM_DMSprActCategory __uuidof(IREM_DMSprActCategory)
#endif
