#include "vcl.h"
#pragma hdrstop


#include "UART_FormaSpiskaSprInfBlockSostavImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_FormaSpiskaSprInfBlockSostavImpl::TART_FormaSpiskaSprInfBlockSostavImpl()           
{                                            
Object=new TART_FormaSpiskaSprInfBlockSostav(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_FormaSpiskaSprInfBlockSostavImpl::~TART_FormaSpiskaSprInfBlockSostavImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_FormaSpiskaSprInfBlockSostavImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_FormaSpiskaSprInfBlockSostavImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_FormaSpiskaSprInfBlockSostav)                        
   {                                                                     
   *ppv=static_cast<IART_FormaSpiskaSprInfBlockSostav*> (this);                                
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
int TART_FormaSpiskaSprInfBlockSostavImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_FormaSpiskaSprInfBlockSostavImpl::kanRelease(void)                                  
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
int  TART_FormaSpiskaSprInfBlockSostavImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_FormaSpiskaSprInfBlockSostavImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_FormaSpiskaSprInfBlockSostavImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_FormaSpiskaSprInfBlockSostavImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_FormaSpiskaSprInfBlockSostavImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_FormaSpiskaSprInfBlockSostavImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_FormaSpiskaSprInfBlockSostavImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TART_FormaSpiskaSprInfBlockSostavImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //��������� �� �������� ������ 
									id_object,      //��� ��������� �������  
									type_event,     //��� ������� � �������� ������� 
									number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������ 
									); 
}   
//---------------------------------------------------------------

//IART_FormaSpiskaSprInfBlockSostav
IART_DMSprInfBlockSostav * TART_FormaSpiskaSprInfBlockSostavImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprInfBlockSostavImpl::set_DM(IART_DMSprInfBlockSostav * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
bool TART_FormaSpiskaSprInfBlockSostavImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprInfBlockSostavImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TART_FormaSpiskaSprInfBlockSostavImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprInfBlockSostavImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
__int64 TART_FormaSpiskaSprInfBlockSostavImpl::get_IdPage(void)
{
return Object->IdPage;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprInfBlockSostavImpl::set_IdPage(__int64 IdPage)
{
Object->IdPage=IdPage;
}
//---------------------------------------------------------------
UnicodeString TART_FormaSpiskaSprInfBlockSostavImpl::get_HeaderText(void)
{
return Object->HeaderText;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprInfBlockSostavImpl::set_HeaderText(UnicodeString HeaderText)
{
Object->HeaderText=HeaderText;
}
//---------------------------------------------------------------
void TART_FormaSpiskaSprInfBlockSostavImpl::UpdateForm()
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
