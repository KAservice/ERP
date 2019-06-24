#ifndef UIDMSprInetCatalogH
#define UIDMSprInetCatalogH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprInetCatalog)) IDMSprInetCatalog : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SINETCATALOG = {read = get_TableID_SINETCATALOG , write = set_TableID_SINETCATALOG};
   virtual TFIBLargeIntField * get_TableID_SINETCATALOG(void)=0;
   virtual void set_TableID_SINETCATALOG(TFIBLargeIntField * TableID_SINETCATALOG)=0;

   __property TFIBLargeIntField * TableIDBASE_SINETCATALOG = {read = get_TableIDBASE_SINETCATALOG , write = set_TableIDBASE_SINETCATALOG};
   virtual TFIBLargeIntField * get_TableIDBASE_SINETCATALOG(void)=0;
   virtual void set_TableIDBASE_SINETCATALOG(TFIBLargeIntField * TableIDBASE_SINETCATALOG)=0;

   __property TFIBWideStringField * TableGID_SINETCATALOG = {read = get_TableGID_SINETCATALOG , write = set_TableGID_SINETCATALOG};
   virtual TFIBWideStringField * get_TableGID_SINETCATALOG(void)=0;
   virtual void set_TableGID_SINETCATALOG(TFIBWideStringField * TableGID_SINETCATALOG)=0;

   __property TFIBWideStringField * TableNAME_SINETCATALOG = {read = get_TableNAME_SINETCATALOG , write = set_TableNAME_SINETCATALOG};
   virtual TFIBWideStringField * get_TableNAME_SINETCATALOG(void)=0;
   virtual void set_TableNAME_SINETCATALOG(TFIBWideStringField * TableNAME_SINETCATALOG)=0;

   __property TFIBLargeIntField * ElementID_SINETCATALOG = {read = get_ElementID_SINETCATALOG , write = set_ElementID_SINETCATALOG};
   virtual TFIBLargeIntField * get_ElementID_SINETCATALOG(void)=0;
   virtual void set_ElementID_SINETCATALOG(TFIBLargeIntField * ElementID_SINETCATALOG)=0;

   __property TFIBLargeIntField * ElementIDBASE_SINETCATALOG = {read = get_ElementIDBASE_SINETCATALOG , write = set_ElementIDBASE_SINETCATALOG};
   virtual TFIBLargeIntField * get_ElementIDBASE_SINETCATALOG(void)=0;
   virtual void set_ElementIDBASE_SINETCATALOG(TFIBLargeIntField * ElementIDBASE_SINETCATALOG)=0;

   __property TFIBWideStringField * ElementGID_SINETCATALOG = {read = get_ElementGID_SINETCATALOG , write = set_ElementGID_SINETCATALOG};
   virtual TFIBWideStringField * get_ElementGID_SINETCATALOG(void)=0;
   virtual void set_ElementGID_SINETCATALOG(TFIBWideStringField * ElementGID_SINETCATALOG)=0;

   __property TFIBWideStringField * ElementNAME_SINETCATALOG = {read = get_ElementNAME_SINETCATALOG , write = set_ElementNAME_SINETCATALOG};
   virtual TFIBWideStringField * get_ElementNAME_SINETCATALOG(void)=0;
   virtual void set_ElementNAME_SINETCATALOG(TFIBWideStringField * ElementNAME_SINETCATALOG)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 GetIdPoName(UnicodeString name)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
};
#define IID_IDMSprInetCatalog __uuidof(IDMSprInetCatalog)
#endif
