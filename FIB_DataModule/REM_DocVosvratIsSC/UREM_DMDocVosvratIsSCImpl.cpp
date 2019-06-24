#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocVosvratIsSCImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocVosvratIsSCImpl::TREM_DMDocVosvratIsSCImpl()           
{                                            
Object=new TREM_DMDocVosvratIsSC(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocVosvratIsSCImpl::~TREM_DMDocVosvratIsSCImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocVosvratIsSCImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocVosvratIsSC)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocVosvratIsSC*> (this);                                
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
int TREM_DMDocVosvratIsSCImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocVosvratIsSCImpl::kanRelease(void)                                  
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
int  TREM_DMDocVosvratIsSCImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocVosvratIsSCImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVosvratIsSCImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocVosvratIsSCImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVosvratIsSCImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocVosvratIsSC
TDataSource * TREM_DMDocVosvratIsSCImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVosvratIsSCImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVosvratIsSCImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratIsSCImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratIsSCImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratIsSCImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVosvratIsSCImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVosvratIsSCImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVosvratIsSCImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratIsSCImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVosvratIsSCImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVosvratIsSCImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVosvratIsSCImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratIsSCImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVosvratIsSCImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratIsSCImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocVosvratIsSCImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratIsSCImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratIsSCImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocVosvratIsSCImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocID_REM_DSCRET(void)
{
return Object->DocID_REM_DSCRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocID_REM_DSCRET(TFIBLargeIntField * DocID_REM_DSCRET)
{
Object->DocID_REM_DSCRET=DocID_REM_DSCRET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocIDBASE_REM_DSCRET(void)
{
return Object->DocIDBASE_REM_DSCRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocIDBASE_REM_DSCRET(TFIBLargeIntField * DocIDBASE_REM_DSCRET)
{
Object->DocIDBASE_REM_DSCRET=DocIDBASE_REM_DSCRET;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocGID_REM_DSCRET(void)
{
return Object->DocGID_REM_DSCRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocGID_REM_DSCRET(TFIBWideStringField * DocGID_REM_DSCRET)
{
Object->DocGID_REM_DSCRET=DocGID_REM_DSCRET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocIDDOC_REM_DSCRET(void)
{
return Object->DocIDDOC_REM_DSCRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocIDDOC_REM_DSCRET(TFIBLargeIntField * DocIDDOC_REM_DSCRET)
{
Object->DocIDDOC_REM_DSCRET=DocIDDOC_REM_DSCRET;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocNUMDOCSC_REM_DSCRET(void)
{
return Object->DocNUMDOCSC_REM_DSCRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocNUMDOCSC_REM_DSCRET(TFIBWideStringField * DocNUMDOCSC_REM_DSCRET)
{
Object->DocNUMDOCSC_REM_DSCRET=DocNUMDOCSC_REM_DSCRET;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVosvratIsSCImpl::get_DocPOSDOCSC_REM_DSCRET(void)
{
return Object->DocPOSDOCSC_REM_DSCRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocPOSDOCSC_REM_DSCRET(TFIBDateTimeField * DocPOSDOCSC_REM_DSCRET)
{
Object->DocPOSDOCSC_REM_DSCRET=DocPOSDOCSC_REM_DSCRET;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocPRIM_REM_DSCRET(void)
{
return Object->DocPRIM_REM_DSCRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocPRIM_REM_DSCRET(TFIBWideStringField * DocPRIM_REM_DSCRET)
{
Object->DocPRIM_REM_DSCRET=DocPRIM_REM_DSCRET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocTID_REM_DSCRETT(void)
{
return Object->DocTID_REM_DSCRETT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTID_REM_DSCRETT(TFIBLargeIntField * DocTID_REM_DSCRETT)
{
Object->DocTID_REM_DSCRETT=DocTID_REM_DSCRETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocTIDBASE_REM_DSCRETT(void)
{
return Object->DocTIDBASE_REM_DSCRETT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTIDBASE_REM_DSCRETT(TFIBLargeIntField * DocTIDBASE_REM_DSCRETT)
{
Object->DocTIDBASE_REM_DSCRETT=DocTIDBASE_REM_DSCRETT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocTGID_REM_DSCRETT(void)
{
return Object->DocTGID_REM_DSCRETT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTGID_REM_DSCRETT(TFIBWideStringField * DocTGID_REM_DSCRETT)
{
Object->DocTGID_REM_DSCRETT=DocTGID_REM_DSCRETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocTIDDOC_REM_DSCRETT(void)
{
return Object->DocTIDDOC_REM_DSCRETT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTIDDOC_REM_DSCRETT(TFIBLargeIntField * DocTIDDOC_REM_DSCRETT)
{
Object->DocTIDDOC_REM_DSCRETT=DocTIDDOC_REM_DSCRETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocTIDZ_REM_DSCRETT(void)
{
return Object->DocTIDZ_REM_DSCRETT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTIDZ_REM_DSCRETT(TFIBLargeIntField * DocTIDZ_REM_DSCRETT)
{
Object->DocTIDZ_REM_DSCRETT=DocTIDZ_REM_DSCRETT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratIsSCImpl::get_DocTKOL_REM_DSCRETT(void)
{
return Object->DocTKOL_REM_DSCRETT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTKOL_REM_DSCRETT(TFIBBCDField * DocTKOL_REM_DSCRETT)
{
Object->DocTKOL_REM_DSCRETT=DocTKOL_REM_DSCRETT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocTNAME_REM_Z(void)
{
return Object->DocTNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z)
{
Object->DocTNAME_REM_Z=DocTNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratIsSCImpl::get_DocTNUM_REM_Z(void)
{
return Object->DocTNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z)
{
Object->DocTNUM_REM_Z=DocTNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVosvratIsSCImpl::get_DocTPOS_REM_Z(void)
{
return Object->DocTPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z)
{
Object->DocTPOS_REM_Z=DocTPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocTSERNUM_REM_Z(void)
{
return Object->DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z)
{
Object->DocTSERNUM_REM_Z=DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocTSERNUM2_REM_Z(void)
{
return Object->DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z)
{
Object->DocTSERNUM2_REM_Z=DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocTKLIENT_NAME_REM_Z(void)
{
return Object->DocTKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTKLIENT_NAME_REM_Z(TFIBWideStringField * DocTKLIENT_NAME_REM_Z)
{
Object->DocTKLIENT_NAME_REM_Z=DocTKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocTMODEL_REM_Z(void)
{
return Object->DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z)
{
Object->DocTMODEL_REM_Z=DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratIsSCImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratIsSCImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
__int64 TREM_DMDocVosvratIsSCImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratIsSCImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratIsSCImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratIsSCImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratIsSCImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratIsSCImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratIsSCImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratIsSCImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocVosvratIsSCImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
