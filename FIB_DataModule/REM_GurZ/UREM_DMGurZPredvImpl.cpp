#include "vcl.h"
#pragma hdrstop


#include "UREM_DMGurZPredvImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMGurZPredvImpl::TREM_DMGurZPredvImpl()           
{                                            
Object=new TREM_DMGurZPredv(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMGurZPredvImpl::~TREM_DMGurZPredvImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMGurZPredvImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMGurZPredv)                        
   {                                                                     
   *ppv=static_cast<IREM_DMGurZPredv*> (this);                                
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
int TREM_DMGurZPredvImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMGurZPredvImpl::kanRelease(void)                                  
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
int  TREM_DMGurZPredvImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMGurZPredvImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMGurZPredvImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMGurZPredvImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMGurZPredvImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMGurZPredv
TDataSource * TREM_DMGurZPredvImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMGurZPredvImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMGurZPredvImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMGurZPredvImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableID_REM_Z2(void)
{
return Object->TableID_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableID_REM_Z2(TFIBLargeIntField * TableID_REM_Z2)
{
Object->TableID_REM_Z2=TableID_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDBASE_REM_Z2(void)
{
return Object->TableIDBASE_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDBASE_REM_Z2(TFIBLargeIntField * TableIDBASE_REM_Z2)
{
Object->TableIDBASE_REM_Z2=TableIDBASE_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TablePREFIKS_REM_Z2(void)
{
return Object->TablePREFIKS_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TablePREFIKS_REM_Z2(TFIBWideStringField * TablePREFIKS_REM_Z2)
{
Object->TablePREFIKS_REM_Z2=TablePREFIKS_REM_Z2;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZPredvImpl::get_TableNUM_REM_Z2(void)
{
return Object->TableNUM_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableNUM_REM_Z2(TFIBIntegerField * TableNUM_REM_Z2)
{
Object->TableNUM_REM_Z2=TableNUM_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableGUID_REM_Z2(void)
{
return Object->TableGUID_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableGUID_REM_Z2(TFIBWideStringField * TableGUID_REM_Z2)
{
Object->TableGUID_REM_Z2=TableGUID_REM_Z2;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurZPredvImpl::get_TablePOS_REM_Z2(void)
{
return Object->TablePOS_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TablePOS_REM_Z2(TFIBDateTimeField * TablePOS_REM_Z2)
{
Object->TablePOS_REM_Z2=TablePOS_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDMODEL_REM_Z2(void)
{
return Object->TableIDMODEL_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDMODEL_REM_Z2(TFIBLargeIntField * TableIDMODEL_REM_Z2)
{
Object->TableIDMODEL_REM_Z2=TableIDMODEL_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDPRMODEL_REM_Z2(void)
{
return Object->TableIDPRMODEL_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDPRMODEL_REM_Z2(TFIBLargeIntField * TableIDPRMODEL_REM_Z2)
{
Object->TableIDPRMODEL_REM_Z2=TableIDPRMODEL_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDFIRM_REM_Z2(void)
{
return Object->TableIDFIRM_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDFIRM_REM_Z2(TFIBLargeIntField * TableIDFIRM_REM_Z2)
{
Object->TableIDFIRM_REM_Z2=TableIDFIRM_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDSKLPR_REM_Z2(void)
{
return Object->TableIDSKLPR_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDSKLPR_REM_Z2(TFIBLargeIntField * TableIDSKLPR_REM_Z2)
{
Object->TableIDSKLPR_REM_Z2=TableIDSKLPR_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDKLIENT_REM_Z2(void)
{
return Object->TableIDKLIENT_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDKLIENT_REM_Z2(TFIBLargeIntField * TableIDKLIENT_REM_Z2)
{
Object->TableIDKLIENT_REM_Z2=TableIDKLIENT_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDDILER_REM_Z2(void)
{
return Object->TableIDDILER_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDDILER_REM_Z2(TFIBLargeIntField * TableIDDILER_REM_Z2)
{
Object->TableIDDILER_REM_Z2=TableIDDILER_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableNAME_REM_Z2(void)
{
return Object->TableNAME_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableNAME_REM_Z2(TFIBWideStringField * TableNAME_REM_Z2)
{
Object->TableNAME_REM_Z2=TableNAME_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableDESCR_REM_Z2(void)
{
return Object->TableDESCR_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableDESCR_REM_Z2(TFIBWideStringField * TableDESCR_REM_Z2)
{
Object->TableDESCR_REM_Z2=TableDESCR_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableKLIENT_NAME_REM_Z2(void)
{
return Object->TableKLIENT_NAME_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableKLIENT_NAME_REM_Z2(TFIBWideStringField * TableKLIENT_NAME_REM_Z2)
{
Object->TableKLIENT_NAME_REM_Z2=TableKLIENT_NAME_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableKLIENT_ADR_REM_Z2(void)
{
return Object->TableKLIENT_ADR_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableKLIENT_ADR_REM_Z2(TFIBWideStringField * TableKLIENT_ADR_REM_Z2)
{
Object->TableKLIENT_ADR_REM_Z2=TableKLIENT_ADR_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableKLIENT_PHONE_REM_Z2(void)
{
return Object->TableKLIENT_PHONE_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableKLIENT_PHONE_REM_Z2(TFIBWideStringField * TableKLIENT_PHONE_REM_Z2)
{
Object->TableKLIENT_PHONE_REM_Z2=TableKLIENT_PHONE_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableKLIENT_EMAIL_REM_Z2(void)
{
return Object->TableKLIENT_EMAIL_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableKLIENT_EMAIL_REM_Z2(TFIBWideStringField * TableKLIENT_EMAIL_REM_Z2)
{
Object->TableKLIENT_EMAIL_REM_Z2=TableKLIENT_EMAIL_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDBRAND_REM_Z2(void)
{
return Object->TableIDBRAND_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDBRAND_REM_Z2(TFIBLargeIntField * TableIDBRAND_REM_Z2)
{
Object->TableIDBRAND_REM_Z2=TableIDBRAND_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDPRODUCER_REM_Z2(void)
{
return Object->TableIDPRODUCER_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDPRODUCER_REM_Z2(TFIBLargeIntField * TableIDPRODUCER_REM_Z2)
{
Object->TableIDPRODUCER_REM_Z2=TableIDPRODUCER_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableNEISPR_REM_Z2(void)
{
return Object->TableNEISPR_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableNEISPR_REM_Z2(TFIBWideStringField * TableNEISPR_REM_Z2)
{
Object->TableNEISPR_REM_Z2=TableNEISPR_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableSOST_REM_Z2(void)
{
return Object->TableSOST_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableSOST_REM_Z2(TFIBWideStringField * TableSOST_REM_Z2)
{
Object->TableSOST_REM_Z2=TableSOST_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableMODEL_STR_REM_Z2(void)
{
return Object->TableMODEL_STR_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableMODEL_STR_REM_Z2(TFIBWideStringField * TableMODEL_STR_REM_Z2)
{
Object->TableMODEL_STR_REM_Z2=TableMODEL_STR_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableSERNUM1_REM_Z2(void)
{
return Object->TableSERNUM1_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableSERNUM1_REM_Z2(TFIBWideStringField * TableSERNUM1_REM_Z2)
{
Object->TableSERNUM1_REM_Z2=TableSERNUM1_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableSERNUM2_REM_Z2(void)
{
return Object->TableSERNUM2_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableSERNUM2_REM_Z2(TFIBWideStringField * TableSERNUM2_REM_Z2)
{
Object->TableSERNUM2_REM_Z2=TableSERNUM2_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDKKT_REM_Z2(void)
{
return Object->TableIDKKT_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDKKT_REM_Z2(TFIBLargeIntField * TableIDKKT_REM_Z2)
{
Object->TableIDKKT_REM_Z2=TableIDKKT_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDHW_REM_Z2(void)
{
return Object->TableIDHW_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDHW_REM_Z2(TFIBLargeIntField * TableIDHW_REM_Z2)
{
Object->TableIDHW_REM_Z2=TableIDHW_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDSELLER_REM_Z2(void)
{
return Object->TableIDSELLER_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDSELLER_REM_Z2(TFIBLargeIntField * TableIDSELLER_REM_Z2)
{
Object->TableIDSELLER_REM_Z2=TableIDSELLER_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableDOPOPISANIE_REM_Z2(void)
{
return Object->TableDOPOPISANIE_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableDOPOPISANIE_REM_Z2(TFIBWideStringField * TableDOPOPISANIE_REM_Z2)
{
Object->TableDOPOPISANIE_REM_Z2=TableDOPOPISANIE_REM_Z2;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurZPredvImpl::get_TableSUMKLIENTA_REM_Z2(void)
{
return Object->TableSUMKLIENTA_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableSUMKLIENTA_REM_Z2(TFIBBCDField * TableSUMKLIENTA_REM_Z2)
{
Object->TableSUMKLIENTA_REM_Z2=TableSUMKLIENTA_REM_Z2;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurZPredvImpl::get_TableSUMNACHA_REM_Z2(void)
{
return Object->TableSUMNACHA_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableSUMNACHA_REM_Z2(TFIBBCDField * TableSUMNACHA_REM_Z2)
{
Object->TableSUMNACHA_REM_Z2=TableSUMNACHA_REM_Z2;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZPredvImpl::get_TableRESULT_REM_Z2(void)
{
return Object->TableRESULT_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableRESULT_REM_Z2(TFIBIntegerField * TableRESULT_REM_Z2)
{
Object->TableRESULT_REM_Z2=TableRESULT_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TablePRICHINA_REM_Z2(void)
{
return Object->TablePRICHINA_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TablePRICHINA_REM_Z2(TFIBWideStringField * TablePRICHINA_REM_Z2)
{
Object->TablePRICHINA_REM_Z2=TablePRICHINA_REM_Z2;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZPredvImpl::get_TablePRICHINA_LIST_REM_Z2(void)
{
return Object->TablePRICHINA_LIST_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TablePRICHINA_LIST_REM_Z2(TFIBIntegerField * TablePRICHINA_LIST_REM_Z2)
{
Object->TablePRICHINA_LIST_REM_Z2=TablePRICHINA_LIST_REM_Z2;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZPredvImpl::get_TableSROK_REM_Z2(void)
{
return Object->TableSROK_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableSROK_REM_Z2(TFIBIntegerField * TableSROK_REM_Z2)
{
Object->TableSROK_REM_Z2=TableSROK_REM_Z2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZPredvImpl::get_TableIDUSER_REM_Z2(void)
{
return Object->TableIDUSER_REM_Z2;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableIDUSER_REM_Z2(TFIBLargeIntField * TableIDUSER_REM_Z2)
{
Object->TableIDUSER_REM_Z2=TableIDUSER_REM_Z2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableNAME_SINFBASE_OBMEN(void)
{
return Object->TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)
{
Object->TableNAME_SINFBASE_OBMEN=TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableNAME_REM_SMODEL(void)
{
return Object->TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)
{
Object->TableNAME_REM_SMODEL=TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableNAME_SKLAD_PR(void)
{
return Object->TableNAME_SKLAD_PR;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableNAME_SKLAD_PR(TFIBWideStringField * TableNAME_SKLAD_PR)
{
Object->TableNAME_SKLAD_PR=TableNAME_SKLAD_PR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableNAMEDILER(void)
{
return Object->TableNAMEDILER;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableNAMEDILER(TFIBWideStringField * TableNAMEDILER)
{
Object->TableNAMEDILER=TableNAMEDILER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZPredvImpl::get_TableNAME_SBRAND(void)
{
return Object->TableNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)
{
Object->TableNAME_SBRAND=TableNAME_SBRAND;
}
//---------------------------------------------------------------
bool TREM_DMGurZPredvImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMGurZPredvImpl::get_IdZ(void)
{
return Object->IdZ;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_IdZ(__int64 IdZ)
{
Object->IdZ=IdZ;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurZPredvImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurZPredvImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::PoiskPoSerNum1(UnicodeString ser_num)
{
return Object->PoiskPoSerNum1(ser_num);
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::PoiskPoSerNum2(UnicodeString ser_num)
{
return Object->PoiskPoSerNum2(ser_num);
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::PoiskPoKlient(UnicodeString value)
{
return Object->PoiskPoKlient(value);
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::PoiskPoModel(UnicodeString value)
{
return Object->PoiskPoModel(value);
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::PoiskPoIdHardware(__int64 id_hw)
{
return Object->PoiskPoIdHardware(id_hw);
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::PoiskPoNumGarDoc(UnicodeString num_gar_doc)
{
return Object->PoiskPoNumGarDoc(num_gar_doc);
}
//---------------------------------------------------------------
void TREM_DMGurZPredvImpl::OpenTableOtbor(TDateTime pos_start,TDateTime pos_end,int poisk,UnicodeString str_value,__int64 int64_value)
{
return Object->OpenTableOtbor(pos_start,pos_end,poisk,str_value,int64_value);
}
//---------------------------------------------------------------
