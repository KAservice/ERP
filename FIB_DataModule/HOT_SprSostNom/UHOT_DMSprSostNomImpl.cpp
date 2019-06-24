#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMSprSostNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMSprSostNomImpl::THOT_DMSprSostNomImpl()           
{                                            
Object=new THOT_DMSprSostNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMSprSostNomImpl::~THOT_DMSprSostNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMSprSostNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMSprSostNom)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMSprSostNom*> (this);                                
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
int THOT_DMSprSostNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMSprSostNomImpl::kanRelease(void)                                  
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
int  THOT_DMSprSostNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMSprSostNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMSprSostNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMSprSostNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMSprSostNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMSprSostNom
TDataSource * THOT_DMSprSostNomImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THOT_DMSprSostNomImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprSostNomImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprSostNomImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * THOT_DMSprSostNomImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMSprSostNomImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMSprSostNomImpl::get_TableFLBRON_HOT_SSOSTNOM(void)
{
return Object->TableFLBRON_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_TableFLBRON_HOT_SSOSTNOM(TFIBSmallIntField * TableFLBRON_HOT_SSOSTNOM)
{
Object->TableFLBRON_HOT_SSOSTNOM=TableFLBRON_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMSprSostNomImpl::get_TableFLRASM_HOT_SSOSTNOM(void)
{
return Object->TableFLRASM_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_TableFLRASM_HOT_SSOSTNOM(TFIBSmallIntField * TableFLRASM_HOT_SSOSTNOM)
{
Object->TableFLRASM_HOT_SSOSTNOM=TableFLRASM_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMSprSostNomImpl::get_ElementFLBRON_HOT_SSOSTNOM(void)
{
return Object->ElementFLBRON_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_ElementFLBRON_HOT_SSOSTNOM(TFIBSmallIntField * ElementFLBRON_HOT_SSOSTNOM)
{
Object->ElementFLBRON_HOT_SSOSTNOM=ElementFLBRON_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMSprSostNomImpl::get_ElementFLRASM_HOT_SSOSTNOM(void)
{
return Object->ElementFLRASM_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_ElementFLRASM_HOT_SSOSTNOM(TFIBSmallIntField * ElementFLRASM_HOT_SSOSTNOM)
{
Object->ElementFLRASM_HOT_SSOSTNOM=ElementFLRASM_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprSostNomImpl::get_TableID_HOT_SSOSTNOM(void)
{
return Object->TableID_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_TableID_HOT_SSOSTNOM(TFIBBCDField * TableID_HOT_SSOSTNOM)
{
Object->TableID_HOT_SSOSTNOM=TableID_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprSostNomImpl::get_ElementID_HOT_SSOSTNOM(void)
{
return Object->ElementID_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_ElementID_HOT_SSOSTNOM(TFIBBCDField * ElementID_HOT_SSOSTNOM)
{
Object->ElementID_HOT_SSOSTNOM=ElementID_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMSprSostNomImpl::get_ElementCOLOR_HOT_SSOSTNOM(void)
{
return Object->ElementCOLOR_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_ElementCOLOR_HOT_SSOSTNOM(TFIBIntegerField * ElementCOLOR_HOT_SSOSTNOM)
{
Object->ElementCOLOR_HOT_SSOSTNOM=ElementCOLOR_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprSostNomImpl::get_TableNAME_HOT_SSOSTNOM(void)
{
return Object->TableNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_TableNAME_HOT_SSOSTNOM(TFIBWideStringField * TableNAME_HOT_SSOSTNOM)
{
Object->TableNAME_HOT_SSOSTNOM=TableNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprSostNomImpl::get_ElementNAME_HOT_SSOSTNOM(void)
{
return Object->ElementNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::set_ElementNAME_HOT_SSOSTNOM(TFIBWideStringField * ElementNAME_HOT_SSOSTNOM)
{
Object->ElementNAME_HOT_SSOSTNOM=ElementNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int THOT_DMSprSostNomImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
bool THOT_DMSprSostNomImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool THOT_DMSprSostNomImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void THOT_DMSprSostNomImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool THOT_DMSprSostNomImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
int THOT_DMSprSostNomImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
