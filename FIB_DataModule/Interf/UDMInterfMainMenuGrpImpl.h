#ifndef UDMInterfMainMenuGrpImplH
#define UDMInterfMainMenuGrpImplH
#include "IDMInterfMainMenuGrp.h"
#include "UDMInterfMainMenuGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMInterfMainMenuGrpImpl)) TDMInterfMainMenuGrpImpl : public IDMInterfMainMenuGrp
{
public:
   TDMInterfMainMenuGrpImpl();
   ~TDMInterfMainMenuGrpImpl();
   TDMInterfMainMenuGrp * Object;
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

//IDMInterfMainMenuGrp
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_MenuTable(void);
   virtual void set_MenuTable(TpFIBDataSet * MenuTable);

   virtual TFIBLargeIntField * get_TableID_INTERF_MAINMENU_GRP(void);
   virtual void set_TableID_INTERF_MAINMENU_GRP(TFIBLargeIntField * TableID_INTERF_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_INTERF_MAINMENU_GRP(void);
   virtual void set_TableIDBASE_INTERF_MAINMENU_GRP(TFIBLargeIntField * TableIDBASE_INTERF_MAINMENU_GRP);

   virtual TFIBIntegerField * get_TableAPPLICATION_INTERF_MAINMENU_GRP(void);
   virtual void set_TableAPPLICATION_INTERF_MAINMENU_GRP(TFIBIntegerField * TableAPPLICATION_INTERF_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_TableIDGRPUSER_INTERF_MAINMENU_GRP(void);
   virtual void set_TableIDGRPUSER_INTERF_MAINMENU_GRP(TFIBLargeIntField * TableIDGRPUSER_INTERF_MAINMENU_GRP);

   virtual TFIBWideStringField * get_TableNAME_INTERF_MAINMENU_GRP(void);
   virtual void set_TableNAME_INTERF_MAINMENU_GRP(TFIBWideStringField * TableNAME_INTERF_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_INTERF_MAINMENU_GRP(void);
   virtual void set_TableIDGRP_INTERF_MAINMENU_GRP(TFIBLargeIntField * TableIDGRP_INTERF_MAINMENU_GRP);

   virtual TFIBIntegerField * get_TableINDEX_INTERF_MAINMENU_GRP(void);
   virtual void set_TableINDEX_INTERF_MAINMENU_GRP(TFIBIntegerField * TableINDEX_INTERF_MAINMENU_GRP);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_ElementID_INTERF_MAINMENU_GRP(void);
   virtual void set_ElementID_INTERF_MAINMENU_GRP(TFIBLargeIntField * ElementID_INTERF_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_INTERF_MAINMENU_GRP(void);
   virtual void set_ElementIDBASE_INTERF_MAINMENU_GRP(TFIBLargeIntField * ElementIDBASE_INTERF_MAINMENU_GRP);

   virtual TFIBIntegerField * get_ElementAPPLICATION_INTERF_MAINMENU_GRP(void);
   virtual void set_ElementAPPLICATION_INTERF_MAINMENU_GRP(TFIBIntegerField * ElementAPPLICATION_INTERF_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRPUSER_INTERF_MAINMENU_GRP(void);
   virtual void set_ElementIDGRPUSER_INTERF_MAINMENU_GRP(TFIBLargeIntField * ElementIDGRPUSER_INTERF_MAINMENU_GRP);

   virtual TFIBWideStringField * get_ElementNAME_INTERF_MAINMENU_GRP(void);
   virtual void set_ElementNAME_INTERF_MAINMENU_GRP(TFIBWideStringField * ElementNAME_INTERF_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_INTERF_MAINMENU_GRP(void);
   virtual void set_ElementIDGRP_INTERF_MAINMENU_GRP(TFIBLargeIntField * ElementIDGRP_INTERF_MAINMENU_GRP);

   virtual TFIBIntegerField * get_ElementINDEX_INTERF_MAINMENU_GRP(void);
   virtual void set_ElementINDEX_INTERF_MAINMENU_GRP(TFIBIntegerField * ElementINDEX_INTERF_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_MenuTableOUT_IDGRP_1(void);
   virtual void set_MenuTableOUT_IDGRP_1(TFIBLargeIntField * MenuTableOUT_IDGRP_1);

   virtual TFIBWideStringField * get_MenuTableOUT_NAMEGRP_1(void);
   virtual void set_MenuTableOUT_NAMEGRP_1(TFIBWideStringField * MenuTableOUT_NAMEGRP_1);

   virtual TFIBLargeIntField * get_MenuTableOUT_IDGRP_2(void);
   virtual void set_MenuTableOUT_IDGRP_2(TFIBLargeIntField * MenuTableOUT_IDGRP_2);

   virtual TFIBWideStringField * get_MenuTableOUT_NAMEGRP_2(void);
   virtual void set_MenuTableOUT_NAMEGRP_2(TFIBWideStringField * MenuTableOUT_NAMEGRP_2);

   virtual TFIBLargeIntField * get_MenuTableOUT_IDGRP_3(void);
   virtual void set_MenuTableOUT_IDGRP_3(TFIBLargeIntField * MenuTableOUT_IDGRP_3);

   virtual TFIBWideStringField * get_MenuTableOUT_NAMEGRP_3(void);
   virtual void set_MenuTableOUT_NAMEGRP_3(TFIBWideStringField * MenuTableOUT_NAMEGRP_3);

   virtual TFIBLargeIntField * get_MenuTableOUT_IDGRP(void);
   virtual void set_MenuTableOUT_IDGRP(TFIBLargeIntField * MenuTableOUT_IDGRP);

   virtual TFIBLargeIntField * get_MenuTableID_INTERF_MAINMENU(void);
   virtual void set_MenuTableID_INTERF_MAINMENU(TFIBLargeIntField * MenuTableID_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_MenuTableIDBASE_INTERF_MAINMENU(void);
   virtual void set_MenuTableIDBASE_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDBASE_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_MenuTableIDGRP_INTERF_MAINMENU(void);
   virtual void set_MenuTableIDGRP_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDGRP_INTERF_MAINMENU);

   virtual TFIBWideStringField * get_MenuTableNAME_INTERF_MAINMENU(void);
   virtual void set_MenuTableNAME_INTERF_MAINMENU(TFIBWideStringField * MenuTableNAME_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_MenuTableMODUL_INTERF_MAINMENU(void);
   virtual void set_MenuTableMODUL_INTERF_MAINMENU(TFIBIntegerField * MenuTableMODUL_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_MenuTableIDGRPUSER_INTERF_MAINMENU(void);
   virtual void set_MenuTableIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDGRPUSER_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_MenuTableAPPLICATION_INTERF_MAINMENU(void);
   virtual void set_MenuTableAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * MenuTableAPPLICATION_INTERF_MAINMENU);

   virtual TFIBWideStringField * get_MenuTableSHORTCUT_INTERF_MAINMENU(void);
   virtual void set_MenuTableSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * MenuTableSHORTCUT_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_MenuTableINDEX_INTERF_MAINMENU(void);
   virtual void set_MenuTableINDEX_INTERF_MAINMENU(TFIBIntegerField * MenuTableINDEX_INTERF_MAINMENU);

   virtual TFIBWideStringField * get_MenuTableGUIDMOD_INTERF_MAINMENU(void);
   virtual void set_MenuTableGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * MenuTableGUIDMOD_INTERF_MAINMENU);

   virtual TFIBSmallIntField * get_MenuTableFL_UPD_FORM_INTERF_MAINMENU(void);
   virtual void set_MenuTableFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * MenuTableFL_UPD_FORM_INTERF_MAINMENU);

   virtual TFIBSmallIntField * get_MenuTableFL_NEW_DOC_INTERF_MAINMENU(void);
   virtual void set_MenuTableFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * MenuTableFL_NEW_DOC_INTERF_MAINMENU);

   virtual TFIBLargeIntField * get_MenuTableIDEL_INTERF_MAINMENU(void);
   virtual void set_MenuTableIDEL_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDEL_INTERF_MAINMENU);

   virtual TFIBSmallIntField * get_MenuTableFL_OPEN_EL_INTERF_MAINMENU(void);
   virtual void set_MenuTableFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * MenuTableFL_OPEN_EL_INTERF_MAINMENU);

   virtual TFIBIntegerField * get_MenuTableTYPE_IDEL_INTERF_MAINMENU(void);
   virtual void set_MenuTableTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * MenuTableTYPE_IDEL_INTERF_MAINMENU);

   virtual __int64 get_IdGrpUser(void);
   virtual void set_IdGrpUser(__int64 IdGrpUser);

   virtual int get_NumApplication(void);
   virtual void set_NumApplication(int NumApplication);

   virtual void OpenTable(int num_application, __int64 id_grp_user);
   virtual void Table_First(void);
   virtual void Table_Next(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(int num_application,__int64 id_grp_user, __int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void Element_Edit(void);
   virtual void Element_Post(void);
   virtual void OpenMenuTable(int num_application, __int64 id_grp_user);
};
#define CLSID_TDMInterfMainMenuGrpImpl __uuidof(TDMInterfMainMenuGrpImpl)
#endif
