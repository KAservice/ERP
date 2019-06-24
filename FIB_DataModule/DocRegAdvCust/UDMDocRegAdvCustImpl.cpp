#include "vcl.h"
#pragma hdrstop


#include "UDMDocRegAdvCustImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRegAdvCustImpl::TDMDocRegAdvCustImpl()           
{                                            
Object=new TDMDocRegAdvCust(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRegAdvCustImpl::~TDMDocRegAdvCustImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRegAdvCustImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRegAdvCust)                        
   {                                                                     
   *ppv=static_cast<IDMDocRegAdvCust*> (this);                                
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
int TDMDocRegAdvCustImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRegAdvCustImpl::kanRelease(void)                                  
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
int  TDMDocRegAdvCustImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRegAdvCustImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRegAdvCustImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRegAdvCustImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRegAdvCustImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRegAdvCust
TDataSource * TDMDocRegAdvCustImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegAdvCustImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegAdvCustImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegAdvCustImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegAdvCustImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegAdvCustImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegAdvCustImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegAdvCustImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegAdvCustImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegAdvCustImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegAdvCustImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegAdvCustImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegAdvCustImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRegAdvCustImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegAdvCustImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegAdvCustImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegAdvCustImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRegAdvCustImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegAdvCustImpl::get_DocTTDV_DRG_ADVCUSTT(void)
{
return Object->DocTTDV_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocTTDV_DRG_ADVCUSTT(TFIBSmallIntField * DocTTDV_DRG_ADVCUSTT)
{
Object->DocTTDV_DRG_ADVCUSTT=DocTTDV_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegAdvCustImpl::get_DocTOPER_DRG_ADVCUSTT(void)
{
return Object->DocTOPER_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocTOPER_DRG_ADVCUSTT(TFIBSmallIntField * DocTOPER_DRG_ADVCUSTT)
{
Object->DocTOPER_DRG_ADVCUSTT=DocTOPER_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegAdvCustImpl::get_DocTSUM_DRG_ADVCUSTT(void)
{
return Object->DocTSUM_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocTSUM_DRG_ADVCUSTT(TFIBBCDField * DocTSUM_DRG_ADVCUSTT)
{
Object->DocTSUM_DRG_ADVCUSTT=DocTSUM_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegAdvCustImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegAdvCustImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegAdvCustImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegAdvCustImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegAdvCustImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocID_DRG_ADVCUST(void)
{
return Object->DocID_DRG_ADVCUST;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocID_DRG_ADVCUST(TFIBLargeIntField * DocID_DRG_ADVCUST)
{
Object->DocID_DRG_ADVCUST=DocID_DRG_ADVCUST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocIDDOC_DRG_ADVCUST(void)
{
return Object->DocIDDOC_DRG_ADVCUST;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocIDDOC_DRG_ADVCUST(TFIBLargeIntField * DocIDDOC_DRG_ADVCUST)
{
Object->DocIDDOC_DRG_ADVCUST=DocIDDOC_DRG_ADVCUST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegAdvCustImpl::get_DocDESCR_DRG_ADVCUST(void)
{
return Object->DocDESCR_DRG_ADVCUST;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocDESCR_DRG_ADVCUST(TFIBWideStringField * DocDESCR_DRG_ADVCUST)
{
Object->DocDESCR_DRG_ADVCUST=DocDESCR_DRG_ADVCUST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocIDBASE_DRG_ADVCUST(void)
{
return Object->DocIDBASE_DRG_ADVCUST;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocIDBASE_DRG_ADVCUST(TFIBLargeIntField * DocIDBASE_DRG_ADVCUST)
{
Object->DocIDBASE_DRG_ADVCUST=DocIDBASE_DRG_ADVCUST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocTID_DRG_ADVCUSTT(void)
{
return Object->DocTID_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocTID_DRG_ADVCUSTT(TFIBLargeIntField * DocTID_DRG_ADVCUSTT)
{
Object->DocTID_DRG_ADVCUSTT=DocTID_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocTIDDOC_DRG_ADVCUSTT(void)
{
return Object->DocTIDDOC_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocTIDDOC_DRG_ADVCUSTT(TFIBLargeIntField * DocTIDDOC_DRG_ADVCUSTT)
{
Object->DocTIDDOC_DRG_ADVCUSTT=DocTIDDOC_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocTIDFIRM_DRG_ADVCUSTT(void)
{
return Object->DocTIDFIRM_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocTIDFIRM_DRG_ADVCUSTT(TFIBLargeIntField * DocTIDFIRM_DRG_ADVCUSTT)
{
Object->DocTIDFIRM_DRG_ADVCUSTT=DocTIDFIRM_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocTIDKLIENT_DRG_ADVCUSTT(void)
{
return Object->DocTIDKLIENT_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocTIDKLIENT_DRG_ADVCUSTT(TFIBLargeIntField * DocTIDKLIENT_DRG_ADVCUSTT)
{
Object->DocTIDKLIENT_DRG_ADVCUSTT=DocTIDKLIENT_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocTIDBASE_DRG_ADVCUSTT(void)
{
return Object->DocTIDBASE_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocTIDBASE_DRG_ADVCUSTT(TFIBLargeIntField * DocTIDBASE_DRG_ADVCUSTT)
{
Object->DocTIDBASE_DRG_ADVCUSTT=DocTIDBASE_DRG_ADVCUSTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegAdvCustImpl::get_DocTNAMEFIRM(void)
{
return Object->DocTNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM)
{
Object->DocTNAMEFIRM=DocTNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegAdvCustImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegAdvCustImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegAdvCustImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegAdvCustImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegAdvCustImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegAdvCustImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
__int64 TDMDocRegAdvCustImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocRegAdvCustImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocRegAdvCustImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocRegAdvCustImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocRegAdvCustImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRegAdvCustImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRegAdvCustImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TDMDocRegAdvCustImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRegAdvCustImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TDMDocRegAdvCustImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
int TDMDocRegAdvCustImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
