#include "vcl.h"
#pragma hdrstop


#include "UDMSprAddressKVImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprAddressKVImpl::TDMSprAddressKVImpl()           
{                                            
Object=new TDMSprAddressKV(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprAddressKVImpl::~TDMSprAddressKVImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprAddressKVImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprAddressKVImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprAddressKV)                        
   {                                                                     
   *ppv=static_cast<IDMSprAddressKV*> (this);                                
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
int TDMSprAddressKVImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprAddressKVImpl::kanRelease(void)                                  
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
int  TDMSprAddressKVImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprAddressKVImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprAddressKVImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprAddressKVImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprAddressKVImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprAddressKV
TDataSource * TDMSprAddressKVImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprAddressKVImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprAddressKVImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprAddressKVImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TDMSprAddressKVImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprAddressKVImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprAddressKVImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_TableID_SADR_KV(void)
{
return Object->TableID_SADR_KV;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_TableID_SADR_KV(TFIBLargeIntField * TableID_SADR_KV)
{
Object->TableID_SADR_KV=TableID_SADR_KV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_TableIDBASE_SADR_KV(void)
{
return Object->TableIDBASE_SADR_KV;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_TableIDBASE_SADR_KV(TFIBLargeIntField * TableIDBASE_SADR_KV)
{
Object->TableIDBASE_SADR_KV=TableIDBASE_SADR_KV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressKVImpl::get_TableNAME_SADR_KV(void)
{
return Object->TableNAME_SADR_KV;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_TableNAME_SADR_KV(TFIBWideStringField * TableNAME_SADR_KV)
{
Object->TableNAME_SADR_KV=TableNAME_SADR_KV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_TableIDSTROEN_SADR_KV(void)
{
return Object->TableIDSTROEN_SADR_KV;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_TableIDSTROEN_SADR_KV(TFIBLargeIntField * TableIDSTROEN_SADR_KV)
{
Object->TableIDSTROEN_SADR_KV=TableIDSTROEN_SADR_KV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementID_SADR_KV(void)
{
return Object->ElementID_SADR_KV;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementID_SADR_KV(TFIBLargeIntField * ElementID_SADR_KV)
{
Object->ElementID_SADR_KV=ElementID_SADR_KV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDBASE_SADR_KV(void)
{
return Object->ElementIDBASE_SADR_KV;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDBASE_SADR_KV(TFIBLargeIntField * ElementIDBASE_SADR_KV)
{
Object->ElementIDBASE_SADR_KV=ElementIDBASE_SADR_KV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressKVImpl::get_ElementNAME_SADR_KV(void)
{
return Object->ElementNAME_SADR_KV;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementNAME_SADR_KV(TFIBWideStringField * ElementNAME_SADR_KV)
{
Object->ElementNAME_SADR_KV=ElementNAME_SADR_KV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDSTROEN_SADR_KV(void)
{
return Object->ElementIDSTROEN_SADR_KV;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDSTROEN_SADR_KV(TFIBLargeIntField * ElementIDSTROEN_SADR_KV)
{
Object->ElementIDSTROEN_SADR_KV=ElementIDSTROEN_SADR_KV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementID_SADR_STROEN(void)
{
return Object->ElementID_SADR_STROEN;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementID_SADR_STROEN(TFIBLargeIntField * ElementID_SADR_STROEN)
{
Object->ElementID_SADR_STROEN=ElementID_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDBASE_SADR_STROEN(void)
{
return Object->ElementIDBASE_SADR_STROEN;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDBASE_SADR_STROEN(TFIBLargeIntField * ElementIDBASE_SADR_STROEN)
{
Object->ElementIDBASE_SADR_STROEN=ElementIDBASE_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressKVImpl::get_ElementNAME_SADR_STROEN(void)
{
return Object->ElementNAME_SADR_STROEN;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementNAME_SADR_STROEN(TFIBWideStringField * ElementNAME_SADR_STROEN)
{
Object->ElementNAME_SADR_STROEN=ElementNAME_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDDOM_SADR_STROEN(void)
{
return Object->ElementIDDOM_SADR_STROEN;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDDOM_SADR_STROEN(TFIBLargeIntField * ElementIDDOM_SADR_STROEN)
{
Object->ElementIDDOM_SADR_STROEN=ElementIDDOM_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementID_SADR_DOM(void)
{
return Object->ElementID_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementID_SADR_DOM(TFIBLargeIntField * ElementID_SADR_DOM)
{
Object->ElementID_SADR_DOM=ElementID_SADR_DOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDBASE_SADR_DOM(void)
{
return Object->ElementIDBASE_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDBASE_SADR_DOM(TFIBLargeIntField * ElementIDBASE_SADR_DOM)
{
Object->ElementIDBASE_SADR_DOM=ElementIDBASE_SADR_DOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDSTREET_SADR_DOM(void)
{
return Object->ElementIDSTREET_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDSTREET_SADR_DOM(TFIBLargeIntField * ElementIDSTREET_SADR_DOM)
{
Object->ElementIDSTREET_SADR_DOM=ElementIDSTREET_SADR_DOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressKVImpl::get_ElementNAME_SADR_DOM(void)
{
return Object->ElementNAME_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementNAME_SADR_DOM(TFIBWideStringField * ElementNAME_SADR_DOM)
{
Object->ElementNAME_SADR_DOM=ElementNAME_SADR_DOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementID_SADR_STREET(void)
{
return Object->ElementID_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementID_SADR_STREET(TFIBLargeIntField * ElementID_SADR_STREET)
{
Object->ElementID_SADR_STREET=ElementID_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDBASE_SADR_STREET(void)
{
return Object->ElementIDBASE_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDBASE_SADR_STREET(TFIBLargeIntField * ElementIDBASE_SADR_STREET)
{
Object->ElementIDBASE_SADR_STREET=ElementIDBASE_SADR_STREET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressKVImpl::get_ElementNAME_SADR_STREET(void)
{
return Object->ElementNAME_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementNAME_SADR_STREET(TFIBWideStringField * ElementNAME_SADR_STREET)
{
Object->ElementNAME_SADR_STREET=ElementNAME_SADR_STREET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressKVImpl::get_ElementPOSTCODE_SADR_STREET(void)
{
return Object->ElementPOSTCODE_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementPOSTCODE_SADR_STREET(TFIBWideStringField * ElementPOSTCODE_SADR_STREET)
{
Object->ElementPOSTCODE_SADR_STREET=ElementPOSTCODE_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDNASPUNKT_SADR_STREET(void)
{
return Object->ElementIDNASPUNKT_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDNASPUNKT_SADR_STREET(TFIBLargeIntField * ElementIDNASPUNKT_SADR_STREET)
{
Object->ElementIDNASPUNKT_SADR_STREET=ElementIDNASPUNKT_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementID_SADR_NASPUNKT(void)
{
return Object->ElementID_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementID_SADR_NASPUNKT(TFIBLargeIntField * ElementID_SADR_NASPUNKT)
{
Object->ElementID_SADR_NASPUNKT=ElementID_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDBASE_SADR_NASPUNKT(void)
{
return Object->ElementIDBASE_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDBASE_SADR_NASPUNKT(TFIBLargeIntField * ElementIDBASE_SADR_NASPUNKT)
{
Object->ElementIDBASE_SADR_NASPUNKT=ElementIDBASE_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDRAYON_SADR_NASPUNKT(void)
{
return Object->ElementIDRAYON_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDRAYON_SADR_NASPUNKT(TFIBLargeIntField * ElementIDRAYON_SADR_NASPUNKT)
{
Object->ElementIDRAYON_SADR_NASPUNKT=ElementIDRAYON_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressKVImpl::get_ElementNAME_SADR_NASPUNKT(void)
{
return Object->ElementNAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementNAME_SADR_NASPUNKT(TFIBWideStringField * ElementNAME_SADR_NASPUNKT)
{
Object->ElementNAME_SADR_NASPUNKT=ElementNAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprAddressKVImpl::get_ElementFL_GOROD_SADR_NASPUNKT(void)
{
return Object->ElementFL_GOROD_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementFL_GOROD_SADR_NASPUNKT(TFIBIntegerField * ElementFL_GOROD_SADR_NASPUNKT)
{
Object->ElementFL_GOROD_SADR_NASPUNKT=ElementFL_GOROD_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementID_SADR_RAYON(void)
{
return Object->ElementID_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementID_SADR_RAYON(TFIBLargeIntField * ElementID_SADR_RAYON)
{
Object->ElementID_SADR_RAYON=ElementID_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDBASE_SADR_RAYON(void)
{
return Object->ElementIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDBASE_SADR_RAYON(TFIBLargeIntField * ElementIDBASE_SADR_RAYON)
{
Object->ElementIDBASE_SADR_RAYON=ElementIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDREGION_SADR_RAYON(void)
{
return Object->ElementIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDREGION_SADR_RAYON(TFIBLargeIntField * ElementIDREGION_SADR_RAYON)
{
Object->ElementIDREGION_SADR_RAYON=ElementIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressKVImpl::get_ElementNAME_SADR_RAYON(void)
{
return Object->ElementNAME_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementNAME_SADR_RAYON(TFIBWideStringField * ElementNAME_SADR_RAYON)
{
Object->ElementNAME_SADR_RAYON=ElementNAME_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementID_SADR_REGION(void)
{
return Object->ElementID_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementID_SADR_REGION(TFIBLargeIntField * ElementID_SADR_REGION)
{
Object->ElementID_SADR_REGION=ElementID_SADR_REGION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressKVImpl::get_ElementIDBASE_SADR_REGION(void)
{
return Object->ElementIDBASE_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementIDBASE_SADR_REGION(TFIBLargeIntField * ElementIDBASE_SADR_REGION)
{
Object->ElementIDBASE_SADR_REGION=ElementIDBASE_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressKVImpl::get_ElementNAME_SADR_REGION(void)
{
return Object->ElementNAME_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementNAME_SADR_REGION(TFIBWideStringField * ElementNAME_SADR_REGION)
{
Object->ElementNAME_SADR_REGION=ElementNAME_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressKVImpl::get_ElementCODE_SADR_REGION(void)
{
return Object->ElementCODE_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_ElementCODE_SADR_REGION(TFIBWideStringField * ElementCODE_SADR_REGION)
{
Object->ElementCODE_SADR_REGION=ElementCODE_SADR_REGION;
}
//---------------------------------------------------------------
__int64 TDMSprAddressKVImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
__int64 TDMSprAddressKVImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprAddressKVImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
bool TDMSprAddressKVImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
int TDMSprAddressKVImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprAddressKVImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprAddressKVImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
