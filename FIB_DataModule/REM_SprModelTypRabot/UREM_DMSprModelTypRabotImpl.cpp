#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprModelTypRabotImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprModelTypRabotImpl::TREM_DMSprModelTypRabotImpl()           
{                                            
Object=new TREM_DMSprModelTypRabot(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprModelTypRabotImpl::~TREM_DMSprModelTypRabotImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprModelTypRabotImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprModelTypRabot)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprModelTypRabot*> (this);                                
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
int TREM_DMSprModelTypRabotImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprModelTypRabotImpl::kanRelease(void)                                  
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
int  TREM_DMSprModelTypRabotImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprModelTypRabotImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModelTypRabotImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprModelTypRabotImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModelTypRabotImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprModelTypRabot
TDataSource * TREM_DMSprModelTypRabotImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModelTypRabotImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModelTypRabotImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModelTypRabotImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprModelTypRabotImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModelTypRabotImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprModelTypRabotImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelTypRabotImpl::get_TableID_REM_SMODEL_TRAB(void)
{
return Object->TableID_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_TableID_REM_SMODEL_TRAB(TFIBLargeIntField * TableID_REM_SMODEL_TRAB)
{
Object->TableID_REM_SMODEL_TRAB=TableID_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelTypRabotImpl::get_TableIDBASE_REM_SMODEL_TRAB(void)
{
return Object->TableIDBASE_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_TableIDBASE_REM_SMODEL_TRAB(TFIBLargeIntField * TableIDBASE_REM_SMODEL_TRAB)
{
Object->TableIDBASE_REM_SMODEL_TRAB=TableIDBASE_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelTypRabotImpl::get_TableIDTR_REM_SMODEL_TRAB(void)
{
return Object->TableIDTR_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_TableIDTR_REM_SMODEL_TRAB(TFIBLargeIntField * TableIDTR_REM_SMODEL_TRAB)
{
Object->TableIDTR_REM_SMODEL_TRAB=TableIDTR_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelTypRabotImpl::get_TableIDMODEL_REM_SMODEL_TRAB(void)
{
return Object->TableIDMODEL_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_TableIDMODEL_REM_SMODEL_TRAB(TFIBLargeIntField * TableIDMODEL_REM_SMODEL_TRAB)
{
Object->TableIDMODEL_REM_SMODEL_TRAB=TableIDMODEL_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelTypRabotImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelTypRabotImpl::get_TableARTNOM(void)
{
return Object->TableARTNOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_TableARTNOM(TFIBWideStringField * TableARTNOM)
{
Object->TableARTNOM=TableARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprModelTypRabotImpl::get_TableCODENOM(void)
{
return Object->TableCODENOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_TableCODENOM(TFIBIntegerField * TableCODENOM)
{
Object->TableCODENOM=TableCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelTypRabotImpl::get_TableNAME_REM_STYPRABOT(void)
{
return Object->TableNAME_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_TableNAME_REM_STYPRABOT(TFIBWideStringField * TableNAME_REM_STYPRABOT)
{
Object->TableNAME_REM_STYPRABOT=TableNAME_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelTypRabotImpl::get_ElementID_REM_SMODEL_TRAB(void)
{
return Object->ElementID_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_ElementID_REM_SMODEL_TRAB(TFIBLargeIntField * ElementID_REM_SMODEL_TRAB)
{
Object->ElementID_REM_SMODEL_TRAB=ElementID_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelTypRabotImpl::get_ElementIDBASE_REM_SMODEL_TRAB(void)
{
return Object->ElementIDBASE_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_ElementIDBASE_REM_SMODEL_TRAB(TFIBLargeIntField * ElementIDBASE_REM_SMODEL_TRAB)
{
Object->ElementIDBASE_REM_SMODEL_TRAB=ElementIDBASE_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelTypRabotImpl::get_ElementIDTR_REM_SMODEL_TRAB(void)
{
return Object->ElementIDTR_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_ElementIDTR_REM_SMODEL_TRAB(TFIBLargeIntField * ElementIDTR_REM_SMODEL_TRAB)
{
Object->ElementIDTR_REM_SMODEL_TRAB=ElementIDTR_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelTypRabotImpl::get_ElementIDMODEL_REM_SMODEL_TRAB(void)
{
return Object->ElementIDMODEL_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_ElementIDMODEL_REM_SMODEL_TRAB(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_TRAB)
{
Object->ElementIDMODEL_REM_SMODEL_TRAB=ElementIDMODEL_REM_SMODEL_TRAB;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelTypRabotImpl::get_ElementNAMENOM(void)
{
return Object->ElementNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)
{
Object->ElementNAMENOM=ElementNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelTypRabotImpl::get_ElementARTNOM(void)
{
return Object->ElementARTNOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)
{
Object->ElementARTNOM=ElementARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprModelTypRabotImpl::get_ElementCODENOM(void)
{
return Object->ElementCODENOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)
{
Object->ElementCODENOM=ElementCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelTypRabotImpl::get_ElementNAME_REM_STYPRABOT(void)
{
return Object->ElementNAME_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_ElementNAME_REM_STYPRABOT(TFIBWideStringField * ElementNAME_REM_STYPRABOT)
{
Object->ElementNAME_REM_STYPRABOT=ElementNAME_REM_STYPRABOT;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModelTypRabotImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModelTypRabotImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprModelTypRabotImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
bool TREM_DMSprModelTypRabotImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
int TREM_DMSprModelTypRabotImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TREM_DMSprModelTypRabotImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprModelTypRabotImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement( id);
}
//---------------------------------------------------------------
