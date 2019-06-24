#include "vcl.h"
#pragma hdrstop


#include "UREM_FormaGurAllDocImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_FormaGurAllDocImpl::TREM_FormaGurAllDocImpl()           
{                                            
Object=new TREM_FormaGurAllDoc(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_FormaGurAllDocImpl::~TREM_FormaGurAllDocImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_FormaGurAllDocImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_FormaGurAllDoc)                        
   {                                                                     
   *ppv=static_cast<IREM_FormaGurAllDoc*> (this);                                
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
int TREM_FormaGurAllDocImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_FormaGurAllDocImpl::kanRelease(void)                                  
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
int  TREM_FormaGurAllDocImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_FormaGurAllDocImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_FormaGurAllDocImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_FormaGurAllDocImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_FormaGurAllDocImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TREM_FormaGurAllDocImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IREM_FormaGurAllDoc
bool TREM_FormaGurAllDocImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TREM_FormaGurAllDocImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IREM_DMGurAllDoc * TREM_FormaGurAllDocImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_DM(IREM_DMGurAllDoc * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
__int64 TREM_FormaGurAllDocImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TREM_FormaGurAllDocImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TREM_FormaGurAllDocImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 TREM_FormaGurAllDocImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_NameKlient(void)
{
return Object->NameKlient;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_NameKlient(UnicodeString NameKlient)
{
Object->NameKlient=NameKlient;
}
//---------------------------------------------------------------
__int64 TREM_FormaGurAllDocImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_NameSklad(void)
{
return Object->NameSklad;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_NameSklad(UnicodeString NameSklad)
{
Object->NameSklad=NameSklad;
}
//---------------------------------------------------------------
__int64 TREM_FormaGurAllDocImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_NameFirm(void)
{
return Object->NameFirm;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_NameFirm(UnicodeString NameFirm)
{
Object->NameFirm=NameFirm;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_StringTypeDoc(void)
{
return Object->StringTypeDoc;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_StringTypeDoc(UnicodeString StringTypeDoc)
{
Object->StringTypeDoc=StringTypeDoc;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_NameTypeDoc(void)
{
return Object->NameTypeDoc;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_NameTypeDoc(UnicodeString NameTypeDoc)
{
Object->NameTypeDoc=NameTypeDoc;
}
//---------------------------------------------------------------
bool TREM_FormaGurAllDocImpl::get_OtborPoKlientu(void)
{
return Object->OtborPoKlientu;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_OtborPoKlientu(bool OtborPoKlientu)
{
Object->OtborPoKlientu=OtborPoKlientu;
}
//---------------------------------------------------------------
bool TREM_FormaGurAllDocImpl::get_OtborPoFirm(void)
{
return Object->OtborPoFirm;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_OtborPoFirm(bool OtborPoFirm)
{
Object->OtborPoFirm=OtborPoFirm;
}
//---------------------------------------------------------------
bool TREM_FormaGurAllDocImpl::get_OtborPoSklad(void)
{
return Object->OtborPoSklad;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_OtborPoSklad(bool OtborPoSklad)
{
Object->OtborPoSklad=OtborPoSklad;
}
//---------------------------------------------------------------
bool TREM_FormaGurAllDocImpl::get_OtborPoTypeDoc(void)
{
return Object->OtborPoTypeDoc;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_OtborPoTypeDoc(bool OtborPoTypeDoc)
{
Object->OtborPoTypeDoc=OtborPoTypeDoc;
}
//---------------------------------------------------------------
__int64 TREM_FormaGurAllDocImpl::get_IdVibHardware(void)
{
return Object->IdVibHardware;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_IdVibHardware(__int64 IdVibHardware)
{
Object->IdVibHardware=IdVibHardware;
}
//---------------------------------------------------------------
__int64 TREM_FormaGurAllDocImpl::get_IdVibZayavka(void)
{
return Object->IdVibZayavka;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_IdVibZayavka(__int64 IdVibZayavka)
{
Object->IdVibZayavka=IdVibZayavka;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_Zayavka_NameKlient(void)
{
return Object->Zayavka_NameKlient;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_Zayavka_NameKlient(UnicodeString Zayavka_NameKlient)
{
Object->Zayavka_NameKlient=Zayavka_NameKlient;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_Zayavka_NameModel(void)
{
return Object->Zayavka_NameModel;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_Zayavka_NameModel(UnicodeString Zayavka_NameModel)
{
Object->Zayavka_NameModel=Zayavka_NameModel;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_Zayavka_SerNum(void)
{
return Object->Zayavka_SerNum;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_Zayavka_SerNum(UnicodeString Zayavka_SerNum)
{
Object->Zayavka_SerNum=Zayavka_SerNum;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_Zayavka_SerNum2(void)
{
return Object->Zayavka_SerNum2;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_Zayavka_SerNum2(UnicodeString Zayavka_SerNum2)
{
Object->Zayavka_SerNum2=Zayavka_SerNum2;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_Zayavka_Name(void)
{
return Object->Zayavka_Name;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_Zayavka_Name(UnicodeString Zayavka_Name)
{
Object->Zayavka_Name=Zayavka_Name;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_Hardware_NameModel(void)
{
return Object->Hardware_NameModel;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_Hardware_NameModel(UnicodeString Hardware_NameModel)
{
Object->Hardware_NameModel=Hardware_NameModel;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_Hardware_SerNum(void)
{
return Object->Hardware_SerNum;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_Hardware_SerNum(UnicodeString Hardware_SerNum)
{
Object->Hardware_SerNum=Hardware_SerNum;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_Hardware_SerNum2(void)
{
return Object->Hardware_SerNum2;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_Hardware_SerNum2(UnicodeString Hardware_SerNum2)
{
Object->Hardware_SerNum2=Hardware_SerNum2;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaGurAllDocImpl::get_Hardware_Name(void)
{
return Object->Hardware_Name;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::set_Hardware_Name(UnicodeString Hardware_Name)
{
Object->Hardware_Name=Hardware_Name;
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
void TREM_FormaGurAllDocImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
