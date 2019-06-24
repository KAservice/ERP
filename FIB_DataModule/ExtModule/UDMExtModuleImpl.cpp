#include "vcl.h"
#pragma hdrstop


#include "UDMExtModuleImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMExtModuleImpl::TDMExtModuleImpl()           
{                                            
Object=new TDMExtModule(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMExtModuleImpl::~TDMExtModuleImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMExtModuleImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMExtModuleImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMExtModule)                        
   {                                                                     
   *ppv=static_cast<IDMExtModule*> (this);                                
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
int TDMExtModuleImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMExtModuleImpl::kanRelease(void)                                  
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
int  TDMExtModuleImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMExtModuleImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMExtModuleImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMExtModuleImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMExtModuleImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMExtModuleImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMExtModuleImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMExtModule
TDataSource * TDMExtModuleImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMExtModuleImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMExtModuleImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMExtModuleImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMExtModuleImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMExtModuleImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBBCDField * TDMExtModuleImpl::get_TableID_EXT_MODULE(void)
{
return Object->TableID_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_TableID_EXT_MODULE(TFIBBCDField * TableID_EXT_MODULE)
{
Object->TableID_EXT_MODULE=TableID_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMExtModuleImpl::get_TableIDGRP_EXT_MODULE(void)
{
return Object->TableIDGRP_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_TableIDGRP_EXT_MODULE(TFIBBCDField * TableIDGRP_EXT_MODULE)
{
Object->TableIDGRP_EXT_MODULE=TableIDGRP_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMExtModuleImpl::get_TableTYPE_EXT_MODULE(void)
{
return Object->TableTYPE_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_TableTYPE_EXT_MODULE(TFIBSmallIntField * TableTYPE_EXT_MODULE)
{
Object->TableTYPE_EXT_MODULE=TableTYPE_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMExtModuleImpl::get_TableISP_EXT_MODULE(void)
{
return Object->TableISP_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_TableISP_EXT_MODULE(TFIBSmallIntField * TableISP_EXT_MODULE)
{
Object->TableISP_EXT_MODULE=TableISP_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMExtModuleImpl::get_ElementID_EXT_MODULE(void)
{
return Object->ElementID_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_ElementID_EXT_MODULE(TFIBBCDField * ElementID_EXT_MODULE)
{
Object->ElementID_EXT_MODULE=ElementID_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMExtModuleImpl::get_ElementIDGRP_EXT_MODULE(void)
{
return Object->ElementIDGRP_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_ElementIDGRP_EXT_MODULE(TFIBBCDField * ElementIDGRP_EXT_MODULE)
{
Object->ElementIDGRP_EXT_MODULE=ElementIDGRP_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMExtModuleImpl::get_ElementTYPE_EXT_MODULE(void)
{
return Object->ElementTYPE_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_ElementTYPE_EXT_MODULE(TFIBSmallIntField * ElementTYPE_EXT_MODULE)
{
Object->ElementTYPE_EXT_MODULE=ElementTYPE_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMExtModuleImpl::get_ElementISP_EXT_MODULE(void)
{
return Object->ElementISP_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_ElementISP_EXT_MODULE(TFIBSmallIntField * ElementISP_EXT_MODULE)
{
Object->ElementISP_EXT_MODULE=ElementISP_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBBlobField * TDMExtModuleImpl::get_ElementBODY_EXT_MODULE(void)
{
return Object->ElementBODY_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_ElementBODY_EXT_MODULE(TFIBBlobField * ElementBODY_EXT_MODULE)
{
Object->ElementBODY_EXT_MODULE=ElementBODY_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMExtModuleImpl::get_ElementRESIDENCE_EXT_MODULE(void)
{
return Object->ElementRESIDENCE_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_ElementRESIDENCE_EXT_MODULE(TFIBIntegerField * ElementRESIDENCE_EXT_MODULE)
{
Object->ElementRESIDENCE_EXT_MODULE=ElementRESIDENCE_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMExtModuleImpl::get_TableNAME_EXT_MODULE(void)
{
return Object->TableNAME_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_TableNAME_EXT_MODULE(TFIBWideStringField * TableNAME_EXT_MODULE)
{
Object->TableNAME_EXT_MODULE=TableNAME_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMExtModuleImpl::get_TableFILE_NAME_EXT_MODULE(void)
{
return Object->TableFILE_NAME_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_TableFILE_NAME_EXT_MODULE(TFIBWideStringField * TableFILE_NAME_EXT_MODULE)
{
Object->TableFILE_NAME_EXT_MODULE=TableFILE_NAME_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMExtModuleImpl::get_ElementNAME_EXT_MODULE(void)
{
return Object->ElementNAME_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_ElementNAME_EXT_MODULE(TFIBWideStringField * ElementNAME_EXT_MODULE)
{
Object->ElementNAME_EXT_MODULE=ElementNAME_EXT_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMExtModuleImpl::get_ElementFILE_NAME_EXT_MODULE(void)
{
return Object->ElementFILE_NAME_EXT_MODULE;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_ElementFILE_NAME_EXT_MODULE(TFIBWideStringField * ElementFILE_NAME_EXT_MODULE)
{
Object->ElementFILE_NAME_EXT_MODULE=ElementFILE_NAME_EXT_MODULE;
}
//---------------------------------------------------------------
__int64 TDMExtModuleImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMExtModuleImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMExtModuleImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMExtModuleImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp, all);
}
//---------------------------------------------------------------
int TDMExtModuleImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMExtModuleImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMExtModuleImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMExtModuleImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement( id);
}
//---------------------------------------------------------------
void TDMExtModuleImpl::ChancheGrp(__int64 new_id_grp)
{
return Object->ChancheGrp( new_id_grp);
}
//---------------------------------------------------------------
__int64 TDMExtModuleImpl::FindPoName(AnsiString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TDMExtModuleImpl::GetIdGrpExtModule(__int64 id_ext_module)
{
return Object->GetIdGrpExtModule(id_ext_module);
}
//---------------------------------------------------------------
