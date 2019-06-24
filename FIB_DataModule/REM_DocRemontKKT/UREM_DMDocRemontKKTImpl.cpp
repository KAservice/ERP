#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocRemontKKTImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocRemontKKTImpl::TREM_DMDocRemontKKTImpl()           
{                                            
Object=new TREM_DMDocRemontKKT(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocRemontKKTImpl::~TREM_DMDocRemontKKTImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocRemontKKTImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocRemontKKT)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocRemontKKT*> (this);                                
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
int TREM_DMDocRemontKKTImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocRemontKKTImpl::kanRelease(void)                                  
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
int  TREM_DMDocRemontKKTImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocRemontKKTImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocRemontKKTImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocRemontKKTImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocRemontKKTImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocRemontKKT
TDataSource * TREM_DMDocRemontKKTImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocRemontKKTImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocRemontKKTImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontKKTImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontKKTImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontKKTImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRemontKKTImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRemontKKTImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRemontKKTImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontKKTImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRemontKKTImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRemontKKTImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRemontKKTImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontKKTImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocRemontKKTImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontKKTImpl::get_DocTKOL_REM_DREMONTKKTT(void)
{
return Object->DocTKOL_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTKOL_REM_DREMONTKKTT(TFIBBCDField * DocTKOL_REM_DREMONTKKTT)
{
Object->DocTKOL_REM_DREMONTKKTT=DocTKOL_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontKKTImpl::get_DocTKF_REM_DREMONTKKTT(void)
{
return Object->DocTKF_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTKF_REM_DREMONTKKTT(TFIBBCDField * DocTKF_REM_DREMONTKKTT)
{
Object->DocTKF_REM_DREMONTKKTT=DocTKF_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontKKTImpl::get_DocTPRICE_REM_DREMONTKKTT(void)
{
return Object->DocTPRICE_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTPRICE_REM_DREMONTKKTT(TFIBBCDField * DocTPRICE_REM_DREMONTKKTT)
{
Object->DocTPRICE_REM_DREMONTKKTT=DocTPRICE_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontKKTImpl::get_DocTSUM_REM_DREMONTKKTT(void)
{
return Object->DocTSUM_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTSUM_REM_DREMONTKKTT(TFIBBCDField * DocTSUM_REM_DREMONTKKTT)
{
Object->DocTSUM_REM_DREMONTKKTT=DocTSUM_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontKKTImpl::get_DocTPRICEMEX_REM_DREMONTKKTT(void)
{
return Object->DocTPRICEMEX_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTPRICEMEX_REM_DREMONTKKTT(TFIBBCDField * DocTPRICEMEX_REM_DREMONTKKTT)
{
Object->DocTPRICEMEX_REM_DREMONTKKTT=DocTPRICEMEX_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontKKTImpl::get_DocTSUMMEX_REM_DREMONTKKTT(void)
{
return Object->DocTSUMMEX_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTSUMMEX_REM_DREMONTKKTT(TFIBBCDField * DocTSUMMEX_REM_DREMONTKKTT)
{
Object->DocTSUMMEX_REM_DREMONTKKTT=DocTSUMMEX_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocRemontKKTImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontKKTImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRemontKKTImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontKKTImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontKKTImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocID_REM_DREMONTKKT(void)
{
return Object->DocID_REM_DREMONTKKT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocID_REM_DREMONTKKT(TFIBLargeIntField * DocID_REM_DREMONTKKT)
{
Object->DocID_REM_DREMONTKKT=DocID_REM_DREMONTKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocIDBASE_REM_DREMONTKKT(void)
{
return Object->DocIDBASE_REM_DREMONTKKT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocIDBASE_REM_DREMONTKKT(TFIBLargeIntField * DocIDBASE_REM_DREMONTKKT)
{
Object->DocIDBASE_REM_DREMONTKKT=DocIDBASE_REM_DREMONTKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocIDDOC_REM_DREMONTKKT(void)
{
return Object->DocIDDOC_REM_DREMONTKKT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocIDDOC_REM_DREMONTKKT(TFIBLargeIntField * DocIDDOC_REM_DREMONTKKT)
{
Object->DocIDDOC_REM_DREMONTKKT=DocIDDOC_REM_DREMONTKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocIDKKT_REM_DREMONTKKT(void)
{
return Object->DocIDKKT_REM_DREMONTKKT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocIDKKT_REM_DREMONTKKT(TFIBLargeIntField * DocIDKKT_REM_DREMONTKKT)
{
Object->DocIDKKT_REM_DREMONTKKT=DocIDKKT_REM_DREMONTKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocIDTPRICE_REM_DREMONTKKT(void)
{
return Object->DocIDTPRICE_REM_DREMONTKKT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocIDTPRICE_REM_DREMONTKKT(TFIBLargeIntField * DocIDTPRICE_REM_DREMONTKKT)
{
Object->DocIDTPRICE_REM_DREMONTKKT=DocIDTPRICE_REM_DREMONTKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocPRIM_REM_DREMONTKKT(void)
{
return Object->DocPRIM_REM_DREMONTKKT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocPRIM_REM_DREMONTKKT(TFIBWideStringField * DocPRIM_REM_DREMONTKKT)
{
Object->DocPRIM_REM_DREMONTKKT=DocPRIM_REM_DREMONTKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocNAME_REM_SKKT(void)
{
return Object->DocNAME_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocNAME_REM_SKKT(TFIBWideStringField * DocNAME_REM_SKKT)
{
Object->DocNAME_REM_SKKT=DocNAME_REM_SKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocTID_REM_DREMONTKKTT(void)
{
return Object->DocTID_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTID_REM_DREMONTKKTT(TFIBLargeIntField * DocTID_REM_DREMONTKKTT)
{
Object->DocTID_REM_DREMONTKKTT=DocTID_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocTIDBASE_REM_DREMONTKKTT(void)
{
return Object->DocTIDBASE_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTIDBASE_REM_DREMONTKKTT(TFIBLargeIntField * DocTIDBASE_REM_DREMONTKKTT)
{
Object->DocTIDBASE_REM_DREMONTKKTT=DocTIDBASE_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocTIDDOC_REM_DREMONTKKTT(void)
{
return Object->DocTIDDOC_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTIDDOC_REM_DREMONTKKTT(TFIBLargeIntField * DocTIDDOC_REM_DREMONTKKTT)
{
Object->DocTIDDOC_REM_DREMONTKKTT=DocTIDDOC_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocTIDNOM_REM_DREMONTKKTT(void)
{
return Object->DocTIDNOM_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTIDNOM_REM_DREMONTKKTT(TFIBLargeIntField * DocTIDNOM_REM_DREMONTKKTT)
{
Object->DocTIDNOM_REM_DREMONTKKTT=DocTIDNOM_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocTIDED_REM_DREMONTKKTT(void)
{
return Object->DocTIDED_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTIDED_REM_DREMONTKKTT(TFIBLargeIntField * DocTIDED_REM_DREMONTKKTT)
{
Object->DocTIDED_REM_DREMONTKKTT=DocTIDED_REM_DREMONTKKTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontKKTImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontKKTImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
__int64 TREM_DMDocRemontKKTImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocRemontKKTImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocRemontKKTImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRemontKKTImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocRemontKKTImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRemontKKTImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocRemontKKTImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRemontKKTImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocRemontKKTImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
