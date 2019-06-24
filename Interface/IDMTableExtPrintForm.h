#ifndef UIDMTableExtPrintFormH
#define UIDMTableExtPrintFormH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMTableExtPrintForm)) IDMTableExtPrintForm : public IMainInterface
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

   __property TFIBLargeIntField * TableID_EXTPRINT_FORM = {read = get_TableID_EXTPRINT_FORM , write = set_TableID_EXTPRINT_FORM};
   virtual TFIBLargeIntField * get_TableID_EXTPRINT_FORM(void)=0;
   virtual void set_TableID_EXTPRINT_FORM(TFIBLargeIntField * TableID_EXTPRINT_FORM)=0;

   __property TFIBWideStringField * TableNAME_EXTPRINT_FORM = {read = get_TableNAME_EXTPRINT_FORM , write = set_TableNAME_EXTPRINT_FORM};
   virtual TFIBWideStringField * get_TableNAME_EXTPRINT_FORM(void)=0;
   virtual void set_TableNAME_EXTPRINT_FORM(TFIBWideStringField * TableNAME_EXTPRINT_FORM)=0;

   __property TFIBWideStringField * TableOBJECT_EXTPRINT_FORM = {read = get_TableOBJECT_EXTPRINT_FORM , write = set_TableOBJECT_EXTPRINT_FORM};
   virtual TFIBWideStringField * get_TableOBJECT_EXTPRINT_FORM(void)=0;
   virtual void set_TableOBJECT_EXTPRINT_FORM(TFIBWideStringField * TableOBJECT_EXTPRINT_FORM)=0;

   __property TFIBWideStringField * TableFILE_NAME_EXTPRINT_FORM = {read = get_TableFILE_NAME_EXTPRINT_FORM , write = set_TableFILE_NAME_EXTPRINT_FORM};
   virtual TFIBWideStringField * get_TableFILE_NAME_EXTPRINT_FORM(void)=0;
   virtual void set_TableFILE_NAME_EXTPRINT_FORM(TFIBWideStringField * TableFILE_NAME_EXTPRINT_FORM)=0;

   __property TFIBIntegerField * TableISPCONST_EXTPRINT_FORM = {read = get_TableISPCONST_EXTPRINT_FORM , write = set_TableISPCONST_EXTPRINT_FORM};
   virtual TFIBIntegerField * get_TableISPCONST_EXTPRINT_FORM(void)=0;
   virtual void set_TableISPCONST_EXTPRINT_FORM(TFIBIntegerField * TableISPCONST_EXTPRINT_FORM)=0;

   __property TFIBWideStringField * TableGID_EXTPRINT_FORM = {read = get_TableGID_EXTPRINT_FORM , write = set_TableGID_EXTPRINT_FORM};
   virtual TFIBWideStringField * get_TableGID_EXTPRINT_FORM(void)=0;
   virtual void set_TableGID_EXTPRINT_FORM(TFIBWideStringField * TableGID_EXTPRINT_FORM)=0;

   __property TFIBLargeIntField * TableIDBASE_EXTPRINT_FORM = {read = get_TableIDBASE_EXTPRINT_FORM , write = set_TableIDBASE_EXTPRINT_FORM};
   virtual TFIBLargeIntField * get_TableIDBASE_EXTPRINT_FORM(void)=0;
   virtual void set_TableIDBASE_EXTPRINT_FORM(TFIBLargeIntField * TableIDBASE_EXTPRINT_FORM)=0;

   __property TFIBIntegerField * TableTYPEMODULE_EXTPRINT_FORM = {read = get_TableTYPEMODULE_EXTPRINT_FORM , write = set_TableTYPEMODULE_EXTPRINT_FORM};
   virtual TFIBIntegerField * get_TableTYPEMODULE_EXTPRINT_FORM(void)=0;
   virtual void set_TableTYPEMODULE_EXTPRINT_FORM(TFIBIntegerField * TableTYPEMODULE_EXTPRINT_FORM)=0;

   __property TFIBIntegerField * TableRESIDENCE_EXTPRINT_FORM = {read = get_TableRESIDENCE_EXTPRINT_FORM , write = set_TableRESIDENCE_EXTPRINT_FORM};
   virtual TFIBIntegerField * get_TableRESIDENCE_EXTPRINT_FORM(void)=0;
   virtual void set_TableRESIDENCE_EXTPRINT_FORM(TFIBIntegerField * TableRESIDENCE_EXTPRINT_FORM)=0;

   __property TFIBBlobField * TableBODY_EXTPRINT_FORM = {read = get_TableBODY_EXTPRINT_FORM , write = set_TableBODY_EXTPRINT_FORM};
   virtual TFIBBlobField * get_TableBODY_EXTPRINT_FORM(void)=0;
   virtual void set_TableBODY_EXTPRINT_FORM(TFIBBlobField * TableBODY_EXTPRINT_FORM)=0;

   __property TFIBWideStringField * TableGUID_OB_EXTPRINT_FORM = {read = get_TableGUID_OB_EXTPRINT_FORM , write = set_TableGUID_OB_EXTPRINT_FORM};
   virtual TFIBWideStringField * get_TableGUID_OB_EXTPRINT_FORM(void)=0;
   virtual void set_TableGUID_OB_EXTPRINT_FORM(TFIBWideStringField * TableGUID_OB_EXTPRINT_FORM)=0;

   __property TFIBWideStringField * TableNAME_PROGRAM_MODULE = {read = get_TableNAME_PROGRAM_MODULE , write = set_TableNAME_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void)=0;
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TablePROGID_PROGRAM_MODULE = {read = get_TablePROGID_PROGRAM_MODULE , write = set_TablePROGID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TablePROGID_PROGRAM_MODULE(void)=0;
   virtual void set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TablePATCH_PROGRAM_MODULE = {read = get_TablePATCH_PROGRAM_MODULE , write = set_TablePATCH_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void)=0;
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)=0;

   __property TFIBLargeIntField * ElementID_EXTPRINT_FORM = {read = get_ElementID_EXTPRINT_FORM , write = set_ElementID_EXTPRINT_FORM};
   virtual TFIBLargeIntField * get_ElementID_EXTPRINT_FORM(void)=0;
   virtual void set_ElementID_EXTPRINT_FORM(TFIBLargeIntField * ElementID_EXTPRINT_FORM)=0;

   __property TFIBWideStringField * ElementNAME_EXTPRINT_FORM = {read = get_ElementNAME_EXTPRINT_FORM , write = set_ElementNAME_EXTPRINT_FORM};
   virtual TFIBWideStringField * get_ElementNAME_EXTPRINT_FORM(void)=0;
   virtual void set_ElementNAME_EXTPRINT_FORM(TFIBWideStringField * ElementNAME_EXTPRINT_FORM)=0;

   __property TFIBWideStringField * ElementOBJECT_EXTPRINT_FORM = {read = get_ElementOBJECT_EXTPRINT_FORM , write = set_ElementOBJECT_EXTPRINT_FORM};
   virtual TFIBWideStringField * get_ElementOBJECT_EXTPRINT_FORM(void)=0;
   virtual void set_ElementOBJECT_EXTPRINT_FORM(TFIBWideStringField * ElementOBJECT_EXTPRINT_FORM)=0;

   __property TFIBWideStringField * ElementFILE_NAME_EXTPRINT_FORM = {read = get_ElementFILE_NAME_EXTPRINT_FORM , write = set_ElementFILE_NAME_EXTPRINT_FORM};
   virtual TFIBWideStringField * get_ElementFILE_NAME_EXTPRINT_FORM(void)=0;
   virtual void set_ElementFILE_NAME_EXTPRINT_FORM(TFIBWideStringField * ElementFILE_NAME_EXTPRINT_FORM)=0;

   __property TFIBIntegerField * ElementISPCONST_EXTPRINT_FORM = {read = get_ElementISPCONST_EXTPRINT_FORM , write = set_ElementISPCONST_EXTPRINT_FORM};
   virtual TFIBIntegerField * get_ElementISPCONST_EXTPRINT_FORM(void)=0;
   virtual void set_ElementISPCONST_EXTPRINT_FORM(TFIBIntegerField * ElementISPCONST_EXTPRINT_FORM)=0;

   __property TFIBWideStringField * ElementGID_EXTPRINT_FORM = {read = get_ElementGID_EXTPRINT_FORM , write = set_ElementGID_EXTPRINT_FORM};
   virtual TFIBWideStringField * get_ElementGID_EXTPRINT_FORM(void)=0;
   virtual void set_ElementGID_EXTPRINT_FORM(TFIBWideStringField * ElementGID_EXTPRINT_FORM)=0;

   __property TFIBLargeIntField * ElementIDBASE_EXTPRINT_FORM = {read = get_ElementIDBASE_EXTPRINT_FORM , write = set_ElementIDBASE_EXTPRINT_FORM};
   virtual TFIBLargeIntField * get_ElementIDBASE_EXTPRINT_FORM(void)=0;
   virtual void set_ElementIDBASE_EXTPRINT_FORM(TFIBLargeIntField * ElementIDBASE_EXTPRINT_FORM)=0;

   __property TFIBIntegerField * ElementTYPEMODULE_EXTPRINT_FORM = {read = get_ElementTYPEMODULE_EXTPRINT_FORM , write = set_ElementTYPEMODULE_EXTPRINT_FORM};
   virtual TFIBIntegerField * get_ElementTYPEMODULE_EXTPRINT_FORM(void)=0;
   virtual void set_ElementTYPEMODULE_EXTPRINT_FORM(TFIBIntegerField * ElementTYPEMODULE_EXTPRINT_FORM)=0;

   __property TFIBIntegerField * ElementRESIDENCE_EXTPRINT_FORM = {read = get_ElementRESIDENCE_EXTPRINT_FORM , write = set_ElementRESIDENCE_EXTPRINT_FORM};
   virtual TFIBIntegerField * get_ElementRESIDENCE_EXTPRINT_FORM(void)=0;
   virtual void set_ElementRESIDENCE_EXTPRINT_FORM(TFIBIntegerField * ElementRESIDENCE_EXTPRINT_FORM)=0;

   __property TFIBBlobField * ElementBODY_EXTPRINT_FORM = {read = get_ElementBODY_EXTPRINT_FORM , write = set_ElementBODY_EXTPRINT_FORM};
   virtual TFIBBlobField * get_ElementBODY_EXTPRINT_FORM(void)=0;
   virtual void set_ElementBODY_EXTPRINT_FORM(TFIBBlobField * ElementBODY_EXTPRINT_FORM)=0;

   __property TFIBWideStringField * ElementGUID_OB_EXTPRINT_FORM = {read = get_ElementGUID_OB_EXTPRINT_FORM , write = set_ElementGUID_OB_EXTPRINT_FORM};
   virtual TFIBWideStringField * get_ElementGUID_OB_EXTPRINT_FORM(void)=0;
   virtual void set_ElementGUID_OB_EXTPRINT_FORM(TFIBWideStringField * ElementGUID_OB_EXTPRINT_FORM)=0;

   __property TFIBWideStringField * ElementNAME_PROGRAM_MODULE = {read = get_ElementNAME_PROGRAM_MODULE , write = set_ElementNAME_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void)=0;
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementPROGID_PROGRAM_MODULE = {read = get_ElementPROGID_PROGRAM_MODULE , write = set_ElementPROGID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementPROGID_PROGRAM_MODULE(void)=0;
   virtual void set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementPATCH_PROGRAM_MODULE = {read = get_ElementPATCH_PROGRAM_MODULE , write = set_ElementPATCH_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void)=0;
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)=0;

   virtual void OpenTable(REFIID guid, bool all)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual __int64 GetIDElement(String gid)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
};
#define IID_IDMTableExtPrintForm __uuidof(IDMTableExtPrintForm)
#endif
