#ifndef UIDMSprCountryH
#define UIDMSprCountryH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{D4E09E4C-8ABC-4F29-9BAD-0C83AEF99BC0}")) IDMSprCountry : public IMainInterface
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

   __property TFIBBCDField * TableID_SCOUNTRY = {read = get_TableID_SCOUNTRY , write = set_TableID_SCOUNTRY};
   virtual TFIBBCDField * get_TableID_SCOUNTRY(void)=0;
   virtual void set_TableID_SCOUNTRY(TFIBBCDField * TableID_SCOUNTRY)=0;

   __property TFIBBCDField * ElementID_SCOUNTRY = {read = get_ElementID_SCOUNTRY , write = set_ElementID_SCOUNTRY};
   virtual TFIBBCDField * get_ElementID_SCOUNTRY(void)=0;
   virtual void set_ElementID_SCOUNTRY(TFIBBCDField * ElementID_SCOUNTRY)=0;

   __property TFIBWideStringField * TableCODE_SCOUNTRY = {read = get_TableCODE_SCOUNTRY , write = set_TableCODE_SCOUNTRY};
   virtual TFIBWideStringField * get_TableCODE_SCOUNTRY(void)=0;
   virtual void set_TableCODE_SCOUNTRY(TFIBWideStringField * TableCODE_SCOUNTRY)=0;

   __property TFIBWideStringField * TableGID_SCOUNTRY = {read = get_TableGID_SCOUNTRY , write = set_TableGID_SCOUNTRY};
   virtual TFIBWideStringField * get_TableGID_SCOUNTRY(void)=0;
   virtual void set_TableGID_SCOUNTRY(TFIBWideStringField * TableGID_SCOUNTRY)=0;

   __property TFIBWideStringField * TableNAME_SCOUNTRY = {read = get_TableNAME_SCOUNTRY , write = set_TableNAME_SCOUNTRY};
   virtual TFIBWideStringField * get_TableNAME_SCOUNTRY(void)=0;
   virtual void set_TableNAME_SCOUNTRY(TFIBWideStringField * TableNAME_SCOUNTRY)=0;

   __property TFIBWideStringField * ElementCODE_SCOUNTRY = {read = get_ElementCODE_SCOUNTRY , write = set_ElementCODE_SCOUNTRY};
   virtual TFIBWideStringField * get_ElementCODE_SCOUNTRY(void)=0;
   virtual void set_ElementCODE_SCOUNTRY(TFIBWideStringField * ElementCODE_SCOUNTRY)=0;

   __property TFIBWideStringField * ElementGID_SCOUNTRY = {read = get_ElementGID_SCOUNTRY , write = set_ElementGID_SCOUNTRY};
   virtual TFIBWideStringField * get_ElementGID_SCOUNTRY(void)=0;
   virtual void set_ElementGID_SCOUNTRY(TFIBWideStringField * ElementGID_SCOUNTRY)=0;

   __property TFIBWideStringField * ElementNAME_SCOUNTRY = {read = get_ElementNAME_SCOUNTRY , write = set_ElementNAME_SCOUNTRY};
   virtual TFIBWideStringField * get_ElementNAME_SCOUNTRY(void)=0;
   virtual void set_ElementNAME_SCOUNTRY(TFIBWideStringField * ElementNAME_SCOUNTRY)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual __int64 GetIDElement(String gid)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
   virtual __int64 GetIdPoName(UnicodeString name)=0;
};
#define IID_IDMSprCountry __uuidof(IDMSprCountry)
#endif
