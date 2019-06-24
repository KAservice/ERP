#include "vcl.h"
#pragma hdrstop


#include "UDMSprCustomerAccountKLientImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprCustomerAccountKLientImpl::TDMSprCustomerAccountKLientImpl()           
{                                            
Object=new TDMSprCustomerAccountKLient(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprCustomerAccountKLientImpl::~TDMSprCustomerAccountKLientImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprCustomerAccountKLientImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprCustomerAccountKLient)                        
   {                                                                     
   *ppv=static_cast<IDMSprCustomerAccountKLient*> (this);                                
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
int TDMSprCustomerAccountKLientImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprCustomerAccountKLientImpl::kanRelease(void)                                  
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
int  TDMSprCustomerAccountKLientImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprCustomerAccountKLientImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerAccountKLientImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprCustomerAccountKLientImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerAccountKLientImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprCustomerAccountKLient
TDataSource * TDMSprCustomerAccountKLientImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerAccountKLientImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerAccountKLientImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerAccountKLientImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TDMSprCustomerAccountKLientImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerAccountKLientImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountKLientImpl::get_TableID_CUST_KLIENT(void)
{
return Object->TableID_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_TableID_CUST_KLIENT(TFIBLargeIntField * TableID_CUST_KLIENT)
{
Object->TableID_CUST_KLIENT=TableID_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountKLientImpl::get_TableIDBASE_CUST_KLIENT(void)
{
return Object->TableIDBASE_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_TableIDBASE_CUST_KLIENT(TFIBLargeIntField * TableIDBASE_CUST_KLIENT)
{
Object->TableIDBASE_CUST_KLIENT=TableIDBASE_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountKLientImpl::get_TableGID_CUST_KLIENT(void)
{
return Object->TableGID_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_TableGID_CUST_KLIENT(TFIBWideStringField * TableGID_CUST_KLIENT)
{
Object->TableGID_CUST_KLIENT=TableGID_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountKLientImpl::get_TableIDACCOUNT_CUST_KLIENT(void)
{
return Object->TableIDACCOUNT_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_TableIDACCOUNT_CUST_KLIENT(TFIBLargeIntField * TableIDACCOUNT_CUST_KLIENT)
{
Object->TableIDACCOUNT_CUST_KLIENT=TableIDACCOUNT_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountKLientImpl::get_TableIDKLIENT_CUST_KLIENT(void)
{
return Object->TableIDKLIENT_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_TableIDKLIENT_CUST_KLIENT(TFIBLargeIntField * TableIDKLIENT_CUST_KLIENT)
{
Object->TableIDKLIENT_CUST_KLIENT=TableIDKLIENT_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountKLientImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountKLientImpl::get_ElementID_CUST_KLIENT(void)
{
return Object->ElementID_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_ElementID_CUST_KLIENT(TFIBLargeIntField * ElementID_CUST_KLIENT)
{
Object->ElementID_CUST_KLIENT=ElementID_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountKLientImpl::get_ElementIDBASE_CUST_KLIENT(void)
{
return Object->ElementIDBASE_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_ElementIDBASE_CUST_KLIENT(TFIBLargeIntField * ElementIDBASE_CUST_KLIENT)
{
Object->ElementIDBASE_CUST_KLIENT=ElementIDBASE_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountKLientImpl::get_ElementGID_CUST_KLIENT(void)
{
return Object->ElementGID_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_ElementGID_CUST_KLIENT(TFIBWideStringField * ElementGID_CUST_KLIENT)
{
Object->ElementGID_CUST_KLIENT=ElementGID_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountKLientImpl::get_ElementIDACCOUNT_CUST_KLIENT(void)
{
return Object->ElementIDACCOUNT_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_ElementIDACCOUNT_CUST_KLIENT(TFIBLargeIntField * ElementIDACCOUNT_CUST_KLIENT)
{
Object->ElementIDACCOUNT_CUST_KLIENT=ElementIDACCOUNT_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountKLientImpl::get_ElementIDKLIENT_CUST_KLIENT(void)
{
return Object->ElementIDKLIENT_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_ElementIDKLIENT_CUST_KLIENT(TFIBLargeIntField * ElementIDKLIENT_CUST_KLIENT)
{
Object->ElementIDKLIENT_CUST_KLIENT=ElementIDKLIENT_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountKLientImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerAccountKLientImpl::get_IdAccount(void)
{
return Object->IdAccount;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_IdAccount(__int64 IdAccount)
{
Object->IdAccount=IdAccount;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerAccountKLientImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountKLientImpl::OpenTable(__int64 id_account)
{
return Object->OpenTable(__int64 id_account);
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountKLientImpl::SaveIsmen(void)
{
return Object->SaveIsmen(void);
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountKLientImpl::CancelIsmen(void)
{
return Object->CancelIsmen(void);
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountKLientImpl::TableAppend(__int64 id_account)
{
return Object->TableAppend(__int64 id_account);
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountKLientImpl::TableDelete(void)
{
return Object->TableDelete(void);
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountKLientImpl::NewElement(__int64 id_account)
{
return Object->NewElement(__int64 id_account);
}
//---------------------------------------------------------------
int TDMSprCustomerAccountKLientImpl::OpenElement(__int64 id )
{
return Object->OpenElement(__int64 id );
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountKLientImpl::SaveElement(void)
{
return Object->SaveElement(void);
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountKLientImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(__int64 id);
}
//---------------------------------------------------------------
