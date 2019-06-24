#include "vcl.h"
#pragma hdrstop


#include "UDMSprAddressStroenImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprAddressStroenImpl::TDMSprAddressStroenImpl()           
{                                            
Object=new TDMSprAddressStroen(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprAddressStroenImpl::~TDMSprAddressStroenImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprAddressStroenImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprAddressStroen)                        
   {                                                                     
   *ppv=static_cast<IDMSprAddressStroen*> (this);                                
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
int TDMSprAddressStroenImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprAddressStroenImpl::kanRelease(void)                                  
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
int  TDMSprAddressStroenImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprAddressStroenImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprAddressStroenImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprAddressStroenImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprAddressStroenImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprAddressStroen
TDataSource * TDMSprAddressStroenImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprAddressStroenImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprAddressStroenImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprAddressStroenImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TDMSprAddressStroenImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprAddressStroenImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprAddressStroenImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_TableID_SADR_STROEN(void)
{
return Object->TableID_SADR_STROEN;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_TableID_SADR_STROEN(TFIBLargeIntField * TableID_SADR_STROEN)
{
Object->TableID_SADR_STROEN=TableID_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_TableIDBASE_SADR_STROEN(void)
{
return Object->TableIDBASE_SADR_STROEN;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_TableIDBASE_SADR_STROEN(TFIBLargeIntField * TableIDBASE_SADR_STROEN)
{
Object->TableIDBASE_SADR_STROEN=TableIDBASE_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStroenImpl::get_TableNAME_SADR_STROEN(void)
{
return Object->TableNAME_SADR_STROEN;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_TableNAME_SADR_STROEN(TFIBWideStringField * TableNAME_SADR_STROEN)
{
Object->TableNAME_SADR_STROEN=TableNAME_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_TableIDDOM_SADR_STROEN(void)
{
return Object->TableIDDOM_SADR_STROEN;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_TableIDDOM_SADR_STROEN(TFIBLargeIntField * TableIDDOM_SADR_STROEN)
{
Object->TableIDDOM_SADR_STROEN=TableIDDOM_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementID_SADR_STROEN(void)
{
return Object->ElementID_SADR_STROEN;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementID_SADR_STROEN(TFIBLargeIntField * ElementID_SADR_STROEN)
{
Object->ElementID_SADR_STROEN=ElementID_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementIDBASE_SADR_STROEN(void)
{
return Object->ElementIDBASE_SADR_STROEN;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementIDBASE_SADR_STROEN(TFIBLargeIntField * ElementIDBASE_SADR_STROEN)
{
Object->ElementIDBASE_SADR_STROEN=ElementIDBASE_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStroenImpl::get_ElementNAME_SADR_STROEN(void)
{
return Object->ElementNAME_SADR_STROEN;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementNAME_SADR_STROEN(TFIBWideStringField * ElementNAME_SADR_STROEN)
{
Object->ElementNAME_SADR_STROEN=ElementNAME_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementIDDOM_SADR_STROEN(void)
{
return Object->ElementIDDOM_SADR_STROEN;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementIDDOM_SADR_STROEN(TFIBLargeIntField * ElementIDDOM_SADR_STROEN)
{
Object->ElementIDDOM_SADR_STROEN=ElementIDDOM_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementID_SADR_DOM(void)
{
return Object->ElementID_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementID_SADR_DOM(TFIBLargeIntField * ElementID_SADR_DOM)
{
Object->ElementID_SADR_DOM=ElementID_SADR_DOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementIDBASE_SADR_DOM(void)
{
return Object->ElementIDBASE_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementIDBASE_SADR_DOM(TFIBLargeIntField * ElementIDBASE_SADR_DOM)
{
Object->ElementIDBASE_SADR_DOM=ElementIDBASE_SADR_DOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementIDSTREET_SADR_DOM(void)
{
return Object->ElementIDSTREET_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementIDSTREET_SADR_DOM(TFIBLargeIntField * ElementIDSTREET_SADR_DOM)
{
Object->ElementIDSTREET_SADR_DOM=ElementIDSTREET_SADR_DOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStroenImpl::get_ElementNAME_SADR_DOM(void)
{
return Object->ElementNAME_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementNAME_SADR_DOM(TFIBWideStringField * ElementNAME_SADR_DOM)
{
Object->ElementNAME_SADR_DOM=ElementNAME_SADR_DOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementID_SADR_STREET(void)
{
return Object->ElementID_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementID_SADR_STREET(TFIBLargeIntField * ElementID_SADR_STREET)
{
Object->ElementID_SADR_STREET=ElementID_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementIDBASE_SADR_STREET(void)
{
return Object->ElementIDBASE_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementIDBASE_SADR_STREET(TFIBLargeIntField * ElementIDBASE_SADR_STREET)
{
Object->ElementIDBASE_SADR_STREET=ElementIDBASE_SADR_STREET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStroenImpl::get_ElementNAME_SADR_STREET(void)
{
return Object->ElementNAME_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementNAME_SADR_STREET(TFIBWideStringField * ElementNAME_SADR_STREET)
{
Object->ElementNAME_SADR_STREET=ElementNAME_SADR_STREET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStroenImpl::get_ElementPOSTCODE_SADR_STREET(void)
{
return Object->ElementPOSTCODE_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementPOSTCODE_SADR_STREET(TFIBWideStringField * ElementPOSTCODE_SADR_STREET)
{
Object->ElementPOSTCODE_SADR_STREET=ElementPOSTCODE_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementIDNASPUNKT_SADR_STREET(void)
{
return Object->ElementIDNASPUNKT_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementIDNASPUNKT_SADR_STREET(TFIBLargeIntField * ElementIDNASPUNKT_SADR_STREET)
{
Object->ElementIDNASPUNKT_SADR_STREET=ElementIDNASPUNKT_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementID_SADR_NASPUNKT(void)
{
return Object->ElementID_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementID_SADR_NASPUNKT(TFIBLargeIntField * ElementID_SADR_NASPUNKT)
{
Object->ElementID_SADR_NASPUNKT=ElementID_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementIDBASE_SADR_NASPUNKT(void)
{
return Object->ElementIDBASE_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementIDBASE_SADR_NASPUNKT(TFIBLargeIntField * ElementIDBASE_SADR_NASPUNKT)
{
Object->ElementIDBASE_SADR_NASPUNKT=ElementIDBASE_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementIDRAYON_SADR_NASPUNKT(void)
{
return Object->ElementIDRAYON_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementIDRAYON_SADR_NASPUNKT(TFIBLargeIntField * ElementIDRAYON_SADR_NASPUNKT)
{
Object->ElementIDRAYON_SADR_NASPUNKT=ElementIDRAYON_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStroenImpl::get_ElementNAME_SADR_NASPUNKT(void)
{
return Object->ElementNAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementNAME_SADR_NASPUNKT(TFIBWideStringField * ElementNAME_SADR_NASPUNKT)
{
Object->ElementNAME_SADR_NASPUNKT=ElementNAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprAddressStroenImpl::get_ElementFL_GOROD_SADR_NASPUNKT(void)
{
return Object->ElementFL_GOROD_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementFL_GOROD_SADR_NASPUNKT(TFIBIntegerField * ElementFL_GOROD_SADR_NASPUNKT)
{
Object->ElementFL_GOROD_SADR_NASPUNKT=ElementFL_GOROD_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementID_SADR_RAYON(void)
{
return Object->ElementID_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementID_SADR_RAYON(TFIBLargeIntField * ElementID_SADR_RAYON)
{
Object->ElementID_SADR_RAYON=ElementID_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementIDBASE_SADR_RAYON(void)
{
return Object->ElementIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementIDBASE_SADR_RAYON(TFIBLargeIntField * ElementIDBASE_SADR_RAYON)
{
Object->ElementIDBASE_SADR_RAYON=ElementIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementIDREGION_SADR_RAYON(void)
{
return Object->ElementIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementIDREGION_SADR_RAYON(TFIBLargeIntField * ElementIDREGION_SADR_RAYON)
{
Object->ElementIDREGION_SADR_RAYON=ElementIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStroenImpl::get_ElementNAME_SADR_RAYON(void)
{
return Object->ElementNAME_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementNAME_SADR_RAYON(TFIBWideStringField * ElementNAME_SADR_RAYON)
{
Object->ElementNAME_SADR_RAYON=ElementNAME_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementID_SADR_REGION(void)
{
return Object->ElementID_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementID_SADR_REGION(TFIBLargeIntField * ElementID_SADR_REGION)
{
Object->ElementID_SADR_REGION=ElementID_SADR_REGION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressStroenImpl::get_ElementIDBASE_SADR_REGION(void)
{
return Object->ElementIDBASE_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementIDBASE_SADR_REGION(TFIBLargeIntField * ElementIDBASE_SADR_REGION)
{
Object->ElementIDBASE_SADR_REGION=ElementIDBASE_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStroenImpl::get_ElementNAME_SADR_REGION(void)
{
return Object->ElementNAME_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementNAME_SADR_REGION(TFIBWideStringField * ElementNAME_SADR_REGION)
{
Object->ElementNAME_SADR_REGION=ElementNAME_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressStroenImpl::get_ElementCODE_SADR_REGION(void)
{
return Object->ElementCODE_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_ElementCODE_SADR_REGION(TFIBWideStringField * ElementCODE_SADR_REGION)
{
Object->ElementCODE_SADR_REGION=ElementCODE_SADR_REGION;
}
//---------------------------------------------------------------
__int64 TDMSprAddressStroenImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
__int64 TDMSprAddressStroenImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprAddressStroenImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
bool TDMSprAddressStroenImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
int TDMSprAddressStroenImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprAddressStroenImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprAddressStroenImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
