#include "vcl.h"
#pragma hdrstop


#include "UDMDocSchetImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocSchetImpl::TDMDocSchetImpl()           
{                                            
Object=new TDMDocSchet(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocSchetImpl::~TDMDocSchetImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocSchetImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocSchetImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocSchet)                        
   {                                                                     
   *ppv=static_cast<IDMDocSchet*> (this);                                
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
int TDMDocSchetImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocSchetImpl::kanRelease(void)                                  
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
int  TDMDocSchetImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocSchetImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocSchetImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocSchetImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocSchetImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocSchetImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocSchetImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocSchet
TDataSource * TDMDocSchetImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TDataSource * TDMDocSchetImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocSchetImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSchetImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSchetImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSchetImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSchetImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSchetImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocSchetImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocSchetImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSchetImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTKOLSCHT(void)
{
return Object->DocTKOLSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTKOLSCHT(TFIBBCDField * DocTKOLSCHT)
{
Object->DocTKOLSCHT=DocTKOLSCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTKFSCHT(void)
{
return Object->DocTKFSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTKFSCHT(TFIBBCDField * DocTKFSCHT)
{
Object->DocTKFSCHT=DocTKFSCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTPRICESCHT(void)
{
return Object->DocTPRICESCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTPRICESCHT(TFIBBCDField * DocTPRICESCHT)
{
Object->DocTPRICESCHT=DocTPRICESCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTSUMSCHT(void)
{
return Object->DocTSUMSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTSUMSCHT(TFIBBCDField * DocTSUMSCHT)
{
Object->DocTSUMSCHT=DocTSUMSCHT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSchetImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSchetImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSchetImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TIntegerField * TDMDocSchetImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSchetImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSchetImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSchetImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllIDDOC(TFIBBCDField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllIDFIRMDOC(TFIBBCDField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllIDSKLDOC(TFIBBCDField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllIDKLDOC(TFIBBCDField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllIDDOGDOC(TFIBBCDField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllIDDOCOSNDOC(TFIBBCDField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocIDSCH(void)
{
return Object->DocIDSCH;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocIDSCH(TFIBBCDField * DocIDSCH)
{
Object->DocIDSCH=DocIDSCH;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocIDDOCSCH(void)
{
return Object->DocIDDOCSCH;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocIDDOCSCH(TFIBBCDField * DocIDDOCSCH)
{
Object->DocIDDOCSCH=DocIDDOCSCH;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocIDBSCHET_DSCH(void)
{
return Object->DocIDBSCHET_DSCH;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocIDBSCHET_DSCH(TFIBBCDField * DocIDBSCHET_DSCH)
{
Object->DocIDBSCHET_DSCH=DocIDBSCHET_DSCH;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocIDTPRICESCH(void)
{
return Object->DocIDTPRICESCH;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocIDTPRICESCH(TFIBBCDField * DocIDTPRICESCH)
{
Object->DocIDTPRICESCH=DocIDTPRICESCH;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTIDSCHT(void)
{
return Object->DocTIDSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTIDSCHT(TFIBBCDField * DocTIDSCHT)
{
Object->DocTIDSCHT=DocTIDSCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTIDDOCSCHT(void)
{
return Object->DocTIDDOCSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTIDDOCSCHT(TFIBBCDField * DocTIDDOCSCHT)
{
Object->DocTIDDOCSCHT=DocTIDDOCSCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTIDNOMSCHT(void)
{
return Object->DocTIDNOMSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTIDNOMSCHT(TFIBBCDField * DocTIDNOMSCHT)
{
Object->DocTIDNOMSCHT=DocTIDNOMSCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTIDEDSCHT(void)
{
return Object->DocTIDEDSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTIDEDSCHT(TFIBBCDField * DocTIDEDSCHT)
{
Object->DocTIDEDSCHT=DocTIDEDSCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSchetImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocIDBASE_DSCH(void)
{
return Object->DocIDBASE_DSCH;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocIDBASE_DSCH(TFIBBCDField * DocIDBASE_DSCH)
{
Object->DocIDBASE_DSCH=DocIDBASE_DSCH;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTIDBASE_DSCHT(void)
{
return Object->DocTIDBASE_DSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTIDBASE_DSCHT(TFIBBCDField * DocTIDBASE_DSCHT)
{
Object->DocTIDBASE_DSCHT=DocTIDBASE_DSCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSchetImpl::get_DocTNDS_DSCHT(void)
{
return Object->DocTNDS_DSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTNDS_DSCHT(TFIBIntegerField * DocTNDS_DSCHT)
{
Object->DocTNDS_DSCHT=DocTNDS_DSCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTSUMNDS_DSCHT(void)
{
return Object->DocTSUMNDS_DSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTSUMNDS_DSCHT(TFIBBCDField * DocTSUMNDS_DSCHT)
{
Object->DocTSUMNDS_DSCHT=DocTSUMNDS_DSCHT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSchetImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocPRIMSCH(void)
{
return Object->DocPRIMSCH;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocPRIMSCH(TFIBWideStringField * DocPRIMSCH)
{
Object->DocPRIMSCH=DocPRIMSCH;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocGID_DSCH(void)
{
return Object->DocGID_DSCH;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocGID_DSCH(TFIBWideStringField * DocGID_DSCH)
{
Object->DocGID_DSCH=DocGID_DSCH;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocNAME_TPRICE(void)
{
return Object->DocNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)
{
Object->DocNAME_TPRICE=DocNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocNAMEBSCHET(void)
{
return Object->DocNAMEBSCHET;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)
{
Object->DocNAMEBSCHET=DocNAMEBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocTGID_DSCHT(void)
{
return Object->DocTGID_DSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTGID_DSCHT(TFIBWideStringField * DocTGID_DSCHT)
{
Object->DocTGID_DSCHT=DocTGID_DSCHT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllIDPROJECT_GALLDOC(TFIBBCDField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBBCDField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTSUMSK_DSCHT(void)
{
return Object->DocTSUMSK_DSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTSUMSK_DSCHT(TFIBBCDField * DocTSUMSK_DSCHT)
{
Object->DocTSUMSK_DSCHT=DocTSUMSK_DSCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTPRSK_DSCHT(void)
{
return Object->DocTPRSK_DSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTPRSK_DSCHT(TFIBBCDField * DocTPRSK_DSCHT)
{
Object->DocTPRSK_DSCHT=DocTPRSK_DSCHT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocSchetImpl::get_DocTNO_SK_DSCHT(void)
{
return Object->DocTNO_SK_DSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTNO_SK_DSCHT(TFIBSmallIntField * DocTNO_SK_DSCHT)
{
Object->DocTNO_SK_DSCHT=DocTNO_SK_DSCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTPRSK_CARD_DSCHT(void)
{
return Object->DocTPRSK_CARD_DSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTPRSK_CARD_DSCHT(TFIBBCDField * DocTPRSK_CARD_DSCHT)
{
Object->DocTPRSK_CARD_DSCHT=DocTPRSK_CARD_DSCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTPRSK_AUTO_DSCHT(void)
{
return Object->DocTPRSK_AUTO_DSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTPRSK_AUTO_DSCHT(TFIBBCDField * DocTPRSK_AUTO_DSCHT)
{
Object->DocTPRSK_AUTO_DSCHT=DocTPRSK_AUTO_DSCHT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetImpl::get_DocTPRSK_HAND_DSCHT(void)
{
return Object->DocTPRSK_HAND_DSCHT;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTPRSK_HAND_DSCHT(TFIBBCDField * DocTPRSK_HAND_DSCHT)
{
Object->DocTPRSK_HAND_DSCHT=DocTPRSK_HAND_DSCHT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSchetImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
bool TDMDocSchetImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocSchetImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocSchetImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocSchetImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocSchetImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocSchetImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocSchetImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
void TDMDocSchetImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocSchetImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocSchetImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocSchetImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocSchetImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TDMDocSchetImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
int TDMDocSchetImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
