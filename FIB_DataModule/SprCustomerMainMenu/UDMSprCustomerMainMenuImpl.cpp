#include "vcl.h"
#pragma hdrstop


#include "UDMSprCustomerMainMenuImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprCustomerMainMenuImpl::TDMSprCustomerMainMenuImpl()           
{                                            
Object=new TDMSprCustomerMainMenu(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprCustomerMainMenuImpl::~TDMSprCustomerMainMenuImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprCustomerMainMenuImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprCustomerMainMenu)                        
   {                                                                     
   *ppv=static_cast<IDMSprCustomerMainMenu*> (this);                                
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
int TDMSprCustomerMainMenuImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprCustomerMainMenuImpl::kanRelease(void)                                  
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
int  TDMSprCustomerMainMenuImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprCustomerMainMenuImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerMainMenuImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprCustomerMainMenuImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerMainMenuImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprCustomerMainMenu
TDataSource * TDMSprCustomerMainMenuImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerMainMenuImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerMainMenuImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerMainMenuImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerMainMenuImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_TableID_CUST_MAINMENU(void)
{
return Object->TableID_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableID_CUST_MAINMENU(TFIBLargeIntField * TableID_CUST_MAINMENU)
{
Object->TableID_CUST_MAINMENU=TableID_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_TableIDBASE_CUST_MAINMENU(void)
{
return Object->TableIDBASE_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableIDBASE_CUST_MAINMENU(TFIBLargeIntField * TableIDBASE_CUST_MAINMENU)
{
Object->TableIDBASE_CUST_MAINMENU=TableIDBASE_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_TableGID_CUST_MAINMENU(void)
{
return Object->TableGID_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableGID_CUST_MAINMENU(TFIBWideStringField * TableGID_CUST_MAINMENU)
{
Object->TableGID_CUST_MAINMENU=TableGID_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_TableIDACCOUNT_CUST_MAINMENU(void)
{
return Object->TableIDACCOUNT_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableIDACCOUNT_CUST_MAINMENU(TFIBLargeIntField * TableIDACCOUNT_CUST_MAINMENU)
{
Object->TableIDACCOUNT_CUST_MAINMENU=TableIDACCOUNT_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_TableIDGRPUSER_CUST_MAINMENU(void)
{
return Object->TableIDGRPUSER_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableIDGRPUSER_CUST_MAINMENU(TFIBLargeIntField * TableIDGRPUSER_CUST_MAINMENU)
{
Object->TableIDGRPUSER_CUST_MAINMENU=TableIDGRPUSER_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_TableIDGRP_CUST_MAINMENU(void)
{
return Object->TableIDGRP_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableIDGRP_CUST_MAINMENU(TFIBLargeIntField * TableIDGRP_CUST_MAINMENU)
{
Object->TableIDGRP_CUST_MAINMENU=TableIDGRP_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_TableNAME_CUST_MAINMENU(void)
{
return Object->TableNAME_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableNAME_CUST_MAINMENU(TFIBWideStringField * TableNAME_CUST_MAINMENU)
{
Object->TableNAME_CUST_MAINMENU=TableNAME_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprCustomerMainMenuImpl::get_TableINDEX_CUST_MAINMENU(void)
{
return Object->TableINDEX_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableINDEX_CUST_MAINMENU(TFIBIntegerField * TableINDEX_CUST_MAINMENU)
{
Object->TableINDEX_CUST_MAINMENU=TableINDEX_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_TableGUID_CUST_MAINMENU(void)
{
return Object->TableGUID_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableGUID_CUST_MAINMENU(TFIBWideStringField * TableGUID_CUST_MAINMENU)
{
Object->TableGUID_CUST_MAINMENU=TableGUID_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_TableGUIDMOD_CUST_MAINMENU(void)
{
return Object->TableGUIDMOD_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableGUIDMOD_CUST_MAINMENU(TFIBWideStringField * TableGUIDMOD_CUST_MAINMENU)
{
Object->TableGUIDMOD_CUST_MAINMENU=TableGUIDMOD_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_TableIDMOD_CUST_MAINMENU(void)
{
return Object->TableIDMOD_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableIDMOD_CUST_MAINMENU(TFIBLargeIntField * TableIDMOD_CUST_MAINMENU)
{
Object->TableIDMOD_CUST_MAINMENU=TableIDMOD_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprCustomerMainMenuImpl::get_TableFL_OPEN_EL_CUST_MAINMENU(void)
{
return Object->TableFL_OPEN_EL_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableFL_OPEN_EL_CUST_MAINMENU(TFIBSmallIntField * TableFL_OPEN_EL_CUST_MAINMENU)
{
Object->TableFL_OPEN_EL_CUST_MAINMENU=TableFL_OPEN_EL_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_TableIDEL_CUST_MAINMENU(void)
{
return Object->TableIDEL_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableIDEL_CUST_MAINMENU(TFIBLargeIntField * TableIDEL_CUST_MAINMENU)
{
Object->TableIDEL_CUST_MAINMENU=TableIDEL_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_TableNAME_PROGRAM_MODULE(void)
{
return Object->TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)
{
Object->TableNAME_PROGRAM_MODULE=TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_TablePROGID_PROGRAM_MODULE(void)
{
return Object->TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)
{
Object->TablePROGID_PROGRAM_MODULE=TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_TablePATCH_PROGRAM_MODULE(void)
{
return Object->TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)
{
Object->TablePATCH_PROGRAM_MODULE=TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprCustomerMainMenuImpl::get_TableTYPEMOD_PROGRAM_MODULE(void)
{
return Object->TableTYPEMOD_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_TableTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * TableTYPEMOD_PROGRAM_MODULE)
{
Object->TableTYPEMOD_PROGRAM_MODULE=TableTYPEMOD_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_ElementID_CUST_MAINMENU(void)
{
return Object->ElementID_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementID_CUST_MAINMENU(TFIBLargeIntField * ElementID_CUST_MAINMENU)
{
Object->ElementID_CUST_MAINMENU=ElementID_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_ElementIDBASE_CUST_MAINMENU(void)
{
return Object->ElementIDBASE_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementIDBASE_CUST_MAINMENU(TFIBLargeIntField * ElementIDBASE_CUST_MAINMENU)
{
Object->ElementIDBASE_CUST_MAINMENU=ElementIDBASE_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_ElementGID_CUST_MAINMENU(void)
{
return Object->ElementGID_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementGID_CUST_MAINMENU(TFIBWideStringField * ElementGID_CUST_MAINMENU)
{
Object->ElementGID_CUST_MAINMENU=ElementGID_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_ElementIDACCOUNT_CUST_MAINMENU(void)
{
return Object->ElementIDACCOUNT_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementIDACCOUNT_CUST_MAINMENU(TFIBLargeIntField * ElementIDACCOUNT_CUST_MAINMENU)
{
Object->ElementIDACCOUNT_CUST_MAINMENU=ElementIDACCOUNT_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_ElementIDGRPUSER_CUST_MAINMENU(void)
{
return Object->ElementIDGRPUSER_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementIDGRPUSER_CUST_MAINMENU(TFIBLargeIntField * ElementIDGRPUSER_CUST_MAINMENU)
{
Object->ElementIDGRPUSER_CUST_MAINMENU=ElementIDGRPUSER_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_ElementIDGRP_CUST_MAINMENU(void)
{
return Object->ElementIDGRP_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementIDGRP_CUST_MAINMENU(TFIBLargeIntField * ElementIDGRP_CUST_MAINMENU)
{
Object->ElementIDGRP_CUST_MAINMENU=ElementIDGRP_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_ElementNAME_CUST_MAINMENU(void)
{
return Object->ElementNAME_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementNAME_CUST_MAINMENU(TFIBWideStringField * ElementNAME_CUST_MAINMENU)
{
Object->ElementNAME_CUST_MAINMENU=ElementNAME_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprCustomerMainMenuImpl::get_ElementINDEX_CUST_MAINMENU(void)
{
return Object->ElementINDEX_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementINDEX_CUST_MAINMENU(TFIBIntegerField * ElementINDEX_CUST_MAINMENU)
{
Object->ElementINDEX_CUST_MAINMENU=ElementINDEX_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_ElementGUID_CUST_MAINMENU(void)
{
return Object->ElementGUID_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementGUID_CUST_MAINMENU(TFIBWideStringField * ElementGUID_CUST_MAINMENU)
{
Object->ElementGUID_CUST_MAINMENU=ElementGUID_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_ElementGUIDMOD_CUST_MAINMENU(void)
{
return Object->ElementGUIDMOD_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementGUIDMOD_CUST_MAINMENU(TFIBWideStringField * ElementGUIDMOD_CUST_MAINMENU)
{
Object->ElementGUIDMOD_CUST_MAINMENU=ElementGUIDMOD_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_ElementIDMOD_CUST_MAINMENU(void)
{
return Object->ElementIDMOD_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementIDMOD_CUST_MAINMENU(TFIBLargeIntField * ElementIDMOD_CUST_MAINMENU)
{
Object->ElementIDMOD_CUST_MAINMENU=ElementIDMOD_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprCustomerMainMenuImpl::get_ElementFL_OPEN_EL_CUST_MAINMENU(void)
{
return Object->ElementFL_OPEN_EL_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementFL_OPEN_EL_CUST_MAINMENU(TFIBSmallIntField * ElementFL_OPEN_EL_CUST_MAINMENU)
{
Object->ElementFL_OPEN_EL_CUST_MAINMENU=ElementFL_OPEN_EL_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerMainMenuImpl::get_ElementIDEL_CUST_MAINMENU(void)
{
return Object->ElementIDEL_CUST_MAINMENU;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementIDEL_CUST_MAINMENU(TFIBLargeIntField * ElementIDEL_CUST_MAINMENU)
{
Object->ElementIDEL_CUST_MAINMENU=ElementIDEL_CUST_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_ElementNAME_PROGRAM_MODULE(void)
{
return Object->ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)
{
Object->ElementNAME_PROGRAM_MODULE=ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_ElementPROGID_PROGRAM_MODULE(void)
{
return Object->ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)
{
Object->ElementPROGID_PROGRAM_MODULE=ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerMainMenuImpl::get_ElementPATCH_PROGRAM_MODULE(void)
{
return Object->ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)
{
Object->ElementPATCH_PROGRAM_MODULE=ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerMainMenuImpl::get_IdAccount(void)
{
return Object->IdAccount;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_IdAccount(__int64 IdAccount)
{
Object->IdAccount=IdAccount;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerMainMenuImpl::get_IdGrpUser(void)
{
return Object->IdGrpUser;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_IdGrpUser(__int64 IdGrpUser)
{
Object->IdGrpUser=IdGrpUser;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerMainMenuImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprCustomerMainMenuImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::OpenTable(__int64 id_account, __int64 id_grp_user, __int64 id_grp, bool all)
{
return Object->OpenTable(id_account,id_grp_user,id_grp,all);
}
//---------------------------------------------------------------
bool TDMSprCustomerMainMenuImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool TDMSprCustomerMainMenuImpl::Table_Delete(void)
{
return Object->Table_Delete();
}
//---------------------------------------------------------------
bool TDMSprCustomerMainMenuImpl::Table_AppendString(__int64 id_account, __int64 id_grp_user, __int64 id_grp)
{
return Object->Table_AppendString(id_account, id_grp_user,id_grp);
}
//---------------------------------------------------------------
bool TDMSprCustomerMainMenuImpl::NewElement(__int64 id_account, __int64 id_grp_user, __int64 id_grp)
{
return Object->NewElement(id_account,id_grp_user,  id_grp);
}
//---------------------------------------------------------------
bool TDMSprCustomerMainMenuImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprCustomerMainMenuImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement( id);
}
//---------------------------------------------------------------
bool TDMSprCustomerMainMenuImpl::InsertElement(__int64 id_account, __int64 id_grp_user, __int64 id_grp)
{
return Object->InsertElement(id_account, id_grp_user, id_grp);
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::Element_Edit(void)
{
return Object->Element_Edit();
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::Element_Post(void)
{
return Object->Element_Post();
}
//---------------------------------------------------------------
bool TDMSprCustomerMainMenuImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprCustomerMainMenuImpl::ChancheGrp(__int64 id_new_grp)
{
return Object->ChancheGrp(id_new_grp);
}
//---------------------------------------------------------------
