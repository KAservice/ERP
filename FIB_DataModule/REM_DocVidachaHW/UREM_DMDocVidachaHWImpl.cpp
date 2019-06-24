#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocVidachaHWImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocVidachaHWImpl::TREM_DMDocVidachaHWImpl()           
{                                            
Object=new TREM_DMDocVidachaHW(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocVidachaHWImpl::~TREM_DMDocVidachaHWImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocVidachaHWImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocVidachaHW)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocVidachaHW*> (this);                                
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
int TREM_DMDocVidachaHWImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocVidachaHWImpl::kanRelease(void)                                  
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
int  TREM_DMDocVidachaHWImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocVidachaHWImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVidachaHWImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocVidachaHWImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVidachaHWImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocVidachaHW
TDataSource * TREM_DMDocVidachaHWImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVidachaHWImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVidachaHWImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVidachaHWImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVidachaHWImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVidachaHWImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVidachaHWImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVidachaHWImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVidachaHWImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVidachaHWImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVidachaHWImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVidachaHWImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVidachaHWImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVidachaHWImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocVidachaHWImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVidachaHWImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVidachaHWImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocVidachaHWImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVidachaHWImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVidachaHWImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocID_REM_DVIDACHA_HW(void)
{
return Object->DocID_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocID_REM_DVIDACHA_HW(TFIBLargeIntField * DocID_REM_DVIDACHA_HW)
{
Object->DocID_REM_DVIDACHA_HW=DocID_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocIDBASE_REM_DVIDACHA_HW(void)
{
return Object->DocIDBASE_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocIDBASE_REM_DVIDACHA_HW(TFIBLargeIntField * DocIDBASE_REM_DVIDACHA_HW)
{
Object->DocIDBASE_REM_DVIDACHA_HW=DocIDBASE_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocGID_REM_DVIDACHA_HW(void)
{
return Object->DocGID_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocGID_REM_DVIDACHA_HW(TFIBWideStringField * DocGID_REM_DVIDACHA_HW)
{
Object->DocGID_REM_DVIDACHA_HW=DocGID_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocIDDOC_REM_DVIDACHA_HW(void)
{
return Object->DocIDDOC_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocIDDOC_REM_DVIDACHA_HW(TFIBLargeIntField * DocIDDOC_REM_DVIDACHA_HW)
{
Object->DocIDDOC_REM_DVIDACHA_HW=DocIDDOC_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocKLIENT_NAME_REM_DVIDACHA_HW(void)
{
return Object->DocKLIENT_NAME_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocKLIENT_NAME_REM_DVIDACHA_HW(TFIBWideStringField * DocKLIENT_NAME_REM_DVIDACHA_HW)
{
Object->DocKLIENT_NAME_REM_DVIDACHA_HW=DocKLIENT_NAME_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocKLIENT_ADR_REM_DVIDACHA_HW(void)
{
return Object->DocKLIENT_ADR_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocKLIENT_ADR_REM_DVIDACHA_HW(TFIBWideStringField * DocKLIENT_ADR_REM_DVIDACHA_HW)
{
Object->DocKLIENT_ADR_REM_DVIDACHA_HW=DocKLIENT_ADR_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocKLIENT_PHONE_REM_DVIDACHA_HW(void)
{
return Object->DocKLIENT_PHONE_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocKLIENT_PHONE_REM_DVIDACHA_HW(TFIBWideStringField * DocKLIENT_PHONE_REM_DVIDACHA_HW)
{
Object->DocKLIENT_PHONE_REM_DVIDACHA_HW=DocKLIENT_PHONE_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocKLIENT_PASSPORT_REM_DVIDACHA_HW(void)
{
return Object->DocKLIENT_PASSPORT_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocKLIENT_PASSPORT_REM_DVIDACHA_HW(TFIBWideStringField * DocKLIENT_PASSPORT_REM_DVIDACHA_HW)
{
Object->DocKLIENT_PASSPORT_REM_DVIDACHA_HW=DocKLIENT_PASSPORT_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocPRIM_REM_DVIDACHA_HW(void)
{
return Object->DocPRIM_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocPRIM_REM_DVIDACHA_HW(TFIBWideStringField * DocPRIM_REM_DVIDACHA_HW)
{
Object->DocPRIM_REM_DVIDACHA_HW=DocPRIM_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocIDZ_REM_DVIDACHA_HW(void)
{
return Object->DocIDZ_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocIDZ_REM_DVIDACHA_HW(TFIBLargeIntField * DocIDZ_REM_DVIDACHA_HW)
{
Object->DocIDZ_REM_DVIDACHA_HW=DocIDZ_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocIDHW_REM_DVIDACHA_HW(void)
{
return Object->DocIDHW_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocIDHW_REM_DVIDACHA_HW(TFIBLargeIntField * DocIDHW_REM_DVIDACHA_HW)
{
Object->DocIDHW_REM_DVIDACHA_HW=DocIDHW_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocIDKKT_REM_DVIDACHA_HW(void)
{
return Object->DocIDKKT_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocIDKKT_REM_DVIDACHA_HW(TFIBLargeIntField * DocIDKKT_REM_DVIDACHA_HW)
{
Object->DocIDKKT_REM_DVIDACHA_HW=DocIDKKT_REM_DVIDACHA_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocNAME_REM_SHARDWARE(void)
{
return Object->DocNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocNAME_REM_SHARDWARE(TFIBWideStringField * DocNAME_REM_SHARDWARE)
{
Object->DocNAME_REM_SHARDWARE=DocNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVidachaHWImpl::get_DocCODE_REM_SHARDWARE(void)
{
return Object->DocCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocCODE_REM_SHARDWARE(TFIBIntegerField * DocCODE_REM_SHARDWARE)
{
Object->DocCODE_REM_SHARDWARE=DocCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocSERNUM_REM_SHARDWARE(void)
{
return Object->DocSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocSERNUM_REM_SHARDWARE(TFIBWideStringField * DocSERNUM_REM_SHARDWARE)
{
Object->DocSERNUM_REM_SHARDWARE=DocSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocSERNUM2_REM_SHARDWARE(void)
{
return Object->DocSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocSERNUM2_REM_SHARDWARE)
{
Object->DocSERNUM2_REM_SHARDWARE=DocSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocNAME_REM_SMODEL(void)
{
return Object->DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL)
{
Object->DocNAME_REM_SMODEL=DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocCODE_REM_SMODEL(void)
{
return Object->DocCODE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocCODE_REM_SMODEL(TFIBWideStringField * DocCODE_REM_SMODEL)
{
Object->DocCODE_REM_SMODEL=DocCODE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocCODE_REM_SPRMODEL(void)
{
return Object->DocCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocCODE_REM_SPRMODEL(TFIBWideStringField * DocCODE_REM_SPRMODEL)
{
Object->DocCODE_REM_SPRMODEL=DocCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocNAME_REM_SPRMODEL(void)
{
return Object->DocNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocNAME_REM_SPRMODEL(TFIBWideStringField * DocNAME_REM_SPRMODEL)
{
Object->DocNAME_REM_SPRMODEL=DocNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocNAME_REM_Z(void)
{
return Object->DocNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z)
{
Object->DocNAME_REM_Z=DocNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocPREFIKS_NUM_REM_Z(void)
{
return Object->DocPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocPREFIKS_NUM_REM_Z(TFIBWideStringField * DocPREFIKS_NUM_REM_Z)
{
Object->DocPREFIKS_NUM_REM_Z=DocPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVidachaHWImpl::get_DocNUM_REM_Z(void)
{
return Object->DocNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocNUM_REM_Z(TFIBIntegerField * DocNUM_REM_Z)
{
Object->DocNUM_REM_Z=DocNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVidachaHWImpl::get_DocPOS_REM_Z(void)
{
return Object->DocPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocPOS_REM_Z(TFIBDateTimeField * DocPOS_REM_Z)
{
Object->DocPOS_REM_Z=DocPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocMODEL_REM_Z(void)
{
return Object->DocMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z)
{
Object->DocMODEL_REM_Z=DocMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocSERNUM_REM_Z(void)
{
return Object->DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocSERNUM_REM_Z(TFIBWideStringField * DocSERNUM_REM_Z)
{
Object->DocSERNUM_REM_Z=DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocSERNUM2_REM_Z(void)
{
return Object->DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocSERNUM2_REM_Z(TFIBWideStringField * DocSERNUM2_REM_Z)
{
Object->DocSERNUM2_REM_Z=DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocTID_REM_DVIDACHA_HWT(void)
{
return Object->DocTID_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTID_REM_DVIDACHA_HWT(TFIBLargeIntField * DocTID_REM_DVIDACHA_HWT)
{
Object->DocTID_REM_DVIDACHA_HWT=DocTID_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocTIDBASE_REM_DVIDACHA_HWT(void)
{
return Object->DocTIDBASE_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTIDBASE_REM_DVIDACHA_HWT(TFIBLargeIntField * DocTIDBASE_REM_DVIDACHA_HWT)
{
Object->DocTIDBASE_REM_DVIDACHA_HWT=DocTIDBASE_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocTGID_REM_DVIDACHA_HWT(void)
{
return Object->DocTGID_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTGID_REM_DVIDACHA_HWT(TFIBWideStringField * DocTGID_REM_DVIDACHA_HWT)
{
Object->DocTGID_REM_DVIDACHA_HWT=DocTGID_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocTIDDOC_REM_DVIDACHA_HWT(void)
{
return Object->DocTIDDOC_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTIDDOC_REM_DVIDACHA_HWT(TFIBLargeIntField * DocTIDDOC_REM_DVIDACHA_HWT)
{
Object->DocTIDDOC_REM_DVIDACHA_HWT=DocTIDDOC_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVidachaHWImpl::get_DocTIDHW_REM_DVIDACHA_HWT(void)
{
return Object->DocTIDHW_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTIDHW_REM_DVIDACHA_HWT(TFIBLargeIntField * DocTIDHW_REM_DVIDACHA_HWT)
{
Object->DocTIDHW_REM_DVIDACHA_HWT=DocTIDHW_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVidachaHWImpl::get_DocTKF_REM_DVIDACHA_HWT(void)
{
return Object->DocTKF_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTKF_REM_DVIDACHA_HWT(TFIBBCDField * DocTKF_REM_DVIDACHA_HWT)
{
Object->DocTKF_REM_DVIDACHA_HWT=DocTKF_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVidachaHWImpl::get_DocTKOL_REM_DVIDACHA_HWT(void)
{
return Object->DocTKOL_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTKOL_REM_DVIDACHA_HWT(TFIBBCDField * DocTKOL_REM_DVIDACHA_HWT)
{
Object->DocTKOL_REM_DVIDACHA_HWT=DocTKOL_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocTPOVREGD_REM_DVIDACHA_HWT(void)
{
return Object->DocTPOVREGD_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTPOVREGD_REM_DVIDACHA_HWT(TFIBWideStringField * DocTPOVREGD_REM_DVIDACHA_HWT)
{
Object->DocTPOVREGD_REM_DVIDACHA_HWT=DocTPOVREGD_REM_DVIDACHA_HWT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVidachaHWImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocTSERNUM2_REM_SHARDWARE(void)
{
return Object->DocTSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM2_REM_SHARDWARE)
{
Object->DocTSERNUM2_REM_SHARDWARE=DocTSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocTNAME_REM_SMODEL(void)
{
return Object->DocTNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTNAME_REM_SMODEL(TFIBWideStringField * DocTNAME_REM_SMODEL)
{
Object->DocTNAME_REM_SMODEL=DocTNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocTCODE_REM_SMODEL(void)
{
return Object->DocTCODE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTCODE_REM_SMODEL(TFIBWideStringField * DocTCODE_REM_SMODEL)
{
Object->DocTCODE_REM_SMODEL=DocTCODE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocTCODE_REM_SPRMODEL(void)
{
return Object->DocTCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTCODE_REM_SPRMODEL(TFIBWideStringField * DocTCODE_REM_SPRMODEL)
{
Object->DocTCODE_REM_SPRMODEL=DocTCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVidachaHWImpl::get_DocTNAME_REM_SPRMODEL(void)
{
return Object->DocTNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_DocTNAME_REM_SPRMODEL(TFIBWideStringField * DocTNAME_REM_SPRMODEL)
{
Object->DocTNAME_REM_SPRMODEL=DocTNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
__int64 TREM_DMDocVidachaHWImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocVidachaHWImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocVidachaHWImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVidachaHWImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocVidachaHWImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVidachaHWImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocVidachaHWImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVidachaHWImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocVidachaHWImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
