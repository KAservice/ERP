#ifndef UIDMSprGrpBusinessOperH
#define UIDMSprGrpBusinessOperH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprGrpBusinessOper)) IDMSprGrpBusinessOper : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SBUSINESS_OPER_GRP = {read = get_TableID_SBUSINESS_OPER_GRP , write = set_TableID_SBUSINESS_OPER_GRP};
   virtual TFIBLargeIntField * get_TableID_SBUSINESS_OPER_GRP(void)=0;
   virtual void set_TableID_SBUSINESS_OPER_GRP(TFIBLargeIntField * TableID_SBUSINESS_OPER_GRP)=0;

   __property TFIBWideStringField * TableGID_SBUSINESS_OPER_GRP = {read = get_TableGID_SBUSINESS_OPER_GRP , write = set_TableGID_SBUSINESS_OPER_GRP};
   virtual TFIBWideStringField * get_TableGID_SBUSINESS_OPER_GRP(void)=0;
   virtual void set_TableGID_SBUSINESS_OPER_GRP(TFIBWideStringField * TableGID_SBUSINESS_OPER_GRP)=0;

   __property TFIBLargeIntField * TableIDBASE_SBUSINESS_OPER_GRP = {read = get_TableIDBASE_SBUSINESS_OPER_GRP , write = set_TableIDBASE_SBUSINESS_OPER_GRP};
   virtual TFIBLargeIntField * get_TableIDBASE_SBUSINESS_OPER_GRP(void)=0;
   virtual void set_TableIDBASE_SBUSINESS_OPER_GRP(TFIBLargeIntField * TableIDBASE_SBUSINESS_OPER_GRP)=0;

   __property TFIBLargeIntField * TableIDGRP_SBUSINESS_OPER_GRP = {read = get_TableIDGRP_SBUSINESS_OPER_GRP , write = set_TableIDGRP_SBUSINESS_OPER_GRP};
   virtual TFIBLargeIntField * get_TableIDGRP_SBUSINESS_OPER_GRP(void)=0;
   virtual void set_TableIDGRP_SBUSINESS_OPER_GRP(TFIBLargeIntField * TableIDGRP_SBUSINESS_OPER_GRP)=0;

   __property TFIBWideStringField * TableNAME_SBUSINESS_OPER_GRP = {read = get_TableNAME_SBUSINESS_OPER_GRP , write = set_TableNAME_SBUSINESS_OPER_GRP};
   virtual TFIBWideStringField * get_TableNAME_SBUSINESS_OPER_GRP(void)=0;
   virtual void set_TableNAME_SBUSINESS_OPER_GRP(TFIBWideStringField * TableNAME_SBUSINESS_OPER_GRP)=0;

   __property TFIBLargeIntField * ElementID_SBUSINESS_OPER_GRP = {read = get_ElementID_SBUSINESS_OPER_GRP , write = set_ElementID_SBUSINESS_OPER_GRP};
   virtual TFIBLargeIntField * get_ElementID_SBUSINESS_OPER_GRP(void)=0;
   virtual void set_ElementID_SBUSINESS_OPER_GRP(TFIBLargeIntField * ElementID_SBUSINESS_OPER_GRP)=0;

   __property TFIBWideStringField * ElementGID_SBUSINESS_OPER_GRP = {read = get_ElementGID_SBUSINESS_OPER_GRP , write = set_ElementGID_SBUSINESS_OPER_GRP};
   virtual TFIBWideStringField * get_ElementGID_SBUSINESS_OPER_GRP(void)=0;
   virtual void set_ElementGID_SBUSINESS_OPER_GRP(TFIBWideStringField * ElementGID_SBUSINESS_OPER_GRP)=0;

   __property TFIBLargeIntField * ElementIDBASE_SBUSINESS_OPER_GRP = {read = get_ElementIDBASE_SBUSINESS_OPER_GRP , write = set_ElementIDBASE_SBUSINESS_OPER_GRP};
   virtual TFIBLargeIntField * get_ElementIDBASE_SBUSINESS_OPER_GRP(void)=0;
   virtual void set_ElementIDBASE_SBUSINESS_OPER_GRP(TFIBLargeIntField * ElementIDBASE_SBUSINESS_OPER_GRP)=0;

   __property TFIBLargeIntField * ElementIDGRP_SBUSINESS_OPER_GRP = {read = get_ElementIDGRP_SBUSINESS_OPER_GRP , write = set_ElementIDGRP_SBUSINESS_OPER_GRP};
   virtual TFIBLargeIntField * get_ElementIDGRP_SBUSINESS_OPER_GRP(void)=0;
   virtual void set_ElementIDGRP_SBUSINESS_OPER_GRP(TFIBLargeIntField * ElementIDGRP_SBUSINESS_OPER_GRP)=0;

   __property TFIBWideStringField * ElementNAME_SBUSINESS_OPER_GRP = {read = get_ElementNAME_SBUSINESS_OPER_GRP , write = set_ElementNAME_SBUSINESS_OPER_GRP};
   virtual TFIBWideStringField * get_ElementNAME_SBUSINESS_OPER_GRP(void)=0;
   virtual void set_ElementNAME_SBUSINESS_OPER_GRP(TFIBWideStringField * ElementNAME_SBUSINESS_OPER_GRP)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 GetIdPoName(UnicodeString name)=0;
};
#define IID_IDMSprGrpBusinessOper __uuidof(IDMSprGrpBusinessOper)
#endif
