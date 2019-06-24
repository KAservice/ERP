#include "vcl.h"
#pragma hdrstop


#include "UDMSprUserImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprUserImpl::TDMSprUserImpl()           
{                                            
Object=new TDMSprUser(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprUserImpl::~TDMSprUserImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprUserImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprUserImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprUser)                        
   {                                                                     
   *ppv=static_cast<IDMSprUser*> (this);                                
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
int TDMSprUserImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprUserImpl::kanRelease(void)                                  
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
int  TDMSprUserImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprUserImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprUserImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprUserImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprUserImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprUserImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprUserImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprUser
TDataSource * TDMSprUserImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprUserImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprUserImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprUserImpl::get_pFIBTr(void)
{
return Object->pFIBTr;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_pFIBTr(TpFIBTransaction * pFIBTr)
{
Object->pFIBTr=pFIBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprUserImpl::get_pFIBTrUpdate(void)
{
return Object->pFIBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_pFIBTrUpdate(TpFIBTransaction * pFIBTrUpdate)
{
Object->pFIBTrUpdate=pFIBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprUserImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprUserImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * TDMSprUserImpl::get_TableUSERID(void)
{
return Object->TableUSERID;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableUSERID(TIntegerField * TableUSERID)
{
Object->TableUSERID=TableUSERID;
}
//---------------------------------------------------------------
TpFIBSecurityService * TDMSprUserImpl::get_pFIBSecurityService1(void)
{
return Object->pFIBSecurityService1;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_pFIBSecurityService1(TpFIBSecurityService * pFIBSecurityService1)
{
Object->pFIBSecurityService1=pFIBSecurityService1;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_TableID_USER(void)
{
return Object->TableID_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableID_USER(TFIBLargeIntField * TableID_USER)
{
Object->TableID_USER=TableID_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_TableIDPOD_USER(void)
{
return Object->TableIDPOD_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableIDPOD_USER(TFIBLargeIntField * TableIDPOD_USER)
{
Object->TableIDPOD_USER=TableIDPOD_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_TableIDFIRM_USER(void)
{
return Object->TableIDFIRM_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableIDFIRM_USER(TFIBLargeIntField * TableIDFIRM_USER)
{
Object->TableIDFIRM_USER=TableIDFIRM_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_TableIDSKLAD_USER(void)
{
return Object->TableIDSKLAD_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableIDSKLAD_USER(TFIBLargeIntField * TableIDSKLAD_USER)
{
Object->TableIDSKLAD_USER=TableIDSKLAD_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_TableIDTPRICE_USER(void)
{
return Object->TableIDTPRICE_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableIDTPRICE_USER(TFIBLargeIntField * TableIDTPRICE_USER)
{
Object->TableIDTPRICE_USER=TableIDTPRICE_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_TableFNAME_USER(void)
{
return Object->TableFNAME_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableFNAME_USER(TFIBWideStringField * TableFNAME_USER)
{
Object->TableFNAME_USER=TableFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_TablePASSWORD_USER(void)
{
return Object->TablePASSWORD_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TablePASSWORD_USER(TFIBWideStringField * TablePASSWORD_USER)
{
Object->TablePASSWORD_USER=TablePASSWORD_USER;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprUserImpl::get_TableINTERF_USER(void)
{
return Object->TableINTERF_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableINTERF_USER(TFIBIntegerField * TableINTERF_USER)
{
Object->TableINTERF_USER=TableINTERF_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_TableIDTPRICE1_USER(void)
{
return Object->TableIDTPRICE1_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableIDTPRICE1_USER(TFIBLargeIntField * TableIDTPRICE1_USER)
{
Object->TableIDTPRICE1_USER=TableIDTPRICE1_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_TableIDTPRICE2_USER(void)
{
return Object->TableIDTPRICE2_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableIDTPRICE2_USER(TFIBLargeIntField * TableIDTPRICE2_USER)
{
Object->TableIDTPRICE2_USER=TableIDTPRICE2_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_TableGID_SUSER(void)
{
return Object->TableGID_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableGID_SUSER(TFIBWideStringField * TableGID_SUSER)
{
Object->TableGID_SUSER=TableGID_SUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_TablePREFIKS_USER(void)
{
return Object->TablePREFIKS_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TablePREFIKS_USER(TFIBWideStringField * TablePREFIKS_USER)
{
Object->TablePREFIKS_USER=TablePREFIKS_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_TableIDBSCHET_USER(void)
{
return Object->TableIDBSCHET_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableIDBSCHET_USER(TFIBLargeIntField * TableIDBSCHET_USER)
{
Object->TableIDBSCHET_USER=TableIDBSCHET_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_TableIDGRP_USER(void)
{
return Object->TableIDGRP_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableIDGRP_USER(TFIBLargeIntField * TableIDGRP_USER)
{
Object->TableIDGRP_USER=TableIDGRP_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_TableNAME2_USER(void)
{
return Object->TableNAME2_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableNAME2_USER(TFIBWideStringField * TableNAME2_USER)
{
Object->TableNAME2_USER=TableNAME2_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_TableIDKASSA_USER(void)
{
return Object->TableIDKASSA_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableIDKASSA_USER(TFIBLargeIntField * TableIDKASSA_USER)
{
Object->TableIDKASSA_USER=TableIDKASSA_USER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableTPOSREPORT_SUSER(void)
{
return Object->TableTPOSREPORT_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableTPOSREPORT_SUSER(TFIBSmallIntField * TableTPOSREPORT_SUSER)
{
Object->TableTPOSREPORT_SUSER=TableTPOSREPORT_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableTPOSGOURNAL_SUSER(void)
{
return Object->TableTPOSGOURNAL_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableTPOSGOURNAL_SUSER(TFIBSmallIntField * TableTPOSGOURNAL_SUSER)
{
Object->TableTPOSGOURNAL_SUSER=TableTPOSGOURNAL_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableKOLDAYREP_SUSER(void)
{
return Object->TableKOLDAYREP_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableKOLDAYREP_SUSER(TFIBSmallIntField * TableKOLDAYREP_SUSER)
{
Object->TableKOLDAYREP_SUSER=TableKOLDAYREP_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableKOLDAYGUR_SUSER(void)
{
return Object->TableKOLDAYGUR_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableKOLDAYGUR_SUSER(TFIBSmallIntField * TableKOLDAYGUR_SUSER)
{
Object->TableKOLDAYGUR_SUSER=TableKOLDAYGUR_SUSER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_TableIDBASE_SUSER(void)
{
return Object->TableIDBASE_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableIDBASE_SUSER(TFIBLargeIntField * TableIDBASE_SUSER)
{
Object->TableIDBASE_SUSER=TableIDBASE_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableUPDGUR_AFTER_CLOSE_DOC_SUSER(void)
{
return Object->TableUPDGUR_AFTER_CLOSE_DOC_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableUPDGUR_AFTER_CLOSE_DOC_SUSER(TFIBSmallIntField * TableUPDGUR_AFTER_CLOSE_DOC_SUSER)
{
Object->TableUPDGUR_AFTER_CLOSE_DOC_SUSER=TableUPDGUR_AFTER_CLOSE_DOC_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableSPRNOM_OST_SUSER(void)
{
return Object->TableSPRNOM_OST_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableSPRNOM_OST_SUSER(TFIBSmallIntField * TableSPRNOM_OST_SUSER)
{
Object->TableSPRNOM_OST_SUSER=TableSPRNOM_OST_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableREOPEN_GUR_SUSER(void)
{
return Object->TableREOPEN_GUR_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableREOPEN_GUR_SUSER(TFIBSmallIntField * TableREOPEN_GUR_SUSER)
{
Object->TableREOPEN_GUR_SUSER=TableREOPEN_GUR_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableREOPEN_SPR_SUSER(void)
{
return Object->TableREOPEN_SPR_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableREOPEN_SPR_SUSER(TFIBSmallIntField * TableREOPEN_SPR_SUSER)
{
Object->TableREOPEN_SPR_SUSER=TableREOPEN_SPR_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableEDIT_CHUG_DOC_SUSER(void)
{
return Object->TableEDIT_CHUG_DOC_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableEDIT_CHUG_DOC_SUSER(TFIBSmallIntField * TableEDIT_CHUG_DOC_SUSER)
{
Object->TableEDIT_CHUG_DOC_SUSER=TableEDIT_CHUG_DOC_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableDEL_CHUG_DOC_SUSER(void)
{
return Object->TableDEL_CHUG_DOC_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableDEL_CHUG_DOC_SUSER(TFIBSmallIntField * TableDEL_CHUG_DOC_SUSER)
{
Object->TableDEL_CHUG_DOC_SUSER=TableDEL_CHUG_DOC_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableSHOW_LOG_SUSER(void)
{
return Object->TableSHOW_LOG_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableSHOW_LOG_SUSER(TFIBSmallIntField * TableSHOW_LOG_SUSER)
{
Object->TableSHOW_LOG_SUSER=TableSHOW_LOG_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableDETALIED_LOG_SUSER(void)
{
return Object->TableDETALIED_LOG_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableDETALIED_LOG_SUSER(TFIBSmallIntField * TableDETALIED_LOG_SUSER)
{
Object->TableDETALIED_LOG_SUSER=TableDETALIED_LOG_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_TableSAVENAME_SUSER(void)
{
return Object->TableSAVENAME_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableSAVENAME_SUSER(TFIBSmallIntField * TableSAVENAME_SUSER)
{
Object->TableSAVENAME_SUSER=TableSAVENAME_SUSER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_TableIDACTCATEGORY_SUSER(void)
{
return Object->TableIDACTCATEGORY_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_TableIDACTCATEGORY_SUSER(TFIBLargeIntField * TableIDACTCATEGORY_SUSER)
{
Object->TableIDACTCATEGORY_SUSER=TableIDACTCATEGORY_SUSER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementID_USER(void)
{
return Object->ElementID_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementID_USER(TFIBLargeIntField * ElementID_USER)
{
Object->ElementID_USER=ElementID_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDPOD_USER(void)
{
return Object->ElementIDPOD_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDPOD_USER(TFIBLargeIntField * ElementIDPOD_USER)
{
Object->ElementIDPOD_USER=ElementIDPOD_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDFIRM_USER(void)
{
return Object->ElementIDFIRM_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDFIRM_USER(TFIBLargeIntField * ElementIDFIRM_USER)
{
Object->ElementIDFIRM_USER=ElementIDFIRM_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDSKLAD_USER(void)
{
return Object->ElementIDSKLAD_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDSKLAD_USER(TFIBLargeIntField * ElementIDSKLAD_USER)
{
Object->ElementIDSKLAD_USER=ElementIDSKLAD_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDTPRICE_USER(void)
{
return Object->ElementIDTPRICE_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDTPRICE_USER(TFIBLargeIntField * ElementIDTPRICE_USER)
{
Object->ElementIDTPRICE_USER=ElementIDTPRICE_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementNAME_USER(void)
{
return Object->ElementNAME_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)
{
Object->ElementNAME_USER=ElementNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementFNAME_USER(void)
{
return Object->ElementFNAME_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementFNAME_USER(TFIBWideStringField * ElementFNAME_USER)
{
Object->ElementFNAME_USER=ElementFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementPASSWORD_USER(void)
{
return Object->ElementPASSWORD_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementPASSWORD_USER(TFIBWideStringField * ElementPASSWORD_USER)
{
Object->ElementPASSWORD_USER=ElementPASSWORD_USER;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprUserImpl::get_ElementINTERF_USER(void)
{
return Object->ElementINTERF_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementINTERF_USER(TFIBIntegerField * ElementINTERF_USER)
{
Object->ElementINTERF_USER=ElementINTERF_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDTPRICE1_USER(void)
{
return Object->ElementIDTPRICE1_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDTPRICE1_USER(TFIBLargeIntField * ElementIDTPRICE1_USER)
{
Object->ElementIDTPRICE1_USER=ElementIDTPRICE1_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDTPRICE2_USER(void)
{
return Object->ElementIDTPRICE2_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDTPRICE2_USER(TFIBLargeIntField * ElementIDTPRICE2_USER)
{
Object->ElementIDTPRICE2_USER=ElementIDTPRICE2_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementGID_SUSER(void)
{
return Object->ElementGID_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementGID_SUSER(TFIBWideStringField * ElementGID_SUSER)
{
Object->ElementGID_SUSER=ElementGID_SUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementPREFIKS_USER(void)
{
return Object->ElementPREFIKS_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementPREFIKS_USER(TFIBWideStringField * ElementPREFIKS_USER)
{
Object->ElementPREFIKS_USER=ElementPREFIKS_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDBSCHET_USER(void)
{
return Object->ElementIDBSCHET_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDBSCHET_USER(TFIBLargeIntField * ElementIDBSCHET_USER)
{
Object->ElementIDBSCHET_USER=ElementIDBSCHET_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDGRP_USER(void)
{
return Object->ElementIDGRP_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDGRP_USER(TFIBLargeIntField * ElementIDGRP_USER)
{
Object->ElementIDGRP_USER=ElementIDGRP_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementNAME2_USER(void)
{
return Object->ElementNAME2_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementNAME2_USER(TFIBWideStringField * ElementNAME2_USER)
{
Object->ElementNAME2_USER=ElementNAME2_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDKASSA_USER(void)
{
return Object->ElementIDKASSA_USER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDKASSA_USER(TFIBLargeIntField * ElementIDKASSA_USER)
{
Object->ElementIDKASSA_USER=ElementIDKASSA_USER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_ElementTPOSREPORT_SUSER(void)
{
return Object->ElementTPOSREPORT_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementTPOSREPORT_SUSER(TFIBSmallIntField * ElementTPOSREPORT_SUSER)
{
Object->ElementTPOSREPORT_SUSER=ElementTPOSREPORT_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_ElementTPOSGOURNAL_SUSER(void)
{
return Object->ElementTPOSGOURNAL_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementTPOSGOURNAL_SUSER(TFIBSmallIntField * ElementTPOSGOURNAL_SUSER)
{
Object->ElementTPOSGOURNAL_SUSER=ElementTPOSGOURNAL_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_ElementKOLDAYREP_SUSER(void)
{
return Object->ElementKOLDAYREP_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementKOLDAYREP_SUSER(TFIBSmallIntField * ElementKOLDAYREP_SUSER)
{
Object->ElementKOLDAYREP_SUSER=ElementKOLDAYREP_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_ElementKOLDAYGUR_SUSER(void)
{
return Object->ElementKOLDAYGUR_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementKOLDAYGUR_SUSER(TFIBSmallIntField * ElementKOLDAYGUR_SUSER)
{
Object->ElementKOLDAYGUR_SUSER=ElementKOLDAYGUR_SUSER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDBASE_SUSER(void)
{
return Object->ElementIDBASE_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDBASE_SUSER(TFIBLargeIntField * ElementIDBASE_SUSER)
{
Object->ElementIDBASE_SUSER=ElementIDBASE_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_ElementUPDGUR_AFTER_CLOSE_DOC_SUSER(void)
{
return Object->ElementUPDGUR_AFTER_CLOSE_DOC_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementUPDGUR_AFTER_CLOSE_DOC_SUSER(TFIBSmallIntField * ElementUPDGUR_AFTER_CLOSE_DOC_SUSER)
{
Object->ElementUPDGUR_AFTER_CLOSE_DOC_SUSER=ElementUPDGUR_AFTER_CLOSE_DOC_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_ElementSPRNOM_OST_SUSER(void)
{
return Object->ElementSPRNOM_OST_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementSPRNOM_OST_SUSER(TFIBSmallIntField * ElementSPRNOM_OST_SUSER)
{
Object->ElementSPRNOM_OST_SUSER=ElementSPRNOM_OST_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_ElementREOPEN_GUR_SUSER(void)
{
return Object->ElementREOPEN_GUR_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementREOPEN_GUR_SUSER(TFIBSmallIntField * ElementREOPEN_GUR_SUSER)
{
Object->ElementREOPEN_GUR_SUSER=ElementREOPEN_GUR_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_ElementREOPEN_SPR_SUSER(void)
{
return Object->ElementREOPEN_SPR_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementREOPEN_SPR_SUSER(TFIBSmallIntField * ElementREOPEN_SPR_SUSER)
{
Object->ElementREOPEN_SPR_SUSER=ElementREOPEN_SPR_SUSER;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprUserImpl::get_ElementEDIT_CHUG_DOC_SUSER(void)
{
return Object->ElementEDIT_CHUG_DOC_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementEDIT_CHUG_DOC_SUSER(TFIBIntegerField * ElementEDIT_CHUG_DOC_SUSER)
{
Object->ElementEDIT_CHUG_DOC_SUSER=ElementEDIT_CHUG_DOC_SUSER;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprUserImpl::get_ElementDEL_CHUG_DOC_SUSER(void)
{
return Object->ElementDEL_CHUG_DOC_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementDEL_CHUG_DOC_SUSER(TFIBIntegerField * ElementDEL_CHUG_DOC_SUSER)
{
Object->ElementDEL_CHUG_DOC_SUSER=ElementDEL_CHUG_DOC_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_ElementSHOW_LOG_SUSER(void)
{
return Object->ElementSHOW_LOG_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementSHOW_LOG_SUSER(TFIBSmallIntField * ElementSHOW_LOG_SUSER)
{
Object->ElementSHOW_LOG_SUSER=ElementSHOW_LOG_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_ElementDETALIED_LOG_SUSER(void)
{
return Object->ElementDETALIED_LOG_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementDETALIED_LOG_SUSER(TFIBSmallIntField * ElementDETALIED_LOG_SUSER)
{
Object->ElementDETALIED_LOG_SUSER=ElementDETALIED_LOG_SUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprUserImpl::get_ElementSAVENAME_SUSER(void)
{
return Object->ElementSAVENAME_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementSAVENAME_SUSER(TFIBSmallIntField * ElementSAVENAME_SUSER)
{
Object->ElementSAVENAME_SUSER=ElementSAVENAME_SUSER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDACTCATEGORY_SUSER(void)
{
return Object->ElementIDACTCATEGORY_SUSER;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDACTCATEGORY_SUSER(TFIBLargeIntField * ElementIDACTCATEGORY_SUSER)
{
Object->ElementIDACTCATEGORY_SUSER=ElementIDACTCATEGORY_SUSER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDPOD(void)
{
return Object->ElementIDPOD;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDPOD(TFIBLargeIntField * ElementIDPOD)
{
Object->ElementIDPOD=ElementIDPOD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementNAMEPOD(void)
{
return Object->ElementNAMEPOD;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementNAMEPOD(TFIBWideStringField * ElementNAMEPOD)
{
Object->ElementNAMEPOD=ElementNAMEPOD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDFIRM(void)
{
return Object->ElementIDFIRM;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDFIRM(TFIBLargeIntField * ElementIDFIRM)
{
Object->ElementIDFIRM=ElementIDFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementNAMEFIRM(void)
{
return Object->ElementNAMEFIRM;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM)
{
Object->ElementNAMEFIRM=ElementNAMEFIRM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementIDSKLAD(void)
{
return Object->ElementIDSKLAD;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementIDSKLAD(TFIBLargeIntField * ElementIDSKLAD)
{
Object->ElementIDSKLAD=ElementIDSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementNAMESKLAD(void)
{
return Object->ElementNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)
{
Object->ElementNAMESKLAD=ElementNAMESKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprUserImpl::get_ElementID_TPRICE(void)
{
return Object->ElementID_TPRICE;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementID_TPRICE(TFIBLargeIntField * ElementID_TPRICE)
{
Object->ElementID_TPRICE=ElementID_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementNAME_TPRICE(void)
{
return Object->ElementNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementNAME_TPRICE(TFIBWideStringField * ElementNAME_TPRICE)
{
Object->ElementNAME_TPRICE=ElementNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementNAME_SINFBASE_OBMEN(void)
{
return Object->ElementNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN)
{
Object->ElementNAME_SINFBASE_OBMEN=ElementNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementNAMEBSCHET(void)
{
return Object->ElementNAMEBSCHET;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementNAMEBSCHET(TFIBWideStringField * ElementNAMEBSCHET)
{
Object->ElementNAMEBSCHET=ElementNAMEBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementNAMEKKM(void)
{
return Object->ElementNAMEKKM;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementNAMEKKM(TFIBWideStringField * ElementNAMEKKM)
{
Object->ElementNAMEKKM=ElementNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprUserImpl::get_ElementNAME_REM_SACTCATEGORY(void)
{
return Object->ElementNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY)
{
Object->ElementNAME_REM_SACTCATEGORY=ElementNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
bool TDMSprUserImpl::get_UserOK(void)
{
return Object->UserOK;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_UserOK(bool UserOK)
{
Object->UserOK=UserOK;
}
//---------------------------------------------------------------
__int64 TDMSprUserImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprUserImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprUserImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
AnsiString TDMSprUserImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
void TDMSprUserImpl::OpenTable(__int64 id_grp,bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
int TDMSprUserImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprUserImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprUserImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprUserImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMSprUserImpl::FindPoName(String NameUser)
{
return Object->FindPoName(NameUser);
}
//---------------------------------------------------------------
__int64 TDMSprUserImpl::FindPoPassword(String Password)
{
return Object->FindPoPassword(Password);
}
//---------------------------------------------------------------
__int64 TDMSprUserImpl::GetIdGrpUser(__int64 id_user)
{
return Object->GetIdGrpUser(id_user);
}
//---------------------------------------------------------------
void TDMSprUserImpl::ChancheGrp(__int64 new_grp)
{
return Object->ChancheGrp(new_grp);
}
//---------------------------------------------------------------
TDateTime TDMSprUserImpl::GetPosNachReport(void)
{
return Object->GetPosNachReport();
}
//---------------------------------------------------------------
TDateTime TDMSprUserImpl::GetPosNachGurnal(void)
{
return Object->GetPosNachGurnal();
}
//---------------------------------------------------------------
