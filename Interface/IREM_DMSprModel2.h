#ifndef UIREM_DMSprModel2H
#define UIREM_DMSprModel2H
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprModel2)) IREM_DMSprModel2 : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourcePodr = {read = get_DataSourcePodr , write = set_DataSourcePodr};
   virtual TDataSource * get_DataSourcePodr(void)=0;
   virtual void set_DataSourcePodr(TDataSource * DataSourcePodr)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TFIBLargeIntField * TableID_REM_SMODEL2 = {read = get_TableID_REM_SMODEL2 , write = set_TableID_REM_SMODEL2};
   virtual TFIBLargeIntField * get_TableID_REM_SMODEL2(void)=0;
   virtual void set_TableID_REM_SMODEL2(TFIBLargeIntField * TableID_REM_SMODEL2)=0;

   __property TFIBWideStringField * TableGID_REM_SMODEL2 = {read = get_TableGID_REM_SMODEL2 , write = set_TableGID_REM_SMODEL2};
   virtual TFIBWideStringField * get_TableGID_REM_SMODEL2(void)=0;
   virtual void set_TableGID_REM_SMODEL2(TFIBWideStringField * TableGID_REM_SMODEL2)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SMODEL2 = {read = get_TableIDBASE_REM_SMODEL2 , write = set_TableIDBASE_REM_SMODEL2};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SMODEL2(void)=0;
   virtual void set_TableIDBASE_REM_SMODEL2(TFIBLargeIntField * TableIDBASE_REM_SMODEL2)=0;

   __property TFIBWideStringField * TableNAME_REM_SMODEL2 = {read = get_TableNAME_REM_SMODEL2 , write = set_TableNAME_REM_SMODEL2};
   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL2(void)=0;
   virtual void set_TableNAME_REM_SMODEL2(TFIBWideStringField * TableNAME_REM_SMODEL2)=0;

   __property TFIBLargeIntField * TableIDTYPEDEV_REM_SMODEL2 = {read = get_TableIDTYPEDEV_REM_SMODEL2 , write = set_TableIDTYPEDEV_REM_SMODEL2};
   virtual TFIBLargeIntField * get_TableIDTYPEDEV_REM_SMODEL2(void)=0;
   virtual void set_TableIDTYPEDEV_REM_SMODEL2(TFIBLargeIntField * TableIDTYPEDEV_REM_SMODEL2)=0;

   __property TFIBLargeIntField * TableIDMODEL_REM_SMODEL2 = {read = get_TableIDMODEL_REM_SMODEL2 , write = set_TableIDMODEL_REM_SMODEL2};
   virtual TFIBLargeIntField * get_TableIDMODEL_REM_SMODEL2(void)=0;
   virtual void set_TableIDMODEL_REM_SMODEL2(TFIBLargeIntField * TableIDMODEL_REM_SMODEL2)=0;

   __property TFIBLargeIntField * TableIDGRP_REM_SMODEL2 = {read = get_TableIDGRP_REM_SMODEL2 , write = set_TableIDGRP_REM_SMODEL2};
   virtual TFIBLargeIntField * get_TableIDGRP_REM_SMODEL2(void)=0;
   virtual void set_TableIDGRP_REM_SMODEL2(TFIBLargeIntField * TableIDGRP_REM_SMODEL2)=0;

   __property TFIBWideStringField * TableSTRCODE_REM_SMODEL = {read = get_TableSTRCODE_REM_SMODEL , write = set_TableSTRCODE_REM_SMODEL};
   virtual TFIBWideStringField * get_TableSTRCODE_REM_SMODEL(void)=0;
   virtual void set_TableSTRCODE_REM_SMODEL(TFIBWideStringField * TableSTRCODE_REM_SMODEL)=0;

   __property TFIBWideStringField * TableNAME_REM_SMODEL = {read = get_TableNAME_REM_SMODEL , write = set_TableNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void)=0;
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)=0;

   __property TFIBLargeIntField * ElementID_REM_SMODEL2 = {read = get_ElementID_REM_SMODEL2 , write = set_ElementID_REM_SMODEL2};
   virtual TFIBLargeIntField * get_ElementID_REM_SMODEL2(void)=0;
   virtual void set_ElementID_REM_SMODEL2(TFIBLargeIntField * ElementID_REM_SMODEL2)=0;

   __property TFIBWideStringField * ElementGID_REM_SMODEL2 = {read = get_ElementGID_REM_SMODEL2 , write = set_ElementGID_REM_SMODEL2};
   virtual TFIBWideStringField * get_ElementGID_REM_SMODEL2(void)=0;
   virtual void set_ElementGID_REM_SMODEL2(TFIBWideStringField * ElementGID_REM_SMODEL2)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SMODEL2 = {read = get_ElementIDBASE_REM_SMODEL2 , write = set_ElementIDBASE_REM_SMODEL2};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SMODEL2(void)=0;
   virtual void set_ElementIDBASE_REM_SMODEL2(TFIBLargeIntField * ElementIDBASE_REM_SMODEL2)=0;

   __property TFIBWideStringField * ElementNAME_REM_SMODEL2 = {read = get_ElementNAME_REM_SMODEL2 , write = set_ElementNAME_REM_SMODEL2};
   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL2(void)=0;
   virtual void set_ElementNAME_REM_SMODEL2(TFIBWideStringField * ElementNAME_REM_SMODEL2)=0;

   __property TFIBLargeIntField * ElementIDTYPEDEV_REM_SMODEL2 = {read = get_ElementIDTYPEDEV_REM_SMODEL2 , write = set_ElementIDTYPEDEV_REM_SMODEL2};
   virtual TFIBLargeIntField * get_ElementIDTYPEDEV_REM_SMODEL2(void)=0;
   virtual void set_ElementIDTYPEDEV_REM_SMODEL2(TFIBLargeIntField * ElementIDTYPEDEV_REM_SMODEL2)=0;

   __property TFIBLargeIntField * ElementIDMODEL_REM_SMODEL2 = {read = get_ElementIDMODEL_REM_SMODEL2 , write = set_ElementIDMODEL_REM_SMODEL2};
   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SMODEL2(void)=0;
   virtual void set_ElementIDMODEL_REM_SMODEL2(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL2)=0;

   __property TFIBLargeIntField * ElementIDGRP_REM_SMODEL2 = {read = get_ElementIDGRP_REM_SMODEL2 , write = set_ElementIDGRP_REM_SMODEL2};
   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SMODEL2(void)=0;
   virtual void set_ElementIDGRP_REM_SMODEL2(TFIBLargeIntField * ElementIDGRP_REM_SMODEL2)=0;

   __property TFIBWideStringField * ElementSTRCODE_REM_SMODEL = {read = get_ElementSTRCODE_REM_SMODEL , write = set_ElementSTRCODE_REM_SMODEL};
   virtual TFIBWideStringField * get_ElementSTRCODE_REM_SMODEL(void)=0;
   virtual void set_ElementSTRCODE_REM_SMODEL(TFIBWideStringField * ElementSTRCODE_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementNAME_REM_SMODEL = {read = get_ElementNAME_REM_SMODEL , write = set_ElementNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL(void)=0;
   virtual void set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL)=0;

   __property __int64 IdGroupElement = {read = get_IdGroupElement , write = set_IdGroupElement};
   virtual __int64 get_IdGroupElement(void)=0;
   virtual void set_IdGroupElement(__int64 IdGroupElement)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual bool NewElement(__int64 id_group_element, __int64 id_grp)=0;
   virtual bool InsertElement(__int64 id_group_element, __int64 id_grp, __int64 id_model)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool SaveElement(void)=0;
   virtual bool ChancheGrp(__int64 id_new_grp,__int64 id_element)=0;
   virtual bool OpenTable(__int64 id_group_element, __int64 id_grp, bool all)=0;
   virtual bool TableSaveIsmen(void)=0;
   virtual bool TableCancelIsmen(void)=0;
   virtual bool TableNewElement(__int64 id_group_element, __int64 id_grp)=0;
   virtual bool TableAppend(void)=0;
   virtual bool TableDelete(void)=0;
   virtual bool TableEdit(void)=0;
   virtual bool TablePost(void)=0;
};
#define IID_IREM_DMSprModel2 __uuidof(IREM_DMSprModel2)
#endif
