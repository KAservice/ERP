#ifndef UIDMObjectBaseGrpH
#define UIDMObjectBaseGrpH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IDMObjectBaseGrp)) IDMObjectBaseGrp : public IMainInterface
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

   __property TFIBLargeIntField * TableID_OBJECT_BASE_GRP = {read = get_TableID_OBJECT_BASE_GRP , write = set_TableID_OBJECT_BASE_GRP};
   virtual TFIBLargeIntField * get_TableID_OBJECT_BASE_GRP(void)=0;
   virtual void set_TableID_OBJECT_BASE_GRP(TFIBLargeIntField * TableID_OBJECT_BASE_GRP)=0;

   __property TFIBLargeIntField * TableIDBASE_OBJECT_BASE_GRP = {read = get_TableIDBASE_OBJECT_BASE_GRP , write = set_TableIDBASE_OBJECT_BASE_GRP};
   virtual TFIBLargeIntField * get_TableIDBASE_OBJECT_BASE_GRP(void)=0;
   virtual void set_TableIDBASE_OBJECT_BASE_GRP(TFIBLargeIntField * TableIDBASE_OBJECT_BASE_GRP)=0;

   __property TFIBWideStringField * TableNAME_OBJECT_BASE_GRP = {read = get_TableNAME_OBJECT_BASE_GRP , write = set_TableNAME_OBJECT_BASE_GRP};
   virtual TFIBWideStringField * get_TableNAME_OBJECT_BASE_GRP(void)=0;
   virtual void set_TableNAME_OBJECT_BASE_GRP(TFIBWideStringField * TableNAME_OBJECT_BASE_GRP)=0;

   __property TFIBLargeIntField * TableIDGRP_OBJECT_BASE_GRP = {read = get_TableIDGRP_OBJECT_BASE_GRP , write = set_TableIDGRP_OBJECT_BASE_GRP};
   virtual TFIBLargeIntField * get_TableIDGRP_OBJECT_BASE_GRP(void)=0;
   virtual void set_TableIDGRP_OBJECT_BASE_GRP(TFIBLargeIntField * TableIDGRP_OBJECT_BASE_GRP)=0;

   __property TFIBLargeIntField * ElementID_OBJECT_BASE_GRP = {read = get_ElementID_OBJECT_BASE_GRP , write = set_ElementID_OBJECT_BASE_GRP};
   virtual TFIBLargeIntField * get_ElementID_OBJECT_BASE_GRP(void)=0;
   virtual void set_ElementID_OBJECT_BASE_GRP(TFIBLargeIntField * ElementID_OBJECT_BASE_GRP)=0;

   __property TFIBLargeIntField * ElementIDBASE_OBJECT_BASE_GRP = {read = get_ElementIDBASE_OBJECT_BASE_GRP , write = set_ElementIDBASE_OBJECT_BASE_GRP};
   virtual TFIBLargeIntField * get_ElementIDBASE_OBJECT_BASE_GRP(void)=0;
   virtual void set_ElementIDBASE_OBJECT_BASE_GRP(TFIBLargeIntField * ElementIDBASE_OBJECT_BASE_GRP)=0;

   __property TFIBWideStringField * ElementNAME_OBJECT_BASE_GRP = {read = get_ElementNAME_OBJECT_BASE_GRP , write = set_ElementNAME_OBJECT_BASE_GRP};
   virtual TFIBWideStringField * get_ElementNAME_OBJECT_BASE_GRP(void)=0;
   virtual void set_ElementNAME_OBJECT_BASE_GRP(TFIBWideStringField * ElementNAME_OBJECT_BASE_GRP)=0;

   __property TFIBLargeIntField * ElementIDGRP_OBJECT_BASE_GRP = {read = get_ElementIDGRP_OBJECT_BASE_GRP , write = set_ElementIDGRP_OBJECT_BASE_GRP};
   virtual TFIBLargeIntField * get_ElementIDGRP_OBJECT_BASE_GRP(void)=0;
   virtual void set_ElementIDGRP_OBJECT_BASE_GRP(TFIBLargeIntField * ElementIDGRP_OBJECT_BASE_GRP)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   virtual void OpenTable(void)=0;
   virtual void Table_First(void)=0;
   virtual void Table_Next(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement( __int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void Element_Edit(void)=0;
   virtual void Element_Post(void)=0;
};
#define IID_IDMObjectBaseGrp __uuidof(IDMObjectBaseGrp)
#endif
