#include <vcl.h>
#pragma hdrstop


#include "UDMSprGrafikPlatImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprGrafikPlatImpl::TDMSprGrafikPlatImpl()           
{                                            
Object=new TDMSprGrafikPlat(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprGrafikPlatImpl::~TDMSprGrafikPlatImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprGrafikPlatImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprGrafikPlat)                        
   {                                                                     
   *ppv=static_cast<IDMSprGrafikPlat*> (this);                                
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
int TDMSprGrafikPlatImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprGrafikPlatImpl::kanRelease(void)                                  
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
int  TDMSprGrafikPlatImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprGrafikPlatImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprGrafikPlatImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprGrafikPlatImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprGrafikPlatImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprGrafikPlatImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrafikPlatImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrafikPlatImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrafikPlatImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateField * TDMSprGrafikPlatImpl::get_TableDO_SGRPLAT(void)
{
return Object->TableDO_SGRPLAT;
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::set_TableDO_SGRPLAT(TFIBDateField * TableDO_SGRPLAT)
{
Object->TableDO_SGRPLAT=TableDO_SGRPLAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrafikPlatImpl::get_TableSUM_SGRPLAT(void)
{
return Object->TableSUM_SGRPLAT;
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::set_TableSUM_SGRPLAT(TFIBBCDField * TableSUM_SGRPLAT)
{
Object->TableSUM_SGRPLAT=TableSUM_SGRPLAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrafikPlatImpl::get_TableID_SGRPLAT(void)
{
return Object->TableID_SGRPLAT;
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::set_TableID_SGRPLAT(TFIBBCDField * TableID_SGRPLAT)
{
Object->TableID_SGRPLAT=TableID_SGRPLAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrafikPlatImpl::get_TableIDDOG_SGRPLAT(void)
{
return Object->TableIDDOG_SGRPLAT;
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::set_TableIDDOG_SGRPLAT(TFIBBCDField * TableIDDOG_SGRPLAT)
{
Object->TableIDDOG_SGRPLAT=TableIDDOG_SGRPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrafikPlatImpl::get_TableGID_SGRPLAT(void)
{
return Object->TableGID_SGRPLAT;
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::set_TableGID_SGRPLAT(TFIBWideStringField * TableGID_SGRPLAT)
{
Object->TableGID_SGRPLAT=TableGID_SGRPLAT;
}
//---------------------------------------------------------------
__int64 TDMSprGrafikPlatImpl::get_IdDogovor(void)
{
return Object->IdDogovor;
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::set_IdDogovor(__int64 IdDogovor)
{
Object->IdDogovor=IdDogovor;
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::OpenTable(__int64 idDogovor)
{
return Object->OpenTable(idDogovor);
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::NewElement(__int64 idDogovor)
{
return Object->NewElement(idDogovor);
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::DeleteElement()
{
return Object->DeleteElement();
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprGrafikPlatImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
