#ifndef UIDMTableNumberDocH
#define UIDMTableNumberDocH
#include "IMainInterface.h"

#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>

class __declspec(uuid("{D1BE5AA7-4847-4A29-B934-1E473ABF299B}"))IDMTableNumberDoc : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBBCDField * TableID_TNUM_DOC = {read = get_TableID_TNUM_DOC , write = set_TableID_TNUM_DOC};
   virtual TFIBBCDField * get_TableID_TNUM_DOC(void)=0;
   virtual void set_TableID_TNUM_DOC(TFIBBCDField * TableID_TNUM_DOC)=0;

   __property TFIBBCDField * ElementID_TNUM_DOC = {read = get_ElementID_TNUM_DOC , write = set_ElementID_TNUM_DOC};
   virtual TFIBBCDField * get_ElementID_TNUM_DOC(void)=0;
   virtual void set_ElementID_TNUM_DOC(TFIBBCDField * ElementID_TNUM_DOC)=0;

   __property TFIBWideStringField * TableGID_TNUM_DOC = {read = get_TableGID_TNUM_DOC , write = set_TableGID_TNUM_DOC};
   virtual TFIBWideStringField * get_TableGID_TNUM_DOC(void)=0;
   virtual void set_TableGID_TNUM_DOC(TFIBWideStringField * TableGID_TNUM_DOC)=0;

   __property TFIBWideStringField * TableDOC_TNUM_DOC = {read = get_TableDOC_TNUM_DOC , write = set_TableDOC_TNUM_DOC};
   virtual TFIBWideStringField * get_TableDOC_TNUM_DOC(void)=0;
   virtual void set_TableDOC_TNUM_DOC(TFIBWideStringField * TableDOC_TNUM_DOC)=0;

   __property TFIBSmallIntField * TableTYPE_TNUM_DOC = {read = get_TableTYPE_TNUM_DOC , write = set_TableTYPE_TNUM_DOC};
   virtual TFIBSmallIntField * get_TableTYPE_TNUM_DOC(void)=0;
   virtual void set_TableTYPE_TNUM_DOC(TFIBSmallIntField * TableTYPE_TNUM_DOC)=0;

   __property TFIBWideStringField * ElementGID_TNUM_DOC = {read = get_ElementGID_TNUM_DOC , write = set_ElementGID_TNUM_DOC};
   virtual TFIBWideStringField * get_ElementGID_TNUM_DOC(void)=0;
   virtual void set_ElementGID_TNUM_DOC(TFIBWideStringField * ElementGID_TNUM_DOC)=0;

   __property TFIBWideStringField * ElementDOC_TNUM_DOC = {read = get_ElementDOC_TNUM_DOC , write = set_ElementDOC_TNUM_DOC};
   virtual TFIBWideStringField * get_ElementDOC_TNUM_DOC(void)=0;
   virtual void set_ElementDOC_TNUM_DOC(TFIBWideStringField * ElementDOC_TNUM_DOC)=0;

   __property TFIBSmallIntField * ElementTYPE_TNUM_DOC = {read = get_ElementTYPE_TNUM_DOC , write = set_ElementTYPE_TNUM_DOC};
   virtual TFIBSmallIntField * get_ElementTYPE_TNUM_DOC(void)=0;
   virtual void set_ElementTYPE_TNUM_DOC(TFIBSmallIntField * ElementTYPE_TNUM_DOC)=0;


   virtual void OpenTable(void)=0;
   virtual void SaveIsmen()=0;
   virtual void CancelIsmen()=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual void SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual TDateTime GetPosNachNumDoc(AnsiString type_doc)=0;
};
#define IID_IDMTableNumberDoc __uuidof(IDMTableNumberDoc)
#endif
