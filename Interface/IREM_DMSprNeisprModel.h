#ifndef UIREM_DMSprNeisprModelH
#define UIREM_DMSprNeisprModelH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprNeisprModel)) IREM_DMSprNeisprModel : public IMainInterface
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

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_REM_SNEISPMODEL = {read = get_TableID_REM_SNEISPMODEL , write = set_TableID_REM_SNEISPMODEL};
   virtual TFIBLargeIntField * get_TableID_REM_SNEISPMODEL(void)=0;
   virtual void set_TableID_REM_SNEISPMODEL(TFIBLargeIntField * TableID_REM_SNEISPMODEL)=0;

   __property TFIBWideStringField * TableGID_REM_SNEISPMODEL = {read = get_TableGID_REM_SNEISPMODEL , write = set_TableGID_REM_SNEISPMODEL};
   virtual TFIBWideStringField * get_TableGID_REM_SNEISPMODEL(void)=0;
   virtual void set_TableGID_REM_SNEISPMODEL(TFIBWideStringField * TableGID_REM_SNEISPMODEL)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SNEISPMODEL = {read = get_TableIDBASE_REM_SNEISPMODEL , write = set_TableIDBASE_REM_SNEISPMODEL};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SNEISPMODEL(void)=0;
   virtual void set_TableIDBASE_REM_SNEISPMODEL(TFIBLargeIntField * TableIDBASE_REM_SNEISPMODEL)=0;

   __property TFIBWideStringField * TableDESCR_REM_SNEISPMODEL = {read = get_TableDESCR_REM_SNEISPMODEL , write = set_TableDESCR_REM_SNEISPMODEL};
   virtual TFIBWideStringField * get_TableDESCR_REM_SNEISPMODEL(void)=0;
   virtual void set_TableDESCR_REM_SNEISPMODEL(TFIBWideStringField * TableDESCR_REM_SNEISPMODEL)=0;

   __property TFIBLargeIntField * TableIDMODEL_REM_SNEISPMODEL = {read = get_TableIDMODEL_REM_SNEISPMODEL , write = set_TableIDMODEL_REM_SNEISPMODEL};
   virtual TFIBLargeIntField * get_TableIDMODEL_REM_SNEISPMODEL(void)=0;
   virtual void set_TableIDMODEL_REM_SNEISPMODEL(TFIBLargeIntField * TableIDMODEL_REM_SNEISPMODEL)=0;

   __property TFIBLargeIntField * TableIDNEISPR_REM_SNEISPMODEL = {read = get_TableIDNEISPR_REM_SNEISPMODEL , write = set_TableIDNEISPR_REM_SNEISPMODEL};
   virtual TFIBLargeIntField * get_TableIDNEISPR_REM_SNEISPMODEL(void)=0;
   virtual void set_TableIDNEISPR_REM_SNEISPMODEL(TFIBLargeIntField * TableIDNEISPR_REM_SNEISPMODEL)=0;

   __property TFIBWideStringField * TableNAME_REM_SNEISPR = {read = get_TableNAME_REM_SNEISPR , write = set_TableNAME_REM_SNEISPR};
   virtual TFIBWideStringField * get_TableNAME_REM_SNEISPR(void)=0;
   virtual void set_TableNAME_REM_SNEISPR(TFIBWideStringField * TableNAME_REM_SNEISPR)=0;

   __property TFIBLargeIntField * ElementID_REM_SNEISPMODEL = {read = get_ElementID_REM_SNEISPMODEL , write = set_ElementID_REM_SNEISPMODEL};
   virtual TFIBLargeIntField * get_ElementID_REM_SNEISPMODEL(void)=0;
   virtual void set_ElementID_REM_SNEISPMODEL(TFIBLargeIntField * ElementID_REM_SNEISPMODEL)=0;

   __property TFIBWideStringField * ElementGID_REM_SNEISPMODEL = {read = get_ElementGID_REM_SNEISPMODEL , write = set_ElementGID_REM_SNEISPMODEL};
   virtual TFIBWideStringField * get_ElementGID_REM_SNEISPMODEL(void)=0;
   virtual void set_ElementGID_REM_SNEISPMODEL(TFIBWideStringField * ElementGID_REM_SNEISPMODEL)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SNEISPMODEL = {read = get_ElementIDBASE_REM_SNEISPMODEL , write = set_ElementIDBASE_REM_SNEISPMODEL};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SNEISPMODEL(void)=0;
   virtual void set_ElementIDBASE_REM_SNEISPMODEL(TFIBLargeIntField * ElementIDBASE_REM_SNEISPMODEL)=0;

   __property TFIBWideStringField * ElementDESCR_REM_SNEISPMODEL = {read = get_ElementDESCR_REM_SNEISPMODEL , write = set_ElementDESCR_REM_SNEISPMODEL};
   virtual TFIBWideStringField * get_ElementDESCR_REM_SNEISPMODEL(void)=0;
   virtual void set_ElementDESCR_REM_SNEISPMODEL(TFIBWideStringField * ElementDESCR_REM_SNEISPMODEL)=0;

   __property TFIBLargeIntField * ElementIDMODEL_REM_SNEISPMODEL = {read = get_ElementIDMODEL_REM_SNEISPMODEL , write = set_ElementIDMODEL_REM_SNEISPMODEL};
   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SNEISPMODEL(void)=0;
   virtual void set_ElementIDMODEL_REM_SNEISPMODEL(TFIBLargeIntField * ElementIDMODEL_REM_SNEISPMODEL)=0;

   __property TFIBLargeIntField * ElementIDNEISPR_REM_SNEISPMODEL = {read = get_ElementIDNEISPR_REM_SNEISPMODEL , write = set_ElementIDNEISPR_REM_SNEISPMODEL};
   virtual TFIBLargeIntField * get_ElementIDNEISPR_REM_SNEISPMODEL(void)=0;
   virtual void set_ElementIDNEISPR_REM_SNEISPMODEL(TFIBLargeIntField * ElementIDNEISPR_REM_SNEISPMODEL)=0;

   __property TFIBWideStringField * ElementNAME_REM_SNEISPR = {read = get_ElementNAME_REM_SNEISPR , write = set_ElementNAME_REM_SNEISPR};
   virtual TFIBWideStringField * get_ElementNAME_REM_SNEISPR(void)=0;
   virtual void set_ElementNAME_REM_SNEISPR(TFIBWideStringField * ElementNAME_REM_SNEISPR)=0;

   __property TFIBWideStringField * TableNAME_REM_SNEISPMODEL = {read = get_TableNAME_REM_SNEISPMODEL , write = set_TableNAME_REM_SNEISPMODEL};
   virtual TFIBWideStringField * get_TableNAME_REM_SNEISPMODEL(void)=0;
   virtual void set_TableNAME_REM_SNEISPMODEL(TFIBWideStringField * TableNAME_REM_SNEISPMODEL)=0;

   __property TFIBWideStringField * ElementNAME_REM_SNEISPMODEL = {read = get_ElementNAME_REM_SNEISPMODEL , write = set_ElementNAME_REM_SNEISPMODEL};
   virtual TFIBWideStringField * get_ElementNAME_REM_SNEISPMODEL(void)=0;
   virtual void set_ElementNAME_REM_SNEISPMODEL(TFIBWideStringField * ElementNAME_REM_SNEISPMODEL)=0;

   __property TFIBLargeIntField * ElementIDMODELNEISPR_REM_SNEISPMODEL = {read = get_ElementIDMODELNEISPR_REM_SNEISPMODEL , write = set_ElementIDMODELNEISPR_REM_SNEISPMODEL};
   virtual TFIBLargeIntField * get_ElementIDMODELNEISPR_REM_SNEISPMODEL(void)=0;
   virtual void set_ElementIDMODELNEISPR_REM_SNEISPMODEL(TFIBLargeIntField * ElementIDMODELNEISPR_REM_SNEISPMODEL)=0;

   __property TFIBWideStringField * ElementNAME_REM_SMODEL = {read = get_ElementNAME_REM_SMODEL , write = set_ElementNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL(void)=0;
   virtual void set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL)=0;

   __property TFIBLargeIntField * TableIDMODELNEISPR_REM_SNEISPMODEL = {read = get_TableIDMODELNEISPR_REM_SNEISPMODEL , write = set_TableIDMODELNEISPR_REM_SNEISPMODEL};
   virtual TFIBLargeIntField * get_TableIDMODELNEISPR_REM_SNEISPMODEL(void)=0;
   virtual void set_TableIDMODELNEISPR_REM_SNEISPMODEL(TFIBLargeIntField * TableIDMODELNEISPR_REM_SNEISPMODEL)=0;

   __property TFIBWideStringField * TableNAME_REM_SMODEL = {read = get_TableNAME_REM_SMODEL , write = set_TableNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void)=0;
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)=0;

   virtual void OpenTable(__int64 id_model)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_model)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IREM_DMSprNeisprModel __uuidof(IREM_DMSprNeisprModel)
#endif
