#ifndef UIDMSprPropertiesValuesListH
#define UIDMSprPropertiesValuesListH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprPropertiesValuesList)) IDMSprPropertiesValuesList : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SPROPVALUELIST = {read = get_TableID_SPROPVALUELIST , write = set_TableID_SPROPVALUELIST};
   virtual TFIBLargeIntField * get_TableID_SPROPVALUELIST(void)=0;
   virtual void set_TableID_SPROPVALUELIST(TFIBLargeIntField * TableID_SPROPVALUELIST)=0;

   __property TFIBLargeIntField * TableIDBASE_SPROPVALUELIST = {read = get_TableIDBASE_SPROPVALUELIST , write = set_TableIDBASE_SPROPVALUELIST};
   virtual TFIBLargeIntField * get_TableIDBASE_SPROPVALUELIST(void)=0;
   virtual void set_TableIDBASE_SPROPVALUELIST(TFIBLargeIntField * TableIDBASE_SPROPVALUELIST)=0;

   __property TFIBWideStringField * TableGID_SPROPVALUELIST = {read = get_TableGID_SPROPVALUELIST , write = set_TableGID_SPROPVALUELIST};
   virtual TFIBWideStringField * get_TableGID_SPROPVALUELIST(void)=0;
   virtual void set_TableGID_SPROPVALUELIST(TFIBWideStringField * TableGID_SPROPVALUELIST)=0;

   __property TFIBLargeIntField * TableIDPROP_SPROPVALUELIST = {read = get_TableIDPROP_SPROPVALUELIST , write = set_TableIDPROP_SPROPVALUELIST};
   virtual TFIBLargeIntField * get_TableIDPROP_SPROPVALUELIST(void)=0;
   virtual void set_TableIDPROP_SPROPVALUELIST(TFIBLargeIntField * TableIDPROP_SPROPVALUELIST)=0;

   __property TFIBWideStringField * TableNAME_SPROPVALUELIST = {read = get_TableNAME_SPROPVALUELIST , write = set_TableNAME_SPROPVALUELIST};
   virtual TFIBWideStringField * get_TableNAME_SPROPVALUELIST(void)=0;
   virtual void set_TableNAME_SPROPVALUELIST(TFIBWideStringField * TableNAME_SPROPVALUELIST)=0;

   __property TFIBLargeIntField * ElementID_SPROPVALUELIST = {read = get_ElementID_SPROPVALUELIST , write = set_ElementID_SPROPVALUELIST};
   virtual TFIBLargeIntField * get_ElementID_SPROPVALUELIST(void)=0;
   virtual void set_ElementID_SPROPVALUELIST(TFIBLargeIntField * ElementID_SPROPVALUELIST)=0;

   __property TFIBLargeIntField * ElementIDBASE_SPROPVALUELIST = {read = get_ElementIDBASE_SPROPVALUELIST , write = set_ElementIDBASE_SPROPVALUELIST};
   virtual TFIBLargeIntField * get_ElementIDBASE_SPROPVALUELIST(void)=0;
   virtual void set_ElementIDBASE_SPROPVALUELIST(TFIBLargeIntField * ElementIDBASE_SPROPVALUELIST)=0;

   __property TFIBWideStringField * ElementGID_SPROPVALUELIST = {read = get_ElementGID_SPROPVALUELIST , write = set_ElementGID_SPROPVALUELIST};
   virtual TFIBWideStringField * get_ElementGID_SPROPVALUELIST(void)=0;
   virtual void set_ElementGID_SPROPVALUELIST(TFIBWideStringField * ElementGID_SPROPVALUELIST)=0;

   __property TFIBLargeIntField * ElementIDPROP_SPROPVALUELIST = {read = get_ElementIDPROP_SPROPVALUELIST , write = set_ElementIDPROP_SPROPVALUELIST};
   virtual TFIBLargeIntField * get_ElementIDPROP_SPROPVALUELIST(void)=0;
   virtual void set_ElementIDPROP_SPROPVALUELIST(TFIBLargeIntField * ElementIDPROP_SPROPVALUELIST)=0;

   __property TFIBWideStringField * ElementNAME_SPROPVALUELIST = {read = get_ElementNAME_SPROPVALUELIST , write = set_ElementNAME_SPROPVALUELIST};
   virtual TFIBWideStringField * get_ElementNAME_SPROPVALUELIST(void)=0;
   virtual void set_ElementNAME_SPROPVALUELIST(TFIBWideStringField * ElementNAME_SPROPVALUELIST)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   virtual void OpenTable(__int64 id_prop)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_prop)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IDMSprPropertiesValuesList __uuidof(IDMSprPropertiesValuesList)
#endif
