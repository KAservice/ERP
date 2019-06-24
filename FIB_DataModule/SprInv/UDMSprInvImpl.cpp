#include <vcl.h>
#pragma hdrstop


#include "UDMSprInvImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprInvImpl::TDMSprInvImpl()           
{                                            
Object=new TDMSprInv(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprInvImpl::~TDMSprInvImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprInvImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprInvImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprInv)                        
   {                                                                     
   *ppv=static_cast<IDMSprInv*> (this);                                
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
int TDMSprInvImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprInvImpl::kanRelease(void)                                  
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
int  TDMSprInvImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprInvImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprInvImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprInvImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprInvImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprInvImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprInvImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprInvImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprInvImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprInvImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprInvImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprInvImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprInvImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateField * TDMSprInvImpl::get_TableDATE_SINV(void)
{
return Object->TableDATE_SINV;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_TableDATE_SINV(TFIBDateField * TableDATE_SINV)
{
Object->TableDATE_SINV=TableDATE_SINV;
}
//---------------------------------------------------------------
TIntegerField * TDMSprInvImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBDateField * TDMSprInvImpl::get_ElementDATE_SINV(void)
{
return Object->ElementDATE_SINV;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_ElementDATE_SINV(TFIBDateField * ElementDATE_SINV)
{
Object->ElementDATE_SINV=ElementDATE_SINV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprInvImpl::get_TableID_SINV(void)
{
return Object->TableID_SINV;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_TableID_SINV(TFIBBCDField * TableID_SINV)
{
Object->TableID_SINV=TableID_SINV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprInvImpl::get_ElementID_SINV(void)
{
return Object->ElementID_SINV;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_ElementID_SINV(TFIBBCDField * ElementID_SINV)
{
Object->ElementID_SINV=ElementID_SINV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInvImpl::get_TableGID_SINV(void)
{
return Object->TableGID_SINV;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_TableGID_SINV(TFIBWideStringField * TableGID_SINV)
{
Object->TableGID_SINV=TableGID_SINV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInvImpl::get_TableNAME_SINV(void)
{
return Object->TableNAME_SINV;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_TableNAME_SINV(TFIBWideStringField * TableNAME_SINV)
{
Object->TableNAME_SINV=TableNAME_SINV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInvImpl::get_ElementGID_SINV(void)
{
return Object->ElementGID_SINV;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_ElementGID_SINV(TFIBWideStringField * ElementGID_SINV)
{
Object->ElementGID_SINV=ElementGID_SINV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInvImpl::get_ElementNAME_SINV(void)
{
return Object->ElementNAME_SINV;
}
//---------------------------------------------------------------
void TDMSprInvImpl::set_ElementNAME_SINV(TFIBWideStringField * ElementNAME_SINV)
{
Object->ElementNAME_SINV=ElementNAME_SINV;
}
//---------------------------------------------------------------
void TDMSprInvImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprInvImpl::OpenElement(__int64 Id)
{
return Object->OpenElement( Id);
}
//---------------------------------------------------------------
void TDMSprInvImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprInvImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprInvImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
void TDMSprInvImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMSprInvImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString TDMSprInvImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
