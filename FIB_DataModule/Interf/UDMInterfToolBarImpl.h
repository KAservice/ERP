#ifndef UDMInterfToolBarImplH
#define UDMInterfToolBarImplH
#include "IDMInterfToolBar.h"
#include "UDMInterfToolBar.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMInterfToolBarImpl)) TDMInterfToolBarImpl : public IDMInterfToolBar
{
public:
   TDMInterfToolBarImpl();
   ~TDMInterfToolBarImpl();
   TDMInterfToolBar * Object;
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

//IDMInterfToolBar
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

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_TableID_INTERF_TOOLBAR(void);
   virtual void set_TableID_INTERF_TOOLBAR(TFIBLargeIntField * TableID_INTERF_TOOLBAR);

   virtual TFIBLargeIntField * get_TableIDBASE_INTERF_TOOLBAR(void);
   virtual void set_TableIDBASE_INTERF_TOOLBAR(TFIBLargeIntField * TableIDBASE_INTERF_TOOLBAR);

   virtual TFIBWideStringField * get_TableNAME_INTERF_TOOLBAR(void);
   virtual void set_TableNAME_INTERF_TOOLBAR(TFIBWideStringField * TableNAME_INTERF_TOOLBAR);

   virtual TFIBLargeIntField * get_TableIDGRPUSER_INTERF_TOOLBAR(void);
   virtual void set_TableIDGRPUSER_INTERF_TOOLBAR(TFIBLargeIntField * TableIDGRPUSER_INTERF_TOOLBAR);

   virtual TFIBIntegerField * get_TableAPPLICATION_INTERF_TOOLBAR(void);
   virtual void set_TableAPPLICATION_INTERF_TOOLBAR(TFIBIntegerField * TableAPPLICATION_INTERF_TOOLBAR);

   virtual TFIBIntegerField * get_TableMODUL_INTERF_TOOLBAR(void);
   virtual void set_TableMODUL_INTERF_TOOLBAR(TFIBIntegerField * TableMODUL_INTERF_TOOLBAR);

   virtual TFIBWideStringField * get_TableHINT_INTERF_TOOLBAR(void);
   virtual void set_TableHINT_INTERF_TOOLBAR(TFIBWideStringField * TableHINT_INTERF_TOOLBAR);

   virtual TFIBIntegerField * get_TableIMAGEINDEX_INTERF_TOOLBAR(void);
   virtual void set_TableIMAGEINDEX_INTERF_TOOLBAR(TFIBIntegerField * TableIMAGEINDEX_INTERF_TOOLBAR);

   virtual TFIBIntegerField * get_TableINDEX_INTERF_TOOLBAR(void);
   virtual void set_TableINDEX_INTERF_TOOLBAR(TFIBIntegerField * TableINDEX_INTERF_TOOLBAR);

   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void);
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePROGID_PROGRAM_MODULE(void);
   virtual void set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void);
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE);

   virtual TFIBLargeIntField * get_ElementID_INTERF_TOOLBAR(void);
   virtual void set_ElementID_INTERF_TOOLBAR(TFIBLargeIntField * ElementID_INTERF_TOOLBAR);

   virtual TFIBLargeIntField * get_ElementIDBASE_INTERF_TOOLBAR(void);
   virtual void set_ElementIDBASE_INTERF_TOOLBAR(TFIBLargeIntField * ElementIDBASE_INTERF_TOOLBAR);

   virtual TFIBWideStringField * get_ElementNAME_INTERF_TOOLBAR(void);
   virtual void set_ElementNAME_INTERF_TOOLBAR(TFIBWideStringField * ElementNAME_INTERF_TOOLBAR);

   virtual TFIBLargeIntField * get_ElementIDGRPUSER_INTERF_TOOLBAR(void);
   virtual void set_ElementIDGRPUSER_INTERF_TOOLBAR(TFIBLargeIntField * ElementIDGRPUSER_INTERF_TOOLBAR);

   virtual TFIBIntegerField * get_ElementAPPLICATION_INTERF_TOOLBAR(void);
   virtual void set_ElementAPPLICATION_INTERF_TOOLBAR(TFIBIntegerField * ElementAPPLICATION_INTERF_TOOLBAR);

   virtual TFIBIntegerField * get_ElementMODUL_INTERF_TOOLBAR(void);
   virtual void set_ElementMODUL_INTERF_TOOLBAR(TFIBIntegerField * ElementMODUL_INTERF_TOOLBAR);

   virtual TFIBWideStringField * get_ElementHINT_INTERF_TOOLBAR(void);
   virtual void set_ElementHINT_INTERF_TOOLBAR(TFIBWideStringField * ElementHINT_INTERF_TOOLBAR);

   virtual TFIBIntegerField * get_ElementIMAGEINDEX_INTERF_TOOLBAR(void);
   virtual void set_ElementIMAGEINDEX_INTERF_TOOLBAR(TFIBIntegerField * ElementIMAGEINDEX_INTERF_TOOLBAR);

   virtual TFIBIntegerField * get_ElementINDEX_INTERF_TOOLBAR(void);
   virtual void set_ElementINDEX_INTERF_TOOLBAR(TFIBIntegerField * ElementINDEX_INTERF_TOOLBAR);

   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void);
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPROGID_PROGRAM_MODULE(void);
   virtual void set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void);
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementGUIDMOD_INTERF_TOOLBAR(void);
   virtual void set_ElementGUIDMOD_INTERF_TOOLBAR(TFIBWideStringField * ElementGUIDMOD_INTERF_TOOLBAR);

   virtual TFIBWideStringField * get_TableGUIDMOD_INTERF_TOOLBAR(void);
   virtual void set_TableGUIDMOD_INTERF_TOOLBAR(TFIBWideStringField * TableGUIDMOD_INTERF_TOOLBAR);

   virtual TFIBLargeIntField * get_TableIDMOD_INTERF_TOOLBAR(void);
   virtual void set_TableIDMOD_INTERF_TOOLBAR(TFIBLargeIntField * TableIDMOD_INTERF_TOOLBAR);

   virtual TFIBSmallIntField * get_TableFL_UPD_FORM_INTERF_TOOLBAR(void);
   virtual void set_TableFL_UPD_FORM_INTERF_TOOLBAR(TFIBSmallIntField * TableFL_UPD_FORM_INTERF_TOOLBAR);

   virtual TFIBLargeIntField * get_TableIDEL_INTERF_TOOLBAR(void);
   virtual void set_TableIDEL_INTERF_TOOLBAR(TFIBLargeIntField * TableIDEL_INTERF_TOOLBAR);

   virtual TFIBSmallIntField * get_TableFL_OPEN_EL_INTERF_TOOLBAR(void);
   virtual void set_TableFL_OPEN_EL_INTERF_TOOLBAR(TFIBSmallIntField * TableFL_OPEN_EL_INTERF_TOOLBAR);

   virtual TFIBIntegerField * get_TableTYPE_IDEL_INTERF_TOOLBAR(void);
   virtual void set_TableTYPE_IDEL_INTERF_TOOLBAR(TFIBIntegerField * TableTYPE_IDEL_INTERF_TOOLBAR);

   virtual TFIBLargeIntField * get_ElementIDMOD_INTERF_TOOLBAR(void);
   virtual void set_ElementIDMOD_INTERF_TOOLBAR(TFIBLargeIntField * ElementIDMOD_INTERF_TOOLBAR);

   virtual TFIBSmallIntField * get_ElementFL_UPD_FORM_INTERF_TOOLBAR(void);
   virtual void set_ElementFL_UPD_FORM_INTERF_TOOLBAR(TFIBSmallIntField * ElementFL_UPD_FORM_INTERF_TOOLBAR);

   virtual TFIBLargeIntField * get_ElementIDEL_INTERF_TOOLBAR(void);
   virtual void set_ElementIDEL_INTERF_TOOLBAR(TFIBLargeIntField * ElementIDEL_INTERF_TOOLBAR);

   virtual TFIBSmallIntField * get_ElementFL_OPEN_EL_INTERF_TOOLBAR(void);
   virtual void set_ElementFL_OPEN_EL_INTERF_TOOLBAR(TFIBSmallIntField * ElementFL_OPEN_EL_INTERF_TOOLBAR);

   virtual TFIBIntegerField * get_ElementTYPE_IDEL_INTERF_TOOLBAR(void);
   virtual void set_ElementTYPE_IDEL_INTERF_TOOLBAR(TFIBIntegerField * ElementTYPE_IDEL_INTERF_TOOLBAR);

   virtual TFIBIntegerField * get_ElementTYPEMOD_PROGRAM_MODULE(void);
   virtual void set_ElementTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * ElementTYPEMOD_PROGRAM_MODULE);

   virtual int get_NumApplication(void);
   virtual void set_NumApplication(int NumApplication);

   virtual __int64 get_IdGrpUser(void);
   virtual void set_IdGrpUser(__int64 IdGrpUser);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual void OpenTable(int num_application, __int64 id_grp_user);
   virtual bool SaveIsmen();
   virtual void CancelIsmen();
   virtual bool Table_Delete(void);
   virtual bool Table_AppendString(int num_application, __int64 id_grp_user);
   virtual bool NewElement(int num_application, __int64 id_grp_user);
   virtual bool OpenElement(__int64 id);
   virtual bool DeleteElement(__int64 id);
   virtual bool InsertElement(int num_application, __int64 id_grp_user);
   virtual void Element_Edit(void);
   virtual void Element_Post(void);
   virtual bool SaveElement(void);
};
#define CLSID_TDMInterfToolBarImpl __uuidof(TDMInterfToolBarImpl)
#endif
