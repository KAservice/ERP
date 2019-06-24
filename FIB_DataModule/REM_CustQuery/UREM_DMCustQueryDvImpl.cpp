#include "vcl.h"
#pragma hdrstop


#include "UREM_DMCustQueryDvImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMCustQueryDvImpl::TREM_DMCustQueryDvImpl()           
{                                            
Object=new TREM_DMCustQueryDv(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMCustQueryDvImpl::~TREM_DMCustQueryDvImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMCustQueryDvImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMCustQueryDv)                        
   {                                                                     
   *ppv=static_cast<IREM_DMCustQueryDv*> (this);                                
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
int TREM_DMCustQueryDvImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMCustQueryDvImpl::kanRelease(void)                                  
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
int  TREM_DMCustQueryDvImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMCustQueryDvImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMCustQueryDvImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMCustQueryDvImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMCustQueryDvImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMCustQueryDv
TDataSource * TREM_DMCustQueryDvImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMCustQueryDvImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMCustQueryDvImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMCustQueryDvImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMCustQueryDvImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMCustQueryDvImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMCustQueryDvImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryDvImpl::get_TableID_REM_CQUERYT_DV(void)
{
return Object->TableID_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_TableID_REM_CQUERYT_DV(TFIBLargeIntField * TableID_REM_CQUERYT_DV)
{
Object->TableID_REM_CQUERYT_DV=TableID_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryDvImpl::get_TableGID_REM_CQUERYT_DV(void)
{
return Object->TableGID_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_TableGID_REM_CQUERYT_DV(TFIBWideStringField * TableGID_REM_CQUERYT_DV)
{
Object->TableGID_REM_CQUERYT_DV=TableGID_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryDvImpl::get_TableIDBASE_REM_CQUERYT_DV(void)
{
return Object->TableIDBASE_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_TableIDBASE_REM_CQUERYT_DV(TFIBLargeIntField * TableIDBASE_REM_CQUERYT_DV)
{
Object->TableIDBASE_REM_CQUERYT_DV=TableIDBASE_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryDvImpl::get_TableIDCQT_REM_CQUERYT_DV(void)
{
return Object->TableIDCQT_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_TableIDCQT_REM_CQUERYT_DV(TFIBLargeIntField * TableIDCQT_REM_CQUERYT_DV)
{
Object->TableIDCQT_REM_CQUERYT_DV=TableIDCQT_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryDvImpl::get_TableIDUSER_REM_CQUERYT_DV(void)
{
return Object->TableIDUSER_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_TableIDUSER_REM_CQUERYT_DV(TFIBLargeIntField * TableIDUSER_REM_CQUERYT_DV)
{
Object->TableIDUSER_REM_CQUERYT_DV=TableIDUSER_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryDvImpl::get_TableIDSOST_REM_CQUERYT_DV(void)
{
return Object->TableIDSOST_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_TableIDSOST_REM_CQUERYT_DV(TFIBLargeIntField * TableIDSOST_REM_CQUERYT_DV)
{
Object->TableIDSOST_REM_CQUERYT_DV=TableIDSOST_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMCustQueryDvImpl::get_TablePOS_REM_CQUERYT_DV(void)
{
return Object->TablePOS_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_TablePOS_REM_CQUERYT_DV(TFIBDateTimeField * TablePOS_REM_CQUERYT_DV)
{
Object->TablePOS_REM_CQUERYT_DV=TablePOS_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryDvImpl::get_TableNAME_REM_SSOST_CQUERY(void)
{
return Object->TableNAME_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_TableNAME_REM_SSOST_CQUERY(TFIBWideStringField * TableNAME_REM_SSOST_CQUERY)
{
Object->TableNAME_REM_SSOST_CQUERY=TableNAME_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryDvImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryDvImpl::get_ElementID_REM_CQUERYT_DV(void)
{
return Object->ElementID_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_ElementID_REM_CQUERYT_DV(TFIBLargeIntField * ElementID_REM_CQUERYT_DV)
{
Object->ElementID_REM_CQUERYT_DV=ElementID_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryDvImpl::get_ElementGID_REM_CQUERYT_DV(void)
{
return Object->ElementGID_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_ElementGID_REM_CQUERYT_DV(TFIBWideStringField * ElementGID_REM_CQUERYT_DV)
{
Object->ElementGID_REM_CQUERYT_DV=ElementGID_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryDvImpl::get_ElementIDBASE_REM_CQUERYT_DV(void)
{
return Object->ElementIDBASE_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_ElementIDBASE_REM_CQUERYT_DV(TFIBLargeIntField * ElementIDBASE_REM_CQUERYT_DV)
{
Object->ElementIDBASE_REM_CQUERYT_DV=ElementIDBASE_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryDvImpl::get_ElementIDCQT_REM_CQUERYT_DV(void)
{
return Object->ElementIDCQT_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_ElementIDCQT_REM_CQUERYT_DV(TFIBLargeIntField * ElementIDCQT_REM_CQUERYT_DV)
{
Object->ElementIDCQT_REM_CQUERYT_DV=ElementIDCQT_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryDvImpl::get_ElementIDUSER_REM_CQUERYT_DV(void)
{
return Object->ElementIDUSER_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_ElementIDUSER_REM_CQUERYT_DV(TFIBLargeIntField * ElementIDUSER_REM_CQUERYT_DV)
{
Object->ElementIDUSER_REM_CQUERYT_DV=ElementIDUSER_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryDvImpl::get_ElementIDSOST_REM_CQUERYT_DV(void)
{
return Object->ElementIDSOST_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_ElementIDSOST_REM_CQUERYT_DV(TFIBLargeIntField * ElementIDSOST_REM_CQUERYT_DV)
{
Object->ElementIDSOST_REM_CQUERYT_DV=ElementIDSOST_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMCustQueryDvImpl::get_ElementPOS_REM_CQUERYT_DV(void)
{
return Object->ElementPOS_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_ElementPOS_REM_CQUERYT_DV(TFIBDateTimeField * ElementPOS_REM_CQUERYT_DV)
{
Object->ElementPOS_REM_CQUERYT_DV=ElementPOS_REM_CQUERYT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryDvImpl::get_ElementNAME_REM_SSOST_CQUERY(void)
{
return Object->ElementNAME_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_ElementNAME_REM_SSOST_CQUERY(TFIBWideStringField * ElementNAME_REM_SSOST_CQUERY)
{
Object->ElementNAME_REM_SSOST_CQUERY=ElementNAME_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryDvImpl::get_ElementNAME_USER(void)
{
return Object->ElementNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)
{
Object->ElementNAME_USER=ElementNAME_USER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMCustQueryDvImpl::get_TableRUN_REM_CQUERY_DV(void)
{
return Object->TableRUN_REM_CQUERY_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_TableRUN_REM_CQUERY_DV(TFIBSmallIntField * TableRUN_REM_CQUERY_DV)
{
Object->TableRUN_REM_CQUERY_DV=TableRUN_REM_CQUERY_DV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMCustQueryDvImpl::get_TableACT_REM_CQUERY_DV(void)
{
return Object->TableACT_REM_CQUERY_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_TableACT_REM_CQUERY_DV(TFIBSmallIntField * TableACT_REM_CQUERY_DV)
{
Object->TableACT_REM_CQUERY_DV=TableACT_REM_CQUERY_DV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMCustQueryDvImpl::get_ElementRUN_REM_CQUERY_DV(void)
{
return Object->ElementRUN_REM_CQUERY_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_ElementRUN_REM_CQUERY_DV(TFIBSmallIntField * ElementRUN_REM_CQUERY_DV)
{
Object->ElementRUN_REM_CQUERY_DV=ElementRUN_REM_CQUERY_DV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMCustQueryDvImpl::get_ElementACT_REM_CQUERY_DV(void)
{
return Object->ElementACT_REM_CQUERY_DV;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_ElementACT_REM_CQUERY_DV(TFIBSmallIntField * ElementACT_REM_CQUERY_DV)
{
Object->ElementACT_REM_CQUERY_DV=ElementACT_REM_CQUERY_DV;
}
//---------------------------------------------------------------
bool TREM_DMCustQueryDvImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMCustQueryDvImpl::get_IdCustQueryT(void)
{
return Object->IdCustQueryT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::set_IdCustQueryT(__int64 IdCustQueryT)
{
Object->IdCustQueryT=IdCustQueryT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryDvImpl::OpenTable(__int64 id_cqt)
{
return Object->OpenTable(id_cqt);
}
//---------------------------------------------------------------
int TREM_DMCustQueryDvImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMCustQueryDvImpl::NewElement(__int64 id_cqt)
{
return Object->NewElement(id_cqt);
}
//---------------------------------------------------------------
bool TREM_DMCustQueryDvImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMCustQueryDvImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TREM_DMCustQueryDvImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TREM_DMCustQueryDvImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
bool TREM_DMCustQueryDvImpl::AddRecordDv(TDateTime pos,	__int64 id_cqt,	__int64 id_sost,__int64 id_user,int act,int run)
{
return Object->AddRecordDv(pos,	id_cqt,	id_sost,id_user, act, run);
}
//---------------------------------------------------------------
