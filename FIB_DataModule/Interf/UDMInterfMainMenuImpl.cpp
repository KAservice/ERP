#include "vcl.h"
#pragma hdrstop


#include "UDMInterfMainMenuImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMInterfMainMenuImpl::TDMInterfMainMenuImpl()           
{                                            
Object=new TDMInterfMainMenu(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMInterfMainMenuImpl::~TDMInterfMainMenuImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMInterfMainMenuImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMInterfMainMenu)                        
   {                                                                     
   *ppv=static_cast<IDMInterfMainMenu*> (this);                                
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
int TDMInterfMainMenuImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMInterfMainMenuImpl::kanRelease(void)                                  
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
int  TDMInterfMainMenuImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMInterfMainMenuImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMInterfMainMenuImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMInterfMainMenuImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMInterfMainMenuImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMInterfMainMenu
TDataSource * TDMInterfMainMenuImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMInterfMainMenuImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMInterfMainMenuImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMInterfMainMenuImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMInterfMainMenuImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuImpl::get_TableID_INTERF_MAINMENU(void)
{
return Object->TableID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableID_INTERF_MAINMENU(TFIBLargeIntField * TableID_INTERF_MAINMENU)
{
Object->TableID_INTERF_MAINMENU=TableID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuImpl::get_TableIDBASE_INTERF_MAINMENU(void)
{
return Object->TableIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableIDBASE_INTERF_MAINMENU(TFIBLargeIntField * TableIDBASE_INTERF_MAINMENU)
{
Object->TableIDBASE_INTERF_MAINMENU=TableIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuImpl::get_TableIDGRP_INTERF_MAINMENU(void)
{
return Object->TableIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableIDGRP_INTERF_MAINMENU(TFIBLargeIntField * TableIDGRP_INTERF_MAINMENU)
{
Object->TableIDGRP_INTERF_MAINMENU=TableIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_TableNAME_INTERF_MAINMENU(void)
{
return Object->TableNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableNAME_INTERF_MAINMENU(TFIBWideStringField * TableNAME_INTERF_MAINMENU)
{
Object->TableNAME_INTERF_MAINMENU=TableNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuImpl::get_TableMODUL_INTERF_MAINMENU(void)
{
return Object->TableMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableMODUL_INTERF_MAINMENU(TFIBIntegerField * TableMODUL_INTERF_MAINMENU)
{
Object->TableMODUL_INTERF_MAINMENU=TableMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuImpl::get_TableIDGRPUSER_INTERF_MAINMENU(void)
{
return Object->TableIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * TableIDGRPUSER_INTERF_MAINMENU)
{
Object->TableIDGRPUSER_INTERF_MAINMENU=TableIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuImpl::get_TableAPPLICATION_INTERF_MAINMENU(void)
{
return Object->TableAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * TableAPPLICATION_INTERF_MAINMENU)
{
Object->TableAPPLICATION_INTERF_MAINMENU=TableAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_TableSHORTCUT_INTERF_MAINMENU(void)
{
return Object->TableSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * TableSHORTCUT_INTERF_MAINMENU)
{
Object->TableSHORTCUT_INTERF_MAINMENU=TableSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuImpl::get_TableINDEX_INTERF_MAINMENU(void)
{
return Object->TableINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableINDEX_INTERF_MAINMENU(TFIBIntegerField * TableINDEX_INTERF_MAINMENU)
{
Object->TableINDEX_INTERF_MAINMENU=TableINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_TableNAME_SGRPUSER(void)
{
return Object->TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER)
{
Object->TableNAME_SGRPUSER=TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_TableNAME_PROGRAM_MODULE(void)
{
return Object->TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)
{
Object->TableNAME_PROGRAM_MODULE=TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_TablePROGID_PROGRAM_MODULE(void)
{
return Object->TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)
{
Object->TablePROGID_PROGRAM_MODULE=TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_TablePATCH_PROGRAM_MODULE(void)
{
return Object->TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)
{
Object->TablePATCH_PROGRAM_MODULE=TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TIntegerField * TDMInterfMainMenuImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuImpl::get_ElementID_INTERF_MAINMENU(void)
{
return Object->ElementID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementID_INTERF_MAINMENU(TFIBLargeIntField * ElementID_INTERF_MAINMENU)
{
Object->ElementID_INTERF_MAINMENU=ElementID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuImpl::get_ElementIDBASE_INTERF_MAINMENU(void)
{
return Object->ElementIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementIDBASE_INTERF_MAINMENU(TFIBLargeIntField * ElementIDBASE_INTERF_MAINMENU)
{
Object->ElementIDBASE_INTERF_MAINMENU=ElementIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuImpl::get_ElementIDGRP_INTERF_MAINMENU(void)
{
return Object->ElementIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementIDGRP_INTERF_MAINMENU(TFIBLargeIntField * ElementIDGRP_INTERF_MAINMENU)
{
Object->ElementIDGRP_INTERF_MAINMENU=ElementIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_ElementNAME_INTERF_MAINMENU(void)
{
return Object->ElementNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementNAME_INTERF_MAINMENU(TFIBWideStringField * ElementNAME_INTERF_MAINMENU)
{
Object->ElementNAME_INTERF_MAINMENU=ElementNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuImpl::get_ElementMODUL_INTERF_MAINMENU(void)
{
return Object->ElementMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementMODUL_INTERF_MAINMENU(TFIBIntegerField * ElementMODUL_INTERF_MAINMENU)
{
Object->ElementMODUL_INTERF_MAINMENU=ElementMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuImpl::get_ElementIDGRPUSER_INTERF_MAINMENU(void)
{
return Object->ElementIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * ElementIDGRPUSER_INTERF_MAINMENU)
{
Object->ElementIDGRPUSER_INTERF_MAINMENU=ElementIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuImpl::get_ElementAPPLICATION_INTERF_MAINMENU(void)
{
return Object->ElementAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * ElementAPPLICATION_INTERF_MAINMENU)
{
Object->ElementAPPLICATION_INTERF_MAINMENU=ElementAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_ElementSHORTCUT_INTERF_MAINMENU(void)
{
return Object->ElementSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * ElementSHORTCUT_INTERF_MAINMENU)
{
Object->ElementSHORTCUT_INTERF_MAINMENU=ElementSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuImpl::get_ElementINDEX_INTERF_MAINMENU(void)
{
return Object->ElementINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementINDEX_INTERF_MAINMENU(TFIBIntegerField * ElementINDEX_INTERF_MAINMENU)
{
Object->ElementINDEX_INTERF_MAINMENU=ElementINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_ElementNAME_PROGRAM_MODULE(void)
{
return Object->ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)
{
Object->ElementNAME_PROGRAM_MODULE=ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_ElementPROGID_PROGRAM_MODULE(void)
{
return Object->ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)
{
Object->ElementPROGID_PROGRAM_MODULE=ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_ElementPATCH_PROGRAM_MODULE(void)
{
return Object->ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)
{
Object->ElementPATCH_PROGRAM_MODULE=ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfMainMenuImpl::get_TableFL_UPD_FORM_INTERF_MAINMENU(void)
{
return Object->TableFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * TableFL_UPD_FORM_INTERF_MAINMENU)
{
Object->TableFL_UPD_FORM_INTERF_MAINMENU=TableFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfMainMenuImpl::get_TableFL_NEW_DOC_INTERF_MAINMENU(void)
{
return Object->TableFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * TableFL_NEW_DOC_INTERF_MAINMENU)
{
Object->TableFL_NEW_DOC_INTERF_MAINMENU=TableFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuImpl::get_TableIDEL_INTERF_MAINMENU(void)
{
return Object->TableIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableIDEL_INTERF_MAINMENU(TFIBLargeIntField * TableIDEL_INTERF_MAINMENU)
{
Object->TableIDEL_INTERF_MAINMENU=TableIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfMainMenuImpl::get_TableFL_OPEN_EL_INTERF_MAINMENU(void)
{
return Object->TableFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * TableFL_OPEN_EL_INTERF_MAINMENU)
{
Object->TableFL_OPEN_EL_INTERF_MAINMENU=TableFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfMainMenuImpl::get_ElementFL_UPD_FORM_INTERF_MAINMENU(void)
{
return Object->ElementFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_UPD_FORM_INTERF_MAINMENU)
{
Object->ElementFL_UPD_FORM_INTERF_MAINMENU=ElementFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfMainMenuImpl::get_ElementFL_NEW_DOC_INTERF_MAINMENU(void)
{
return Object->ElementFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_NEW_DOC_INTERF_MAINMENU)
{
Object->ElementFL_NEW_DOC_INTERF_MAINMENU=ElementFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuImpl::get_ElementIDEL_INTERF_MAINMENU(void)
{
return Object->ElementIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementIDEL_INTERF_MAINMENU(TFIBLargeIntField * ElementIDEL_INTERF_MAINMENU)
{
Object->ElementIDEL_INTERF_MAINMENU=ElementIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfMainMenuImpl::get_ElementFL_OPEN_EL_INTERF_MAINMENU(void)
{
return Object->ElementFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_OPEN_EL_INTERF_MAINMENU)
{
Object->ElementFL_OPEN_EL_INTERF_MAINMENU=ElementFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_TableGUIDMOD_INTERF_MAINMENU(void)
{
return Object->TableGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * TableGUIDMOD_INTERF_MAINMENU)
{
Object->TableGUIDMOD_INTERF_MAINMENU=TableGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuImpl::get_TableTYPE_IDEL_INTERF_MAINMENU(void)
{
return Object->TableTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * TableTYPE_IDEL_INTERF_MAINMENU)
{
Object->TableTYPE_IDEL_INTERF_MAINMENU=TableTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuImpl::get_ElementGUIDMOD_INTERF_MAINMENU(void)
{
return Object->ElementGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * ElementGUIDMOD_INTERF_MAINMENU)
{
Object->ElementGUIDMOD_INTERF_MAINMENU=ElementGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuImpl::get_ElementTYPE_IDEL_INTERF_MAINMENU(void)
{
return Object->ElementTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * ElementTYPE_IDEL_INTERF_MAINMENU)
{
Object->ElementTYPE_IDEL_INTERF_MAINMENU=ElementTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuImpl::get_TableIDMOD_INTERF_MAINMENU(void)
{
return Object->TableIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableIDMOD_INTERF_MAINMENU(TFIBLargeIntField * TableIDMOD_INTERF_MAINMENU)
{
Object->TableIDMOD_INTERF_MAINMENU=TableIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuImpl::get_TableTYPEMOD_PROGRAM_MODULE(void)
{
return Object->TableTYPEMOD_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_TableTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * TableTYPEMOD_PROGRAM_MODULE)
{
Object->TableTYPEMOD_PROGRAM_MODULE=TableTYPEMOD_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuImpl::get_ElementIDMOD_INTERF_MAINMENU(void)
{
return Object->ElementIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_ElementIDMOD_INTERF_MAINMENU(TFIBLargeIntField * ElementIDMOD_INTERF_MAINMENU)
{
Object->ElementIDMOD_INTERF_MAINMENU=ElementIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
int TDMInterfMainMenuImpl::get_NumApplication(void)
{
return Object->NumApplication;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_NumApplication(int NumApplication)
{
Object->NumApplication=NumApplication;
}
//---------------------------------------------------------------
__int64 TDMInterfMainMenuImpl::get_IdGrpUser(void)
{
return Object->IdGrpUser;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_IdGrpUser(__int64 IdGrpUser)
{
Object->IdGrpUser=IdGrpUser;
}
//---------------------------------------------------------------
__int64 TDMInterfMainMenuImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMInterfMainMenuImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::OpenTable(int num_application, __int64 id_grp_user, __int64 id_grp, bool all)
{
return Object->OpenTable(num_application,id_grp_user,id_grp,  all);
}
//---------------------------------------------------------------
bool TDMInterfMainMenuImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool TDMInterfMainMenuImpl::Table_Delete(void)
{
return Object->Table_Delete();
}
//---------------------------------------------------------------
bool TDMInterfMainMenuImpl::Table_AppendString(int num_application, __int64 id_grp_user, __int64 id_grp)
{
return Object->Table_AppendString(num_application,id_grp_user,id_grp);
}
//---------------------------------------------------------------
bool TDMInterfMainMenuImpl::NewElement(int num_application, __int64 id_grp_user, __int64 id_grp)
{
return Object->NewElement(num_application,id_grp_user,id_grp);
}
//---------------------------------------------------------------
bool TDMInterfMainMenuImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMInterfMainMenuImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement( id);
}
//---------------------------------------------------------------
bool TDMInterfMainMenuImpl::InsertElement(int num_application, __int64 id_grp_user, __int64 id_grp)
{
return Object->InsertElement(num_application, id_grp_user, id_grp);
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::Element_Edit(void)
{
return Object->Element_Edit();
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::Element_Post(void)
{
return Object->Element_Post();
}
//---------------------------------------------------------------
bool TDMInterfMainMenuImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMInterfMainMenuImpl::ChancheGrp(__int64 id_new_grp)
{
return Object->ChancheGrp(id_new_grp);
}
//---------------------------------------------------------------
