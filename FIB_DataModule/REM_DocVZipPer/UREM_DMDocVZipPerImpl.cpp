#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocVZipPerImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocVZipPerImpl::TREM_DMDocVZipPerImpl()           
{                                            
Object=new TREM_DMDocVZipPer(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocVZipPerImpl::~TREM_DMDocVZipPerImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocVZipPerImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocVZipPer)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocVZipPer*> (this);                                
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
int TREM_DMDocVZipPerImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocVZipPerImpl::kanRelease(void)                                  
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
int  TREM_DMDocVZipPerImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocVZipPerImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVZipPerImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocVZipPerImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVZipPerImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocVZipPer
TDataSource * TREM_DMDocVZipPerImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVZipPerImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVZipPerImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVZipPerImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVZipPerImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVZipPerImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVZipPerImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVZipPerImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVZipPerImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVZipPerImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVZipPerImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVZipPerImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVZipPerImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVZipPerImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVZipPerImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocVZipPerImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVZipPerImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVZipPerImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocAllIDOBJECT_REM_GALLDOC(void)
{
return Object->DocAllIDOBJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllIDOBJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC)
{
Object->DocAllIDOBJECT_REM_GALLDOC=DocAllIDOBJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocAllNAME_SOBJECT(void)
{
return Object->DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT)
{
Object->DocAllNAME_SOBJECT=DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocID_REM_DVZPER(void)
{
return Object->DocID_REM_DVZPER;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocID_REM_DVZPER(TFIBLargeIntField * DocID_REM_DVZPER)
{
Object->DocID_REM_DVZPER=DocID_REM_DVZPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocIDBASE_REM_DVZPER(void)
{
return Object->DocIDBASE_REM_DVZPER;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocIDBASE_REM_DVZPER(TFIBLargeIntField * DocIDBASE_REM_DVZPER)
{
Object->DocIDBASE_REM_DVZPER=DocIDBASE_REM_DVZPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocIDDOC_REM_DVZPER(void)
{
return Object->DocIDDOC_REM_DVZPER;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocIDDOC_REM_DVZPER(TFIBLargeIntField * DocIDDOC_REM_DVZPER)
{
Object->DocIDDOC_REM_DVZPER=DocIDDOC_REM_DVZPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocIDSKLADPOL_REM_DVZPER(void)
{
return Object->DocIDSKLADPOL_REM_DVZPER;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocIDSKLADPOL_REM_DVZPER(TFIBLargeIntField * DocIDSKLADPOL_REM_DVZPER)
{
Object->DocIDSKLADPOL_REM_DVZPER=DocIDSKLADPOL_REM_DVZPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocPRIM_REM_DVZPER(void)
{
return Object->DocPRIM_REM_DVZPER;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocPRIM_REM_DVZPER(TFIBWideStringField * DocPRIM_REM_DVZPER)
{
Object->DocPRIM_REM_DVZPER=DocPRIM_REM_DVZPER;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVZipPerImpl::get_DocOPER_REM_DVZPER(void)
{
return Object->DocOPER_REM_DVZPER;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocOPER_REM_DVZPER(TFIBIntegerField * DocOPER_REM_DVZPER)
{
Object->DocOPER_REM_DVZPER=DocOPER_REM_DVZPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocNAMESKLAD(void)
{
return Object->DocNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocNAMESKLAD(TFIBWideStringField * DocNAMESKLAD)
{
Object->DocNAMESKLAD=DocNAMESKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocTID_REM_DVZPERT(void)
{
return Object->DocTID_REM_DVZPERT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTID_REM_DVZPERT(TFIBLargeIntField * DocTID_REM_DVZPERT)
{
Object->DocTID_REM_DVZPERT=DocTID_REM_DVZPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocTIDBASE_REM_DVZPERT(void)
{
return Object->DocTIDBASE_REM_DVZPERT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTIDBASE_REM_DVZPERT(TFIBLargeIntField * DocTIDBASE_REM_DVZPERT)
{
Object->DocTIDBASE_REM_DVZPERT=DocTIDBASE_REM_DVZPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocTIDDOC_REM_DVZPERT(void)
{
return Object->DocTIDDOC_REM_DVZPERT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTIDDOC_REM_DVZPERT(TFIBLargeIntField * DocTIDDOC_REM_DVZPERT)
{
Object->DocTIDDOC_REM_DVZPERT=DocTIDDOC_REM_DVZPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocTIDKLIENT_REM_DVZPERT(void)
{
return Object->DocTIDKLIENT_REM_DVZPERT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTIDKLIENT_REM_DVZPERT(TFIBLargeIntField * DocTIDKLIENT_REM_DVZPERT)
{
Object->DocTIDKLIENT_REM_DVZPERT=DocTIDKLIENT_REM_DVZPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocTIDTNOM_REM_DVZPERT(void)
{
return Object->DocTIDTNOM_REM_DVZPERT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTIDTNOM_REM_DVZPERT(TFIBLargeIntField * DocTIDTNOM_REM_DVZPERT)
{
Object->DocTIDTNOM_REM_DVZPERT=DocTIDTNOM_REM_DVZPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocTIDNOM_REM_DVZPERT(void)
{
return Object->DocTIDNOM_REM_DVZPERT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTIDNOM_REM_DVZPERT(TFIBLargeIntField * DocTIDNOM_REM_DVZPERT)
{
Object->DocTIDNOM_REM_DVZPERT=DocTIDNOM_REM_DVZPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocTIDZ_REM_DVZPERT(void)
{
return Object->DocTIDZ_REM_DVZPERT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTIDZ_REM_DVZPERT(TFIBLargeIntField * DocTIDZ_REM_DVZPERT)
{
Object->DocTIDZ_REM_DVZPERT=DocTIDZ_REM_DVZPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocTIDHW_REM_DVZPERT(void)
{
return Object->DocTIDHW_REM_DVZPERT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTIDHW_REM_DVZPERT(TFIBLargeIntField * DocTIDHW_REM_DVZPERT)
{
Object->DocTIDHW_REM_DVZPERT=DocTIDHW_REM_DVZPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVZipPerImpl::get_DocTKOL_REM_DVZPERT(void)
{
return Object->DocTKOL_REM_DVZPERT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTKOL_REM_DVZPERT(TFIBBCDField * DocTKOL_REM_DVZPERT)
{
Object->DocTKOL_REM_DVZPERT=DocTKOL_REM_DVZPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocTIDTVZIP_REM_DVZPERT(void)
{
return Object->DocTIDTVZIP_REM_DVZPERT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTIDTVZIP_REM_DVZPERT(TFIBLargeIntField * DocTIDTVZIP_REM_DVZPERT)
{
Object->DocTIDTVZIP_REM_DVZPERT=DocTIDTVZIP_REM_DVZPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTNAME_REM_Z(void)
{
return Object->DocTNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z)
{
Object->DocTNAME_REM_Z=DocTNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVZipPerImpl::get_DocTNUM_REM_Z(void)
{
return Object->DocTNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z)
{
Object->DocTNUM_REM_Z=DocTNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVZipPerImpl::get_DocTPOS_REM_Z(void)
{
return Object->DocTPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z)
{
Object->DocTPOS_REM_Z=DocTPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTSERNUM_REM_Z(void)
{
return Object->DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z)
{
Object->DocTSERNUM_REM_Z=DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTSERNUM2_REM_Z(void)
{
return Object->DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z)
{
Object->DocTSERNUM2_REM_Z=DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTKLIENT_NAME_REM_Z(void)
{
return Object->DocTKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTKLIENT_NAME_REM_Z(TFIBWideStringField * DocTKLIENT_NAME_REM_Z)
{
Object->DocTKLIENT_NAME_REM_Z=DocTKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTMODEL_REM_Z(void)
{
return Object->DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z)
{
Object->DocTMODEL_REM_Z=DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTNAME_STNOM(void)
{
return Object->DocTNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)
{
Object->DocTNAME_STNOM=DocTNAME_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTNAME_REM_STVZIP(void)
{
return Object->DocTNAME_REM_STVZIP;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTNAME_REM_STVZIP(TFIBWideStringField * DocTNAME_REM_STVZIP)
{
Object->DocTNAME_REM_STVZIP=DocTNAME_REM_STVZIP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTSERNUM2_REM_SHARDWARE(void)
{
return Object->DocTSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM2_REM_SHARDWARE)
{
Object->DocTSERNUM2_REM_SHARDWARE=DocTSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTNAME_REM_SPRMODEL(void)
{
return Object->DocTNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTNAME_REM_SPRMODEL(TFIBWideStringField * DocTNAME_REM_SPRMODEL)
{
Object->DocTNAME_REM_SPRMODEL=DocTNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocVZipPerImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocTIDMHRAN_OTPR_REM_DVZPERT(void)
{
return Object->DocTIDMHRAN_OTPR_REM_DVZPERT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTIDMHRAN_OTPR_REM_DVZPERT(TFIBLargeIntField * DocTIDMHRAN_OTPR_REM_DVZPERT)
{
Object->DocTIDMHRAN_OTPR_REM_DVZPERT=DocTIDMHRAN_OTPR_REM_DVZPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipPerImpl::get_DocTIDMHRAN_POL_REM_DVZPERT(void)
{
return Object->DocTIDMHRAN_POL_REM_DVZPERT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTIDMHRAN_POL_REM_DVZPERT(TFIBLargeIntField * DocTIDMHRAN_POL_REM_DVZPERT)
{
Object->DocTIDMHRAN_POL_REM_DVZPERT=DocTIDMHRAN_POL_REM_DVZPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTNAME_SMHRAN_OTPR(void)
{
return Object->DocTNAME_SMHRAN_OTPR;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTNAME_SMHRAN_OTPR(TFIBWideStringField * DocTNAME_SMHRAN_OTPR)
{
Object->DocTNAME_SMHRAN_OTPR=DocTNAME_SMHRAN_OTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipPerImpl::get_DocTNAME_SMHRAN_POL(void)
{
return Object->DocTNAME_SMHRAN_POL;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_DocTNAME_SMHRAN_POL(TFIBWideStringField * DocTNAME_SMHRAN_POL)
{
Object->DocTNAME_SMHRAN_POL=DocTNAME_SMHRAN_POL;
}
//---------------------------------------------------------------
__int64 TREM_DMDocVZipPerImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocVZipPerImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocVZipPerImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVZipPerImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocVZipPerImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVZipPerImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocVZipPerImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVZipPerImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocVZipPerImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
int TREM_DMDocVZipPerImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
