#include "vcl.h"
#pragma hdrstop


#include "UART_FormaElementaSprInfBlockImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_FormaElementaSprInfBlockImpl::TART_FormaElementaSprInfBlockImpl()           
{                                            
Object=new TART_FormaElementaSprInfBlock(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_FormaElementaSprInfBlockImpl::~TART_FormaElementaSprInfBlockImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_FormaElementaSprInfBlockImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_FormaElementaSprInfBlockImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_FormaElementaSprInfBlock)                        
   {                                                                     
   *ppv=static_cast<IART_FormaElementaSprInfBlock*> (this);                                
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
int TART_FormaElementaSprInfBlockImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_FormaElementaSprInfBlockImpl::kanRelease(void)                                  
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
int  TART_FormaElementaSprInfBlockImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_FormaElementaSprInfBlockImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_FormaElementaSprInfBlockImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_FormaElementaSprInfBlockImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_FormaElementaSprInfBlockImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_FormaElementaSprInfBlockImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_FormaElementaSprInfBlockImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TART_FormaElementaSprInfBlockImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IART_FormaElementaSprInfBlock
IART_DMSprInfBlock * TART_FormaElementaSprInfBlockImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TART_FormaElementaSprInfBlockImpl::set_DM(IART_DMSprInfBlock * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
bool TART_FormaElementaSprInfBlockImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TART_FormaElementaSprInfBlockImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TART_FormaElementaSprInfBlockImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TART_FormaElementaSprInfBlockImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
__int64 TART_FormaElementaSprInfBlockImpl::get_IdGrpPage(void)
{
return Object->IdGrpPage;
}
//---------------------------------------------------------------
void TART_FormaElementaSprInfBlockImpl::set_IdGrpPage(__int64 IdGrpPage)
{
Object->IdGrpPage=IdGrpPage;
}
//---------------------------------------------------------------
UnicodeString TART_FormaElementaSprInfBlockImpl::get_NameGrp(void)
{
return Object->NameGrp;
}
//---------------------------------------------------------------
void TART_FormaElementaSprInfBlockImpl::set_NameGrp(UnicodeString NameGrp)
{
Object->NameGrp=NameGrp;
}
//---------------------------------------------------------------
void TART_FormaElementaSprInfBlockImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
