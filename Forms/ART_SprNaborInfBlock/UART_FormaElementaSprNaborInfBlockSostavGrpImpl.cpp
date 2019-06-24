#include "vcl.h"
#pragma hdrstop


#include "UART_FormaElementaSprNaborInfBlockSostavGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_FormaElementaSprNaborInfBlockSostavGrpImpl::TART_FormaElementaSprNaborInfBlockSostavGrpImpl()           
{                                            
Object=new TART_FormaElementaSprNaborInfBlockSostavGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_FormaElementaSprNaborInfBlockSostavGrpImpl::~TART_FormaElementaSprNaborInfBlockSostavGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_FormaElementaSprNaborInfBlockSostavGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_FormaElementaSprNaborInfBlockSostavGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_FormaElementaSprNaborInfBlockSostavGrp)                        
   {                                                                     
   *ppv=static_cast<IART_FormaElementaSprNaborInfBlockSostavGrp*> (this);                                
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
int TART_FormaElementaSprNaborInfBlockSostavGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_FormaElementaSprNaborInfBlockSostavGrpImpl::kanRelease(void)                                  
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
int  TART_FormaElementaSprNaborInfBlockSostavGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_FormaElementaSprNaborInfBlockSostavGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_FormaElementaSprNaborInfBlockSostavGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_FormaElementaSprNaborInfBlockSostavGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_FormaElementaSprNaborInfBlockSostavGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_FormaElementaSprNaborInfBlockSostavGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_FormaElementaSprNaborInfBlockSostavGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TART_FormaElementaSprNaborInfBlockSostavGrpImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IART_FormaElementaSprNaborInfBlockSostavGrp
bool TART_FormaElementaSprNaborInfBlockSostavGrpImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TART_FormaElementaSprNaborInfBlockSostavGrpImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TART_FormaElementaSprNaborInfBlockSostavGrpImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TART_FormaElementaSprNaborInfBlockSostavGrpImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IART_DMSprNaborInfBlockSostavGrp* TART_FormaElementaSprNaborInfBlockSostavGrpImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TART_FormaElementaSprNaborInfBlockSostavGrpImpl::set_DM(IART_DMSprNaborInfBlockSostavGrp* DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
