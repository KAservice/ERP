#include "vcl.h"
#pragma hdrstop


#include "UREM_DMGurVigrusokImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMGurVigrusokImpl::TREM_DMGurVigrusokImpl()           
{                                            
Object=new TREM_DMGurVigrusok(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMGurVigrusokImpl::~TREM_DMGurVigrusokImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMGurVigrusokImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMGurVigrusok)                        
   {                                                                     
   *ppv=static_cast<IREM_DMGurVigrusok*> (this);                                
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
int TREM_DMGurVigrusokImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMGurVigrusokImpl::kanRelease(void)                                  
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
int  TREM_DMGurVigrusokImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMGurVigrusokImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMGurVigrusokImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMGurVigrusokImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMGurVigrusokImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMGurVigrusok
TDataSource * TREM_DMGurVigrusokImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMGurVigrusokImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMGurVigrusokImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMGurVigrusokImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMGurVigrusokImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurVigrusokImpl::get_TableID_REM_GUR_VIGR(void)
{
return Object->TableID_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableID_REM_GUR_VIGR(TFIBLargeIntField * TableID_REM_GUR_VIGR)
{
Object->TableID_REM_GUR_VIGR=TableID_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurVigrusokImpl::get_TableIDBASE_REM_GUR_VIGR(void)
{
return Object->TableIDBASE_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableIDBASE_REM_GUR_VIGR(TFIBLargeIntField * TableIDBASE_REM_GUR_VIGR)
{
Object->TableIDBASE_REM_GUR_VIGR=TableIDBASE_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurVigrusokImpl::get_TableIDUSER_REM_GUR_VIGR(void)
{
return Object->TableIDUSER_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableIDUSER_REM_GUR_VIGR(TFIBLargeIntField * TableIDUSER_REM_GUR_VIGR)
{
Object->TableIDUSER_REM_GUR_VIGR=TableIDUSER_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurVigrusokImpl::get_TablePOS_REM_GUR_VIGR(void)
{
return Object->TablePOS_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TablePOS_REM_GUR_VIGR(TFIBDateTimeField * TablePOS_REM_GUR_VIGR)
{
Object->TablePOS_REM_GUR_VIGR=TablePOS_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurVigrusokImpl::get_TableNUM_REM_GUR_VIGR(void)
{
return Object->TableNUM_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableNUM_REM_GUR_VIGR(TFIBIntegerField * TableNUM_REM_GUR_VIGR)
{
Object->TableNUM_REM_GUR_VIGR=TableNUM_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurVigrusokImpl::get_TableGUID_TRANSACTION_REM_GUR_VIGR(void)
{
return Object->TableGUID_TRANSACTION_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableGUID_TRANSACTION_REM_GUR_VIGR(TFIBWideStringField * TableGUID_TRANSACTION_REM_GUR_VIGR)
{
Object->TableGUID_TRANSACTION_REM_GUR_VIGR=TableGUID_TRANSACTION_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurVigrusokImpl::get_TableCODE_STR_VIGR_REM_GUR_VIGR(void)
{
return Object->TableCODE_STR_VIGR_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableCODE_STR_VIGR_REM_GUR_VIGR(TFIBWideStringField * TableCODE_STR_VIGR_REM_GUR_VIGR)
{
Object->TableCODE_STR_VIGR_REM_GUR_VIGR=TableCODE_STR_VIGR_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurVigrusokImpl::get_TableGUID_VIGR_REM_GUR_VIGR(void)
{
return Object->TableGUID_VIGR_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableGUID_VIGR_REM_GUR_VIGR(TFIBWideStringField * TableGUID_VIGR_REM_GUR_VIGR)
{
Object->TableGUID_VIGR_REM_GUR_VIGR=TableGUID_VIGR_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurVigrusokImpl::get_TableIDKLIENT_REM_GUR_VIGR(void)
{
return Object->TableIDKLIENT_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableIDKLIENT_REM_GUR_VIGR(TFIBLargeIntField * TableIDKLIENT_REM_GUR_VIGR)
{
Object->TableIDKLIENT_REM_GUR_VIGR=TableIDKLIENT_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurVigrusokImpl::get_TableIDPRODUCER_REM_GUR_VIGR(void)
{
return Object->TableIDPRODUCER_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableIDPRODUCER_REM_GUR_VIGR(TFIBLargeIntField * TableIDPRODUCER_REM_GUR_VIGR)
{
Object->TableIDPRODUCER_REM_GUR_VIGR=TableIDPRODUCER_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurVigrusokImpl::get_TableNAME_SPRODUCER(void)
{
return Object->TableNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER)
{
Object->TableNAME_SPRODUCER=TableNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurVigrusokImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurVigrusokImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurVigrusokImpl::get_TableNAME_SINFBASE_OBMEN(void)
{
return Object->TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)
{
Object->TableNAME_SINFBASE_OBMEN=TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurVigrusokImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurVigrusokImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 TREM_DMGurVigrusokImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_DMGurVigrusokImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
__int64 TREM_DMGurVigrusokImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TREM_DMGurVigrusokImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
UnicodeString TREM_DMGurVigrusokImpl::get_StringTypeDoc(void)
{
return Object->StringTypeDoc;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_StringTypeDoc(UnicodeString StringTypeDoc)
{
Object->StringTypeDoc=StringTypeDoc;
}
//---------------------------------------------------------------
bool TREM_DMGurVigrusokImpl::get_OtborVkl(void)
{
return Object->OtborVkl;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::set_OtborVkl(bool OtborVkl)
{
Object->OtborVkl=OtborVkl;
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TREM_DMGurVigrusokImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
