#include "vcl.h"
#pragma hdrstop


#include "UDMSprBusinessOperImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprBusinessOperImpl::TDMSprBusinessOperImpl()           
{                                            
Object=new TDMSprBusinessOper(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprBusinessOperImpl::~TDMSprBusinessOperImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprBusinessOperImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprBusinessOper)                        
   {                                                                     
   *ppv=static_cast<IDMSprBusinessOper*> (this);                                
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
int TDMSprBusinessOperImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprBusinessOperImpl::kanRelease(void)                                  
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
int  TDMSprBusinessOperImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprBusinessOperImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprBusinessOperImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprBusinessOperImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprBusinessOperImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprBusinessOper
TDataSource * TDMSprBusinessOperImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprBusinessOperImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprBusinessOperImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprBusinessOperImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprBusinessOperImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprBusinessOperImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprBusinessOperImpl::get_TableID_SBUSINESS_OPER(void)
{
return Object->TableID_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_TableID_SBUSINESS_OPER(TFIBLargeIntField * TableID_SBUSINESS_OPER)
{
Object->TableID_SBUSINESS_OPER=TableID_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBusinessOperImpl::get_TableGID_SBUSINESS_OPER(void)
{
return Object->TableGID_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_TableGID_SBUSINESS_OPER(TFIBWideStringField * TableGID_SBUSINESS_OPER)
{
Object->TableGID_SBUSINESS_OPER=TableGID_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprBusinessOperImpl::get_TableIDBASE_SBUSINESS_OPER(void)
{
return Object->TableIDBASE_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_TableIDBASE_SBUSINESS_OPER(TFIBLargeIntField * TableIDBASE_SBUSINESS_OPER)
{
Object->TableIDBASE_SBUSINESS_OPER=TableIDBASE_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBusinessOperImpl::get_TableNAME_SBUSINESS_OPER(void)
{
return Object->TableNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_TableNAME_SBUSINESS_OPER(TFIBWideStringField * TableNAME_SBUSINESS_OPER)
{
Object->TableNAME_SBUSINESS_OPER=TableNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprBusinessOperImpl::get_TableIDGRP_SBUSINESS_OPER(void)
{
return Object->TableIDGRP_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_TableIDGRP_SBUSINESS_OPER(TFIBLargeIntField * TableIDGRP_SBUSINESS_OPER)
{
Object->TableIDGRP_SBUSINESS_OPER=TableIDGRP_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprBusinessOperImpl::get_ElementID_SBUSINESS_OPER(void)
{
return Object->ElementID_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_ElementID_SBUSINESS_OPER(TFIBLargeIntField * ElementID_SBUSINESS_OPER)
{
Object->ElementID_SBUSINESS_OPER=ElementID_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBusinessOperImpl::get_ElementGID_SBUSINESS_OPER(void)
{
return Object->ElementGID_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_ElementGID_SBUSINESS_OPER(TFIBWideStringField * ElementGID_SBUSINESS_OPER)
{
Object->ElementGID_SBUSINESS_OPER=ElementGID_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprBusinessOperImpl::get_ElementIDBASE_SBUSINESS_OPER(void)
{
return Object->ElementIDBASE_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_ElementIDBASE_SBUSINESS_OPER(TFIBLargeIntField * ElementIDBASE_SBUSINESS_OPER)
{
Object->ElementIDBASE_SBUSINESS_OPER=ElementIDBASE_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBusinessOperImpl::get_ElementNAME_SBUSINESS_OPER(void)
{
return Object->ElementNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_ElementNAME_SBUSINESS_OPER(TFIBWideStringField * ElementNAME_SBUSINESS_OPER)
{
Object->ElementNAME_SBUSINESS_OPER=ElementNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprBusinessOperImpl::get_ElementIDGRP_SBUSINESS_OPER(void)
{
return Object->ElementIDGRP_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_ElementIDGRP_SBUSINESS_OPER(TFIBLargeIntField * ElementIDGRP_SBUSINESS_OPER)
{
Object->ElementIDGRP_SBUSINESS_OPER=ElementIDGRP_SBUSINESS_OPER;
}
//---------------------------------------------------------------
__int64 TDMSprBusinessOperImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprBusinessOperImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprBusinessOperImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
int TDMSprBusinessOperImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprBusinessOperImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprBusinessOperImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprBusinessOperImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMSprBusinessOperImpl::ChancheGrp(__int64 new_id_grp)
{
return Object->ChancheGrp(new_id_grp);
}
//---------------------------------------------------------------
__int64 TDMSprBusinessOperImpl::GetIdPoName(UnicodeString name)
{
return Object->GetIdPoName(name);
}
//---------------------------------------------------------------
__int64 TDMSprBusinessOperImpl::GetIdGrpBusinessOper(__int64 id_bo)
{
return Object->GetIdGrpBusinessOper(id_bo);
}
//---------------------------------------------------------------
