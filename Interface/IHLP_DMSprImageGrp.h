#ifndef UIHLP_DMSprImageGrpH
#define UIHLP_DMSprImageGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IHLP_DMSprImageGrp)) IHLP_DMSprImageGrp : public IMainInterface
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

   __property TFIBLargeIntField * TableID_HLP_IMG_GRP = {read = get_TableID_HLP_IMG_GRP , write = set_TableID_HLP_IMG_GRP};
   virtual TFIBLargeIntField * get_TableID_HLP_IMG_GRP(void)=0;
   virtual void set_TableID_HLP_IMG_GRP(TFIBLargeIntField * TableID_HLP_IMG_GRP)=0;

   __property TFIBLargeIntField * TableIDBASE_HLP_IMG_GRP = {read = get_TableIDBASE_HLP_IMG_GRP , write = set_TableIDBASE_HLP_IMG_GRP};
   virtual TFIBLargeIntField * get_TableIDBASE_HLP_IMG_GRP(void)=0;
   virtual void set_TableIDBASE_HLP_IMG_GRP(TFIBLargeIntField * TableIDBASE_HLP_IMG_GRP)=0;

   __property TFIBWideStringField * TableGUID_HLP_IMG_GRP = {read = get_TableGUID_HLP_IMG_GRP , write = set_TableGUID_HLP_IMG_GRP};
   virtual TFIBWideStringField * get_TableGUID_HLP_IMG_GRP(void)=0;
   virtual void set_TableGUID_HLP_IMG_GRP(TFIBWideStringField * TableGUID_HLP_IMG_GRP)=0;

   __property TFIBDateTimeField * TablePOS_ISM_HLP_IMG_GRP = {read = get_TablePOS_ISM_HLP_IMG_GRP , write = set_TablePOS_ISM_HLP_IMG_GRP};
   virtual TFIBDateTimeField * get_TablePOS_ISM_HLP_IMG_GRP(void)=0;
   virtual void set_TablePOS_ISM_HLP_IMG_GRP(TFIBDateTimeField * TablePOS_ISM_HLP_IMG_GRP)=0;

   __property TFIBLargeIntField * TableIDGRP_HLP_IMG_GRP = {read = get_TableIDGRP_HLP_IMG_GRP , write = set_TableIDGRP_HLP_IMG_GRP};
   virtual TFIBLargeIntField * get_TableIDGRP_HLP_IMG_GRP(void)=0;
   virtual void set_TableIDGRP_HLP_IMG_GRP(TFIBLargeIntField * TableIDGRP_HLP_IMG_GRP)=0;

   __property TFIBWideStringField * TableGUIDGRP_HLP_IMG_GRP = {read = get_TableGUIDGRP_HLP_IMG_GRP , write = set_TableGUIDGRP_HLP_IMG_GRP};
   virtual TFIBWideStringField * get_TableGUIDGRP_HLP_IMG_GRP(void)=0;
   virtual void set_TableGUIDGRP_HLP_IMG_GRP(TFIBWideStringField * TableGUIDGRP_HLP_IMG_GRP)=0;

   __property TFIBWideStringField * TableNAME_HLP_IMG_GRP = {read = get_TableNAME_HLP_IMG_GRP , write = set_TableNAME_HLP_IMG_GRP};
   virtual TFIBWideStringField * get_TableNAME_HLP_IMG_GRP(void)=0;
   virtual void set_TableNAME_HLP_IMG_GRP(TFIBWideStringField * TableNAME_HLP_IMG_GRP)=0;

   __property TFIBIntegerField * TableINDEX_HLP_IMG_GRP = {read = get_TableINDEX_HLP_IMG_GRP , write = set_TableINDEX_HLP_IMG_GRP};
   virtual TFIBIntegerField * get_TableINDEX_HLP_IMG_GRP(void)=0;
   virtual void set_TableINDEX_HLP_IMG_GRP(TFIBIntegerField * TableINDEX_HLP_IMG_GRP)=0;

   __property TFIBLargeIntField * ElementID_HLP_IMG_GRP = {read = get_ElementID_HLP_IMG_GRP , write = set_ElementID_HLP_IMG_GRP};
   virtual TFIBLargeIntField * get_ElementID_HLP_IMG_GRP(void)=0;
   virtual void set_ElementID_HLP_IMG_GRP(TFIBLargeIntField * ElementID_HLP_IMG_GRP)=0;

   __property TFIBLargeIntField * ElementIDBASE_HLP_IMG_GRP = {read = get_ElementIDBASE_HLP_IMG_GRP , write = set_ElementIDBASE_HLP_IMG_GRP};
   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_IMG_GRP(void)=0;
   virtual void set_ElementIDBASE_HLP_IMG_GRP(TFIBLargeIntField * ElementIDBASE_HLP_IMG_GRP)=0;

   __property TFIBWideStringField * ElementGUID_HLP_IMG_GRP = {read = get_ElementGUID_HLP_IMG_GRP , write = set_ElementGUID_HLP_IMG_GRP};
   virtual TFIBWideStringField * get_ElementGUID_HLP_IMG_GRP(void)=0;
   virtual void set_ElementGUID_HLP_IMG_GRP(TFIBWideStringField * ElementGUID_HLP_IMG_GRP)=0;

   __property TFIBDateTimeField * ElementPOS_ISM_HLP_IMG_GRP = {read = get_ElementPOS_ISM_HLP_IMG_GRP , write = set_ElementPOS_ISM_HLP_IMG_GRP};
   virtual TFIBDateTimeField * get_ElementPOS_ISM_HLP_IMG_GRP(void)=0;
   virtual void set_ElementPOS_ISM_HLP_IMG_GRP(TFIBDateTimeField * ElementPOS_ISM_HLP_IMG_GRP)=0;

   __property TFIBLargeIntField * ElementIDGRP_HLP_IMG_GRP = {read = get_ElementIDGRP_HLP_IMG_GRP , write = set_ElementIDGRP_HLP_IMG_GRP};
   virtual TFIBLargeIntField * get_ElementIDGRP_HLP_IMG_GRP(void)=0;
   virtual void set_ElementIDGRP_HLP_IMG_GRP(TFIBLargeIntField * ElementIDGRP_HLP_IMG_GRP)=0;

   __property TFIBWideStringField * ElementGUIDGRP_HLP_IMG_GRP = {read = get_ElementGUIDGRP_HLP_IMG_GRP , write = set_ElementGUIDGRP_HLP_IMG_GRP};
   virtual TFIBWideStringField * get_ElementGUIDGRP_HLP_IMG_GRP(void)=0;
   virtual void set_ElementGUIDGRP_HLP_IMG_GRP(TFIBWideStringField * ElementGUIDGRP_HLP_IMG_GRP)=0;

   __property TFIBWideStringField * ElementNAME_HLP_IMG_GRP = {read = get_ElementNAME_HLP_IMG_GRP , write = set_ElementNAME_HLP_IMG_GRP};
   virtual TFIBWideStringField * get_ElementNAME_HLP_IMG_GRP(void)=0;
   virtual void set_ElementNAME_HLP_IMG_GRP(TFIBWideStringField * ElementNAME_HLP_IMG_GRP)=0;

   __property TFIBIntegerField * ElementINDEX_HLP_IMG_GRP = {read = get_ElementINDEX_HLP_IMG_GRP , write = set_ElementINDEX_HLP_IMG_GRP};
   virtual TFIBIntegerField * get_ElementINDEX_HLP_IMG_GRP(void)=0;
   virtual void set_ElementINDEX_HLP_IMG_GRP(TFIBIntegerField * ElementINDEX_HLP_IMG_GRP)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 FindPoName(UnicodeString name)=0;
};
#define IID_IHLP_DMSprImageGrp __uuidof(IHLP_DMSprImageGrp)
#endif
