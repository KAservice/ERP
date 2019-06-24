#include "vcl.h"
#pragma hdrstop


#include "UDMSprProducerPriceImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprProducerPriceImpl::TDMSprProducerPriceImpl()           
{                                            
Object=new TDMSprProducerPrice(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprProducerPriceImpl::~TDMSprProducerPriceImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprProducerPriceImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprProducerPrice)                        
   {                                                                     
   *ppv=static_cast<IDMSprProducerPrice*> (this);                                
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
int TDMSprProducerPriceImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprProducerPriceImpl::kanRelease(void)                                  
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
int  TDMSprProducerPriceImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprProducerPriceImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprProducerPriceImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprProducerPriceImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprProducerPriceImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprProducerPrice
TDataSource * TDMSprProducerPriceImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerPriceImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerPriceImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProducerPriceImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProducerPriceImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerPriceImpl::get_TPrice(void)
{
return Object->TPrice;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_TPrice(TpFIBDataSet * TPrice)
{
Object->TPrice=TPrice;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprProducerPriceImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerPriceImpl::get_TPriceID_SPRTYPE_PRICE(void)
{
return Object->TPriceID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_TPriceID_SPRTYPE_PRICE(TFIBLargeIntField * TPriceID_SPRTYPE_PRICE)
{
Object->TPriceID_SPRTYPE_PRICE=TPriceID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerPriceImpl::get_TPriceNAME_SPRTYPE_PRICE(void)
{
return Object->TPriceNAME_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_TPriceNAME_SPRTYPE_PRICE(TFIBWideStringField * TPriceNAME_SPRTYPE_PRICE)
{
Object->TPriceNAME_SPRTYPE_PRICE=TPriceNAME_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerPriceImpl::get_TableID_SPRPRICE(void)
{
return Object->TableID_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_TableID_SPRPRICE(TFIBLargeIntField * TableID_SPRPRICE)
{
Object->TableID_SPRPRICE=TableID_SPRPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerPriceImpl::get_TableIDBASE_SPRPRICE(void)
{
return Object->TableIDBASE_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_TableIDBASE_SPRPRICE(TFIBLargeIntField * TableIDBASE_SPRPRICE)
{
Object->TableIDBASE_SPRPRICE=TableIDBASE_SPRPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerPriceImpl::get_TableGID_SPRPRICE(void)
{
return Object->TableGID_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_TableGID_SPRPRICE(TFIBWideStringField * TableGID_SPRPRICE)
{
Object->TableGID_SPRPRICE=TableGID_SPRPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerPriceImpl::get_TableIDPRNOM_SPRPRICE(void)
{
return Object->TableIDPRNOM_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_TableIDPRNOM_SPRPRICE(TFIBLargeIntField * TableIDPRNOM_SPRPRICE)
{
Object->TableIDPRNOM_SPRPRICE=TableIDPRNOM_SPRPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerPriceImpl::get_TableIDPRTPRICE_SPRPRICE(void)
{
return Object->TableIDPRTPRICE_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_TableIDPRTPRICE_SPRPRICE(TFIBLargeIntField * TableIDPRTPRICE_SPRPRICE)
{
Object->TableIDPRTPRICE_SPRPRICE=TableIDPRTPRICE_SPRPRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerPriceImpl::get_TableVALUE_SPRPRICE(void)
{
return Object->TableVALUE_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_TableVALUE_SPRPRICE(TFIBBCDField * TableVALUE_SPRPRICE)
{
Object->TableVALUE_SPRPRICE=TableVALUE_SPRPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerPriceImpl::get_TableNAME_SPRTYPE_PRICE(void)
{
return Object->TableNAME_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_TableNAME_SPRTYPE_PRICE(TFIBWideStringField * TableNAME_SPRTYPE_PRICE)
{
Object->TableNAME_SPRTYPE_PRICE=TableNAME_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerPriceImpl::get_ElementID_SPRPRICE(void)
{
return Object->ElementID_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_ElementID_SPRPRICE(TFIBBCDField * ElementID_SPRPRICE)
{
Object->ElementID_SPRPRICE=ElementID_SPRPRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerPriceImpl::get_ElementIDBASE_SPRPRICE(void)
{
return Object->ElementIDBASE_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_ElementIDBASE_SPRPRICE(TFIBBCDField * ElementIDBASE_SPRPRICE)
{
Object->ElementIDBASE_SPRPRICE=ElementIDBASE_SPRPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerPriceImpl::get_ElementGID_SPRPRICE(void)
{
return Object->ElementGID_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_ElementGID_SPRPRICE(TFIBWideStringField * ElementGID_SPRPRICE)
{
Object->ElementGID_SPRPRICE=ElementGID_SPRPRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerPriceImpl::get_ElementIDPRNOM_SPRPRICE(void)
{
return Object->ElementIDPRNOM_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_ElementIDPRNOM_SPRPRICE(TFIBBCDField * ElementIDPRNOM_SPRPRICE)
{
Object->ElementIDPRNOM_SPRPRICE=ElementIDPRNOM_SPRPRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerPriceImpl::get_ElementIDPRTPRICE_SPRPRICE(void)
{
return Object->ElementIDPRTPRICE_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_ElementIDPRTPRICE_SPRPRICE(TFIBBCDField * ElementIDPRTPRICE_SPRPRICE)
{
Object->ElementIDPRTPRICE_SPRPRICE=ElementIDPRTPRICE_SPRPRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerPriceImpl::get_ElementVALUE_SPRPRICE(void)
{
return Object->ElementVALUE_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_ElementVALUE_SPRPRICE(TFIBBCDField * ElementVALUE_SPRPRICE)
{
Object->ElementVALUE_SPRPRICE=ElementVALUE_SPRPRICE;
}
//---------------------------------------------------------------
__int64 TDMSprProducerPriceImpl::get_IdProducerNom(void)
{
return Object->IdProducerNom;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_IdProducerNom(__int64 IdProducerNom)
{
Object->IdProducerNom=IdProducerNom;
}
//---------------------------------------------------------------
__int64 TDMSprProducerPriceImpl::get_IdProducerTypePrice(void)
{
return Object->IdProducerTypePrice;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::set_IdProducerTypePrice(__int64 IdProducerTypePrice)
{
Object->IdProducerTypePrice=IdProducerTypePrice;
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::OpenTable(__int64 id_producer_nom)
{
return Object->OpenTable(id_producer_nom);
}
//---------------------------------------------------------------
bool TDMSprProducerPriceImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
int TDMSprProducerPriceImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprProducerPriceImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprProducerPriceImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprProducerPriceImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprProducerPriceImpl::FindElement(__int64 id_producer_type_price, __int64 id_producer_nom)
{
return Object->FindElement(id_producer_type_price,id_producer_nom);
}
//---------------------------------------------------------------

