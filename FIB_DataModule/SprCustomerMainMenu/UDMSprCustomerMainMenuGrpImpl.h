#ifndef UDMSprCustomerMainMenuGrpImplH
#define UDMSprCustomerMainMenuGrpImplH
#include "IDMSprCustomerMainMenuGrp.h"
#include "UDMSprCustomerMainMenuGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprCustomerMainMenuGrpImpl)) TDMSprCustomerMainMenuGrpImpl : public IDMSprCustomerMainMenuGrp
{
public:
   TDMSprCustomerMainMenuGrpImpl();
   ~TDMSprCustomerMainMenuGrpImpl();
   TDMSprCustomerMainMenuGrp * Object;
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

//IDMSprCustomerMainMenuGrp
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

   virtual TFIBLargeIntField * get_TableID_CUST_MAINMENU_GRP(void);
   virtual void set_TableID_CUST_MAINMENU_GRP(TFIBLargeIntField * TableID_CUST_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_CUST_MAINMENU_GRP(void);
   virtual void set_TableIDBASE_CUST_MAINMENU_GRP(TFIBLargeIntField * TableIDBASE_CUST_MAINMENU_GRP);

   virtual TFIBWideStringField * get_TableGID_CUST_MAINMENU_GRP(void);
   virtual void set_TableGID_CUST_MAINMENU_GRP(TFIBWideStringField * TableGID_CUST_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_TableIDACCOUNT_CUST_MAINMENU_GRP(void);
   virtual void set_TableIDACCOUNT_CUST_MAINMENU_GRP(TFIBLargeIntField * TableIDACCOUNT_CUST_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_CUST_MAINMENU_GRP(void);
   virtual void set_TableIDGRP_CUST_MAINMENU_GRP(TFIBLargeIntField * TableIDGRP_CUST_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_TableIDGRPUSER_CUST_MAINMENU_GRP(void);
   virtual void set_TableIDGRPUSER_CUST_MAINMENU_GRP(TFIBLargeIntField * TableIDGRPUSER_CUST_MAINMENU_GRP);

   virtual TFIBWideStringField * get_TableNAME_CUST_MAINMENU_GRP(void);
   virtual void set_TableNAME_CUST_MAINMENU_GRP(TFIBWideStringField * TableNAME_CUST_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_ElementID_CUST_MAINMENU_GRP(void);
   virtual void set_ElementID_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementID_CUST_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_CUST_MAINMENU_GRP(void);
   virtual void set_ElementIDBASE_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementIDBASE_CUST_MAINMENU_GRP);

   virtual TFIBWideStringField * get_ElementGID_CUST_MAINMENU_GRP(void);
   virtual void set_ElementGID_CUST_MAINMENU_GRP(TFIBWideStringField * ElementGID_CUST_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_ElementIDACCOUNT_CUST_MAINMENU_GRP(void);
   virtual void set_ElementIDACCOUNT_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementIDACCOUNT_CUST_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_CUST_MAINMENU_GRP(void);
   virtual void set_ElementIDGRP_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementIDGRP_CUST_MAINMENU_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRPUSER_CUST_MAINMENU_GRP(void);
   virtual void set_ElementIDGRPUSER_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementIDGRPUSER_CUST_MAINMENU_GRP);

   virtual TFIBWideStringField * get_ElementNAME_CUST_MAINMENU_GRP(void);
   virtual void set_ElementNAME_CUST_MAINMENU_GRP(TFIBWideStringField * ElementNAME_CUST_MAINMENU_GRP);

   virtual __int64 get_IdGrpUser(void);
   virtual void set_IdGrpUser(__int64 IdGrpUser);

   virtual __int64 get_IdAccount(void);
   virtual void set_IdAccount(__int64 IdAccount);

   virtual void OpenTable(__int64 id_account, __int64 id_grp_user);
   virtual void Table_First(void);
   virtual void Table_Next(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_account,__int64 id_grp_user, __int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void Element_Edit(void);
   virtual void Element_Post(void);
   virtual void OpenMenuTable(int num_application, __int64 id_grp_user);
};
#define CLSID_TDMSprCustomerMainMenuGrpImpl __uuidof(TDMSprCustomerMainMenuGrpImpl)
#endif
