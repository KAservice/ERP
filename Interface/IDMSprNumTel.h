#ifndef UIDMSprNumTelH
#define UIDMSprNumTelH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{454B1B7B-7771-4D01-BB6E-B1E92752D9ED}")) IDMSprNumTel : public IMainInterface
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

   __property TFIBBCDField * TableID_NUMTEL = {read = get_TableID_NUMTEL , write = set_TableID_NUMTEL};
   virtual TFIBBCDField * get_TableID_NUMTEL(void)=0;
   virtual void set_TableID_NUMTEL(TFIBBCDField * TableID_NUMTEL)=0;

   __property TFIBBCDField * TableIDKLIENT_NUMTEL = {read = get_TableIDKLIENT_NUMTEL , write = set_TableIDKLIENT_NUMTEL};
   virtual TFIBBCDField * get_TableIDKLIENT_NUMTEL(void)=0;
   virtual void set_TableIDKLIENT_NUMTEL(TFIBBCDField * TableIDKLIENT_NUMTEL)=0;

   __property TFIBBCDField * ElementID_NUMTEL = {read = get_ElementID_NUMTEL , write = set_ElementID_NUMTEL};
   virtual TFIBBCDField * get_ElementID_NUMTEL(void)=0;
   virtual void set_ElementID_NUMTEL(TFIBBCDField * ElementID_NUMTEL)=0;

   __property TFIBBCDField * ElementIDKLIENT_NUMTEL = {read = get_ElementIDKLIENT_NUMTEL , write = set_ElementIDKLIENT_NUMTEL};
   virtual TFIBBCDField * get_ElementIDKLIENT_NUMTEL(void)=0;
   virtual void set_ElementIDKLIENT_NUMTEL(TFIBBCDField * ElementIDKLIENT_NUMTEL)=0;

   __property TFIBWideStringField * TableCODE_NUMTEL = {read = get_TableCODE_NUMTEL , write = set_TableCODE_NUMTEL};
   virtual TFIBWideStringField * get_TableCODE_NUMTEL(void)=0;
   virtual void set_TableCODE_NUMTEL(TFIBWideStringField * TableCODE_NUMTEL)=0;

   __property TFIBWideStringField * TableNUMBER_NUMTEL = {read = get_TableNUMBER_NUMTEL , write = set_TableNUMBER_NUMTEL};
   virtual TFIBWideStringField * get_TableNUMBER_NUMTEL(void)=0;
   virtual void set_TableNUMBER_NUMTEL(TFIBWideStringField * TableNUMBER_NUMTEL)=0;

   __property TFIBWideStringField * TableGID_SNUMTEL = {read = get_TableGID_SNUMTEL , write = set_TableGID_SNUMTEL};
   virtual TFIBWideStringField * get_TableGID_SNUMTEL(void)=0;
   virtual void set_TableGID_SNUMTEL(TFIBWideStringField * TableGID_SNUMTEL)=0;

   __property TFIBWideStringField * ElementCODE_NUMTEL = {read = get_ElementCODE_NUMTEL , write = set_ElementCODE_NUMTEL};
   virtual TFIBWideStringField * get_ElementCODE_NUMTEL(void)=0;
   virtual void set_ElementCODE_NUMTEL(TFIBWideStringField * ElementCODE_NUMTEL)=0;

   __property TFIBWideStringField * ElementNUMBER_NUMTEL = {read = get_ElementNUMBER_NUMTEL , write = set_ElementNUMBER_NUMTEL};
   virtual TFIBWideStringField * get_ElementNUMBER_NUMTEL(void)=0;
   virtual void set_ElementNUMBER_NUMTEL(TFIBWideStringField * ElementNUMBER_NUMTEL)=0;

   __property TFIBWideStringField * ElementGID_SNUMTEL = {read = get_ElementGID_SNUMTEL , write = set_ElementGID_SNUMTEL};
   virtual TFIBWideStringField * get_ElementGID_SNUMTEL(void)=0;
   virtual void set_ElementGID_SNUMTEL(TFIBWideStringField * ElementGID_SNUMTEL)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   virtual void OpenTable(__int64 IdKl)=0;
   virtual int OpenElement(__int64 Id)=0;  //возвращает количество элементо=0;
   virtual void NewElement(__int64 IdKl)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
};
#define IID_IDMSprNumTel __uuidof(IDMSprNumTel)
#endif
