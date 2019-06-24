#include "vcl.h"
#pragma hdrstop


#include "UHOT_FormaSpiskaSprObjectImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_FormaSpiskaSprObjectImpl::THOT_FormaSpiskaSprObjectImpl()           
{                                            
Object=new THOT_FormaSpiskaSprObject(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_FormaSpiskaSprObjectImpl::~THOT_FormaSpiskaSprObjectImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_FormaSpiskaSprObjectImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_FormaSpiskaSprObjectImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_FormaSpiskaSprObject)                        
   {                                                                     
   *ppv=static_cast<IHOT_FormaSpiskaSprObject*> (this);                                
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
int THOT_FormaSpiskaSprObjectImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_FormaSpiskaSprObjectImpl::kanRelease(void)                                  
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
int  THOT_FormaSpiskaSprObjectImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_FormaSpiskaSprObjectImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_FormaSpiskaSprObjectImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_FormaSpiskaSprObjectImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_FormaSpiskaSprObjectImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_FormaSpiskaSprObjectImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_FormaSpiskaSprObjectImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int THOT_FormaSpiskaSprObjectImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //��������� �� �������� ������ 
									id_object,      //��� ��������� �������  
									type_event,     //��� ������� � �������� ������� 
									number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������ 
									); 
}   
//---------------------------------------------------------------

//IHOT_FormaSpiskaSprObject
IHOT_DMSprObject * THOT_FormaSpiskaSprObjectImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void THOT_FormaSpiskaSprObjectImpl::set_DM(IHOT_DMSprObject * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
bool THOT_FormaSpiskaSprObjectImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void THOT_FormaSpiskaSprObjectImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int THOT_FormaSpiskaSprObjectImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void THOT_FormaSpiskaSprObjectImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
