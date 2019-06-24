#include "vcl.h"
#pragma hdrstop


#include "UREM_DMGurCustQueryDetalImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMGurCustQueryDetalImpl::TREM_DMGurCustQueryDetalImpl()           
{                                            
Object=new TREM_DMGurCustQueryDetal(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMGurCustQueryDetalImpl::~TREM_DMGurCustQueryDetalImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMGurCustQueryDetalImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMGurCustQueryDetal)                        
   {                                                                     
   *ppv=static_cast<IREM_DMGurCustQueryDetal*> (this);                                
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
int TREM_DMGurCustQueryDetalImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMGurCustQueryDetalImpl::kanRelease(void)                                  
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
int  TREM_DMGurCustQueryDetalImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMGurCustQueryDetalImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMGurCustQueryDetalImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMGurCustQueryDetalImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMGurCustQueryDetalImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMGurCustQueryDetal
TDataSource * TREM_DMGurCustQueryDetalImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMGurCustQueryDetalImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMGurCustQueryDetalImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMGurCustQueryDetalImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryDetalImpl::get_TableID_REM_CQUERY(void)
{
return Object->TableID_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableID_REM_CQUERY(TFIBLargeIntField * TableID_REM_CQUERY)
{
Object->TableID_REM_CQUERY=TableID_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableGID_REM_CQUERY(void)
{
return Object->TableGID_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableGID_REM_CQUERY(TFIBWideStringField * TableGID_REM_CQUERY)
{
Object->TableGID_REM_CQUERY=TableGID_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryDetalImpl::get_TableIDBASE_REM_CQUERY(void)
{
return Object->TableIDBASE_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableIDBASE_REM_CQUERY(TFIBLargeIntField * TableIDBASE_REM_CQUERY)
{
Object->TableIDBASE_REM_CQUERY=TableIDBASE_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurCustQueryDetalImpl::get_TablePOS_REM_CQUERY(void)
{
return Object->TablePOS_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TablePOS_REM_CQUERY(TFIBDateTimeField * TablePOS_REM_CQUERY)
{
Object->TablePOS_REM_CQUERY=TablePOS_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurCustQueryDetalImpl::get_TableNUM_REM_CQUERY(void)
{
return Object->TableNUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNUM_REM_CQUERY(TFIBIntegerField * TableNUM_REM_CQUERY)
{
Object->TableNUM_REM_CQUERY=TableNUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryDetalImpl::get_TableIDFIRM_REM_CQUERY(void)
{
return Object->TableIDFIRM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableIDFIRM_REM_CQUERY(TFIBLargeIntField * TableIDFIRM_REM_CQUERY)
{
Object->TableIDFIRM_REM_CQUERY=TableIDFIRM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryDetalImpl::get_TableIDSKLAD_REM_CQUERY(void)
{
return Object->TableIDSKLAD_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableIDSKLAD_REM_CQUERY(TFIBLargeIntField * TableIDSKLAD_REM_CQUERY)
{
Object->TableIDSKLAD_REM_CQUERY=TableIDSKLAD_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryDetalImpl::get_TableIDUSER_REM_CQUERY(void)
{
return Object->TableIDUSER_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableIDUSER_REM_CQUERY(TFIBLargeIntField * TableIDUSER_REM_CQUERY)
{
Object->TableIDUSER_REM_CQUERY=TableIDUSER_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryDetalImpl::get_TableIDKLIENT_REM_CQUERY(void)
{
return Object->TableIDKLIENT_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableIDKLIENT_REM_CQUERY(TFIBLargeIntField * TableIDKLIENT_REM_CQUERY)
{
Object->TableIDKLIENT_REM_CQUERY=TableIDKLIENT_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableKLIENT_NAME_REM_CQUERY(void)
{
return Object->TableKLIENT_NAME_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableKLIENT_NAME_REM_CQUERY(TFIBWideStringField * TableKLIENT_NAME_REM_CQUERY)
{
Object->TableKLIENT_NAME_REM_CQUERY=TableKLIENT_NAME_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableKLIENT_ADR_REM_CQUERY(void)
{
return Object->TableKLIENT_ADR_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableKLIENT_ADR_REM_CQUERY(TFIBWideStringField * TableKLIENT_ADR_REM_CQUERY)
{
Object->TableKLIENT_ADR_REM_CQUERY=TableKLIENT_ADR_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableKLIENT_PHONE_REM_CQUERY(void)
{
return Object->TableKLIENT_PHONE_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableKLIENT_PHONE_REM_CQUERY(TFIBWideStringField * TableKLIENT_PHONE_REM_CQUERY)
{
Object->TableKLIENT_PHONE_REM_CQUERY=TableKLIENT_PHONE_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableCOMMENTS_REM_CQUERY(void)
{
return Object->TableCOMMENTS_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableCOMMENTS_REM_CQUERY(TFIBWideStringField * TableCOMMENTS_REM_CQUERY)
{
Object->TableCOMMENTS_REM_CQUERY=TableCOMMENTS_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurCustQueryDetalImpl::get_TableRUN_REM_CQUERY(void)
{
return Object->TableRUN_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableRUN_REM_CQUERY(TFIBSmallIntField * TableRUN_REM_CQUERY)
{
Object->TableRUN_REM_CQUERY=TableRUN_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurCustQueryDetalImpl::get_TableDO_SUM_REM_CQUERY(void)
{
return Object->TableDO_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableDO_SUM_REM_CQUERY(TFIBBCDField * TableDO_SUM_REM_CQUERY)
{
Object->TableDO_SUM_REM_CQUERY=TableDO_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurCustQueryDetalImpl::get_TableTEC_SUM_REM_CQUERY(void)
{
return Object->TableTEC_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableTEC_SUM_REM_CQUERY(TFIBBCDField * TableTEC_SUM_REM_CQUERY)
{
Object->TableTEC_SUM_REM_CQUERY=TableTEC_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurCustQueryDetalImpl::get_TableSOGL_SUM_REM_CQUERY(void)
{
return Object->TableSOGL_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableSOGL_SUM_REM_CQUERY(TFIBBCDField * TableSOGL_SUM_REM_CQUERY)
{
Object->TableSOGL_SUM_REM_CQUERY=TableSOGL_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryDetalImpl::get_TableIDZ_REM_CQUERY(void)
{
return Object->TableIDZ_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableIDZ_REM_CQUERY(TFIBLargeIntField * TableIDZ_REM_CQUERY)
{
Object->TableIDZ_REM_CQUERY=TableIDZ_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryDetalImpl::get_TableIDMODEL_REM_CQUERY(void)
{
return Object->TableIDMODEL_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableIDMODEL_REM_CQUERY(TFIBLargeIntField * TableIDMODEL_REM_CQUERY)
{
Object->TableIDMODEL_REM_CQUERY=TableIDMODEL_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNAME_MODEL_REM_CQUERY(void)
{
return Object->TableNAME_MODEL_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNAME_MODEL_REM_CQUERY(TFIBWideStringField * TableNAME_MODEL_REM_CQUERY)
{
Object->TableNAME_MODEL_REM_CQUERY=TableNAME_MODEL_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNAME_REM_SMODEL(void)
{
return Object->TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)
{
Object->TableNAME_REM_SMODEL=TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryDetalImpl::get_TableIDBRAND_REM_CQUERY(void)
{
return Object->TableIDBRAND_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableIDBRAND_REM_CQUERY(TFIBLargeIntField * TableIDBRAND_REM_CQUERY)
{
Object->TableIDBRAND_REM_CQUERY=TableIDBRAND_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryDetalImpl::get_TableIDPRODUCER_REM_CQUERY(void)
{
return Object->TableIDPRODUCER_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableIDPRODUCER_REM_CQUERY(TFIBLargeIntField * TableIDPRODUCER_REM_CQUERY)
{
Object->TableIDPRODUCER_REM_CQUERY=TableIDPRODUCER_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurCustQueryDetalImpl::get_TableFL_KLIENT_UVEDOML_REM_CQUERY(void)
{
return Object->TableFL_KLIENT_UVEDOML_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableFL_KLIENT_UVEDOML_REM_CQUERY(TFIBSmallIntField * TableFL_KLIENT_UVEDOML_REM_CQUERY)
{
Object->TableFL_KLIENT_UVEDOML_REM_CQUERY=TableFL_KLIENT_UVEDOML_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNAME_SBRAND(void)
{
return Object->TableNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)
{
Object->TableNAME_SBRAND=TableNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNAME_SPRODUCER(void)
{
return Object->TableNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER)
{
Object->TableNAME_SPRODUCER=TableNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurCustQueryDetalImpl::get_TableNUM_ZAKAZA_REM_CQUERY(void)
{
return Object->TableNUM_ZAKAZA_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNUM_ZAKAZA_REM_CQUERY(TFIBIntegerField * TableNUM_ZAKAZA_REM_CQUERY)
{
Object->TableNUM_ZAKAZA_REM_CQUERY=TableNUM_ZAKAZA_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMGurCustQueryDetalImpl::get_TableDATE_ZAKAZA_REM_CQUERY(void)
{
return Object->TableDATE_ZAKAZA_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableDATE_ZAKAZA_REM_CQUERY(TFIBDateField * TableDATE_ZAKAZA_REM_CQUERY)
{
Object->TableDATE_ZAKAZA_REM_CQUERY=TableDATE_ZAKAZA_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurCustQueryDetalImpl::get_TableTYPE_REM_CQUERY(void)
{
return Object->TableTYPE_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableTYPE_REM_CQUERY(TFIBIntegerField * TableTYPE_REM_CQUERY)
{
Object->TableTYPE_REM_CQUERY=TableTYPE_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNAMENOM_REM_CQUERYT(void)
{
return Object->TableNAMENOM_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNAMENOM_REM_CQUERYT(TFIBWideStringField * TableNAMENOM_REM_CQUERYT)
{
Object->TableNAMENOM_REM_CQUERYT=TableNAMENOM_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurCustQueryDetalImpl::get_TableCODENOM(void)
{
return Object->TableCODENOM;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableCODENOM(TFIBIntegerField * TableCODENOM)
{
Object->TableCODENOM=TableCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableARTNOM(void)
{
return Object->TableARTNOM;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableARTNOM(TFIBWideStringField * TableARTNOM)
{
Object->TableARTNOM=TableARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurCustQueryDetalImpl::get_TableKOL_REM_CQUERYT(void)
{
return Object->TableKOL_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableKOL_REM_CQUERYT(TFIBBCDField * TableKOL_REM_CQUERYT)
{
Object->TableKOL_REM_CQUERYT=TableKOL_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurCustQueryDetalImpl::get_TableKF_REM_CQUERYT(void)
{
return Object->TableKF_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableKF_REM_CQUERYT(TFIBBCDField * TableKF_REM_CQUERYT)
{
Object->TableKF_REM_CQUERYT=TableKF_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurCustQueryDetalImpl::get_TablePRICE_REM_CQUERYT(void)
{
return Object->TablePRICE_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TablePRICE_REM_CQUERYT(TFIBBCDField * TablePRICE_REM_CQUERYT)
{
Object->TablePRICE_REM_CQUERYT=TablePRICE_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurCustQueryDetalImpl::get_TableNOM_SUM_STR(void)
{
return Object->TableNOM_SUM_STR;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNOM_SUM_STR(TFIBBCDField * TableNOM_SUM_STR)
{
Object->TableNOM_SUM_STR=TableNOM_SUM_STR;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurCustQueryDetalImpl::get_TableCODE_SPRNOM(void)
{
return Object->TableCODE_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableCODE_SPRNOM(TFIBIntegerField * TableCODE_SPRNOM)
{
Object->TableCODE_SPRNOM=TableCODE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableART_SPRNOM(void)
{
return Object->TableART_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableART_SPRNOM(TFIBWideStringField * TableART_SPRNOM)
{
Object->TableART_SPRNOM=TableART_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNAME_SPRNOM(void)
{
return Object->TableNAME_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNAME_SPRNOM(TFIBWideStringField * TableNAME_SPRNOM)
{
Object->TableNAME_SPRNOM=TableNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurCustQueryDetalImpl::get_TableFL_DOSTUPNO_SPRNOM(void)
{
return Object->TableFL_DOSTUPNO_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableFL_DOSTUPNO_SPRNOM(TFIBSmallIntField * TableFL_DOSTUPNO_SPRNOM)
{
Object->TableFL_DOSTUPNO_SPRNOM=TableFL_DOSTUPNO_SPRNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurCustQueryDetalImpl::get_TablePRICE_ZAKUP_SPRNOM(void)
{
return Object->TablePRICE_ZAKUP_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TablePRICE_ZAKUP_SPRNOM(TFIBBCDField * TablePRICE_ZAKUP_SPRNOM)
{
Object->TablePRICE_ZAKUP_SPRNOM=TablePRICE_ZAKUP_SPRNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurCustQueryDetalImpl::get_TablePRNOM_SUM_STR(void)
{
return Object->TablePRNOM_SUM_STR;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TablePRNOM_SUM_STR(TFIBBCDField * TablePRNOM_SUM_STR)
{
Object->TablePRNOM_SUM_STR=TablePRNOM_SUM_STR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryDetalImpl::get_TableID_REM_CQUERYT(void)
{
return Object->TableID_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableID_REM_CQUERYT(TFIBLargeIntField * TableID_REM_CQUERYT)
{
Object->TableID_REM_CQUERYT=TableID_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TablePRODAVEC_NAME(void)
{
return Object->TablePRODAVEC_NAME;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TablePRODAVEC_NAME(TFIBWideStringField * TablePRODAVEC_NAME)
{
Object->TablePRODAVEC_NAME=TablePRODAVEC_NAME;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNUM_STR_ZAK_POST_REM_CQUERY(void)
{
return Object->TableNUM_STR_ZAK_POST_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNUM_STR_ZAK_POST_REM_CQUERY(TFIBWideStringField * TableNUM_STR_ZAK_POST_REM_CQUERY)
{
Object->TableNUM_STR_ZAK_POST_REM_CQUERY=TableNUM_STR_ZAK_POST_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNUM_STR_ZAK_SPROV_REM_CQUERY(void)
{
return Object->TableNUM_STR_ZAK_SPROV_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNUM_STR_ZAK_SPROV_REM_CQUERY(TFIBWideStringField * TableNUM_STR_ZAK_SPROV_REM_CQUERY)
{
Object->TableNUM_STR_ZAK_SPROV_REM_CQUERY=TableNUM_STR_ZAK_SPROV_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryDetalImpl::get_TableNUMDOCTK_REM_CQUERY(void)
{
return Object->TableNUMDOCTK_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_TableNUMDOCTK_REM_CQUERY(TFIBWideStringField * TableNUMDOCTK_REM_CQUERY)
{
Object->TableNUMDOCTK_REM_CQUERY=TableNUMDOCTK_REM_CQUERY;
}
//---------------------------------------------------------------
bool TREM_DMGurCustQueryDetalImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMGurCustQueryDetalImpl::get_IdCustQuery(void)
{
return Object->IdCustQuery;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_IdCustQuery(__int64 IdCustQuery)
{
Object->IdCustQuery=IdCustQuery;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurCustQueryDetalImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurCustQueryDetalImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
bool TREM_DMGurCustQueryDetalImpl::OpenTableOnlyZayavka(__int64 id_z)
{
return Object->OpenTableOnlyZayavka(id_z);
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::PoiskPoKlient(UnicodeString value)
{
return Object->PoiskPoKlient(value);
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::PoiskPoModel(UnicodeString value)
{
return Object->PoiskPoModel(value);
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::OpenTableGur (__int64 id_user, int poisk, TDateTime pos_nach, TDateTime pos_con, UnicodeString value_str, __int64 value_int64)
{
return Object->OpenTableGur (id_user,  poisk,  pos_nach,  pos_con,  value_str,  value_int64);
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryDetalImpl::OpenTablePoNumZakaza (__int64 id_user, __int64 id_producer,int number_zakaza, TDate date_zakaza)
{
return Object->OpenTablePoNumZakaza (id_user, id_producer, number_zakaza, date_zakaza);
}
//---------------------------------------------------------------
