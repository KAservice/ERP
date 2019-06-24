#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprActCategoryImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprActCategoryImpl::TREM_DMSprActCategoryImpl()           
{                                            
Object=new TREM_DMSprActCategory(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprActCategoryImpl::~TREM_DMSprActCategoryImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprActCategoryImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprActCategory)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprActCategory*> (this);                                
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
int TREM_DMSprActCategoryImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprActCategoryImpl::kanRelease(void)                                  
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
int  TREM_DMSprActCategoryImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprActCategoryImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprActCategoryImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprActCategoryImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprActCategoryImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprActCategory
TDataSource * TREM_DMSprActCategoryImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprActCategoryImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprActCategoryImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprActCategoryImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprActCategoryImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprActCategoryImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprActCategoryImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprActCategoryImpl::get_TableID_REM_SACTCATEGORY(void)
{
return Object->TableID_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_TableID_REM_SACTCATEGORY(TFIBLargeIntField * TableID_REM_SACTCATEGORY)
{
Object->TableID_REM_SACTCATEGORY=TableID_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprActCategoryImpl::get_TableIDBASE_REM_SACTCATEGORY(void)
{
return Object->TableIDBASE_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_TableIDBASE_REM_SACTCATEGORY(TFIBLargeIntField * TableIDBASE_REM_SACTCATEGORY)
{
Object->TableIDBASE_REM_SACTCATEGORY=TableIDBASE_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprActCategoryImpl::get_TableGID_REM_SACTCATEGORY(void)
{
return Object->TableGID_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_TableGID_REM_SACTCATEGORY(TFIBWideStringField * TableGID_REM_SACTCATEGORY)
{
Object->TableGID_REM_SACTCATEGORY=TableGID_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprActCategoryImpl::get_TableNAME_REM_SACTCATEGORY(void)
{
return Object->TableNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_TableNAME_REM_SACTCATEGORY(TFIBWideStringField * TableNAME_REM_SACTCATEGORY)
{
Object->TableNAME_REM_SACTCATEGORY=TableNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprActCategoryImpl::get_ElementID_REM_SACTCATEGORY(void)
{
return Object->ElementID_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_ElementID_REM_SACTCATEGORY(TFIBLargeIntField * ElementID_REM_SACTCATEGORY)
{
Object->ElementID_REM_SACTCATEGORY=ElementID_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprActCategoryImpl::get_ElementIDBASE_REM_SACTCATEGORY(void)
{
return Object->ElementIDBASE_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_ElementIDBASE_REM_SACTCATEGORY(TFIBLargeIntField * ElementIDBASE_REM_SACTCATEGORY)
{
Object->ElementIDBASE_REM_SACTCATEGORY=ElementIDBASE_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprActCategoryImpl::get_ElementGID_REM_SACTCATEGORY(void)
{
return Object->ElementGID_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_ElementGID_REM_SACTCATEGORY(TFIBWideStringField * ElementGID_REM_SACTCATEGORY)
{
Object->ElementGID_REM_SACTCATEGORY=ElementGID_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprActCategoryImpl::get_ElementNAME_REM_SACTCATEGORY(void)
{
return Object->ElementNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY)
{
Object->ElementNAME_REM_SACTCATEGORY=ElementNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprActCategoryImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TREM_DMSprActCategoryImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprActCategoryImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TREM_DMSprActCategoryImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprActCategoryImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
