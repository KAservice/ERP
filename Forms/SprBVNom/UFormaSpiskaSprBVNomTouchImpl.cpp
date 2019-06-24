#include "vcl.h"
#pragma hdrstop


#include "UFormaSpiskaSprBVNomTouchImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaSpiskaSprBVNomTouchImpl::TFormaSpiskaSprBVNomTouchImpl()           
{                                            
Object=new TFormaSpiskaSprBVNomTouch(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaSpiskaSprBVNomTouchImpl::~TFormaSpiskaSprBVNomTouchImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaSpiskaSprBVNomTouchImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaSpiskaSprBVNomTouch)                        
   {                                                                     
   *ppv=static_cast<IFormaSpiskaSprBVNomTouch*> (this);                                
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
int TFormaSpiskaSprBVNomTouchImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaSpiskaSprBVNomTouchImpl::kanRelease(void)                                  
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
int  TFormaSpiskaSprBVNomTouchImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaSpiskaSprBVNomTouchImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaSprBVNomTouchImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaSpiskaSprBVNomTouchImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaSprBVNomTouchImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaSpiskaSprBVNomTouchImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IFormaSpiskaSprBVNomTouch
TpFIBDataSet * TFormaSpiskaSprBVNomTouchImpl::get_Grp(void)
{
return Object->Grp;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_Grp(TpFIBDataSet * Grp)
{
Object->Grp=Grp;
}
//---------------------------------------------------------------
TpFIBDataSet * TFormaSpiskaSprBVNomTouchImpl::get_El(void)
{
return Object->El;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_El(TpFIBDataSet * El)
{
Object->El=El;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaSprBVNomTouchImpl::get_ElCODE_BVNOM(void)
{
return Object->ElCODE_BVNOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_ElCODE_BVNOM(TFIBIntegerField * ElCODE_BVNOM)
{
Object->ElCODE_BVNOM=ElCODE_BVNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TFormaSpiskaSprBVNomTouchImpl::get_ElTNOM(void)
{
return Object->ElTNOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_ElTNOM(TFIBIntegerField * ElTNOM)
{
Object->ElTNOM=ElTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprBVNomTouchImpl::get_GrpID_GBVNOM(void)
{
return Object->GrpID_GBVNOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_GrpID_GBVNOM(TFIBBCDField * GrpID_GBVNOM)
{
Object->GrpID_GBVNOM=GrpID_GBVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprBVNomTouchImpl::get_GrpIDGRP_GBVNOM(void)
{
return Object->GrpIDGRP_GBVNOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_GrpIDGRP_GBVNOM(TFIBBCDField * GrpIDGRP_GBVNOM)
{
Object->GrpIDGRP_GBVNOM=GrpIDGRP_GBVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprBVNomTouchImpl::get_GrpIDPOD_GBVNOM(void)
{
return Object->GrpIDPOD_GBVNOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_GrpIDPOD_GBVNOM(TFIBBCDField * GrpIDPOD_GBVNOM)
{
Object->GrpIDPOD_GBVNOM=GrpIDPOD_GBVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprBVNomTouchImpl::get_ElID_BVNOM(void)
{
return Object->ElID_BVNOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_ElID_BVNOM(TFIBBCDField * ElID_BVNOM)
{
Object->ElID_BVNOM=ElID_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprBVNomTouchImpl::get_ElIDPOD_BVNOM(void)
{
return Object->ElIDPOD_BVNOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_ElIDPOD_BVNOM(TFIBBCDField * ElIDPOD_BVNOM)
{
Object->ElIDPOD_BVNOM=ElIDPOD_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprBVNomTouchImpl::get_ElIDNOM_BVNOM(void)
{
return Object->ElIDNOM_BVNOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_ElIDNOM_BVNOM(TFIBBCDField * ElIDNOM_BVNOM)
{
Object->ElIDNOM_BVNOM=ElIDNOM_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprBVNomTouchImpl::get_ElIDGRP_BVNOM(void)
{
return Object->ElIDGRP_BVNOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_ElIDGRP_BVNOM(TFIBBCDField * ElIDGRP_BVNOM)
{
Object->ElIDGRP_BVNOM=ElIDGRP_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TFormaSpiskaSprBVNomTouchImpl::get_ElIDBASEDNOM(void)
{
return Object->ElIDBASEDNOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_ElIDBASEDNOM(TFIBBCDField * ElIDBASEDNOM)
{
Object->ElIDBASEDNOM=ElIDBASEDNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaSprBVNomTouchImpl::get_ElNAMENOM(void)
{
return Object->ElNAMENOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_ElNAMENOM(TFIBWideStringField * ElNAMENOM)
{
Object->ElNAMENOM=ElNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaSprBVNomTouchImpl::get_ElKRNAMENOM(void)
{
return Object->ElKRNAMENOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_ElKRNAMENOM(TFIBWideStringField * ElKRNAMENOM)
{
Object->ElKRNAMENOM=ElKRNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TFormaSpiskaSprBVNomTouchImpl::get_GrpNAME_GBVNOM(void)
{
return Object->GrpNAME_GBVNOM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_GrpNAME_GBVNOM(TFIBWideStringField * GrpNAME_GBVNOM)
{
Object->GrpNAME_GBVNOM=GrpNAME_GBVNOM;
}
//---------------------------------------------------------------
bool TFormaSpiskaSprBVNomTouchImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaSpiskaSprBVNomTouchImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
bool TFormaSpiskaSprBVNomTouchImpl::get_MnVibor(void)
{
return Object->MnVibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_MnVibor(bool MnVibor)
{
Object->MnVibor=MnVibor;
}
//---------------------------------------------------------------
bool TFormaSpiskaSprBVNomTouchImpl::get_ZaprosEd(void)
{
return Object->ZaprosEd;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_ZaprosEd(bool ZaprosEd)
{
Object->ZaprosEd=ZaprosEd;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprBVNomTouchImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprBVNomTouchImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprBVNomTouchImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprBVNomTouchImpl::get_IdEd(void)
{
return Object->IdEd;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_IdEd(__int64 IdEd)
{
Object->IdEd=IdEd;
}
//---------------------------------------------------------------
String TFormaSpiskaSprBVNomTouchImpl::get_NameEd(void)
{
return Object->NameEd;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_NameEd(String NameEd)
{
Object->NameEd=NameEd;
}
//---------------------------------------------------------------
double TFormaSpiskaSprBVNomTouchImpl::get_KFEd(void)
{
return Object->KFEd;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_KFEd(double KFEd)
{
Object->KFEd=KFEd;
}
//---------------------------------------------------------------
double TFormaSpiskaSprBVNomTouchImpl::get_Kol(void)
{
return Object->Kol;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_Kol(double Kol)
{
Object->Kol=Kol;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprBVNomTouchImpl::get_IdPod(void)
{
return Object->IdPod;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_IdPod(__int64 IdPod)
{
Object->IdPod=IdPod;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprBVNomTouchImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TFormaSpiskaSprBVNomTouchImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
