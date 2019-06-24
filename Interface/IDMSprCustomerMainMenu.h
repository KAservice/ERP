#ifndef UIDMSprCustomerMainMenuH
#define UIDMSprCustomerMainMenuH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprCustomerMainMenu)) IDMSprCustomerMainMenu : public IMainInterface
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

   __property TFIBLargeIntField * TableID_CUST_MAINMENU = {read = get_TableID_CUST_MAINMENU , write = set_TableID_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_TableID_CUST_MAINMENU(void)=0;
   virtual void set_TableID_CUST_MAINMENU(TFIBLargeIntField * TableID_CUST_MAINMENU)=0;

   __property TFIBLargeIntField * TableIDBASE_CUST_MAINMENU = {read = get_TableIDBASE_CUST_MAINMENU , write = set_TableIDBASE_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_TableIDBASE_CUST_MAINMENU(void)=0;
   virtual void set_TableIDBASE_CUST_MAINMENU(TFIBLargeIntField * TableIDBASE_CUST_MAINMENU)=0;

   __property TFIBWideStringField * TableGID_CUST_MAINMENU = {read = get_TableGID_CUST_MAINMENU , write = set_TableGID_CUST_MAINMENU};
   virtual TFIBWideStringField * get_TableGID_CUST_MAINMENU(void)=0;
   virtual void set_TableGID_CUST_MAINMENU(TFIBWideStringField * TableGID_CUST_MAINMENU)=0;

   __property TFIBLargeIntField * TableIDACCOUNT_CUST_MAINMENU = {read = get_TableIDACCOUNT_CUST_MAINMENU , write = set_TableIDACCOUNT_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_TableIDACCOUNT_CUST_MAINMENU(void)=0;
   virtual void set_TableIDACCOUNT_CUST_MAINMENU(TFIBLargeIntField * TableIDACCOUNT_CUST_MAINMENU)=0;

   __property TFIBLargeIntField * TableIDGRPUSER_CUST_MAINMENU = {read = get_TableIDGRPUSER_CUST_MAINMENU , write = set_TableIDGRPUSER_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_TableIDGRPUSER_CUST_MAINMENU(void)=0;
   virtual void set_TableIDGRPUSER_CUST_MAINMENU(TFIBLargeIntField * TableIDGRPUSER_CUST_MAINMENU)=0;

   __property TFIBLargeIntField * TableIDGRP_CUST_MAINMENU = {read = get_TableIDGRP_CUST_MAINMENU , write = set_TableIDGRP_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_TableIDGRP_CUST_MAINMENU(void)=0;
   virtual void set_TableIDGRP_CUST_MAINMENU(TFIBLargeIntField * TableIDGRP_CUST_MAINMENU)=0;

   __property TFIBWideStringField * TableNAME_CUST_MAINMENU = {read = get_TableNAME_CUST_MAINMENU , write = set_TableNAME_CUST_MAINMENU};
   virtual TFIBWideStringField * get_TableNAME_CUST_MAINMENU(void)=0;
   virtual void set_TableNAME_CUST_MAINMENU(TFIBWideStringField * TableNAME_CUST_MAINMENU)=0;

   __property TFIBIntegerField * TableINDEX_CUST_MAINMENU = {read = get_TableINDEX_CUST_MAINMENU , write = set_TableINDEX_CUST_MAINMENU};
   virtual TFIBIntegerField * get_TableINDEX_CUST_MAINMENU(void)=0;
   virtual void set_TableINDEX_CUST_MAINMENU(TFIBIntegerField * TableINDEX_CUST_MAINMENU)=0;

   __property TFIBWideStringField * TableGUID_CUST_MAINMENU = {read = get_TableGUID_CUST_MAINMENU , write = set_TableGUID_CUST_MAINMENU};
   virtual TFIBWideStringField * get_TableGUID_CUST_MAINMENU(void)=0;
   virtual void set_TableGUID_CUST_MAINMENU(TFIBWideStringField * TableGUID_CUST_MAINMENU)=0;

   __property TFIBWideStringField * TableGUIDMOD_CUST_MAINMENU = {read = get_TableGUIDMOD_CUST_MAINMENU , write = set_TableGUIDMOD_CUST_MAINMENU};
   virtual TFIBWideStringField * get_TableGUIDMOD_CUST_MAINMENU(void)=0;
   virtual void set_TableGUIDMOD_CUST_MAINMENU(TFIBWideStringField * TableGUIDMOD_CUST_MAINMENU)=0;

   __property TFIBLargeIntField * TableIDMOD_CUST_MAINMENU = {read = get_TableIDMOD_CUST_MAINMENU , write = set_TableIDMOD_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_TableIDMOD_CUST_MAINMENU(void)=0;
   virtual void set_TableIDMOD_CUST_MAINMENU(TFIBLargeIntField * TableIDMOD_CUST_MAINMENU)=0;

   __property TFIBSmallIntField * TableFL_OPEN_EL_CUST_MAINMENU = {read = get_TableFL_OPEN_EL_CUST_MAINMENU , write = set_TableFL_OPEN_EL_CUST_MAINMENU};
   virtual TFIBSmallIntField * get_TableFL_OPEN_EL_CUST_MAINMENU(void)=0;
   virtual void set_TableFL_OPEN_EL_CUST_MAINMENU(TFIBSmallIntField * TableFL_OPEN_EL_CUST_MAINMENU)=0;

   __property TFIBLargeIntField * TableIDEL_CUST_MAINMENU = {read = get_TableIDEL_CUST_MAINMENU , write = set_TableIDEL_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_TableIDEL_CUST_MAINMENU(void)=0;
   virtual void set_TableIDEL_CUST_MAINMENU(TFIBLargeIntField * TableIDEL_CUST_MAINMENU)=0;

   __property TFIBWideStringField * TableNAME_PROGRAM_MODULE = {read = get_TableNAME_PROGRAM_MODULE , write = set_TableNAME_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void)=0;
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TablePROGID_PROGRAM_MODULE = {read = get_TablePROGID_PROGRAM_MODULE , write = set_TablePROGID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TablePROGID_PROGRAM_MODULE(void)=0;
   virtual void set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TablePATCH_PROGRAM_MODULE = {read = get_TablePATCH_PROGRAM_MODULE , write = set_TablePATCH_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void)=0;
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)=0;

   __property TFIBIntegerField * TableTYPEMOD_PROGRAM_MODULE = {read = get_TableTYPEMOD_PROGRAM_MODULE , write = set_TableTYPEMOD_PROGRAM_MODULE};
   virtual TFIBIntegerField * get_TableTYPEMOD_PROGRAM_MODULE(void)=0;
   virtual void set_TableTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * TableTYPEMOD_PROGRAM_MODULE)=0;

   __property TFIBLargeIntField * ElementID_CUST_MAINMENU = {read = get_ElementID_CUST_MAINMENU , write = set_ElementID_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_ElementID_CUST_MAINMENU(void)=0;
   virtual void set_ElementID_CUST_MAINMENU(TFIBLargeIntField * ElementID_CUST_MAINMENU)=0;

   __property TFIBLargeIntField * ElementIDBASE_CUST_MAINMENU = {read = get_ElementIDBASE_CUST_MAINMENU , write = set_ElementIDBASE_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_ElementIDBASE_CUST_MAINMENU(void)=0;
   virtual void set_ElementIDBASE_CUST_MAINMENU(TFIBLargeIntField * ElementIDBASE_CUST_MAINMENU)=0;

   __property TFIBWideStringField * ElementGID_CUST_MAINMENU = {read = get_ElementGID_CUST_MAINMENU , write = set_ElementGID_CUST_MAINMENU};
   virtual TFIBWideStringField * get_ElementGID_CUST_MAINMENU(void)=0;
   virtual void set_ElementGID_CUST_MAINMENU(TFIBWideStringField * ElementGID_CUST_MAINMENU)=0;

   __property TFIBLargeIntField * ElementIDACCOUNT_CUST_MAINMENU = {read = get_ElementIDACCOUNT_CUST_MAINMENU , write = set_ElementIDACCOUNT_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_ElementIDACCOUNT_CUST_MAINMENU(void)=0;
   virtual void set_ElementIDACCOUNT_CUST_MAINMENU(TFIBLargeIntField * ElementIDACCOUNT_CUST_MAINMENU)=0;

   __property TFIBLargeIntField * ElementIDGRPUSER_CUST_MAINMENU = {read = get_ElementIDGRPUSER_CUST_MAINMENU , write = set_ElementIDGRPUSER_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_ElementIDGRPUSER_CUST_MAINMENU(void)=0;
   virtual void set_ElementIDGRPUSER_CUST_MAINMENU(TFIBLargeIntField * ElementIDGRPUSER_CUST_MAINMENU)=0;

   __property TFIBLargeIntField * ElementIDGRP_CUST_MAINMENU = {read = get_ElementIDGRP_CUST_MAINMENU , write = set_ElementIDGRP_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_ElementIDGRP_CUST_MAINMENU(void)=0;
   virtual void set_ElementIDGRP_CUST_MAINMENU(TFIBLargeIntField * ElementIDGRP_CUST_MAINMENU)=0;

   __property TFIBWideStringField * ElementNAME_CUST_MAINMENU = {read = get_ElementNAME_CUST_MAINMENU , write = set_ElementNAME_CUST_MAINMENU};
   virtual TFIBWideStringField * get_ElementNAME_CUST_MAINMENU(void)=0;
   virtual void set_ElementNAME_CUST_MAINMENU(TFIBWideStringField * ElementNAME_CUST_MAINMENU)=0;

   __property TFIBIntegerField * ElementINDEX_CUST_MAINMENU = {read = get_ElementINDEX_CUST_MAINMENU , write = set_ElementINDEX_CUST_MAINMENU};
   virtual TFIBIntegerField * get_ElementINDEX_CUST_MAINMENU(void)=0;
   virtual void set_ElementINDEX_CUST_MAINMENU(TFIBIntegerField * ElementINDEX_CUST_MAINMENU)=0;

   __property TFIBWideStringField * ElementGUID_CUST_MAINMENU = {read = get_ElementGUID_CUST_MAINMENU , write = set_ElementGUID_CUST_MAINMENU};
   virtual TFIBWideStringField * get_ElementGUID_CUST_MAINMENU(void)=0;
   virtual void set_ElementGUID_CUST_MAINMENU(TFIBWideStringField * ElementGUID_CUST_MAINMENU)=0;

   __property TFIBWideStringField * ElementGUIDMOD_CUST_MAINMENU = {read = get_ElementGUIDMOD_CUST_MAINMENU , write = set_ElementGUIDMOD_CUST_MAINMENU};
   virtual TFIBWideStringField * get_ElementGUIDMOD_CUST_MAINMENU(void)=0;
   virtual void set_ElementGUIDMOD_CUST_MAINMENU(TFIBWideStringField * ElementGUIDMOD_CUST_MAINMENU)=0;

   __property TFIBLargeIntField * ElementIDMOD_CUST_MAINMENU = {read = get_ElementIDMOD_CUST_MAINMENU , write = set_ElementIDMOD_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_ElementIDMOD_CUST_MAINMENU(void)=0;
   virtual void set_ElementIDMOD_CUST_MAINMENU(TFIBLargeIntField * ElementIDMOD_CUST_MAINMENU)=0;

   __property TFIBSmallIntField * ElementFL_OPEN_EL_CUST_MAINMENU = {read = get_ElementFL_OPEN_EL_CUST_MAINMENU , write = set_ElementFL_OPEN_EL_CUST_MAINMENU};
   virtual TFIBSmallIntField * get_ElementFL_OPEN_EL_CUST_MAINMENU(void)=0;
   virtual void set_ElementFL_OPEN_EL_CUST_MAINMENU(TFIBSmallIntField * ElementFL_OPEN_EL_CUST_MAINMENU)=0;

   __property TFIBLargeIntField * ElementIDEL_CUST_MAINMENU = {read = get_ElementIDEL_CUST_MAINMENU , write = set_ElementIDEL_CUST_MAINMENU};
   virtual TFIBLargeIntField * get_ElementIDEL_CUST_MAINMENU(void)=0;
   virtual void set_ElementIDEL_CUST_MAINMENU(TFIBLargeIntField * ElementIDEL_CUST_MAINMENU)=0;

   __property TFIBWideStringField * ElementNAME_PROGRAM_MODULE = {read = get_ElementNAME_PROGRAM_MODULE , write = set_ElementNAME_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void)=0;
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementPROGID_PROGRAM_MODULE = {read = get_ElementPROGID_PROGRAM_MODULE , write = set_ElementPROGID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementPROGID_PROGRAM_MODULE(void)=0;
   virtual void set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementPATCH_PROGRAM_MODULE = {read = get_ElementPATCH_PROGRAM_MODULE , write = set_ElementPATCH_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void)=0;
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)=0;

   __property __int64 IdAccount = {read = get_IdAccount , write = set_IdAccount};
   virtual __int64 get_IdAccount(void)=0;
   virtual void set_IdAccount(__int64 IdAccount)=0;

   __property __int64 IdGrpUser = {read = get_IdGrpUser , write = set_IdGrpUser};
   virtual __int64 get_IdGrpUser(void)=0;
   virtual void set_IdGrpUser(__int64 IdGrpUser)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void OpenTable(__int64 id_account, __int64 id_grp_user, __int64 id_grp, bool all)=0;
   virtual bool SaveIsmen()=0;
   virtual void CancelIsmen()=0;
   virtual bool Table_Delete(void)=0;
   virtual bool Table_AppendString(__int64 id_account, __int64 id_grp_user, __int64 id_grp)=0;
   virtual bool NewElement(__int64 id_account, __int64 id_grp_user, __int64 id_grp)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool InsertElement(__int64 id_account, __int64 id_grp_user, __int64 id_grp)=0;
   virtual void Element_Edit(void)=0;
   virtual void Element_Post(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void ChancheGrp(__int64 id_new_grp)=0;
};
#define IID_IDMSprCustomerMainMenu __uuidof(IDMSprCustomerMainMenu)
#endif
