#include "vcl.h"
#pragma hdrstop


#include "UART_FormaSpiskaSprNaborInfBlockSostavImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_FormaSpiskaSprNaborInfBlockSostavImpl::TART_FormaSpiskaSprNaborInfBlockSostavImpl()           
{                                            
Object=new TART_FormaSpiskaSprNaborInfBlockSostav(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_FormaSpiskaSprNaborInfBlockSostavImpl::~TART_FormaSpiskaSprNaborInfBlockSostavImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_FormaSpiskaSprNaborInfBlockSostavImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_FormaSpiskaSprNaborInfBlockSostav)                        
   {                                                                     
   *ppv=static_cast<IART_FormaSpiskaSprNaborInfBlockSostav*> (this);                                
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
int TART_FormaSpiskaSprNaborInfBlockSostavImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_FormaSpiskaSprNaborInfBlockSostavImpl::kanRelease(void)                                  
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
int  TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_FormaSpiskaSprNaborInfBlockSostavImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_FormaSpiskaSprNaborInfBlockSostavImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_FormaSpiskaSprNaborInfBlockSostavImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TART_FormaSpiskaSprNaborInfBlockSostavImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IART_FormaSpiskaSprNaborInfBlockSostav
IART_DMSprNaborInfBlockSostav* TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_DM(IART_DMSprNaborInfBlockSostav* DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
bool TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
bool TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_Podbor(void)
{
return Object->Podbor;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_Podbor(bool Podbor)
{
Object->Podbor=Podbor;
}
//---------------------------------------------------------------
__int64 TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
UnicodeString TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_NameGroupElement(void)
{
return Object->NameGroupElement;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_NameGroupElement(UnicodeString NameGroupElement)
{
Object->NameGroupElement=NameGroupElement;
}
//---------------------------------------------------------------
__int64 TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
__int64 TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_ViborIdOsnElement(void)
{
return Object->ViborIdOsnElement;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_ViborIdOsnElement(__int64 ViborIdOsnElement)
{
Object->ViborIdOsnElement=ViborIdOsnElement;
}
//---------------------------------------------------------------
bool TART_FormaSpiskaSprNaborInfBlockSostavImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::DeleteElement()
{
return Object->DeleteElement();
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprNaborInfBlockSostavImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
