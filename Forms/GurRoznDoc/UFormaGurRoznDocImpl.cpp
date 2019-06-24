#include "vcl.h"
#pragma hdrstop


#include "UFormaGurRoznDocImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaGurRoznDocImpl::TFormaGurRoznDocImpl()           
{                                            
Object=new TFormaGurRoznDoc(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaGurRoznDocImpl::~TFormaGurRoznDocImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaGurRoznDocImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaGurRoznDoc)                        
   {                                                                     
   *ppv=static_cast<IFormaGurRoznDoc*> (this);                                
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
int TFormaGurRoznDocImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaGurRoznDocImpl::kanRelease(void)                                  
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
int  TFormaGurRoznDocImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaGurRoznDocImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaGurRoznDocImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaGurRoznDocImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaGurRoznDocImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaGurRoznDocImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IFormaGurRoznDoc
IDMGurRoznDoc * TFormaGurRoznDocImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_DM(IDMGurRoznDoc * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
bool TFormaGurRoznDocImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaGurRoznDocImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
__int64 TFormaGurRoznDocImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TFormaGurRoznDocImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TFormaGurRoznDocImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 TFormaGurRoznDocImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
UnicodeString TFormaGurRoznDocImpl::get_NameKlient(void)
{
return Object->NameKlient;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_NameKlient(UnicodeString NameKlient)
{
Object->NameKlient=NameKlient;
}
//---------------------------------------------------------------
UnicodeString TFormaGurRoznDocImpl::get_StringTypeDoc(void)
{
return Object->StringTypeDoc;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_StringTypeDoc(UnicodeString StringTypeDoc)
{
Object->StringTypeDoc=StringTypeDoc;
}
//---------------------------------------------------------------
UnicodeString TFormaGurRoznDocImpl::get_NameTypeDoc(void)
{
return Object->NameTypeDoc;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_NameTypeDoc(UnicodeString NameTypeDoc)
{
Object->NameTypeDoc=NameTypeDoc;
}
//---------------------------------------------------------------
UnicodeString TFormaGurRoznDocImpl::get_StringFullTypeDoc(void)
{
return Object->StringFullTypeDoc;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_StringFullTypeDoc(UnicodeString StringFullTypeDoc)
{
Object->StringFullTypeDoc=StringFullTypeDoc;
}
//---------------------------------------------------------------
bool TFormaGurRoznDocImpl::get_OtborPoKlientu(void)
{
return Object->OtborPoKlientu;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_OtborPoKlientu(bool OtborPoKlientu)
{
Object->OtborPoKlientu=OtborPoKlientu;
}
//---------------------------------------------------------------
bool TFormaGurRoznDocImpl::get_OtborPoTypeDoc(void)
{
return Object->OtborPoTypeDoc;
}
//---------------------------------------------------------------
void TFormaGurRoznDocImpl::set_OtborPoTypeDoc(bool OtborPoTypeDoc)
{
Object->OtborPoTypeDoc=OtborPoTypeDoc;
}
//---------------------------------------------------------------
