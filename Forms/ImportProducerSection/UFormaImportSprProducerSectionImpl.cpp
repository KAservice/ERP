#include "vcl.h"
#pragma hdrstop


#include "UFormaImportSprProducerSectionImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaImportSprProducerSectionImpl::TFormaImportSprProducerSectionImpl()           
{                                            
Object=new TFormaImportSprProducerSection(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaImportSprProducerSectionImpl::~TFormaImportSprProducerSectionImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaImportSprProducerSectionImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaImportSprProducerSection)                        
   {                                                                     
   *ppv=static_cast<IFormaImportSprProducerSection*> (this);                                
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
int TFormaImportSprProducerSectionImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaImportSprProducerSectionImpl::kanRelease(void)                                  
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
int  TFormaImportSprProducerSectionImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaImportSprProducerSectionImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaImportSprProducerSectionImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaImportSprProducerSectionImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaImportSprProducerSectionImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaImportSprProducerSectionImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IFormaImportSprProducerSection
bool TFormaImportSprProducerSectionImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaImportSprProducerSectionImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerSectionImpl::get_IdInfBase(void)
{
return Object->IdInfBase;
}
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::set_IdInfBase(__int64 IdInfBase)
{
Object->IdInfBase=IdInfBase;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerSectionImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerSectionImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerSectionImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerSectionImpl::get_IdGrpNom(void)
{
return Object->IdGrpNom;
}
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::set_IdGrpNom(__int64 IdGrpNom)
{
Object->IdGrpNom=IdGrpNom;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerSectionImpl::get_IdProducer(void)
{
return Object->IdProducer;
}
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::set_IdProducer(__int64 IdProducer)
{
Object->IdProducer=IdProducer;
}
//---------------------------------------------------------------
__int64 TFormaImportSprProducerSectionImpl::get_IdImportSet(void)
{
return Object->IdImportSet;
}
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::set_IdImportSet(__int64 IdImportSet)
{
Object->IdImportSet=IdImportSet;
}
//---------------------------------------------------------------
void TFormaImportSprProducerSectionImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
