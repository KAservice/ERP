#include "vcl.h"
#pragma hdrstop


#include "UDMSprPropertiesValuesListImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprPropertiesValuesListImpl::TDMSprPropertiesValuesListImpl()           
{                                            
Object=new TDMSprPropertiesValuesList(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprPropertiesValuesListImpl::~TDMSprPropertiesValuesListImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprPropertiesValuesListImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprPropertiesValuesList)                        
   {                                                                     
   *ppv=static_cast<IDMSprPropertiesValuesList*> (this);                                
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
int TDMSprPropertiesValuesListImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprPropertiesValuesListImpl::kanRelease(void)                                  
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
int  TDMSprPropertiesValuesListImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprPropertiesValuesListImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprPropertiesValuesListImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprPropertiesValuesListImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprPropertiesValuesListImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprPropertiesValuesList
TDataSource * TDMSprPropertiesValuesListImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprPropertiesValuesListImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPropertiesValuesListImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPropertiesValuesListImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPropertiesValuesListImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPropertiesValuesListImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprPropertiesValuesListImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesValuesListImpl::get_TableID_SPROPVALUELIST(void)
{
return Object->TableID_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_TableID_SPROPVALUELIST(TFIBLargeIntField * TableID_SPROPVALUELIST)
{
Object->TableID_SPROPVALUELIST=TableID_SPROPVALUELIST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesValuesListImpl::get_TableIDBASE_SPROPVALUELIST(void)
{
return Object->TableIDBASE_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_TableIDBASE_SPROPVALUELIST(TFIBLargeIntField * TableIDBASE_SPROPVALUELIST)
{
Object->TableIDBASE_SPROPVALUELIST=TableIDBASE_SPROPVALUELIST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesValuesListImpl::get_TableGID_SPROPVALUELIST(void)
{
return Object->TableGID_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_TableGID_SPROPVALUELIST(TFIBWideStringField * TableGID_SPROPVALUELIST)
{
Object->TableGID_SPROPVALUELIST=TableGID_SPROPVALUELIST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesValuesListImpl::get_TableIDPROP_SPROPVALUELIST(void)
{
return Object->TableIDPROP_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_TableIDPROP_SPROPVALUELIST(TFIBLargeIntField * TableIDPROP_SPROPVALUELIST)
{
Object->TableIDPROP_SPROPVALUELIST=TableIDPROP_SPROPVALUELIST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesValuesListImpl::get_TableNAME_SPROPVALUELIST(void)
{
return Object->TableNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_TableNAME_SPROPVALUELIST(TFIBWideStringField * TableNAME_SPROPVALUELIST)
{
Object->TableNAME_SPROPVALUELIST=TableNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesValuesListImpl::get_ElementID_SPROPVALUELIST(void)
{
return Object->ElementID_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_ElementID_SPROPVALUELIST(TFIBLargeIntField * ElementID_SPROPVALUELIST)
{
Object->ElementID_SPROPVALUELIST=ElementID_SPROPVALUELIST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesValuesListImpl::get_ElementIDBASE_SPROPVALUELIST(void)
{
return Object->ElementIDBASE_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_ElementIDBASE_SPROPVALUELIST(TFIBLargeIntField * ElementIDBASE_SPROPVALUELIST)
{
Object->ElementIDBASE_SPROPVALUELIST=ElementIDBASE_SPROPVALUELIST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesValuesListImpl::get_ElementGID_SPROPVALUELIST(void)
{
return Object->ElementGID_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_ElementGID_SPROPVALUELIST(TFIBWideStringField * ElementGID_SPROPVALUELIST)
{
Object->ElementGID_SPROPVALUELIST=ElementGID_SPROPVALUELIST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesValuesListImpl::get_ElementIDPROP_SPROPVALUELIST(void)
{
return Object->ElementIDPROP_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_ElementIDPROP_SPROPVALUELIST(TFIBLargeIntField * ElementIDPROP_SPROPVALUELIST)
{
Object->ElementIDPROP_SPROPVALUELIST=ElementIDPROP_SPROPVALUELIST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesValuesListImpl::get_ElementNAME_SPROPVALUELIST(void)
{
return Object->ElementNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_ElementNAME_SPROPVALUELIST(TFIBWideStringField * ElementNAME_SPROPVALUELIST)
{
Object->ElementNAME_SPROPVALUELIST=ElementNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
TIntegerField * TDMSprPropertiesValuesListImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
void TDMSprPropertiesValuesListImpl::OpenTable(__int64 id_prop)
{
return Object->OpenTable(id_prop);
}
//---------------------------------------------------------------
int TDMSprPropertiesValuesListImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprPropertiesValuesListImpl::NewElement(__int64 id_prop)
{
return Object->NewElement(id_prop);
}
//---------------------------------------------------------------
bool TDMSprPropertiesValuesListImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprPropertiesValuesListImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
