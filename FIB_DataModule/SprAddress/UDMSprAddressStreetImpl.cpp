#include "vcl.h"
#pragma hdrstop


#include "UDMSprAddressStreetImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprAddressStreetImpl::TDMSprAddressStreetImpl()           
{                                            
Object=new TDMSprAddressStreet(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprAddressStreetImpl::~TDMSprAddressStreetImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprAddressStreetImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprAddressStreet)                        
   {                                                                     
   *ppv=static_cast<IDMSprAddressStreet*> (this);                                
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
int TDMSprAddressStreetImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprAddressStreetImpl::kanRelease(void)                                  
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
int  TDMSprAddressStreetImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprAddressStreetImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprAddressStreetImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprAddressStreetImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprAddressStreetImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprAddressStreet
TDataSource * TDMSprAddressStreetImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprAddressStreetImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprAddressStreetImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprAddressStreetImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TDMSprAddressStreetImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprAddressStreetImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprAddressStreetImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_TableID_SADR_STREET(void)
{
return Object->TableID_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_TableID_SADR_STREET(TFIBLargeIntField * TableID_SADR_STREET)
{
Object->TableID_SADR_STREET=TableID_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_TableIDBASE_SADR_STREET(void)
{
return Object->TableIDBASE_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_TableIDBASE_SADR_STREET(TFIBLargeIntField * TableIDBASE_SADR_STREET)
{
Object->TableIDBASE_SADR_STREET=TableIDBASE_SADR_STREET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStreetImpl::get_TableNAME_SADR_STREET(void)
{
return Object->TableNAME_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_TableNAME_SADR_STREET(TFIBWideStringField * TableNAME_SADR_STREET)
{
Object->TableNAME_SADR_STREET=TableNAME_SADR_STREET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStreetImpl::get_TablePOSTCODE_SADR_STREET(void)
{
return Object->TablePOSTCODE_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_TablePOSTCODE_SADR_STREET(TFIBWideStringField * TablePOSTCODE_SADR_STREET)
{
Object->TablePOSTCODE_SADR_STREET=TablePOSTCODE_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_TableIDNASPUNKT_SADR_STREET(void)
{
return Object->TableIDNASPUNKT_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_TableIDNASPUNKT_SADR_STREET(TFIBLargeIntField * TableIDNASPUNKT_SADR_STREET)
{
Object->TableIDNASPUNKT_SADR_STREET=TableIDNASPUNKT_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_ElementID_SADR_STREET(void)
{
return Object->ElementID_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementID_SADR_STREET(TFIBLargeIntField * ElementID_SADR_STREET)
{
Object->ElementID_SADR_STREET=ElementID_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_ElementIDBASE_SADR_STREET(void)
{
return Object->ElementIDBASE_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementIDBASE_SADR_STREET(TFIBLargeIntField * ElementIDBASE_SADR_STREET)
{
Object->ElementIDBASE_SADR_STREET=ElementIDBASE_SADR_STREET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStreetImpl::get_ElementNAME_SADR_STREET(void)
{
return Object->ElementNAME_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementNAME_SADR_STREET(TFIBWideStringField * ElementNAME_SADR_STREET)
{
Object->ElementNAME_SADR_STREET=ElementNAME_SADR_STREET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStreetImpl::get_ElementPOSTCODE_SADR_STREET(void)
{
return Object->ElementPOSTCODE_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementPOSTCODE_SADR_STREET(TFIBWideStringField * ElementPOSTCODE_SADR_STREET)
{
Object->ElementPOSTCODE_SADR_STREET=ElementPOSTCODE_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_ElementIDNASPUNKT_SADR_STREET(void)
{
return Object->ElementIDNASPUNKT_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementIDNASPUNKT_SADR_STREET(TFIBLargeIntField * ElementIDNASPUNKT_SADR_STREET)
{
Object->ElementIDNASPUNKT_SADR_STREET=ElementIDNASPUNKT_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_ElementID_SADR_NASPUNKT(void)
{
return Object->ElementID_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementID_SADR_NASPUNKT(TFIBLargeIntField * ElementID_SADR_NASPUNKT)
{
Object->ElementID_SADR_NASPUNKT=ElementID_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_ElementIDBASE_SADR_NASPUNKT(void)
{
return Object->ElementIDBASE_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementIDBASE_SADR_NASPUNKT(TFIBLargeIntField * ElementIDBASE_SADR_NASPUNKT)
{
Object->ElementIDBASE_SADR_NASPUNKT=ElementIDBASE_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_ElementIDRAYON_SADR_NASPUNKT(void)
{
return Object->ElementIDRAYON_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementIDRAYON_SADR_NASPUNKT(TFIBLargeIntField * ElementIDRAYON_SADR_NASPUNKT)
{
Object->ElementIDRAYON_SADR_NASPUNKT=ElementIDRAYON_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStreetImpl::get_ElementNAME_SADR_NASPUNKT(void)
{
return Object->ElementNAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementNAME_SADR_NASPUNKT(TFIBWideStringField * ElementNAME_SADR_NASPUNKT)
{
Object->ElementNAME_SADR_NASPUNKT=ElementNAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprAddressStreetImpl::get_ElementFL_GOROD_SADR_NASPUNKT(void)
{
return Object->ElementFL_GOROD_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementFL_GOROD_SADR_NASPUNKT(TFIBIntegerField * ElementFL_GOROD_SADR_NASPUNKT)
{
Object->ElementFL_GOROD_SADR_NASPUNKT=ElementFL_GOROD_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_ElementID_SADR_RAYON(void)
{
return Object->ElementID_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementID_SADR_RAYON(TFIBLargeIntField * ElementID_SADR_RAYON)
{
Object->ElementID_SADR_RAYON=ElementID_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_ElementIDBASE_SADR_RAYON(void)
{
return Object->ElementIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementIDBASE_SADR_RAYON(TFIBLargeIntField * ElementIDBASE_SADR_RAYON)
{
Object->ElementIDBASE_SADR_RAYON=ElementIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_ElementIDREGION_SADR_RAYON(void)
{
return Object->ElementIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementIDREGION_SADR_RAYON(TFIBLargeIntField * ElementIDREGION_SADR_RAYON)
{
Object->ElementIDREGION_SADR_RAYON=ElementIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStreetImpl::get_ElementNAME_SADR_RAYON(void)
{
return Object->ElementNAME_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementNAME_SADR_RAYON(TFIBWideStringField * ElementNAME_SADR_RAYON)
{
Object->ElementNAME_SADR_RAYON=ElementNAME_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_ElementID_SADR_REGION(void)
{
return Object->ElementID_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementID_SADR_REGION(TFIBLargeIntField * ElementID_SADR_REGION)
{
Object->ElementID_SADR_REGION=ElementID_SADR_REGION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStreetImpl::get_ElementIDBASE_SADR_REGION(void)
{
return Object->ElementIDBASE_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementIDBASE_SADR_REGION(TFIBLargeIntField * ElementIDBASE_SADR_REGION)
{
Object->ElementIDBASE_SADR_REGION=ElementIDBASE_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStreetImpl::get_ElementNAME_SADR_REGION(void)
{
return Object->ElementNAME_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementNAME_SADR_REGION(TFIBWideStringField * ElementNAME_SADR_REGION)
{
Object->ElementNAME_SADR_REGION=ElementNAME_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStreetImpl::get_ElementCODE_SADR_REGION(void)
{
return Object->ElementCODE_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_ElementCODE_SADR_REGION(TFIBWideStringField * ElementCODE_SADR_REGION)
{
Object->ElementCODE_SADR_REGION=ElementCODE_SADR_REGION;
}
//---------------------------------------------------------------
__int64 TDMSprAddressStreetImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
__int64 TDMSprAddressStreetImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprAddressStreetImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
bool TDMSprAddressStreetImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
int TDMSprAddressStreetImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprAddressStreetImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprAddressStreetImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
