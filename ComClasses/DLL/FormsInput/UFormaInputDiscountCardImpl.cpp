#include "vcl.h"
#pragma hdrstop


#include "UFormaInputDiscountCardImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaInputDiscountCardImpl::TFormaInputDiscountCardImpl()           
{                                            
Object=new TFormaInputDiscountCard(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaInputDiscountCardImpl::~TFormaInputDiscountCardImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaInputDiscountCardImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaInputDiscountCardImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
 {                                                                         
int result=0;                                                             
if (id_interface==IID_IkanUnknown)                                        
   {                                                                     
   *ppv=static_cast<IkanUnknown*> (static_cast<IMainInterface*> (this));
   result=-1;                                                             
   }                                                                      
else if (id_interface==IID_IMainInterface)                        
   {                                                                     
   *ppv=static_cast<IMainInterface*> (this);                                
   result=-1;                                                            
   }  
else if (id_interface==IID_IFormaInputDiscountCard)                        
   {                                                                     
   *ppv=static_cast<IFormaInputDiscountCard*> (this);                                
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
kanAddRef();
return result;                                                           
}                                                                       
//---------------------------------------------------------------
int TFormaInputDiscountCardImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaInputDiscountCardImpl::kanRelease(void)                                  
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
int  TFormaInputDiscountCardImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaInputDiscountCardImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaInputDiscountCardImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaInputDiscountCardImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaInputDiscountCardImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaInputDiscountCardImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TFormaInputDiscountCardImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IFormaInputDiscountCard
bool TFormaInputDiscountCardImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaInputDiscountCardImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
UnicodeString TFormaInputDiscountCardImpl::get_InputText(void)
{
return Object->InputText;
}
//---------------------------------------------------------------
void TFormaInputDiscountCardImpl::set_InputText(UnicodeString InputText)
{
Object->InputText=InputText;
}
//---------------------------------------------------------------
int TFormaInputDiscountCardImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaInputDiscountCardImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
//IAcyncExternalEvent
int TFormaInputDiscountCardImpl::AsyncExternalEvent(char * object, char* event, char* data)
{
AnsiString ansi_object=object;
AnsiString ansi_event=event;
AnsiString ansi_data=data;

if (Trim(ansi_object)=="scaner")
	{
	Object->ReadShtrihCodEvent(0,ansi_data);
	}
return -1;
}
//-----------------------------------------------------------------
int TFormaInputDiscountCardImpl::SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form)
{

return -1;
}
//------------------------------------------------------------------
