#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMTableSostNFImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMTableSostNFImpl::THOT_DMTableSostNFImpl()           
{                                            
Object=new THOT_DMTableSostNF(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMTableSostNFImpl::~THOT_DMTableSostNFImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMTableSostNFImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMTableSostNF)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMTableSostNF*> (this);                                
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
int THOT_DMTableSostNFImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMTableSostNFImpl::kanRelease(void)                                  
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
int  THOT_DMTableSostNFImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMTableSostNFImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMTableSostNFImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMTableSostNFImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMTableSostNFImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMTableSostNF
TDataSource * THOT_DMTableSostNFImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THOT_DMTableSostNFImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMTableSostNFImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMTableSostNFImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMTableSostNFImpl::get_TableKOLM_HOT_SOSTNF(void)
{
return Object->TableKOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableKOLM_HOT_SOSTNF(TFIBIntegerField * TableKOLM_HOT_SOSTNF)
{
Object->TableKOLM_HOT_SOSTNF=TableKOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMTableSostNFImpl::get_TablePOSNACH_HOT_SOSTNF(void)
{
return Object->TablePOSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TablePOSNACH_HOT_SOSTNF(TFIBDateTimeField * TablePOSNACH_HOT_SOSTNF)
{
Object->TablePOSNACH_HOT_SOSTNF=TablePOSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMTableSostNFImpl::get_TablePOSCON_HOT_SOSTNF(void)
{
return Object->TablePOSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TablePOSCON_HOT_SOSTNF(TFIBDateTimeField * TablePOSCON_HOT_SOSTNF)
{
Object->TablePOSCON_HOT_SOSTNF=TablePOSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
TIntegerField * THOT_DMTableSostNFImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMTableSostNFImpl::get_ElementKOLM_HOT_SOSTNF(void)
{
return Object->ElementKOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementKOLM_HOT_SOSTNF(TFIBIntegerField * ElementKOLM_HOT_SOSTNF)
{
Object->ElementKOLM_HOT_SOSTNF=ElementKOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMTableSostNFImpl::get_ElementPOSNACH_HOT_SOSTNF(void)
{
return Object->ElementPOSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementPOSNACH_HOT_SOSTNF(TFIBDateTimeField * ElementPOSNACH_HOT_SOSTNF)
{
Object->ElementPOSNACH_HOT_SOSTNF=ElementPOSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMTableSostNFImpl::get_ElementPOSCON_HOT_SOSTNF(void)
{
return Object->ElementPOSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementPOSCON_HOT_SOSTNF(TFIBDateTimeField * ElementPOSCON_HOT_SOSTNF)
{
Object->ElementPOSCON_HOT_SOSTNF=ElementPOSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_TableID_HOT_SOSTNF(void)
{
return Object->TableID_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableID_HOT_SOSTNF(TFIBBCDField * TableID_HOT_SOSTNF)
{
Object->TableID_HOT_SOSTNF=TableID_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_TableIDNOMER_HOT_SOSTNF(void)
{
return Object->TableIDNOMER_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableIDNOMER_HOT_SOSTNF(TFIBBCDField * TableIDNOMER_HOT_SOSTNF)
{
Object->TableIDNOMER_HOT_SOSTNF=TableIDNOMER_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_TableIDPLAT_HOT_SOSTNF(void)
{
return Object->TableIDPLAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableIDPLAT_HOT_SOSTNF(TFIBBCDField * TableIDPLAT_HOT_SOSTNF)
{
Object->TableIDPLAT_HOT_SOSTNF=TableIDPLAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_TableIDGUEST_HOT_SOSTNF(void)
{
return Object->TableIDGUEST_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableIDGUEST_HOT_SOSTNF(TFIBBCDField * TableIDGUEST_HOT_SOSTNF)
{
Object->TableIDGUEST_HOT_SOSTNF=TableIDGUEST_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_TableIDSOST_HOT_SOSTNF(void)
{
return Object->TableIDSOST_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableIDSOST_HOT_SOSTNF(TFIBBCDField * TableIDSOST_HOT_SOSTNF)
{
Object->TableIDSOST_HOT_SOSTNF=TableIDSOST_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_TableIDTPOS_HOT_SOSTNF(void)
{
return Object->TableIDTPOS_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableIDTPOS_HOT_SOSTNF(TFIBBCDField * TableIDTPOS_HOT_SOSTNF)
{
Object->TableIDTPOS_HOT_SOSTNF=TableIDTPOS_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_TableIDCAT_HOT_SOSTNF(void)
{
return Object->TableIDCAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableIDCAT_HOT_SOSTNF(TFIBBCDField * TableIDCAT_HOT_SOSTNF)
{
Object->TableIDCAT_HOT_SOSTNF=TableIDCAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_TableIDDOCH_HOT_SOSTNF(void)
{
return Object->TableIDDOCH_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableIDDOCH_HOT_SOSTNF(TFIBBCDField * TableIDDOCH_HOT_SOSTNF)
{
Object->TableIDDOCH_HOT_SOSTNF=TableIDDOCH_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_ElementID_HOT_SOSTNF(void)
{
return Object->ElementID_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementID_HOT_SOSTNF(TFIBBCDField * ElementID_HOT_SOSTNF)
{
Object->ElementID_HOT_SOSTNF=ElementID_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_ElementIDNOMER_HOT_SOSTNF(void)
{
return Object->ElementIDNOMER_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementIDNOMER_HOT_SOSTNF(TFIBBCDField * ElementIDNOMER_HOT_SOSTNF)
{
Object->ElementIDNOMER_HOT_SOSTNF=ElementIDNOMER_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_ElementIDPLAT_HOT_SOSTNF(void)
{
return Object->ElementIDPLAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementIDPLAT_HOT_SOSTNF(TFIBBCDField * ElementIDPLAT_HOT_SOSTNF)
{
Object->ElementIDPLAT_HOT_SOSTNF=ElementIDPLAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_ElementIDGUEST_HOT_SOSTNF(void)
{
return Object->ElementIDGUEST_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementIDGUEST_HOT_SOSTNF(TFIBBCDField * ElementIDGUEST_HOT_SOSTNF)
{
Object->ElementIDGUEST_HOT_SOSTNF=ElementIDGUEST_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_ElementIDSOST_HOT_SOSTNF(void)
{
return Object->ElementIDSOST_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementIDSOST_HOT_SOSTNF(TFIBBCDField * ElementIDSOST_HOT_SOSTNF)
{
Object->ElementIDSOST_HOT_SOSTNF=ElementIDSOST_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_ElementIDTPOS_HOT_SOSTNF(void)
{
return Object->ElementIDTPOS_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementIDTPOS_HOT_SOSTNF(TFIBBCDField * ElementIDTPOS_HOT_SOSTNF)
{
Object->ElementIDTPOS_HOT_SOSTNF=ElementIDTPOS_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_ElementIDCAT_HOT_SOSTNF(void)
{
return Object->ElementIDCAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementIDCAT_HOT_SOSTNF(TFIBBCDField * ElementIDCAT_HOT_SOSTNF)
{
Object->ElementIDCAT_HOT_SOSTNF=ElementIDCAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_ElementIDDOCH_HOT_SOSTNF(void)
{
return Object->ElementIDDOCH_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementIDDOCH_HOT_SOSTNF(TFIBBCDField * ElementIDDOCH_HOT_SOSTNF)
{
Object->ElementIDDOCH_HOT_SOSTNF=ElementIDDOCH_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMTableSostNFImpl::get_ElementIDCEL_HOT_SOSTNF(void)
{
return Object->ElementIDCEL_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementIDCEL_HOT_SOSTNF(TFIBBCDField * ElementIDCEL_HOT_SOSTNF)
{
Object->ElementIDCEL_HOT_SOSTNF=ElementIDCEL_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMTableSostNFImpl::get_TableNAMEPLAT(void)
{
return Object->TableNAMEPLAT;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableNAMEPLAT(TFIBWideStringField * TableNAMEPLAT)
{
Object->TableNAMEPLAT=TableNAMEPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMTableSostNFImpl::get_TableNAMEGUEST(void)
{
return Object->TableNAMEGUEST;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableNAMEGUEST(TFIBWideStringField * TableNAMEGUEST)
{
Object->TableNAMEGUEST=TableNAMEGUEST;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMTableSostNFImpl::get_TableNAME_HOT_SNF(void)
{
return Object->TableNAME_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableNAME_HOT_SNF(TFIBWideStringField * TableNAME_HOT_SNF)
{
Object->TableNAME_HOT_SNF=TableNAME_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMTableSostNFImpl::get_TableNAME_HOT_SSOSTNOM(void)
{
return Object->TableNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableNAME_HOT_SSOSTNOM(TFIBWideStringField * TableNAME_HOT_SSOSTNOM)
{
Object->TableNAME_HOT_SSOSTNOM=TableNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMTableSostNFImpl::get_TableNAME_HOT_STYPEPOS(void)
{
return Object->TableNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_TableNAME_HOT_STYPEPOS(TFIBWideStringField * TableNAME_HOT_STYPEPOS)
{
Object->TableNAME_HOT_STYPEPOS=TableNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMTableSostNFImpl::get_ElementNAMEPLAT(void)
{
return Object->ElementNAMEPLAT;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementNAMEPLAT(TFIBWideStringField * ElementNAMEPLAT)
{
Object->ElementNAMEPLAT=ElementNAMEPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMTableSostNFImpl::get_ElementNAMEGUEST(void)
{
return Object->ElementNAMEGUEST;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementNAMEGUEST(TFIBWideStringField * ElementNAMEGUEST)
{
Object->ElementNAMEGUEST=ElementNAMEGUEST;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMTableSostNFImpl::get_ElementNAME_HOT_SNF(void)
{
return Object->ElementNAME_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementNAME_HOT_SNF(TFIBWideStringField * ElementNAME_HOT_SNF)
{
Object->ElementNAME_HOT_SNF=ElementNAME_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMTableSostNFImpl::get_ElementNAME_HOT_SSOSTNOM(void)
{
return Object->ElementNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementNAME_HOT_SSOSTNOM(TFIBWideStringField * ElementNAME_HOT_SSOSTNOM)
{
Object->ElementNAME_HOT_SSOSTNOM=ElementNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMTableSostNFImpl::get_ElementNAME_HOT_STYPEPOS(void)
{
return Object->ElementNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementNAME_HOT_STYPEPOS(TFIBWideStringField * ElementNAME_HOT_STYPEPOS)
{
Object->ElementNAME_HOT_STYPEPOS=ElementNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMTableSostNFImpl::get_ElementNAME_HOT_SCATNOM(void)
{
return Object->ElementNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementNAME_HOT_SCATNOM(TFIBWideStringField * ElementNAME_HOT_SCATNOM)
{
Object->ElementNAME_HOT_SCATNOM=ElementNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMTableSostNFImpl::get_ElementNAME_HOT_SCELPR(void)
{
return Object->ElementNAME_HOT_SCELPR;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_ElementNAME_HOT_SCELPR(TFIBWideStringField * ElementNAME_HOT_SCELPR)
{
Object->ElementNAME_HOT_SCELPR=ElementNAME_HOT_SCELPR;
}
//---------------------------------------------------------------
__int64 THOT_DMTableSostNFImpl::get_IdPlat(void)
{
return Object->IdPlat;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::set_IdPlat(__int64 IdPlat)
{
Object->IdPlat=IdPlat;
}
//---------------------------------------------------------------
void THOT_DMTableSostNFImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int THOT_DMTableSostNFImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
bool THOT_DMTableSostNFImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool THOT_DMTableSostNFImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THOT_DMTableSostNFImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
