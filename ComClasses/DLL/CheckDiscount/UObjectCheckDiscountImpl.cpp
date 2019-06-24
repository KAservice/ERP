#include "vcl.h"
#pragma hdrstop


#include "UObjectCheckDiscountImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TObjectCheckDiscountImpl::TObjectCheckDiscountImpl()           
{                                            
Object=new TObjectCheckDiscount();
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TObjectCheckDiscountImpl::~TObjectCheckDiscountImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TObjectCheckDiscountImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IObjectCheckDiscount)                        
   {                                                                     
   *ppv=static_cast<IObjectCheckDiscount*> (this);                                
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
int TObjectCheckDiscountImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TObjectCheckDiscountImpl::kanRelease(void)                                  
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
int  TObjectCheckDiscountImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TObjectCheckDiscountImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TObjectCheckDiscountImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TObjectCheckDiscountImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TObjectCheckDiscountImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IObjectCheckDiscount
TStringDoc * TObjectCheckDiscountImpl::get_StringDoc(void)
{
return Object->StringDoc;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_StringDoc(TStringDoc * StringDoc)
{
Object->StringDoc=StringDoc;
}
//---------------------------------------------------------------
int TObjectCheckDiscountImpl::get_NumberTecString(void)
{
return Object->NumberTecString;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_NumberTecString(int NumberTecString)
{
Object->NumberTecString=NumberTecString;
}
//---------------------------------------------------------------
UnicodeString TObjectCheckDiscountImpl::get_TextMessage(void)
{
return Object->TextMessage;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_TextMessage(UnicodeString TextMessage)
{
Object->TextMessage=TextMessage;
}
//---------------------------------------------------------------
UnicodeString TObjectCheckDiscountImpl::get_TextMessageAtention(void)
{
return Object->TextMessageAtention;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_TextMessageAtention(UnicodeString TextMessageAtention)
{
Object->TextMessageAtention=TextMessageAtention;
}
//---------------------------------------------------------------
__int64 TObjectCheckDiscountImpl::get_IdDiscountCard(void)
{
return Object->IdDiscountCard;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_IdDiscountCard(__int64 IdDiscountCard)
{
Object->IdDiscountCard=IdDiscountCard;
}
//---------------------------------------------------------------
UnicodeString TObjectCheckDiscountImpl::get_NameDiscountCard(void)
{
return Object->NameDiscountCard;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_NameDiscountCard(UnicodeString NameDiscountCard)
{
Object->NameDiscountCard=NameDiscountCard;
}
//---------------------------------------------------------------
__int64 TObjectCheckDiscountImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
UnicodeString TObjectCheckDiscountImpl::get_NameTypePrice(void)
{
return Object->NameTypePrice;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_NameTypePrice(UnicodeString NameTypePrice)
{
Object->NameTypePrice=NameTypePrice;
}
//---------------------------------------------------------------
__int64 TObjectCheckDiscountImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TObjectCheckDiscountImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
UnicodeString TObjectCheckDiscountImpl::get_NameKlient(void)
{
return Object->NameKlient;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_NameKlient(UnicodeString NameKlient)
{
Object->NameKlient=NameKlient;
}
//---------------------------------------------------------------
double TObjectCheckDiscountImpl::get_SummaDoc(void)
{
return Object->SummaDoc;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::set_SummaDoc(double SummaDoc)
{
Object->SummaDoc=SummaDoc;
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::CheckDiscount(void)
{
return Object->CheckDiscount();
}
//---------------------------------------------------------------
bool TObjectCheckDiscountImpl::GetString(void)
{
return Object->GetString();
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::ClearList(void)
{
return Object->ClearList();
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::AddString(__int64 id_string,__int64 id_nom,__int64 id_ed,__int64 id_grp,	__int64 id_vid_nom,double price,double kol,double kf,double sum,double sum_discount,double procent_discount,double procent_discount_auto,double procent_discount_card,double procent_discount_hand,bool no_discount)
{
return Object->AddString(id_string,id_nom,id_ed,id_grp,id_vid_nom, price,kol,kf,sum,sum_discount,procent_discount,procent_discount_auto,procent_discount_card,procent_discount_hand, no_discount);
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::GetProcentPoDiscountCard(void)
{
return Object->GetProcentPoDiscountCard();
}
//---------------------------------------------------------------
void TObjectCheckDiscountImpl::GetProcentAuto(double sum_doc)
{
return Object->GetProcentAuto(sum_doc);
}
//---------------------------------------------------------------
bool TObjectCheckDiscountImpl::FindCardPoCodu(UnicodeString code)
{
return Object->FindCardPoCodu(code);
}
//---------------------------------------------------------------
