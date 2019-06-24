#ifndef UIDMSprCustomerMainMenuGrpH
#define UIDMSprCustomerMainMenuGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprCustomerMainMenuGrp)) IDMSprCustomerMainMenuGrp : public IMainInterface
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

   __property TpFIBDataSet * MenuTable = {read = get_MenuTable , write = set_MenuTable};
   virtual TpFIBDataSet * get_MenuTable(void)=0;
   virtual void set_MenuTable(TpFIBDataSet * MenuTable)=0;

   __property TFIBLargeIntField * MenuTableOUT_IDGRP_1 = {read = get_MenuTableOUT_IDGRP_1 , write = set_MenuTableOUT_IDGRP_1};
   virtual TFIBLargeIntField * get_MenuTableOUT_IDGRP_1(void)=0;
   virtual void set_MenuTableOUT_IDGRP_1(TFIBLargeIntField * MenuTableOUT_IDGRP_1)=0;

   __property TFIBWideStringField * MenuTableOUT_NAMEGRP_1 = {read = get_MenuTableOUT_NAMEGRP_1 , write = set_MenuTableOUT_NAMEGRP_1};
   virtual TFIBWideStringField * get_MenuTableOUT_NAMEGRP_1(void)=0;
   virtual void set_MenuTableOUT_NAMEGRP_1(TFIBWideStringField * MenuTableOUT_NAMEGRP_1)=0;

   __property TFIBLargeIntField * MenuTableOUT_IDGRP_2 = {read = get_MenuTableOUT_IDGRP_2 , write = set_MenuTableOUT_IDGRP_2};
   virtual TFIBLargeIntField * get_MenuTableOUT_IDGRP_2(void)=0;
   virtual void set_MenuTableOUT_IDGRP_2(TFIBLargeIntField * MenuTableOUT_IDGRP_2)=0;

   __property TFIBWideStringField * MenuTableOUT_NAMEGRP_2 = {read = get_MenuTableOUT_NAMEGRP_2 , write = set_MenuTableOUT_NAMEGRP_2};
   virtual TFIBWideStringField * get_MenuTableOUT_NAMEGRP_2(void)=0;
   virtual void set_MenuTableOUT_NAMEGRP_2(TFIBWideStringField * MenuTableOUT_NAMEGRP_2)=0;

   __property TFIBLargeIntField * MenuTableOUT_IDGRP_3 = {read = get_MenuTableOUT_IDGRP_3 , write = set_MenuTableOUT_IDGRP_3};
   virtual TFIBLargeIntField * get_MenuTableOUT_IDGRP_3(void)=0;
   virtual void set_MenuTableOUT_IDGRP_3(TFIBLargeIntField * MenuTableOUT_IDGRP_3)=0;

   __property TFIBWideStringField * MenuTableOUT_NAMEGRP_3 = {read = get_MenuTableOUT_NAMEGRP_3 , write = set_MenuTableOUT_NAMEGRP_3};
   virtual TFIBWideStringField * get_MenuTableOUT_NAMEGRP_3(void)=0;
   virtual void set_MenuTableOUT_NAMEGRP_3(TFIBWideStringField * MenuTableOUT_NAMEGRP_3)=0;

   __property TFIBLargeIntField * MenuTableOUT_IDGRP = {read = get_MenuTableOUT_IDGRP , write = set_MenuTableOUT_IDGRP};
   virtual TFIBLargeIntField * get_MenuTableOUT_IDGRP(void)=0;
   virtual void set_MenuTableOUT_IDGRP(TFIBLargeIntField * MenuTableOUT_IDGRP)=0;

   __property TFIBLargeIntField * MenuTableID_INTERF_MAINMENU = {read = get_MenuTableID_INTERF_MAINMENU , write = set_MenuTableID_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_MenuTableID_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableID_INTERF_MAINMENU(TFIBLargeIntField * MenuTableID_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * MenuTableIDBASE_INTERF_MAINMENU = {read = get_MenuTableIDBASE_INTERF_MAINMENU , write = set_MenuTableIDBASE_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_MenuTableIDBASE_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableIDBASE_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDBASE_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * MenuTableIDGRP_INTERF_MAINMENU = {read = get_MenuTableIDGRP_INTERF_MAINMENU , write = set_MenuTableIDGRP_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_MenuTableIDGRP_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableIDGRP_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDGRP_INTERF_MAINMENU)=0;

   __property TFIBWideStringField * MenuTableNAME_INTERF_MAINMENU = {read = get_MenuTableNAME_INTERF_MAINMENU , write = set_MenuTableNAME_INTERF_MAINMENU};
   virtual TFIBWideStringField * get_MenuTableNAME_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableNAME_INTERF_MAINMENU(TFIBWideStringField * MenuTableNAME_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * MenuTableMODUL_INTERF_MAINMENU = {read = get_MenuTableMODUL_INTERF_MAINMENU , write = set_MenuTableMODUL_INTERF_MAINMENU};
   virtual TFIBIntegerField * get_MenuTableMODUL_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableMODUL_INTERF_MAINMENU(TFIBIntegerField * MenuTableMODUL_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * MenuTableIDGRPUSER_INTERF_MAINMENU = {read = get_MenuTableIDGRPUSER_INTERF_MAINMENU , write = set_MenuTableIDGRPUSER_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_MenuTableIDGRPUSER_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDGRPUSER_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * MenuTableAPPLICATION_INTERF_MAINMENU = {read = get_MenuTableAPPLICATION_INTERF_MAINMENU , write = set_MenuTableAPPLICATION_INTERF_MAINMENU};
   virtual TFIBIntegerField * get_MenuTableAPPLICATION_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * MenuTableAPPLICATION_INTERF_MAINMENU)=0;

   __property TFIBWideStringField * MenuTableSHORTCUT_INTERF_MAINMENU = {read = get_MenuTableSHORTCUT_INTERF_MAINMENU , write = set_MenuTableSHORTCUT_INTERF_MAINMENU};
   virtual TFIBWideStringField * get_MenuTableSHORTCUT_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * MenuTableSHORTCUT_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * MenuTableINDEX_INTERF_MAINMENU = {read = get_MenuTableINDEX_INTERF_MAINMENU , write = set_MenuTableINDEX_INTERF_MAINMENU};
   virtual TFIBIntegerField * get_MenuTableINDEX_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableINDEX_INTERF_MAINMENU(TFIBIntegerField * MenuTableINDEX_INTERF_MAINMENU)=0;

   __property TFIBWideStringField * MenuTableGUIDMOD_INTERF_MAINMENU = {read = get_MenuTableGUIDMOD_INTERF_MAINMENU , write = set_MenuTableGUIDMOD_INTERF_MAINMENU};
   virtual TFIBWideStringField * get_MenuTableGUIDMOD_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * MenuTableGUIDMOD_INTERF_MAINMENU)=0;

   __property TFIBSmallIntField * MenuTableFL_UPD_FORM_INTERF_MAINMENU = {read = get_MenuTableFL_UPD_FORM_INTERF_MAINMENU , write = set_MenuTableFL_UPD_FORM_INTERF_MAINMENU};
   virtual TFIBSmallIntField * get_MenuTableFL_UPD_FORM_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * MenuTableFL_UPD_FORM_INTERF_MAINMENU)=0;

   __property TFIBSmallIntField * MenuTableFL_NEW_DOC_INTERF_MAINMENU = {read = get_MenuTableFL_NEW_DOC_INTERF_MAINMENU , write = set_MenuTableFL_NEW_DOC_INTERF_MAINMENU};
   virtual TFIBSmallIntField * get_MenuTableFL_NEW_DOC_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * MenuTableFL_NEW_DOC_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * MenuTableIDEL_INTERF_MAINMENU = {read = get_MenuTableIDEL_INTERF_MAINMENU , write = set_MenuTableIDEL_INTERF_MAINMENU};
   virtual TFIBLargeIntField * get_MenuTableIDEL_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableIDEL_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDEL_INTERF_MAINMENU)=0;

   __property TFIBSmallIntField * MenuTableFL_OPEN_EL_INTERF_MAINMENU = {read = get_MenuTableFL_OPEN_EL_INTERF_MAINMENU , write = set_MenuTableFL_OPEN_EL_INTERF_MAINMENU};
   virtual TFIBSmallIntField * get_MenuTableFL_OPEN_EL_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * MenuTableFL_OPEN_EL_INTERF_MAINMENU)=0;

   __property TFIBIntegerField * MenuTableTYPE_IDEL_INTERF_MAINMENU = {read = get_MenuTableTYPE_IDEL_INTERF_MAINMENU , write = set_MenuTableTYPE_IDEL_INTERF_MAINMENU};
   virtual TFIBIntegerField * get_MenuTableTYPE_IDEL_INTERF_MAINMENU(void)=0;
   virtual void set_MenuTableTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * MenuTableTYPE_IDEL_INTERF_MAINMENU)=0;

   __property TFIBLargeIntField * TableID_CUST_MAINMENU_GRP = {read = get_TableID_CUST_MAINMENU_GRP , write = set_TableID_CUST_MAINMENU_GRP};
   virtual TFIBLargeIntField * get_TableID_CUST_MAINMENU_GRP(void)=0;
   virtual void set_TableID_CUST_MAINMENU_GRP(TFIBLargeIntField * TableID_CUST_MAINMENU_GRP)=0;

   __property TFIBLargeIntField * TableIDBASE_CUST_MAINMENU_GRP = {read = get_TableIDBASE_CUST_MAINMENU_GRP , write = set_TableIDBASE_CUST_MAINMENU_GRP};
   virtual TFIBLargeIntField * get_TableIDBASE_CUST_MAINMENU_GRP(void)=0;
   virtual void set_TableIDBASE_CUST_MAINMENU_GRP(TFIBLargeIntField * TableIDBASE_CUST_MAINMENU_GRP)=0;

   __property TFIBWideStringField * TableGID_CUST_MAINMENU_GRP = {read = get_TableGID_CUST_MAINMENU_GRP , write = set_TableGID_CUST_MAINMENU_GRP};
   virtual TFIBWideStringField * get_TableGID_CUST_MAINMENU_GRP(void)=0;
   virtual void set_TableGID_CUST_MAINMENU_GRP(TFIBWideStringField * TableGID_CUST_MAINMENU_GRP)=0;

   __property TFIBLargeIntField * TableIDACCOUNT_CUST_MAINMENU_GRP = {read = get_TableIDACCOUNT_CUST_MAINMENU_GRP , write = set_TableIDACCOUNT_CUST_MAINMENU_GRP};
   virtual TFIBLargeIntField * get_TableIDACCOUNT_CUST_MAINMENU_GRP(void)=0;
   virtual void set_TableIDACCOUNT_CUST_MAINMENU_GRP(TFIBLargeIntField * TableIDACCOUNT_CUST_MAINMENU_GRP)=0;

   __property TFIBLargeIntField * TableIDGRP_CUST_MAINMENU_GRP = {read = get_TableIDGRP_CUST_MAINMENU_GRP , write = set_TableIDGRP_CUST_MAINMENU_GRP};
   virtual TFIBLargeIntField * get_TableIDGRP_CUST_MAINMENU_GRP(void)=0;
   virtual void set_TableIDGRP_CUST_MAINMENU_GRP(TFIBLargeIntField * TableIDGRP_CUST_MAINMENU_GRP)=0;

   __property TFIBLargeIntField * TableIDGRPUSER_CUST_MAINMENU_GRP = {read = get_TableIDGRPUSER_CUST_MAINMENU_GRP , write = set_TableIDGRPUSER_CUST_MAINMENU_GRP};
   virtual TFIBLargeIntField * get_TableIDGRPUSER_CUST_MAINMENU_GRP(void)=0;
   virtual void set_TableIDGRPUSER_CUST_MAINMENU_GRP(TFIBLargeIntField * TableIDGRPUSER_CUST_MAINMENU_GRP)=0;

   __property TFIBWideStringField * TableNAME_CUST_MAINMENU_GRP = {read = get_TableNAME_CUST_MAINMENU_GRP , write = set_TableNAME_CUST_MAINMENU_GRP};
   virtual TFIBWideStringField * get_TableNAME_CUST_MAINMENU_GRP(void)=0;
   virtual void set_TableNAME_CUST_MAINMENU_GRP(TFIBWideStringField * TableNAME_CUST_MAINMENU_GRP)=0;

   __property TFIBLargeIntField * ElementID_CUST_MAINMENU_GRP = {read = get_ElementID_CUST_MAINMENU_GRP , write = set_ElementID_CUST_MAINMENU_GRP};
   virtual TFIBLargeIntField * get_ElementID_CUST_MAINMENU_GRP(void)=0;
   virtual void set_ElementID_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementID_CUST_MAINMENU_GRP)=0;

   __property TFIBLargeIntField * ElementIDBASE_CUST_MAINMENU_GRP = {read = get_ElementIDBASE_CUST_MAINMENU_GRP , write = set_ElementIDBASE_CUST_MAINMENU_GRP};
   virtual TFIBLargeIntField * get_ElementIDBASE_CUST_MAINMENU_GRP(void)=0;
   virtual void set_ElementIDBASE_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementIDBASE_CUST_MAINMENU_GRP)=0;

   __property TFIBWideStringField * ElementGID_CUST_MAINMENU_GRP = {read = get_ElementGID_CUST_MAINMENU_GRP , write = set_ElementGID_CUST_MAINMENU_GRP};
   virtual TFIBWideStringField * get_ElementGID_CUST_MAINMENU_GRP(void)=0;
   virtual void set_ElementGID_CUST_MAINMENU_GRP(TFIBWideStringField * ElementGID_CUST_MAINMENU_GRP)=0;

   __property TFIBLargeIntField * ElementIDACCOUNT_CUST_MAINMENU_GRP = {read = get_ElementIDACCOUNT_CUST_MAINMENU_GRP , write = set_ElementIDACCOUNT_CUST_MAINMENU_GRP};
   virtual TFIBLargeIntField * get_ElementIDACCOUNT_CUST_MAINMENU_GRP(void)=0;
   virtual void set_ElementIDACCOUNT_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementIDACCOUNT_CUST_MAINMENU_GRP)=0;

   __property TFIBLargeIntField * ElementIDGRP_CUST_MAINMENU_GRP = {read = get_ElementIDGRP_CUST_MAINMENU_GRP , write = set_ElementIDGRP_CUST_MAINMENU_GRP};
   virtual TFIBLargeIntField * get_ElementIDGRP_CUST_MAINMENU_GRP(void)=0;
   virtual void set_ElementIDGRP_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementIDGRP_CUST_MAINMENU_GRP)=0;

   __property TFIBLargeIntField * ElementIDGRPUSER_CUST_MAINMENU_GRP = {read = get_ElementIDGRPUSER_CUST_MAINMENU_GRP , write = set_ElementIDGRPUSER_CUST_MAINMENU_GRP};
   virtual TFIBLargeIntField * get_ElementIDGRPUSER_CUST_MAINMENU_GRP(void)=0;
   virtual void set_ElementIDGRPUSER_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementIDGRPUSER_CUST_MAINMENU_GRP)=0;

   __property TFIBWideStringField * ElementNAME_CUST_MAINMENU_GRP = {read = get_ElementNAME_CUST_MAINMENU_GRP , write = set_ElementNAME_CUST_MAINMENU_GRP};
   virtual TFIBWideStringField * get_ElementNAME_CUST_MAINMENU_GRP(void)=0;
   virtual void set_ElementNAME_CUST_MAINMENU_GRP(TFIBWideStringField * ElementNAME_CUST_MAINMENU_GRP)=0;

   __property __int64 IdGrpUser = {read = get_IdGrpUser , write = set_IdGrpUser};
   virtual __int64 get_IdGrpUser(void)=0;
   virtual void set_IdGrpUser(__int64 IdGrpUser)=0;

   __property __int64 IdAccount = {read = get_IdAccount , write = set_IdAccount};
   virtual __int64 get_IdAccount(void)=0;
   virtual void set_IdAccount(__int64 IdAccount)=0;

   virtual void OpenTable(__int64 id_account, __int64 id_grp_user)=0;
   virtual void Table_First(void)=0;
   virtual void Table_Next(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_account,__int64 id_grp_user, __int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void Element_Edit(void)=0;
   virtual void Element_Post(void)=0;
   virtual void OpenMenuTable(int num_application, __int64 id_grp_user)=0;
};
#define IID_IDMSprCustomerMainMenuGrp __uuidof(IDMSprCustomerMainMenuGrp)
#endif
