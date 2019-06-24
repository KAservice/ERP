#include "vcl.h"
#pragma hdrstop


#include "UDMSprInetCatalogImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprInetCatalogImpl::TDMSprInetCatalogImpl()           
{                                            
Object=new TDMSprInetCatalog(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprInetCatalogImpl::~TDMSprInetCatalogImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprInetCatalogImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprInetCatalog)                        
   {                                                                     
   *ppv=static_cast<IDMSprInetCatalog*> (this);                                
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
int TDMSprInetCatalogImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprInetCatalogImpl::kanRelease(void)                                  
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
int  TDMSprInetCatalogImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprInetCatalogImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprInetCatalogImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprInetCatalogImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprInetCatalogImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprInetCatalog
TDataSource * TDMSprInetCatalogImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprInetCatalogImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprInetCatalogImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprInetCatalogImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprInetCatalogImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprInetCatalogImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprInetCatalogImpl::get_TableID_SINETCATALOG(void)
{
return Object->TableID_SINETCATALOG;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_TableID_SINETCATALOG(TFIBLargeIntField * TableID_SINETCATALOG)
{
Object->TableID_SINETCATALOG=TableID_SINETCATALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprInetCatalogImpl::get_TableIDBASE_SINETCATALOG(void)
{
return Object->TableIDBASE_SINETCATALOG;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_TableIDBASE_SINETCATALOG(TFIBLargeIntField * TableIDBASE_SINETCATALOG)
{
Object->TableIDBASE_SINETCATALOG=TableIDBASE_SINETCATALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInetCatalogImpl::get_TableGID_SINETCATALOG(void)
{
return Object->TableGID_SINETCATALOG;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_TableGID_SINETCATALOG(TFIBWideStringField * TableGID_SINETCATALOG)
{
Object->TableGID_SINETCATALOG=TableGID_SINETCATALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInetCatalogImpl::get_TableNAME_SINETCATALOG(void)
{
return Object->TableNAME_SINETCATALOG;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_TableNAME_SINETCATALOG(TFIBWideStringField * TableNAME_SINETCATALOG)
{
Object->TableNAME_SINETCATALOG=TableNAME_SINETCATALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprInetCatalogImpl::get_ElementID_SINETCATALOG(void)
{
return Object->ElementID_SINETCATALOG;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_ElementID_SINETCATALOG(TFIBLargeIntField * ElementID_SINETCATALOG)
{
Object->ElementID_SINETCATALOG=ElementID_SINETCATALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprInetCatalogImpl::get_ElementIDBASE_SINETCATALOG(void)
{
return Object->ElementIDBASE_SINETCATALOG;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_ElementIDBASE_SINETCATALOG(TFIBLargeIntField * ElementIDBASE_SINETCATALOG)
{
Object->ElementIDBASE_SINETCATALOG=ElementIDBASE_SINETCATALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInetCatalogImpl::get_ElementGID_SINETCATALOG(void)
{
return Object->ElementGID_SINETCATALOG;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_ElementGID_SINETCATALOG(TFIBWideStringField * ElementGID_SINETCATALOG)
{
Object->ElementGID_SINETCATALOG=ElementGID_SINETCATALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInetCatalogImpl::get_ElementNAME_SINETCATALOG(void)
{
return Object->ElementNAME_SINETCATALOG;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_ElementNAME_SINETCATALOG(TFIBWideStringField * ElementNAME_SINETCATALOG)
{
Object->ElementNAME_SINETCATALOG=ElementNAME_SINETCATALOG;
}
//---------------------------------------------------------------
__int64 TDMSprInetCatalogImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprInetCatalogImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprInetCatalogImpl::OpenElement(__int64 id )
{
return Object->OpenElement( id );
}
//---------------------------------------------------------------
bool TDMSprInetCatalogImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprInetCatalogImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprInetCatalogImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprInetCatalogImpl::GetIdPoName(UnicodeString name)
{
return Object->GetIdPoName(name);
}
//---------------------------------------------------------------
int TDMSprInetCatalogImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
