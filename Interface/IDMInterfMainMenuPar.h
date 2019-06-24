#ifndef UIDMInterfMainMenuParH
#define UIDMInterfMainMenuParH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMInterfMainMenuPar)) IDMInterfMainMenuPar : public IMainInterface
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

   __property TFIBLargeIntField * TableID_INTERF_MAINMENU_PAR = {read = get_TableID_INTERF_MAINMENU_PAR , write = set_TableID_INTERF_MAINMENU_PAR};
   virtual TFIBLargeIntField * get_TableID_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_TableID_INTERF_MAINMENU_PAR(TFIBLargeIntField * TableID_INTERF_MAINMENU_PAR)=0;

   __property TFIBLargeIntField * TableIDBASE_INTERF_MAINMENU_PAR = {read = get_TableIDBASE_INTERF_MAINMENU_PAR , write = set_TableIDBASE_INTERF_MAINMENU_PAR};
   virtual TFIBLargeIntField * get_TableIDBASE_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_TableIDBASE_INTERF_MAINMENU_PAR(TFIBLargeIntField * TableIDBASE_INTERF_MAINMENU_PAR)=0;

   __property TFIBWideStringField * TableGID_INTERF_MAINMENU_PAR = {read = get_TableGID_INTERF_MAINMENU_PAR , write = set_TableGID_INTERF_MAINMENU_PAR};
   virtual TFIBWideStringField * get_TableGID_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_TableGID_INTERF_MAINMENU_PAR(TFIBWideStringField * TableGID_INTERF_MAINMENU_PAR)=0;

   __property TFIBLargeIntField * TableIDMAINMENU_INTERF_MAINMENU_PAR = {read = get_TableIDMAINMENU_INTERF_MAINMENU_PAR , write = set_TableIDMAINMENU_INTERF_MAINMENU_PAR};
   virtual TFIBLargeIntField * get_TableIDMAINMENU_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_TableIDMAINMENU_INTERF_MAINMENU_PAR(TFIBLargeIntField * TableIDMAINMENU_INTERF_MAINMENU_PAR)=0;

   __property TFIBWideStringField * TableNAME_INTERF_MAINMENU_PAR = {read = get_TableNAME_INTERF_MAINMENU_PAR , write = set_TableNAME_INTERF_MAINMENU_PAR};
   virtual TFIBWideStringField * get_TableNAME_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_TableNAME_INTERF_MAINMENU_PAR(TFIBWideStringField * TableNAME_INTERF_MAINMENU_PAR)=0;

   __property TFIBWideStringField * TableVALUE_INTERF_MAINMENU_PAR = {read = get_TableVALUE_INTERF_MAINMENU_PAR , write = set_TableVALUE_INTERF_MAINMENU_PAR};
   virtual TFIBWideStringField * get_TableVALUE_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_TableVALUE_INTERF_MAINMENU_PAR(TFIBWideStringField * TableVALUE_INTERF_MAINMENU_PAR)=0;

   __property TFIBDateTimeField * TableVALUE_TIMESTAMP_MAINMENU_PAR = {read = get_TableVALUE_TIMESTAMP_MAINMENU_PAR , write = set_TableVALUE_TIMESTAMP_MAINMENU_PAR};
   virtual TFIBDateTimeField * get_TableVALUE_TIMESTAMP_MAINMENU_PAR(void)=0;
   virtual void set_TableVALUE_TIMESTAMP_MAINMENU_PAR(TFIBDateTimeField * TableVALUE_TIMESTAMP_MAINMENU_PAR)=0;

   __property TFIBSmallIntField * TableTYPE_VALUE_MAINMENU_PAR = {read = get_TableTYPE_VALUE_MAINMENU_PAR , write = set_TableTYPE_VALUE_MAINMENU_PAR};
   virtual TFIBSmallIntField * get_TableTYPE_VALUE_MAINMENU_PAR(void)=0;
   virtual void set_TableTYPE_VALUE_MAINMENU_PAR(TFIBSmallIntField * TableTYPE_VALUE_MAINMENU_PAR)=0;

   __property TFIBIntegerField * TableTYPE_PAR_INTERF_MAINMENU_PAR = {read = get_TableTYPE_PAR_INTERF_MAINMENU_PAR , write = set_TableTYPE_PAR_INTERF_MAINMENU_PAR};
   virtual TFIBIntegerField * get_TableTYPE_PAR_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_TableTYPE_PAR_INTERF_MAINMENU_PAR(TFIBIntegerField * TableTYPE_PAR_INTERF_MAINMENU_PAR)=0;

   __property TFIBLargeIntField * ElementID_INTERF_MAINMENU_PAR = {read = get_ElementID_INTERF_MAINMENU_PAR , write = set_ElementID_INTERF_MAINMENU_PAR};
   virtual TFIBLargeIntField * get_ElementID_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_ElementID_INTERF_MAINMENU_PAR(TFIBLargeIntField * ElementID_INTERF_MAINMENU_PAR)=0;

   __property TFIBLargeIntField * ElementIDBASE_INTERF_MAINMENU_PAR = {read = get_ElementIDBASE_INTERF_MAINMENU_PAR , write = set_ElementIDBASE_INTERF_MAINMENU_PAR};
   virtual TFIBLargeIntField * get_ElementIDBASE_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_ElementIDBASE_INTERF_MAINMENU_PAR(TFIBLargeIntField * ElementIDBASE_INTERF_MAINMENU_PAR)=0;

   __property TFIBWideStringField * ElementGID_INTERF_MAINMENU_PAR = {read = get_ElementGID_INTERF_MAINMENU_PAR , write = set_ElementGID_INTERF_MAINMENU_PAR};
   virtual TFIBWideStringField * get_ElementGID_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_ElementGID_INTERF_MAINMENU_PAR(TFIBWideStringField * ElementGID_INTERF_MAINMENU_PAR)=0;

   __property TFIBLargeIntField * ElementIDMAINMENU_INTERF_MAINMENU_PAR = {read = get_ElementIDMAINMENU_INTERF_MAINMENU_PAR , write = set_ElementIDMAINMENU_INTERF_MAINMENU_PAR};
   virtual TFIBLargeIntField * get_ElementIDMAINMENU_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_ElementIDMAINMENU_INTERF_MAINMENU_PAR(TFIBLargeIntField * ElementIDMAINMENU_INTERF_MAINMENU_PAR)=0;

   __property TFIBWideStringField * ElementNAME_INTERF_MAINMENU_PAR = {read = get_ElementNAME_INTERF_MAINMENU_PAR , write = set_ElementNAME_INTERF_MAINMENU_PAR};
   virtual TFIBWideStringField * get_ElementNAME_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_ElementNAME_INTERF_MAINMENU_PAR(TFIBWideStringField * ElementNAME_INTERF_MAINMENU_PAR)=0;

   __property TFIBWideStringField * ElementVALUE_INTERF_MAINMENU_PAR = {read = get_ElementVALUE_INTERF_MAINMENU_PAR , write = set_ElementVALUE_INTERF_MAINMENU_PAR};
   virtual TFIBWideStringField * get_ElementVALUE_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_ElementVALUE_INTERF_MAINMENU_PAR(TFIBWideStringField * ElementVALUE_INTERF_MAINMENU_PAR)=0;

   __property TFIBDateTimeField * ElementVALUE_TIMESTAMP_MAINMENU_PAR = {read = get_ElementVALUE_TIMESTAMP_MAINMENU_PAR , write = set_ElementVALUE_TIMESTAMP_MAINMENU_PAR};
   virtual TFIBDateTimeField * get_ElementVALUE_TIMESTAMP_MAINMENU_PAR(void)=0;
   virtual void set_ElementVALUE_TIMESTAMP_MAINMENU_PAR(TFIBDateTimeField * ElementVALUE_TIMESTAMP_MAINMENU_PAR)=0;

   __property TFIBSmallIntField * ElementTYPE_VALUE_MAINMENU_PAR = {read = get_ElementTYPE_VALUE_MAINMENU_PAR , write = set_ElementTYPE_VALUE_MAINMENU_PAR};
   virtual TFIBSmallIntField * get_ElementTYPE_VALUE_MAINMENU_PAR(void)=0;
   virtual void set_ElementTYPE_VALUE_MAINMENU_PAR(TFIBSmallIntField * ElementTYPE_VALUE_MAINMENU_PAR)=0;

   __property TFIBIntegerField * ElementTYPE_PAR_INTERF_MAINMENU_PAR = {read = get_ElementTYPE_PAR_INTERF_MAINMENU_PAR , write = set_ElementTYPE_PAR_INTERF_MAINMENU_PAR};
   virtual TFIBIntegerField * get_ElementTYPE_PAR_INTERF_MAINMENU_PAR(void)=0;
   virtual void set_ElementTYPE_PAR_INTERF_MAINMENU_PAR(TFIBIntegerField * ElementTYPE_PAR_INTERF_MAINMENU_PAR)=0;

   __property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};
   virtual __int64 get_IdOwner(void)=0;
   virtual void set_IdOwner(__int64 IdOwner)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_owner)=0;
   virtual bool SaveIsmen(void)=0;
   virtual bool CancelIsmen(void)=0;
   virtual bool TableAppend(__int64 id_owner)=0;
   virtual bool TableDelete(void)=0;
   virtual bool NewElement(__int64 id_owner)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IDMInterfMainMenuPar __uuidof(IDMInterfMainMenuPar)
#endif
