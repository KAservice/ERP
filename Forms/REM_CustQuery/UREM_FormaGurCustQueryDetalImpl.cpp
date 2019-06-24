#include "vcl.h"
#pragma hdrstop


#include "UREM_FormaGurCustQueryDetalImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_FormaGurCustQueryDetalImpl::TREM_FormaGurCustQueryDetalImpl()           
{                                            
Object=new TREM_FormaGurCustQueryDetal(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_FormaGurCustQueryDetalImpl::~TREM_FormaGurCustQueryDetalImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_FormaGurCustQueryDetalImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_FormaGurCustQueryDetal)                        
   {                                                                     
   *ppv=static_cast<IREM_FormaGurCustQueryDetal*> (this);                                
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
int TREM_FormaGurCustQueryDetalImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_FormaGurCustQueryDetalImpl::kanRelease(void)                                  
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
int  TREM_FormaGurCustQueryDetalImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_FormaGurCustQueryDetalImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_FormaGurCustQueryDetalImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_FormaGurCustQueryDetalImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_FormaGurCustQueryDetalImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TREM_FormaGurCustQueryDetalImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IREM_FormaGurCustQueryDetal
bool TREM_FormaGurCustQueryDetalImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TREM_FormaGurCustQueryDetalImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IREM_DMGurCustQueryDetal * TREM_FormaGurCustQueryDetalImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_DM(IREM_DMGurCustQueryDetal * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
__int64 TREM_FormaGurCustQueryDetalImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TREM_FormaGurCustQueryDetalImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TREM_FormaGurCustQueryDetalImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 TREM_FormaGurCustQueryDetalImpl::get_IdVibZayavka(void)
{
return Object->IdVibZayavka;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_IdVibZayavka(__int64 IdVibZayavka)
{
Object->IdVibZayavka=IdVibZayavka;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurCustQueryDetalImpl::get_Zayavka_NameKlient(void)
{
return Object->Zayavka_NameKlient;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_Zayavka_NameKlient(UnicodeString Zayavka_NameKlient)
{
Object->Zayavka_NameKlient=Zayavka_NameKlient;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurCustQueryDetalImpl::get_Zayavka_NameModel(void)
{
return Object->Zayavka_NameModel;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_Zayavka_NameModel(UnicodeString Zayavka_NameModel)
{
Object->Zayavka_NameModel=Zayavka_NameModel;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurCustQueryDetalImpl::get_Zayavka_SerNum(void)
{
return Object->Zayavka_SerNum;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_Zayavka_SerNum(UnicodeString Zayavka_SerNum)
{
Object->Zayavka_SerNum=Zayavka_SerNum;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurCustQueryDetalImpl::get_Zayavka_SerNum2(void)
{
return Object->Zayavka_SerNum2;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_Zayavka_SerNum2(UnicodeString Zayavka_SerNum2)
{
Object->Zayavka_SerNum2=Zayavka_SerNum2;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurCustQueryDetalImpl::get_Zayavka_Name(void)
{
return Object->Zayavka_Name;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::set_Zayavka_Name(UnicodeString Zayavka_Name)
{
Object->Zayavka_Name=Zayavka_Name;
}
//---------------------------------------------------------------
void TREM_FormaGurCustQueryDetalImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
