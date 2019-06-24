#ifndef UIDMSprBusinessOperH
#define UIDMSprBusinessOperH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprBusinessOper)) IDMSprBusinessOper : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SBUSINESS_OPER = {read = get_TableID_SBUSINESS_OPER , write = set_TableID_SBUSINESS_OPER};
   virtual TFIBLargeIntField * get_TableID_SBUSINESS_OPER(void)=0;
   virtual void set_TableID_SBUSINESS_OPER(TFIBLargeIntField * TableID_SBUSINESS_OPER)=0;

   __property TFIBWideStringField * TableGID_SBUSINESS_OPER = {read = get_TableGID_SBUSINESS_OPER , write = set_TableGID_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_TableGID_SBUSINESS_OPER(void)=0;
   virtual void set_TableGID_SBUSINESS_OPER(TFIBWideStringField * TableGID_SBUSINESS_OPER)=0;

   __property TFIBLargeIntField * TableIDBASE_SBUSINESS_OPER = {read = get_TableIDBASE_SBUSINESS_OPER , write = set_TableIDBASE_SBUSINESS_OPER};
   virtual TFIBLargeIntField * get_TableIDBASE_SBUSINESS_OPER(void)=0;
   virtual void set_TableIDBASE_SBUSINESS_OPER(TFIBLargeIntField * TableIDBASE_SBUSINESS_OPER)=0;

   __property TFIBWideStringField * TableNAME_SBUSINESS_OPER = {read = get_TableNAME_SBUSINESS_OPER , write = set_TableNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_TableNAME_SBUSINESS_OPER(void)=0;
   virtual void set_TableNAME_SBUSINESS_OPER(TFIBWideStringField * TableNAME_SBUSINESS_OPER)=0;

   __property TFIBLargeIntField * TableIDGRP_SBUSINESS_OPER = {read = get_TableIDGRP_SBUSINESS_OPER , write = set_TableIDGRP_SBUSINESS_OPER};
   virtual TFIBLargeIntField * get_TableIDGRP_SBUSINESS_OPER(void)=0;
   virtual void set_TableIDGRP_SBUSINESS_OPER(TFIBLargeIntField * TableIDGRP_SBUSINESS_OPER)=0;

   __property TFIBLargeIntField * ElementID_SBUSINESS_OPER = {read = get_ElementID_SBUSINESS_OPER , write = set_ElementID_SBUSINESS_OPER};
   virtual TFIBLargeIntField * get_ElementID_SBUSINESS_OPER(void)=0;
   virtual void set_ElementID_SBUSINESS_OPER(TFIBLargeIntField * ElementID_SBUSINESS_OPER)=0;

   __property TFIBWideStringField * ElementGID_SBUSINESS_OPER = {read = get_ElementGID_SBUSINESS_OPER , write = set_ElementGID_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_ElementGID_SBUSINESS_OPER(void)=0;
   virtual void set_ElementGID_SBUSINESS_OPER(TFIBWideStringField * ElementGID_SBUSINESS_OPER)=0;

   __property TFIBLargeIntField * ElementIDBASE_SBUSINESS_OPER = {read = get_ElementIDBASE_SBUSINESS_OPER , write = set_ElementIDBASE_SBUSINESS_OPER};
   virtual TFIBLargeIntField * get_ElementIDBASE_SBUSINESS_OPER(void)=0;
   virtual void set_ElementIDBASE_SBUSINESS_OPER(TFIBLargeIntField * ElementIDBASE_SBUSINESS_OPER)=0;

   __property TFIBWideStringField * ElementNAME_SBUSINESS_OPER = {read = get_ElementNAME_SBUSINESS_OPER , write = set_ElementNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_ElementNAME_SBUSINESS_OPER(void)=0;
   virtual void set_ElementNAME_SBUSINESS_OPER(TFIBWideStringField * ElementNAME_SBUSINESS_OPER)=0;

   __property TFIBLargeIntField * ElementIDGRP_SBUSINESS_OPER = {read = get_ElementIDGRP_SBUSINESS_OPER , write = set_ElementIDGRP_SBUSINESS_OPER};
   virtual TFIBLargeIntField * get_ElementIDGRP_SBUSINESS_OPER(void)=0;
   virtual void set_ElementIDGRP_SBUSINESS_OPER(TFIBLargeIntField * ElementIDGRP_SBUSINESS_OPER)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_grp, bool all)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void ChancheGrp(__int64 new_id_grp)=0;
   virtual __int64 GetIdPoName(UnicodeString name)=0;
   virtual __int64 GetIdGrpBusinessOper(__int64 id_bo)=0;
};
#define IID_IDMSprBusinessOper __uuidof(IDMSprBusinessOper)
#endif
