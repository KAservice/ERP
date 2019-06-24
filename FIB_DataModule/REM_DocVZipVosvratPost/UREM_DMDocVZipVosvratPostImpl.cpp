#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocVZipVosvratPostImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocVZipVosvratPostImpl::TREM_DMDocVZipVosvratPostImpl()           
{                                            
Object=new TREM_DMDocVZipVosvratPost(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocVZipVosvratPostImpl::~TREM_DMDocVZipVosvratPostImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocVZipVosvratPostImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocVZipVosvratPost)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocVZipVosvratPost*> (this);                                
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
int TREM_DMDocVZipVosvratPostImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocVZipVosvratPostImpl::kanRelease(void)                                  
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
int  TREM_DMDocVZipVosvratPostImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocVZipVosvratPostImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVZipVosvratPostImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocVZipVosvratPostImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocVZipVosvratPostImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocVZipVosvratPost
TDataSource * TREM_DMDocVZipVosvratPostImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVZipVosvratPostImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocVZipVosvratPostImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVZipVosvratPostImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVZipVosvratPostImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVZipVosvratPostImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVZipVosvratPostImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVZipVosvratPostImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocVZipVosvratPostImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocVZipVosvratPostImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVZipVosvratPostImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVZipVosvratPostImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocVZipVosvratPostImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVZipVosvratPostImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVZipVosvratPostImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocVZipVosvratPostImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVZipVosvratPostImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVZipVosvratPostImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocAllIDOBJECT_REM_GALLDOC(void)
{
return Object->DocAllIDOBJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllIDOBJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC)
{
Object->DocAllIDOBJECT_REM_GALLDOC=DocAllIDOBJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocAllNAME_SOBJECT(void)
{
return Object->DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT)
{
Object->DocAllNAME_SOBJECT=DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocID_REM_DVZVPO(void)
{
return Object->DocID_REM_DVZVPO;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocID_REM_DVZVPO(TFIBLargeIntField * DocID_REM_DVZVPO)
{
Object->DocID_REM_DVZVPO=DocID_REM_DVZVPO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocIDBASE_REM_DVZVPO(void)
{
return Object->DocIDBASE_REM_DVZVPO;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocIDBASE_REM_DVZVPO(TFIBLargeIntField * DocIDBASE_REM_DVZVPO)
{
Object->DocIDBASE_REM_DVZVPO=DocIDBASE_REM_DVZVPO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocIDDOC_REM_DVZVPO(void)
{
return Object->DocIDDOC_REM_DVZVPO;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocIDDOC_REM_DVZVPO(TFIBLargeIntField * DocIDDOC_REM_DVZVPO)
{
Object->DocIDDOC_REM_DVZVPO=DocIDDOC_REM_DVZVPO;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocDESCR_REM_DVZVPO(void)
{
return Object->DocDESCR_REM_DVZVPO;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocDESCR_REM_DVZVPO(TFIBWideStringField * DocDESCR_REM_DVZVPO)
{
Object->DocDESCR_REM_DVZVPO=DocDESCR_REM_DVZVPO;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVZipVosvratPostImpl::get_DocOPER_REM_DVZVPO(void)
{
return Object->DocOPER_REM_DVZVPO;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocOPER_REM_DVZVPO(TFIBIntegerField * DocOPER_REM_DVZVPO)
{
Object->DocOPER_REM_DVZVPO=DocOPER_REM_DVZVPO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocTID_REM_DVZVPOT(void)
{
return Object->DocTID_REM_DVZVPOT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTID_REM_DVZVPOT(TFIBLargeIntField * DocTID_REM_DVZVPOT)
{
Object->DocTID_REM_DVZVPOT=DocTID_REM_DVZVPOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocTIDBASE_REM_DVZVPOT(void)
{
return Object->DocTIDBASE_REM_DVZVPOT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTIDBASE_REM_DVZVPOT(TFIBLargeIntField * DocTIDBASE_REM_DVZVPOT)
{
Object->DocTIDBASE_REM_DVZVPOT=DocTIDBASE_REM_DVZVPOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocTIDDOC_REM_DVZVPOT(void)
{
return Object->DocTIDDOC_REM_DVZVPOT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTIDDOC_REM_DVZVPOT(TFIBLargeIntField * DocTIDDOC_REM_DVZVPOT)
{
Object->DocTIDDOC_REM_DVZVPOT=DocTIDDOC_REM_DVZVPOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocTIDTNOM_REM_DVZVPOT(void)
{
return Object->DocTIDTNOM_REM_DVZVPOT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTIDTNOM_REM_DVZVPOT(TFIBLargeIntField * DocTIDTNOM_REM_DVZVPOT)
{
Object->DocTIDTNOM_REM_DVZVPOT=DocTIDTNOM_REM_DVZVPOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocTIDNOM_REM_DVZVPOT(void)
{
return Object->DocTIDNOM_REM_DVZVPOT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTIDNOM_REM_DVZVPOT(TFIBLargeIntField * DocTIDNOM_REM_DVZVPOT)
{
Object->DocTIDNOM_REM_DVZVPOT=DocTIDNOM_REM_DVZVPOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocTIDZ_REM_DVZVPOT(void)
{
return Object->DocTIDZ_REM_DVZVPOT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTIDZ_REM_DVZVPOT(TFIBLargeIntField * DocTIDZ_REM_DVZVPOT)
{
Object->DocTIDZ_REM_DVZVPOT=DocTIDZ_REM_DVZVPOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocTIDHW_REM_DVZVPOT(void)
{
return Object->DocTIDHW_REM_DVZVPOT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTIDHW_REM_DVZVPOT(TFIBLargeIntField * DocTIDHW_REM_DVZVPOT)
{
Object->DocTIDHW_REM_DVZVPOT=DocTIDHW_REM_DVZVPOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocTIDTVZIP_REM_DVZVPOT(void)
{
return Object->DocTIDTVZIP_REM_DVZVPOT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTIDTVZIP_REM_DVZVPOT(TFIBLargeIntField * DocTIDTVZIP_REM_DVZVPOT)
{
Object->DocTIDTVZIP_REM_DVZVPOT=DocTIDTVZIP_REM_DVZVPOT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocVZipVosvratPostImpl::get_DocTKOL_REM_DVZVPOT(void)
{
return Object->DocTKOL_REM_DVZVPOT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTKOL_REM_DVZVPOT(TFIBBCDField * DocTKOL_REM_DVZVPOT)
{
Object->DocTKOL_REM_DVZVPOT=DocTKOL_REM_DVZVPOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTNAME_REM_Z(void)
{
return Object->DocTNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z)
{
Object->DocTNAME_REM_Z=DocTNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVZipVosvratPostImpl::get_DocTNUM_REM_Z(void)
{
return Object->DocTNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z)
{
Object->DocTNUM_REM_Z=DocTNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocVZipVosvratPostImpl::get_DocTPOS_REM_Z(void)
{
return Object->DocTPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z)
{
Object->DocTPOS_REM_Z=DocTPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTSERNUM_REM_Z(void)
{
return Object->DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z)
{
Object->DocTSERNUM_REM_Z=DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTSERNUM2_REM_Z(void)
{
return Object->DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z)
{
Object->DocTSERNUM2_REM_Z=DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTKLIENT_NAME_REM_Z(void)
{
return Object->DocTKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTKLIENT_NAME_REM_Z(TFIBWideStringField * DocTKLIENT_NAME_REM_Z)
{
Object->DocTKLIENT_NAME_REM_Z=DocTKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTMODEL_REM_Z(void)
{
return Object->DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z)
{
Object->DocTMODEL_REM_Z=DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTNAME_STNOM(void)
{
return Object->DocTNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)
{
Object->DocTNAME_STNOM=DocTNAME_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTNAME_REM_STVZIP(void)
{
return Object->DocTNAME_REM_STVZIP;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTNAME_REM_STVZIP(TFIBWideStringField * DocTNAME_REM_STVZIP)
{
Object->DocTNAME_REM_STVZIP=DocTNAME_REM_STVZIP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTSERNUM2_REM_SHARDWARE(void)
{
return Object->DocTSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM2_REM_SHARDWARE)
{
Object->DocTSERNUM2_REM_SHARDWARE=DocTSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTNAME_REM_SPRMODEL(void)
{
return Object->DocTNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTNAME_REM_SPRMODEL(TFIBWideStringField * DocTNAME_REM_SPRMODEL)
{
Object->DocTNAME_REM_SPRMODEL=DocTNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocVZipVosvratPostImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocVZipVosvratPostImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocVZipVosvratPostImpl::get_DocTIDMHRAN_REM_DVZVPOT(void)
{
return Object->DocTIDMHRAN_REM_DVZVPOT;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTIDMHRAN_REM_DVZVPOT(TFIBLargeIntField * DocTIDMHRAN_REM_DVZVPOT)
{
Object->DocTIDMHRAN_REM_DVZVPOT=DocTIDMHRAN_REM_DVZVPOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocVZipVosvratPostImpl::get_DocTNAME_SMHRAN(void)
{
return Object->DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN)
{
Object->DocTNAME_SMHRAN=DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
__int64 TREM_DMDocVZipVosvratPostImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocVZipVosvratPostImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocVZipVosvratPostImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVZipVosvratPostImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocVZipVosvratPostImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVZipVosvratPostImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocVZipVosvratPostImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocVZipVosvratPostImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocVZipVosvratPostImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
int TREM_DMDocVZipVosvratPostImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
