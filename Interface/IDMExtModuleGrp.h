#ifndef UIDMExtModuleGrpH
#define UIDMExtModuleGrpH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{9973C71D-3B85-4248-904F-EFD1608FA318}")) IDMExtModuleGrp : public IMainInterface
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

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * TableID_EXT_MODULE_GRP = {read = get_TableID_EXT_MODULE_GRP , write = set_TableID_EXT_MODULE_GRP};
   virtual TFIBBCDField * get_TableID_EXT_MODULE_GRP(void)=0;
   virtual void set_TableID_EXT_MODULE_GRP(TFIBBCDField * TableID_EXT_MODULE_GRP)=0;

   __property TFIBBCDField * TableIDGRP_EXT_MODULE_GRP = {read = get_TableIDGRP_EXT_MODULE_GRP , write = set_TableIDGRP_EXT_MODULE_GRP};
   virtual TFIBBCDField * get_TableIDGRP_EXT_MODULE_GRP(void)=0;
   virtual void set_TableIDGRP_EXT_MODULE_GRP(TFIBBCDField * TableIDGRP_EXT_MODULE_GRP)=0;

   __property TFIBBCDField * ElementID_EXT_MODULE_GRP = {read = get_ElementID_EXT_MODULE_GRP , write = set_ElementID_EXT_MODULE_GRP};
   virtual TFIBBCDField * get_ElementID_EXT_MODULE_GRP(void)=0;
   virtual void set_ElementID_EXT_MODULE_GRP(TFIBBCDField * ElementID_EXT_MODULE_GRP)=0;

   __property TFIBBCDField * ElementIDGRP_EXT_MODULE_GRP = {read = get_ElementIDGRP_EXT_MODULE_GRP , write = set_ElementIDGRP_EXT_MODULE_GRP};
   virtual TFIBBCDField * get_ElementIDGRP_EXT_MODULE_GRP(void)=0;
   virtual void set_ElementIDGRP_EXT_MODULE_GRP(TFIBBCDField * ElementIDGRP_EXT_MODULE_GRP)=0;

   __property TFIBWideStringField * TableNAME_EXT_MODULE_GRP = {read = get_TableNAME_EXT_MODULE_GRP , write = set_TableNAME_EXT_MODULE_GRP};
   virtual TFIBWideStringField * get_TableNAME_EXT_MODULE_GRP(void)=0;
   virtual void set_TableNAME_EXT_MODULE_GRP(TFIBWideStringField * TableNAME_EXT_MODULE_GRP)=0;

   __property TFIBWideStringField * ElementNAME_EXT_MODULE_GRP = {read = get_ElementNAME_EXT_MODULE_GRP , write = set_ElementNAME_EXT_MODULE_GRP};
   virtual TFIBWideStringField * get_ElementNAME_EXT_MODULE_GRP(void)=0;
   virtual void set_ElementNAME_EXT_MODULE_GRP(TFIBWideStringField * ElementNAME_EXT_MODULE_GRP)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 FindPoName(AnsiString name)=0;
};
#define IID_IDMExtModuleGrp __uuidof(IDMExtModuleGrp)
#endif
