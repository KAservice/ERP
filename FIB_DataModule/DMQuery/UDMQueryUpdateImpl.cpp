#include "vcl.h"
#pragma hdrstop


#include "UDMQueryUpdateImpl.h"

#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMQueryUpdateImpl::TDMQueryUpdateImpl()           
{                                            
Object=new TDMQueryUpdate(Application);
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMQueryUpdateImpl::~TDMQueryUpdateImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMQueryUpdateImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMQueryUpdateImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMQueryUpdate)                        
   {                                                                     
   *ppv=static_cast<IDMQueryUpdate*> (this);                                
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
int TDMQueryUpdateImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMQueryUpdateImpl::kanRelease(void)                                  
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
int  TDMQueryUpdateImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMQueryUpdateImpl::set_CodeError(int CodeError)
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMQueryUpdateImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMQueryUpdateImpl::set_TextError(UnicodeString  TextError)
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMQueryUpdateImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMQueryUpdateImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TpFIBQuery * TDMQueryUpdateImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMQueryUpdateImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMQueryUpdateImpl::get_pFIBTr(void)
{
return Object->pFIBTr;
}
//---------------------------------------------------------------
void TDMQueryUpdateImpl::set_pFIBTr(TpFIBTransaction * pFIBTr)
{
Object->pFIBTr=pFIBTr;
}
//---------------------------------------------------------------
