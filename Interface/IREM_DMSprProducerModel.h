#ifndef UIREM_DMSprProducerModelH
#define UIREM_DMSprProducerModelH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprProducerModel)) IREM_DMSprProducerModel : public IMainInterface
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

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TFIBLargeIntField * TableID_REM_SPRMODEL = {read = get_TableID_REM_SPRMODEL , write = set_TableID_REM_SPRMODEL};
   virtual TFIBLargeIntField * get_TableID_REM_SPRMODEL(void)=0;
   virtual void set_TableID_REM_SPRMODEL(TFIBLargeIntField * TableID_REM_SPRMODEL)=0;

   __property TFIBWideStringField * TableCODE_REM_SPRMODEL = {read = get_TableCODE_REM_SPRMODEL , write = set_TableCODE_REM_SPRMODEL};
   virtual TFIBWideStringField * get_TableCODE_REM_SPRMODEL(void)=0;
   virtual void set_TableCODE_REM_SPRMODEL(TFIBWideStringField * TableCODE_REM_SPRMODEL)=0;

   __property TFIBWideStringField * TableNAME_REM_SPRMODEL = {read = get_TableNAME_REM_SPRMODEL , write = set_TableNAME_REM_SPRMODEL};
   virtual TFIBWideStringField * get_TableNAME_REM_SPRMODEL(void)=0;
   virtual void set_TableNAME_REM_SPRMODEL(TFIBWideStringField * TableNAME_REM_SPRMODEL)=0;

   __property TFIBLargeIntField * ElementID_REM_SPRMODEL = {read = get_ElementID_REM_SPRMODEL , write = set_ElementID_REM_SPRMODEL};
   virtual TFIBLargeIntField * get_ElementID_REM_SPRMODEL(void)=0;
   virtual void set_ElementID_REM_SPRMODEL(TFIBLargeIntField * ElementID_REM_SPRMODEL)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SPRMODEL = {read = get_ElementIDBASE_REM_SPRMODEL , write = set_ElementIDBASE_REM_SPRMODEL};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SPRMODEL(void)=0;
   virtual void set_ElementIDBASE_REM_SPRMODEL(TFIBLargeIntField * ElementIDBASE_REM_SPRMODEL)=0;

   __property TFIBWideStringField * ElementGID_REM_SPRMODEL = {read = get_ElementGID_REM_SPRMODEL , write = set_ElementGID_REM_SPRMODEL};
   virtual TFIBWideStringField * get_ElementGID_REM_SPRMODEL(void)=0;
   virtual void set_ElementGID_REM_SPRMODEL(TFIBWideStringField * ElementGID_REM_SPRMODEL)=0;

   __property TFIBLargeIntField * ElementIDPR_REM_SPRMODEL = {read = get_ElementIDPR_REM_SPRMODEL , write = set_ElementIDPR_REM_SPRMODEL};
   virtual TFIBLargeIntField * get_ElementIDPR_REM_SPRMODEL(void)=0;
   virtual void set_ElementIDPR_REM_SPRMODEL(TFIBLargeIntField * ElementIDPR_REM_SPRMODEL)=0;

   __property TFIBLargeIntField * ElementIDGRP_REM_SPRMODEL = {read = get_ElementIDGRP_REM_SPRMODEL , write = set_ElementIDGRP_REM_SPRMODEL};
   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SPRMODEL(void)=0;
   virtual void set_ElementIDGRP_REM_SPRMODEL(TFIBLargeIntField * ElementIDGRP_REM_SPRMODEL)=0;

   __property TFIBLargeIntField * ElementIDMODEL_REM_SPRMODEL = {read = get_ElementIDMODEL_REM_SPRMODEL , write = set_ElementIDMODEL_REM_SPRMODEL};
   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SPRMODEL(void)=0;
   virtual void set_ElementIDMODEL_REM_SPRMODEL(TFIBLargeIntField * ElementIDMODEL_REM_SPRMODEL)=0;

   __property TFIBWideStringField * ElementCODE_REM_SPRMODEL = {read = get_ElementCODE_REM_SPRMODEL , write = set_ElementCODE_REM_SPRMODEL};
   virtual TFIBWideStringField * get_ElementCODE_REM_SPRMODEL(void)=0;
   virtual void set_ElementCODE_REM_SPRMODEL(TFIBWideStringField * ElementCODE_REM_SPRMODEL)=0;

   __property TFIBWideStringField * ElementNAME_REM_SPRMODEL = {read = get_ElementNAME_REM_SPRMODEL , write = set_ElementNAME_REM_SPRMODEL};
   virtual TFIBWideStringField * get_ElementNAME_REM_SPRMODEL(void)=0;
   virtual void set_ElementNAME_REM_SPRMODEL(TFIBWideStringField * ElementNAME_REM_SPRMODEL)=0;

   __property TFIBWideStringField * ElementNAME_REM_SMODEL = {read = get_ElementNAME_REM_SMODEL , write = set_ElementNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL(void)=0;
   virtual void set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL)=0;

   __property TFIBWideStringField * TableNAME_REM_SMODEL = {read = get_TableNAME_REM_SMODEL , write = set_TableNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void)=0;
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)=0;

   __property TFIBLargeIntField * TableIDPR_REM_SPRMODEL = {read = get_TableIDPR_REM_SPRMODEL , write = set_TableIDPR_REM_SPRMODEL};
   virtual TFIBLargeIntField * get_TableIDPR_REM_SPRMODEL(void)=0;
   virtual void set_TableIDPR_REM_SPRMODEL(TFIBLargeIntField * TableIDPR_REM_SPRMODEL)=0;

   __property TFIBLargeIntField * TableIDGRP_REM_SPRMODEL = {read = get_TableIDGRP_REM_SPRMODEL , write = set_TableIDGRP_REM_SPRMODEL};
   virtual TFIBLargeIntField * get_TableIDGRP_REM_SPRMODEL(void)=0;
   virtual void set_TableIDGRP_REM_SPRMODEL(TFIBLargeIntField * TableIDGRP_REM_SPRMODEL)=0;

   __property TFIBWideStringField * TableNAME_SBRAND = {read = get_TableNAME_SBRAND , write = set_TableNAME_SBRAND};
   virtual TFIBWideStringField * get_TableNAME_SBRAND(void)=0;
   virtual void set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)=0;

   __property TFIBWideStringField * TableNAME_SPRODUCER = {read = get_TableNAME_SPRODUCER , write = set_TableNAME_SPRODUCER};
   virtual TFIBWideStringField * get_TableNAME_SPRODUCER(void)=0;
   virtual void set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER)=0;

   __property TFIBWideStringField * TableNAME_REM_SACTCATEGORY = {read = get_TableNAME_REM_SACTCATEGORY , write = set_TableNAME_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_TableNAME_REM_SACTCATEGORY(void)=0;
   virtual void set_TableNAME_REM_SACTCATEGORY(TFIBWideStringField * TableNAME_REM_SACTCATEGORY)=0;

   __property TFIBWideStringField * TableNAME_REM_STYPEDEVICE = {read = get_TableNAME_REM_STYPEDEVICE , write = set_TableNAME_REM_STYPEDEVICE};
   virtual TFIBWideStringField * get_TableNAME_REM_STYPEDEVICE(void)=0;
   virtual void set_TableNAME_REM_STYPEDEVICE(TFIBWideStringField * TableNAME_REM_STYPEDEVICE)=0;

   __property TFIBLargeIntField * ElementIDBRAND_REM_SPRMODEL = {read = get_ElementIDBRAND_REM_SPRMODEL , write = set_ElementIDBRAND_REM_SPRMODEL};
   virtual TFIBLargeIntField * get_ElementIDBRAND_REM_SPRMODEL(void)=0;
   virtual void set_ElementIDBRAND_REM_SPRMODEL(TFIBLargeIntField * ElementIDBRAND_REM_SPRMODEL)=0;

   __property TFIBLargeIntField * ElementIDACTCATEGORY_REM_SPRMODEL = {read = get_ElementIDACTCATEGORY_REM_SPRMODEL , write = set_ElementIDACTCATEGORY_REM_SPRMODEL};
   virtual TFIBLargeIntField * get_ElementIDACTCATEGORY_REM_SPRMODEL(void)=0;
   virtual void set_ElementIDACTCATEGORY_REM_SPRMODEL(TFIBLargeIntField * ElementIDACTCATEGORY_REM_SPRMODEL)=0;

   __property TFIBLargeIntField * ElementIDTYPEDEVICE_REM_SPRMODEL = {read = get_ElementIDTYPEDEVICE_REM_SPRMODEL , write = set_ElementIDTYPEDEVICE_REM_SPRMODEL};
   virtual TFIBLargeIntField * get_ElementIDTYPEDEVICE_REM_SPRMODEL(void)=0;
   virtual void set_ElementIDTYPEDEVICE_REM_SPRMODEL(TFIBLargeIntField * ElementIDTYPEDEVICE_REM_SPRMODEL)=0;

   __property TFIBWideStringField * ElementNAME_SBRAND = {read = get_ElementNAME_SBRAND , write = set_ElementNAME_SBRAND};
   virtual TFIBWideStringField * get_ElementNAME_SBRAND(void)=0;
   virtual void set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND)=0;

   __property TFIBWideStringField * ElementNAME_SPRODUCER = {read = get_ElementNAME_SPRODUCER , write = set_ElementNAME_SPRODUCER};
   virtual TFIBWideStringField * get_ElementNAME_SPRODUCER(void)=0;
   virtual void set_ElementNAME_SPRODUCER(TFIBWideStringField * ElementNAME_SPRODUCER)=0;

   __property TFIBWideStringField * ElementNAME_REM_SACTCATEGORY = {read = get_ElementNAME_REM_SACTCATEGORY , write = set_ElementNAME_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_ElementNAME_REM_SACTCATEGORY(void)=0;
   virtual void set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY)=0;

   __property TFIBWideStringField * ElementNAME_REM_STYPEDEVICE = {read = get_ElementNAME_REM_STYPEDEVICE , write = set_ElementNAME_REM_STYPEDEVICE};
   virtual TFIBWideStringField * get_ElementNAME_REM_STYPEDEVICE(void)=0;
   virtual void set_ElementNAME_REM_STYPEDEVICE(TFIBWideStringField * ElementNAME_REM_STYPEDEVICE)=0;

   __property __int64 IdGroupElement = {read = get_IdGroupElement , write = set_IdGroupElement};
   virtual __int64 get_IdGroupElement(void)=0;
   virtual void set_IdGroupElement(__int64 IdGroupElement)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void OpenTable(__int64 id_group_element, __int64 id_grp, bool all)=0;
   virtual bool NewElement(__int64 id_group_element, __int64 id_grp)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool SaveElement(void)=0;
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_element)=0;
};
#define IID_IREM_DMSprProducerModel __uuidof(IREM_DMSprProducerModel)
#endif
