#ifndef UIREM_DMZayavkaImageH
#define UIREM_DMZayavkaImageH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMZayavkaImage)) IREM_DMZayavkaImage : public IMainInterface
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

   __property TFIBLargeIntField * TableID_REM_ZIMAGE = {read = get_TableID_REM_ZIMAGE , write = set_TableID_REM_ZIMAGE};
   virtual TFIBLargeIntField * get_TableID_REM_ZIMAGE(void)=0;
   virtual void set_TableID_REM_ZIMAGE(TFIBLargeIntField * TableID_REM_ZIMAGE)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_ZIMAGE = {read = get_TableIDBASE_REM_ZIMAGE , write = set_TableIDBASE_REM_ZIMAGE};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_ZIMAGE(void)=0;
   virtual void set_TableIDBASE_REM_ZIMAGE(TFIBLargeIntField * TableIDBASE_REM_ZIMAGE)=0;

   __property TFIBLargeIntField * TableIDZ_REM_ZIMAGE = {read = get_TableIDZ_REM_ZIMAGE , write = set_TableIDZ_REM_ZIMAGE};
   virtual TFIBLargeIntField * get_TableIDZ_REM_ZIMAGE(void)=0;
   virtual void set_TableIDZ_REM_ZIMAGE(TFIBLargeIntField * TableIDZ_REM_ZIMAGE)=0;

   __property TFIBWideStringField * TableNAME_REM_ZIMAGE = {read = get_TableNAME_REM_ZIMAGE , write = set_TableNAME_REM_ZIMAGE};
   virtual TFIBWideStringField * get_TableNAME_REM_ZIMAGE(void)=0;
   virtual void set_TableNAME_REM_ZIMAGE(TFIBWideStringField * TableNAME_REM_ZIMAGE)=0;

   __property TFIBSmallIntField * TableSHOWUSER_REM_ZIMAGE = {read = get_TableSHOWUSER_REM_ZIMAGE , write = set_TableSHOWUSER_REM_ZIMAGE};
   virtual TFIBSmallIntField * get_TableSHOWUSER_REM_ZIMAGE(void)=0;
   virtual void set_TableSHOWUSER_REM_ZIMAGE(TFIBSmallIntField * TableSHOWUSER_REM_ZIMAGE)=0;

   __property TFIBBlobField * TableIMAGE_REM_ZIMAGE = {read = get_TableIMAGE_REM_ZIMAGE , write = set_TableIMAGE_REM_ZIMAGE};
   virtual TFIBBlobField * get_TableIMAGE_REM_ZIMAGE(void)=0;
   virtual void set_TableIMAGE_REM_ZIMAGE(TFIBBlobField * TableIMAGE_REM_ZIMAGE)=0;

   __property TFIBLargeIntField * ElementID_REM_ZIMAGE = {read = get_ElementID_REM_ZIMAGE , write = set_ElementID_REM_ZIMAGE};
   virtual TFIBLargeIntField * get_ElementID_REM_ZIMAGE(void)=0;
   virtual void set_ElementID_REM_ZIMAGE(TFIBLargeIntField * ElementID_REM_ZIMAGE)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_ZIMAGE = {read = get_ElementIDBASE_REM_ZIMAGE , write = set_ElementIDBASE_REM_ZIMAGE};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_ZIMAGE(void)=0;
   virtual void set_ElementIDBASE_REM_ZIMAGE(TFIBLargeIntField * ElementIDBASE_REM_ZIMAGE)=0;

   __property TFIBLargeIntField * ElementIDZ_REM_ZIMAGE = {read = get_ElementIDZ_REM_ZIMAGE , write = set_ElementIDZ_REM_ZIMAGE};
   virtual TFIBLargeIntField * get_ElementIDZ_REM_ZIMAGE(void)=0;
   virtual void set_ElementIDZ_REM_ZIMAGE(TFIBLargeIntField * ElementIDZ_REM_ZIMAGE)=0;

   __property TFIBWideStringField * ElementNAME_REM_ZIMAGE = {read = get_ElementNAME_REM_ZIMAGE , write = set_ElementNAME_REM_ZIMAGE};
   virtual TFIBWideStringField * get_ElementNAME_REM_ZIMAGE(void)=0;
   virtual void set_ElementNAME_REM_ZIMAGE(TFIBWideStringField * ElementNAME_REM_ZIMAGE)=0;

   __property TFIBSmallIntField * ElementSHOWUSER_REM_ZIMAGE = {read = get_ElementSHOWUSER_REM_ZIMAGE , write = set_ElementSHOWUSER_REM_ZIMAGE};
   virtual TFIBSmallIntField * get_ElementSHOWUSER_REM_ZIMAGE(void)=0;
   virtual void set_ElementSHOWUSER_REM_ZIMAGE(TFIBSmallIntField * ElementSHOWUSER_REM_ZIMAGE)=0;

   __property TFIBBlobField * ElementIMAGE_REM_ZIMAGE = {read = get_ElementIMAGE_REM_ZIMAGE , write = set_ElementIMAGE_REM_ZIMAGE};
   virtual TFIBBlobField * get_ElementIMAGE_REM_ZIMAGE(void)=0;
   virtual void set_ElementIMAGE_REM_ZIMAGE(TFIBBlobField * ElementIMAGE_REM_ZIMAGE)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_z)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool NewElement(__int64 id_z)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IREM_DMZayavkaImage __uuidof(IREM_DMZayavkaImage)
#endif
