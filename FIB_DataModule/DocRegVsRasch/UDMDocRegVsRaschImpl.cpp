#include "vcl.h"
#pragma hdrstop


#include "UDMDocRegVsRaschImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRegVsRaschImpl::TDMDocRegVsRaschImpl()           
{                                            
Object=new TDMDocRegVsRasch(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRegVsRaschImpl::~TDMDocRegVsRaschImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRegVsRaschImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRegVsRasch)                        
   {                                                                     
   *ppv=static_cast<IDMDocRegVsRasch*> (this);                                
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
int TDMDocRegVsRaschImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRegVsRaschImpl::kanRelease(void)                                  
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
int  TDMDocRegVsRaschImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRegVsRaschImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRegVsRaschImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRegVsRaschImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRegVsRaschImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRegVsRasch
TDataSource * TDMDocRegVsRaschImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegVsRaschImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegVsRaschImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegVsRaschImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegVsRaschImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegVsRaschImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegVsRaschImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegVsRaschImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegVsRaschImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegVsRaschImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegVsRaschImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegVsRaschImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegVsRaschImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRegVsRaschImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegVsRaschImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegVsRaschImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegVsRaschImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRegVsRaschImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegVsRaschImpl::get_DocTTDV_DRG_VSRASCHT(void)
{
return Object->DocTTDV_DRG_VSRASCHT;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocTTDV_DRG_VSRASCHT(TFIBSmallIntField * DocTTDV_DRG_VSRASCHT)
{
Object->DocTTDV_DRG_VSRASCHT=DocTTDV_DRG_VSRASCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegVsRaschImpl::get_DocTSUM_DRG_VSRASCHT(void)
{
return Object->DocTSUM_DRG_VSRASCHT;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocTSUM_DRG_VSRASCHT(TFIBBCDField * DocTSUM_DRG_VSRASCHT)
{
Object->DocTSUM_DRG_VSRASCHT=DocTSUM_DRG_VSRASCHT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegVsRaschImpl::get_DocTOPER_DRG_VSRASCHT(void)
{
return Object->DocTOPER_DRG_VSRASCHT;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocTOPER_DRG_VSRASCHT(TFIBIntegerField * DocTOPER_DRG_VSRASCHT)
{
Object->DocTOPER_DRG_VSRASCHT=DocTOPER_DRG_VSRASCHT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegVsRaschImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegVsRaschImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegVsRaschImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegVsRaschImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegVsRaschImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocID_DRG_VSRASCH(void)
{
return Object->DocID_DRG_VSRASCH;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocID_DRG_VSRASCH(TFIBLargeIntField * DocID_DRG_VSRASCH)
{
Object->DocID_DRG_VSRASCH=DocID_DRG_VSRASCH;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocIDDOC_DRG_VSRASCH(void)
{
return Object->DocIDDOC_DRG_VSRASCH;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocIDDOC_DRG_VSRASCH(TFIBLargeIntField * DocIDDOC_DRG_VSRASCH)
{
Object->DocIDDOC_DRG_VSRASCH=DocIDDOC_DRG_VSRASCH;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegVsRaschImpl::get_DocDESCR_DRG_VSRASCH(void)
{
return Object->DocDESCR_DRG_VSRASCH;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocDESCR_DRG_VSRASCH(TFIBWideStringField * DocDESCR_DRG_VSRASCH)
{
Object->DocDESCR_DRG_VSRASCH=DocDESCR_DRG_VSRASCH;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocIDBASE_DRG_VSRASCH(void)
{
return Object->DocIDBASE_DRG_VSRASCH;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocIDBASE_DRG_VSRASCH(TFIBLargeIntField * DocIDBASE_DRG_VSRASCH)
{
Object->DocIDBASE_DRG_VSRASCH=DocIDBASE_DRG_VSRASCH;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocTID_DRG_VSRASCHT(void)
{
return Object->DocTID_DRG_VSRASCHT;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocTID_DRG_VSRASCHT(TFIBLargeIntField * DocTID_DRG_VSRASCHT)
{
Object->DocTID_DRG_VSRASCHT=DocTID_DRG_VSRASCHT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocTIDDOC_DRG_VSRASCHT(void)
{
return Object->DocTIDDOC_DRG_VSRASCHT;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocTIDDOC_DRG_VSRASCHT(TFIBLargeIntField * DocTIDDOC_DRG_VSRASCHT)
{
Object->DocTIDDOC_DRG_VSRASCHT=DocTIDDOC_DRG_VSRASCHT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocTIDFIRM_DRG_VSRASCHT(void)
{
return Object->DocTIDFIRM_DRG_VSRASCHT;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocTIDFIRM_DRG_VSRASCHT(TFIBLargeIntField * DocTIDFIRM_DRG_VSRASCHT)
{
Object->DocTIDFIRM_DRG_VSRASCHT=DocTIDFIRM_DRG_VSRASCHT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocTIDKLIENT_DRG_VSRASCHT(void)
{
return Object->DocTIDKLIENT_DRG_VSRASCHT;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocTIDKLIENT_DRG_VSRASCHT(TFIBLargeIntField * DocTIDKLIENT_DRG_VSRASCHT)
{
Object->DocTIDKLIENT_DRG_VSRASCHT=DocTIDKLIENT_DRG_VSRASCHT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocTIDBASE_DRG_VSRASCHT(void)
{
return Object->DocTIDBASE_DRG_VSRASCHT;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocTIDBASE_DRG_VSRASCHT(TFIBLargeIntField * DocTIDBASE_DRG_VSRASCHT)
{
Object->DocTIDBASE_DRG_VSRASCHT=DocTIDBASE_DRG_VSRASCHT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegVsRaschImpl::get_DocTNAMEFIRM(void)
{
return Object->DocTNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM)
{
Object->DocTNAMEFIRM=DocTNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegVsRaschImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegVsRaschImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegVsRaschImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegVsRaschImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegVsRaschImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegVsRaschImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
__int64 TDMDocRegVsRaschImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocRegVsRaschImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocRegVsRaschImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocRegVsRaschImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocRegVsRaschImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRegVsRaschImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRegVsRaschImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TDMDocRegVsRaschImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRegVsRaschImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TDMDocRegVsRaschImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
int TDMDocRegVsRaschImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
