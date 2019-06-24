#include "vcl.h"
#pragma hdrstop


#include "UDMSprProducerNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprProducerNomImpl::TDMSprProducerNomImpl()           
{                                            
Object=new TDMSprProducerNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprProducerNomImpl::~TDMSprProducerNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprProducerNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprProducerNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprProducerNom)                        
   {                                                                     
   *ppv=static_cast<IDMSprProducerNom*> (this);                                
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
int TDMSprProducerNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprProducerNomImpl::kanRelease(void)                                  
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
int  TDMSprProducerNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprProducerNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprProducerNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprProducerNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprProducerNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprProducerNom
TDataSource * TDMSprProducerNomImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerNomImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProducerNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProducerNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerNomImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TDMSprProducerNomImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerNomImpl::get_SpTPrice(void)
{
return Object->SpTPrice;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_SpTPrice(TpFIBDataSet * SpTPrice)
{
Object->SpTPrice=SpTPrice;
}
//---------------------------------------------------------------
TDataSource * TDMSprProducerNomImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomImpl::get_ElementID_SPRNOM(void)
{
return Object->ElementID_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementID_SPRNOM(TFIBLargeIntField * ElementID_SPRNOM)
{
Object->ElementID_SPRNOM=ElementID_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomImpl::get_ElementIDBASE_SPRNOM(void)
{
return Object->ElementIDBASE_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementIDBASE_SPRNOM(TFIBLargeIntField * ElementIDBASE_SPRNOM)
{
Object->ElementIDBASE_SPRNOM=ElementIDBASE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementGID_SPRNOM(void)
{
return Object->ElementGID_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementGID_SPRNOM(TFIBWideStringField * ElementGID_SPRNOM)
{
Object->ElementGID_SPRNOM=ElementGID_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomImpl::get_ElementIDPROD_SPRNOM(void)
{
return Object->ElementIDPROD_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementIDPROD_SPRNOM(TFIBLargeIntField * ElementIDPROD_SPRNOM)
{
Object->ElementIDPROD_SPRNOM=ElementIDPROD_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomImpl::get_ElementIDGRP_SPRNOM(void)
{
return Object->ElementIDGRP_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementIDGRP_SPRNOM(TFIBLargeIntField * ElementIDGRP_SPRNOM)
{
Object->ElementIDGRP_SPRNOM=ElementIDGRP_SPRNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProducerNomImpl::get_ElementCODE_SPRNOM(void)
{
return Object->ElementCODE_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementCODE_SPRNOM(TFIBIntegerField * ElementCODE_SPRNOM)
{
Object->ElementCODE_SPRNOM=ElementCODE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementART_SPRNOM(void)
{
return Object->ElementART_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementART_SPRNOM(TFIBWideStringField * ElementART_SPRNOM)
{
Object->ElementART_SPRNOM=ElementART_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementNAME_SPRNOM(void)
{
return Object->ElementNAME_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementNAME_SPRNOM(TFIBWideStringField * ElementNAME_SPRNOM)
{
Object->ElementNAME_SPRNOM=ElementNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementKRNAME_SPRNOM(void)
{
return Object->ElementKRNAME_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementKRNAME_SPRNOM(TFIBWideStringField * ElementKRNAME_SPRNOM)
{
Object->ElementKRNAME_SPRNOM=ElementKRNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementFNAME_SPRNOM(void)
{
return Object->ElementFNAME_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementFNAME_SPRNOM(TFIBWideStringField * ElementFNAME_SPRNOM)
{
Object->ElementFNAME_SPRNOM=ElementFNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProducerNomImpl::get_ElementTYPE_SPRNOM(void)
{
return Object->ElementTYPE_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementTYPE_SPRNOM(TFIBIntegerField * ElementTYPE_SPRNOM)
{
Object->ElementTYPE_SPRNOM=ElementTYPE_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomImpl::get_ElementIDBASED_SPRNOM(void)
{
return Object->ElementIDBASED_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementIDBASED_SPRNOM(TFIBLargeIntField * ElementIDBASED_SPRNOM)
{
Object->ElementIDBASED_SPRNOM=ElementIDBASED_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomImpl::get_TableID_SPRNOM(void)
{
return Object->TableID_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableID_SPRNOM(TFIBLargeIntField * TableID_SPRNOM)
{
Object->TableID_SPRNOM=TableID_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomImpl::get_TableIDGRP_SPRNOM(void)
{
return Object->TableIDGRP_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableIDGRP_SPRNOM(TFIBLargeIntField * TableIDGRP_SPRNOM)
{
Object->TableIDGRP_SPRNOM=TableIDGRP_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomImpl::get_TableIDPROD_SPRNOM(void)
{
return Object->TableIDPROD_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableIDPROD_SPRNOM(TFIBLargeIntField * TableIDPROD_SPRNOM)
{
Object->TableIDPROD_SPRNOM=TableIDPROD_SPRNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProducerNomImpl::get_TableCODE_SPRNOM(void)
{
return Object->TableCODE_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableCODE_SPRNOM(TFIBIntegerField * TableCODE_SPRNOM)
{
Object->TableCODE_SPRNOM=TableCODE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_TableART_SPRNOM(void)
{
return Object->TableART_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableART_SPRNOM(TFIBWideStringField * TableART_SPRNOM)
{
Object->TableART_SPRNOM=TableART_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_TableNAME_SPRNOM(void)
{
return Object->TableNAME_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableNAME_SPRNOM(TFIBWideStringField * TableNAME_SPRNOM)
{
Object->TableNAME_SPRNOM=TableNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_TableNAME_SPRED(void)
{
return Object->TableNAME_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableNAME_SPRED(TFIBWideStringField * TableNAME_SPRED)
{
Object->TableNAME_SPRED=TableNAME_SPRED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_TableBARCODE_SPRED(void)
{
return Object->TableBARCODE_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableBARCODE_SPRED(TFIBWideStringField * TableBARCODE_SPRED)
{
Object->TableBARCODE_SPRED=TableBARCODE_SPRED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerNomImpl::get_TableVALUE_SPRPRICE(void)
{
return Object->TableVALUE_SPRPRICE;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableVALUE_SPRPRICE(TFIBBCDField * TableVALUE_SPRPRICE)
{
Object->TableVALUE_SPRPRICE=TableVALUE_SPRPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomImpl::get_SpTPriceID_SPRTYPE_PRICE(void)
{
return Object->SpTPriceID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_SpTPriceID_SPRTYPE_PRICE(TFIBLargeIntField * SpTPriceID_SPRTYPE_PRICE)
{
Object->SpTPriceID_SPRTYPE_PRICE=SpTPriceID_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_SpTPriceNAME_SPRTYPE_PRICE(void)
{
return Object->SpTPriceNAME_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_SpTPriceNAME_SPRTYPE_PRICE(TFIBWideStringField * SpTPriceNAME_SPRTYPE_PRICE)
{
Object->SpTPriceNAME_SPRTYPE_PRICE=SpTPriceNAME_SPRTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_TableMODEL_STR_SPRNOM(void)
{
return Object->TableMODEL_STR_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableMODEL_STR_SPRNOM(TFIBWideStringField * TableMODEL_STR_SPRNOM)
{
Object->TableMODEL_STR_SPRNOM=TableMODEL_STR_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_TableCODE_ANALOG_STR_SPRNOM(void)
{
return Object->TableCODE_ANALOG_STR_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableCODE_ANALOG_STR_SPRNOM(TFIBWideStringField * TableCODE_ANALOG_STR_SPRNOM)
{
Object->TableCODE_ANALOG_STR_SPRNOM=TableCODE_ANALOG_STR_SPRNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprProducerNomImpl::get_TableFL_DOSTUPNO_SPRNOM(void)
{
return Object->TableFL_DOSTUPNO_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableFL_DOSTUPNO_SPRNOM(TFIBSmallIntField * TableFL_DOSTUPNO_SPRNOM)
{
Object->TableFL_DOSTUPNO_SPRNOM=TableFL_DOSTUPNO_SPRNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerNomImpl::get_TablePRICE_ZAKUP_SPRNOM(void)
{
return Object->TablePRICE_ZAKUP_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TablePRICE_ZAKUP_SPRNOM(TFIBBCDField * TablePRICE_ZAKUP_SPRNOM)
{
Object->TablePRICE_ZAKUP_SPRNOM=TablePRICE_ZAKUP_SPRNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerNomImpl::get_TablePRICE_SPRNOM(void)
{
return Object->TablePRICE_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TablePRICE_SPRNOM(TFIBBCDField * TablePRICE_SPRNOM)
{
Object->TablePRICE_SPRNOM=TablePRICE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementMODEL_STR_SPRNOM(void)
{
return Object->ElementMODEL_STR_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementMODEL_STR_SPRNOM(TFIBWideStringField * ElementMODEL_STR_SPRNOM)
{
Object->ElementMODEL_STR_SPRNOM=ElementMODEL_STR_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementCODE_ANALOG_STR_SPRNOM(void)
{
return Object->ElementCODE_ANALOG_STR_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementCODE_ANALOG_STR_SPRNOM(TFIBWideStringField * ElementCODE_ANALOG_STR_SPRNOM)
{
Object->ElementCODE_ANALOG_STR_SPRNOM=ElementCODE_ANALOG_STR_SPRNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprProducerNomImpl::get_ElementFL_DOSTUPNO_SPRNOM(void)
{
return Object->ElementFL_DOSTUPNO_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementFL_DOSTUPNO_SPRNOM(TFIBSmallIntField * ElementFL_DOSTUPNO_SPRNOM)
{
Object->ElementFL_DOSTUPNO_SPRNOM=ElementFL_DOSTUPNO_SPRNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerNomImpl::get_ElementPRICE_ZAKUP_SPRNOM(void)
{
return Object->ElementPRICE_ZAKUP_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementPRICE_ZAKUP_SPRNOM(TFIBBCDField * ElementPRICE_ZAKUP_SPRNOM)
{
Object->ElementPRICE_ZAKUP_SPRNOM=ElementPRICE_ZAKUP_SPRNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerNomImpl::get_ElementPRICE_SPRNOM(void)
{
return Object->ElementPRICE_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementPRICE_SPRNOM(TFIBBCDField * ElementPRICE_SPRNOM)
{
Object->ElementPRICE_SPRNOM=ElementPRICE_SPRNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProducerNomImpl::get_TableCODENOM(void)
{
return Object->TableCODENOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableCODENOM(TFIBIntegerField * TableCODENOM)
{
Object->TableCODENOM=TableCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_TableARTNOM(void)
{
return Object->TableARTNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableARTNOM(TFIBWideStringField * TableARTNOM)
{
Object->TableARTNOM=TableARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_TableSHED(void)
{
return Object->TableSHED;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableSHED(TFIBWideStringField * TableSHED)
{
Object->TableSHED=TableSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_TableNAMEED(void)
{
return Object->TableNAMEED;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableNAMEED(TFIBWideStringField * TableNAMEED)
{
Object->TableNAMEED=TableNAMEED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomImpl::get_ElementIDNOM_SPRNOM(void)
{
return Object->ElementIDNOM_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementIDNOM_SPRNOM(TFIBLargeIntField * ElementIDNOM_SPRNOM)
{
Object->ElementIDNOM_SPRNOM=ElementIDNOM_SPRNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProducerNomImpl::get_ElementCODENOM(void)
{
return Object->ElementCODENOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)
{
Object->ElementCODENOM=ElementCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementARTNOM(void)
{
return Object->ElementARTNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)
{
Object->ElementARTNOM=ElementARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementNAMENOM(void)
{
return Object->ElementNAMENOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)
{
Object->ElementNAMENOM=ElementNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementSHED(void)
{
return Object->ElementSHED;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementSHED(TFIBWideStringField * ElementSHED)
{
Object->ElementSHED=ElementSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementNAMEED(void)
{
return Object->ElementNAMEED;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementNAMEED(TFIBWideStringField * ElementNAMEED)
{
Object->ElementNAMEED=ElementNAMEED;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprProducerNomImpl::get_pFIBQuery(void)
{
return Object->pFIBQuery;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_pFIBQuery(TpFIBQuery * pFIBQuery)
{
Object->pFIBQuery=pFIBQuery;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprProducerNomImpl::get_ElementISM_SPRNOM(void)
{
return Object->ElementISM_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementISM_SPRNOM(TFIBDateTimeField * ElementISM_SPRNOM)
{
Object->ElementISM_SPRNOM=ElementISM_SPRNOM;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprProducerNomImpl::get_TableISM_SPRNOM(void)
{
return Object->TableISM_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableISM_SPRNOM(TFIBDateTimeField * TableISM_SPRNOM)
{
Object->TableISM_SPRNOM=TableISM_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementREPAIRCODE_SPRNOM(void)
{
return Object->ElementREPAIRCODE_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementREPAIRCODE_SPRNOM(TFIBWideStringField * ElementREPAIRCODE_SPRNOM)
{
Object->ElementREPAIRCODE_SPRNOM=ElementREPAIRCODE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementLOCATION_SPRNOM(void)
{
return Object->ElementLOCATION_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementLOCATION_SPRNOM(TFIBWideStringField * ElementLOCATION_SPRNOM)
{
Object->ElementLOCATION_SPRNOM=ElementLOCATION_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementART2_SPRNOM(void)
{
return Object->ElementART2_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementART2_SPRNOM(TFIBWideStringField * ElementART2_SPRNOM)
{
Object->ElementART2_SPRNOM=ElementART2_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_ElementANGL_NAME_SPRNOM(void)
{
return Object->ElementANGL_NAME_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_ElementANGL_NAME_SPRNOM(TFIBWideStringField * ElementANGL_NAME_SPRNOM)
{
Object->ElementANGL_NAME_SPRNOM=ElementANGL_NAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomImpl::get_TableART2_SPRNOM(void)
{
return Object->TableART2_SPRNOM;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_TableART2_SPRNOM(TFIBWideStringField * TableART2_SPRNOM)
{
Object->TableART2_SPRNOM=TableART2_SPRNOM;
}
//---------------------------------------------------------------

__int64 TDMSprProducerNomImpl::get_IdProducer(void)
{
return Object->IdProducer;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_IdProducer(__int64 IdProducer)
{
Object->IdProducer=IdProducer;
}
//---------------------------------------------------------------
__int64 TDMSprProducerNomImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprProducerNomImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprProducerNomImpl::get_IdProducerTypePrice(void)
{
return Object->IdProducerTypePrice;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::set_IdProducerTypePrice(__int64 IdProducerTypePrice)
{
Object->IdProducerTypePrice=IdProducerTypePrice;
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::OpenTable(__int64 id_producer, __int64 id_grp, __int64 id_producer_type_price, bool all,	UnicodeString in_str, int fl_poisk)
{
return Object->OpenTable(id_producer, id_grp, id_producer_type_price, all,	in_str,fl_poisk);
}
//---------------------------------------------------------------
bool TDMSprProducerNomImpl::NewElement(__int64 id_producer, __int64 id_grp)
{
return Object->NewElement(id_producer,id_grp);
}
//---------------------------------------------------------------
bool TDMSprProducerNomImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprProducerNomImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TDMSprProducerNomImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprProducerNomImpl::ChancheGrp(__int64 id_new_grp,__int64 id_producer_nom)
{
return Object->ChancheGrp(id_new_grp,id_producer_nom);
}
//---------------------------------------------------------------
__int64 TDMSprProducerNomImpl::FindPoCodu(__int64 id_producer, UnicodeString model, int Code)
{
return Object->FindPoCodu(id_producer, model,Code);
}
//---------------------------------------------------------------
__int64 TDMSprProducerNomImpl::FindPoShtrihCodu(__int64 id_producer, UnicodeString model,UnicodeString shtrih_cod)
{
return Object->FindPoShtrihCodu(id_producer, model,shtrih_cod);
}
//---------------------------------------------------------------
__int64 TDMSprProducerNomImpl::FindPoName(__int64 id_producer, UnicodeString model,UnicodeString name)
{
return Object->FindPoName(id_producer,  model,name);
}
//---------------------------------------------------------------
__int64 TDMSprProducerNomImpl::FindPoArtikulu(__int64 id_producer, UnicodeString model,UnicodeString artikul)
{
return Object->FindPoArtikulu(id_producer, model,artikul);
}
//---------------------------------------------------------------
__int64 TDMSprProducerNomImpl::GetIdGrpNom(__int64 id_nom)
{
return Object->GetIdGrpNom(id_nom);
}
//---------------------------------------------------------------
