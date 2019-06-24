#include "vcl.h"
#pragma hdrstop


#include "UDMInterfToolBarImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMInterfToolBarImpl::TDMInterfToolBarImpl()           
{                                            
Object=new TDMInterfToolBar(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMInterfToolBarImpl::~TDMInterfToolBarImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMInterfToolBarImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMInterfToolBarImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMInterfToolBar)                        
   {                                                                     
   *ppv=static_cast<IDMInterfToolBar*> (this);                                
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
int TDMInterfToolBarImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMInterfToolBarImpl::kanRelease(void)                                  
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
int  TDMInterfToolBarImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMInterfToolBarImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMInterfToolBarImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMInterfToolBarImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMInterfToolBarImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMInterfToolBar
TDataSource * TDMInterfToolBarImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMInterfToolBarImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMInterfToolBarImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMInterfToolBarImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMInterfToolBarImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TDMInterfToolBarImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfToolBarImpl::get_TableID_INTERF_TOOLBAR(void)
{
return Object->TableID_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableID_INTERF_TOOLBAR(TFIBLargeIntField * TableID_INTERF_TOOLBAR)
{
Object->TableID_INTERF_TOOLBAR=TableID_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfToolBarImpl::get_TableIDBASE_INTERF_TOOLBAR(void)
{
return Object->TableIDBASE_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableIDBASE_INTERF_TOOLBAR(TFIBLargeIntField * TableIDBASE_INTERF_TOOLBAR)
{
Object->TableIDBASE_INTERF_TOOLBAR=TableIDBASE_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfToolBarImpl::get_TableNAME_INTERF_TOOLBAR(void)
{
return Object->TableNAME_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableNAME_INTERF_TOOLBAR(TFIBWideStringField * TableNAME_INTERF_TOOLBAR)
{
Object->TableNAME_INTERF_TOOLBAR=TableNAME_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfToolBarImpl::get_TableIDGRPUSER_INTERF_TOOLBAR(void)
{
return Object->TableIDGRPUSER_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableIDGRPUSER_INTERF_TOOLBAR(TFIBLargeIntField * TableIDGRPUSER_INTERF_TOOLBAR)
{
Object->TableIDGRPUSER_INTERF_TOOLBAR=TableIDGRPUSER_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfToolBarImpl::get_TableAPPLICATION_INTERF_TOOLBAR(void)
{
return Object->TableAPPLICATION_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableAPPLICATION_INTERF_TOOLBAR(TFIBIntegerField * TableAPPLICATION_INTERF_TOOLBAR)
{
Object->TableAPPLICATION_INTERF_TOOLBAR=TableAPPLICATION_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfToolBarImpl::get_TableMODUL_INTERF_TOOLBAR(void)
{
return Object->TableMODUL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableMODUL_INTERF_TOOLBAR(TFIBIntegerField * TableMODUL_INTERF_TOOLBAR)
{
Object->TableMODUL_INTERF_TOOLBAR=TableMODUL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfToolBarImpl::get_TableHINT_INTERF_TOOLBAR(void)
{
return Object->TableHINT_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableHINT_INTERF_TOOLBAR(TFIBWideStringField * TableHINT_INTERF_TOOLBAR)
{
Object->TableHINT_INTERF_TOOLBAR=TableHINT_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfToolBarImpl::get_TableIMAGEINDEX_INTERF_TOOLBAR(void)
{
return Object->TableIMAGEINDEX_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableIMAGEINDEX_INTERF_TOOLBAR(TFIBIntegerField * TableIMAGEINDEX_INTERF_TOOLBAR)
{
Object->TableIMAGEINDEX_INTERF_TOOLBAR=TableIMAGEINDEX_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfToolBarImpl::get_TableINDEX_INTERF_TOOLBAR(void)
{
return Object->TableINDEX_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableINDEX_INTERF_TOOLBAR(TFIBIntegerField * TableINDEX_INTERF_TOOLBAR)
{
Object->TableINDEX_INTERF_TOOLBAR=TableINDEX_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfToolBarImpl::get_TableNAME_PROGRAM_MODULE(void)
{
return Object->TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)
{
Object->TableNAME_PROGRAM_MODULE=TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfToolBarImpl::get_TablePROGID_PROGRAM_MODULE(void)
{
return Object->TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)
{
Object->TablePROGID_PROGRAM_MODULE=TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfToolBarImpl::get_TablePATCH_PROGRAM_MODULE(void)
{
return Object->TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)
{
Object->TablePATCH_PROGRAM_MODULE=TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfToolBarImpl::get_ElementID_INTERF_TOOLBAR(void)
{
return Object->ElementID_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementID_INTERF_TOOLBAR(TFIBLargeIntField * ElementID_INTERF_TOOLBAR)
{
Object->ElementID_INTERF_TOOLBAR=ElementID_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfToolBarImpl::get_ElementIDBASE_INTERF_TOOLBAR(void)
{
return Object->ElementIDBASE_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementIDBASE_INTERF_TOOLBAR(TFIBLargeIntField * ElementIDBASE_INTERF_TOOLBAR)
{
Object->ElementIDBASE_INTERF_TOOLBAR=ElementIDBASE_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfToolBarImpl::get_ElementNAME_INTERF_TOOLBAR(void)
{
return Object->ElementNAME_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementNAME_INTERF_TOOLBAR(TFIBWideStringField * ElementNAME_INTERF_TOOLBAR)
{
Object->ElementNAME_INTERF_TOOLBAR=ElementNAME_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfToolBarImpl::get_ElementIDGRPUSER_INTERF_TOOLBAR(void)
{
return Object->ElementIDGRPUSER_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementIDGRPUSER_INTERF_TOOLBAR(TFIBLargeIntField * ElementIDGRPUSER_INTERF_TOOLBAR)
{
Object->ElementIDGRPUSER_INTERF_TOOLBAR=ElementIDGRPUSER_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfToolBarImpl::get_ElementAPPLICATION_INTERF_TOOLBAR(void)
{
return Object->ElementAPPLICATION_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementAPPLICATION_INTERF_TOOLBAR(TFIBIntegerField * ElementAPPLICATION_INTERF_TOOLBAR)
{
Object->ElementAPPLICATION_INTERF_TOOLBAR=ElementAPPLICATION_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfToolBarImpl::get_ElementMODUL_INTERF_TOOLBAR(void)
{
return Object->ElementMODUL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementMODUL_INTERF_TOOLBAR(TFIBIntegerField * ElementMODUL_INTERF_TOOLBAR)
{
Object->ElementMODUL_INTERF_TOOLBAR=ElementMODUL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfToolBarImpl::get_ElementHINT_INTERF_TOOLBAR(void)
{
return Object->ElementHINT_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementHINT_INTERF_TOOLBAR(TFIBWideStringField * ElementHINT_INTERF_TOOLBAR)
{
Object->ElementHINT_INTERF_TOOLBAR=ElementHINT_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfToolBarImpl::get_ElementIMAGEINDEX_INTERF_TOOLBAR(void)
{
return Object->ElementIMAGEINDEX_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementIMAGEINDEX_INTERF_TOOLBAR(TFIBIntegerField * ElementIMAGEINDEX_INTERF_TOOLBAR)
{
Object->ElementIMAGEINDEX_INTERF_TOOLBAR=ElementIMAGEINDEX_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfToolBarImpl::get_ElementINDEX_INTERF_TOOLBAR(void)
{
return Object->ElementINDEX_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementINDEX_INTERF_TOOLBAR(TFIBIntegerField * ElementINDEX_INTERF_TOOLBAR)
{
Object->ElementINDEX_INTERF_TOOLBAR=ElementINDEX_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfToolBarImpl::get_ElementNAME_PROGRAM_MODULE(void)
{
return Object->ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)
{
Object->ElementNAME_PROGRAM_MODULE=ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfToolBarImpl::get_ElementPROGID_PROGRAM_MODULE(void)
{
return Object->ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)
{
Object->ElementPROGID_PROGRAM_MODULE=ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfToolBarImpl::get_ElementPATCH_PROGRAM_MODULE(void)
{
return Object->ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)
{
Object->ElementPATCH_PROGRAM_MODULE=ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfToolBarImpl::get_ElementGUIDMOD_INTERF_TOOLBAR(void)
{
return Object->ElementGUIDMOD_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementGUIDMOD_INTERF_TOOLBAR(TFIBWideStringField * ElementGUIDMOD_INTERF_TOOLBAR)
{
Object->ElementGUIDMOD_INTERF_TOOLBAR=ElementGUIDMOD_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfToolBarImpl::get_TableGUIDMOD_INTERF_TOOLBAR(void)
{
return Object->TableGUIDMOD_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableGUIDMOD_INTERF_TOOLBAR(TFIBWideStringField * TableGUIDMOD_INTERF_TOOLBAR)
{
Object->TableGUIDMOD_INTERF_TOOLBAR=TableGUIDMOD_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfToolBarImpl::get_TableIDMOD_INTERF_TOOLBAR(void)
{
return Object->TableIDMOD_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableIDMOD_INTERF_TOOLBAR(TFIBLargeIntField * TableIDMOD_INTERF_TOOLBAR)
{
Object->TableIDMOD_INTERF_TOOLBAR=TableIDMOD_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfToolBarImpl::get_TableFL_UPD_FORM_INTERF_TOOLBAR(void)
{
return Object->TableFL_UPD_FORM_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableFL_UPD_FORM_INTERF_TOOLBAR(TFIBSmallIntField * TableFL_UPD_FORM_INTERF_TOOLBAR)
{
Object->TableFL_UPD_FORM_INTERF_TOOLBAR=TableFL_UPD_FORM_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfToolBarImpl::get_TableIDEL_INTERF_TOOLBAR(void)
{
return Object->TableIDEL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableIDEL_INTERF_TOOLBAR(TFIBLargeIntField * TableIDEL_INTERF_TOOLBAR)
{
Object->TableIDEL_INTERF_TOOLBAR=TableIDEL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfToolBarImpl::get_TableFL_OPEN_EL_INTERF_TOOLBAR(void)
{
return Object->TableFL_OPEN_EL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableFL_OPEN_EL_INTERF_TOOLBAR(TFIBSmallIntField * TableFL_OPEN_EL_INTERF_TOOLBAR)
{
Object->TableFL_OPEN_EL_INTERF_TOOLBAR=TableFL_OPEN_EL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfToolBarImpl::get_TableTYPE_IDEL_INTERF_TOOLBAR(void)
{
return Object->TableTYPE_IDEL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_TableTYPE_IDEL_INTERF_TOOLBAR(TFIBIntegerField * TableTYPE_IDEL_INTERF_TOOLBAR)
{
Object->TableTYPE_IDEL_INTERF_TOOLBAR=TableTYPE_IDEL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfToolBarImpl::get_ElementIDMOD_INTERF_TOOLBAR(void)
{
return Object->ElementIDMOD_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementIDMOD_INTERF_TOOLBAR(TFIBLargeIntField * ElementIDMOD_INTERF_TOOLBAR)
{
Object->ElementIDMOD_INTERF_TOOLBAR=ElementIDMOD_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfToolBarImpl::get_ElementFL_UPD_FORM_INTERF_TOOLBAR(void)
{
return Object->ElementFL_UPD_FORM_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementFL_UPD_FORM_INTERF_TOOLBAR(TFIBSmallIntField * ElementFL_UPD_FORM_INTERF_TOOLBAR)
{
Object->ElementFL_UPD_FORM_INTERF_TOOLBAR=ElementFL_UPD_FORM_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfToolBarImpl::get_ElementIDEL_INTERF_TOOLBAR(void)
{
return Object->ElementIDEL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementIDEL_INTERF_TOOLBAR(TFIBLargeIntField * ElementIDEL_INTERF_TOOLBAR)
{
Object->ElementIDEL_INTERF_TOOLBAR=ElementIDEL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfToolBarImpl::get_ElementFL_OPEN_EL_INTERF_TOOLBAR(void)
{
return Object->ElementFL_OPEN_EL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementFL_OPEN_EL_INTERF_TOOLBAR(TFIBSmallIntField * ElementFL_OPEN_EL_INTERF_TOOLBAR)
{
Object->ElementFL_OPEN_EL_INTERF_TOOLBAR=ElementFL_OPEN_EL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfToolBarImpl::get_ElementTYPE_IDEL_INTERF_TOOLBAR(void)
{
return Object->ElementTYPE_IDEL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementTYPE_IDEL_INTERF_TOOLBAR(TFIBIntegerField * ElementTYPE_IDEL_INTERF_TOOLBAR)
{
Object->ElementTYPE_IDEL_INTERF_TOOLBAR=ElementTYPE_IDEL_INTERF_TOOLBAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfToolBarImpl::get_ElementTYPEMOD_PROGRAM_MODULE(void)
{
return Object->ElementTYPEMOD_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_ElementTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * ElementTYPEMOD_PROGRAM_MODULE)
{
Object->ElementTYPEMOD_PROGRAM_MODULE=ElementTYPEMOD_PROGRAM_MODULE;
}
//---------------------------------------------------------------
int TDMInterfToolBarImpl::get_NumApplication(void)
{
return Object->NumApplication;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_NumApplication(int NumApplication)
{
Object->NumApplication=NumApplication;
}
//---------------------------------------------------------------
__int64 TDMInterfToolBarImpl::get_IdGrpUser(void)
{
return Object->IdGrpUser;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_IdGrpUser(__int64 IdGrpUser)
{
Object->IdGrpUser=IdGrpUser;
}
//---------------------------------------------------------------
__int64 TDMInterfToolBarImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMInterfToolBarImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::OpenTable(int num_application, __int64 id_grp_user)
{
return Object->OpenTable(num_application,id_grp_user);
}
//---------------------------------------------------------------
bool TDMInterfToolBarImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool TDMInterfToolBarImpl::Table_Delete(void)
{
return Object->Table_Delete();
}
//---------------------------------------------------------------
bool TDMInterfToolBarImpl::Table_AppendString(int num_application, __int64 id_grp_user)
{
return Object->Table_AppendString(num_application,id_grp_user);
}
//---------------------------------------------------------------
bool TDMInterfToolBarImpl::NewElement(int num_application, __int64 id_grp_user)
{
return Object->NewElement(num_application,id_grp_user);
}
//---------------------------------------------------------------
bool TDMInterfToolBarImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMInterfToolBarImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TDMInterfToolBarImpl::InsertElement(int num_application, __int64 id_grp_user)
{
return Object->InsertElement(num_application,id_grp_user);
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::Element_Edit(void)
{
return Object->Element_Edit();
}
//---------------------------------------------------------------
void TDMInterfToolBarImpl::Element_Post(void)
{
return Object->Element_Post();
}
//---------------------------------------------------------------
bool TDMInterfToolBarImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
