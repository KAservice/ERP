#ifndef UIDMSprPropertiesNaborH
#define UIDMSprPropertiesNaborH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprPropertiesNabor)) IDMSprPropertiesNabor : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SPROPNABOR = {read = get_TableID_SPROPNABOR , write = set_TableID_SPROPNABOR};
   virtual TFIBLargeIntField * get_TableID_SPROPNABOR(void)=0;
   virtual void set_TableID_SPROPNABOR(TFIBLargeIntField * TableID_SPROPNABOR)=0;

   __property TFIBLargeIntField * TableIDBASE_SPROPNABOR = {read = get_TableIDBASE_SPROPNABOR , write = set_TableIDBASE_SPROPNABOR};
   virtual TFIBLargeIntField * get_TableIDBASE_SPROPNABOR(void)=0;
   virtual void set_TableIDBASE_SPROPNABOR(TFIBLargeIntField * TableIDBASE_SPROPNABOR)=0;

   __property TFIBWideStringField * TableGID_SPROPNABOR = {read = get_TableGID_SPROPNABOR , write = set_TableGID_SPROPNABOR};
   virtual TFIBWideStringField * get_TableGID_SPROPNABOR(void)=0;
   virtual void set_TableGID_SPROPNABOR(TFIBWideStringField * TableGID_SPROPNABOR)=0;

   __property TFIBLargeIntField * TableIDGRP_SPROPNABOR = {read = get_TableIDGRP_SPROPNABOR , write = set_TableIDGRP_SPROPNABOR};
   virtual TFIBLargeIntField * get_TableIDGRP_SPROPNABOR(void)=0;
   virtual void set_TableIDGRP_SPROPNABOR(TFIBLargeIntField * TableIDGRP_SPROPNABOR)=0;

   __property TFIBWideStringField * TableNAME_SPROPNABOR = {read = get_TableNAME_SPROPNABOR , write = set_TableNAME_SPROPNABOR};
   virtual TFIBWideStringField * get_TableNAME_SPROPNABOR(void)=0;
   virtual void set_TableNAME_SPROPNABOR(TFIBWideStringField * TableNAME_SPROPNABOR)=0;

   __property TFIBLargeIntField * ElementID_SPROPNABOR = {read = get_ElementID_SPROPNABOR , write = set_ElementID_SPROPNABOR};
   virtual TFIBLargeIntField * get_ElementID_SPROPNABOR(void)=0;
   virtual void set_ElementID_SPROPNABOR(TFIBLargeIntField * ElementID_SPROPNABOR)=0;

   __property TFIBLargeIntField * ElementIDBASE_SPROPNABOR = {read = get_ElementIDBASE_SPROPNABOR , write = set_ElementIDBASE_SPROPNABOR};
   virtual TFIBLargeIntField * get_ElementIDBASE_SPROPNABOR(void)=0;
   virtual void set_ElementIDBASE_SPROPNABOR(TFIBLargeIntField * ElementIDBASE_SPROPNABOR)=0;

   __property TFIBWideStringField * ElementGID_SPROPNABOR = {read = get_ElementGID_SPROPNABOR , write = set_ElementGID_SPROPNABOR};
   virtual TFIBWideStringField * get_ElementGID_SPROPNABOR(void)=0;
   virtual void set_ElementGID_SPROPNABOR(TFIBWideStringField * ElementGID_SPROPNABOR)=0;

   __property TFIBLargeIntField * ElementIDGRP_SPROPNABOR = {read = get_ElementIDGRP_SPROPNABOR , write = set_ElementIDGRP_SPROPNABOR};
   virtual TFIBLargeIntField * get_ElementIDGRP_SPROPNABOR(void)=0;
   virtual void set_ElementIDGRP_SPROPNABOR(TFIBLargeIntField * ElementIDGRP_SPROPNABOR)=0;

   __property TFIBWideStringField * ElementNAME_SPROPNABOR = {read = get_ElementNAME_SPROPNABOR , write = set_ElementNAME_SPROPNABOR};
   virtual TFIBWideStringField * get_ElementNAME_SPROPNABOR(void)=0;
   virtual void set_ElementNAME_SPROPNABOR(TFIBWideStringField * ElementNAME_SPROPNABOR)=0;

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
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_element)=0;
   virtual __int64 FindPoName(UnicodeString name)=0;
   virtual __int64 GetIdGrp(__int64 id_el)=0;
};
#define IID_IDMSprPropertiesNabor __uuidof(IDMSprPropertiesNabor)
#endif
