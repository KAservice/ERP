#ifndef UIART_DMSprNaborInfBlockH
#define UIART_DMSprNaborInfBlockH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IART_DMSprNaborInfBlock)) IART_DMSprNaborInfBlock : public IMainInterface
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

   __property TFIBLargeIntField * TableID_ART_N_IB = {read = get_TableID_ART_N_IB , write = set_TableID_ART_N_IB};
   virtual TFIBLargeIntField * get_TableID_ART_N_IB(void)=0;
   virtual void set_TableID_ART_N_IB(TFIBLargeIntField * TableID_ART_N_IB)=0;

   __property TFIBLargeIntField * TableIDBASE_ART_N_IB = {read = get_TableIDBASE_ART_N_IB , write = set_TableIDBASE_ART_N_IB};
   virtual TFIBLargeIntField * get_TableIDBASE_ART_N_IB(void)=0;
   virtual void set_TableIDBASE_ART_N_IB(TFIBLargeIntField * TableIDBASE_ART_N_IB)=0;

   __property TFIBWideStringField * TableGUID_ART_N_IB = {read = get_TableGUID_ART_N_IB , write = set_TableGUID_ART_N_IB};
   virtual TFIBWideStringField * get_TableGUID_ART_N_IB(void)=0;
   virtual void set_TableGUID_ART_N_IB(TFIBWideStringField * TableGUID_ART_N_IB)=0;

   __property TFIBDateTimeField * TablePOS_ISM_ART_N_IB = {read = get_TablePOS_ISM_ART_N_IB , write = set_TablePOS_ISM_ART_N_IB};
   virtual TFIBDateTimeField * get_TablePOS_ISM_ART_N_IB(void)=0;
   virtual void set_TablePOS_ISM_ART_N_IB(TFIBDateTimeField * TablePOS_ISM_ART_N_IB)=0;

   __property TFIBLargeIntField * TableIDGRP_ART_N_IB = {read = get_TableIDGRP_ART_N_IB , write = set_TableIDGRP_ART_N_IB};
   virtual TFIBLargeIntField * get_TableIDGRP_ART_N_IB(void)=0;
   virtual void set_TableIDGRP_ART_N_IB(TFIBLargeIntField * TableIDGRP_ART_N_IB)=0;

   __property TFIBWideStringField * TableNAME_ART_N_IB = {read = get_TableNAME_ART_N_IB , write = set_TableNAME_ART_N_IB};
   virtual TFIBWideStringField * get_TableNAME_ART_N_IB(void)=0;
   virtual void set_TableNAME_ART_N_IB(TFIBWideStringField * TableNAME_ART_N_IB)=0;

   __property TFIBLargeIntField * ElementID_ART_N_IB = {read = get_ElementID_ART_N_IB , write = set_ElementID_ART_N_IB};
   virtual TFIBLargeIntField * get_ElementID_ART_N_IB(void)=0;
   virtual void set_ElementID_ART_N_IB(TFIBLargeIntField * ElementID_ART_N_IB)=0;

   __property TFIBLargeIntField * ElementIDBASE_ART_N_IB = {read = get_ElementIDBASE_ART_N_IB , write = set_ElementIDBASE_ART_N_IB};
   virtual TFIBLargeIntField * get_ElementIDBASE_ART_N_IB(void)=0;
   virtual void set_ElementIDBASE_ART_N_IB(TFIBLargeIntField * ElementIDBASE_ART_N_IB)=0;

   __property TFIBWideStringField * ElementGUID_ART_N_IB = {read = get_ElementGUID_ART_N_IB , write = set_ElementGUID_ART_N_IB};
   virtual TFIBWideStringField * get_ElementGUID_ART_N_IB(void)=0;
   virtual void set_ElementGUID_ART_N_IB(TFIBWideStringField * ElementGUID_ART_N_IB)=0;

   __property TFIBDateTimeField * ElementPOS_ISM_ART_N_IB = {read = get_ElementPOS_ISM_ART_N_IB , write = set_ElementPOS_ISM_ART_N_IB};
   virtual TFIBDateTimeField * get_ElementPOS_ISM_ART_N_IB(void)=0;
   virtual void set_ElementPOS_ISM_ART_N_IB(TFIBDateTimeField * ElementPOS_ISM_ART_N_IB)=0;

   __property TFIBLargeIntField * ElementIDGRP_ART_N_IB = {read = get_ElementIDGRP_ART_N_IB , write = set_ElementIDGRP_ART_N_IB};
   virtual TFIBLargeIntField * get_ElementIDGRP_ART_N_IB(void)=0;
   virtual void set_ElementIDGRP_ART_N_IB(TFIBLargeIntField * ElementIDGRP_ART_N_IB)=0;

   __property TFIBWideStringField * ElementNAME_ART_N_IB = {read = get_ElementNAME_ART_N_IB , write = set_ElementNAME_ART_N_IB};
   virtual TFIBWideStringField * get_ElementNAME_ART_N_IB(void)=0;
   virtual void set_ElementNAME_ART_N_IB(TFIBWideStringField * ElementNAME_ART_N_IB)=0;

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
#define IID_IART_DMSprNaborInfBlock __uuidof(IART_DMSprNaborInfBlock)
#endif
