#include "vcl.h"
#pragma hdrstop


#include "UREM_FormaReportKartTovaraImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_FormaReportKartTovaraImpl::TREM_FormaReportKartTovaraImpl()           
{                                            
Object=new TREM_FormaReportKartTovara(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_FormaReportKartTovaraImpl::~TREM_FormaReportKartTovaraImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_FormaReportKartTovaraImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_FormaReportKartTovara)                        
   {                                                                     
   *ppv=static_cast<IREM_FormaReportKartTovara*> (this);                                
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
int TREM_FormaReportKartTovaraImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_FormaReportKartTovaraImpl::kanRelease(void)                                  
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
int  TREM_FormaReportKartTovaraImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_FormaReportKartTovaraImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_FormaReportKartTovaraImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_FormaReportKartTovaraImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_FormaReportKartTovaraImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TREM_FormaReportKartTovaraImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IREM_FormaReportKartTovara
__int64 TREM_FormaReportKartTovaraImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TREM_FormaReportKartTovaraImpl::get_IdSkl(void)
{
return Object->IdSkl;
}
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::set_IdSkl(__int64 IdSkl)
{
Object->IdSkl=IdSkl;
}
//---------------------------------------------------------------
__int64 TREM_FormaReportKartTovaraImpl::get_IdGrpNom(void)
{
return Object->IdGrpNom;
}
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::set_IdGrpNom(__int64 IdGrpNom)
{
Object->IdGrpNom=IdGrpNom;
}
//---------------------------------------------------------------
__int64 TREM_FormaReportKartTovaraImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
TDateTime TREM_FormaReportKartTovaraImpl::get_PosStart(void)
{
return Object->PosStart;
}
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::set_PosStart(TDateTime PosStart)
{
Object->PosStart=PosStart;
}
//---------------------------------------------------------------
TDateTime TREM_FormaReportKartTovaraImpl::get_PosEnd(void)
{
return Object->PosEnd;
}
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::set_PosEnd(TDateTime PosEnd)
{
Object->PosEnd=PosEnd;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaReportKartTovaraImpl::get_NameFirm(void)
{
return Object->NameFirm;
}
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::set_NameFirm(UnicodeString NameFirm)
{
Object->NameFirm=NameFirm;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaReportKartTovaraImpl::get_NameSklad(void)
{
return Object->NameSklad;
}
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::set_NameSklad(UnicodeString NameSklad)
{
Object->NameSklad=NameSklad;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaReportKartTovaraImpl::get_NameNom(void)
{
return Object->NameNom;
}
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::set_NameNom(UnicodeString NameNom)
{
Object->NameNom=NameNom;
}
//---------------------------------------------------------------
void TREM_FormaReportKartTovaraImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
