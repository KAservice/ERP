#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocOstNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocOstNomImpl::TREM_DMDocOstNomImpl()           
{                                            
Object=new TREM_DMDocOstNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocOstNomImpl::~TREM_DMDocOstNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocOstNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocOstNom)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocOstNom*> (this);                                
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
int TREM_DMDocOstNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocOstNomImpl::kanRelease(void)                                  
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
int  TREM_DMDocOstNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocOstNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocOstNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocOstNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocOstNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocOstNom
TDataSource * TREM_DMDocOstNomImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocOstNomImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocOstNomImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocOstNomImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocOstNomImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocOstNomImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocOstNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocOstNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocOstNomImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocOstNomImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocOstNomImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocOstNomImpl::get_DocOsn(void)
{
return Object->DocOsn;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocOsn(TpFIBDataSet * DocOsn)
{
Object->DocOsn=DocOsn;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocOstNomImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocOstNomImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocOstNomImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocOstNomImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocOstNomImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocOstNomImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOstNomImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocID_REM_DOSN(void)
{
return Object->DocID_REM_DOSN;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocID_REM_DOSN(TFIBLargeIntField * DocID_REM_DOSN)
{
Object->DocID_REM_DOSN=DocID_REM_DOSN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocIDBASE_REM_DOSN(void)
{
return Object->DocIDBASE_REM_DOSN;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocIDBASE_REM_DOSN(TFIBLargeIntField * DocIDBASE_REM_DOSN)
{
Object->DocIDBASE_REM_DOSN=DocIDBASE_REM_DOSN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocIDDOC_REM_DOSN(void)
{
return Object->DocIDDOC_REM_DOSN;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocIDDOC_REM_DOSN(TFIBLargeIntField * DocIDDOC_REM_DOSN)
{
Object->DocIDDOC_REM_DOSN=DocIDDOC_REM_DOSN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocGID_REM_DOSN(void)
{
return Object->DocGID_REM_DOSN;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocGID_REM_DOSN(TFIBWideStringField * DocGID_REM_DOSN)
{
Object->DocGID_REM_DOSN=DocGID_REM_DOSN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocIDTPRICE_REM_DOSN(void)
{
return Object->DocIDTPRICE_REM_DOSN;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocIDTPRICE_REM_DOSN(TFIBLargeIntField * DocIDTPRICE_REM_DOSN)
{
Object->DocIDTPRICE_REM_DOSN=DocIDTPRICE_REM_DOSN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocIDRTPRICE_REM_DOSN(void)
{
return Object->DocIDRTPRICE_REM_DOSN;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocIDRTPRICE_REM_DOSN(TFIBLargeIntField * DocIDRTPRICE_REM_DOSN)
{
Object->DocIDRTPRICE_REM_DOSN=DocIDRTPRICE_REM_DOSN;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOstNomImpl::get_DocRSUM_REM_DOSN(void)
{
return Object->DocRSUM_REM_DOSN;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocRSUM_REM_DOSN(TFIBBCDField * DocRSUM_REM_DOSN)
{
Object->DocRSUM_REM_DOSN=DocRSUM_REM_DOSN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocPRIM_REM_DOSN(void)
{
return Object->DocPRIM_REM_DOSN;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocPRIM_REM_DOSN(TFIBWideStringField * DocPRIM_REM_DOSN)
{
Object->DocPRIM_REM_DOSN=DocPRIM_REM_DOSN;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocOstNomImpl::get_DataSourceDocOsn(void)
{
return Object->DataSourceDocOsn;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DataSourceDocOsn(TDataSource * DataSourceDocOsn)
{
Object->DataSourceDocOsn=DataSourceDocOsn;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocTID_REM_DOSNT(void)
{
return Object->DocTID_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTID_REM_DOSNT(TFIBLargeIntField * DocTID_REM_DOSNT)
{
Object->DocTID_REM_DOSNT=DocTID_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocTIDBASE_REM_DOSNT(void)
{
return Object->DocTIDBASE_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTIDBASE_REM_DOSNT(TFIBLargeIntField * DocTIDBASE_REM_DOSNT)
{
Object->DocTIDBASE_REM_DOSNT=DocTIDBASE_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocTIDDOC_REM_DOSNT(void)
{
return Object->DocTIDDOC_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTIDDOC_REM_DOSNT(TFIBLargeIntField * DocTIDDOC_REM_DOSNT)
{
Object->DocTIDDOC_REM_DOSNT=DocTIDDOC_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocTGID_REM_DOSNT(void)
{
return Object->DocTGID_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTGID_REM_DOSNT(TFIBWideStringField * DocTGID_REM_DOSNT)
{
Object->DocTGID_REM_DOSNT=DocTGID_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocTIDNOM_REM_DOSNT(void)
{
return Object->DocTIDNOM_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTIDNOM_REM_DOSNT(TFIBLargeIntField * DocTIDNOM_REM_DOSNT)
{
Object->DocTIDNOM_REM_DOSNT=DocTIDNOM_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocTIDED_REM_DOSNT(void)
{
return Object->DocTIDED_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTIDED_REM_DOSNT(TFIBLargeIntField * DocTIDED_REM_DOSNT)
{
Object->DocTIDED_REM_DOSNT=DocTIDED_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocTIDHW_REM_DOSNT(void)
{
return Object->DocTIDHW_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTIDHW_REM_DOSNT(TFIBLargeIntField * DocTIDHW_REM_DOSNT)
{
Object->DocTIDHW_REM_DOSNT=DocTIDHW_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOstNomImpl::get_DocTKOL_REM_DOSNT(void)
{
return Object->DocTKOL_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTKOL_REM_DOSNT(TFIBBCDField * DocTKOL_REM_DOSNT)
{
Object->DocTKOL_REM_DOSNT=DocTKOL_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOstNomImpl::get_DocTKF_REM_DOSNT(void)
{
return Object->DocTKF_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTKF_REM_DOSNT(TFIBBCDField * DocTKF_REM_DOSNT)
{
Object->DocTKF_REM_DOSNT=DocTKF_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOstNomImpl::get_DocTPRICE_REM_DOSNT(void)
{
return Object->DocTPRICE_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTPRICE_REM_DOSNT(TFIBBCDField * DocTPRICE_REM_DOSNT)
{
Object->DocTPRICE_REM_DOSNT=DocTPRICE_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOstNomImpl::get_DocTSUM_REM_DOSNT(void)
{
return Object->DocTSUM_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTSUM_REM_DOSNT(TFIBBCDField * DocTSUM_REM_DOSNT)
{
Object->DocTSUM_REM_DOSNT=DocTSUM_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOstNomImpl::get_DocTRPRICE_REM_DOSNT(void)
{
return Object->DocTRPRICE_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTRPRICE_REM_DOSNT(TFIBBCDField * DocTRPRICE_REM_DOSNT)
{
Object->DocTRPRICE_REM_DOSNT=DocTRPRICE_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOstNomImpl::get_DocTRSUM_REM_DOSNT(void)
{
return Object->DocTRSUM_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTRSUM_REM_DOSNT(TFIBBCDField * DocTRSUM_REM_DOSNT)
{
Object->DocTRSUM_REM_DOSNT=DocTRSUM_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocOstNomImpl::get_DocTNDS_REM_DOSNT(void)
{
return Object->DocTNDS_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTNDS_REM_DOSNT(TFIBIntegerField * DocTNDS_REM_DOSNT)
{
Object->DocTNDS_REM_DOSNT=DocTNDS_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocOstNomImpl::get_DocTSUMNDS_REM_DOSNT(void)
{
return Object->DocTSUMNDS_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTSUMNDS_REM_DOSNT(TFIBBCDField * DocTSUMNDS_REM_DOSNT)
{
Object->DocTSUMNDS_REM_DOSNT=DocTSUMNDS_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocOstNomImpl::get_DocTDVREG_REM_DOSNT(void)
{
return Object->DocTDVREG_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTDVREG_REM_DOSNT(TFIBSmallIntField * DocTDVREG_REM_DOSNT)
{
Object->DocTDVREG_REM_DOSNT=DocTDVREG_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocOstNomImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocOstNomImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocOsnTDOC_REM_GALLDOC(void)
{
return Object->DocOsnTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocOsnTDOC_REM_GALLDOC(TFIBWideStringField * DocOsnTDOC_REM_GALLDOC)
{
Object->DocOsnTDOC_REM_GALLDOC=DocOsnTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocOstNomImpl::get_DocOsnNUM_REM_GALLDOC(void)
{
return Object->DocOsnNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocOsnNUM_REM_GALLDOC(TFIBIntegerField * DocOsnNUM_REM_GALLDOC)
{
Object->DocOsnNUM_REM_GALLDOC=DocOsnNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocOstNomImpl::get_DocOsnPOS_REM_GALLDOC(void)
{
return Object->DocOsnPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocOsnPOS_REM_GALLDOC(TFIBDateTimeField * DocOsnPOS_REM_GALLDOC)
{
Object->DocOsnPOS_REM_GALLDOC=DocOsnPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocOstNomImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocAllIDOBJECT_REM_GALLDOC(void)
{
return Object->DocAllIDOBJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllIDOBJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_REM_GALLDOC)
{
Object->DocAllIDOBJECT_REM_GALLDOC=DocAllIDOBJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocAllNAME_SOBJECT(void)
{
return Object->DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT)
{
Object->DocAllNAME_SOBJECT=DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocOstNomImpl::get_TypeNom(void)
{
return Object->TypeNom;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_TypeNom(TpFIBDataSet * TypeNom)
{
Object->TypeNom=TypeNom;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_TypeNomID_STNOM(void)
{
return Object->TypeNomID_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_TypeNomID_STNOM(TFIBLargeIntField * TypeNomID_STNOM)
{
Object->TypeNomID_STNOM=TypeNomID_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_TypeNomNAME_STNOM(void)
{
return Object->TypeNomNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_TypeNomNAME_STNOM(TFIBWideStringField * TypeNomNAME_STNOM)
{
Object->TypeNomNAME_STNOM=TypeNomNAME_STNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocTIDTNOM_REM_DOSNT(void)
{
return Object->DocTIDTNOM_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTIDTNOM_REM_DOSNT(TFIBLargeIntField * DocTIDTNOM_REM_DOSNT)
{
Object->DocTIDTNOM_REM_DOSNT=DocTIDTNOM_REM_DOSNT;
}
//---------------------------------------------------------------
TStringField * TREM_DMDocOstNomImpl::get_DocTNAME_TYPE_NOM_LOOCUP(void)
{
return Object->DocTNAME_TYPE_NOM_LOOCUP;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTNAME_TYPE_NOM_LOOCUP(TStringField * DocTNAME_TYPE_NOM_LOOCUP)
{
Object->DocTNAME_TYPE_NOM_LOOCUP=DocTNAME_TYPE_NOM_LOOCUP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocOstNomImpl::get_DocTIDMHRAN_REM_DOSNT(void)
{
return Object->DocTIDMHRAN_REM_DOSNT;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTIDMHRAN_REM_DOSNT(TFIBLargeIntField * DocTIDMHRAN_REM_DOSNT)
{
Object->DocTIDMHRAN_REM_DOSNT=DocTIDMHRAN_REM_DOSNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocOstNomImpl::get_DocTNAME_SMHRAN(void)
{
return Object->DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN)
{
Object->DocTNAME_SMHRAN=DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
bool TREM_DMDocOstNomImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TREM_DMDocOstNomImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMDocOstNomImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_DMDocOstNomImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_DMDocOstNomImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::OpenDoc(__int64 id_doc)
{
return Object->OpenDoc(id_doc);
}
//---------------------------------------------------------------
bool TREM_DMDocOstNomImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocOstNomImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocOstNomImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TREM_DMDocOstNomImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocOstNomImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
