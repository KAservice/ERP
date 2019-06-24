#ifndef UIDMSprDocKlientH
#define UIDMSprDocKlientH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{DCF22380-7720-41D5-80E2-90142B1B71E1}")) IDMSprDocKlient : public IMainInterface
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

   __property TFIBDateField * TableDATEVID_SDOCKLIENT = {read = get_TableDATEVID_SDOCKLIENT , write = set_TableDATEVID_SDOCKLIENT};
   virtual TFIBDateField * get_TableDATEVID_SDOCKLIENT(void)=0;
   virtual void set_TableDATEVID_SDOCKLIENT(TFIBDateField * TableDATEVID_SDOCKLIENT)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBDateField * ElementDATEVID_SDOCKLIENT = {read = get_ElementDATEVID_SDOCKLIENT , write = set_ElementDATEVID_SDOCKLIENT};
   virtual TFIBDateField * get_ElementDATEVID_SDOCKLIENT(void)=0;
   virtual void set_ElementDATEVID_SDOCKLIENT(TFIBDateField * ElementDATEVID_SDOCKLIENT)=0;

   __property TFIBBCDField * TableID_SDOCKLIENT = {read = get_TableID_SDOCKLIENT , write = set_TableID_SDOCKLIENT};
   virtual TFIBBCDField * get_TableID_SDOCKLIENT(void)=0;
   virtual void set_TableID_SDOCKLIENT(TFIBBCDField * TableID_SDOCKLIENT)=0;

   __property TFIBBCDField * TableIDKLIENT_SDOCKLIENT = {read = get_TableIDKLIENT_SDOCKLIENT , write = set_TableIDKLIENT_SDOCKLIENT};
   virtual TFIBBCDField * get_TableIDKLIENT_SDOCKLIENT(void)=0;
   virtual void set_TableIDKLIENT_SDOCKLIENT(TFIBBCDField * TableIDKLIENT_SDOCKLIENT)=0;

   __property TFIBBCDField * ElementID_SDOCKLIENT = {read = get_ElementID_SDOCKLIENT , write = set_ElementID_SDOCKLIENT};
   virtual TFIBBCDField * get_ElementID_SDOCKLIENT(void)=0;
   virtual void set_ElementID_SDOCKLIENT(TFIBBCDField * ElementID_SDOCKLIENT)=0;

   __property TFIBBCDField * ElementIDKLIENT_SDOCKLIENT = {read = get_ElementIDKLIENT_SDOCKLIENT , write = set_ElementIDKLIENT_SDOCKLIENT};
   virtual TFIBBCDField * get_ElementIDKLIENT_SDOCKLIENT(void)=0;
   virtual void set_ElementIDKLIENT_SDOCKLIENT(TFIBBCDField * ElementIDKLIENT_SDOCKLIENT)=0;

   __property TFIBWideStringField * TableNAME_SDOCKLIENT = {read = get_TableNAME_SDOCKLIENT , write = set_TableNAME_SDOCKLIENT};
   virtual TFIBWideStringField * get_TableNAME_SDOCKLIENT(void)=0;
   virtual void set_TableNAME_SDOCKLIENT(TFIBWideStringField * TableNAME_SDOCKLIENT)=0;

   __property TFIBWideStringField * TableSER_SDOCKLIENT = {read = get_TableSER_SDOCKLIENT , write = set_TableSER_SDOCKLIENT};
   virtual TFIBWideStringField * get_TableSER_SDOCKLIENT(void)=0;
   virtual void set_TableSER_SDOCKLIENT(TFIBWideStringField * TableSER_SDOCKLIENT)=0;

   __property TFIBWideStringField * TableNUM_SDOCKLIENT = {read = get_TableNUM_SDOCKLIENT , write = set_TableNUM_SDOCKLIENT};
   virtual TFIBWideStringField * get_TableNUM_SDOCKLIENT(void)=0;
   virtual void set_TableNUM_SDOCKLIENT(TFIBWideStringField * TableNUM_SDOCKLIENT)=0;

   __property TFIBWideStringField * TableVID_SDOCKLIENT = {read = get_TableVID_SDOCKLIENT , write = set_TableVID_SDOCKLIENT};
   virtual TFIBWideStringField * get_TableVID_SDOCKLIENT(void)=0;
   virtual void set_TableVID_SDOCKLIENT(TFIBWideStringField * TableVID_SDOCKLIENT)=0;

   __property TFIBWideStringField * TableGID_SDOCKLIENT = {read = get_TableGID_SDOCKLIENT , write = set_TableGID_SDOCKLIENT};
   virtual TFIBWideStringField * get_TableGID_SDOCKLIENT(void)=0;
   virtual void set_TableGID_SDOCKLIENT(TFIBWideStringField * TableGID_SDOCKLIENT)=0;

   __property TFIBBCDField * TableIDBASE_SDOCKLIENT = {read = get_TableIDBASE_SDOCKLIENT , write = set_TableIDBASE_SDOCKLIENT};
   virtual TFIBBCDField * get_TableIDBASE_SDOCKLIENT(void)=0;
   virtual void set_TableIDBASE_SDOCKLIENT(TFIBBCDField * TableIDBASE_SDOCKLIENT)=0;

   __property TFIBWideStringField * ElementNAME_SDOCKLIENT = {read = get_ElementNAME_SDOCKLIENT , write = set_ElementNAME_SDOCKLIENT};
   virtual TFIBWideStringField * get_ElementNAME_SDOCKLIENT(void)=0;
   virtual void set_ElementNAME_SDOCKLIENT(TFIBWideStringField * ElementNAME_SDOCKLIENT)=0;

   __property TFIBWideStringField * ElementSER_SDOCKLIENT = {read = get_ElementSER_SDOCKLIENT , write = set_ElementSER_SDOCKLIENT};
   virtual TFIBWideStringField * get_ElementSER_SDOCKLIENT(void)=0;
   virtual void set_ElementSER_SDOCKLIENT(TFIBWideStringField * ElementSER_SDOCKLIENT)=0;

   __property TFIBWideStringField * ElementNUM_SDOCKLIENT = {read = get_ElementNUM_SDOCKLIENT , write = set_ElementNUM_SDOCKLIENT};
   virtual TFIBWideStringField * get_ElementNUM_SDOCKLIENT(void)=0;
   virtual void set_ElementNUM_SDOCKLIENT(TFIBWideStringField * ElementNUM_SDOCKLIENT)=0;

   __property TFIBWideStringField * ElementVID_SDOCKLIENT = {read = get_ElementVID_SDOCKLIENT , write = set_ElementVID_SDOCKLIENT};
   virtual TFIBWideStringField * get_ElementVID_SDOCKLIENT(void)=0;
   virtual void set_ElementVID_SDOCKLIENT(TFIBWideStringField * ElementVID_SDOCKLIENT)=0;

   __property TFIBWideStringField * ElementGID_SDOCKLIENT = {read = get_ElementGID_SDOCKLIENT , write = set_ElementGID_SDOCKLIENT};
   virtual TFIBWideStringField * get_ElementGID_SDOCKLIENT(void)=0;
   virtual void set_ElementGID_SDOCKLIENT(TFIBWideStringField * ElementGID_SDOCKLIENT)=0;

   __property TFIBBCDField * ElementIDBASE_SDOCKLIENT = {read = get_ElementIDBASE_SDOCKLIENT , write = set_ElementIDBASE_SDOCKLIENT};
   virtual TFIBBCDField * get_ElementIDBASE_SDOCKLIENT(void)=0;
   virtual void set_ElementIDBASE_SDOCKLIENT(TFIBBCDField * ElementIDBASE_SDOCKLIENT)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   virtual void OpenTable(__int64 IdKl)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(__int64 IdKl)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
};
#define IID_IDMSprDocKlient __uuidof(IDMSprDocKlient)
#endif
