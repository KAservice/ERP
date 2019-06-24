#include "vcl.h"
#pragma hdrstop


#include "UDMInterfMainMenuGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMInterfMainMenuGrpImpl::TDMInterfMainMenuGrpImpl()           
{                                            
Object=new TDMInterfMainMenuGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMInterfMainMenuGrpImpl::~TDMInterfMainMenuGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMInterfMainMenuGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMInterfMainMenuGrp)                        
   {                                                                     
   *ppv=static_cast<IDMInterfMainMenuGrp*> (this);                                
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
int TDMInterfMainMenuGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMInterfMainMenuGrpImpl::kanRelease(void)                                  
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
int  TDMInterfMainMenuGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMInterfMainMenuGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMInterfMainMenuGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMInterfMainMenuGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMInterfMainMenuGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMInterfMainMenuGrp
TDataSource * TDMInterfMainMenuGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMInterfMainMenuGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMInterfMainMenuGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMInterfMainMenuGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMInterfMainMenuGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMInterfMainMenuGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMInterfMainMenuGrpImpl::get_MenuTable(void)
{
return Object->MenuTable;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTable(TpFIBDataSet * MenuTable)
{
Object->MenuTable=MenuTable;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_TableID_INTERF_MAINMENU_GRP(void)
{
return Object->TableID_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_TableID_INTERF_MAINMENU_GRP(TFIBLargeIntField * TableID_INTERF_MAINMENU_GRP)
{
Object->TableID_INTERF_MAINMENU_GRP=TableID_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_TableIDBASE_INTERF_MAINMENU_GRP(void)
{
return Object->TableIDBASE_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_TableIDBASE_INTERF_MAINMENU_GRP(TFIBLargeIntField * TableIDBASE_INTERF_MAINMENU_GRP)
{
Object->TableIDBASE_INTERF_MAINMENU_GRP=TableIDBASE_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuGrpImpl::get_TableAPPLICATION_INTERF_MAINMENU_GRP(void)
{
return Object->TableAPPLICATION_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_TableAPPLICATION_INTERF_MAINMENU_GRP(TFIBIntegerField * TableAPPLICATION_INTERF_MAINMENU_GRP)
{
Object->TableAPPLICATION_INTERF_MAINMENU_GRP=TableAPPLICATION_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_TableIDGRPUSER_INTERF_MAINMENU_GRP(void)
{
return Object->TableIDGRPUSER_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_TableIDGRPUSER_INTERF_MAINMENU_GRP(TFIBLargeIntField * TableIDGRPUSER_INTERF_MAINMENU_GRP)
{
Object->TableIDGRPUSER_INTERF_MAINMENU_GRP=TableIDGRPUSER_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuGrpImpl::get_TableNAME_INTERF_MAINMENU_GRP(void)
{
return Object->TableNAME_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_TableNAME_INTERF_MAINMENU_GRP(TFIBWideStringField * TableNAME_INTERF_MAINMENU_GRP)
{
Object->TableNAME_INTERF_MAINMENU_GRP=TableNAME_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_TableIDGRP_INTERF_MAINMENU_GRP(void)
{
return Object->TableIDGRP_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_TableIDGRP_INTERF_MAINMENU_GRP(TFIBLargeIntField * TableIDGRP_INTERF_MAINMENU_GRP)
{
Object->TableIDGRP_INTERF_MAINMENU_GRP=TableIDGRP_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuGrpImpl::get_TableINDEX_INTERF_MAINMENU_GRP(void)
{
return Object->TableINDEX_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_TableINDEX_INTERF_MAINMENU_GRP(TFIBIntegerField * TableINDEX_INTERF_MAINMENU_GRP)
{
Object->TableINDEX_INTERF_MAINMENU_GRP=TableINDEX_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TIntegerField * TDMInterfMainMenuGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_ElementID_INTERF_MAINMENU_GRP(void)
{
return Object->ElementID_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_ElementID_INTERF_MAINMENU_GRP(TFIBLargeIntField * ElementID_INTERF_MAINMENU_GRP)
{
Object->ElementID_INTERF_MAINMENU_GRP=ElementID_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_ElementIDBASE_INTERF_MAINMENU_GRP(void)
{
return Object->ElementIDBASE_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_ElementIDBASE_INTERF_MAINMENU_GRP(TFIBLargeIntField * ElementIDBASE_INTERF_MAINMENU_GRP)
{
Object->ElementIDBASE_INTERF_MAINMENU_GRP=ElementIDBASE_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuGrpImpl::get_ElementAPPLICATION_INTERF_MAINMENU_GRP(void)
{
return Object->ElementAPPLICATION_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_ElementAPPLICATION_INTERF_MAINMENU_GRP(TFIBIntegerField * ElementAPPLICATION_INTERF_MAINMENU_GRP)
{
Object->ElementAPPLICATION_INTERF_MAINMENU_GRP=ElementAPPLICATION_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_ElementIDGRPUSER_INTERF_MAINMENU_GRP(void)
{
return Object->ElementIDGRPUSER_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_ElementIDGRPUSER_INTERF_MAINMENU_GRP(TFIBLargeIntField * ElementIDGRPUSER_INTERF_MAINMENU_GRP)
{
Object->ElementIDGRPUSER_INTERF_MAINMENU_GRP=ElementIDGRPUSER_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuGrpImpl::get_ElementNAME_INTERF_MAINMENU_GRP(void)
{
return Object->ElementNAME_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_ElementNAME_INTERF_MAINMENU_GRP(TFIBWideStringField * ElementNAME_INTERF_MAINMENU_GRP)
{
Object->ElementNAME_INTERF_MAINMENU_GRP=ElementNAME_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_ElementIDGRP_INTERF_MAINMENU_GRP(void)
{
return Object->ElementIDGRP_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_ElementIDGRP_INTERF_MAINMENU_GRP(TFIBLargeIntField * ElementIDGRP_INTERF_MAINMENU_GRP)
{
Object->ElementIDGRP_INTERF_MAINMENU_GRP=ElementIDGRP_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuGrpImpl::get_ElementINDEX_INTERF_MAINMENU_GRP(void)
{
return Object->ElementINDEX_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_ElementINDEX_INTERF_MAINMENU_GRP(TFIBIntegerField * ElementINDEX_INTERF_MAINMENU_GRP)
{
Object->ElementINDEX_INTERF_MAINMENU_GRP=ElementINDEX_INTERF_MAINMENU_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_MenuTableOUT_IDGRP_1(void)
{
return Object->MenuTableOUT_IDGRP_1;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableOUT_IDGRP_1(TFIBLargeIntField * MenuTableOUT_IDGRP_1)
{
Object->MenuTableOUT_IDGRP_1=MenuTableOUT_IDGRP_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuGrpImpl::get_MenuTableOUT_NAMEGRP_1(void)
{
return Object->MenuTableOUT_NAMEGRP_1;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableOUT_NAMEGRP_1(TFIBWideStringField * MenuTableOUT_NAMEGRP_1)
{
Object->MenuTableOUT_NAMEGRP_1=MenuTableOUT_NAMEGRP_1;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_MenuTableOUT_IDGRP_2(void)
{
return Object->MenuTableOUT_IDGRP_2;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableOUT_IDGRP_2(TFIBLargeIntField * MenuTableOUT_IDGRP_2)
{
Object->MenuTableOUT_IDGRP_2=MenuTableOUT_IDGRP_2;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuGrpImpl::get_MenuTableOUT_NAMEGRP_2(void)
{
return Object->MenuTableOUT_NAMEGRP_2;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableOUT_NAMEGRP_2(TFIBWideStringField * MenuTableOUT_NAMEGRP_2)
{
Object->MenuTableOUT_NAMEGRP_2=MenuTableOUT_NAMEGRP_2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_MenuTableOUT_IDGRP_3(void)
{
return Object->MenuTableOUT_IDGRP_3;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableOUT_IDGRP_3(TFIBLargeIntField * MenuTableOUT_IDGRP_3)
{
Object->MenuTableOUT_IDGRP_3=MenuTableOUT_IDGRP_3;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuGrpImpl::get_MenuTableOUT_NAMEGRP_3(void)
{
return Object->MenuTableOUT_NAMEGRP_3;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableOUT_NAMEGRP_3(TFIBWideStringField * MenuTableOUT_NAMEGRP_3)
{
Object->MenuTableOUT_NAMEGRP_3=MenuTableOUT_NAMEGRP_3;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_MenuTableOUT_IDGRP(void)
{
return Object->MenuTableOUT_IDGRP;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableOUT_IDGRP(TFIBLargeIntField * MenuTableOUT_IDGRP)
{
Object->MenuTableOUT_IDGRP=MenuTableOUT_IDGRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_MenuTableID_INTERF_MAINMENU(void)
{
return Object->MenuTableID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableID_INTERF_MAINMENU(TFIBLargeIntField * MenuTableID_INTERF_MAINMENU)
{
Object->MenuTableID_INTERF_MAINMENU=MenuTableID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_MenuTableIDBASE_INTERF_MAINMENU(void)
{
return Object->MenuTableIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableIDBASE_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDBASE_INTERF_MAINMENU)
{
Object->MenuTableIDBASE_INTERF_MAINMENU=MenuTableIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_MenuTableIDGRP_INTERF_MAINMENU(void)
{
return Object->MenuTableIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableIDGRP_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDGRP_INTERF_MAINMENU)
{
Object->MenuTableIDGRP_INTERF_MAINMENU=MenuTableIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuGrpImpl::get_MenuTableNAME_INTERF_MAINMENU(void)
{
return Object->MenuTableNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableNAME_INTERF_MAINMENU(TFIBWideStringField * MenuTableNAME_INTERF_MAINMENU)
{
Object->MenuTableNAME_INTERF_MAINMENU=MenuTableNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuGrpImpl::get_MenuTableMODUL_INTERF_MAINMENU(void)
{
return Object->MenuTableMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableMODUL_INTERF_MAINMENU(TFIBIntegerField * MenuTableMODUL_INTERF_MAINMENU)
{
Object->MenuTableMODUL_INTERF_MAINMENU=MenuTableMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_MenuTableIDGRPUSER_INTERF_MAINMENU(void)
{
return Object->MenuTableIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDGRPUSER_INTERF_MAINMENU)
{
Object->MenuTableIDGRPUSER_INTERF_MAINMENU=MenuTableIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuGrpImpl::get_MenuTableAPPLICATION_INTERF_MAINMENU(void)
{
return Object->MenuTableAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * MenuTableAPPLICATION_INTERF_MAINMENU)
{
Object->MenuTableAPPLICATION_INTERF_MAINMENU=MenuTableAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuGrpImpl::get_MenuTableSHORTCUT_INTERF_MAINMENU(void)
{
return Object->MenuTableSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * MenuTableSHORTCUT_INTERF_MAINMENU)
{
Object->MenuTableSHORTCUT_INTERF_MAINMENU=MenuTableSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuGrpImpl::get_MenuTableINDEX_INTERF_MAINMENU(void)
{
return Object->MenuTableINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableINDEX_INTERF_MAINMENU(TFIBIntegerField * MenuTableINDEX_INTERF_MAINMENU)
{
Object->MenuTableINDEX_INTERF_MAINMENU=MenuTableINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuGrpImpl::get_MenuTableGUIDMOD_INTERF_MAINMENU(void)
{
return Object->MenuTableGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * MenuTableGUIDMOD_INTERF_MAINMENU)
{
Object->MenuTableGUIDMOD_INTERF_MAINMENU=MenuTableGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfMainMenuGrpImpl::get_MenuTableFL_UPD_FORM_INTERF_MAINMENU(void)
{
return Object->MenuTableFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * MenuTableFL_UPD_FORM_INTERF_MAINMENU)
{
Object->MenuTableFL_UPD_FORM_INTERF_MAINMENU=MenuTableFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfMainMenuGrpImpl::get_MenuTableFL_NEW_DOC_INTERF_MAINMENU(void)
{
return Object->MenuTableFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * MenuTableFL_NEW_DOC_INTERF_MAINMENU)
{
Object->MenuTableFL_NEW_DOC_INTERF_MAINMENU=MenuTableFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuGrpImpl::get_MenuTableIDEL_INTERF_MAINMENU(void)
{
return Object->MenuTableIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableIDEL_INTERF_MAINMENU(TFIBLargeIntField * MenuTableIDEL_INTERF_MAINMENU)
{
Object->MenuTableIDEL_INTERF_MAINMENU=MenuTableIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfMainMenuGrpImpl::get_MenuTableFL_OPEN_EL_INTERF_MAINMENU(void)
{
return Object->MenuTableFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * MenuTableFL_OPEN_EL_INTERF_MAINMENU)
{
Object->MenuTableFL_OPEN_EL_INTERF_MAINMENU=MenuTableFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuGrpImpl::get_MenuTableTYPE_IDEL_INTERF_MAINMENU(void)
{
return Object->MenuTableTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_MenuTableTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * MenuTableTYPE_IDEL_INTERF_MAINMENU)
{
Object->MenuTableTYPE_IDEL_INTERF_MAINMENU=MenuTableTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
__int64 TDMInterfMainMenuGrpImpl::get_IdGrpUser(void)
{
return Object->IdGrpUser;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_IdGrpUser(__int64 IdGrpUser)
{
Object->IdGrpUser=IdGrpUser;
}
//---------------------------------------------------------------
int TDMInterfMainMenuGrpImpl::get_NumApplication(void)
{
return Object->NumApplication;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::set_NumApplication(int NumApplication)
{
Object->NumApplication=NumApplication;
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::OpenTable(int num_application, __int64 id_grp_user)
{
return Object->OpenTable(num_application,id_grp_user);
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::Table_First(void)
{
return Object->Table_First();
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::Table_Next(void)
{
return Object->Table_Next();
}
//---------------------------------------------------------------
int TDMInterfMainMenuGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::NewElement(int num_application,__int64 id_grp_user, __int64 id_grp)
{
return Object->NewElement(num_application,id_grp_user,id_grp);
}
//---------------------------------------------------------------
bool TDMInterfMainMenuGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMInterfMainMenuGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::Element_Edit(void)
{
return Object->Element_Edit();
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::Element_Post(void)
{
return Object->Element_Post();
}
//---------------------------------------------------------------
void TDMInterfMainMenuGrpImpl::OpenMenuTable(int num_application, __int64 id_grp_user)
{
return Object->OpenMenuTable(num_application, id_grp_user);
}
//---------------------------------------------------------------
