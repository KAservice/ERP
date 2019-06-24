#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprSostImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprSostImpl::TREM_DMSprSostImpl()           
{                                            
Object=new TREM_DMSprSost(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprSostImpl::~TREM_DMSprSostImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprSostImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprSostImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprSost)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprSost*> (this);                                
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
int TREM_DMSprSostImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprSostImpl::kanRelease(void)                                  
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
int  TREM_DMSprSostImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprSostImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprSostImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprSostImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprSostImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprSost
TDataSource * TREM_DMSprSostImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprSostImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprSostImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprSostImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprSostImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprSostImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprSostImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprSostImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprSostImpl::get_TableID_REMSSOST(void)
{
return Object->TableID_REMSSOST;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_TableID_REMSSOST(TFIBLargeIntField * TableID_REMSSOST)
{
Object->TableID_REMSSOST=TableID_REMSSOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprSostImpl::get_TableGID_REMSSOST(void)
{
return Object->TableGID_REMSSOST;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_TableGID_REMSSOST(TFIBWideStringField * TableGID_REMSSOST)
{
Object->TableGID_REMSSOST=TableGID_REMSSOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprSostImpl::get_TableNAME_REMSSOST(void)
{
return Object->TableNAME_REMSSOST;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_TableNAME_REMSSOST(TFIBWideStringField * TableNAME_REMSSOST)
{
Object->TableNAME_REMSSOST=TableNAME_REMSSOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprSostImpl::get_TableIDBASE_REM_SSOST(void)
{
return Object->TableIDBASE_REM_SSOST;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_TableIDBASE_REM_SSOST(TFIBLargeIntField * TableIDBASE_REM_SSOST)
{
Object->TableIDBASE_REM_SSOST=TableIDBASE_REM_SSOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprSostImpl::get_ElementID_REMSSOST(void)
{
return Object->ElementID_REMSSOST;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_ElementID_REMSSOST(TFIBLargeIntField * ElementID_REMSSOST)
{
Object->ElementID_REMSSOST=ElementID_REMSSOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprSostImpl::get_ElementGID_REMSSOST(void)
{
return Object->ElementGID_REMSSOST;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_ElementGID_REMSSOST(TFIBWideStringField * ElementGID_REMSSOST)
{
Object->ElementGID_REMSSOST=ElementGID_REMSSOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprSostImpl::get_ElementNAME_REMSSOST(void)
{
return Object->ElementNAME_REMSSOST;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_ElementNAME_REMSSOST(TFIBWideStringField * ElementNAME_REMSSOST)
{
Object->ElementNAME_REMSSOST=ElementNAME_REMSSOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprSostImpl::get_ElementIDBASE_REM_SSOST(void)
{
return Object->ElementIDBASE_REM_SSOST;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::set_ElementIDBASE_REM_SSOST(TFIBLargeIntField * ElementIDBASE_REM_SSOST)
{
Object->ElementIDBASE_REM_SSOST=ElementIDBASE_REM_SSOST;
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TREM_DMSprSostImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TREM_DMSprSostImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprSostImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TREM_DMSprSostImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TREM_DMSprSostImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprSostImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
int TREM_DMSprSostImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
