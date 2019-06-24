#include "vcl.h"
#pragma hdrstop


#include "UHLP_FormaSpiskaSprNaborInfBlockSostavImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_FormaSpiskaSprNaborInfBlockSostavImpl::THLP_FormaSpiskaSprNaborInfBlockSostavImpl()           
{                                            
Object=new THLP_FormaSpiskaSprNaborInfBlockSostav(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_FormaSpiskaSprNaborInfBlockSostavImpl::~THLP_FormaSpiskaSprNaborInfBlockSostavImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_FormaSpiskaSprNaborInfBlockSostavImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_FormaSpiskaSprNaborInfBlockSostav)                        
   {                                                                     
   *ppv=static_cast<IHLP_FormaSpiskaSprNaborInfBlockSostav*> (this);                                
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
int THLP_FormaSpiskaSprNaborInfBlockSostavImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_FormaSpiskaSprNaborInfBlockSostavImpl::kanRelease(void)                                  
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
int  THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_FormaSpiskaSprNaborInfBlockSostavImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_FormaSpiskaSprNaborInfBlockSostavImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_FormaSpiskaSprNaborInfBlockSostavImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int THLP_FormaSpiskaSprNaborInfBlockSostavImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IHLP_FormaSpiskaSprNaborInfBlockSostav
IHLP_DMSprNaborInfBlockSostav* THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_DM(IHLP_DMSprNaborInfBlockSostav* DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
bool THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
bool THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_Podbor(void)
{
return Object->Podbor;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_Podbor(bool Podbor)
{
Object->Podbor=Podbor;
}
//---------------------------------------------------------------
__int64 THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
UnicodeString THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_NameGroupElement(void)
{
return Object->NameGroupElement;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_NameGroupElement(UnicodeString NameGroupElement)
{
Object->NameGroupElement=NameGroupElement;
}
//---------------------------------------------------------------
__int64 THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
__int64 THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_ViborIdOsnElement(void)
{
return Object->ViborIdOsnElement;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_ViborIdOsnElement(__int64 ViborIdOsnElement)
{
Object->ViborIdOsnElement=ViborIdOsnElement;
}
//---------------------------------------------------------------
bool THLP_FormaSpiskaSprNaborInfBlockSostavImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::DeleteElement()
{
return Object->DeleteElement();
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostavImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
