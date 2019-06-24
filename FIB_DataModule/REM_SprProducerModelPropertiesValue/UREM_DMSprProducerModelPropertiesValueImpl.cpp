#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerModelPropertiesValueImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerModelPropertiesValueImpl::TREM_DMSprProducerModelPropertiesValueImpl()           
{                                            
Object=new TREM_DMSprProducerModelPropertiesValue(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerModelPropertiesValueImpl::~TREM_DMSprProducerModelPropertiesValueImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerModelPropertiesValueImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerModelPropertiesValue)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerModelPropertiesValue*> (this);                                
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
int TREM_DMSprProducerModelPropertiesValueImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerModelPropertiesValueImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerModelPropertiesValueImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerModelPropertiesValueImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerModelPropertiesValueImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerModelPropertiesValueImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerModelPropertiesValueImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerModelPropertiesValue
TDataSource * TREM_DMSprProducerModelPropertiesValueImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerModelPropertiesValueImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerModelPropertiesValueImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerModelPropertiesValueImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerModelPropertiesValueImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerModelPropertiesValueImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprProducerModelPropertiesValueImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableID_REM_SPRMOD_PRVAL(void)
{
return Object->TableID_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableID_REM_SPRMOD_PRVAL(TFIBLargeIntField * TableID_REM_SPRMOD_PRVAL)
{
Object->TableID_REM_SPRMOD_PRVAL=TableID_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableIDBASE_REM_SPRMOD_PRVAL(void)
{
return Object->TableIDBASE_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableIDBASE_REM_SPRMOD_PRVAL(TFIBLargeIntField * TableIDBASE_REM_SPRMOD_PRVAL)
{
Object->TableIDBASE_REM_SPRMOD_PRVAL=TableIDBASE_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableGID_REM_SPRMOD_PRVAL(void)
{
return Object->TableGID_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableGID_REM_SPRMOD_PRVAL(TFIBWideStringField * TableGID_REM_SPRMOD_PRVAL)
{
Object->TableGID_REM_SPRMOD_PRVAL=TableGID_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableIDPRMODEL_REM_SPRMOD_PRVAL(void)
{
return Object->TableIDPRMODEL_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableIDPRMODEL_REM_SPRMOD_PRVAL(TFIBLargeIntField * TableIDPRMODEL_REM_SPRMOD_PRVAL)
{
Object->TableIDPRMODEL_REM_SPRMOD_PRVAL=TableIDPRMODEL_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableIDPROP_REM_SPRMOD_PRVAL(void)
{
return Object->TableIDPROP_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableIDPROP_REM_SPRMOD_PRVAL(TFIBLargeIntField * TableIDPROP_REM_SPRMOD_PRVAL)
{
Object->TableIDPROP_REM_SPRMOD_PRVAL=TableIDPROP_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableIDPVL_REM_SPRMOD_PRVAL(void)
{
return Object->TableIDPVL_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableIDPVL_REM_SPRMOD_PRVAL(TFIBLargeIntField * TableIDPVL_REM_SPRMOD_PRVAL)
{
Object->TableIDPVL_REM_SPRMOD_PRVAL=TableIDPVL_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableVALTEXT_REM_SPRMOD_PRVAL(void)
{
return Object->TableVALTEXT_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableVALTEXT_REM_SPRMOD_PRVAL(TFIBWideStringField * TableVALTEXT_REM_SPRMOD_PRVAL)
{
Object->TableVALTEXT_REM_SPRMOD_PRVAL=TableVALTEXT_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableISM_REM_SPRMOD_PRVAL(void)
{
return Object->TableISM_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableISM_REM_SPRMOD_PRVAL(TFIBDateTimeField * TableISM_REM_SPRMOD_PRVAL)
{
Object->TableISM_REM_SPRMOD_PRVAL=TableISM_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableNAME_SPROP(void)
{
return Object->TableNAME_SPROP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableNAME_SPROP(TFIBWideStringField * TableNAME_SPROP)
{
Object->TableNAME_SPROP=TableNAME_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableNAME_FOR_PRINT_SPROP(void)
{
return Object->TableNAME_FOR_PRINT_SPROP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableNAME_FOR_PRINT_SPROP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP)
{
Object->TableNAME_FOR_PRINT_SPROP=TableNAME_FOR_PRINT_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableNAME_SPROPVALUELIST(void)
{
return Object->TableNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableNAME_SPROPVALUELIST(TFIBWideStringField * TableNAME_SPROPVALUELIST)
{
Object->TableNAME_SPROPVALUELIST=TableNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableNAME_SPROP_GRP(void)
{
return Object->TableNAME_SPROP_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableNAME_SPROP_GRP(TFIBWideStringField * TableNAME_SPROP_GRP)
{
Object->TableNAME_SPROP_GRP=TableNAME_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelPropertiesValueImpl::get_TableNAME_FOR_PRINT_SPROP_GRP(void)
{
return Object->TableNAME_FOR_PRINT_SPROP_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_TableNAME_FOR_PRINT_SPROP_GRP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP)
{
Object->TableNAME_FOR_PRINT_SPROP_GRP=TableNAME_FOR_PRINT_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelPropertiesValueImpl::get_ElementID_REM_SPRMOD_PRVAL(void)
{
return Object->ElementID_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_ElementID_REM_SPRMOD_PRVAL(TFIBLargeIntField * ElementID_REM_SPRMOD_PRVAL)
{
Object->ElementID_REM_SPRMOD_PRVAL=ElementID_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelPropertiesValueImpl::get_ElementIDBASE_REM_SPRMOD_PRVAL(void)
{
return Object->ElementIDBASE_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_ElementIDBASE_REM_SPRMOD_PRVAL(TFIBLargeIntField * ElementIDBASE_REM_SPRMOD_PRVAL)
{
Object->ElementIDBASE_REM_SPRMOD_PRVAL=ElementIDBASE_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelPropertiesValueImpl::get_ElementGID_REM_SPRMOD_PRVAL(void)
{
return Object->ElementGID_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_ElementGID_REM_SPRMOD_PRVAL(TFIBWideStringField * ElementGID_REM_SPRMOD_PRVAL)
{
Object->ElementGID_REM_SPRMOD_PRVAL=ElementGID_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelPropertiesValueImpl::get_ElementIDPRMODEL_REM_SPRMOD_PRVAL(void)
{
return Object->ElementIDPRMODEL_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_ElementIDPRMODEL_REM_SPRMOD_PRVAL(TFIBLargeIntField * ElementIDPRMODEL_REM_SPRMOD_PRVAL)
{
Object->ElementIDPRMODEL_REM_SPRMOD_PRVAL=ElementIDPRMODEL_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelPropertiesValueImpl::get_ElementIDPROP_REM_SPRMOD_PRVAL(void)
{
return Object->ElementIDPROP_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_ElementIDPROP_REM_SPRMOD_PRVAL(TFIBLargeIntField * ElementIDPROP_REM_SPRMOD_PRVAL)
{
Object->ElementIDPROP_REM_SPRMOD_PRVAL=ElementIDPROP_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelPropertiesValueImpl::get_ElementIDPVL_REM_SPRMOD_PRVAL(void)
{
return Object->ElementIDPVL_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_ElementIDPVL_REM_SPRMOD_PRVAL(TFIBLargeIntField * ElementIDPVL_REM_SPRMOD_PRVAL)
{
Object->ElementIDPVL_REM_SPRMOD_PRVAL=ElementIDPVL_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelPropertiesValueImpl::get_ElementVALTEXT_REM_SPRMOD_PRVAL(void)
{
return Object->ElementVALTEXT_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_ElementVALTEXT_REM_SPRMOD_PRVAL(TFIBWideStringField * ElementVALTEXT_REM_SPRMOD_PRVAL)
{
Object->ElementVALTEXT_REM_SPRMOD_PRVAL=ElementVALTEXT_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprProducerModelPropertiesValueImpl::get_ElementISM_REM_SPRMOD_PRVAL(void)
{
return Object->ElementISM_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_ElementISM_REM_SPRMOD_PRVAL(TFIBDateTimeField * ElementISM_REM_SPRMOD_PRVAL)
{
Object->ElementISM_REM_SPRMOD_PRVAL=ElementISM_REM_SPRMOD_PRVAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelPropertiesValueImpl::get_ElementNAME_SPROP(void)
{
return Object->ElementNAME_SPROP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_ElementNAME_SPROP(TFIBWideStringField * ElementNAME_SPROP)
{
Object->ElementNAME_SPROP=ElementNAME_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelPropertiesValueImpl::get_ElementNAME_SPROPVALUELIST(void)
{
return Object->ElementNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_ElementNAME_SPROPVALUELIST(TFIBWideStringField * ElementNAME_SPROPVALUELIST)
{
Object->ElementNAME_SPROPVALUELIST=ElementNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerModelPropertiesValueImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerModelPropertiesValueImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelPropertiesValueImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelPropertiesValueImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
int TREM_DMSprProducerModelPropertiesValueImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelPropertiesValueImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelPropertiesValueImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
