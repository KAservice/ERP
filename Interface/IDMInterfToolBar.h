#ifndef UIDMInterfToolBarH
#define UIDMInterfToolBarH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMInterfToolBar)) IDMInterfToolBar : public IMainInterface
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

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBLargeIntField * TableID_INTERF_TOOLBAR = {read = get_TableID_INTERF_TOOLBAR , write = set_TableID_INTERF_TOOLBAR};
   virtual TFIBLargeIntField * get_TableID_INTERF_TOOLBAR(void)=0;
   virtual void set_TableID_INTERF_TOOLBAR(TFIBLargeIntField * TableID_INTERF_TOOLBAR)=0;

   __property TFIBLargeIntField * TableIDBASE_INTERF_TOOLBAR = {read = get_TableIDBASE_INTERF_TOOLBAR , write = set_TableIDBASE_INTERF_TOOLBAR};
   virtual TFIBLargeIntField * get_TableIDBASE_INTERF_TOOLBAR(void)=0;
   virtual void set_TableIDBASE_INTERF_TOOLBAR(TFIBLargeIntField * TableIDBASE_INTERF_TOOLBAR)=0;

   __property TFIBWideStringField * TableNAME_INTERF_TOOLBAR = {read = get_TableNAME_INTERF_TOOLBAR , write = set_TableNAME_INTERF_TOOLBAR};
   virtual TFIBWideStringField * get_TableNAME_INTERF_TOOLBAR(void)=0;
   virtual void set_TableNAME_INTERF_TOOLBAR(TFIBWideStringField * TableNAME_INTERF_TOOLBAR)=0;

   __property TFIBLargeIntField * TableIDGRPUSER_INTERF_TOOLBAR = {read = get_TableIDGRPUSER_INTERF_TOOLBAR , write = set_TableIDGRPUSER_INTERF_TOOLBAR};
   virtual TFIBLargeIntField * get_TableIDGRPUSER_INTERF_TOOLBAR(void)=0;
   virtual void set_TableIDGRPUSER_INTERF_TOOLBAR(TFIBLargeIntField * TableIDGRPUSER_INTERF_TOOLBAR)=0;

   __property TFIBIntegerField * TableAPPLICATION_INTERF_TOOLBAR = {read = get_TableAPPLICATION_INTERF_TOOLBAR , write = set_TableAPPLICATION_INTERF_TOOLBAR};
   virtual TFIBIntegerField * get_TableAPPLICATION_INTERF_TOOLBAR(void)=0;
   virtual void set_TableAPPLICATION_INTERF_TOOLBAR(TFIBIntegerField * TableAPPLICATION_INTERF_TOOLBAR)=0;

   __property TFIBIntegerField * TableMODUL_INTERF_TOOLBAR = {read = get_TableMODUL_INTERF_TOOLBAR , write = set_TableMODUL_INTERF_TOOLBAR};
   virtual TFIBIntegerField * get_TableMODUL_INTERF_TOOLBAR(void)=0;
   virtual void set_TableMODUL_INTERF_TOOLBAR(TFIBIntegerField * TableMODUL_INTERF_TOOLBAR)=0;

   __property TFIBWideStringField * TableHINT_INTERF_TOOLBAR = {read = get_TableHINT_INTERF_TOOLBAR , write = set_TableHINT_INTERF_TOOLBAR};
   virtual TFIBWideStringField * get_TableHINT_INTERF_TOOLBAR(void)=0;
   virtual void set_TableHINT_INTERF_TOOLBAR(TFIBWideStringField * TableHINT_INTERF_TOOLBAR)=0;

   __property TFIBIntegerField * TableIMAGEINDEX_INTERF_TOOLBAR = {read = get_TableIMAGEINDEX_INTERF_TOOLBAR , write = set_TableIMAGEINDEX_INTERF_TOOLBAR};
   virtual TFIBIntegerField * get_TableIMAGEINDEX_INTERF_TOOLBAR(void)=0;
   virtual void set_TableIMAGEINDEX_INTERF_TOOLBAR(TFIBIntegerField * TableIMAGEINDEX_INTERF_TOOLBAR)=0;

   __property TFIBIntegerField * TableINDEX_INTERF_TOOLBAR = {read = get_TableINDEX_INTERF_TOOLBAR , write = set_TableINDEX_INTERF_TOOLBAR};
   virtual TFIBIntegerField * get_TableINDEX_INTERF_TOOLBAR(void)=0;
   virtual void set_TableINDEX_INTERF_TOOLBAR(TFIBIntegerField * TableINDEX_INTERF_TOOLBAR)=0;

   __property TFIBWideStringField * TableNAME_PROGRAM_MODULE = {read = get_TableNAME_PROGRAM_MODULE , write = set_TableNAME_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void)=0;
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TablePROGID_PROGRAM_MODULE = {read = get_TablePROGID_PROGRAM_MODULE , write = set_TablePROGID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TablePROGID_PROGRAM_MODULE(void)=0;
   virtual void set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TablePATCH_PROGRAM_MODULE = {read = get_TablePATCH_PROGRAM_MODULE , write = set_TablePATCH_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void)=0;
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)=0;

   __property TFIBLargeIntField * ElementID_INTERF_TOOLBAR = {read = get_ElementID_INTERF_TOOLBAR , write = set_ElementID_INTERF_TOOLBAR};
   virtual TFIBLargeIntField * get_ElementID_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementID_INTERF_TOOLBAR(TFIBLargeIntField * ElementID_INTERF_TOOLBAR)=0;

   __property TFIBLargeIntField * ElementIDBASE_INTERF_TOOLBAR = {read = get_ElementIDBASE_INTERF_TOOLBAR , write = set_ElementIDBASE_INTERF_TOOLBAR};
   virtual TFIBLargeIntField * get_ElementIDBASE_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementIDBASE_INTERF_TOOLBAR(TFIBLargeIntField * ElementIDBASE_INTERF_TOOLBAR)=0;

   __property TFIBWideStringField * ElementNAME_INTERF_TOOLBAR = {read = get_ElementNAME_INTERF_TOOLBAR , write = set_ElementNAME_INTERF_TOOLBAR};
   virtual TFIBWideStringField * get_ElementNAME_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementNAME_INTERF_TOOLBAR(TFIBWideStringField * ElementNAME_INTERF_TOOLBAR)=0;

   __property TFIBLargeIntField * ElementIDGRPUSER_INTERF_TOOLBAR = {read = get_ElementIDGRPUSER_INTERF_TOOLBAR , write = set_ElementIDGRPUSER_INTERF_TOOLBAR};
   virtual TFIBLargeIntField * get_ElementIDGRPUSER_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementIDGRPUSER_INTERF_TOOLBAR(TFIBLargeIntField * ElementIDGRPUSER_INTERF_TOOLBAR)=0;

   __property TFIBIntegerField * ElementAPPLICATION_INTERF_TOOLBAR = {read = get_ElementAPPLICATION_INTERF_TOOLBAR , write = set_ElementAPPLICATION_INTERF_TOOLBAR};
   virtual TFIBIntegerField * get_ElementAPPLICATION_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementAPPLICATION_INTERF_TOOLBAR(TFIBIntegerField * ElementAPPLICATION_INTERF_TOOLBAR)=0;

   __property TFIBIntegerField * ElementMODUL_INTERF_TOOLBAR = {read = get_ElementMODUL_INTERF_TOOLBAR , write = set_ElementMODUL_INTERF_TOOLBAR};
   virtual TFIBIntegerField * get_ElementMODUL_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementMODUL_INTERF_TOOLBAR(TFIBIntegerField * ElementMODUL_INTERF_TOOLBAR)=0;

   __property TFIBWideStringField * ElementHINT_INTERF_TOOLBAR = {read = get_ElementHINT_INTERF_TOOLBAR , write = set_ElementHINT_INTERF_TOOLBAR};
   virtual TFIBWideStringField * get_ElementHINT_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementHINT_INTERF_TOOLBAR(TFIBWideStringField * ElementHINT_INTERF_TOOLBAR)=0;

   __property TFIBIntegerField * ElementIMAGEINDEX_INTERF_TOOLBAR = {read = get_ElementIMAGEINDEX_INTERF_TOOLBAR , write = set_ElementIMAGEINDEX_INTERF_TOOLBAR};
   virtual TFIBIntegerField * get_ElementIMAGEINDEX_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementIMAGEINDEX_INTERF_TOOLBAR(TFIBIntegerField * ElementIMAGEINDEX_INTERF_TOOLBAR)=0;

   __property TFIBIntegerField * ElementINDEX_INTERF_TOOLBAR = {read = get_ElementINDEX_INTERF_TOOLBAR , write = set_ElementINDEX_INTERF_TOOLBAR};
   virtual TFIBIntegerField * get_ElementINDEX_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementINDEX_INTERF_TOOLBAR(TFIBIntegerField * ElementINDEX_INTERF_TOOLBAR)=0;

   __property TFIBWideStringField * ElementNAME_PROGRAM_MODULE = {read = get_ElementNAME_PROGRAM_MODULE , write = set_ElementNAME_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void)=0;
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementPROGID_PROGRAM_MODULE = {read = get_ElementPROGID_PROGRAM_MODULE , write = set_ElementPROGID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementPROGID_PROGRAM_MODULE(void)=0;
   virtual void set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementPATCH_PROGRAM_MODULE = {read = get_ElementPATCH_PROGRAM_MODULE , write = set_ElementPATCH_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void)=0;
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementGUIDMOD_INTERF_TOOLBAR = {read = get_ElementGUIDMOD_INTERF_TOOLBAR , write = set_ElementGUIDMOD_INTERF_TOOLBAR};
   virtual TFIBWideStringField * get_ElementGUIDMOD_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementGUIDMOD_INTERF_TOOLBAR(TFIBWideStringField * ElementGUIDMOD_INTERF_TOOLBAR)=0;

   __property TFIBWideStringField * TableGUIDMOD_INTERF_TOOLBAR = {read = get_TableGUIDMOD_INTERF_TOOLBAR , write = set_TableGUIDMOD_INTERF_TOOLBAR};
   virtual TFIBWideStringField * get_TableGUIDMOD_INTERF_TOOLBAR(void)=0;
   virtual void set_TableGUIDMOD_INTERF_TOOLBAR(TFIBWideStringField * TableGUIDMOD_INTERF_TOOLBAR)=0;

   __property TFIBLargeIntField * TableIDMOD_INTERF_TOOLBAR = {read = get_TableIDMOD_INTERF_TOOLBAR , write = set_TableIDMOD_INTERF_TOOLBAR};
   virtual TFIBLargeIntField * get_TableIDMOD_INTERF_TOOLBAR(void)=0;
   virtual void set_TableIDMOD_INTERF_TOOLBAR(TFIBLargeIntField * TableIDMOD_INTERF_TOOLBAR)=0;

   __property TFIBSmallIntField * TableFL_UPD_FORM_INTERF_TOOLBAR = {read = get_TableFL_UPD_FORM_INTERF_TOOLBAR , write = set_TableFL_UPD_FORM_INTERF_TOOLBAR};
   virtual TFIBSmallIntField * get_TableFL_UPD_FORM_INTERF_TOOLBAR(void)=0;
   virtual void set_TableFL_UPD_FORM_INTERF_TOOLBAR(TFIBSmallIntField * TableFL_UPD_FORM_INTERF_TOOLBAR)=0;

   __property TFIBLargeIntField * TableIDEL_INTERF_TOOLBAR = {read = get_TableIDEL_INTERF_TOOLBAR , write = set_TableIDEL_INTERF_TOOLBAR};
   virtual TFIBLargeIntField * get_TableIDEL_INTERF_TOOLBAR(void)=0;
   virtual void set_TableIDEL_INTERF_TOOLBAR(TFIBLargeIntField * TableIDEL_INTERF_TOOLBAR)=0;

   __property TFIBSmallIntField * TableFL_OPEN_EL_INTERF_TOOLBAR = {read = get_TableFL_OPEN_EL_INTERF_TOOLBAR , write = set_TableFL_OPEN_EL_INTERF_TOOLBAR};
   virtual TFIBSmallIntField * get_TableFL_OPEN_EL_INTERF_TOOLBAR(void)=0;
   virtual void set_TableFL_OPEN_EL_INTERF_TOOLBAR(TFIBSmallIntField * TableFL_OPEN_EL_INTERF_TOOLBAR)=0;

   __property TFIBIntegerField * TableTYPE_IDEL_INTERF_TOOLBAR = {read = get_TableTYPE_IDEL_INTERF_TOOLBAR , write = set_TableTYPE_IDEL_INTERF_TOOLBAR};
   virtual TFIBIntegerField * get_TableTYPE_IDEL_INTERF_TOOLBAR(void)=0;
   virtual void set_TableTYPE_IDEL_INTERF_TOOLBAR(TFIBIntegerField * TableTYPE_IDEL_INTERF_TOOLBAR)=0;

   __property TFIBLargeIntField * ElementIDMOD_INTERF_TOOLBAR = {read = get_ElementIDMOD_INTERF_TOOLBAR , write = set_ElementIDMOD_INTERF_TOOLBAR};
   virtual TFIBLargeIntField * get_ElementIDMOD_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementIDMOD_INTERF_TOOLBAR(TFIBLargeIntField * ElementIDMOD_INTERF_TOOLBAR)=0;

   __property TFIBSmallIntField * ElementFL_UPD_FORM_INTERF_TOOLBAR = {read = get_ElementFL_UPD_FORM_INTERF_TOOLBAR , write = set_ElementFL_UPD_FORM_INTERF_TOOLBAR};
   virtual TFIBSmallIntField * get_ElementFL_UPD_FORM_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementFL_UPD_FORM_INTERF_TOOLBAR(TFIBSmallIntField * ElementFL_UPD_FORM_INTERF_TOOLBAR)=0;

   __property TFIBLargeIntField * ElementIDEL_INTERF_TOOLBAR = {read = get_ElementIDEL_INTERF_TOOLBAR , write = set_ElementIDEL_INTERF_TOOLBAR};
   virtual TFIBLargeIntField * get_ElementIDEL_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementIDEL_INTERF_TOOLBAR(TFIBLargeIntField * ElementIDEL_INTERF_TOOLBAR)=0;

   __property TFIBSmallIntField * ElementFL_OPEN_EL_INTERF_TOOLBAR = {read = get_ElementFL_OPEN_EL_INTERF_TOOLBAR , write = set_ElementFL_OPEN_EL_INTERF_TOOLBAR};
   virtual TFIBSmallIntField * get_ElementFL_OPEN_EL_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementFL_OPEN_EL_INTERF_TOOLBAR(TFIBSmallIntField * ElementFL_OPEN_EL_INTERF_TOOLBAR)=0;

   __property TFIBIntegerField * ElementTYPE_IDEL_INTERF_TOOLBAR = {read = get_ElementTYPE_IDEL_INTERF_TOOLBAR , write = set_ElementTYPE_IDEL_INTERF_TOOLBAR};
   virtual TFIBIntegerField * get_ElementTYPE_IDEL_INTERF_TOOLBAR(void)=0;
   virtual void set_ElementTYPE_IDEL_INTERF_TOOLBAR(TFIBIntegerField * ElementTYPE_IDEL_INTERF_TOOLBAR)=0;

   __property TFIBIntegerField * ElementTYPEMOD_PROGRAM_MODULE = {read = get_ElementTYPEMOD_PROGRAM_MODULE , write = set_ElementTYPEMOD_PROGRAM_MODULE};
   virtual TFIBIntegerField * get_ElementTYPEMOD_PROGRAM_MODULE(void)=0;
   virtual void set_ElementTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * ElementTYPEMOD_PROGRAM_MODULE)=0;

   __property int NumApplication = {read = get_NumApplication , write = set_NumApplication};
   virtual int get_NumApplication(void)=0;
   virtual void set_NumApplication(int NumApplication)=0;

   __property __int64 IdGrpUser = {read = get_IdGrpUser , write = set_IdGrpUser};
   virtual __int64 get_IdGrpUser(void)=0;
   virtual void set_IdGrpUser(__int64 IdGrpUser)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void OpenTable(int num_application, __int64 id_grp_user)=0;
   virtual bool SaveIsmen()=0;
   virtual void CancelIsmen()=0;
   virtual bool Table_Delete(void)=0;
   virtual bool Table_AppendString(int num_application, __int64 id_grp_user)=0;
   virtual bool NewElement(int num_application, __int64 id_grp_user)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool InsertElement(int num_application, __int64 id_grp_user)=0;
   virtual void Element_Edit(void)=0;
   virtual void Element_Post(void)=0;
   virtual bool SaveElement(void)=0;
};
#define IID_IDMInterfToolBar __uuidof(IDMInterfToolBar)
#endif
