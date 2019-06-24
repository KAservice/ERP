#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprSostCustQueryImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprSostCustQueryImpl::TREM_DMSprSostCustQueryImpl()           
{                                            
Object=new TREM_DMSprSostCustQuery(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprSostCustQueryImpl::~TREM_DMSprSostCustQueryImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprSostCustQueryImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprSostCustQuery)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprSostCustQuery*> (this);                                
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
int TREM_DMSprSostCustQueryImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprSostCustQueryImpl::kanRelease(void)                                  
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
int  TREM_DMSprSostCustQueryImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprSostCustQueryImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprSostCustQueryImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprSostCustQueryImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprSostCustQueryImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprSostCustQuery
TDataSource * TREM_DMSprSostCustQueryImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprSostCustQueryImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprSostCustQueryImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprSostCustQueryImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprSostCustQueryImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprSostCustQueryImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprSostCustQueryImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprSostCustQueryImpl::get_TableID_REM_SSOST_CQUERY(void)
{
return Object->TableID_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_TableID_REM_SSOST_CQUERY(TFIBLargeIntField * TableID_REM_SSOST_CQUERY)
{
Object->TableID_REM_SSOST_CQUERY=TableID_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprSostCustQueryImpl::get_TableGID_REM_SSOST_CQUERY(void)
{
return Object->TableGID_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_TableGID_REM_SSOST_CQUERY(TFIBWideStringField * TableGID_REM_SSOST_CQUERY)
{
Object->TableGID_REM_SSOST_CQUERY=TableGID_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprSostCustQueryImpl::get_TableIDBASE_REM_SSOST_CQUERY(void)
{
return Object->TableIDBASE_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_TableIDBASE_REM_SSOST_CQUERY(TFIBLargeIntField * TableIDBASE_REM_SSOST_CQUERY)
{
Object->TableIDBASE_REM_SSOST_CQUERY=TableIDBASE_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprSostCustQueryImpl::get_TableNAME_REM_SSOST_CQUERY(void)
{
return Object->TableNAME_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_TableNAME_REM_SSOST_CQUERY(TFIBWideStringField * TableNAME_REM_SSOST_CQUERY)
{
Object->TableNAME_REM_SSOST_CQUERY=TableNAME_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprSostCustQueryImpl::get_ElementID_REM_SSOST_CQUERY(void)
{
return Object->ElementID_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_ElementID_REM_SSOST_CQUERY(TFIBLargeIntField * ElementID_REM_SSOST_CQUERY)
{
Object->ElementID_REM_SSOST_CQUERY=ElementID_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprSostCustQueryImpl::get_ElementGID_REM_SSOST_CQUERY(void)
{
return Object->ElementGID_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_ElementGID_REM_SSOST_CQUERY(TFIBWideStringField * ElementGID_REM_SSOST_CQUERY)
{
Object->ElementGID_REM_SSOST_CQUERY=ElementGID_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprSostCustQueryImpl::get_ElementIDBASE_REM_SSOST_CQUERY(void)
{
return Object->ElementIDBASE_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_ElementIDBASE_REM_SSOST_CQUERY(TFIBLargeIntField * ElementIDBASE_REM_SSOST_CQUERY)
{
Object->ElementIDBASE_REM_SSOST_CQUERY=ElementIDBASE_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprSostCustQueryImpl::get_ElementNAME_REM_SSOST_CQUERY(void)
{
return Object->ElementNAME_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_ElementNAME_REM_SSOST_CQUERY(TFIBWideStringField * ElementNAME_REM_SSOST_CQUERY)
{
Object->ElementNAME_REM_SSOST_CQUERY=ElementNAME_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprSostCustQueryImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TREM_DMSprSostCustQueryImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TREM_DMSprSostCustQueryImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprSostCustQueryImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TREM_DMSprSostCustQueryImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TREM_DMSprSostCustQueryImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprSostCustQueryImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
int TREM_DMSprSostCustQueryImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
