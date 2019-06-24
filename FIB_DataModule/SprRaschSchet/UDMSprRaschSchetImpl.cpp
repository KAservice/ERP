#include <vcl.h>
#pragma hdrstop


#include "UDMSprRaschSchetImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprRaschSchetImpl::TDMSprRaschSchetImpl()           
{                                            
Object=new TDMSprRaschSchet(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprRaschSchetImpl::~TDMSprRaschSchetImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprRaschSchetImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprRaschSchet)                        
   {                                                                     
   *ppv=static_cast<IDMSprRaschSchet*> (this);                                
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
int TDMSprRaschSchetImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprRaschSchetImpl::kanRelease(void)                                  
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
int  TDMSprRaschSchetImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprRaschSchetImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprRaschSchetImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprRaschSchetImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprRaschSchetImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprRaschSchetImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprRaschSchetImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprRaschSchetImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprRaschSchetImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprRaschSchetImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprRaschSchetImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprRaschSchetImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprRaschSchetImpl::get_TableIDRSCHET(void)
{
return Object->TableIDRSCHET;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TableIDRSCHET(TFIBBCDField * TableIDRSCHET)
{
Object->TableIDRSCHET=TableIDRSCHET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprRaschSchetImpl::get_TableIDKLRSCHET(void)
{
return Object->TableIDKLRSCHET;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TableIDKLRSCHET(TFIBBCDField * TableIDKLRSCHET)
{
Object->TableIDKLRSCHET=TableIDKLRSCHET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprRaschSchetImpl::get_TableIDBANKRSCHET(void)
{
return Object->TableIDBANKRSCHET;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TableIDBANKRSCHET(TFIBBCDField * TableIDBANKRSCHET)
{
Object->TableIDBANKRSCHET=TableIDBANKRSCHET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprRaschSchetImpl::get_TableIDBANK(void)
{
return Object->TableIDBANK;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TableIDBANK(TFIBBCDField * TableIDBANK)
{
Object->TableIDBANK=TableIDBANK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprRaschSchetImpl::get_ElementIDRSCHET(void)
{
return Object->ElementIDRSCHET;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_ElementIDRSCHET(TFIBBCDField * ElementIDRSCHET)
{
Object->ElementIDRSCHET=ElementIDRSCHET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprRaschSchetImpl::get_ElementIDKLRSCHET(void)
{
return Object->ElementIDKLRSCHET;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_ElementIDKLRSCHET(TFIBBCDField * ElementIDKLRSCHET)
{
Object->ElementIDKLRSCHET=ElementIDKLRSCHET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprRaschSchetImpl::get_ElementIDBANKRSCHET(void)
{
return Object->ElementIDBANKRSCHET;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_ElementIDBANKRSCHET(TFIBBCDField * ElementIDBANKRSCHET)
{
Object->ElementIDBANKRSCHET=ElementIDBANKRSCHET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprRaschSchetImpl::get_ElementIDBANK(void)
{
return Object->ElementIDBANK;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_ElementIDBANK(TFIBBCDField * ElementIDBANK)
{
Object->ElementIDBANK=ElementIDBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_TableNAMERSCHET(void)
{
return Object->TableNAMERSCHET;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TableNAMERSCHET(TFIBWideStringField * TableNAMERSCHET)
{
Object->TableNAMERSCHET=TableNAMERSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_TableNUMRSCHET(void)
{
return Object->TableNUMRSCHET;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TableNUMRSCHET(TFIBWideStringField * TableNUMRSCHET)
{
Object->TableNUMRSCHET=TableNUMRSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_TableGID_SRSCHET(void)
{
return Object->TableGID_SRSCHET;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TableGID_SRSCHET(TFIBWideStringField * TableGID_SRSCHET)
{
Object->TableGID_SRSCHET=TableGID_SRSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_TableNAMEBANK(void)
{
return Object->TableNAMEBANK;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TableNAMEBANK(TFIBWideStringField * TableNAMEBANK)
{
Object->TableNAMEBANK=TableNAMEBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_TableBIKBANK(void)
{
return Object->TableBIKBANK;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TableBIKBANK(TFIBWideStringField * TableBIKBANK)
{
Object->TableBIKBANK=TableBIKBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_TableGORBANK(void)
{
return Object->TableGORBANK;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TableGORBANK(TFIBWideStringField * TableGORBANK)
{
Object->TableGORBANK=TableGORBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_TableKSBANK(void)
{
return Object->TableKSBANK;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_TableKSBANK(TFIBWideStringField * TableKSBANK)
{
Object->TableKSBANK=TableKSBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_ElementNAMERSCHET(void)
{
return Object->ElementNAMERSCHET;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_ElementNAMERSCHET(TFIBWideStringField * ElementNAMERSCHET)
{
Object->ElementNAMERSCHET=ElementNAMERSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_ElementNUMRSCHET(void)
{
return Object->ElementNUMRSCHET;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_ElementNUMRSCHET(TFIBWideStringField * ElementNUMRSCHET)
{
Object->ElementNUMRSCHET=ElementNUMRSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_ElementGID_SRSCHET(void)
{
return Object->ElementGID_SRSCHET;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_ElementGID_SRSCHET(TFIBWideStringField * ElementGID_SRSCHET)
{
Object->ElementGID_SRSCHET=ElementGID_SRSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_ElementNAMEBANK(void)
{
return Object->ElementNAMEBANK;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_ElementNAMEBANK(TFIBWideStringField * ElementNAMEBANK)
{
Object->ElementNAMEBANK=ElementNAMEBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_ElementBIKBANK(void)
{
return Object->ElementBIKBANK;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_ElementBIKBANK(TFIBWideStringField * ElementBIKBANK)
{
Object->ElementBIKBANK=ElementBIKBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_ElementGORBANK(void)
{
return Object->ElementGORBANK;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_ElementGORBANK(TFIBWideStringField * ElementGORBANK)
{
Object->ElementGORBANK=ElementGORBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprRaschSchetImpl::get_ElementKSBANK(void)
{
return Object->ElementKSBANK;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::set_ElementKSBANK(TFIBWideStringField * ElementKSBANK)
{
Object->ElementKSBANK=ElementKSBANK;
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::OpenTable(__int64 IdKlient)
{
return Object->OpenTable(IdKlient);
}
//---------------------------------------------------------------
int TDMSprRaschSchetImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::NewElement(__int64 IdKlient)
{
return Object->NewElement(IdKlient);
}
//---------------------------------------------------------------
bool TDMSprRaschSchetImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprRaschSchetImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
