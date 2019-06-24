#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprGrpHardwareImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprGrpHardwareImpl::TREM_DMSprGrpHardwareImpl()           
{                                            
Object=new TREM_DMSprGrpHardware(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprGrpHardwareImpl::~TREM_DMSprGrpHardwareImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprGrpHardwareImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprGrpHardware)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprGrpHardware*> (this);                                
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
int TREM_DMSprGrpHardwareImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprGrpHardwareImpl::kanRelease(void)                                  
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
int  TREM_DMSprGrpHardwareImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprGrpHardwareImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpHardwareImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprGrpHardwareImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpHardwareImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprGrpHardware
TDataSource * TREM_DMSprGrpHardwareImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprGrpHardwareImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpHardwareImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpHardwareImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprGrpHardwareImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprGrpHardwareImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpHardwareImpl::get_TableID_REM_SGRP_HARDWARE(void)
{
return Object->TableID_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_TableID_REM_SGRP_HARDWARE(TFIBLargeIntField * TableID_REM_SGRP_HARDWARE)
{
Object->TableID_REM_SGRP_HARDWARE=TableID_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpHardwareImpl::get_TableIDBASE_REM_SGRP_HARDWARE(void)
{
return Object->TableIDBASE_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_TableIDBASE_REM_SGRP_HARDWARE(TFIBLargeIntField * TableIDBASE_REM_SGRP_HARDWARE)
{
Object->TableIDBASE_REM_SGRP_HARDWARE=TableIDBASE_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpHardwareImpl::get_TableNAME_REM_SGRP_HARDWARE(void)
{
return Object->TableNAME_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_TableNAME_REM_SGRP_HARDWARE(TFIBWideStringField * TableNAME_REM_SGRP_HARDWARE)
{
Object->TableNAME_REM_SGRP_HARDWARE=TableNAME_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpHardwareImpl::get_TableIDGRP_REM_SGRP_HARDWARE(void)
{
return Object->TableIDGRP_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_TableIDGRP_REM_SGRP_HARDWARE(TFIBLargeIntField * TableIDGRP_REM_SGRP_HARDWARE)
{
Object->TableIDGRP_REM_SGRP_HARDWARE=TableIDGRP_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpHardwareImpl::get_ElementID_REM_SGRP_HARDWARE(void)
{
return Object->ElementID_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_ElementID_REM_SGRP_HARDWARE(TFIBLargeIntField * ElementID_REM_SGRP_HARDWARE)
{
Object->ElementID_REM_SGRP_HARDWARE=ElementID_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpHardwareImpl::get_ElementIDBASE_REM_SGRP_HARDWARE(void)
{
return Object->ElementIDBASE_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_ElementIDBASE_REM_SGRP_HARDWARE(TFIBLargeIntField * ElementIDBASE_REM_SGRP_HARDWARE)
{
Object->ElementIDBASE_REM_SGRP_HARDWARE=ElementIDBASE_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpHardwareImpl::get_ElementNAME_REM_SGRP_HARDWARE(void)
{
return Object->ElementNAME_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_ElementNAME_REM_SGRP_HARDWARE(TFIBWideStringField * ElementNAME_REM_SGRP_HARDWARE)
{
Object->ElementNAME_REM_SGRP_HARDWARE=ElementNAME_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpHardwareImpl::get_ElementIDGRP_REM_SGRP_HARDWARE(void)
{
return Object->ElementIDGRP_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::set_ElementIDGRP_REM_SGRP_HARDWARE(TFIBLargeIntField * ElementIDGRP_REM_SGRP_HARDWARE)
{
Object->ElementIDGRP_REM_SGRP_HARDWARE=ElementIDGRP_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TREM_DMSprGrpHardwareImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprGrpHardwareImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprGrpHardwareImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprGrpHardwareImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TREM_DMSprGrpHardwareImpl::FindPoName(AnsiString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
