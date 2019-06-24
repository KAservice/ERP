#include "vcl.h"
#pragma hdrstop


#include "UDMSprFirmImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprFirmImpl::TDMSprFirmImpl()           
{                                            
Object=new TDMSprFirm(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprFirmImpl::~TDMSprFirmImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprFirmImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprFirmImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprFirm)                        
   {                                                                     
   *ppv=static_cast<IDMSprFirm*> (this);                                
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
int TDMSprFirmImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprFirmImpl::kanRelease(void)                                  
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
int  TDMSprFirmImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprFirmImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprFirmImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprFirmImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprFirmImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprFirmImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprFirmImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprFirm
TDataSource * TDMSprFirmImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TDataSource * TDMSprFirmImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprFirmImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprFirmImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprFirmImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprFirmImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprFirmImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprFirmImpl::get_ElementTYPEFIRM(void)
{
return Object->ElementTYPEFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementTYPEFIRM(TFIBSmallIntField * ElementTYPEFIRM)
{
Object->ElementTYPEFIRM=ElementTYPEFIRM;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprFirmImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprFirmImpl::get_TableIDFIRM(void)
{
return Object->TableIDFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_TableIDFIRM(TFIBBCDField * TableIDFIRM)
{
Object->TableIDFIRM=TableIDFIRM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprFirmImpl::get_ElementIDFIRM(void)
{
return Object->ElementIDFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementIDFIRM(TFIBBCDField * ElementIDFIRM)
{
Object->ElementIDFIRM=ElementIDFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_TableINNFIRM(void)
{
return Object->TableINNFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_TableINNFIRM(TFIBWideStringField * TableINNFIRM)
{
Object->TableINNFIRM=TableINNFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementNAMEFIRM(void)
{
return Object->ElementNAMEFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM)
{
Object->ElementNAMEFIRM=ElementNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementFNAMEFIRM(void)
{
return Object->ElementFNAMEFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementFNAMEFIRM(TFIBWideStringField * ElementFNAMEFIRM)
{
Object->ElementFNAMEFIRM=ElementFNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementPADRFIRM(void)
{
return Object->ElementPADRFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementPADRFIRM(TFIBWideStringField * ElementPADRFIRM)
{
Object->ElementPADRFIRM=ElementPADRFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementUADRFIRM(void)
{
return Object->ElementUADRFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementUADRFIRM(TFIBWideStringField * ElementUADRFIRM)
{
Object->ElementUADRFIRM=ElementUADRFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementINNFIRM(void)
{
return Object->ElementINNFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementINNFIRM(TFIBWideStringField * ElementINNFIRM)
{
Object->ElementINNFIRM=ElementINNFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementKPPFIRM(void)
{
return Object->ElementKPPFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementKPPFIRM(TFIBWideStringField * ElementKPPFIRM)
{
Object->ElementKPPFIRM=ElementKPPFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementDIRFIRM(void)
{
return Object->ElementDIRFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementDIRFIRM(TFIBWideStringField * ElementDIRFIRM)
{
Object->ElementDIRFIRM=ElementDIRFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementBUHFIRM(void)
{
return Object->ElementBUHFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementBUHFIRM(TFIBWideStringField * ElementBUHFIRM)
{
Object->ElementBUHFIRM=ElementBUHFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementKASFIRM(void)
{
return Object->ElementKASFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementKASFIRM(TFIBWideStringField * ElementKASFIRM)
{
Object->ElementKASFIRM=ElementKASFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementGID_SFIRM(void)
{
return Object->ElementGID_SFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementGID_SFIRM(TFIBWideStringField * ElementGID_SFIRM)
{
Object->ElementGID_SFIRM=ElementGID_SFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementNUMDOCREGFIRM(void)
{
return Object->ElementNUMDOCREGFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementNUMDOCREGFIRM(TFIBWideStringField * ElementNUMDOCREGFIRM)
{
Object->ElementNUMDOCREGFIRM=ElementNUMDOCREGFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementOKPOSFIRM(void)
{
return Object->ElementOKPOSFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementOKPOSFIRM(TFIBWideStringField * ElementOKPOSFIRM)
{
Object->ElementOKPOSFIRM=ElementOKPOSFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementOKDPSFIRM(void)
{
return Object->ElementOKDPSFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementOKDPSFIRM(TFIBWideStringField * ElementOKDPSFIRM)
{
Object->ElementOKDPSFIRM=ElementOKDPSFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementTELFIRM(void)
{
return Object->ElementTELFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementTELFIRM(TFIBWideStringField * ElementTELFIRM)
{
Object->ElementTELFIRM=ElementTELFIRM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprFirmImpl::get_ElementIDBASE_SFIRM(void)
{
return Object->ElementIDBASE_SFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementIDBASE_SFIRM(TFIBBCDField * ElementIDBASE_SFIRM)
{
Object->ElementIDBASE_SFIRM=ElementIDBASE_SFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementKRNAMEFIRM(void)
{
return Object->ElementKRNAMEFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementKRNAMEFIRM(TFIBWideStringField * ElementKRNAMEFIRM)
{
Object->ElementKRNAMEFIRM=ElementKRNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementDATEDOCREGFIRM(void)
{
return Object->ElementDATEDOCREGFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementDATEDOCREGFIRM(TFIBWideStringField * ElementDATEDOCREGFIRM)
{
Object->ElementDATEDOCREGFIRM=ElementDATEDOCREGFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFirmImpl::get_ElementPREFIKS_NUM_SFIRM(void)
{
return Object->ElementPREFIKS_NUM_SFIRM;
}
//---------------------------------------------------------------
void TDMSprFirmImpl::set_ElementPREFIKS_NUM_SFIRM(TFIBWideStringField * ElementPREFIKS_NUM_SFIRM)
{
Object->ElementPREFIKS_NUM_SFIRM=ElementPREFIKS_NUM_SFIRM;
}
//---------------------------------------------------------------
bool TDMSprFirmImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprFirmImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
bool TDMSprFirmImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprFirmImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprFirmImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
UnicodeString TDMSprFirmImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprFirmImpl::GetIDElement(AnsiString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
int TDMSprFirmImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
