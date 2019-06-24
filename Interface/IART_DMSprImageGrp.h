#ifndef UIART_DMSprImageGrpH
#define UIART_DMSprImageGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IART_DMSprImageGrp)) IART_DMSprImageGrp : public IMainInterface
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

   __property TFIBLargeIntField * TableID_ART_IMG_GRP = {read = get_TableID_ART_IMG_GRP , write = set_TableID_ART_IMG_GRP};
   virtual TFIBLargeIntField * get_TableID_ART_IMG_GRP(void)=0;
   virtual void set_TableID_ART_IMG_GRP(TFIBLargeIntField * TableID_ART_IMG_GRP)=0;

   __property TFIBLargeIntField * TableIDBASE_ART_IMG_GRP = {read = get_TableIDBASE_ART_IMG_GRP , write = set_TableIDBASE_ART_IMG_GRP};
   virtual TFIBLargeIntField * get_TableIDBASE_ART_IMG_GRP(void)=0;
   virtual void set_TableIDBASE_ART_IMG_GRP(TFIBLargeIntField * TableIDBASE_ART_IMG_GRP)=0;

   __property TFIBWideStringField * TableGUID_ART_IMG_GRP = {read = get_TableGUID_ART_IMG_GRP , write = set_TableGUID_ART_IMG_GRP};
   virtual TFIBWideStringField * get_TableGUID_ART_IMG_GRP(void)=0;
   virtual void set_TableGUID_ART_IMG_GRP(TFIBWideStringField * TableGUID_ART_IMG_GRP)=0;

   __property TFIBDateTimeField * TablePOS_ISM_ART_IMG_GRP = {read = get_TablePOS_ISM_ART_IMG_GRP , write = set_TablePOS_ISM_ART_IMG_GRP};
   virtual TFIBDateTimeField * get_TablePOS_ISM_ART_IMG_GRP(void)=0;
   virtual void set_TablePOS_ISM_ART_IMG_GRP(TFIBDateTimeField * TablePOS_ISM_ART_IMG_GRP)=0;

   __property TFIBLargeIntField * TableIDGRP_ART_IMG_GRP = {read = get_TableIDGRP_ART_IMG_GRP , write = set_TableIDGRP_ART_IMG_GRP};
   virtual TFIBLargeIntField * get_TableIDGRP_ART_IMG_GRP(void)=0;
   virtual void set_TableIDGRP_ART_IMG_GRP(TFIBLargeIntField * TableIDGRP_ART_IMG_GRP)=0;

   __property TFIBWideStringField * TableGUIDGRP_ART_IMG_GRP = {read = get_TableGUIDGRP_ART_IMG_GRP , write = set_TableGUIDGRP_ART_IMG_GRP};
   virtual TFIBWideStringField * get_TableGUIDGRP_ART_IMG_GRP(void)=0;
   virtual void set_TableGUIDGRP_ART_IMG_GRP(TFIBWideStringField * TableGUIDGRP_ART_IMG_GRP)=0;

   __property TFIBWideStringField * TableNAME_ART_IMG_GRP = {read = get_TableNAME_ART_IMG_GRP , write = set_TableNAME_ART_IMG_GRP};
   virtual TFIBWideStringField * get_TableNAME_ART_IMG_GRP(void)=0;
   virtual void set_TableNAME_ART_IMG_GRP(TFIBWideStringField * TableNAME_ART_IMG_GRP)=0;

   __property TFIBLargeIntField * ElementID_ART_IMG_GRP = {read = get_ElementID_ART_IMG_GRP , write = set_ElementID_ART_IMG_GRP};
   virtual TFIBLargeIntField * get_ElementID_ART_IMG_GRP(void)=0;
   virtual void set_ElementID_ART_IMG_GRP(TFIBLargeIntField * ElementID_ART_IMG_GRP)=0;

   __property TFIBLargeIntField * ElementIDBASE_ART_IMG_GRP = {read = get_ElementIDBASE_ART_IMG_GRP , write = set_ElementIDBASE_ART_IMG_GRP};
   virtual TFIBLargeIntField * get_ElementIDBASE_ART_IMG_GRP(void)=0;
   virtual void set_ElementIDBASE_ART_IMG_GRP(TFIBLargeIntField * ElementIDBASE_ART_IMG_GRP)=0;

   __property TFIBWideStringField * ElementGUID_ART_IMG_GRP = {read = get_ElementGUID_ART_IMG_GRP , write = set_ElementGUID_ART_IMG_GRP};
   virtual TFIBWideStringField * get_ElementGUID_ART_IMG_GRP(void)=0;
   virtual void set_ElementGUID_ART_IMG_GRP(TFIBWideStringField * ElementGUID_ART_IMG_GRP)=0;

   __property TFIBDateTimeField * ElementPOS_ISM_ART_IMG_GRP = {read = get_ElementPOS_ISM_ART_IMG_GRP , write = set_ElementPOS_ISM_ART_IMG_GRP};
   virtual TFIBDateTimeField * get_ElementPOS_ISM_ART_IMG_GRP(void)=0;
   virtual void set_ElementPOS_ISM_ART_IMG_GRP(TFIBDateTimeField * ElementPOS_ISM_ART_IMG_GRP)=0;

   __property TFIBLargeIntField * ElementIDGRP_ART_IMG_GRP = {read = get_ElementIDGRP_ART_IMG_GRP , write = set_ElementIDGRP_ART_IMG_GRP};
   virtual TFIBLargeIntField * get_ElementIDGRP_ART_IMG_GRP(void)=0;
   virtual void set_ElementIDGRP_ART_IMG_GRP(TFIBLargeIntField * ElementIDGRP_ART_IMG_GRP)=0;

   __property TFIBWideStringField * ElementGUIDGRP_ART_IMG_GRP = {read = get_ElementGUIDGRP_ART_IMG_GRP , write = set_ElementGUIDGRP_ART_IMG_GRP};
   virtual TFIBWideStringField * get_ElementGUIDGRP_ART_IMG_GRP(void)=0;
   virtual void set_ElementGUIDGRP_ART_IMG_GRP(TFIBWideStringField * ElementGUIDGRP_ART_IMG_GRP)=0;

   __property TFIBWideStringField * ElementNAME_ART_IMG_GRP = {read = get_ElementNAME_ART_IMG_GRP , write = set_ElementNAME_ART_IMG_GRP};
   virtual TFIBWideStringField * get_ElementNAME_ART_IMG_GRP(void)=0;
   virtual void set_ElementNAME_ART_IMG_GRP(TFIBWideStringField * ElementNAME_ART_IMG_GRP)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 FindPoName(UnicodeString name)=0;
};
#define IID_IART_DMSprImageGrp __uuidof(IART_DMSprImageGrp)
#endif
