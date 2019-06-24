#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocRemontHWImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocRemontHWImpl::TREM_DMDocRemontHWImpl()           
{                                            
Object=new TREM_DMDocRemontHW(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocRemontHWImpl::~TREM_DMDocRemontHWImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocRemontHWImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocRemontHW)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocRemontHW*> (this);                                
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
int TREM_DMDocRemontHWImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocRemontHWImpl::kanRelease(void)                                  
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
int  TREM_DMDocRemontHWImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocRemontHWImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocRemontHWImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocRemontHWImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocRemontHWImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocRemontHW
TDataSource * TREM_DMDocRemontHWImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocRemontHWImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocRemontHWImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontHWImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontHWImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontHWImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRemontHWImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRemontHWImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRemontHWImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontHWImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRemontHWImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRemontHWImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRemontHWImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontHWImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontHWImpl::get_DocTKOL_REM_DREMONTHWT(void)
{
return Object->DocTKOL_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTKOL_REM_DREMONTHWT(TFIBBCDField * DocTKOL_REM_DREMONTHWT)
{
Object->DocTKOL_REM_DREMONTHWT=DocTKOL_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontHWImpl::get_DocTKF_REM_DREMONTHWT(void)
{
return Object->DocTKF_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTKF_REM_DREMONTHWT(TFIBBCDField * DocTKF_REM_DREMONTHWT)
{
Object->DocTKF_REM_DREMONTHWT=DocTKF_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontHWImpl::get_DocTPRICE_REM_DREMONTHWT(void)
{
return Object->DocTPRICE_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTPRICE_REM_DREMONTHWT(TFIBBCDField * DocTPRICE_REM_DREMONTHWT)
{
Object->DocTPRICE_REM_DREMONTHWT=DocTPRICE_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontHWImpl::get_DocTSUM_REM_DREMONTHWT(void)
{
return Object->DocTSUM_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTSUM_REM_DREMONTHWT(TFIBBCDField * DocTSUM_REM_DREMONTHWT)
{
Object->DocTSUM_REM_DREMONTHWT=DocTSUM_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontHWImpl::get_DocTPRICEMEX_REM_DREMONTHWT(void)
{
return Object->DocTPRICEMEX_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTPRICEMEX_REM_DREMONTHWT(TFIBBCDField * DocTPRICEMEX_REM_DREMONTHWT)
{
Object->DocTPRICEMEX_REM_DREMONTHWT=DocTPRICEMEX_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontHWImpl::get_DocTSUMMEX_REM_DREMONTHWT(void)
{
return Object->DocTSUMMEX_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTSUMMEX_REM_DREMONTHWT(TFIBBCDField * DocTSUMMEX_REM_DREMONTHWT)
{
Object->DocTSUMMEX_REM_DREMONTHWT=DocTSUMMEX_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocRemontHWImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocRemontHWImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontHWImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRemontHWImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontHWImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontHWImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocID_REM_DREMONTHW(void)
{
return Object->DocID_REM_DREMONTHW;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocID_REM_DREMONTHW(TFIBLargeIntField * DocID_REM_DREMONTHW)
{
Object->DocID_REM_DREMONTHW=DocID_REM_DREMONTHW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocIDDOC_REM_DREMONTHW(void)
{
return Object->DocIDDOC_REM_DREMONTHW;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocIDDOC_REM_DREMONTHW(TFIBLargeIntField * DocIDDOC_REM_DREMONTHW)
{
Object->DocIDDOC_REM_DREMONTHW=DocIDDOC_REM_DREMONTHW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocPRIM_REM_DREMONTHW(void)
{
return Object->DocPRIM_REM_DREMONTHW;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocPRIM_REM_DREMONTHW(TFIBWideStringField * DocPRIM_REM_DREMONTHW)
{
Object->DocPRIM_REM_DREMONTHW=DocPRIM_REM_DREMONTHW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocIDHW_REM_DREMONTHW(void)
{
return Object->DocIDHW_REM_DREMONTHW;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocIDHW_REM_DREMONTHW(TFIBLargeIntField * DocIDHW_REM_DREMONTHW)
{
Object->DocIDHW_REM_DREMONTHW=DocIDHW_REM_DREMONTHW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocIDBASE_REM_DREMONTHW(void)
{
return Object->DocIDBASE_REM_DREMONTHW;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocIDBASE_REM_DREMONTHW(TFIBLargeIntField * DocIDBASE_REM_DREMONTHW)
{
Object->DocIDBASE_REM_DREMONTHW=DocIDBASE_REM_DREMONTHW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocIDTPRICE_REM_DREMONTHW(void)
{
return Object->DocIDTPRICE_REM_DREMONTHW;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocIDTPRICE_REM_DREMONTHW(TFIBLargeIntField * DocIDTPRICE_REM_DREMONTHW)
{
Object->DocIDTPRICE_REM_DREMONTHW=DocIDTPRICE_REM_DREMONTHW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocNAME_REM_SHARDWARE(void)
{
return Object->DocNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocNAME_REM_SHARDWARE(TFIBWideStringField * DocNAME_REM_SHARDWARE)
{
Object->DocNAME_REM_SHARDWARE=DocNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocTID_REM_DREMONTHWT(void)
{
return Object->DocTID_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTID_REM_DREMONTHWT(TFIBLargeIntField * DocTID_REM_DREMONTHWT)
{
Object->DocTID_REM_DREMONTHWT=DocTID_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocTIDDOC_REM_DREMONTHWT(void)
{
return Object->DocTIDDOC_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTIDDOC_REM_DREMONTHWT(TFIBLargeIntField * DocTIDDOC_REM_DREMONTHWT)
{
Object->DocTIDDOC_REM_DREMONTHWT=DocTIDDOC_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocTIDBASE_REM_DREMONTHWT(void)
{
return Object->DocTIDBASE_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTIDBASE_REM_DREMONTHWT(TFIBLargeIntField * DocTIDBASE_REM_DREMONTHWT)
{
Object->DocTIDBASE_REM_DREMONTHWT=DocTIDBASE_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocTIDNOM_REM_DREMONTHWT(void)
{
return Object->DocTIDNOM_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTIDNOM_REM_DREMONTHWT(TFIBLargeIntField * DocTIDNOM_REM_DREMONTHWT)
{
Object->DocTIDNOM_REM_DREMONTHWT=DocTIDNOM_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocTIDED_REM_DREMONTHWT(void)
{
return Object->DocTIDED_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTIDED_REM_DREMONTHWT(TFIBLargeIntField * DocTIDED_REM_DREMONTHWT)
{
Object->DocTIDED_REM_DREMONTHWT=DocTIDED_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocNEISPR_REM_DREMONTHW(void)
{
return Object->DocNEISPR_REM_DREMONTHW;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocNEISPR_REM_DREMONTHW(TFIBWideStringField * DocNEISPR_REM_DREMONTHW)
{
Object->DocNEISPR_REM_DREMONTHW=DocNEISPR_REM_DREMONTHW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontHWImpl::get_DocTIDHW_REM_DREMONTHWT(void)
{
return Object->DocTIDHW_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTIDHW_REM_DREMONTHWT(TFIBLargeIntField * DocTIDHW_REM_DREMONTHWT)
{
Object->DocTIDHW_REM_DREMONTHWT=DocTIDHW_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRemontHWImpl::get_DocTDVREG_REM_DREMONTHWT(void)
{
return Object->DocTDVREG_REM_DREMONTHWT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTDVREG_REM_DREMONTHWT(TFIBSmallIntField * DocTDVREG_REM_DREMONTHWT)
{
Object->DocTDVREG_REM_DREMONTHWT=DocTDVREG_REM_DREMONTHWT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontHWImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontHWImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontHWImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
__int64 TREM_DMDocRemontHWImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocRemontHWImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocRemontHWImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRemontHWImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TREM_DMDocRemontHWImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRemontHWImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocRemontHWImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRemontHWImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocRemontHWImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
