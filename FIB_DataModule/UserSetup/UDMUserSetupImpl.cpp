#include "vcl.h"
#pragma hdrstop


#include "UDMUserSetupImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMUserSetupImpl::TDMUserSetupImpl()           
{                                            
Object=new TDMUserSetup(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMUserSetupImpl::~TDMUserSetupImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMUserSetupImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMUserSetupImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMUserSetup)                        
   {                                                                     
   *ppv=static_cast<IDMUserSetup*> (this);                                
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
int TDMUserSetupImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMUserSetupImpl::kanRelease(void)                                  
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
int  TDMUserSetupImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMUserSetupImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMUserSetupImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMUserSetupImpl::set_TextError(UnicodeString  TextError)
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMUserSetupImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMUserSetupImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMUserSetup
void TDMUserSetupImpl::SaveSetup(AnsiString form_name,AnsiString name_setup, AnsiString value)
{
return Object->SaveSetup(form_name,name_setup,value);
}
//---------------------------------------------------------------
AnsiString TDMUserSetupImpl::LoadSetup(AnsiString form_name, AnsiString name_setup)
{
return Object->LoadSetup(form_name,name_setup);
}
//---------------------------------------------------------------
void TDMUserSetupImpl::SaveSetupBool(AnsiString form_name,AnsiString name_setup, bool value)
{
return Object->SaveSetupBool(form_name, name_setup,value);
}
//---------------------------------------------------------------
bool TDMUserSetupImpl::LoadSetupBool(AnsiString form_name, AnsiString name_setup)
{
return Object->LoadSetupBool(form_name,  name_setup);
}
//---------------------------------------------------------------
void TDMUserSetupImpl::SaveSetupInt(AnsiString form_name,AnsiString name_setup, int value)
{
return Object->SaveSetupInt(form_name,name_setup,value);
}
//---------------------------------------------------------------
int TDMUserSetupImpl::LoadSetupInt(AnsiString form_name, AnsiString name_setup)
{
return Object->LoadSetupInt(form_name, name_setup);
}
//---------------------------------------------------------------
void TDMUserSetupImpl::SaveSetupInt64(AnsiString form_name,AnsiString name_setup, __int64 value)
{
return Object->SaveSetupInt64(form_name,name_setup,value);
}
//---------------------------------------------------------------
__int64 TDMUserSetupImpl::LoadSetupInt64(AnsiString form_name, AnsiString name_setup)
{
return Object->LoadSetupInt64(form_name, name_setup);
}
//---------------------------------------------------------------
