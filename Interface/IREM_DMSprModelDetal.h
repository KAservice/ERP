#ifndef UIREM_DMSprModelDetalH
#define UIREM_DMSprModelDetalH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprModelDetal)) IREM_DMSprModelDetal : public IMainInterface
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

   __property TFIBLargeIntField * TableID_REM_SMODEL_DETAL = {read = get_TableID_REM_SMODEL_DETAL , write = set_TableID_REM_SMODEL_DETAL};
   virtual TFIBLargeIntField * get_TableID_REM_SMODEL_DETAL(void)=0;
   virtual void set_TableID_REM_SMODEL_DETAL(TFIBLargeIntField * TableID_REM_SMODEL_DETAL)=0;

   __property TFIBWideStringField * TableGID_REM_SMODEL_DETAL = {read = get_TableGID_REM_SMODEL_DETAL , write = set_TableGID_REM_SMODEL_DETAL};
   virtual TFIBWideStringField * get_TableGID_REM_SMODEL_DETAL(void)=0;
   virtual void set_TableGID_REM_SMODEL_DETAL(TFIBWideStringField * TableGID_REM_SMODEL_DETAL)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SMODEL_DETAL = {read = get_TableIDBASE_REM_SMODEL_DETAL , write = set_TableIDBASE_REM_SMODEL_DETAL};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SMODEL_DETAL(void)=0;
   virtual void set_TableIDBASE_REM_SMODEL_DETAL(TFIBLargeIntField * TableIDBASE_REM_SMODEL_DETAL)=0;

   __property TFIBLargeIntField * TableIDMODEL_REM_SMODEL_DETAL = {read = get_TableIDMODEL_REM_SMODEL_DETAL , write = set_TableIDMODEL_REM_SMODEL_DETAL};
   virtual TFIBLargeIntField * get_TableIDMODEL_REM_SMODEL_DETAL(void)=0;
   virtual void set_TableIDMODEL_REM_SMODEL_DETAL(TFIBLargeIntField * TableIDMODEL_REM_SMODEL_DETAL)=0;

   __property TFIBLargeIntField * TableIDTYPUSLA_REM_SMODEL_DETAL = {read = get_TableIDTYPUSLA_REM_SMODEL_DETAL , write = set_TableIDTYPUSLA_REM_SMODEL_DETAL};
   virtual TFIBLargeIntField * get_TableIDTYPUSLA_REM_SMODEL_DETAL(void)=0;
   virtual void set_TableIDTYPUSLA_REM_SMODEL_DETAL(TFIBLargeIntField * TableIDTYPUSLA_REM_SMODEL_DETAL)=0;

   __property TFIBLargeIntField * TableIDNOM_REM_SMODEL_DETAL = {read = get_TableIDNOM_REM_SMODEL_DETAL , write = set_TableIDNOM_REM_SMODEL_DETAL};
   virtual TFIBLargeIntField * get_TableIDNOM_REM_SMODEL_DETAL(void)=0;
   virtual void set_TableIDNOM_REM_SMODEL_DETAL(TFIBLargeIntField * TableIDNOM_REM_SMODEL_DETAL)=0;

   __property TFIBLargeIntField * TableIDPRNOM_REM_SMODEL_DETAL = {read = get_TableIDPRNOM_REM_SMODEL_DETAL , write = set_TableIDPRNOM_REM_SMODEL_DETAL};
   virtual TFIBLargeIntField * get_TableIDPRNOM_REM_SMODEL_DETAL(void)=0;
   virtual void set_TableIDPRNOM_REM_SMODEL_DETAL(TFIBLargeIntField * TableIDPRNOM_REM_SMODEL_DETAL)=0;

   __property TFIBWideStringField * TableNAME_REM_SMODEL_DETAL = {read = get_TableNAME_REM_SMODEL_DETAL , write = set_TableNAME_REM_SMODEL_DETAL};
   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL_DETAL(void)=0;
   virtual void set_TableNAME_REM_SMODEL_DETAL(TFIBWideStringField * TableNAME_REM_SMODEL_DETAL)=0;

   __property TFIBWideStringField * TablePARTNUM_REM_SMODEL_DETAL = {read = get_TablePARTNUM_REM_SMODEL_DETAL , write = set_TablePARTNUM_REM_SMODEL_DETAL};
   virtual TFIBWideStringField * get_TablePARTNUM_REM_SMODEL_DETAL(void)=0;
   virtual void set_TablePARTNUM_REM_SMODEL_DETAL(TFIBWideStringField * TablePARTNUM_REM_SMODEL_DETAL)=0;

   __property TFIBWideStringField * TableDESCR_REM_SMODEL_DETAL = {read = get_TableDESCR_REM_SMODEL_DETAL , write = set_TableDESCR_REM_SMODEL_DETAL};
   virtual TFIBWideStringField * get_TableDESCR_REM_SMODEL_DETAL(void)=0;
   virtual void set_TableDESCR_REM_SMODEL_DETAL(TFIBWideStringField * TableDESCR_REM_SMODEL_DETAL)=0;

   __property TFIBBCDField * TableKOL_REM_SMODEL_DETAL = {read = get_TableKOL_REM_SMODEL_DETAL , write = set_TableKOL_REM_SMODEL_DETAL};
   virtual TFIBBCDField * get_TableKOL_REM_SMODEL_DETAL(void)=0;
   virtual void set_TableKOL_REM_SMODEL_DETAL(TFIBBCDField * TableKOL_REM_SMODEL_DETAL)=0;

   __property TFIBWideStringField * TableNAME_REM_STYPUSLOV = {read = get_TableNAME_REM_STYPUSLOV , write = set_TableNAME_REM_STYPUSLOV};
   virtual TFIBWideStringField * get_TableNAME_REM_STYPUSLOV(void)=0;
   virtual void set_TableNAME_REM_STYPUSLOV(TFIBWideStringField * TableNAME_REM_STYPUSLOV)=0;

   __property TFIBIntegerField * TableCODENOM = {read = get_TableCODENOM , write = set_TableCODENOM};
   virtual TFIBIntegerField * get_TableCODENOM(void)=0;
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM)=0;

   __property TFIBWideStringField * TableARTNOM = {read = get_TableARTNOM , write = set_TableARTNOM};
   virtual TFIBWideStringField * get_TableARTNOM(void)=0;
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBIntegerField * TableCODE_SPRNOM = {read = get_TableCODE_SPRNOM , write = set_TableCODE_SPRNOM};
   virtual TFIBIntegerField * get_TableCODE_SPRNOM(void)=0;
   virtual void set_TableCODE_SPRNOM(TFIBIntegerField * TableCODE_SPRNOM)=0;

   __property TFIBWideStringField * TableART_SPRNOM = {read = get_TableART_SPRNOM , write = set_TableART_SPRNOM};
   virtual TFIBWideStringField * get_TableART_SPRNOM(void)=0;
   virtual void set_TableART_SPRNOM(TFIBWideStringField * TableART_SPRNOM)=0;

   __property TFIBWideStringField * TableNAME_SPRNOM = {read = get_TableNAME_SPRNOM , write = set_TableNAME_SPRNOM};
   virtual TFIBWideStringField * get_TableNAME_SPRNOM(void)=0;
   virtual void set_TableNAME_SPRNOM(TFIBWideStringField * TableNAME_SPRNOM)=0;

   __property TFIBLargeIntField * ElementID_REM_SMODEL_DETAL = {read = get_ElementID_REM_SMODEL_DETAL , write = set_ElementID_REM_SMODEL_DETAL};
   virtual TFIBLargeIntField * get_ElementID_REM_SMODEL_DETAL(void)=0;
   virtual void set_ElementID_REM_SMODEL_DETAL(TFIBLargeIntField * ElementID_REM_SMODEL_DETAL)=0;

   __property TFIBWideStringField * ElementGID_REM_SMODEL_DETAL = {read = get_ElementGID_REM_SMODEL_DETAL , write = set_ElementGID_REM_SMODEL_DETAL};
   virtual TFIBWideStringField * get_ElementGID_REM_SMODEL_DETAL(void)=0;
   virtual void set_ElementGID_REM_SMODEL_DETAL(TFIBWideStringField * ElementGID_REM_SMODEL_DETAL)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SMODEL_DETAL = {read = get_ElementIDBASE_REM_SMODEL_DETAL , write = set_ElementIDBASE_REM_SMODEL_DETAL};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SMODEL_DETAL(void)=0;
   virtual void set_ElementIDBASE_REM_SMODEL_DETAL(TFIBLargeIntField * ElementIDBASE_REM_SMODEL_DETAL)=0;

   __property TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_DETAL = {read = get_ElementIDMODEL_REM_SMODEL_DETAL , write = set_ElementIDMODEL_REM_SMODEL_DETAL};
   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SMODEL_DETAL(void)=0;
   virtual void set_ElementIDMODEL_REM_SMODEL_DETAL(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_DETAL)=0;

   __property TFIBLargeIntField * ElementIDTYPUSLA_REM_SMODEL_DETAL = {read = get_ElementIDTYPUSLA_REM_SMODEL_DETAL , write = set_ElementIDTYPUSLA_REM_SMODEL_DETAL};
   virtual TFIBLargeIntField * get_ElementIDTYPUSLA_REM_SMODEL_DETAL(void)=0;
   virtual void set_ElementIDTYPUSLA_REM_SMODEL_DETAL(TFIBLargeIntField * ElementIDTYPUSLA_REM_SMODEL_DETAL)=0;

   __property TFIBLargeIntField * ElementIDNOM_REM_SMODEL_DETAL = {read = get_ElementIDNOM_REM_SMODEL_DETAL , write = set_ElementIDNOM_REM_SMODEL_DETAL};
   virtual TFIBLargeIntField * get_ElementIDNOM_REM_SMODEL_DETAL(void)=0;
   virtual void set_ElementIDNOM_REM_SMODEL_DETAL(TFIBLargeIntField * ElementIDNOM_REM_SMODEL_DETAL)=0;

   __property TFIBLargeIntField * ElementIDPRNOM_REM_SMODEL_DETAL = {read = get_ElementIDPRNOM_REM_SMODEL_DETAL , write = set_ElementIDPRNOM_REM_SMODEL_DETAL};
   virtual TFIBLargeIntField * get_ElementIDPRNOM_REM_SMODEL_DETAL(void)=0;
   virtual void set_ElementIDPRNOM_REM_SMODEL_DETAL(TFIBLargeIntField * ElementIDPRNOM_REM_SMODEL_DETAL)=0;

   __property TFIBWideStringField * ElementNAME_REM_SMODEL_DETAL = {read = get_ElementNAME_REM_SMODEL_DETAL , write = set_ElementNAME_REM_SMODEL_DETAL};
   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL_DETAL(void)=0;
   virtual void set_ElementNAME_REM_SMODEL_DETAL(TFIBWideStringField * ElementNAME_REM_SMODEL_DETAL)=0;

   __property TFIBWideStringField * ElementPARTNUM_REM_SMODEL_DETAL = {read = get_ElementPARTNUM_REM_SMODEL_DETAL , write = set_ElementPARTNUM_REM_SMODEL_DETAL};
   virtual TFIBWideStringField * get_ElementPARTNUM_REM_SMODEL_DETAL(void)=0;
   virtual void set_ElementPARTNUM_REM_SMODEL_DETAL(TFIBWideStringField * ElementPARTNUM_REM_SMODEL_DETAL)=0;

   __property TFIBWideStringField * ElementDESCR_REM_SMODEL_DETAL = {read = get_ElementDESCR_REM_SMODEL_DETAL , write = set_ElementDESCR_REM_SMODEL_DETAL};
   virtual TFIBWideStringField * get_ElementDESCR_REM_SMODEL_DETAL(void)=0;
   virtual void set_ElementDESCR_REM_SMODEL_DETAL(TFIBWideStringField * ElementDESCR_REM_SMODEL_DETAL)=0;

   __property TFIBBCDField * ElementKOL_REM_SMODEL_DETAL = {read = get_ElementKOL_REM_SMODEL_DETAL , write = set_ElementKOL_REM_SMODEL_DETAL};
   virtual TFIBBCDField * get_ElementKOL_REM_SMODEL_DETAL(void)=0;
   virtual void set_ElementKOL_REM_SMODEL_DETAL(TFIBBCDField * ElementKOL_REM_SMODEL_DETAL)=0;

   __property TFIBWideStringField * ElementNAME_REM_STYPUSLOV = {read = get_ElementNAME_REM_STYPUSLOV , write = set_ElementNAME_REM_STYPUSLOV};
   virtual TFIBWideStringField * get_ElementNAME_REM_STYPUSLOV(void)=0;
   virtual void set_ElementNAME_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_REM_STYPUSLOV)=0;

   __property TFIBIntegerField * ElementCODENOM = {read = get_ElementCODENOM , write = set_ElementCODENOM};
   virtual TFIBIntegerField * get_ElementCODENOM(void)=0;
   virtual void set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)=0;

   __property TFIBWideStringField * ElementARTNOM = {read = get_ElementARTNOM , write = set_ElementARTNOM};
   virtual TFIBWideStringField * get_ElementARTNOM(void)=0;
   virtual void set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)=0;

   __property TFIBWideStringField * ElementNAMENOM = {read = get_ElementNAMENOM , write = set_ElementNAMENOM};
   virtual TFIBWideStringField * get_ElementNAMENOM(void)=0;
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)=0;

   __property TFIBIntegerField * ElementCODE_SPRNOM = {read = get_ElementCODE_SPRNOM , write = set_ElementCODE_SPRNOM};
   virtual TFIBIntegerField * get_ElementCODE_SPRNOM(void)=0;
   virtual void set_ElementCODE_SPRNOM(TFIBIntegerField * ElementCODE_SPRNOM)=0;

   __property TFIBWideStringField * ElementART_SPRNOM = {read = get_ElementART_SPRNOM , write = set_ElementART_SPRNOM};
   virtual TFIBWideStringField * get_ElementART_SPRNOM(void)=0;
   virtual void set_ElementART_SPRNOM(TFIBWideStringField * ElementART_SPRNOM)=0;

   __property TFIBWideStringField * ElementNAME_SPRNOM = {read = get_ElementNAME_SPRNOM , write = set_ElementNAME_SPRNOM};
   virtual TFIBWideStringField * get_ElementNAME_SPRNOM(void)=0;
   virtual void set_ElementNAME_SPRNOM(TFIBWideStringField * ElementNAME_SPRNOM)=0;

   virtual void OpenTable(__int64 id_model)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_model)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IREM_DMSprModelDetal __uuidof(IREM_DMSprModelDetal)
#endif
