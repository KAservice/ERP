#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocOtprPostImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocOtprPostImpl::TREM_DMDocOtprPostImpl()           
{                                            
Object=new TREM_DMDocOtprPost(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocOtprPostImpl::~TREM_DMDocOtprPostImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocOtprPostImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocOtprPost)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocOtprPost*> (this);                                
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
int TREM_DMDocOtprPostImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocOtprPostImpl::kanRelease(void)                                  
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
int  TREM_DMDocOtprPostImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocOtprPostImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocOtprPostImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocOtprPostImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocOtprPostImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocOtprPost
TDataSource * TREM_DMDocOtprPostImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocOtprPostImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocOtprPostImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocOtprPostImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocOtprPostImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocOtprPostImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocOtprPostImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocOtprPostImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocOtprPostImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocOtprPostImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocOtprPostImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocOtprPostImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocOtprPostImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocOtprPostImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocOtprPostImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocOtprPostImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocOtprPostImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOtprPostImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocID_REM_DOTPRPOST(void)
{
return Object->DocID_REM_DOTPRPOST;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocID_REM_DOTPRPOST(TFIBLargeIntField * DocID_REM_DOTPRPOST)
{
Object->DocID_REM_DOTPRPOST=DocID_REM_DOTPRPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocIDBASE_REM_DOTPRPOST(void)
{
return Object->DocIDBASE_REM_DOTPRPOST;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocIDBASE_REM_DOTPRPOST(TFIBLargeIntField * DocIDBASE_REM_DOTPRPOST)
{
Object->DocIDBASE_REM_DOTPRPOST=DocIDBASE_REM_DOTPRPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocIDDOC_REM_DOTPRPOST(void)
{
return Object->DocIDDOC_REM_DOTPRPOST;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocIDDOC_REM_DOTPRPOST(TFIBLargeIntField * DocIDDOC_REM_DOTPRPOST)
{
Object->DocIDDOC_REM_DOTPRPOST=DocIDDOC_REM_DOTPRPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocIDTPRICE_REM_DOTPRPOST(void)
{
return Object->DocIDTPRICE_REM_DOTPRPOST;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocIDTPRICE_REM_DOTPRPOST(TFIBLargeIntField * DocIDTPRICE_REM_DOTPRPOST)
{
Object->DocIDTPRICE_REM_DOTPRPOST=DocIDTPRICE_REM_DOTPRPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocIDBRAND_REM_DOTPRPOST(void)
{
return Object->DocIDBRAND_REM_DOTPRPOST;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocIDBRAND_REM_DOTPRPOST(TFIBLargeIntField * DocIDBRAND_REM_DOTPRPOST)
{
Object->DocIDBRAND_REM_DOTPRPOST=DocIDBRAND_REM_DOTPRPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocIDPRODUCER_REM_DOTPRPOST(void)
{
return Object->DocIDPRODUCER_REM_DOTPRPOST;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocIDPRODUCER_REM_DOTPRPOST(TFIBLargeIntField * DocIDPRODUCER_REM_DOTPRPOST)
{
Object->DocIDPRODUCER_REM_DOTPRPOST=DocIDPRODUCER_REM_DOTPRPOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTK_REM_DOTPRPOST(void)
{
return Object->DocTK_REM_DOTPRPOST;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTK_REM_DOTPRPOST(TFIBWideStringField * DocTK_REM_DOTPRPOST)
{
Object->DocTK_REM_DOTPRPOST=DocTK_REM_DOTPRPOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocNUMDOCTK_REM_DOTPRPOST(void)
{
return Object->DocNUMDOCTK_REM_DOTPRPOST;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocNUMDOCTK_REM_DOTPRPOST(TFIBWideStringField * DocNUMDOCTK_REM_DOTPRPOST)
{
Object->DocNUMDOCTK_REM_DOTPRPOST=DocNUMDOCTK_REM_DOTPRPOST;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMDocOtprPostImpl::get_DocPLANDOSTAVKI_REM_DOTPRPOST(void)
{
return Object->DocPLANDOSTAVKI_REM_DOTPRPOST;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocPLANDOSTAVKI_REM_DOTPRPOST(TFIBDateField * DocPLANDOSTAVKI_REM_DOTPRPOST)
{
Object->DocPLANDOSTAVKI_REM_DOTPRPOST=DocPLANDOSTAVKI_REM_DOTPRPOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocNAME_SBRAND(void)
{
return Object->DocNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocNAME_SBRAND(TFIBWideStringField * DocNAME_SBRAND)
{
Object->DocNAME_SBRAND=DocNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocNAME_SPRODUCER(void)
{
return Object->DocNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocNAME_SPRODUCER(TFIBWideStringField * DocNAME_SPRODUCER)
{
Object->DocNAME_SPRODUCER=DocNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocTID_REM_DOTPRPOSTT(void)
{
return Object->DocTID_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTID_REM_DOTPRPOSTT(TFIBLargeIntField * DocTID_REM_DOTPRPOSTT)
{
Object->DocTID_REM_DOTPRPOSTT=DocTID_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocTIDBASE_REM_DOTPRPOSTT(void)
{
return Object->DocTIDBASE_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTIDBASE_REM_DOTPRPOSTT(TFIBLargeIntField * DocTIDBASE_REM_DOTPRPOSTT)
{
Object->DocTIDBASE_REM_DOTPRPOSTT=DocTIDBASE_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocTIDDOC_REM_DOTPRPOSTT(void)
{
return Object->DocTIDDOC_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTIDDOC_REM_DOTPRPOSTT(TFIBLargeIntField * DocTIDDOC_REM_DOTPRPOSTT)
{
Object->DocTIDDOC_REM_DOTPRPOSTT=DocTIDDOC_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocTIDNOM_REM_DOTPRPOSTT(void)
{
return Object->DocTIDNOM_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTIDNOM_REM_DOTPRPOSTT(TFIBLargeIntField * DocTIDNOM_REM_DOTPRPOSTT)
{
Object->DocTIDNOM_REM_DOTPRPOSTT=DocTIDNOM_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocTIDED_REM_DOTPRPOSTT(void)
{
return Object->DocTIDED_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTIDED_REM_DOTPRPOSTT(TFIBLargeIntField * DocTIDED_REM_DOTPRPOSTT)
{
Object->DocTIDED_REM_DOTPRPOSTT=DocTIDED_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOtprPostImpl::get_DocTKOL_REM_DOTPRPOSTT(void)
{
return Object->DocTKOL_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTKOL_REM_DOTPRPOSTT(TFIBBCDField * DocTKOL_REM_DOTPRPOSTT)
{
Object->DocTKOL_REM_DOTPRPOSTT=DocTKOL_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOtprPostImpl::get_DocTKF_REM_DOTPRPOSTT(void)
{
return Object->DocTKF_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTKF_REM_DOTPRPOSTT(TFIBBCDField * DocTKF_REM_DOTPRPOSTT)
{
Object->DocTKF_REM_DOTPRPOSTT=DocTKF_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOtprPostImpl::get_DocTPRICE_REM_DOTPRPOSTT(void)
{
return Object->DocTPRICE_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTPRICE_REM_DOTPRPOSTT(TFIBBCDField * DocTPRICE_REM_DOTPRPOSTT)
{
Object->DocTPRICE_REM_DOTPRPOSTT=DocTPRICE_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOtprPostImpl::get_DocTSUM_REM_DOTPRPOSTT(void)
{
return Object->DocTSUM_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTSUM_REM_DOTPRPOSTT(TFIBBCDField * DocTSUM_REM_DOTPRPOSTT)
{
Object->DocTSUM_REM_DOTPRPOSTT=DocTSUM_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocTIDCQT_REM_DOTPRPOSTT(void)
{
return Object->DocTIDCQT_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTIDCQT_REM_DOTPRPOSTT(TFIBLargeIntField * DocTIDCQT_REM_DOTPRPOSTT)
{
Object->DocTIDCQT_REM_DOTPRPOSTT=DocTIDCQT_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocTIDPRNOM_REM_DOTPRPOSTT(void)
{
return Object->DocTIDPRNOM_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTIDPRNOM_REM_DOTPRPOSTT(TFIBLargeIntField * DocTIDPRNOM_REM_DOTPRPOSTT)
{
Object->DocTIDPRNOM_REM_DOTPRPOSTT=DocTIDPRNOM_REM_DOTPRPOSTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocOtprPostImpl::get_DocTFL_ADD_IN_SOBORUD_SNOM(void)
{
return Object->DocTFL_ADD_IN_SOBORUD_SNOM;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTFL_ADD_IN_SOBORUD_SNOM(TFIBSmallIntField * DocTFL_ADD_IN_SOBORUD_SNOM)
{
Object->DocTFL_ADD_IN_SOBORUD_SNOM=DocTFL_ADD_IN_SOBORUD_SNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocOtprPostImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocTID_REM_CQUERY(void)
{
return Object->DocTID_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTID_REM_CQUERY(TFIBLargeIntField * DocTID_REM_CQUERY)
{
Object->DocTID_REM_CQUERY=DocTID_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTNAME_REM_CQUERY(void)
{
return Object->DocTNAME_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTNAME_REM_CQUERY(TFIBWideStringField * DocTNAME_REM_CQUERY)
{
Object->DocTNAME_REM_CQUERY=DocTNAME_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocOtprPostImpl::get_DocTNUM_REM_CQUERY(void)
{
return Object->DocTNUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTNUM_REM_CQUERY(TFIBIntegerField * DocTNUM_REM_CQUERY)
{
Object->DocTNUM_REM_CQUERY=DocTNUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocOtprPostImpl::get_DocTPOS_REM_CQUERY(void)
{
return Object->DocTPOS_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTPOS_REM_CQUERY(TFIBDateTimeField * DocTPOS_REM_CQUERY)
{
Object->DocTPOS_REM_CQUERY=DocTPOS_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTKLIENT_NAME_REM_CQUERY(void)
{
return Object->DocTKLIENT_NAME_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTKLIENT_NAME_REM_CQUERY(TFIBWideStringField * DocTKLIENT_NAME_REM_CQUERY)
{
Object->DocTKLIENT_NAME_REM_CQUERY=DocTKLIENT_NAME_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTNAME_MODEL_REM_CQUERY(void)
{
return Object->DocTNAME_MODEL_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTNAME_MODEL_REM_CQUERY(TFIBWideStringField * DocTNAME_MODEL_REM_CQUERY)
{
Object->DocTNAME_MODEL_REM_CQUERY=DocTNAME_MODEL_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTNUM_STR_ZAK_POST_REM_CQUERY(void)
{
return Object->DocTNUM_STR_ZAK_POST_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTNUM_STR_ZAK_POST_REM_CQUERY(TFIBWideStringField * DocTNUM_STR_ZAK_POST_REM_CQUERY)
{
Object->DocTNUM_STR_ZAK_POST_REM_CQUERY=DocTNUM_STR_ZAK_POST_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOtprPostImpl::get_DocTID_REM_Z(void)
{
return Object->DocTID_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTID_REM_Z(TFIBLargeIntField * DocTID_REM_Z)
{
Object->DocTID_REM_Z=DocTID_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTNAME_REM_Z(void)
{
return Object->DocTNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z)
{
Object->DocTNAME_REM_Z=DocTNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTPREFIKS_NUM_REM_Z(void)
{
return Object->DocTPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTPREFIKS_NUM_REM_Z(TFIBWideStringField * DocTPREFIKS_NUM_REM_Z)
{
Object->DocTPREFIKS_NUM_REM_Z=DocTPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocOtprPostImpl::get_DocTNUM_REM_Z(void)
{
return Object->DocTNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z)
{
Object->DocTNUM_REM_Z=DocTNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocOtprPostImpl::get_DocTPOS_REM_Z(void)
{
return Object->DocTPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z)
{
Object->DocTPOS_REM_Z=DocTPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTMODEL_REM_Z(void)
{
return Object->DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z)
{
Object->DocTMODEL_REM_Z=DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTSERNUM_REM_Z(void)
{
return Object->DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z)
{
Object->DocTSERNUM_REM_Z=DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTSERNUM2_REM_Z(void)
{
return Object->DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z)
{
Object->DocTSERNUM2_REM_Z=DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTSTR_CODE_VIGR_REM_Z_1(void)
{
return Object->DocTSTR_CODE_VIGR_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTSTR_CODE_VIGR_REM_Z_1(TFIBWideStringField * DocTSTR_CODE_VIGR_REM_Z_1)
{
Object->DocTSTR_CODE_VIGR_REM_Z_1=DocTSTR_CODE_VIGR_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTNAME_REM_SPRMODEL(void)
{
return Object->DocTNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTNAME_REM_SPRMODEL(TFIBWideStringField * DocTNAME_REM_SPRMODEL)
{
Object->DocTNAME_REM_SPRMODEL=DocTNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTART_SPRNOM(void)
{
return Object->DocTART_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTART_SPRNOM(TFIBWideStringField * DocTART_SPRNOM)
{
Object->DocTART_SPRNOM=DocTART_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTNAME_SPRNOM(void)
{
return Object->DocTNAME_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTNAME_SPRNOM(TFIBWideStringField * DocTNAME_SPRNOM)
{
Object->DocTNAME_SPRNOM=DocTNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocOtprPostImpl::get_DocTFL_DOSTUPNO_SPRNOM(void)
{
return Object->DocTFL_DOSTUPNO_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTFL_DOSTUPNO_SPRNOM(TFIBSmallIntField * DocTFL_DOSTUPNO_SPRNOM)
{
Object->DocTFL_DOSTUPNO_SPRNOM=DocTFL_DOSTUPNO_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTMODEL_STR_SPRNOM(void)
{
return Object->DocTMODEL_STR_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTMODEL_STR_SPRNOM(TFIBWideStringField * DocTMODEL_STR_SPRNOM)
{
Object->DocTMODEL_STR_SPRNOM=DocTMODEL_STR_SPRNOM;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocOtprPostImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTART_REM_CQUERYT(void)
{
return Object->DocTART_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTART_REM_CQUERYT(TFIBWideStringField * DocTART_REM_CQUERYT)
{
Object->DocTART_REM_CQUERYT=DocTART_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOtprPostImpl::get_DocTNAMENOM_REM_CQUERYT(void)
{
return Object->DocTNAMENOM_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_DocTNAMENOM_REM_CQUERYT(TFIBWideStringField * DocTNAMENOM_REM_CQUERYT)
{
Object->DocTNAMENOM_REM_CQUERYT=DocTNAMENOM_REM_CQUERYT;
}
//---------------------------------------------------------------
bool TREM_DMDocOtprPostImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMDocOtprPostImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_DMDocOtprPostImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_DMDocOtprPostImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
__int64 TREM_DMDocOtprPostImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
bool TREM_DMDocOtprPostImpl::get_IsmPrice(void)
{
return Object->IsmPrice;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_IsmPrice(bool IsmPrice)
{
Object->IsmPrice=IsmPrice;
}
//---------------------------------------------------------------
bool TREM_DMDocOtprPostImpl::get_IsmSum(void)
{
return Object->IsmSum;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_IsmSum(bool IsmSum)
{
Object->IsmSum=IsmSum;
}
//---------------------------------------------------------------
bool TREM_DMDocOtprPostImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocOtprPostImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TREM_DMDocOtprPostImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocOtprPostImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocOtprPostImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocOtprPostImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocOtprPostImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocOtprPostImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocOtprPostImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
bool TREM_DMDocOtprPostImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
__int64 TREM_DMDocOtprPostImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc, date_doc);
}
//---------------------------------------------------------------
int TREM_DMDocOtprPostImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
