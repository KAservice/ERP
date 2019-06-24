#include "vcl.h"
#pragma hdrstop


#include "UFormaImportSprProducerRabotaImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaImportSprProducerRabotaImpl::TFormaImportSprProducerRabotaImpl()           
{                                            
Object=new TFormaImportSprProducerRabota(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaImportSprProducerRabotaImpl::~TFormaImportSprProducerRabotaImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaImportSprProducerRabotaImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaImportSprProducerRabotaImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaImportSprProducerRabota)                        
   {                                                                     
   *ppv=static_cast<IFormaImportSprProducerRabota*> (this);                                
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
int TFormaImportSprProducerRabotaImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaImportSprProducerRabotaImpl::kanRelease(void)                                  
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
int  TFormaImportSprProducerRabotaImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaImportSprProducerRabotaImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaImportSprProducerRabotaImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaImportSprProducerRabotaImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaImportSprProducerRabotaImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaImportSprProducerRabotaImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaImportSprProducerRabotaImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaImportSprProducerRabotaImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IFormaImportSprProducerRabota
__int64 TFormaImportSprProducerRabotaImpl::get_IdInfBase(void)
{
return Object->IdInfBase;
}
//---------------------------------------------------------------
void TFormaImportSprProducerRabotaImpl::set_IdInfBase(__int64 IdInfBase)
{
Object->IdInfBase=IdInfBase;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerRabotaImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TFormaImportSprProducerRabotaImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerRabotaImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TFormaImportSprProducerRabotaImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerRabotaImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TFormaImportSprProducerRabotaImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerRabotaImpl::get_IdGrpNom(void)
{
return Object->IdGrpNom;
}
//---------------------------------------------------------------
void TFormaImportSprProducerRabotaImpl::set_IdGrpNom(__int64 IdGrpNom)
{
Object->IdGrpNom=IdGrpNom;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerRabotaImpl::get_IdProducer(void)
{
return Object->IdProducer;
}
//---------------------------------------------------------------
void TFormaImportSprProducerRabotaImpl::set_IdProducer(__int64 IdProducer)
{
Object->IdProducer=IdProducer;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerRabotaImpl::get_IdImportSet(void)
{
return Object->IdImportSet;
}
//---------------------------------------------------------------
void TFormaImportSprProducerRabotaImpl::set_IdImportSet(__int64 IdImportSet)
{
Object->IdImportSet=IdImportSet;
}
//---------------------------------------------------------------
void TFormaImportSprProducerRabotaImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
