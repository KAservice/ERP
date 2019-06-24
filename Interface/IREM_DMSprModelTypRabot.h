#ifndef UIREM_DMSprModelTypRabotH
#define UIREM_DMSprModelTypRabotH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprModelTypRabot)) IREM_DMSprModelTypRabot : public IMainInterface
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

   __property TFIBLargeIntField * TableID_REM_SMODEL_TRAB = {read = get_TableID_REM_SMODEL_TRAB , write = set_TableID_REM_SMODEL_TRAB};
   virtual TFIBLargeIntField * get_TableID_REM_SMODEL_TRAB(void)=0;
   virtual void set_TableID_REM_SMODEL_TRAB(TFIBLargeIntField * TableID_REM_SMODEL_TRAB)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SMODEL_TRAB = {read = get_TableIDBASE_REM_SMODEL_TRAB , write = set_TableIDBASE_REM_SMODEL_TRAB};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SMODEL_TRAB(void)=0;
   virtual void set_TableIDBASE_REM_SMODEL_TRAB(TFIBLargeIntField * TableIDBASE_REM_SMODEL_TRAB)=0;

   __property TFIBLargeIntField * TableIDTR_REM_SMODEL_TRAB = {read = get_TableIDTR_REM_SMODEL_TRAB , write = set_TableIDTR_REM_SMODEL_TRAB};
   virtual TFIBLargeIntField * get_TableIDTR_REM_SMODEL_TRAB(void)=0;
   virtual void set_TableIDTR_REM_SMODEL_TRAB(TFIBLargeIntField * TableIDTR_REM_SMODEL_TRAB)=0;

   __property TFIBLargeIntField * TableIDMODEL_REM_SMODEL_TRAB = {read = get_TableIDMODEL_REM_SMODEL_TRAB , write = set_TableIDMODEL_REM_SMODEL_TRAB};
   virtual TFIBLargeIntField * get_TableIDMODEL_REM_SMODEL_TRAB(void)=0;
   virtual void set_TableIDMODEL_REM_SMODEL_TRAB(TFIBLargeIntField * TableIDMODEL_REM_SMODEL_TRAB)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBWideStringField * TableARTNOM = {read = get_TableARTNOM , write = set_TableARTNOM};
   virtual TFIBWideStringField * get_TableARTNOM(void)=0;
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM)=0;

   __property TFIBIntegerField * TableCODENOM = {read = get_TableCODENOM , write = set_TableCODENOM};
   virtual TFIBIntegerField * get_TableCODENOM(void)=0;
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM)=0;

   __property TFIBWideStringField * TableNAME_REM_STYPRABOT = {read = get_TableNAME_REM_STYPRABOT , write = set_TableNAME_REM_STYPRABOT};
   virtual TFIBWideStringField * get_TableNAME_REM_STYPRABOT(void)=0;
   virtual void set_TableNAME_REM_STYPRABOT(TFIBWideStringField * TableNAME_REM_STYPRABOT)=0;

   __property TFIBLargeIntField * ElementID_REM_SMODEL_TRAB = {read = get_ElementID_REM_SMODEL_TRAB , write = set_ElementID_REM_SMODEL_TRAB};
   virtual TFIBLargeIntField * get_ElementID_REM_SMODEL_TRAB(void)=0;
   virtual void set_ElementID_REM_SMODEL_TRAB(TFIBLargeIntField * ElementID_REM_SMODEL_TRAB)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SMODEL_TRAB = {read = get_ElementIDBASE_REM_SMODEL_TRAB , write = set_ElementIDBASE_REM_SMODEL_TRAB};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SMODEL_TRAB(void)=0;
   virtual void set_ElementIDBASE_REM_SMODEL_TRAB(TFIBLargeIntField * ElementIDBASE_REM_SMODEL_TRAB)=0;

   __property TFIBLargeIntField * ElementIDTR_REM_SMODEL_TRAB = {read = get_ElementIDTR_REM_SMODEL_TRAB , write = set_ElementIDTR_REM_SMODEL_TRAB};
   virtual TFIBLargeIntField * get_ElementIDTR_REM_SMODEL_TRAB(void)=0;
   virtual void set_ElementIDTR_REM_SMODEL_TRAB(TFIBLargeIntField * ElementIDTR_REM_SMODEL_TRAB)=0;

   __property TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_TRAB = {read = get_ElementIDMODEL_REM_SMODEL_TRAB , write = set_ElementIDMODEL_REM_SMODEL_TRAB};
   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SMODEL_TRAB(void)=0;
   virtual void set_ElementIDMODEL_REM_SMODEL_TRAB(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_TRAB)=0;

   __property TFIBWideStringField * ElementNAMENOM = {read = get_ElementNAMENOM , write = set_ElementNAMENOM};
   virtual TFIBWideStringField * get_ElementNAMENOM(void)=0;
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)=0;

   __property TFIBWideStringField * ElementARTNOM = {read = get_ElementARTNOM , write = set_ElementARTNOM};
   virtual TFIBWideStringField * get_ElementARTNOM(void)=0;
   virtual void set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)=0;

   __property TFIBIntegerField * ElementCODENOM = {read = get_ElementCODENOM , write = set_ElementCODENOM};
   virtual TFIBIntegerField * get_ElementCODENOM(void)=0;
   virtual void set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)=0;

   __property TFIBWideStringField * ElementNAME_REM_STYPRABOT = {read = get_ElementNAME_REM_STYPRABOT , write = set_ElementNAME_REM_STYPRABOT};
   virtual TFIBWideStringField * get_ElementNAME_REM_STYPRABOT(void)=0;
   virtual void set_ElementNAME_REM_STYPRABOT(TFIBWideStringField * ElementNAME_REM_STYPRABOT)=0;

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
#define IID_IREM_DMSprModelTypRabot __uuidof(IREM_DMSprModelTypRabot)
#endif
