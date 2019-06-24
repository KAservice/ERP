#include "vcl.h"
#pragma hdrstop


#include "UDMSprBankSchetImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprBankSchetImpl::TDMSprBankSchetImpl()           
{                                            
Object=new TDMSprBankSchet(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprBankSchetImpl::~TDMSprBankSchetImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprBankSchetImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprBankSchetImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprBankSchet)                        
   {                                                                     
   *ppv=static_cast<IDMSprBankSchet*> (this);                                
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
int TDMSprBankSchetImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprBankSchetImpl::kanRelease(void)                                  
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
int  TDMSprBankSchetImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprBankSchetImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprBankSchetImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprBankSchetImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprBankSchetImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprBankSchet
TDataSource * TDMSprBankSchetImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprBankSchetImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprBankSchetImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprBankSchetImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprBankSchetImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprBankSchetImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprBankSchetImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBankSchetImpl::get_TableIDBSCHET(void)
{
return Object->TableIDBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_TableIDBSCHET(TFIBBCDField * TableIDBSCHET)
{
Object->TableIDBSCHET=TableIDBSCHET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBankSchetImpl::get_TableIDBANKBSCHET(void)
{
return Object->TableIDBANKBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_TableIDBANKBSCHET(TFIBBCDField * TableIDBANKBSCHET)
{
Object->TableIDBANKBSCHET=TableIDBANKBSCHET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBankSchetImpl::get_TableIDFIRMBSCHET(void)
{
return Object->TableIDFIRMBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_TableIDFIRMBSCHET(TFIBBCDField * TableIDFIRMBSCHET)
{
Object->TableIDFIRMBSCHET=TableIDFIRMBSCHET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBankSchetImpl::get_ElementIDBSCHET(void)
{
return Object->ElementIDBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementIDBSCHET(TFIBBCDField * ElementIDBSCHET)
{
Object->ElementIDBSCHET=ElementIDBSCHET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBankSchetImpl::get_ElementIDBANKBSCHET(void)
{
return Object->ElementIDBANKBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementIDBANKBSCHET(TFIBBCDField * ElementIDBANKBSCHET)
{
Object->ElementIDBANKBSCHET=ElementIDBANKBSCHET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBankSchetImpl::get_ElementIDFIRMBSCHET(void)
{
return Object->ElementIDFIRMBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementIDFIRMBSCHET(TFIBBCDField * ElementIDFIRMBSCHET)
{
Object->ElementIDFIRMBSCHET=ElementIDFIRMBSCHET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBankSchetImpl::get_ElementIDBANK(void)
{
return Object->ElementIDBANK;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementIDBANK(TFIBBCDField * ElementIDBANK)
{
Object->ElementIDBANK=ElementIDBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_TableNAMEBSCHET(void)
{
return Object->TableNAMEBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_TableNAMEBSCHET(TFIBWideStringField * TableNAMEBSCHET)
{
Object->TableNAMEBSCHET=TableNAMEBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_TableNUMBSCHET(void)
{
return Object->TableNUMBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_TableNUMBSCHET(TFIBWideStringField * TableNUMBSCHET)
{
Object->TableNUMBSCHET=TableNUMBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_TableGID_SBSCHET(void)
{
return Object->TableGID_SBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_TableGID_SBSCHET(TFIBWideStringField * TableGID_SBSCHET)
{
Object->TableGID_SBSCHET=TableGID_SBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_TableNAMEBANK(void)
{
return Object->TableNAMEBANK;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_TableNAMEBANK(TFIBWideStringField * TableNAMEBANK)
{
Object->TableNAMEBANK=TableNAMEBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_TableBIKBANK(void)
{
return Object->TableBIKBANK;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_TableBIKBANK(TFIBWideStringField * TableBIKBANK)
{
Object->TableBIKBANK=TableBIKBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_TableGORBANK(void)
{
return Object->TableGORBANK;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_TableGORBANK(TFIBWideStringField * TableGORBANK)
{
Object->TableGORBANK=TableGORBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_TableKSBANK(void)
{
return Object->TableKSBANK;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_TableKSBANK(TFIBWideStringField * TableKSBANK)
{
Object->TableKSBANK=TableKSBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_ElementNAMEBSCHET(void)
{
return Object->ElementNAMEBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementNAMEBSCHET(TFIBWideStringField * ElementNAMEBSCHET)
{
Object->ElementNAMEBSCHET=ElementNAMEBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_ElementNUMBSCHET(void)
{
return Object->ElementNUMBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementNUMBSCHET(TFIBWideStringField * ElementNUMBSCHET)
{
Object->ElementNUMBSCHET=ElementNUMBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_ElementGID_SBSCHET(void)
{
return Object->ElementGID_SBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementGID_SBSCHET(TFIBWideStringField * ElementGID_SBSCHET)
{
Object->ElementGID_SBSCHET=ElementGID_SBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_ElementNAMEBANK(void)
{
return Object->ElementNAMEBANK;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementNAMEBANK(TFIBWideStringField * ElementNAMEBANK)
{
Object->ElementNAMEBANK=ElementNAMEBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_ElementBIKBANK(void)
{
return Object->ElementBIKBANK;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementBIKBANK(TFIBWideStringField * ElementBIKBANK)
{
Object->ElementBIKBANK=ElementBIKBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_ElementGORBANK(void)
{
return Object->ElementGORBANK;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementGORBANK(TFIBWideStringField * ElementGORBANK)
{
Object->ElementGORBANK=ElementGORBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_ElementKSBANK(void)
{
return Object->ElementKSBANK;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementKSBANK(TFIBWideStringField * ElementKSBANK)
{
Object->ElementKSBANK=ElementKSBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_ElementGID_SBANK(void)
{
return Object->ElementGID_SBANK;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementGID_SBANK(TFIBWideStringField * ElementGID_SBANK)
{
Object->ElementGID_SBANK=ElementGID_SBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBankSchetImpl::get_ElementPREFIKS_NUM_SBSCHET(void)
{
return Object->ElementPREFIKS_NUM_SBSCHET;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_ElementPREFIKS_NUM_SBSCHET(TFIBWideStringField * ElementPREFIKS_NUM_SBSCHET)
{
Object->ElementPREFIKS_NUM_SBSCHET=ElementPREFIKS_NUM_SBSCHET;
}
//---------------------------------------------------------------
__int64 TDMSprBankSchetImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprBankSchetImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::NewElement()
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprBankSchetImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprBankSchetImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
