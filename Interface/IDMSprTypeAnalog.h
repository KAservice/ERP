#ifndef UIDMSprTypeAnalogH
#define UIDMSprTypeAnalogH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprTypeAnalog)) IDMSprTypeAnalog : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourcePodr = {read = get_DataSourcePodr , write = set_DataSourcePodr};
   virtual TDataSource * get_DataSourcePodr(void)=0;
   virtual void set_DataSourcePodr(TDataSource * DataSourcePodr)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TFIBLargeIntField * TableID_STYPE_ANALOG = {read = get_TableID_STYPE_ANALOG , write = set_TableID_STYPE_ANALOG};
   virtual TFIBLargeIntField * get_TableID_STYPE_ANALOG(void)=0;
   virtual void set_TableID_STYPE_ANALOG(TFIBLargeIntField * TableID_STYPE_ANALOG)=0;

   __property TFIBLargeIntField * TableIDBASE_STYPE_ANALOG = {read = get_TableIDBASE_STYPE_ANALOG , write = set_TableIDBASE_STYPE_ANALOG};
   virtual TFIBLargeIntField * get_TableIDBASE_STYPE_ANALOG(void)=0;
   virtual void set_TableIDBASE_STYPE_ANALOG(TFIBLargeIntField * TableIDBASE_STYPE_ANALOG)=0;

   __property TFIBWideStringField * TableGID_STYPE_ANALOG = {read = get_TableGID_STYPE_ANALOG , write = set_TableGID_STYPE_ANALOG};
   virtual TFIBWideStringField * get_TableGID_STYPE_ANALOG(void)=0;
   virtual void set_TableGID_STYPE_ANALOG(TFIBWideStringField * TableGID_STYPE_ANALOG)=0;

   __property TFIBWideStringField * TableNAME_STYPE_ANALOG = {read = get_TableNAME_STYPE_ANALOG , write = set_TableNAME_STYPE_ANALOG};
   virtual TFIBWideStringField * get_TableNAME_STYPE_ANALOG(void)=0;
   virtual void set_TableNAME_STYPE_ANALOG(TFIBWideStringField * TableNAME_STYPE_ANALOG)=0;

   __property TFIBLargeIntField * ElementID_STYPE_ANALOG = {read = get_ElementID_STYPE_ANALOG , write = set_ElementID_STYPE_ANALOG};
   virtual TFIBLargeIntField * get_ElementID_STYPE_ANALOG(void)=0;
   virtual void set_ElementID_STYPE_ANALOG(TFIBLargeIntField * ElementID_STYPE_ANALOG)=0;

   __property TFIBLargeIntField * ElementIDBASE_STYPE_ANALOG = {read = get_ElementIDBASE_STYPE_ANALOG , write = set_ElementIDBASE_STYPE_ANALOG};
   virtual TFIBLargeIntField * get_ElementIDBASE_STYPE_ANALOG(void)=0;
   virtual void set_ElementIDBASE_STYPE_ANALOG(TFIBLargeIntField * ElementIDBASE_STYPE_ANALOG)=0;

   __property TFIBWideStringField * ElementGID_STYPE_ANALOG = {read = get_ElementGID_STYPE_ANALOG , write = set_ElementGID_STYPE_ANALOG};
   virtual TFIBWideStringField * get_ElementGID_STYPE_ANALOG(void)=0;
   virtual void set_ElementGID_STYPE_ANALOG(TFIBWideStringField * ElementGID_STYPE_ANALOG)=0;

   __property TFIBWideStringField * ElementNAME_STYPE_ANALOG = {read = get_ElementNAME_STYPE_ANALOG , write = set_ElementNAME_STYPE_ANALOG};
   virtual TFIBWideStringField * get_ElementNAME_STYPE_ANALOG(void)=0;
   virtual void set_ElementNAME_STYPE_ANALOG(TFIBWideStringField * ElementNAME_STYPE_ANALOG)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual bool NewElement(void)=0;
   virtual bool InsertElement(UnicodeString name)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool SaveElement(void)=0;
   virtual bool OpenTable(void)=0;
   virtual bool TableSaveIsmen(void)=0;
   virtual bool TableCancelIsmen(void)=0;
   virtual bool TableNewElement(void)=0;
   virtual bool TableAppend(void)=0;
   virtual bool TableDelete(void)=0;
   virtual bool TableEdit(void)=0;
   virtual bool TablePost(void)=0;
};
#define IID_IDMSprTypeAnalog __uuidof(IDMSprTypeAnalog)
#endif
