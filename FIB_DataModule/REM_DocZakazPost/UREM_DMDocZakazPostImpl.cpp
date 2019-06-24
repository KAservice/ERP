#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocZakazPostImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocZakazPostImpl::TREM_DMDocZakazPostImpl()           
{                                            
Object=new TREM_DMDocZakazPost(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocZakazPostImpl::~TREM_DMDocZakazPostImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocZakazPostImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocZakazPost)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocZakazPost*> (this);                                
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
int TREM_DMDocZakazPostImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocZakazPostImpl::kanRelease(void)                                  
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
int  TREM_DMDocZakazPostImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocZakazPostImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocZakazPostImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocZakazPostImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocZakazPostImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocZakazPost
TDataSource * TREM_DMDocZakazPostImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocZakazPostImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocZakazPostImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZakazPostImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZakazPostImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZakazPostImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZakazPostImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZakazPostImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocZakazPostImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocZakazPostImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZakazPostImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZakazPostImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocZakazPostImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZakazPostImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZakazPostImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZakazPostImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZakazPostImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZakazPostImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocID_REM_DZAKPOST(void)
{
return Object->DocID_REM_DZAKPOST;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocID_REM_DZAKPOST(TFIBLargeIntField * DocID_REM_DZAKPOST)
{
Object->DocID_REM_DZAKPOST=DocID_REM_DZAKPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocIDBASE_REM_DZAKPOST(void)
{
return Object->DocIDBASE_REM_DZAKPOST;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocIDBASE_REM_DZAKPOST(TFIBLargeIntField * DocIDBASE_REM_DZAKPOST)
{
Object->DocIDBASE_REM_DZAKPOST=DocIDBASE_REM_DZAKPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocIDDOC_REM_DZAKPOST(void)
{
return Object->DocIDDOC_REM_DZAKPOST;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocIDDOC_REM_DZAKPOST(TFIBLargeIntField * DocIDDOC_REM_DZAKPOST)
{
Object->DocIDDOC_REM_DZAKPOST=DocIDDOC_REM_DZAKPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocIDTPRICE_REM_DZAKPOST(void)
{
return Object->DocIDTPRICE_REM_DZAKPOST;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocIDTPRICE_REM_DZAKPOST(TFIBLargeIntField * DocIDTPRICE_REM_DZAKPOST)
{
Object->DocIDTPRICE_REM_DZAKPOST=DocIDTPRICE_REM_DZAKPOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocNUMZAKPOST_REM_DZAKPOST(void)
{
return Object->DocNUMZAKPOST_REM_DZAKPOST;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocNUMZAKPOST_REM_DZAKPOST(TFIBWideStringField * DocNUMZAKPOST_REM_DZAKPOST)
{
Object->DocNUMZAKPOST_REM_DZAKPOST=DocNUMZAKPOST_REM_DZAKPOST;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZakazPostImpl::get_DocPOSZAKPOST_REM_DZAKPOST(void)
{
return Object->DocPOSZAKPOST_REM_DZAKPOST;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocPOSZAKPOST_REM_DZAKPOST(TFIBDateTimeField * DocPOSZAKPOST_REM_DZAKPOST)
{
Object->DocPOSZAKPOST_REM_DZAKPOST=DocPOSZAKPOST_REM_DZAKPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocTID_REM_DZAKPOSTT(void)
{
return Object->DocTID_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTID_REM_DZAKPOSTT(TFIBLargeIntField * DocTID_REM_DZAKPOSTT)
{
Object->DocTID_REM_DZAKPOSTT=DocTID_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocTIDBASE_REM_DZAKPOSTT(void)
{
return Object->DocTIDBASE_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTIDBASE_REM_DZAKPOSTT(TFIBLargeIntField * DocTIDBASE_REM_DZAKPOSTT)
{
Object->DocTIDBASE_REM_DZAKPOSTT=DocTIDBASE_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocTIDDOC_REM_DZAKPOSTT(void)
{
return Object->DocTIDDOC_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTIDDOC_REM_DZAKPOSTT(TFIBLargeIntField * DocTIDDOC_REM_DZAKPOSTT)
{
Object->DocTIDDOC_REM_DZAKPOSTT=DocTIDDOC_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocTIDNOM_REM_DZAKPOSTT(void)
{
return Object->DocTIDNOM_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTIDNOM_REM_DZAKPOSTT(TFIBLargeIntField * DocTIDNOM_REM_DZAKPOSTT)
{
Object->DocTIDNOM_REM_DZAKPOSTT=DocTIDNOM_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocTIDED_REM_DZAKPOSTT(void)
{
return Object->DocTIDED_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTIDED_REM_DZAKPOSTT(TFIBLargeIntField * DocTIDED_REM_DZAKPOSTT)
{
Object->DocTIDED_REM_DZAKPOSTT=DocTIDED_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZakazPostImpl::get_DocTKOL_REM_DZAKPOSTT(void)
{
return Object->DocTKOL_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTKOL_REM_DZAKPOSTT(TFIBBCDField * DocTKOL_REM_DZAKPOSTT)
{
Object->DocTKOL_REM_DZAKPOSTT=DocTKOL_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZakazPostImpl::get_DocTKF_REM_DZAKPOSTT(void)
{
return Object->DocTKF_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTKF_REM_DZAKPOSTT(TFIBBCDField * DocTKF_REM_DZAKPOSTT)
{
Object->DocTKF_REM_DZAKPOSTT=DocTKF_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZakazPostImpl::get_DocTPRICE_REM_DZAKPOSTT(void)
{
return Object->DocTPRICE_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTPRICE_REM_DZAKPOSTT(TFIBBCDField * DocTPRICE_REM_DZAKPOSTT)
{
Object->DocTPRICE_REM_DZAKPOSTT=DocTPRICE_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocZakazPostImpl::get_DocTSUM_REM_DZAKPOSTT(void)
{
return Object->DocTSUM_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTSUM_REM_DZAKPOSTT(TFIBBCDField * DocTSUM_REM_DZAKPOSTT)
{
Object->DocTSUM_REM_DZAKPOSTT=DocTSUM_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZakazPostImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZakazPostImpl::get_DocTNUM_REM_CQUERY(void)
{
return Object->DocTNUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTNUM_REM_CQUERY(TFIBIntegerField * DocTNUM_REM_CQUERY)
{
Object->DocTNUM_REM_CQUERY=DocTNUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZakazPostImpl::get_DocTPOS_REM_CQUERY(void)
{
return Object->DocTPOS_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTPOS_REM_CQUERY(TFIBDateTimeField * DocTPOS_REM_CQUERY)
{
Object->DocTPOS_REM_CQUERY=DocTPOS_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTKLIENT_NAME_REM_CQUERY(void)
{
return Object->DocTKLIENT_NAME_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTKLIENT_NAME_REM_CQUERY(TFIBWideStringField * DocTKLIENT_NAME_REM_CQUERY)
{
Object->DocTKLIENT_NAME_REM_CQUERY=DocTKLIENT_NAME_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTPREFIKS_NUM_REM_Z(void)
{
return Object->DocTPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTPREFIKS_NUM_REM_Z(TFIBWideStringField * DocTPREFIKS_NUM_REM_Z)
{
Object->DocTPREFIKS_NUM_REM_Z=DocTPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocZakazPostImpl::get_DocTNUM_REM_Z(void)
{
return Object->DocTNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z)
{
Object->DocTNUM_REM_Z=DocTNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocZakazPostImpl::get_DocTPOS_REM_Z(void)
{
return Object->DocTPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z)
{
Object->DocTPOS_REM_Z=DocTPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTNAME_REM_SPRMODEL(void)
{
return Object->DocTNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTNAME_REM_SPRMODEL(TFIBWideStringField * DocTNAME_REM_SPRMODEL)
{
Object->DocTNAME_REM_SPRMODEL=DocTNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocZakazPostImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocIDBRAND_REM_DZAKPOST(void)
{
return Object->DocIDBRAND_REM_DZAKPOST;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocIDBRAND_REM_DZAKPOST(TFIBLargeIntField * DocIDBRAND_REM_DZAKPOST)
{
Object->DocIDBRAND_REM_DZAKPOST=DocIDBRAND_REM_DZAKPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocIDPRODUCER_REM_DZAKPOST(void)
{
return Object->DocIDPRODUCER_REM_DZAKPOST;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocIDPRODUCER_REM_DZAKPOST(TFIBLargeIntField * DocIDPRODUCER_REM_DZAKPOST)
{
Object->DocIDPRODUCER_REM_DZAKPOST=DocIDPRODUCER_REM_DZAKPOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocNAME_SBRAND(void)
{
return Object->DocNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocNAME_SBRAND(TFIBWideStringField * DocNAME_SBRAND)
{
Object->DocNAME_SBRAND=DocNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocNAME_SPRODUCER(void)
{
return Object->DocNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocNAME_SPRODUCER(TFIBWideStringField * DocNAME_SPRODUCER)
{
Object->DocNAME_SPRODUCER=DocNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocTIDPRNOM_REM_DZAKPOSTT(void)
{
return Object->DocTIDPRNOM_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTIDPRNOM_REM_DZAKPOSTT(TFIBLargeIntField * DocTIDPRNOM_REM_DZAKPOSTT)
{
Object->DocTIDPRNOM_REM_DZAKPOSTT=DocTIDPRNOM_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTART_SPRNOM(void)
{
return Object->DocTART_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTART_SPRNOM(TFIBWideStringField * DocTART_SPRNOM)
{
Object->DocTART_SPRNOM=DocTART_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTNAME_SPRNOM(void)
{
return Object->DocTNAME_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTNAME_SPRNOM(TFIBWideStringField * DocTNAME_SPRNOM)
{
Object->DocTNAME_SPRNOM=DocTNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZakazPostImpl::get_DocTFL_DOSTUPNO_SPRNOM(void)
{
return Object->DocTFL_DOSTUPNO_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTFL_DOSTUPNO_SPRNOM(TFIBSmallIntField * DocTFL_DOSTUPNO_SPRNOM)
{
Object->DocTFL_DOSTUPNO_SPRNOM=DocTFL_DOSTUPNO_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocTIDCQT_REM_DZAKPOSTT(void)
{
return Object->DocTIDCQT_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTIDCQT_REM_DZAKPOSTT(TFIBLargeIntField * DocTIDCQT_REM_DZAKPOSTT)
{
Object->DocTIDCQT_REM_DZAKPOSTT=DocTIDCQT_REM_DZAKPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocTID_REM_CQUERY(void)
{
return Object->DocTID_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTID_REM_CQUERY(TFIBLargeIntField * DocTID_REM_CQUERY)
{
Object->DocTID_REM_CQUERY=DocTID_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTNAME_REM_CQUERY(void)
{
return Object->DocTNAME_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTNAME_REM_CQUERY(TFIBWideStringField * DocTNAME_REM_CQUERY)
{
Object->DocTNAME_REM_CQUERY=DocTNAME_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTNAME_MODEL_REM_CQUERY(void)
{
return Object->DocTNAME_MODEL_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTNAME_MODEL_REM_CQUERY(TFIBWideStringField * DocTNAME_MODEL_REM_CQUERY)
{
Object->DocTNAME_MODEL_REM_CQUERY=DocTNAME_MODEL_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocZakazPostImpl::get_DocTID_REM_Z(void)
{
return Object->DocTID_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTID_REM_Z(TFIBLargeIntField * DocTID_REM_Z)
{
Object->DocTID_REM_Z=DocTID_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTNAME_REM_Z(void)
{
return Object->DocTNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z)
{
Object->DocTNAME_REM_Z=DocTNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTMODEL_REM_Z(void)
{
return Object->DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z)
{
Object->DocTMODEL_REM_Z=DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTSERNUM_REM_Z(void)
{
return Object->DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z)
{
Object->DocTSERNUM_REM_Z=DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTSERNUM2_REM_Z(void)
{
return Object->DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z)
{
Object->DocTSERNUM2_REM_Z=DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTNUM_STR_ZAK_POST_REM_CQUERY(void)
{
return Object->DocTNUM_STR_ZAK_POST_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTNUM_STR_ZAK_POST_REM_CQUERY(TFIBWideStringField * DocTNUM_STR_ZAK_POST_REM_CQUERY)
{
Object->DocTNUM_STR_ZAK_POST_REM_CQUERY=DocTNUM_STR_ZAK_POST_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTSTR_CODE_VIGR_REM_Z_1(void)
{
return Object->DocTSTR_CODE_VIGR_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTSTR_CODE_VIGR_REM_Z_1(TFIBWideStringField * DocTSTR_CODE_VIGR_REM_Z_1)
{
Object->DocTSTR_CODE_VIGR_REM_Z_1=DocTSTR_CODE_VIGR_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTMODEL_STR_SPRNOM(void)
{
return Object->DocTMODEL_STR_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTMODEL_STR_SPRNOM(TFIBWideStringField * DocTMODEL_STR_SPRNOM)
{
Object->DocTMODEL_STR_SPRNOM=DocTMODEL_STR_SPRNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocZakazPostImpl::get_DocTFL_ADD_IN_SOBORUD_SNOM(void)
{
return Object->DocTFL_ADD_IN_SOBORUD_SNOM;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTFL_ADD_IN_SOBORUD_SNOM(TFIBSmallIntField * DocTFL_ADD_IN_SOBORUD_SNOM)
{
Object->DocTFL_ADD_IN_SOBORUD_SNOM=DocTFL_ADD_IN_SOBORUD_SNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTART_REM_CQUERYT(void)
{
return Object->DocTART_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTART_REM_CQUERYT(TFIBWideStringField * DocTART_REM_CQUERYT)
{
Object->DocTART_REM_CQUERYT=DocTART_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocZakazPostImpl::get_DocTNAMENOM_REM_CQUERYT(void)
{
return Object->DocTNAMENOM_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_DocTNAMENOM_REM_CQUERYT(TFIBWideStringField * DocTNAMENOM_REM_CQUERYT)
{
Object->DocTNAMENOM_REM_CQUERYT=DocTNAMENOM_REM_CQUERYT;
}
//---------------------------------------------------------------
bool TREM_DMDocZakazPostImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMDocZakazPostImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_DMDocZakazPostImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_DMDocZakazPostImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
__int64 TREM_DMDocZakazPostImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
bool TREM_DMDocZakazPostImpl::get_IsmPrice(void)
{
return Object->IsmPrice;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_IsmPrice(bool IsmPrice)
{
Object->IsmPrice=IsmPrice;
}
//---------------------------------------------------------------
bool TREM_DMDocZakazPostImpl::get_IsmSum(void)
{
return Object->IsmSum;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_IsmSum(bool IsmSum)
{
Object->IsmSum=IsmSum;
}
//---------------------------------------------------------------
bool TREM_DMDocZakazPostImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocZakazPostImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TREM_DMDocZakazPostImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZakazPostImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocZakazPostImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZakazPostImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocZakazPostImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZakazPostImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocZakazPostImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
bool TREM_DMDocZakazPostImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
__int64 TREM_DMDocZakazPostImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc,date_doc);
}
//---------------------------------------------------------------
int TREM_DMDocZakazPostImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
