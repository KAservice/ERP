#include "vcl.h"
#pragma hdrstop


#include "UFormaSpiskaSprDepartmentImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaSpiskaSprDepartmentImpl::TFormaSpiskaSprDepartmentImpl()
{                                            
Object=new TFormaSpiskaSprDepartment(Application);
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaSpiskaSprDepartmentImpl::~TFormaSpiskaSprDepartmentImpl()
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::DeleteImpl(void)
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaSpiskaSprDepartmentImpl::kanQueryInterface(REFIID id_interface, void ** ppv)
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
else if (id_interface==IID_IkasForm)
   {
   *ppv=static_cast<IkasForm*> (this);
   result=-1;
   }
else if (id_interface==IID_IkasFormSpr)
   {
   *ppv=static_cast<IkasFormSpr*> (this);
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
int TFormaSpiskaSprDepartmentImpl::kanAddRef(void)
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaSpiskaSprDepartmentImpl::kanRelease(void)
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
int  TFormaSpiskaSprDepartmentImpl::get_CodeError(void)
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_CodeError(int CodeError)
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaSpiskaSprDepartmentImpl::get_TextError(void)
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_TextError(UnicodeString  TextError)
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaSprDepartmentImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaSpiskaSprDepartmentImpl;
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaSprDepartmentImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaSpiskaSprDepartmentImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

   //IkasForm
void TFormaSpiskaSprDepartmentImpl::UpdateForm(void)
{

Object->UpdateForm();
}
//---------------------------------------------------------------
bool TFormaSpiskaSprDepartmentImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_Vibor(bool Vibor)  //форма открыта для выбора
{
Object->Vibor=Vibor;
}
//-------------------------------------------------------------
int TFormaSpiskaSprDepartmentImpl::get_NumberProcVibor(void)
{

return Object->NumberProcVibor;
}
//--------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_NumberProcVibor(int NumberProcVibor)  //какую процедуру использовать для обработки выбора во внешней форме
{
Object->NumberProcVibor=NumberProcVibor;
}
//-----------------------------------------------------------------



   //IkasFormSpr
__int64 TFormaSpiskaSprDepartmentImpl::get_IdGroupEl1(void)
{

return Object->IdGroupEl1;
}
//-------------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_IdGroupEl1(__int64 IdGroupEl1)
{
Object->IdGroupEl1=IdGroupEl1;
}
//-------------------------------------------------------------------
UnicodeString TFormaSpiskaSprDepartmentImpl::get_NameGroupEl1(void)
{

return Object->NameGroupEl1;
}
//-------------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_NameGroupEl1(UnicodeString NameGroupEl1)
{
Object->NameGroupEl1=NameGroupEl1;
}
//-----------------------------------------------------------------

__int64 TFormaSpiskaSprDepartmentImpl::get_IdGroupEl2(void)
{
return Object->IdGroupEl2;
}
//--------------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_IdGroupEl2(__int64 IdGroupEl2)
{
Object->IdGroupEl2=IdGroupEl2;
}
//-------------------------------------------------------------------
UnicodeString TFormaSpiskaSprDepartmentImpl::get_NameGroupEl2(void)
{
return Object->NameGroupEl2;
}
//---------------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_NameGroupEl2(UnicodeString NameGroupEl2)
{
Object->NameGroupEl2=NameGroupEl2;
}
//------------------------------------------------------------------

__int64 TFormaSpiskaSprDepartmentImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//------------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//-------------------------------------------------------------------
UnicodeString TFormaSpiskaSprDepartmentImpl::get_NameOwner(void)
{
return Object->NameOwner;
}
//----------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_NameOwner(UnicodeString NameOwner)
{
Object->NameOwner=NameOwner;
}
//-----------------------------------------------------------------

__int64 TFormaSpiskaSprDepartmentImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_IdGrp(__int64 IdGrp)
{

Object->IdGrp=IdGrp;
}
//-----------------------------------------------------------------
UnicodeString TFormaSpiskaSprDepartmentImpl::get_NameGrp(void)
{
return Object->NameGrp;
}
//-----------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_NameGrp(UnicodeString NameGrp)
{
Object->NameGrp=NameGrp;
}
//----------------------------------------------------------------

__int64 TFormaSpiskaSprDepartmentImpl::get_IdEl(void)
{
return Object->IdEl;
}
//----------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_IdEl(__int64 IdEl)
{
Object->IdEl=IdEl;
}
//----------------------------------------------------------------
UnicodeString TFormaSpiskaSprDepartmentImpl::get_NameEl(void)
{
return Object->NameEl;
}
//-----------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_NameEl(UnicodeString IdEl)
{
Object->NameEl=NameEl;
}
//------------------------------------------------------------------

bool TFormaSpiskaSprDepartmentImpl::get_All(void)
{
return Object->All;
}
//-------------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_All(bool All)
{
Object->All=All;
}
//-------------------------------------------------------------------


IkasDMSpr * TFormaSpiskaSprDepartmentImpl::get_DM(void)
{

return Object->DM;
}
//-------------------------------------------------------------------
void TFormaSpiskaSprDepartmentImpl::set_DM(IkasDMSpr * DM)
{
Object->DM=DM;
}
//------------------------------------------------------------------
