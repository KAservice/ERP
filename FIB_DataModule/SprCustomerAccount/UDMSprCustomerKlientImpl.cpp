#include "vcl.h"
#pragma hdrstop


#include "UDMSprCustomerKlientImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprCustomerKlientImpl::TDMSprCustomerKlientImpl()           
{                                            
Object=new TDMSprCustomerKlient(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprCustomerKlientImpl::~TDMSprCustomerKlientImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprCustomerKlientImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprCustomerKlient)                        
   {                                                                     
   *ppv=static_cast<IDMSprCustomerKlient*> (this);                                
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
int TDMSprCustomerKlientImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprCustomerKlientImpl::kanRelease(void)                                  
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
int  TDMSprCustomerKlientImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprCustomerKlientImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerKlientImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprCustomerKlientImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerKlientImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprCustomerKlient
TDataSource * TDMSprCustomerKlientImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerKlientImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerKlientImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerKlientImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TDMSprCustomerKlientImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerKlientImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerKlientImpl::get_TableID_CUST_KLIENT(void)
{
return Object->TableID_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_TableID_CUST_KLIENT(TFIBLargeIntField * TableID_CUST_KLIENT)
{
Object->TableID_CUST_KLIENT=TableID_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerKlientImpl::get_TableIDBASE_CUST_KLIENT(void)
{
return Object->TableIDBASE_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_TableIDBASE_CUST_KLIENT(TFIBLargeIntField * TableIDBASE_CUST_KLIENT)
{
Object->TableIDBASE_CUST_KLIENT=TableIDBASE_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerKlientImpl::get_TableGID_CUST_KLIENT(void)
{
return Object->TableGID_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_TableGID_CUST_KLIENT(TFIBWideStringField * TableGID_CUST_KLIENT)
{
Object->TableGID_CUST_KLIENT=TableGID_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerKlientImpl::get_TableIDACCOUNT_CUST_KLIENT(void)
{
return Object->TableIDACCOUNT_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_TableIDACCOUNT_CUST_KLIENT(TFIBLargeIntField * TableIDACCOUNT_CUST_KLIENT)
{
Object->TableIDACCOUNT_CUST_KLIENT=TableIDACCOUNT_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerKlientImpl::get_TableIDKLIENT_CUST_KLIENT(void)
{
return Object->TableIDKLIENT_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_TableIDKLIENT_CUST_KLIENT(TFIBLargeIntField * TableIDKLIENT_CUST_KLIENT)
{
Object->TableIDKLIENT_CUST_KLIENT=TableIDKLIENT_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerKlientImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerKlientImpl::get_ElementID_CUST_KLIENT(void)
{
return Object->ElementID_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_ElementID_CUST_KLIENT(TFIBLargeIntField * ElementID_CUST_KLIENT)
{
Object->ElementID_CUST_KLIENT=ElementID_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerKlientImpl::get_ElementIDBASE_CUST_KLIENT(void)
{
return Object->ElementIDBASE_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_ElementIDBASE_CUST_KLIENT(TFIBLargeIntField * ElementIDBASE_CUST_KLIENT)
{
Object->ElementIDBASE_CUST_KLIENT=ElementIDBASE_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerKlientImpl::get_ElementGID_CUST_KLIENT(void)
{
return Object->ElementGID_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_ElementGID_CUST_KLIENT(TFIBWideStringField * ElementGID_CUST_KLIENT)
{
Object->ElementGID_CUST_KLIENT=ElementGID_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerKlientImpl::get_ElementIDACCOUNT_CUST_KLIENT(void)
{
return Object->ElementIDACCOUNT_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_ElementIDACCOUNT_CUST_KLIENT(TFIBLargeIntField * ElementIDACCOUNT_CUST_KLIENT)
{
Object->ElementIDACCOUNT_CUST_KLIENT=ElementIDACCOUNT_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerKlientImpl::get_ElementIDKLIENT_CUST_KLIENT(void)
{
return Object->ElementIDKLIENT_CUST_KLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_ElementIDKLIENT_CUST_KLIENT(TFIBLargeIntField * ElementIDKLIENT_CUST_KLIENT)
{
Object->ElementIDKLIENT_CUST_KLIENT=ElementIDKLIENT_CUST_KLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerKlientImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerKlientImpl::get_IdAccount(void)
{
return Object->IdAccount;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_IdAccount(__int64 IdAccount)
{
Object->IdAccount=IdAccount;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerKlientImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprCustomerKlientImpl::OpenTable(__int64 id_account)
{
return Object->OpenTable(id_account);
}
//---------------------------------------------------------------
bool TDMSprCustomerKlientImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
bool TDMSprCustomerKlientImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool TDMSprCustomerKlientImpl::TableAppend(__int64 id_account)
{
return Object->TableAppend(id_account);
}
//---------------------------------------------------------------
bool TDMSprCustomerKlientImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
bool TDMSprCustomerKlientImpl::NewElement(__int64 id_account)
{
return Object->NewElement(id_account);
}
//---------------------------------------------------------------
int TDMSprCustomerKlientImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprCustomerKlientImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprCustomerKlientImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
