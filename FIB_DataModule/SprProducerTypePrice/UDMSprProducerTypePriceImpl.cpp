#include "vcl.h"
#pragma hdrstop


#include "UDMSprProducerTypePriceImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprProducerTypePriceImpl::TDMSprProducerTypePriceImpl()           
{                                            
Object=new TDMSprProducerTypePrice(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprProducerTypePriceImpl::~TDMSprProducerTypePriceImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprProducerTypePriceImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprProducerTypePrice)                        
   {                                                                     
   *ppv=static_cast<IDMSprProducerTypePrice*> (this);                                
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
int TDMSprProducerTypePriceImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprProducerTypePriceImpl::kanRelease(void)                                  
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
int  TDMSprProducerTypePriceImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprProducerTypePriceImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprProducerTypePriceImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprProducerTypePriceImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprProducerTypePriceImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprProducerTypePrice
TDataSource * TDMSprProducerTypePriceImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprProducerTypePriceImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerTypePriceImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerTypePriceImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProducerTypePriceImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProducerTypePriceImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprProducerTypePriceImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprProducerTypePriceImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerTypePriceImpl::get_TableID_SPRTYPE_PRICE(void)
{
return Object->TableID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_TableID_SPRTYPE_PRICE(TFIBLargeIntField * TableID_SPRTYPE_PRICE)
{
Object->TableID_SPRTYPE_PRICE=TableID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerTypePriceImpl::get_TableIDBASE_SPRTYPE_PRICE(void)
{
return Object->TableIDBASE_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_TableIDBASE_SPRTYPE_PRICE(TFIBLargeIntField * TableIDBASE_SPRTYPE_PRICE)
{
Object->TableIDBASE_SPRTYPE_PRICE=TableIDBASE_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerTypePriceImpl::get_TableGID_SPRTYPE_PRICE(void)
{
return Object->TableGID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_TableGID_SPRTYPE_PRICE(TFIBWideStringField * TableGID_SPRTYPE_PRICE)
{
Object->TableGID_SPRTYPE_PRICE=TableGID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerTypePriceImpl::get_TableNAME_SPRTYPE_PRICE(void)
{
return Object->TableNAME_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_TableNAME_SPRTYPE_PRICE(TFIBWideStringField * TableNAME_SPRTYPE_PRICE)
{
Object->TableNAME_SPRTYPE_PRICE=TableNAME_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerTypePriceImpl::get_ElementID_SPRTYPE_PRICE(void)
{
return Object->ElementID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_ElementID_SPRTYPE_PRICE(TFIBLargeIntField * ElementID_SPRTYPE_PRICE)
{
Object->ElementID_SPRTYPE_PRICE=ElementID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerTypePriceImpl::get_ElementIDBASE_SPRTYPE_PRICE(void)
{
return Object->ElementIDBASE_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_ElementIDBASE_SPRTYPE_PRICE(TFIBLargeIntField * ElementIDBASE_SPRTYPE_PRICE)
{
Object->ElementIDBASE_SPRTYPE_PRICE=ElementIDBASE_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerTypePriceImpl::get_ElementGID_SPRTYPE_PRICE(void)
{
return Object->ElementGID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_ElementGID_SPRTYPE_PRICE(TFIBWideStringField * ElementGID_SPRTYPE_PRICE)
{
Object->ElementGID_SPRTYPE_PRICE=ElementGID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerTypePriceImpl::get_ElementNAME_SPRTYPE_PRICE(void)
{
return Object->ElementNAME_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::set_ElementNAME_SPRTYPE_PRICE(TFIBWideStringField * ElementNAME_SPRTYPE_PRICE)
{
Object->ElementNAME_SPRTYPE_PRICE=ElementNAME_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
bool TDMSprProducerTypePriceImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
bool TDMSprProducerTypePriceImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprProducerTypePriceImpl::NewElement()
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprProducerTypePriceImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprProducerTypePriceImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TDMSprProducerTypePriceImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprProducerTypePriceImpl::GetIdElementPoName(UnicodeString   name)
{
return Object->GetIdElementPoName( name);
}
//---------------------------------------------------------------
int TDMSprProducerTypePriceImpl::GetIndexInTablePoId(__int64 id_element)
{
return Object->GetIndexInTablePoId(id_element);
}
//---------------------------------------------------------------
__int64 TDMSprProducerTypePriceImpl::GetIdElementPoGid(UnicodeString gid)
{
return Object->GetIdElementPoGid(gid);
}
//---------------------------------------------------------------
UnicodeString TDMSprProducerTypePriceImpl::GetGidElementPoId(__int64 id)
{
return Object->GetGidElementPoId(id);
}
//---------------------------------------------------------------
