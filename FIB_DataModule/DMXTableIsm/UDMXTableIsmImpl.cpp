#include "vcl.h"
#pragma hdrstop


#include "UDMXTableIsmImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMXTableIsmImpl::TDMXTableIsmImpl()           
{                                            
Object=new TDMXTableIsm(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMXTableIsmImpl::~TDMXTableIsmImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMXTableIsmImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMXTableIsmImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMXTableIsm)                        
   {                                                                     
   *ppv=static_cast<IDMXTableIsm*> (this);                                
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
int TDMXTableIsmImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMXTableIsmImpl::kanRelease(void)                                  
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
int  TDMXTableIsmImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMXTableIsmImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMXTableIsmImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMXTableIsmImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMXTableIsmImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMXTableIsmImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMXTableIsmImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMXTableIsm
__int64 TDMXTableIsmImpl::get_Id(void)
{
return Object->Id;
}
//---------------------------------------------------------------
void TDMXTableIsmImpl::set_Id(__int64 Id)
{
Object->Id=Id;
}
//---------------------------------------------------------------
void TDMXTableIsmImpl::OpenTable(__int64 id_max)
{
return Object->OpenTable(id_max);
}
//---------------------------------------------------------------
int TDMXTableIsmImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMXTableIsmImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
void TDMXTableIsmImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMXTableIsmImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMXTableIsmImpl::GetMaxID(void)
{
return Object->GetMaxID();
}
//---------------------------------------------------------------
