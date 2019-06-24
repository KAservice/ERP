#include "vcl.h"
#pragma hdrstop


#include "UFormaZakazOfImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaZakazOfImpl::TFormaZakazOfImpl()           
{                                            
Object=new TFormaZakazOf(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaZakazOfImpl::~TFormaZakazOfImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaZakazOfImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaZakazOfImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IAsyncExternalEvent)
   {
   *ppv=static_cast<IAsyncExternalEvent*> (this);
   result=-1;
   }
else if (id_interface==IID_IFormaZakazOf)                        
   {                                                                     
   *ppv=static_cast<IFormaZakazOf*> (this);                                
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
int TFormaZakazOfImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaZakazOfImpl::kanRelease(void)                                  
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
int  TFormaZakazOfImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaZakazOfImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaZakazOfImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaZakazOfImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaZakazOfImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaZakazOfImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaZakazOfImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaZakazOfImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------
//IAcyncExternalEvent
int TFormaZakazOfImpl::AsyncExternalEvent(char * object, char* event, char* data)
{
AnsiString ansi_object=object;
AnsiString ansi_event=event;
AnsiString ansi_data=data;

if (Trim(ansi_object)=="scaner")
	{
	Object->ReadShtrihCodEvent(0,ansi_data);
	}
return -1;
}
//-----------------------------------------------------------------
int TFormaZakazOfImpl::SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form)
{

return -1;
}
//------------------------------------------------------------------
//IFormaZakazOf
bool TFormaZakazOfImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaZakazOfImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IDMRegZak * TFormaZakazOfImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::set_DM(IDMRegZak * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
__int64 TFormaZakazOfImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TFormaZakazOfImpl::get_IdPod(void)
{
return Object->IdPod;
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::set_IdPod(__int64 IdPod)
{
Object->IdPod=IdPod;
}
//---------------------------------------------------------------
bool TFormaZakazOfImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TFormaZakazOfImpl::get_ObjectSave(void)
{
return Object->ObjectSave;
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::set_ObjectSave(bool ObjectSave)
{
Object->ObjectSave=ObjectSave;
}
//---------------------------------------------------------------
__int64 TFormaZakazOfImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
UnicodeString TFormaZakazOfImpl::get_NameTypePrice(void)
{
return Object->NameTypePrice;
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::set_NameTypePrice(UnicodeString NameTypePrice)
{
Object->NameTypePrice=NameTypePrice;
}
//---------------------------------------------------------------
UnicodeString TFormaZakazOfImpl::get_NameObjectZakaza(void)
{
return Object->NameObjectZakaza;
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::set_NameObjectZakaza(UnicodeString NameObjectZakaza)
{
Object->NameObjectZakaza=NameObjectZakaza;
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::ObnovitForm(void)
{
return Object->ObnovitForm();
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
void TFormaZakazOfImpl::OpenZakaz(void)
{
return Object->OpenZakaz();
}
//---------------------------------------------------------------
