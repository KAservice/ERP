#ifndef UIREM_DMSprModelInfBlockH
#define UIREM_DMSprModelInfBlockH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprModelInfBlock)) IREM_DMSprModelInfBlock : public IMainInterface
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

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBLargeIntField * TableID_REM_SMODEL_INF = {read = get_TableID_REM_SMODEL_INF , write = set_TableID_REM_SMODEL_INF};
   virtual TFIBLargeIntField * get_TableID_REM_SMODEL_INF(void)=0;
   virtual void set_TableID_REM_SMODEL_INF(TFIBLargeIntField * TableID_REM_SMODEL_INF)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SMODEL_INF = {read = get_TableIDBASE_REM_SMODEL_INF , write = set_TableIDBASE_REM_SMODEL_INF};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SMODEL_INF(void)=0;
   virtual void set_TableIDBASE_REM_SMODEL_INF(TFIBLargeIntField * TableIDBASE_REM_SMODEL_INF)=0;

   __property TFIBWideStringField * TableGID_REM_SMODEL_INF = {read = get_TableGID_REM_SMODEL_INF , write = set_TableGID_REM_SMODEL_INF};
   virtual TFIBWideStringField * get_TableGID_REM_SMODEL_INF(void)=0;
   virtual void set_TableGID_REM_SMODEL_INF(TFIBWideStringField * TableGID_REM_SMODEL_INF)=0;

   __property TFIBLargeIntField * TableIDMODEL_REM_SMODEL_INF = {read = get_TableIDMODEL_REM_SMODEL_INF , write = set_TableIDMODEL_REM_SMODEL_INF};
   virtual TFIBLargeIntField * get_TableIDMODEL_REM_SMODEL_INF(void)=0;
   virtual void set_TableIDMODEL_REM_SMODEL_INF(TFIBLargeIntField * TableIDMODEL_REM_SMODEL_INF)=0;

   __property TFIBLargeIntField * TableIDIB_REM_SMODEL_INF = {read = get_TableIDIB_REM_SMODEL_INF , write = set_TableIDIB_REM_SMODEL_INF};
   virtual TFIBLargeIntField * get_TableIDIB_REM_SMODEL_INF(void)=0;
   virtual void set_TableIDIB_REM_SMODEL_INF(TFIBLargeIntField * TableIDIB_REM_SMODEL_INF)=0;

   __property TFIBDateTimeField * TableISM_REM_SMODEL_INF = {read = get_TableISM_REM_SMODEL_INF , write = set_TableISM_REM_SMODEL_INF};
   virtual TFIBDateTimeField * get_TableISM_REM_SMODEL_INF(void)=0;
   virtual void set_TableISM_REM_SMODEL_INF(TFIBDateTimeField * TableISM_REM_SMODEL_INF)=0;

   __property TFIBWideStringField * TableNAME_ART_IB = {read = get_TableNAME_ART_IB , write = set_TableNAME_ART_IB};
   virtual TFIBWideStringField * get_TableNAME_ART_IB(void)=0;
   virtual void set_TableNAME_ART_IB(TFIBWideStringField * TableNAME_ART_IB)=0;

   __property TFIBWideStringField * TableDESCR_ART_IB = {read = get_TableDESCR_ART_IB , write = set_TableDESCR_ART_IB};
   virtual TFIBWideStringField * get_TableDESCR_ART_IB(void)=0;
   virtual void set_TableDESCR_ART_IB(TFIBWideStringField * TableDESCR_ART_IB)=0;

   __property TFIBLargeIntField * ElementID_REM_SMODEL_INF = {read = get_ElementID_REM_SMODEL_INF , write = set_ElementID_REM_SMODEL_INF};
   virtual TFIBLargeIntField * get_ElementID_REM_SMODEL_INF(void)=0;
   virtual void set_ElementID_REM_SMODEL_INF(TFIBLargeIntField * ElementID_REM_SMODEL_INF)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SMODEL_INF = {read = get_ElementIDBASE_REM_SMODEL_INF , write = set_ElementIDBASE_REM_SMODEL_INF};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SMODEL_INF(void)=0;
   virtual void set_ElementIDBASE_REM_SMODEL_INF(TFIBLargeIntField * ElementIDBASE_REM_SMODEL_INF)=0;

   __property TFIBWideStringField * ElementGID_REM_SMODEL_INF = {read = get_ElementGID_REM_SMODEL_INF , write = set_ElementGID_REM_SMODEL_INF};
   virtual TFIBWideStringField * get_ElementGID_REM_SMODEL_INF(void)=0;
   virtual void set_ElementGID_REM_SMODEL_INF(TFIBWideStringField * ElementGID_REM_SMODEL_INF)=0;

   __property TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_INF = {read = get_ElementIDMODEL_REM_SMODEL_INF , write = set_ElementIDMODEL_REM_SMODEL_INF};
   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SMODEL_INF(void)=0;
   virtual void set_ElementIDMODEL_REM_SMODEL_INF(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_INF)=0;

   __property TFIBLargeIntField * ElementIDIB_REM_SMODEL_INF = {read = get_ElementIDIB_REM_SMODEL_INF , write = set_ElementIDIB_REM_SMODEL_INF};
   virtual TFIBLargeIntField * get_ElementIDIB_REM_SMODEL_INF(void)=0;
   virtual void set_ElementIDIB_REM_SMODEL_INF(TFIBLargeIntField * ElementIDIB_REM_SMODEL_INF)=0;

   __property TFIBDateTimeField * ElementISM_REM_SMODEL_INF = {read = get_ElementISM_REM_SMODEL_INF , write = set_ElementISM_REM_SMODEL_INF};
   virtual TFIBDateTimeField * get_ElementISM_REM_SMODEL_INF(void)=0;
   virtual void set_ElementISM_REM_SMODEL_INF(TFIBDateTimeField * ElementISM_REM_SMODEL_INF)=0;

   __property TFIBWideStringField * ElementNAME_ART_IB = {read = get_ElementNAME_ART_IB , write = set_ElementNAME_ART_IB};
   virtual TFIBWideStringField * get_ElementNAME_ART_IB(void)=0;
   virtual void set_ElementNAME_ART_IB(TFIBWideStringField * ElementNAME_ART_IB)=0;

   __property TFIBWideStringField * ElementDESCR_ART_IB = {read = get_ElementDESCR_ART_IB , write = set_ElementDESCR_ART_IB};
   virtual TFIBWideStringField * get_ElementDESCR_ART_IB(void)=0;
   virtual void set_ElementDESCR_ART_IB(TFIBWideStringField * ElementDESCR_ART_IB)=0;

   __property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};
   virtual __int64 get_IdOwner(void)=0;
   virtual void set_IdOwner(__int64 IdOwner)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_owner)=0;
   virtual bool NewElement(__int64 id_owner)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IREM_DMSprModelInfBlock __uuidof(IREM_DMSprModelInfBlock)
#endif
