#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMSprCelPriesdaImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMSprCelPriesdaImpl::THOT_DMSprCelPriesdaImpl()           
{                                            
Object=new THOT_DMSprCelPriesda(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMSprCelPriesdaImpl::~THOT_DMSprCelPriesdaImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMSprCelPriesdaImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMSprCelPriesda)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMSprCelPriesda*> (this);                                
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
int THOT_DMSprCelPriesdaImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMSprCelPriesdaImpl::kanRelease(void)                                  
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
int  THOT_DMSprCelPriesdaImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMSprCelPriesdaImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMSprCelPriesdaImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMSprCelPriesdaImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMSprCelPriesdaImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMSprCelPriesda
TDataSource * THOT_DMSprCelPriesdaImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THOT_DMSprCelPriesdaImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprCelPriesdaImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprCelPriesdaImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * THOT_DMSprCelPriesdaImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THOT_DMSprCelPriesdaImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * THOT_DMSprCelPriesdaImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMSprCelPriesdaImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprCelPriesdaImpl::get_ElementID_HOT_SCELPR(void)
{
return Object->ElementID_HOT_SCELPR;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_ElementID_HOT_SCELPR(TFIBBCDField * ElementID_HOT_SCELPR)
{
Object->ElementID_HOT_SCELPR=ElementID_HOT_SCELPR;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprCelPriesdaImpl::get_TableID_HOT_SCELPR(void)
{
return Object->TableID_HOT_SCELPR;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_TableID_HOT_SCELPR(TFIBBCDField * TableID_HOT_SCELPR)
{
Object->TableID_HOT_SCELPR=TableID_HOT_SCELPR;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprCelPriesdaImpl::get_ElementNAME_HOT_SCELPR(void)
{
return Object->ElementNAME_HOT_SCELPR;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_ElementNAME_HOT_SCELPR(TFIBWideStringField * ElementNAME_HOT_SCELPR)
{
Object->ElementNAME_HOT_SCELPR=ElementNAME_HOT_SCELPR;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprCelPriesdaImpl::get_TableNAME_HOT_SCELPR(void)
{
return Object->TableNAME_HOT_SCELPR;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::set_TableNAME_HOT_SCELPR(TFIBWideStringField * TableNAME_HOT_SCELPR)
{
Object->TableNAME_HOT_SCELPR=TableNAME_HOT_SCELPR;
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int THOT_DMSprCelPriesdaImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
bool THOT_DMSprCelPriesdaImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool THOT_DMSprCelPriesdaImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THOT_DMSprCelPriesdaImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
bool THOT_DMSprCelPriesdaImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
void THOT_DMSprCelPriesdaImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool THOT_DMSprCelPriesdaImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
int THOT_DMSprCelPriesdaImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
