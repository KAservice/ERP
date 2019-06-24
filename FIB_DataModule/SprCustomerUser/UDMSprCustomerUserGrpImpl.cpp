#include "vcl.h"
#pragma hdrstop


#include "UDMSprCustomerUserGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprCustomerUserGrpImpl::TDMSprCustomerUserGrpImpl()           
{                                            
Object=new TDMSprCustomerUserGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprCustomerUserGrpImpl::~TDMSprCustomerUserGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprCustomerUserGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprCustomerUserGrp)                        
   {                                                                     
   *ppv=static_cast<IDMSprCustomerUserGrp*> (this);                                
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
int TDMSprCustomerUserGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprCustomerUserGrpImpl::kanRelease(void)                                  
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
int  TDMSprCustomerUserGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprCustomerUserGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerUserGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprCustomerUserGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerUserGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprCustomerUserGrp
TDataSource * TDMSprCustomerUserGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprCustomerUserGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerUserGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerUserGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerUserGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerUserGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserGrpImpl::get_TableID_CUST_USER_GRP(void)
{
return Object->TableID_CUST_USER_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_TableID_CUST_USER_GRP(TFIBLargeIntField * TableID_CUST_USER_GRP)
{
Object->TableID_CUST_USER_GRP=TableID_CUST_USER_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserGrpImpl::get_TableIDBASE_CUST_USER_GRP(void)
{
return Object->TableIDBASE_CUST_USER_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_TableIDBASE_CUST_USER_GRP(TFIBLargeIntField * TableIDBASE_CUST_USER_GRP)
{
Object->TableIDBASE_CUST_USER_GRP=TableIDBASE_CUST_USER_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerUserGrpImpl::get_TableGID_CUST_USER_GRP(void)
{
return Object->TableGID_CUST_USER_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_TableGID_CUST_USER_GRP(TFIBWideStringField * TableGID_CUST_USER_GRP)
{
Object->TableGID_CUST_USER_GRP=TableGID_CUST_USER_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserGrpImpl::get_TableIDGRP_CUST_USER_GRP(void)
{
return Object->TableIDGRP_CUST_USER_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_TableIDGRP_CUST_USER_GRP(TFIBLargeIntField * TableIDGRP_CUST_USER_GRP)
{
Object->TableIDGRP_CUST_USER_GRP=TableIDGRP_CUST_USER_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserGrpImpl::get_TableIDACCOUNT_CUST_USER_GRP(void)
{
return Object->TableIDACCOUNT_CUST_USER_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_TableIDACCOUNT_CUST_USER_GRP(TFIBLargeIntField * TableIDACCOUNT_CUST_USER_GRP)
{
Object->TableIDACCOUNT_CUST_USER_GRP=TableIDACCOUNT_CUST_USER_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerUserGrpImpl::get_TableNAME_CUST_USER_GRP(void)
{
return Object->TableNAME_CUST_USER_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_TableNAME_CUST_USER_GRP(TFIBWideStringField * TableNAME_CUST_USER_GRP)
{
Object->TableNAME_CUST_USER_GRP=TableNAME_CUST_USER_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserGrpImpl::get_ElementID_CUST_USER_GRP(void)
{
return Object->ElementID_CUST_USER_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_ElementID_CUST_USER_GRP(TFIBLargeIntField * ElementID_CUST_USER_GRP)
{
Object->ElementID_CUST_USER_GRP=ElementID_CUST_USER_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserGrpImpl::get_ElementIDBASE_CUST_USER_GRP(void)
{
return Object->ElementIDBASE_CUST_USER_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_ElementIDBASE_CUST_USER_GRP(TFIBLargeIntField * ElementIDBASE_CUST_USER_GRP)
{
Object->ElementIDBASE_CUST_USER_GRP=ElementIDBASE_CUST_USER_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerUserGrpImpl::get_ElementGID_CUST_USER_GRP(void)
{
return Object->ElementGID_CUST_USER_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_ElementGID_CUST_USER_GRP(TFIBWideStringField * ElementGID_CUST_USER_GRP)
{
Object->ElementGID_CUST_USER_GRP=ElementGID_CUST_USER_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserGrpImpl::get_ElementIDGRP_CUST_USER_GRP(void)
{
return Object->ElementIDGRP_CUST_USER_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_ElementIDGRP_CUST_USER_GRP(TFIBLargeIntField * ElementIDGRP_CUST_USER_GRP)
{
Object->ElementIDGRP_CUST_USER_GRP=ElementIDGRP_CUST_USER_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserGrpImpl::get_ElementIDACCOUNT_CUST_USER_GRP(void)
{
return Object->ElementIDACCOUNT_CUST_USER_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_ElementIDACCOUNT_CUST_USER_GRP(TFIBLargeIntField * ElementIDACCOUNT_CUST_USER_GRP)
{
Object->ElementIDACCOUNT_CUST_USER_GRP=ElementIDACCOUNT_CUST_USER_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerUserGrpImpl::get_ElementNAME_CUST_USER_GRP(void)
{
return Object->ElementNAME_CUST_USER_GRP;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_ElementNAME_CUST_USER_GRP(TFIBWideStringField * ElementNAME_CUST_USER_GRP)
{
Object->ElementNAME_CUST_USER_GRP=ElementNAME_CUST_USER_GRP;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerUserGrpImpl::get_IdAccount(void)
{
return Object->IdAccount;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_IdAccount(__int64 IdAccount)
{
Object->IdAccount=IdAccount;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerUserGrpImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::OpenTable(__int64 id_account)
{
return Object->OpenTable(id_account);
}
//---------------------------------------------------------------
int TDMSprCustomerUserGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::NewElement(__int64 id_account, __int64 id_grp)
{
return Object->NewElement(id_account,id_grp);
}
//---------------------------------------------------------------
bool TDMSprCustomerUserGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprCustomerUserGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
