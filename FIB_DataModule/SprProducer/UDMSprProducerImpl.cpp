#include "vcl.h"
#pragma hdrstop


#include "UDMSprProducerImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprProducerImpl::TDMSprProducerImpl()           
{                                            
Object=new TDMSprProducer(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprProducerImpl::~TDMSprProducerImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprProducerImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprProducerImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprProducer)                        
   {                                                                     
   *ppv=static_cast<IDMSprProducer*> (this);                                
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
int TDMSprProducerImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprProducerImpl::kanRelease(void)                                  
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
int  TDMSprProducerImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProducerImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprProducerImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProducerImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprProducerImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprProducerImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprProducerImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprProducer
TDataSource * TDMSprProducerImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprProducerImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProducerImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProducerImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprProducerImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprProducerImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerImpl::get_TableID_SPRODUCER(void)
{
return Object->TableID_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_TableID_SPRODUCER(TFIBLargeIntField * TableID_SPRODUCER)
{
Object->TableID_SPRODUCER=TableID_SPRODUCER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerImpl::get_TableIDBASE_SPRODUCER(void)
{
return Object->TableIDBASE_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_TableIDBASE_SPRODUCER(TFIBLargeIntField * TableIDBASE_SPRODUCER)
{
Object->TableIDBASE_SPRODUCER=TableIDBASE_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_TableGID_SPRODUCER(void)
{
return Object->TableGID_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_TableGID_SPRODUCER(TFIBWideStringField * TableGID_SPRODUCER)
{
Object->TableGID_SPRODUCER=TableGID_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_TableNAME_SPRODUCER(void)
{
return Object->TableNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER)
{
Object->TableNAME_SPRODUCER=TableNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerImpl::get_TableIDKLIENT_SPRODUCER(void)
{
return Object->TableIDKLIENT_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_TableIDKLIENT_SPRODUCER(TFIBLargeIntField * TableIDKLIENT_SPRODUCER)
{
Object->TableIDKLIENT_SPRODUCER=TableIDKLIENT_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_TableINNKLIENT(void)
{
return Object->TableINNKLIENT;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_TableINNKLIENT(TFIBWideStringField * TableINNKLIENT)
{
Object->TableINNKLIENT=TableINNKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerImpl::get_ElementID_SPRODUCER(void)
{
return Object->ElementID_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementID_SPRODUCER(TFIBLargeIntField * ElementID_SPRODUCER)
{
Object->ElementID_SPRODUCER=ElementID_SPRODUCER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerImpl::get_ElementIDBASE_SPRODUCER(void)
{
return Object->ElementIDBASE_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementIDBASE_SPRODUCER(TFIBLargeIntField * ElementIDBASE_SPRODUCER)
{
Object->ElementIDBASE_SPRODUCER=ElementIDBASE_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_ElementGID_SPRODUCER(void)
{
return Object->ElementGID_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementGID_SPRODUCER(TFIBWideStringField * ElementGID_SPRODUCER)
{
Object->ElementGID_SPRODUCER=ElementGID_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_ElementNAME_SPRODUCER(void)
{
return Object->ElementNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementNAME_SPRODUCER(TFIBWideStringField * ElementNAME_SPRODUCER)
{
Object->ElementNAME_SPRODUCER=ElementNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerImpl::get_ElementIDKLIENT_SPRODUCER(void)
{
return Object->ElementIDKLIENT_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementIDKLIENT_SPRODUCER(TFIBLargeIntField * ElementIDKLIENT_SPRODUCER)
{
Object->ElementIDKLIENT_SPRODUCER=ElementIDKLIENT_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerImpl::get_ElementIDPOST_ZIP_SPRODUCER(void)
{
return Object->ElementIDPOST_ZIP_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementIDPOST_ZIP_SPRODUCER(TFIBLargeIntField * ElementIDPOST_ZIP_SPRODUCER)
{
Object->ElementIDPOST_ZIP_SPRODUCER=ElementIDPOST_ZIP_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_ElementPOST_ZIP_NAME(void)
{
return Object->ElementPOST_ZIP_NAME;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementPOST_ZIP_NAME(TFIBWideStringField * ElementPOST_ZIP_NAME)
{
Object->ElementPOST_ZIP_NAME=ElementPOST_ZIP_NAME;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprProducerImpl::get_TablePOSZAGRNOM_SPRODUCER(void)
{
return Object->TablePOSZAGRNOM_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_TablePOSZAGRNOM_SPRODUCER(TFIBDateTimeField * TablePOSZAGRNOM_SPRODUCER)
{
Object->TablePOSZAGRNOM_SPRODUCER=TablePOSZAGRNOM_SPRODUCER;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprProducerImpl::get_ElementPOSZAGRNOM_SPRODUCER(void)
{
return Object->ElementPOSZAGRNOM_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementPOSZAGRNOM_SPRODUCER(TFIBDateTimeField * ElementPOSZAGRNOM_SPRODUCER)
{
Object->ElementPOSZAGRNOM_SPRODUCER=ElementPOSZAGRNOM_SPRODUCER;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProducerImpl::get_ElementTYPE_POISK_SPRNOM_SPRODUCER(void)
{
return Object->ElementTYPE_POISK_SPRNOM_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementTYPE_POISK_SPRNOM_SPRODUCER(TFIBIntegerField * ElementTYPE_POISK_SPRNOM_SPRODUCER)
{
Object->ElementTYPE_POISK_SPRNOM_SPRODUCER=ElementTYPE_POISK_SPRNOM_SPRODUCER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerImpl::get_ElementIDINETCAT_USL_SPRODUCER(void)
{
return Object->ElementIDINETCAT_USL_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementIDINETCAT_USL_SPRODUCER(TFIBLargeIntField * ElementIDINETCAT_USL_SPRODUCER)
{
Object->ElementIDINETCAT_USL_SPRODUCER=ElementIDINETCAT_USL_SPRODUCER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerImpl::get_ElementIDGRPINETCAT_USL_SPRODUCER(void)
{
return Object->ElementIDGRPINETCAT_USL_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementIDGRPINETCAT_USL_SPRODUCER(TFIBLargeIntField * ElementIDGRPINETCAT_USL_SPRODUCER)
{
Object->ElementIDGRPINETCAT_USL_SPRODUCER=ElementIDGRPINETCAT_USL_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_ElementNAME_SINETCATALOG(void)
{
return Object->ElementNAME_SINETCATALOG;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementNAME_SINETCATALOG(TFIBWideStringField * ElementNAME_SINETCATALOG)
{
Object->ElementNAME_SINETCATALOG=ElementNAME_SINETCATALOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_ElementNAME_SNOMINETCAT_GRP(void)
{
return Object->ElementNAME_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementNAME_SNOMINETCAT_GRP(TFIBWideStringField * ElementNAME_SNOMINETCAT_GRP)
{
Object->ElementNAME_SNOMINETCAT_GRP=ElementNAME_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerImpl::get_ElementIDGRPNOM_ZIP_SPRODUCER(void)
{
return Object->ElementIDGRPNOM_ZIP_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementIDGRPNOM_ZIP_SPRODUCER(TFIBLargeIntField * ElementIDGRPNOM_ZIP_SPRODUCER)
{
Object->ElementIDGRPNOM_ZIP_SPRODUCER=ElementIDGRPNOM_ZIP_SPRODUCER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerImpl::get_ElementIDGRPNOM_RAB_SPRODUCER(void)
{
return Object->ElementIDGRPNOM_RAB_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementIDGRPNOM_RAB_SPRODUCER(TFIBLargeIntField * ElementIDGRPNOM_RAB_SPRODUCER)
{
Object->ElementIDGRPNOM_RAB_SPRODUCER=ElementIDGRPNOM_RAB_SPRODUCER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerImpl::get_ElementIDGRP_HW_SPRODUCER(void)
{
return Object->ElementIDGRP_HW_SPRODUCER;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementIDGRP_HW_SPRODUCER(TFIBLargeIntField * ElementIDGRP_HW_SPRODUCER)
{
Object->ElementIDGRP_HW_SPRODUCER=ElementIDGRP_HW_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_ElementNAMEGN(void)
{
return Object->ElementNAMEGN;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementNAMEGN(TFIBWideStringField * ElementNAMEGN)
{
Object->ElementNAMEGN=ElementNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_ElementRAB_NAMEGN(void)
{
return Object->ElementRAB_NAMEGN;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementRAB_NAMEGN(TFIBWideStringField * ElementRAB_NAMEGN)
{
Object->ElementRAB_NAMEGN=ElementRAB_NAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerImpl::get_ElementNAME_REM_SGRP_HARDWARE(void)
{
return Object->ElementNAME_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
void TDMSprProducerImpl::set_ElementNAME_REM_SGRP_HARDWARE(TFIBWideStringField * ElementNAME_REM_SGRP_HARDWARE)
{
Object->ElementNAME_REM_SGRP_HARDWARE=ElementNAME_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
bool TDMSprProducerImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
bool TDMSprProducerImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprProducerImpl::NewElement()
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprProducerImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprProducerImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TDMSprProducerImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprProducerImpl::GetIdElementPoName(UnicodeString   name)
{
return Object->GetIdElementPoName(name);
}
//---------------------------------------------------------------
int TDMSprProducerImpl::GetIndexInTablePoId(__int64 id_element)
{
return Object->GetIndexInTablePoId(id_element);
}
//---------------------------------------------------------------
__int64 TDMSprProducerImpl::GetIdElementPoGid(UnicodeString gid)
{
return Object->GetIdElementPoGid(gid);
}
//---------------------------------------------------------------
UnicodeString TDMSprProducerImpl::GetGidElementPoId(__int64 id)
{
return Object->GetGidElementPoId(id);
}
//---------------------------------------------------------------
