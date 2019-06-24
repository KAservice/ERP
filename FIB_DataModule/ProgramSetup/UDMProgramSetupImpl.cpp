#include "vcl.h"
#pragma hdrstop


#include "UDMProgramSetupImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMProgramSetupImpl::TDMProgramSetupImpl()           
{                                            
Object=new TDMProgramSetup(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMProgramSetupImpl::~TDMProgramSetupImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMProgramSetupImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMProgramSetupImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMProgramSetup)                        
   {                                                                     
   *ppv=static_cast<IDMProgramSetup*> (this);                                
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
int TDMProgramSetupImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMProgramSetupImpl::kanRelease(void)                                  
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
int  TDMProgramSetupImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMProgramSetupImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMProgramSetupImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMProgramSetupImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMProgramSetupImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
//kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
//Object->ClsIdImpl=CLSID_TDMProgramSetupImpl;
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMProgramSetupImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMProgramSetup
void TDMProgramSetupImpl::SaveSetup(UnicodeString group_name,UnicodeString name_setup, UnicodeString value)
{
return Object->SaveSetup(group_name,name_setup,value);
}
//---------------------------------------------------------------
UnicodeString TDMProgramSetupImpl::LoadSetup(UnicodeString group_name, UnicodeString name_setup)
{
return Object->LoadSetup(group_name,name_setup);
}
//---------------------------------------------------------------
void TDMProgramSetupImpl::SaveSetupBool(UnicodeString group_name,UnicodeString name_setup, bool value)
{
return Object->SaveSetupBool(group_name,name_setup,value);
}
//---------------------------------------------------------------
bool TDMProgramSetupImpl::LoadSetupBool(UnicodeString group_name, UnicodeString name_setup)
{
return Object->LoadSetupBool(group_name,name_setup);
}
//---------------------------------------------------------------
void TDMProgramSetupImpl::SaveSetupInt(UnicodeString group_name,UnicodeString name_setup, int value)
{
return Object->SaveSetupInt(group_name,name_setup,value);
}
//---------------------------------------------------------------
int TDMProgramSetupImpl::LoadSetupInt(UnicodeString group_name, UnicodeString name_setup)
{
return Object->LoadSetupInt(group_name,name_setup);
}
//---------------------------------------------------------------
void TDMProgramSetupImpl::SaveSetupInt64(UnicodeString group_name,UnicodeString name_setup, __int64 value)
{
return Object->SaveSetupInt64(group_name,name_setup,value);
}
//---------------------------------------------------------------
__int64 TDMProgramSetupImpl::LoadSetupInt64(UnicodeString group_name, UnicodeString name_setup)
{
return Object->LoadSetupInt64(group_name,name_setup);
}
//---------------------------------------------------------------
