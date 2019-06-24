#ifndef UIREM_DMSprModelPropertiesValueH
#define UIREM_DMSprModelPropertiesValueH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprModelPropertiesValue)) IREM_DMSprModelPropertiesValue : public IMainInterface
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

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBLargeIntField * TableID_REM_SMODEL_PROPVAL = {read = get_TableID_REM_SMODEL_PROPVAL , write = set_TableID_REM_SMODEL_PROPVAL};
   virtual TFIBLargeIntField * get_TableID_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_TableID_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableID_REM_SMODEL_PROPVAL)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SMODEL_PROPVAL = {read = get_TableIDBASE_REM_SMODEL_PROPVAL , write = set_TableIDBASE_REM_SMODEL_PROPVAL};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_TableIDBASE_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableIDBASE_REM_SMODEL_PROPVAL)=0;

   __property TFIBWideStringField * TableGID_REM_SMODEL_PROPVAL = {read = get_TableGID_REM_SMODEL_PROPVAL , write = set_TableGID_REM_SMODEL_PROPVAL};
   virtual TFIBWideStringField * get_TableGID_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_TableGID_REM_SMODEL_PROPVAL(TFIBWideStringField * TableGID_REM_SMODEL_PROPVAL)=0;

   __property TFIBLargeIntField * TableIDMODEL_REM_SMODEL_PROPVAL = {read = get_TableIDMODEL_REM_SMODEL_PROPVAL , write = set_TableIDMODEL_REM_SMODEL_PROPVAL};
   virtual TFIBLargeIntField * get_TableIDMODEL_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_TableIDMODEL_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableIDMODEL_REM_SMODEL_PROPVAL)=0;

   __property TFIBLargeIntField * TableIDPROP_REM_SMODEL_PROPVAL = {read = get_TableIDPROP_REM_SMODEL_PROPVAL , write = set_TableIDPROP_REM_SMODEL_PROPVAL};
   virtual TFIBLargeIntField * get_TableIDPROP_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_TableIDPROP_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableIDPROP_REM_SMODEL_PROPVAL)=0;

   __property TFIBLargeIntField * TableIDPVL_REM_SMODEL_PROPVAL = {read = get_TableIDPVL_REM_SMODEL_PROPVAL , write = set_TableIDPVL_REM_SMODEL_PROPVAL};
   virtual TFIBLargeIntField * get_TableIDPVL_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_TableIDPVL_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableIDPVL_REM_SMODEL_PROPVAL)=0;

   __property TFIBWideStringField * TableVALTEXT_REM_SMODEL_PROPVAL = {read = get_TableVALTEXT_REM_SMODEL_PROPVAL , write = set_TableVALTEXT_REM_SMODEL_PROPVAL};
   virtual TFIBWideStringField * get_TableVALTEXT_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_TableVALTEXT_REM_SMODEL_PROPVAL(TFIBWideStringField * TableVALTEXT_REM_SMODEL_PROPVAL)=0;

   __property TFIBDateTimeField * TableISM_REM_SMODEL_PROPVAL = {read = get_TableISM_REM_SMODEL_PROPVAL , write = set_TableISM_REM_SMODEL_PROPVAL};
   virtual TFIBDateTimeField * get_TableISM_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_TableISM_REM_SMODEL_PROPVAL(TFIBDateTimeField * TableISM_REM_SMODEL_PROPVAL)=0;

   __property TFIBWideStringField * TableNAME_SPROP = {read = get_TableNAME_SPROP , write = set_TableNAME_SPROP};
   virtual TFIBWideStringField * get_TableNAME_SPROP(void)=0;
   virtual void set_TableNAME_SPROP(TFIBWideStringField * TableNAME_SPROP)=0;

   __property TFIBWideStringField * TableNAME_FOR_PRINT_SPROP = {read = get_TableNAME_FOR_PRINT_SPROP , write = set_TableNAME_FOR_PRINT_SPROP};
   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP(void)=0;
   virtual void set_TableNAME_FOR_PRINT_SPROP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP)=0;

   __property TFIBWideStringField * TableNAME_SPROPVALUELIST = {read = get_TableNAME_SPROPVALUELIST , write = set_TableNAME_SPROPVALUELIST};
   virtual TFIBWideStringField * get_TableNAME_SPROPVALUELIST(void)=0;
   virtual void set_TableNAME_SPROPVALUELIST(TFIBWideStringField * TableNAME_SPROPVALUELIST)=0;

   __property TFIBWideStringField * TableNAME_SPROP_GRP = {read = get_TableNAME_SPROP_GRP , write = set_TableNAME_SPROP_GRP};
   virtual TFIBWideStringField * get_TableNAME_SPROP_GRP(void)=0;
   virtual void set_TableNAME_SPROP_GRP(TFIBWideStringField * TableNAME_SPROP_GRP)=0;

   __property TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP = {read = get_TableNAME_FOR_PRINT_SPROP_GRP , write = set_TableNAME_FOR_PRINT_SPROP_GRP};
   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP_GRP(void)=0;
   virtual void set_TableNAME_FOR_PRINT_SPROP_GRP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP)=0;

   __property TFIBLargeIntField * ElementID_REM_SMODEL_PROPVAL = {read = get_ElementID_REM_SMODEL_PROPVAL , write = set_ElementID_REM_SMODEL_PROPVAL};
   virtual TFIBLargeIntField * get_ElementID_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_ElementID_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementID_REM_SMODEL_PROPVAL)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SMODEL_PROPVAL = {read = get_ElementIDBASE_REM_SMODEL_PROPVAL , write = set_ElementIDBASE_REM_SMODEL_PROPVAL};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_ElementIDBASE_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementIDBASE_REM_SMODEL_PROPVAL)=0;

   __property TFIBWideStringField * ElementGID_REM_SMODEL_PROPVAL = {read = get_ElementGID_REM_SMODEL_PROPVAL , write = set_ElementGID_REM_SMODEL_PROPVAL};
   virtual TFIBWideStringField * get_ElementGID_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_ElementGID_REM_SMODEL_PROPVAL(TFIBWideStringField * ElementGID_REM_SMODEL_PROPVAL)=0;

   __property TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_PROPVAL = {read = get_ElementIDMODEL_REM_SMODEL_PROPVAL , write = set_ElementIDMODEL_REM_SMODEL_PROPVAL};
   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_ElementIDMODEL_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_PROPVAL)=0;

   __property TFIBLargeIntField * ElementIDPROP_REM_SMODEL_PROPVAL = {read = get_ElementIDPROP_REM_SMODEL_PROPVAL , write = set_ElementIDPROP_REM_SMODEL_PROPVAL};
   virtual TFIBLargeIntField * get_ElementIDPROP_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_ElementIDPROP_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementIDPROP_REM_SMODEL_PROPVAL)=0;

   __property TFIBLargeIntField * ElementIDPVL_REM_SMODEL_PROPVAL = {read = get_ElementIDPVL_REM_SMODEL_PROPVAL , write = set_ElementIDPVL_REM_SMODEL_PROPVAL};
   virtual TFIBLargeIntField * get_ElementIDPVL_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_ElementIDPVL_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementIDPVL_REM_SMODEL_PROPVAL)=0;

   __property TFIBWideStringField * ElementVALTEXT_REM_SMODEL_PROPVAL = {read = get_ElementVALTEXT_REM_SMODEL_PROPVAL , write = set_ElementVALTEXT_REM_SMODEL_PROPVAL};
   virtual TFIBWideStringField * get_ElementVALTEXT_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_ElementVALTEXT_REM_SMODEL_PROPVAL(TFIBWideStringField * ElementVALTEXT_REM_SMODEL_PROPVAL)=0;

   __property TFIBDateTimeField * ElementISM_REM_SMODEL_PROPVAL = {read = get_ElementISM_REM_SMODEL_PROPVAL , write = set_ElementISM_REM_SMODEL_PROPVAL};
   virtual TFIBDateTimeField * get_ElementISM_REM_SMODEL_PROPVAL(void)=0;
   virtual void set_ElementISM_REM_SMODEL_PROPVAL(TFIBDateTimeField * ElementISM_REM_SMODEL_PROPVAL)=0;

   __property TFIBWideStringField * ElementNAME_SPROP = {read = get_ElementNAME_SPROP , write = set_ElementNAME_SPROP};
   virtual TFIBWideStringField * get_ElementNAME_SPROP(void)=0;
   virtual void set_ElementNAME_SPROP(TFIBWideStringField * ElementNAME_SPROP)=0;

   __property TFIBWideStringField * ElementNAME_SPROPVALUELIST = {read = get_ElementNAME_SPROPVALUELIST , write = set_ElementNAME_SPROPVALUELIST};
   virtual TFIBWideStringField * get_ElementNAME_SPROPVALUELIST(void)=0;
   virtual void set_ElementNAME_SPROPVALUELIST(TFIBWideStringField * ElementNAME_SPROPVALUELIST)=0;

   __property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};
   virtual __int64 get_IdOwner(void)=0;
   virtual void set_IdOwner(__int64 IdOwner)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_owner)=0;
   virtual bool NewElement(__int64 id_owner)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IREM_DMSprModelPropertiesValue __uuidof(IREM_DMSprModelPropertiesValue)
#endif
