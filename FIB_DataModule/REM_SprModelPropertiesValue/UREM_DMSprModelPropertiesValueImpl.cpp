#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprModelPropertiesValueImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprModelPropertiesValueImpl::TREM_DMSprModelPropertiesValueImpl()           
{                                            
Object=new TREM_DMSprModelPropertiesValue(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprModelPropertiesValueImpl::~TREM_DMSprModelPropertiesValueImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprModelPropertiesValueImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprModelPropertiesValue)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprModelPropertiesValue*> (this);                                
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
int TREM_DMSprModelPropertiesValueImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprModelPropertiesValueImpl::kanRelease(void)                                  
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
int  TREM_DMSprModelPropertiesValueImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprModelPropertiesValueImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModelPropertiesValueImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprModelPropertiesValueImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModelPropertiesValueImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprModelPropertiesValue
TDataSource * TREM_DMSprModelPropertiesValueImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModelPropertiesValueImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModelPropertiesValueImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModelPropertiesValueImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprModelPropertiesValueImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModelPropertiesValueImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprModelPropertiesValueImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelPropertiesValueImpl::get_TableID_REM_SMODEL_PROPVAL(void)
{
return Object->TableID_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableID_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableID_REM_SMODEL_PROPVAL)
{
Object->TableID_REM_SMODEL_PROPVAL=TableID_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelPropertiesValueImpl::get_TableIDBASE_REM_SMODEL_PROPVAL(void)
{
return Object->TableIDBASE_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableIDBASE_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableIDBASE_REM_SMODEL_PROPVAL)
{
Object->TableIDBASE_REM_SMODEL_PROPVAL=TableIDBASE_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelPropertiesValueImpl::get_TableGID_REM_SMODEL_PROPVAL(void)
{
return Object->TableGID_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableGID_REM_SMODEL_PROPVAL(TFIBWideStringField * TableGID_REM_SMODEL_PROPVAL)
{
Object->TableGID_REM_SMODEL_PROPVAL=TableGID_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelPropertiesValueImpl::get_TableIDMODEL_REM_SMODEL_PROPVAL(void)
{
return Object->TableIDMODEL_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableIDMODEL_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableIDMODEL_REM_SMODEL_PROPVAL)
{
Object->TableIDMODEL_REM_SMODEL_PROPVAL=TableIDMODEL_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelPropertiesValueImpl::get_TableIDPROP_REM_SMODEL_PROPVAL(void)
{
return Object->TableIDPROP_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableIDPROP_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableIDPROP_REM_SMODEL_PROPVAL)
{
Object->TableIDPROP_REM_SMODEL_PROPVAL=TableIDPROP_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelPropertiesValueImpl::get_TableIDPVL_REM_SMODEL_PROPVAL(void)
{
return Object->TableIDPVL_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableIDPVL_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableIDPVL_REM_SMODEL_PROPVAL)
{
Object->TableIDPVL_REM_SMODEL_PROPVAL=TableIDPVL_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelPropertiesValueImpl::get_TableVALTEXT_REM_SMODEL_PROPVAL(void)
{
return Object->TableVALTEXT_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableVALTEXT_REM_SMODEL_PROPVAL(TFIBWideStringField * TableVALTEXT_REM_SMODEL_PROPVAL)
{
Object->TableVALTEXT_REM_SMODEL_PROPVAL=TableVALTEXT_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprModelPropertiesValueImpl::get_TableISM_REM_SMODEL_PROPVAL(void)
{
return Object->TableISM_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableISM_REM_SMODEL_PROPVAL(TFIBDateTimeField * TableISM_REM_SMODEL_PROPVAL)
{
Object->TableISM_REM_SMODEL_PROPVAL=TableISM_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelPropertiesValueImpl::get_TableNAME_SPROP(void)
{
return Object->TableNAME_SPROP;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableNAME_SPROP(TFIBWideStringField * TableNAME_SPROP)
{
Object->TableNAME_SPROP=TableNAME_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelPropertiesValueImpl::get_TableNAME_FOR_PRINT_SPROP(void)
{
return Object->TableNAME_FOR_PRINT_SPROP;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableNAME_FOR_PRINT_SPROP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP)
{
Object->TableNAME_FOR_PRINT_SPROP=TableNAME_FOR_PRINT_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelPropertiesValueImpl::get_TableNAME_SPROPVALUELIST(void)
{
return Object->TableNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableNAME_SPROPVALUELIST(TFIBWideStringField * TableNAME_SPROPVALUELIST)
{
Object->TableNAME_SPROPVALUELIST=TableNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelPropertiesValueImpl::get_TableNAME_SPROP_GRP(void)
{
return Object->TableNAME_SPROP_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableNAME_SPROP_GRP(TFIBWideStringField * TableNAME_SPROP_GRP)
{
Object->TableNAME_SPROP_GRP=TableNAME_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelPropertiesValueImpl::get_TableNAME_FOR_PRINT_SPROP_GRP(void)
{
return Object->TableNAME_FOR_PRINT_SPROP_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_TableNAME_FOR_PRINT_SPROP_GRP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP)
{
Object->TableNAME_FOR_PRINT_SPROP_GRP=TableNAME_FOR_PRINT_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelPropertiesValueImpl::get_ElementID_REM_SMODEL_PROPVAL(void)
{
return Object->ElementID_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_ElementID_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementID_REM_SMODEL_PROPVAL)
{
Object->ElementID_REM_SMODEL_PROPVAL=ElementID_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelPropertiesValueImpl::get_ElementIDBASE_REM_SMODEL_PROPVAL(void)
{
return Object->ElementIDBASE_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_ElementIDBASE_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementIDBASE_REM_SMODEL_PROPVAL)
{
Object->ElementIDBASE_REM_SMODEL_PROPVAL=ElementIDBASE_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelPropertiesValueImpl::get_ElementGID_REM_SMODEL_PROPVAL(void)
{
return Object->ElementGID_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_ElementGID_REM_SMODEL_PROPVAL(TFIBWideStringField * ElementGID_REM_SMODEL_PROPVAL)
{
Object->ElementGID_REM_SMODEL_PROPVAL=ElementGID_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelPropertiesValueImpl::get_ElementIDMODEL_REM_SMODEL_PROPVAL(void)
{
return Object->ElementIDMODEL_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_ElementIDMODEL_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_PROPVAL)
{
Object->ElementIDMODEL_REM_SMODEL_PROPVAL=ElementIDMODEL_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelPropertiesValueImpl::get_ElementIDPROP_REM_SMODEL_PROPVAL(void)
{
return Object->ElementIDPROP_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_ElementIDPROP_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementIDPROP_REM_SMODEL_PROPVAL)
{
Object->ElementIDPROP_REM_SMODEL_PROPVAL=ElementIDPROP_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelPropertiesValueImpl::get_ElementIDPVL_REM_SMODEL_PROPVAL(void)
{
return Object->ElementIDPVL_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_ElementIDPVL_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementIDPVL_REM_SMODEL_PROPVAL)
{
Object->ElementIDPVL_REM_SMODEL_PROPVAL=ElementIDPVL_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelPropertiesValueImpl::get_ElementVALTEXT_REM_SMODEL_PROPVAL(void)
{
return Object->ElementVALTEXT_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_ElementVALTEXT_REM_SMODEL_PROPVAL(TFIBWideStringField * ElementVALTEXT_REM_SMODEL_PROPVAL)
{
Object->ElementVALTEXT_REM_SMODEL_PROPVAL=ElementVALTEXT_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprModelPropertiesValueImpl::get_ElementISM_REM_SMODEL_PROPVAL(void)
{
return Object->ElementISM_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_ElementISM_REM_SMODEL_PROPVAL(TFIBDateTimeField * ElementISM_REM_SMODEL_PROPVAL)
{
Object->ElementISM_REM_SMODEL_PROPVAL=ElementISM_REM_SMODEL_PROPVAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelPropertiesValueImpl::get_ElementNAME_SPROP(void)
{
return Object->ElementNAME_SPROP;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_ElementNAME_SPROP(TFIBWideStringField * ElementNAME_SPROP)
{
Object->ElementNAME_SPROP=ElementNAME_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelPropertiesValueImpl::get_ElementNAME_SPROPVALUELIST(void)
{
return Object->ElementNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_ElementNAME_SPROPVALUELIST(TFIBWideStringField * ElementNAME_SPROPVALUELIST)
{
Object->ElementNAME_SPROPVALUELIST=ElementNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModelPropertiesValueImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModelPropertiesValueImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprModelPropertiesValueImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
bool TREM_DMSprModelPropertiesValueImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
int TREM_DMSprModelPropertiesValueImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TREM_DMSprModelPropertiesValueImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprModelPropertiesValueImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
