#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocSetServHWImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocSetServHWImpl::TREM_DMDocSetServHWImpl()           
{                                            
Object=new TREM_DMDocSetServHW(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocSetServHWImpl::~TREM_DMDocSetServHWImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocSetServHWImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocSetServHW)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocSetServHW*> (this);                                
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
int TREM_DMDocSetServHWImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocSetServHWImpl::kanRelease(void)                                  
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
int  TREM_DMDocSetServHWImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocSetServHWImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocSetServHWImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocSetServHWImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocSetServHWImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocSetServHW
TDataSource * TREM_DMDocSetServHWImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocSetServHWImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocSetServHWImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSetServHWImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSetServHWImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSetServHWImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocSetServHWImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocSetServHWImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocSetServHWImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSetServHWImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocSetServHWImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocSetServHWImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocSetServHWImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSetServHWImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocSetServHWImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSetServHWImpl::get_DocTSUM_REM_SETSERVHWT(void)
{
return Object->DocTSUM_REM_SETSERVHWT;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocTSUM_REM_SETSERVHWT(TFIBBCDField * DocTSUM_REM_SETSERVHWT)
{
Object->DocTSUM_REM_SETSERVHWT=DocTSUM_REM_SETSERVHWT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocSetServHWImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSetServHWImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocSetServHWImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSetServHWImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSetServHWImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSetServHWImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSetServHWImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSetServHWImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSetServHWImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSetServHWImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSetServHWImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocID_REM_DSETSERVHW(void)
{
return Object->DocID_REM_DSETSERVHW;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocID_REM_DSETSERVHW(TFIBLargeIntField * DocID_REM_DSETSERVHW)
{
Object->DocID_REM_DSETSERVHW=DocID_REM_DSETSERVHW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocIDBASE_REM_DSETSERVHW(void)
{
return Object->DocIDBASE_REM_DSETSERVHW;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocIDBASE_REM_DSETSERVHW(TFIBLargeIntField * DocIDBASE_REM_DSETSERVHW)
{
Object->DocIDBASE_REM_DSETSERVHW=DocIDBASE_REM_DSETSERVHW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocIDDOC_REM_DSETSERVHW(void)
{
return Object->DocIDDOC_REM_DSETSERVHW;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocIDDOC_REM_DSETSERVHW(TFIBLargeIntField * DocIDDOC_REM_DSETSERVHW)
{
Object->DocIDDOC_REM_DSETSERVHW=DocIDDOC_REM_DSETSERVHW;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSetServHWImpl::get_DocTDOC_REM_DSETSERVHW(void)
{
return Object->DocTDOC_REM_DSETSERVHW;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocTDOC_REM_DSETSERVHW(TFIBIntegerField * DocTDOC_REM_DSETSERVHW)
{
Object->DocTDOC_REM_DSETSERVHW=DocTDOC_REM_DSETSERVHW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSetServHWImpl::get_DocPRIM_REM_DSETSERVHW(void)
{
return Object->DocPRIM_REM_DSETSERVHW;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocPRIM_REM_DSETSERVHW(TFIBWideStringField * DocPRIM_REM_DSETSERVHW)
{
Object->DocPRIM_REM_DSETSERVHW=DocPRIM_REM_DSETSERVHW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocTID_REM_DSETSERVHWT(void)
{
return Object->DocTID_REM_DSETSERVHWT;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocTID_REM_DSETSERVHWT(TFIBLargeIntField * DocTID_REM_DSETSERVHWT)
{
Object->DocTID_REM_DSETSERVHWT=DocTID_REM_DSETSERVHWT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocTIDBASE_REM_DSETSERVHWT(void)
{
return Object->DocTIDBASE_REM_DSETSERVHWT;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocTIDBASE_REM_DSETSERVHWT(TFIBLargeIntField * DocTIDBASE_REM_DSETSERVHWT)
{
Object->DocTIDBASE_REM_DSETSERVHWT=DocTIDBASE_REM_DSETSERVHWT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocTIDDOC_REM_DSETSERVHWT(void)
{
return Object->DocTIDDOC_REM_DSETSERVHWT;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocTIDDOC_REM_DSETSERVHWT(TFIBLargeIntField * DocTIDDOC_REM_DSETSERVHWT)
{
Object->DocTIDDOC_REM_DSETSERVHWT=DocTIDDOC_REM_DSETSERVHWT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocTIDHW_REM_DSETSERVHWT(void)
{
return Object->DocTIDHW_REM_DSETSERVHWT;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocTIDHW_REM_DSETSERVHWT(TFIBLargeIntField * DocTIDHW_REM_DSETSERVHWT)
{
Object->DocTIDHW_REM_DSETSERVHWT=DocTIDHW_REM_DSETSERVHWT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSetServHWImpl::get_DocTSUM_REM_DSETSERVHWT(void)
{
return Object->DocTSUM_REM_DSETSERVHWT;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocTSUM_REM_DSETSERVHWT(TFIBBCDField * DocTSUM_REM_DSETSERVHWT)
{
Object->DocTSUM_REM_DSETSERVHWT=DocTSUM_REM_DSETSERVHWT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSetServHWImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSetServHWImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSetServHWImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSetServHWImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSetServHWImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
__int64 TREM_DMDocSetServHWImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocSetServHWImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocSetServHWImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocSetServHWImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocSetServHWImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocSetServHWImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocSetServHWImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocSetServHWImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocSetServHWImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
