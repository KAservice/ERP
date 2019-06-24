#include "vcl.h"
#pragma hdrstop


#include "UFormaSpiskaSprOborudParamImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaSpiskaSprOborudParamImpl::TFormaSpiskaSprOborudParamImpl()           
{                                            
Object=new TFormaSpiskaSprOborudParam(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaSpiskaSprOborudParamImpl::~TFormaSpiskaSprOborudParamImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaSpiskaSprOborudParamImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IkasForm)
   {
   *ppv=static_cast<IkasForm*> (this);
   result=-1;
   }
else if (id_interface==IID_IkasFormSpr)
   {
   *ppv=static_cast<IkasFormSpr*> (this);
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
int TFormaSpiskaSprOborudParamImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaSpiskaSprOborudParamImpl::kanRelease(void)                                  
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
int  TFormaSpiskaSprOborudParamImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaSpiskaSprOborudParamImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaSprOborudParamImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaSpiskaSprOborudParamImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaSprOborudParamImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaSpiskaSprOborudParamImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

   //IkasForm
void TFormaSpiskaSprOborudParamImpl::UpdateForm(void)
{

Object->UpdateForm();
}
//---------------------------------------------------------------
bool TFormaSpiskaSprOborudParamImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_Vibor(bool Vibor)  //форма открыта для выбора
{
Object->Vibor=Vibor;
}
//-------------------------------------------------------------
int TFormaSpiskaSprOborudParamImpl::get_NumberProcVibor(void)
{

return Object->NumberProcVibor;
}
//--------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_NumberProcVibor(int NumberProcVibor)  //какую процедуру использовать для обработки выбора во внешней форме
{
Object->NumberProcVibor=NumberProcVibor;
}
//-----------------------------------------------------------------



   //IkasFormSpr
__int64 TFormaSpiskaSprOborudParamImpl::get_IdGroupEl1(void)
{

return Object->IdGroupEl1;
}
//-------------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_IdGroupEl1(__int64 IdGroupEl1)
{
Object->IdGroupEl1=IdGroupEl1;
}
//-------------------------------------------------------------------
UnicodeString TFormaSpiskaSprOborudParamImpl::get_NameGroupEl1(void)
{

return Object->NameGroupEl1;
}
//-------------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_NameGroupEl1(UnicodeString NameGroupEl1)
{
Object->NameGroupEl1=NameGroupEl1;
}
//-----------------------------------------------------------------

__int64 TFormaSpiskaSprOborudParamImpl::get_IdGroupEl2(void)
{
return Object->IdGroupEl2;
}
//--------------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_IdGroupEl2(__int64 IdGroupEl2)
{
Object->IdGroupEl2=IdGroupEl2;
}
//-------------------------------------------------------------------
UnicodeString TFormaSpiskaSprOborudParamImpl::get_NameGroupEl2(void)
{
return Object->NameGroupEl2;
}
//---------------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_NameGroupEl2(UnicodeString NameGroupEl2)
{
Object->NameGroupEl2=NameGroupEl2;
}
//------------------------------------------------------------------

__int64 TFormaSpiskaSprOborudParamImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//------------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//-------------------------------------------------------------------
UnicodeString TFormaSpiskaSprOborudParamImpl::get_NameOwner(void)
{
return Object->NameOwner;
}
//----------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_NameOwner(UnicodeString NameOwner)
{
Object->NameOwner=NameOwner;
}
//-----------------------------------------------------------------

__int64 TFormaSpiskaSprOborudParamImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_IdGrp(__int64 IdGrp)
{

Object->IdGrp=IdGrp;
}
//-----------------------------------------------------------------
UnicodeString TFormaSpiskaSprOborudParamImpl::get_NameGrp(void)
{
return Object->NameGrp;
}
//-----------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_NameGrp(UnicodeString NameGrp)
{
Object->NameGrp=NameGrp;
}
//----------------------------------------------------------------

__int64 TFormaSpiskaSprOborudParamImpl::get_IdEl(void)
{
return Object->IdEl;
}
//----------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_IdEl(__int64 IdEl)
{
Object->IdEl=IdEl;
}
//----------------------------------------------------------------
UnicodeString TFormaSpiskaSprOborudParamImpl::get_NameEl(void)
{
return Object->NameEl;
}
//-----------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_NameEl(UnicodeString IdEl)
{
Object->NameEl=NameEl;
}
//------------------------------------------------------------------

bool TFormaSpiskaSprOborudParamImpl::get_All(void)
{
return Object->All;
}
//-------------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_All(bool All)
{
Object->All=All;
}
//-------------------------------------------------------------------


IkasDMSpr * TFormaSpiskaSprOborudParamImpl::get_DM(void)
{

return Object->DM;
}
//-------------------------------------------------------------------
void TFormaSpiskaSprOborudParamImpl::set_DM(IkasDMSpr * DM)
{
Object->DM=DM;
}
//------------------------------------------------------------------
