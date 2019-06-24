#include "vcl.h"
#pragma hdrstop


#include "UFormaSpiskaInterfMainMenuParImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaSpiskaInterfMainMenuParImpl::TFormaSpiskaInterfMainMenuParImpl()           
{                                            
Object=new TFormaSpiskaInterfMainMenuPar(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaSpiskaInterfMainMenuParImpl::~TFormaSpiskaInterfMainMenuParImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuParImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaSpiskaInterfMainMenuPar)                        
   {                                                                     
   *ppv=static_cast<IFormaSpiskaInterfMainMenuPar*> (this);                                
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
int TFormaSpiskaInterfMainMenuParImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuParImpl::kanRelease(void)                                  
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
int  TFormaSpiskaInterfMainMenuParImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaSpiskaInterfMainMenuParImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuParImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaSpiskaInterfMainMenuParImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuParImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IFormaSpiskaInterfMainMenuPar
TDataSource * TFormaSpiskaInterfMainMenuParImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TFormaSpiskaInterfMainMenuParImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TFormaSpiskaInterfMainMenuParImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TFormaSpiskaInterfMainMenuParImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TFormaSpiskaInterfMainMenuParImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuParImpl::get_TableID_INTERF_MAINMENU(void)
{
return Object->TableID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableID_INTERF_MAINMENU(TFIBLargeIntField * TableID_INTERF_MAINMENU)
{
Object->TableID_INTERF_MAINMENU=TableID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuParImpl::get_TableIDBASE_INTERF_MAINMENU(void)
{
return Object->TableIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableIDBASE_INTERF_MAINMENU(TFIBLargeIntField * TableIDBASE_INTERF_MAINMENU)
{
Object->TableIDBASE_INTERF_MAINMENU=TableIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuParImpl::get_TableIDGRP_INTERF_MAINMENU(void)
{
return Object->TableIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableIDGRP_INTERF_MAINMENU(TFIBLargeIntField * TableIDGRP_INTERF_MAINMENU)
{
Object->TableIDGRP_INTERF_MAINMENU=TableIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_TableNAME_INTERF_MAINMENU(void)
{
return Object->TableNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableNAME_INTERF_MAINMENU(TFIBWideStringField * TableNAME_INTERF_MAINMENU)
{
Object->TableNAME_INTERF_MAINMENU=TableNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuParImpl::get_TableMODUL_INTERF_MAINMENU(void)
{
return Object->TableMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableMODUL_INTERF_MAINMENU(TFIBIntegerField * TableMODUL_INTERF_MAINMENU)
{
Object->TableMODUL_INTERF_MAINMENU=TableMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuParImpl::get_TableIDGRPUSER_INTERF_MAINMENU(void)
{
return Object->TableIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * TableIDGRPUSER_INTERF_MAINMENU)
{
Object->TableIDGRPUSER_INTERF_MAINMENU=TableIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuParImpl::get_TableAPPLICATION_INTERF_MAINMENU(void)
{
return Object->TableAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * TableAPPLICATION_INTERF_MAINMENU)
{
Object->TableAPPLICATION_INTERF_MAINMENU=TableAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_TableSHORTCUT_INTERF_MAINMENU(void)
{
return Object->TableSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * TableSHORTCUT_INTERF_MAINMENU)
{
Object->TableSHORTCUT_INTERF_MAINMENU=TableSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuParImpl::get_TableINDEX_INTERF_MAINMENU(void)
{
return Object->TableINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableINDEX_INTERF_MAINMENU(TFIBIntegerField * TableINDEX_INTERF_MAINMENU)
{
Object->TableINDEX_INTERF_MAINMENU=TableINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_TableNAME_SGRPUSER(void)
{
return Object->TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER)
{
Object->TableNAME_SGRPUSER=TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_TableNAME_PROGRAM_MODULE(void)
{
return Object->TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)
{
Object->TableNAME_PROGRAM_MODULE=TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_TablePROGID_PROGRAM_MODULE(void)
{
return Object->TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)
{
Object->TablePROGID_PROGRAM_MODULE=TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_TablePATCH_PROGRAM_MODULE(void)
{
return Object->TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)
{
Object->TablePATCH_PROGRAM_MODULE=TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TIntegerField * TFormaSpiskaInterfMainMenuParImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuParImpl::get_ElementID_INTERF_MAINMENU(void)
{
return Object->ElementID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementID_INTERF_MAINMENU(TFIBLargeIntField * ElementID_INTERF_MAINMENU)
{
Object->ElementID_INTERF_MAINMENU=ElementID_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuParImpl::get_ElementIDBASE_INTERF_MAINMENU(void)
{
return Object->ElementIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementIDBASE_INTERF_MAINMENU(TFIBLargeIntField * ElementIDBASE_INTERF_MAINMENU)
{
Object->ElementIDBASE_INTERF_MAINMENU=ElementIDBASE_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuParImpl::get_ElementIDGRP_INTERF_MAINMENU(void)
{
return Object->ElementIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementIDGRP_INTERF_MAINMENU(TFIBLargeIntField * ElementIDGRP_INTERF_MAINMENU)
{
Object->ElementIDGRP_INTERF_MAINMENU=ElementIDGRP_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_ElementNAME_INTERF_MAINMENU(void)
{
return Object->ElementNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementNAME_INTERF_MAINMENU(TFIBWideStringField * ElementNAME_INTERF_MAINMENU)
{
Object->ElementNAME_INTERF_MAINMENU=ElementNAME_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuParImpl::get_ElementMODUL_INTERF_MAINMENU(void)
{
return Object->ElementMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementMODUL_INTERF_MAINMENU(TFIBIntegerField * ElementMODUL_INTERF_MAINMENU)
{
Object->ElementMODUL_INTERF_MAINMENU=ElementMODUL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuParImpl::get_ElementIDGRPUSER_INTERF_MAINMENU(void)
{
return Object->ElementIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementIDGRPUSER_INTERF_MAINMENU(TFIBLargeIntField * ElementIDGRPUSER_INTERF_MAINMENU)
{
Object->ElementIDGRPUSER_INTERF_MAINMENU=ElementIDGRPUSER_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuParImpl::get_ElementAPPLICATION_INTERF_MAINMENU(void)
{
return Object->ElementAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementAPPLICATION_INTERF_MAINMENU(TFIBIntegerField * ElementAPPLICATION_INTERF_MAINMENU)
{
Object->ElementAPPLICATION_INTERF_MAINMENU=ElementAPPLICATION_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_ElementSHORTCUT_INTERF_MAINMENU(void)
{
return Object->ElementSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementSHORTCUT_INTERF_MAINMENU(TFIBWideStringField * ElementSHORTCUT_INTERF_MAINMENU)
{
Object->ElementSHORTCUT_INTERF_MAINMENU=ElementSHORTCUT_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuParImpl::get_ElementINDEX_INTERF_MAINMENU(void)
{
return Object->ElementINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementINDEX_INTERF_MAINMENU(TFIBIntegerField * ElementINDEX_INTERF_MAINMENU)
{
Object->ElementINDEX_INTERF_MAINMENU=ElementINDEX_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_ElementNAME_PROGRAM_MODULE(void)
{
return Object->ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)
{
Object->ElementNAME_PROGRAM_MODULE=ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_ElementPROGID_PROGRAM_MODULE(void)
{
return Object->ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)
{
Object->ElementPROGID_PROGRAM_MODULE=ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_ElementPATCH_PROGRAM_MODULE(void)
{
return Object->ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)
{
Object->ElementPATCH_PROGRAM_MODULE=ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaInterfMainMenuParImpl::get_TableFL_UPD_FORM_INTERF_MAINMENU(void)
{
return Object->TableFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * TableFL_UPD_FORM_INTERF_MAINMENU)
{
Object->TableFL_UPD_FORM_INTERF_MAINMENU=TableFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaInterfMainMenuParImpl::get_TableFL_NEW_DOC_INTERF_MAINMENU(void)
{
return Object->TableFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * TableFL_NEW_DOC_INTERF_MAINMENU)
{
Object->TableFL_NEW_DOC_INTERF_MAINMENU=TableFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuParImpl::get_TableIDEL_INTERF_MAINMENU(void)
{
return Object->TableIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableIDEL_INTERF_MAINMENU(TFIBLargeIntField * TableIDEL_INTERF_MAINMENU)
{
Object->TableIDEL_INTERF_MAINMENU=TableIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaInterfMainMenuParImpl::get_TableFL_OPEN_EL_INTERF_MAINMENU(void)
{
return Object->TableFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * TableFL_OPEN_EL_INTERF_MAINMENU)
{
Object->TableFL_OPEN_EL_INTERF_MAINMENU=TableFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaInterfMainMenuParImpl::get_ElementFL_UPD_FORM_INTERF_MAINMENU(void)
{
return Object->ElementFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementFL_UPD_FORM_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_UPD_FORM_INTERF_MAINMENU)
{
Object->ElementFL_UPD_FORM_INTERF_MAINMENU=ElementFL_UPD_FORM_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaInterfMainMenuParImpl::get_ElementFL_NEW_DOC_INTERF_MAINMENU(void)
{
return Object->ElementFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementFL_NEW_DOC_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_NEW_DOC_INTERF_MAINMENU)
{
Object->ElementFL_NEW_DOC_INTERF_MAINMENU=ElementFL_NEW_DOC_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBLargeIntField * TFormaSpiskaInterfMainMenuParImpl::get_ElementIDEL_INTERF_MAINMENU(void)
{
return Object->ElementIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementIDEL_INTERF_MAINMENU(TFIBLargeIntField * ElementIDEL_INTERF_MAINMENU)
{
Object->ElementIDEL_INTERF_MAINMENU=ElementIDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaInterfMainMenuParImpl::get_ElementFL_OPEN_EL_INTERF_MAINMENU(void)
{
return Object->ElementFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementFL_OPEN_EL_INTERF_MAINMENU(TFIBSmallIntField * ElementFL_OPEN_EL_INTERF_MAINMENU)
{
Object->ElementFL_OPEN_EL_INTERF_MAINMENU=ElementFL_OPEN_EL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_TableGUIDMOD_INTERF_MAINMENU(void)
{
return Object->TableGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * TableGUIDMOD_INTERF_MAINMENU)
{
Object->TableGUIDMOD_INTERF_MAINMENU=TableGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuParImpl::get_TableTYPE_IDEL_INTERF_MAINMENU(void)
{
return Object->TableTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_TableTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * TableTYPE_IDEL_INTERF_MAINMENU)
{
Object->TableTYPE_IDEL_INTERF_MAINMENU=TableTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaInterfMainMenuParImpl::get_ElementGUIDMOD_INTERF_MAINMENU(void)
{
return Object->ElementGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementGUIDMOD_INTERF_MAINMENU(TFIBWideStringField * ElementGUIDMOD_INTERF_MAINMENU)
{
Object->ElementGUIDMOD_INTERF_MAINMENU=ElementGUIDMOD_INTERF_MAINMENU;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaInterfMainMenuParImpl::get_ElementTYPE_IDEL_INTERF_MAINMENU(void)
{
return Object->ElementTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_ElementTYPE_IDEL_INTERF_MAINMENU(TFIBIntegerField * ElementTYPE_IDEL_INTERF_MAINMENU)
{
Object->ElementTYPE_IDEL_INTERF_MAINMENU=ElementTYPE_IDEL_INTERF_MAINMENU;
}
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuParImpl::get_NumApplication(void)
{
return Object->NumApplication;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_NumApplication(int NumApplication)
{
Object->NumApplication=NumApplication;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaInterfMainMenuParImpl::get_IdGrpUser(void)
{
return Object->IdGrpUser;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_IdGrpUser(__int64 IdGrpUser)
{
Object->IdGrpUser=IdGrpUser;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaInterfMainMenuParImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuParImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::OpenTable(int num_application, __int64 id_grp_user, __int64 id_grp, bool all)
{
return Object->OpenTable(int num_application, __int64 id_grp_user, __int64 id_grp, bool all);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuParImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuParImpl::Table_Delete(void)
{
return Object->Table_Delete(void);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuParImpl::Table_AppendString(int num_application, __int64 id_grp_user, __int64 id_grp)
{
return Object->Table_AppendString(int num_application, __int64 id_grp_user, __int64 id_grp);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuParImpl::NewElement(int num_application, __int64 id_grp_user, __int64 id_grp)
{
return Object->NewElement(int num_application, __int64 id_grp_user, __int64 id_grp);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuParImpl::OpenElement(__int64 id)
{
return Object->OpenElement(__int64 id);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuParImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(__int64 id);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuParImpl::InsertElement(int num_application, __int64 id_grp_user, __int64 id_grp)
{
return Object->InsertElement(int num_application, __int64 id_grp_user, __int64 id_grp);
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::Element_Edit(void)
{
return Object->Element_Edit(void);
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::Element_Post(void)
{
return Object->Element_Post(void);
}
//---------------------------------------------------------------
bool TFormaSpiskaInterfMainMenuParImpl::SaveElement(void)
{
return Object->SaveElement(void);
}
//---------------------------------------------------------------
void TFormaSpiskaInterfMainMenuParImpl::ChancheGrp(__int64 id_new_grp)
{
return Object->ChancheGrp(__int64 id_new_grp);
}
//---------------------------------------------------------------
