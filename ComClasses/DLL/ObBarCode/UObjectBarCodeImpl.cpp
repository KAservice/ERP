#pragma hdrstop


#include "UObjectBarCodeImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TObjectBarCodeImpl::TObjectBarCodeImpl()           
{                                            
Object=new TObjectBarCode();
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TObjectBarCodeImpl::~TObjectBarCodeImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TObjectBarCodeImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TObjectBarCodeImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
 {                                                                         
int result=0;                                                             
if (id_interface==IID_IkanUnknown)                                        
   {                                                                     
   *ppv=static_cast<IkanUnknown*> (this);                                 
   result=-1;                                                             
   }                                                                      
else if (id_interface==IID_IMainInterface)                        
   {                                                                     
   *ppv=static_cast<IMainInterface*> (this);                                
   result=-1;                                                            
   }                                                                     
else if (id_interface==IID_IObjectBarCode)                        
   {                                                                     
   *ppv=static_cast<IObjectBarCode*> (this);                                
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
int TObjectBarCodeImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TObjectBarCodeImpl::kanRelease(void)                                  
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
int  TObjectBarCodeImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TObjectBarCodeImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TObjectBarCodeImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TObjectBarCodeImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TObjectBarCodeImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
double TObjectBarCodeImpl::get_Kol(void)
{
return Object->Kol;
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_Kol(double Kol)
{
Object->Kol=Kol;
}
//---------------------------------------------------------------
__int64 TObjectBarCodeImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
double TObjectBarCodeImpl::get_Price(void)
{
return Object->Price;
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_Price(double Price)
{
Object->Price=Price;
}
//---------------------------------------------------------------
IDMSprNom * TObjectBarCodeImpl::get_SprNom(void)
{
return Object->SprNom;
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_SprNom(IDMSprNom * SprNom)
{
Object->SprNom=SprNom;
}
//---------------------------------------------------------------
IDMSprEd * TObjectBarCodeImpl::get_SprEd(void)
{
return Object->SprEd;
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_SprEd(IDMSprEd * SprEd)
{
Object->SprEd=SprEd;
}
//---------------------------------------------------------------
bool TObjectBarCodeImpl::get_OutReady(void)
{
return Object->OutReady;
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_OutReady(bool OutReady)
{
Object->OutReady=OutReady;
}
//---------------------------------------------------------------
UnicodeString TObjectBarCodeImpl::get_Prefiks1(void)
{
return Object->Prefiks1;
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_Prefiks1(UnicodeString Prefiks1)
{
Object->Prefiks1=Prefiks1;
}
//---------------------------------------------------------------
UnicodeString TObjectBarCodeImpl::get_Prefiks2(void)
{
return Object->Prefiks2;
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_Prefiks2(UnicodeString Prefiks2)
{
Object->Prefiks2=Prefiks2;
}
//---------------------------------------------------------------
UnicodeString TObjectBarCodeImpl::get_Prefiks3(void)
{
return Object->Prefiks3;
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_Prefiks3(UnicodeString Prefiks3)
{
Object->Prefiks3=Prefiks3;
}
//---------------------------------------------------------------
UnicodeString TObjectBarCodeImpl::get_Prefiks4(void)
{
return Object->Prefiks4;
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_Prefiks4(UnicodeString Prefiks4)
{
Object->Prefiks4=Prefiks4;
}
//---------------------------------------------------------------
UnicodeString TObjectBarCodeImpl::get_Prefiks5(void)
{
return Object->Prefiks5;
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::set_Prefiks5(UnicodeString Prefiks5)
{
Object->Prefiks5=Prefiks5;
}
//---------------------------------------------------------------
UnicodeString TObjectBarCodeImpl::AddEAN13(UnicodeString cod)
{
return Object->AddEAN13(cod);
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::ObrabotatShtrihCod(UnicodeString sh)
{
return Object->ObrabotatShtrihCod(sh);
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::ObrabotatPrefiks2(UnicodeString bar_code)
{
return Object->ObrabotatPrefiks2(bar_code);
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::ObrabotatPrefiks3(UnicodeString bar_code)
{
return Object->ObrabotatPrefiks3(bar_code);
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::ObrabotatPrefiks4(UnicodeString bar_code)
{
return Object->ObrabotatPrefiks4(bar_code);
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::ObrabotatPrefiks5(UnicodeString bar_code)
{
return Object->ObrabotatPrefiks5(bar_code);
}
//---------------------------------------------------------------
UnicodeString TObjectBarCodeImpl::GetNewBarCode(UnicodeString code, int type_bar_code)
{
return Object->GetNewBarCode(code,type_bar_code);
}
//---------------------------------------------------------------
void TObjectBarCodeImpl::GetValuePrefiksBarCode(void)
{
return Object->GetValuePrefiksBarCode();
}
//---------------------------------------------------------------
