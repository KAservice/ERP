#ifndef UIART_DMSprNaborInfBlockSostavH
#define UIART_DMSprNaborInfBlockSostavH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IART_DMSprNaborInfBlockSostav)) IART_DMSprNaborInfBlockSostav : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourcePodr = {read = get_DataSourcePodr , write = set_DataSourcePodr};
   virtual TDataSource * get_DataSourcePodr(void)=0;
   virtual void set_DataSourcePodr(TDataSource * DataSourcePodr)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TFIBLargeIntField * TableID_ART_N_IB_S = {read = get_TableID_ART_N_IB_S , write = set_TableID_ART_N_IB_S};
   virtual TFIBLargeIntField * get_TableID_ART_N_IB_S(void)=0;
   virtual void set_TableID_ART_N_IB_S(TFIBLargeIntField * TableID_ART_N_IB_S)=0;

   __property TFIBLargeIntField * TableIDBASE_ART_N_IB_S = {read = get_TableIDBASE_ART_N_IB_S , write = set_TableIDBASE_ART_N_IB_S};
   virtual TFIBLargeIntField * get_TableIDBASE_ART_N_IB_S(void)=0;
   virtual void set_TableIDBASE_ART_N_IB_S(TFIBLargeIntField * TableIDBASE_ART_N_IB_S)=0;

   __property TFIBWideStringField * TableGUID_ART_N_IB_S = {read = get_TableGUID_ART_N_IB_S , write = set_TableGUID_ART_N_IB_S};
   virtual TFIBWideStringField * get_TableGUID_ART_N_IB_S(void)=0;
   virtual void set_TableGUID_ART_N_IB_S(TFIBWideStringField * TableGUID_ART_N_IB_S)=0;

   __property TFIBDateTimeField * TablePOS_ISM_ART_N_IB_S = {read = get_TablePOS_ISM_ART_N_IB_S , write = set_TablePOS_ISM_ART_N_IB_S};
   virtual TFIBDateTimeField * get_TablePOS_ISM_ART_N_IB_S(void)=0;
   virtual void set_TablePOS_ISM_ART_N_IB_S(TFIBDateTimeField * TablePOS_ISM_ART_N_IB_S)=0;

   __property TFIBLargeIntField * TableIDGRP_ART_N_IB_S = {read = get_TableIDGRP_ART_N_IB_S , write = set_TableIDGRP_ART_N_IB_S};
   virtual TFIBLargeIntField * get_TableIDGRP_ART_N_IB_S(void)=0;
   virtual void set_TableIDGRP_ART_N_IB_S(TFIBLargeIntField * TableIDGRP_ART_N_IB_S)=0;

   __property TFIBLargeIntField * TableIDNABOR_ART_N_IB_S = {read = get_TableIDNABOR_ART_N_IB_S , write = set_TableIDNABOR_ART_N_IB_S};
   virtual TFIBLargeIntField * get_TableIDNABOR_ART_N_IB_S(void)=0;
   virtual void set_TableIDNABOR_ART_N_IB_S(TFIBLargeIntField * TableIDNABOR_ART_N_IB_S)=0;

   __property TFIBLargeIntField * TableIDIB_ART_N_IB_S = {read = get_TableIDIB_ART_N_IB_S , write = set_TableIDIB_ART_N_IB_S};
   virtual TFIBLargeIntField * get_TableIDIB_ART_N_IB_S(void)=0;
   virtual void set_TableIDIB_ART_N_IB_S(TFIBLargeIntField * TableIDIB_ART_N_IB_S)=0;

   __property TFIBWideStringField * TableNAME_ART_IB = {read = get_TableNAME_ART_IB , write = set_TableNAME_ART_IB};
   virtual TFIBWideStringField * get_TableNAME_ART_IB(void)=0;
   virtual void set_TableNAME_ART_IB(TFIBWideStringField * TableNAME_ART_IB)=0;

   __property TFIBLargeIntField * ElementID_ART_N_IB_S = {read = get_ElementID_ART_N_IB_S , write = set_ElementID_ART_N_IB_S};
   virtual TFIBLargeIntField * get_ElementID_ART_N_IB_S(void)=0;
   virtual void set_ElementID_ART_N_IB_S(TFIBLargeIntField * ElementID_ART_N_IB_S)=0;

   __property TFIBLargeIntField * ElementIDBASE_ART_N_IB_S = {read = get_ElementIDBASE_ART_N_IB_S , write = set_ElementIDBASE_ART_N_IB_S};
   virtual TFIBLargeIntField * get_ElementIDBASE_ART_N_IB_S(void)=0;
   virtual void set_ElementIDBASE_ART_N_IB_S(TFIBLargeIntField * ElementIDBASE_ART_N_IB_S)=0;

   __property TFIBWideStringField * ElementGUID_ART_N_IB_S = {read = get_ElementGUID_ART_N_IB_S , write = set_ElementGUID_ART_N_IB_S};
   virtual TFIBWideStringField * get_ElementGUID_ART_N_IB_S(void)=0;
   virtual void set_ElementGUID_ART_N_IB_S(TFIBWideStringField * ElementGUID_ART_N_IB_S)=0;

   __property TFIBDateTimeField * ElementPOS_ISM_ART_N_IB_S = {read = get_ElementPOS_ISM_ART_N_IB_S , write = set_ElementPOS_ISM_ART_N_IB_S};
   virtual TFIBDateTimeField * get_ElementPOS_ISM_ART_N_IB_S(void)=0;
   virtual void set_ElementPOS_ISM_ART_N_IB_S(TFIBDateTimeField * ElementPOS_ISM_ART_N_IB_S)=0;

   __property TFIBLargeIntField * ElementIDGRP_ART_N_IB_S = {read = get_ElementIDGRP_ART_N_IB_S , write = set_ElementIDGRP_ART_N_IB_S};
   virtual TFIBLargeIntField * get_ElementIDGRP_ART_N_IB_S(void)=0;
   virtual void set_ElementIDGRP_ART_N_IB_S(TFIBLargeIntField * ElementIDGRP_ART_N_IB_S)=0;

   __property TFIBLargeIntField * ElementIDNABOR_ART_N_IB_S = {read = get_ElementIDNABOR_ART_N_IB_S , write = set_ElementIDNABOR_ART_N_IB_S};
   virtual TFIBLargeIntField * get_ElementIDNABOR_ART_N_IB_S(void)=0;
   virtual void set_ElementIDNABOR_ART_N_IB_S(TFIBLargeIntField * ElementIDNABOR_ART_N_IB_S)=0;

   __property TFIBLargeIntField * ElementIDIB_ART_N_IB_S = {read = get_ElementIDIB_ART_N_IB_S , write = set_ElementIDIB_ART_N_IB_S};
   virtual TFIBLargeIntField * get_ElementIDIB_ART_N_IB_S(void)=0;
   virtual void set_ElementIDIB_ART_N_IB_S(TFIBLargeIntField * ElementIDIB_ART_N_IB_S)=0;

   __property TFIBWideStringField * ElementNAME_ART_IB = {read = get_ElementNAME_ART_IB , write = set_ElementNAME_ART_IB};
   virtual TFIBWideStringField * get_ElementNAME_ART_IB(void)=0;
   virtual void set_ElementNAME_ART_IB(TFIBWideStringField * ElementNAME_ART_IB)=0;

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

   virtual bool NewElement(__int64 id_group_element, __int64 id_grp)=0;
   virtual bool InsertElement(__int64 id_group_element, __int64 id_grp, __int64 id_ib)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool SaveElement(void)=0;
   virtual bool ChancheGrp(__int64 id_new_grp,__int64 id_element)=0;
   virtual bool OpenTable(__int64 id_group_element, __int64 id_grp, bool all)=0;
   virtual bool TableSaveIsmen(void)=0;
   virtual bool TableCancelIsmen(void)=0;
   virtual bool TableNewElement(__int64 id_group_element, __int64 id_grp)=0;
   virtual bool TableAppend(void)=0;
   virtual bool TableDelete(void)=0;
   virtual bool TableEdit(void)=0;
   virtual bool TablePost(void)=0;
};
#define IID_IART_DMSprNaborInfBlockSostav __uuidof(IART_DMSprNaborInfBlockSostav)
#endif
