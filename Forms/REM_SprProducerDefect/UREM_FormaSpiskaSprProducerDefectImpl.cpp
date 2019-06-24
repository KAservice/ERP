#include "vcl.h"
#pragma hdrstop


#include "UREM_FormaSpiskaSprProducerDefectImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_FormaSpiskaSprProducerDefectImpl::TREM_FormaSpiskaSprProducerDefectImpl()           
{                                            
Object=new TREM_FormaSpiskaSprProducerDefect(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_FormaSpiskaSprProducerDefectImpl::~TREM_FormaSpiskaSprProducerDefectImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerDefectImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_FormaSpiskaSprProducerDefect)                        
   {                                                                     
   *ppv=static_cast<IREM_FormaSpiskaSprProducerDefect*> (this);                                
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
int TREM_FormaSpiskaSprProducerDefectImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerDefectImpl::kanRelease(void)                                  
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
int  TREM_FormaSpiskaSprProducerDefectImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_FormaSpiskaSprProducerDefectImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerDefectImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_FormaSpiskaSprProducerDefectImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerDefectImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TREM_FormaSpiskaSprProducerDefectImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IREM_FormaSpiskaSprProducerDefect
IREM_DMSprProducerDefect* TREM_FormaSpiskaSprProducerDefectImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::set_DM(IREM_DMSprProducerDefect* DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
IREM_DMSprProducerDefectGrp* TREM_FormaSpiskaSprProducerDefectImpl::get_DMGrp(void)
{
return Object->DMGrp;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::set_DMGrp(IREM_DMSprProducerDefectGrp* DMGrp)
{
Object->DMGrp=DMGrp;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprProducerDefectImpl::get_flVibor(void)
{
return Object->flVibor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::set_flVibor(bool flVibor)
{
Object->flVibor=flVibor;
}
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerDefectImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprProducerDefectImpl::get_flPodbor(void)
{
return Object->flPodbor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::set_flPodbor(bool flPodbor)
{
Object->flPodbor=flPodbor;
}
//---------------------------------------------------------------
__int64 TREM_FormaSpiskaSprProducerDefectImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaSpiskaSprProducerDefectImpl::get_NameGroupElement(void)
{
return Object->NameGroupElement;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::set_NameGroupElement(UnicodeString NameGroupElement)
{
Object->NameGroupElement=NameGroupElement;
}
//---------------------------------------------------------------
__int64 TREM_FormaSpiskaSprProducerDefectImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_FormaSpiskaSprProducerDefectImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprProducerDefectImpl::get_flAllElement(void)
{
return Object->flAllElement;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::set_flAllElement(bool flAllElement)
{
Object->flAllElement=flAllElement;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprProducerDefectImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
