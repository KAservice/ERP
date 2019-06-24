#include "vcl.h"
#pragma hdrstop


#include "UFormaUnReportImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaUnReportImpl::TFormaUnReportImpl()           
{                                            
Object=new TFormaUnReport(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaUnReportImpl::~TFormaUnReportImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaUnReportImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaUnReportImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IkasForm)
   {
   *ppv=static_cast<IkasForm*> (this);
   result=-1;
   }
else if (id_interface==IID_IkanCallBack) 
   {                                        
   *ppv=static_cast<IkanCallBack*> (this);  
   result=-1;                               
   }                                        
else if (id_interface==IID_IFormaUnReport)                        
   {                                                                     
   *ppv=static_cast<IFormaUnReport*> (this);
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
int TFormaUnReportImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaUnReportImpl::kanRelease(void)                                  
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
int  TFormaUnReportImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaUnReportImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaUnReportImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaUnReportImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaUnReportImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaUnReportImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaUnReportImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaUnReportImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------
   //IkasForm
void TFormaUnReportImpl::UpdateForm(void)
{
Object->UpdateForm();
}
//-----------------------------------------------------------------------
bool TFormaUnReportImpl::get_Vibor(void)
{
return Object->Vibor;
}
//----------------------------------------------------------------------
void TFormaUnReportImpl::set_Vibor(bool Vibor)  //форма открыта для выбора
{
Object->Vibor= Vibor;
}
//----------------------------------------------------------------------
int TFormaUnReportImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------------
void TFormaUnReportImpl::set_NumberProcVibor(int NumberProcVibor)  //какую процедуру использовать для обработки выбора во вн
{
Object->NumberProcVibor=NumberProcVibor;
}
//--------------------------------------------------------------------------
//IFormaUnReport
IkasDM * TFormaUnReportImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TFormaUnReportImpl::set_DM(IkasDM * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
__int64 TFormaUnReportImpl::get_IdHw(void)
{
return Object->IdHw;
}
//---------------------------------------------------------------
void TFormaUnReportImpl::set_IdHw(__int64 IdHw)
{
Object->IdHw=IdHw;
}
//---------------------------------------------------------------
UnicodeString TFormaUnReportImpl::get_NameHardware(void)
{
return Object->NameHardware;
}
//---------------------------------------------------------------
void TFormaUnReportImpl::set_NameHardware(UnicodeString NameHardware)
{
Object->NameHardware=NameHardware;
}
//---------------------------------------------------------------
