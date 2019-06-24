#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprTypeRemontImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprTypeRemontImpl::TREM_DMSprTypeRemontImpl()           
{                                            
Object=new TREM_DMSprTypeRemont(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprTypeRemontImpl::~TREM_DMSprTypeRemontImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprTypeRemontImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprTypeRemont)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprTypeRemont*> (this);                                
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
int TREM_DMSprTypeRemontImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprTypeRemontImpl::kanRelease(void)                                  
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
int  TREM_DMSprTypeRemontImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprTypeRemontImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTypeRemontImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprTypeRemontImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTypeRemontImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprTypeRemont
TDataSource * TREM_DMSprTypeRemontImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprTypeRemontImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTypeRemontImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTypeRemontImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTypeRemontImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprTypeRemontImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprTypeRemontImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypeRemontImpl::get_ElementID_STREMONT(void)
{
return Object->ElementID_STREMONT;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_ElementID_STREMONT(TFIBLargeIntField * ElementID_STREMONT)
{
Object->ElementID_STREMONT=ElementID_STREMONT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypeRemontImpl::get_ElementGID_STREMONT(void)
{
return Object->ElementGID_STREMONT;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_ElementGID_STREMONT(TFIBWideStringField * ElementGID_STREMONT)
{
Object->ElementGID_STREMONT=ElementGID_STREMONT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypeRemontImpl::get_ElementNAME_STREMONT(void)
{
return Object->ElementNAME_STREMONT;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_ElementNAME_STREMONT(TFIBWideStringField * ElementNAME_STREMONT)
{
Object->ElementNAME_STREMONT=ElementNAME_STREMONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypeRemontImpl::get_ElementIDBASE_REM_STREMONT(void)
{
return Object->ElementIDBASE_REM_STREMONT;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_ElementIDBASE_REM_STREMONT(TFIBLargeIntField * ElementIDBASE_REM_STREMONT)
{
Object->ElementIDBASE_REM_STREMONT=ElementIDBASE_REM_STREMONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypeRemontImpl::get_TableID_STREMONT(void)
{
return Object->TableID_STREMONT;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_TableID_STREMONT(TFIBLargeIntField * TableID_STREMONT)
{
Object->TableID_STREMONT=TableID_STREMONT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypeRemontImpl::get_TableGID_STREMONT(void)
{
return Object->TableGID_STREMONT;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_TableGID_STREMONT(TFIBWideStringField * TableGID_STREMONT)
{
Object->TableGID_STREMONT=TableGID_STREMONT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypeRemontImpl::get_TableNAME_STREMONT(void)
{
return Object->TableNAME_STREMONT;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_TableNAME_STREMONT(TFIBWideStringField * TableNAME_STREMONT)
{
Object->TableNAME_STREMONT=TableNAME_STREMONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypeRemontImpl::get_TableIDBASE_REM_STREMONT(void)
{
return Object->TableIDBASE_REM_STREMONT;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_TableIDBASE_REM_STREMONT(TFIBLargeIntField * TableIDBASE_REM_STREMONT)
{
Object->TableIDBASE_REM_STREMONT=TableIDBASE_REM_STREMONT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTypeRemontImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TREM_DMSprTypeRemontImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TREM_DMSprTypeRemontImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprTypeRemontImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TREM_DMSprTypeRemontImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TREM_DMSprTypeRemontImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprTypeRemontImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
int TREM_DMSprTypeRemontImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
