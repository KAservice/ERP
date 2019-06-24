#include <vcl.h>
#pragma hdrstop


#include "UDMSprCountryImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprCountryImpl::TDMSprCountryImpl()           
{                                            
Object=new TDMSprCountry(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprCountryImpl::~TDMSprCountryImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprCountryImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprCountryImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprCountry)                        
   {                                                                     
   *ppv=static_cast<IDMSprCountry*> (this);                                
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
int TDMSprCountryImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprCountryImpl::kanRelease(void)                                  
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
int  TDMSprCountryImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCountryImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprCountryImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprCountryImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprCountryImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprCountryImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprCountryImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprCountryImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprCountryImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCountryImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprCountryImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCountryImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprCountryImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprCountryImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprCountryImpl::get_TableID_SCOUNTRY(void)
{
return Object->TableID_SCOUNTRY;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_TableID_SCOUNTRY(TFIBBCDField * TableID_SCOUNTRY)
{
Object->TableID_SCOUNTRY=TableID_SCOUNTRY;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprCountryImpl::get_ElementID_SCOUNTRY(void)
{
return Object->ElementID_SCOUNTRY;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_ElementID_SCOUNTRY(TFIBBCDField * ElementID_SCOUNTRY)
{
Object->ElementID_SCOUNTRY=ElementID_SCOUNTRY;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCountryImpl::get_TableCODE_SCOUNTRY(void)
{
return Object->TableCODE_SCOUNTRY;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_TableCODE_SCOUNTRY(TFIBWideStringField * TableCODE_SCOUNTRY)
{
Object->TableCODE_SCOUNTRY=TableCODE_SCOUNTRY;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCountryImpl::get_TableGID_SCOUNTRY(void)
{
return Object->TableGID_SCOUNTRY;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_TableGID_SCOUNTRY(TFIBWideStringField * TableGID_SCOUNTRY)
{
Object->TableGID_SCOUNTRY=TableGID_SCOUNTRY;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCountryImpl::get_TableNAME_SCOUNTRY(void)
{
return Object->TableNAME_SCOUNTRY;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_TableNAME_SCOUNTRY(TFIBWideStringField * TableNAME_SCOUNTRY)
{
Object->TableNAME_SCOUNTRY=TableNAME_SCOUNTRY;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCountryImpl::get_ElementCODE_SCOUNTRY(void)
{
return Object->ElementCODE_SCOUNTRY;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_ElementCODE_SCOUNTRY(TFIBWideStringField * ElementCODE_SCOUNTRY)
{
Object->ElementCODE_SCOUNTRY=ElementCODE_SCOUNTRY;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCountryImpl::get_ElementGID_SCOUNTRY(void)
{
return Object->ElementGID_SCOUNTRY;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_ElementGID_SCOUNTRY(TFIBWideStringField * ElementGID_SCOUNTRY)
{
Object->ElementGID_SCOUNTRY=ElementGID_SCOUNTRY;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprCountryImpl::get_ElementNAME_SCOUNTRY(void)
{
return Object->ElementNAME_SCOUNTRY;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::set_ElementNAME_SCOUNTRY(TFIBWideStringField * ElementNAME_SCOUNTRY)
{
Object->ElementNAME_SCOUNTRY=ElementNAME_SCOUNTRY;
}
//---------------------------------------------------------------
void TDMSprCountryImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprCountryImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprCountryImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprCountryImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprCountryImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TDMSprCountryImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMSprCountryImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString TDMSprCountryImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprCountryImpl::GetIdPoName(UnicodeString name)
{
return Object->GetIdPoName(name);
}
//-----------------------------------------------------------------
