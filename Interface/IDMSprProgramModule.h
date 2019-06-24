#ifndef UIDMSprProgramModuleH
#define UIDMSprProgramModuleH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprProgramModule)) IDMSprProgramModule : public IMainInterface
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

   __property TFIBLargeIntField * TableID_PROGRAM_MODULE = {read = get_TableID_PROGRAM_MODULE , write = set_TableID_PROGRAM_MODULE};
   virtual TFIBLargeIntField * get_TableID_PROGRAM_MODULE(void)=0;
   virtual void set_TableID_PROGRAM_MODULE(TFIBLargeIntField * TableID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TableNAME_PROGRAM_MODULE = {read = get_TableNAME_PROGRAM_MODULE , write = set_TableNAME_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void)=0;
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TablePROGID_PROGRAM_MODULE = {read = get_TablePROGID_PROGRAM_MODULE , write = set_TablePROGID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TablePROGID_PROGRAM_MODULE(void)=0;
   virtual void set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TableMODULE_PROGRAM_MODULE = {read = get_TableMODULE_PROGRAM_MODULE , write = set_TableMODULE_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TableMODULE_PROGRAM_MODULE(void)=0;
   virtual void set_TableMODULE_PROGRAM_MODULE(TFIBWideStringField * TableMODULE_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TableDESCR_PROGRAM_MODULE = {read = get_TableDESCR_PROGRAM_MODULE , write = set_TableDESCR_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TableDESCR_PROGRAM_MODULE(void)=0;
   virtual void set_TableDESCR_PROGRAM_MODULE(TFIBWideStringField * TableDESCR_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TablePATCH_PROGRAM_MODULE = {read = get_TablePATCH_PROGRAM_MODULE , write = set_TablePATCH_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void)=0;
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)=0;

   __property TFIBLargeIntField * TableIDBASE_PROGRAM_MODULE = {read = get_TableIDBASE_PROGRAM_MODULE , write = set_TableIDBASE_PROGRAM_MODULE};
   virtual TFIBLargeIntField * get_TableIDBASE_PROGRAM_MODULE(void)=0;
   virtual void set_TableIDBASE_PROGRAM_MODULE(TFIBLargeIntField * TableIDBASE_PROGRAM_MODULE)=0;

   __property TFIBLargeIntField * ElementID_PROGRAM_MODULE = {read = get_ElementID_PROGRAM_MODULE , write = set_ElementID_PROGRAM_MODULE};
   virtual TFIBLargeIntField * get_ElementID_PROGRAM_MODULE(void)=0;
   virtual void set_ElementID_PROGRAM_MODULE(TFIBLargeIntField * ElementID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementNAME_PROGRAM_MODULE = {read = get_ElementNAME_PROGRAM_MODULE , write = set_ElementNAME_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void)=0;
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementPROGID_PROGRAM_MODULE = {read = get_ElementPROGID_PROGRAM_MODULE , write = set_ElementPROGID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementPROGID_PROGRAM_MODULE(void)=0;
   virtual void set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementMODULE_PROGRAM_MODULE = {read = get_ElementMODULE_PROGRAM_MODULE , write = set_ElementMODULE_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementMODULE_PROGRAM_MODULE(void)=0;
   virtual void set_ElementMODULE_PROGRAM_MODULE(TFIBWideStringField * ElementMODULE_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementDESCR_PROGRAM_MODULE = {read = get_ElementDESCR_PROGRAM_MODULE , write = set_ElementDESCR_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementDESCR_PROGRAM_MODULE(void)=0;
   virtual void set_ElementDESCR_PROGRAM_MODULE(TFIBWideStringField * ElementDESCR_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementPATCH_PROGRAM_MODULE = {read = get_ElementPATCH_PROGRAM_MODULE , write = set_ElementPATCH_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void)=0;
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)=0;

   __property TFIBLargeIntField * ElementIDBASE_PROGRAM_MODULE = {read = get_ElementIDBASE_PROGRAM_MODULE , write = set_ElementIDBASE_PROGRAM_MODULE};
   virtual TFIBLargeIntField * get_ElementIDBASE_PROGRAM_MODULE(void)=0;
   virtual void set_ElementIDBASE_PROGRAM_MODULE(TFIBLargeIntField * ElementIDBASE_PROGRAM_MODULE)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBWideStringField * TableGUID_PROGRAM_MODULE = {read = get_TableGUID_PROGRAM_MODULE , write = set_TableGUID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TableGUID_PROGRAM_MODULE(void)=0;
   virtual void set_TableGUID_PROGRAM_MODULE(TFIBWideStringField * TableGUID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementGUID_PROGRAM_MODULE = {read = get_ElementGUID_PROGRAM_MODULE , write = set_ElementGUID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementGUID_PROGRAM_MODULE(void)=0;
   virtual void set_ElementGUID_PROGRAM_MODULE(TFIBWideStringField * ElementGUID_PROGRAM_MODULE)=0;

   __property TFIBIntegerField * TableTYPEMOD_PROGRAM_MODULE = {read = get_TableTYPEMOD_PROGRAM_MODULE , write = set_TableTYPEMOD_PROGRAM_MODULE};
   virtual TFIBIntegerField * get_TableTYPEMOD_PROGRAM_MODULE(void)=0;
   virtual void set_TableTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * TableTYPEMOD_PROGRAM_MODULE)=0;

   __property TFIBIntegerField * ElementTYPEMOD_PROGRAM_MODULE = {read = get_ElementTYPEMOD_PROGRAM_MODULE , write = set_ElementTYPEMOD_PROGRAM_MODULE};
   virtual TFIBIntegerField * get_ElementTYPEMOD_PROGRAM_MODULE(void)=0;
   virtual void set_ElementTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * ElementTYPEMOD_PROGRAM_MODULE)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual __int64 GetIDElement(UnicodeString gid)=0;
   virtual GUID GetCLSIDFromProgID(UnicodeString prog_id)=0;
   virtual UnicodeString GetProgIDFromCLSID (GUID guid)=0;
   virtual UnicodeString GetNameModuleFromCLSID(GUID guid)=0;
   virtual UnicodeString GetFullPatchFromCLSID(GUID guid)=0;
   virtual __int64 GetIdModuleFromGUID(GUID guid)=0;
   virtual __int64 GetIdModuleFromProgId(UnicodeString prog_id)=0;
};
#define IID_IDMSprProgramModule __uuidof(IDMSprProgramModule)
#endif
