#ifndef UIART_DMSprImageH
#define UIART_DMSprImageH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IART_DMSprImage)) IART_DMSprImage : public IMainInterface
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

   __property TFIBLargeIntField * ElementID_ART_IMG = {read = get_ElementID_ART_IMG , write = set_ElementID_ART_IMG};
   virtual TFIBLargeIntField * get_ElementID_ART_IMG(void)=0;
   virtual void set_ElementID_ART_IMG(TFIBLargeIntField * ElementID_ART_IMG)=0;

   __property TFIBLargeIntField * ElementIDBASE_ART_IMG = {read = get_ElementIDBASE_ART_IMG , write = set_ElementIDBASE_ART_IMG};
   virtual TFIBLargeIntField * get_ElementIDBASE_ART_IMG(void)=0;
   virtual void set_ElementIDBASE_ART_IMG(TFIBLargeIntField * ElementIDBASE_ART_IMG)=0;

   __property TFIBWideStringField * ElementGUID_ART_IMG = {read = get_ElementGUID_ART_IMG , write = set_ElementGUID_ART_IMG};
   virtual TFIBWideStringField * get_ElementGUID_ART_IMG(void)=0;
   virtual void set_ElementGUID_ART_IMG(TFIBWideStringField * ElementGUID_ART_IMG)=0;

   __property TFIBDateTimeField * ElementPOS_ISM_ART_IMG = {read = get_ElementPOS_ISM_ART_IMG , write = set_ElementPOS_ISM_ART_IMG};
   virtual TFIBDateTimeField * get_ElementPOS_ISM_ART_IMG(void)=0;
   virtual void set_ElementPOS_ISM_ART_IMG(TFIBDateTimeField * ElementPOS_ISM_ART_IMG)=0;

   __property TFIBLargeIntField * ElementIDGRP_ART_IMG = {read = get_ElementIDGRP_ART_IMG , write = set_ElementIDGRP_ART_IMG};
   virtual TFIBLargeIntField * get_ElementIDGRP_ART_IMG(void)=0;
   virtual void set_ElementIDGRP_ART_IMG(TFIBLargeIntField * ElementIDGRP_ART_IMG)=0;

   __property TFIBWideStringField * ElementGUIDGRP_ART_IMG = {read = get_ElementGUIDGRP_ART_IMG , write = set_ElementGUIDGRP_ART_IMG};
   virtual TFIBWideStringField * get_ElementGUIDGRP_ART_IMG(void)=0;
   virtual void set_ElementGUIDGRP_ART_IMG(TFIBWideStringField * ElementGUIDGRP_ART_IMG)=0;

   __property TFIBWideStringField * ElementNAME_ART_IMG = {read = get_ElementNAME_ART_IMG , write = set_ElementNAME_ART_IMG};
   virtual TFIBWideStringField * get_ElementNAME_ART_IMG(void)=0;
   virtual void set_ElementNAME_ART_IMG(TFIBWideStringField * ElementNAME_ART_IMG)=0;

   __property TFIBWideStringField * ElementTEXT_ART_IMG = {read = get_ElementTEXT_ART_IMG , write = set_ElementTEXT_ART_IMG};
   virtual TFIBWideStringField * get_ElementTEXT_ART_IMG(void)=0;
   virtual void set_ElementTEXT_ART_IMG(TFIBWideStringField * ElementTEXT_ART_IMG)=0;

   __property TFIBIntegerField * ElementHEIGHT_ART_IMG = {read = get_ElementHEIGHT_ART_IMG , write = set_ElementHEIGHT_ART_IMG};
   virtual TFIBIntegerField * get_ElementHEIGHT_ART_IMG(void)=0;
   virtual void set_ElementHEIGHT_ART_IMG(TFIBIntegerField * ElementHEIGHT_ART_IMG)=0;

   __property TFIBIntegerField * ElementWIDTH_ART_IMG = {read = get_ElementWIDTH_ART_IMG , write = set_ElementWIDTH_ART_IMG};
   virtual TFIBIntegerField * get_ElementWIDTH_ART_IMG(void)=0;
   virtual void set_ElementWIDTH_ART_IMG(TFIBIntegerField * ElementWIDTH_ART_IMG)=0;

   __property TFIBBlobField * ElementIMAGE_ART_IMG = {read = get_ElementIMAGE_ART_IMG , write = set_ElementIMAGE_ART_IMG};
   virtual TFIBBlobField * get_ElementIMAGE_ART_IMG(void)=0;
   virtual void set_ElementIMAGE_ART_IMG(TFIBBlobField * ElementIMAGE_ART_IMG)=0;

   __property TFIBLargeIntField * TableID_ART_IMG = {read = get_TableID_ART_IMG , write = set_TableID_ART_IMG};
   virtual TFIBLargeIntField * get_TableID_ART_IMG(void)=0;
   virtual void set_TableID_ART_IMG(TFIBLargeIntField * TableID_ART_IMG)=0;

   __property TFIBLargeIntField * TableIDBASE_ART_IMG = {read = get_TableIDBASE_ART_IMG , write = set_TableIDBASE_ART_IMG};
   virtual TFIBLargeIntField * get_TableIDBASE_ART_IMG(void)=0;
   virtual void set_TableIDBASE_ART_IMG(TFIBLargeIntField * TableIDBASE_ART_IMG)=0;

   __property TFIBWideStringField * TableGUID_ART_IMG = {read = get_TableGUID_ART_IMG , write = set_TableGUID_ART_IMG};
   virtual TFIBWideStringField * get_TableGUID_ART_IMG(void)=0;
   virtual void set_TableGUID_ART_IMG(TFIBWideStringField * TableGUID_ART_IMG)=0;

   __property TFIBDateTimeField * TablePOS_ISM_ART_IMG = {read = get_TablePOS_ISM_ART_IMG , write = set_TablePOS_ISM_ART_IMG};
   virtual TFIBDateTimeField * get_TablePOS_ISM_ART_IMG(void)=0;
   virtual void set_TablePOS_ISM_ART_IMG(TFIBDateTimeField * TablePOS_ISM_ART_IMG)=0;

   __property TFIBLargeIntField * TableIDGRP_ART_IMG = {read = get_TableIDGRP_ART_IMG , write = set_TableIDGRP_ART_IMG};
   virtual TFIBLargeIntField * get_TableIDGRP_ART_IMG(void)=0;
   virtual void set_TableIDGRP_ART_IMG(TFIBLargeIntField * TableIDGRP_ART_IMG)=0;

   __property TFIBWideStringField * TableGUIDGRP_ART_IMG = {read = get_TableGUIDGRP_ART_IMG , write = set_TableGUIDGRP_ART_IMG};
   virtual TFIBWideStringField * get_TableGUIDGRP_ART_IMG(void)=0;
   virtual void set_TableGUIDGRP_ART_IMG(TFIBWideStringField * TableGUIDGRP_ART_IMG)=0;

   __property TFIBWideStringField * TableNAME_ART_IMG = {read = get_TableNAME_ART_IMG , write = set_TableNAME_ART_IMG};
   virtual TFIBWideStringField * get_TableNAME_ART_IMG(void)=0;
   virtual void set_TableNAME_ART_IMG(TFIBWideStringField * TableNAME_ART_IMG)=0;

   __property TFIBWideStringField * TableTEXT_ART_IMG = {read = get_TableTEXT_ART_IMG , write = set_TableTEXT_ART_IMG};
   virtual TFIBWideStringField * get_TableTEXT_ART_IMG(void)=0;
   virtual void set_TableTEXT_ART_IMG(TFIBWideStringField * TableTEXT_ART_IMG)=0;

   __property TFIBIntegerField * TableHEIGHT_ART_IMG = {read = get_TableHEIGHT_ART_IMG , write = set_TableHEIGHT_ART_IMG};
   virtual TFIBIntegerField * get_TableHEIGHT_ART_IMG(void)=0;
   virtual void set_TableHEIGHT_ART_IMG(TFIBIntegerField * TableHEIGHT_ART_IMG)=0;

   __property TFIBIntegerField * TableWIDTH_ART_IMG = {read = get_TableWIDTH_ART_IMG , write = set_TableWIDTH_ART_IMG};
   virtual TFIBIntegerField * get_TableWIDTH_ART_IMG(void)=0;
   virtual void set_TableWIDTH_ART_IMG(TFIBIntegerField * TableWIDTH_ART_IMG)=0;

   __property TFIBBlobField * TableIMAGE_ART_IMG = {read = get_TableIMAGE_ART_IMG , write = set_TableIMAGE_ART_IMG};
   virtual TFIBBlobField * get_TableIMAGE_ART_IMG(void)=0;
   virtual void set_TableIMAGE_ART_IMG(TFIBBlobField * TableIMAGE_ART_IMG)=0;

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
#define IID_IART_DMSprImage __uuidof(IART_DMSprImage)
#endif
