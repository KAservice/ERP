#ifndef UIHLP_DMSprPageElementH
#define UIHLP_DMSprPageElementH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IHLP_DMSprPageElement)) IHLP_DMSprPageElement : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TFIBLargeIntField * TableID_HLP_PAGE_ELEMENT = {read = get_TableID_HLP_PAGE_ELEMENT , write = set_TableID_HLP_PAGE_ELEMENT};
   virtual TFIBLargeIntField * get_TableID_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_TableID_HLP_PAGE_ELEMENT(TFIBLargeIntField * TableID_HLP_PAGE_ELEMENT)=0;

   __property TFIBLargeIntField * TableIDBASE_HLP_PAGE_ELEMENT = {read = get_TableIDBASE_HLP_PAGE_ELEMENT , write = set_TableIDBASE_HLP_PAGE_ELEMENT};
   virtual TFIBLargeIntField * get_TableIDBASE_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_TableIDBASE_HLP_PAGE_ELEMENT(TFIBLargeIntField * TableIDBASE_HLP_PAGE_ELEMENT)=0;

   __property TFIBWideStringField * TableGID_HLP_PAGE_ELEMENT = {read = get_TableGID_HLP_PAGE_ELEMENT , write = set_TableGID_HLP_PAGE_ELEMENT};
   virtual TFIBWideStringField * get_TableGID_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_TableGID_HLP_PAGE_ELEMENT(TFIBWideStringField * TableGID_HLP_PAGE_ELEMENT)=0;

   __property TFIBWideStringField * TableGUID_HLP_PAGE_ELEMENT = {read = get_TableGUID_HLP_PAGE_ELEMENT , write = set_TableGUID_HLP_PAGE_ELEMENT};
   virtual TFIBWideStringField * get_TableGUID_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_TableGUID_HLP_PAGE_ELEMENT(TFIBWideStringField * TableGUID_HLP_PAGE_ELEMENT)=0;

   __property TFIBLargeIntField * TableIDPAGE_HLP_PAGE_ELEMENT = {read = get_TableIDPAGE_HLP_PAGE_ELEMENT , write = set_TableIDPAGE_HLP_PAGE_ELEMENT};
   virtual TFIBLargeIntField * get_TableIDPAGE_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_TableIDPAGE_HLP_PAGE_ELEMENT(TFIBLargeIntField * TableIDPAGE_HLP_PAGE_ELEMENT)=0;

   __property TFIBSmallIntField * TableTYPE_HLP_PAGE_ELEMENT = {read = get_TableTYPE_HLP_PAGE_ELEMENT , write = set_TableTYPE_HLP_PAGE_ELEMENT};
   virtual TFIBSmallIntField * get_TableTYPE_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_TableTYPE_HLP_PAGE_ELEMENT(TFIBSmallIntField * TableTYPE_HLP_PAGE_ELEMENT)=0;

   __property TFIBWideStringField * TableTEXT_HLP_PAGE_ELEMENT = {read = get_TableTEXT_HLP_PAGE_ELEMENT , write = set_TableTEXT_HLP_PAGE_ELEMENT};
   virtual TFIBWideStringField * get_TableTEXT_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_TableTEXT_HLP_PAGE_ELEMENT(TFIBWideStringField * TableTEXT_HLP_PAGE_ELEMENT)=0;

   __property TFIBWideStringField * TableGUIDPAGE_HLP_PAGE_ELEMENT = {read = get_TableGUIDPAGE_HLP_PAGE_ELEMENT , write = set_TableGUIDPAGE_HLP_PAGE_ELEMENT};
   virtual TFIBWideStringField * get_TableGUIDPAGE_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_TableGUIDPAGE_HLP_PAGE_ELEMENT(TFIBWideStringField * TableGUIDPAGE_HLP_PAGE_ELEMENT)=0;

   __property TFIBWideStringField * TableGUIDIMAGE_HLP_PAGE_ELEMENT = {read = get_TableGUIDIMAGE_HLP_PAGE_ELEMENT , write = set_TableGUIDIMAGE_HLP_PAGE_ELEMENT};
   virtual TFIBWideStringField * get_TableGUIDIMAGE_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_TableGUIDIMAGE_HLP_PAGE_ELEMENT(TFIBWideStringField * TableGUIDIMAGE_HLP_PAGE_ELEMENT)=0;

   __property TFIBLargeIntField * ElementID_HLP_PAGE_ELEMENT = {read = get_ElementID_HLP_PAGE_ELEMENT , write = set_ElementID_HLP_PAGE_ELEMENT};
   virtual TFIBLargeIntField * get_ElementID_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementID_HLP_PAGE_ELEMENT(TFIBLargeIntField * ElementID_HLP_PAGE_ELEMENT)=0;

   __property TFIBLargeIntField * ElementIDBASE_HLP_PAGE_ELEMENT = {read = get_ElementIDBASE_HLP_PAGE_ELEMENT , write = set_ElementIDBASE_HLP_PAGE_ELEMENT};
   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementIDBASE_HLP_PAGE_ELEMENT(TFIBLargeIntField * ElementIDBASE_HLP_PAGE_ELEMENT)=0;

   __property TFIBWideStringField * ElementGID_HLP_PAGE_ELEMENT = {read = get_ElementGID_HLP_PAGE_ELEMENT , write = set_ElementGID_HLP_PAGE_ELEMENT};
   virtual TFIBWideStringField * get_ElementGID_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementGID_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementGID_HLP_PAGE_ELEMENT)=0;

   __property TFIBWideStringField * ElementGUID_HLP_PAGE_ELEMENT = {read = get_ElementGUID_HLP_PAGE_ELEMENT , write = set_ElementGUID_HLP_PAGE_ELEMENT};
   virtual TFIBWideStringField * get_ElementGUID_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementGUID_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementGUID_HLP_PAGE_ELEMENT)=0;

   __property TFIBLargeIntField * ElementIDPAGE_HLP_PAGE_ELEMENT = {read = get_ElementIDPAGE_HLP_PAGE_ELEMENT , write = set_ElementIDPAGE_HLP_PAGE_ELEMENT};
   virtual TFIBLargeIntField * get_ElementIDPAGE_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementIDPAGE_HLP_PAGE_ELEMENT(TFIBLargeIntField * ElementIDPAGE_HLP_PAGE_ELEMENT)=0;

   __property TFIBSmallIntField * ElementTYPE_HLP_PAGE_ELEMENT = {read = get_ElementTYPE_HLP_PAGE_ELEMENT , write = set_ElementTYPE_HLP_PAGE_ELEMENT};
   virtual TFIBSmallIntField * get_ElementTYPE_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementTYPE_HLP_PAGE_ELEMENT(TFIBSmallIntField * ElementTYPE_HLP_PAGE_ELEMENT)=0;

   __property TFIBWideStringField * ElementTEXT_HLP_PAGE_ELEMENT = {read = get_ElementTEXT_HLP_PAGE_ELEMENT , write = set_ElementTEXT_HLP_PAGE_ELEMENT};
   virtual TFIBWideStringField * get_ElementTEXT_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementTEXT_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementTEXT_HLP_PAGE_ELEMENT)=0;

   __property TFIBWideStringField * ElementGUIDPAGE_HLP_PAGE_ELEMENT = {read = get_ElementGUIDPAGE_HLP_PAGE_ELEMENT , write = set_ElementGUIDPAGE_HLP_PAGE_ELEMENT};
   virtual TFIBWideStringField * get_ElementGUIDPAGE_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementGUIDPAGE_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementGUIDPAGE_HLP_PAGE_ELEMENT)=0;

   __property TFIBWideStringField * ElementGUIDIMAGE_HLP_PAGE_ELEMENT = {read = get_ElementGUIDIMAGE_HLP_PAGE_ELEMENT , write = set_ElementGUIDIMAGE_HLP_PAGE_ELEMENT};
   virtual TFIBWideStringField * get_ElementGUIDIMAGE_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementGUIDIMAGE_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementGUIDIMAGE_HLP_PAGE_ELEMENT)=0;

   __property TFIBLargeIntField * TableIDIMAGE_HLP_PAGE_ELEMENT = {read = get_TableIDIMAGE_HLP_PAGE_ELEMENT , write = set_TableIDIMAGE_HLP_PAGE_ELEMENT};
   virtual TFIBLargeIntField * get_TableIDIMAGE_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_TableIDIMAGE_HLP_PAGE_ELEMENT(TFIBLargeIntField * TableIDIMAGE_HLP_PAGE_ELEMENT)=0;

   __property TFIBIntegerField * TableINDEX_HLP_PAGE_ELEMENT = {read = get_TableINDEX_HLP_PAGE_ELEMENT , write = set_TableINDEX_HLP_PAGE_ELEMENT};
   virtual TFIBIntegerField * get_TableINDEX_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_TableINDEX_HLP_PAGE_ELEMENT(TFIBIntegerField * TableINDEX_HLP_PAGE_ELEMENT)=0;

   __property TFIBLargeIntField * ElementIDIMAGE_HLP_PAGE_ELEMENT = {read = get_ElementIDIMAGE_HLP_PAGE_ELEMENT , write = set_ElementIDIMAGE_HLP_PAGE_ELEMENT};
   virtual TFIBLargeIntField * get_ElementIDIMAGE_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementIDIMAGE_HLP_PAGE_ELEMENT(TFIBLargeIntField * ElementIDIMAGE_HLP_PAGE_ELEMENT)=0;

   __property TFIBSmallIntField * ElementTYPE_TBL_HLP_PAGE_ELEMENT = {read = get_ElementTYPE_TBL_HLP_PAGE_ELEMENT , write = set_ElementTYPE_TBL_HLP_PAGE_ELEMENT};
   virtual TFIBSmallIntField * get_ElementTYPE_TBL_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementTYPE_TBL_HLP_PAGE_ELEMENT(TFIBSmallIntField * ElementTYPE_TBL_HLP_PAGE_ELEMENT)=0;

   __property TFIBIntegerField * ElementINDEX_HLP_PAGE_ELEMENT = {read = get_ElementINDEX_HLP_PAGE_ELEMENT , write = set_ElementINDEX_HLP_PAGE_ELEMENT};
   virtual TFIBIntegerField * get_ElementINDEX_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementINDEX_HLP_PAGE_ELEMENT(TFIBIntegerField * ElementINDEX_HLP_PAGE_ELEMENT)=0;

   __property TFIBWideStringField * TableNAME_HLP_IMAGE = {read = get_TableNAME_HLP_IMAGE , write = set_TableNAME_HLP_IMAGE};
   virtual TFIBWideStringField * get_TableNAME_HLP_IMAGE(void)=0;
   virtual void set_TableNAME_HLP_IMAGE(TFIBWideStringField * TableNAME_HLP_IMAGE)=0;

   __property TFIBBlobField * TableIMAGE_HLP_IMAGE = {read = get_TableIMAGE_HLP_IMAGE , write = set_TableIMAGE_HLP_IMAGE};
   virtual TFIBBlobField * get_TableIMAGE_HLP_IMAGE(void)=0;
   virtual void set_TableIMAGE_HLP_IMAGE(TFIBBlobField * TableIMAGE_HLP_IMAGE)=0;

   __property TFIBSmallIntField * TableTYPE_HLP_IMAGE = {read = get_TableTYPE_HLP_IMAGE , write = set_TableTYPE_HLP_IMAGE};
   virtual TFIBSmallIntField * get_TableTYPE_HLP_IMAGE(void)=0;
   virtual void set_TableTYPE_HLP_IMAGE(TFIBSmallIntField * TableTYPE_HLP_IMAGE)=0;

   __property TFIBIntegerField * TableH_ALIGN_HLP_PAGE_ELEMENT = {read = get_TableH_ALIGN_HLP_PAGE_ELEMENT , write = set_TableH_ALIGN_HLP_PAGE_ELEMENT};
   virtual TFIBIntegerField * get_TableH_ALIGN_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_TableH_ALIGN_HLP_PAGE_ELEMENT(TFIBIntegerField * TableH_ALIGN_HLP_PAGE_ELEMENT)=0;

   __property TFIBIntegerField * ElementH_ALIGN_HLP_PAGE_ELEMENT = {read = get_ElementH_ALIGN_HLP_PAGE_ELEMENT , write = set_ElementH_ALIGN_HLP_PAGE_ELEMENT};
   virtual TFIBIntegerField * get_ElementH_ALIGN_HLP_PAGE_ELEMENT(void)=0;
   virtual void set_ElementH_ALIGN_HLP_PAGE_ELEMENT(TFIBIntegerField * ElementH_ALIGN_HLP_PAGE_ELEMENT)=0;

   __property __int64 IdPage = {read = get_IdPage , write = set_IdPage};
   virtual __int64 get_IdPage(void)=0;
   virtual void set_IdPage(__int64 IdPage)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_page)=0;
   virtual bool SaveIsmen(void)=0;
   virtual bool CancelIsmen(void)=0;
   virtual bool TableAppend(__int64 id_page)=0;
   virtual bool TableDelete(void)=0;
   virtual bool NewElement(__int64 id_page)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IHLP_DMSprPageElement __uuidof(IHLP_DMSprPageElement)
#endif
