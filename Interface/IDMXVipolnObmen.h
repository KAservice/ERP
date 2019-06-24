#ifndef UIDMXVipolnObmenH
#define UIDMXVipolnObmenH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMXVipolnObmen)) IDMXVipolnObmen : public IMainInterface
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

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBLargeIntField * TableID_XVIPOLN_OBMEN = {read = get_TableID_XVIPOLN_OBMEN , write = set_TableID_XVIPOLN_OBMEN};
   virtual TFIBLargeIntField * get_TableID_XVIPOLN_OBMEN(void)=0;
   virtual void set_TableID_XVIPOLN_OBMEN(TFIBLargeIntField * TableID_XVIPOLN_OBMEN)=0;

   __property TFIBLargeIntField * TableIDBASE_XVIPOLN_OBMEN = {read = get_TableIDBASE_XVIPOLN_OBMEN , write = set_TableIDBASE_XVIPOLN_OBMEN};
   virtual TFIBLargeIntField * get_TableIDBASE_XVIPOLN_OBMEN(void)=0;
   virtual void set_TableIDBASE_XVIPOLN_OBMEN(TFIBLargeIntField * TableIDBASE_XVIPOLN_OBMEN)=0;

   __property TFIBLargeIntField * TableIDINFBASE_XVIPOLN_OBMEN = {read = get_TableIDINFBASE_XVIPOLN_OBMEN , write = set_TableIDINFBASE_XVIPOLN_OBMEN};
   virtual TFIBLargeIntField * get_TableIDINFBASE_XVIPOLN_OBMEN(void)=0;
   virtual void set_TableIDINFBASE_XVIPOLN_OBMEN(TFIBLargeIntField * TableIDINFBASE_XVIPOLN_OBMEN)=0;

   __property TFIBDateTimeField * TablePOS_ZAGR_XVIPOLN_OBMEN = {read = get_TablePOS_ZAGR_XVIPOLN_OBMEN , write = set_TablePOS_ZAGR_XVIPOLN_OBMEN};
   virtual TFIBDateTimeField * get_TablePOS_ZAGR_XVIPOLN_OBMEN(void)=0;
   virtual void set_TablePOS_ZAGR_XVIPOLN_OBMEN(TFIBDateTimeField * TablePOS_ZAGR_XVIPOLN_OBMEN)=0;

   __property TFIBDateTimeField * TablePOS_VIGR_XVIPOLN_OBMEN = {read = get_TablePOS_VIGR_XVIPOLN_OBMEN , write = set_TablePOS_VIGR_XVIPOLN_OBMEN};
   virtual TFIBDateTimeField * get_TablePOS_VIGR_XVIPOLN_OBMEN(void)=0;
   virtual void set_TablePOS_VIGR_XVIPOLN_OBMEN(TFIBDateTimeField * TablePOS_VIGR_XVIPOLN_OBMEN)=0;

   __property TFIBWideStringField * TableNAME_SINFBASE_OBMEN = {read = get_TableNAME_SINFBASE_OBMEN , write = set_TableNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)=0;

   __property TFIBSmallIntField * TableNOACT_SINFBASE_OBMEN = {read = get_TableNOACT_SINFBASE_OBMEN , write = set_TableNOACT_SINFBASE_OBMEN};
   virtual TFIBSmallIntField * get_TableNOACT_SINFBASE_OBMEN(void)=0;
   virtual void set_TableNOACT_SINFBASE_OBMEN(TFIBSmallIntField * TableNOACT_SINFBASE_OBMEN)=0;

   __property TFIBLargeIntField * ElementID_XVIPOLN_OBMEN = {read = get_ElementID_XVIPOLN_OBMEN , write = set_ElementID_XVIPOLN_OBMEN};
   virtual TFIBLargeIntField * get_ElementID_XVIPOLN_OBMEN(void)=0;
   virtual void set_ElementID_XVIPOLN_OBMEN(TFIBLargeIntField * ElementID_XVIPOLN_OBMEN)=0;

   __property TFIBLargeIntField * ElementIDBASE_XVIPOLN_OBMEN = {read = get_ElementIDBASE_XVIPOLN_OBMEN , write = set_ElementIDBASE_XVIPOLN_OBMEN};
   virtual TFIBLargeIntField * get_ElementIDBASE_XVIPOLN_OBMEN(void)=0;
   virtual void set_ElementIDBASE_XVIPOLN_OBMEN(TFIBLargeIntField * ElementIDBASE_XVIPOLN_OBMEN)=0;

   __property TFIBLargeIntField * ElementIDINFBASE_XVIPOLN_OBMEN = {read = get_ElementIDINFBASE_XVIPOLN_OBMEN , write = set_ElementIDINFBASE_XVIPOLN_OBMEN};
   virtual TFIBLargeIntField * get_ElementIDINFBASE_XVIPOLN_OBMEN(void)=0;
   virtual void set_ElementIDINFBASE_XVIPOLN_OBMEN(TFIBLargeIntField * ElementIDINFBASE_XVIPOLN_OBMEN)=0;

   __property TFIBDateTimeField * ElementPOS_ZAGR_XVIPOLN_OBMEN = {read = get_ElementPOS_ZAGR_XVIPOLN_OBMEN , write = set_ElementPOS_ZAGR_XVIPOLN_OBMEN};
   virtual TFIBDateTimeField * get_ElementPOS_ZAGR_XVIPOLN_OBMEN(void)=0;
   virtual void set_ElementPOS_ZAGR_XVIPOLN_OBMEN(TFIBDateTimeField * ElementPOS_ZAGR_XVIPOLN_OBMEN)=0;

   __property TFIBDateTimeField * ElementPOS_VIGR_XVIPOLN_OBMEN = {read = get_ElementPOS_VIGR_XVIPOLN_OBMEN , write = set_ElementPOS_VIGR_XVIPOLN_OBMEN};
   virtual TFIBDateTimeField * get_ElementPOS_VIGR_XVIPOLN_OBMEN(void)=0;
   virtual void set_ElementPOS_VIGR_XVIPOLN_OBMEN(TFIBDateTimeField * ElementPOS_VIGR_XVIPOLN_OBMEN)=0;

   __property TFIBWideStringField * ElementNAME_SINFBASE_OBMEN = {read = get_ElementNAME_SINFBASE_OBMEN , write = set_ElementNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_ElementNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN)=0;

   __property TFIBSmallIntField * ElementNOACT_SINFBASE_OBMEN = {read = get_ElementNOACT_SINFBASE_OBMEN , write = set_ElementNOACT_SINFBASE_OBMEN};
   virtual TFIBSmallIntField * get_ElementNOACT_SINFBASE_OBMEN(void)=0;
   virtual void set_ElementNOACT_SINFBASE_OBMEN(TFIBSmallIntField * ElementNOACT_SINFBASE_OBMEN)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(void)=0;
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_element)=0;
   virtual __int64 FindPoName(UnicodeString name)=0;
   virtual __int64 FindPoIdBase(__int64 id_base)=0;
   virtual __int64 GetIdGrp(__int64 id_el)=0;
};
#define IID_IDMXVipolnObmen __uuidof(IDMXVipolnObmen)
#endif
