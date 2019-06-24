#include "vcl.h"
#pragma hdrstop


#include "UHLP_FormaElementaSprInfBlockImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_FormaElementaSprInfBlockImpl::THLP_FormaElementaSprInfBlockImpl()           
{                                            
Object=new THLP_FormaElementaSprInfBlock(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_FormaElementaSprInfBlockImpl::~THLP_FormaElementaSprInfBlockImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_FormaElementaSprInfBlockImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_FormaElementaSprInfBlockImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_FormaElementaSprInfBlock)                        
   {                                                                     
   *ppv=static_cast<IHLP_FormaElementaSprInfBlock*> (this);                                
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
int THLP_FormaElementaSprInfBlockImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_FormaElementaSprInfBlockImpl::kanRelease(void)                                  
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
int  THLP_FormaElementaSprInfBlockImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_FormaElementaSprInfBlockImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_FormaElementaSprInfBlockImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_FormaElementaSprInfBlockImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_FormaElementaSprInfBlockImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_FormaElementaSprInfBlockImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_FormaElementaSprInfBlockImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int THLP_FormaElementaSprInfBlockImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IHLP_FormaElementaSprInfBlock
IHLP_DMSprInfBlock * THLP_FormaElementaSprInfBlockImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void THLP_FormaElementaSprInfBlockImpl::set_DM(IHLP_DMSprInfBlock * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
bool THLP_FormaElementaSprInfBlockImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void THLP_FormaElementaSprInfBlockImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int THLP_FormaElementaSprInfBlockImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void THLP_FormaElementaSprInfBlockImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
__int64 THLP_FormaElementaSprInfBlockImpl::get_IdGrpPage(void)
{
return Object->IdGrpPage;
}
//---------------------------------------------------------------
void THLP_FormaElementaSprInfBlockImpl::set_IdGrpPage(__int64 IdGrpPage)
{
Object->IdGrpPage=IdGrpPage;
}
//---------------------------------------------------------------
UnicodeString THLP_FormaElementaSprInfBlockImpl::get_NameGrp(void)
{
return Object->NameGrp;
}
//---------------------------------------------------------------
void THLP_FormaElementaSprInfBlockImpl::set_NameGrp(UnicodeString NameGrp)
{
Object->NameGrp=NameGrp;
}
//---------------------------------------------------------------
void THLP_FormaElementaSprInfBlockImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
