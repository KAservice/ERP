#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocRegOtchetPostImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocRegOtchetPostImpl::TREM_DMDocRegOtchetPostImpl()           
{                                            
Object=new TREM_DMDocRegOtchetPost(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocRegOtchetPostImpl::~TREM_DMDocRegOtchetPostImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocRegOtchetPostImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocRegOtchetPost)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocRegOtchetPost*> (this);                                
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
int TREM_DMDocRegOtchetPostImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocRegOtchetPostImpl::kanRelease(void)                                  
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
int  TREM_DMDocRegOtchetPostImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocRegOtchetPostImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocRegOtchetPostImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocRegOtchetPostImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocRegOtchetPostImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocRegOtchetPost
TDataSource * TREM_DMDocRegOtchetPostImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocRegOtchetPostImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocRegOtchetPostImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRegOtchetPostImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRegOtchetPostImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRegOtchetPostImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRegOtchetPostImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRegOtchetPostImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRegOtchetPostImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRegOtchetPostImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRegOtchetPostImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRegOtchetPostImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRegOtchetPostImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocRegOtchetPostImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocRegOtchetPostImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRegOtchetPostImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRegOtchetPostImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRegOtchetPostImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRegOtchetPostImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocID_REM_DRG_OTCHPOST(void)
{
return Object->DocID_REM_DRG_OTCHPOST;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocID_REM_DRG_OTCHPOST(TFIBLargeIntField * DocID_REM_DRG_OTCHPOST)
{
Object->DocID_REM_DRG_OTCHPOST=DocID_REM_DRG_OTCHPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocIDBASE_REM_DRG_OTCHPOST(void)
{
return Object->DocIDBASE_REM_DRG_OTCHPOST;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocIDBASE_REM_DRG_OTCHPOST(TFIBLargeIntField * DocIDBASE_REM_DRG_OTCHPOST)
{
Object->DocIDBASE_REM_DRG_OTCHPOST=DocIDBASE_REM_DRG_OTCHPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocIDDOC_REM_DRG_OTCHPOST(void)
{
return Object->DocIDDOC_REM_DRG_OTCHPOST;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocIDDOC_REM_DRG_OTCHPOST(TFIBLargeIntField * DocIDDOC_REM_DRG_OTCHPOST)
{
Object->DocIDDOC_REM_DRG_OTCHPOST=DocIDDOC_REM_DRG_OTCHPOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocDESCR_REM_DRG_OTCHPOST(void)
{
return Object->DocDESCR_REM_DRG_OTCHPOST;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocDESCR_REM_DRG_OTCHPOST(TFIBWideStringField * DocDESCR_REM_DRG_OTCHPOST)
{
Object->DocDESCR_REM_DRG_OTCHPOST=DocDESCR_REM_DRG_OTCHPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocTID_REM_DRG_OTCHPOSTT(void)
{
return Object->DocTID_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTID_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTID_REM_DRG_OTCHPOSTT)
{
Object->DocTID_REM_DRG_OTCHPOSTT=DocTID_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocTIDBASE_REM_DRG_OTCHPOSTT(void)
{
return Object->DocTIDBASE_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTIDBASE_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDBASE_REM_DRG_OTCHPOSTT)
{
Object->DocTIDBASE_REM_DRG_OTCHPOSTT=DocTIDBASE_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocTIDDOC_REM_DRG_OTCHPOSTT(void)
{
return Object->DocTIDDOC_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTIDDOC_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDDOC_REM_DRG_OTCHPOSTT)
{
Object->DocTIDDOC_REM_DRG_OTCHPOSTT=DocTIDDOC_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRegOtchetPostImpl::get_DocTTDV_REM_DRG_OTCHPOSTT(void)
{
return Object->DocTTDV_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTTDV_REM_DRG_OTCHPOSTT(TFIBSmallIntField * DocTTDV_REM_DRG_OTCHPOSTT)
{
Object->DocTTDV_REM_DRG_OTCHPOSTT=DocTTDV_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocTIDFIRM_REM_DRG_OTCHPOSTT(void)
{
return Object->DocTIDFIRM_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTIDFIRM_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDFIRM_REM_DRG_OTCHPOSTT)
{
Object->DocTIDFIRM_REM_DRG_OTCHPOSTT=DocTIDFIRM_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocTIDSKLAD_REM_DRG_OTCHPOSTT(void)
{
return Object->DocTIDSKLAD_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTIDSKLAD_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDSKLAD_REM_DRG_OTCHPOSTT)
{
Object->DocTIDSKLAD_REM_DRG_OTCHPOSTT=DocTIDSKLAD_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocTIDPOST_REM_DRG_OTCHPOSTT(void)
{
return Object->DocTIDPOST_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTIDPOST_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDPOST_REM_DRG_OTCHPOSTT)
{
Object->DocTIDPOST_REM_DRG_OTCHPOSTT=DocTIDPOST_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocTIDDOCPOST_REM_DRG_OTCHPOSTT(void)
{
return Object->DocTIDDOCPOST_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTIDDOCPOST_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDDOCPOST_REM_DRG_OTCHPOSTT)
{
Object->DocTIDDOCPOST_REM_DRG_OTCHPOSTT=DocTIDDOCPOST_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRegOtchetPostImpl::get_DocTIDNOM_REM_DRG_OTCHPOSTT(void)
{
return Object->DocTIDNOM_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTIDNOM_REM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDNOM_REM_DRG_OTCHPOSTT)
{
Object->DocTIDNOM_REM_DRG_OTCHPOSTT=DocTIDNOM_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRegOtchetPostImpl::get_DocTKOL_REM_DRG_OTCHPOSTT(void)
{
return Object->DocTKOL_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTKOL_REM_DRG_OTCHPOSTT(TFIBBCDField * DocTKOL_REM_DRG_OTCHPOSTT)
{
Object->DocTKOL_REM_DRG_OTCHPOSTT=DocTKOL_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRegOtchetPostImpl::get_DocTSUM_REM_DRG_OTCHPOSTT(void)
{
return Object->DocTSUM_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTSUM_REM_DRG_OTCHPOSTT(TFIBBCDField * DocTSUM_REM_DRG_OTCHPOSTT)
{
Object->DocTSUM_REM_DRG_OTCHPOSTT=DocTSUM_REM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocTNAMEFIRM(void)
{
return Object->DocTNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM)
{
Object->DocTNAMEFIRM=DocTNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocTNAMESKLAD(void)
{
return Object->DocTNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTNAMESKLAD(TFIBWideStringField * DocTNAMESKLAD)
{
Object->DocTNAMESKLAD=DocTNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRegOtchetPostImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocTPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocTPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocTPREFIKS_NUM_REM_GALLDOC)
{
Object->DocTPREFIKS_NUM_REM_GALLDOC=DocTPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRegOtchetPostImpl::get_DocTNUM_REM_GALLDOC(void)
{
return Object->DocTNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTNUM_REM_GALLDOC(TFIBIntegerField * DocTNUM_REM_GALLDOC)
{
Object->DocTNUM_REM_GALLDOC=DocTNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocRegOtchetPostImpl::get_DocTPOS_REM_GALLDOC(void)
{
return Object->DocTPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTPOS_REM_GALLDOC(TFIBDateTimeField * DocTPOS_REM_GALLDOC)
{
Object->DocTPOS_REM_GALLDOC=DocTPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRegOtchetPostImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
__int64 TREM_DMDocRegOtchetPostImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocRegOtchetPostImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocRegOtchetPostImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TREM_DMDocRegOtchetPostImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRegOtchetPostImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TREM_DMDocRegOtchetPostImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRegOtchetPostImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocRegOtchetPostImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRegOtchetPostImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocRegOtchetPostImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
int TREM_DMDocRegOtchetPostImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
