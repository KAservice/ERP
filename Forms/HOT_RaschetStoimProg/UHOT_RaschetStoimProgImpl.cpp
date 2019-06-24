#include "vcl.h"
#pragma hdrstop


#include "UHOT_RaschetStoimProgImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_RaschetStoimProgImpl::THOT_RaschetStoimProgImpl()           
{                                            
Object=new TRaschetStoimProg();
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_RaschetStoimProgImpl::~THOT_RaschetStoimProgImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_RaschetStoimProgImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
 {                                                                         
int result=0;                                                             
if (id_interface==IID_IkanUnknown)                                        
   {                                                                     
   *ppv=static_cast<IkanUnknown*> (this);                                 
   result=-1;                                                             
   }                                                                      
else if (id_interface==IID_IMainInterface)                        
   {                                                                     
   *ppv=static_cast<IMainInterface*> (this);                                
   result=-1;                                                            
   }  
else if (id_interface==IID_IHOT_RaschetStoimProg)                        
   {                                                                     
   *ppv=static_cast<IHOT_RaschetStoimProg*> (this);                                
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
int THOT_RaschetStoimProgImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_RaschetStoimProgImpl::kanRelease(void)                                  
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
int  THOT_RaschetStoimProgImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_RaschetStoimProgImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_RaschetStoimProgImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_RaschetStoimProgImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_RaschetStoimProgImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_RaschetStoimProg
bool THOT_RaschetStoimProgImpl::get_AddBron(void)
{
return Object->AddBron;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_AddBron(bool AddBron)
{
Object->AddBron=AddBron;
}
//---------------------------------------------------------------
TDateTime THOT_RaschetStoimProgImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime THOT_RaschetStoimProgImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
TDateTime THOT_RaschetStoimProgImpl::get_PosNachBron(void)
{
return Object->PosNachBron;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_PosNachBron(TDateTime PosNachBron)
{
Object->PosNachBron=PosNachBron;
}
//---------------------------------------------------------------
TDateTime THOT_RaschetStoimProgImpl::get_PosConBron(void)
{
return Object->PosConBron;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_PosConBron(TDateTime PosConBron)
{
Object->PosConBron=PosConBron;
}
//---------------------------------------------------------------
__int64 THOT_RaschetStoimProgImpl::get_IdNomer(void)
{
return Object->IdNomer;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_IdNomer(__int64 IdNomer)
{
Object->IdNomer=IdNomer;
}
//---------------------------------------------------------------
__int64 THOT_RaschetStoimProgImpl::get_IdTypePos(void)
{
return Object->IdTypePos;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_IdTypePos(__int64 IdTypePos)
{
Object->IdTypePos=IdTypePos;
}
//---------------------------------------------------------------
AnsiString THOT_RaschetStoimProgImpl::get_NameTypePos(void)
{
return Object->NameTypePos;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_NameTypePos(AnsiString NameTypePos)
{
Object->NameTypePos=NameTypePos;
}
//---------------------------------------------------------------
__int64 THOT_RaschetStoimProgImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
int THOT_RaschetStoimProgImpl::get_NumberTecString(void)
{
return Object->NumberTecString;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_NumberTecString(int NumberTecString)
{
Object->NumberTecString=NumberTecString;
}
//---------------------------------------------------------------
TList * THOT_RaschetStoimProgImpl::get_ResultList(void)
{
return Object->ResultList;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_ResultList(TList * ResultList)
{
Object->ResultList=ResultList;
}
//---------------------------------------------------------------
TStringDoc * THOT_RaschetStoimProgImpl::get_StringDoc(void)
{
return Object->StringDoc;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::set_StringDoc(TStringDoc * StringDoc)
{
Object->StringDoc=StringDoc;
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::GetTableDoc(void)
{
return Object->GetTableDoc();
}
//---------------------------------------------------------------
bool THOT_RaschetStoimProgImpl::GetString(void)
{
return Object->GetString();
}
//---------------------------------------------------------------
void THOT_RaschetStoimProgImpl::AddStringNewReal( TDateTime pos_nach, TDateTime pos_con,	__int64 id_nom, AnsiString name_nom,__int64 id_ed, double kf, AnsiString name_ed,double price,double kol,int type_usl)
{
return Object->AddStringNewReal(pos_nach, pos_con,id_nom,name_nom,id_ed,kf, name_ed,price,kol,type_usl);
}
//---------------------------------------------------------------
