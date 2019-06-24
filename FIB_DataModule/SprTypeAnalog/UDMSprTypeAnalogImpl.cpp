#include "vcl.h"
#pragma hdrstop


#include "UDMSprTypeAnalogImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprTypeAnalogImpl::TDMSprTypeAnalogImpl()           
{                                            
Object=new TDMSprTypeAnalog(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprTypeAnalogImpl::~TDMSprTypeAnalogImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprTypeAnalogImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprTypeAnalog)                        
   {                                                                     
   *ppv=static_cast<IDMSprTypeAnalog*> (this);                                
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
int TDMSprTypeAnalogImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprTypeAnalogImpl::kanRelease(void)                                  
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
int  TDMSprTypeAnalogImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprTypeAnalogImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprTypeAnalogImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprTypeAnalogImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprTypeAnalogImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprTypeAnalog
TDataSource * TDMSprTypeAnalogImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprTypeAnalogImpl::get_DataSourcePodr(void)
{
return Object->DataSourcePodr;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_DataSourcePodr(TDataSource * DataSourcePodr)
{
Object->DataSourcePodr=DataSourcePodr;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprTypeAnalogImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprTypeAnalogImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprTypeAnalogImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprTypeAnalogImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprTypeAnalogImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprTypeAnalogImpl::get_TableID_STYPE_ANALOG(void)
{
return Object->TableID_STYPE_ANALOG;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_TableID_STYPE_ANALOG(TFIBLargeIntField * TableID_STYPE_ANALOG)
{
Object->TableID_STYPE_ANALOG=TableID_STYPE_ANALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprTypeAnalogImpl::get_TableIDBASE_STYPE_ANALOG(void)
{
return Object->TableIDBASE_STYPE_ANALOG;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_TableIDBASE_STYPE_ANALOG(TFIBLargeIntField * TableIDBASE_STYPE_ANALOG)
{
Object->TableIDBASE_STYPE_ANALOG=TableIDBASE_STYPE_ANALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypeAnalogImpl::get_TableGID_STYPE_ANALOG(void)
{
return Object->TableGID_STYPE_ANALOG;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_TableGID_STYPE_ANALOG(TFIBWideStringField * TableGID_STYPE_ANALOG)
{
Object->TableGID_STYPE_ANALOG=TableGID_STYPE_ANALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypeAnalogImpl::get_TableNAME_STYPE_ANALOG(void)
{
return Object->TableNAME_STYPE_ANALOG;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_TableNAME_STYPE_ANALOG(TFIBWideStringField * TableNAME_STYPE_ANALOG)
{
Object->TableNAME_STYPE_ANALOG=TableNAME_STYPE_ANALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprTypeAnalogImpl::get_ElementID_STYPE_ANALOG(void)
{
return Object->ElementID_STYPE_ANALOG;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_ElementID_STYPE_ANALOG(TFIBLargeIntField * ElementID_STYPE_ANALOG)
{
Object->ElementID_STYPE_ANALOG=ElementID_STYPE_ANALOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprTypeAnalogImpl::get_ElementIDBASE_STYPE_ANALOG(void)
{
return Object->ElementIDBASE_STYPE_ANALOG;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_ElementIDBASE_STYPE_ANALOG(TFIBLargeIntField * ElementIDBASE_STYPE_ANALOG)
{
Object->ElementIDBASE_STYPE_ANALOG=ElementIDBASE_STYPE_ANALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypeAnalogImpl::get_ElementGID_STYPE_ANALOG(void)
{
return Object->ElementGID_STYPE_ANALOG;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_ElementGID_STYPE_ANALOG(TFIBWideStringField * ElementGID_STYPE_ANALOG)
{
Object->ElementGID_STYPE_ANALOG=ElementGID_STYPE_ANALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypeAnalogImpl::get_ElementNAME_STYPE_ANALOG(void)
{
return Object->ElementNAME_STYPE_ANALOG;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_ElementNAME_STYPE_ANALOG(TFIBWideStringField * ElementNAME_STYPE_ANALOG)
{
Object->ElementNAME_STYPE_ANALOG=ElementNAME_STYPE_ANALOG;
}
//---------------------------------------------------------------
__int64 TDMSprTypeAnalogImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprTypeAnalogImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::InsertElement(UnicodeString name)
{
return Object->InsertElement(name);
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::TableSaveIsmen(void)
{
return Object->TableSaveIsmen();
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::TableCancelIsmen(void)
{
return Object->TableCancelIsmen();
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::TableNewElement(void)
{
return Object->TableNewElement();
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::TableEdit(void)
{
return Object->TableEdit();
}
//---------------------------------------------------------------
bool TDMSprTypeAnalogImpl::TablePost(void)
{
return Object->TablePost();
}
//---------------------------------------------------------------
