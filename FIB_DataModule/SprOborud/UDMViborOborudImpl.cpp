#include <vcl.h>
#pragma hdrstop


#include "UDMViborOborudImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMViborOborudImpl::TDMViborOborudImpl()           
{                                            
Object=new TDMViborOborud(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMViborOborudImpl::~TDMViborOborudImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMViborOborudImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMViborOborudImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMViborOborud)                        
   {                                                                     
   *ppv=static_cast<IDMViborOborud*> (this);                                
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
int TDMViborOborudImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMViborOborudImpl::kanRelease(void)                                  
{                                                                      
if (--NumRefs==0)                                                     
   {                                                                  
   delete this;                                                       
   }                                                                  
return NumRefs;                                                       
}                                                                     
//---------------------------------------------------------------

//IMainInterface 

//---------------------------------------------------------------
int  TDMViborOborudImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMViborOborudImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMViborOborudImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMViborOborudImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMViborOborudImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMViborOborudImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMViborOborudImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMViborOborudImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMViborOborudImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TFIBBCDField * TDMViborOborudImpl::get_TableID_OBORUD(void)
{
return Object->TableID_OBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableID_OBORUD(TFIBBCDField * TableID_OBORUD)
{
Object->TableID_OBORUD=TableID_OBORUD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMViborOborudImpl::get_TableIDARM_SOBORUD(void)
{
return Object->TableIDARM_SOBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableIDARM_SOBORUD(TFIBBCDField * TableIDARM_SOBORUD)
{
Object->TableIDARM_SOBORUD=TableIDARM_SOBORUD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMViborOborudImpl::get_TableON_START_SOBORUD(void)
{
return Object->TableON_START_SOBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableON_START_SOBORUD(TFIBSmallIntField * TableON_START_SOBORUD)
{
Object->TableON_START_SOBORUD=TableON_START_SOBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMViborOborudImpl::get_TableNAME_OBORUD(void)
{
return Object->TableNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableNAME_OBORUD(TFIBWideStringField * TableNAME_OBORUD)
{
Object->TableNAME_OBORUD=TableNAME_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMViborOborudImpl::get_TableCOMPNAME_OBORUD(void)
{
return Object->TableCOMPNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableCOMPNAME_OBORUD(TFIBWideStringField * TableCOMPNAME_OBORUD)
{
Object->TableCOMPNAME_OBORUD=TableCOMPNAME_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMViborOborudImpl::get_TableCOMNAME_OBORUD(void)
{
return Object->TableCOMNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableCOMNAME_OBORUD(TFIBWideStringField * TableCOMNAME_OBORUD)
{
Object->TableCOMNAME_OBORUD=TableCOMNAME_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMViborOborudImpl::get_TableBAUDRATE_OBORUD(void)
{
return Object->TableBAUDRATE_OBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableBAUDRATE_OBORUD(TFIBWideStringField * TableBAUDRATE_OBORUD)
{
Object->TableBAUDRATE_OBORUD=TableBAUDRATE_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMViborOborudImpl::get_TableTYPE_OBORUD(void)
{
return Object->TableTYPE_OBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableTYPE_OBORUD(TFIBWideStringField * TableTYPE_OBORUD)
{
Object->TableTYPE_OBORUD=TableTYPE_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMViborOborudImpl::get_TableMODEL_OBORUD(void)
{
return Object->TableMODEL_OBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableMODEL_OBORUD(TFIBWideStringField * TableMODEL_OBORUD)
{
Object->TableMODEL_OBORUD=TableMODEL_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMViborOborudImpl::get_TableGID_SOBORUD(void)
{
return Object->TableGID_SOBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableGID_SOBORUD(TFIBWideStringField * TableGID_SOBORUD)
{
Object->TableGID_SOBORUD=TableGID_SOBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMViborOborudImpl::get_TableSTRPAR_SOBORUD(void)
{
return Object->TableSTRPAR_SOBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableSTRPAR_SOBORUD(TFIBWideStringField * TableSTRPAR_SOBORUD)
{
Object->TableSTRPAR_SOBORUD=TableSTRPAR_SOBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMViborOborudImpl::get_TableMODUL_SOBORUD(void)
{
return Object->TableMODUL_SOBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableMODUL_SOBORUD(TFIBWideStringField * TableMODUL_SOBORUD)
{
Object->TableMODUL_SOBORUD=TableMODUL_SOBORUD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMViborOborudImpl::get_TableIDBASE_SOBORUD(void)
{
return Object->TableIDBASE_SOBORUD;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_TableIDBASE_SOBORUD(TFIBBCDField * TableIDBASE_SOBORUD)
{
Object->TableIDBASE_SOBORUD=TableIDBASE_SOBORUD;
}
//---------------------------------------------------------------
__int64 TDMViborOborudImpl::get_IdArm(void)
{
return Object->IdArm;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::set_IdArm(__int64 IdArm)
{
Object->IdArm=IdArm;
}
//---------------------------------------------------------------
void TDMViborOborudImpl::OpenTable(__int64 id_arm, AnsiString type_oborud)
{
return Object->OpenTable(id_arm, type_oborud);
}
//---------------------------------------------------------------
