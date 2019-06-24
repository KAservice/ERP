#include "vcl.h"
#pragma hdrstop


#include "UDMSprCustomerAccountGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprCustomerAccountGrpImpl::TDMSprCustomerAccountGrpImpl()           
{                                            
Object=new TDMSprCustomerAccountGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprCustomerAccountGrpImpl::~TDMSprCustomerAccountGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprCustomerAccountGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprCustomerAccountGrp)                        
   {                                                                     
   *ppv=static_cast<IDMSprCustomerAccountGrp*> (this);                                
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
int TDMSprCustomerAccountGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprCustomerAccountGrpImpl::kanRelease(void)                                  
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
int  TDMSprCustomerAccountGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprCustomerAccountGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerAccountGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprCustomerAccountGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerAccountGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprCustomerAccountGrp
TDataSource * TDMSprCustomerAccountGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprCustomerAccountGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerAccountGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerAccountGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerAccountGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerAccountGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprCustomerAccountGrpImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountGrpImpl::get_TableID_CUST_ACCOUNT_GRP(void)
{
return Object->TableID_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_TableID_CUST_ACCOUNT_GRP(TFIBLargeIntField * TableID_CUST_ACCOUNT_GRP)
{
Object->TableID_CUST_ACCOUNT_GRP=TableID_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountGrpImpl::get_TableIDBASE_CUST_ACCOUNT_GRP(void)
{
return Object->TableIDBASE_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_TableIDBASE_CUST_ACCOUNT_GRP(TFIBLargeIntField * TableIDBASE_CUST_ACCOUNT_GRP)
{
Object->TableIDBASE_CUST_ACCOUNT_GRP=TableIDBASE_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountGrpImpl::get_TableGID_CUST_ACCOUNT_GRP(void)
{
return Object->TableGID_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_TableGID_CUST_ACCOUNT_GRP(TFIBWideStringField * TableGID_CUST_ACCOUNT_GRP)
{
Object->TableGID_CUST_ACCOUNT_GRP=TableGID_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountGrpImpl::get_TableIDGRP_CUST_ACCOUNT_GRP(void)
{
return Object->TableIDGRP_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_TableIDGRP_CUST_ACCOUNT_GRP(TFIBLargeIntField * TableIDGRP_CUST_ACCOUNT_GRP)
{
Object->TableIDGRP_CUST_ACCOUNT_GRP=TableIDGRP_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountGrpImpl::get_TableNAME_CUST_ACCOUNT_GRP(void)
{
return Object->TableNAME_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_TableNAME_CUST_ACCOUNT_GRP(TFIBWideStringField * TableNAME_CUST_ACCOUNT_GRP)
{
Object->TableNAME_CUST_ACCOUNT_GRP=TableNAME_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountGrpImpl::get_ElementID_CUST_ACCOUNT_GRP(void)
{
return Object->ElementID_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_ElementID_CUST_ACCOUNT_GRP(TFIBLargeIntField * ElementID_CUST_ACCOUNT_GRP)
{
Object->ElementID_CUST_ACCOUNT_GRP=ElementID_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountGrpImpl::get_ElementIDBASE_CUST_ACCOUNT_GRP(void)
{
return Object->ElementIDBASE_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_ElementIDBASE_CUST_ACCOUNT_GRP(TFIBLargeIntField * ElementIDBASE_CUST_ACCOUNT_GRP)
{
Object->ElementIDBASE_CUST_ACCOUNT_GRP=ElementIDBASE_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountGrpImpl::get_ElementGID_CUST_ACCOUNT_GRP(void)
{
return Object->ElementGID_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_ElementGID_CUST_ACCOUNT_GRP(TFIBWideStringField * ElementGID_CUST_ACCOUNT_GRP)
{
Object->ElementGID_CUST_ACCOUNT_GRP=ElementGID_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountGrpImpl::get_ElementIDGRP_CUST_ACCOUNT_GRP(void)
{
return Object->ElementIDGRP_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_ElementIDGRP_CUST_ACCOUNT_GRP(TFIBLargeIntField * ElementIDGRP_CUST_ACCOUNT_GRP)
{
Object->ElementIDGRP_CUST_ACCOUNT_GRP=ElementIDGRP_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountGrpImpl::get_ElementNAME_CUST_ACCOUNT_GRP(void)
{
return Object->ElementNAME_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::set_ElementNAME_CUST_ACCOUNT_GRP(TFIBWideStringField * ElementNAME_CUST_ACCOUNT_GRP)
{
Object->ElementNAME_CUST_ACCOUNT_GRP=ElementNAME_CUST_ACCOUNT_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprCustomerAccountGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprCustomerAccountGrpImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement( id);
}
//---------------------------------------------------------------
__int64 TDMSprCustomerAccountGrpImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
