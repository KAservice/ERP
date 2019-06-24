#ifndef UIDMSprVidImageH
#define UIDMSprVidImageH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprVidImage)) IDMSprVidImage : public IMainInterface
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

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBLargeIntField * TableID_SVIDIMAGE = {read = get_TableID_SVIDIMAGE , write = set_TableID_SVIDIMAGE};
   virtual TFIBLargeIntField * get_TableID_SVIDIMAGE(void)=0;
   virtual void set_TableID_SVIDIMAGE(TFIBLargeIntField * TableID_SVIDIMAGE)=0;

   __property TFIBLargeIntField * TableIDBASE_SVIDIMAGE = {read = get_TableIDBASE_SVIDIMAGE , write = set_TableIDBASE_SVIDIMAGE};
   virtual TFIBLargeIntField * get_TableIDBASE_SVIDIMAGE(void)=0;
   virtual void set_TableIDBASE_SVIDIMAGE(TFIBLargeIntField * TableIDBASE_SVIDIMAGE)=0;

   __property TFIBWideStringField * TableGID_SVIDIMAGE = {read = get_TableGID_SVIDIMAGE , write = set_TableGID_SVIDIMAGE};
   virtual TFIBWideStringField * get_TableGID_SVIDIMAGE(void)=0;
   virtual void set_TableGID_SVIDIMAGE(TFIBWideStringField * TableGID_SVIDIMAGE)=0;

   __property TFIBLargeIntField * TableIDGRP_SVIDIMAGE = {read = get_TableIDGRP_SVIDIMAGE , write = set_TableIDGRP_SVIDIMAGE};
   virtual TFIBLargeIntField * get_TableIDGRP_SVIDIMAGE(void)=0;
   virtual void set_TableIDGRP_SVIDIMAGE(TFIBLargeIntField * TableIDGRP_SVIDIMAGE)=0;

   __property TFIBWideStringField * TableNAME_SVIDIMAGE = {read = get_TableNAME_SVIDIMAGE , write = set_TableNAME_SVIDIMAGE};
   virtual TFIBWideStringField * get_TableNAME_SVIDIMAGE(void)=0;
   virtual void set_TableNAME_SVIDIMAGE(TFIBWideStringField * TableNAME_SVIDIMAGE)=0;

   __property TFIBLargeIntField * ElementID_SVIDIMAGE = {read = get_ElementID_SVIDIMAGE , write = set_ElementID_SVIDIMAGE};
   virtual TFIBLargeIntField * get_ElementID_SVIDIMAGE(void)=0;
   virtual void set_ElementID_SVIDIMAGE(TFIBLargeIntField * ElementID_SVIDIMAGE)=0;

   __property TFIBLargeIntField * ElementIDBASE_SVIDIMAGE = {read = get_ElementIDBASE_SVIDIMAGE , write = set_ElementIDBASE_SVIDIMAGE};
   virtual TFIBLargeIntField * get_ElementIDBASE_SVIDIMAGE(void)=0;
   virtual void set_ElementIDBASE_SVIDIMAGE(TFIBLargeIntField * ElementIDBASE_SVIDIMAGE)=0;

   __property TFIBWideStringField * ElementGID_SVIDIMAGE = {read = get_ElementGID_SVIDIMAGE , write = set_ElementGID_SVIDIMAGE};
   virtual TFIBWideStringField * get_ElementGID_SVIDIMAGE(void)=0;
   virtual void set_ElementGID_SVIDIMAGE(TFIBWideStringField * ElementGID_SVIDIMAGE)=0;

   __property TFIBLargeIntField * ElementIDGRP_SVIDIMAGE = {read = get_ElementIDGRP_SVIDIMAGE , write = set_ElementIDGRP_SVIDIMAGE};
   virtual TFIBLargeIntField * get_ElementIDGRP_SVIDIMAGE(void)=0;
   virtual void set_ElementIDGRP_SVIDIMAGE(TFIBLargeIntField * ElementIDGRP_SVIDIMAGE)=0;

   __property TFIBWideStringField * ElementNAME_SVIDIMAGE = {read = get_ElementNAME_SVIDIMAGE , write = set_ElementNAME_SVIDIMAGE};
   virtual TFIBWideStringField * get_ElementNAME_SVIDIMAGE(void)=0;
   virtual void set_ElementNAME_SVIDIMAGE(TFIBWideStringField * ElementNAME_SVIDIMAGE)=0;

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
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_prop)=0;
   virtual __int64 FindPoName(UnicodeString name)=0;
   virtual __int64 GetIdGrp(__int64 id_el)=0;
};
#define IID_IDMSprVidImage __uuidof(IDMSprVidImage)
#endif
