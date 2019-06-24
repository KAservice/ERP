#include "vcl.h"
#pragma hdrstop


#include "UDMSetupImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSetupImpl::TDMSetupImpl()           
{                                            
Object=new TDMSetup(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSetupImpl::~TDMSetupImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSetupImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSetupImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSetup)                        
   {                                                                     
   *ppv=static_cast<IDMSetup*> (this);                                
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
int TDMSetupImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSetupImpl::kanRelease(void)                                  
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

//---------------------------------------------------------------
int  TDMSetupImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSetupImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSetupImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSetupImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSetupImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSetupImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSetupImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSetupImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSetupImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSetupImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSetupImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSetupImpl::get_pFIBQKolPrDoc(void)
{
return Object->pFIBQKolPrDoc;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_pFIBQKolPrDoc(TpFIBQuery * pFIBQKolPrDoc)
{
Object->pFIBQKolPrDoc=pFIBQKolPrDoc;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSetupImpl::get_ElementID_SETUP(void)
{
return Object->ElementID_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_ElementID_SETUP(TFIBBCDField * ElementID_SETUP)
{
Object->ElementID_SETUP=ElementID_SETUP;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSetupImpl::get_TableID_SETUP(void)
{
return Object->TableID_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_TableID_SETUP(TFIBBCDField * TableID_SETUP)
{
Object->TableID_SETUP=TableID_SETUP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSetupImpl::get_TableVALUE_TIMESTAMP_SETUP(void)
{
return Object->TableVALUE_TIMESTAMP_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_TableVALUE_TIMESTAMP_SETUP(TFIBDateTimeField * TableVALUE_TIMESTAMP_SETUP)
{
Object->TableVALUE_TIMESTAMP_SETUP=TableVALUE_TIMESTAMP_SETUP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSetupImpl::get_ElementVALUE_TIMESTAMP_SETUP(void)
{
return Object->ElementVALUE_TIMESTAMP_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_ElementVALUE_TIMESTAMP_SETUP(TFIBDateTimeField * ElementVALUE_TIMESTAMP_SETUP)
{
Object->ElementVALUE_TIMESTAMP_SETUP=ElementVALUE_TIMESTAMP_SETUP;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSetupImpl::get_TableTYPE_VALUE_SETUP(void)
{
return Object->TableTYPE_VALUE_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_TableTYPE_VALUE_SETUP(TFIBSmallIntField * TableTYPE_VALUE_SETUP)
{
Object->TableTYPE_VALUE_SETUP=TableTYPE_VALUE_SETUP;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSetupImpl::get_ElementTYPE_VALUE_SETUP(void)
{
return Object->ElementTYPE_VALUE_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_ElementTYPE_VALUE_SETUP(TFIBSmallIntField * ElementTYPE_VALUE_SETUP)
{
Object->ElementTYPE_VALUE_SETUP=ElementTYPE_VALUE_SETUP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSetupImpl::get_TableDESCRIPTION_SETUP(void)
{
return Object->TableDESCRIPTION_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_TableDESCRIPTION_SETUP(TFIBWideStringField * TableDESCRIPTION_SETUP)
{
Object->TableDESCRIPTION_SETUP=TableDESCRIPTION_SETUP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSetupImpl::get_TableVALUE_SETUP(void)
{
return Object->TableVALUE_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_TableVALUE_SETUP(TFIBWideStringField * TableVALUE_SETUP)
{
Object->TableVALUE_SETUP=TableVALUE_SETUP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSetupImpl::get_TableGID_SETUP(void)
{
return Object->TableGID_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_TableGID_SETUP(TFIBWideStringField * TableGID_SETUP)
{
Object->TableGID_SETUP=TableGID_SETUP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSetupImpl::get_ElementDESCRIPTION_SETUP(void)
{
return Object->ElementDESCRIPTION_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_ElementDESCRIPTION_SETUP(TFIBWideStringField * ElementDESCRIPTION_SETUP)
{
Object->ElementDESCRIPTION_SETUP=ElementDESCRIPTION_SETUP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSetupImpl::get_ElementVALUE_SETUP(void)
{
return Object->ElementVALUE_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_ElementVALUE_SETUP(TFIBWideStringField * ElementVALUE_SETUP)
{
Object->ElementVALUE_SETUP=ElementVALUE_SETUP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSetupImpl::get_ElementGID_SETUP(void)
{
return Object->ElementGID_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::set_ElementGID_SETUP(TFIBWideStringField * ElementGID_SETUP)
{
Object->ElementGID_SETUP=ElementGID_SETUP;
}
//---------------------------------------------------------------
void TDMSetupImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TDMSetupImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSetupImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
int TDMSetupImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSetupImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
void TDMSetupImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSetupImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
void TDMSetupImpl::ProveritPosled( TDateTime  posDoc)
{
return Object->ProveritPosled(posDoc);
}
//---------------------------------------------------------------
int TDMSetupImpl::GetKolProvDoc( TDateTime  posDoc)
{
return Object->GetKolProvDoc(posDoc);
}
//---------------------------------------------------------------
bool TDMSetupImpl::ProveritPosZapretaRed( TDateTime  posDoc)
{
return Object->ProveritPosZapretaRed( posDoc);
}
//---------------------------------------------------------------
void TDMSetupImpl::ProveritPosledHotel( TDateTime  posDoc)
{
return Object->ProveritPosledHotel(posDoc);
}
//---------------------------------------------------------------
int TDMSetupImpl::GetKolProvDocHotel( TDateTime  posDoc)
{
return Object->GetKolProvDocHotel(posDoc);
}
//---------------------------------------------------------------
bool TDMSetupImpl::ProveritPosZapretaRedHotel( TDateTime  posDoc)
{
return Object->ProveritPosZapretaRedHotel( posDoc);
}
//---------------------------------------------------------------
void TDMSetupImpl::ProveritPosledRemont( TDateTime  posDoc)
{
return Object->ProveritPosledRemont(posDoc);
}
//---------------------------------------------------------------
int TDMSetupImpl::GetKolProvDocRemont( TDateTime  posDoc)
{
return Object->GetKolProvDocRemont( posDoc);
}
//---------------------------------------------------------------
bool TDMSetupImpl::ProveritPosZapretaRedRemont( TDateTime  posDoc)
{
return Object->ProveritPosZapretaRedRemont( posDoc);
}
//---------------------------------------------------------------
