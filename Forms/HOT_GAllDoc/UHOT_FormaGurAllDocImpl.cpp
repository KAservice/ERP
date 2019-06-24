#include "vcl.h"
#pragma hdrstop


#include "UHOT_FormaGurAllDocImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_FormaGurAllDocImpl::THOT_FormaGurAllDocImpl()           
{                                            
Object=new THOT_FormaGurAllDoc(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_FormaGurAllDocImpl::~THOT_FormaGurAllDocImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_FormaGurAllDocImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_FormaGurAllDoc)                        
   {                                                                     
   *ppv=static_cast<IHOT_FormaGurAllDoc*> (this);                                
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
int THOT_FormaGurAllDocImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_FormaGurAllDocImpl::kanRelease(void)                                  
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
int  THOT_FormaGurAllDocImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_FormaGurAllDocImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_FormaGurAllDocImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THOT_FormaGurAllDocImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_FormaGurAllDocImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int THOT_FormaGurAllDocImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IHOT_FormaGurAllDoc
bool THOT_FormaGurAllDocImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int THOT_FormaGurAllDocImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IHOT_DMGurAllDoc * THOT_FormaGurAllDocImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_DM(IHOT_DMGurAllDoc * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
__int64 THOT_FormaGurAllDocImpl::get_IdDocH(void)
{
return Object->IdDocH;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_IdDocH(__int64 IdDocH)
{
Object->IdDocH=IdDocH;
}
//---------------------------------------------------------------
TDateTime THOT_FormaGurAllDocImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime THOT_FormaGurAllDocImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 THOT_FormaGurAllDocImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
UnicodeString THOT_FormaGurAllDocImpl::get_NameKlient(void)
{
return Object->NameKlient;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_NameKlient(UnicodeString NameKlient)
{
Object->NameKlient=NameKlient;
}
//---------------------------------------------------------------
__int64 THOT_FormaGurAllDocImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
UnicodeString THOT_FormaGurAllDocImpl::get_NameSklad(void)
{
return Object->NameSklad;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_NameSklad(UnicodeString NameSklad)
{
Object->NameSklad=NameSklad;
}
//---------------------------------------------------------------
__int64 THOT_FormaGurAllDocImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
UnicodeString THOT_FormaGurAllDocImpl::get_NameFirm(void)
{
return Object->NameFirm;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_NameFirm(UnicodeString NameFirm)
{
Object->NameFirm=NameFirm;
}
//---------------------------------------------------------------
UnicodeString THOT_FormaGurAllDocImpl::get_StringTypeDoc(void)
{
return Object->StringTypeDoc;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_StringTypeDoc(UnicodeString StringTypeDoc)
{
Object->StringTypeDoc=StringTypeDoc;
}
//---------------------------------------------------------------
UnicodeString THOT_FormaGurAllDocImpl::get_NameTypeDoc(void)
{
return Object->NameTypeDoc;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_NameTypeDoc(UnicodeString NameTypeDoc)
{
Object->NameTypeDoc=NameTypeDoc;
}
//---------------------------------------------------------------
bool THOT_FormaGurAllDocImpl::get_OtborPoKlientu(void)
{
return Object->OtborPoKlientu;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_OtborPoKlientu(bool OtborPoKlientu)
{
Object->OtborPoKlientu=OtborPoKlientu;
}
//---------------------------------------------------------------
bool THOT_FormaGurAllDocImpl::get_OtborPoFirm(void)
{
return Object->OtborPoFirm;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_OtborPoFirm(bool OtborPoFirm)
{
Object->OtborPoFirm=OtborPoFirm;
}
//---------------------------------------------------------------
bool THOT_FormaGurAllDocImpl::get_OtborPoSklad(void)
{
return Object->OtborPoSklad;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_OtborPoSklad(bool OtborPoSklad)
{
Object->OtborPoSklad=OtborPoSklad;
}
//---------------------------------------------------------------
bool THOT_FormaGurAllDocImpl::get_OtborPoTypeDoc(void)
{
return Object->OtborPoTypeDoc;
}
//---------------------------------------------------------------
void THOT_FormaGurAllDocImpl::set_OtborPoTypeDoc(bool OtborPoTypeDoc)
{
Object->OtborPoTypeDoc=OtborPoTypeDoc;
}
//---------------------------------------------------------------
