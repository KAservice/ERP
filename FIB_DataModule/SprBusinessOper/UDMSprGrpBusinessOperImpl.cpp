#include "vcl.h"
#pragma hdrstop


#include "UDMSprGrpBusinessOperImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprGrpBusinessOperImpl::TDMSprGrpBusinessOperImpl()           
{                                            
Object=new TDMSprGrpBusinessOper(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprGrpBusinessOperImpl::~TDMSprGrpBusinessOperImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprGrpBusinessOperImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprGrpBusinessOper)                        
   {                                                                     
   *ppv=static_cast<IDMSprGrpBusinessOper*> (this);                                
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
int TDMSprGrpBusinessOperImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprGrpBusinessOperImpl::kanRelease(void)                                  
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
int  TDMSprGrpBusinessOperImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprGrpBusinessOperImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprGrpBusinessOperImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprGrpBusinessOperImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprGrpBusinessOperImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprGrpBusinessOper
TDataSource * TDMSprGrpBusinessOperImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprGrpBusinessOperImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpBusinessOperImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpBusinessOperImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpBusinessOperImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpBusinessOperImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprGrpBusinessOperImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpBusinessOperImpl::get_TableID_SBUSINESS_OPER_GRP(void)
{
return Object->TableID_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_TableID_SBUSINESS_OPER_GRP(TFIBLargeIntField * TableID_SBUSINESS_OPER_GRP)
{
Object->TableID_SBUSINESS_OPER_GRP=TableID_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpBusinessOperImpl::get_TableGID_SBUSINESS_OPER_GRP(void)
{
return Object->TableGID_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_TableGID_SBUSINESS_OPER_GRP(TFIBWideStringField * TableGID_SBUSINESS_OPER_GRP)
{
Object->TableGID_SBUSINESS_OPER_GRP=TableGID_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpBusinessOperImpl::get_TableIDBASE_SBUSINESS_OPER_GRP(void)
{
return Object->TableIDBASE_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_TableIDBASE_SBUSINESS_OPER_GRP(TFIBLargeIntField * TableIDBASE_SBUSINESS_OPER_GRP)
{
Object->TableIDBASE_SBUSINESS_OPER_GRP=TableIDBASE_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpBusinessOperImpl::get_TableIDGRP_SBUSINESS_OPER_GRP(void)
{
return Object->TableIDGRP_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_TableIDGRP_SBUSINESS_OPER_GRP(TFIBLargeIntField * TableIDGRP_SBUSINESS_OPER_GRP)
{
Object->TableIDGRP_SBUSINESS_OPER_GRP=TableIDGRP_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpBusinessOperImpl::get_TableNAME_SBUSINESS_OPER_GRP(void)
{
return Object->TableNAME_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_TableNAME_SBUSINESS_OPER_GRP(TFIBWideStringField * TableNAME_SBUSINESS_OPER_GRP)
{
Object->TableNAME_SBUSINESS_OPER_GRP=TableNAME_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpBusinessOperImpl::get_ElementID_SBUSINESS_OPER_GRP(void)
{
return Object->ElementID_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_ElementID_SBUSINESS_OPER_GRP(TFIBLargeIntField * ElementID_SBUSINESS_OPER_GRP)
{
Object->ElementID_SBUSINESS_OPER_GRP=ElementID_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpBusinessOperImpl::get_ElementGID_SBUSINESS_OPER_GRP(void)
{
return Object->ElementGID_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_ElementGID_SBUSINESS_OPER_GRP(TFIBWideStringField * ElementGID_SBUSINESS_OPER_GRP)
{
Object->ElementGID_SBUSINESS_OPER_GRP=ElementGID_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpBusinessOperImpl::get_ElementIDBASE_SBUSINESS_OPER_GRP(void)
{
return Object->ElementIDBASE_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_ElementIDBASE_SBUSINESS_OPER_GRP(TFIBLargeIntField * ElementIDBASE_SBUSINESS_OPER_GRP)
{
Object->ElementIDBASE_SBUSINESS_OPER_GRP=ElementIDBASE_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpBusinessOperImpl::get_ElementIDGRP_SBUSINESS_OPER_GRP(void)
{
return Object->ElementIDGRP_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_ElementIDGRP_SBUSINESS_OPER_GRP(TFIBLargeIntField * ElementIDGRP_SBUSINESS_OPER_GRP)
{
Object->ElementIDGRP_SBUSINESS_OPER_GRP=ElementIDGRP_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpBusinessOperImpl::get_ElementNAME_SBUSINESS_OPER_GRP(void)
{
return Object->ElementNAME_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::set_ElementNAME_SBUSINESS_OPER_GRP(TFIBWideStringField * ElementNAME_SBUSINESS_OPER_GRP)
{
Object->ElementNAME_SBUSINESS_OPER_GRP=ElementNAME_SBUSINESS_OPER_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprGrpBusinessOperImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprGrpBusinessOperImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprGrpBusinessOperImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprGrpBusinessOperImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprGrpBusinessOperImpl::GetIdPoName(UnicodeString name)
{
return Object->GetIdPoName(name);
}
//---------------------------------------------------------------
