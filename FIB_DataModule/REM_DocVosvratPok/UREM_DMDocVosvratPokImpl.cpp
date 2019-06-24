#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocVosvratPokImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocVosvratPokImpl::TREM_DMDocVosvratPokImpl()           
{                                            
Object=new TREM_DMDocVosvratPok(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocVosvratPokImpl::~TREM_DMDocVosvratPokImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocVosvratPokImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocVosvratPok)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocVosvratPok*> (this);                                
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
int TREM_DMDocVosvratPokImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocVosvratPokImpl::kanRelease(void)                                  
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
int  TREM_DMDocVosvratPokImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocVosvratPokImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVosvratPokImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocVosvratPokImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVosvratPokImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocVosvratPok
TDataSource * TREM_DMDocVosvratPokImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVosvratPokImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVosvratPokImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratPokImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratPokImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratPokImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVosvratPokImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVosvratPokImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVosvratPokImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratPokImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVosvratPokImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVosvratPokImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVosvratPokImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVosvratPokImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratPokImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocVosvratPokImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratPokImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratPokImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratPokImpl::get_DocOsn(void)
{
return Object->DocOsn;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocOsn(TpFIBDataSet * DocOsn)
{
Object->DocOsn=DocOsn;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVosvratPokImpl::get_DataSourceDocOsn(void)
{
return Object->DataSourceDocOsn;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DataSourceDocOsn(TDataSource * DataSourceDocOsn)
{
Object->DataSourceDocOsn=DataSourceDocOsn;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocID_REM_DVPOK(void)
{
return Object->DocID_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocID_REM_DVPOK(TFIBLargeIntField * DocID_REM_DVPOK)
{
Object->DocID_REM_DVPOK=DocID_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocIDBASE_REM_DVPOK(void)
{
return Object->DocIDBASE_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocIDBASE_REM_DVPOK(TFIBLargeIntField * DocIDBASE_REM_DVPOK)
{
Object->DocIDBASE_REM_DVPOK=DocIDBASE_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocGID_REM_DVPOK(void)
{
return Object->DocGID_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocGID_REM_DVPOK(TFIBWideStringField * DocGID_REM_DVPOK)
{
Object->DocGID_REM_DVPOK=DocGID_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocIDDOC_REM_DVPOK(void)
{
return Object->DocIDDOC_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocIDDOC_REM_DVPOK(TFIBLargeIntField * DocIDDOC_REM_DVPOK)
{
Object->DocIDDOC_REM_DVPOK=DocIDDOC_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocIDTYPEPRICE_REM_DVPOK(void)
{
return Object->DocIDTYPEPRICE_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocIDTYPEPRICE_REM_DVPOK(TFIBLargeIntField * DocIDTYPEPRICE_REM_DVPOK)
{
Object->DocIDTYPEPRICE_REM_DVPOK=DocIDTYPEPRICE_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocIDRTYPEPRICE_REM_DVPOK(void)
{
return Object->DocIDRTYPEPRICE_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocIDRTYPEPRICE_REM_DVPOK(TFIBLargeIntField * DocIDRTYPEPRICE_REM_DVPOK)
{
Object->DocIDRTYPEPRICE_REM_DVPOK=DocIDRTYPEPRICE_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocIDCARD_REM_DVPOK(void)
{
return Object->DocIDCARD_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocIDCARD_REM_DVPOK(TFIBLargeIntField * DocIDCARD_REM_DVPOK)
{
Object->DocIDCARD_REM_DVPOK=DocIDCARD_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocKLIENT_NAME_REM_DVPOK(void)
{
return Object->DocKLIENT_NAME_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocKLIENT_NAME_REM_DVPOK(TFIBWideStringField * DocKLIENT_NAME_REM_DVPOK)
{
Object->DocKLIENT_NAME_REM_DVPOK=DocKLIENT_NAME_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocKLIENT_ADR_REM_DVPOK(void)
{
return Object->DocKLIENT_ADR_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocKLIENT_ADR_REM_DVPOK(TFIBWideStringField * DocKLIENT_ADR_REM_DVPOK)
{
Object->DocKLIENT_ADR_REM_DVPOK=DocKLIENT_ADR_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocKLIENT_PHONE_REM_DVPOK(void)
{
return Object->DocKLIENT_PHONE_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocKLIENT_PHONE_REM_DVPOK(TFIBWideStringField * DocKLIENT_PHONE_REM_DVPOK)
{
Object->DocKLIENT_PHONE_REM_DVPOK=DocKLIENT_PHONE_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocKLIENT_PASSPORT_REM_DVPOK(void)
{
return Object->DocKLIENT_PASSPORT_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocKLIENT_PASSPORT_REM_DVPOK(TFIBWideStringField * DocKLIENT_PASSPORT_REM_DVPOK)
{
Object->DocKLIENT_PASSPORT_REM_DVPOK=DocKLIENT_PASSPORT_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocPRICHINA_REM_DVPOK(void)
{
return Object->DocPRICHINA_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocPRICHINA_REM_DVPOK(TFIBWideStringField * DocPRICHINA_REM_DVPOK)
{
Object->DocPRICHINA_REM_DVPOK=DocPRICHINA_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocDESCR_REM_DVPOK(void)
{
return Object->DocDESCR_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocDESCR_REM_DVPOK(TFIBWideStringField * DocDESCR_REM_DVPOK)
{
Object->DocDESCR_REM_DVPOK=DocDESCR_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocNUMDOCSALE_REM_DVPOK(void)
{
return Object->DocNUMDOCSALE_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocNUMDOCSALE_REM_DVPOK(TFIBWideStringField * DocNUMDOCSALE_REM_DVPOK)
{
Object->DocNUMDOCSALE_REM_DVPOK=DocNUMDOCSALE_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVosvratPokImpl::get_DocPOSDOCSALE_REM_DVPOK(void)
{
return Object->DocPOSDOCSALE_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocPOSDOCSALE_REM_DVPOK(TFIBDateTimeField * DocPOSDOCSALE_REM_DVPOK)
{
Object->DocPOSDOCSALE_REM_DVPOK=DocPOSDOCSALE_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocNUMDOCKL_REM_DVPOK(void)
{
return Object->DocNUMDOCKL_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocNUMDOCKL_REM_DVPOK(TFIBWideStringField * DocNUMDOCKL_REM_DVPOK)
{
Object->DocNUMDOCKL_REM_DVPOK=DocNUMDOCKL_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVosvratPokImpl::get_DocPOSDOCKL_REM_DVPOK(void)
{
return Object->DocPOSDOCKL_REM_DVPOK;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocPOSDOCKL_REM_DVPOK(TFIBDateTimeField * DocPOSDOCKL_REM_DVPOK)
{
Object->DocPOSDOCKL_REM_DVPOK=DocPOSDOCKL_REM_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocNAME_SDISCOUNT_CARD(void)
{
return Object->DocNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD)
{
Object->DocNAME_SDISCOUNT_CARD=DocNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocOsnTDOC_REM_GALLDOC(void)
{
return Object->DocOsnTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocOsnTDOC_REM_GALLDOC(TFIBWideStringField * DocOsnTDOC_REM_GALLDOC)
{
Object->DocOsnTDOC_REM_GALLDOC=DocOsnTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVosvratPokImpl::get_DocOsnPOS_REM_GALLDOC(void)
{
return Object->DocOsnPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocOsnPOS_REM_GALLDOC(TFIBDateTimeField * DocOsnPOS_REM_GALLDOC)
{
Object->DocOsnPOS_REM_GALLDOC=DocOsnPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratPokImpl::get_DocOsnNUM_REM_GALLDOC(void)
{
return Object->DocOsnNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocOsnNUM_REM_GALLDOC(TFIBIntegerField * DocOsnNUM_REM_GALLDOC)
{
Object->DocOsnNUM_REM_GALLDOC=DocOsnNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocTID_REM_DVPOKT(void)
{
return Object->DocTID_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTID_REM_DVPOKT(TFIBLargeIntField * DocTID_REM_DVPOKT)
{
Object->DocTID_REM_DVPOKT=DocTID_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocTIDBASE_REM_DVPOKT(void)
{
return Object->DocTIDBASE_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTIDBASE_REM_DVPOKT(TFIBLargeIntField * DocTIDBASE_REM_DVPOKT)
{
Object->DocTIDBASE_REM_DVPOKT=DocTIDBASE_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocTGID_REM_DVPOKT(void)
{
return Object->DocTGID_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTGID_REM_DVPOKT(TFIBWideStringField * DocTGID_REM_DVPOKT)
{
Object->DocTGID_REM_DVPOKT=DocTGID_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocTIDDOC_REM_DVPOKT(void)
{
return Object->DocTIDDOC_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTIDDOC_REM_DVPOKT(TFIBLargeIntField * DocTIDDOC_REM_DVPOKT)
{
Object->DocTIDDOC_REM_DVPOKT=DocTIDDOC_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocTIDNOM_REM_DVPOKT(void)
{
return Object->DocTIDNOM_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTIDNOM_REM_DVPOKT(TFIBLargeIntField * DocTIDNOM_REM_DVPOKT)
{
Object->DocTIDNOM_REM_DVPOKT=DocTIDNOM_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocTIDED_REM_DVPOKT(void)
{
return Object->DocTIDED_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTIDED_REM_DVPOKT(TFIBLargeIntField * DocTIDED_REM_DVPOKT)
{
Object->DocTIDED_REM_DVPOKT=DocTIDED_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratPokImpl::get_DocTIDHW_REM_DVPOKT(void)
{
return Object->DocTIDHW_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTIDHW_REM_DVPOKT(TFIBLargeIntField * DocTIDHW_REM_DVPOKT)
{
Object->DocTIDHW_REM_DVPOKT=DocTIDHW_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocVosvratPokImpl::get_DocTDVREG_REM_DVPOKT(void)
{
return Object->DocTDVREG_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTDVREG_REM_DVPOKT(TFIBSmallIntField * DocTDVREG_REM_DVPOKT)
{
Object->DocTDVREG_REM_DVPOKT=DocTDVREG_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratPokImpl::get_DocTKOL_REM_DVPOKT(void)
{
return Object->DocTKOL_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTKOL_REM_DVPOKT(TFIBBCDField * DocTKOL_REM_DVPOKT)
{
Object->DocTKOL_REM_DVPOKT=DocTKOL_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratPokImpl::get_DocTKF_REM_DVPOKT(void)
{
return Object->DocTKF_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTKF_REM_DVPOKT(TFIBBCDField * DocTKF_REM_DVPOKT)
{
Object->DocTKF_REM_DVPOKT=DocTKF_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratPokImpl::get_DocTPRICE_REM_DVPOKT(void)
{
return Object->DocTPRICE_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTPRICE_REM_DVPOKT(TFIBBCDField * DocTPRICE_REM_DVPOKT)
{
Object->DocTPRICE_REM_DVPOKT=DocTPRICE_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratPokImpl::get_DocTSUM_REM_DVPOKT(void)
{
return Object->DocTSUM_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTSUM_REM_DVPOKT(TFIBBCDField * DocTSUM_REM_DVPOKT)
{
Object->DocTSUM_REM_DVPOKT=DocTSUM_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratPokImpl::get_DocTNDS_REM_DVPOKT(void)
{
return Object->DocTNDS_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTNDS_REM_DVPOKT(TFIBIntegerField * DocTNDS_REM_DVPOKT)
{
Object->DocTNDS_REM_DVPOKT=DocTNDS_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratPokImpl::get_DocTSUMNDS_REM_DVPOKT(void)
{
return Object->DocTSUMNDS_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTSUMNDS_REM_DVPOKT(TFIBBCDField * DocTSUMNDS_REM_DVPOKT)
{
Object->DocTSUMNDS_REM_DVPOKT=DocTSUMNDS_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratPokImpl::get_DocTPRSK_REM_DVPOKT(void)
{
return Object->DocTPRSK_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTPRSK_REM_DVPOKT(TFIBBCDField * DocTPRSK_REM_DVPOKT)
{
Object->DocTPRSK_REM_DVPOKT=DocTPRSK_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratPokImpl::get_DocTSUMSK_REM_DVPOKT(void)
{
return Object->DocTSUMSK_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTSUMSK_REM_DVPOKT(TFIBBCDField * DocTSUMSK_REM_DVPOKT)
{
Object->DocTSUMSK_REM_DVPOKT=DocTSUMSK_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratPokImpl::get_DocTPRSK_CARD_REM_DVPOKT(void)
{
return Object->DocTPRSK_CARD_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTPRSK_CARD_REM_DVPOKT(TFIBBCDField * DocTPRSK_CARD_REM_DVPOKT)
{
Object->DocTPRSK_CARD_REM_DVPOKT=DocTPRSK_CARD_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratPokImpl::get_DocTPRSK_AUTO_REM_DVPOKT(void)
{
return Object->DocTPRSK_AUTO_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTPRSK_AUTO_REM_DVPOKT(TFIBBCDField * DocTPRSK_AUTO_REM_DVPOKT)
{
Object->DocTPRSK_AUTO_REM_DVPOKT=DocTPRSK_AUTO_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratPokImpl::get_DocTPRSK_HAND_REM_DVPOKT(void)
{
return Object->DocTPRSK_HAND_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTPRSK_HAND_REM_DVPOKT(TFIBBCDField * DocTPRSK_HAND_REM_DVPOKT)
{
Object->DocTPRSK_HAND_REM_DVPOKT=DocTPRSK_HAND_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocVosvratPokImpl::get_DocTNO_SK_REM_DVPOKT(void)
{
return Object->DocTNO_SK_REM_DVPOKT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTNO_SK_REM_DVPOKT(TFIBSmallIntField * DocTNO_SK_REM_DVPOKT)
{
Object->DocTNO_SK_REM_DVPOKT=DocTNO_SK_REM_DVPOKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratPokImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratPokImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocVosvratPokImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratPokImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratPokImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMDocVosvratPokImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_DMDocVosvratPokImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_DMDocVosvratPokImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
__int64 TREM_DMDocVosvratPokImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratPokImpl::get_IsmPrice(void)
{
return Object->IsmPrice;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_IsmPrice(bool IsmPrice)
{
Object->IsmPrice=IsmPrice;
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratPokImpl::get_IsmSum(void)
{
return Object->IsmSum;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_IsmSum(bool IsmSum)
{
Object->IsmSum=IsmSum;
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratPokImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratPokImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::CopyDoc(__int64 id_doc)
{
return Object->CopyDoc(id_doc);
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::OpenDocOsn(void)
{
return Object->OpenDocOsn();
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratPokImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratPokImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratPokImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TREM_DMDocVosvratPokImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratPokImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
double TREM_DMDocVosvratPokImpl::Summa(void)
{
return Object->Summa();
}
//---------------------------------------------------------------
__int64 TREM_DMDocVosvratPokImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc,date_doc);
}
//---------------------------------------------------------------
