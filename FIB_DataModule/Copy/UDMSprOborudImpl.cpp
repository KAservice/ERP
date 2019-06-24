#include "vcl.h"
#pragma hdrstop


#include "UDMSprOborudImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprOborudImpl::TDMSprOborudImpl()           
{                                            
Object=new TDMSprOborud(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprOborudImpl::~TDMSprOborudImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprOborudImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprOborudImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprOborud)                        
   {                                                                     
   *ppv=static_cast<IDMSprOborud*> (this);                                
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
int TDMSprOborudImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprOborudImpl::kanRelease(void)                                  
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
int  TDMSprOborudImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprOborudImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprOborudImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprOborudImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprOborudImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprOborudImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprOborud
TDataSource * TDMSprOborudImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprOborudImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprOborudImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprOborudImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprOborudImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprOborudImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprOborudImpl::get_TableON_START_SOBORUD(void)
{
return Object->TableON_START_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableON_START_SOBORUD(TFIBSmallIntField * TableON_START_SOBORUD)
{
Object->TableON_START_SOBORUD=TableON_START_SOBORUD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprOborudImpl::get_ElementON_START_SOBORUD(void)
{
return Object->ElementON_START_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementON_START_SOBORUD(TFIBSmallIntField * ElementON_START_SOBORUD)
{
Object->ElementON_START_SOBORUD=ElementON_START_SOBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_TableNAME_OBORUD(void)
{
return Object->TableNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableNAME_OBORUD(TFIBWideStringField * TableNAME_OBORUD)
{
Object->TableNAME_OBORUD=TableNAME_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_TableCOMPNAME_OBORUD(void)
{
return Object->TableCOMPNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableCOMPNAME_OBORUD(TFIBWideStringField * TableCOMPNAME_OBORUD)
{
Object->TableCOMPNAME_OBORUD=TableCOMPNAME_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_TableCOMNAME_OBORUD(void)
{
return Object->TableCOMNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableCOMNAME_OBORUD(TFIBWideStringField * TableCOMNAME_OBORUD)
{
Object->TableCOMNAME_OBORUD=TableCOMNAME_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_TableBAUDRATE_OBORUD(void)
{
return Object->TableBAUDRATE_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableBAUDRATE_OBORUD(TFIBWideStringField * TableBAUDRATE_OBORUD)
{
Object->TableBAUDRATE_OBORUD=TableBAUDRATE_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_TableMODEL_OBORUD(void)
{
return Object->TableMODEL_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableMODEL_OBORUD(TFIBWideStringField * TableMODEL_OBORUD)
{
Object->TableMODEL_OBORUD=TableMODEL_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_TableGID_SOBORUD(void)
{
return Object->TableGID_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableGID_SOBORUD(TFIBWideStringField * TableGID_SOBORUD)
{
Object->TableGID_SOBORUD=TableGID_SOBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_TableSTRPAR_SOBORUD(void)
{
return Object->TableSTRPAR_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableSTRPAR_SOBORUD(TFIBWideStringField * TableSTRPAR_SOBORUD)
{
Object->TableSTRPAR_SOBORUD=TableSTRPAR_SOBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_TableMODUL_SOBORUD(void)
{
return Object->TableMODUL_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableMODUL_SOBORUD(TFIBWideStringField * TableMODUL_SOBORUD)
{
Object->TableMODUL_SOBORUD=TableMODUL_SOBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_ElementNAME_OBORUD(void)
{
return Object->ElementNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementNAME_OBORUD(TFIBWideStringField * ElementNAME_OBORUD)
{
Object->ElementNAME_OBORUD=ElementNAME_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_ElementCOMPNAME_OBORUD(void)
{
return Object->ElementCOMPNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementCOMPNAME_OBORUD(TFIBWideStringField * ElementCOMPNAME_OBORUD)
{
Object->ElementCOMPNAME_OBORUD=ElementCOMPNAME_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_ElementCOMNAME_OBORUD(void)
{
return Object->ElementCOMNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementCOMNAME_OBORUD(TFIBWideStringField * ElementCOMNAME_OBORUD)
{
Object->ElementCOMNAME_OBORUD=ElementCOMNAME_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_ElementTYPE_OBORUD(void)
{
return Object->ElementTYPE_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementTYPE_OBORUD(TFIBWideStringField * ElementTYPE_OBORUD)
{
Object->ElementTYPE_OBORUD=ElementTYPE_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_ElementMODEL_OBORUD(void)
{
return Object->ElementMODEL_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementMODEL_OBORUD(TFIBWideStringField * ElementMODEL_OBORUD)
{
Object->ElementMODEL_OBORUD=ElementMODEL_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_ElementGID_SOBORUD(void)
{
return Object->ElementGID_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementGID_SOBORUD(TFIBWideStringField * ElementGID_SOBORUD)
{
Object->ElementGID_SOBORUD=ElementGID_SOBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_ElementSTRPAR_SOBORUD(void)
{
return Object->ElementSTRPAR_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementSTRPAR_SOBORUD(TFIBWideStringField * ElementSTRPAR_SOBORUD)
{
Object->ElementSTRPAR_SOBORUD=ElementSTRPAR_SOBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_ElementMODUL_SOBORUD(void)
{
return Object->ElementMODUL_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementMODUL_SOBORUD(TFIBWideStringField * ElementMODUL_SOBORUD)
{
Object->ElementMODUL_SOBORUD=ElementMODUL_SOBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_TableTYPE_OBORUD(void)
{
return Object->TableTYPE_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableTYPE_OBORUD(TFIBWideStringField * TableTYPE_OBORUD)
{
Object->TableTYPE_OBORUD=TableTYPE_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_ElementBAUDRATE_OBORUD(void)
{
return Object->ElementBAUDRATE_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementBAUDRATE_OBORUD(TFIBWideStringField * ElementBAUDRATE_OBORUD)
{
Object->ElementBAUDRATE_OBORUD=ElementBAUDRATE_OBORUD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprOborudImpl::get_TableID_OBORUD(void)
{
return Object->TableID_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableID_OBORUD(TFIBLargeIntField * TableID_OBORUD)
{
Object->TableID_OBORUD=TableID_OBORUD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprOborudImpl::get_TableIDARM_SOBORUD(void)
{
return Object->TableIDARM_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableIDARM_SOBORUD(TFIBLargeIntField * TableIDARM_SOBORUD)
{
Object->TableIDARM_SOBORUD=TableIDARM_SOBORUD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprOborudImpl::get_TableIDBASE_SOBORUD(void)
{
return Object->TableIDBASE_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TableIDBASE_SOBORUD(TFIBLargeIntField * TableIDBASE_SOBORUD)
{
Object->TableIDBASE_SOBORUD=TableIDBASE_SOBORUD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprOborudImpl::get_ElementID_OBORUD(void)
{
return Object->ElementID_OBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementID_OBORUD(TFIBLargeIntField * ElementID_OBORUD)
{
Object->ElementID_OBORUD=ElementID_OBORUD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprOborudImpl::get_ElementIDARM_SOBORUD(void)
{
return Object->ElementIDARM_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementIDARM_SOBORUD(TFIBLargeIntField * ElementIDARM_SOBORUD)
{
Object->ElementIDARM_SOBORUD=ElementIDARM_SOBORUD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprOborudImpl::get_ElementIDBASE_SOBORUD(void)
{
return Object->ElementIDBASE_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementIDBASE_SOBORUD(TFIBLargeIntField * ElementIDBASE_SOBORUD)
{
Object->ElementIDBASE_SOBORUD=ElementIDBASE_SOBORUD;
}
//---------------------------------------------------------------
__int64 TDMSprOborudImpl::get_IdKKM(void)
{
return Object->IdKKM;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_IdKKM(__int64 IdKKM)
{
Object->IdKKM=IdKKM;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::OpenTable(__int64 id_kkm)
{
return Object->OpenTable(id_kkm);
}
//---------------------------------------------------------------
void TDMSprOborudImpl::OpenTablePoTypeOborud(__int64 id_kkm, UnicodeString type_oborud)
{
return Object->OpenTablePoTypeOborud(id_kkm, type_oborud);
}
//---------------------------------------------------------------
int TDMSprOborudImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprOborudImpl::NewElement(__int64 id_kkm)
{
return Object->NewElement(id_kkm);
}
//---------------------------------------------------------------
bool TDMSprOborudImpl::SaveElement(void)
{

return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprOborudImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
UnicodeString TDMSprOborudImpl::GetParameter(UnicodeString parameter)
{
return Object->GetParameter(parameter);
}
//---------------------------------------------------------------
UnicodeString TDMSprOborudImpl::GetParameterPoTable(UnicodeString parameter)
{
return Object->GetParameterPoTable(parameter);
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_TablePROGID_SOBORUD(void)
{
return Object->TablePROGID_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_TablePROGID_SOBORUD(TFIBWideStringField * TablePROGID_SOBORUD)
{
Object->TablePROGID_SOBORUD=TablePROGID_SOBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOborudImpl::get_ElementPROGID_SOBORUD(void)
{
return Object->ElementPROGID_SOBORUD;
}
//---------------------------------------------------------------
void TDMSprOborudImpl::set_ElementPROGID_SOBORUD(TFIBWideStringField * ElementPROGID_SOBORUD)
{
Object->ElementPROGID_SOBORUD=ElementPROGID_SOBORUD;
}
//---------------------------------------------------------------
