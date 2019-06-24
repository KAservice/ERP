#include "vcl.h"
#pragma hdrstop


#include "UFormaOperCreditCardImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaOperCreditCardImpl::TFormaOperCreditCardImpl()           
{                                            
Object=new TFormaOperCreditCard(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaOperCreditCardImpl::~TFormaOperCreditCardImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaOperCreditCardImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaOperCreditCardImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IAsyncExternalEvent)
   {
   *ppv=static_cast<IAsyncExternalEvent*> (this);
   result=-1;
   }
else                                                                     
   {                                                                     
   *ppv=NULL;                                                            
   result=1;                                                             
   return result;                                                        
   }                                                                     
reinterpret_cast<IkanUnknown*>(*ppv)->kanAddRef();                       
return result;                                                           
}                                                                       
//---------------------------------------------------------------
int TFormaOperCreditCardImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaOperCreditCardImpl::kanRelease(void)                                  
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
int  TFormaOperCreditCardImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaOperCreditCardImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaOperCreditCardImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaOperCreditCardImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaOperCreditCardImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaOperCreditCardImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaOperCreditCardImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaOperCreditCardImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------
//IAcyncExternalEvent
int TFormaOperCreditCardImpl::AsyncExternalEvent(char * object, char* event, char* data)
{
AnsiString ansi_object=object;
AnsiString ansi_event=event;
AnsiString ansi_data=data;

if (Trim(ansi_object)=="scaner")
	{
	//Object->ReadShtrihCodEvent(0,ansi_data);
	}
return -1;
}
//-----------------------------------------------------------------
int TFormaOperCreditCardImpl::SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form)
{

return -1;
}
//------------------------------------------------------------------
