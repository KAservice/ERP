#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMDocOtmenaBronImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMDocOtmenaBronImpl::THOT_DMDocOtmenaBronImpl()           
{                                            
Object=new THOT_DMDocOtmenaBron(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMDocOtmenaBronImpl::~THOT_DMDocOtmenaBronImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMDocOtmenaBronImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMDocOtmenaBron)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMDocOtmenaBron*> (this);                                
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
int THOT_DMDocOtmenaBronImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMDocOtmenaBronImpl::kanRelease(void)                                  
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
int  THOT_DMDocOtmenaBronImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMDocOtmenaBronImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMDocOtmenaBronImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMDocOtmenaBronImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMDocOtmenaBronImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMDocOtmenaBron
TDataSource * THOT_DMDocOtmenaBronImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * THOT_DMDocOtmenaBronImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocOtmenaBronImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocOtmenaBronImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocOtmenaBronImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocOtmenaBronImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocOtmenaBronImpl::get_DocAllPOS_HOT_GALLDOC(void)
{
return Object->DocAllPOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllPOS_HOT_GALLDOC(TFIBDateTimeField * DocAllPOS_HOT_GALLDOC)
{
Object->DocAllPOS_HOT_GALLDOC=DocAllPOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMDocOtmenaBronImpl::get_DocAllPR_HOT_GALLDOC(void)
{
return Object->DocAllPR_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllPR_HOT_GALLDOC(TFIBSmallIntField * DocAllPR_HOT_GALLDOC)
{
Object->DocAllPR_HOT_GALLDOC=DocAllPR_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocOtmenaBronImpl::get_DocAllSUM_HOT_GALLDOC(void)
{
return Object->DocAllSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllSUM_HOT_GALLDOC(TFIBBCDField * DocAllSUM_HOT_GALLDOC)
{
Object->DocAllSUM_HOT_GALLDOC=DocAllSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocOtmenaBronImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocOtmenaBronImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocOtmenaBronImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TDataSource * THOT_DMDocOtmenaBronImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocOtmenaBronImpl::get_DocTKOLM_HOT_SOSTNF(void)
{
return Object->DocTKOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTKOLM_HOT_SOSTNF(TFIBIntegerField * DocTKOLM_HOT_SOSTNF)
{
Object->DocTKOLM_HOT_SOSTNF=DocTKOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocOtmenaBronImpl::get_DocTPOSNACH_HOT_SOSTNF(void)
{
return Object->DocTPOSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTPOSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTPOSNACH_HOT_SOSTNF)
{
Object->DocTPOSNACH_HOT_SOSTNF=DocTPOSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocOtmenaBronImpl::get_DocTPOSCON_HOT_SOSTNF(void)
{
return Object->DocTPOSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTPOSCON_HOT_SOSTNF(TFIBDateTimeField * DocTPOSCON_HOT_SOSTNF)
{
Object->DocTPOSCON_HOT_SOSTNF=DocTPOSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocOtmenaBronImpl::get_DocAllTDOC_HOT_GALLDOC(void)
{
return Object->DocAllTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllTDOC_HOT_GALLDOC(TFIBWideStringField * DocAllTDOC_HOT_GALLDOC)
{
Object->DocAllTDOC_HOT_GALLDOC=DocAllTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocOtmenaBronImpl::get_DocAllNUMBER_HOT_GALLDOC(void)
{
return Object->DocAllNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllNUMBER_HOT_GALLDOC(TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC)
{
Object->DocAllNUMBER_HOT_GALLDOC=DocAllNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocOtmenaBronImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocOtmenaBronImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocOtmenaBronImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocOtmenaBronImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocOtmenaBronImpl::get_DocGID_HOT_DOTMBRON(void)
{
return Object->DocGID_HOT_DOTMBRON;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocGID_HOT_DOTMBRON(TFIBWideStringField * DocGID_HOT_DOTMBRON)
{
Object->DocGID_HOT_DOTMBRON=DocGID_HOT_DOTMBRON;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocOtmenaBronImpl::get_DocTNAME_HOT_SNF(void)
{
return Object->DocTNAME_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTNAME_HOT_SNF(TFIBWideStringField * DocTNAME_HOT_SNF)
{
Object->DocTNAME_HOT_SNF=DocTNAME_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocOtmenaBronImpl::get_DocTNAME_HOT_SCATNOM(void)
{
return Object->DocTNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTNAME_HOT_SCATNOM(TFIBWideStringField * DocTNAME_HOT_SCATNOM)
{
Object->DocTNAME_HOT_SCATNOM=DocTNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocOtmenaBronImpl::get_DocTNAME_HOT_STYPEPOS(void)
{
return Object->DocTNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTNAME_HOT_STYPEPOS(TFIBWideStringField * DocTNAME_HOT_STYPEPOS)
{
Object->DocTNAME_HOT_STYPEPOS=DocTNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocOtmenaBronImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocOtmenaBronImpl::get_DocTNAME_HOT_SSOSTNOM(void)
{
return Object->DocTNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTNAME_HOT_SSOSTNOM(TFIBWideStringField * DocTNAME_HOT_SSOSTNOM)
{
Object->DocTNAME_HOT_SSOSTNOM=DocTNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocAllID_HOT_GALLDOC(void)
{
return Object->DocAllID_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllID_HOT_GALLDOC(TFIBLargeIntField * DocAllID_HOT_GALLDOC)
{
Object->DocAllID_HOT_GALLDOC=DocAllID_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocAllIDFIRM_HOT_GALLDOC(void)
{
return Object->DocAllIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllIDFIRM_HOT_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_HOT_GALLDOC)
{
Object->DocAllIDFIRM_HOT_GALLDOC=DocAllIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocAllIDKL_HOT_GALLDOC(void)
{
return Object->DocAllIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllIDKL_HOT_GALLDOC(TFIBLargeIntField * DocAllIDKL_HOT_GALLDOC)
{
Object->DocAllIDKL_HOT_GALLDOC=DocAllIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocAllIDUSER_HOT_GALLDOC(void)
{
return Object->DocAllIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllIDUSER_HOT_GALLDOC(TFIBLargeIntField * DocAllIDUSER_HOT_GALLDOC)
{
Object->DocAllIDUSER_HOT_GALLDOC=DocAllIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocAllIDDOCOSN_HOT_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllIDDOCOSN_HOT_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_HOT_GALLDOC)
{
Object->DocAllIDDOCOSN_HOT_GALLDOC=DocAllIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocAllIDBASE_HOT_GALLDOC(void)
{
return Object->DocAllIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocAllIDBASE_HOT_GALLDOC(TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC)
{
Object->DocAllIDBASE_HOT_GALLDOC=DocAllIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocID_HOT_DOTMBRON(void)
{
return Object->DocID_HOT_DOTMBRON;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocID_HOT_DOTMBRON(TFIBLargeIntField * DocID_HOT_DOTMBRON)
{
Object->DocID_HOT_DOTMBRON=DocID_HOT_DOTMBRON;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocIDDOCH_HOT_DOTMBRON(void)
{
return Object->DocIDDOCH_HOT_DOTMBRON;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocIDDOCH_HOT_DOTMBRON(TFIBLargeIntField * DocIDDOCH_HOT_DOTMBRON)
{
Object->DocIDDOCH_HOT_DOTMBRON=DocIDDOCH_HOT_DOTMBRON;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocOtmenaBronImpl::get_DocDESCR_HOT_DOTMBRON(void)
{
return Object->DocDESCR_HOT_DOTMBRON;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocDESCR_HOT_DOTMBRON(TFIBWideStringField * DocDESCR_HOT_DOTMBRON)
{
Object->DocDESCR_HOT_DOTMBRON=DocDESCR_HOT_DOTMBRON;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocIDBASE_HOT_DOTMBRON(void)
{
return Object->DocIDBASE_HOT_DOTMBRON;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocIDBASE_HOT_DOTMBRON(TFIBLargeIntField * DocIDBASE_HOT_DOTMBRON)
{
Object->DocIDBASE_HOT_DOTMBRON=DocIDBASE_HOT_DOTMBRON;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocTID_HOT_DOTMBRONT(void)
{
return Object->DocTID_HOT_DOTMBRONT;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTID_HOT_DOTMBRONT(TFIBLargeIntField * DocTID_HOT_DOTMBRONT)
{
Object->DocTID_HOT_DOTMBRONT=DocTID_HOT_DOTMBRONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocTIDDOCH_HOT_DOTMBRONT(void)
{
return Object->DocTIDDOCH_HOT_DOTMBRONT;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTIDDOCH_HOT_DOTMBRONT(TFIBLargeIntField * DocTIDDOCH_HOT_DOTMBRONT)
{
Object->DocTIDDOCH_HOT_DOTMBRONT=DocTIDDOCH_HOT_DOTMBRONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocTIDSOST_HOT_DOTMBRONT(void)
{
return Object->DocTIDSOST_HOT_DOTMBRONT;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTIDSOST_HOT_DOTMBRONT(TFIBLargeIntField * DocTIDSOST_HOT_DOTMBRONT)
{
Object->DocTIDSOST_HOT_DOTMBRONT=DocTIDSOST_HOT_DOTMBRONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocTIDBASE_HOT_DOTMBRONT(void)
{
return Object->DocTIDBASE_HOT_DOTMBRONT;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTIDBASE_HOT_DOTMBRONT(TFIBLargeIntField * DocTIDBASE_HOT_DOTMBRONT)
{
Object->DocTIDBASE_HOT_DOTMBRONT=DocTIDBASE_HOT_DOTMBRONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocTIDNOMER_HOT_SOSTNF(void)
{
return Object->DocTIDNOMER_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTIDNOMER_HOT_SOSTNF(TFIBLargeIntField * DocTIDNOMER_HOT_SOSTNF)
{
Object->DocTIDNOMER_HOT_SOSTNF=DocTIDNOMER_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocTIDPLAT_HOT_SOSTNF(void)
{
return Object->DocTIDPLAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTIDPLAT_HOT_SOSTNF(TFIBLargeIntField * DocTIDPLAT_HOT_SOSTNF)
{
Object->DocTIDPLAT_HOT_SOSTNF=DocTIDPLAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocTIDGUEST_HOT_SOSTNF(void)
{
return Object->DocTIDGUEST_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTIDGUEST_HOT_SOSTNF(TFIBLargeIntField * DocTIDGUEST_HOT_SOSTNF)
{
Object->DocTIDGUEST_HOT_SOSTNF=DocTIDGUEST_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocTIDSOST_HOT_SOSTNF(void)
{
return Object->DocTIDSOST_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTIDSOST_HOT_SOSTNF(TFIBLargeIntField * DocTIDSOST_HOT_SOSTNF)
{
Object->DocTIDSOST_HOT_SOSTNF=DocTIDSOST_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocTIDTPOS_HOT_SOSTNF(void)
{
return Object->DocTIDTPOS_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTIDTPOS_HOT_SOSTNF(TFIBLargeIntField * DocTIDTPOS_HOT_SOSTNF)
{
Object->DocTIDTPOS_HOT_SOSTNF=DocTIDTPOS_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocOtmenaBronImpl::get_DocTIDCAT_HOT_SOSTNF(void)
{
return Object->DocTIDCAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_DocTIDCAT_HOT_SOSTNF(TFIBLargeIntField * DocTIDCAT_HOT_SOSTNF)
{
Object->DocTIDCAT_HOT_SOSTNF=DocTIDCAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
bool THOT_DMDocOtmenaBronImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool THOT_DMDocOtmenaBronImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool THOT_DMDocOtmenaBronImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocOtmenaBronImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocOtmenaBronImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocOtmenaBronImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::AddString(void)
{
return Object->AddString();
}
//---------------------------------------------------------------
void THOT_DMDocOtmenaBronImpl::DeleteString(void)
{
return Object->DeleteString();
}
//---------------------------------------------------------------
