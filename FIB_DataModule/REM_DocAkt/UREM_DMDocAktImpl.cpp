#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocAktImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocAktImpl::TREM_DMDocAktImpl()           
{                                            
Object=new TREM_DMDocAkt(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocAktImpl::~TREM_DMDocAktImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocAktImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocAktImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocAkt)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocAkt*> (this);                                
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
int TREM_DMDocAktImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocAktImpl::kanRelease(void)                                  
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
int  TREM_DMDocAktImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocAktImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocAktImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocAktImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocAktImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocAkt
TDataSource * TREM_DMDocAktImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocAktImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocAktImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocAktImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocAktImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocAktImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocAktImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocAktImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocAktImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocAktImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocAktImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocAktImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocAktImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocAktImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocAktImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocAktImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocAktImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocAktImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocAktImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocAktImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocID_REM_DAKT(void)
{
return Object->DocID_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocID_REM_DAKT(TFIBLargeIntField * DocID_REM_DAKT)
{
Object->DocID_REM_DAKT=DocID_REM_DAKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocIDBASE_REM_DAKT(void)
{
return Object->DocIDBASE_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocIDBASE_REM_DAKT(TFIBLargeIntField * DocIDBASE_REM_DAKT)
{
Object->DocIDBASE_REM_DAKT=DocIDBASE_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocGID_REM_DAKT(void)
{
return Object->DocGID_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocGID_REM_DAKT(TFIBWideStringField * DocGID_REM_DAKT)
{
Object->DocGID_REM_DAKT=DocGID_REM_DAKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocIDDOC_REM_DAKT(void)
{
return Object->DocIDDOC_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocIDDOC_REM_DAKT(TFIBLargeIntField * DocIDDOC_REM_DAKT)
{
Object->DocIDDOC_REM_DAKT=DocIDDOC_REM_DAKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocIDZ_REM_DAKT(void)
{
return Object->DocIDZ_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocIDZ_REM_DAKT(TFIBLargeIntField * DocIDZ_REM_DAKT)
{
Object->DocIDZ_REM_DAKT=DocIDZ_REM_DAKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocIDHW_REM_DAKT(void)
{
return Object->DocIDHW_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocIDHW_REM_DAKT(TFIBLargeIntField * DocIDHW_REM_DAKT)
{
Object->DocIDHW_REM_DAKT=DocIDHW_REM_DAKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocIDKKT_REM_DAKT(void)
{
return Object->DocIDKKT_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocIDKKT_REM_DAKT(TFIBLargeIntField * DocIDKKT_REM_DAKT)
{
Object->DocIDKKT_REM_DAKT=DocIDKKT_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocPRIM_REM_DAKT(void)
{
return Object->DocPRIM_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocPRIM_REM_DAKT(TFIBWideStringField * DocPRIM_REM_DAKT)
{
Object->DocPRIM_REM_DAKT=DocPRIM_REM_DAKT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocAktImpl::get_DocKL_SOGLASEN_REM_DAKT(void)
{
return Object->DocKL_SOGLASEN_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocKL_SOGLASEN_REM_DAKT(TFIBSmallIntField * DocKL_SOGLASEN_REM_DAKT)
{
Object->DocKL_SOGLASEN_REM_DAKT=DocKL_SOGLASEN_REM_DAKT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocAktImpl::get_DocPODPISAN_REM_DAKT(void)
{
return Object->DocPODPISAN_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocPODPISAN_REM_DAKT(TFIBSmallIntField * DocPODPISAN_REM_DAKT)
{
Object->DocPODPISAN_REM_DAKT=DocPODPISAN_REM_DAKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocAktImpl::get_DocTYPE_REM_DAKT(void)
{
return Object->DocTYPE_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocTYPE_REM_DAKT(TFIBIntegerField * DocTYPE_REM_DAKT)
{
Object->DocTYPE_REM_DAKT=DocTYPE_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocNAME_REM_SHARDWARE(void)
{
return Object->DocNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocNAME_REM_SHARDWARE(TFIBWideStringField * DocNAME_REM_SHARDWARE)
{
Object->DocNAME_REM_SHARDWARE=DocNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocSERNUM_REM_SHARDWARE(void)
{
return Object->DocSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocSERNUM_REM_SHARDWARE(TFIBWideStringField * DocSERNUM_REM_SHARDWARE)
{
Object->DocSERNUM_REM_SHARDWARE=DocSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocSERNUM2_REM_SHARDWARE(void)
{
return Object->DocSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocSERNUM2_REM_SHARDWARE)
{
Object->DocSERNUM2_REM_SHARDWARE=DocSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocNAME_REM_SKKT(void)
{
return Object->DocNAME_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocNAME_REM_SKKT(TFIBWideStringField * DocNAME_REM_SKKT)
{
Object->DocNAME_REM_SKKT=DocNAME_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocSERNUM_REM_SKKT(void)
{
return Object->DocSERNUM_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocSERNUM_REM_SKKT(TFIBWideStringField * DocSERNUM_REM_SKKT)
{
Object->DocSERNUM_REM_SKKT=DocSERNUM_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocSERNUM_REM_Z(void)
{
return Object->DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocSERNUM_REM_Z(TFIBWideStringField * DocSERNUM_REM_Z)
{
Object->DocSERNUM_REM_Z=DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocSERNUM2_REM_Z(void)
{
return Object->DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocSERNUM2_REM_Z(TFIBWideStringField * DocSERNUM2_REM_Z)
{
Object->DocSERNUM2_REM_Z=DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocMODEL_REM_Z(void)
{
return Object->DocMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z)
{
Object->DocMODEL_REM_Z=DocMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocNAME_REM_SMODEL(void)
{
return Object->DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL)
{
Object->DocNAME_REM_SMODEL=DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocTID_REM_DAKTT(void)
{
return Object->DocTID_REM_DAKTT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocTID_REM_DAKTT(TFIBLargeIntField * DocTID_REM_DAKTT)
{
Object->DocTID_REM_DAKTT=DocTID_REM_DAKTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocTIDBASE_REM_DAKTT(void)
{
return Object->DocTIDBASE_REM_DAKTT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocTIDBASE_REM_DAKTT(TFIBLargeIntField * DocTIDBASE_REM_DAKTT)
{
Object->DocTIDBASE_REM_DAKTT=DocTIDBASE_REM_DAKTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocTGID_REM_DAKTT(void)
{
return Object->DocTGID_REM_DAKTT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocTGID_REM_DAKTT(TFIBWideStringField * DocTGID_REM_DAKTT)
{
Object->DocTGID_REM_DAKTT=DocTGID_REM_DAKTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocTIDDOC_REM_DAKTT(void)
{
return Object->DocTIDDOC_REM_DAKTT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocTIDDOC_REM_DAKTT(TFIBLargeIntField * DocTIDDOC_REM_DAKTT)
{
Object->DocTIDDOC_REM_DAKTT=DocTIDDOC_REM_DAKTT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocAktImpl::get_DocTINDEX_REM_DAKTT(void)
{
return Object->DocTINDEX_REM_DAKTT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocTINDEX_REM_DAKTT(TFIBIntegerField * DocTINDEX_REM_DAKTT)
{
Object->DocTINDEX_REM_DAKTT=DocTINDEX_REM_DAKTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocTTEXT_REM_DAKTT(void)
{
return Object->DocTTEXT_REM_DAKTT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocTTEXT_REM_DAKTT(TFIBWideStringField * DocTTEXT_REM_DAKTT)
{
Object->DocTTEXT_REM_DAKTT=DocTTEXT_REM_DAKTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocNAME_REM_Z(void)
{
return Object->DocNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z)
{
Object->DocNAME_REM_Z=DocNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocAktImpl::get_DocAllIDOBJECT_REM_GALLDOC(void)
{
return Object->DocAllIDOBJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllIDOBJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC)
{
Object->DocAllIDOBJECT_REM_GALLDOC=DocAllIDOBJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocAllNAME_SOBJECT(void)
{
return Object->DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT)
{
Object->DocAllNAME_SOBJECT=DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocNUM_U_PROISV_REM_DAKT(void)
{
return Object->DocNUM_U_PROISV_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocNUM_U_PROISV_REM_DAKT(TFIBWideStringField * DocNUM_U_PROISV_REM_DAKT)
{
Object->DocNUM_U_PROISV_REM_DAKT=DocNUM_U_PROISV_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocNEISPR_KLIENTA_REM_DAKT(void)
{
return Object->DocNEISPR_KLIENTA_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocNEISPR_KLIENTA_REM_DAKT(TFIBWideStringField * DocNEISPR_KLIENTA_REM_DAKT)
{
Object->DocNEISPR_KLIENTA_REM_DAKT=DocNEISPR_KLIENTA_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocNEISPR_SC_REM_DAKT(void)
{
return Object->DocNEISPR_SC_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocNEISPR_SC_REM_DAKT(TFIBWideStringField * DocNEISPR_SC_REM_DAKT)
{
Object->DocNEISPR_SC_REM_DAKT=DocNEISPR_SC_REM_DAKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocAktImpl::get_DocFL_FULL_KOMPL_REM_DAKT(void)
{
return Object->DocFL_FULL_KOMPL_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocFL_FULL_KOMPL_REM_DAKT(TFIBIntegerField * DocFL_FULL_KOMPL_REM_DAKT)
{
Object->DocFL_FULL_KOMPL_REM_DAKT=DocFL_FULL_KOMPL_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocNEKOMPL_STR_REM_DAKT(void)
{
return Object->DocNEKOMPL_STR_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocNEKOMPL_STR_REM_DAKT(TFIBWideStringField * DocNEKOMPL_STR_REM_DAKT)
{
Object->DocNEKOMPL_STR_REM_DAKT=DocNEKOMPL_STR_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocKOMPL_STR_REM_DAKT(void)
{
return Object->DocKOMPL_STR_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocKOMPL_STR_REM_DAKT(TFIBWideStringField * DocKOMPL_STR_REM_DAKT)
{
Object->DocKOMPL_STR_REM_DAKT=DocKOMPL_STR_REM_DAKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocAktImpl::get_DocFL_MEXPOVR_REM_DAKT(void)
{
return Object->DocFL_MEXPOVR_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocFL_MEXPOVR_REM_DAKT(TFIBIntegerField * DocFL_MEXPOVR_REM_DAKT)
{
Object->DocFL_MEXPOVR_REM_DAKT=DocFL_MEXPOVR_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocMEXPOVR_STR_REM_DAKT(void)
{
return Object->DocMEXPOVR_STR_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocMEXPOVR_STR_REM_DAKT(TFIBWideStringField * DocMEXPOVR_STR_REM_DAKT)
{
Object->DocMEXPOVR_STR_REM_DAKT=DocMEXPOVR_STR_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocNEISPR_BLOK_REM_DAKT(void)
{
return Object->DocNEISPR_BLOK_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocNEISPR_BLOK_REM_DAKT(TFIBWideStringField * DocNEISPR_BLOK_REM_DAKT)
{
Object->DocNEISPR_BLOK_REM_DAKT=DocNEISPR_BLOK_REM_DAKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocAktImpl::get_DocFL_PRICHINA_ACTA_REM_DAKT(void)
{
return Object->DocFL_PRICHINA_ACTA_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocFL_PRICHINA_ACTA_REM_DAKT(TFIBIntegerField * DocFL_PRICHINA_ACTA_REM_DAKT)
{
Object->DocFL_PRICHINA_ACTA_REM_DAKT=DocFL_PRICHINA_ACTA_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocPRICHINA_ACTA_DR_STR_REM_DAKT(void)
{
return Object->DocPRICHINA_ACTA_DR_STR_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocPRICHINA_ACTA_DR_STR_REM_DAKT(TFIBWideStringField * DocPRICHINA_ACTA_DR_STR_REM_DAKT)
{
Object->DocPRICHINA_ACTA_DR_STR_REM_DAKT=DocPRICHINA_ACTA_DR_STR_REM_DAKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocAktImpl::get_DocFL_PRICHINA_SOST_REM_DAKT(void)
{
return Object->DocFL_PRICHINA_SOST_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocFL_PRICHINA_SOST_REM_DAKT(TFIBIntegerField * DocFL_PRICHINA_SOST_REM_DAKT)
{
Object->DocFL_PRICHINA_SOST_REM_DAKT=DocFL_PRICHINA_SOST_REM_DAKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocAktImpl::get_DocFL_MESTONAX_REM_DAKT(void)
{
return Object->DocFL_MESTONAX_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocFL_MESTONAX_REM_DAKT(TFIBIntegerField * DocFL_MESTONAX_REM_DAKT)
{
Object->DocFL_MESTONAX_REM_DAKT=DocFL_MESTONAX_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocISD_NAME_REM_DAKT(void)
{
return Object->DocISD_NAME_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocISD_NAME_REM_DAKT(TFIBWideStringField * DocISD_NAME_REM_DAKT)
{
Object->DocISD_NAME_REM_DAKT=DocISD_NAME_REM_DAKT;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMDocAktImpl::get_DocISD_DATE_PRODAGI_REM_DAKT(void)
{
return Object->DocISD_DATE_PRODAGI_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocISD_DATE_PRODAGI_REM_DAKT(TFIBDateField * DocISD_DATE_PRODAGI_REM_DAKT)
{
Object->DocISD_DATE_PRODAGI_REM_DAKT=DocISD_DATE_PRODAGI_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocISD_MODEL_REM_DAKT(void)
{
return Object->DocISD_MODEL_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocISD_MODEL_REM_DAKT(TFIBWideStringField * DocISD_MODEL_REM_DAKT)
{
Object->DocISD_MODEL_REM_DAKT=DocISD_MODEL_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocISD_SERNUM1_REM_DAKT(void)
{
return Object->DocISD_SERNUM1_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocISD_SERNUM1_REM_DAKT(TFIBWideStringField * DocISD_SERNUM1_REM_DAKT)
{
Object->DocISD_SERNUM1_REM_DAKT=DocISD_SERNUM1_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocISD_SERNUM2_REM_DAKT(void)
{
return Object->DocISD_SERNUM2_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocISD_SERNUM2_REM_DAKT(TFIBWideStringField * DocISD_SERNUM2_REM_DAKT)
{
Object->DocISD_SERNUM2_REM_DAKT=DocISD_SERNUM2_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocISD_SERNUM3_REM_DAKT(void)
{
return Object->DocISD_SERNUM3_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocISD_SERNUM3_REM_DAKT(TFIBWideStringField * DocISD_SERNUM3_REM_DAKT)
{
Object->DocISD_SERNUM3_REM_DAKT=DocISD_SERNUM3_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocISD_NUMUP_REM_DAKT(void)
{
return Object->DocISD_NUMUP_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocISD_NUMUP_REM_DAKT(TFIBWideStringField * DocISD_NUMUP_REM_DAKT)
{
Object->DocISD_NUMUP_REM_DAKT=DocISD_NUMUP_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocISD_NUMTEXLIST_REM_DAKT(void)
{
return Object->DocISD_NUMTEXLIST_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocISD_NUMTEXLIST_REM_DAKT(TFIBWideStringField * DocISD_NUMTEXLIST_REM_DAKT)
{
Object->DocISD_NUMTEXLIST_REM_DAKT=DocISD_NUMTEXLIST_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocPRODAVEC_NAME_REM_DAKT(void)
{
return Object->DocPRODAVEC_NAME_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocPRODAVEC_NAME_REM_DAKT(TFIBWideStringField * DocPRODAVEC_NAME_REM_DAKT)
{
Object->DocPRODAVEC_NAME_REM_DAKT=DocPRODAVEC_NAME_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocPRODAVEC_TEL_REM_DAKT(void)
{
return Object->DocPRODAVEC_TEL_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocPRODAVEC_TEL_REM_DAKT(TFIBWideStringField * DocPRODAVEC_TEL_REM_DAKT)
{
Object->DocPRODAVEC_TEL_REM_DAKT=DocPRODAVEC_TEL_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocKLIENT_NAME_REM_DAKT(void)
{
return Object->DocKLIENT_NAME_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocKLIENT_NAME_REM_DAKT(TFIBWideStringField * DocKLIENT_NAME_REM_DAKT)
{
Object->DocKLIENT_NAME_REM_DAKT=DocKLIENT_NAME_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocKLIENT_ADR_REM_DAKT(void)
{
return Object->DocKLIENT_ADR_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocKLIENT_ADR_REM_DAKT(TFIBWideStringField * DocKLIENT_ADR_REM_DAKT)
{
Object->DocKLIENT_ADR_REM_DAKT=DocKLIENT_ADR_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocKLIENT_PHONE_REM_DAKT(void)
{
return Object->DocKLIENT_PHONE_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocKLIENT_PHONE_REM_DAKT(TFIBWideStringField * DocKLIENT_PHONE_REM_DAKT)
{
Object->DocKLIENT_PHONE_REM_DAKT=DocKLIENT_PHONE_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocPRICHINA_SOST_DR_REM_DAKT(void)
{
return Object->DocPRICHINA_SOST_DR_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocPRICHINA_SOST_DR_REM_DAKT(TFIBWideStringField * DocPRICHINA_SOST_DR_REM_DAKT)
{
Object->DocPRICHINA_SOST_DR_REM_DAKT=DocPRICHINA_SOST_DR_REM_DAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocAktImpl::get_DocPRODAVEC_ADR_REM_DAKT(void)
{
return Object->DocPRODAVEC_ADR_REM_DAKT;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_DocPRODAVEC_ADR_REM_DAKT(TFIBWideStringField * DocPRODAVEC_ADR_REM_DAKT)
{
Object->DocPRODAVEC_ADR_REM_DAKT=DocPRODAVEC_ADR_REM_DAKT;
}
//---------------------------------------------------------------
__int64 TREM_DMDocAktImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocAktImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocAktImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocAktImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocAktImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocAktImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocAktImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocAktImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocAktImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
