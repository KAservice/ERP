#include "vcl.h"
#pragma hdrstop


#include "UFormaGurDocCheckKKM2Impl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaGurDocCheckKKM2Impl::TFormaGurDocCheckKKM2Impl()           
{                                            
Object=new TFormaGurDocCheckKKM2(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaGurDocCheckKKM2Impl::~TFormaGurDocCheckKKM2Impl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaGurDocCheckKKM2Impl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaGurDocCheckKKM2Impl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaGurDocCheckKKM2)                        
   {                                                                     
   *ppv=static_cast<IFormaGurDocCheckKKM2*> (this);                                
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
int TFormaGurDocCheckKKM2Impl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaGurDocCheckKKM2Impl::kanRelease(void)                                  
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

//---------------------------------------------------------------
int  TFormaGurDocCheckKKM2Impl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaGurDocCheckKKM2Impl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaGurDocCheckKKM2Impl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaGurDocCheckKKM2Impl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaGurDocCheckKKM2Impl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaGurDocCheckKKM2Impl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TFormaGurDocCheckKKM2Impl::Done(void)
{
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------
//IkanCallBack
int TFormaGurDocCheckKKM2Impl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)
{
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект
									id_object,      //тип дочернего объекта
									type_event,     //тип события в дочернем объекте
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);
}
//---------------------------------------------------------------
//IFormaGurDocCheckKKM2
IDMGurDocCheckKKM2 * TFormaGurDocCheckKKM2Impl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TFormaGurDocCheckKKM2Impl::set_DM(IDMGurDocCheckKKM2 * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
bool TFormaGurDocCheckKKM2Impl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaGurDocCheckKKM2Impl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaGurDocCheckKKM2Impl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaGurDocCheckKKM2Impl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
__int64 TFormaGurDocCheckKKM2Impl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TFormaGurDocCheckKKM2Impl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TFormaGurDocCheckKKM2Impl::get_IdKKM(void)
{
return Object->IdKKM;
}
//---------------------------------------------------------------
void TFormaGurDocCheckKKM2Impl::set_IdKKM(__int64 IdKKM)
{
Object->IdKKM=IdKKM;
}
//---------------------------------------------------------------
bool TFormaGurDocCheckKKM2Impl::get_Otbor(void)
{
return Object->Otbor;
}
//---------------------------------------------------------------
void TFormaGurDocCheckKKM2Impl::set_Otbor(bool Otbor)
{
Object->Otbor=Otbor;
}
//---------------------------------------------------------------
TDateTime TFormaGurDocCheckKKM2Impl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TFormaGurDocCheckKKM2Impl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TFormaGurDocCheckKKM2Impl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TFormaGurDocCheckKKM2Impl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
void TFormaGurDocCheckKKM2Impl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
