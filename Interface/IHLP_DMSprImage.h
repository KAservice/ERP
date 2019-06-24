#ifndef UIHLP_DMSprImageH
#define UIHLP_DMSprImageH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IHLP_DMSprImage)) IHLP_DMSprImage : public IMainInterface
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

   __property TFIBLargeIntField * TableID_HLP_IMG = {read = get_TableID_HLP_IMG , write = set_TableID_HLP_IMG};
   virtual TFIBLargeIntField * get_TableID_HLP_IMG(void)=0;
   virtual void set_TableID_HLP_IMG(TFIBLargeIntField * TableID_HLP_IMG)=0;

   __property TFIBLargeIntField * TableIDBASE_HLP_IMG = {read = get_TableIDBASE_HLP_IMG , write = set_TableIDBASE_HLP_IMG};
   virtual TFIBLargeIntField * get_TableIDBASE_HLP_IMG(void)=0;
   virtual void set_TableIDBASE_HLP_IMG(TFIBLargeIntField * TableIDBASE_HLP_IMG)=0;

   __property TFIBWideStringField * TableGUID_HLP_IMG = {read = get_TableGUID_HLP_IMG , write = set_TableGUID_HLP_IMG};
   virtual TFIBWideStringField * get_TableGUID_HLP_IMG(void)=0;
   virtual void set_TableGUID_HLP_IMG(TFIBWideStringField * TableGUID_HLP_IMG)=0;

   __property TFIBDateTimeField * TablePOS_ISM_HLP_IMG = {read = get_TablePOS_ISM_HLP_IMG , write = set_TablePOS_ISM_HLP_IMG};
   virtual TFIBDateTimeField * get_TablePOS_ISM_HLP_IMG(void)=0;
   virtual void set_TablePOS_ISM_HLP_IMG(TFIBDateTimeField * TablePOS_ISM_HLP_IMG)=0;

   __property TFIBLargeIntField * TableIDGRP_HLP_IMG = {read = get_TableIDGRP_HLP_IMG , write = set_TableIDGRP_HLP_IMG};
   virtual TFIBLargeIntField * get_TableIDGRP_HLP_IMG(void)=0;
   virtual void set_TableIDGRP_HLP_IMG(TFIBLargeIntField * TableIDGRP_HLP_IMG)=0;

   __property TFIBWideStringField * TableGUIDGRP_HLP_IMG = {read = get_TableGUIDGRP_HLP_IMG , write = set_TableGUIDGRP_HLP_IMG};
   virtual TFIBWideStringField * get_TableGUIDGRP_HLP_IMG(void)=0;
   virtual void set_TableGUIDGRP_HLP_IMG(TFIBWideStringField * TableGUIDGRP_HLP_IMG)=0;

   __property TFIBWideStringField * TableNAME_HLP_IMG = {read = get_TableNAME_HLP_IMG , write = set_TableNAME_HLP_IMG};
   virtual TFIBWideStringField * get_TableNAME_HLP_IMG(void)=0;
   virtual void set_TableNAME_HLP_IMG(TFIBWideStringField * TableNAME_HLP_IMG)=0;

   __property TFIBWideStringField * TableTEXT_HLP_IMG = {read = get_TableTEXT_HLP_IMG , write = set_TableTEXT_HLP_IMG};
   virtual TFIBWideStringField * get_TableTEXT_HLP_IMG(void)=0;
   virtual void set_TableTEXT_HLP_IMG(TFIBWideStringField * TableTEXT_HLP_IMG)=0;

   __property TFIBIntegerField * TableHEIGHT_HLP_IMG = {read = get_TableHEIGHT_HLP_IMG , write = set_TableHEIGHT_HLP_IMG};
   virtual TFIBIntegerField * get_TableHEIGHT_HLP_IMG(void)=0;
   virtual void set_TableHEIGHT_HLP_IMG(TFIBIntegerField * TableHEIGHT_HLP_IMG)=0;

   __property TFIBIntegerField * TableWIDTH_HLP_IMG = {read = get_TableWIDTH_HLP_IMG , write = set_TableWIDTH_HLP_IMG};
   virtual TFIBIntegerField * get_TableWIDTH_HLP_IMG(void)=0;
   virtual void set_TableWIDTH_HLP_IMG(TFIBIntegerField * TableWIDTH_HLP_IMG)=0;

   __property TFIBBlobField * TableIMAGE_HLP_IMG = {read = get_TableIMAGE_HLP_IMG , write = set_TableIMAGE_HLP_IMG};
   virtual TFIBBlobField * get_TableIMAGE_HLP_IMG(void)=0;
   virtual void set_TableIMAGE_HLP_IMG(TFIBBlobField * TableIMAGE_HLP_IMG)=0;

   __property TFIBIntegerField * TableINDEX_HLP_IMG = {read = get_TableINDEX_HLP_IMG , write = set_TableINDEX_HLP_IMG};
   virtual TFIBIntegerField * get_TableINDEX_HLP_IMG(void)=0;
   virtual void set_TableINDEX_HLP_IMG(TFIBIntegerField * TableINDEX_HLP_IMG)=0;

   __property TFIBLargeIntField * ElementID_HLP_IMG = {read = get_ElementID_HLP_IMG , write = set_ElementID_HLP_IMG};
   virtual TFIBLargeIntField * get_ElementID_HLP_IMG(void)=0;
   virtual void set_ElementID_HLP_IMG(TFIBLargeIntField * ElementID_HLP_IMG)=0;

   __property TFIBLargeIntField * ElementIDBASE_HLP_IMG = {read = get_ElementIDBASE_HLP_IMG , write = set_ElementIDBASE_HLP_IMG};
   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_IMG(void)=0;
   virtual void set_ElementIDBASE_HLP_IMG(TFIBLargeIntField * ElementIDBASE_HLP_IMG)=0;

   __property TFIBWideStringField * ElementGUID_HLP_IMG = {read = get_ElementGUID_HLP_IMG , write = set_ElementGUID_HLP_IMG};
   virtual TFIBWideStringField * get_ElementGUID_HLP_IMG(void)=0;
   virtual void set_ElementGUID_HLP_IMG(TFIBWideStringField * ElementGUID_HLP_IMG)=0;

   __property TFIBDateTimeField * ElementPOS_ISM_HLP_IMG = {read = get_ElementPOS_ISM_HLP_IMG , write = set_ElementPOS_ISM_HLP_IMG};
   virtual TFIBDateTimeField * get_ElementPOS_ISM_HLP_IMG(void)=0;
   virtual void set_ElementPOS_ISM_HLP_IMG(TFIBDateTimeField * ElementPOS_ISM_HLP_IMG)=0;

   __property TFIBLargeIntField * ElementIDGRP_HLP_IMG = {read = get_ElementIDGRP_HLP_IMG , write = set_ElementIDGRP_HLP_IMG};
   virtual TFIBLargeIntField * get_ElementIDGRP_HLP_IMG(void)=0;
   virtual void set_ElementIDGRP_HLP_IMG(TFIBLargeIntField * ElementIDGRP_HLP_IMG)=0;

   __property TFIBWideStringField * ElementGUIDGRP_HLP_IMG = {read = get_ElementGUIDGRP_HLP_IMG , write = set_ElementGUIDGRP_HLP_IMG};
   virtual TFIBWideStringField * get_ElementGUIDGRP_HLP_IMG(void)=0;
   virtual void set_ElementGUIDGRP_HLP_IMG(TFIBWideStringField * ElementGUIDGRP_HLP_IMG)=0;

   __property TFIBWideStringField * ElementNAME_HLP_IMG = {read = get_ElementNAME_HLP_IMG , write = set_ElementNAME_HLP_IMG};
   virtual TFIBWideStringField * get_ElementNAME_HLP_IMG(void)=0;
   virtual void set_ElementNAME_HLP_IMG(TFIBWideStringField * ElementNAME_HLP_IMG)=0;

   __property TFIBWideStringField * ElementTEXT_HLP_IMG = {read = get_ElementTEXT_HLP_IMG , write = set_ElementTEXT_HLP_IMG};
   virtual TFIBWideStringField * get_ElementTEXT_HLP_IMG(void)=0;
   virtual void set_ElementTEXT_HLP_IMG(TFIBWideStringField * ElementTEXT_HLP_IMG)=0;

   __property TFIBIntegerField * ElementHEIGHT_HLP_IMG = {read = get_ElementHEIGHT_HLP_IMG , write = set_ElementHEIGHT_HLP_IMG};
   virtual TFIBIntegerField * get_ElementHEIGHT_HLP_IMG(void)=0;
   virtual void set_ElementHEIGHT_HLP_IMG(TFIBIntegerField * ElementHEIGHT_HLP_IMG)=0;

   __property TFIBIntegerField * ElementWIDTH_HLP_IMG = {read = get_ElementWIDTH_HLP_IMG , write = set_ElementWIDTH_HLP_IMG};
   virtual TFIBIntegerField * get_ElementWIDTH_HLP_IMG(void)=0;
   virtual void set_ElementWIDTH_HLP_IMG(TFIBIntegerField * ElementWIDTH_HLP_IMG)=0;

   __property TFIBBlobField * ElementIMAGE_HLP_IMG = {read = get_ElementIMAGE_HLP_IMG , write = set_ElementIMAGE_HLP_IMG};
   virtual TFIBBlobField * get_ElementIMAGE_HLP_IMG(void)=0;
   virtual void set_ElementIMAGE_HLP_IMG(TFIBBlobField * ElementIMAGE_HLP_IMG)=0;

   __property TFIBIntegerField * ElementINDEX_HLP_IMG = {read = get_ElementINDEX_HLP_IMG , write = set_ElementINDEX_HLP_IMG};
   virtual TFIBIntegerField * get_ElementINDEX_HLP_IMG(void)=0;
   virtual void set_ElementINDEX_HLP_IMG(TFIBIntegerField * ElementINDEX_HLP_IMG)=0;

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
#define IID_IHLP_DMSprImage __uuidof(IHLP_DMSprImage)
#endif
