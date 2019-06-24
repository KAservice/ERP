#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocVosvratDileruImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocVosvratDileruImpl::TREM_DMDocVosvratDileruImpl()           
{                                            
Object=new TREM_DMDocVosvratDileru(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocVosvratDileruImpl::~TREM_DMDocVosvratDileruImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocVosvratDileruImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocVosvratDileru)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocVosvratDileru*> (this);                                
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
int TREM_DMDocVosvratDileruImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocVosvratDileruImpl::kanRelease(void)                                  
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
int  TREM_DMDocVosvratDileruImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocVosvratDileruImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVosvratDileruImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocVosvratDileruImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVosvratDileruImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocVosvratDileru
TDataSource * TREM_DMDocVosvratDileruImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVosvratDileruImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVosvratDileruImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratDileruImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratDileruImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratDileruImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVosvratDileruImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVosvratDileruImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVosvratDileruImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVosvratDileruImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVosvratDileruImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVosvratDileruImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVosvratDileruImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratDileruImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVosvratDileruImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratDileruImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocVosvratDileruImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratDileruImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratDileruImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocVosvratDileruImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocID_REM_DDILRET(void)
{
return Object->DocID_REM_DDILRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocID_REM_DDILRET(TFIBLargeIntField * DocID_REM_DDILRET)
{
Object->DocID_REM_DDILRET=DocID_REM_DDILRET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocIDBASE_REM_DDILRET(void)
{
return Object->DocIDBASE_REM_DDILRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocIDBASE_REM_DDILRET(TFIBLargeIntField * DocIDBASE_REM_DDILRET)
{
Object->DocIDBASE_REM_DDILRET=DocIDBASE_REM_DDILRET;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocGID_REM_DDILRET(void)
{
return Object->DocGID_REM_DDILRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocGID_REM_DDILRET(TFIBWideStringField * DocGID_REM_DDILRET)
{
Object->DocGID_REM_DDILRET=DocGID_REM_DDILRET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocIDDOC_REM_DDILRET(void)
{
return Object->DocIDDOC_REM_DDILRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocIDDOC_REM_DDILRET(TFIBLargeIntField * DocIDDOC_REM_DDILRET)
{
Object->DocIDDOC_REM_DDILRET=DocIDDOC_REM_DDILRET;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocNUMDOCDIL_REM_DDILRET(void)
{
return Object->DocNUMDOCDIL_REM_DDILRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocNUMDOCDIL_REM_DDILRET(TFIBWideStringField * DocNUMDOCDIL_REM_DDILRET)
{
Object->DocNUMDOCDIL_REM_DDILRET=DocNUMDOCDIL_REM_DDILRET;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVosvratDileruImpl::get_DocPOSDOCDIL_REM_DDILRET(void)
{
return Object->DocPOSDOCDIL_REM_DDILRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocPOSDOCDIL_REM_DDILRET(TFIBDateTimeField * DocPOSDOCDIL_REM_DDILRET)
{
Object->DocPOSDOCDIL_REM_DDILRET=DocPOSDOCDIL_REM_DDILRET;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocPRIM_REM_DDILRET(void)
{
return Object->DocPRIM_REM_DDILRET;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocPRIM_REM_DDILRET(TFIBWideStringField * DocPRIM_REM_DDILRET)
{
Object->DocPRIM_REM_DDILRET=DocPRIM_REM_DDILRET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocTID_REM_DDILRETT(void)
{
return Object->DocTID_REM_DDILRETT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTID_REM_DDILRETT(TFIBLargeIntField * DocTID_REM_DDILRETT)
{
Object->DocTID_REM_DDILRETT=DocTID_REM_DDILRETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocTIDBASE_REM_DDILRETT(void)
{
return Object->DocTIDBASE_REM_DDILRETT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTIDBASE_REM_DDILRETT(TFIBLargeIntField * DocTIDBASE_REM_DDILRETT)
{
Object->DocTIDBASE_REM_DDILRETT=DocTIDBASE_REM_DDILRETT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocTGID_REM_DDILRETT(void)
{
return Object->DocTGID_REM_DDILRETT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTGID_REM_DDILRETT(TFIBWideStringField * DocTGID_REM_DDILRETT)
{
Object->DocTGID_REM_DDILRETT=DocTGID_REM_DDILRETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocTIDDOC_REM_DDILRETT(void)
{
return Object->DocTIDDOC_REM_DDILRETT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTIDDOC_REM_DDILRETT(TFIBLargeIntField * DocTIDDOC_REM_DDILRETT)
{
Object->DocTIDDOC_REM_DDILRETT=DocTIDDOC_REM_DDILRETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocTIDZ_REM_DDILRETT(void)
{
return Object->DocTIDZ_REM_DDILRETT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTIDZ_REM_DDILRETT(TFIBLargeIntField * DocTIDZ_REM_DDILRETT)
{
Object->DocTIDZ_REM_DDILRETT=DocTIDZ_REM_DDILRETT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVosvratDileruImpl::get_DocTKOL_REM_DDILRETT(void)
{
return Object->DocTKOL_REM_DDILRETT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTKOL_REM_DDILRETT(TFIBBCDField * DocTKOL_REM_DDILRETT)
{
Object->DocTKOL_REM_DDILRETT=DocTKOL_REM_DDILRETT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocTNAME_REM_Z(void)
{
return Object->DocTNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z)
{
Object->DocTNAME_REM_Z=DocTNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVosvratDileruImpl::get_DocTNUM_REM_Z(void)
{
return Object->DocTNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z)
{
Object->DocTNUM_REM_Z=DocTNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVosvratDileruImpl::get_DocTPOS_REM_Z(void)
{
return Object->DocTPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z)
{
Object->DocTPOS_REM_Z=DocTPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocTSERNUM_REM_Z(void)
{
return Object->DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z)
{
Object->DocTSERNUM_REM_Z=DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocTSERNUM2_REM_Z(void)
{
return Object->DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z)
{
Object->DocTSERNUM2_REM_Z=DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocTKLIENT_NAME_REM_Z(void)
{
return Object->DocTKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTKLIENT_NAME_REM_Z(TFIBWideStringField * DocTKLIENT_NAME_REM_Z)
{
Object->DocTKLIENT_NAME_REM_Z=DocTKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocTMODEL_REM_Z(void)
{
return Object->DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z)
{
Object->DocTMODEL_REM_Z=DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVosvratDileruImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVosvratDileruImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
__int64 TREM_DMDocVosvratDileruImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratDileruImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratDileruImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratDileruImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratDileruImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratDileruImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratDileruImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVosvratDileruImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocVosvratDileruImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
