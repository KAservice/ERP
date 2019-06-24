#include "vcl.h"
#pragma hdrstop


#include "UDMSprAddressNasPunktImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprAddressNasPunktImpl::TDMSprAddressNasPunktImpl()           
{                                            
Object=new TDMSprAddressNasPunkt(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprAddressNasPunktImpl::~TDMSprAddressNasPunktImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprAddressNasPunktImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprAddressNasPunkt)                        
   {                                                                     
   *ppv=static_cast<IDMSprAddressNasPunkt*> (this);                                
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
int TDMSprAddressNasPunktImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprAddressNasPunktImpl::kanRelease(void)                                  
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
int  TDMSprAddressNasPunktImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprAddressNasPunktImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprAddressNasPunktImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprAddressNasPunktImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprAddressNasPunktImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprAddressNasPunkt
TDataSource * TDMSprAddressNasPunktImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprAddressNasPunktImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprAddressNasPunktImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprAddressNasPunktImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TDMSprAddressNasPunktImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprAddressNasPunktImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprAddressNasPunktImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressNasPunktImpl::get_TableID_SADR_NASPUNKT(void)
{
return Object->TableID_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_TableID_SADR_NASPUNKT(TFIBLargeIntField * TableID_SADR_NASPUNKT)
{
Object->TableID_SADR_NASPUNKT=TableID_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressNasPunktImpl::get_TableIDBASE_SADR_NASPUNKT(void)
{
return Object->TableIDBASE_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_TableIDBASE_SADR_NASPUNKT(TFIBLargeIntField * TableIDBASE_SADR_NASPUNKT)
{
Object->TableIDBASE_SADR_NASPUNKT=TableIDBASE_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressNasPunktImpl::get_TableIDRAYON_SADR_NASPUNKT(void)
{
return Object->TableIDRAYON_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_TableIDRAYON_SADR_NASPUNKT(TFIBLargeIntField * TableIDRAYON_SADR_NASPUNKT)
{
Object->TableIDRAYON_SADR_NASPUNKT=TableIDRAYON_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressNasPunktImpl::get_TableNAME_SADR_NASPUNKT(void)
{
return Object->TableNAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_TableNAME_SADR_NASPUNKT(TFIBWideStringField * TableNAME_SADR_NASPUNKT)
{
Object->TableNAME_SADR_NASPUNKT=TableNAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprAddressNasPunktImpl::get_TableFL_GOROD_SADR_NASPUNKT(void)
{
return Object->TableFL_GOROD_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_TableFL_GOROD_SADR_NASPUNKT(TFIBIntegerField * TableFL_GOROD_SADR_NASPUNKT)
{
Object->TableFL_GOROD_SADR_NASPUNKT=TableFL_GOROD_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressNasPunktImpl::get_ElementID_SADR_NASPUNKT(void)
{
return Object->ElementID_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementID_SADR_NASPUNKT(TFIBLargeIntField * ElementID_SADR_NASPUNKT)
{
Object->ElementID_SADR_NASPUNKT=ElementID_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressNasPunktImpl::get_ElementIDBASE_SADR_NASPUNKT(void)
{
return Object->ElementIDBASE_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementIDBASE_SADR_NASPUNKT(TFIBLargeIntField * ElementIDBASE_SADR_NASPUNKT)
{
Object->ElementIDBASE_SADR_NASPUNKT=ElementIDBASE_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressNasPunktImpl::get_ElementIDRAYON_SADR_NASPUNKT(void)
{
return Object->ElementIDRAYON_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementIDRAYON_SADR_NASPUNKT(TFIBLargeIntField * ElementIDRAYON_SADR_NASPUNKT)
{
Object->ElementIDRAYON_SADR_NASPUNKT=ElementIDRAYON_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressNasPunktImpl::get_ElementNAME_SADR_NASPUNKT(void)
{
return Object->ElementNAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementNAME_SADR_NASPUNKT(TFIBWideStringField * ElementNAME_SADR_NASPUNKT)
{
Object->ElementNAME_SADR_NASPUNKT=ElementNAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprAddressNasPunktImpl::get_ElementFL_GOROD_SADR_NASPUNKT(void)
{
return Object->ElementFL_GOROD_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementFL_GOROD_SADR_NASPUNKT(TFIBIntegerField * ElementFL_GOROD_SADR_NASPUNKT)
{
Object->ElementFL_GOROD_SADR_NASPUNKT=ElementFL_GOROD_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressNasPunktImpl::get_ElementID_SADR_RAYON(void)
{
return Object->ElementID_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementID_SADR_RAYON(TFIBLargeIntField * ElementID_SADR_RAYON)
{
Object->ElementID_SADR_RAYON=ElementID_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressNasPunktImpl::get_ElementIDBASE_SADR_RAYON(void)
{
return Object->ElementIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementIDBASE_SADR_RAYON(TFIBLargeIntField * ElementIDBASE_SADR_RAYON)
{
Object->ElementIDBASE_SADR_RAYON=ElementIDBASE_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressNasPunktImpl::get_ElementIDREGION_SADR_RAYON(void)
{
return Object->ElementIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementIDREGION_SADR_RAYON(TFIBLargeIntField * ElementIDREGION_SADR_RAYON)
{
Object->ElementIDREGION_SADR_RAYON=ElementIDREGION_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressNasPunktImpl::get_ElementNAME_SADR_RAYON(void)
{
return Object->ElementNAME_SADR_RAYON;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementNAME_SADR_RAYON(TFIBWideStringField * ElementNAME_SADR_RAYON)
{
Object->ElementNAME_SADR_RAYON=ElementNAME_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressNasPunktImpl::get_ElementID_SADR_REGION(void)
{
return Object->ElementID_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementID_SADR_REGION(TFIBLargeIntField * ElementID_SADR_REGION)
{
Object->ElementID_SADR_REGION=ElementID_SADR_REGION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprAddressNasPunktImpl::get_ElementIDBASE_SADR_REGION(void)
{
return Object->ElementIDBASE_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementIDBASE_SADR_REGION(TFIBLargeIntField * ElementIDBASE_SADR_REGION)
{
Object->ElementIDBASE_SADR_REGION=ElementIDBASE_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressNasPunktImpl::get_ElementNAME_SADR_REGION(void)
{
return Object->ElementNAME_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementNAME_SADR_REGION(TFIBWideStringField * ElementNAME_SADR_REGION)
{
Object->ElementNAME_SADR_REGION=ElementNAME_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprAddressNasPunktImpl::get_ElementCODE_SADR_REGION(void)
{
return Object->ElementCODE_SADR_REGION;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_ElementCODE_SADR_REGION(TFIBWideStringField * ElementCODE_SADR_REGION)
{
Object->ElementCODE_SADR_REGION=ElementCODE_SADR_REGION;
}
//---------------------------------------------------------------
__int64 TDMSprAddressNasPunktImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
__int64 TDMSprAddressNasPunktImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprAddressNasPunktImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
bool TDMSprAddressNasPunktImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
int TDMSprAddressNasPunktImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprAddressNasPunktImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprAddressNasPunktImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
