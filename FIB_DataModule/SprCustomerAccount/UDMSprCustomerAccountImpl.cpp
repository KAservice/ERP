#include "vcl.h"
#pragma hdrstop


#include "UDMSprCustomerAccountImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprCustomerAccountImpl::TDMSprCustomerAccountImpl()           
{                                            
Object=new TDMSprCustomerAccount(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprCustomerAccountImpl::~TDMSprCustomerAccountImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprCustomerAccountImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprCustomerAccount)                        
   {                                                                     
   *ppv=static_cast<IDMSprCustomerAccount*> (this);                                
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
int TDMSprCustomerAccountImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprCustomerAccountImpl::kanRelease(void)                                  
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
int  TDMSprCustomerAccountImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprCustomerAccountImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerAccountImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprCustomerAccountImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerAccountImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprCustomerAccount
TDataSource * TDMSprCustomerAccountImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprCustomerAccountImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerAccountImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerAccountImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerAccountImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerAccountImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprCustomerAccountImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountImpl::get_TableID_CUST_ACCOUNT(void)
{
return Object->TableID_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TableID_CUST_ACCOUNT(TFIBLargeIntField * TableID_CUST_ACCOUNT)
{
Object->TableID_CUST_ACCOUNT=TableID_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountImpl::get_TableIDBASE_CUST_ACCOUNT(void)
{
return Object->TableIDBASE_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TableIDBASE_CUST_ACCOUNT(TFIBLargeIntField * TableIDBASE_CUST_ACCOUNT)
{
Object->TableIDBASE_CUST_ACCOUNT=TableIDBASE_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_TableGID_CUST_ACCOUNT(void)
{
return Object->TableGID_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TableGID_CUST_ACCOUNT(TFIBWideStringField * TableGID_CUST_ACCOUNT)
{
Object->TableGID_CUST_ACCOUNT=TableGID_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountImpl::get_TableIDGRP_CUST_ACCOUNT(void)
{
return Object->TableIDGRP_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TableIDGRP_CUST_ACCOUNT(TFIBLargeIntField * TableIDGRP_CUST_ACCOUNT)
{
Object->TableIDGRP_CUST_ACCOUNT=TableIDGRP_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_TableNAME_CUST_ACCOUNT(void)
{
return Object->TableNAME_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TableNAME_CUST_ACCOUNT(TFIBWideStringField * TableNAME_CUST_ACCOUNT)
{
Object->TableNAME_CUST_ACCOUNT=TableNAME_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_TableDESCR_CUST_ACCOUNT(void)
{
return Object->TableDESCR_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TableDESCR_CUST_ACCOUNT(TFIBWideStringField * TableDESCR_CUST_ACCOUNT)
{
Object->TableDESCR_CUST_ACCOUNT=TableDESCR_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountImpl::get_TableIDUSER_CUST_ACCOUNT(void)
{
return Object->TableIDUSER_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TableIDUSER_CUST_ACCOUNT(TFIBLargeIntField * TableIDUSER_CUST_ACCOUNT)
{
Object->TableIDUSER_CUST_ACCOUNT=TableIDUSER_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_TablePASSWORD_CUST_ACCOUNT(void)
{
return Object->TablePASSWORD_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TablePASSWORD_CUST_ACCOUNT(TFIBWideStringField * TablePASSWORD_CUST_ACCOUNT)
{
Object->TablePASSWORD_CUST_ACCOUNT=TablePASSWORD_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_TableLOGIN_CUST_ACCOUNT(void)
{
return Object->TableLOGIN_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TableLOGIN_CUST_ACCOUNT(TFIBWideStringField * TableLOGIN_CUST_ACCOUNT)
{
Object->TableLOGIN_CUST_ACCOUNT=TableLOGIN_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountImpl::get_ElementID_CUST_ACCOUNT(void)
{
return Object->ElementID_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_ElementID_CUST_ACCOUNT(TFIBLargeIntField * ElementID_CUST_ACCOUNT)
{
Object->ElementID_CUST_ACCOUNT=ElementID_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountImpl::get_ElementIDBASE_CUST_ACCOUNT(void)
{
return Object->ElementIDBASE_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_ElementIDBASE_CUST_ACCOUNT(TFIBLargeIntField * ElementIDBASE_CUST_ACCOUNT)
{
Object->ElementIDBASE_CUST_ACCOUNT=ElementIDBASE_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_ElementGID_CUST_ACCOUNT(void)
{
return Object->ElementGID_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_ElementGID_CUST_ACCOUNT(TFIBWideStringField * ElementGID_CUST_ACCOUNT)
{
Object->ElementGID_CUST_ACCOUNT=ElementGID_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountImpl::get_ElementIDGRP_CUST_ACCOUNT(void)
{
return Object->ElementIDGRP_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_ElementIDGRP_CUST_ACCOUNT(TFIBLargeIntField * ElementIDGRP_CUST_ACCOUNT)
{
Object->ElementIDGRP_CUST_ACCOUNT=ElementIDGRP_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_ElementNAME_CUST_ACCOUNT(void)
{
return Object->ElementNAME_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_ElementNAME_CUST_ACCOUNT(TFIBWideStringField * ElementNAME_CUST_ACCOUNT)
{
Object->ElementNAME_CUST_ACCOUNT=ElementNAME_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_ElementDESCR_CUST_ACCOUNT(void)
{
return Object->ElementDESCR_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_ElementDESCR_CUST_ACCOUNT(TFIBWideStringField * ElementDESCR_CUST_ACCOUNT)
{
Object->ElementDESCR_CUST_ACCOUNT=ElementDESCR_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountImpl::get_ElementIDUSER_CUST_ACCOUNT(void)
{
return Object->ElementIDUSER_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_ElementIDUSER_CUST_ACCOUNT(TFIBLargeIntField * ElementIDUSER_CUST_ACCOUNT)
{
Object->ElementIDUSER_CUST_ACCOUNT=ElementIDUSER_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_ElementPASSWORD_CUST_ACCOUNT(void)
{
return Object->ElementPASSWORD_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_ElementPASSWORD_CUST_ACCOUNT(TFIBWideStringField * ElementPASSWORD_CUST_ACCOUNT)
{
Object->ElementPASSWORD_CUST_ACCOUNT=ElementPASSWORD_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_ElementLOGIN_CUST_ACCOUNT(void)
{
return Object->ElementLOGIN_CUST_ACCOUNT;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_ElementLOGIN_CUST_ACCOUNT(TFIBWideStringField * ElementLOGIN_CUST_ACCOUNT)
{
Object->ElementLOGIN_CUST_ACCOUNT=ElementLOGIN_CUST_ACCOUNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_TableNAME_SGRPUSER(void)
{
return Object->TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER)
{
Object->TableNAME_SGRPUSER=TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountImpl::get_TableIDGRP_USER(void)
{
return Object->TableIDGRP_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_TableIDGRP_USER(TFIBLargeIntField * TableIDGRP_USER)
{
Object->TableIDGRP_USER=TableIDGRP_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_ElementNAME_USER(void)
{
return Object->ElementNAME_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)
{
Object->ElementNAME_USER=ElementNAME_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerAccountImpl::get_ElementIDGRP_USER(void)
{
return Object->ElementIDGRP_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_ElementIDGRP_USER(TFIBLargeIntField * ElementIDGRP_USER)
{
Object->ElementIDGRP_USER=ElementIDGRP_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerAccountImpl::get_ElementNAME_SGRPUSER(void)
{
return Object->ElementNAME_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_ElementNAME_SGRPUSER(TFIBWideStringField * ElementNAME_SGRPUSER)
{
Object->ElementNAME_SGRPUSER=ElementNAME_SGRPUSER;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerAccountImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerAccountImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
UnicodeString TDMSprCustomerAccountImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
int TDMSprCustomerAccountImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprCustomerAccountImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMSprCustomerAccountImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 TDMSprCustomerAccountImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TDMSprCustomerAccountImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
