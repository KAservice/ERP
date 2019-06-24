#include "vcl.h"
#pragma hdrstop


#include "UREM_DMGurCustQueryImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMGurCustQueryImpl::TREM_DMGurCustQueryImpl()           
{                                            
Object=new TREM_DMGurCustQuery(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMGurCustQueryImpl::~TREM_DMGurCustQueryImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMGurCustQueryImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMGurCustQuery)                        
   {                                                                     
   *ppv=static_cast<IREM_DMGurCustQuery*> (this);                                
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
int TREM_DMGurCustQueryImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMGurCustQueryImpl::kanRelease(void)                                  
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
int  TREM_DMGurCustQueryImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMGurCustQueryImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMGurCustQueryImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMGurCustQueryImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMGurCustQueryImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMGurCustQuery
TDataSource * TREM_DMGurCustQueryImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMGurCustQueryImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMGurCustQueryImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMGurCustQueryImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryImpl::get_TableID_REM_CQUERY(void)
{
return Object->TableID_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableID_REM_CQUERY(TFIBLargeIntField * TableID_REM_CQUERY)
{
Object->TableID_REM_CQUERY=TableID_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableGID_REM_CQUERY(void)
{
return Object->TableGID_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableGID_REM_CQUERY(TFIBWideStringField * TableGID_REM_CQUERY)
{
Object->TableGID_REM_CQUERY=TableGID_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryImpl::get_TableIDBASE_REM_CQUERY(void)
{
return Object->TableIDBASE_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableIDBASE_REM_CQUERY(TFIBLargeIntField * TableIDBASE_REM_CQUERY)
{
Object->TableIDBASE_REM_CQUERY=TableIDBASE_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurCustQueryImpl::get_TablePOS_REM_CQUERY(void)
{
return Object->TablePOS_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TablePOS_REM_CQUERY(TFIBDateTimeField * TablePOS_REM_CQUERY)
{
Object->TablePOS_REM_CQUERY=TablePOS_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurCustQueryImpl::get_TableNUM_REM_CQUERY(void)
{
return Object->TableNUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableNUM_REM_CQUERY(TFIBIntegerField * TableNUM_REM_CQUERY)
{
Object->TableNUM_REM_CQUERY=TableNUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryImpl::get_TableIDFIRM_REM_CQUERY(void)
{
return Object->TableIDFIRM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableIDFIRM_REM_CQUERY(TFIBLargeIntField * TableIDFIRM_REM_CQUERY)
{
Object->TableIDFIRM_REM_CQUERY=TableIDFIRM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryImpl::get_TableIDSKLAD_REM_CQUERY(void)
{
return Object->TableIDSKLAD_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableIDSKLAD_REM_CQUERY(TFIBLargeIntField * TableIDSKLAD_REM_CQUERY)
{
Object->TableIDSKLAD_REM_CQUERY=TableIDSKLAD_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryImpl::get_TableIDUSER_REM_CQUERY(void)
{
return Object->TableIDUSER_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableIDUSER_REM_CQUERY(TFIBLargeIntField * TableIDUSER_REM_CQUERY)
{
Object->TableIDUSER_REM_CQUERY=TableIDUSER_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryImpl::get_TableIDKLIENT_REM_CQUERY(void)
{
return Object->TableIDKLIENT_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableIDKLIENT_REM_CQUERY(TFIBLargeIntField * TableIDKLIENT_REM_CQUERY)
{
Object->TableIDKLIENT_REM_CQUERY=TableIDKLIENT_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableKLIENT_NAME_REM_CQUERY(void)
{
return Object->TableKLIENT_NAME_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableKLIENT_NAME_REM_CQUERY(TFIBWideStringField * TableKLIENT_NAME_REM_CQUERY)
{
Object->TableKLIENT_NAME_REM_CQUERY=TableKLIENT_NAME_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableKLIENT_ADR_REM_CQUERY(void)
{
return Object->TableKLIENT_ADR_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableKLIENT_ADR_REM_CQUERY(TFIBWideStringField * TableKLIENT_ADR_REM_CQUERY)
{
Object->TableKLIENT_ADR_REM_CQUERY=TableKLIENT_ADR_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableKLIENT_PHONE_REM_CQUERY(void)
{
return Object->TableKLIENT_PHONE_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableKLIENT_PHONE_REM_CQUERY(TFIBWideStringField * TableKLIENT_PHONE_REM_CQUERY)
{
Object->TableKLIENT_PHONE_REM_CQUERY=TableKLIENT_PHONE_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableCOMMENTS_REM_CQUERY(void)
{
return Object->TableCOMMENTS_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableCOMMENTS_REM_CQUERY(TFIBWideStringField * TableCOMMENTS_REM_CQUERY)
{
Object->TableCOMMENTS_REM_CQUERY=TableCOMMENTS_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurCustQueryImpl::get_TableRUN_REM_CQUERY(void)
{
return Object->TableRUN_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableRUN_REM_CQUERY(TFIBSmallIntField * TableRUN_REM_CQUERY)
{
Object->TableRUN_REM_CQUERY=TableRUN_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurCustQueryImpl::get_TableDO_SUM_REM_CQUERY(void)
{
return Object->TableDO_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableDO_SUM_REM_CQUERY(TFIBBCDField * TableDO_SUM_REM_CQUERY)
{
Object->TableDO_SUM_REM_CQUERY=TableDO_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurCustQueryImpl::get_TableTEC_SUM_REM_CQUERY(void)
{
return Object->TableTEC_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableTEC_SUM_REM_CQUERY(TFIBBCDField * TableTEC_SUM_REM_CQUERY)
{
Object->TableTEC_SUM_REM_CQUERY=TableTEC_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurCustQueryImpl::get_TableSOGL_SUM_REM_CQUERY(void)
{
return Object->TableSOGL_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableSOGL_SUM_REM_CQUERY(TFIBBCDField * TableSOGL_SUM_REM_CQUERY)
{
Object->TableSOGL_SUM_REM_CQUERY=TableSOGL_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryImpl::get_TableIDZ_REM_CQUERY(void)
{
return Object->TableIDZ_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableIDZ_REM_CQUERY(TFIBLargeIntField * TableIDZ_REM_CQUERY)
{
Object->TableIDZ_REM_CQUERY=TableIDZ_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryImpl::get_TableIDMODEL_REM_CQUERY(void)
{
return Object->TableIDMODEL_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableIDMODEL_REM_CQUERY(TFIBLargeIntField * TableIDMODEL_REM_CQUERY)
{
Object->TableIDMODEL_REM_CQUERY=TableIDMODEL_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableNAME_MODEL_REM_CQUERY(void)
{
return Object->TableNAME_MODEL_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableNAME_MODEL_REM_CQUERY(TFIBWideStringField * TableNAME_MODEL_REM_CQUERY)
{
Object->TableNAME_MODEL_REM_CQUERY=TableNAME_MODEL_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableNAME_REM_SMODEL(void)
{
return Object->TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)
{
Object->TableNAME_REM_SMODEL=TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryImpl::get_TableIDBRAND_REM_CQUERY(void)
{
return Object->TableIDBRAND_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableIDBRAND_REM_CQUERY(TFIBLargeIntField * TableIDBRAND_REM_CQUERY)
{
Object->TableIDBRAND_REM_CQUERY=TableIDBRAND_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurCustQueryImpl::get_TableIDPRODUCER_REM_CQUERY(void)
{
return Object->TableIDPRODUCER_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableIDPRODUCER_REM_CQUERY(TFIBLargeIntField * TableIDPRODUCER_REM_CQUERY)
{
Object->TableIDPRODUCER_REM_CQUERY=TableIDPRODUCER_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurCustQueryImpl::get_TableFL_KLIENT_UVEDOML_REM_CQUERY(void)
{
return Object->TableFL_KLIENT_UVEDOML_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableFL_KLIENT_UVEDOML_REM_CQUERY(TFIBSmallIntField * TableFL_KLIENT_UVEDOML_REM_CQUERY)
{
Object->TableFL_KLIENT_UVEDOML_REM_CQUERY=TableFL_KLIENT_UVEDOML_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableNAME_SBRAND(void)
{
return Object->TableNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)
{
Object->TableNAME_SBRAND=TableNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurCustQueryImpl::get_TableNAME_SPRODUCER(void)
{
return Object->TableNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER)
{
Object->TableNAME_SPRODUCER=TableNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurCustQueryImpl::get_TableNUM_ZAKAZA_REM_CQUERY(void)
{
return Object->TableNUM_ZAKAZA_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableNUM_ZAKAZA_REM_CQUERY(TFIBIntegerField * TableNUM_ZAKAZA_REM_CQUERY)
{
Object->TableNUM_ZAKAZA_REM_CQUERY=TableNUM_ZAKAZA_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMGurCustQueryImpl::get_TableDATE_ZAKAZA_REM_CQUERY(void)
{
return Object->TableDATE_ZAKAZA_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableDATE_ZAKAZA_REM_CQUERY(TFIBDateField * TableDATE_ZAKAZA_REM_CQUERY)
{
Object->TableDATE_ZAKAZA_REM_CQUERY=TableDATE_ZAKAZA_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurCustQueryImpl::get_TableTYPE_REM_CQUERY(void)
{
return Object->TableTYPE_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_TableTYPE_REM_CQUERY(TFIBIntegerField * TableTYPE_REM_CQUERY)
{
Object->TableTYPE_REM_CQUERY=TableTYPE_REM_CQUERY;
}
//---------------------------------------------------------------
bool TREM_DMGurCustQueryImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMGurCustQueryImpl::get_IdCustQuery(void)
{
return Object->IdCustQuery;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_IdCustQuery(__int64 IdCustQuery)
{
Object->IdCustQuery=IdCustQuery;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurCustQueryImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurCustQueryImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
bool TREM_DMGurCustQueryImpl::OpenTableOnlyZayavka(__int64 id_z)
{
return Object->OpenTableOnlyZayavka(id_z);
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::PoiskPoKlient(UnicodeString value)
{
return Object->PoiskPoKlient(value);
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::PoiskPoModel(UnicodeString value)
{
return Object->PoiskPoModel(value);
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::OpenTableGur (__int64 id_user, int poisk, TDateTime pos_nach, TDateTime pos_con, UnicodeString value_str, __int64 value_int64)
{
return Object->OpenTableGur (id_user,poisk,pos_nach,pos_con,value_str,value_int64);
}
//---------------------------------------------------------------
void TREM_DMGurCustQueryImpl::OpenTablePoNumZakaza (__int64 id_user, __int64 id_producer,int number_zakaza, TDate date_zakaza)
{
return Object->OpenTablePoNumZakaza (id_user,id_producer,number_zakaza,date_zakaza);
}
//---------------------------------------------------------------
