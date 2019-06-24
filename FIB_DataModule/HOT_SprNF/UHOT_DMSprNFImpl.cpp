#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMSprNFImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMSprNFImpl::THOT_DMSprNFImpl()           
{                                            
Object=new THOT_DMSprNF(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMSprNFImpl::~THOT_DMSprNFImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMSprNFImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMSprNFImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMSprNF)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMSprNF*> (this);                                
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
int THOT_DMSprNFImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMSprNFImpl::kanRelease(void)                                  
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
int  THOT_DMSprNFImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMSprNFImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMSprNFImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMSprNFImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMSprNFImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMSprNF
TDataSource * THOT_DMSprNFImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THOT_DMSprNFImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprNFImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprNFImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * THOT_DMSprNFImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMSprNFImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMSprNFImpl::get_TableKOLM_HOT_SNF(void)
{
return Object->TableKOLM_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_TableKOLM_HOT_SNF(TFIBIntegerField * TableKOLM_HOT_SNF)
{
Object->TableKOLM_HOT_SNF=TableKOLM_HOT_SNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMSprNFImpl::get_TablePOSIN_HOT_SNF(void)
{
return Object->TablePOSIN_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_TablePOSIN_HOT_SNF(TFIBDateTimeField * TablePOSIN_HOT_SNF)
{
Object->TablePOSIN_HOT_SNF=TablePOSIN_HOT_SNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMSprNFImpl::get_TablePOSOUT_HOT_SNF(void)
{
return Object->TablePOSOUT_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_TablePOSOUT_HOT_SNF(TFIBDateTimeField * TablePOSOUT_HOT_SNF)
{
Object->TablePOSOUT_HOT_SNF=TablePOSOUT_HOT_SNF;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMSprNFImpl::get_ElementKOLM_HOT_SNF(void)
{
return Object->ElementKOLM_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_ElementKOLM_HOT_SNF(TFIBIntegerField * ElementKOLM_HOT_SNF)
{
Object->ElementKOLM_HOT_SNF=ElementKOLM_HOT_SNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMSprNFImpl::get_ElementPOSIN_HOT_SNF(void)
{
return Object->ElementPOSIN_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_ElementPOSIN_HOT_SNF(TFIBDateTimeField * ElementPOSIN_HOT_SNF)
{
Object->ElementPOSIN_HOT_SNF=ElementPOSIN_HOT_SNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMSprNFImpl::get_ElementPOSOUT_HOT_SNF(void)
{
return Object->ElementPOSOUT_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_ElementPOSOUT_HOT_SNF(TFIBDateTimeField * ElementPOSOUT_HOT_SNF)
{
Object->ElementPOSOUT_HOT_SNF=ElementPOSOUT_HOT_SNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprNFImpl::get_ElementID_HOT_SNF(void)
{
return Object->ElementID_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_ElementID_HOT_SNF(TFIBBCDField * ElementID_HOT_SNF)
{
Object->ElementID_HOT_SNF=ElementID_HOT_SNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprNFImpl::get_ElementIDOB_HOT_SNF(void)
{
return Object->ElementIDOB_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_ElementIDOB_HOT_SNF(TFIBBCDField * ElementIDOB_HOT_SNF)
{
Object->ElementIDOB_HOT_SNF=ElementIDOB_HOT_SNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprNFImpl::get_ElementIDCAT_HOT_SNF(void)
{
return Object->ElementIDCAT_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_ElementIDCAT_HOT_SNF(TFIBBCDField * ElementIDCAT_HOT_SNF)
{
Object->ElementIDCAT_HOT_SNF=ElementIDCAT_HOT_SNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprNFImpl::get_TableID_HOT_SNF(void)
{
return Object->TableID_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_TableID_HOT_SNF(TFIBBCDField * TableID_HOT_SNF)
{
Object->TableID_HOT_SNF=TableID_HOT_SNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprNFImpl::get_TableIDOB_HOT_SNF(void)
{
return Object->TableIDOB_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_TableIDOB_HOT_SNF(TFIBBCDField * TableIDOB_HOT_SNF)
{
Object->TableIDOB_HOT_SNF=TableIDOB_HOT_SNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprNFImpl::get_TableIDCAT_HOT_SNF(void)
{
return Object->TableIDCAT_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_TableIDCAT_HOT_SNF(TFIBBCDField * TableIDCAT_HOT_SNF)
{
Object->TableIDCAT_HOT_SNF=TableIDCAT_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprNFImpl::get_ElementNAME_HOT_SNF(void)
{
return Object->ElementNAME_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_ElementNAME_HOT_SNF(TFIBWideStringField * ElementNAME_HOT_SNF)
{
Object->ElementNAME_HOT_SNF=ElementNAME_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprNFImpl::get_ElementNAME_HOT_SOBJECT(void)
{
return Object->ElementNAME_HOT_SOBJECT;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_ElementNAME_HOT_SOBJECT(TFIBWideStringField * ElementNAME_HOT_SOBJECT)
{
Object->ElementNAME_HOT_SOBJECT=ElementNAME_HOT_SOBJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprNFImpl::get_ElementNAME_HOT_SCATNOM(void)
{
return Object->ElementNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_ElementNAME_HOT_SCATNOM(TFIBWideStringField * ElementNAME_HOT_SCATNOM)
{
Object->ElementNAME_HOT_SCATNOM=ElementNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprNFImpl::get_TableNAME_HOT_SNF(void)
{
return Object->TableNAME_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_TableNAME_HOT_SNF(TFIBWideStringField * TableNAME_HOT_SNF)
{
Object->TableNAME_HOT_SNF=TableNAME_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprNFImpl::get_TableNAME_HOT_SOBJECT(void)
{
return Object->TableNAME_HOT_SOBJECT;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_TableNAME_HOT_SOBJECT(TFIBWideStringField * TableNAME_HOT_SOBJECT)
{
Object->TableNAME_HOT_SOBJECT=TableNAME_HOT_SOBJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprNFImpl::get_TableNAME_HOT_SCATNOM(void)
{
return Object->TableNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::set_TableNAME_HOT_SCATNOM(TFIBWideStringField * TableNAME_HOT_SCATNOM)
{
Object->TableNAME_HOT_SCATNOM=TableNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
int THOT_DMSprNFImpl::OpenElement(__int64 Id)
{
return Object->OpenElement( Id);
}
//---------------------------------------------------------------
bool THOT_DMSprNFImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool THOT_DMSprNFImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void THOT_DMSprNFImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool THOT_DMSprNFImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
int THOT_DMSprNFImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
