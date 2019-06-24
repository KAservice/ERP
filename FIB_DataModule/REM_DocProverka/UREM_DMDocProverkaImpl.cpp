#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocProverkaImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocProverkaImpl::TREM_DMDocProverkaImpl()           
{                                            
Object=new TREM_DMDocProverka(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocProverkaImpl::~TREM_DMDocProverkaImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocProverkaImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocProverka)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocProverka*> (this);                                
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
int TREM_DMDocProverkaImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocProverkaImpl::kanRelease(void)                                  
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
int  TREM_DMDocProverkaImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocProverkaImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocProverkaImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocProverkaImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocProverkaImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocProverka
TDataSource * TREM_DMDocProverkaImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocProverkaImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocProverkaImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocProverkaImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocProverkaImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocProverkaImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocProverkaImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocProverkaImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocProverkaImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocProverkaImpl::get_DocAllID_REM_GUR_PROV(void)
{
return Object->DocAllID_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllID_REM_GUR_PROV(TFIBLargeIntField * DocAllID_REM_GUR_PROV)
{
Object->DocAllID_REM_GUR_PROV=DocAllID_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocProverkaImpl::get_DocAllIDBASE_REM_GUR_PROV(void)
{
return Object->DocAllIDBASE_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllIDBASE_REM_GUR_PROV(TFIBLargeIntField * DocAllIDBASE_REM_GUR_PROV)
{
Object->DocAllIDBASE_REM_GUR_PROV=DocAllIDBASE_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocProverkaImpl::get_DocAllPOS_REM_GUR_PROV(void)
{
return Object->DocAllPOS_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllPOS_REM_GUR_PROV(TFIBDateTimeField * DocAllPOS_REM_GUR_PROV)
{
Object->DocAllPOS_REM_GUR_PROV=DocAllPOS_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocProverkaImpl::get_DocAllNUM_REM_GUR_PROV(void)
{
return Object->DocAllNUM_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllNUM_REM_GUR_PROV(TFIBIntegerField * DocAllNUM_REM_GUR_PROV)
{
Object->DocAllNUM_REM_GUR_PROV=DocAllNUM_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocProverkaImpl::get_DocAllDESCR_REM_GUR_PROV(void)
{
return Object->DocAllDESCR_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllDESCR_REM_GUR_PROV(TFIBWideStringField * DocAllDESCR_REM_GUR_PROV)
{
Object->DocAllDESCR_REM_GUR_PROV=DocAllDESCR_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocProverkaImpl::get_DocAllIDDOC_REM_GUR_PROV(void)
{
return Object->DocAllIDDOC_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllIDDOC_REM_GUR_PROV(TFIBLargeIntField * DocAllIDDOC_REM_GUR_PROV)
{
Object->DocAllIDDOC_REM_GUR_PROV=DocAllIDDOC_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocProverkaImpl::get_DocAllIDUSER_REM_GUR_PROV(void)
{
return Object->DocAllIDUSER_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllIDUSER_REM_GUR_PROV(TFIBLargeIntField * DocAllIDUSER_REM_GUR_PROV)
{
Object->DocAllIDUSER_REM_GUR_PROV=DocAllIDUSER_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocProverkaImpl::get_DocAllRES_REM_GUR_PROV(void)
{
return Object->DocAllRES_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllRES_REM_GUR_PROV(TFIBIntegerField * DocAllRES_REM_GUR_PROV)
{
Object->DocAllRES_REM_GUR_PROV=DocAllRES_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocProverkaImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocProverkaImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocProverkaImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocProverkaImpl::get_DocAllNAME_USER_DOC(void)
{
return Object->DocAllNAME_USER_DOC;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllNAME_USER_DOC(TFIBWideStringField * DocAllNAME_USER_DOC)
{
Object->DocAllNAME_USER_DOC=DocAllNAME_USER_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocProverkaImpl::get_DocAllNAME_USER_PROV(void)
{
return Object->DocAllNAME_USER_PROV;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllNAME_USER_PROV(TFIBWideStringField * DocAllNAME_USER_PROV)
{
Object->DocAllNAME_USER_PROV=DocAllNAME_USER_PROV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocProverkaImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocProverkaImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocProverkaImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocProverkaImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocProverkaImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocProverkaImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocProverkaImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
__int64 TREM_DMDocProverkaImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocProverkaImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocProverkaImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocProverkaImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocProverkaImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocProverkaImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocProverkaImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocProverkaImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocProverkaImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
int TREM_DMDocProverkaImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
