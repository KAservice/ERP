#include "vcl.h"
#pragma hdrstop


#include "UNameModulEditImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TNameModulEditImpl::TNameModulEditImpl()           
{                                            
Object=new TNameModulEdit(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TNameModulEditImpl::~TNameModulEditImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TNameModulEditImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TNameModulEditImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_INameModulEdit)                        
   {                                                                     
   *ppv=static_cast<INameModulEdit*> (this);                                
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
int TNameModulEditImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TNameModulEditImpl::kanRelease(void)                                  
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
int  TNameModulEditImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TNameModulEditImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TNameModulEditImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TNameModulEditImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TNameModulEditImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TNameModulEditImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TNameModulEditImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit
TDataSource * TNameModulEditImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TNameModulEditImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TNameModulEditImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TNameModulEditImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TNameModulEditImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TNameModulEditImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TNameModulEditImpl::get_SpTPrice(void)
{
return Object->SpTPrice;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_SpTPrice(TpFIBDataSet * SpTPrice)
{
Object->SpTPrice=SpTPrice;
}
//---------------------------------------------------------------
TDataSource * TNameModulEditImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TFIBLargeIntField * TNameModulEditImpl::get_ElementID_SPRNOM(void)
{
return Object->ElementID_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_ElementID_SPRNOM(TFIBLargeIntField * ElementID_SPRNOM)
{
Object->ElementID_SPRNOM=ElementID_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TNameModulEditImpl::get_ElementIDBASE_SPRNOM(void)
{
return Object->ElementIDBASE_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_ElementIDBASE_SPRNOM(TFIBLargeIntField * ElementIDBASE_SPRNOM)
{
Object->ElementIDBASE_SPRNOM=ElementIDBASE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TNameModulEditImpl::get_ElementGID_SPRNOM(void)
{
return Object->ElementGID_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_ElementGID_SPRNOM(TFIBWideStringField * ElementGID_SPRNOM)
{
Object->ElementGID_SPRNOM=ElementGID_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TNameModulEditImpl::get_ElementIDPROD_SPRNOM(void)
{
return Object->ElementIDPROD_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_ElementIDPROD_SPRNOM(TFIBLargeIntField * ElementIDPROD_SPRNOM)
{
Object->ElementIDPROD_SPRNOM=ElementIDPROD_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TNameModulEditImpl::get_ElementIDGRP_SPRNOM(void)
{
return Object->ElementIDGRP_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_ElementIDGRP_SPRNOM(TFIBLargeIntField * ElementIDGRP_SPRNOM)
{
Object->ElementIDGRP_SPRNOM=ElementIDGRP_SPRNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TNameModulEditImpl::get_ElementCODE_SPRNOM(void)
{
return Object->ElementCODE_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_ElementCODE_SPRNOM(TFIBIntegerField * ElementCODE_SPRNOM)
{
Object->ElementCODE_SPRNOM=ElementCODE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TNameModulEditImpl::get_ElementART_SPRNOM(void)
{
return Object->ElementART_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_ElementART_SPRNOM(TFIBWideStringField * ElementART_SPRNOM)
{
Object->ElementART_SPRNOM=ElementART_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TNameModulEditImpl::get_ElementNAME_SPRNOM(void)
{
return Object->ElementNAME_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_ElementNAME_SPRNOM(TFIBWideStringField * ElementNAME_SPRNOM)
{
Object->ElementNAME_SPRNOM=ElementNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TNameModulEditImpl::get_ElementKRNAME_SPRNOM(void)
{
return Object->ElementKRNAME_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_ElementKRNAME_SPRNOM(TFIBWideStringField * ElementKRNAME_SPRNOM)
{
Object->ElementKRNAME_SPRNOM=ElementKRNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TNameModulEditImpl::get_ElementFNAME_SPRNOM(void)
{
return Object->ElementFNAME_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_ElementFNAME_SPRNOM(TFIBWideStringField * ElementFNAME_SPRNOM)
{
Object->ElementFNAME_SPRNOM=ElementFNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TNameModulEditImpl::get_ElementTYPE_SPRNOM(void)
{
return Object->ElementTYPE_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_ElementTYPE_SPRNOM(TFIBIntegerField * ElementTYPE_SPRNOM)
{
Object->ElementTYPE_SPRNOM=ElementTYPE_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TNameModulEditImpl::get_ElementIDBASED_SPRNOM(void)
{
return Object->ElementIDBASED_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_ElementIDBASED_SPRNOM(TFIBLargeIntField * ElementIDBASED_SPRNOM)
{
Object->ElementIDBASED_SPRNOM=ElementIDBASED_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TNameModulEditImpl::get_TableID_SPRNOM(void)
{
return Object->TableID_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_TableID_SPRNOM(TFIBLargeIntField * TableID_SPRNOM)
{
Object->TableID_SPRNOM=TableID_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TNameModulEditImpl::get_TableIDGRP_SPRNOM(void)
{
return Object->TableIDGRP_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_TableIDGRP_SPRNOM(TFIBLargeIntField * TableIDGRP_SPRNOM)
{
Object->TableIDGRP_SPRNOM=TableIDGRP_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TNameModulEditImpl::get_TableIDPROD_SPRNOM(void)
{
return Object->TableIDPROD_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_TableIDPROD_SPRNOM(TFIBLargeIntField * TableIDPROD_SPRNOM)
{
Object->TableIDPROD_SPRNOM=TableIDPROD_SPRNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TNameModulEditImpl::get_TableCODE_SPRNOM(void)
{
return Object->TableCODE_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_TableCODE_SPRNOM(TFIBIntegerField * TableCODE_SPRNOM)
{
Object->TableCODE_SPRNOM=TableCODE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TNameModulEditImpl::get_TableART_SPRNOM(void)
{
return Object->TableART_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_TableART_SPRNOM(TFIBWideStringField * TableART_SPRNOM)
{
Object->TableART_SPRNOM=TableART_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TNameModulEditImpl::get_TableNAME_SPRNOM(void)
{
return Object->TableNAME_SPRNOM;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_TableNAME_SPRNOM(TFIBWideStringField * TableNAME_SPRNOM)
{
Object->TableNAME_SPRNOM=TableNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TNameModulEditImpl::get_TableNAME_SPRED(void)
{
return Object->TableNAME_SPRED;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_TableNAME_SPRED(TFIBWideStringField * TableNAME_SPRED)
{
Object->TableNAME_SPRED=TableNAME_SPRED;
}
//---------------------------------------------------------------
TFIBWideStringField * TNameModulEditImpl::get_TableBARCODE_SPRED(void)
{
return Object->TableBARCODE_SPRED;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_TableBARCODE_SPRED(TFIBWideStringField * TableBARCODE_SPRED)
{
Object->TableBARCODE_SPRED=TableBARCODE_SPRED;
}
//---------------------------------------------------------------
TFIBBCDField * TNameModulEditImpl::get_TableVALUE_SPRPRICE(void)
{
return Object->TableVALUE_SPRPRICE;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_TableVALUE_SPRPRICE(TFIBBCDField * TableVALUE_SPRPRICE)
{
Object->TableVALUE_SPRPRICE=TableVALUE_SPRPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TNameModulEditImpl::get_SpTPriceID_SPRTYPE_PRICE(void)
{
return Object->SpTPriceID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_SpTPriceID_SPRTYPE_PRICE(TFIBLargeIntField * SpTPriceID_SPRTYPE_PRICE)
{
Object->SpTPriceID_SPRTYPE_PRICE=SpTPriceID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TNameModulEditImpl::get_SpTPriceNAME_SPRTYPE_PRICE(void)
{
return Object->SpTPriceNAME_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_SpTPriceNAME_SPRTYPE_PRICE(TFIBWideStringField * SpTPriceNAME_SPRTYPE_PRICE)
{
Object->SpTPriceNAME_SPRTYPE_PRICE=SpTPriceNAME_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
__int64 TNameModulEditImpl::get_IdProducer(void)
{
return Object->IdProducer;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_IdProducer(__int64 IdProducer)
{
Object->IdProducer=IdProducer;
}
//---------------------------------------------------------------
__int64 TNameModulEditImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TNameModulEditImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TNameModulEditImpl::get_IdProducerTypePrice(void)
{
return Object->IdProducerTypePrice;
}
//---------------------------------------------------------------
void TNameModulEditImpl::set_IdProducerTypePrice(__int64 IdProducerTypePrice)
{
Object->IdProducerTypePrice=IdProducerTypePrice;
}
//---------------------------------------------------------------
void TNameModulEditImpl::OpenTable(__int64 id_producer, __int64 id_grp, __int64 id_producer_type_price, bool all)
{
return Object->OpenTable(__int64 id_producer, __int64 id_grp, __int64 id_producer_type_price, bool all);
}
//---------------------------------------------------------------
bool TNameModulEditImpl::NewElement(__int64 id_producer, __int64 id_grp)
{
return Object->NewElement(__int64 id_producer, __int64 id_grp);
}
//---------------------------------------------------------------
bool TNameModulEditImpl::OpenElement(__int64 id)
{
return Object->OpenElement(__int64 id);
}
//---------------------------------------------------------------
bool TNameModulEditImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(__int64 id);
}
//---------------------------------------------------------------
bool TNameModulEditImpl::SaveElement(void)
{
return Object->SaveElement(void);
}
//---------------------------------------------------------------
void TNameModulEditImpl::ChancheGrp(__int64 id_new_grp,__int64 id_producer_nom)
{
return Object->ChancheGrp(__int64 id_new_grp,__int64 id_producer_nom);
}
//---------------------------------------------------------------
