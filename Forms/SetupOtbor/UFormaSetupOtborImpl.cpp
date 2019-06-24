#include "vcl.h"
#pragma hdrstop


#include "UFormaSetupOtborImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaSetupOtborImpl::TFormaSetupOtborImpl()           
{                                            
Object=new TFormaSetupOtbor(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaSetupOtborImpl::~TFormaSetupOtborImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaSetupOtborImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaSetupOtborImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaSetupOtbor)                        
   {                                                                     
   *ppv=static_cast<IFormaSetupOtbor*> (this);                                
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
int TFormaSetupOtborImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaSetupOtborImpl::kanRelease(void)                                  
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
int  TFormaSetupOtborImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaSetupOtborImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaSetupOtborImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaSetupOtborImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaSetupOtborImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaSetupOtborImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IFormaSetupOtbor
bool TFormaSetupOtborImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaSetupOtborImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
__int64 TFormaSetupOtborImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
UnicodeString TFormaSetupOtborImpl::get_NameKlient(void)
{
return Object->NameKlient;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_NameKlient(UnicodeString NameKlient)
{
Object->NameKlient=NameKlient;
}
//---------------------------------------------------------------
__int64 TFormaSetupOtborImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
UnicodeString TFormaSetupOtborImpl::get_NameSklad(void)
{
return Object->NameSklad;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_NameSklad(UnicodeString NameSklad)
{
Object->NameSklad=NameSklad;
}
//---------------------------------------------------------------
__int64 TFormaSetupOtborImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
UnicodeString TFormaSetupOtborImpl::get_NameFirm(void)
{
return Object->NameFirm;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_NameFirm(UnicodeString NameFirm)
{
Object->NameFirm=NameFirm;
}
//---------------------------------------------------------------
UnicodeString TFormaSetupOtborImpl::get_StringTypeDoc(void)
{
return Object->StringTypeDoc;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_StringTypeDoc(UnicodeString StringTypeDoc)
{
Object->StringTypeDoc=StringTypeDoc;
}
//---------------------------------------------------------------
UnicodeString TFormaSetupOtborImpl::get_NameTypeDoc(void)
{
return Object->NameTypeDoc;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_NameTypeDoc(UnicodeString NameTypeDoc)
{
Object->NameTypeDoc=NameTypeDoc;
}
//---------------------------------------------------------------
UnicodeString TFormaSetupOtborImpl::get_StringFullTypeDoc(void)
{
return Object->StringFullTypeDoc;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_StringFullTypeDoc(UnicodeString StringFullTypeDoc)
{
Object->StringFullTypeDoc=StringFullTypeDoc;
}
//---------------------------------------------------------------
bool TFormaSetupOtborImpl::get_OtborPoKlient(void)
{
return Object->OtborPoKlient;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_OtborPoKlient(bool OtborPoKlient)
{
Object->OtborPoKlient=OtborPoKlient;
}
//---------------------------------------------------------------
bool TFormaSetupOtborImpl::get_OtborPoFirm(void)
{
return Object->OtborPoFirm;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_OtborPoFirm(bool OtborPoFirm)
{
Object->OtborPoFirm=OtborPoFirm;
}
//---------------------------------------------------------------
bool TFormaSetupOtborImpl::get_OtborPoSklad(void)
{
return Object->OtborPoSklad;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_OtborPoSklad(bool OtborPoSklad)
{
Object->OtborPoSklad=OtborPoSklad;
}
//---------------------------------------------------------------
bool TFormaSetupOtborImpl::get_OtborPoTypeDoc(void)
{
return Object->OtborPoTypeDoc;
}
//---------------------------------------------------------------
void TFormaSetupOtborImpl::set_OtborPoTypeDoc(bool OtborPoTypeDoc)
{
Object->OtborPoTypeDoc=OtborPoTypeDoc;
}
//---------------------------------------------------------------
