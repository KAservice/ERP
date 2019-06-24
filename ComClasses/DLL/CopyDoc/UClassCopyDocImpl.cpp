#include "vcl.h"
#pragma hdrstop


#include "UClassCopyDocImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TClassCopyDocImpl::TClassCopyDocImpl()           
{                                            
Object=new TClassCopyDoc();
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TClassCopyDocImpl::~TClassCopyDocImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TClassCopyDocImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TClassCopyDocImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IClassCopyDoc)                        
   {                                                                     
   *ppv=static_cast<IClassCopyDoc*> (this);                                
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
int TClassCopyDocImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TClassCopyDocImpl::kanRelease(void)                                  
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
int  TClassCopyDocImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TClassCopyDocImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TClassCopyDocImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TClassCopyDocImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TClassCopyDocImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TClassCopyDocImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TClassCopyDocImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IClassCopyDoc
bool TClassCopyDocImpl::CreateNewCopyDoc(__int64 id_doc, UnicodeString type_doc, UnicodeString type_new_doc, bool fl_save_doc, bool fl_open_form_doc, int param1, int param2, int param3)
{
return Object->CreateNewCopyDoc(id_doc,type_doc,type_new_doc,fl_save_doc,fl_open_form_doc,param1,param2,param3);
}
//---------------------------------------------------------------
__int64 TClassCopyDocImpl::CreateNewDocNaOsn(__int64 id_doc, UnicodeString type_doc, UnicodeString type_new_doc,bool fl_save_doc, bool fl_open_form_doc,int param1, int param2, int param3)
{
return Object->CreateNewDocNaOsn(id_doc,type_doc,type_new_doc,fl_save_doc,fl_open_form_doc,param1,param2,param3);
}
//---------------------------------------------------------------
