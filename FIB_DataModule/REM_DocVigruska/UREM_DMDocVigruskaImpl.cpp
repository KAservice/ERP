#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocVigruskaImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocVigruskaImpl::TREM_DMDocVigruskaImpl()           
{                                            
Object=new TREM_DMDocVigruska(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocVigruskaImpl::~TREM_DMDocVigruskaImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocVigruskaImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocVigruska)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocVigruska*> (this);                                
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
int TREM_DMDocVigruskaImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocVigruskaImpl::kanRelease(void)                                  
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
int  TREM_DMDocVigruskaImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocVigruskaImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVigruskaImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocVigruskaImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVigruskaImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocVigruska
TDataSource * TREM_DMDocVigruskaImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVigruskaImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVigruskaImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVigruskaImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVigruskaImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVigruskaImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVigruskaImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVigruskaImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVigruskaImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVigruskaImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVigruskaImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVigruskaImpl::get_DocAllID_REM_GUR_VIGR(void)
{
return Object->DocAllID_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllID_REM_GUR_VIGR(TFIBLargeIntField * DocAllID_REM_GUR_VIGR)
{
Object->DocAllID_REM_GUR_VIGR=DocAllID_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVigruskaImpl::get_DocAllIDBASE_REM_GUR_VIGR(void)
{
return Object->DocAllIDBASE_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllIDBASE_REM_GUR_VIGR(TFIBLargeIntField * DocAllIDBASE_REM_GUR_VIGR)
{
Object->DocAllIDBASE_REM_GUR_VIGR=DocAllIDBASE_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVigruskaImpl::get_DocAllIDUSER_REM_GUR_VIGR(void)
{
return Object->DocAllIDUSER_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllIDUSER_REM_GUR_VIGR(TFIBLargeIntField * DocAllIDUSER_REM_GUR_VIGR)
{
Object->DocAllIDUSER_REM_GUR_VIGR=DocAllIDUSER_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVigruskaImpl::get_DocAllPOS_REM_GUR_VIGR(void)
{
return Object->DocAllPOS_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllPOS_REM_GUR_VIGR(TFIBDateTimeField * DocAllPOS_REM_GUR_VIGR)
{
Object->DocAllPOS_REM_GUR_VIGR=DocAllPOS_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVigruskaImpl::get_DocAllNUM_REM_GUR_VIGR(void)
{
return Object->DocAllNUM_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllNUM_REM_GUR_VIGR(TFIBIntegerField * DocAllNUM_REM_GUR_VIGR)
{
Object->DocAllNUM_REM_GUR_VIGR=DocAllNUM_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocAllGUID_TRANSACTION_REM_GUR_VIGR(void)
{
return Object->DocAllGUID_TRANSACTION_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllGUID_TRANSACTION_REM_GUR_VIGR(TFIBWideStringField * DocAllGUID_TRANSACTION_REM_GUR_VIGR)
{
Object->DocAllGUID_TRANSACTION_REM_GUR_VIGR=DocAllGUID_TRANSACTION_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocAllCODE_STR_VIGR_REM_GUR_VIGR(void)
{
return Object->DocAllCODE_STR_VIGR_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllCODE_STR_VIGR_REM_GUR_VIGR(TFIBWideStringField * DocAllCODE_STR_VIGR_REM_GUR_VIGR)
{
Object->DocAllCODE_STR_VIGR_REM_GUR_VIGR=DocAllCODE_STR_VIGR_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocAllGUID_VIGR_REM_GUR_VIGR(void)
{
return Object->DocAllGUID_VIGR_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllGUID_VIGR_REM_GUR_VIGR(TFIBWideStringField * DocAllGUID_VIGR_REM_GUR_VIGR)
{
Object->DocAllGUID_VIGR_REM_GUR_VIGR=DocAllGUID_VIGR_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVigruskaImpl::get_DocAllIDKLIENT_REM_GUR_VIGR(void)
{
return Object->DocAllIDKLIENT_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllIDKLIENT_REM_GUR_VIGR(TFIBLargeIntField * DocAllIDKLIENT_REM_GUR_VIGR)
{
Object->DocAllIDKLIENT_REM_GUR_VIGR=DocAllIDKLIENT_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVigruskaImpl::get_DocAllIDPRODUCER_REM_GUR_VIGR(void)
{
return Object->DocAllIDPRODUCER_REM_GUR_VIGR;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllIDPRODUCER_REM_GUR_VIGR(TFIBLargeIntField * DocAllIDPRODUCER_REM_GUR_VIGR)
{
Object->DocAllIDPRODUCER_REM_GUR_VIGR=DocAllIDPRODUCER_REM_GUR_VIGR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocAllNAME_SPRODUCER(void)
{
return Object->DocAllNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllNAME_SPRODUCER(TFIBWideStringField * DocAllNAME_SPRODUCER)
{
Object->DocAllNAME_SPRODUCER=DocAllNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocAllNAME_USER(void)
{
return Object->DocAllNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllNAME_USER(TFIBWideStringField * DocAllNAME_USER)
{
Object->DocAllNAME_USER=DocAllNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVigruskaImpl::get_DocTID_REM_GUR_VIGRT(void)
{
return Object->DocTID_REM_GUR_VIGRT;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTID_REM_GUR_VIGRT(TFIBLargeIntField * DocTID_REM_GUR_VIGRT)
{
Object->DocTID_REM_GUR_VIGRT=DocTID_REM_GUR_VIGRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVigruskaImpl::get_DocTIDBASE_REM_GUR_VIGRT(void)
{
return Object->DocTIDBASE_REM_GUR_VIGRT;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTIDBASE_REM_GUR_VIGRT(TFIBLargeIntField * DocTIDBASE_REM_GUR_VIGRT)
{
Object->DocTIDBASE_REM_GUR_VIGRT=DocTIDBASE_REM_GUR_VIGRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVigruskaImpl::get_DocTIDDOC_REM_GUR_VIGRT(void)
{
return Object->DocTIDDOC_REM_GUR_VIGRT;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTIDDOC_REM_GUR_VIGRT(TFIBLargeIntField * DocTIDDOC_REM_GUR_VIGRT)
{
Object->DocTIDDOC_REM_GUR_VIGRT=DocTIDDOC_REM_GUR_VIGRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVigruskaImpl::get_DocTIDDOCVIGR_REM_GUR_VIGRT(void)
{
return Object->DocTIDDOCVIGR_REM_GUR_VIGRT;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTIDDOCVIGR_REM_GUR_VIGRT(TFIBLargeIntField * DocTIDDOCVIGR_REM_GUR_VIGRT)
{
Object->DocTIDDOCVIGR_REM_GUR_VIGRT=DocTIDDOCVIGR_REM_GUR_VIGRT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocTNAMEFIRM(void)
{
return Object->DocTNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM)
{
Object->DocTNAMEFIRM=DocTNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocTNAMESKLAD(void)
{
return Object->DocTNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTNAMESKLAD(TFIBWideStringField * DocTNAMESKLAD)
{
Object->DocTNAMESKLAD=DocTNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocTNAME_SINFBASE_OBMEN(void)
{
return Object->DocTNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTNAME_SINFBASE_OBMEN(TFIBWideStringField * DocTNAME_SINFBASE_OBMEN)
{
Object->DocTNAME_SINFBASE_OBMEN=DocTNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocTPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocTPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocTPREFIKS_NUM_REM_GALLDOC)
{
Object->DocTPREFIKS_NUM_REM_GALLDOC=DocTPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocVigruskaImpl::get_DocTPR_REM_GALLDOC(void)
{
return Object->DocTPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTPR_REM_GALLDOC(TFIBSmallIntField * DocTPR_REM_GALLDOC)
{
Object->DocTPR_REM_GALLDOC=DocTPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVigruskaImpl::get_DocTNUM_REM_GALLDOC(void)
{
return Object->DocTNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTNUM_REM_GALLDOC(TFIBIntegerField * DocTNUM_REM_GALLDOC)
{
Object->DocTNUM_REM_GALLDOC=DocTNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVigruskaImpl::get_DocTPOS_REM_GALLDOC(void)
{
return Object->DocTPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTPOS_REM_GALLDOC(TFIBDateTimeField * DocTPOS_REM_GALLDOC)
{
Object->DocTPOS_REM_GALLDOC=DocTPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocTTDOC_REM_GALLDOC(void)
{
return Object->DocTTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTTDOC_REM_GALLDOC(TFIBWideStringField * DocTTDOC_REM_GALLDOC)
{
Object->DocTTDOC_REM_GALLDOC=DocTTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocVigruskaImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVigruskaImpl::get_DocTOUT_INFO(void)
{
return Object->DocTOUT_INFO;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTOUT_INFO(TFIBWideStringField * DocTOUT_INFO)
{
Object->DocTOUT_INFO=DocTOUT_INFO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVigruskaImpl::get_DocTOUT_IDZ(void)
{
return Object->DocTOUT_IDZ;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_DocTOUT_IDZ(TFIBLargeIntField * DocTOUT_IDZ)
{
Object->DocTOUT_IDZ=DocTOUT_IDZ;
}
//---------------------------------------------------------------
__int64 TREM_DMDocVigruskaImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocVigruskaImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocVigruskaImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TREM_DMDocVigruskaImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVigruskaImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TREM_DMDocVigruskaImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVigruskaImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocVigruskaImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVigruskaImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocVigruskaImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
int TREM_DMDocVigruskaImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
