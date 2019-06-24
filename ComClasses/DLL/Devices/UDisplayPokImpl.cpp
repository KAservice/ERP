#include "vcl.h"
#pragma hdrstop


#include "UDisplayPokImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDisplayPokImpl::TDisplayPokImpl()           
{                                            
Object=new TDisplayPok();
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDisplayPokImpl::~TDisplayPokImpl()          
{                                            

	delete Object;                              

--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDisplayPokImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDisplayPokImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDisplayPok)                        
   {                                                                     
   *ppv=static_cast<IDisplayPok*> (this);                                
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
int TDisplayPokImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDisplayPokImpl::kanRelease(void)                                  
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
int  TDisplayPokImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDisplayPokImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDisplayPokImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDisplayPokImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDisplayPokImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDisplayPokImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDisplayPokImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDisplayPok
AnsiString TDisplayPokImpl::get_Modul(void)
{
return Object->Modul;
}
//---------------------------------------------------------------
void TDisplayPokImpl::set_Modul(AnsiString Modul)
{
Object->Modul=Modul;
}
//---------------------------------------------------------------
bool TDisplayPokImpl::InitDevice()
{
return Object->InitDevice();
}
//---------------------------------------------------------------
bool TDisplayPokImpl::Connect(int port, int baud_rate)
{
return Object->Connect(port,baud_rate);
}
//---------------------------------------------------------------
void TDisplayPokImpl::Disconnect(void)
{
return Object->Disconnect();
}
//---------------------------------------------------------------
bool TDisplayPokImpl::ShowString1(UnicodeString str, int size_font,int style_font,int alignment)
{
return Object->ShowString1(str,size_font,style_font,alignment);
}
//---------------------------------------------------------------
bool TDisplayPokImpl::ShowString2(UnicodeString str, int size_font,int style_font,int alignment)
{
return Object->ShowString2(str,size_font,style_font,alignment);
}
//---------------------------------------------------------------
bool TDisplayPokImpl::ShowText(UnicodeString str, int size_font,	int style_font,	int alignment, bool word_wrap)
{
return Object->ShowText(str, size_font,style_font,alignment,word_wrap);
}
//---------------------------------------------------------------
