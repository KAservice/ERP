#include "vcl.h"
#pragma hdrstop


#include "UDMQueryReadImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMQueryReadImpl::TDMQueryReadImpl()           
{                                            
Object=new TDMQueryRead(Application);
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMQueryReadImpl::~TDMQueryReadImpl()          
{                                            
if (flDeleteObject==true)
	{
	Object->flDeleteImpl=false;
	delete Object;
	}
--NumObject;
}                                            
//---------------------------------------------------------------
void TDMQueryReadImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMQueryReadImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMQueryRead)
   {                                                                     
   *ppv=static_cast<IDMQueryRead*> (this);
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
int TDMQueryReadImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMQueryReadImpl::kanRelease(void)
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
int  TDMQueryReadImpl::get_CodeError(void)
{                                                              
return 0;                                                      
}                                                              
//---------------------------------------------------------------
void TDMQueryReadImpl::set_CodeError(int CodeError)
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMQueryReadImpl::get_TextError(void)
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMQueryReadImpl::set_TextError(UnicodeString  TextError)
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMQueryReadImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMQueryReadImpl::Done(void)
{                                                              
return -1;                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TpFIBQuery * TDMQueryReadImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMQueryReadImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMQueryReadImpl::get_pFIBTr(void)
{
return Object->pFIBTr;
}
//---------------------------------------------------------------
void TDMQueryReadImpl::set_pFIBTr(TpFIBTransaction * pFIBTr)
{
Object->pFIBTr=pFIBTr;
}
//---------------------------------------------------------------
TpFIBQuery * TDMQueryReadImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMQueryReadImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMQueryReadImpl::get_Transaction(void)
{
return Object->Transaction;
}
//---------------------------------------------------------------
void TDMQueryReadImpl::set_Transaction(TpFIBTransaction * Transaction)
{
Object->Transaction=Transaction;
}
//---------------------------------------------------------------
