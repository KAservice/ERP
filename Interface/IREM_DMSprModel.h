#ifndef UIREM_DMSprModelH
#define UIREM_DMSprModelH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprModel)) IREM_DMSprModel : public IMainInterface
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

   __property TpFIBQuery * pFIBQuery = {read = get_pFIBQuery , write = set_pFIBQuery};
   virtual TpFIBQuery * get_pFIBQuery(void)=0;
   virtual void set_pFIBQuery(TpFIBQuery * pFIBQuery)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBLargeIntField * TableID_REM_SMODEL = {read = get_TableID_REM_SMODEL , write = set_TableID_REM_SMODEL};
   virtual TFIBLargeIntField * get_TableID_REM_SMODEL(void)=0;
   virtual void set_TableID_REM_SMODEL(TFIBLargeIntField * TableID_REM_SMODEL)=0;

   __property TFIBWideStringField * TableGID_REM_SMODEL = {read = get_TableGID_REM_SMODEL , write = set_TableGID_REM_SMODEL};
   virtual TFIBWideStringField * get_TableGID_REM_SMODEL(void)=0;
   virtual void set_TableGID_REM_SMODEL(TFIBWideStringField * TableGID_REM_SMODEL)=0;

   __property TFIBLargeIntField * TableIDGRP_REM_SMODEL = {read = get_TableIDGRP_REM_SMODEL , write = set_TableIDGRP_REM_SMODEL};
   virtual TFIBLargeIntField * get_TableIDGRP_REM_SMODEL(void)=0;
   virtual void set_TableIDGRP_REM_SMODEL(TFIBLargeIntField * TableIDGRP_REM_SMODEL)=0;

   __property TFIBWideStringField * TableNAME_REM_SMODEL = {read = get_TableNAME_REM_SMODEL , write = set_TableNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void)=0;
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SMODEL = {read = get_TableIDBASE_REM_SMODEL , write = set_TableIDBASE_REM_SMODEL};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SMODEL(void)=0;
   virtual void set_TableIDBASE_REM_SMODEL(TFIBLargeIntField * TableIDBASE_REM_SMODEL)=0;

   __property TFIBLargeIntField * ElementID_REM_SMODEL = {read = get_ElementID_REM_SMODEL , write = set_ElementID_REM_SMODEL};
   virtual TFIBLargeIntField * get_ElementID_REM_SMODEL(void)=0;
   virtual void set_ElementID_REM_SMODEL(TFIBLargeIntField * ElementID_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementGID_REM_SMODEL = {read = get_ElementGID_REM_SMODEL , write = set_ElementGID_REM_SMODEL};
   virtual TFIBWideStringField * get_ElementGID_REM_SMODEL(void)=0;
   virtual void set_ElementGID_REM_SMODEL(TFIBWideStringField * ElementGID_REM_SMODEL)=0;

   __property TFIBLargeIntField * ElementIDGRP_REM_SMODEL = {read = get_ElementIDGRP_REM_SMODEL , write = set_ElementIDGRP_REM_SMODEL};
   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SMODEL(void)=0;
   virtual void set_ElementIDGRP_REM_SMODEL(TFIBLargeIntField * ElementIDGRP_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementNAME_REM_SMODEL = {read = get_ElementNAME_REM_SMODEL , write = set_ElementNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL(void)=0;
   virtual void set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SMODEL = {read = get_ElementIDBASE_REM_SMODEL , write = set_ElementIDBASE_REM_SMODEL};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SMODEL(void)=0;
   virtual void set_ElementIDBASE_REM_SMODEL(TFIBLargeIntField * ElementIDBASE_REM_SMODEL)=0;

   __property TFIBLargeIntField * ElementIDNOM_REM_SMODEL = {read = get_ElementIDNOM_REM_SMODEL , write = set_ElementIDNOM_REM_SMODEL};
   virtual TFIBLargeIntField * get_ElementIDNOM_REM_SMODEL(void)=0;
   virtual void set_ElementIDNOM_REM_SMODEL(TFIBLargeIntField * ElementIDNOM_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementSTRCODE_REM_SMODEL = {read = get_ElementSTRCODE_REM_SMODEL , write = set_ElementSTRCODE_REM_SMODEL};
   virtual TFIBWideStringField * get_ElementSTRCODE_REM_SMODEL(void)=0;
   virtual void set_ElementSTRCODE_REM_SMODEL(TFIBWideStringField * ElementSTRCODE_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementNAMENOM = {read = get_ElementNAMENOM , write = set_ElementNAMENOM};
   virtual TFIBWideStringField * get_ElementNAMENOM(void)=0;
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)=0;

   __property TFIBLargeIntField * ElementIDBRAND_REM_SMODEL = {read = get_ElementIDBRAND_REM_SMODEL , write = set_ElementIDBRAND_REM_SMODEL};
   virtual TFIBLargeIntField * get_ElementIDBRAND_REM_SMODEL(void)=0;
   virtual void set_ElementIDBRAND_REM_SMODEL(TFIBLargeIntField * ElementIDBRAND_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementNAME_SBRAND = {read = get_ElementNAME_SBRAND , write = set_ElementNAME_SBRAND};
   virtual TFIBWideStringField * get_ElementNAME_SBRAND(void)=0;
   virtual void set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND)=0;

   __property TFIBWideStringField * TableSTRCODE_REM_SMODEL = {read = get_TableSTRCODE_REM_SMODEL , write = set_TableSTRCODE_REM_SMODEL};
   virtual TFIBWideStringField * get_TableSTRCODE_REM_SMODEL(void)=0;
   virtual void set_TableSTRCODE_REM_SMODEL(TFIBWideStringField * TableSTRCODE_REM_SMODEL)=0;

   __property TFIBLargeIntField * TableIDBRAND_REM_SMODEL = {read = get_TableIDBRAND_REM_SMODEL , write = set_TableIDBRAND_REM_SMODEL};
   virtual TFIBLargeIntField * get_TableIDBRAND_REM_SMODEL(void)=0;
   virtual void set_TableIDBRAND_REM_SMODEL(TFIBLargeIntField * TableIDBRAND_REM_SMODEL)=0;

   __property TFIBLargeIntField * TableIDPRMODEL_REM_SMODEL = {read = get_TableIDPRMODEL_REM_SMODEL , write = set_TableIDPRMODEL_REM_SMODEL};
   virtual TFIBLargeIntField * get_TableIDPRMODEL_REM_SMODEL(void)=0;
   virtual void set_TableIDPRMODEL_REM_SMODEL(TFIBLargeIntField * TableIDPRMODEL_REM_SMODEL)=0;

   __property TFIBWideStringField * TableDESCR_REM_SMODEL = {read = get_TableDESCR_REM_SMODEL , write = set_TableDESCR_REM_SMODEL};
   virtual TFIBWideStringField * get_TableDESCR_REM_SMODEL(void)=0;
   virtual void set_TableDESCR_REM_SMODEL(TFIBWideStringField * TableDESCR_REM_SMODEL)=0;

   __property TFIBWideStringField * TableNAME_REM_SPRMODEL = {read = get_TableNAME_REM_SPRMODEL , write = set_TableNAME_REM_SPRMODEL};
   virtual TFIBWideStringField * get_TableNAME_REM_SPRMODEL(void)=0;
   virtual void set_TableNAME_REM_SPRMODEL(TFIBWideStringField * TableNAME_REM_SPRMODEL)=0;

   __property TFIBWideStringField * TableNAME_SBRAND = {read = get_TableNAME_SBRAND , write = set_TableNAME_SBRAND};
   virtual TFIBWideStringField * get_TableNAME_SBRAND(void)=0;
   virtual void set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)=0;

   __property TFIBLargeIntField * TableIDNOM_REM_SMODEL = {read = get_TableIDNOM_REM_SMODEL , write = set_TableIDNOM_REM_SMODEL};
   virtual TFIBLargeIntField * get_TableIDNOM_REM_SMODEL(void)=0;
   virtual void set_TableIDNOM_REM_SMODEL(TFIBLargeIntField * TableIDNOM_REM_SMODEL)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBLargeIntField * ElementIDPRMODEL_REM_SMODEL = {read = get_ElementIDPRMODEL_REM_SMODEL , write = set_ElementIDPRMODEL_REM_SMODEL};
   virtual TFIBLargeIntField * get_ElementIDPRMODEL_REM_SMODEL(void)=0;
   virtual void set_ElementIDPRMODEL_REM_SMODEL(TFIBLargeIntField * ElementIDPRMODEL_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementDESCR_REM_SMODEL = {read = get_ElementDESCR_REM_SMODEL , write = set_ElementDESCR_REM_SMODEL};
   virtual TFIBWideStringField * get_ElementDESCR_REM_SMODEL(void)=0;
   virtual void set_ElementDESCR_REM_SMODEL(TFIBWideStringField * ElementDESCR_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementCODE_REM_SMODEL = {read = get_ElementCODE_REM_SMODEL , write = set_ElementCODE_REM_SMODEL};
   virtual TFIBWideStringField * get_ElementCODE_REM_SMODEL(void)=0;
   virtual void set_ElementCODE_REM_SMODEL(TFIBWideStringField * ElementCODE_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementNAME_REM_SPRMODEL = {read = get_ElementNAME_REM_SPRMODEL , write = set_ElementNAME_REM_SPRMODEL};
   virtual TFIBWideStringField * get_ElementNAME_REM_SPRMODEL(void)=0;
   virtual void set_ElementNAME_REM_SPRMODEL(TFIBWideStringField * ElementNAME_REM_SPRMODEL)=0;

   __property TFIBLargeIntField * ElementIDMODELNEISPR_REM_SMODEL = {read = get_ElementIDMODELNEISPR_REM_SMODEL , write = set_ElementIDMODELNEISPR_REM_SMODEL};
   virtual TFIBLargeIntField * get_ElementIDMODELNEISPR_REM_SMODEL(void)=0;
   virtual void set_ElementIDMODELNEISPR_REM_SMODEL(TFIBLargeIntField * ElementIDMODELNEISPR_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementNAME_REM_SMODEL_NEISPR = {read = get_ElementNAME_REM_SMODEL_NEISPR , write = set_ElementNAME_REM_SMODEL_NEISPR};
   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL_NEISPR(void)=0;
   virtual void set_ElementNAME_REM_SMODEL_NEISPR(TFIBWideStringField * ElementNAME_REM_SMODEL_NEISPR)=0;

   __property TFIBWideStringField * TableCODE_REM_SMODEL = {read = get_TableCODE_REM_SMODEL , write = set_TableCODE_REM_SMODEL};
   virtual TFIBWideStringField * get_TableCODE_REM_SMODEL(void)=0;
   virtual void set_TableCODE_REM_SMODEL(TFIBWideStringField * TableCODE_REM_SMODEL)=0;

   __property TFIBLargeIntField * TableIDMODELNEISPR_REM_SMODEL = {read = get_TableIDMODELNEISPR_REM_SMODEL , write = set_TableIDMODELNEISPR_REM_SMODEL};
   virtual TFIBLargeIntField * get_TableIDMODELNEISPR_REM_SMODEL(void)=0;
   virtual void set_TableIDMODELNEISPR_REM_SMODEL(TFIBLargeIntField * TableIDMODELNEISPR_REM_SMODEL)=0;

   __property TFIBWideStringField * TableNAME_REM_SMODEL_NEISPR = {read = get_TableNAME_REM_SMODEL_NEISPR , write = set_TableNAME_REM_SMODEL_NEISPR};
   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL_NEISPR(void)=0;
   virtual void set_TableNAME_REM_SMODEL_NEISPR(TFIBWideStringField * TableNAME_REM_SMODEL_NEISPR)=0;

   __property TFIBLargeIntField * ElementIDPRODUCER_REM_SMODEL = {read = get_ElementIDPRODUCER_REM_SMODEL , write = set_ElementIDPRODUCER_REM_SMODEL};
   virtual TFIBLargeIntField * get_ElementIDPRODUCER_REM_SMODEL(void)=0;
   virtual void set_ElementIDPRODUCER_REM_SMODEL(TFIBLargeIntField * ElementIDPRODUCER_REM_SMODEL)=0;

   __property TFIBLargeIntField * ElementIDACTCATEGORY_REM_SMODEL = {read = get_ElementIDACTCATEGORY_REM_SMODEL , write = set_ElementIDACTCATEGORY_REM_SMODEL};
   virtual TFIBLargeIntField * get_ElementIDACTCATEGORY_REM_SMODEL(void)=0;
   virtual void set_ElementIDACTCATEGORY_REM_SMODEL(TFIBLargeIntField * ElementIDACTCATEGORY_REM_SMODEL)=0;

   __property TFIBLargeIntField * ElementIDTYPEDEVICE_REM_SMODEL = {read = get_ElementIDTYPEDEVICE_REM_SMODEL , write = set_ElementIDTYPEDEVICE_REM_SMODEL};
   virtual TFIBLargeIntField * get_ElementIDTYPEDEVICE_REM_SMODEL(void)=0;
   virtual void set_ElementIDTYPEDEVICE_REM_SMODEL(TFIBLargeIntField * ElementIDTYPEDEVICE_REM_SMODEL)=0;

   __property TFIBWideStringField * ElementNAME_SPRODUCER = {read = get_ElementNAME_SPRODUCER , write = set_ElementNAME_SPRODUCER};
   virtual TFIBWideStringField * get_ElementNAME_SPRODUCER(void)=0;
   virtual void set_ElementNAME_SPRODUCER(TFIBWideStringField * ElementNAME_SPRODUCER)=0;

   __property TFIBWideStringField * ElementNAME_REM_SACTCATEGORY = {read = get_ElementNAME_REM_SACTCATEGORY , write = set_ElementNAME_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_ElementNAME_REM_SACTCATEGORY(void)=0;
   virtual void set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY)=0;

   __property TFIBWideStringField * ElementNAME_REM_STYPEDEVICE = {read = get_ElementNAME_REM_STYPEDEVICE , write = set_ElementNAME_REM_STYPEDEVICE};
   virtual TFIBWideStringField * get_ElementNAME_REM_STYPEDEVICE(void)=0;
   virtual void set_ElementNAME_REM_STYPEDEVICE(TFIBWideStringField * ElementNAME_REM_STYPEDEVICE)=0;

   __property TFIBLargeIntField * TableIDPRODUCER_REM_SMODEL = {read = get_TableIDPRODUCER_REM_SMODEL , write = set_TableIDPRODUCER_REM_SMODEL};
   virtual TFIBLargeIntField * get_TableIDPRODUCER_REM_SMODEL(void)=0;
   virtual void set_TableIDPRODUCER_REM_SMODEL(TFIBLargeIntField * TableIDPRODUCER_REM_SMODEL)=0;

   __property TFIBLargeIntField * TableIDACTCATEGORY_REM_SMODEL = {read = get_TableIDACTCATEGORY_REM_SMODEL , write = set_TableIDACTCATEGORY_REM_SMODEL};
   virtual TFIBLargeIntField * get_TableIDACTCATEGORY_REM_SMODEL(void)=0;
   virtual void set_TableIDACTCATEGORY_REM_SMODEL(TFIBLargeIntField * TableIDACTCATEGORY_REM_SMODEL)=0;

   __property TFIBLargeIntField * TableIDTYPEDEVICE_REM_SMODEL = {read = get_TableIDTYPEDEVICE_REM_SMODEL , write = set_TableIDTYPEDEVICE_REM_SMODEL};
   virtual TFIBLargeIntField * get_TableIDTYPEDEVICE_REM_SMODEL(void)=0;
   virtual void set_TableIDTYPEDEVICE_REM_SMODEL(TFIBLargeIntField * TableIDTYPEDEVICE_REM_SMODEL)=0;

   __property TFIBWideStringField * TableNAME_SPRODUCER = {read = get_TableNAME_SPRODUCER , write = set_TableNAME_SPRODUCER};
   virtual TFIBWideStringField * get_TableNAME_SPRODUCER(void)=0;
   virtual void set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER)=0;

   __property TFIBWideStringField * TableNAME_REM_SACTCATEGORY = {read = get_TableNAME_REM_SACTCATEGORY , write = set_TableNAME_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_TableNAME_REM_SACTCATEGORY(void)=0;
   virtual void set_TableNAME_REM_SACTCATEGORY(TFIBWideStringField * TableNAME_REM_SACTCATEGORY)=0;

   __property TFIBWideStringField * TableNAME_REM_STYPEDEVICE = {read = get_TableNAME_REM_STYPEDEVICE , write = set_TableNAME_REM_STYPEDEVICE};
   virtual TFIBWideStringField * get_TableNAME_REM_STYPEDEVICE(void)=0;
   virtual void set_TableNAME_REM_STYPEDEVICE(TFIBWideStringField * TableNAME_REM_STYPEDEVICE)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all)=0;
   virtual void OpenTable(__int64 id_grp, bool all)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void ChancheGrp(__int64 id_new_grp, __int64 id_el)=0;
   virtual __int64 GetIDElement(UnicodeString gid)=0;
   virtual UnicodeString GetGIDElement(__int64 id)=0;
   virtual __int64 GetIdGrpNom(__int64 id)=0;
   virtual __int64 FindPoNom(__int64 id_nom)=0;
};
#define IID_IREM_DMSprModel __uuidof(IREM_DMSprModel)
#endif
