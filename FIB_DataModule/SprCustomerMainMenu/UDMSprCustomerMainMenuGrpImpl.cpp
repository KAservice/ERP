#include "vcl.h"
#pragma hdrstop


#include "UDMSprCustomerMainMenuGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprCustomerMainMenuGrpImpl::TDMSprCustomerMainMenuGrpImpl()           
{                                            
Object=new TDMSprCustomerMainMenuGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprCustomerMainMenuGrpImpl::~TDMSprCustomerMainMenuGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprCustomerMainMenuGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
 {                                                                         
int result=0;                                                             
if (id_interface==IID_IkanUnknown)                                        
   {                                                                     
   *ppv=static_cast<IkanUnknown*> (this);                                 
   result=-1;                                                             
   }                                                                      
else if (id_interface==IID_IMainInterface)                        
   {                                                                     
   *ppv=static_cast<IMainInterface*> (this);                                
   result=-1;                                                            
   }  
else if (id_interface==IID_IDMSprCustomerMainMenuGrp)                        
   {                                                                     
   *ppv=static_cast<IDMSprCustomerMainMenuGrp*> (this);                                
   result=-1;                                                            
   }                                                                     
else                                                                     
   {                                                                     
   *ppv=NULL;                                                            
   result=1;                                                             
   return result;                                                        
   }                                                                     
kanAddRef();                       
return result;                                                           
}                                                                       
//---------------------------------------------------------------
int TDMSprCustomerMainMenuGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprCustomerMainMenuGrpImpl::kanRelease(void)                                  
{                                                                      
if (--NumRefs==0)                                                     
   {                                                                  
   delete this;                                                       
   return 0;                                                       
   }                                                                  
return NumRefs;                                                       
}                                                                     
//---------------------------------------------------------------

//IMainInterface 
int  TDMSprCustomerMainMenuGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprCustomerMainMenuGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerMainMenuGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprCustomerMainMenuGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerMainMenuGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprCustomerMainMenuGrp
TDataSource * TDMSprCustomerMainMenuGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprCustomerMainMenuGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerMainMenuGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerMainMenuGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerMainMenuGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerMainMenuGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerMainMenuGrpImpl::get_MenuTable(void)
{
return Object->MenuTable;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTable(TpFIBDataSet * MenuTable)
{
Object->MenuTable=MenuTable;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableOUT_IDGRP_1(void)
{
return Object->MenuTableOUT_IDGRP_1;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableOUT_IDGRP_1(TFIBLargeIntField * MenuTableOUT_IDGRP_1)
{
Object->MenuTableOUT_IDGRP_1=MenuTableOUT_IDGRP_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableOUT_NAMEGRP_1(void)
{
return Object->MenuTableOUT_NAMEGRP_1;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableOUT_NAMEGRP_1(TFIBWideStringField * MenuTableOUT_NAMEGRP_1)
{
Object->MenuTableOUT_NAMEGRP_1=MenuTableOUT_NAMEGRP_1;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableOUT_IDGRP_2(void)
{
return Object->MenuTableOUT_IDGRP_2;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableOUT_IDGRP_2(TFIBLargeIntField * MenuTableOUT_IDGRP_2)
{
Object->MenuTableOUT_IDGRP_2=MenuTableOUT_IDGRP_2;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableOUT_NAMEGRP_2(void)
{
return Object->MenuTableOUT_NAMEGRP_2;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableOUT_NAMEGRP_2(TFIBWideStringField * MenuTableOUT_NAMEGRP_2)
{
Object->MenuTableOUT_NAMEGRP_2=MenuTableOUT_NAMEGRP_2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableOUT_IDGRP_3(void)
{
return Object->MenuTableOUT_IDGRP_3;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableOUT_IDGRP_3(TFIBLargeIntField * MenuTableOUT_IDGRP_3)
{
Object->MenuTableOUT_IDGRP_3=MenuTableOUT_IDGRP_3;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableOUT_NAMEGRP_3(void)
{
return Object->MenuTableOUT_NAMEGRP_3;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableOUT_NAMEGRP_3(TFIBWideStringField * MenuTableOUT_NAMEGRP_3)
{
Object->MenuTableOUT_NAMEGRP_3=MenuTableOUT_NAMEGRP_3;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableOUT_IDGRP(void)
{
return Object->MenuTableOUT_IDGRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableOUT_IDGRP(TFIBLargeIntField * MenuTableOUT_IDGRP)
{
Object->MenuTableOUT_IDGRP=MenuTableOUT_IDGRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableID_INTERF_MAINMENU(void)
{
return Object->MenuTableID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableID_INTERF_MAINMENU(TFIBLargeIntField * MenuTableID_INTERF_MAINMENU)
{
Object->MenuTableID_INTERF_MAINMENU=MenuTableID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableIDBASE_INTERF_MAINMENU(void)
{
return Object->MenuTableIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableIDBASE_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDBASE_INTERF_MAINMENU)
{
Object->MenuTableIDBASE_INTERF_MAINMENU=MenuTableIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableIDGRP_INTERF_MAINMENU(void)
{
return Object->MenuTableIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableIDGRP_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDGRP_INTERF_MAINMENU)
{
Object->MenuTableIDGRP_INTERF_MAINMENU=MenuTableIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableNAME_INTERF_MAINMENU(void)
{
return Object->MenuTableNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableNAME_INTERF_MAINMENU(TFIBWideStringField * MenuTableNAME_INTERF_MAINMENU)
{
Object->MenuTableNAME_INTERF_MAINMENU=MenuTableNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableMODUL_INTERF_MAINMENU(void)
{
return Object->MenuTableMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableMODUL_INTERF_MAINMENU(TFIBIntegerField * MenuTableMODUL_INTERF_MAINMENU)
{
Object->MenuTableMODUL_INTERF_MAINMENU=MenuTableMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableIDGRPUSER_INTERF_MAINMENU(void)
{
return Object->MenuTableIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDGRPUSER_INTERF_MAINMENU)
{
Object->MenuTableIDGRPUSER_INTERF_MAINMENU=MenuTableIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableAPPLICATION_INTERF_MAINMENU(void)
{
return Object->MenuTableAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * MenuTableAPPLICATION_INTERF_MAINMENU)
{
Object->MenuTableAPPLICATION_INTERF_MAINMENU=MenuTableAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableSHORTCUT_INTERF_MAINMENU(void)
{
return Object->MenuTableSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * MenuTableSHORTCUT_INTERF_MAINMENU)
{
Object->MenuTableSHORTCUT_INTERF_MAINMENU=MenuTableSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableINDEX_INTERF_MAINMENU(void)
{
return Object->MenuTableINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableINDEX_INTERF_MAINMENU(TFIBIntegerField * MenuTableINDEX_INTERF_MAINMENU)
{
Object->MenuTableINDEX_INTERF_MAINMENU=MenuTableINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableGUIDMOD_INTERF_MAINMENU(void)
{
return Object->MenuTableGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * MenuTableGUIDMOD_INTERF_MAINMENU)
{
Object->MenuTableGUIDMOD_INTERF_MAINMENU=MenuTableGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableFL_UPD_FORM_INTERF_MAINMENU(void)
{
return Object->MenuTableFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * MenuTableFL_UPD_FORM_INTERF_MAINMENU)
{
Object->MenuTableFL_UPD_FORM_INTERF_MAINMENU=MenuTableFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableFL_NEW_DOC_INTERF_MAINMENU(void)
{
return Object->MenuTableFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * MenuTableFL_NEW_DOC_INTERF_MAINMENU)
{
Object->MenuTableFL_NEW_DOC_INTERF_MAINMENU=MenuTableFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableIDEL_INTERF_MAINMENU(void)
{
return Object->MenuTableIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableIDEL_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDEL_INTERF_MAINMENU)
{
Object->MenuTableIDEL_INTERF_MAINMENU=MenuTableIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableFL_OPEN_EL_INTERF_MAINMENU(void)
{
return Object->MenuTableFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * MenuTableFL_OPEN_EL_INTERF_MAINMENU)
{
Object->MenuTableFL_OPEN_EL_INTERF_MAINMENU=MenuTableFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprCustomerMainMenuGrpImpl::get_MenuTableTYPE_IDEL_INTERF_MAINMENU(void)
{
return Object->MenuTableTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_MenuTableTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * MenuTableTYPE_IDEL_INTERF_MAINMENU)
{
Object->MenuTableTYPE_IDEL_INTERF_MAINMENU=MenuTableTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_TableID_CUST_MAINMENU_GRP(void)
{
return Object->TableID_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_TableID_CUST_MAINMENU_GRP(TFIBLargeIntField * TableID_CUST_MAINMENU_GRP)
{
Object->TableID_CUST_MAINMENU_GRP=TableID_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_TableIDBASE_CUST_MAINMENU_GRP(void)
{
return Object->TableIDBASE_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_TableIDBASE_CUST_MAINMENU_GRP(TFIBLargeIntField * TableIDBASE_CUST_MAINMENU_GRP)
{
Object->TableIDBASE_CUST_MAINMENU_GRP=TableIDBASE_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuGrpImpl::get_TableGID_CUST_MAINMENU_GRP(void)
{
return Object->TableGID_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_TableGID_CUST_MAINMENU_GRP(TFIBWideStringField * TableGID_CUST_MAINMENU_GRP)
{
Object->TableGID_CUST_MAINMENU_GRP=TableGID_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_TableIDACCOUNT_CUST_MAINMENU_GRP(void)
{
return Object->TableIDACCOUNT_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_TableIDACCOUNT_CUST_MAINMENU_GRP(TFIBLargeIntField * TableIDACCOUNT_CUST_MAINMENU_GRP)
{
Object->TableIDACCOUNT_CUST_MAINMENU_GRP=TableIDACCOUNT_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_TableIDGRP_CUST_MAINMENU_GRP(void)
{
return Object->TableIDGRP_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_TableIDGRP_CUST_MAINMENU_GRP(TFIBLargeIntField * TableIDGRP_CUST_MAINMENU_GRP)
{
Object->TableIDGRP_CUST_MAINMENU_GRP=TableIDGRP_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_TableIDGRPUSER_CUST_MAINMENU_GRP(void)
{
return Object->TableIDGRPUSER_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_TableIDGRPUSER_CUST_MAINMENU_GRP(TFIBLargeIntField * TableIDGRPUSER_CUST_MAINMENU_GRP)
{
Object->TableIDGRPUSER_CUST_MAINMENU_GRP=TableIDGRPUSER_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuGrpImpl::get_TableNAME_CUST_MAINMENU_GRP(void)
{
return Object->TableNAME_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_TableNAME_CUST_MAINMENU_GRP(TFIBWideStringField * TableNAME_CUST_MAINMENU_GRP)
{
Object->TableNAME_CUST_MAINMENU_GRP=TableNAME_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_ElementID_CUST_MAINMENU_GRP(void)
{
return Object->ElementID_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_ElementID_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementID_CUST_MAINMENU_GRP)
{
Object->ElementID_CUST_MAINMENU_GRP=ElementID_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_ElementIDBASE_CUST_MAINMENU_GRP(void)
{
return Object->ElementIDBASE_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_ElementIDBASE_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementIDBASE_CUST_MAINMENU_GRP)
{
Object->ElementIDBASE_CUST_MAINMENU_GRP=ElementIDBASE_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuGrpImpl::get_ElementGID_CUST_MAINMENU_GRP(void)
{
return Object->ElementGID_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_ElementGID_CUST_MAINMENU_GRP(TFIBWideStringField * ElementGID_CUST_MAINMENU_GRP)
{
Object->ElementGID_CUST_MAINMENU_GRP=ElementGID_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_ElementIDACCOUNT_CUST_MAINMENU_GRP(void)
{
return Object->ElementIDACCOUNT_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_ElementIDACCOUNT_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementIDACCOUNT_CUST_MAINMENU_GRP)
{
Object->ElementIDACCOUNT_CUST_MAINMENU_GRP=ElementIDACCOUNT_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_ElementIDGRP_CUST_MAINMENU_GRP(void)
{
return Object->ElementIDGRP_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_ElementIDGRP_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementIDGRP_CUST_MAINMENU_GRP)
{
Object->ElementIDGRP_CUST_MAINMENU_GRP=ElementIDGRP_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuGrpImpl::get_ElementIDGRPUSER_CUST_MAINMENU_GRP(void)
{
return Object->ElementIDGRPUSER_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_ElementIDGRPUSER_CUST_MAINMENU_GRP(TFIBLargeIntField * ElementIDGRPUSER_CUST_MAINMENU_GRP)
{
Object->ElementIDGRPUSER_CUST_MAINMENU_GRP=ElementIDGRPUSER_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuGrpImpl::get_ElementNAME_CUST_MAINMENU_GRP(void)
{
return Object->ElementNAME_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_ElementNAME_CUST_MAINMENU_GRP(TFIBWideStringField * ElementNAME_CUST_MAINMENU_GRP)
{
Object->ElementNAME_CUST_MAINMENU_GRP=ElementNAME_CUST_MAINMENU_GRP;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerMainMenuGrpImpl::get_IdGrpUser(void)
{
return Object->IdGrpUser;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_IdGrpUser(__int64 IdGrpUser)
{
Object->IdGrpUser=IdGrpUser;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerMainMenuGrpImpl::get_IdAccount(void)
{
return Object->IdAccount;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::set_IdAccount(__int64 IdAccount)
{
Object->IdAccount=IdAccount;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::OpenTable(__int64 id_account, __int64 id_grp_user)
{
return Object->OpenTable(id_account,id_grp_user);
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::Table_First(void)
{
return Object->Table_First();
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::Table_Next(void)
{
return Object->Table_Next();
}
//---------------------------------------------------------------
int TDMSprCustomerMainMenuGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::NewElement(__int64 id_account,__int64 id_grp_user, __int64 id_grp)
{
return Object->NewElement(id_account,id_grp_user,id_grp);
}
//---------------------------------------------------------------
bool TDMSprCustomerMainMenuGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprCustomerMainMenuGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::Element_Edit(void)
{
return Object->Element_Edit();
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::Element_Post(void)
{
return Object->Element_Post();
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuGrpImpl::OpenMenuTable(int num_application, __int64 id_grp_user)
{
return Object->OpenMenuTable(num_application,id_grp_user);
}
//---------------------------------------------------------------
