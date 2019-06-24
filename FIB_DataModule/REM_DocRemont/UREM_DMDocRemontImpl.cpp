#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocRemontImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocRemontImpl::TREM_DMDocRemontImpl()           
{                                            
Object=new TREM_DMDocRemont(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocRemontImpl::~TREM_DMDocRemontImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocRemontImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocRemont)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocRemont*> (this);                                
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
int TREM_DMDocRemontImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocRemontImpl::kanRelease(void)                                  
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
int  TREM_DMDocRemontImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocRemontImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocRemontImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocRemontImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocRemontImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocRemont
TDataSource * TREM_DMDocRemontImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocRemontImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocRemontImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRemontImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRemontImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRemontImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRemontImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRemontImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRemontImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocRemontImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocRemontImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRemontImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocID_REM_DREMONT(void)
{
return Object->DocID_REM_DREMONT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocID_REM_DREMONT(TFIBLargeIntField * DocID_REM_DREMONT)
{
Object->DocID_REM_DREMONT=DocID_REM_DREMONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocIDDOC_REM_DREMONT(void)
{
return Object->DocIDDOC_REM_DREMONT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocIDDOC_REM_DREMONT(TFIBLargeIntField * DocIDDOC_REM_DREMONT)
{
Object->DocIDDOC_REM_DREMONT=DocIDDOC_REM_DREMONT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocPRIM_REM_DREMONT(void)
{
return Object->DocPRIM_REM_DREMONT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocPRIM_REM_DREMONT(TFIBWideStringField * DocPRIM_REM_DREMONT)
{
Object->DocPRIM_REM_DREMONT=DocPRIM_REM_DREMONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocIDBASE_REM_DREMONT(void)
{
return Object->DocIDBASE_REM_DREMONT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocIDBASE_REM_DREMONT(TFIBLargeIntField * DocIDBASE_REM_DREMONT)
{
Object->DocIDBASE_REM_DREMONT=DocIDBASE_REM_DREMONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocIDZ_REM_DREMONT(void)
{
return Object->DocIDZ_REM_DREMONT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocIDZ_REM_DREMONT(TFIBLargeIntField * DocIDZ_REM_DREMONT)
{
Object->DocIDZ_REM_DREMONT=DocIDZ_REM_DREMONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocIDTPRICE_REM_DREMONT(void)
{
return Object->DocIDTPRICE_REM_DREMONT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocIDTPRICE_REM_DREMONT(TFIBLargeIntField * DocIDTPRICE_REM_DREMONT)
{
Object->DocIDTPRICE_REM_DREMONT=DocIDTPRICE_REM_DREMONT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocNAME_REM_Z(void)
{
return Object->DocNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z)
{
Object->DocNAME_REM_Z=DocNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocTID_REM_DREMONTT(void)
{
return Object->DocTID_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTID_REM_DREMONTT(TFIBLargeIntField * DocTID_REM_DREMONTT)
{
Object->DocTID_REM_DREMONTT=DocTID_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocTIDDOC_REM_DREMONTT(void)
{
return Object->DocTIDDOC_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTIDDOC_REM_DREMONTT(TFIBLargeIntField * DocTIDDOC_REM_DREMONTT)
{
Object->DocTIDDOC_REM_DREMONTT=DocTIDDOC_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocTIDBASE_REM_DREMONTT(void)
{
return Object->DocTIDBASE_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTIDBASE_REM_DREMONTT(TFIBLargeIntField * DocTIDBASE_REM_DREMONTT)
{
Object->DocTIDBASE_REM_DREMONTT=DocTIDBASE_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocTIDNOM_REM_DREMONTT(void)
{
return Object->DocTIDNOM_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTIDNOM_REM_DREMONTT(TFIBLargeIntField * DocTIDNOM_REM_DREMONTT)
{
Object->DocTIDNOM_REM_DREMONTT=DocTIDNOM_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocTIDED_REM_DREMONTT(void)
{
return Object->DocTIDED_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTIDED_REM_DREMONTT(TFIBLargeIntField * DocTIDED_REM_DREMONTT)
{
Object->DocTIDED_REM_DREMONTT=DocTIDED_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontImpl::get_DocTKOL_REM_DREMONTT(void)
{
return Object->DocTKOL_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTKOL_REM_DREMONTT(TFIBBCDField * DocTKOL_REM_DREMONTT)
{
Object->DocTKOL_REM_DREMONTT=DocTKOL_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontImpl::get_DocTKF_REM_DREMONTT(void)
{
return Object->DocTKF_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTKF_REM_DREMONTT(TFIBBCDField * DocTKF_REM_DREMONTT)
{
Object->DocTKF_REM_DREMONTT=DocTKF_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontImpl::get_DocTPRICE_REM_DREMONTT(void)
{
return Object->DocTPRICE_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTPRICE_REM_DREMONTT(TFIBBCDField * DocTPRICE_REM_DREMONTT)
{
Object->DocTPRICE_REM_DREMONTT=DocTPRICE_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontImpl::get_DocTSUM_REM_DREMONTT(void)
{
return Object->DocTSUM_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTSUM_REM_DREMONTT(TFIBBCDField * DocTSUM_REM_DREMONTT)
{
Object->DocTSUM_REM_DREMONTT=DocTSUM_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontImpl::get_DocTSUMMEX_REM_DREMONTT(void)
{
return Object->DocTSUMMEX_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTSUMMEX_REM_DREMONTT(TFIBBCDField * DocTSUMMEX_REM_DREMONTT)
{
Object->DocTSUMMEX_REM_DREMONTT=DocTSUMMEX_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRemontImpl::get_DocTPRICEMEX_REM_DREMONTT(void)
{
return Object->DocTPRICEMEX_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTPRICEMEX_REM_DREMONTT(TFIBBCDField * DocTPRICEMEX_REM_DREMONTT)
{
Object->DocTPRICEMEX_REM_DREMONTT=DocTPRICEMEX_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontImpl::get_DocNUM_REM_Z(void)
{
return Object->DocNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocNUM_REM_Z(TFIBIntegerField * DocNUM_REM_Z)
{
Object->DocNUM_REM_Z=DocNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocRemontImpl::get_DocPOS_REM_Z(void)
{
return Object->DocPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocPOS_REM_Z(TFIBDateTimeField * DocPOS_REM_Z)
{
Object->DocPOS_REM_Z=DocPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocSERNUM_REM_Z(void)
{
return Object->DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocSERNUM_REM_Z(TFIBWideStringField * DocSERNUM_REM_Z)
{
Object->DocSERNUM_REM_Z=DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocSERNUM2_REM_Z(void)
{
return Object->DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocSERNUM2_REM_Z(TFIBWideStringField * DocSERNUM2_REM_Z)
{
Object->DocSERNUM2_REM_Z=DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocKLIENT_NAME_REM_Z(void)
{
return Object->DocKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocKLIENT_NAME_REM_Z(TFIBWideStringField * DocKLIENT_NAME_REM_Z)
{
Object->DocKLIENT_NAME_REM_Z=DocKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocMODEL_REM_Z(void)
{
return Object->DocMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z)
{
Object->DocMODEL_REM_Z=DocMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocTIDHW_REM_DREMONTT(void)
{
return Object->DocTIDHW_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTIDHW_REM_DREMONTT(TFIBLargeIntField * DocTIDHW_REM_DREMONTT)
{
Object->DocTIDHW_REM_DREMONTT=DocTIDHW_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRemontImpl::get_DocTDVREG_REM_DREMONTT(void)
{
return Object->DocTDVREG_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTDVREG_REM_DREMONTT(TFIBSmallIntField * DocTDVREG_REM_DREMONTT)
{
Object->DocTDVREG_REM_DREMONTT=DocTDVREG_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocIDHW_REM_DREMONT(void)
{
return Object->DocIDHW_REM_DREMONT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocIDHW_REM_DREMONT(TFIBLargeIntField * DocIDHW_REM_DREMONT)
{
Object->DocIDHW_REM_DREMONT=DocIDHW_REM_DREMONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocIDKKT_REM_DREMONT(void)
{
return Object->DocIDKKT_REM_DREMONT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocIDKKT_REM_DREMONT(TFIBLargeIntField * DocIDKKT_REM_DREMONT)
{
Object->DocIDKKT_REM_DREMONT=DocIDKKT_REM_DREMONT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontImpl::get_DocTYPE_REMONT_REM_DREMONT(void)
{
return Object->DocTYPE_REMONT_REM_DREMONT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTYPE_REMONT_REM_DREMONT(TFIBIntegerField * DocTYPE_REMONT_REM_DREMONT)
{
Object->DocTYPE_REMONT_REM_DREMONT=DocTYPE_REMONT_REM_DREMONT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocNAME_REM_SMODEL(void)
{
return Object->DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL)
{
Object->DocNAME_REM_SMODEL=DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocNAME_REM_SHARDWARE(void)
{
return Object->DocNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocNAME_REM_SHARDWARE(TFIBWideStringField * DocNAME_REM_SHARDWARE)
{
Object->DocNAME_REM_SHARDWARE=DocNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocSERNUM_REM_SHARDWARE(void)
{
return Object->DocSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocSERNUM_REM_SHARDWARE(TFIBWideStringField * DocSERNUM_REM_SHARDWARE)
{
Object->DocSERNUM_REM_SHARDWARE=DocSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocSERNUM2_REM_SHARDWARE(void)
{
return Object->DocSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocSERNUM2_REM_SHARDWARE)
{
Object->DocSERNUM2_REM_SHARDWARE=DocSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocNAME_REM_SKKT(void)
{
return Object->DocNAME_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocNAME_REM_SKKT(TFIBWideStringField * DocNAME_REM_SKKT)
{
Object->DocNAME_REM_SKKT=DocNAME_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocSERNUM_REM_SKKT(void)
{
return Object->DocSERNUM_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocSERNUM_REM_SKKT(TFIBWideStringField * DocSERNUM_REM_SKKT)
{
Object->DocSERNUM_REM_SKKT=DocSERNUM_REM_SKKT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRemontImpl::get_DocTVD_REM_DREMONTT(void)
{
return Object->DocTVD_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTVD_REM_DREMONTT(TFIBSmallIntField * DocTVD_REM_DREMONTT)
{
Object->DocTVD_REM_DREMONTT=DocTVD_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRemontImpl::get_DocTREP_PRODUCER_REM_DREMONTT(void)
{
return Object->DocTREP_PRODUCER_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTREP_PRODUCER_REM_DREMONTT(TFIBSmallIntField * DocTREP_PRODUCER_REM_DREMONTT)
{
Object->DocTREP_PRODUCER_REM_DREMONTT=DocTREP_PRODUCER_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocAllIDOBJECT_REM_GALLDOC(void)
{
return Object->DocAllIDOBJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllIDOBJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC)
{
Object->DocAllIDOBJECT_REM_GALLDOC=DocAllIDOBJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocAllNAME_SOBJECT(void)
{
return Object->DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT)
{
Object->DocAllNAME_SOBJECT=DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRemontImpl::get_TypeNom(void)
{
return Object->TypeNom;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_TypeNom(TpFIBDataSet * TypeNom)
{
Object->TypeNom=TypeNom;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_TypeNomID_STNOM(void)
{
return Object->TypeNomID_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_TypeNomID_STNOM(TFIBLargeIntField * TypeNomID_STNOM)
{
Object->TypeNomID_STNOM=TypeNomID_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_TypeNomNAME_STNOM(void)
{
return Object->TypeNomNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_TypeNomNAME_STNOM(TFIBWideStringField * TypeNomNAME_STNOM)
{
Object->TypeNomNAME_STNOM=TypeNomNAME_STNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocTIDHWOLD_REM_DREMONTT(void)
{
return Object->DocTIDHWOLD_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTIDHWOLD_REM_DREMONTT(TFIBLargeIntField * DocTIDHWOLD_REM_DREMONTT)
{
Object->DocTIDHWOLD_REM_DREMONTT=DocTIDHWOLD_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocTIDTNOM_REM_DREMONTT(void)
{
return Object->DocTIDTNOM_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTIDTNOM_REM_DREMONTT(TFIBLargeIntField * DocTIDTNOM_REM_DREMONTT)
{
Object->DocTIDTNOM_REM_DREMONTT=DocTIDTNOM_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocTIDHW_DONOR_REM_DREMONTT(void)
{
return Object->DocTIDHW_DONOR_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTIDHW_DONOR_REM_DREMONTT(TFIBLargeIntField * DocTIDHW_DONOR_REM_DREMONTT)
{
Object->DocTIDHW_DONOR_REM_DREMONTT=DocTIDHW_DONOR_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocTIDTYP_USEL_REM_DREMONTT(void)
{
return Object->DocTIDTYP_USEL_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTIDTYP_USEL_REM_DREMONTT(TFIBLargeIntField * DocTIDTYP_USEL_REM_DREMONTT)
{
Object->DocTIDTYP_USEL_REM_DREMONTT=DocTIDTYP_USEL_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTDESCR_REM_DREMONTT(void)
{
return Object->DocTDESCR_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTDESCR_REM_DREMONTT(TFIBWideStringField * DocTDESCR_REM_DREMONTT)
{
Object->DocTDESCR_REM_DREMONTT=DocTDESCR_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTOLD_NAME_REM_SHARDWARE(void)
{
return Object->DocTOLD_NAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTOLD_NAME_REM_SHARDWARE(TFIBWideStringField * DocTOLD_NAME_REM_SHARDWARE)
{
Object->DocTOLD_NAME_REM_SHARDWARE=DocTOLD_NAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontImpl::get_DocTOLD_CODE_REM_SHARDWARE(void)
{
return Object->DocTOLD_CODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTOLD_CODE_REM_SHARDWARE(TFIBIntegerField * DocTOLD_CODE_REM_SHARDWARE)
{
Object->DocTOLD_CODE_REM_SHARDWARE=DocTOLD_CODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTOLD_SERNUM_REM_SHARDWARE(void)
{
return Object->DocTOLD_SERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTOLD_SERNUM_REM_SHARDWARE(TFIBWideStringField * DocTOLD_SERNUM_REM_SHARDWARE)
{
Object->DocTOLD_SERNUM_REM_SHARDWARE=DocTOLD_SERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTDONOR_NAME_REM_SHARDWARE(void)
{
return Object->DocTDONOR_NAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTDONOR_NAME_REM_SHARDWARE(TFIBWideStringField * DocTDONOR_NAME_REM_SHARDWARE)
{
Object->DocTDONOR_NAME_REM_SHARDWARE=DocTDONOR_NAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRemontImpl::get_DocTDONOR_CODE_REM_SHARDWARE(void)
{
return Object->DocTDONOR_CODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTDONOR_CODE_REM_SHARDWARE(TFIBIntegerField * DocTDONOR_CODE_REM_SHARDWARE)
{
Object->DocTDONOR_CODE_REM_SHARDWARE=DocTDONOR_CODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTDONOR_SERNUM_REM_SHARDWARE(void)
{
return Object->DocTDONOR_SERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTDONOR_SERNUM_REM_SHARDWARE(TFIBWideStringField * DocTDONOR_SERNUM_REM_SHARDWARE)
{
Object->DocTDONOR_SERNUM_REM_SHARDWARE=DocTDONOR_SERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTNAME_REM_STYPUSLOV(void)
{
return Object->DocTNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTNAME_REM_STYPUSLOV(TFIBWideStringField * DocTNAME_REM_STYPUSLOV)
{
Object->DocTNAME_REM_STYPUSLOV=DocTNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTNAME_STNOM(void)
{
return Object->DocTNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)
{
Object->DocTNAME_STNOM=DocTNAME_STNOM;
}
//---------------------------------------------------------------
TStringField * TREM_DMDocRemontImpl::get_DocTNAME_TYPE_NOM_LOOCUP(void)
{
return Object->DocTNAME_TYPE_NOM_LOOCUP;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTNAME_TYPE_NOM_LOOCUP(TStringField * DocTNAME_TYPE_NOM_LOOCUP)
{
Object->DocTNAME_TYPE_NOM_LOOCUP=DocTNAME_TYPE_NOM_LOOCUP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRemontImpl::get_DocTIDMHRAN_REM_DREMONTT(void)
{
return Object->DocTIDMHRAN_REM_DREMONTT;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTIDMHRAN_REM_DREMONTT(TFIBLargeIntField * DocTIDMHRAN_REM_DREMONTT)
{
Object->DocTIDMHRAN_REM_DREMONTT=DocTIDMHRAN_REM_DREMONTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRemontImpl::get_DocTNAME_SMHRAN(void)
{
return Object->DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN)
{
Object->DocTNAME_SMHRAN=DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
__int64 TREM_DMDocRemontImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocRemontImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocRemontImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRemontImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocRemontImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRemontImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocRemontImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRemontImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocRemontImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
