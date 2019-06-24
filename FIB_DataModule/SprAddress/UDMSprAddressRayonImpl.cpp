#include "vcl.h"
#pragma hdrstop


#include "UDMSprAddressRayonImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprAddressRayonImpl::TDMSprAddressRayonImpl()           
{                                            
Object=new TDMSprAddressRayon(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprAddressRayonImpl::~TDMSprAddressRayonImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprAddressRayonImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprAddressRayon)                        
   {                                                                     
   *ppv=static_cast<IDMSprAddressRayon*> (this);                                
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
int TDMSprAddressRayonImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprAddressRayonImpl::kanRelease(void)                                  
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
int  TDMSprAddressRayonImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprAddressRayonImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprAddressRayonImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprAddressRayonImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprAddressRayonImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprAddressRayon
TDataSource * TDMSprAddressRayonImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprAddressRayonImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprAddressRayonImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprAddressRayonImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TDMSprAddressRayonImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprAddressRayonImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprAddressRayonImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressRayonImpl::get_TableID_SADR_RAYON(void)
{
return Object->TableID_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_TableID_SADR_RAYON(TFIBLargeIntField * TableID_SADR_RAYON)
{
Object->TableID_SADR_RAYON=TableID_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressRayonImpl::get_TableIDBASE_SADR_RAYON(void)
{
return Object->TableIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_TableIDBASE_SADR_RAYON(TFIBLargeIntField * TableIDBASE_SADR_RAYON)
{
Object->TableIDBASE_SADR_RAYON=TableIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressRayonImpl::get_TableIDREGION_SADR_RAYON(void)
{
return Object->TableIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_TableIDREGION_SADR_RAYON(TFIBLargeIntField * TableIDREGION_SADR_RAYON)
{
Object->TableIDREGION_SADR_RAYON=TableIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressRayonImpl::get_TableNAME_SADR_RAYON(void)
{
return Object->TableNAME_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_TableNAME_SADR_RAYON(TFIBWideStringField * TableNAME_SADR_RAYON)
{
Object->TableNAME_SADR_RAYON=TableNAME_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressRayonImpl::get_ElementID_SADR_RAYON(void)
{
return Object->ElementID_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_ElementID_SADR_RAYON(TFIBLargeIntField * ElementID_SADR_RAYON)
{
Object->ElementID_SADR_RAYON=ElementID_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressRayonImpl::get_ElementIDBASE_SADR_RAYON(void)
{
return Object->ElementIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_ElementIDBASE_SADR_RAYON(TFIBLargeIntField * ElementIDBASE_SADR_RAYON)
{
Object->ElementIDBASE_SADR_RAYON=ElementIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressRayonImpl::get_ElementIDREGION_SADR_RAYON(void)
{
return Object->ElementIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_ElementIDREGION_SADR_RAYON(TFIBLargeIntField * ElementIDREGION_SADR_RAYON)
{
Object->ElementIDREGION_SADR_RAYON=ElementIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressRayonImpl::get_ElementNAME_SADR_RAYON(void)
{
return Object->ElementNAME_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_ElementNAME_SADR_RAYON(TFIBWideStringField * ElementNAME_SADR_RAYON)
{
Object->ElementNAME_SADR_RAYON=ElementNAME_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressRayonImpl::get_ElementID_SADR_REGION(void)
{
return Object->ElementID_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_ElementID_SADR_REGION(TFIBLargeIntField * ElementID_SADR_REGION)
{
Object->ElementID_SADR_REGION=ElementID_SADR_REGION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressRayonImpl::get_ElementIDBASE_SADR_REGION(void)
{
return Object->ElementIDBASE_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_ElementIDBASE_SADR_REGION(TFIBLargeIntField * ElementIDBASE_SADR_REGION)
{
Object->ElementIDBASE_SADR_REGION=ElementIDBASE_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressRayonImpl::get_ElementNAME_SADR_REGION(void)
{
return Object->ElementNAME_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_ElementNAME_SADR_REGION(TFIBWideStringField * ElementNAME_SADR_REGION)
{
Object->ElementNAME_SADR_REGION=ElementNAME_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressRayonImpl::get_ElementCODE_SADR_REGION(void)
{
return Object->ElementCODE_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_ElementCODE_SADR_REGION(TFIBWideStringField * ElementCODE_SADR_REGION)
{
Object->ElementCODE_SADR_REGION=ElementCODE_SADR_REGION;
}
//---------------------------------------------------------------
__int64 TDMSprAddressRayonImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
__int64 TDMSprAddressRayonImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprAddressRayonImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
bool TDMSprAddressRayonImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
int TDMSprAddressRayonImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprAddressRayonImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprAddressRayonImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
