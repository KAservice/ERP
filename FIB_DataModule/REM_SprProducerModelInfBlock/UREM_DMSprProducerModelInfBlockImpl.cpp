#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerModelInfBlockImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerModelInfBlockImpl::TREM_DMSprProducerModelInfBlockImpl()           
{                                            
Object=new TREM_DMSprProducerModelInfBlock(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerModelInfBlockImpl::~TREM_DMSprProducerModelInfBlockImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerModelInfBlockImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerModelInfBlock)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerModelInfBlock*> (this);                                
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
int TREM_DMSprProducerModelInfBlockImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerModelInfBlockImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerModelInfBlockImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerModelInfBlockImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerModelInfBlockImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerModelInfBlockImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerModelInfBlockImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerModelInfBlock
TDataSource * TREM_DMSprProducerModelInfBlockImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerModelInfBlockImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerModelInfBlockImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerModelInfBlockImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerModelInfBlockImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerModelInfBlockImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprProducerModelInfBlockImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelInfBlockImpl::get_TableID_REM_SPRMODEL_INF(void)
{
return Object->TableID_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_TableID_REM_SPRMODEL_INF(TFIBLargeIntField * TableID_REM_SPRMODEL_INF)
{
Object->TableID_REM_SPRMODEL_INF=TableID_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelInfBlockImpl::get_TableIDBASE_REM_SPRMODEL_INF(void)
{
return Object->TableIDBASE_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_TableIDBASE_REM_SPRMODEL_INF(TFIBLargeIntField * TableIDBASE_REM_SPRMODEL_INF)
{
Object->TableIDBASE_REM_SPRMODEL_INF=TableIDBASE_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelInfBlockImpl::get_TableGID_REM_SPRMODEL_INF(void)
{
return Object->TableGID_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_TableGID_REM_SPRMODEL_INF(TFIBWideStringField * TableGID_REM_SPRMODEL_INF)
{
Object->TableGID_REM_SPRMODEL_INF=TableGID_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelInfBlockImpl::get_TableIDPRMODEL_REM_SPRMODEL_INF(void)
{
return Object->TableIDPRMODEL_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_TableIDPRMODEL_REM_SPRMODEL_INF(TFIBLargeIntField * TableIDPRMODEL_REM_SPRMODEL_INF)
{
Object->TableIDPRMODEL_REM_SPRMODEL_INF=TableIDPRMODEL_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelInfBlockImpl::get_TableIDIB_REM_SPRMODEL_INF(void)
{
return Object->TableIDIB_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_TableIDIB_REM_SPRMODEL_INF(TFIBLargeIntField * TableIDIB_REM_SPRMODEL_INF)
{
Object->TableIDIB_REM_SPRMODEL_INF=TableIDIB_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprProducerModelInfBlockImpl::get_TableISM_REM_SPRMODEL_INF(void)
{
return Object->TableISM_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_TableISM_REM_SPRMODEL_INF(TFIBDateTimeField * TableISM_REM_SPRMODEL_INF)
{
Object->TableISM_REM_SPRMODEL_INF=TableISM_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelInfBlockImpl::get_TableNAME_ART_IB(void)
{
return Object->TableNAME_ART_IB;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_TableNAME_ART_IB(TFIBWideStringField * TableNAME_ART_IB)
{
Object->TableNAME_ART_IB=TableNAME_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelInfBlockImpl::get_TableDESCR_ART_IB(void)
{
return Object->TableDESCR_ART_IB;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_TableDESCR_ART_IB(TFIBWideStringField * TableDESCR_ART_IB)
{
Object->TableDESCR_ART_IB=TableDESCR_ART_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelInfBlockImpl::get_ElementID_REM_SPRMODEL_INF(void)
{
return Object->ElementID_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_ElementID_REM_SPRMODEL_INF(TFIBLargeIntField * ElementID_REM_SPRMODEL_INF)
{
Object->ElementID_REM_SPRMODEL_INF=ElementID_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelInfBlockImpl::get_ElementIDBASE_REM_SPRMODEL_INF(void)
{
return Object->ElementIDBASE_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_ElementIDBASE_REM_SPRMODEL_INF(TFIBLargeIntField * ElementIDBASE_REM_SPRMODEL_INF)
{
Object->ElementIDBASE_REM_SPRMODEL_INF=ElementIDBASE_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelInfBlockImpl::get_ElementGID_REM_SPRMODEL_INF(void)
{
return Object->ElementGID_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_ElementGID_REM_SPRMODEL_INF(TFIBWideStringField * ElementGID_REM_SPRMODEL_INF)
{
Object->ElementGID_REM_SPRMODEL_INF=ElementGID_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelInfBlockImpl::get_ElementIDPRMODEL_REM_SPRMODEL_INF(void)
{
return Object->ElementIDPRMODEL_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_ElementIDPRMODEL_REM_SPRMODEL_INF(TFIBLargeIntField * ElementIDPRMODEL_REM_SPRMODEL_INF)
{
Object->ElementIDPRMODEL_REM_SPRMODEL_INF=ElementIDPRMODEL_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelInfBlockImpl::get_ElementIDIB_REM_SPRMODEL_INF(void)
{
return Object->ElementIDIB_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_ElementIDIB_REM_SPRMODEL_INF(TFIBLargeIntField * ElementIDIB_REM_SPRMODEL_INF)
{
Object->ElementIDIB_REM_SPRMODEL_INF=ElementIDIB_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprProducerModelInfBlockImpl::get_ElementISM_REM_SPRMODEL_INF(void)
{
return Object->ElementISM_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_ElementISM_REM_SPRMODEL_INF(TFIBDateTimeField * ElementISM_REM_SPRMODEL_INF)
{
Object->ElementISM_REM_SPRMODEL_INF=ElementISM_REM_SPRMODEL_INF;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelInfBlockImpl::get_ElementNAME_ART_IB(void)
{
return Object->ElementNAME_ART_IB;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_ElementNAME_ART_IB(TFIBWideStringField * ElementNAME_ART_IB)
{
Object->ElementNAME_ART_IB=ElementNAME_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelInfBlockImpl::get_ElementDESCR_ART_IB(void)
{
return Object->ElementDESCR_ART_IB;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_ElementDESCR_ART_IB(TFIBWideStringField * ElementDESCR_ART_IB)
{
Object->ElementDESCR_ART_IB=ElementDESCR_ART_IB;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerModelInfBlockImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerModelInfBlockImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelInfBlockImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelInfBlockImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
int TREM_DMSprProducerModelInfBlockImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelInfBlockImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelInfBlockImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
