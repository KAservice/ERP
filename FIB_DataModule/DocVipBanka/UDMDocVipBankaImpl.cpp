#include "vcl.h"
#pragma hdrstop


#include "UDMDocVipBankaImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocVipBankaImpl::TDMDocVipBankaImpl()           
{                                            
Object=new TDMDocVipBanka(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocVipBankaImpl::~TDMDocVipBankaImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocVipBankaImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocVipBankaImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocVipBanka)                        
   {                                                                     
   *ppv=static_cast<IDMDocVipBanka*> (this);                                
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
int TDMDocVipBankaImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocVipBankaImpl::kanRelease(void)                                  
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
int  TDMDocVipBankaImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocVipBankaImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocVipBankaImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocVipBankaImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocVipBankaImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocVipBanka
TDataSource * TDMDocVipBankaImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocVipBankaImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocVipBankaImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVipBankaImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVipBankaImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVipBankaImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocVipBankaImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocVipBankaImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocVipBankaImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVipBankaImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocVipBankaImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocVipBankaImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocVipBankaImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllIDDOC(TFIBBCDField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocVipBankaImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocVipBankaImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVipBankaImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllIDFIRMDOC(TFIBBCDField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllIDSKLDOC(TFIBBCDField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllIDKLDOC(TFIBBCDField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllIDDOGDOC(TFIBBCDField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllIDDOCOSNDOC(TFIBBCDField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TIntegerField * TDMDocVipBankaImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocID_DVIPBANK(void)
{
return Object->DocID_DVIPBANK;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocID_DVIPBANK(TFIBBCDField * DocID_DVIPBANK)
{
Object->DocID_DVIPBANK=DocID_DVIPBANK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocIDDOC_DVIPBANK(void)
{
return Object->DocIDDOC_DVIPBANK;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocIDDOC_DVIPBANK(TFIBBCDField * DocIDDOC_DVIPBANK)
{
Object->DocIDDOC_DVIPBANK=DocIDDOC_DVIPBANK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocIDBASE_DVIPBANK(void)
{
return Object->DocIDBASE_DVIPBANK;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocIDBASE_DVIPBANK(TFIBBCDField * DocIDBASE_DVIPBANK)
{
Object->DocIDBASE_DVIPBANK=DocIDBASE_DVIPBANK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocIDBSCHET_DVIPBANK(void)
{
return Object->DocIDBSCHET_DVIPBANK;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocIDBSCHET_DVIPBANK(TFIBBCDField * DocIDBSCHET_DVIPBANK)
{
Object->DocIDBSCHET_DVIPBANK=DocIDBSCHET_DVIPBANK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocTID_DVIPBANKT(void)
{
return Object->DocTID_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTID_DVIPBANKT(TFIBBCDField * DocTID_DVIPBANKT)
{
Object->DocTID_DVIPBANKT=DocTID_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocTIDBASE_DVIPBANKT(void)
{
return Object->DocTIDBASE_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTIDBASE_DVIPBANKT(TFIBBCDField * DocTIDBASE_DVIPBANKT)
{
Object->DocTIDBASE_DVIPBANKT=DocTIDBASE_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocTIDDOC_DVIPBANKT(void)
{
return Object->DocTIDDOC_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTIDDOC_DVIPBANKT(TFIBBCDField * DocTIDDOC_DVIPBANKT)
{
Object->DocTIDDOC_DVIPBANKT=DocTIDDOC_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocTIDKLIENT_DVIPBANKT(void)
{
return Object->DocTIDKLIENT_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTIDKLIENT_DVIPBANKT(TFIBBCDField * DocTIDKLIENT_DVIPBANKT)
{
Object->DocTIDKLIENT_DVIPBANKT=DocTIDKLIENT_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBDateField * TDMDocVipBankaImpl::get_DocTDATEPP_DVIPBANKT(void)
{
return Object->DocTDATEPP_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTDATEPP_DVIPBANKT(TFIBDateField * DocTDATEPP_DVIPBANKT)
{
Object->DocTDATEPP_DVIPBANKT=DocTDATEPP_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocTPRIHOD_DVIPBANKT(void)
{
return Object->DocTPRIHOD_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTPRIHOD_DVIPBANKT(TFIBBCDField * DocTPRIHOD_DVIPBANKT)
{
Object->DocTPRIHOD_DVIPBANKT=DocTPRIHOD_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVipBankaImpl::get_DocTPRIHODNDS_DVIPBANKT(void)
{
return Object->DocTPRIHODNDS_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTPRIHODNDS_DVIPBANKT(TFIBIntegerField * DocTPRIHODNDS_DVIPBANKT)
{
Object->DocTPRIHODNDS_DVIPBANKT=DocTPRIHODNDS_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocTPRIHODSUMNDS_DVIPBANKT(void)
{
return Object->DocTPRIHODSUMNDS_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTPRIHODSUMNDS_DVIPBANKT(TFIBBCDField * DocTPRIHODSUMNDS_DVIPBANKT)
{
Object->DocTPRIHODSUMNDS_DVIPBANKT=DocTPRIHODSUMNDS_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocTRASHOD_DVIPBANKT(void)
{
return Object->DocTRASHOD_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTRASHOD_DVIPBANKT(TFIBBCDField * DocTRASHOD_DVIPBANKT)
{
Object->DocTRASHOD_DVIPBANKT=DocTRASHOD_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVipBankaImpl::get_DocTRASHODNDS_DVIPBANKT(void)
{
return Object->DocTRASHODNDS_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTRASHODNDS_DVIPBANKT(TFIBIntegerField * DocTRASHODNDS_DVIPBANKT)
{
Object->DocTRASHODNDS_DVIPBANKT=DocTRASHODNDS_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocTRASHODSUMNDS_DVIPBANKT(void)
{
return Object->DocTRASHODSUMNDS_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTRASHODSUMNDS_DVIPBANKT(TFIBBCDField * DocTRASHODSUMNDS_DVIPBANKT)
{
Object->DocTRASHODSUMNDS_DVIPBANKT=DocTRASHODSUMNDS_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVipBankaImpl::get_DocTOPER_DVIPBANKT(void)
{
return Object->DocTOPER_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTOPER_DVIPBANKT(TFIBIntegerField * DocTOPER_DVIPBANKT)
{
Object->DocTOPER_DVIPBANKT=DocTOPER_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVipBankaImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocPRIM_DVIPBANK(void)
{
return Object->DocPRIM_DVIPBANK;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocPRIM_DVIPBANK(TFIBWideStringField * DocPRIM_DVIPBANK)
{
Object->DocPRIM_DVIPBANK=DocPRIM_DVIPBANK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocNAMEBSCHET(void)
{
return Object->DocNAMEBSCHET;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)
{
Object->DocNAMEBSCHET=DocNAMEBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocTNUMPP_DVIPBANKT(void)
{
return Object->DocTNUMPP_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTNUMPP_DVIPBANKT(TFIBWideStringField * DocTNUMPP_DVIPBANKT)
{
Object->DocTNUMPP_DVIPBANKT=DocTNUMPP_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocTTEXTPP_DVIPBANKT(void)
{
return Object->DocTTEXTPP_DVIPBANKT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTTEXTPP_DVIPBANKT(TFIBWideStringField * DocTTEXTPP_DVIPBANKT)
{
Object->DocTTEXTPP_DVIPBANKT=DocTTEXTPP_DVIPBANKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllIDPROJECT_GALLDOC(TFIBBCDField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipBankaImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBBCDField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipBankaImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
__int64 TDMDocVipBankaImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocVipBankaImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocVipBankaImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocVipBankaImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocVipBankaImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocVipBankaImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocVipBankaImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TDMDocVipBankaImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocVipBankaImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TDMDocVipBankaImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
int TDMDocVipBankaImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
