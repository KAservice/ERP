#include "vcl.h"
#pragma hdrstop


#include "UFormaElementaSprAddressViborImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaElementaSprAddressViborImpl::TFormaElementaSprAddressViborImpl()           
{                                            
Object=new TFormaElementaSprAddressVibor(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaElementaSprAddressViborImpl::~TFormaElementaSprAddressViborImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaElementaSprAddressViborImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
 {                                                                         
int result=0;                                                             
if (id_interface==IID_IkanUnknown)                                        
   {                                                                     
   *ppv=static_cast<IkanUnknown*> (static_cast<IMainInterface*>(this)); 
   result=-1;                                                             
   }                                                                      
else if (id_interface==IID_IMainInterface)                        
   {                                                                     
   *ppv=static_cast<IMainInterface*> (this);                                
   result=-1;                                                            
   }  
else if (id_interface==IID_IkanCallBack) 
   {                                        
   *ppv=static_cast<IkanCallBack*> (this);  
   result=-1;                               
   }                                        
else if (id_interface==IID_IFormaElementaSprAddressVibor)                        
   {                                                                     
   *ppv=static_cast<IFormaElementaSprAddressVibor*> (this);                                
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
int TFormaElementaSprAddressViborImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaElementaSprAddressViborImpl::kanRelease(void)                                  
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
int  TFormaElementaSprAddressViborImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaElementaSprAddressViborImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaElementaSprAddressViborImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaElementaSprAddressViborImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaElementaSprAddressViborImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaElementaSprAddressViborImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IFormaElementaSprAddressVibor
IDMSprAddressRegion * TFormaElementaSprAddressViborImpl::get_DM_Region(void)
{
return Object->DM_Region;
}
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::set_DM_Region(IDMSprAddressRegion * DM_Region)
{
Object->DM_Region=DM_Region;
}
//---------------------------------------------------------------
IDMSprAddressRayon * TFormaElementaSprAddressViborImpl::get_DM_Rayon(void)
{
return Object->DM_Rayon;
}
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::set_DM_Rayon(IDMSprAddressRayon * DM_Rayon)
{
Object->DM_Rayon=DM_Rayon;
}
//---------------------------------------------------------------
IDMSprAddressNasPunkt * TFormaElementaSprAddressViborImpl::get_DM_NasPunkt(void)
{
return Object->DM_NasPunkt;
}
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::set_DM_NasPunkt(IDMSprAddressNasPunkt * DM_NasPunkt)
{
Object->DM_NasPunkt=DM_NasPunkt;
}
//---------------------------------------------------------------
IDMSprAddressStreet * TFormaElementaSprAddressViborImpl::get_DM_Street(void)
{
return Object->DM_Street;
}
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::set_DM_Street(IDMSprAddressStreet * DM_Street)
{
Object->DM_Street=DM_Street;
}
//---------------------------------------------------------------
IDMSprAddressDom * TFormaElementaSprAddressViborImpl::get_DM_Dom(void)
{
return Object->DM_Dom;
}
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::set_DM_Dom(IDMSprAddressDom * DM_Dom)
{
Object->DM_Dom=DM_Dom;
}
//---------------------------------------------------------------
IDMSprAddressStroen * TFormaElementaSprAddressViborImpl::get_DM_Stroen(void)
{
return Object->DM_Stroen;
}
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::set_DM_Stroen(IDMSprAddressStroen * DM_Stroen)
{
Object->DM_Stroen=DM_Stroen;
}
//---------------------------------------------------------------
IDMSprAddressKV * TFormaElementaSprAddressViborImpl::get_DM_KV(void)
{
return Object->DM_KV;
}
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::set_DM_KV(IDMSprAddressKV * DM_KV)
{
Object->DM_KV=DM_KV;
}
//---------------------------------------------------------------
bool TFormaElementaSprAddressViborImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaElementaSprAddressViborImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaElementaSprAddressViborImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
