#include "vcl.h"
#pragma hdrstop


#include "UDMSprAddressDomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprAddressDomImpl::TDMSprAddressDomImpl()           
{                                            
Object=new TDMSprAddressDom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprAddressDomImpl::~TDMSprAddressDomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprAddressDomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprAddressDomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprAddressDom)                        
   {                                                                     
   *ppv=static_cast<IDMSprAddressDom*> (this);                                
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
int TDMSprAddressDomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprAddressDomImpl::kanRelease(void)                                  
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
int  TDMSprAddressDomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprAddressDomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprAddressDomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprAddressDomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprAddressDomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprAddressDom
TDataSource * TDMSprAddressDomImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprAddressDomImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprAddressDomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprAddressDomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TDMSprAddressDomImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprAddressDomImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprAddressDomImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_TableID_SADR_DOM(void)
{
return Object->TableID_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_TableID_SADR_DOM(TFIBLargeIntField * TableID_SADR_DOM)
{
Object->TableID_SADR_DOM=TableID_SADR_DOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_TableIDBASE_SADR_DOM(void)
{
return Object->TableIDBASE_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_TableIDBASE_SADR_DOM(TFIBLargeIntField * TableIDBASE_SADR_DOM)
{
Object->TableIDBASE_SADR_DOM=TableIDBASE_SADR_DOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_TableIDSTREET_SADR_DOM(void)
{
return Object->TableIDSTREET_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_TableIDSTREET_SADR_DOM(TFIBLargeIntField * TableIDSTREET_SADR_DOM)
{
Object->TableIDSTREET_SADR_DOM=TableIDSTREET_SADR_DOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressDomImpl::get_TableNAME_SADR_DOM(void)
{
return Object->TableNAME_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_TableNAME_SADR_DOM(TFIBWideStringField * TableNAME_SADR_DOM)
{
Object->TableNAME_SADR_DOM=TableNAME_SADR_DOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementID_SADR_DOM(void)
{
return Object->ElementID_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementID_SADR_DOM(TFIBLargeIntField * ElementID_SADR_DOM)
{
Object->ElementID_SADR_DOM=ElementID_SADR_DOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementIDBASE_SADR_DOM(void)
{
return Object->ElementIDBASE_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementIDBASE_SADR_DOM(TFIBLargeIntField * ElementIDBASE_SADR_DOM)
{
Object->ElementIDBASE_SADR_DOM=ElementIDBASE_SADR_DOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementIDSTREET_SADR_DOM(void)
{
return Object->ElementIDSTREET_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementIDSTREET_SADR_DOM(TFIBLargeIntField * ElementIDSTREET_SADR_DOM)
{
Object->ElementIDSTREET_SADR_DOM=ElementIDSTREET_SADR_DOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressDomImpl::get_ElementNAME_SADR_DOM(void)
{
return Object->ElementNAME_SADR_DOM;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementNAME_SADR_DOM(TFIBWideStringField * ElementNAME_SADR_DOM)
{
Object->ElementNAME_SADR_DOM=ElementNAME_SADR_DOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementID_SADR_STREET(void)
{
return Object->ElementID_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementID_SADR_STREET(TFIBLargeIntField * ElementID_SADR_STREET)
{
Object->ElementID_SADR_STREET=ElementID_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementIDBASE_SADR_STREET(void)
{
return Object->ElementIDBASE_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementIDBASE_SADR_STREET(TFIBLargeIntField * ElementIDBASE_SADR_STREET)
{
Object->ElementIDBASE_SADR_STREET=ElementIDBASE_SADR_STREET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressDomImpl::get_ElementNAME_SADR_STREET(void)
{
return Object->ElementNAME_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementNAME_SADR_STREET(TFIBWideStringField * ElementNAME_SADR_STREET)
{
Object->ElementNAME_SADR_STREET=ElementNAME_SADR_STREET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressDomImpl::get_ElementPOSTCODE_SADR_STREET(void)
{
return Object->ElementPOSTCODE_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementPOSTCODE_SADR_STREET(TFIBWideStringField * ElementPOSTCODE_SADR_STREET)
{
Object->ElementPOSTCODE_SADR_STREET=ElementPOSTCODE_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementIDNASPUNKT_SADR_STREET(void)
{
return Object->ElementIDNASPUNKT_SADR_STREET;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementIDNASPUNKT_SADR_STREET(TFIBLargeIntField * ElementIDNASPUNKT_SADR_STREET)
{
Object->ElementIDNASPUNKT_SADR_STREET=ElementIDNASPUNKT_SADR_STREET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementID_SADR_NASPUNKT(void)
{
return Object->ElementID_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementID_SADR_NASPUNKT(TFIBLargeIntField * ElementID_SADR_NASPUNKT)
{
Object->ElementID_SADR_NASPUNKT=ElementID_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementIDBASE_SADR_NASPUNKT(void)
{
return Object->ElementIDBASE_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementIDBASE_SADR_NASPUNKT(TFIBLargeIntField * ElementIDBASE_SADR_NASPUNKT)
{
Object->ElementIDBASE_SADR_NASPUNKT=ElementIDBASE_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementIDRAYON_SADR_NASPUNKT(void)
{
return Object->ElementIDRAYON_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementIDRAYON_SADR_NASPUNKT(TFIBLargeIntField * ElementIDRAYON_SADR_NASPUNKT)
{
Object->ElementIDRAYON_SADR_NASPUNKT=ElementIDRAYON_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressDomImpl::get_ElementNAME_SADR_NASPUNKT(void)
{
return Object->ElementNAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementNAME_SADR_NASPUNKT(TFIBWideStringField * ElementNAME_SADR_NASPUNKT)
{
Object->ElementNAME_SADR_NASPUNKT=ElementNAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprAddressDomImpl::get_ElementFL_GOROD_SADR_NASPUNKT(void)
{
return Object->ElementFL_GOROD_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementFL_GOROD_SADR_NASPUNKT(TFIBIntegerField * ElementFL_GOROD_SADR_NASPUNKT)
{
Object->ElementFL_GOROD_SADR_NASPUNKT=ElementFL_GOROD_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementID_SADR_RAYON(void)
{
return Object->ElementID_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementID_SADR_RAYON(TFIBLargeIntField * ElementID_SADR_RAYON)
{
Object->ElementID_SADR_RAYON=ElementID_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementIDBASE_SADR_RAYON(void)
{
return Object->ElementIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementIDBASE_SADR_RAYON(TFIBLargeIntField * ElementIDBASE_SADR_RAYON)
{
Object->ElementIDBASE_SADR_RAYON=ElementIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementIDREGION_SADR_RAYON(void)
{
return Object->ElementIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementIDREGION_SADR_RAYON(TFIBLargeIntField * ElementIDREGION_SADR_RAYON)
{
Object->ElementIDREGION_SADR_RAYON=ElementIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressDomImpl::get_ElementNAME_SADR_RAYON(void)
{
return Object->ElementNAME_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementNAME_SADR_RAYON(TFIBWideStringField * ElementNAME_SADR_RAYON)
{
Object->ElementNAME_SADR_RAYON=ElementNAME_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementID_SADR_REGION(void)
{
return Object->ElementID_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementID_SADR_REGION(TFIBLargeIntField * ElementID_SADR_REGION)
{
Object->ElementID_SADR_REGION=ElementID_SADR_REGION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressDomImpl::get_ElementIDBASE_SADR_REGION(void)
{
return Object->ElementIDBASE_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementIDBASE_SADR_REGION(TFIBLargeIntField * ElementIDBASE_SADR_REGION)
{
Object->ElementIDBASE_SADR_REGION=ElementIDBASE_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressDomImpl::get_ElementNAME_SADR_REGION(void)
{
return Object->ElementNAME_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementNAME_SADR_REGION(TFIBWideStringField * ElementNAME_SADR_REGION)
{
Object->ElementNAME_SADR_REGION=ElementNAME_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressDomImpl::get_ElementCODE_SADR_REGION(void)
{
return Object->ElementCODE_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_ElementCODE_SADR_REGION(TFIBWideStringField * ElementCODE_SADR_REGION)
{
Object->ElementCODE_SADR_REGION=ElementCODE_SADR_REGION;
}
//---------------------------------------------------------------
__int64 TDMSprAddressDomImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
__int64 TDMSprAddressDomImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprAddressDomImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
bool TDMSprAddressDomImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
int TDMSprAddressDomImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprAddressDomImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprAddressDomImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
