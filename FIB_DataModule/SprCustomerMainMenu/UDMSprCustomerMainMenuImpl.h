#ifndef UDMSprCustomerMainMenuImplH
#define UDMSprCustomerMainMenuImplH
#include "IDMSprCustomerMainMenu.h"
#include "UDMSprCustomerMainMenu.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprCustomerMainMenuImpl)) TDMSprCustomerMainMenuImpl : public IDMSprCustomerMainMenu
{
public:
   TDMSprCustomerMainMenuImpl();
   ~TDMSprCustomerMainMenuImpl();
   TDMSprCustomerMainMenu * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IDMSprCustomerMainMenu
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TFIBLargeIntField * get_TableID_CUST_MAINMENU(void);
   virtual void set_TableID_CUST_MAINMENU(TFIBLargeIntField * TableID_CUST_MAINMENU);

   virtual TFIBLargeIntField * get_TableIDBASE_CUST_MAINMENU(void);
   virtual void set_TableIDBASE_CUST_MAINMENU(TFIBLargeIntField * TableIDBASE_CUST_MAINMENU);

   virtual TFIBWideStringField * get_TableGID_CUST_MAINMENU(void);
   virtual void set_TableGID_CUST_MAINMENU(TFIBWideStringField * TableGID_CUST_MAINMENU);

   virtual TFIBLargeIntField * get_TableIDACCOUNT_CUST_MAINMENU(void);
   virtual void set_TableIDACCOUNT_CUST_MAINMENU(TFIBLargeIntField * TableIDACCOUNT_CUST_MAINMENU);

   virtual TFIBLargeIntField * get_TableIDGRPUSER_CUST_MAINMENU(void);
   virtual void set_TableIDGRPUSER_CUST_MAINMENU(TFIBLargeIntField * TableIDGRPUSER_CUST_MAINMENU);

   virtual TFIBLargeIntField * get_TableIDGRP_CUST_MAINMENU(void);
   virtual void set_TableIDGRP_CUST_MAINMENU(TFIBLargeIntField * TableIDGRP_CUST_MAINMENU);

   virtual TFIBWideStringField * get_TableNAME_CUST_MAINMENU(void);
   virtual void set_TableNAME_CUST_MAINMENU(TFIBWideStringField * TableNAME_CUST_MAINMENU);

   virtual TFIBIntegerField * get_TableINDEX_CUST_MAINMENU(void);
   virtual void set_TableINDEX_CUST_MAINMENU(TFIBIntegerField * TableINDEX_CUST_MAINMENU);

   virtual TFIBWideStringField * get_TableGUID_CUST_MAINMENU(void);
   virtual void set_TableGUID_CUST_MAINMENU(TFIBWideStringField * TableGUID_CUST_MAINMENU);

   virtual TFIBWideStringField * get_TableGUIDMOD_CUST_MAINMENU(void);
   virtual void set_TableGUIDMOD_CUST_MAINMENU(TFIBWideStringField * TableGUIDMOD_CUST_MAINMENU);

   virtual TFIBLargeIntField * get_TableIDMOD_CUST_MAINMENU(void);
   virtual void set_TableIDMOD_CUST_MAINMENU(TFIBLargeIntField * TableIDMOD_CUST_MAINMENU);

   virtual TFIBSmallIntField * get_TableFL_OPEN_EL_CUST_MAINMENU(void);
   virtual void set_TableFL_OPEN_EL_CUST_MAINMENU(TFIBSmallIntField * TableFL_OPEN_EL_CUST_MAINMENU);

   virtual TFIBLargeIntField * get_TableIDEL_CUST_MAINMENU(void);
   virtual void set_TableIDEL_CUST_MAINMENU(TFIBLargeIntField * TableIDEL_CUST_MAINMENU);

   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void);
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePROGID_PROGRAM_MODULE(void);
   virtual void set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void);
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE);

   virtual TFIBIntegerField * get_TableTYPEMOD_PROGRAM_MODULE(void);
   virtual void set_TableTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * TableTYPEMOD_PROGRAM_MODULE);

   virtual TFIBLargeIntField * get_ElementID_CUST_MAINMENU(void);
   virtual void set_ElementID_CUST_MAINMENU(TFIBLargeIntField * ElementID_CUST_MAINMENU);

   virtual TFIBLargeIntField * get_ElementIDBASE_CUST_MAINMENU(void);
   virtual void set_ElementIDBASE_CUST_MAINMENU(TFIBLargeIntField * ElementIDBASE_CUST_MAINMENU);

   virtual TFIBWideStringField * get_ElementGID_CUST_MAINMENU(void);
   virtual void set_ElementGID_CUST_MAINMENU(TFIBWideStringField * ElementGID_CUST_MAINMENU);

   virtual TFIBLargeIntField * get_ElementIDACCOUNT_CUST_MAINMENU(void);
   virtual void set_ElementIDACCOUNT_CUST_MAINMENU(TFIBLargeIntField * ElementIDACCOUNT_CUST_MAINMENU);

   virtual TFIBLargeIntField * get_ElementIDGRPUSER_CUST_MAINMENU(void);
   virtual void set_ElementIDGRPUSER_CUST_MAINMENU(TFIBLargeIntField * ElementIDGRPUSER_CUST_MAINMENU);

   virtual TFIBLargeIntField * get_ElementIDGRP_CUST_MAINMENU(void);
   virtual void set_ElementIDGRP_CUST_MAINMENU(TFIBLargeIntField * ElementIDGRP_CUST_MAINMENU);

   virtual TFIBWideStringField * get_ElementNAME_CUST_MAINMENU(void);
   virtual void set_ElementNAME_CUST_MAINMENU(TFIBWideStringField * ElementNAME_CUST_MAINMENU);

   virtual TFIBIntegerField * get_ElementINDEX_CUST_MAINMENU(void);
   virtual void set_ElementINDEX_CUST_MAINMENU(TFIBIntegerField * ElementINDEX_CUST_MAINMENU);

   virtual TFIBWideStringField * get_ElementGUID_CUST_MAINMENU(void);
   virtual void set_ElementGUID_CUST_MAINMENU(TFIBWideStringField * ElementGUID_CUST_MAINMENU);

   virtual TFIBWideStringField * get_ElementGUIDMOD_CUST_MAINMENU(void);
   virtual void set_ElementGUIDMOD_CUST_MAINMENU(TFIBWideStringField * ElementGUIDMOD_CUST_MAINMENU);

   virtual TFIBLargeIntField * get_ElementIDMOD_CUST_MAINMENU(void);
   virtual void set_ElementIDMOD_CUST_MAINMENU(TFIBLargeIntField * ElementIDMOD_CUST_MAINMENU);

   virtual TFIBSmallIntField * get_ElementFL_OPEN_EL_CUST_MAINMENU(void);
   virtual void set_ElementFL_OPEN_EL_CUST_MAINMENU(TFIBSmallIntField * ElementFL_OPEN_EL_CUST_MAINMENU);

   virtual TFIBLargeIntField * get_ElementIDEL_CUST_MAINMENU(void);
   virtual void set_ElementIDEL_CUST_MAINMENU(TFIBLargeIntField * ElementIDEL_CUST_MAINMENU);

   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void);
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPROGID_PROGRAM_MODULE(void);
   virtual void set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void);
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE);

   virtual __int64 get_IdAccount(void);
   virtual void set_IdAccount(__int64 IdAccount);

   virtual __int64 get_IdGrpUser(void);
   virtual void set_IdGrpUser(__int64 IdGrpUser);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual void OpenTable(__int64 id_account, __int64 id_grp_user, __int64 id_grp, bool all);
   virtual bool SaveIsmen();
   virtual void CancelIsmen();
   virtual bool Table_Delete(void);
   virtual bool Table_AppendString(__int64 id_account, __int64 id_grp_user, __int64 id_grp);
   virtual bool NewElement(__int64 id_account, __int64 id_grp_user, __int64 id_grp);
   virtual bool OpenElement(__int64 id);
   virtual bool DeleteElement(__int64 id);
   virtual bool InsertElement(__int64 id_account, __int64 id_grp_user, __int64 id_grp);
   virtual void Element_Edit(void);
   virtual void Element_Post(void);
   virtual bool SaveElement(void);
   virtual void ChancheGrp(__int64 id_new_grp);
};
#define CLSID_TDMSprCustomerMainMenuImpl __uuidof(TDMSprCustomerMainMenuImpl)
#endif
