#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprModelInfBlockImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprModelInfBlockImpl::TREM_DMSprModelInfBlockImpl()           
{                                            
Object=new TREM_DMSprModelInfBlock(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprModelInfBlockImpl::~TREM_DMSprModelInfBlockImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprModelInfBlockImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprModelInfBlock)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprModelInfBlock*> (this);                                
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
int TREM_DMSprModelInfBlockImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprModelInfBlockImpl::kanRelease(void)                                  
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
int  TREM_DMSprModelInfBlockImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprModelInfBlockImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModelInfBlockImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprModelInfBlockImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModelInfBlockImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprModelInfBlock
TDataSource * TREM_DMSprModelInfBlockImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModelInfBlockImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModelInfBlockImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModelInfBlockImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprModelInfBlockImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModelInfBlockImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprModelInfBlockImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelInfBlockImpl::get_TableID_REM_SMODEL_INF(void)
{
return Object->TableID_REM_SMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_TableID_REM_SMODEL_INF(TFIBLargeIntField * TableID_REM_SMODEL_INF)
{
Object->TableID_REM_SMODEL_INF=TableID_REM_SMODEL_INF;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelInfBlockImpl::get_TableIDBASE_REM_SMODEL_INF(void)
{
return Object->TableIDBASE_REM_SMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_TableIDBASE_REM_SMODEL_INF(TFIBLargeIntField * TableIDBASE_REM_SMODEL_INF)
{
Object->TableIDBASE_REM_SMODEL_INF=TableIDBASE_REM_SMODEL_INF;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelInfBlockImpl::get_TableGID_REM_SMODEL_INF(void)
{
return Object->TableGID_REM_SMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_TableGID_REM_SMODEL_INF(TFIBWideStringField * TableGID_REM_SMODEL_INF)
{
Object->TableGID_REM_SMODEL_INF=TableGID_REM_SMODEL_INF;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelInfBlockImpl::get_TableIDMODEL_REM_SMODEL_INF(void)
{
return Object->TableIDMODEL_REM_SMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_TableIDMODEL_REM_SMODEL_INF(TFIBLargeIntField * TableIDMODEL_REM_SMODEL_INF)
{
Object->TableIDMODEL_REM_SMODEL_INF=TableIDMODEL_REM_SMODEL_INF;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelInfBlockImpl::get_TableIDIB_REM_SMODEL_INF(void)
{
return Object->TableIDIB_REM_SMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_TableIDIB_REM_SMODEL_INF(TFIBLargeIntField * TableIDIB_REM_SMODEL_INF)
{
Object->TableIDIB_REM_SMODEL_INF=TableIDIB_REM_SMODEL_INF;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprModelInfBlockImpl::get_TableISM_REM_SMODEL_INF(void)
{
return Object->TableISM_REM_SMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_TableISM_REM_SMODEL_INF(TFIBDateTimeField * TableISM_REM_SMODEL_INF)
{
Object->TableISM_REM_SMODEL_INF=TableISM_REM_SMODEL_INF;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelInfBlockImpl::get_TableNAME_ART_IB(void)
{
return Object->TableNAME_ART_IB;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_TableNAME_ART_IB(TFIBWideStringField * TableNAME_ART_IB)
{
Object->TableNAME_ART_IB=TableNAME_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelInfBlockImpl::get_TableDESCR_ART_IB(void)
{
return Object->TableDESCR_ART_IB;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_TableDESCR_ART_IB(TFIBWideStringField * TableDESCR_ART_IB)
{
Object->TableDESCR_ART_IB=TableDESCR_ART_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelInfBlockImpl::get_ElementID_REM_SMODEL_INF(void)
{
return Object->ElementID_REM_SMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_ElementID_REM_SMODEL_INF(TFIBLargeIntField * ElementID_REM_SMODEL_INF)
{
Object->ElementID_REM_SMODEL_INF=ElementID_REM_SMODEL_INF;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelInfBlockImpl::get_ElementIDBASE_REM_SMODEL_INF(void)
{
return Object->ElementIDBASE_REM_SMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_ElementIDBASE_REM_SMODEL_INF(TFIBLargeIntField * ElementIDBASE_REM_SMODEL_INF)
{
Object->ElementIDBASE_REM_SMODEL_INF=ElementIDBASE_REM_SMODEL_INF;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelInfBlockImpl::get_ElementGID_REM_SMODEL_INF(void)
{
return Object->ElementGID_REM_SMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_ElementGID_REM_SMODEL_INF(TFIBWideStringField * ElementGID_REM_SMODEL_INF)
{
Object->ElementGID_REM_SMODEL_INF=ElementGID_REM_SMODEL_INF;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelInfBlockImpl::get_ElementIDMODEL_REM_SMODEL_INF(void)
{
return Object->ElementIDMODEL_REM_SMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_ElementIDMODEL_REM_SMODEL_INF(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_INF)
{
Object->ElementIDMODEL_REM_SMODEL_INF=ElementIDMODEL_REM_SMODEL_INF;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelInfBlockImpl::get_ElementIDIB_REM_SMODEL_INF(void)
{
return Object->ElementIDIB_REM_SMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_ElementIDIB_REM_SMODEL_INF(TFIBLargeIntField * ElementIDIB_REM_SMODEL_INF)
{
Object->ElementIDIB_REM_SMODEL_INF=ElementIDIB_REM_SMODEL_INF;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprModelInfBlockImpl::get_ElementISM_REM_SMODEL_INF(void)
{
return Object->ElementISM_REM_SMODEL_INF;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_ElementISM_REM_SMODEL_INF(TFIBDateTimeField * ElementISM_REM_SMODEL_INF)
{
Object->ElementISM_REM_SMODEL_INF=ElementISM_REM_SMODEL_INF;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelInfBlockImpl::get_ElementNAME_ART_IB(void)
{
return Object->ElementNAME_ART_IB;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_ElementNAME_ART_IB(TFIBWideStringField * ElementNAME_ART_IB)
{
Object->ElementNAME_ART_IB=ElementNAME_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelInfBlockImpl::get_ElementDESCR_ART_IB(void)
{
return Object->ElementDESCR_ART_IB;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_ElementDESCR_ART_IB(TFIBWideStringField * ElementDESCR_ART_IB)
{
Object->ElementDESCR_ART_IB=ElementDESCR_ART_IB;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModelInfBlockImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModelInfBlockImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprModelInfBlockImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
bool TREM_DMSprModelInfBlockImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
int TREM_DMSprModelInfBlockImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TREM_DMSprModelInfBlockImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprModelInfBlockImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
