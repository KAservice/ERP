#include "vcl.h"
#pragma hdrstop


#include "UFormaSpiskaSprEdTouchImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaSpiskaSprEdTouchImpl::TFormaSpiskaSprEdTouchImpl()           
{                                            
Object=new TFormaSpiskaSprEdTouch(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaSpiskaSprEdTouchImpl::~TFormaSpiskaSprEdTouchImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaSpiskaSprEdTouchImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaSpiskaSprEdTouch)                        
   {                                                                     
   *ppv=static_cast<IFormaSpiskaSprEdTouch*> (this);                                
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
int TFormaSpiskaSprEdTouchImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaSpiskaSprEdTouchImpl::kanRelease(void)                                  
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
int  TFormaSpiskaSprEdTouchImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaSpiskaSprEdTouchImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaSprEdTouchImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaSpiskaSprEdTouchImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaSprEdTouchImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaSpiskaSprEdTouchImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IFormaSpiskaSprEdTouch
TpFIBDataSet * TFormaSpiskaSprEdTouchImpl::get_El(void)
{
return Object->El;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_El(TpFIBDataSet * El)
{
Object->El=El;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprEdTouchImpl::get_ElKFED(void)
{
return Object->ElKFED;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_ElKFED(TFIBBCDField * ElKFED)
{
Object->ElKFED=ElKFED;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaSprEdTouchImpl::get_ElTSHED(void)
{
return Object->ElTSHED;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_ElTSHED(TFIBIntegerField * ElTSHED)
{
Object->ElTSHED=ElTSHED;
}
//---------------------------------------------------------------
TFIBSmallIntField * TFormaSpiskaSprEdTouchImpl::get_ElNEISPED(void)
{
return Object->ElNEISPED;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_ElNEISPED(TFIBSmallIntField * ElNEISPED)
{
Object->ElNEISPED=ElNEISPED;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprEdTouchImpl::get_ElZNACH_PRICE(void)
{
return Object->ElZNACH_PRICE;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_ElZNACH_PRICE(TFIBBCDField * ElZNACH_PRICE)
{
Object->ElZNACH_PRICE=ElZNACH_PRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprEdTouchImpl::get_ElIDED(void)
{
return Object->ElIDED;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_ElIDED(TFIBBCDField * ElIDED)
{
Object->ElIDED=ElIDED;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprEdTouchImpl::get_ElIDNOMED(void)
{
return Object->ElIDNOMED;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_ElIDNOMED(TFIBBCDField * ElIDNOMED)
{
Object->ElIDNOMED=ElIDNOMED;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprEdTouchImpl::get_ElIDOKEIED(void)
{
return Object->ElIDOKEIED;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_ElIDOKEIED(TFIBBCDField * ElIDOKEIED)
{
Object->ElIDOKEIED=ElIDOKEIED;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaSprEdTouchImpl::get_ElNAMEED(void)
{
return Object->ElNAMEED;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_ElNAMEED(TFIBWideStringField * ElNAMEED)
{
Object->ElNAMEED=ElNAMEED;
}
//---------------------------------------------------------------
bool TFormaSpiskaSprEdTouchImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaSpiskaSprEdTouchImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
UnicodeString TFormaSpiskaSprEdTouchImpl::get_NameNom(void)
{
return Object->NameNom;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_NameNom(UnicodeString NameNom)
{
Object->NameNom=NameNom;
}
//---------------------------------------------------------------
bool TFormaSpiskaSprEdTouchImpl::get_MnVibor(void)
{
return Object->MnVibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_MnVibor(bool MnVibor)
{
Object->MnVibor=MnVibor;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprEdTouchImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprEdTouchImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprEdTouchImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprEdTouchImpl::get_IdBasEd(void)
{
return Object->IdBasEd;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_IdBasEd(__int64 IdBasEd)
{
Object->IdBasEd=IdBasEd;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprEdTouchImpl::get_IdEd(void)
{
return Object->IdEd;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_IdEd(__int64 IdEd)
{
Object->IdEd=IdEd;
}
//---------------------------------------------------------------
int TFormaSpiskaSprEdTouchImpl::get_TypeNom(void)
{
return Object->TypeNom;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_TypeNom(int TypeNom)
{
Object->TypeNom=TypeNom;
}
//---------------------------------------------------------------
double TFormaSpiskaSprEdTouchImpl::get_Kol(void)
{
return Object->Kol;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_Kol(double Kol)
{
Object->Kol=Kol;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprEdTouchImpl::get_IdPod(void)
{
return Object->IdPod;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_IdPod(__int64 IdPod)
{
Object->IdPod=IdPod;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprEdTouchImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::OpenSpisokEd(void)
{
return Object->OpenSpisokEd();
}
//---------------------------------------------------------------
void TFormaSpiskaSprEdTouchImpl::OpenElement(int Num)
{
return Object->OpenElement(Num);
}
//---------------------------------------------------------------
