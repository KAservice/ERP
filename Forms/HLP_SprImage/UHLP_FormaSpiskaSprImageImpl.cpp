#include "vcl.h"
#pragma hdrstop


#include "UHLP_FormaSpiskaSprImageImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_FormaSpiskaSprImageImpl::THLP_FormaSpiskaSprImageImpl()           
{                                            
Object=new THLP_FormaSpiskaSprImage(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_FormaSpiskaSprImageImpl::~THLP_FormaSpiskaSprImageImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_FormaSpiskaSprImageImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_FormaSpiskaSprImageImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_FormaSpiskaSprImage)                        
   {                                                                     
   *ppv=static_cast<IHLP_FormaSpiskaSprImage*> (this);                                
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
int THLP_FormaSpiskaSprImageImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_FormaSpiskaSprImageImpl::kanRelease(void)                                  
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
int  THLP_FormaSpiskaSprImageImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_FormaSpiskaSprImageImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_FormaSpiskaSprImageImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_FormaSpiskaSprImageImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_FormaSpiskaSprImageImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_FormaSpiskaSprImageImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_FormaSpiskaSprImageImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int THLP_FormaSpiskaSprImageImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IHLP_FormaSpiskaSprImage
IHLP_DMSprImage* THLP_FormaSpiskaSprImageImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprImageImpl::set_DM(IHLP_DMSprImage* DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
IHLP_DMSprImageGrp * THLP_FormaSpiskaSprImageImpl::get_DMGrp(void)
{
return Object->DMGrp;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprImageImpl::set_DMGrp(IHLP_DMSprImageGrp * DMGrp)
{
Object->DMGrp=DMGrp;
}
//---------------------------------------------------------------
bool THLP_FormaSpiskaSprImageImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprImageImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int THLP_FormaSpiskaSprImageImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprImageImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
__int64 THLP_FormaSpiskaSprImageImpl::get_IdGrpElement(void)
{
return Object->IdGrpElement;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprImageImpl::set_IdGrpElement(__int64 IdGrpElement)
{
Object->IdGrpElement=IdGrpElement;
}
//---------------------------------------------------------------
__int64 THLP_FormaSpiskaSprImageImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprImageImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
__int64 THLP_FormaSpiskaSprImageImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprImageImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool THLP_FormaSpiskaSprImageImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprImageImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void THLP_FormaSpiskaSprImageImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
