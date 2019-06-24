#include <vcl.h>
#pragma hdrstop


#include "UDMSprKlientDopFisLImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprKlientDopFisLImpl::TDMSprKlientDopFisLImpl()           
{                                            
Object=new TDMSprKlientDopFisL(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprKlientDopFisLImpl::~TDMSprKlientDopFisLImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprKlientDopFisLImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprKlientDopFisL)                        
   {                                                                     
   *ppv=static_cast<IDMSprKlientDopFisL*> (this);                                
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
int TDMSprKlientDopFisLImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprKlientDopFisLImpl::kanRelease(void)                                  
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

//---------------------------------------------------------------
int  TDMSprKlientDopFisLImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprKlientDopFisLImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprKlientDopFisLImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprKlientDopFisLImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprKlientDopFisLImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprKlientDopFisLImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprKlientDopFisLImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprKlientDopFisLImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprKlientDopFisLImpl::get_ElementPOL_SKLIENT_DOPFISL(void)
{
return Object->ElementPOL_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_ElementPOL_SKLIENT_DOPFISL(TFIBIntegerField * ElementPOL_SKLIENT_DOPFISL)
{
Object->ElementPOL_SKLIENT_DOPFISL=ElementPOL_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientDopFisLImpl::get_ElementID_SKLIENT_DOPFISL(void)
{
return Object->ElementID_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_ElementID_SKLIENT_DOPFISL(TFIBBCDField * ElementID_SKLIENT_DOPFISL)
{
Object->ElementID_SKLIENT_DOPFISL=ElementID_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientDopFisLImpl::get_ElementIDKLIENT_SKLIENT_DOPFISL(void)
{
return Object->ElementIDKLIENT_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_ElementIDKLIENT_SKLIENT_DOPFISL(TFIBBCDField * ElementIDKLIENT_SKLIENT_DOPFISL)
{
Object->ElementIDKLIENT_SKLIENT_DOPFISL=ElementIDKLIENT_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
TFIBDateField * TDMSprKlientDopFisLImpl::get_ElementDATEROG_SKLIENT_DOPFISL(void)
{
return Object->ElementDATEROG_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_ElementDATEROG_SKLIENT_DOPFISL(TFIBDateField * ElementDATEROG_SKLIENT_DOPFISL)
{
Object->ElementDATEROG_SKLIENT_DOPFISL=ElementDATEROG_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientDopFisLImpl::get_ElementMESTOROG_SKLIENT_DOPFISL(void)
{
return Object->ElementMESTOROG_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_ElementMESTOROG_SKLIENT_DOPFISL(TFIBWideStringField * ElementMESTOROG_SKLIENT_DOPFISL)
{
Object->ElementMESTOROG_SKLIENT_DOPFISL=ElementMESTOROG_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientDopFisLImpl::get_ElementDOLRAB_SKLIENT_DOPFISL(void)
{
return Object->ElementDOLRAB_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_ElementDOLRAB_SKLIENT_DOPFISL(TFIBWideStringField * ElementDOLRAB_SKLIENT_DOPFISL)
{
Object->ElementDOLRAB_SKLIENT_DOPFISL=ElementDOLRAB_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientDopFisLImpl::get_ElementMESTORAB_SKLIENT_DOPFISL(void)
{
return Object->ElementMESTORAB_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_ElementMESTORAB_SKLIENT_DOPFISL(TFIBWideStringField * ElementMESTORAB_SKLIENT_DOPFISL)
{
Object->ElementMESTORAB_SKLIENT_DOPFISL=ElementMESTORAB_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientDopFisLImpl::get_ElementIDBASE_SKLIENT_DOPFISL(void)
{
return Object->ElementIDBASE_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_ElementIDBASE_SKLIENT_DOPFISL(TFIBBCDField * ElementIDBASE_SKLIENT_DOPFISL)
{
Object->ElementIDBASE_SKLIENT_DOPFISL=ElementIDBASE_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientDopFisLImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientDopFisLImpl::get_ElementGID_SKLIENT_DOPFISL(void)
{
return Object->ElementGID_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_ElementGID_SKLIENT_DOPFISL(TFIBWideStringField * ElementGID_SKLIENT_DOPFISL)
{
Object->ElementGID_SKLIENT_DOPFISL=ElementGID_SKLIENT_DOPFISL;
}
//---------------------------------------------------------------
__int64 TDMSprKlientDopFisLImpl::get_Id(void)
{
return Object->Id;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_Id(__int64 Id)
{
Object->Id=Id;
}
//---------------------------------------------------------------
__int64 TDMSprKlientDopFisLImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
int TDMSprKlientDopFisLImpl::OpenElement(void)
{
return Object->OpenElement();
}
//---------------------------------------------------------------
void TDMSprKlientDopFisLImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprKlientDopFisLImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprKlientDopFisLImpl::DeleteElement(void)
{
return Object->DeleteElement();
}
//---------------------------------------------------------------
