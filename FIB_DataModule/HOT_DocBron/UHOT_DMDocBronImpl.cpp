#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMDocBronImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMDocBronImpl::THOT_DMDocBronImpl()           
{                                            
Object=new THOT_DMDocBron(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMDocBronImpl::~THOT_DMDocBronImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMDocBronImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMDocBronImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMDocBron)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMDocBron*> (this);                                
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
int THOT_DMDocBronImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMDocBronImpl::kanRelease(void)                                  
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
int  THOT_DMDocBronImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMDocBronImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMDocBronImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMDocBronImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMDocBronImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMDocBron
TDataSource * THOT_DMDocBronImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * THOT_DMDocBronImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocBronImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocBronImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocBronImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocBronImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocBronImpl::get_DocAllPOS_HOT_GALLDOC(void)
{
return Object->DocAllPOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllPOS_HOT_GALLDOC(TFIBDateTimeField * DocAllPOS_HOT_GALLDOC)
{
Object->DocAllPOS_HOT_GALLDOC=DocAllPOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMDocBronImpl::get_DocAllPR_HOT_GALLDOC(void)
{
return Object->DocAllPR_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllPR_HOT_GALLDOC(TFIBSmallIntField * DocAllPR_HOT_GALLDOC)
{
Object->DocAllPR_HOT_GALLDOC=DocAllPR_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocBronImpl::get_DocAllSUM_HOT_GALLDOC(void)
{
return Object->DocAllSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllSUM_HOT_GALLDOC(TFIBBCDField * DocAllSUM_HOT_GALLDOC)
{
Object->DocAllSUM_HOT_GALLDOC=DocAllSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocBronImpl::get_DocAllNUMBER_HOT_GALLDOC(void)
{
return Object->DocAllNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllNUMBER_HOT_GALLDOC(TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC)
{
Object->DocAllNUMBER_HOT_GALLDOC=DocAllNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocBronImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocBronImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocBronImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocBronImpl::get_DocTKOLM_HOT_SOSTNF(void)
{
return Object->DocTKOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTKOLM_HOT_SOSTNF(TFIBIntegerField * DocTKOLM_HOT_SOSTNF)
{
Object->DocTKOLM_HOT_SOSTNF=DocTKOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocBronImpl::get_DocTPOSNACH_HOT_SOSTNF(void)
{
return Object->DocTPOSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTPOSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTPOSNACH_HOT_SOSTNF)
{
Object->DocTPOSNACH_HOT_SOSTNF=DocTPOSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocBronImpl::get_DocTPOSCON_HOT_SOSTNF(void)
{
return Object->DocTPOSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTPOSCON_HOT_SOSTNF(TFIBDateTimeField * DocTPOSCON_HOT_SOSTNF)
{
Object->DocTPOSCON_HOT_SOSTNF=DocTPOSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
TDataSource * THOT_DMDocBronImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocBronImpl::get_DocAllTDOC_HOT_GALLDOC(void)
{
return Object->DocAllTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllTDOC_HOT_GALLDOC(TFIBWideStringField * DocAllTDOC_HOT_GALLDOC)
{
Object->DocAllTDOC_HOT_GALLDOC=DocAllTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocBronImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocBronImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocBronImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocBronImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocBronImpl::get_DocTNAME_HOT_SNF(void)
{
return Object->DocTNAME_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTNAME_HOT_SNF(TFIBWideStringField * DocTNAME_HOT_SNF)
{
Object->DocTNAME_HOT_SNF=DocTNAME_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocBronImpl::get_DocTNAME_HOT_SCATNOM(void)
{
return Object->DocTNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTNAME_HOT_SCATNOM(TFIBWideStringField * DocTNAME_HOT_SCATNOM)
{
Object->DocTNAME_HOT_SCATNOM=DocTNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocBronImpl::get_DocTNAME_HOT_STYPEPOS(void)
{
return Object->DocTNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTNAME_HOT_STYPEPOS(TFIBWideStringField * DocTNAME_HOT_STYPEPOS)
{
Object->DocTNAME_HOT_STYPEPOS=DocTNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocBronImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocBronImpl::get_DocTNAME_HOT_SSOSTNOM(void)
{
return Object->DocTNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTNAME_HOT_SSOSTNOM(TFIBWideStringField * DocTNAME_HOT_SSOSTNOM)
{
Object->DocTNAME_HOT_SSOSTNOM=DocTNAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocAllID_HOT_GALLDOC(void)
{
return Object->DocAllID_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllID_HOT_GALLDOC(TFIBLargeIntField * DocAllID_HOT_GALLDOC)
{
Object->DocAllID_HOT_GALLDOC=DocAllID_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocAllIDFIRM_HOT_GALLDOC(void)
{
return Object->DocAllIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllIDFIRM_HOT_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_HOT_GALLDOC)
{
Object->DocAllIDFIRM_HOT_GALLDOC=DocAllIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocAllIDKL_HOT_GALLDOC(void)
{
return Object->DocAllIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllIDKL_HOT_GALLDOC(TFIBLargeIntField * DocAllIDKL_HOT_GALLDOC)
{
Object->DocAllIDKL_HOT_GALLDOC=DocAllIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocAllIDUSER_HOT_GALLDOC(void)
{
return Object->DocAllIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllIDUSER_HOT_GALLDOC(TFIBLargeIntField * DocAllIDUSER_HOT_GALLDOC)
{
Object->DocAllIDUSER_HOT_GALLDOC=DocAllIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocAllIDDOCOSN_HOT_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllIDDOCOSN_HOT_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_HOT_GALLDOC)
{
Object->DocAllIDDOCOSN_HOT_GALLDOC=DocAllIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocAllIDBASE_HOT_GALLDOC(void)
{
return Object->DocAllIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocAllIDBASE_HOT_GALLDOC(TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC)
{
Object->DocAllIDBASE_HOT_GALLDOC=DocAllIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocID_HOT_DBRON(void)
{
return Object->DocID_HOT_DBRON;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocID_HOT_DBRON(TFIBLargeIntField * DocID_HOT_DBRON)
{
Object->DocID_HOT_DBRON=DocID_HOT_DBRON;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocIDDOCH_HOT_DBRON(void)
{
return Object->DocIDDOCH_HOT_DBRON;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocIDDOCH_HOT_DBRON(TFIBLargeIntField * DocIDDOCH_HOT_DBRON)
{
Object->DocIDDOCH_HOT_DBRON=DocIDDOCH_HOT_DBRON;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocBronImpl::get_DocDESCR_HOT_DBRON(void)
{
return Object->DocDESCR_HOT_DBRON;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocDESCR_HOT_DBRON(TFIBWideStringField * DocDESCR_HOT_DBRON)
{
Object->DocDESCR_HOT_DBRON=DocDESCR_HOT_DBRON;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocIDBASE_HOT_DBRON(void)
{
return Object->DocIDBASE_HOT_DBRON;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocIDBASE_HOT_DBRON(TFIBLargeIntField * DocIDBASE_HOT_DBRON)
{
Object->DocIDBASE_HOT_DBRON=DocIDBASE_HOT_DBRON;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocIDTPRICE_HOT_DBRON(void)
{
return Object->DocIDTPRICE_HOT_DBRON;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocIDTPRICE_HOT_DBRON(TFIBLargeIntField * DocIDTPRICE_HOT_DBRON)
{
Object->DocIDTPRICE_HOT_DBRON=DocIDTPRICE_HOT_DBRON;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocTID_HOT_DBRONT(void)
{
return Object->DocTID_HOT_DBRONT;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTID_HOT_DBRONT(TFIBLargeIntField * DocTID_HOT_DBRONT)
{
Object->DocTID_HOT_DBRONT=DocTID_HOT_DBRONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocTIDDOCH_HOT_DBRONT(void)
{
return Object->DocTIDDOCH_HOT_DBRONT;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTIDDOCH_HOT_DBRONT(TFIBLargeIntField * DocTIDDOCH_HOT_DBRONT)
{
Object->DocTIDDOCH_HOT_DBRONT=DocTIDDOCH_HOT_DBRONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocTIDSOST_HOT_DBRONT(void)
{
return Object->DocTIDSOST_HOT_DBRONT;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTIDSOST_HOT_DBRONT(TFIBLargeIntField * DocTIDSOST_HOT_DBRONT)
{
Object->DocTIDSOST_HOT_DBRONT=DocTIDSOST_HOT_DBRONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocTIDBASE_HOT_DBRONT(void)
{
return Object->DocTIDBASE_HOT_DBRONT;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTIDBASE_HOT_DBRONT(TFIBLargeIntField * DocTIDBASE_HOT_DBRONT)
{
Object->DocTIDBASE_HOT_DBRONT=DocTIDBASE_HOT_DBRONT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocTID_HOT_SOSTNF(void)
{
return Object->DocTID_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTID_HOT_SOSTNF(TFIBLargeIntField * DocTID_HOT_SOSTNF)
{
Object->DocTID_HOT_SOSTNF=DocTID_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocTIDNOMER_HOT_SOSTNF(void)
{
return Object->DocTIDNOMER_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTIDNOMER_HOT_SOSTNF(TFIBLargeIntField * DocTIDNOMER_HOT_SOSTNF)
{
Object->DocTIDNOMER_HOT_SOSTNF=DocTIDNOMER_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocTIDPLAT_HOT_SOSTNF(void)
{
return Object->DocTIDPLAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTIDPLAT_HOT_SOSTNF(TFIBLargeIntField * DocTIDPLAT_HOT_SOSTNF)
{
Object->DocTIDPLAT_HOT_SOSTNF=DocTIDPLAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocTIDGUEST_HOT_SOSTNF(void)
{
return Object->DocTIDGUEST_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTIDGUEST_HOT_SOSTNF(TFIBLargeIntField * DocTIDGUEST_HOT_SOSTNF)
{
Object->DocTIDGUEST_HOT_SOSTNF=DocTIDGUEST_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocTIDSOST_HOT_SOSTNF(void)
{
return Object->DocTIDSOST_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTIDSOST_HOT_SOSTNF(TFIBLargeIntField * DocTIDSOST_HOT_SOSTNF)
{
Object->DocTIDSOST_HOT_SOSTNF=DocTIDSOST_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocTIDTPOS_HOT_SOSTNF(void)
{
return Object->DocTIDTPOS_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTIDTPOS_HOT_SOSTNF(TFIBLargeIntField * DocTIDTPOS_HOT_SOSTNF)
{
Object->DocTIDTPOS_HOT_SOSTNF=DocTIDTPOS_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocTIDCAT_HOT_SOSTNF(void)
{
return Object->DocTIDCAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTIDCAT_HOT_SOSTNF(TFIBLargeIntField * DocTIDCAT_HOT_SOSTNF)
{
Object->DocTIDCAT_HOT_SOSTNF=DocTIDCAT_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocBronImpl::get_DocTIDDOCH_HOT_SOSTNF(void)
{
return Object->DocTIDDOCH_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_DocTIDDOCH_HOT_SOSTNF(TFIBLargeIntField * DocTIDDOCH_HOT_SOSTNF)
{
Object->DocTIDDOCH_HOT_SOSTNF=DocTIDDOCH_HOT_SOSTNF;
}
//---------------------------------------------------------------
bool THOT_DMDocBronImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool THOT_DMDocBronImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool THOT_DMDocBronImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocBronImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocBronImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocBronImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::AddString(void)
{
return Object->AddString();
}
//---------------------------------------------------------------
void THOT_DMDocBronImpl::DeleteString(void)
{
return Object->DeleteString();
}
//---------------------------------------------------------------
