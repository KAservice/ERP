#ifndef UIDMSprInfBaseH
#define UIDMSprInfBaseH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprInfBase)) IDMSprInfBase : public IMainInterface
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

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * TableID_SINFBASE_OBMEN = {read = get_TableID_SINFBASE_OBMEN , write = set_TableID_SINFBASE_OBMEN};
   virtual TFIBBCDField * get_TableID_SINFBASE_OBMEN(void)=0;
   virtual void set_TableID_SINFBASE_OBMEN(TFIBBCDField * TableID_SINFBASE_OBMEN)=0;

   __property TFIBIntegerField * TableIDTIZM_SINFBASE_OBMEN = {read = get_TableIDTIZM_SINFBASE_OBMEN , write = set_TableIDTIZM_SINFBASE_OBMEN};
   virtual TFIBIntegerField * get_TableIDTIZM_SINFBASE_OBMEN(void)=0;
   virtual void set_TableIDTIZM_SINFBASE_OBMEN(TFIBIntegerField * TableIDTIZM_SINFBASE_OBMEN)=0;

   __property TFIBBCDField * ElementID_SINFBASE_OBMEN = {read = get_ElementID_SINFBASE_OBMEN , write = set_ElementID_SINFBASE_OBMEN};
   virtual TFIBBCDField * get_ElementID_SINFBASE_OBMEN(void)=0;
   virtual void set_ElementID_SINFBASE_OBMEN(TFIBBCDField * ElementID_SINFBASE_OBMEN)=0;

   __property TFIBIntegerField * ElementIDTIZM_SINFBASE_OBMEN = {read = get_ElementIDTIZM_SINFBASE_OBMEN , write = set_ElementIDTIZM_SINFBASE_OBMEN};
   virtual TFIBIntegerField * get_ElementIDTIZM_SINFBASE_OBMEN(void)=0;
   virtual void set_ElementIDTIZM_SINFBASE_OBMEN(TFIBIntegerField * ElementIDTIZM_SINFBASE_OBMEN)=0;

   __property TFIBSmallIntField * ElementNOACT_SINFBASE_OBMEN = {read = get_ElementNOACT_SINFBASE_OBMEN , write = set_ElementNOACT_SINFBASE_OBMEN};
   virtual TFIBSmallIntField * get_ElementNOACT_SINFBASE_OBMEN(void)=0;
   virtual void set_ElementNOACT_SINFBASE_OBMEN(TFIBSmallIntField * ElementNOACT_SINFBASE_OBMEN)=0;

   __property TFIBSmallIntField * TableNOACT_SINFBASE_OBMEN = {read = get_TableNOACT_SINFBASE_OBMEN , write = set_TableNOACT_SINFBASE_OBMEN};
   virtual TFIBSmallIntField * get_TableNOACT_SINFBASE_OBMEN(void)=0;
   virtual void set_TableNOACT_SINFBASE_OBMEN(TFIBSmallIntField * TableNOACT_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * TableGID_SINFBASE_OBMEN = {read = get_TableGID_SINFBASE_OBMEN , write = set_TableGID_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_TableGID_SINFBASE_OBMEN(void)=0;
   virtual void set_TableGID_SINFBASE_OBMEN(TFIBWideStringField * TableGID_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * TableNAME_SINFBASE_OBMEN = {read = get_TableNAME_SINFBASE_OBMEN , write = set_TableNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * ElementGID_SINFBASE_OBMEN = {read = get_ElementGID_SINFBASE_OBMEN , write = set_ElementGID_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_ElementGID_SINFBASE_OBMEN(void)=0;
   virtual void set_ElementGID_SINFBASE_OBMEN(TFIBWideStringField * ElementGID_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * ElementNAME_SINFBASE_OBMEN = {read = get_ElementNAME_SINFBASE_OBMEN , write = set_ElementNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_ElementNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * ElementPREF_NUM_SINFBASE_OBMEN = {read = get_ElementPREF_NUM_SINFBASE_OBMEN , write = set_ElementPREF_NUM_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_ElementPREF_NUM_SINFBASE_OBMEN(void)=0;
   virtual void set_ElementPREF_NUM_SINFBASE_OBMEN(TFIBWideStringField * ElementPREF_NUM_SINFBASE_OBMEN)=0;

   virtual __int64 GetIdPoPrefiks(AnsiString prefiks)=0;
   virtual __int64 GetIdPoName(AnsiString name)=0;
   virtual void OpenTable(void)=0;
   virtual int  OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
};
#define IID_IDMSprInfBase __uuidof(IDMSprInfBase)
#endif
