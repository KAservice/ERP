#ifndef UIREM_DMSprTypeRemontH
#define UIREM_DMSprTypeRemontH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{81DC3AB3-C53D-463C-8A02-3F887D41623B}")) IREM_DMSprTypeRemont : public IMainInterface
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

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * ElementID_STREMONT = {read = get_ElementID_STREMONT , write = set_ElementID_STREMONT};
   virtual TFIBLargeIntField * get_ElementID_STREMONT(void)=0;
   virtual void set_ElementID_STREMONT(TFIBLargeIntField * ElementID_STREMONT)=0;

   __property TFIBWideStringField * ElementGID_STREMONT = {read = get_ElementGID_STREMONT , write = set_ElementGID_STREMONT};
   virtual TFIBWideStringField * get_ElementGID_STREMONT(void)=0;
   virtual void set_ElementGID_STREMONT(TFIBWideStringField * ElementGID_STREMONT)=0;

   __property TFIBWideStringField * ElementNAME_STREMONT = {read = get_ElementNAME_STREMONT , write = set_ElementNAME_STREMONT};
   virtual TFIBWideStringField * get_ElementNAME_STREMONT(void)=0;
   virtual void set_ElementNAME_STREMONT(TFIBWideStringField * ElementNAME_STREMONT)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_STREMONT = {read = get_ElementIDBASE_REM_STREMONT , write = set_ElementIDBASE_REM_STREMONT};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_STREMONT(void)=0;
   virtual void set_ElementIDBASE_REM_STREMONT(TFIBLargeIntField * ElementIDBASE_REM_STREMONT)=0;

   __property TFIBLargeIntField * TableID_STREMONT = {read = get_TableID_STREMONT , write = set_TableID_STREMONT};
   virtual TFIBLargeIntField * get_TableID_STREMONT(void)=0;
   virtual void set_TableID_STREMONT(TFIBLargeIntField * TableID_STREMONT)=0;

   __property TFIBWideStringField * TableGID_STREMONT = {read = get_TableGID_STREMONT , write = set_TableGID_STREMONT};
   virtual TFIBWideStringField * get_TableGID_STREMONT(void)=0;
   virtual void set_TableGID_STREMONT(TFIBWideStringField * TableGID_STREMONT)=0;

   __property TFIBWideStringField * TableNAME_STREMONT = {read = get_TableNAME_STREMONT , write = set_TableNAME_STREMONT};
   virtual TFIBWideStringField * get_TableNAME_STREMONT(void)=0;
   virtual void set_TableNAME_STREMONT(TFIBWideStringField * TableNAME_STREMONT)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_STREMONT = {read = get_TableIDBASE_REM_STREMONT , write = set_TableIDBASE_REM_STREMONT};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_STREMONT(void)=0;
   virtual void set_TableIDBASE_REM_STREMONT(TFIBLargeIntField * TableIDBASE_REM_STREMONT)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 GetIDElement(UnicodeString gid)=0;
   virtual UnicodeString GetGIDElement(__int64 id)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
};
#define IID_IREM_DMSprTypeRemont __uuidof(IREM_DMSprTypeRemont)
#endif
