#include "vcl.h"
#pragma hdrstop


#include "UFormaSpiskaSprVesNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaSpiskaSprVesNomImpl::TFormaSpiskaSprVesNomImpl()           
{                                            
Object=new TFormaSpiskaSprVesNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaSpiskaSprVesNomImpl::~TFormaSpiskaSprVesNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaSpiskaSprVesNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaSpiskaSprVesNom)                        
   {                                                                     
   *ppv=static_cast<IFormaSpiskaSprVesNom*> (this);                                
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
int TFormaSpiskaSprVesNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaSpiskaSprVesNomImpl::kanRelease(void)                                  
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
int  TFormaSpiskaSprVesNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaSpiskaSprVesNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaSprVesNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaSpiskaSprVesNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaSprVesNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaSpiskaSprVesNomImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IFormaSpiskaSprVesNom
bool TFormaSpiskaSprVesNomImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaSpiskaSprVesNomImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IDMSprVesNom* TFormaSpiskaSprVesNomImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::set_DM(IDMSprVesNom* DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
IDMSprGrpVesNom* TFormaSpiskaSprVesNomImpl::get_DMGrp(void)
{
return Object->DMGrp;
}
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::set_DMGrp(IDMSprGrpVesNom* DMGrp)
{
Object->DMGrp=DMGrp;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprVesNomImpl::get_IdScale(void)
{
return Object->IdScale;
}
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::set_IdScale(__int64 IdScale)
{
Object->IdScale=IdScale;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprVesNomImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprVesNomImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprVesNomImpl::get_IdVesNom(void)
{
return Object->IdVesNom;
}
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::set_IdVesNom(__int64 IdVesNom)
{
Object->IdVesNom=IdVesNom;
}
//---------------------------------------------------------------
bool TFormaSpiskaSprVesNomImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
bool TFormaSpiskaSprVesNomImpl::get_Podbor(void)
{
return Object->Podbor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::set_Podbor(bool Podbor)
{
Object->Podbor=Podbor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprVesNomImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
