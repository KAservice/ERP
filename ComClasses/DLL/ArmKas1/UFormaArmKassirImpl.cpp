#include "vcl.h"
#pragma hdrstop


#include "UFormaArmKassirImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaArmKassirImpl::TFormaArmKassirImpl()           
{                                            
Object=new TFormaARMKassir(Application);
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaArmKassirImpl::~TFormaArmKassirImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaArmKassirImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaArmKassirImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IAsyncExternalEvent)
   {
   *ppv=static_cast<IAsyncExternalEvent*> (this);
   result=-1;
   }
else if (id_interface==IID_IFormaArmKassir)                        
   {                                                                     
   *ppv=static_cast<IFormaArmKassir*> (this);                                
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
int TFormaArmKassirImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaArmKassirImpl::kanRelease(void)                                  
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
int  TFormaArmKassirImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaArmKassirImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaArmKassirImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TFormaArmKassirImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaArmKassirImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaArmKassirImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------
//IAcyncExternalEvent
int TFormaArmKassirImpl::AsyncExternalEvent(char * object, char* event, char* data)
{
AnsiString ansi_object=object;
AnsiString ansi_event=event;
AnsiString ansi_data=data;

if (Trim(ansi_object)=="scaner")
	{
	Object->ReadShtrihCodEvent(0,ansi_data);
	}
return -1;
}
//-----------------------------------------------------------------
int TFormaArmKassirImpl::SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form)
{

return -1;
}
//------------------------------------------------------------------
//IFormaArmKassir
IDMDocCheck * TFormaArmKassirImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_DM(IDMDocCheck * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
__int64 TFormaArmKassirImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TFormaArmKassirImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TFormaArmKassirImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
__int64 TFormaArmKassirImpl::get_VibTovarId(void)
{
return Object->VibTovarId;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_VibTovarId(__int64 VibTovarId)
{
Object->VibTovarId=VibTovarId;
}
//---------------------------------------------------------------
__int64 TFormaArmKassirImpl::get_VibTovarIdGrp(void)
{
return Object->VibTovarIdGrp;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_VibTovarIdGrp(__int64 VibTovarIdGrp)
{
Object->VibTovarIdGrp=VibTovarIdGrp;
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::get_OutReady(void)
{
return Object->OutReady;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_OutReady(bool OutReady)
{
Object->OutReady=OutReady;
}
//---------------------------------------------------------------
__int64 TFormaArmKassirImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
AnsiString TFormaArmKassirImpl::get_NameTypePrice(void)
{
return Object->NameTypePrice;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_NameTypePrice(AnsiString NameTypePrice)
{
Object->NameTypePrice=NameTypePrice;
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::get_CheckSave(void)
{
return Object->CheckSave;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_CheckSave(bool CheckSave)
{
Object->CheckSave=CheckSave;
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::get_CheckPrint(void)
{
return Object->CheckPrint;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_CheckPrint(bool CheckPrint)
{
Object->CheckPrint=CheckPrint;
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::get_CheckProveden(void)
{
return Object->CheckProveden;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_CheckProveden(bool CheckProveden)
{
Object->CheckProveden=CheckProveden;
}
//---------------------------------------------------------------
String TFormaArmKassirImpl::get_StrPrint(void)
{
return Object->StrPrint;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_StrPrint(String StrPrint)
{
Object->StrPrint=StrPrint;
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::get_CheckCreate(void)
{
return Object->CheckCreate;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_CheckCreate(bool CheckCreate)
{
Object->CheckCreate=CheckCreate;
}
//---------------------------------------------------------------
__int64 TFormaArmKassirImpl::get_IdARM(void)
{
return Object->IdARM;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_IdARM(__int64 IdARM)
{
Object->IdARM=IdARM;
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::get_ExternalCreateCheck(void)
{
return Object->ExternalCreateCheck;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_ExternalCreateCheck(bool ExternalCreateCheck)
{
Object->ExternalCreateCheck=ExternalCreateCheck;
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::get_NoOtrOstatok(void)
{
return Object->NoOtrOstatok;
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::set_NoOtrOstatok(bool NoOtrOstatok)
{
Object->NoOtrOstatok=NoOtrOstatok;
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::BeforeEditCheck(void)
{
return Object->BeforeEditCheck();
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::BeforeCreateNewCheck(void)
{
return Object->BeforeCreateNewCheck();
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::CreateNewDocCheck(void)
{
return Object->CreateNewDocCheck();
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::CreateNewDocCheckVosvrat(void)
{
return Object->CreateNewDocCheckVosvrat();
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::PrintCheck(bool povtor)
{
return Object->PrintCheck(povtor);
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::SaveCheck(void)
{
return Object->SaveCheck();
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::UpdateSetup(void)
{
return Object->UpdateSetup();
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::UpdateParameterFR(void)
{
return Object->UpdateParameterFR();
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::PrintDocCheck(void)
{
return Object->PrintDocCheck();
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::UpdateValuesDiscount(void)
{
return Object->UpdateValuesDiscount();
}
//---------------------------------------------------------------
void TFormaArmKassirImpl::ValidateOstatok(double treb_kol)
{
return Object->ValidateOstatok(treb_kol);
}
//---------------------------------------------------------------
bool TFormaArmKassirImpl::CreateCheckNaOsnRealRemont(__int64 id_doc_real_remont)
{
return Object->CreateCheckNaOsnRealRemont(id_doc_real_remont);
}
//---------------------------------------------------------------
