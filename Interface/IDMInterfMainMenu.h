#ifndef UIDMInterfMainMenuH
#define UIDMInterfMainMenuH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMInterfMainMenu)) IDMInterfMainMenu : public IMainInterface
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

   __property TFIBLargeIntField * TableID_INTERF_MAINMENU = {read = get_TableID_INTERF_MAINMENU , write = set_TableID_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_TableID_INTERF_MAINMENU(void)=0;
   virtual void set_TableID_INTERF_MAINMENU(TFIBLargeIntField * TableID_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * TableIDBASE_INTERF_MAINMENU = {read = get_TableIDBASE_INTERF_MAINMENU , write = set_TableIDBASE_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_TableIDBASE_INTERF_MAINMENU(void)=0;
   virtual void set_TableIDBASE_INTERF_MAINMENU(TFIBLargeIntField * TableIDBASE_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * TableIDGRP_INTERF_MAINMENU = {read = get_TableIDGRP_INTERF_MAINMENU , write = set_TableIDGRP_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_TableIDGRP_INTERF_MAINMENU(void)=0;
   virtual void set_TableIDGRP_INTERF_MAINMENU(TFIBLargeIntField * TableIDGRP_INTERF_MAINMENU)=0;

   __property TFIBWideStringField * TableNAME_INTERF_MAINMENU = {read = get_TableNAME_INTERF_MAINMENU , write = set_TableNAME_INTERF_MAINMENU};
   virtual TFIBWideStringField * get_TableNAME_INTERF_MAINMENU(void)=0;
   virtual void set_TableNAME_INTERF_MAINMENU(TFIBWideStringField * TableNAME_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * TableMODUL_INTERF_MAINMENU = {read = get_TableMODUL_INTERF_MAINMENU , write = set_TableMODUL_INTERF_MAINMENU};
   virtual TFIBIntegerField * get_TableMODUL_INTERF_MAINMENU(void)=0;
   virtual void set_TableMODUL_INTERF_MAINMENU(TFIBIntegerField * TableMODUL_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * TableIDGRPUSER_INTERF_MAINMENU = {read = get_TableIDGRPUSER_INTERF_MAINMENU , write = set_TableIDGRPUSER_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_TableIDGRPUSER_INTERF_MAINMENU(void)=0;
   virtual void set_TableIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * TableIDGRPUSER_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * TableAPPLICATION_INTERF_MAINMENU = {read = get_TableAPPLICATION_INTERF_MAINMENU , write = set_TableAPPLICATION_INTERF_MAINMENU};
   virtual TFIBIntegerField * get_TableAPPLICATION_INTERF_MAINMENU(void)=0;
   virtual void set_TableAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * TableAPPLICATION_INTERF_MAINMENU)=0;

   __property TFIBWideStringField * TableSHORTCUT_INTERF_MAINMENU = {read = get_TableSHORTCUT_INTERF_MAINMENU , write = set_TableSHORTCUT_INTERF_MAINMENU};
   virtual TFIBWideStringField * get_TableSHORTCUT_INTERF_MAINMENU(void)=0;
   virtual void set_TableSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * TableSHORTCUT_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * TableINDEX_INTERF_MAINMENU = {read = get_TableINDEX_INTERF_MAINMENU , write = set_TableINDEX_INTERF_MAINMENU};
   virtual TFIBIntegerField * get_TableINDEX_INTERF_MAINMENU(void)=0;
   virtual void set_TableINDEX_INTERF_MAINMENU(TFIBIntegerField * TableINDEX_INTERF_MAINMENU)=0;

   __property TFIBWideStringField * TableNAME_SGRPUSER = {read = get_TableNAME_SGRPUSER , write = set_TableNAME_SGRPUSER};
   virtual TFIBWideStringField * get_TableNAME_SGRPUSER(void)=0;
   virtual void set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER)=0;

   __property TFIBWideStringField * TableNAME_PROGRAM_MODULE = {read = get_TableNAME_PROGRAM_MODULE , write = set_TableNAME_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void)=0;
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TablePROGID_PROGRAM_MODULE = {read = get_TablePROGID_PROGRAM_MODULE , write = set_TablePROGID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TablePROGID_PROGRAM_MODULE(void)=0;
   virtual void set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TablePATCH_PROGRAM_MODULE = {read = get_TablePATCH_PROGRAM_MODULE , write = set_TablePATCH_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void)=0;
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBLargeIntField * ElementID_INTERF_MAINMENU = {read = get_ElementID_INTERF_MAINMENU , write = set_ElementID_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_ElementID_INTERF_MAINMENU(void)=0;
   virtual void set_ElementID_INTERF_MAINMENU(TFIBLargeIntField * ElementID_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * ElementIDBASE_INTERF_MAINMENU = {read = get_ElementIDBASE_INTERF_MAINMENU , write = set_ElementIDBASE_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_ElementIDBASE_INTERF_MAINMENU(void)=0;
   virtual void set_ElementIDBASE_INTERF_MAINMENU(TFIBLargeIntField * ElementIDBASE_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * ElementIDGRP_INTERF_MAINMENU = {read = get_ElementIDGRP_INTERF_MAINMENU , write = set_ElementIDGRP_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_ElementIDGRP_INTERF_MAINMENU(void)=0;
   virtual void set_ElementIDGRP_INTERF_MAINMENU(TFIBLargeIntField * ElementIDGRP_INTERF_MAINMENU)=0;

   __property TFIBWideStringField * ElementNAME_INTERF_MAINMENU = {read = get_ElementNAME_INTERF_MAINMENU , write = set_ElementNAME_INTERF_MAINMENU};
   virtual TFIBWideStringField * get_ElementNAME_INTERF_MAINMENU(void)=0;
   virtual void set_ElementNAME_INTERF_MAINMENU(TFIBWideStringField * ElementNAME_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * ElementMODUL_INTERF_MAINMENU = {read = get_ElementMODUL_INTERF_MAINMENU , write = set_ElementMODUL_INTERF_MAINMENU};
   virtual TFIBIntegerField * get_ElementMODUL_INTERF_MAINMENU(void)=0;
   virtual void set_ElementMODUL_INTERF_MAINMENU(TFIBIntegerField * ElementMODUL_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * ElementIDGRPUSER_INTERF_MAINMENU = {read = get_ElementIDGRPUSER_INTERF_MAINMENU , write = set_ElementIDGRPUSER_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_ElementIDGRPUSER_INTERF_MAINMENU(void)=0;
   virtual void set_ElementIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * ElementIDGRPUSER_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * ElementAPPLICATION_INTERF_MAINMENU = {read = get_ElementAPPLICATION_INTERF_MAINMENU , write = set_ElementAPPLICATION_INTERF_MAINMENU};
   virtual TFIBIntegerField * get_ElementAPPLICATION_INTERF_MAINMENU(void)=0;
   virtual void set_ElementAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * ElementAPPLICATION_INTERF_MAINMENU)=0;

   __property TFIBWideStringField * ElementSHORTCUT_INTERF_MAINMENU = {read = get_ElementSHORTCUT_INTERF_MAINMENU , write = set_ElementSHORTCUT_INTERF_MAINMENU};
   virtual TFIBWideStringField * get_ElementSHORTCUT_INTERF_MAINMENU(void)=0;
   virtual void set_ElementSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * ElementSHORTCUT_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * ElementINDEX_INTERF_MAINMENU = {read = get_ElementINDEX_INTERF_MAINMENU , write = set_ElementINDEX_INTERF_MAINMENU};
   virtual TFIBIntegerField * get_ElementINDEX_INTERF_MAINMENU(void)=0;
   virtual void set_ElementINDEX_INTERF_MAINMENU(TFIBIntegerField * ElementINDEX_INTERF_MAINMENU)=0;

   __property TFIBWideStringField * ElementNAME_PROGRAM_MODULE = {read = get_ElementNAME_PROGRAM_MODULE , write = set_ElementNAME_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void)=0;
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementPROGID_PROGRAM_MODULE = {read = get_ElementPROGID_PROGRAM_MODULE , write = set_ElementPROGID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementPROGID_PROGRAM_MODULE(void)=0;
   virtual void set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementPATCH_PROGRAM_MODULE = {read = get_ElementPATCH_PROGRAM_MODULE , write = set_ElementPATCH_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void)=0;
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)=0;

   __property TFIBSmallIntField * TableFL_UPD_FORM_INTERF_MAINMENU = {read = get_TableFL_UPD_FORM_INTERF_MAINMENU , write = set_TableFL_UPD_FORM_INTERF_MAINMENU};
   virtual TFIBSmallIntField * get_TableFL_UPD_FORM_INTERF_MAINMENU(void)=0;
   virtual void set_TableFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * TableFL_UPD_FORM_INTERF_MAINMENU)=0;

   __property TFIBSmallIntField * TableFL_NEW_DOC_INTERF_MAINMENU = {read = get_TableFL_NEW_DOC_INTERF_MAINMENU , write = set_TableFL_NEW_DOC_INTERF_MAINMENU};
   virtual TFIBSmallIntField * get_TableFL_NEW_DOC_INTERF_MAINMENU(void)=0;
   virtual void set_TableFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * TableFL_NEW_DOC_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * TableIDEL_INTERF_MAINMENU = {read = get_TableIDEL_INTERF_MAINMENU , write = set_TableIDEL_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_TableIDEL_INTERF_MAINMENU(void)=0;
   virtual void set_TableIDEL_INTERF_MAINMENU(TFIBLargeIntField * TableIDEL_INTERF_MAINMENU)=0;

   __property TFIBSmallIntField * TableFL_OPEN_EL_INTERF_MAINMENU = {read = get_TableFL_OPEN_EL_INTERF_MAINMENU , write = set_TableFL_OPEN_EL_INTERF_MAINMENU};
   virtual TFIBSmallIntField * get_TableFL_OPEN_EL_INTERF_MAINMENU(void)=0;
   virtual void set_TableFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * TableFL_OPEN_EL_INTERF_MAINMENU)=0;

   __property TFIBSmallIntField * ElementFL_UPD_FORM_INTERF_MAINMENU = {read = get_ElementFL_UPD_FORM_INTERF_MAINMENU , write = set_ElementFL_UPD_FORM_INTERF_MAINMENU};
   virtual TFIBSmallIntField * get_ElementFL_UPD_FORM_INTERF_MAINMENU(void)=0;
   virtual void set_ElementFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_UPD_FORM_INTERF_MAINMENU)=0;

   __property TFIBSmallIntField * ElementFL_NEW_DOC_INTERF_MAINMENU = {read = get_ElementFL_NEW_DOC_INTERF_MAINMENU , write = set_ElementFL_NEW_DOC_INTERF_MAINMENU};
   virtual TFIBSmallIntField * get_ElementFL_NEW_DOC_INTERF_MAINMENU(void)=0;
   virtual void set_ElementFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_NEW_DOC_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * ElementIDEL_INTERF_MAINMENU = {read = get_ElementIDEL_INTERF_MAINMENU , write = set_ElementIDEL_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_ElementIDEL_INTERF_MAINMENU(void)=0;
   virtual void set_ElementIDEL_INTERF_MAINMENU(TFIBLargeIntField * ElementIDEL_INTERF_MAINMENU)=0;

   __property TFIBSmallIntField * ElementFL_OPEN_EL_INTERF_MAINMENU = {read = get_ElementFL_OPEN_EL_INTERF_MAINMENU , write = set_ElementFL_OPEN_EL_INTERF_MAINMENU};
   virtual TFIBSmallIntField * get_ElementFL_OPEN_EL_INTERF_MAINMENU(void)=0;
   virtual void set_ElementFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_OPEN_EL_INTERF_MAINMENU)=0;

   __property TFIBWideStringField * TableGUIDMOD_INTERF_MAINMENU = {read = get_TableGUIDMOD_INTERF_MAINMENU , write = set_TableGUIDMOD_INTERF_MAINMENU};
   virtual TFIBWideStringField * get_TableGUIDMOD_INTERF_MAINMENU(void)=0;
   virtual void set_TableGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * TableGUIDMOD_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * TableTYPE_IDEL_INTERF_MAINMENU = {read = get_TableTYPE_IDEL_INTERF_MAINMENU , write = set_TableTYPE_IDEL_INTERF_MAINMENU};
   virtual TFIBIntegerField * get_TableTYPE_IDEL_INTERF_MAINMENU(void)=0;
   virtual void set_TableTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * TableTYPE_IDEL_INTERF_MAINMENU)=0;

   __property TFIBWideStringField * ElementGUIDMOD_INTERF_MAINMENU = {read = get_ElementGUIDMOD_INTERF_MAINMENU , write = set_ElementGUIDMOD_INTERF_MAINMENU};
   virtual TFIBWideStringField * get_ElementGUIDMOD_INTERF_MAINMENU(void)=0;
   virtual void set_ElementGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * ElementGUIDMOD_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * ElementTYPE_IDEL_INTERF_MAINMENU = {read = get_ElementTYPE_IDEL_INTERF_MAINMENU , write = set_ElementTYPE_IDEL_INTERF_MAINMENU};
   virtual TFIBIntegerField * get_ElementTYPE_IDEL_INTERF_MAINMENU(void)=0;
   virtual void set_ElementTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * ElementTYPE_IDEL_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * TableIDMOD_INTERF_MAINMENU = {read = get_TableIDMOD_INTERF_MAINMENU , write = set_TableIDMOD_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_TableIDMOD_INTERF_MAINMENU(void)=0;
   virtual void set_TableIDMOD_INTERF_MAINMENU(TFIBLargeIntField * TableIDMOD_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * TableTYPEMOD_PROGRAM_MODULE = {read = get_TableTYPEMOD_PROGRAM_MODULE , write = set_TableTYPEMOD_PROGRAM_MODULE};
   virtual TFIBIntegerField * get_TableTYPEMOD_PROGRAM_MODULE(void)=0;
   virtual void set_TableTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * TableTYPEMOD_PROGRAM_MODULE)=0;

   __property TFIBLargeIntField * ElementIDMOD_INTERF_MAINMENU = {read = get_ElementIDMOD_INTERF_MAINMENU , write = set_ElementIDMOD_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_ElementIDMOD_INTERF_MAINMENU(void)=0;
   virtual void set_ElementIDMOD_INTERF_MAINMENU(TFIBLargeIntField * ElementIDMOD_INTERF_MAINMENU)=0;

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

   virtual void OpenTable(int num_application, __int64 id_grp_user, __int64 id_grp, bool all)=0;
   virtual bool SaveIsmen()=0;
   virtual void CancelIsmen()=0;
   virtual bool Table_Delete(void)=0;
   virtual bool Table_AppendString(int num_application, __int64 id_grp_user, __int64 id_grp)=0;
   virtual bool NewElement(int num_application, __int64 id_grp_user, __int64 id_grp)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool InsertElement(int num_application, __int64 id_grp_user, __int64 id_grp)=0;
   virtual void Element_Edit(void)=0;
   virtual void Element_Post(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void ChancheGrp(__int64 id_new_grp)=0;
};
#define IID_IDMInterfMainMenu __uuidof(IDMInterfMainMenu)
#endif
