#include "vcl.h"
#pragma hdrstop


#include "UFormaSpiskaInterfMainMenuImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaSpiskaInterfMainMenuImpl::TFormaSpiskaInterfMainMenuImpl()           
{                                            
Object=new TFormaSpiskaInterfMainMenu(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaSpiskaInterfMainMenuImpl::~TFormaSpiskaInterfMainMenuImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaSpiskaInterfMainMenu)                        
   {                                                                     
   *ppv=static_cast<IFormaSpiskaInterfMainMenu*> (this);                                
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
int TFormaSpiskaInterfMainMenuImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuImpl::kanRelease(void)                                  
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
int  TFormaSpiskaInterfMainMenuImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaSpiskaInterfMainMenuImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaSpiskaInterfMainMenuImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IFormaSpiskaInterfMainMenu
TDataSource * TFormaSpiskaInterfMainMenuImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TFormaSpiskaInterfMainMenuImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TFormaSpiskaInterfMainMenuImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TFormaSpiskaInterfMainMenuImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TFormaSpiskaInterfMainMenuImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuImpl::get_TableID_INTERF_MAINMENU(void)
{
return Object->TableID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableID_INTERF_MAINMENU(TFIBLargeIntField * TableID_INTERF_MAINMENU)
{
Object->TableID_INTERF_MAINMENU=TableID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuImpl::get_TableIDBASE_INTERF_MAINMENU(void)
{
return Object->TableIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableIDBASE_INTERF_MAINMENU(TFIBLargeIntField * TableIDBASE_INTERF_MAINMENU)
{
Object->TableIDBASE_INTERF_MAINMENU=TableIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuImpl::get_TableIDGRP_INTERF_MAINMENU(void)
{
return Object->TableIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableIDGRP_INTERF_MAINMENU(TFIBLargeIntField * TableIDGRP_INTERF_MAINMENU)
{
Object->TableIDGRP_INTERF_MAINMENU=TableIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_TableNAME_INTERF_MAINMENU(void)
{
return Object->TableNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableNAME_INTERF_MAINMENU(TFIBWideStringField * TableNAME_INTERF_MAINMENU)
{
Object->TableNAME_INTERF_MAINMENU=TableNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuImpl::get_TableMODUL_INTERF_MAINMENU(void)
{
return Object->TableMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableMODUL_INTERF_MAINMENU(TFIBIntegerField * TableMODUL_INTERF_MAINMENU)
{
Object->TableMODUL_INTERF_MAINMENU=TableMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuImpl::get_TableIDGRPUSER_INTERF_MAINMENU(void)
{
return Object->TableIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * TableIDGRPUSER_INTERF_MAINMENU)
{
Object->TableIDGRPUSER_INTERF_MAINMENU=TableIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuImpl::get_TableAPPLICATION_INTERF_MAINMENU(void)
{
return Object->TableAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * TableAPPLICATION_INTERF_MAINMENU)
{
Object->TableAPPLICATION_INTERF_MAINMENU=TableAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_TableSHORTCUT_INTERF_MAINMENU(void)
{
return Object->TableSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * TableSHORTCUT_INTERF_MAINMENU)
{
Object->TableSHORTCUT_INTERF_MAINMENU=TableSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuImpl::get_TableINDEX_INTERF_MAINMENU(void)
{
return Object->TableINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableINDEX_INTERF_MAINMENU(TFIBIntegerField * TableINDEX_INTERF_MAINMENU)
{
Object->TableINDEX_INTERF_MAINMENU=TableINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_TableNAME_SGRPUSER(void)
{
return Object->TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER)
{
Object->TableNAME_SGRPUSER=TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_TableNAME_PROGRAM_MODULE(void)
{
return Object->TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)
{
Object->TableNAME_PROGRAM_MODULE=TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_TablePROGID_PROGRAM_MODULE(void)
{
return Object->TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)
{
Object->TablePROGID_PROGRAM_MODULE=TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_TablePATCH_PROGRAM_MODULE(void)
{
return Object->TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)
{
Object->TablePATCH_PROGRAM_MODULE=TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TIntegerField * TFormaSpiskaInterfMainMenuImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuImpl::get_ElementID_INTERF_MAINMENU(void)
{
return Object->ElementID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementID_INTERF_MAINMENU(TFIBLargeIntField * ElementID_INTERF_MAINMENU)
{
Object->ElementID_INTERF_MAINMENU=ElementID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuImpl::get_ElementIDBASE_INTERF_MAINMENU(void)
{
return Object->ElementIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementIDBASE_INTERF_MAINMENU(TFIBLargeIntField * ElementIDBASE_INTERF_MAINMENU)
{
Object->ElementIDBASE_INTERF_MAINMENU=ElementIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuImpl::get_ElementIDGRP_INTERF_MAINMENU(void)
{
return Object->ElementIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementIDGRP_INTERF_MAINMENU(TFIBLargeIntField * ElementIDGRP_INTERF_MAINMENU)
{
Object->ElementIDGRP_INTERF_MAINMENU=ElementIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_ElementNAME_INTERF_MAINMENU(void)
{
return Object->ElementNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementNAME_INTERF_MAINMENU(TFIBWideStringField * ElementNAME_INTERF_MAINMENU)
{
Object->ElementNAME_INTERF_MAINMENU=ElementNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuImpl::get_ElementMODUL_INTERF_MAINMENU(void)
{
return Object->ElementMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementMODUL_INTERF_MAINMENU(TFIBIntegerField * ElementMODUL_INTERF_MAINMENU)
{
Object->ElementMODUL_INTERF_MAINMENU=ElementMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuImpl::get_ElementIDGRPUSER_INTERF_MAINMENU(void)
{
return Object->ElementIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * ElementIDGRPUSER_INTERF_MAINMENU)
{
Object->ElementIDGRPUSER_INTERF_MAINMENU=ElementIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuImpl::get_ElementAPPLICATION_INTERF_MAINMENU(void)
{
return Object->ElementAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * ElementAPPLICATION_INTERF_MAINMENU)
{
Object->ElementAPPLICATION_INTERF_MAINMENU=ElementAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_ElementSHORTCUT_INTERF_MAINMENU(void)
{
return Object->ElementSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * ElementSHORTCUT_INTERF_MAINMENU)
{
Object->ElementSHORTCUT_INTERF_MAINMENU=ElementSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuImpl::get_ElementINDEX_INTERF_MAINMENU(void)
{
return Object->ElementINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementINDEX_INTERF_MAINMENU(TFIBIntegerField * ElementINDEX_INTERF_MAINMENU)
{
Object->ElementINDEX_INTERF_MAINMENU=ElementINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_ElementNAME_PROGRAM_MODULE(void)
{
return Object->ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)
{
Object->ElementNAME_PROGRAM_MODULE=ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_ElementPROGID_PROGRAM_MODULE(void)
{
return Object->ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)
{
Object->ElementPROGID_PROGRAM_MODULE=ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_ElementPATCH_PROGRAM_MODULE(void)
{
return Object->ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)
{
Object->ElementPATCH_PROGRAM_MODULE=ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaInterfMainMenuImpl::get_TableFL_UPD_FORM_INTERF_MAINMENU(void)
{
return Object->TableFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * TableFL_UPD_FORM_INTERF_MAINMENU)
{
Object->TableFL_UPD_FORM_INTERF_MAINMENU=TableFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaInterfMainMenuImpl::get_TableFL_NEW_DOC_INTERF_MAINMENU(void)
{
return Object->TableFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * TableFL_NEW_DOC_INTERF_MAINMENU)
{
Object->TableFL_NEW_DOC_INTERF_MAINMENU=TableFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuImpl::get_TableIDEL_INTERF_MAINMENU(void)
{
return Object->TableIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableIDEL_INTERF_MAINMENU(TFIBLargeIntField * TableIDEL_INTERF_MAINMENU)
{
Object->TableIDEL_INTERF_MAINMENU=TableIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaInterfMainMenuImpl::get_TableFL_OPEN_EL_INTERF_MAINMENU(void)
{
return Object->TableFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * TableFL_OPEN_EL_INTERF_MAINMENU)
{
Object->TableFL_OPEN_EL_INTERF_MAINMENU=TableFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaInterfMainMenuImpl::get_ElementFL_UPD_FORM_INTERF_MAINMENU(void)
{
return Object->ElementFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_UPD_FORM_INTERF_MAINMENU)
{
Object->ElementFL_UPD_FORM_INTERF_MAINMENU=ElementFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaInterfMainMenuImpl::get_ElementFL_NEW_DOC_INTERF_MAINMENU(void)
{
return Object->ElementFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_NEW_DOC_INTERF_MAINMENU)
{
Object->ElementFL_NEW_DOC_INTERF_MAINMENU=ElementFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuImpl::get_ElementIDEL_INTERF_MAINMENU(void)
{
return Object->ElementIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementIDEL_INTERF_MAINMENU(TFIBLargeIntField * ElementIDEL_INTERF_MAINMENU)
{
Object->ElementIDEL_INTERF_MAINMENU=ElementIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaInterfMainMenuImpl::get_ElementFL_OPEN_EL_INTERF_MAINMENU(void)
{
return Object->ElementFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_OPEN_EL_INTERF_MAINMENU)
{
Object->ElementFL_OPEN_EL_INTERF_MAINMENU=ElementFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_TableGUIDMOD_INTERF_MAINMENU(void)
{
return Object->TableGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * TableGUIDMOD_INTERF_MAINMENU)
{
Object->TableGUIDMOD_INTERF_MAINMENU=TableGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuImpl::get_TableTYPE_IDEL_INTERF_MAINMENU(void)
{
return Object->TableTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_TableTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * TableTYPE_IDEL_INTERF_MAINMENU)
{
Object->TableTYPE_IDEL_INTERF_MAINMENU=TableTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuImpl::get_ElementGUIDMOD_INTERF_MAINMENU(void)
{
return Object->ElementGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * ElementGUIDMOD_INTERF_MAINMENU)
{
Object->ElementGUIDMOD_INTERF_MAINMENU=ElementGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuImpl::get_ElementTYPE_IDEL_INTERF_MAINMENU(void)
{
return Object->ElementTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_ElementTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * ElementTYPE_IDEL_INTERF_MAINMENU)
{
Object->ElementTYPE_IDEL_INTERF_MAINMENU=ElementTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuImpl::get_NumApplication(void)
{
return Object->NumApplication;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_NumApplication(int NumApplication)
{
Object->NumApplication=NumApplication;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaInterfMainMenuImpl::get_IdGrpUser(void)
{
return Object->IdGrpUser;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_IdGrpUser(__int64 IdGrpUser)
{
Object->IdGrpUser=IdGrpUser;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaInterfMainMenuImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::OpenTable(int num_application, __int64 id_grp_user, __int64 id_grp, bool all)
{
return Object->OpenTable(int num_application, __int64 id_grp_user, __int64 id_grp, bool all);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuImpl::Table_Delete(void)
{
return Object->Table_Delete(void);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuImpl::Table_AppendString(int num_application, __int64 id_grp_user, __int64 id_grp)
{
return Object->Table_AppendString(int num_application, __int64 id_grp_user, __int64 id_grp);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuImpl::NewElement(int num_application, __int64 id_grp_user, __int64 id_grp)
{
return Object->NewElement(int num_application, __int64 id_grp_user, __int64 id_grp);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuImpl::OpenElement(__int64 id)
{
return Object->OpenElement(__int64 id);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(__int64 id);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuImpl::InsertElement(int num_application, __int64 id_grp_user, __int64 id_grp)
{
return Object->InsertElement(int num_application, __int64 id_grp_user, __int64 id_grp);
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::Element_Edit(void)
{
return Object->Element_Edit(void);
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::Element_Post(void)
{
return Object->Element_Post(void);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuImpl::SaveElement(void)
{
return Object->SaveElement(void);
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuImpl::ChancheGrp(__int64 id_new_grp)
{
return Object->ChancheGrp(__int64 id_new_grp);
}
//---------------------------------------------------------------
