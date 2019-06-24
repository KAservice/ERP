#include "vcl.h"
#pragma hdrstop


#include "UDMSprCodeTelImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprCodeTelImpl::TDMSprCodeTelImpl()           
{                                            
Object=new TDMSprCodeTel(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprCodeTelImpl::~TDMSprCodeTelImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprCodeTelImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprCodeTelImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprCodeTel)                        
   {                                                                     
   *ppv=static_cast<IDMSprCodeTel*> (this);                                
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
int TDMSprCodeTelImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprCodeTelImpl::kanRelease(void)                                  
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
int  TDMSprCodeTelImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprCodeTelImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprCodeTelImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprCodeTelImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprCodeTelImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprCodeTel
TDataSource * TDMSprCodeTelImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprCodeTelImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCodeTelImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCodeTelImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCodeTelImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCodeTelImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCodeTelImpl::get_ElementID_CODETEL(void)
{
return Object->ElementID_CODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_ElementID_CODETEL(TFIBLargeIntField * ElementID_CODETEL)
{
Object->ElementID_CODETEL=ElementID_CODETEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCodeTelImpl::get_ElementIDNOM_CODETEL(void)
{
return Object->ElementIDNOM_CODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_ElementIDNOM_CODETEL(TFIBLargeIntField * ElementIDNOM_CODETEL)
{
Object->ElementIDNOM_CODETEL=ElementIDNOM_CODETEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCodeTelImpl::get_ElementCODE_CODETEL(void)
{
return Object->ElementCODE_CODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_ElementCODE_CODETEL(TFIBWideStringField * ElementCODE_CODETEL)
{
Object->ElementCODE_CODETEL=ElementCODE_CODETEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCodeTelImpl::get_ElementGID_SCODETEL(void)
{
return Object->ElementGID_SCODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_ElementGID_SCODETEL(TFIBWideStringField * ElementGID_SCODETEL)
{
Object->ElementGID_SCODETEL=ElementGID_SCODETEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCodeTelImpl::get_ElementNAME_CODETEL(void)
{
return Object->ElementNAME_CODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_ElementNAME_CODETEL(TFIBWideStringField * ElementNAME_CODETEL)
{
Object->ElementNAME_CODETEL=ElementNAME_CODETEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCodeTelImpl::get_ElementCODOPER_CODETEL(void)
{
return Object->ElementCODOPER_CODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_ElementCODOPER_CODETEL(TFIBWideStringField * ElementCODOPER_CODETEL)
{
Object->ElementCODOPER_CODETEL=ElementCODOPER_CODETEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCodeTelImpl::get_ElementIDNOMCOM_CODETEL(void)
{
return Object->ElementIDNOMCOM_CODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_ElementIDNOMCOM_CODETEL(TFIBLargeIntField * ElementIDNOMCOM_CODETEL)
{
Object->ElementIDNOMCOM_CODETEL=ElementIDNOMCOM_CODETEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCodeTelImpl::get_ElementIDBASE_SCODETEL(void)
{
return Object->ElementIDBASE_SCODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_ElementIDBASE_SCODETEL(TFIBLargeIntField * ElementIDBASE_SCODETEL)
{
Object->ElementIDBASE_SCODETEL=ElementIDBASE_SCODETEL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprCodeTelImpl::get_ElementPRCOMIS_SCODETEL(void)
{
return Object->ElementPRCOMIS_SCODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_ElementPRCOMIS_SCODETEL(TFIBBCDField * ElementPRCOMIS_SCODETEL)
{
Object->ElementPRCOMIS_SCODETEL=ElementPRCOMIS_SCODETEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCodeTelImpl::get_ElementNAMENOM(void)
{
return Object->ElementNAMENOM;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)
{
Object->ElementNAMENOM=ElementNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCodeTelImpl::get_ElementNAMENOMCOM(void)
{
return Object->ElementNAMENOMCOM;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_ElementNAMENOMCOM(TFIBWideStringField * ElementNAMENOMCOM)
{
Object->ElementNAMENOMCOM=ElementNAMENOMCOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCodeTelImpl::get_TableID_CODETEL(void)
{
return Object->TableID_CODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableID_CODETEL(TFIBLargeIntField * TableID_CODETEL)
{
Object->TableID_CODETEL=TableID_CODETEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCodeTelImpl::get_TableIDNOM_CODETEL(void)
{
return Object->TableIDNOM_CODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableIDNOM_CODETEL(TFIBLargeIntField * TableIDNOM_CODETEL)
{
Object->TableIDNOM_CODETEL=TableIDNOM_CODETEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCodeTelImpl::get_TableCODE_CODETEL(void)
{
return Object->TableCODE_CODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableCODE_CODETEL(TFIBWideStringField * TableCODE_CODETEL)
{
Object->TableCODE_CODETEL=TableCODE_CODETEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCodeTelImpl::get_TableGID_SCODETEL(void)
{
return Object->TableGID_SCODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableGID_SCODETEL(TFIBWideStringField * TableGID_SCODETEL)
{
Object->TableGID_SCODETEL=TableGID_SCODETEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCodeTelImpl::get_TableNAME_CODETEL(void)
{
return Object->TableNAME_CODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableNAME_CODETEL(TFIBWideStringField * TableNAME_CODETEL)
{
Object->TableNAME_CODETEL=TableNAME_CODETEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCodeTelImpl::get_TableCODOPER_CODETEL(void)
{
return Object->TableCODOPER_CODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableCODOPER_CODETEL(TFIBWideStringField * TableCODOPER_CODETEL)
{
Object->TableCODOPER_CODETEL=TableCODOPER_CODETEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCodeTelImpl::get_TableIDNOMCOM_CODETEL(void)
{
return Object->TableIDNOMCOM_CODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableIDNOMCOM_CODETEL(TFIBLargeIntField * TableIDNOMCOM_CODETEL)
{
Object->TableIDNOMCOM_CODETEL=TableIDNOMCOM_CODETEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCodeTelImpl::get_TableIDBASE_SCODETEL(void)
{
return Object->TableIDBASE_SCODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableIDBASE_SCODETEL(TFIBLargeIntField * TableIDBASE_SCODETEL)
{
Object->TableIDBASE_SCODETEL=TableIDBASE_SCODETEL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprCodeTelImpl::get_TablePRCOMIS_SCODETEL(void)
{
return Object->TablePRCOMIS_SCODETEL;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TablePRCOMIS_SCODETEL(TFIBBCDField * TablePRCOMIS_SCODETEL)
{
Object->TablePRCOMIS_SCODETEL=TablePRCOMIS_SCODETEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCodeTelImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprCodeTelImpl::get_TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR(void)
{
return Object->TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR(TFIBIntegerField * TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR)
{
Object->TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR=TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCodeTelImpl::get_TableNOM_DEPARTMENT_ID_SDEPARTMENT(void)
{
return Object->TableNOM_DEPARTMENT_ID_SDEPARTMENT;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableNOM_DEPARTMENT_ID_SDEPARTMENT(TFIBLargeIntField * TableNOM_DEPARTMENT_ID_SDEPARTMENT)
{
Object->TableNOM_DEPARTMENT_ID_SDEPARTMENT=TableNOM_DEPARTMENT_ID_SDEPARTMENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCodeTelImpl::get_TableNAMENOMCOM(void)
{
return Object->TableNAMENOMCOM;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableNAMENOMCOM(TFIBWideStringField * TableNAMENOMCOM)
{
Object->TableNAMENOMCOM=TableNAMENOMCOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprCodeTelImpl::get_TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR(void)
{
return Object->TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR(TFIBIntegerField * TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR)
{
Object->TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR=TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCodeTelImpl::get_TableCOM_DEPARTMENT_ID_SDEPARTMENT(void)
{
return Object->TableCOM_DEPARTMENT_ID_SDEPARTMENT;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::set_TableCOM_DEPARTMENT_ID_SDEPARTMENT(TFIBLargeIntField * TableCOM_DEPARTMENT_ID_SDEPARTMENT)
{
Object->TableCOM_DEPARTMENT_ID_SDEPARTMENT=TableCOM_DEPARTMENT_ID_SDEPARTMENT;
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprCodeTelImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprCodeTelImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprCodeTelImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
