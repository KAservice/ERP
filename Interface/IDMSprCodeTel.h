#ifndef UIDMSprCodeTelH
#define UIDMSprCodeTelH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprCodeTel)) IDMSprCodeTel : public IMainInterface
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

   __property TFIBLargeIntField * ElementID_CODETEL = {read = get_ElementID_CODETEL , write = set_ElementID_CODETEL};
   virtual TFIBLargeIntField * get_ElementID_CODETEL(void)=0;
   virtual void set_ElementID_CODETEL(TFIBLargeIntField * ElementID_CODETEL)=0;

   __property TFIBLargeIntField * ElementIDNOM_CODETEL = {read = get_ElementIDNOM_CODETEL , write = set_ElementIDNOM_CODETEL};
   virtual TFIBLargeIntField * get_ElementIDNOM_CODETEL(void)=0;
   virtual void set_ElementIDNOM_CODETEL(TFIBLargeIntField * ElementIDNOM_CODETEL)=0;

   __property TFIBWideStringField * ElementCODE_CODETEL = {read = get_ElementCODE_CODETEL , write = set_ElementCODE_CODETEL};
   virtual TFIBWideStringField * get_ElementCODE_CODETEL(void)=0;
   virtual void set_ElementCODE_CODETEL(TFIBWideStringField * ElementCODE_CODETEL)=0;

   __property TFIBWideStringField * ElementGID_SCODETEL = {read = get_ElementGID_SCODETEL , write = set_ElementGID_SCODETEL};
   virtual TFIBWideStringField * get_ElementGID_SCODETEL(void)=0;
   virtual void set_ElementGID_SCODETEL(TFIBWideStringField * ElementGID_SCODETEL)=0;

   __property TFIBWideStringField * ElementNAME_CODETEL = {read = get_ElementNAME_CODETEL , write = set_ElementNAME_CODETEL};
   virtual TFIBWideStringField * get_ElementNAME_CODETEL(void)=0;
   virtual void set_ElementNAME_CODETEL(TFIBWideStringField * ElementNAME_CODETEL)=0;

   __property TFIBWideStringField * ElementCODOPER_CODETEL = {read = get_ElementCODOPER_CODETEL , write = set_ElementCODOPER_CODETEL};
   virtual TFIBWideStringField * get_ElementCODOPER_CODETEL(void)=0;
   virtual void set_ElementCODOPER_CODETEL(TFIBWideStringField * ElementCODOPER_CODETEL)=0;

   __property TFIBLargeIntField * ElementIDNOMCOM_CODETEL = {read = get_ElementIDNOMCOM_CODETEL , write = set_ElementIDNOMCOM_CODETEL};
   virtual TFIBLargeIntField * get_ElementIDNOMCOM_CODETEL(void)=0;
   virtual void set_ElementIDNOMCOM_CODETEL(TFIBLargeIntField * ElementIDNOMCOM_CODETEL)=0;

   __property TFIBLargeIntField * ElementIDBASE_SCODETEL = {read = get_ElementIDBASE_SCODETEL , write = set_ElementIDBASE_SCODETEL};
   virtual TFIBLargeIntField * get_ElementIDBASE_SCODETEL(void)=0;
   virtual void set_ElementIDBASE_SCODETEL(TFIBLargeIntField * ElementIDBASE_SCODETEL)=0;

   __property TFIBBCDField * ElementPRCOMIS_SCODETEL = {read = get_ElementPRCOMIS_SCODETEL , write = set_ElementPRCOMIS_SCODETEL};
   virtual TFIBBCDField * get_ElementPRCOMIS_SCODETEL(void)=0;
   virtual void set_ElementPRCOMIS_SCODETEL(TFIBBCDField * ElementPRCOMIS_SCODETEL)=0;

   __property TFIBWideStringField * ElementNAMENOM = {read = get_ElementNAMENOM , write = set_ElementNAMENOM};
   virtual TFIBWideStringField * get_ElementNAMENOM(void)=0;
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)=0;

   __property TFIBWideStringField * ElementNAMENOMCOM = {read = get_ElementNAMENOMCOM , write = set_ElementNAMENOMCOM};
   virtual TFIBWideStringField * get_ElementNAMENOMCOM(void)=0;
   virtual void set_ElementNAMENOMCOM(TFIBWideStringField * ElementNAMENOMCOM)=0;

   __property TFIBLargeIntField * TableID_CODETEL = {read = get_TableID_CODETEL , write = set_TableID_CODETEL};
   virtual TFIBLargeIntField * get_TableID_CODETEL(void)=0;
   virtual void set_TableID_CODETEL(TFIBLargeIntField * TableID_CODETEL)=0;

   __property TFIBLargeIntField * TableIDNOM_CODETEL = {read = get_TableIDNOM_CODETEL , write = set_TableIDNOM_CODETEL};
   virtual TFIBLargeIntField * get_TableIDNOM_CODETEL(void)=0;
   virtual void set_TableIDNOM_CODETEL(TFIBLargeIntField * TableIDNOM_CODETEL)=0;

   __property TFIBWideStringField * TableCODE_CODETEL = {read = get_TableCODE_CODETEL , write = set_TableCODE_CODETEL};
   virtual TFIBWideStringField * get_TableCODE_CODETEL(void)=0;
   virtual void set_TableCODE_CODETEL(TFIBWideStringField * TableCODE_CODETEL)=0;

   __property TFIBWideStringField * TableGID_SCODETEL = {read = get_TableGID_SCODETEL , write = set_TableGID_SCODETEL};
   virtual TFIBWideStringField * get_TableGID_SCODETEL(void)=0;
   virtual void set_TableGID_SCODETEL(TFIBWideStringField * TableGID_SCODETEL)=0;

   __property TFIBWideStringField * TableNAME_CODETEL = {read = get_TableNAME_CODETEL , write = set_TableNAME_CODETEL};
   virtual TFIBWideStringField * get_TableNAME_CODETEL(void)=0;
   virtual void set_TableNAME_CODETEL(TFIBWideStringField * TableNAME_CODETEL)=0;

   __property TFIBWideStringField * TableCODOPER_CODETEL = {read = get_TableCODOPER_CODETEL , write = set_TableCODOPER_CODETEL};
   virtual TFIBWideStringField * get_TableCODOPER_CODETEL(void)=0;
   virtual void set_TableCODOPER_CODETEL(TFIBWideStringField * TableCODOPER_CODETEL)=0;

   __property TFIBLargeIntField * TableIDNOMCOM_CODETEL = {read = get_TableIDNOMCOM_CODETEL , write = set_TableIDNOMCOM_CODETEL};
   virtual TFIBLargeIntField * get_TableIDNOMCOM_CODETEL(void)=0;
   virtual void set_TableIDNOMCOM_CODETEL(TFIBLargeIntField * TableIDNOMCOM_CODETEL)=0;

   __property TFIBLargeIntField * TableIDBASE_SCODETEL = {read = get_TableIDBASE_SCODETEL , write = set_TableIDBASE_SCODETEL};
   virtual TFIBLargeIntField * get_TableIDBASE_SCODETEL(void)=0;
   virtual void set_TableIDBASE_SCODETEL(TFIBLargeIntField * TableIDBASE_SCODETEL)=0;

   __property TFIBBCDField * TablePRCOMIS_SCODETEL = {read = get_TablePRCOMIS_SCODETEL , write = set_TablePRCOMIS_SCODETEL};
   virtual TFIBBCDField * get_TablePRCOMIS_SCODETEL(void)=0;
   virtual void set_TablePRCOMIS_SCODETEL(TFIBBCDField * TablePRCOMIS_SCODETEL)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBIntegerField * TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR = {read = get_TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR , write = set_TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR};
   virtual TFIBIntegerField * get_TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR(void)=0;
   virtual void set_TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR(TFIBIntegerField * TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR)=0;

   __property TFIBLargeIntField * TableNOM_DEPARTMENT_ID_SDEPARTMENT = {read = get_TableNOM_DEPARTMENT_ID_SDEPARTMENT , write = set_TableNOM_DEPARTMENT_ID_SDEPARTMENT};
   virtual TFIBLargeIntField * get_TableNOM_DEPARTMENT_ID_SDEPARTMENT(void)=0;
   virtual void set_TableNOM_DEPARTMENT_ID_SDEPARTMENT(TFIBLargeIntField * TableNOM_DEPARTMENT_ID_SDEPARTMENT)=0;

   __property TFIBWideStringField * TableNAMENOMCOM = {read = get_TableNAMENOMCOM , write = set_TableNAMENOMCOM};
   virtual TFIBWideStringField * get_TableNAMENOMCOM(void)=0;
   virtual void set_TableNAMENOMCOM(TFIBWideStringField * TableNAMENOMCOM)=0;

   __property TFIBIntegerField * TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR = {read = get_TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR , write = set_TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR};
   virtual TFIBIntegerField * get_TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR(void)=0;
   virtual void set_TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR(TFIBIntegerField * TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR)=0;

   __property TFIBLargeIntField * TableCOM_DEPARTMENT_ID_SDEPARTMENT = {read = get_TableCOM_DEPARTMENT_ID_SDEPARTMENT , write = set_TableCOM_DEPARTMENT_ID_SDEPARTMENT};
   virtual TFIBLargeIntField * get_TableCOM_DEPARTMENT_ID_SDEPARTMENT(void)=0;
   virtual void set_TableCOM_DEPARTMENT_ID_SDEPARTMENT(TFIBLargeIntField * TableCOM_DEPARTMENT_ID_SDEPARTMENT)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
};
#define IID_IDMSprCodeTel __uuidof(IDMSprCodeTel)
#endif
