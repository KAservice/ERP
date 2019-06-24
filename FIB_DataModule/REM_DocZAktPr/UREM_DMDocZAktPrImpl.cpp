#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocZAktPrImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocZAktPrImpl::TREM_DMDocZAktPrImpl()           
{                                            
Object=new TREM_DMDocZAktPr(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocZAktPrImpl::~TREM_DMDocZAktPrImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocZAktPrImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocZAktPr)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocZAktPr*> (this);                                
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
int TREM_DMDocZAktPrImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocZAktPrImpl::kanRelease(void)                                  
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
int  TREM_DMDocZAktPrImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocZAktPrImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocZAktPrImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocZAktPrImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocZAktPrImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocZAktPr
TDataSource * TREM_DMDocZAktPrImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocZAktPrImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocZAktPrImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZAktPrImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZAktPrImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZAktPrImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZAktPrImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZAktPrImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZAktPrImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZAktPrImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZAktPrImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZAktPrImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZAktPrImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZAktPrImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocZAktPrImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZAktPrImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZAktPrImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZAktPrImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZAktPrImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZAktPrImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocID_REM_DZAKTPR(void)
{
return Object->DocID_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocID_REM_DZAKTPR(TFIBLargeIntField * DocID_REM_DZAKTPR)
{
Object->DocID_REM_DZAKTPR=DocID_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocIDBASE_REM_DZAKTPR(void)
{
return Object->DocIDBASE_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocIDBASE_REM_DZAKTPR(TFIBLargeIntField * DocIDBASE_REM_DZAKTPR)
{
Object->DocIDBASE_REM_DZAKTPR=DocIDBASE_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocGID_REM_DZAKTPR(void)
{
return Object->DocGID_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocGID_REM_DZAKTPR(TFIBWideStringField * DocGID_REM_DZAKTPR)
{
Object->DocGID_REM_DZAKTPR=DocGID_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocIDDOC_REM_DZAKTPR(void)
{
return Object->DocIDDOC_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocIDDOC_REM_DZAKTPR(TFIBLargeIntField * DocIDDOC_REM_DZAKTPR)
{
Object->DocIDDOC_REM_DZAKTPR=DocIDDOC_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocIDZ_REM_DZAKTPR(void)
{
return Object->DocIDZ_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocIDZ_REM_DZAKTPR(TFIBLargeIntField * DocIDZ_REM_DZAKTPR)
{
Object->DocIDZ_REM_DZAKTPR=DocIDZ_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocIDTPRICE_REM_DZAKTPR(void)
{
return Object->DocIDTPRICE_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocIDTPRICE_REM_DZAKTPR(TFIBLargeIntField * DocIDTPRICE_REM_DZAKTPR)
{
Object->DocIDTPRICE_REM_DZAKTPR=DocIDTPRICE_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocPRIM_REM_DZAKTPR(void)
{
return Object->DocPRIM_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocPRIM_REM_DZAKTPR(TFIBWideStringField * DocPRIM_REM_DZAKTPR)
{
Object->DocPRIM_REM_DZAKTPR=DocPRIM_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocNAME_REM_Z(void)
{
return Object->DocNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z)
{
Object->DocNAME_REM_Z=DocNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZAktPrImpl::get_DocNUM_REM_Z(void)
{
return Object->DocNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNUM_REM_Z(TFIBIntegerField * DocNUM_REM_Z)
{
Object->DocNUM_REM_Z=DocNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZAktPrImpl::get_DocPOS_REM_Z(void)
{
return Object->DocPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocPOS_REM_Z(TFIBDateTimeField * DocPOS_REM_Z)
{
Object->DocPOS_REM_Z=DocPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocSERNUM_REM_Z(void)
{
return Object->DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocSERNUM_REM_Z(TFIBWideStringField * DocSERNUM_REM_Z)
{
Object->DocSERNUM_REM_Z=DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocSERNUM2_REM_Z(void)
{
return Object->DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocSERNUM2_REM_Z(TFIBWideStringField * DocSERNUM2_REM_Z)
{
Object->DocSERNUM2_REM_Z=DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocKLIENT_NAME_REM_Z(void)
{
return Object->DocKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocKLIENT_NAME_REM_Z(TFIBWideStringField * DocKLIENT_NAME_REM_Z)
{
Object->DocKLIENT_NAME_REM_Z=DocKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocMODEL_REM_Z(void)
{
return Object->DocMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z)
{
Object->DocMODEL_REM_Z=DocMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocNAME_REM_SMODEL(void)
{
return Object->DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL)
{
Object->DocNAME_REM_SMODEL=DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTID_REM_DZAKTPRT(void)
{
return Object->DocTID_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTID_REM_DZAKTPRT(TFIBLargeIntField * DocTID_REM_DZAKTPRT)
{
Object->DocTID_REM_DZAKTPRT=DocTID_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDBASE_REM_DZAKTPRT(void)
{
return Object->DocTIDBASE_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDBASE_REM_DZAKTPRT(TFIBLargeIntField * DocTIDBASE_REM_DZAKTPRT)
{
Object->DocTIDBASE_REM_DZAKTPRT=DocTIDBASE_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTGID_REM_DZAKTPRT(void)
{
return Object->DocTGID_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTGID_REM_DZAKTPRT(TFIBWideStringField * DocTGID_REM_DZAKTPRT)
{
Object->DocTGID_REM_DZAKTPRT=DocTGID_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDDOC_REM_DZAKTPRT(void)
{
return Object->DocTIDDOC_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDDOC_REM_DZAKTPRT(TFIBLargeIntField * DocTIDDOC_REM_DZAKTPRT)
{
Object->DocTIDDOC_REM_DZAKTPRT=DocTIDDOC_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDNOM_REM_DZAKTPRT(void)
{
return Object->DocTIDNOM_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDNOM_REM_DZAKTPRT(TFIBLargeIntField * DocTIDNOM_REM_DZAKTPRT)
{
Object->DocTIDNOM_REM_DZAKTPRT=DocTIDNOM_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDED_REM_DZAKTPRT(void)
{
return Object->DocTIDED_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDED_REM_DZAKTPRT(TFIBLargeIntField * DocTIDED_REM_DZAKTPRT)
{
Object->DocTIDED_REM_DZAKTPRT=DocTIDED_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDHW_REM_DZAKTPRT(void)
{
return Object->DocTIDHW_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDHW_REM_DZAKTPRT(TFIBLargeIntField * DocTIDHW_REM_DZAKTPRT)
{
Object->DocTIDHW_REM_DZAKTPRT=DocTIDHW_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZAktPrImpl::get_DocTKOL_REM_DZAKTPRT(void)
{
return Object->DocTKOL_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTKOL_REM_DZAKTPRT(TFIBBCDField * DocTKOL_REM_DZAKTPRT)
{
Object->DocTKOL_REM_DZAKTPRT=DocTKOL_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZAktPrImpl::get_DocTKF_REM_DZAKTPRT(void)
{
return Object->DocTKF_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTKF_REM_DZAKTPRT(TFIBBCDField * DocTKF_REM_DZAKTPRT)
{
Object->DocTKF_REM_DZAKTPRT=DocTKF_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZAktPrImpl::get_DocTPRICE_REM_DZAKTPRT(void)
{
return Object->DocTPRICE_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTPRICE_REM_DZAKTPRT(TFIBBCDField * DocTPRICE_REM_DZAKTPRT)
{
Object->DocTPRICE_REM_DZAKTPRT=DocTPRICE_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZAktPrImpl::get_DocTSUM_REM_DZAKTPRT(void)
{
return Object->DocTSUM_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTSUM_REM_DZAKTPRT(TFIBBCDField * DocTSUM_REM_DZAKTPRT)
{
Object->DocTSUM_REM_DZAKTPRT=DocTSUM_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZAktPrImpl::get_DocTDVREG_REM_DZAKTPRT(void)
{
return Object->DocTDVREG_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTDVREG_REM_DZAKTPRT(TFIBSmallIntField * DocTDVREG_REM_DZAKTPRT)
{
Object->DocTDVREG_REM_DZAKTPRT=DocTDVREG_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZAktPrImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZAktPrImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocIDPR_REM_DZAKTPR(void)
{
return Object->DocIDPR_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocIDPR_REM_DZAKTPR(TFIBLargeIntField * DocIDPR_REM_DZAKTPR)
{
Object->DocIDPR_REM_DZAKTPR=DocIDPR_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocIDCFC_REM_DZAKTPR(void)
{
return Object->DocIDCFC_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocIDCFC_REM_DZAKTPR(TFIBLargeIntField * DocIDCFC_REM_DZAKTPR)
{
Object->DocIDCFC_REM_DZAKTPR=DocIDCFC_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocIDDFC_REM_DZAKTPR(void)
{
return Object->DocIDDFC_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocIDDFC_REM_DZAKTPR(TFIBLargeIntField * DocIDDFC_REM_DZAKTPR)
{
Object->DocIDDFC_REM_DZAKTPR=DocIDDFC_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocIDPRMODEL_REM_DZAKTPR(void)
{
return Object->DocIDPRMODEL_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocIDPRMODEL_REM_DZAKTPR(TFIBLargeIntField * DocIDPRMODEL_REM_DZAKTPR)
{
Object->DocIDPRMODEL_REM_DZAKTPR=DocIDPRMODEL_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocPODO_REM_DZAKTPR(void)
{
return Object->DocPODO_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocPODO_REM_DZAKTPR(TFIBWideStringField * DocPODO_REM_DZAKTPR)
{
Object->DocPODO_REM_DZAKTPR=DocPODO_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocPOPOSLE_REM_DZAKTPR(void)
{
return Object->DocPOPOSLE_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocPOPOSLE_REM_DZAKTPR(TFIBWideStringField * DocPOPOSLE_REM_DZAKTPR)
{
Object->DocPOPOSLE_REM_DZAKTPR=DocPOPOSLE_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocDESCR_REM_DZAKTPR(void)
{
return Object->DocDESCR_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocDESCR_REM_DZAKTPR(TFIBWideStringField * DocDESCR_REM_DZAKTPR)
{
Object->DocDESCR_REM_DZAKTPR=DocDESCR_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocPRODAVEC_REM_DZAKTPR(void)
{
return Object->DocPRODAVEC_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocPRODAVEC_REM_DZAKTPR(TFIBWideStringField * DocPRODAVEC_REM_DZAKTPR)
{
Object->DocPRODAVEC_REM_DZAKTPR=DocPRODAVEC_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocNUMGARTALON_REM_DZAKTPR(void)
{
return Object->DocNUMGARTALON_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNUMGARTALON_REM_DZAKTPR(TFIBWideStringField * DocNUMGARTALON_REM_DZAKTPR)
{
Object->DocNUMGARTALON_REM_DZAKTPR=DocNUMGARTALON_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocSERNUM3_REM_DZAKTPR(void)
{
return Object->DocSERNUM3_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocSERNUM3_REM_DZAKTPR(TFIBWideStringField * DocSERNUM3_REM_DZAKTPR)
{
Object->DocSERNUM3_REM_DZAKTPR=DocSERNUM3_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocSERNUM4_REM_DZAKTPR(void)
{
return Object->DocSERNUM4_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocSERNUM4_REM_DZAKTPR(TFIBWideStringField * DocSERNUM4_REM_DZAKTPR)
{
Object->DocSERNUM4_REM_DZAKTPR=DocSERNUM4_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocNUMBAT_REM_DZAKTPR(void)
{
return Object->DocNUMBAT_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNUMBAT_REM_DZAKTPR(TFIBWideStringField * DocNUMBAT_REM_DZAKTPR)
{
Object->DocNUMBAT_REM_DZAKTPR=DocNUMBAT_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocSOST_REM_DZAKTPR(void)
{
return Object->DocSOST_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocSOST_REM_DZAKTPR(TFIBWideStringField * DocSOST_REM_DZAKTPR)
{
Object->DocSOST_REM_DZAKTPR=DocSOST_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMDocZAktPrImpl::get_DocDATEVIPUSK_REM_DZAKTPR(void)
{
return Object->DocDATEVIPUSK_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocDATEVIPUSK_REM_DZAKTPR(TFIBDateField * DocDATEVIPUSK_REM_DZAKTPR)
{
Object->DocDATEVIPUSK_REM_DZAKTPR=DocDATEVIPUSK_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMDocZAktPrImpl::get_DocDATE_PRODAGI_REM_DZAKTPR(void)
{
return Object->DocDATE_PRODAGI_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocDATE_PRODAGI_REM_DZAKTPR(TFIBDateField * DocDATE_PRODAGI_REM_DZAKTPR)
{
Object->DocDATE_PRODAGI_REM_DZAKTPR=DocDATE_PRODAGI_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZAktPrImpl::get_DocTYPE_REMONT_REM_DZAKTPR(void)
{
return Object->DocTYPE_REMONT_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTYPE_REMONT_REM_DZAKTPR(TFIBIntegerField * DocTYPE_REMONT_REM_DZAKTPR)
{
Object->DocTYPE_REMONT_REM_DZAKTPR=DocTYPE_REMONT_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZAktPrImpl::get_DocKEM_SDANO_REM_DZAKTPR(void)
{
return Object->DocKEM_SDANO_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocKEM_SDANO_REM_DZAKTPR(TFIBIntegerField * DocKEM_SDANO_REM_DZAKTPR)
{
Object->DocKEM_SDANO_REM_DZAKTPR=DocKEM_SDANO_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocCFC_NAME(void)
{
return Object->DocCFC_NAME;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocCFC_NAME(TFIBWideStringField * DocCFC_NAME)
{
Object->DocCFC_NAME=DocCFC_NAME;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocCFC_CODE(void)
{
return Object->DocCFC_CODE;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocCFC_CODE(TFIBWideStringField * DocCFC_CODE)
{
Object->DocCFC_CODE=DocCFC_CODE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocDFC_NAME(void)
{
return Object->DocDFC_NAME;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocDFC_NAME(TFIBWideStringField * DocDFC_NAME)
{
Object->DocDFC_NAME=DocDFC_NAME;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocDFC_CODE(void)
{
return Object->DocDFC_CODE;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocDFC_CODE(TFIBWideStringField * DocDFC_CODE)
{
Object->DocDFC_CODE=DocDFC_CODE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocNAME_SPRODUCER(void)
{
return Object->DocNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNAME_SPRODUCER(TFIBWideStringField * DocNAME_SPRODUCER)
{
Object->DocNAME_SPRODUCER=DocNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocNAME_REM_SPRMODEL(void)
{
return Object->DocNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNAME_REM_SPRMODEL(TFIBWideStringField * DocNAME_REM_SPRMODEL)
{
Object->DocNAME_REM_SPRMODEL=DocNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocCODE_REM_SPRMODEL(void)
{
return Object->DocCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocCODE_REM_SPRMODEL(TFIBWideStringField * DocCODE_REM_SPRMODEL)
{
Object->DocCODE_REM_SPRMODEL=DocCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocNEISPR_REM_DZAKTPR(void)
{
return Object->DocNEISPR_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNEISPR_REM_DZAKTPR(TFIBWideStringField * DocNEISPR_REM_DZAKTPR)
{
Object->DocNEISPR_REM_DZAKTPR=DocNEISPR_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocNEISPR_REM_Z(void)
{
return Object->DocNEISPR_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNEISPR_REM_Z(TFIBWideStringField * DocNEISPR_REM_Z)
{
Object->DocNEISPR_REM_Z=DocNEISPR_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDPRDEFECT_REM_DZAKTPR(void)
{
return Object->DocTIDPRDEFECT_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDPRDEFECT_REM_DZAKTPR(TFIBLargeIntField * DocTIDPRDEFECT_REM_DZAKTPR)
{
Object->DocTIDPRDEFECT_REM_DZAKTPR=DocTIDPRDEFECT_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTCODE_REM_SPRDEFECT(void)
{
return Object->DocTCODE_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTCODE_REM_SPRDEFECT(TFIBWideStringField * DocTCODE_REM_SPRDEFECT)
{
Object->DocTCODE_REM_SPRDEFECT=DocTCODE_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_SPRDEFECT(void)
{
return Object->DocTNAME_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_SPRDEFECT(TFIBWideStringField * DocTNAME_REM_SPRDEFECT)
{
Object->DocTNAME_REM_SPRDEFECT=DocTNAME_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZAktPrImpl::get_DocFL_FICTIV_REM_DZAKTPR(void)
{
return Object->DocFL_FICTIV_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocFL_FICTIV_REM_DZAKTPR(TFIBIntegerField * DocFL_FICTIV_REM_DZAKTPR)
{
Object->DocFL_FICTIV_REM_DZAKTPR=DocFL_FICTIV_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocKLIENT_NAME_REM_DZAKTPR(void)
{
return Object->DocKLIENT_NAME_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocKLIENT_NAME_REM_DZAKTPR(TFIBWideStringField * DocKLIENT_NAME_REM_DZAKTPR)
{
Object->DocKLIENT_NAME_REM_DZAKTPR=DocKLIENT_NAME_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocKLIENT_ADR_REM_DZAKTPR(void)
{
return Object->DocKLIENT_ADR_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocKLIENT_ADR_REM_DZAKTPR(TFIBWideStringField * DocKLIENT_ADR_REM_DZAKTPR)
{
Object->DocKLIENT_ADR_REM_DZAKTPR=DocKLIENT_ADR_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocKLIENT_PHONE_REM_DZAKTPR(void)
{
return Object->DocKLIENT_PHONE_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocKLIENT_PHONE_REM_DZAKTPR(TFIBWideStringField * DocKLIENT_PHONE_REM_DZAKTPR)
{
Object->DocKLIENT_PHONE_REM_DZAKTPR=DocKLIENT_PHONE_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocIDDILER_REM_DZAKTPR(void)
{
return Object->DocIDDILER_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocIDDILER_REM_DZAKTPR(TFIBLargeIntField * DocIDDILER_REM_DZAKTPR)
{
Object->DocIDDILER_REM_DZAKTPR=DocIDDILER_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocNAMEKLIENT(void)
{
return Object->DocNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT)
{
Object->DocNAMEKLIENT=DocNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocPOST_ZIP_NAME(void)
{
return Object->DocPOST_ZIP_NAME;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocPOST_ZIP_NAME(TFIBWideStringField * DocPOST_ZIP_NAME)
{
Object->DocPOST_ZIP_NAME=DocPOST_ZIP_NAME;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZAktPrImpl::get_DocFL_OTCHET_POST_REM_DZAKTPR(void)
{
return Object->DocFL_OTCHET_POST_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocFL_OTCHET_POST_REM_DZAKTPR(TFIBSmallIntField * DocFL_OTCHET_POST_REM_DZAKTPR)
{
Object->DocFL_OTCHET_POST_REM_DZAKTPR=DocFL_OTCHET_POST_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocIDPOST_ZIP_REM_DZAKTPR(void)
{
return Object->DocIDPOST_ZIP_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocIDPOST_ZIP_REM_DZAKTPR(TFIBLargeIntField * DocIDPOST_ZIP_REM_DZAKTPR)
{
Object->DocIDPOST_ZIP_REM_DZAKTPR=DocIDPOST_ZIP_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZAktPrImpl::get_DocFL_NE_OTCH_REM_DZAKTPR(void)
{
return Object->DocFL_NE_OTCH_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocFL_NE_OTCH_REM_DZAKTPR(TFIBSmallIntField * DocFL_NE_OTCH_REM_DZAKTPR)
{
Object->DocFL_NE_OTCH_REM_DZAKTPR=DocFL_NE_OTCH_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZAktPrImpl::get_DocFL_NADO_OTCH_REM_DZAKTPR(void)
{
return Object->DocFL_NADO_OTCH_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocFL_NADO_OTCH_REM_DZAKTPR(TFIBSmallIntField * DocFL_NADO_OTCH_REM_DZAKTPR)
{
Object->DocFL_NADO_OTCH_REM_DZAKTPR=DocFL_NADO_OTCH_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZAktPrImpl::get_DocFL_PRIG_KREM_REM_DZAKTPR(void)
{
return Object->DocFL_PRIG_KREM_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocFL_PRIG_KREM_REM_DZAKTPR(TFIBSmallIntField * DocFL_PRIG_KREM_REM_DZAKTPR)
{
Object->DocFL_PRIG_KREM_REM_DZAKTPR=DocFL_PRIG_KREM_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocCODE_REM_SMODEL(void)
{
return Object->DocCODE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocCODE_REM_SMODEL(TFIBWideStringField * DocCODE_REM_SMODEL)
{
Object->DocCODE_REM_SMODEL=DocCODE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocNAME_REM_SPRNEISPR_GRP(void)
{
return Object->DocNAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * DocNAME_REM_SPRNEISPR_GRP)
{
Object->DocNAME_REM_SPRNEISPR_GRP=DocNAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZAktPrImpl::get_DocPOSPRIEMA_REM_DZAKTPR(void)
{
return Object->DocPOSPRIEMA_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocPOSPRIEMA_REM_DZAKTPR(TFIBDateTimeField * DocPOSPRIEMA_REM_DZAKTPR)
{
Object->DocPOSPRIEMA_REM_DZAKTPR=DocPOSPRIEMA_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocIDSELLER_REM_DZAKTPR(void)
{
return Object->DocIDSELLER_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocIDSELLER_REM_DZAKTPR(TFIBLargeIntField * DocIDSELLER_REM_DZAKTPR)
{
Object->DocIDSELLER_REM_DZAKTPR=DocIDSELLER_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocNAME_SSELLER(void)
{
return Object->DocNAME_SSELLER;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNAME_SSELLER(TFIBWideStringField * DocNAME_SSELLER)
{
Object->DocNAME_SSELLER=DocNAME_SSELLER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocCFC_NAME_ENG(void)
{
return Object->DocCFC_NAME_ENG;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocCFC_NAME_ENG(TFIBWideStringField * DocCFC_NAME_ENG)
{
Object->DocCFC_NAME_ENG=DocCFC_NAME_ENG;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocNAME_ENG_REM_SPRNEISPR_GRP(void)
{
return Object->DocNAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * DocNAME_ENG_REM_SPRNEISPR_GRP)
{
Object->DocNAME_ENG_REM_SPRNEISPR_GRP=DocNAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocKLIENT_EMAIL_REM_DZAKTPR(void)
{
return Object->DocKLIENT_EMAIL_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocKLIENT_EMAIL_REM_DZAKTPR(TFIBWideStringField * DocKLIENT_EMAIL_REM_DZAKTPR)
{
Object->DocKLIENT_EMAIL_REM_DZAKTPR=DocKLIENT_EMAIL_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocFAMILIYA_REM_DZAKTPR(void)
{
return Object->DocFAMILIYA_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocFAMILIYA_REM_DZAKTPR(TFIBWideStringField * DocFAMILIYA_REM_DZAKTPR)
{
Object->DocFAMILIYA_REM_DZAKTPR=DocFAMILIYA_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocIMYA_REM_DZAKTPR(void)
{
return Object->DocIMYA_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocIMYA_REM_DZAKTPR(TFIBWideStringField * DocIMYA_REM_DZAKTPR)
{
Object->DocIMYA_REM_DZAKTPR=DocIMYA_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocOTCHESTVO_REM_DZAKTPR(void)
{
return Object->DocOTCHESTVO_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocOTCHESTVO_REM_DZAKTPR(TFIBWideStringField * DocOTCHESTVO_REM_DZAKTPR)
{
Object->DocOTCHESTVO_REM_DZAKTPR=DocOTCHESTVO_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDPRNEISPR_REM_DZAKTPRT(void)
{
return Object->DocTIDPRNEISPR_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDPRNEISPR_REM_DZAKTPRT(TFIBLargeIntField * DocTIDPRNEISPR_REM_DZAKTPRT)
{
Object->DocTIDPRNEISPR_REM_DZAKTPRT=DocTIDPRNEISPR_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDPRRABOTA_REM_DZAKTPRT(void)
{
return Object->DocTIDPRRABOTA_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDPRRABOTA_REM_DZAKTPRT(TFIBLargeIntField * DocTIDPRRABOTA_REM_DZAKTPRT)
{
Object->DocTIDPRRABOTA_REM_DZAKTPRT=DocTIDPRRABOTA_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDHWOLD_REM_DZAKTPRT(void)
{
return Object->DocTIDHWOLD_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDHWOLD_REM_DZAKTPRT(TFIBLargeIntField * DocTIDHWOLD_REM_DZAKTPRT)
{
Object->DocTIDHWOLD_REM_DZAKTPRT=DocTIDHWOLD_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZAktPrImpl::get_DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT(void)
{
return Object->DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT(TFIBSmallIntField * DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT)
{
Object->DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT=DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_SPRNEISPR(void)
{
return Object->DocTNAME_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_SPRNEISPR(TFIBWideStringField * DocTNAME_REM_SPRNEISPR)
{
Object->DocTNAME_REM_SPRNEISPR=DocTNAME_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_ENG_REM_SPRNEISPR(void)
{
return Object->DocTNAME_ENG_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_ENG_REM_SPRNEISPR(TFIBWideStringField * DocTNAME_ENG_REM_SPRNEISPR)
{
Object->DocTNAME_ENG_REM_SPRNEISPR=DocTNAME_ENG_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTCODE_REM_SPRNEISPR(void)
{
return Object->DocTCODE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTCODE_REM_SPRNEISPR(TFIBWideStringField * DocTCODE_REM_SPRNEISPR)
{
Object->DocTCODE_REM_SPRNEISPR=DocTCODE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_SPRNEISPR_GRP(void)
{
return Object->DocTNAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * DocTNAME_REM_SPRNEISPR_GRP)
{
Object->DocTNAME_REM_SPRNEISPR_GRP=DocTNAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_ENG_REM_SPRNEISPR_GRP(void)
{
return Object->DocTNAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRNEISPR_GRP)
{
Object->DocTNAME_ENG_REM_SPRNEISPR_GRP=DocTNAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_SPRDEFECT_GRP(void)
{
return Object->DocTNAME_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_SPRDEFECT_GRP(TFIBWideStringField * DocTNAME_REM_SPRDEFECT_GRP)
{
Object->DocTNAME_REM_SPRDEFECT_GRP=DocTNAME_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_ENG_REM_SPRDEFECT_GRP(void)
{
return Object->DocTNAME_ENG_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_ENG_REM_SPRDEFECT_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRDEFECT_GRP)
{
Object->DocTNAME_ENG_REM_SPRDEFECT_GRP=DocTNAME_ENG_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTCODE_REM_SPRRABOTA(void)
{
return Object->DocTCODE_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTCODE_REM_SPRRABOTA(TFIBWideStringField * DocTCODE_REM_SPRRABOTA)
{
Object->DocTCODE_REM_SPRRABOTA=DocTCODE_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_SPRRABOTA(void)
{
return Object->DocTNAME_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_SPRRABOTA(TFIBWideStringField * DocTNAME_REM_SPRRABOTA)
{
Object->DocTNAME_REM_SPRRABOTA=DocTNAME_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_ENG_REM_SPRRABOTA(void)
{
return Object->DocTNAME_ENG_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_ENG_REM_SPRRABOTA(TFIBWideStringField * DocTNAME_ENG_REM_SPRRABOTA)
{
Object->DocTNAME_ENG_REM_SPRRABOTA=DocTNAME_ENG_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_SPRRABOTA_GRP(void)
{
return Object->DocTNAME_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_SPRRABOTA_GRP(TFIBWideStringField * DocTNAME_REM_SPRRABOTA_GRP)
{
Object->DocTNAME_REM_SPRRABOTA_GRP=DocTNAME_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_ENG_REM_SPRRABOTA_GRP(void)
{
return Object->DocTNAME_ENG_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_ENG_REM_SPRRABOTA_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRRABOTA_GRP)
{
Object->DocTNAME_ENG_REM_SPRRABOTA_GRP=DocTNAME_ENG_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTOLD_NAME_REM_SHARDWARE(void)
{
return Object->DocTOLD_NAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTOLD_NAME_REM_SHARDWARE(TFIBWideStringField * DocTOLD_NAME_REM_SHARDWARE)
{
Object->DocTOLD_NAME_REM_SHARDWARE=DocTOLD_NAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZAktPrImpl::get_DocTOLD_CODE_REM_SHARDWARE(void)
{
return Object->DocTOLD_CODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTOLD_CODE_REM_SHARDWARE(TFIBIntegerField * DocTOLD_CODE_REM_SHARDWARE)
{
Object->DocTOLD_CODE_REM_SHARDWARE=DocTOLD_CODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTOLD_SERNUM_REM_SHARDWARE(void)
{
return Object->DocTOLD_SERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTOLD_SERNUM_REM_SHARDWARE(TFIBWideStringField * DocTOLD_SERNUM_REM_SHARDWARE)
{
Object->DocTOLD_SERNUM_REM_SHARDWARE=DocTOLD_SERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZAktPrImpl::get_DocTFL_ISP_REM_DZAKTPRT(void)
{
return Object->DocTFL_ISP_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTFL_ISP_REM_DZAKTPRT(TFIBIntegerField * DocTFL_ISP_REM_DZAKTPRT)
{
Object->DocTFL_ISP_REM_DZAKTPRT=DocTFL_ISP_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDPRCOND_REM_DZAKTPRT(void)
{
return Object->DocTIDPRCOND_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDPRCOND_REM_DZAKTPRT(TFIBLargeIntField * DocTIDPRCOND_REM_DZAKTPRT)
{
Object->DocTIDPRCOND_REM_DZAKTPRT=DocTIDPRCOND_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDPRSECTION_REM_DZAKTPRT(void)
{
return Object->DocTIDPRSECTION_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDPRSECTION_REM_DZAKTPRT(TFIBLargeIntField * DocTIDPRSECTION_REM_DZAKTPRT)
{
Object->DocTIDPRSECTION_REM_DZAKTPRT=DocTIDPRSECTION_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTCODE_REM_SPRCONDITION(void)
{
return Object->DocTCODE_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTCODE_REM_SPRCONDITION(TFIBWideStringField * DocTCODE_REM_SPRCONDITION)
{
Object->DocTCODE_REM_SPRCONDITION=DocTCODE_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_SPRCONDITION(void)
{
return Object->DocTNAME_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_SPRCONDITION(TFIBWideStringField * DocTNAME_REM_SPRCONDITION)
{
Object->DocTNAME_REM_SPRCONDITION=DocTNAME_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_ENG_REM_SPRCONDITION(void)
{
return Object->DocTNAME_ENG_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_ENG_REM_SPRCONDITION(TFIBWideStringField * DocTNAME_ENG_REM_SPRCONDITION)
{
Object->DocTNAME_ENG_REM_SPRCONDITION=DocTNAME_ENG_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTCODE_REM_SPRCOND_GRP(void)
{
return Object->DocTCODE_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTCODE_REM_SPRCOND_GRP(TFIBWideStringField * DocTCODE_REM_SPRCOND_GRP)
{
Object->DocTCODE_REM_SPRCOND_GRP=DocTCODE_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_SPRCOND_GRP(void)
{
return Object->DocTNAME_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_SPRCOND_GRP(TFIBWideStringField * DocTNAME_REM_SPRCOND_GRP)
{
Object->DocTNAME_REM_SPRCOND_GRP=DocTNAME_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_ENG_REM_SPRCOND_GRP(void)
{
return Object->DocTNAME_ENG_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_ENG_REM_SPRCOND_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRCOND_GRP)
{
Object->DocTNAME_ENG_REM_SPRCOND_GRP=DocTNAME_ENG_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTCODE_REM_SPRSECTION(void)
{
return Object->DocTCODE_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTCODE_REM_SPRSECTION(TFIBWideStringField * DocTCODE_REM_SPRSECTION)
{
Object->DocTCODE_REM_SPRSECTION=DocTCODE_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_SPRSECTION(void)
{
return Object->DocTNAME_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_SPRSECTION(TFIBWideStringField * DocTNAME_REM_SPRSECTION)
{
Object->DocTNAME_REM_SPRSECTION=DocTNAME_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_ENG_REM_SPRSECTION(void)
{
return Object->DocTNAME_ENG_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_ENG_REM_SPRSECTION(TFIBWideStringField * DocTNAME_ENG_REM_SPRSECTION)
{
Object->DocTNAME_ENG_REM_SPRSECTION=DocTNAME_ENG_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTCODE_REM_SPRSECTION_GRP(void)
{
return Object->DocTCODE_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTCODE_REM_SPRSECTION_GRP(TFIBWideStringField * DocTCODE_REM_SPRSECTION_GRP)
{
Object->DocTCODE_REM_SPRSECTION_GRP=DocTCODE_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_SPRSECTION_GRP(void)
{
return Object->DocTNAME_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_SPRSECTION_GRP(TFIBWideStringField * DocTNAME_REM_SPRSECTION_GRP)
{
Object->DocTNAME_REM_SPRSECTION_GRP=DocTNAME_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_ENG_REM_SPRSECTION_GRP(void)
{
return Object->DocTNAME_ENG_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_ENG_REM_SPRSECTION_GRP(TFIBWideStringField * DocTNAME_ENG_REM_SPRSECTION_GRP)
{
Object->DocTNAME_ENG_REM_SPRSECTION_GRP=DocTNAME_ENG_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocAllIDOBJECT_REM_GALLDOC(void)
{
return Object->DocAllIDOBJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllIDOBJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC)
{
Object->DocAllIDOBJECT_REM_GALLDOC=DocAllIDOBJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocAllNAME_SOBJECT(void)
{
return Object->DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT)
{
Object->DocAllNAME_SOBJECT=DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDTNOM_REM_DZAKTPRT(void)
{
return Object->DocTIDTNOM_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDTNOM_REM_DZAKTPRT(TFIBLargeIntField * DocTIDTNOM_REM_DZAKTPRT)
{
Object->DocTIDTNOM_REM_DZAKTPRT=DocTIDTNOM_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDHW_DONOR_REM_DZAKTPRT(void)
{
return Object->DocTIDHW_DONOR_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDHW_DONOR_REM_DZAKTPRT(TFIBLargeIntField * DocTIDHW_DONOR_REM_DZAKTPRT)
{
Object->DocTIDHW_DONOR_REM_DZAKTPRT=DocTIDHW_DONOR_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDTYP_USEL_REM_DZAKTPRT(void)
{
return Object->DocTIDTYP_USEL_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDTYP_USEL_REM_DZAKTPRT(TFIBLargeIntField * DocTIDTYP_USEL_REM_DZAKTPRT)
{
Object->DocTIDTYP_USEL_REM_DZAKTPRT=DocTIDTYP_USEL_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTDESCR_REM_DZAKTPRT(void)
{
return Object->DocTDESCR_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTDESCR_REM_DZAKTPRT(TFIBWideStringField * DocTDESCR_REM_DZAKTPRT)
{
Object->DocTDESCR_REM_DZAKTPRT=DocTDESCR_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTDONOR_NAME_REM_SHARDWARE(void)
{
return Object->DocTDONOR_NAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTDONOR_NAME_REM_SHARDWARE(TFIBWideStringField * DocTDONOR_NAME_REM_SHARDWARE)
{
Object->DocTDONOR_NAME_REM_SHARDWARE=DocTDONOR_NAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZAktPrImpl::get_DocTDONOR_CODE_REM_SHARDWARE(void)
{
return Object->DocTDONOR_CODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTDONOR_CODE_REM_SHARDWARE(TFIBIntegerField * DocTDONOR_CODE_REM_SHARDWARE)
{
Object->DocTDONOR_CODE_REM_SHARDWARE=DocTDONOR_CODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTDONOR_SERNUM_REM_SHARDWARE(void)
{
return Object->DocTDONOR_SERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTDONOR_SERNUM_REM_SHARDWARE(TFIBWideStringField * DocTDONOR_SERNUM_REM_SHARDWARE)
{
Object->DocTDONOR_SERNUM_REM_SHARDWARE=DocTDONOR_SERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_STYPUSLOV(void)
{
return Object->DocTNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_STYPUSLOV(TFIBWideStringField * DocTNAME_REM_STYPUSLOV)
{
Object->DocTNAME_REM_STYPUSLOV=DocTNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_STNOM(void)
{
return Object->DocTNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)
{
Object->DocTNAME_STNOM=DocTNAME_STNOM;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZAktPrImpl::get_TypeNom(void)
{
return Object->TypeNom;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_TypeNom(TpFIBDataSet * TypeNom)
{
Object->TypeNom=TypeNom;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_TypeNomID_STNOM(void)
{
return Object->TypeNomID_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_TypeNomID_STNOM(TFIBLargeIntField * TypeNomID_STNOM)
{
Object->TypeNomID_STNOM=TypeNomID_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_TypeNomNAME_STNOM(void)
{
return Object->TypeNomNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_TypeNomNAME_STNOM(TFIBWideStringField * TypeNomNAME_STNOM)
{
Object->TypeNomNAME_STNOM=TypeNomNAME_STNOM;
}
//---------------------------------------------------------------
TStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_TYPE_NOM_LOOCUP(void)
{
return Object->DocTNAME_TYPE_NOM_LOOCUP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_TYPE_NOM_LOOCUP(TStringField * DocTNAME_TYPE_NOM_LOOCUP)
{
Object->DocTNAME_TYPE_NOM_LOOCUP=DocTNAME_TYPE_NOM_LOOCUP;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZAktPrImpl::get_DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR(void)
{
return Object->DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR(TFIBSmallIntField * DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR)
{
Object->DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR=DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDTVZIP_REM_DZAKTPRT(void)
{
return Object->DocTIDTVZIP_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDTVZIP_REM_DZAKTPRT(TFIBLargeIntField * DocTIDTVZIP_REM_DZAKTPRT)
{
Object->DocTIDTVZIP_REM_DZAKTPRT=DocTIDTVZIP_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZAktPrImpl::get_DocTIDMHRAN_REM_DZAKTPRT(void)
{
return Object->DocTIDMHRAN_REM_DZAKTPRT;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTIDMHRAN_REM_DZAKTPRT(TFIBLargeIntField * DocTIDMHRAN_REM_DZAKTPRT)
{
Object->DocTIDMHRAN_REM_DZAKTPRT=DocTIDMHRAN_REM_DZAKTPRT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_SMHRAN(void)
{
return Object->DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN)
{
Object->DocTNAME_SMHRAN=DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZAktPrImpl::get_DocTNAME_REM_STVZIP(void)
{
return Object->DocTNAME_REM_STVZIP;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_DocTNAME_REM_STVZIP(TFIBWideStringField * DocTNAME_REM_STVZIP)
{
Object->DocTNAME_REM_STVZIP=DocTNAME_REM_STVZIP;
}
//---------------------------------------------------------------
__int64 TREM_DMDocZAktPrImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocZAktPrImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocZAktPrImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZAktPrImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocZAktPrImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZAktPrImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocZAktPrImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZAktPrImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocZAktPrImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
