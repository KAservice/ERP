#include <vcl.h>
#pragma hdrstop


#include "UDMSprVidKlientImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprVidKlientImpl::TDMSprVidKlientImpl()           
{                                            
Object=new TDMSprVidKlient(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprVidKlientImpl::~TDMSprVidKlientImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprVidKlientImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprVidKlientImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprVidKlient)                        
   {                                                                     
   *ppv=static_cast<IDMSprVidKlient*> (this);                                
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
int TDMSprVidKlientImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprVidKlientImpl::kanRelease(void)
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
int  TDMSprVidKlientImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprVidKlientImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprVidKlientImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprVidKlientImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprVidKlientImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprVidKlientImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprVidKlientImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprVidKlientImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprVidKlientImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprVidKlientImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprVidKlientImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprVidKlientImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprVidKlientImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVidKlientImpl::get_TableID_SVIDKLIENT(void)
{
return Object->TableID_SVIDKLIENT;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_TableID_SVIDKLIENT(TFIBBCDField * TableID_SVIDKLIENT)
{
Object->TableID_SVIDKLIENT=TableID_SVIDKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVidKlientImpl::get_ElementID_SVIDKLIENT(void)
{
return Object->ElementID_SVIDKLIENT;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_ElementID_SVIDKLIENT(TFIBBCDField * ElementID_SVIDKLIENT)
{
Object->ElementID_SVIDKLIENT=ElementID_SVIDKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidKlientImpl::get_TableGID_SVIDKLIENT(void)
{
return Object->TableGID_SVIDKLIENT;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_TableGID_SVIDKLIENT(TFIBWideStringField * TableGID_SVIDKLIENT)
{
Object->TableGID_SVIDKLIENT=TableGID_SVIDKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidKlientImpl::get_TableNAME_SVIDKLIENT(void)
{
return Object->TableNAME_SVIDKLIENT;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_TableNAME_SVIDKLIENT(TFIBWideStringField * TableNAME_SVIDKLIENT)
{
Object->TableNAME_SVIDKLIENT=TableNAME_SVIDKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidKlientImpl::get_ElementGID_SVIDKLIENT(void)
{
return Object->ElementGID_SVIDKLIENT;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_ElementGID_SVIDKLIENT(TFIBWideStringField * ElementGID_SVIDKLIENT)
{
Object->ElementGID_SVIDKLIENT=ElementGID_SVIDKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidKlientImpl::get_ElementNAME_SVIDKLIENT(void)
{
return Object->ElementNAME_SVIDKLIENT;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::set_ElementNAME_SVIDKLIENT(TFIBWideStringField * ElementNAME_SVIDKLIENT)
{
Object->ElementNAME_SVIDKLIENT=ElementNAME_SVIDKLIENT;
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprVidKlientImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
bool TDMSprVidKlientImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprVidKlientImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprVidKlientImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
bool TDMSprVidKlientImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
void TDMSprVidKlientImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TDMSprVidKlientImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
int TDMSprVidKlientImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
