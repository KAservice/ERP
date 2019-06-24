#include "vcl.h"
#pragma hdrstop


#include "UFormaGurAllDocImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaGurAllDocImpl::TFormaGurAllDocImpl()           
{                                            
Object=new TFormaGurAllDoc(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaGurAllDocImpl::~TFormaGurAllDocImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaGurAllDocImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaGurAllDocImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaGurAllDoc)                        
   {                                                                     
   *ppv=static_cast<IFormaGurAllDoc*> (this);                                
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
int TFormaGurAllDocImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaGurAllDocImpl::kanRelease(void)                                  
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
int  TFormaGurAllDocImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaGurAllDocImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaGurAllDocImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaGurAllDocImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaGurAllDocImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaGurAllDocImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IFormaGurAllDoc
bool TFormaGurAllDocImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaGurAllDocImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IDMGurAllDoc * TFormaGurAllDocImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_DM(IDMGurAllDoc * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
__int64 TFormaGurAllDocImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TFormaGurAllDocImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TFormaGurAllDocImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 TFormaGurAllDocImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
UnicodeString TFormaGurAllDocImpl::get_NameKlient(void)
{
return Object->NameKlient;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_NameKlient(UnicodeString NameKlient)
{
Object->NameKlient=NameKlient;
}
//---------------------------------------------------------------
__int64 TFormaGurAllDocImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
UnicodeString TFormaGurAllDocImpl::get_NameSklad(void)
{
return Object->NameSklad;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_NameSklad(UnicodeString NameSklad)
{
Object->NameSklad=NameSklad;
}
//---------------------------------------------------------------
__int64 TFormaGurAllDocImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
UnicodeString TFormaGurAllDocImpl::get_NameFirm(void)
{
return Object->NameFirm;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_NameFirm(UnicodeString NameFirm)
{
Object->NameFirm=NameFirm;
}
//---------------------------------------------------------------
UnicodeString TFormaGurAllDocImpl::get_StringTypeDoc(void)
{
return Object->StringTypeDoc;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_StringTypeDoc(UnicodeString StringTypeDoc)
{
Object->StringTypeDoc=StringTypeDoc;
}
//---------------------------------------------------------------
UnicodeString TFormaGurAllDocImpl::get_NameTypeDoc(void)
{
return Object->NameTypeDoc;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_NameTypeDoc(UnicodeString NameTypeDoc)
{
Object->NameTypeDoc=NameTypeDoc;
}
//---------------------------------------------------------------
bool TFormaGurAllDocImpl::get_OtborPoKlientu(void)
{
return Object->OtborPoKlientu;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_OtborPoKlientu(bool OtborPoKlientu)
{
Object->OtborPoKlientu=OtborPoKlientu;
}
//---------------------------------------------------------------
bool TFormaGurAllDocImpl::get_OtborPoFirm(void)
{
return Object->OtborPoFirm;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_OtborPoFirm(bool OtborPoFirm)
{
Object->OtborPoFirm=OtborPoFirm;
}
//---------------------------------------------------------------
bool TFormaGurAllDocImpl::get_OtborPoSklad(void)
{
return Object->OtborPoSklad;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_OtborPoSklad(bool OtborPoSklad)
{
Object->OtborPoSklad=OtborPoSklad;
}
//---------------------------------------------------------------
bool TFormaGurAllDocImpl::get_OtborPoTypeDoc(void)
{
return Object->OtborPoTypeDoc;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_OtborPoTypeDoc(bool OtborPoTypeDoc)
{
Object->OtborPoTypeDoc=OtborPoTypeDoc;
}
//---------------------------------------------------------------
bool TFormaGurAllDocImpl::get_NoCheck(void)
{
return Object->NoCheck;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::set_NoCheck(bool NoCheck)
{
Object->NoCheck=NoCheck;
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::OpenFormDoc()
{
return Object->OpenFormDoc();
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::DeleteDoc(void)
{
return Object->DeleteDoc();
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::DeleteAllDoc(void)
{
return Object->DeleteAllDoc();
}
//---------------------------------------------------------------
void TFormaGurAllDocImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
