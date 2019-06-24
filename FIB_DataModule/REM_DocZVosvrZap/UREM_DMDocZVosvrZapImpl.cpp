#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocZVosvrZapImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocZVosvrZapImpl::TREM_DMDocZVosvrZapImpl()           
{                                            
Object=new TREM_DMDocZVosvrZap(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocZVosvrZapImpl::~TREM_DMDocZVosvrZapImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocZVosvrZapImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocZVosvrZap)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocZVosvrZap*> (this);                                
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
int TREM_DMDocZVosvrZapImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocZVosvrZapImpl::kanRelease(void)                                  
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
int  TREM_DMDocZVosvrZapImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocZVosvrZapImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocZVosvrZapImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocZVosvrZapImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocZVosvrZapImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocZVosvrZap
TDataSource * TREM_DMDocZVosvrZapImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocZVosvrZapImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocZVosvrZapImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZVosvrZapImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZVosvrZapImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZVosvrZapImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZVosvrZapImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZVosvrZapImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZVosvrZapImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZVosvrZapImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZVosvrZapImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZVosvrZapImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZVosvrZapImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZVosvrZapImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocZVosvrZapImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZVosvrZapImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZVosvrZapImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZVosvrZapImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZVosvrZapImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZVosvrZapImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocID_REM_DZVZAP(void)
{
return Object->DocID_REM_DZVZAP;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocID_REM_DZVZAP(TFIBLargeIntField * DocID_REM_DZVZAP)
{
Object->DocID_REM_DZVZAP=DocID_REM_DZVZAP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocIDBASE_REM_DZVZAP(void)
{
return Object->DocIDBASE_REM_DZVZAP;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocIDBASE_REM_DZVZAP(TFIBLargeIntField * DocIDBASE_REM_DZVZAP)
{
Object->DocIDBASE_REM_DZVZAP=DocIDBASE_REM_DZVZAP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocGID_REM_DZVZAP(void)
{
return Object->DocGID_REM_DZVZAP;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocGID_REM_DZVZAP(TFIBWideStringField * DocGID_REM_DZVZAP)
{
Object->DocGID_REM_DZVZAP=DocGID_REM_DZVZAP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocIDDOC_REM_DZVZAP(void)
{
return Object->DocIDDOC_REM_DZVZAP;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocIDDOC_REM_DZVZAP(TFIBLargeIntField * DocIDDOC_REM_DZVZAP)
{
Object->DocIDDOC_REM_DZVZAP=DocIDDOC_REM_DZVZAP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocIDZ_REM_DZVZAP(void)
{
return Object->DocIDZ_REM_DZVZAP;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocIDZ_REM_DZVZAP(TFIBLargeIntField * DocIDZ_REM_DZVZAP)
{
Object->DocIDZ_REM_DZVZAP=DocIDZ_REM_DZVZAP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocIDTPRICE_REM_DZVZAP(void)
{
return Object->DocIDTPRICE_REM_DZVZAP;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocIDTPRICE_REM_DZVZAP(TFIBLargeIntField * DocIDTPRICE_REM_DZVZAP)
{
Object->DocIDTPRICE_REM_DZVZAP=DocIDTPRICE_REM_DZVZAP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocPRIM_REM_DZVZAP(void)
{
return Object->DocPRIM_REM_DZVZAP;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocPRIM_REM_DZVZAP(TFIBWideStringField * DocPRIM_REM_DZVZAP)
{
Object->DocPRIM_REM_DZVZAP=DocPRIM_REM_DZVZAP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocNAME_REM_Z(void)
{
return Object->DocNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z)
{
Object->DocNAME_REM_Z=DocNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZVosvrZapImpl::get_DocNUM_REM_Z(void)
{
return Object->DocNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocNUM_REM_Z(TFIBIntegerField * DocNUM_REM_Z)
{
Object->DocNUM_REM_Z=DocNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZVosvrZapImpl::get_DocPOS_REM_Z(void)
{
return Object->DocPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocPOS_REM_Z(TFIBDateTimeField * DocPOS_REM_Z)
{
Object->DocPOS_REM_Z=DocPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocSERNUM_REM_Z(void)
{
return Object->DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocSERNUM_REM_Z(TFIBWideStringField * DocSERNUM_REM_Z)
{
Object->DocSERNUM_REM_Z=DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocSERNUM2_REM_Z(void)
{
return Object->DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocSERNUM2_REM_Z(TFIBWideStringField * DocSERNUM2_REM_Z)
{
Object->DocSERNUM2_REM_Z=DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocKLIENT_NAME_REM_Z(void)
{
return Object->DocKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocKLIENT_NAME_REM_Z(TFIBWideStringField * DocKLIENT_NAME_REM_Z)
{
Object->DocKLIENT_NAME_REM_Z=DocKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocMODEL_REM_Z(void)
{
return Object->DocMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z)
{
Object->DocMODEL_REM_Z=DocMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocNAME_REM_SMODEL(void)
{
return Object->DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL)
{
Object->DocNAME_REM_SMODEL=DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocTID_REM_DZVZAPT(void)
{
return Object->DocTID_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTID_REM_DZVZAPT(TFIBLargeIntField * DocTID_REM_DZVZAPT)
{
Object->DocTID_REM_DZVZAPT=DocTID_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocTIDBASE_REM_DZVZAPT(void)
{
return Object->DocTIDBASE_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTIDBASE_REM_DZVZAPT(TFIBLargeIntField * DocTIDBASE_REM_DZVZAPT)
{
Object->DocTIDBASE_REM_DZVZAPT=DocTIDBASE_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocTGID_REM_DZVZAPT(void)
{
return Object->DocTGID_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTGID_REM_DZVZAPT(TFIBWideStringField * DocTGID_REM_DZVZAPT)
{
Object->DocTGID_REM_DZVZAPT=DocTGID_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocTIDDOC_REM_DZVZAPT(void)
{
return Object->DocTIDDOC_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTIDDOC_REM_DZVZAPT(TFIBLargeIntField * DocTIDDOC_REM_DZVZAPT)
{
Object->DocTIDDOC_REM_DZVZAPT=DocTIDDOC_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocTIDNOM_REM_DZVZAPT(void)
{
return Object->DocTIDNOM_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTIDNOM_REM_DZVZAPT(TFIBLargeIntField * DocTIDNOM_REM_DZVZAPT)
{
Object->DocTIDNOM_REM_DZVZAPT=DocTIDNOM_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocTIDED_REM_DZVZAPT(void)
{
return Object->DocTIDED_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTIDED_REM_DZVZAPT(TFIBLargeIntField * DocTIDED_REM_DZVZAPT)
{
Object->DocTIDED_REM_DZVZAPT=DocTIDED_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocTIDHW_REM_DZVZAPT(void)
{
return Object->DocTIDHW_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTIDHW_REM_DZVZAPT(TFIBLargeIntField * DocTIDHW_REM_DZVZAPT)
{
Object->DocTIDHW_REM_DZVZAPT=DocTIDHW_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZVosvrZapImpl::get_DocTKOL_REM_DZVZAPT(void)
{
return Object->DocTKOL_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTKOL_REM_DZVZAPT(TFIBBCDField * DocTKOL_REM_DZVZAPT)
{
Object->DocTKOL_REM_DZVZAPT=DocTKOL_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZVosvrZapImpl::get_DocTKF_REM_DZVZAPT(void)
{
return Object->DocTKF_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTKF_REM_DZVZAPT(TFIBBCDField * DocTKF_REM_DZVZAPT)
{
Object->DocTKF_REM_DZVZAPT=DocTKF_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZVosvrZapImpl::get_DocTPRICE_REM_DZVZAPT(void)
{
return Object->DocTPRICE_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTPRICE_REM_DZVZAPT(TFIBBCDField * DocTPRICE_REM_DZVZAPT)
{
Object->DocTPRICE_REM_DZVZAPT=DocTPRICE_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZVosvrZapImpl::get_DocTSUM_REM_DZVZAPT(void)
{
return Object->DocTSUM_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTSUM_REM_DZVZAPT(TFIBBCDField * DocTSUM_REM_DZVZAPT)
{
Object->DocTSUM_REM_DZVZAPT=DocTSUM_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZVosvrZapImpl::get_DocTDVREG_REM_DZVZAPT(void)
{
return Object->DocTDVREG_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTDVREG_REM_DZVZAPT(TFIBSmallIntField * DocTDVREG_REM_DZVZAPT)
{
Object->DocTDVREG_REM_DZVZAPT=DocTDVREG_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZVosvrZapImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZVosvrZapImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZVosvrZapImpl::get_TypeNom(void)
{
return Object->TypeNom;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_TypeNom(TpFIBDataSet * TypeNom)
{
Object->TypeNom=TypeNom;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_TypeNomID_STNOM(void)
{
return Object->TypeNomID_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_TypeNomID_STNOM(TFIBLargeIntField * TypeNomID_STNOM)
{
Object->TypeNomID_STNOM=TypeNomID_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_TypeNomNAME_STNOM(void)
{
return Object->TypeNomNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_TypeNomNAME_STNOM(TFIBWideStringField * TypeNomNAME_STNOM)
{
Object->TypeNomNAME_STNOM=TypeNomNAME_STNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocTIDTNOM_REM_DZVZAPT(void)
{
return Object->DocTIDTNOM_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTIDTNOM_REM_DZVZAPT(TFIBLargeIntField * DocTIDTNOM_REM_DZVZAPT)
{
Object->DocTIDTNOM_REM_DZVZAPT=DocTIDTNOM_REM_DZVZAPT;
}
//---------------------------------------------------------------
TStringField * TREM_DMDocZVosvrZapImpl::get_DocTNAME_TYPE_NOM_LOOKUP(void)
{
return Object->DocTNAME_TYPE_NOM_LOOKUP;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTNAME_TYPE_NOM_LOOKUP(TStringField * DocTNAME_TYPE_NOM_LOOKUP)
{
Object->DocTNAME_TYPE_NOM_LOOKUP=DocTNAME_TYPE_NOM_LOOKUP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocTIDTVZIP_REM_DZVZAPT(void)
{
return Object->DocTIDTVZIP_REM_DZVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTIDTVZIP_REM_DZVZAPT(TFIBLargeIntField * DocTIDTVZIP_REM_DZVZAPT)
{
Object->DocTIDTVZIP_REM_DZVZAPT=DocTIDTVZIP_REM_DZVZAPT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZVosvrZapImpl::get_DocTIDMHRAN_REM_DVZAPT(void)
{
return Object->DocTIDMHRAN_REM_DVZAPT;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTIDMHRAN_REM_DVZAPT(TFIBLargeIntField * DocTIDMHRAN_REM_DVZAPT)
{
Object->DocTIDMHRAN_REM_DVZAPT=DocTIDMHRAN_REM_DVZAPT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocTNAME_STNOM(void)
{
return Object->DocTNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)
{
Object->DocTNAME_STNOM=DocTNAME_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocTNAME_REM_STVZIP(void)
{
return Object->DocTNAME_REM_STVZIP;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTNAME_REM_STVZIP(TFIBWideStringField * DocTNAME_REM_STVZIP)
{
Object->DocTNAME_REM_STVZIP=DocTNAME_REM_STVZIP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZVosvrZapImpl::get_DocTNAME_SMHRAN(void)
{
return Object->DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN)
{
Object->DocTNAME_SMHRAN=DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
__int64 TREM_DMDocZVosvrZapImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocZVosvrZapImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocZVosvrZapImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZVosvrZapImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocZVosvrZapImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZVosvrZapImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocZVosvrZapImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZVosvrZapImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocZVosvrZapImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
