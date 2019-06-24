#include "vcl.h"
#pragma hdrstop


#include "UHLP_FormaElementaSprNaborInfBlockGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_FormaElementaSprNaborInfBlockGrpImpl::THLP_FormaElementaSprNaborInfBlockGrpImpl()           
{                                            
Object=new THLP_FormaElementaSprNaborInfBlockGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_FormaElementaSprNaborInfBlockGrpImpl::~THLP_FormaElementaSprNaborInfBlockGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_FormaElementaSprNaborInfBlockGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_FormaElementaSprNaborInfBlockGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_FormaElementaSprNaborInfBlockGrp)                        
   {                                                                     
   *ppv=static_cast<IHLP_FormaElementaSprNaborInfBlockGrp*> (this);                                
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
int THLP_FormaElementaSprNaborInfBlockGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_FormaElementaSprNaborInfBlockGrpImpl::kanRelease(void)                                  
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
int  THLP_FormaElementaSprNaborInfBlockGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_FormaElementaSprNaborInfBlockGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_FormaElementaSprNaborInfBlockGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_FormaElementaSprNaborInfBlockGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_FormaElementaSprNaborInfBlockGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_FormaElementaSprNaborInfBlockGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_FormaElementaSprNaborInfBlockGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int THLP_FormaElementaSprNaborInfBlockGrpImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IHLP_FormaElementaSprNaborInfBlockGrp
bool THLP_FormaElementaSprNaborInfBlockGrpImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void THLP_FormaElementaSprNaborInfBlockGrpImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool THLP_FormaElementaSprNaborInfBlockGrpImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void THLP_FormaElementaSprNaborInfBlockGrpImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int THLP_FormaElementaSprNaborInfBlockGrpImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void THLP_FormaElementaSprNaborInfBlockGrpImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IHLP_DMSprNaborInfBlockGrp* THLP_FormaElementaSprNaborInfBlockGrpImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void THLP_FormaElementaSprNaborInfBlockGrpImpl::set_DM(IHLP_DMSprNaborInfBlockGrp* DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
