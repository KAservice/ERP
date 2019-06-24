#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocSborkaKomplImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocSborkaKomplImpl::TREM_DMDocSborkaKomplImpl()           
{                                            
Object=new TREM_DMDocSborkaKompl(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocSborkaKomplImpl::~TREM_DMDocSborkaKomplImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocSborkaKomplImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocSborkaKompl)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocSborkaKompl*> (this);                                
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
int TREM_DMDocSborkaKomplImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocSborkaKomplImpl::kanRelease(void)                                  
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
int  TREM_DMDocSborkaKomplImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocSborkaKomplImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocSborkaKomplImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocSborkaKomplImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocSborkaKomplImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocSborkaKompl
TDataSource * TREM_DMDocSborkaKomplImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocSborkaKomplImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocSborkaKomplImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSborkaKomplImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSborkaKomplImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSborkaKomplImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocSborkaKomplImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocSborkaKomplImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocSborkaKomplImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSborkaKomplImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSborkaKomplImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocSborkaKomplImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocSborkaKomplImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSborkaKomplImpl::get_DocOsn(void)
{
return Object->DocOsn;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocOsn(TpFIBDataSet * DocOsn)
{
Object->DocOsn=DocOsn;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocSborkaKomplImpl::get_DataSourceDocOsn(void)
{
return Object->DataSourceDocOsn;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DataSourceDocOsn(TDataSource * DataSourceDocOsn)
{
Object->DataSourceDocOsn=DataSourceDocOsn;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocSborkaKomplImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSborkaKomplImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocSborkaKomplImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSborkaKomplImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSborkaKomplImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocOsnTDOC_REM_GALLDOC(void)
{
return Object->DocOsnTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocOsnTDOC_REM_GALLDOC(TFIBWideStringField * DocOsnTDOC_REM_GALLDOC)
{
Object->DocOsnTDOC_REM_GALLDOC=DocOsnTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocSborkaKomplImpl::get_DocOsnPOS_REM_GALLDOC(void)
{
return Object->DocOsnPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocOsnPOS_REM_GALLDOC(TFIBDateTimeField * DocOsnPOS_REM_GALLDOC)
{
Object->DocOsnPOS_REM_GALLDOC=DocOsnPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSborkaKomplImpl::get_DocOsnNUM_REM_GALLDOC(void)
{
return Object->DocOsnNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocOsnNUM_REM_GALLDOC(TFIBIntegerField * DocOsnNUM_REM_GALLDOC)
{
Object->DocOsnNUM_REM_GALLDOC=DocOsnNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocTID_REM_DSBKOMPLT(void)
{
return Object->DocTID_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTID_REM_DSBKOMPLT(TFIBLargeIntField * DocTID_REM_DSBKOMPLT)
{
Object->DocTID_REM_DSBKOMPLT=DocTID_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocTIDBASE_REM_DSBKOMPLT(void)
{
return Object->DocTIDBASE_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTIDBASE_REM_DSBKOMPLT(TFIBLargeIntField * DocTIDBASE_REM_DSBKOMPLT)
{
Object->DocTIDBASE_REM_DSBKOMPLT=DocTIDBASE_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocTIDDOC_REM_DSBKOMPLT(void)
{
return Object->DocTIDDOC_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTIDDOC_REM_DSBKOMPLT(TFIBLargeIntField * DocTIDDOC_REM_DSBKOMPLT)
{
Object->DocTIDDOC_REM_DSBKOMPLT=DocTIDDOC_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocTGID_REM_DSBKOMPLT(void)
{
return Object->DocTGID_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTGID_REM_DSBKOMPLT(TFIBWideStringField * DocTGID_REM_DSBKOMPLT)
{
Object->DocTGID_REM_DSBKOMPLT=DocTGID_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocTIDNOM_REM_DSBKOMPLT(void)
{
return Object->DocTIDNOM_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTIDNOM_REM_DSBKOMPLT(TFIBLargeIntField * DocTIDNOM_REM_DSBKOMPLT)
{
Object->DocTIDNOM_REM_DSBKOMPLT=DocTIDNOM_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocTIDED_REM_DSBKOMPLT(void)
{
return Object->DocTIDED_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTIDED_REM_DSBKOMPLT(TFIBLargeIntField * DocTIDED_REM_DSBKOMPLT)
{
Object->DocTIDED_REM_DSBKOMPLT=DocTIDED_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocTIDHW_REM_DSBKOMPLT(void)
{
return Object->DocTIDHW_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTIDHW_REM_DSBKOMPLT(TFIBLargeIntField * DocTIDHW_REM_DSBKOMPLT)
{
Object->DocTIDHW_REM_DSBKOMPLT=DocTIDHW_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSborkaKomplImpl::get_DocTKOL_REM_DSBKOMPLT(void)
{
return Object->DocTKOL_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTKOL_REM_DSBKOMPLT(TFIBBCDField * DocTKOL_REM_DSBKOMPLT)
{
Object->DocTKOL_REM_DSBKOMPLT=DocTKOL_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSborkaKomplImpl::get_DocTKF_REM_DSBKOMPLT(void)
{
return Object->DocTKF_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTKF_REM_DSBKOMPLT(TFIBBCDField * DocTKF_REM_DSBKOMPLT)
{
Object->DocTKF_REM_DSBKOMPLT=DocTKF_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSborkaKomplImpl::get_DocTRPRICE_REM_DSBKOMPLT(void)
{
return Object->DocTRPRICE_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTRPRICE_REM_DSBKOMPLT(TFIBBCDField * DocTRPRICE_REM_DSBKOMPLT)
{
Object->DocTRPRICE_REM_DSBKOMPLT=DocTRPRICE_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSborkaKomplImpl::get_DocTRSUM_REM_DSBKOMPLT(void)
{
return Object->DocTRSUM_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTRSUM_REM_DSBKOMPLT(TFIBBCDField * DocTRSUM_REM_DSBKOMPLT)
{
Object->DocTRSUM_REM_DSBKOMPLT=DocTRSUM_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocSborkaKomplImpl::get_DocTDVREG_REM_DSBKOMPLT(void)
{
return Object->DocTDVREG_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTDVREG_REM_DSBKOMPLT(TFIBSmallIntField * DocTDVREG_REM_DSBKOMPLT)
{
Object->DocTDVREG_REM_DSBKOMPLT=DocTDVREG_REM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocTKRNAMENOM(void)
{
return Object->DocTKRNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM)
{
Object->DocTKRNAMENOM=DocTKRNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocSborkaKomplImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTTNOM(TFIBSmallIntField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSborkaKomplImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocTIDGRPNOM(void)
{
return Object->DocTIDGRPNOM;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTIDGRPNOM(TFIBLargeIntField * DocTIDGRPNOM)
{
Object->DocTIDGRPNOM=DocTIDGRPNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocTIDVID_SNOM(void)
{
return Object->DocTIDVID_SNOM;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTIDVID_SNOM(TFIBLargeIntField * DocTIDVID_SNOM)
{
Object->DocTIDVID_SNOM=DocTIDVID_SNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocTNAMEGN(void)
{
return Object->DocTNAMEGN;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN)
{
Object->DocTNAMEGN=DocTNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocTNAME_SVIDNOM(void)
{
return Object->DocTNAME_SVIDNOM;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTNAME_SVIDNOM(TFIBWideStringField * DocTNAME_SVIDNOM)
{
Object->DocTNAME_SVIDNOM=DocTNAME_SVIDNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSborkaKomplImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocSborkaKomplImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocID_REM_DSBKOMPL(void)
{
return Object->DocID_REM_DSBKOMPL;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocID_REM_DSBKOMPL(TFIBLargeIntField * DocID_REM_DSBKOMPL)
{
Object->DocID_REM_DSBKOMPL=DocID_REM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocIDBASE_REM_DSBKOMPL(void)
{
return Object->DocIDBASE_REM_DSBKOMPL;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocIDBASE_REM_DSBKOMPL(TFIBLargeIntField * DocIDBASE_REM_DSBKOMPL)
{
Object->DocIDBASE_REM_DSBKOMPL=DocIDBASE_REM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocIDDOC_REM_DSBKOMPL(void)
{
return Object->DocIDDOC_REM_DSBKOMPL;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocIDDOC_REM_DSBKOMPL(TFIBLargeIntField * DocIDDOC_REM_DSBKOMPL)
{
Object->DocIDDOC_REM_DSBKOMPL=DocIDDOC_REM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocGID_REM_DSBKOMPL(void)
{
return Object->DocGID_REM_DSBKOMPL;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocGID_REM_DSBKOMPL(TFIBWideStringField * DocGID_REM_DSBKOMPL)
{
Object->DocGID_REM_DSBKOMPL=DocGID_REM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocIDNOM_REM_DSBKOMPL(void)
{
return Object->DocIDNOM_REM_DSBKOMPL;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocIDNOM_REM_DSBKOMPL(TFIBLargeIntField * DocIDNOM_REM_DSBKOMPL)
{
Object->DocIDNOM_REM_DSBKOMPL=DocIDNOM_REM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocIDED_REM_DSBKOMPL(void)
{
return Object->DocIDED_REM_DSBKOMPL;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocIDED_REM_DSBKOMPL(TFIBLargeIntField * DocIDED_REM_DSBKOMPL)
{
Object->DocIDED_REM_DSBKOMPL=DocIDED_REM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocIDHW_REM_DSBKOMPL(void)
{
return Object->DocIDHW_REM_DSBKOMPL;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocIDHW_REM_DSBKOMPL(TFIBLargeIntField * DocIDHW_REM_DSBKOMPL)
{
Object->DocIDHW_REM_DSBKOMPL=DocIDHW_REM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSborkaKomplImpl::get_DocKOL_REM_DSBKOMPL(void)
{
return Object->DocKOL_REM_DSBKOMPL;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocKOL_REM_DSBKOMPL(TFIBBCDField * DocKOL_REM_DSBKOMPL)
{
Object->DocKOL_REM_DSBKOMPL=DocKOL_REM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSborkaKomplImpl::get_DocKF_REM_DSBKOMPL(void)
{
return Object->DocKF_REM_DSBKOMPL;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocKF_REM_DSBKOMPL(TFIBBCDField * DocKF_REM_DSBKOMPL)
{
Object->DocKF_REM_DSBKOMPL=DocKF_REM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSborkaKomplImpl::get_DocRPRICE_REM_DSBKOMPL(void)
{
return Object->DocRPRICE_REM_DSBKOMPL;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocRPRICE_REM_DSBKOMPL(TFIBBCDField * DocRPRICE_REM_DSBKOMPL)
{
Object->DocRPRICE_REM_DSBKOMPL=DocRPRICE_REM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSborkaKomplImpl::get_DocIDRTPRICE_REM_DSBKOMPL(void)
{
return Object->DocIDRTPRICE_REM_DSBKOMPL;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocIDRTPRICE_REM_DSBKOMPL(TFIBLargeIntField * DocIDRTPRICE_REM_DSBKOMPL)
{
Object->DocIDRTPRICE_REM_DSBKOMPL=DocIDRTPRICE_REM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocPRIM_REM_DSBKOMPL(void)
{
return Object->DocPRIM_REM_DSBKOMPL;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocPRIM_REM_DSBKOMPL(TFIBWideStringField * DocPRIM_REM_DSBKOMPL)
{
Object->DocPRIM_REM_DSBKOMPL=DocPRIM_REM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocNAMENOM(void)
{
return Object->DocNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocNAMENOM(TFIBWideStringField * DocNAMENOM)
{
Object->DocNAMENOM=DocNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSborkaKomplImpl::get_DocCODENOM(void)
{
return Object->DocCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocCODENOM(TFIBIntegerField * DocCODENOM)
{
Object->DocCODENOM=DocCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocARTNOM(void)
{
return Object->DocARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocARTNOM(TFIBWideStringField * DocARTNOM)
{
Object->DocARTNOM=DocARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocNAME_REM_SHARDWARE(void)
{
return Object->DocNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocNAME_REM_SHARDWARE(TFIBWideStringField * DocNAME_REM_SHARDWARE)
{
Object->DocNAME_REM_SHARDWARE=DocNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSborkaKomplImpl::get_DocCODE_REM_SHARDWARE(void)
{
return Object->DocCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocCODE_REM_SHARDWARE(TFIBIntegerField * DocCODE_REM_SHARDWARE)
{
Object->DocCODE_REM_SHARDWARE=DocCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocSERNUM_REM_SHARDWARE(void)
{
return Object->DocSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocSERNUM_REM_SHARDWARE(TFIBWideStringField * DocSERNUM_REM_SHARDWARE)
{
Object->DocSERNUM_REM_SHARDWARE=DocSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocNAMEED(void)
{
return Object->DocNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocNAMEED(TFIBWideStringField * DocNAMEED)
{
Object->DocNAMEED=DocNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSborkaKomplImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
UnicodeString TREM_DMDocSborkaKomplImpl::get_ProsmotrText(void)
{
return Object->ProsmotrText;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_ProsmotrText(UnicodeString ProsmotrText)
{
Object->ProsmotrText=ProsmotrText;
}
//---------------------------------------------------------------
__int64 TREM_DMDocSborkaKomplImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_DMDocSborkaKomplImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_DMDocSborkaKomplImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
__int64 TREM_DMDocSborkaKomplImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
int TREM_DMDocSborkaKomplImpl::get_Operation(void)
{
return Object->Operation;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_Operation(int Operation)
{
Object->Operation=Operation;
}
//---------------------------------------------------------------
__int64 TREM_DMDocSborkaKomplImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::get_AutoRaschet(void)
{
return Object->AutoRaschet;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_AutoRaschet(bool AutoRaschet)
{
Object->AutoRaschet=AutoRaschet;
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::get_NoOtrOstatok(void)
{
return Object->NoOtrOstatok;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::set_NoOtrOstatok(bool NoOtrOstatok)
{
Object->NoOtrOstatok=NoOtrOstatok;
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::OpenDocOsn(void)
{
return Object->OpenDocOsn();
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::BeforeSaveDoc(void)
{
return Object->BeforeSaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::AfterSaveDoc(void)
{
return Object->AfterSaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocSborkaKomplImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
void TREM_DMDocSborkaKomplImpl::ValidateProsmotr(void)
{
return Object->ValidateProsmotr();
}
//---------------------------------------------------------------
int TREM_DMDocSborkaKomplImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
