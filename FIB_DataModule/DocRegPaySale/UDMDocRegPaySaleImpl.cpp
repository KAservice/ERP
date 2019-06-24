#include "vcl.h"
#pragma hdrstop


#include "UDMDocRegPaySaleImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRegPaySaleImpl::TDMDocRegPaySaleImpl()           
{                                            
Object=new TDMDocRegPaySale(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRegPaySaleImpl::~TDMDocRegPaySaleImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRegPaySaleImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRegPaySale)                        
   {                                                                     
   *ppv=static_cast<IDMDocRegPaySale*> (this);                                
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
int TDMDocRegPaySaleImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRegPaySaleImpl::kanRelease(void)                                  
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
int  TDMDocRegPaySaleImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRegPaySaleImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRegPaySaleImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRegPaySaleImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRegPaySaleImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRegPaySale
TDataSource * TDMDocRegPaySaleImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegPaySaleImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegPaySaleImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegPaySaleImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegPaySaleImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegPaySaleImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegPaySaleImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegPaySaleImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegPaySaleImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegPaySaleImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegPaySaleImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegPaySaleImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegPaySaleImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRegPaySaleImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegPaySaleImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegPaySaleImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegPaySaleImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRegPaySaleImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegPaySaleImpl::get_DocTTDV_DRG_PAYSALET(void)
{
return Object->DocTTDV_DRG_PAYSALET;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTTDV_DRG_PAYSALET(TFIBSmallIntField * DocTTDV_DRG_PAYSALET)
{
Object->DocTTDV_DRG_PAYSALET=DocTTDV_DRG_PAYSALET;
}
//---------------------------------------------------------------
TFIBDateField * TDMDocRegPaySaleImpl::get_DocTDATE_DRG_PAYSALET(void)
{
return Object->DocTDATE_DRG_PAYSALET;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTDATE_DRG_PAYSALET(TFIBDateField * DocTDATE_DRG_PAYSALET)
{
Object->DocTDATE_DRG_PAYSALET=DocTDATE_DRG_PAYSALET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegPaySaleImpl::get_DocTSUM_DRG_PAYSALET(void)
{
return Object->DocTSUM_DRG_PAYSALET;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTSUM_DRG_PAYSALET(TFIBBCDField * DocTSUM_DRG_PAYSALET)
{
Object->DocTSUM_DRG_PAYSALET=DocTSUM_DRG_PAYSALET;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRegPaySaleImpl::get_DocTPOSDOC(void)
{
return Object->DocTPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTPOSDOC(TFIBDateTimeField * DocTPOSDOC)
{
Object->DocTPOSDOC=DocTPOSDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegPaySaleImpl::get_DocTNUMDOC(void)
{
return Object->DocTNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTNUMDOC(TFIBIntegerField * DocTNUMDOC)
{
Object->DocTNUMDOC=DocTNUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegPaySaleImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocID_DRG_PAYSALE(void)
{
return Object->DocID_DRG_PAYSALE;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocID_DRG_PAYSALE(TFIBLargeIntField * DocID_DRG_PAYSALE)
{
Object->DocID_DRG_PAYSALE=DocID_DRG_PAYSALE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocIDDOC_DRG_PAYSALE(void)
{
return Object->DocIDDOC_DRG_PAYSALE;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocIDDOC_DRG_PAYSALE(TFIBLargeIntField * DocIDDOC_DRG_PAYSALE)
{
Object->DocIDDOC_DRG_PAYSALE=DocIDDOC_DRG_PAYSALE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocDESCR_DRG_PAYSALE(void)
{
return Object->DocDESCR_DRG_PAYSALE;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocDESCR_DRG_PAYSALE(TFIBWideStringField * DocDESCR_DRG_PAYSALE)
{
Object->DocDESCR_DRG_PAYSALE=DocDESCR_DRG_PAYSALE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocIDBASE_DRG_PAYSALE(void)
{
return Object->DocIDBASE_DRG_PAYSALE;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocIDBASE_DRG_PAYSALE(TFIBLargeIntField * DocIDBASE_DRG_PAYSALE)
{
Object->DocIDBASE_DRG_PAYSALE=DocIDBASE_DRG_PAYSALE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocTID_DRG_PAYSALET(void)
{
return Object->DocTID_DRG_PAYSALET;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTID_DRG_PAYSALET(TFIBLargeIntField * DocTID_DRG_PAYSALET)
{
Object->DocTID_DRG_PAYSALET=DocTID_DRG_PAYSALET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocTIDDOC_DRG_PAYSALET(void)
{
return Object->DocTIDDOC_DRG_PAYSALET;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTIDDOC_DRG_PAYSALET(TFIBLargeIntField * DocTIDDOC_DRG_PAYSALET)
{
Object->DocTIDDOC_DRG_PAYSALET=DocTIDDOC_DRG_PAYSALET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocTIDFIRM_DRG_PAYSALET(void)
{
return Object->DocTIDFIRM_DRG_PAYSALET;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTIDFIRM_DRG_PAYSALET(TFIBLargeIntField * DocTIDFIRM_DRG_PAYSALET)
{
Object->DocTIDFIRM_DRG_PAYSALET=DocTIDFIRM_DRG_PAYSALET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocTIDKLIENT_DRG_PAYSALET(void)
{
return Object->DocTIDKLIENT_DRG_PAYSALET;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTIDKLIENT_DRG_PAYSALET(TFIBLargeIntField * DocTIDKLIENT_DRG_PAYSALET)
{
Object->DocTIDKLIENT_DRG_PAYSALET=DocTIDKLIENT_DRG_PAYSALET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocTIDDOG_DRG_PAYSALET(void)
{
return Object->DocTIDDOG_DRG_PAYSALET;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTIDDOG_DRG_PAYSALET(TFIBLargeIntField * DocTIDDOG_DRG_PAYSALET)
{
Object->DocTIDDOG_DRG_PAYSALET=DocTIDDOG_DRG_PAYSALET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocTIDDOCSALE_DRG_PAYSALET(void)
{
return Object->DocTIDDOCSALE_DRG_PAYSALET;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTIDDOCSALE_DRG_PAYSALET(TFIBLargeIntField * DocTIDDOCSALE_DRG_PAYSALET)
{
Object->DocTIDDOCSALE_DRG_PAYSALET=DocTIDDOCSALE_DRG_PAYSALET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocTIDBASE_DRG_PAYSALET(void)
{
return Object->DocTIDBASE_DRG_PAYSALET;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTIDBASE_DRG_PAYSALET(TFIBLargeIntField * DocTIDBASE_DRG_PAYSALET)
{
Object->DocTIDBASE_DRG_PAYSALET=DocTIDBASE_DRG_PAYSALET;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegPaySaleImpl::get_DocTOPER_DRG_PAYSALET(void)
{
return Object->DocTOPER_DRG_PAYSALET;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTOPER_DRG_PAYSALET(TFIBIntegerField * DocTOPER_DRG_PAYSALET)
{
Object->DocTOPER_DRG_PAYSALET=DocTOPER_DRG_PAYSALET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocTNAMEFIRM(void)
{
return Object->DocTNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM)
{
Object->DocTNAMEFIRM=DocTNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocTNAME_SDOG(void)
{
return Object->DocTNAME_SDOG;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTNAME_SDOG(TFIBWideStringField * DocTNAME_SDOG)
{
Object->DocTNAME_SDOG=DocTNAME_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocTTDOC(void)
{
return Object->DocTTDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocTTDOC(TFIBWideStringField * DocTTDOC)
{
Object->DocTTDOC=DocTTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegPaySaleImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegPaySaleImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
__int64 TDMDocRegPaySaleImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocRegPaySaleImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocRegPaySaleImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocRegPaySaleImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocRegPaySaleImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRegPaySaleImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRegPaySaleImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TDMDocRegPaySaleImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRegPaySaleImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TDMDocRegPaySaleImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
int TDMDocRegPaySaleImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
