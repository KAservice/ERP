#include "vcl.h"
#pragma hdrstop


#include "UREM_DMZayavkaPredvImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMZayavkaPredvImpl::TREM_DMZayavkaPredvImpl()           
{                                            
Object=new TREM_DMZayavkaPredv(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMZayavkaPredvImpl::~TREM_DMZayavkaPredvImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMZayavkaPredvImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMZayavkaPredv)                        
   {                                                                     
   *ppv=static_cast<IREM_DMZayavkaPredv*> (this);                                
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
int TREM_DMZayavkaPredvImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMZayavkaPredvImpl::kanRelease(void)                                  
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
int  TREM_DMZayavkaPredvImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMZayavkaPredvImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMZayavkaPredvImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMZayavkaPredvImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMZayavkaPredvImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMZayavkaPredv
TDataSource * TREM_DMZayavkaPredvImpl::get_DataSourceGurZ(void)
{
return Object->DataSourceGurZ;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_DataSourceGurZ(TDataSource * DataSourceGurZ)
{
Object->DataSourceGurZ=DataSourceGurZ;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaPredvImpl::get_GurZ(void)
{
return Object->GurZ;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZ(TpFIBDataSet * GurZ)
{
Object->GurZ=GurZ;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMZayavkaPredvImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMZayavkaPredvImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaPredvImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZID_REM_Z2(void)
{
return Object->GurZID_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZID_REM_Z2(TFIBLargeIntField * GurZID_REM_Z2)
{
Object->GurZID_REM_Z2=GurZID_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDBASE_REM_Z2(void)
{
return Object->GurZIDBASE_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDBASE_REM_Z2(TFIBLargeIntField * GurZIDBASE_REM_Z2)
{
Object->GurZIDBASE_REM_Z2=GurZIDBASE_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZPREFIKS_REM_Z2(void)
{
return Object->GurZPREFIKS_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZPREFIKS_REM_Z2(TFIBWideStringField * GurZPREFIKS_REM_Z2)
{
Object->GurZPREFIKS_REM_Z2=GurZPREFIKS_REM_Z2;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaPredvImpl::get_GurZNUM_REM_Z2(void)
{
return Object->GurZNUM_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNUM_REM_Z2(TFIBIntegerField * GurZNUM_REM_Z2)
{
Object->GurZNUM_REM_Z2=GurZNUM_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZGUID_REM_Z2(void)
{
return Object->GurZGUID_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZGUID_REM_Z2(TFIBWideStringField * GurZGUID_REM_Z2)
{
Object->GurZGUID_REM_Z2=GurZGUID_REM_Z2;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMZayavkaPredvImpl::get_GurZPOS_REM_Z2(void)
{
return Object->GurZPOS_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZPOS_REM_Z2(TFIBDateTimeField * GurZPOS_REM_Z2)
{
Object->GurZPOS_REM_Z2=GurZPOS_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDMODEL_REM_Z2(void)
{
return Object->GurZIDMODEL_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDMODEL_REM_Z2(TFIBLargeIntField * GurZIDMODEL_REM_Z2)
{
Object->GurZIDMODEL_REM_Z2=GurZIDMODEL_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDPRMODEL_REM_Z2(void)
{
return Object->GurZIDPRMODEL_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDPRMODEL_REM_Z2(TFIBLargeIntField * GurZIDPRMODEL_REM_Z2)
{
Object->GurZIDPRMODEL_REM_Z2=GurZIDPRMODEL_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDFIRM_REM_Z2(void)
{
return Object->GurZIDFIRM_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDFIRM_REM_Z2(TFIBLargeIntField * GurZIDFIRM_REM_Z2)
{
Object->GurZIDFIRM_REM_Z2=GurZIDFIRM_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDSKLPR_REM_Z2(void)
{
return Object->GurZIDSKLPR_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDSKLPR_REM_Z2(TFIBLargeIntField * GurZIDSKLPR_REM_Z2)
{
Object->GurZIDSKLPR_REM_Z2=GurZIDSKLPR_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDKLIENT_REM_Z2(void)
{
return Object->GurZIDKLIENT_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDKLIENT_REM_Z2(TFIBLargeIntField * GurZIDKLIENT_REM_Z2)
{
Object->GurZIDKLIENT_REM_Z2=GurZIDKLIENT_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDDILER_REM_Z2(void)
{
return Object->GurZIDDILER_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDDILER_REM_Z2(TFIBLargeIntField * GurZIDDILER_REM_Z2)
{
Object->GurZIDDILER_REM_Z2=GurZIDDILER_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZNAME_REM_Z2(void)
{
return Object->GurZNAME_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNAME_REM_Z2(TFIBWideStringField * GurZNAME_REM_Z2)
{
Object->GurZNAME_REM_Z2=GurZNAME_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZDESCR_REM_Z2(void)
{
return Object->GurZDESCR_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZDESCR_REM_Z2(TFIBWideStringField * GurZDESCR_REM_Z2)
{
Object->GurZDESCR_REM_Z2=GurZDESCR_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZKLIENT_NAME_REM_Z2(void)
{
return Object->GurZKLIENT_NAME_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZKLIENT_NAME_REM_Z2(TFIBWideStringField * GurZKLIENT_NAME_REM_Z2)
{
Object->GurZKLIENT_NAME_REM_Z2=GurZKLIENT_NAME_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZKLIENT_ADR_REM_Z2(void)
{
return Object->GurZKLIENT_ADR_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZKLIENT_ADR_REM_Z2(TFIBWideStringField * GurZKLIENT_ADR_REM_Z2)
{
Object->GurZKLIENT_ADR_REM_Z2=GurZKLIENT_ADR_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZKLIENT_PHONE_REM_Z2(void)
{
return Object->GurZKLIENT_PHONE_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZKLIENT_PHONE_REM_Z2(TFIBWideStringField * GurZKLIENT_PHONE_REM_Z2)
{
Object->GurZKLIENT_PHONE_REM_Z2=GurZKLIENT_PHONE_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZKLIENT_EMAIL_REM_Z2(void)
{
return Object->GurZKLIENT_EMAIL_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZKLIENT_EMAIL_REM_Z2(TFIBWideStringField * GurZKLIENT_EMAIL_REM_Z2)
{
Object->GurZKLIENT_EMAIL_REM_Z2=GurZKLIENT_EMAIL_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDBRAND_REM_Z2(void)
{
return Object->GurZIDBRAND_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDBRAND_REM_Z2(TFIBLargeIntField * GurZIDBRAND_REM_Z2)
{
Object->GurZIDBRAND_REM_Z2=GurZIDBRAND_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDPRODUCER_REM_Z2(void)
{
return Object->GurZIDPRODUCER_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDPRODUCER_REM_Z2(TFIBLargeIntField * GurZIDPRODUCER_REM_Z2)
{
Object->GurZIDPRODUCER_REM_Z2=GurZIDPRODUCER_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZNEISPR_REM_Z2(void)
{
return Object->GurZNEISPR_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNEISPR_REM_Z2(TFIBWideStringField * GurZNEISPR_REM_Z2)
{
Object->GurZNEISPR_REM_Z2=GurZNEISPR_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZSOST_REM_Z2(void)
{
return Object->GurZSOST_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZSOST_REM_Z2(TFIBWideStringField * GurZSOST_REM_Z2)
{
Object->GurZSOST_REM_Z2=GurZSOST_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZMODEL_STR_REM_Z2(void)
{
return Object->GurZMODEL_STR_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZMODEL_STR_REM_Z2(TFIBWideStringField * GurZMODEL_STR_REM_Z2)
{
Object->GurZMODEL_STR_REM_Z2=GurZMODEL_STR_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZSERNUM1_REM_Z2(void)
{
return Object->GurZSERNUM1_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZSERNUM1_REM_Z2(TFIBWideStringField * GurZSERNUM1_REM_Z2)
{
Object->GurZSERNUM1_REM_Z2=GurZSERNUM1_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZSERNUM2_REM_Z2(void)
{
return Object->GurZSERNUM2_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZSERNUM2_REM_Z2(TFIBWideStringField * GurZSERNUM2_REM_Z2)
{
Object->GurZSERNUM2_REM_Z2=GurZSERNUM2_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDKKT_REM_Z2(void)
{
return Object->GurZIDKKT_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDKKT_REM_Z2(TFIBLargeIntField * GurZIDKKT_REM_Z2)
{
Object->GurZIDKKT_REM_Z2=GurZIDKKT_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDHW_REM_Z2(void)
{
return Object->GurZIDHW_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDHW_REM_Z2(TFIBLargeIntField * GurZIDHW_REM_Z2)
{
Object->GurZIDHW_REM_Z2=GurZIDHW_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDSELLER_REM_Z2(void)
{
return Object->GurZIDSELLER_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDSELLER_REM_Z2(TFIBLargeIntField * GurZIDSELLER_REM_Z2)
{
Object->GurZIDSELLER_REM_Z2=GurZIDSELLER_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZDOPOPISANIE_REM_Z2(void)
{
return Object->GurZDOPOPISANIE_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZDOPOPISANIE_REM_Z2(TFIBWideStringField * GurZDOPOPISANIE_REM_Z2)
{
Object->GurZDOPOPISANIE_REM_Z2=GurZDOPOPISANIE_REM_Z2;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaPredvImpl::get_GurZSUMKLIENTA_REM_Z2(void)
{
return Object->GurZSUMKLIENTA_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZSUMKLIENTA_REM_Z2(TFIBBCDField * GurZSUMKLIENTA_REM_Z2)
{
Object->GurZSUMKLIENTA_REM_Z2=GurZSUMKLIENTA_REM_Z2;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaPredvImpl::get_GurZSUMNACHA_REM_Z2(void)
{
return Object->GurZSUMNACHA_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZSUMNACHA_REM_Z2(TFIBBCDField * GurZSUMNACHA_REM_Z2)
{
Object->GurZSUMNACHA_REM_Z2=GurZSUMNACHA_REM_Z2;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaPredvImpl::get_GurZRESULT_REM_Z2(void)
{
return Object->GurZRESULT_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZRESULT_REM_Z2(TFIBIntegerField * GurZRESULT_REM_Z2)
{
Object->GurZRESULT_REM_Z2=GurZRESULT_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZPRICHINA_REM_Z2(void)
{
return Object->GurZPRICHINA_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZPRICHINA_REM_Z2(TFIBWideStringField * GurZPRICHINA_REM_Z2)
{
Object->GurZPRICHINA_REM_Z2=GurZPRICHINA_REM_Z2;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaPredvImpl::get_GurZPRICHINA_LIST_REM_Z2(void)
{
return Object->GurZPRICHINA_LIST_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZPRICHINA_LIST_REM_Z2(TFIBIntegerField * GurZPRICHINA_LIST_REM_Z2)
{
Object->GurZPRICHINA_LIST_REM_Z2=GurZPRICHINA_LIST_REM_Z2;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaPredvImpl::get_GurZSROK_REM_Z2(void)
{
return Object->GurZSROK_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZSROK_REM_Z2(TFIBIntegerField * GurZSROK_REM_Z2)
{
Object->GurZSROK_REM_Z2=GurZSROK_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaPredvImpl::get_GurZIDUSER_REM_Z2(void)
{
return Object->GurZIDUSER_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZIDUSER_REM_Z2(TFIBLargeIntField * GurZIDUSER_REM_Z2)
{
Object->GurZIDUSER_REM_Z2=GurZIDUSER_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZNAMEFIRM(void)
{
return Object->GurZNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNAMEFIRM(TFIBWideStringField * GurZNAMEFIRM)
{
Object->GurZNAMEFIRM=GurZNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZNAME_SINFBASE_OBMEN(void)
{
return Object->GurZNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNAME_SINFBASE_OBMEN(TFIBWideStringField * GurZNAME_SINFBASE_OBMEN)
{
Object->GurZNAME_SINFBASE_OBMEN=GurZNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZNAME_REM_SMODEL(void)
{
return Object->GurZNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNAME_REM_SMODEL(TFIBWideStringField * GurZNAME_REM_SMODEL)
{
Object->GurZNAME_REM_SMODEL=GurZNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZNAME_SKLAD_PR(void)
{
return Object->GurZNAME_SKLAD_PR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNAME_SKLAD_PR(TFIBWideStringField * GurZNAME_SKLAD_PR)
{
Object->GurZNAME_SKLAD_PR=GurZNAME_SKLAD_PR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZNAMEKLIENT(void)
{
return Object->GurZNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNAMEKLIENT(TFIBWideStringField * GurZNAMEKLIENT)
{
Object->GurZNAMEKLIENT=GurZNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZNAMEDILER(void)
{
return Object->GurZNAMEDILER;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNAMEDILER(TFIBWideStringField * GurZNAMEDILER)
{
Object->GurZNAMEDILER=GurZNAMEDILER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZNAME_USER(void)
{
return Object->GurZNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNAME_USER(TFIBWideStringField * GurZNAME_USER)
{
Object->GurZNAME_USER=GurZNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZNAME_SBRAND(void)
{
return Object->GurZNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNAME_SBRAND(TFIBWideStringField * GurZNAME_SBRAND)
{
Object->GurZNAME_SBRAND=GurZNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZNAME_REM_SHARDWARE(void)
{
return Object->GurZNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNAME_REM_SHARDWARE(TFIBWideStringField * GurZNAME_REM_SHARDWARE)
{
Object->GurZNAME_REM_SHARDWARE=GurZNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZSERNUM_REM_SHARDWARE(void)
{
return Object->GurZSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZSERNUM_REM_SHARDWARE(TFIBWideStringField * GurZSERNUM_REM_SHARDWARE)
{
Object->GurZSERNUM_REM_SHARDWARE=GurZSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZSERNUM2_REM_SHARDWARE(void)
{
return Object->GurZSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZSERNUM2_REM_SHARDWARE(TFIBWideStringField * GurZSERNUM2_REM_SHARDWARE)
{
Object->GurZSERNUM2_REM_SHARDWARE=GurZSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZNAME_REM_SKKT(void)
{
return Object->GurZNAME_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZNAME_REM_SKKT(TFIBWideStringField * GurZNAME_REM_SKKT)
{
Object->GurZNAME_REM_SKKT=GurZNAME_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaPredvImpl::get_GurZSERNUM_REM_SKKT(void)
{
return Object->GurZSERNUM_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_GurZSERNUM_REM_SKKT(TFIBWideStringField * GurZSERNUM_REM_SKKT)
{
Object->GurZSERNUM_REM_SKKT=GurZSERNUM_REM_SKKT;
}
//---------------------------------------------------------------
bool TREM_DMZayavkaPredvImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMZayavkaPredvImpl::get_IdZ(void)
{
return Object->IdZ;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_IdZ(__int64 IdZ)
{
Object->IdZ=IdZ;
}
//---------------------------------------------------------------
bool TREM_DMZayavkaPredvImpl::get_flChangeData(void)
{
return Object->flChangeData;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::set_flChangeData(bool flChangeData)
{
Object->flChangeData=flChangeData;
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMZayavkaPredvImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMZayavkaPredvImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void TREM_DMZayavkaPredvImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
