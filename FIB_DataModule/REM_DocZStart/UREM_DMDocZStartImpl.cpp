#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocZStartImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocZStartImpl::TREM_DMDocZStartImpl()           
{                                            
Object=new TREM_DMDocZStart(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocZStartImpl::~TREM_DMDocZStartImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocZStartImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocZStart)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocZStart*> (this);                                
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
int TREM_DMDocZStartImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocZStartImpl::kanRelease(void)                                  
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
int  TREM_DMDocZStartImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocZStartImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocZStartImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocZStartImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocZStartImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocZStart
TDataSource * TREM_DMDocZStartImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocZStartImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZStartImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZStartImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZStartImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZStartImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZStartImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZStartImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZStartImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZStartImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZStartImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZStartImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZStartImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZStartImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZStartImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZStartImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZStartImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocID_REM_DZSTART(void)
{
return Object->DocID_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocID_REM_DZSTART(TFIBLargeIntField * DocID_REM_DZSTART)
{
Object->DocID_REM_DZSTART=DocID_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocIDBASE_REM_DZSTART(void)
{
return Object->DocIDBASE_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocIDBASE_REM_DZSTART(TFIBLargeIntField * DocIDBASE_REM_DZSTART)
{
Object->DocIDBASE_REM_DZSTART=DocIDBASE_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocGID_REM_DZSTART(void)
{
return Object->DocGID_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocGID_REM_DZSTART(TFIBWideStringField * DocGID_REM_DZSTART)
{
Object->DocGID_REM_DZSTART=DocGID_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocIDDOC_REM_DZSTART(void)
{
return Object->DocIDDOC_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocIDDOC_REM_DZSTART(TFIBLargeIntField * DocIDDOC_REM_DZSTART)
{
Object->DocIDDOC_REM_DZSTART=DocIDDOC_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocIDZ_REM_DZSTART(void)
{
return Object->DocIDZ_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocIDZ_REM_DZSTART(TFIBLargeIntField * DocIDZ_REM_DZSTART)
{
Object->DocIDZ_REM_DZSTART=DocIDZ_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocPRIM_REM_DZSTART(void)
{
return Object->DocPRIM_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocPRIM_REM_DZSTART(TFIBWideStringField * DocPRIM_REM_DZSTART)
{
Object->DocPRIM_REM_DZSTART=DocPRIM_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNAME_REM_Z(void)
{
return Object->DocNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z)
{
Object->DocNAME_REM_Z=DocNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZStartImpl::get_DocNUM_REM_Z(void)
{
return Object->DocNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNUM_REM_Z(TFIBIntegerField * DocNUM_REM_Z)
{
Object->DocNUM_REM_Z=DocNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZStartImpl::get_DocPOS_REM_Z(void)
{
return Object->DocPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocPOS_REM_Z(TFIBDateTimeField * DocPOS_REM_Z)
{
Object->DocPOS_REM_Z=DocPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocSERNUM_REM_Z(void)
{
return Object->DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocSERNUM_REM_Z(TFIBWideStringField * DocSERNUM_REM_Z)
{
Object->DocSERNUM_REM_Z=DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocSERNUM2_REM_Z(void)
{
return Object->DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocSERNUM2_REM_Z(TFIBWideStringField * DocSERNUM2_REM_Z)
{
Object->DocSERNUM2_REM_Z=DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocKLIENT_NAME_REM_Z(void)
{
return Object->DocKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocKLIENT_NAME_REM_Z(TFIBWideStringField * DocKLIENT_NAME_REM_Z)
{
Object->DocKLIENT_NAME_REM_Z=DocKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocMODEL_REM_Z(void)
{
return Object->DocMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z)
{
Object->DocMODEL_REM_Z=DocMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNAME_REM_SMODEL(void)
{
return Object->DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL)
{
Object->DocNAME_REM_SMODEL=DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocIDPR_REM_DZSTART(void)
{
return Object->DocIDPR_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocIDPR_REM_DZSTART(TFIBLargeIntField * DocIDPR_REM_DZSTART)
{
Object->DocIDPR_REM_DZSTART=DocIDPR_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocIDCFCPR_REM_DZSTART(void)
{
return Object->DocIDCFCPR_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocIDCFCPR_REM_DZSTART(TFIBLargeIntField * DocIDCFCPR_REM_DZSTART)
{
Object->DocIDCFCPR_REM_DZSTART=DocIDCFCPR_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocIDNEISPR_REM_DZSTART(void)
{
return Object->DocIDNEISPR_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocIDNEISPR_REM_DZSTART(TFIBLargeIntField * DocIDNEISPR_REM_DZSTART)
{
Object->DocIDNEISPR_REM_DZSTART=DocIDNEISPR_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocIDPRMODEL_REM_DZSTART(void)
{
return Object->DocIDPRMODEL_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocIDPRMODEL_REM_DZSTART(TFIBLargeIntField * DocIDPRMODEL_REM_DZSTART)
{
Object->DocIDPRMODEL_REM_DZSTART=DocIDPRMODEL_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocPODO_REM_DZSTART(void)
{
return Object->DocPODO_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocPODO_REM_DZSTART(TFIBWideStringField * DocPODO_REM_DZSTART)
{
Object->DocPODO_REM_DZSTART=DocPODO_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocPRODAVEC_REM_DZSTART(void)
{
return Object->DocPRODAVEC_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocPRODAVEC_REM_DZSTART(TFIBWideStringField * DocPRODAVEC_REM_DZSTART)
{
Object->DocPRODAVEC_REM_DZSTART=DocPRODAVEC_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocSERNUM3_REM_DZSTART(void)
{
return Object->DocSERNUM3_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocSERNUM3_REM_DZSTART(TFIBWideStringField * DocSERNUM3_REM_DZSTART)
{
Object->DocSERNUM3_REM_DZSTART=DocSERNUM3_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocSERNUM4_REM_DZSTART(void)
{
return Object->DocSERNUM4_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocSERNUM4_REM_DZSTART(TFIBWideStringField * DocSERNUM4_REM_DZSTART)
{
Object->DocSERNUM4_REM_DZSTART=DocSERNUM4_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNUMBAT_REM_DZSTART(void)
{
return Object->DocNUMBAT_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNUMBAT_REM_DZSTART(TFIBWideStringField * DocNUMBAT_REM_DZSTART)
{
Object->DocNUMBAT_REM_DZSTART=DocNUMBAT_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocSOST_REM_DZSTART(void)
{
return Object->DocSOST_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocSOST_REM_DZSTART(TFIBWideStringField * DocSOST_REM_DZSTART)
{
Object->DocSOST_REM_DZSTART=DocSOST_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMDocZStartImpl::get_DocDATEVIPUSK_REM_DZSTART(void)
{
return Object->DocDATEVIPUSK_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocDATEVIPUSK_REM_DZSTART(TFIBDateField * DocDATEVIPUSK_REM_DZSTART)
{
Object->DocDATEVIPUSK_REM_DZSTART=DocDATEVIPUSK_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMDocZStartImpl::get_DocDATE_PRODAGI_REM_DZSTART(void)
{
return Object->DocDATE_PRODAGI_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocDATE_PRODAGI_REM_DZSTART(TFIBDateField * DocDATE_PRODAGI_REM_DZSTART)
{
Object->DocDATE_PRODAGI_REM_DZSTART=DocDATE_PRODAGI_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZStartImpl::get_DocKEM_SDANO_REM_DZSTART(void)
{
return Object->DocKEM_SDANO_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocKEM_SDANO_REM_DZSTART(TFIBIntegerField * DocKEM_SDANO_REM_DZSTART)
{
Object->DocKEM_SDANO_REM_DZSTART=DocKEM_SDANO_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZStartImpl::get_DocTYPE_REMONT_REM_DZSTART(void)
{
return Object->DocTYPE_REMONT_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocTYPE_REMONT_REM_DZSTART(TFIBIntegerField * DocTYPE_REMONT_REM_DZSTART)
{
Object->DocTYPE_REMONT_REM_DZSTART=DocTYPE_REMONT_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNAME_SPRODUCER(void)
{
return Object->DocNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNAME_SPRODUCER(TFIBWideStringField * DocNAME_SPRODUCER)
{
Object->DocNAME_SPRODUCER=DocNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNAME_REM_SPRNEISPR(void)
{
return Object->DocNAME_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNAME_REM_SPRNEISPR(TFIBWideStringField * DocNAME_REM_SPRNEISPR)
{
Object->DocNAME_REM_SPRNEISPR=DocNAME_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocCODE_REM_SPRNEISPR(void)
{
return Object->DocCODE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocCODE_REM_SPRNEISPR(TFIBWideStringField * DocCODE_REM_SPRNEISPR)
{
Object->DocCODE_REM_SPRNEISPR=DocCODE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNAME_REM_SNEISPR(void)
{
return Object->DocNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNAME_REM_SNEISPR(TFIBWideStringField * DocNAME_REM_SNEISPR)
{
Object->DocNAME_REM_SNEISPR=DocNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNAME_REM_SPRMODEL(void)
{
return Object->DocNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNAME_REM_SPRMODEL(TFIBWideStringField * DocNAME_REM_SPRMODEL)
{
Object->DocNAME_REM_SPRMODEL=DocNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocCODE_REM_SPRMODEL(void)
{
return Object->DocCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocCODE_REM_SPRMODEL(TFIBWideStringField * DocCODE_REM_SPRMODEL)
{
Object->DocCODE_REM_SPRMODEL=DocCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNUM_GARDOC_REM_Z(void)
{
return Object->DocNUM_GARDOC_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNUM_GARDOC_REM_Z(TFIBWideStringField * DocNUM_GARDOC_REM_Z)
{
Object->DocNUM_GARDOC_REM_Z=DocNUM_GARDOC_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZStartImpl::get_DocIDSELLER_REM_DZSTART(void)
{
return Object->DocIDSELLER_REM_DZSTART;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocIDSELLER_REM_DZSTART(TFIBLargeIntField * DocIDSELLER_REM_DZSTART)
{
Object->DocIDSELLER_REM_DZSTART=DocIDSELLER_REM_DZSTART;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNAME_REM_SPRNEISPR_GRP(void)
{
return Object->DocNAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * DocNAME_REM_SPRNEISPR_GRP)
{
Object->DocNAME_REM_SPRNEISPR_GRP=DocNAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNAME_ENG_REM_SPRNEISPR_GRP(void)
{
return Object->DocNAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * DocNAME_ENG_REM_SPRNEISPR_GRP)
{
Object->DocNAME_ENG_REM_SPRNEISPR_GRP=DocNAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNAME_ENG_REM_SNEISPR(void)
{
return Object->DocNAME_ENG_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNAME_ENG_REM_SNEISPR(TFIBWideStringField * DocNAME_ENG_REM_SNEISPR)
{
Object->DocNAME_ENG_REM_SNEISPR=DocNAME_ENG_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNAME_REM_SGRPNEISPR(void)
{
return Object->DocNAME_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNAME_REM_SGRPNEISPR(TFIBWideStringField * DocNAME_REM_SGRPNEISPR)
{
Object->DocNAME_REM_SGRPNEISPR=DocNAME_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNAME_ENG_REM_SGRPNEISPR(void)
{
return Object->DocNAME_ENG_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNAME_ENG_REM_SGRPNEISPR(TFIBWideStringField * DocNAME_ENG_REM_SGRPNEISPR)
{
Object->DocNAME_ENG_REM_SGRPNEISPR=DocNAME_ENG_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZStartImpl::get_DocNAME_SSELLER(void)
{
return Object->DocNAME_SSELLER;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_DocNAME_SSELLER(TFIBWideStringField * DocNAME_SSELLER)
{
Object->DocNAME_SSELLER=DocNAME_SSELLER;
}
//---------------------------------------------------------------
__int64 TREM_DMDocZStartImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocZStartImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocZStartImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocZStartImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZStartImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocZStartImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZStartImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocZStartImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZStartImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
