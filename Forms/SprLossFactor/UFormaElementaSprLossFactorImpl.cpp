#include "vcl.h"
#pragma hdrstop


#include "UFormaElementaSprLossFactorImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaElementaSprLossFactorImpl::TFormaElementaSprLossFactorImpl()           
{                                            
Object=new TFormaElementaSprLossFactor(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaElementaSprLossFactorImpl::~TFormaElementaSprLossFactorImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaElementaSprLossFactorImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaElementaSprLossFactorImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaElementaSprLossFactor)                        
   {                                                                     
   *ppv=static_cast<IFormaElementaSprLossFactor*> (this);                                
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
int TFormaElementaSprLossFactorImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaElementaSprLossFactorImpl::kanRelease(void)                                  
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
int  TFormaElementaSprLossFactorImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaElementaSprLossFactorImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaElementaSprLossFactorImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaElementaSprLossFactorImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaElementaSprLossFactorImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaElementaSprLossFactorImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaElementaSprLossFactorImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaElementaSprLossFactorImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //��������� �� �������� ������ 
									id_object,      //��� ��������� �������  
									type_event,     //��� ������� � �������� ������� 
									number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������ 
									); 
}   
//---------------------------------------------------------------

//IFormaElementaSprLossFactor
IDMSprLossFactor * TFormaElementaSprLossFactorImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TFormaElementaSprLossFactorImpl::set_DM(IDMSprLossFactor * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
IDMSprLossFactorValue * TFormaElementaSprLossFactorImpl::get_DMSprLossFactorValue(void)
{
return Object->DMSprLossFactorValue;
}
//---------------------------------------------------------------
void TFormaElementaSprLossFactorImpl::set_DMSprLossFactorValue(IDMSprLossFactorValue * DMSprLossFactorValue)
{
Object->DMSprLossFactorValue=DMSprLossFactorValue;
}
//---------------------------------------------------------------
bool TFormaElementaSprLossFactorImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaElementaSprLossFactorImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaElementaSprLossFactorImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaElementaSprLossFactorImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
__int64 TFormaElementaSprLossFactorImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TFormaElementaSprLossFactorImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
UnicodeString TFormaElementaSprLossFactorImpl::get_NameGrp(void)
{
return Object->NameGrp;
}
//---------------------------------------------------------------
void TFormaElementaSprLossFactorImpl::set_NameGrp(UnicodeString NameGrp)
{
Object->NameGrp=NameGrp;
}
//---------------------------------------------------------------
void TFormaElementaSprLossFactorImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
