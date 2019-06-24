#include "vcl.h"
#pragma hdrstop


#include "UDMSprBankImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprBankImpl::TDMSprBankImpl()           
{                                            
Object=new TDMSprBank(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprBankImpl::~TDMSprBankImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprBankImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprBankImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprBank)                        
   {                                                                     
   *ppv=static_cast<IDMSprBank*> (this);                                
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
int TDMSprBankImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprBankImpl::kanRelease(void)                                  
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
int  TDMSprBankImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprBankImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprBankImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprBankImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprBankImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprBankImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprBankImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprBankImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprBankImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprBankImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprBankImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprBankImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprBankImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TDMSprBankImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBankImpl::get_TableIDBANK(void)
{
return Object->TableIDBANK;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_TableIDBANK(TFIBBCDField * TableIDBANK)
{
Object->TableIDBANK=TableIDBANK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBankImpl::get_ElementIDBANK(void)
{
return Object->ElementIDBANK;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_ElementIDBANK(TFIBBCDField * ElementIDBANK)
{
Object->ElementIDBANK=ElementIDBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankImpl::get_TableNAMEBANK(void)
{
return Object->TableNAMEBANK;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_TableNAMEBANK(TFIBWideStringField * TableNAMEBANK)
{
Object->TableNAMEBANK=TableNAMEBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankImpl::get_TableGORBANK(void)
{
return Object->TableGORBANK;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_TableGORBANK(TFIBWideStringField * TableGORBANK)
{
Object->TableGORBANK=TableGORBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankImpl::get_ElementNAMEBANK(void)
{
return Object->ElementNAMEBANK;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_ElementNAMEBANK(TFIBWideStringField * ElementNAMEBANK)
{
Object->ElementNAMEBANK=ElementNAMEBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankImpl::get_ElementBIKBANK(void)
{
return Object->ElementBIKBANK;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_ElementBIKBANK(TFIBWideStringField * ElementBIKBANK)
{
Object->ElementBIKBANK=ElementBIKBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankImpl::get_ElementGORBANK(void)
{
return Object->ElementGORBANK;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_ElementGORBANK(TFIBWideStringField * ElementGORBANK)
{
Object->ElementGORBANK=ElementGORBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankImpl::get_ElementKSBANK(void)
{
return Object->ElementKSBANK;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_ElementKSBANK(TFIBWideStringField * ElementKSBANK)
{
Object->ElementKSBANK=ElementKSBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankImpl::get_ElementGID_SBANK(void)
{
return Object->ElementGID_SBANK;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_ElementGID_SBANK(TFIBWideStringField * ElementGID_SBANK)
{
Object->ElementGID_SBANK=ElementGID_SBANK;
}
//---------------------------------------------------------------
bool TDMSprBankImpl::get_Error(void)
{
return Object->Error;
}
//---------------------------------------------------------------
void TDMSprBankImpl::set_Error(bool Error)
{
Object->Error=Error;
}
//---------------------------------------------------------------
void TDMSprBankImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprBankImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);;
}
//---------------------------------------------------------------
void TDMSprBankImpl::NewElement()
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprBankImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprBankImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
