#ifndef UIDMSprStrObjectH
#define UIDMSprStrObjectH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{858D3C76-CB1C-40E0-8ECA-72332EA9EB02}"))IDMSprStrObject : public IMainInterface
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

   __property TpFIBDataSet * Code = {read = get_Code , write = set_Code};
   virtual TpFIBDataSet * get_Code(void)=0;
   virtual void set_Code(TpFIBDataSet * Code)=0;

   __property TFIBIntegerField * CodeMAXCODE = {read = get_CodeMAXCODE , write = set_CodeMAXCODE};
   virtual TFIBIntegerField * get_CodeMAXCODE(void)=0;
   virtual void set_CodeMAXCODE(TFIBIntegerField * CodeMAXCODE)=0;

   __property TFIBBCDField * TableID_STROB = {read = get_TableID_STROB , write = set_TableID_STROB};
   virtual TFIBBCDField * get_TableID_STROB(void)=0;
   virtual void set_TableID_STROB(TFIBBCDField * TableID_STROB)=0;

   __property TFIBBCDField * TableIDGRP_STROB = {read = get_TableIDGRP_STROB , write = set_TableIDGRP_STROB};
   virtual TFIBBCDField * get_TableIDGRP_STROB(void)=0;
   virtual void set_TableIDGRP_STROB(TFIBBCDField * TableIDGRP_STROB)=0;

   __property TFIBSmallIntField * TableGRP_STROB = {read = get_TableGRP_STROB , write = set_TableGRP_STROB};
   virtual TFIBSmallIntField * get_TableGRP_STROB(void)=0;
   virtual void set_TableGRP_STROB(TFIBSmallIntField * TableGRP_STROB)=0;

   __property TFIBBCDField * ElementID_STROB = {read = get_ElementID_STROB , write = set_ElementID_STROB};
   virtual TFIBBCDField * get_ElementID_STROB(void)=0;
   virtual void set_ElementID_STROB(TFIBBCDField * ElementID_STROB)=0;

   __property TFIBBCDField * ElementIDGRP_STROB = {read = get_ElementIDGRP_STROB , write = set_ElementIDGRP_STROB};
   virtual TFIBBCDField * get_ElementIDGRP_STROB(void)=0;
   virtual void set_ElementIDGRP_STROB(TFIBBCDField * ElementIDGRP_STROB)=0;

   __property TFIBSmallIntField * ElementGRP_STROB = {read = get_ElementGRP_STROB , write = set_ElementGRP_STROB};
   virtual TFIBSmallIntField * get_ElementGRP_STROB(void)=0;
   virtual void set_ElementGRP_STROB(TFIBSmallIntField * ElementGRP_STROB)=0;

   __property TFIBWideStringField * TableNAME_STROB = {read = get_TableNAME_STROB , write = set_TableNAME_STROB};
   virtual TFIBWideStringField * get_TableNAME_STROB(void)=0;
   virtual void set_TableNAME_STROB(TFIBWideStringField * TableNAME_STROB)=0;

   __property TFIBIntegerField * TableCODE_STROB = {read = get_TableCODE_STROB , write = set_TableCODE_STROB};
   virtual TFIBIntegerField * get_TableCODE_STROB(void)=0;
   virtual void set_TableCODE_STROB(TFIBIntegerField * TableCODE_STROB)=0;

   __property TFIBWideStringField * TableGID_SSTROB = {read = get_TableGID_SSTROB , write = set_TableGID_SSTROB};
   virtual TFIBWideStringField * get_TableGID_SSTROB(void)=0;
   virtual void set_TableGID_SSTROB(TFIBWideStringField * TableGID_SSTROB)=0;

   __property TFIBWideStringField * ElementNAME_STROB = {read = get_ElementNAME_STROB , write = set_ElementNAME_STROB};
   virtual TFIBWideStringField * get_ElementNAME_STROB(void)=0;
   virtual void set_ElementNAME_STROB(TFIBWideStringField * ElementNAME_STROB)=0;

   __property TFIBIntegerField * ElementCODE_STROB = {read = get_ElementCODE_STROB , write = set_ElementCODE_STROB};
   virtual TFIBIntegerField * get_ElementCODE_STROB(void)=0;
   virtual void set_ElementCODE_STROB(TFIBIntegerField * ElementCODE_STROB)=0;

   __property TFIBWideStringField * ElementGID_SSTROB = {read = get_ElementGID_SSTROB , write = set_ElementGID_SSTROB};
   virtual TFIBWideStringField * get_ElementGID_SSTROB(void)=0;
   virtual void set_ElementGID_SSTROB(TFIBWideStringField * ElementGID_SSTROB)=0;

   __property __int64 Id = {read = get_Id , write = set_Id};
   virtual __int64 get_Id(void)=0;
   virtual void set_Id(__int64 Id)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(__int64 IdGrp)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual __int64 FindPoCodu(int code)=0;
};
#define IID_IDMSprStrObject __uuidof(IDMSprStrObject)
#endif
