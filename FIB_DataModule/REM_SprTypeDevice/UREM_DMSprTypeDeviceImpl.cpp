#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprTypeDeviceImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprTypeDeviceImpl::TREM_DMSprTypeDeviceImpl()           
{                                            
Object=new TREM_DMSprTypeDevice(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprTypeDeviceImpl::~TREM_DMSprTypeDeviceImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprTypeDeviceImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprTypeDevice)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprTypeDevice*> (this);                                
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
int TREM_DMSprTypeDeviceImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprTypeDeviceImpl::kanRelease(void)                                  
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
int  TREM_DMSprTypeDeviceImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprTypeDeviceImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTypeDeviceImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprTypeDeviceImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTypeDeviceImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprTypeDevice
TDataSource * TREM_DMSprTypeDeviceImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprTypeDeviceImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTypeDeviceImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTypeDeviceImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTypeDeviceImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTypeDeviceImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprTypeDeviceImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypeDeviceImpl::get_TableID_REM_STYPEDEVICE(void)
{
return Object->TableID_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_TableID_REM_STYPEDEVICE(TFIBLargeIntField * TableID_REM_STYPEDEVICE)
{
Object->TableID_REM_STYPEDEVICE=TableID_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypeDeviceImpl::get_TableGID_REM_STYPEDEVICE(void)
{
return Object->TableGID_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_TableGID_REM_STYPEDEVICE(TFIBWideStringField * TableGID_REM_STYPEDEVICE)
{
Object->TableGID_REM_STYPEDEVICE=TableGID_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypeDeviceImpl::get_TableIDBASE_REM_STYPEDEVICE(void)
{
return Object->TableIDBASE_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_TableIDBASE_REM_STYPEDEVICE(TFIBLargeIntField * TableIDBASE_REM_STYPEDEVICE)
{
Object->TableIDBASE_REM_STYPEDEVICE=TableIDBASE_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypeDeviceImpl::get_TableNAME_REM_STYPEDEVICE(void)
{
return Object->TableNAME_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_TableNAME_REM_STYPEDEVICE(TFIBWideStringField * TableNAME_REM_STYPEDEVICE)
{
Object->TableNAME_REM_STYPEDEVICE=TableNAME_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypeDeviceImpl::get_ElementID_REM_STYPEDEVICE(void)
{
return Object->ElementID_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_ElementID_REM_STYPEDEVICE(TFIBLargeIntField * ElementID_REM_STYPEDEVICE)
{
Object->ElementID_REM_STYPEDEVICE=ElementID_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypeDeviceImpl::get_ElementGID_REM_STYPEDEVICE(void)
{
return Object->ElementGID_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_ElementGID_REM_STYPEDEVICE(TFIBWideStringField * ElementGID_REM_STYPEDEVICE)
{
Object->ElementGID_REM_STYPEDEVICE=ElementGID_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypeDeviceImpl::get_ElementIDBASE_REM_STYPEDEVICE(void)
{
return Object->ElementIDBASE_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_ElementIDBASE_REM_STYPEDEVICE(TFIBLargeIntField * ElementIDBASE_REM_STYPEDEVICE)
{
Object->ElementIDBASE_REM_STYPEDEVICE=ElementIDBASE_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypeDeviceImpl::get_ElementNAME_REM_STYPEDEVICE(void)
{
return Object->ElementNAME_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::set_ElementNAME_REM_STYPEDEVICE(TFIBWideStringField * ElementNAME_REM_STYPEDEVICE)
{
Object->ElementNAME_REM_STYPEDEVICE=ElementNAME_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprTypeDeviceImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TREM_DMSprTypeDeviceImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprTypeDeviceImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TREM_DMSprTypeDeviceImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprTypeDeviceImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
