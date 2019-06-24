#include "vcl.h"
#pragma hdrstop


#include "UDMSprCustomerUserImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprCustomerUserImpl::TDMSprCustomerUserImpl()           
{                                            
Object=new TDMSprCustomerUser(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprCustomerUserImpl::~TDMSprCustomerUserImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprCustomerUserImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprCustomerUser)                        
   {                                                                     
   *ppv=static_cast<IDMSprCustomerUser*> (this);                                
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
int TDMSprCustomerUserImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprCustomerUserImpl::kanRelease(void)                                  
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
int  TDMSprCustomerUserImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprCustomerUserImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerUserImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprCustomerUserImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprCustomerUserImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprCustomerUser
TDataSource * TDMSprCustomerUserImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprCustomerUserImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerUserImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerUserImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCustomerUserImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCustomerUserImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprCustomerUserImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserImpl::get_TableID_CUST_USER(void)
{
return Object->TableID_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_TableID_CUST_USER(TFIBLargeIntField * TableID_CUST_USER)
{
Object->TableID_CUST_USER=TableID_CUST_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserImpl::get_TableIDBASE_CUST_USER(void)
{
return Object->TableIDBASE_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_TableIDBASE_CUST_USER(TFIBLargeIntField * TableIDBASE_CUST_USER)
{
Object->TableIDBASE_CUST_USER=TableIDBASE_CUST_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerUserImpl::get_TableGID_CUST_USER(void)
{
return Object->TableGID_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_TableGID_CUST_USER(TFIBWideStringField * TableGID_CUST_USER)
{
Object->TableGID_CUST_USER=TableGID_CUST_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserImpl::get_TableIDACCOUNT_CUST_USER(void)
{
return Object->TableIDACCOUNT_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_TableIDACCOUNT_CUST_USER(TFIBLargeIntField * TableIDACCOUNT_CUST_USER)
{
Object->TableIDACCOUNT_CUST_USER=TableIDACCOUNT_CUST_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserImpl::get_TableIDGRP_CUST_USER(void)
{
return Object->TableIDGRP_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_TableIDGRP_CUST_USER(TFIBLargeIntField * TableIDGRP_CUST_USER)
{
Object->TableIDGRP_CUST_USER=TableIDGRP_CUST_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerUserImpl::get_TableNAME_CUST_USER(void)
{
return Object->TableNAME_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_TableNAME_CUST_USER(TFIBWideStringField * TableNAME_CUST_USER)
{
Object->TableNAME_CUST_USER=TableNAME_CUST_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerUserImpl::get_TableLOGIN_CUST_USER(void)
{
return Object->TableLOGIN_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_TableLOGIN_CUST_USER(TFIBWideStringField * TableLOGIN_CUST_USER)
{
Object->TableLOGIN_CUST_USER=TableLOGIN_CUST_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerUserImpl::get_TablePASSWORD_CUST_USER(void)
{
return Object->TablePASSWORD_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_TablePASSWORD_CUST_USER(TFIBWideStringField * TablePASSWORD_CUST_USER)
{
Object->TablePASSWORD_CUST_USER=TablePASSWORD_CUST_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserImpl::get_ElementID_CUST_USER(void)
{
return Object->ElementID_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_ElementID_CUST_USER(TFIBLargeIntField * ElementID_CUST_USER)
{
Object->ElementID_CUST_USER=ElementID_CUST_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserImpl::get_ElementIDBASE_CUST_USER(void)
{
return Object->ElementIDBASE_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_ElementIDBASE_CUST_USER(TFIBLargeIntField * ElementIDBASE_CUST_USER)
{
Object->ElementIDBASE_CUST_USER=ElementIDBASE_CUST_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerUserImpl::get_ElementGID_CUST_USER(void)
{
return Object->ElementGID_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_ElementGID_CUST_USER(TFIBWideStringField * ElementGID_CUST_USER)
{
Object->ElementGID_CUST_USER=ElementGID_CUST_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserImpl::get_ElementIDACCOUNT_CUST_USER(void)
{
return Object->ElementIDACCOUNT_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_ElementIDACCOUNT_CUST_USER(TFIBLargeIntField * ElementIDACCOUNT_CUST_USER)
{
Object->ElementIDACCOUNT_CUST_USER=ElementIDACCOUNT_CUST_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprCustomerUserImpl::get_ElementIDGRP_CUST_USER(void)
{
return Object->ElementIDGRP_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_ElementIDGRP_CUST_USER(TFIBLargeIntField * ElementIDGRP_CUST_USER)
{
Object->ElementIDGRP_CUST_USER=ElementIDGRP_CUST_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerUserImpl::get_ElementNAME_CUST_USER(void)
{
return Object->ElementNAME_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_ElementNAME_CUST_USER(TFIBWideStringField * ElementNAME_CUST_USER)
{
Object->ElementNAME_CUST_USER=ElementNAME_CUST_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerUserImpl::get_ElementLOGIN_CUST_USER(void)
{
return Object->ElementLOGIN_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_ElementLOGIN_CUST_USER(TFIBWideStringField * ElementLOGIN_CUST_USER)
{
Object->ElementLOGIN_CUST_USER=ElementLOGIN_CUST_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCustomerUserImpl::get_ElementPASSWORD_CUST_USER(void)
{
return Object->ElementPASSWORD_CUST_USER;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_ElementPASSWORD_CUST_USER(TFIBWideStringField * ElementPASSWORD_CUST_USER)
{
Object->ElementPASSWORD_CUST_USER=ElementPASSWORD_CUST_USER;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerUserImpl::get_IdAccount(void)
{
return Object->IdAccount;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_IdAccount(__int64 IdAccount)
{
Object->IdAccount=IdAccount;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerUserImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
__int64 TDMSprCustomerUserImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprCustomerUserImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
UnicodeString TDMSprCustomerUserImpl::GetTextQuery(__int64 id_account,__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_account,id_grp,all);
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::OpenTable(__int64 id_account,__int64 id_grp,bool all)
{
return Object->OpenTable(id_account,id_grp,all);
}
//---------------------------------------------------------------
int TDMSprCustomerUserImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprCustomerUserImpl::NewElement(__int64 id_account,__int64 id_grp)
{
return Object->NewElement(id_account,id_grp);
}
//---------------------------------------------------------------
bool TDMSprCustomerUserImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprCustomerUserImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement( id);
}
//---------------------------------------------------------------
__int64 TDMSprCustomerUserImpl::FindPoName(UnicodeString NameUser)
{
return Object->FindPoName(NameUser);
}
//---------------------------------------------------------------
__int64 TDMSprCustomerUserImpl::FindPoPassword(UnicodeString Password)
{
return Object->FindPoPassword(Password);
}
//---------------------------------------------------------------
__int64 TDMSprCustomerUserImpl::GetIdGrpUser(__int64 id_user)
{
return Object->GetIdGrpUser(id_user);
}
//---------------------------------------------------------------
void TDMSprCustomerUserImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
