#include "vcl.h"
#pragma hdrstop


#include "UDMSprNomAnalogImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprNomAnalogImpl::TDMSprNomAnalogImpl()           
{                                            
Object=new TDMSprNomAnalog(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprNomAnalogImpl::~TDMSprNomAnalogImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprNomAnalogImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprNomAnalog)                        
   {                                                                     
   *ppv=static_cast<IDMSprNomAnalog*> (this);                                
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
int TDMSprNomAnalogImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprNomAnalogImpl::kanRelease(void)                                  
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
int  TDMSprNomAnalogImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprNomAnalogImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprNomAnalogImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprNomAnalogImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprNomAnalogImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprNomAnalog
TDataSource * TDMSprNomAnalogImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprNomAnalogImpl::get_DataSourcePodr(void)
{
return Object->DataSourcePodr;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_DataSourcePodr(TDataSource * DataSourcePodr)
{
Object->DataSourcePodr=DataSourcePodr;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomAnalogImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomAnalogImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomAnalogImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprNomAnalogImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomAnalogImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomAnalogImpl::get_TableID_SNOM_ANALOG(void)
{
return Object->TableID_SNOM_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableID_SNOM_ANALOG(TFIBLargeIntField * TableID_SNOM_ANALOG)
{
Object->TableID_SNOM_ANALOG=TableID_SNOM_ANALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomAnalogImpl::get_TableIDBASE_SNOM_ANALOG(void)
{
return Object->TableIDBASE_SNOM_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableIDBASE_SNOM_ANALOG(TFIBLargeIntField * TableIDBASE_SNOM_ANALOG)
{
Object->TableIDBASE_SNOM_ANALOG=TableIDBASE_SNOM_ANALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_TableGID_SNOM_ANALOG(void)
{
return Object->TableGID_SNOM_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableGID_SNOM_ANALOG(TFIBWideStringField * TableGID_SNOM_ANALOG)
{
Object->TableGID_SNOM_ANALOG=TableGID_SNOM_ANALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomAnalogImpl::get_TableIDNOM_SNOM_ANALOG(void)
{
return Object->TableIDNOM_SNOM_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableIDNOM_SNOM_ANALOG(TFIBLargeIntField * TableIDNOM_SNOM_ANALOG)
{
Object->TableIDNOM_SNOM_ANALOG=TableIDNOM_SNOM_ANALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomAnalogImpl::get_TableIDNOMANALOG_SNOM_ANALOG(void)
{
return Object->TableIDNOMANALOG_SNOM_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableIDNOMANALOG_SNOM_ANALOG(TFIBLargeIntField * TableIDNOMANALOG_SNOM_ANALOG)
{
Object->TableIDNOMANALOG_SNOM_ANALOG=TableIDNOMANALOG_SNOM_ANALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomAnalogImpl::get_TableIDTYPEANALOG_SNOM_ANALOG(void)
{
return Object->TableIDTYPEANALOG_SNOM_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableIDTYPEANALOG_SNOM_ANALOG(TFIBLargeIntField * TableIDTYPEANALOG_SNOM_ANALOG)
{
Object->TableIDTYPEANALOG_SNOM_ANALOG=TableIDTYPEANALOG_SNOM_ANALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_TableNAME_STYPE_ANALOG(void)
{
return Object->TableNAME_STYPE_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableNAME_STYPE_ANALOG(TFIBWideStringField * TableNAME_STYPE_ANALOG)
{
Object->TableNAME_STYPE_ANALOG=TableNAME_STYPE_ANALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_TableARTNOM(void)
{
return Object->TableARTNOM;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableARTNOM(TFIBWideStringField * TableARTNOM)
{
Object->TableARTNOM=TableARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomAnalogImpl::get_TableCODENOM(void)
{
return Object->TableCODENOM;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableCODENOM(TFIBIntegerField * TableCODENOM)
{
Object->TableCODENOM=TableCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_TableNAMEED(void)
{
return Object->TableNAMEED;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableNAMEED(TFIBWideStringField * TableNAMEED)
{
Object->TableNAMEED=TableNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_TableSHED(void)
{
return Object->TableSHED;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableSHED(TFIBWideStringField * TableSHED)
{
Object->TableSHED=TableSHED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomAnalogImpl::get_TableZNACH_PRICE(void)
{
return Object->TableZNACH_PRICE;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)
{
Object->TableZNACH_PRICE=TableZNACH_PRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomAnalogImpl::get_ElementID_SNOM_ANALOG(void)
{
return Object->ElementID_SNOM_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_ElementID_SNOM_ANALOG(TFIBLargeIntField * ElementID_SNOM_ANALOG)
{
Object->ElementID_SNOM_ANALOG=ElementID_SNOM_ANALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomAnalogImpl::get_ElementIDBASE_SNOM_ANALOG(void)
{
return Object->ElementIDBASE_SNOM_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_ElementIDBASE_SNOM_ANALOG(TFIBLargeIntField * ElementIDBASE_SNOM_ANALOG)
{
Object->ElementIDBASE_SNOM_ANALOG=ElementIDBASE_SNOM_ANALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_ElementGID_SNOM_ANALOG(void)
{
return Object->ElementGID_SNOM_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_ElementGID_SNOM_ANALOG(TFIBWideStringField * ElementGID_SNOM_ANALOG)
{
Object->ElementGID_SNOM_ANALOG=ElementGID_SNOM_ANALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomAnalogImpl::get_ElementIDNOM_SNOM_ANALOG(void)
{
return Object->ElementIDNOM_SNOM_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_ElementIDNOM_SNOM_ANALOG(TFIBLargeIntField * ElementIDNOM_SNOM_ANALOG)
{
Object->ElementIDNOM_SNOM_ANALOG=ElementIDNOM_SNOM_ANALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomAnalogImpl::get_ElementIDNOMANALOG_SNOM_ANALOG(void)
{
return Object->ElementIDNOMANALOG_SNOM_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_ElementIDNOMANALOG_SNOM_ANALOG(TFIBLargeIntField * ElementIDNOMANALOG_SNOM_ANALOG)
{
Object->ElementIDNOMANALOG_SNOM_ANALOG=ElementIDNOMANALOG_SNOM_ANALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomAnalogImpl::get_ElementIDTYPEANALOG_SNOM_ANALOG(void)
{
return Object->ElementIDTYPEANALOG_SNOM_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_ElementIDTYPEANALOG_SNOM_ANALOG(TFIBLargeIntField * ElementIDTYPEANALOG_SNOM_ANALOG)
{
Object->ElementIDTYPEANALOG_SNOM_ANALOG=ElementIDTYPEANALOG_SNOM_ANALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_ElementNAME_STYPE_ANALOG(void)
{
return Object->ElementNAME_STYPE_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_ElementNAME_STYPE_ANALOG(TFIBWideStringField * ElementNAME_STYPE_ANALOG)
{
Object->ElementNAME_STYPE_ANALOG=ElementNAME_STYPE_ANALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_ElementNAMENOM(void)
{
return Object->ElementNAMENOM;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)
{
Object->ElementNAMENOM=ElementNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_ElementARTNOM(void)
{
return Object->ElementARTNOM;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)
{
Object->ElementARTNOM=ElementARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomAnalogImpl::get_ElementCODENOM(void)
{
return Object->ElementCODENOM;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)
{
Object->ElementCODENOM=ElementCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_ElementNAMEED(void)
{
return Object->ElementNAMEED;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_ElementNAMEED(TFIBWideStringField * ElementNAMEED)
{
Object->ElementNAMEED=ElementNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_ElementSHED(void)
{
return Object->ElementSHED;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_ElementSHED(TFIBWideStringField * ElementSHED)
{
Object->ElementSHED=ElementSHED;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomAnalogImpl::get_SpisokTypeAnalog(void)
{
return Object->SpisokTypeAnalog;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_SpisokTypeAnalog(TpFIBDataSet * SpisokTypeAnalog)
{
Object->SpisokTypeAnalog=SpisokTypeAnalog;
}
//---------------------------------------------------------------
TDataSource * TDMSprNomAnalogImpl::get_DataSourceSpisokTypeAnalog(void)
{
return Object->DataSourceSpisokTypeAnalog;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_DataSourceSpisokTypeAnalog(TDataSource * DataSourceSpisokTypeAnalog)
{
Object->DataSourceSpisokTypeAnalog=DataSourceSpisokTypeAnalog;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomAnalogImpl::get_SpisokTypeAnalogNAME_STYPE_ANALOG(void)
{
return Object->SpisokTypeAnalogNAME_STYPE_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_SpisokTypeAnalogNAME_STYPE_ANALOG(TFIBWideStringField * SpisokTypeAnalogNAME_STYPE_ANALOG)
{
Object->SpisokTypeAnalogNAME_STYPE_ANALOG=SpisokTypeAnalogNAME_STYPE_ANALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomAnalogImpl::get_SpisokTypeAnalogID_STYPE_ANALOG(void)
{
return Object->SpisokTypeAnalogID_STYPE_ANALOG;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_SpisokTypeAnalogID_STYPE_ANALOG(TFIBLargeIntField * SpisokTypeAnalogID_STYPE_ANALOG)
{
Object->SpisokTypeAnalogID_STYPE_ANALOG=SpisokTypeAnalogID_STYPE_ANALOG;
}
//---------------------------------------------------------------
TStringField * TDMSprNomAnalogImpl::get_TableNAME_TYPE_ANALOG_LOOKUP(void)
{
return Object->TableNAME_TYPE_ANALOG_LOOKUP;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_TableNAME_TYPE_ANALOG_LOOKUP(TStringField * TableNAME_TYPE_ANALOG_LOOKUP)
{
Object->TableNAME_TYPE_ANALOG_LOOKUP=TableNAME_TYPE_ANALOG_LOOKUP;
}
//---------------------------------------------------------------
__int64 TDMSprNomAnalogImpl::get_IdRodElement(void)
{
return Object->IdRodElement;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_IdRodElement(__int64 IdRodElement)
{
Object->IdRodElement=IdRodElement;
}
//---------------------------------------------------------------
__int64 TDMSprNomAnalogImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
__int64 TDMSprNomAnalogImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMSprNomAnalogImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::NewElement(__int64 id_rod_element)
{
return Object->NewElement(id_rod_element);
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::InsertElement(__int64 id_rod_element, __int64 id_nom)
{
return Object->InsertElement(id_rod_element, id_nom);
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement( id);
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::OpenTable(__int64 id_rod_element, __int64 id_type_price)
{
return Object->OpenTable(id_rod_element,id_type_price);
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::TableSaveIsmen(void)
{
return Object->TableSaveIsmen();
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::TableCancelIsmen(void)
{
return Object->TableCancelIsmen();
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::TableNewElement(__int64 id_rod_element)
{
return Object->TableNewElement(id_rod_element);
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::TableEdit(void)
{
return Object->TableEdit();
}
//---------------------------------------------------------------
bool TDMSprNomAnalogImpl::TablePost(void)
{
return Object->TablePost();
}
//---------------------------------------------------------------
