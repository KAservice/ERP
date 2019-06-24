#include "vcl.h"
#pragma hdrstop


#include "UREM_FormaSpiskaSprProducerSectionImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_FormaSpiskaSprProducerSectionImpl::TREM_FormaSpiskaSprProducerSectionImpl()           
{                                            
Object=new TREM_FormaSpiskaSprProducerSection(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_FormaSpiskaSprProducerSectionImpl::~TREM_FormaSpiskaSprProducerSectionImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerSectionImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_FormaSpiskaSprProducerSection)                        
   {                                                                     
   *ppv=static_cast<IREM_FormaSpiskaSprProducerSection*> (this);                                
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
int TREM_FormaSpiskaSprProducerSectionImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerSectionImpl::kanRelease(void)                                  
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
int  TREM_FormaSpiskaSprProducerSectionImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_FormaSpiskaSprProducerSectionImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerSectionImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_FormaSpiskaSprProducerSectionImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerSectionImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TREM_FormaSpiskaSprProducerSectionImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IREM_FormaSpiskaSprProducerSection
IREM_DMSprProducerSection* TREM_FormaSpiskaSprProducerSectionImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::set_DM(IREM_DMSprProducerSection* DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
IREM_DMSprProducerSectionGrp* TREM_FormaSpiskaSprProducerSectionImpl::get_DMGrp(void)
{
return Object->DMGrp;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::set_DMGrp(IREM_DMSprProducerSectionGrp* DMGrp)
{
Object->DMGrp=DMGrp;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprProducerSectionImpl::get_flVibor(void)
{
return Object->flVibor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::set_flVibor(bool flVibor)
{
Object->flVibor=flVibor;
}
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerSectionImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprProducerSectionImpl::get_flPodbor(void)
{
return Object->flPodbor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::set_flPodbor(bool flPodbor)
{
Object->flPodbor=flPodbor;
}
//---------------------------------------------------------------
__int64 TREM_FormaSpiskaSprProducerSectionImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaSpiskaSprProducerSectionImpl::get_NameGroupElement(void)
{
return Object->NameGroupElement;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::set_NameGroupElement(UnicodeString NameGroupElement)
{
Object->NameGroupElement=NameGroupElement;
}
//---------------------------------------------------------------
__int64 TREM_FormaSpiskaSprProducerSectionImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_FormaSpiskaSprProducerSectionImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprProducerSectionImpl::get_flAllElement(void)
{
return Object->flAllElement;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::set_flAllElement(bool flAllElement)
{
Object->flAllElement=flAllElement;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSectionImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
