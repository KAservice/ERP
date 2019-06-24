#include "vcl.h"
#pragma hdrstop


#include "UDMSprFactorImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprFactorImpl::TDMSprFactorImpl()           
{                                            
Object=new TDMSprFactor(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprFactorImpl::~TDMSprFactorImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprFactorImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprFactorImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprFactor)                        
   {                                                                     
   *ppv=static_cast<IDMSprFactor*> (this);                                
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
int TDMSprFactorImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprFactorImpl::kanRelease(void)                                  
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
int  TDMSprFactorImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprFactorImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprFactorImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprFactorImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprFactorImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprFactorImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprFactorImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprFactor
TDataSource * TDMSprFactorImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprFactorImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprFactorImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprFactorImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprFactorImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprFactorImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprFactorImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorImpl::get_TableID_SFACTOR(void)
{
return Object->TableID_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_TableID_SFACTOR(TFIBLargeIntField * TableID_SFACTOR)
{
Object->TableID_SFACTOR=TableID_SFACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFactorImpl::get_TableGID_SFACTOR(void)
{
return Object->TableGID_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_TableGID_SFACTOR(TFIBWideStringField * TableGID_SFACTOR)
{
Object->TableGID_SFACTOR=TableGID_SFACTOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorImpl::get_TableIDBASE_SFACTOR(void)
{
return Object->TableIDBASE_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_TableIDBASE_SFACTOR(TFIBLargeIntField * TableIDBASE_SFACTOR)
{
Object->TableIDBASE_SFACTOR=TableIDBASE_SFACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFactorImpl::get_TableNAME_SFACTOR(void)
{
return Object->TableNAME_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_TableNAME_SFACTOR(TFIBWideStringField * TableNAME_SFACTOR)
{
Object->TableNAME_SFACTOR=TableNAME_SFACTOR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprFactorImpl::get_TableINDEX_SFACTOR(void)
{
return Object->TableINDEX_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_TableINDEX_SFACTOR(TFIBIntegerField * TableINDEX_SFACTOR)
{
Object->TableINDEX_SFACTOR=TableINDEX_SFACTOR;
}
//---------------------------------------------------------------
TIntegerField * TDMSprFactorImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorImpl::get_ElementID_SFACTOR(void)
{
return Object->ElementID_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_ElementID_SFACTOR(TFIBLargeIntField * ElementID_SFACTOR)
{
Object->ElementID_SFACTOR=ElementID_SFACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFactorImpl::get_ElementGID_SFACTOR(void)
{
return Object->ElementGID_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_ElementGID_SFACTOR(TFIBWideStringField * ElementGID_SFACTOR)
{
Object->ElementGID_SFACTOR=ElementGID_SFACTOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorImpl::get_ElementIDBASE_SFACTOR(void)
{
return Object->ElementIDBASE_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_ElementIDBASE_SFACTOR(TFIBLargeIntField * ElementIDBASE_SFACTOR)
{
Object->ElementIDBASE_SFACTOR=ElementIDBASE_SFACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFactorImpl::get_ElementNAME_SFACTOR(void)
{
return Object->ElementNAME_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_ElementNAME_SFACTOR(TFIBWideStringField * ElementNAME_SFACTOR)
{
Object->ElementNAME_SFACTOR=ElementNAME_SFACTOR;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprFactorImpl::get_ElementINDEX_SFACTOR(void)
{
return Object->ElementINDEX_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::set_ElementINDEX_SFACTOR(TFIBIntegerField * ElementINDEX_SFACTOR)
{
Object->ElementINDEX_SFACTOR=ElementINDEX_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprFactorImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprFactorImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprFactorImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprFactorImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TDMSprFactorImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TDMSprFactorImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
bool TDMSprFactorImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
__int64 TDMSprFactorImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TDMSprFactorImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
int TDMSprFactorImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
