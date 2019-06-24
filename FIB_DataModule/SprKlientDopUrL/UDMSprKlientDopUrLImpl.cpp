#include <vcl.h>
#pragma hdrstop


#include "UDMSprKlientDopUrLImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprKlientDopUrLImpl::TDMSprKlientDopUrLImpl()           
{                                            
Object=new TDMSprKlientDopUrL(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprKlientDopUrLImpl::~TDMSprKlientDopUrLImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprKlientDopUrLImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprKlientDopUrL)                        
   {                                                                     
   *ppv=static_cast<IDMSprKlientDopUrL*> (this);                                
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
int TDMSprKlientDopUrLImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprKlientDopUrLImpl::kanRelease(void)                                  
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
                                                             
//---------------------------------------------------------------
int  TDMSprKlientDopUrLImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprKlientDopUrLImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprKlientDopUrLImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprKlientDopUrLImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprKlientDopUrLImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprKlientDopUrLImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprKlientDopUrLImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprKlientDopUrLImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientDopUrLImpl::get_ElementID_SKLIENT_DOPURL(void)
{
return Object->ElementID_SKLIENT_DOPURL;
}
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::set_ElementID_SKLIENT_DOPURL(TFIBBCDField * ElementID_SKLIENT_DOPURL)
{
Object->ElementID_SKLIENT_DOPURL=ElementID_SKLIENT_DOPURL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientDopUrLImpl::get_ElementIDKLIENT_SKLIENT_DOPURL(void)
{
return Object->ElementIDKLIENT_SKLIENT_DOPURL;
}
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::set_ElementIDKLIENT_SKLIENT_DOPURL(TFIBBCDField * ElementIDKLIENT_SKLIENT_DOPURL)
{
Object->ElementIDKLIENT_SKLIENT_DOPURL=ElementIDKLIENT_SKLIENT_DOPURL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientDopUrLImpl::get_ElementGID_SKLIENT_DOPURL(void)
{
return Object->ElementGID_SKLIENT_DOPURL;
}
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::set_ElementGID_SKLIENT_DOPURL(TFIBWideStringField * ElementGID_SKLIENT_DOPURL)
{
Object->ElementGID_SKLIENT_DOPURL=ElementGID_SKLIENT_DOPURL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientDopUrLImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
__int64 TDMSprKlientDopUrLImpl::get_Id(void)
{
return Object->Id;
}
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::set_Id(__int64 Id)
{
Object->Id=Id;
}
//---------------------------------------------------------------
__int64 TDMSprKlientDopUrLImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
int TDMSprKlientDopUrLImpl::OpenElement(void)
{
return Object->OpenElement();
}
//---------------------------------------------------------------
void TDMSprKlientDopUrLImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprKlientDopUrLImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprKlientDopUrLImpl::DeleteElement(void)
{
return Object->DeleteElement();
}
//---------------------------------------------------------------
