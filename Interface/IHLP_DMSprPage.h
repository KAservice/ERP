#ifndef UIHLP_DMSprPageH
#define UIHLP_DMSprPageH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IHLP_DMSprPage)) IHLP_DMSprPage : public IMainInterface
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

   __property TFIBLargeIntField * TableID_HLP_PAGE = {read = get_TableID_HLP_PAGE , write = set_TableID_HLP_PAGE};
   virtual TFIBLargeIntField * get_TableID_HLP_PAGE(void)=0;
   virtual void set_TableID_HLP_PAGE(TFIBLargeIntField * TableID_HLP_PAGE)=0;

   __property TFIBLargeIntField * TableIDBASE_HLP_PAGE = {read = get_TableIDBASE_HLP_PAGE , write = set_TableIDBASE_HLP_PAGE};
   virtual TFIBLargeIntField * get_TableIDBASE_HLP_PAGE(void)=0;
   virtual void set_TableIDBASE_HLP_PAGE(TFIBLargeIntField * TableIDBASE_HLP_PAGE)=0;

   __property TFIBWideStringField * TableGID_HLP_PAGE = {read = get_TableGID_HLP_PAGE , write = set_TableGID_HLP_PAGE};
   virtual TFIBWideStringField * get_TableGID_HLP_PAGE(void)=0;
   virtual void set_TableGID_HLP_PAGE(TFIBWideStringField * TableGID_HLP_PAGE)=0;

   __property TFIBLargeIntField * TableIDGRP_HLP_PAGE = {read = get_TableIDGRP_HLP_PAGE , write = set_TableIDGRP_HLP_PAGE};
   virtual TFIBLargeIntField * get_TableIDGRP_HLP_PAGE(void)=0;
   virtual void set_TableIDGRP_HLP_PAGE(TFIBLargeIntField * TableIDGRP_HLP_PAGE)=0;

   __property TFIBWideStringField * TableNAME_HLP_PAGE = {read = get_TableNAME_HLP_PAGE , write = set_TableNAME_HLP_PAGE};
   virtual TFIBWideStringField * get_TableNAME_HLP_PAGE(void)=0;
   virtual void set_TableNAME_HLP_PAGE(TFIBWideStringField * TableNAME_HLP_PAGE)=0;

   __property TFIBWideStringField * TableKEYWORDS_HLP_PAGE = {read = get_TableKEYWORDS_HLP_PAGE , write = set_TableKEYWORDS_HLP_PAGE};
   virtual TFIBWideStringField * get_TableKEYWORDS_HLP_PAGE(void)=0;
   virtual void set_TableKEYWORDS_HLP_PAGE(TFIBWideStringField * TableKEYWORDS_HLP_PAGE)=0;

   __property TFIBWideStringField * TableTITLE_HLP_PAGE = {read = get_TableTITLE_HLP_PAGE , write = set_TableTITLE_HLP_PAGE};
   virtual TFIBWideStringField * get_TableTITLE_HLP_PAGE(void)=0;
   virtual void set_TableTITLE_HLP_PAGE(TFIBWideStringField * TableTITLE_HLP_PAGE)=0;

   __property TFIBWideStringField * TableDESCR_HLP_PAGE = {read = get_TableDESCR_HLP_PAGE , write = set_TableDESCR_HLP_PAGE};
   virtual TFIBWideStringField * get_TableDESCR_HLP_PAGE(void)=0;
   virtual void set_TableDESCR_HLP_PAGE(TFIBWideStringField * TableDESCR_HLP_PAGE)=0;

   __property TFIBIntegerField * TableINDEX_HLP_PAGE = {read = get_TableINDEX_HLP_PAGE , write = set_TableINDEX_HLP_PAGE};
   virtual TFIBIntegerField * get_TableINDEX_HLP_PAGE(void)=0;
   virtual void set_TableINDEX_HLP_PAGE(TFIBIntegerField * TableINDEX_HLP_PAGE)=0;

   __property TFIBWideStringField * TableWEBKEYWORDS_HLP_PAGE = {read = get_TableWEBKEYWORDS_HLP_PAGE , write = set_TableWEBKEYWORDS_HLP_PAGE};
   virtual TFIBWideStringField * get_TableWEBKEYWORDS_HLP_PAGE(void)=0;
   virtual void set_TableWEBKEYWORDS_HLP_PAGE(TFIBWideStringField * TableWEBKEYWORDS_HLP_PAGE)=0;

   __property TFIBWideStringField * TableWEBTITLE_HLP_PAGE = {read = get_TableWEBTITLE_HLP_PAGE , write = set_TableWEBTITLE_HLP_PAGE};
   virtual TFIBWideStringField * get_TableWEBTITLE_HLP_PAGE(void)=0;
   virtual void set_TableWEBTITLE_HLP_PAGE(TFIBWideStringField * TableWEBTITLE_HLP_PAGE)=0;

   __property TFIBWideStringField * TableWEBDESCR_HLP_PAGE = {read = get_TableWEBDESCR_HLP_PAGE , write = set_TableWEBDESCR_HLP_PAGE};
   virtual TFIBWideStringField * get_TableWEBDESCR_HLP_PAGE(void)=0;
   virtual void set_TableWEBDESCR_HLP_PAGE(TFIBWideStringField * TableWEBDESCR_HLP_PAGE)=0;

   __property TFIBWideStringField * TableGUIDGRP_HLP_PAGE = {read = get_TableGUIDGRP_HLP_PAGE , write = set_TableGUIDGRP_HLP_PAGE};
   virtual TFIBWideStringField * get_TableGUIDGRP_HLP_PAGE(void)=0;
   virtual void set_TableGUIDGRP_HLP_PAGE(TFIBWideStringField * TableGUIDGRP_HLP_PAGE)=0;

   __property TFIBWideStringField * TableSTRCODE_HLP_PAGE = {read = get_TableSTRCODE_HLP_PAGE , write = set_TableSTRCODE_HLP_PAGE};
   virtual TFIBWideStringField * get_TableSTRCODE_HLP_PAGE(void)=0;
   virtual void set_TableSTRCODE_HLP_PAGE(TFIBWideStringField * TableSTRCODE_HLP_PAGE)=0;

   __property TFIBWideStringField * TableGUID_HLP_PAGE = {read = get_TableGUID_HLP_PAGE , write = set_TableGUID_HLP_PAGE};
   virtual TFIBWideStringField * get_TableGUID_HLP_PAGE(void)=0;
   virtual void set_TableGUID_HLP_PAGE(TFIBWideStringField * TableGUID_HLP_PAGE)=0;

   __property TFIBLargeIntField * ElementID_HLP_PAGE = {read = get_ElementID_HLP_PAGE , write = set_ElementID_HLP_PAGE};
   virtual TFIBLargeIntField * get_ElementID_HLP_PAGE(void)=0;
   virtual void set_ElementID_HLP_PAGE(TFIBLargeIntField * ElementID_HLP_PAGE)=0;

   __property TFIBLargeIntField * ElementIDBASE_HLP_PAGE = {read = get_ElementIDBASE_HLP_PAGE , write = set_ElementIDBASE_HLP_PAGE};
   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_PAGE(void)=0;
   virtual void set_ElementIDBASE_HLP_PAGE(TFIBLargeIntField * ElementIDBASE_HLP_PAGE)=0;

   __property TFIBWideStringField * ElementGID_HLP_PAGE = {read = get_ElementGID_HLP_PAGE , write = set_ElementGID_HLP_PAGE};
   virtual TFIBWideStringField * get_ElementGID_HLP_PAGE(void)=0;
   virtual void set_ElementGID_HLP_PAGE(TFIBWideStringField * ElementGID_HLP_PAGE)=0;

   __property TFIBLargeIntField * ElementIDGRP_HLP_PAGE = {read = get_ElementIDGRP_HLP_PAGE , write = set_ElementIDGRP_HLP_PAGE};
   virtual TFIBLargeIntField * get_ElementIDGRP_HLP_PAGE(void)=0;
   virtual void set_ElementIDGRP_HLP_PAGE(TFIBLargeIntField * ElementIDGRP_HLP_PAGE)=0;

   __property TFIBWideStringField * ElementNAME_HLP_PAGE = {read = get_ElementNAME_HLP_PAGE , write = set_ElementNAME_HLP_PAGE};
   virtual TFIBWideStringField * get_ElementNAME_HLP_PAGE(void)=0;
   virtual void set_ElementNAME_HLP_PAGE(TFIBWideStringField * ElementNAME_HLP_PAGE)=0;

   __property TFIBWideStringField * ElementKEYWORDS_HLP_PAGE = {read = get_ElementKEYWORDS_HLP_PAGE , write = set_ElementKEYWORDS_HLP_PAGE};
   virtual TFIBWideStringField * get_ElementKEYWORDS_HLP_PAGE(void)=0;
   virtual void set_ElementKEYWORDS_HLP_PAGE(TFIBWideStringField * ElementKEYWORDS_HLP_PAGE)=0;

   __property TFIBWideStringField * ElementTITLE_HLP_PAGE = {read = get_ElementTITLE_HLP_PAGE , write = set_ElementTITLE_HLP_PAGE};
   virtual TFIBWideStringField * get_ElementTITLE_HLP_PAGE(void)=0;
   virtual void set_ElementTITLE_HLP_PAGE(TFIBWideStringField * ElementTITLE_HLP_PAGE)=0;

   __property TFIBWideStringField * ElementDESCR_HLP_PAGE = {read = get_ElementDESCR_HLP_PAGE , write = set_ElementDESCR_HLP_PAGE};
   virtual TFIBWideStringField * get_ElementDESCR_HLP_PAGE(void)=0;
   virtual void set_ElementDESCR_HLP_PAGE(TFIBWideStringField * ElementDESCR_HLP_PAGE)=0;

   __property TFIBIntegerField * ElementINDEX_HLP_PAGE = {read = get_ElementINDEX_HLP_PAGE , write = set_ElementINDEX_HLP_PAGE};
   virtual TFIBIntegerField * get_ElementINDEX_HLP_PAGE(void)=0;
   virtual void set_ElementINDEX_HLP_PAGE(TFIBIntegerField * ElementINDEX_HLP_PAGE)=0;

   __property TFIBWideStringField * ElementWEBKEYWORDS_HLP_PAGE = {read = get_ElementWEBKEYWORDS_HLP_PAGE , write = set_ElementWEBKEYWORDS_HLP_PAGE};
   virtual TFIBWideStringField * get_ElementWEBKEYWORDS_HLP_PAGE(void)=0;
   virtual void set_ElementWEBKEYWORDS_HLP_PAGE(TFIBWideStringField * ElementWEBKEYWORDS_HLP_PAGE)=0;

   __property TFIBWideStringField * ElementWEBTITLE_HLP_PAGE = {read = get_ElementWEBTITLE_HLP_PAGE , write = set_ElementWEBTITLE_HLP_PAGE};
   virtual TFIBWideStringField * get_ElementWEBTITLE_HLP_PAGE(void)=0;
   virtual void set_ElementWEBTITLE_HLP_PAGE(TFIBWideStringField * ElementWEBTITLE_HLP_PAGE)=0;

   __property TFIBWideStringField * ElementWEBDESCR_HLP_PAGE = {read = get_ElementWEBDESCR_HLP_PAGE , write = set_ElementWEBDESCR_HLP_PAGE};
   virtual TFIBWideStringField * get_ElementWEBDESCR_HLP_PAGE(void)=0;
   virtual void set_ElementWEBDESCR_HLP_PAGE(TFIBWideStringField * ElementWEBDESCR_HLP_PAGE)=0;

   __property TFIBWideStringField * ElementGUIDGRP_HLP_PAGE = {read = get_ElementGUIDGRP_HLP_PAGE , write = set_ElementGUIDGRP_HLP_PAGE};
   virtual TFIBWideStringField * get_ElementGUIDGRP_HLP_PAGE(void)=0;
   virtual void set_ElementGUIDGRP_HLP_PAGE(TFIBWideStringField * ElementGUIDGRP_HLP_PAGE)=0;

   __property TFIBWideStringField * ElementSTRCODE_HLP_PAGE = {read = get_ElementSTRCODE_HLP_PAGE , write = set_ElementSTRCODE_HLP_PAGE};
   virtual TFIBWideStringField * get_ElementSTRCODE_HLP_PAGE(void)=0;
   virtual void set_ElementSTRCODE_HLP_PAGE(TFIBWideStringField * ElementSTRCODE_HLP_PAGE)=0;

   __property TFIBWideStringField * ElementGUID_HLP_PAGE = {read = get_ElementGUID_HLP_PAGE , write = set_ElementGUID_HLP_PAGE};
   virtual TFIBWideStringField * get_ElementGUID_HLP_PAGE(void)=0;
   virtual void set_ElementGUID_HLP_PAGE(TFIBWideStringField * ElementGUID_HLP_PAGE)=0;

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
#define IID_IHLP_DMSprPage __uuidof(IHLP_DMSprPage)
#endif
