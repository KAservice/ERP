#include "vcl.h"
#pragma hdrstop


#include "UFormaSpiskaSprSostProdImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaSpiskaSprSostProdImpl::TFormaSpiskaSprSostProdImpl()           
{                                            
Object=new TFormaSpiskaSprSostProd(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaSpiskaSprSostProdImpl::~TFormaSpiskaSprSostProdImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaSpiskaSprSostProdImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaSpiskaSprSostProdImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaSpiskaSprSostProd)                        
   {                                                                     
   *ppv=static_cast<IFormaSpiskaSprSostProd*> (this);                                
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
int TFormaSpiskaSprSostProdImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaSpiskaSprSostProdImpl::kanRelease(void)                                  
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
int  TFormaSpiskaSprSostProdImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprSostProdImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaSpiskaSprSostProdImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprSostProdImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaSprSostProdImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaSpiskaSprSostProdImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TFormaSpiskaSprSostProdImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaSpiskaSprSostProdImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IFormaSpiskaSprSostProd
IDMSprSostProd * TFormaSpiskaSprSostProdImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprSostProdImpl::set_DM(IDMSprSostProd * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
bool TFormaSpiskaSprSostProdImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprSostProdImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaSpiskaSprSostProdImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprSostProdImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}

//---------------------------------------------------------------
__int64 TFormaSpiskaSprSostProdImpl::get_IdNomRest(void)
{
return Object->IdNomRest;
}
//---------------------------------------------------------------
void TFormaSpiskaSprSostProdImpl::set_IdNomRest(__int64 IdNomRest)
{
Object->IdNomRest=IdNomRest;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprSostProdImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TFormaSpiskaSprSostProdImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
UnicodeString TFormaSpiskaSprSostProdImpl::get_NameNom(void)
{
return Object->NameNom;
}
//----------------------------------------------------------------
void TFormaSpiskaSprSostProdImpl::set_NameNom(UnicodeString NameNom)
{
Object->NameNom=NameNom;
}
//-----------------------------------------------------------------
double TFormaSpiskaSprSostProdImpl::get_KolEdProd(void)
{
return Object->KolEdProd;
}
//----------------------------------------------------------------
void TFormaSpiskaSprSostProdImpl::set_KolEdProd(double KolEdProd)
{
Object->KolEdProd=KolEdProd;
}
//---------------------------------------------------------------

UnicodeString TFormaSpiskaSprSostProdImpl::get_NameEdProd(void)
{
return Object->NameEdProd;
}
//---------------------------------------------------------------
void TFormaSpiskaSprSostProdImpl::set_NameEdProd(UnicodeString NameEdProd)
{
Object->NameEdProd=NameEdProd;
}
//---------------------------------------------------------------
double TFormaSpiskaSprSostProdImpl::get_KFEdProd(void)
{
return Object->KFEdProd;
}
//---------------------------------------------------------------
void TFormaSpiskaSprSostProdImpl::set_KFEdProd(double KFEdProd)
{
Object->KFEdProd=KFEdProd;
}
//-------------------------------------------------------------
