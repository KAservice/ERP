#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMSprTypePoselImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMSprTypePoselImpl::THOT_DMSprTypePoselImpl()           
{                                            
Object=new THOT_DMSprTypePosel(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMSprTypePoselImpl::~THOT_DMSprTypePoselImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMSprTypePoselImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMSprTypePosel)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMSprTypePosel*> (this);                                
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
int THOT_DMSprTypePoselImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMSprTypePoselImpl::kanRelease(void)                                  
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
int  THOT_DMSprTypePoselImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMSprTypePoselImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMSprTypePoselImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMSprTypePoselImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMSprTypePoselImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMSprTypePosel
TDataSource * THOT_DMSprTypePoselImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THOT_DMSprTypePoselImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprTypePoselImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprTypePoselImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * THOT_DMSprTypePoselImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THOT_DMSprTypePoselImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * THOT_DMSprTypePoselImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMSprTypePoselImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMSprTypePoselImpl::get_TableKOLM_HOT_STYPEPOS(void)
{
return Object->TableKOLM_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_TableKOLM_HOT_STYPEPOS(TFIBSmallIntField * TableKOLM_HOT_STYPEPOS)
{
Object->TableKOLM_HOT_STYPEPOS=TableKOLM_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMSprTypePoselImpl::get_TableALL_HOT_STYPEPOS(void)
{
return Object->TableALL_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_TableALL_HOT_STYPEPOS(TFIBSmallIntField * TableALL_HOT_STYPEPOS)
{
Object->TableALL_HOT_STYPEPOS=TableALL_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMSprTypePoselImpl::get_ElementKOLM_HOT_STYPEPOS(void)
{
return Object->ElementKOLM_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_ElementKOLM_HOT_STYPEPOS(TFIBSmallIntField * ElementKOLM_HOT_STYPEPOS)
{
Object->ElementKOLM_HOT_STYPEPOS=ElementKOLM_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMSprTypePoselImpl::get_ElementALL_HOT_STYPEPOS(void)
{
return Object->ElementALL_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_ElementALL_HOT_STYPEPOS(TFIBSmallIntField * ElementALL_HOT_STYPEPOS)
{
Object->ElementALL_HOT_STYPEPOS=ElementALL_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprTypePoselImpl::get_TableID_HOT_STYPEPOS(void)
{
return Object->TableID_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_TableID_HOT_STYPEPOS(TFIBBCDField * TableID_HOT_STYPEPOS)
{
Object->TableID_HOT_STYPEPOS=TableID_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprTypePoselImpl::get_ElementID_HOT_STYPEPOS(void)
{
return Object->ElementID_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_ElementID_HOT_STYPEPOS(TFIBBCDField * ElementID_HOT_STYPEPOS)
{
Object->ElementID_HOT_STYPEPOS=ElementID_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprTypePoselImpl::get_TableNAME_HOT_STYPEPOS(void)
{
return Object->TableNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_TableNAME_HOT_STYPEPOS(TFIBWideStringField * TableNAME_HOT_STYPEPOS)
{
Object->TableNAME_HOT_STYPEPOS=TableNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprTypePoselImpl::get_ElementNAME_HOT_STYPEPOS(void)
{
return Object->ElementNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::set_ElementNAME_HOT_STYPEPOS(TFIBWideStringField * ElementNAME_HOT_STYPEPOS)
{
Object->ElementNAME_HOT_STYPEPOS=ElementNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int THOT_DMSprTypePoselImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
bool THOT_DMSprTypePoselImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool THOT_DMSprTypePoselImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void THOT_DMSprTypePoselImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool THOT_DMSprTypePoselImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
int THOT_DMSprTypePoselImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
