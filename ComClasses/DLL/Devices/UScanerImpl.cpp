#include "vcl.h"
#pragma hdrstop


#include "UScanerImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TScanerImpl::TScanerImpl()           
{                                            
Object=new TScaner();

NumRefs=0;                                   
++NumObject;                                 

}                                            
//---------------------------------------------------------------
TScanerImpl::~TScanerImpl()          
{                                            

	delete Object;                              

--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TScanerImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TScanerImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IScaner)                        
   {                                                                     
   *ppv=static_cast<IScaner*> (this);                                
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
int TScanerImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TScanerImpl::kanRelease(void)                                  
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
int  TScanerImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TScanerImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TScanerImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TScanerImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TScanerImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TScanerImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TScanerImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IScaner
int TScanerImpl::get_Number(void)
{
return Object->Number;
}
//---------------------------------------------------------------
void TScanerImpl::set_Number(int Number)
{
Object->Number=Number;
}
//---------------------------------------------------------------
AnsiString TScanerImpl::get_Modul(void)
{
return Object->Modul;
}
//---------------------------------------------------------------
void TScanerImpl::set_Modul(AnsiString Modul)
{
Object->Modul=Modul;
}
//---------------------------------------------------------------
UnicodeString TScanerImpl::get_NameScaner(void)
{
return Object->NameScaner;
}
//---------------------------------------------------------------
void TScanerImpl::set_NameScaner(UnicodeString NameScaner)
{
Object->NameScaner=NameScaner;
}
//---------------------------------------------------------------
bool TScanerImpl::get_ConnectScaner(void)
{
return Object->ConnectScaner;
}
//---------------------------------------------------------------
void TScanerImpl::set_ConnectScaner(bool ConnectScaner)
{
Object->ConnectScaner=ConnectScaner;
}
//---------------------------------------------------------------
bool TScanerImpl::InitDevice()
{
return Object->InitDevice();
}
//---------------------------------------------------------------
UnicodeString TScanerImpl::ReadShtrihCod(void)
{
return Object->ReadShtrihCod();
}
//---------------------------------------------------------------
bool TScanerImpl::Connect(UnicodeString port ,UnicodeString baud_rate)
{
return Object->Connect(port ,baud_rate);
}
//---------------------------------------------------------------
void TScanerImpl::Disconnect(void)
{
return Object->Disconnect();
}
//---------------------------------------------------------------
UnicodeString TScanerImpl::GetTextError(void)
{
return Object->GetTextError();
}
//---------------------------------------------------------------
