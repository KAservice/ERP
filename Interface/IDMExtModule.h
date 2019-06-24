#ifndef UIDMExtModuleH
#define UIDMExtModuleH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{4E730E41-F16C-4947-BD6B-A2AAA890496B}"))IDMExtModule : public IMainInterface
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

   __property TFIBBCDField * TableID_EXT_MODULE = {read = get_TableID_EXT_MODULE , write = set_TableID_EXT_MODULE};
   virtual TFIBBCDField * get_TableID_EXT_MODULE(void)=0;
   virtual void set_TableID_EXT_MODULE(TFIBBCDField * TableID_EXT_MODULE)=0;

   __property TFIBBCDField * TableIDGRP_EXT_MODULE = {read = get_TableIDGRP_EXT_MODULE , write = set_TableIDGRP_EXT_MODULE};
   virtual TFIBBCDField * get_TableIDGRP_EXT_MODULE(void)=0;
   virtual void set_TableIDGRP_EXT_MODULE(TFIBBCDField * TableIDGRP_EXT_MODULE)=0;

   __property TFIBSmallIntField * TableTYPE_EXT_MODULE = {read = get_TableTYPE_EXT_MODULE , write = set_TableTYPE_EXT_MODULE};
   virtual TFIBSmallIntField * get_TableTYPE_EXT_MODULE(void)=0;
   virtual void set_TableTYPE_EXT_MODULE(TFIBSmallIntField * TableTYPE_EXT_MODULE)=0;

   __property TFIBSmallIntField * TableISP_EXT_MODULE = {read = get_TableISP_EXT_MODULE , write = set_TableISP_EXT_MODULE};
   virtual TFIBSmallIntField * get_TableISP_EXT_MODULE(void)=0;
   virtual void set_TableISP_EXT_MODULE(TFIBSmallIntField * TableISP_EXT_MODULE)=0;

   __property TFIBBCDField * ElementID_EXT_MODULE = {read = get_ElementID_EXT_MODULE , write = set_ElementID_EXT_MODULE};
   virtual TFIBBCDField * get_ElementID_EXT_MODULE(void)=0;
   virtual void set_ElementID_EXT_MODULE(TFIBBCDField * ElementID_EXT_MODULE)=0;

   __property TFIBBCDField * ElementIDGRP_EXT_MODULE = {read = get_ElementIDGRP_EXT_MODULE , write = set_ElementIDGRP_EXT_MODULE};
   virtual TFIBBCDField * get_ElementIDGRP_EXT_MODULE(void)=0;
   virtual void set_ElementIDGRP_EXT_MODULE(TFIBBCDField * ElementIDGRP_EXT_MODULE)=0;

   __property TFIBSmallIntField * ElementTYPE_EXT_MODULE = {read = get_ElementTYPE_EXT_MODULE , write = set_ElementTYPE_EXT_MODULE};
   virtual TFIBSmallIntField * get_ElementTYPE_EXT_MODULE(void)=0;
   virtual void set_ElementTYPE_EXT_MODULE(TFIBSmallIntField * ElementTYPE_EXT_MODULE)=0;

   __property TFIBSmallIntField * ElementISP_EXT_MODULE = {read = get_ElementISP_EXT_MODULE , write = set_ElementISP_EXT_MODULE};
   virtual TFIBSmallIntField * get_ElementISP_EXT_MODULE(void)=0;
   virtual void set_ElementISP_EXT_MODULE(TFIBSmallIntField * ElementISP_EXT_MODULE)=0;

   __property TFIBBlobField * ElementBODY_EXT_MODULE = {read = get_ElementBODY_EXT_MODULE , write = set_ElementBODY_EXT_MODULE};
   virtual TFIBBlobField * get_ElementBODY_EXT_MODULE(void)=0;
   virtual void set_ElementBODY_EXT_MODULE(TFIBBlobField * ElementBODY_EXT_MODULE)=0;

   __property TFIBIntegerField * ElementRESIDENCE_EXT_MODULE = {read = get_ElementRESIDENCE_EXT_MODULE , write = set_ElementRESIDENCE_EXT_MODULE};
   virtual TFIBIntegerField * get_ElementRESIDENCE_EXT_MODULE(void)=0;
   virtual void set_ElementRESIDENCE_EXT_MODULE(TFIBIntegerField * ElementRESIDENCE_EXT_MODULE)=0;

   __property TFIBWideStringField * TableNAME_EXT_MODULE = {read = get_TableNAME_EXT_MODULE , write = set_TableNAME_EXT_MODULE};
   virtual TFIBWideStringField * get_TableNAME_EXT_MODULE(void)=0;
   virtual void set_TableNAME_EXT_MODULE(TFIBWideStringField * TableNAME_EXT_MODULE)=0;

   __property TFIBWideStringField * TableFILE_NAME_EXT_MODULE = {read = get_TableFILE_NAME_EXT_MODULE , write = set_TableFILE_NAME_EXT_MODULE};
   virtual TFIBWideStringField * get_TableFILE_NAME_EXT_MODULE(void)=0;
   virtual void set_TableFILE_NAME_EXT_MODULE(TFIBWideStringField * TableFILE_NAME_EXT_MODULE)=0;

   __property TFIBWideStringField * ElementNAME_EXT_MODULE = {read = get_ElementNAME_EXT_MODULE , write = set_ElementNAME_EXT_MODULE};
   virtual TFIBWideStringField * get_ElementNAME_EXT_MODULE(void)=0;
   virtual void set_ElementNAME_EXT_MODULE(TFIBWideStringField * ElementNAME_EXT_MODULE)=0;

   __property TFIBWideStringField * ElementFILE_NAME_EXT_MODULE = {read = get_ElementFILE_NAME_EXT_MODULE , write = set_ElementFILE_NAME_EXT_MODULE};
   virtual TFIBWideStringField * get_ElementFILE_NAME_EXT_MODULE(void)=0;
   virtual void set_ElementFILE_NAME_EXT_MODULE(TFIBWideStringField * ElementFILE_NAME_EXT_MODULE)=0;

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
   virtual int OpenElement(__int64 id )=0;
   virtual bool NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void ChancheGrp(__int64 new_id_grp)=0;
   virtual __int64 FindPoName(AnsiString name)=0;
   virtual __int64 GetIdGrpExtModule(__int64 id_ext_module)=0;
};
#define IID_IDMExtModule __uuidof(IDMExtModule)
#endif
