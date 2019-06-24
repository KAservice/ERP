#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocZOperImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocZOperImpl::TREM_DMDocZOperImpl()           
{                                            
Object=new TREM_DMDocZOper(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocZOperImpl::~TREM_DMDocZOperImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocZOperImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocZOper)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocZOper*> (this);                                
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
int TREM_DMDocZOperImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocZOperImpl::kanRelease(void)                                  
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
int  TREM_DMDocZOperImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocZOperImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocZOperImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocZOperImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocZOperImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocZOper
TDataSource * TREM_DMDocZOperImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocZOperImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocZOperImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZOperImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZOperImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZOperImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZOperImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZOperImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZOperImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZOperImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZOperImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZOperImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZOperImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZOperImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocZOperImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZOperImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZOperImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZOperImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZOperImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZOperImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocID_REM_DZOPER(void)
{
return Object->DocID_REM_DZOPER;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocID_REM_DZOPER(TFIBLargeIntField * DocID_REM_DZOPER)
{
Object->DocID_REM_DZOPER=DocID_REM_DZOPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocIDBASE_REM_DZOPER(void)
{
return Object->DocIDBASE_REM_DZOPER;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocIDBASE_REM_DZOPER(TFIBLargeIntField * DocIDBASE_REM_DZOPER)
{
Object->DocIDBASE_REM_DZOPER=DocIDBASE_REM_DZOPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocGID_REM_DZOPER(void)
{
return Object->DocGID_REM_DZOPER;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocGID_REM_DZOPER(TFIBWideStringField * DocGID_REM_DZOPER)
{
Object->DocGID_REM_DZOPER=DocGID_REM_DZOPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocIDDOC_REM_DZOPER(void)
{
return Object->DocIDDOC_REM_DZOPER;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocIDDOC_REM_DZOPER(TFIBLargeIntField * DocIDDOC_REM_DZOPER)
{
Object->DocIDDOC_REM_DZOPER=DocIDDOC_REM_DZOPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocIDZ_REM_DZOPER(void)
{
return Object->DocIDZ_REM_DZOPER;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocIDZ_REM_DZOPER(TFIBLargeIntField * DocIDZ_REM_DZOPER)
{
Object->DocIDZ_REM_DZOPER=DocIDZ_REM_DZOPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocIDTPRICE_REM_DZOPER(void)
{
return Object->DocIDTPRICE_REM_DZOPER;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocIDTPRICE_REM_DZOPER(TFIBLargeIntField * DocIDTPRICE_REM_DZOPER)
{
Object->DocIDTPRICE_REM_DZOPER=DocIDTPRICE_REM_DZOPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocPRIM_REM_DZOPER(void)
{
return Object->DocPRIM_REM_DZOPER;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocPRIM_REM_DZOPER(TFIBWideStringField * DocPRIM_REM_DZOPER)
{
Object->DocPRIM_REM_DZOPER=DocPRIM_REM_DZOPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocNAME_REM_Z(void)
{
return Object->DocNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z)
{
Object->DocNAME_REM_Z=DocNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZOperImpl::get_DocNUM_REM_Z(void)
{
return Object->DocNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocNUM_REM_Z(TFIBIntegerField * DocNUM_REM_Z)
{
Object->DocNUM_REM_Z=DocNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZOperImpl::get_DocPOS_REM_Z(void)
{
return Object->DocPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocPOS_REM_Z(TFIBDateTimeField * DocPOS_REM_Z)
{
Object->DocPOS_REM_Z=DocPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocSERNUM_REM_Z(void)
{
return Object->DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocSERNUM_REM_Z(TFIBWideStringField * DocSERNUM_REM_Z)
{
Object->DocSERNUM_REM_Z=DocSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocSERNUM2_REM_Z(void)
{
return Object->DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocSERNUM2_REM_Z(TFIBWideStringField * DocSERNUM2_REM_Z)
{
Object->DocSERNUM2_REM_Z=DocSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocKLIENT_NAME_REM_Z(void)
{
return Object->DocKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocKLIENT_NAME_REM_Z(TFIBWideStringField * DocKLIENT_NAME_REM_Z)
{
Object->DocKLIENT_NAME_REM_Z=DocKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocMODEL_REM_Z(void)
{
return Object->DocMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z)
{
Object->DocMODEL_REM_Z=DocMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocNAME_REM_SMODEL(void)
{
return Object->DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL)
{
Object->DocNAME_REM_SMODEL=DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocTID_REM_DZOPERT(void)
{
return Object->DocTID_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTID_REM_DZOPERT(TFIBLargeIntField * DocTID_REM_DZOPERT)
{
Object->DocTID_REM_DZOPERT=DocTID_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocTIDBASE_REM_DZOPERT(void)
{
return Object->DocTIDBASE_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTIDBASE_REM_DZOPERT(TFIBLargeIntField * DocTIDBASE_REM_DZOPERT)
{
Object->DocTIDBASE_REM_DZOPERT=DocTIDBASE_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTGID_REM_DZOPERT(void)
{
return Object->DocTGID_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTGID_REM_DZOPERT(TFIBWideStringField * DocTGID_REM_DZOPERT)
{
Object->DocTGID_REM_DZOPERT=DocTGID_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocTIDDOC_REM_DZOPERT(void)
{
return Object->DocTIDDOC_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTIDDOC_REM_DZOPERT(TFIBLargeIntField * DocTIDDOC_REM_DZOPERT)
{
Object->DocTIDDOC_REM_DZOPERT=DocTIDDOC_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocTIDNOM_REM_DZOPERT(void)
{
return Object->DocTIDNOM_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTIDNOM_REM_DZOPERT(TFIBLargeIntField * DocTIDNOM_REM_DZOPERT)
{
Object->DocTIDNOM_REM_DZOPERT=DocTIDNOM_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocTIDED_REM_DZOPERT(void)
{
return Object->DocTIDED_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTIDED_REM_DZOPERT(TFIBLargeIntField * DocTIDED_REM_DZOPERT)
{
Object->DocTIDED_REM_DZOPERT=DocTIDED_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocTIDHW_REM_DZOPERT(void)
{
return Object->DocTIDHW_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTIDHW_REM_DZOPERT(TFIBLargeIntField * DocTIDHW_REM_DZOPERT)
{
Object->DocTIDHW_REM_DZOPERT=DocTIDHW_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZOperImpl::get_DocTKOL_REM_DZOPERT(void)
{
return Object->DocTKOL_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTKOL_REM_DZOPERT(TFIBBCDField * DocTKOL_REM_DZOPERT)
{
Object->DocTKOL_REM_DZOPERT=DocTKOL_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZOperImpl::get_DocTKF_REM_DZOPERT(void)
{
return Object->DocTKF_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTKF_REM_DZOPERT(TFIBBCDField * DocTKF_REM_DZOPERT)
{
Object->DocTKF_REM_DZOPERT=DocTKF_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZOperImpl::get_DocTPRICE_REM_DZOPERT(void)
{
return Object->DocTPRICE_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTPRICE_REM_DZOPERT(TFIBBCDField * DocTPRICE_REM_DZOPERT)
{
Object->DocTPRICE_REM_DZOPERT=DocTPRICE_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZOperImpl::get_DocTSUM_REM_DZOPERT(void)
{
return Object->DocTSUM_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTSUM_REM_DZOPERT(TFIBBCDField * DocTSUM_REM_DZOPERT)
{
Object->DocTSUM_REM_DZOPERT=DocTSUM_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZOperImpl::get_DocTDVREG_REM_DZOPERT(void)
{
return Object->DocTDVREG_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTDVREG_REM_DZOPERT(TFIBSmallIntField * DocTDVREG_REM_DZOPERT)
{
Object->DocTDVREG_REM_DZOPERT=DocTDVREG_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTSTR_NAMENOM_REM_DZOPERT(void)
{
return Object->DocTSTR_NAMENOM_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTSTR_NAMENOM_REM_DZOPERT(TFIBWideStringField * DocTSTR_NAMENOM_REM_DZOPERT)
{
Object->DocTSTR_NAMENOM_REM_DZOPERT=DocTSTR_NAMENOM_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZOperImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZOperImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocTIDHWOLD_REM_DZOPERT(void)
{
return Object->DocTIDHWOLD_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTIDHWOLD_REM_DZOPERT(TFIBLargeIntField * DocTIDHWOLD_REM_DZOPERT)
{
Object->DocTIDHWOLD_REM_DZOPERT=DocTIDHWOLD_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocTIDTNOM_REM_DZOPERT(void)
{
return Object->DocTIDTNOM_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTIDTNOM_REM_DZOPERT(TFIBLargeIntField * DocTIDTNOM_REM_DZOPERT)
{
Object->DocTIDTNOM_REM_DZOPERT=DocTIDTNOM_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocTIDHW_DONOR_REM_DZOPERT(void)
{
return Object->DocTIDHW_DONOR_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTIDHW_DONOR_REM_DZOPERT(TFIBLargeIntField * DocTIDHW_DONOR_REM_DZOPERT)
{
Object->DocTIDHW_DONOR_REM_DZOPERT=DocTIDHW_DONOR_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocTIDTYP_USEL_REM_DZOPERT(void)
{
return Object->DocTIDTYP_USEL_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTIDTYP_USEL_REM_DZOPERT(TFIBLargeIntField * DocTIDTYP_USEL_REM_DZOPERT)
{
Object->DocTIDTYP_USEL_REM_DZOPERT=DocTIDTYP_USEL_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZOperImpl::get_DocTIDMHRAN_REM_DZOPERT(void)
{
return Object->DocTIDMHRAN_REM_DZOPERT;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTIDMHRAN_REM_DZOPERT(TFIBLargeIntField * DocTIDMHRAN_REM_DZOPERT)
{
Object->DocTIDMHRAN_REM_DZOPERT=DocTIDMHRAN_REM_DZOPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTOLD_NAME_REM_SHARDWARE(void)
{
return Object->DocTOLD_NAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTOLD_NAME_REM_SHARDWARE(TFIBWideStringField * DocTOLD_NAME_REM_SHARDWARE)
{
Object->DocTOLD_NAME_REM_SHARDWARE=DocTOLD_NAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZOperImpl::get_DocTOLD_CODE_REM_SHARDWARE(void)
{
return Object->DocTOLD_CODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTOLD_CODE_REM_SHARDWARE(TFIBIntegerField * DocTOLD_CODE_REM_SHARDWARE)
{
Object->DocTOLD_CODE_REM_SHARDWARE=DocTOLD_CODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTOLD_SERNUM_REM_SHARDWARE(void)
{
return Object->DocTOLD_SERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTOLD_SERNUM_REM_SHARDWARE(TFIBWideStringField * DocTOLD_SERNUM_REM_SHARDWARE)
{
Object->DocTOLD_SERNUM_REM_SHARDWARE=DocTOLD_SERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTDONOR_NAME_REM_SHARDWARE(void)
{
return Object->DocTDONOR_NAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTDONOR_NAME_REM_SHARDWARE(TFIBWideStringField * DocTDONOR_NAME_REM_SHARDWARE)
{
Object->DocTDONOR_NAME_REM_SHARDWARE=DocTDONOR_NAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZOperImpl::get_DocTDONOR_CODE_REM_SHARDWARE(void)
{
return Object->DocTDONOR_CODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTDONOR_CODE_REM_SHARDWARE(TFIBIntegerField * DocTDONOR_CODE_REM_SHARDWARE)
{
Object->DocTDONOR_CODE_REM_SHARDWARE=DocTDONOR_CODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTDONOR_SERNUM_REM_SHARDWARE(void)
{
return Object->DocTDONOR_SERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTDONOR_SERNUM_REM_SHARDWARE(TFIBWideStringField * DocTDONOR_SERNUM_REM_SHARDWARE)
{
Object->DocTDONOR_SERNUM_REM_SHARDWARE=DocTDONOR_SERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTNAME_STNOM(void)
{
return Object->DocTNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)
{
Object->DocTNAME_STNOM=DocTNAME_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTNAME_SMHRAN(void)
{
return Object->DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN)
{
Object->DocTNAME_SMHRAN=DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZOperImpl::get_DocTNAME_REM_STYPUSLOV(void)
{
return Object->DocTNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_DocTNAME_REM_STYPUSLOV(TFIBWideStringField * DocTNAME_REM_STYPUSLOV)
{
Object->DocTNAME_REM_STYPUSLOV=DocTNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
__int64 TREM_DMDocZOperImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocZOperImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocZOperImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZOperImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocZOperImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZOperImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocZOperImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZOperImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocZOperImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
