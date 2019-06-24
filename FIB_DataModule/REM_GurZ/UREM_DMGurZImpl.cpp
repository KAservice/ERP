#include "vcl.h"
#pragma hdrstop


#include "UREM_DMGurZImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMGurZImpl::TREM_DMGurZImpl()           
{                                            
Object=new TREM_DMGurZ(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMGurZImpl::~TREM_DMGurZImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMGurZImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMGurZImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMGurZ)                        
   {                                                                     
   *ppv=static_cast<IREM_DMGurZ*> (this);                                
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
int TREM_DMGurZImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMGurZImpl::kanRelease(void)                                  
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
int  TREM_DMGurZImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMGurZImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMGurZImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMGurZImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMGurZImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMGurZ
TDataSource * TREM_DMGurZImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMGurZImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMGurZImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMGurZImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableID_REM_Z(void)
{
return Object->TableID_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableID_REM_Z(TFIBLargeIntField * TableID_REM_Z)
{
Object->TableID_REM_Z=TableID_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableGID_REM_Z(void)
{
return Object->TableGID_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableGID_REM_Z(TFIBWideStringField * TableGID_REM_Z)
{
Object->TableGID_REM_Z=TableGID_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TablePREFIKS_REM_Z(void)
{
return Object->TablePREFIKS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TablePREFIKS_REM_Z(TFIBWideStringField * TablePREFIKS_REM_Z)
{
Object->TablePREFIKS_REM_Z=TablePREFIKS_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZImpl::get_TableNUM_REM_Z(void)
{
return Object->TableNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNUM_REM_Z(TFIBIntegerField * TableNUM_REM_Z)
{
Object->TableNUM_REM_Z=TableNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurZImpl::get_TablePOS_REM_Z(void)
{
return Object->TablePOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TablePOS_REM_Z(TFIBDateTimeField * TablePOS_REM_Z)
{
Object->TablePOS_REM_Z=TablePOS_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDBASE_REM_Z(void)
{
return Object->TableIDBASE_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDBASE_REM_Z(TFIBLargeIntField * TableIDBASE_REM_Z)
{
Object->TableIDBASE_REM_Z=TableIDBASE_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDMODEL_REM_Z(void)
{
return Object->TableIDMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDMODEL_REM_Z(TFIBLargeIntField * TableIDMODEL_REM_Z)
{
Object->TableIDMODEL_REM_Z=TableIDMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDSKLPR_REM_Z(void)
{
return Object->TableIDSKLPR_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDSKLPR_REM_Z(TFIBLargeIntField * TableIDSKLPR_REM_Z)
{
Object->TableIDSKLPR_REM_Z=TableIDSKLPR_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDKLIENT_REM_Z(void)
{
return Object->TableIDKLIENT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDKLIENT_REM_Z(TFIBLargeIntField * TableIDKLIENT_REM_Z)
{
Object->TableIDKLIENT_REM_Z=TableIDKLIENT_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDDILER_REM_Z(void)
{
return Object->TableIDDILER_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDDILER_REM_Z(TFIBLargeIntField * TableIDDILER_REM_Z)
{
Object->TableIDDILER_REM_Z=TableIDDILER_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableSERNUM_REM_Z(void)
{
return Object->TableSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableSERNUM_REM_Z(TFIBWideStringField * TableSERNUM_REM_Z)
{
Object->TableSERNUM_REM_Z=TableSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAME_REM_Z(void)
{
return Object->TableNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAME_REM_Z(TFIBWideStringField * TableNAME_REM_Z)
{
Object->TableNAME_REM_Z=TableNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableDESCR_REM_Z(void)
{
return Object->TableDESCR_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableDESCR_REM_Z(TFIBWideStringField * TableDESCR_REM_Z)
{
Object->TableDESCR_REM_Z=TableDESCR_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDTYPEREM_REM_Z(void)
{
return Object->TableIDTYPEREM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDTYPEREM_REM_Z(TFIBLargeIntField * TableIDTYPEREM_REM_Z)
{
Object->TableIDTYPEREM_REM_Z=TableIDTYPEREM_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDSOST_REM_Z(void)
{
return Object->TableIDSOST_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDSOST_REM_Z(TFIBLargeIntField * TableIDSOST_REM_Z)
{
Object->TableIDSOST_REM_Z=TableIDSOST_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDTECSKL_REM_Z(void)
{
return Object->TableIDTECSKL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDTECSKL_REM_Z(TFIBLargeIntField * TableIDTECSKL_REM_Z)
{
Object->TableIDTECSKL_REM_Z=TableIDTECSKL_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDUSER_REM_Z(void)
{
return Object->TableIDUSER_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDUSER_REM_Z(TFIBLargeIntField * TableIDUSER_REM_Z)
{
Object->TableIDUSER_REM_Z=TableIDUSER_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZImpl::get_TableOPER_REM_Z(void)
{
return Object->TableOPER_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableOPER_REM_Z(TFIBIntegerField * TableOPER_REM_Z)
{
Object->TableOPER_REM_Z=TableOPER_REM_Z;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurZImpl::get_TableSUM_REM_Z(void)
{
return Object->TableSUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableSUM_REM_Z(TFIBBCDField * TableSUM_REM_Z)
{
Object->TableSUM_REM_Z=TableSUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMGurZImpl::get_TableSROK_REM_Z(void)
{
return Object->TableSROK_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableSROK_REM_Z(TFIBDateField * TableSROK_REM_Z)
{
Object->TableSROK_REM_Z=TableSROK_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZImpl::get_TableOUT_REM_Z(void)
{
return Object->TableOUT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableOUT_REM_Z(TFIBIntegerField * TableOUT_REM_Z)
{
Object->TableOUT_REM_Z=TableOUT_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDFIRM_REM_Z(void)
{
return Object->TableIDFIRM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDFIRM_REM_Z(TFIBLargeIntField * TableIDFIRM_REM_Z)
{
Object->TableIDFIRM_REM_Z=TableIDFIRM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAME_REM_SMODEL(void)
{
return Object->TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)
{
Object->TableNAME_REM_SMODEL=TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAME_SKLAD_PR(void)
{
return Object->TableNAME_SKLAD_PR;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAME_SKLAD_PR(TFIBWideStringField * TableNAME_SKLAD_PR)
{
Object->TableNAME_SKLAD_PR=TableNAME_SKLAD_PR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAMEDILER(void)
{
return Object->TableNAMEDILER;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAMEDILER(TFIBWideStringField * TableNAMEDILER)
{
Object->TableNAMEDILER=TableNAMEDILER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAME_STREMONT(void)
{
return Object->TableNAME_STREMONT;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAME_STREMONT(TFIBWideStringField * TableNAME_STREMONT)
{
Object->TableNAME_STREMONT=TableNAME_STREMONT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAME_REMSSOST(void)
{
return Object->TableNAME_REMSSOST;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAME_REMSSOST(TFIBWideStringField * TableNAME_REMSSOST)
{
Object->TableNAME_REMSSOST=TableNAME_REMSSOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAME_SKLAD_TEC(void)
{
return Object->TableNAME_SKLAD_TEC;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAME_SKLAD_TEC(TFIBWideStringField * TableNAME_SKLAD_TEC)
{
Object->TableNAME_SKLAD_TEC=TableNAME_SKLAD_TEC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableKLIENT_NAME_REM_Z(void)
{
return Object->TableKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableKLIENT_NAME_REM_Z(TFIBWideStringField * TableKLIENT_NAME_REM_Z)
{
Object->TableKLIENT_NAME_REM_Z=TableKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableMODEL_REM_Z(void)
{
return Object->TableMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableMODEL_REM_Z(TFIBWideStringField * TableMODEL_REM_Z)
{
Object->TableMODEL_REM_Z=TableMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableSERNUM2_REM_Z(void)
{
return Object->TableSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableSERNUM2_REM_Z(TFIBWideStringField * TableSERNUM2_REM_Z)
{
Object->TableSERNUM2_REM_Z=TableSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZImpl::get_TableFL_KLIENT_UVEDOML_REM_Z(void)
{
return Object->TableFL_KLIENT_UVEDOML_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableFL_KLIENT_UVEDOML_REM_Z(TFIBIntegerField * TableFL_KLIENT_UVEDOML_REM_Z)
{
Object->TableFL_KLIENT_UVEDOML_REM_Z=TableFL_KLIENT_UVEDOML_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZImpl::get_TableFL_TREB_KONS_KL_REM_Z(void)
{
return Object->TableFL_TREB_KONS_KL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableFL_TREB_KONS_KL_REM_Z(TFIBIntegerField * TableFL_TREB_KONS_KL_REM_Z)
{
Object->TableFL_TREB_KONS_KL_REM_Z=TableFL_TREB_KONS_KL_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZImpl::get_TableFL_KL_OTV_NA_ZAPROS_REM_Z(void)
{
return Object->TableFL_KL_OTV_NA_ZAPROS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableFL_KL_OTV_NA_ZAPROS_REM_Z(TFIBIntegerField * TableFL_KL_OTV_NA_ZAPROS_REM_Z)
{
Object->TableFL_KL_OTV_NA_ZAPROS_REM_Z=TableFL_KL_OTV_NA_ZAPROS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TablePREFIKS_NUM_REM_Z(void)
{
return Object->TablePREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TablePREFIKS_NUM_REM_Z(TFIBWideStringField * TablePREFIKS_NUM_REM_Z)
{
Object->TablePREFIKS_NUM_REM_Z=TablePREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAME_SINFBASE_OBMEN(void)
{
return Object->TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)
{
Object->TableNAME_SINFBASE_OBMEN=TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDBRAND_REM_Z(void)
{
return Object->TableIDBRAND_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDBRAND_REM_Z(TFIBLargeIntField * TableIDBRAND_REM_Z)
{
Object->TableIDBRAND_REM_Z=TableIDBRAND_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZImpl::get_TableFL_POVTOR_REM_Z(void)
{
return Object->TableFL_POVTOR_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableFL_POVTOR_REM_Z(TFIBSmallIntField * TableFL_POVTOR_REM_Z)
{
Object->TableFL_POVTOR_REM_Z=TableFL_POVTOR_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZImpl::get_TableFL_ADDREPORT_REM_Z(void)
{
return Object->TableFL_ADDREPORT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableFL_ADDREPORT_REM_Z(TFIBSmallIntField * TableFL_ADDREPORT_REM_Z)
{
Object->TableFL_ADDREPORT_REM_Z=TableFL_ADDREPORT_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNUM_GARDOC_REM_Z(void)
{
return Object->TableNUM_GARDOC_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNUM_GARDOC_REM_Z(TFIBWideStringField * TableNUM_GARDOC_REM_Z)
{
Object->TableNUM_GARDOC_REM_Z=TableNUM_GARDOC_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAME_SBRAND(void)
{
return Object->TableNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)
{
Object->TableNAME_SBRAND=TableNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZImpl::get_TableFL_FICTIV_REM_Z(void)
{
return Object->TableFL_FICTIV_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableFL_FICTIV_REM_Z(TFIBIntegerField * TableFL_FICTIV_REM_Z)
{
Object->TableFL_FICTIV_REM_Z=TableFL_FICTIV_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZImpl::get_TableFL_NE_OTCH_REM_Z(void)
{
return Object->TableFL_NE_OTCH_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableFL_NE_OTCH_REM_Z(TFIBSmallIntField * TableFL_NE_OTCH_REM_Z)
{
Object->TableFL_NE_OTCH_REM_Z=TableFL_NE_OTCH_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZImpl::get_TableFL_NADO_OTCH_REM_Z(void)
{
return Object->TableFL_NADO_OTCH_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableFL_NADO_OTCH_REM_Z(TFIBSmallIntField * TableFL_NADO_OTCH_REM_Z)
{
Object->TableFL_NADO_OTCH_REM_Z=TableFL_NADO_OTCH_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZImpl::get_TableSOST_CQUERY(void)
{
return Object->TableSOST_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableSOST_CQUERY(TFIBSmallIntField * TableSOST_CQUERY)
{
Object->TableSOST_CQUERY=TableSOST_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableID_REM_CQUERY(void)
{
return Object->TableID_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableID_REM_CQUERY(TFIBLargeIntField * TableID_REM_CQUERY)
{
Object->TableID_REM_CQUERY=TableID_REM_CQUERY;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMGurZImpl::get_TableSROK_REMONTA(void)
{
return Object->TableSROK_REMONTA;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableSROK_REMONTA(TIntegerField * TableSROK_REMONTA)
{
Object->TableSROK_REMONTA=TableSROK_REMONTA;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMGurZImpl::get_TableSROK_REMONTA_NOW(void)
{
return Object->TableSROK_REMONTA_NOW;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableSROK_REMONTA_NOW(TIntegerField * TableSROK_REMONTA_NOW)
{
Object->TableSROK_REMONTA_NOW=TableSROK_REMONTA_NOW;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurZImpl::get_TablePOSOUT_REM_Z(void)
{
return Object->TablePOSOUT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TablePOSOUT_REM_Z(TFIBDateTimeField * TablePOSOUT_REM_Z)
{
Object->TablePOSOUT_REM_Z=TablePOSOUT_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurZImpl::get_TablePOSREMONT_REM_Z(void)
{
return Object->TablePOSREMONT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TablePOSREMONT_REM_Z(TFIBDateTimeField * TablePOSREMONT_REM_Z)
{
Object->TablePOSREMONT_REM_Z=TablePOSREMONT_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZImpl::get_TableGOTOVO_K_VIDACHE_REM_Z(void)
{
return Object->TableGOTOVO_K_VIDACHE_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableGOTOVO_K_VIDACHE_REM_Z(TFIBSmallIntField * TableGOTOVO_K_VIDACHE_REM_Z)
{
Object->TableGOTOVO_K_VIDACHE_REM_Z=TableGOTOVO_K_VIDACHE_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZImpl::get_TableNAME_SKLAD_OST(void)
{
return Object->TableNAME_SKLAD_OST;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableNAME_SKLAD_OST(TFIBWideStringField * TableNAME_SKLAD_OST)
{
Object->TableNAME_SKLAD_OST=TableNAME_SKLAD_OST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDREC_RGOTPRZ(void)
{
return Object->TableIDREC_RGOTPRZ;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDREC_RGOTPRZ(TFIBLargeIntField * TableIDREC_RGOTPRZ)
{
Object->TableIDREC_RGOTPRZ=TableIDREC_RGOTPRZ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDDOC_VIDACHA_HW(void)
{
return Object->TableIDDOC_VIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDDOC_VIDACHA_HW(TFIBLargeIntField * TableIDDOC_VIDACHA_HW)
{
Object->TableIDDOC_VIDACHA_HW=TableIDDOC_VIDACHA_HW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZImpl::get_TableIDDOC_VOSVRAT_HW(void)
{
return Object->TableIDDOC_VOSVRAT_HW;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_TableIDDOC_VOSVRAT_HW(TFIBLargeIntField * TableIDDOC_VOSVRAT_HW)
{
Object->TableIDDOC_VOSVRAT_HW=TableIDDOC_VOSVRAT_HW;
}
//---------------------------------------------------------------
bool TREM_DMGurZImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMGurZImpl::get_IdZ(void)
{
return Object->IdZ;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_IdZ(__int64 IdZ)
{
Object->IdZ=IdZ;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurZImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurZImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::PoiskPoSerNum1(UnicodeString ser_num)
{
return Object->PoiskPoSerNum1( ser_num);
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::PoiskPoSerNum2(UnicodeString ser_num)
{
return Object->PoiskPoSerNum2(ser_num);
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::PoiskPoKlient(UnicodeString value)
{
return Object->PoiskPoKlient(value);
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::PoiskPoModel(UnicodeString value)
{
return Object->PoiskPoModel(value);
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::PoiskPoIdHardware(__int64 id_hw)
{
return Object->PoiskPoIdHardware(id_hw);
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::PoiskPoNumGarDoc(UnicodeString num_gar_doc)
{
return Object->PoiskPoNumGarDoc(num_gar_doc);
}
//---------------------------------------------------------------
void TREM_DMGurZImpl::OpenTableOtbor(TDateTime pos_start,TDateTime pos_end,int poisk,UnicodeString str_value,__int64 int64_value)
{
return Object->OpenTableOtbor(pos_start,pos_end,poisk,str_value,int64_value);
}
//---------------------------------------------------------------
