#include "vcl.h"
#pragma hdrstop


#include "UFormaElementaSprDepartmentImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaElementaSprDepartmentImpl::TFormaElementaSprDepartmentImpl()
{                                            
Object=new TFormaElementaSprDepartment(Application);
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaElementaSprDepartmentImpl::~TFormaElementaSprDepartmentImpl()
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::DeleteImpl(void)
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaElementaSprDepartmentImpl::kanQueryInterface(REFIID id_interface, void ** ppv)
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
int TFormaElementaSprDepartmentImpl::kanAddRef(void)
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaElementaSprDepartmentImpl::kanRelease(void)
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
int  TFormaElementaSprDepartmentImpl::get_CodeError(void)
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_CodeError(int CodeError)
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaElementaSprDepartmentImpl::get_TextError(void)
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_TextError(UnicodeString  TextError)
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaElementaSprDepartmentImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaElementaSprDepartmentImpl;
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaElementaSprDepartmentImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaElementaSprDepartmentImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

   //IkasForm
void TFormaElementaSprDepartmentImpl::UpdateForm(void)
{

Object->UpdateForm();
}
//---------------------------------------------------------------
bool TFormaElementaSprDepartmentImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_Vibor(bool Vibor)  //форма открыта для выбора
{
Object->Vibor=Vibor;
}
//-------------------------------------------------------------
int TFormaElementaSprDepartmentImpl::get_NumberProcVibor(void)
{

return Object->NumberProcVibor;
}
//--------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_NumberProcVibor(int NumberProcVibor)  //какую процедуру использовать для обработки выбора во внешней форме
{
Object->NumberProcVibor=NumberProcVibor;
}
//-----------------------------------------------------------------



   //IkasFormSpr
__int64 TFormaElementaSprDepartmentImpl::get_IdGroupEl1(void)
{

return Object->IdGroupEl1;
}
//-------------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_IdGroupEl1(__int64 IdGroupEl1)
{
Object->IdGroupEl1=IdGroupEl1;
}
//-------------------------------------------------------------------
UnicodeString TFormaElementaSprDepartmentImpl::get_NameGroupEl1(void)
{

return Object->NameGroupEl1;
}
//-------------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_NameGroupEl1(UnicodeString NameGroupEl1)
{
Object->NameGroupEl1=NameGroupEl1;
}
//-----------------------------------------------------------------

__int64 TFormaElementaSprDepartmentImpl::get_IdGroupEl2(void)
{
return Object->IdGroupEl2;
}
//--------------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_IdGroupEl2(__int64 IdGroupEl2)
{
Object->IdGroupEl2=IdGroupEl2;
}
//-------------------------------------------------------------------
UnicodeString TFormaElementaSprDepartmentImpl::get_NameGroupEl2(void)
{
return Object->NameGroupEl2;
}
//---------------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_NameGroupEl2(UnicodeString NameGroupEl2)
{
Object->NameGroupEl2=NameGroupEl2;
}
//------------------------------------------------------------------

__int64 TFormaElementaSprDepartmentImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//------------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//-------------------------------------------------------------------
UnicodeString TFormaElementaSprDepartmentImpl::get_NameOwner(void)
{
return Object->NameOwner;
}
//----------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_NameOwner(UnicodeString NameOwner)
{
Object->NameOwner=NameOwner;
}
//-----------------------------------------------------------------

__int64 TFormaElementaSprDepartmentImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_IdGrp(__int64 IdGrp)
{

Object->IdGrp=IdGrp;
}
//-----------------------------------------------------------------
UnicodeString TFormaElementaSprDepartmentImpl::get_NameGrp(void)
{
return Object->NameGrp;
}
//-----------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_NameGrp(UnicodeString NameGrp)
{
Object->NameGrp=NameGrp;
}
//----------------------------------------------------------------

__int64 TFormaElementaSprDepartmentImpl::get_IdEl(void)
{
return Object->IdEl;
}
//----------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_IdEl(__int64 IdEl)
{
Object->IdEl=IdEl;
}
//----------------------------------------------------------------
UnicodeString TFormaElementaSprDepartmentImpl::get_NameEl(void)
{
return Object->NameEl;
}
//-----------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_NameEl(UnicodeString IdEl)
{
Object->NameEl=NameEl;
}
//------------------------------------------------------------------

bool TFormaElementaSprDepartmentImpl::get_All(void)
{
return Object->All;
}
//-------------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_All(bool All)
{
Object->All=All;
}
//-------------------------------------------------------------------


IkasDMSpr * TFormaElementaSprDepartmentImpl::get_DM(void)
{

return Object->DM;
}
//-------------------------------------------------------------------
void TFormaElementaSprDepartmentImpl::set_DM(IkasDMSpr * DM)
{
Object->DM=DM;
}
//------------------------------------------------------------------
