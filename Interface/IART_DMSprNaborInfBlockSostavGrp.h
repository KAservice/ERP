#ifndef UIART_DMSprNaborInfBlockSostavGrpH
#define UIART_DMSprNaborInfBlockSostavGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IART_DMSprNaborInfBlockSostavGrp)) IART_DMSprNaborInfBlockSostavGrp : public IMainInterface
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

   __property TFIBLargeIntField * TableID_ART_N_IB_S_GRP = {read = get_TableID_ART_N_IB_S_GRP , write = set_TableID_ART_N_IB_S_GRP};
   virtual TFIBLargeIntField * get_TableID_ART_N_IB_S_GRP(void)=0;
   virtual void set_TableID_ART_N_IB_S_GRP(TFIBLargeIntField * TableID_ART_N_IB_S_GRP)=0;

   __property TFIBLargeIntField * TableIDBASE_ART_N_IB_S_GRP = {read = get_TableIDBASE_ART_N_IB_S_GRP , write = set_TableIDBASE_ART_N_IB_S_GRP};
   virtual TFIBLargeIntField * get_TableIDBASE_ART_N_IB_S_GRP(void)=0;
   virtual void set_TableIDBASE_ART_N_IB_S_GRP(TFIBLargeIntField * TableIDBASE_ART_N_IB_S_GRP)=0;

   __property TFIBWideStringField * TableGUID_ART_N_IB_S_GRP = {read = get_TableGUID_ART_N_IB_S_GRP , write = set_TableGUID_ART_N_IB_S_GRP};
   virtual TFIBWideStringField * get_TableGUID_ART_N_IB_S_GRP(void)=0;
   virtual void set_TableGUID_ART_N_IB_S_GRP(TFIBWideStringField * TableGUID_ART_N_IB_S_GRP)=0;

   __property TFIBDateTimeField * TablePOS_ISM_ART_N_IB_S_GRP = {read = get_TablePOS_ISM_ART_N_IB_S_GRP , write = set_TablePOS_ISM_ART_N_IB_S_GRP};
   virtual TFIBDateTimeField * get_TablePOS_ISM_ART_N_IB_S_GRP(void)=0;
   virtual void set_TablePOS_ISM_ART_N_IB_S_GRP(TFIBDateTimeField * TablePOS_ISM_ART_N_IB_S_GRP)=0;

   __property TFIBLargeIntField * TableIDGRP_ART_N_IB_S_GRP = {read = get_TableIDGRP_ART_N_IB_S_GRP , write = set_TableIDGRP_ART_N_IB_S_GRP};
   virtual TFIBLargeIntField * get_TableIDGRP_ART_N_IB_S_GRP(void)=0;
   virtual void set_TableIDGRP_ART_N_IB_S_GRP(TFIBLargeIntField * TableIDGRP_ART_N_IB_S_GRP)=0;

   __property TFIBWideStringField * TableNAME_ART_N_IB_S_GRP = {read = get_TableNAME_ART_N_IB_S_GRP , write = set_TableNAME_ART_N_IB_S_GRP};
   virtual TFIBWideStringField * get_TableNAME_ART_N_IB_S_GRP(void)=0;
   virtual void set_TableNAME_ART_N_IB_S_GRP(TFIBWideStringField * TableNAME_ART_N_IB_S_GRP)=0;

   __property TFIBLargeIntField * TableIDNABOR_ART_N_IB_S_GRP = {read = get_TableIDNABOR_ART_N_IB_S_GRP , write = set_TableIDNABOR_ART_N_IB_S_GRP};
   virtual TFIBLargeIntField * get_TableIDNABOR_ART_N_IB_S_GRP(void)=0;
   virtual void set_TableIDNABOR_ART_N_IB_S_GRP(TFIBLargeIntField * TableIDNABOR_ART_N_IB_S_GRP)=0;

   __property TFIBLargeIntField * ElementID_ART_N_IB_S_GRP = {read = get_ElementID_ART_N_IB_S_GRP , write = set_ElementID_ART_N_IB_S_GRP};
   virtual TFIBLargeIntField * get_ElementID_ART_N_IB_S_GRP(void)=0;
   virtual void set_ElementID_ART_N_IB_S_GRP(TFIBLargeIntField * ElementID_ART_N_IB_S_GRP)=0;

   __property TFIBLargeIntField * ElementIDBASE_ART_N_IB_S_GRP = {read = get_ElementIDBASE_ART_N_IB_S_GRP , write = set_ElementIDBASE_ART_N_IB_S_GRP};
   virtual TFIBLargeIntField * get_ElementIDBASE_ART_N_IB_S_GRP(void)=0;
   virtual void set_ElementIDBASE_ART_N_IB_S_GRP(TFIBLargeIntField * ElementIDBASE_ART_N_IB_S_GRP)=0;

   __property TFIBWideStringField * ElementGUID_ART_N_IB_S_GRP = {read = get_ElementGUID_ART_N_IB_S_GRP , write = set_ElementGUID_ART_N_IB_S_GRP};
   virtual TFIBWideStringField * get_ElementGUID_ART_N_IB_S_GRP(void)=0;
   virtual void set_ElementGUID_ART_N_IB_S_GRP(TFIBWideStringField * ElementGUID_ART_N_IB_S_GRP)=0;

   __property TFIBDateTimeField * ElementPOS_ISM_ART_N_IB_S_GRP = {read = get_ElementPOS_ISM_ART_N_IB_S_GRP , write = set_ElementPOS_ISM_ART_N_IB_S_GRP};
   virtual TFIBDateTimeField * get_ElementPOS_ISM_ART_N_IB_S_GRP(void)=0;
   virtual void set_ElementPOS_ISM_ART_N_IB_S_GRP(TFIBDateTimeField * ElementPOS_ISM_ART_N_IB_S_GRP)=0;

   __property TFIBLargeIntField * ElementIDGRP_ART_N_IB_S_GRP = {read = get_ElementIDGRP_ART_N_IB_S_GRP , write = set_ElementIDGRP_ART_N_IB_S_GRP};
   virtual TFIBLargeIntField * get_ElementIDGRP_ART_N_IB_S_GRP(void)=0;
   virtual void set_ElementIDGRP_ART_N_IB_S_GRP(TFIBLargeIntField * ElementIDGRP_ART_N_IB_S_GRP)=0;

   __property TFIBWideStringField * ElementNAME_ART_N_IB_S_GRP = {read = get_ElementNAME_ART_N_IB_S_GRP , write = set_ElementNAME_ART_N_IB_S_GRP};
   virtual TFIBWideStringField * get_ElementNAME_ART_N_IB_S_GRP(void)=0;
   virtual void set_ElementNAME_ART_N_IB_S_GRP(TFIBWideStringField * ElementNAME_ART_N_IB_S_GRP)=0;

   __property TFIBLargeIntField * ElementIDNABOR_ART_N_IB_S_GRP = {read = get_ElementIDNABOR_ART_N_IB_S_GRP , write = set_ElementIDNABOR_ART_N_IB_S_GRP};
   virtual TFIBLargeIntField * get_ElementIDNABOR_ART_N_IB_S_GRP(void)=0;
   virtual void set_ElementIDNABOR_ART_N_IB_S_GRP(TFIBLargeIntField * ElementIDNABOR_ART_N_IB_S_GRP)=0;

   __property __int64 IdGroupElement = {read = get_IdGroupElement , write = set_IdGroupElement};
   virtual __int64 get_IdGroupElement(void)=0;
   virtual void set_IdGroupElement(__int64 IdGroupElement)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual bool OpenTable(__int64 id_group_element)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_group_element, __int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IART_DMSprNaborInfBlockSostavGrp __uuidof(IART_DMSprNaborInfBlockSostavGrp)
#endif
