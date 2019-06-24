#ifndef UDMInterfMainMenuImplH
#define UDMInterfMainMenuImplH
#include "IDMInterfMainMenu.h"
#include "UDMInterfMainMenu.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMInterfMainMenuImpl)) TDMInterfMainMenuImpl : public IDMInterfMainMenu
{
public:
   TDMInterfMainMenuImpl();
   ~TDMInterfMainMenuImpl();
   TDMInterfMainMenu * Object;
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

//IDMInterfMainMenu
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

   virtual TFIBLargeIntField * get_TableID_INTERF_MAINMENU(void);
   virtual void set_TableID_INTERF_MAINMENU(TFIBLargeIntField * TableID_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_TableIDBASE_INTERF_MAINMENU(void);
   virtual void set_TableIDBASE_INTERF_MAINMENU(TFIBLargeIntField * TableIDBASE_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_TableIDGRP_INTERF_MAINMENU(void);
   virtual void set_TableIDGRP_INTERF_MAINMENU(TFIBLargeIntField * TableIDGRP_INTERF_MAINMENU);

   virtual TFIBWideStringField * get_TableNAME_INTERF_MAINMENU(void);
   virtual void set_TableNAME_INTERF_MAINMENU(TFIBWideStringField * TableNAME_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_TableMODUL_INTERF_MAINMENU(void);
   virtual void set_TableMODUL_INTERF_MAINMENU(TFIBIntegerField * TableMODUL_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_TableIDGRPUSER_INTERF_MAINMENU(void);
   virtual void set_TableIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * TableIDGRPUSER_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_TableAPPLICATION_INTERF_MAINMENU(void);
   virtual void set_TableAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * TableAPPLICATION_INTERF_MAINMENU);

   virtual TFIBWideStringField * get_TableSHORTCUT_INTERF_MAINMENU(void);
   virtual void set_TableSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * TableSHORTCUT_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_TableINDEX_INTERF_MAINMENU(void);
   virtual void set_TableINDEX_INTERF_MAINMENU(TFIBIntegerField * TableINDEX_INTERF_MAINMENU);

   virtual TFIBWideStringField * get_TableNAME_SGRPUSER(void);
   virtual void set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER);

   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void);
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePROGID_PROGRAM_MODULE(void);
   virtual void set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void);
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_ElementID_INTERF_MAINMENU(void);
   virtual void set_ElementID_INTERF_MAINMENU(TFIBLargeIntField * ElementID_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_ElementIDBASE_INTERF_MAINMENU(void);
   virtual void set_ElementIDBASE_INTERF_MAINMENU(TFIBLargeIntField * ElementIDBASE_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_ElementIDGRP_INTERF_MAINMENU(void);
   virtual void set_ElementIDGRP_INTERF_MAINMENU(TFIBLargeIntField * ElementIDGRP_INTERF_MAINMENU);

   virtual TFIBWideStringField * get_ElementNAME_INTERF_MAINMENU(void);
   virtual void set_ElementNAME_INTERF_MAINMENU(TFIBWideStringField * ElementNAME_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_ElementMODUL_INTERF_MAINMENU(void);
   virtual void set_ElementMODUL_INTERF_MAINMENU(TFIBIntegerField * ElementMODUL_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_ElementIDGRPUSER_INTERF_MAINMENU(void);
   virtual void set_ElementIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * ElementIDGRPUSER_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_ElementAPPLICATION_INTERF_MAINMENU(void);
   virtual void set_ElementAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * ElementAPPLICATION_INTERF_MAINMENU);

   virtual TFIBWideStringField * get_ElementSHORTCUT_INTERF_MAINMENU(void);
   virtual void set_ElementSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * ElementSHORTCUT_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_ElementINDEX_INTERF_MAINMENU(void);
   virtual void set_ElementINDEX_INTERF_MAINMENU(TFIBIntegerField * ElementINDEX_INTERF_MAINMENU);

   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void);
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPROGID_PROGRAM_MODULE(void);
   virtual void set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void);
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE);

   virtual TFIBSmallIntField * get_TableFL_UPD_FORM_INTERF_MAINMENU(void);
   virtual void set_TableFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * TableFL_UPD_FORM_INTERF_MAINMENU);

   virtual TFIBSmallIntField * get_TableFL_NEW_DOC_INTERF_MAINMENU(void);
   virtual void set_TableFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * TableFL_NEW_DOC_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_TableIDEL_INTERF_MAINMENU(void);
   virtual void set_TableIDEL_INTERF_MAINMENU(TFIBLargeIntField * TableIDEL_INTERF_MAINMENU);

   virtual TFIBSmallIntField * get_TableFL_OPEN_EL_INTERF_MAINMENU(void);
   virtual void set_TableFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * TableFL_OPEN_EL_INTERF_MAINMENU);

   virtual TFIBSmallIntField * get_ElementFL_UPD_FORM_INTERF_MAINMENU(void);
   virtual void set_ElementFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_UPD_FORM_INTERF_MAINMENU);

   virtual TFIBSmallIntField * get_ElementFL_NEW_DOC_INTERF_MAINMENU(void);
   virtual void set_ElementFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_NEW_DOC_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_ElementIDEL_INTERF_MAINMENU(void);
   virtual void set_ElementIDEL_INTERF_MAINMENU(TFIBLargeIntField * ElementIDEL_INTERF_MAINMENU);

   virtual TFIBSmallIntField * get_ElementFL_OPEN_EL_INTERF_MAINMENU(void);
   virtual void set_ElementFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_OPEN_EL_INTERF_MAINMENU);

   virtual TFIBWideStringField * get_TableGUIDMOD_INTERF_MAINMENU(void);
   virtual void set_TableGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * TableGUIDMOD_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_TableTYPE_IDEL_INTERF_MAINMENU(void);
   virtual void set_TableTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * TableTYPE_IDEL_INTERF_MAINMENU);

   virtual TFIBWideStringField * get_ElementGUIDMOD_INTERF_MAINMENU(void);
   virtual void set_ElementGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * ElementGUIDMOD_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_ElementTYPE_IDEL_INTERF_MAINMENU(void);
   virtual void set_ElementTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * ElementTYPE_IDEL_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_TableIDMOD_INTERF_MAINMENU(void);
   virtual void set_TableIDMOD_INTERF_MAINMENU(TFIBLargeIntField * TableIDMOD_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_TableTYPEMOD_PROGRAM_MODULE(void);
   virtual void set_TableTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * TableTYPEMOD_PROGRAM_MODULE);

   virtual TFIBLargeIntField * get_ElementIDMOD_INTERF_MAINMENU(void);
   virtual void set_ElementIDMOD_INTERF_MAINMENU(TFIBLargeIntField * ElementIDMOD_INTERF_MAINMENU);

   virtual int get_NumApplication(void);
   virtual void set_NumApplication(int NumApplication);

   virtual __int64 get_IdGrpUser(void);
   virtual void set_IdGrpUser(__int64 IdGrpUser);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual void OpenTable(int num_application, __int64 id_grp_user, __int64 id_grp, bool all);
   virtual bool SaveIsmen();
   virtual void CancelIsmen();
   virtual bool Table_Delete(void);
   virtual bool Table_AppendString(int num_application, __int64 id_grp_user, __int64 id_grp);
   virtual bool NewElement(int num_application, __int64 id_grp_user, __int64 id_grp);
   virtual bool OpenElement(__int64 id);
   virtual bool DeleteElement(__int64 id);
   virtual bool InsertElement(int num_application, __int64 id_grp_user, __int64 id_grp);
   virtual void Element_Edit(void);
   virtual void Element_Post(void);
   virtual bool SaveElement(void);
   virtual void ChancheGrp(__int64 id_new_grp);
};
#define CLSID_TDMInterfMainMenuImpl __uuidof(TDMInterfMainMenuImpl)
#endif
