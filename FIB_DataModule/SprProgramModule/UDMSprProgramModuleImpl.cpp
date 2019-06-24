#include "vcl.h"
#pragma hdrstop


#include "UDMSprProgramModuleImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprProgramModuleImpl::TDMSprProgramModuleImpl()           
{                                            
Object=new TDMSprProgramModule(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprProgramModuleImpl::~TDMSprProgramModuleImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprProgramModuleImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprProgramModule)                        
   {                                                                     
   *ppv=static_cast<IDMSprProgramModule*> (this);                                
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
int TDMSprProgramModuleImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprProgramModuleImpl::kanRelease(void)                                  
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
int  TDMSprProgramModuleImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprProgramModuleImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprProgramModuleImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprProgramModuleImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprProgramModuleImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprProgramModule
TDataSource * TDMSprProgramModuleImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprProgramModuleImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProgramModuleImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProgramModuleImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProgramModuleImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProgramModuleImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProgramModuleImpl::get_TableID_PROGRAM_MODULE(void)
{
return Object->TableID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_TableID_PROGRAM_MODULE(TFIBLargeIntField * TableID_PROGRAM_MODULE)
{
Object->TableID_PROGRAM_MODULE=TableID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProgramModuleImpl::get_TableNAME_PROGRAM_MODULE(void)
{
return Object->TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)
{
Object->TableNAME_PROGRAM_MODULE=TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProgramModuleImpl::get_TablePROGID_PROGRAM_MODULE(void)
{
return Object->TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)
{
Object->TablePROGID_PROGRAM_MODULE=TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProgramModuleImpl::get_TableMODULE_PROGRAM_MODULE(void)
{
return Object->TableMODULE_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_TableMODULE_PROGRAM_MODULE(TFIBWideStringField * TableMODULE_PROGRAM_MODULE)
{
Object->TableMODULE_PROGRAM_MODULE=TableMODULE_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProgramModuleImpl::get_TableDESCR_PROGRAM_MODULE(void)
{
return Object->TableDESCR_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_TableDESCR_PROGRAM_MODULE(TFIBWideStringField * TableDESCR_PROGRAM_MODULE)
{
Object->TableDESCR_PROGRAM_MODULE=TableDESCR_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProgramModuleImpl::get_TablePATCH_PROGRAM_MODULE(void)
{
return Object->TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)
{
Object->TablePATCH_PROGRAM_MODULE=TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProgramModuleImpl::get_TableIDBASE_PROGRAM_MODULE(void)
{
return Object->TableIDBASE_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_TableIDBASE_PROGRAM_MODULE(TFIBLargeIntField * TableIDBASE_PROGRAM_MODULE)
{
Object->TableIDBASE_PROGRAM_MODULE=TableIDBASE_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProgramModuleImpl::get_ElementID_PROGRAM_MODULE(void)
{
return Object->ElementID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_ElementID_PROGRAM_MODULE(TFIBLargeIntField * ElementID_PROGRAM_MODULE)
{
Object->ElementID_PROGRAM_MODULE=ElementID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProgramModuleImpl::get_ElementNAME_PROGRAM_MODULE(void)
{
return Object->ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)
{
Object->ElementNAME_PROGRAM_MODULE=ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProgramModuleImpl::get_ElementPROGID_PROGRAM_MODULE(void)
{
return Object->ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)
{
Object->ElementPROGID_PROGRAM_MODULE=ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProgramModuleImpl::get_ElementMODULE_PROGRAM_MODULE(void)
{
return Object->ElementMODULE_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_ElementMODULE_PROGRAM_MODULE(TFIBWideStringField * ElementMODULE_PROGRAM_MODULE)
{
Object->ElementMODULE_PROGRAM_MODULE=ElementMODULE_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProgramModuleImpl::get_ElementDESCR_PROGRAM_MODULE(void)
{
return Object->ElementDESCR_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_ElementDESCR_PROGRAM_MODULE(TFIBWideStringField * ElementDESCR_PROGRAM_MODULE)
{
Object->ElementDESCR_PROGRAM_MODULE=ElementDESCR_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProgramModuleImpl::get_ElementPATCH_PROGRAM_MODULE(void)
{
return Object->ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)
{
Object->ElementPATCH_PROGRAM_MODULE=ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProgramModuleImpl::get_ElementIDBASE_PROGRAM_MODULE(void)
{
return Object->ElementIDBASE_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_ElementIDBASE_PROGRAM_MODULE(TFIBLargeIntField * ElementIDBASE_PROGRAM_MODULE)
{
Object->ElementIDBASE_PROGRAM_MODULE=ElementIDBASE_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TIntegerField * TDMSprProgramModuleImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprProgramModuleImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProgramModuleImpl::get_TableGUID_PROGRAM_MODULE(void)
{
return Object->TableGUID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_TableGUID_PROGRAM_MODULE(TFIBWideStringField * TableGUID_PROGRAM_MODULE)
{
Object->TableGUID_PROGRAM_MODULE=TableGUID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProgramModuleImpl::get_ElementGUID_PROGRAM_MODULE(void)
{
return Object->ElementGUID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_ElementGUID_PROGRAM_MODULE(TFIBWideStringField * ElementGUID_PROGRAM_MODULE)
{
Object->ElementGUID_PROGRAM_MODULE=ElementGUID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProgramModuleImpl::get_TableTYPEMOD_PROGRAM_MODULE(void)
{
return Object->TableTYPEMOD_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_TableTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * TableTYPEMOD_PROGRAM_MODULE)
{
Object->TableTYPEMOD_PROGRAM_MODULE=TableTYPEMOD_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProgramModuleImpl::get_ElementTYPEMOD_PROGRAM_MODULE(void)
{
return Object->ElementTYPEMOD_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::set_ElementTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * ElementTYPEMOD_PROGRAM_MODULE)
{
Object->ElementTYPEMOD_PROGRAM_MODULE=ElementTYPEMOD_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprProgramModuleImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprProgramModuleImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprProgramModuleImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprProgramModuleImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
GUID TDMSprProgramModuleImpl::GetCLSIDFromProgID(UnicodeString prog_id)
{
return Object->GetCLSIDFromProgID(prog_id);
}
//---------------------------------------------------------------
UnicodeString TDMSprProgramModuleImpl::GetProgIDFromCLSID (GUID guid)
{
return Object->GetProgIDFromCLSID (guid);
}
//---------------------------------------------------------------
UnicodeString TDMSprProgramModuleImpl::GetNameModuleFromCLSID(GUID guid)
{
return Object->GetNameModuleFromCLSID(guid);
}
//---------------------------------------------------------------
UnicodeString TDMSprProgramModuleImpl::GetFullPatchFromCLSID(GUID guid)
{
return Object->GetFullPatchFromCLSID(guid);
}
//---------------------------------------------------------------
__int64 TDMSprProgramModuleImpl::GetIdModuleFromGUID(GUID guid)
{
return Object->GetIdModuleFromGUID(guid);
}
//---------------------------------------------------------------
__int64 TDMSprProgramModuleImpl::GetIdModuleFromProgId(UnicodeString prog_id)
{
return Object->GetIdModuleFromProgId(prog_id);
}
//---------------------------------------------------------------
