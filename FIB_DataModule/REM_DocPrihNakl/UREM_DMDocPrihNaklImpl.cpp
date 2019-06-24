#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocPrihNaklImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocPrihNaklImpl::TREM_DMDocPrihNaklImpl()           
{                                            
Object=new TREM_DMDocPrihNakl(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocPrihNaklImpl::~TREM_DMDocPrihNaklImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocPrihNaklImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocPrihNakl)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocPrihNakl*> (this);                                
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
int TREM_DMDocPrihNaklImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocPrihNaklImpl::kanRelease(void)                                  
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
int  TREM_DMDocPrihNaklImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocPrihNaklImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocPrihNaklImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocPrihNaklImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocPrihNaklImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocPrihNakl
TDataSource * TREM_DMDocPrihNaklImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocPrihNaklImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocPrihNaklImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPrihNaklImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPrihNaklImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPrihNaklImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocPrihNaklImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocPrihNaklImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocPrihNaklImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPrihNaklImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocPrihNaklImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocPrihNaklImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocPrihNaklImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocPrihNaklImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPrihNaklImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocPrihNaklImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPrihNaklImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPrihNaklImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocID_REM_DPRN(void)
{
return Object->DocID_REM_DPRN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocID_REM_DPRN(TFIBLargeIntField * DocID_REM_DPRN)
{
Object->DocID_REM_DPRN=DocID_REM_DPRN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocIDBASE_REM_DPRN(void)
{
return Object->DocIDBASE_REM_DPRN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocIDBASE_REM_DPRN(TFIBLargeIntField * DocIDBASE_REM_DPRN)
{
Object->DocIDBASE_REM_DPRN=DocIDBASE_REM_DPRN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocIDDOC_REM_DPRN(void)
{
return Object->DocIDDOC_REM_DPRN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocIDDOC_REM_DPRN(TFIBLargeIntField * DocIDDOC_REM_DPRN)
{
Object->DocIDDOC_REM_DPRN=DocIDDOC_REM_DPRN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocGID_REM_DPRN(void)
{
return Object->DocGID_REM_DPRN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocGID_REM_DPRN(TFIBWideStringField * DocGID_REM_DPRN)
{
Object->DocGID_REM_DPRN=DocGID_REM_DPRN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocIDTPRICE_REM_DPRN(void)
{
return Object->DocIDTPRICE_REM_DPRN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocIDTPRICE_REM_DPRN(TFIBLargeIntField * DocIDTPRICE_REM_DPRN)
{
Object->DocIDTPRICE_REM_DPRN=DocIDTPRICE_REM_DPRN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocIDRTPRICE_REM_DPRN(void)
{
return Object->DocIDRTPRICE_REM_DPRN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocIDRTPRICE_REM_DPRN(TFIBLargeIntField * DocIDRTPRICE_REM_DPRN)
{
Object->DocIDRTPRICE_REM_DPRN=DocIDRTPRICE_REM_DPRN;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPrihNaklImpl::get_DocRSUM_REM_DPRN(void)
{
return Object->DocRSUM_REM_DPRN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocRSUM_REM_DPRN(TFIBBCDField * DocRSUM_REM_DPRN)
{
Object->DocRSUM_REM_DPRN=DocRSUM_REM_DPRN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocPRIM_REM_DPRN(void)
{
return Object->DocPRIM_REM_DPRN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocPRIM_REM_DPRN(TFIBWideStringField * DocPRIM_REM_DPRN)
{
Object->DocPRIM_REM_DPRN=DocPRIM_REM_DPRN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocNUMDOCPOST_REM_DPRN(void)
{
return Object->DocNUMDOCPOST_REM_DPRN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocNUMDOCPOST_REM_DPRN(TFIBWideStringField * DocNUMDOCPOST_REM_DPRN)
{
Object->DocNUMDOCPOST_REM_DPRN=DocNUMDOCPOST_REM_DPRN;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocPrihNaklImpl::get_DocPOSDOCPOST_REM_DPRN(void)
{
return Object->DocPOSDOCPOST_REM_DPRN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocPOSDOCPOST_REM_DPRN(TFIBDateTimeField * DocPOSDOCPOST_REM_DPRN)
{
Object->DocPOSDOCPOST_REM_DPRN=DocPOSDOCPOST_REM_DPRN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocTID_REM_DPRNT(void)
{
return Object->DocTID_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTID_REM_DPRNT(TFIBLargeIntField * DocTID_REM_DPRNT)
{
Object->DocTID_REM_DPRNT=DocTID_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocTIDBASE_REM_DPRNT(void)
{
return Object->DocTIDBASE_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTIDBASE_REM_DPRNT(TFIBLargeIntField * DocTIDBASE_REM_DPRNT)
{
Object->DocTIDBASE_REM_DPRNT=DocTIDBASE_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocTIDDOC_REM_DPRNT(void)
{
return Object->DocTIDDOC_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTIDDOC_REM_DPRNT(TFIBLargeIntField * DocTIDDOC_REM_DPRNT)
{
Object->DocTIDDOC_REM_DPRNT=DocTIDDOC_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTGID_REM_DPRNT(void)
{
return Object->DocTGID_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTGID_REM_DPRNT(TFIBWideStringField * DocTGID_REM_DPRNT)
{
Object->DocTGID_REM_DPRNT=DocTGID_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocTIDNOM_REM_DPRNT(void)
{
return Object->DocTIDNOM_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTIDNOM_REM_DPRNT(TFIBLargeIntField * DocTIDNOM_REM_DPRNT)
{
Object->DocTIDNOM_REM_DPRNT=DocTIDNOM_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocTIDED_REM_DPRNT(void)
{
return Object->DocTIDED_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTIDED_REM_DPRNT(TFIBLargeIntField * DocTIDED_REM_DPRNT)
{
Object->DocTIDED_REM_DPRNT=DocTIDED_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocTIDHW_REM_DPRNT(void)
{
return Object->DocTIDHW_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTIDHW_REM_DPRNT(TFIBLargeIntField * DocTIDHW_REM_DPRNT)
{
Object->DocTIDHW_REM_DPRNT=DocTIDHW_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPrihNaklImpl::get_DocTKOL_REM_DPRNT(void)
{
return Object->DocTKOL_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTKOL_REM_DPRNT(TFIBBCDField * DocTKOL_REM_DPRNT)
{
Object->DocTKOL_REM_DPRNT=DocTKOL_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPrihNaklImpl::get_DocTKF_REM_DPRNT(void)
{
return Object->DocTKF_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTKF_REM_DPRNT(TFIBBCDField * DocTKF_REM_DPRNT)
{
Object->DocTKF_REM_DPRNT=DocTKF_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPrihNaklImpl::get_DocTPRICE_REM_DPRNT(void)
{
return Object->DocTPRICE_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTPRICE_REM_DPRNT(TFIBBCDField * DocTPRICE_REM_DPRNT)
{
Object->DocTPRICE_REM_DPRNT=DocTPRICE_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPrihNaklImpl::get_DocTSUM_REM_DPRNT(void)
{
return Object->DocTSUM_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTSUM_REM_DPRNT(TFIBBCDField * DocTSUM_REM_DPRNT)
{
Object->DocTSUM_REM_DPRNT=DocTSUM_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPrihNaklImpl::get_DocTNAC_REM_DPRNT(void)
{
return Object->DocTNAC_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNAC_REM_DPRNT(TFIBBCDField * DocTNAC_REM_DPRNT)
{
Object->DocTNAC_REM_DPRNT=DocTNAC_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPrihNaklImpl::get_DocTRPRICE_REM_DPRNT(void)
{
return Object->DocTRPRICE_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTRPRICE_REM_DPRNT(TFIBBCDField * DocTRPRICE_REM_DPRNT)
{
Object->DocTRPRICE_REM_DPRNT=DocTRPRICE_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPrihNaklImpl::get_DocTRSUM_REM_DPRNT(void)
{
return Object->DocTRSUM_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTRSUM_REM_DPRNT(TFIBBCDField * DocTRSUM_REM_DPRNT)
{
Object->DocTRSUM_REM_DPRNT=DocTRSUM_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPrihNaklImpl::get_DocTNDS_REM_DPRNT(void)
{
return Object->DocTNDS_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNDS_REM_DPRNT(TFIBIntegerField * DocTNDS_REM_DPRNT)
{
Object->DocTNDS_REM_DPRNT=DocTNDS_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPrihNaklImpl::get_DocTSUMNDS_REM_DPRNT(void)
{
return Object->DocTSUMNDS_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTSUMNDS_REM_DPRNT(TFIBBCDField * DocTSUMNDS_REM_DPRNT)
{
Object->DocTSUMNDS_REM_DPRNT=DocTSUMNDS_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPrihNaklImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPrihNaklImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocPrihNaklImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocPrihNaklImpl::get_DocTDVREG_REM_DPRNT(void)
{
return Object->DocTDVREG_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTDVREG_REM_DPRNT(TFIBSmallIntField * DocTDVREG_REM_DPRNT)
{
Object->DocTDVREG_REM_DPRNT=DocTDVREG_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocPrihNaklImpl::get_DocFL_TREB_OTCHET_REM_DPRN(void)
{
return Object->DocFL_TREB_OTCHET_REM_DPRN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocFL_TREB_OTCHET_REM_DPRN(TFIBSmallIntField * DocFL_TREB_OTCHET_REM_DPRN)
{
Object->DocFL_TREB_OTCHET_REM_DPRN=DocFL_TREB_OTCHET_REM_DPRN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocPrihNaklImpl::get_DocFL_OTV_HRAN_REM_DPRN(void)
{
return Object->DocFL_OTV_HRAN_REM_DPRN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocFL_OTV_HRAN_REM_DPRN(TFIBSmallIntField * DocFL_OTV_HRAN_REM_DPRN)
{
Object->DocFL_OTV_HRAN_REM_DPRN=DocFL_OTV_HRAN_REM_DPRN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocTIDCQT_REM_DPRNT(void)
{
return Object->DocTIDCQT_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTIDCQT_REM_DPRNT(TFIBLargeIntField * DocTIDCQT_REM_DPRNT)
{
Object->DocTIDCQT_REM_DPRNT=DocTIDCQT_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocPrihNaklImpl::get_DocTFL_ADD_IN_SOBORUD_SNOM(void)
{
return Object->DocTFL_ADD_IN_SOBORUD_SNOM;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTFL_ADD_IN_SOBORUD_SNOM(TFIBSmallIntField * DocTFL_ADD_IN_SOBORUD_SNOM)
{
Object->DocTFL_ADD_IN_SOBORUD_SNOM=DocTFL_ADD_IN_SOBORUD_SNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocTID_REM_CQUERY(void)
{
return Object->DocTID_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTID_REM_CQUERY(TFIBLargeIntField * DocTID_REM_CQUERY)
{
Object->DocTID_REM_CQUERY=DocTID_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTNAME_REM_CQUERY(void)
{
return Object->DocTNAME_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNAME_REM_CQUERY(TFIBWideStringField * DocTNAME_REM_CQUERY)
{
Object->DocTNAME_REM_CQUERY=DocTNAME_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPrihNaklImpl::get_DocTNUM_REM_CQUERY(void)
{
return Object->DocTNUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNUM_REM_CQUERY(TFIBIntegerField * DocTNUM_REM_CQUERY)
{
Object->DocTNUM_REM_CQUERY=DocTNUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocPrihNaklImpl::get_DocTPOS_REM_CQUERY(void)
{
return Object->DocTPOS_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTPOS_REM_CQUERY(TFIBDateTimeField * DocTPOS_REM_CQUERY)
{
Object->DocTPOS_REM_CQUERY=DocTPOS_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTKLIENT_NAME_REM_CQUERY(void)
{
return Object->DocTKLIENT_NAME_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTKLIENT_NAME_REM_CQUERY(TFIBWideStringField * DocTKLIENT_NAME_REM_CQUERY)
{
Object->DocTKLIENT_NAME_REM_CQUERY=DocTKLIENT_NAME_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTNAME_MODEL_REM_CQUERY(void)
{
return Object->DocTNAME_MODEL_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNAME_MODEL_REM_CQUERY(TFIBWideStringField * DocTNAME_MODEL_REM_CQUERY)
{
Object->DocTNAME_MODEL_REM_CQUERY=DocTNAME_MODEL_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTNUM_STR_ZAK_POST_REM_CQUERY(void)
{
return Object->DocTNUM_STR_ZAK_POST_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNUM_STR_ZAK_POST_REM_CQUERY(TFIBWideStringField * DocTNUM_STR_ZAK_POST_REM_CQUERY)
{
Object->DocTNUM_STR_ZAK_POST_REM_CQUERY=DocTNUM_STR_ZAK_POST_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocTID_REM_Z(void)
{
return Object->DocTID_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTID_REM_Z(TFIBLargeIntField * DocTID_REM_Z)
{
Object->DocTID_REM_Z=DocTID_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTNAME_REM_Z(void)
{
return Object->DocTNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z)
{
Object->DocTNAME_REM_Z=DocTNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTPREFIKS_NUM_REM_Z(void)
{
return Object->DocTPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTPREFIKS_NUM_REM_Z(TFIBWideStringField * DocTPREFIKS_NUM_REM_Z)
{
Object->DocTPREFIKS_NUM_REM_Z=DocTPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPrihNaklImpl::get_DocTNUM_REM_Z(void)
{
return Object->DocTNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z)
{
Object->DocTNUM_REM_Z=DocTNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocPrihNaklImpl::get_DocTPOS_REM_Z(void)
{
return Object->DocTPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z)
{
Object->DocTPOS_REM_Z=DocTPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTMODEL_REM_Z(void)
{
return Object->DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z)
{
Object->DocTMODEL_REM_Z=DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTSERNUM_REM_Z(void)
{
return Object->DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z)
{
Object->DocTSERNUM_REM_Z=DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTSERNUM2_REM_Z(void)
{
return Object->DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z)
{
Object->DocTSERNUM2_REM_Z=DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTSTR_CODE_VIGR_REM_Z_1(void)
{
return Object->DocTSTR_CODE_VIGR_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTSTR_CODE_VIGR_REM_Z_1(TFIBWideStringField * DocTSTR_CODE_VIGR_REM_Z_1)
{
Object->DocTSTR_CODE_VIGR_REM_Z_1=DocTSTR_CODE_VIGR_REM_Z_1;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocTIDTNOM_REM_DPRNT(void)
{
return Object->DocTIDTNOM_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTIDTNOM_REM_DPRNT(TFIBLargeIntField * DocTIDTNOM_REM_DPRNT)
{
Object->DocTIDTNOM_REM_DPRNT=DocTIDTNOM_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPrihNaklImpl::get_DocTIDMHRAN_REM_DPRNT(void)
{
return Object->DocTIDMHRAN_REM_DPRNT;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTIDMHRAN_REM_DPRNT(TFIBLargeIntField * DocTIDMHRAN_REM_DPRNT)
{
Object->DocTIDMHRAN_REM_DPRNT=DocTIDMHRAN_REM_DPRNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTNAME_SMHRAN(void)
{
return Object->DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN)
{
Object->DocTNAME_SMHRAN=DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPrihNaklImpl::get_DocTNAME_STNOM(void)
{
return Object->DocTNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)
{
Object->DocTNAME_STNOM=DocTNAME_STNOM;
}
//---------------------------------------------------------------
bool TREM_DMDocPrihNaklImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMDocPrihNaklImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_DMDocPrihNaklImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_DMDocPrihNaklImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
__int64 TREM_DMDocPrihNaklImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
bool TREM_DMDocPrihNaklImpl::get_IsmPrice(void)
{
return Object->IsmPrice;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_IsmPrice(bool IsmPrice)
{
Object->IsmPrice=IsmPrice;
}
//---------------------------------------------------------------
bool TREM_DMDocPrihNaklImpl::get_IsmSum(void)
{
return Object->IsmSum;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_IsmSum(bool IsmSum)
{
Object->IsmSum=IsmSum;
}
//---------------------------------------------------------------
bool TREM_DMDocPrihNaklImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TREM_DMDocPrihNaklImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::CopyDoc(__int64 id_doc)
{
return Object->CopyDoc(id_doc);
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocPrihNaklImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocPrihNaklImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocPrihNaklImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TREM_DMDocPrihNaklImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocPrihNaklImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
double TREM_DMDocPrihNaklImpl::Summa(void)
{
return Object->Summa();
}
//---------------------------------------------------------------
__int64 TREM_DMDocPrihNaklImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc,date_doc);
}
//---------------------------------------------------------------
