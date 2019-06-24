#include "vcl.h"
#pragma hdrstop


#include "UDMInterfMainMenuParImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMInterfMainMenuParImpl::TDMInterfMainMenuParImpl()           
{                                            
Object=new TDMInterfMainMenuPar(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMInterfMainMenuParImpl::~TDMInterfMainMenuParImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMInterfMainMenuParImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMInterfMainMenuPar)                        
   {                                                                     
   *ppv=static_cast<IDMInterfMainMenuPar*> (this);                                
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
int TDMInterfMainMenuParImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMInterfMainMenuParImpl::kanRelease(void)                                  
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
int  TDMInterfMainMenuParImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMInterfMainMenuParImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMInterfMainMenuParImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMInterfMainMenuParImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMInterfMainMenuParImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMInterfMainMenuPar
TDataSource * TDMInterfMainMenuParImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMInterfMainMenuParImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMInterfMainMenuParImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMInterfMainMenuParImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TDMInterfMainMenuParImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMInterfMainMenuParImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuParImpl::get_TableID_INTERF_MAINMENU_PAR(void)
{
return Object->TableID_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_TableID_INTERF_MAINMENU_PAR(TFIBLargeIntField * TableID_INTERF_MAINMENU_PAR)
{
Object->TableID_INTERF_MAINMENU_PAR=TableID_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuParImpl::get_TableIDBASE_INTERF_MAINMENU_PAR(void)
{
return Object->TableIDBASE_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_TableIDBASE_INTERF_MAINMENU_PAR(TFIBLargeIntField * TableIDBASE_INTERF_MAINMENU_PAR)
{
Object->TableIDBASE_INTERF_MAINMENU_PAR=TableIDBASE_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuParImpl::get_TableGID_INTERF_MAINMENU_PAR(void)
{
return Object->TableGID_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_TableGID_INTERF_MAINMENU_PAR(TFIBWideStringField * TableGID_INTERF_MAINMENU_PAR)
{
Object->TableGID_INTERF_MAINMENU_PAR=TableGID_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuParImpl::get_TableIDMAINMENU_INTERF_MAINMENU_PAR(void)
{
return Object->TableIDMAINMENU_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_TableIDMAINMENU_INTERF_MAINMENU_PAR(TFIBLargeIntField * TableIDMAINMENU_INTERF_MAINMENU_PAR)
{
Object->TableIDMAINMENU_INTERF_MAINMENU_PAR=TableIDMAINMENU_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuParImpl::get_TableNAME_INTERF_MAINMENU_PAR(void)
{
return Object->TableNAME_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_TableNAME_INTERF_MAINMENU_PAR(TFIBWideStringField * TableNAME_INTERF_MAINMENU_PAR)
{
Object->TableNAME_INTERF_MAINMENU_PAR=TableNAME_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuParImpl::get_TableVALUE_INTERF_MAINMENU_PAR(void)
{
return Object->TableVALUE_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_TableVALUE_INTERF_MAINMENU_PAR(TFIBWideStringField * TableVALUE_INTERF_MAINMENU_PAR)
{
Object->TableVALUE_INTERF_MAINMENU_PAR=TableVALUE_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMInterfMainMenuParImpl::get_TableVALUE_TIMESTAMP_MAINMENU_PAR(void)
{
return Object->TableVALUE_TIMESTAMP_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_TableVALUE_TIMESTAMP_MAINMENU_PAR(TFIBDateTimeField * TableVALUE_TIMESTAMP_MAINMENU_PAR)
{
Object->TableVALUE_TIMESTAMP_MAINMENU_PAR=TableVALUE_TIMESTAMP_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfMainMenuParImpl::get_TableTYPE_VALUE_MAINMENU_PAR(void)
{
return Object->TableTYPE_VALUE_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_TableTYPE_VALUE_MAINMENU_PAR(TFIBSmallIntField * TableTYPE_VALUE_MAINMENU_PAR)
{
Object->TableTYPE_VALUE_MAINMENU_PAR=TableTYPE_VALUE_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuParImpl::get_TableTYPE_PAR_INTERF_MAINMENU_PAR(void)
{
return Object->TableTYPE_PAR_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_TableTYPE_PAR_INTERF_MAINMENU_PAR(TFIBIntegerField * TableTYPE_PAR_INTERF_MAINMENU_PAR)
{
Object->TableTYPE_PAR_INTERF_MAINMENU_PAR=TableTYPE_PAR_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuParImpl::get_ElementID_INTERF_MAINMENU_PAR(void)
{
return Object->ElementID_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_ElementID_INTERF_MAINMENU_PAR(TFIBLargeIntField * ElementID_INTERF_MAINMENU_PAR)
{
Object->ElementID_INTERF_MAINMENU_PAR=ElementID_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuParImpl::get_ElementIDBASE_INTERF_MAINMENU_PAR(void)
{
return Object->ElementIDBASE_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_ElementIDBASE_INTERF_MAINMENU_PAR(TFIBLargeIntField * ElementIDBASE_INTERF_MAINMENU_PAR)
{
Object->ElementIDBASE_INTERF_MAINMENU_PAR=ElementIDBASE_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuParImpl::get_ElementGID_INTERF_MAINMENU_PAR(void)
{
return Object->ElementGID_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_ElementGID_INTERF_MAINMENU_PAR(TFIBWideStringField * ElementGID_INTERF_MAINMENU_PAR)
{
Object->ElementGID_INTERF_MAINMENU_PAR=ElementGID_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMInterfMainMenuParImpl::get_ElementIDMAINMENU_INTERF_MAINMENU_PAR(void)
{
return Object->ElementIDMAINMENU_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_ElementIDMAINMENU_INTERF_MAINMENU_PAR(TFIBLargeIntField * ElementIDMAINMENU_INTERF_MAINMENU_PAR)
{
Object->ElementIDMAINMENU_INTERF_MAINMENU_PAR=ElementIDMAINMENU_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuParImpl::get_ElementNAME_INTERF_MAINMENU_PAR(void)
{
return Object->ElementNAME_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_ElementNAME_INTERF_MAINMENU_PAR(TFIBWideStringField * ElementNAME_INTERF_MAINMENU_PAR)
{
Object->ElementNAME_INTERF_MAINMENU_PAR=ElementNAME_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMInterfMainMenuParImpl::get_ElementVALUE_INTERF_MAINMENU_PAR(void)
{
return Object->ElementVALUE_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_ElementVALUE_INTERF_MAINMENU_PAR(TFIBWideStringField * ElementVALUE_INTERF_MAINMENU_PAR)
{
Object->ElementVALUE_INTERF_MAINMENU_PAR=ElementVALUE_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMInterfMainMenuParImpl::get_ElementVALUE_TIMESTAMP_MAINMENU_PAR(void)
{
return Object->ElementVALUE_TIMESTAMP_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_ElementVALUE_TIMESTAMP_MAINMENU_PAR(TFIBDateTimeField * ElementVALUE_TIMESTAMP_MAINMENU_PAR)
{
Object->ElementVALUE_TIMESTAMP_MAINMENU_PAR=ElementVALUE_TIMESTAMP_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMInterfMainMenuParImpl::get_ElementTYPE_VALUE_MAINMENU_PAR(void)
{
return Object->ElementTYPE_VALUE_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_ElementTYPE_VALUE_MAINMENU_PAR(TFIBSmallIntField * ElementTYPE_VALUE_MAINMENU_PAR)
{
Object->ElementTYPE_VALUE_MAINMENU_PAR=ElementTYPE_VALUE_MAINMENU_PAR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMInterfMainMenuParImpl::get_ElementTYPE_PAR_INTERF_MAINMENU_PAR(void)
{
return Object->ElementTYPE_PAR_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_ElementTYPE_PAR_INTERF_MAINMENU_PAR(TFIBIntegerField * ElementTYPE_PAR_INTERF_MAINMENU_PAR)
{
Object->ElementTYPE_PAR_INTERF_MAINMENU_PAR=ElementTYPE_PAR_INTERF_MAINMENU_PAR;
}
//---------------------------------------------------------------
__int64 TDMInterfMainMenuParImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
__int64 TDMInterfMainMenuParImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMInterfMainMenuParImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
bool TDMInterfMainMenuParImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
bool TDMInterfMainMenuParImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool TDMInterfMainMenuParImpl::TableAppend(__int64 id_owner)
{
return Object->TableAppend(id_owner);
}
//---------------------------------------------------------------
bool TDMInterfMainMenuParImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
bool TDMInterfMainMenuParImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
int TDMInterfMainMenuParImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMInterfMainMenuParImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMInterfMainMenuParImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
