#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMSprObjectImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMSprObjectImpl::THOT_DMSprObjectImpl()           
{                                            
Object=new THOT_DMSprObject(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMSprObjectImpl::~THOT_DMSprObjectImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMSprObjectImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMSprObject)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMSprObject*> (this);                                
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
int THOT_DMSprObjectImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMSprObjectImpl::kanRelease(void)                                  
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
int  THOT_DMSprObjectImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMSprObjectImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMSprObjectImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMSprObjectImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMSprObjectImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMSprObject
TDataSource * THOT_DMSprObjectImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THOT_DMSprObjectImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprObjectImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprObjectImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * THOT_DMSprObjectImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMSprObjectImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprObjectImpl::get_TableID_HOT_SOBJECT(void)
{
return Object->TableID_HOT_SOBJECT;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_TableID_HOT_SOBJECT(TFIBBCDField * TableID_HOT_SOBJECT)
{
Object->TableID_HOT_SOBJECT=TableID_HOT_SOBJECT;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprObjectImpl::get_TableIDSKL_HOT_SOBJECT(void)
{
return Object->TableIDSKL_HOT_SOBJECT;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_TableIDSKL_HOT_SOBJECT(TFIBBCDField * TableIDSKL_HOT_SOBJECT)
{
Object->TableIDSKL_HOT_SOBJECT=TableIDSKL_HOT_SOBJECT;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprObjectImpl::get_ElementID_HOT_SOBJECT(void)
{
return Object->ElementID_HOT_SOBJECT;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_ElementID_HOT_SOBJECT(TFIBBCDField * ElementID_HOT_SOBJECT)
{
Object->ElementID_HOT_SOBJECT=ElementID_HOT_SOBJECT;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprObjectImpl::get_ElementIDSKL_HOT_SOBJECT(void)
{
return Object->ElementIDSKL_HOT_SOBJECT;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_ElementIDSKL_HOT_SOBJECT(TFIBBCDField * ElementIDSKL_HOT_SOBJECT)
{
Object->ElementIDSKL_HOT_SOBJECT=ElementIDSKL_HOT_SOBJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprObjectImpl::get_ElementNAME_HOT_SOBJECT(void)
{
return Object->ElementNAME_HOT_SOBJECT;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_ElementNAME_HOT_SOBJECT(TFIBWideStringField * ElementNAME_HOT_SOBJECT)
{
Object->ElementNAME_HOT_SOBJECT=ElementNAME_HOT_SOBJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprObjectImpl::get_ElementNAMESKLAD(void)
{
return Object->ElementNAMESKLAD;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)
{
Object->ElementNAMESKLAD=ElementNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprObjectImpl::get_TableNAME_HOT_SOBJECT(void)
{
return Object->TableNAME_HOT_SOBJECT;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_TableNAME_HOT_SOBJECT(TFIBWideStringField * TableNAME_HOT_SOBJECT)
{
Object->TableNAME_HOT_SOBJECT=TableNAME_HOT_SOBJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprObjectImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int THOT_DMSprObjectImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
bool THOT_DMSprObjectImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool THOT_DMSprObjectImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void THOT_DMSprObjectImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool THOT_DMSprObjectImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
int THOT_DMSprObjectImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
