#include "vcl.h"
#pragma hdrstop


#include "UREM_FormaSpiskaSprHardwareVZipImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_FormaSpiskaSprHardwareVZipImpl::TREM_FormaSpiskaSprHardwareVZipImpl()           
{                                            
Object=new TREM_FormaSpiskaSprHardwareVZip(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_FormaSpiskaSprHardwareVZipImpl::~TREM_FormaSpiskaSprHardwareVZipImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareVZipImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_FormaSpiskaSprHardwareVZip)                        
   {                                                                     
   *ppv=static_cast<IREM_FormaSpiskaSprHardwareVZip*> (this);                                
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
int TREM_FormaSpiskaSprHardwareVZipImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareVZipImpl::kanRelease(void)                                  
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
int  TREM_FormaSpiskaSprHardwareVZipImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_FormaSpiskaSprHardwareVZipImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareVZipImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_FormaSpiskaSprHardwareVZipImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareVZipImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TREM_FormaSpiskaSprHardwareVZipImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IREM_FormaSpiskaSprHardwareVZip
bool TREM_FormaSpiskaSprHardwareVZipImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprHardwareVZipImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareVZipImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaSpiskaSprHardwareVZipImpl::get_TextMessage(void)
{
return Object->TextMessage;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_TextMessage(UnicodeString TextMessage)
{
Object->TextMessage=TextMessage;
}
//---------------------------------------------------------------
IREM_DMSprHardwareVZip* TREM_FormaSpiskaSprHardwareVZipImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_DM(IREM_DMSprHardwareVZip* DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
IREM_DMSprGrpHardware * TREM_FormaSpiskaSprHardwareVZipImpl::get_DMGrp(void)
{
return Object->DMGrp;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_DMGrp(IREM_DMSprGrpHardware * DMGrp)
{
Object->DMGrp=DMGrp;
}
//---------------------------------------------------------------
__int64 TREM_FormaSpiskaSprHardwareVZipImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_FormaSpiskaSprHardwareVZipImpl::get_IdHardware(void)
{
return Object->IdHardware;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_IdHardware(__int64 IdHardware)
{
Object->IdHardware=IdHardware;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprHardwareVZipImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprHardwareVZipImpl::get_Podbor(void)
{
return Object->Podbor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_Podbor(bool Podbor)
{
Object->Podbor=Podbor;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaSpiskaSprHardwareVZipImpl::get_SerNumber1(void)
{
return Object->SerNumber1;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_SerNumber1(UnicodeString SerNumber1)
{
Object->SerNumber1=SerNumber1;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaSpiskaSprHardwareVZipImpl::get_SerNumber2(void)
{
return Object->SerNumber2;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::set_SerNumber2(UnicodeString SerNumber2)
{
Object->SerNumber2=SerNumber2;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZipImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
