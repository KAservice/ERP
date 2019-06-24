#ifndef UIREM_DMSprSostH
#define UIREM_DMSprSostH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{AAC37E6C-9476-4EE7-9E03-68C703A63E72}")) IREM_DMSprSost : public IMainInterface
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

   __property TFIBLargeIntField * TableID_REMSSOST = {read = get_TableID_REMSSOST , write = set_TableID_REMSSOST};
   virtual TFIBLargeIntField * get_TableID_REMSSOST(void)=0;
   virtual void set_TableID_REMSSOST(TFIBLargeIntField * TableID_REMSSOST)=0;

   __property TFIBWideStringField * TableGID_REMSSOST = {read = get_TableGID_REMSSOST , write = set_TableGID_REMSSOST};
   virtual TFIBWideStringField * get_TableGID_REMSSOST(void)=0;
   virtual void set_TableGID_REMSSOST(TFIBWideStringField * TableGID_REMSSOST)=0;

   __property TFIBWideStringField * TableNAME_REMSSOST = {read = get_TableNAME_REMSSOST , write = set_TableNAME_REMSSOST};
   virtual TFIBWideStringField * get_TableNAME_REMSSOST(void)=0;
   virtual void set_TableNAME_REMSSOST(TFIBWideStringField * TableNAME_REMSSOST)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SSOST = {read = get_TableIDBASE_REM_SSOST , write = set_TableIDBASE_REM_SSOST};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SSOST(void)=0;
   virtual void set_TableIDBASE_REM_SSOST(TFIBLargeIntField * TableIDBASE_REM_SSOST)=0;

   __property TFIBLargeIntField * ElementID_REMSSOST = {read = get_ElementID_REMSSOST , write = set_ElementID_REMSSOST};
   virtual TFIBLargeIntField * get_ElementID_REMSSOST(void)=0;
   virtual void set_ElementID_REMSSOST(TFIBLargeIntField * ElementID_REMSSOST)=0;

   __property TFIBWideStringField * ElementGID_REMSSOST = {read = get_ElementGID_REMSSOST , write = set_ElementGID_REMSSOST};
   virtual TFIBWideStringField * get_ElementGID_REMSSOST(void)=0;
   virtual void set_ElementGID_REMSSOST(TFIBWideStringField * ElementGID_REMSSOST)=0;

   __property TFIBWideStringField * ElementNAME_REMSSOST = {read = get_ElementNAME_REMSSOST , write = set_ElementNAME_REMSSOST};
   virtual TFIBWideStringField * get_ElementNAME_REMSSOST(void)=0;
   virtual void set_ElementNAME_REMSSOST(TFIBWideStringField * ElementNAME_REMSSOST)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SSOST = {read = get_ElementIDBASE_REM_SSOST , write = set_ElementIDBASE_REM_SSOST};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SSOST(void)=0;
   virtual void set_ElementIDBASE_REM_SSOST(TFIBLargeIntField * ElementIDBASE_REM_SSOST)=0;

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
#define IID_IREM_DMSprSost __uuidof(IREM_DMSprSost)
#endif
