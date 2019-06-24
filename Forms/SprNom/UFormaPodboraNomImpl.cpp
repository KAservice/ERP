#include "vcl.h"
#pragma hdrstop


#include "UFormaPodboraNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaPodboraNomImpl::TFormaPodboraNomImpl()           
{                                            
Object=new TFormaPodboraNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaPodboraNomImpl::~TFormaPodboraNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaPodboraNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaPodboraNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaPodboraNom)                        
   {                                                                     
   *ppv=static_cast<IFormaPodboraNom*> (this);                                
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
int TFormaPodboraNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaPodboraNomImpl::kanRelease(void)                                  
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
int  TFormaPodboraNomImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaPodboraNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaPodboraNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaPodboraNomImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TFormaPodboraNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaPodboraNomImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IFormaPodboraNom
bool TFormaPodboraNomImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaPodboraNomImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------

__int64 TFormaPodboraNomImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
double TFormaPodboraNomImpl::get_Price(void)
{
return Object->Price;
}
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_Price(double Price)
{
Object->Price=Price;
}
//---------------------------------------------------------------
double TFormaPodboraNomImpl::get_PriceBasEd(void)
{
return Object->PriceBasEd;
}
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_PriceBasEd(double PriceBasEd)
{
Object->PriceBasEd=PriceBasEd;
}
//---------------------------------------------------------------
double TFormaPodboraNomImpl::get_Kol(void)
{
return Object->Kol;
}
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_Kol(double Kol)
{
Object->Kol=Kol;
}
//---------------------------------------------------------------
double TFormaPodboraNomImpl::get_Summa(void)
{
return Object->Summa;
}
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_Summa(double Summa)
{
Object->Summa=Summa;
}
//---------------------------------------------------------------
int TFormaPodboraNomImpl::get_IdEd(void)
{
return Object->IdEd;
}
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_IdEd(int IdEd)
{
Object->IdEd=IdEd;
}
//---------------------------------------------------------------
UnicodeString TFormaPodboraNomImpl::get_NameEd(void)
{
return Object->NameEd;
}
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_NameEd(UnicodeString NameEd)
{
Object->NameEd=NameEd;
}
//---------------------------------------------------------------
UnicodeString TFormaPodboraNomImpl::get_NameNom(void)
{
return Object->NameNom;
}
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_NameNom(UnicodeString NameNom)
{
Object->NameNom=NameNom;
}
//---------------------------------------------------------------
double TFormaPodboraNomImpl::get_KFEd(void)
{
return Object->KFEd;
}
//---------------------------------------------------------------
void TFormaPodboraNomImpl::set_KFEd(double KFEd)
{
Object->KFEd=KFEd;
}
//---------------------------------------------------------------
void TFormaPodboraNomImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
