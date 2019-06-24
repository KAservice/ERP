#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMDocViezdImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMDocViezdImpl::THOT_DMDocViezdImpl()           
{                                            
Object=new THOT_DMDocViezd(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMDocViezdImpl::~THOT_DMDocViezdImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMDocViezdImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMDocViezd)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMDocViezd*> (this);                                
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
int THOT_DMDocViezdImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMDocViezdImpl::kanRelease(void)                                  
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
int  THOT_DMDocViezdImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMDocViezdImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMDocViezdImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMDocViezdImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMDocViezdImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMDocViezd
TDataSource * THOT_DMDocViezdImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * THOT_DMDocViezdImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocViezdImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocViezdImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocViezdImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocViezdImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocViezdImpl::get_DocAllPOS_HOT_GALLDOC(void)
{
return Object->DocAllPOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllPOS_HOT_GALLDOC(TFIBDateTimeField * DocAllPOS_HOT_GALLDOC)
{
Object->DocAllPOS_HOT_GALLDOC=DocAllPOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMDocViezdImpl::get_DocAllPR_HOT_GALLDOC(void)
{
return Object->DocAllPR_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllPR_HOT_GALLDOC(TFIBSmallIntField * DocAllPR_HOT_GALLDOC)
{
Object->DocAllPR_HOT_GALLDOC=DocAllPR_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocViezdImpl::get_DocAllSUM_HOT_GALLDOC(void)
{
return Object->DocAllSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllSUM_HOT_GALLDOC(TFIBBCDField * DocAllSUM_HOT_GALLDOC)
{
Object->DocAllSUM_HOT_GALLDOC=DocAllSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocViezdImpl::get_DocAllNUMBER_HOT_GALLDOC(void)
{
return Object->DocAllNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllNUMBER_HOT_GALLDOC(TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC)
{
Object->DocAllNUMBER_HOT_GALLDOC=DocAllNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocViezdImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocViezdImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocViezdImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocViezdImpl::get_DocTKOLM_HOT_SOSTNF(void)
{
return Object->DocTKOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTKOLM_HOT_SOSTNF(TFIBIntegerField * DocTKOLM_HOT_SOSTNF)
{
Object->DocTKOLM_HOT_SOSTNF=DocTKOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocViezdImpl::get_DocTPOSNACH_HOT_SOSTNF(void)
{
return Object->DocTPOSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTPOSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTPOSNACH_HOT_SOSTNF)
{
Object->DocTPOSNACH_HOT_SOSTNF=DocTPOSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocViezdImpl::get_DocTPOSCON_HOT_SOSTNF(void)
{
return Object->DocTPOSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTPOSCON_HOT_SOSTNF(TFIBDateTimeField * DocTPOSCON_HOT_SOSTNF)
{
Object->DocTPOSCON_HOT_SOSTNF=DocTPOSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
TDataSource * THOT_DMDocViezdImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocViezdImpl::get_DocAllTDOC_HOT_GALLDOC(void)
{
return Object->DocAllTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllTDOC_HOT_GALLDOC(TFIBWideStringField * DocAllTDOC_HOT_GALLDOC)
{
Object->DocAllTDOC_HOT_GALLDOC=DocAllTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocViezdImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocViezdImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocViezdImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocViezdImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocViezdImpl::get_DocDESCR_HOT_DVIESD(void)
{
return Object->DocDESCR_HOT_DVIESD;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocDESCR_HOT_DVIESD(TFIBWideStringField * DocDESCR_HOT_DVIESD)
{
Object->DocDESCR_HOT_DVIESD=DocDESCR_HOT_DVIESD;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocViezdImpl::get_DocTNAME_HOT_SNF(void)
{
return Object->DocTNAME_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTNAME_HOT_SNF(TFIBWideStringField * DocTNAME_HOT_SNF)
{
Object->DocTNAME_HOT_SNF=DocTNAME_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocViezdImpl::get_DocTNAME_HOT_SCATNOM(void)
{
return Object->DocTNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTNAME_HOT_SCATNOM(TFIBWideStringField * DocTNAME_HOT_SCATNOM)
{
Object->DocTNAME_HOT_SCATNOM=DocTNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocViezdImpl::get_DocTNAME_HOT_STYPEPOS(void)
{
return Object->DocTNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTNAME_HOT_STYPEPOS(TFIBWideStringField * DocTNAME_HOT_STYPEPOS)
{
Object->DocTNAME_HOT_STYPEPOS=DocTNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocViezdImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocViezdImpl::get_DocTNAME_HOT_SSOSTNOM(void)
{
return Object->DocTNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTNAME_HOT_SSOSTNOM(TFIBWideStringField * DocTNAME_HOT_SSOSTNOM)
{
Object->DocTNAME_HOT_SSOSTNOM=DocTNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocAllID_HOT_GALLDOC(void)
{
return Object->DocAllID_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllID_HOT_GALLDOC(TFIBLargeIntField * DocAllID_HOT_GALLDOC)
{
Object->DocAllID_HOT_GALLDOC=DocAllID_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocAllIDFIRM_HOT_GALLDOC(void)
{
return Object->DocAllIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllIDFIRM_HOT_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_HOT_GALLDOC)
{
Object->DocAllIDFIRM_HOT_GALLDOC=DocAllIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocAllIDKL_HOT_GALLDOC(void)
{
return Object->DocAllIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllIDKL_HOT_GALLDOC(TFIBLargeIntField * DocAllIDKL_HOT_GALLDOC)
{
Object->DocAllIDKL_HOT_GALLDOC=DocAllIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocAllIDUSER_HOT_GALLDOC(void)
{
return Object->DocAllIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllIDUSER_HOT_GALLDOC(TFIBLargeIntField * DocAllIDUSER_HOT_GALLDOC)
{
Object->DocAllIDUSER_HOT_GALLDOC=DocAllIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocAllIDDOCOSN_HOT_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllIDDOCOSN_HOT_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_HOT_GALLDOC)
{
Object->DocAllIDDOCOSN_HOT_GALLDOC=DocAllIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocAllIDBASE_HOT_GALLDOC(void)
{
return Object->DocAllIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocAllIDBASE_HOT_GALLDOC(TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC)
{
Object->DocAllIDBASE_HOT_GALLDOC=DocAllIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocID_HOT_DVIESD(void)
{
return Object->DocID_HOT_DVIESD;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocID_HOT_DVIESD(TFIBLargeIntField * DocID_HOT_DVIESD)
{
Object->DocID_HOT_DVIESD=DocID_HOT_DVIESD;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocIDDOCH_HOT_DVIESD(void)
{
return Object->DocIDDOCH_HOT_DVIESD;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocIDDOCH_HOT_DVIESD(TFIBLargeIntField * DocIDDOCH_HOT_DVIESD)
{
Object->DocIDDOCH_HOT_DVIESD=DocIDDOCH_HOT_DVIESD;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocIDBASE_HOT_DVIESD(void)
{
return Object->DocIDBASE_HOT_DVIESD;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocIDBASE_HOT_DVIESD(TFIBLargeIntField * DocIDBASE_HOT_DVIESD)
{
Object->DocIDBASE_HOT_DVIESD=DocIDBASE_HOT_DVIESD;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocTID_HOT_DVIESDT(void)
{
return Object->DocTID_HOT_DVIESDT;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTID_HOT_DVIESDT(TFIBLargeIntField * DocTID_HOT_DVIESDT)
{
Object->DocTID_HOT_DVIESDT=DocTID_HOT_DVIESDT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocTIDDOCH_HOT_DVIESDT(void)
{
return Object->DocTIDDOCH_HOT_DVIESDT;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTIDDOCH_HOT_DVIESDT(TFIBLargeIntField * DocTIDDOCH_HOT_DVIESDT)
{
Object->DocTIDDOCH_HOT_DVIESDT=DocTIDDOCH_HOT_DVIESDT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocTIDSOST_HOT_DVIESDT(void)
{
return Object->DocTIDSOST_HOT_DVIESDT;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTIDSOST_HOT_DVIESDT(TFIBLargeIntField * DocTIDSOST_HOT_DVIESDT)
{
Object->DocTIDSOST_HOT_DVIESDT=DocTIDSOST_HOT_DVIESDT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocTIDBASE_HOT_DVIESDT(void)
{
return Object->DocTIDBASE_HOT_DVIESDT;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTIDBASE_HOT_DVIESDT(TFIBLargeIntField * DocTIDBASE_HOT_DVIESDT)
{
Object->DocTIDBASE_HOT_DVIESDT=DocTIDBASE_HOT_DVIESDT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocTIDNOMER_HOT_SOSTNF(void)
{
return Object->DocTIDNOMER_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTIDNOMER_HOT_SOSTNF(TFIBLargeIntField * DocTIDNOMER_HOT_SOSTNF)
{
Object->DocTIDNOMER_HOT_SOSTNF=DocTIDNOMER_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocTIDPLAT_HOT_SOSTNF(void)
{
return Object->DocTIDPLAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTIDPLAT_HOT_SOSTNF(TFIBLargeIntField * DocTIDPLAT_HOT_SOSTNF)
{
Object->DocTIDPLAT_HOT_SOSTNF=DocTIDPLAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocTIDGUEST_HOT_SOSTNF(void)
{
return Object->DocTIDGUEST_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTIDGUEST_HOT_SOSTNF(TFIBLargeIntField * DocTIDGUEST_HOT_SOSTNF)
{
Object->DocTIDGUEST_HOT_SOSTNF=DocTIDGUEST_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocTIDSOST_HOT_SOSTNF(void)
{
return Object->DocTIDSOST_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTIDSOST_HOT_SOSTNF(TFIBLargeIntField * DocTIDSOST_HOT_SOSTNF)
{
Object->DocTIDSOST_HOT_SOSTNF=DocTIDSOST_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocTIDTPOS_HOT_SOSTNF(void)
{
return Object->DocTIDTPOS_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTIDTPOS_HOT_SOSTNF(TFIBLargeIntField * DocTIDTPOS_HOT_SOSTNF)
{
Object->DocTIDTPOS_HOT_SOSTNF=DocTIDTPOS_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocViezdImpl::get_DocTIDCAT_HOT_SOSTNF(void)
{
return Object->DocTIDCAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_DocTIDCAT_HOT_SOSTNF(TFIBLargeIntField * DocTIDCAT_HOT_SOSTNF)
{
Object->DocTIDCAT_HOT_SOSTNF=DocTIDCAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
bool THOT_DMDocViezdImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool THOT_DMDocViezdImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool THOT_DMDocViezdImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocViezdImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocViezdImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocViezdImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::AddString(void)
{
return Object->AddString();
}
//---------------------------------------------------------------
void THOT_DMDocViezdImpl::DeleteString(void)
{
return Object->DeleteString();
}
//---------------------------------------------------------------
