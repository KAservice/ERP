#include "vcl.h"
#pragma hdrstop


#include "UDMDocPrihNaklImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocPrihNaklImpl::TDMDocPrihNaklImpl()           
{                                            
Object=new TDMDocPrihNakl(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocPrihNaklImpl::~TDMDocPrihNaklImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocPrihNaklImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocPrihNakl)                        
   {                                                                     
   *ppv=static_cast<IDMDocPrihNakl*> (this);                                
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
int TDMDocPrihNaklImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocPrihNaklImpl::kanRelease(void)                                  
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
int  TDMDocPrihNaklImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocPrihNaklImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocPrihNaklImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocPrihNaklImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocPrihNaklImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocPrihNakl
TDataSource * TDMDocPrihNaklImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocPrihNaklImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocPrihNaklImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPrihNaklImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPrihNaklImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPrihNaklImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPrihNaklImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPrihNaklImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocPrihNaklImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocPrihNaklImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPrihNaklImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPrihNaklImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPrihNaklImpl::get_DocTKOLPRNT(void)
{
return Object->DocTKOLPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTKOLPRNT(TFIBBCDField * DocTKOLPRNT)
{
Object->DocTKOLPRNT=DocTKOLPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPrihNaklImpl::get_DocTKFPRNT(void)
{
return Object->DocTKFPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTKFPRNT(TFIBBCDField * DocTKFPRNT)
{
Object->DocTKFPRNT=DocTKFPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPrihNaklImpl::get_DocTPRICEPRNT(void)
{
return Object->DocTPRICEPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTPRICEPRNT(TFIBBCDField * DocTPRICEPRNT)
{
Object->DocTPRICEPRNT=DocTPRICEPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPrihNaklImpl::get_DocTSUMPRNT(void)
{
return Object->DocTSUMPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTSUMPRNT(TFIBBCDField * DocTSUMPRNT)
{
Object->DocTSUMPRNT=DocTSUMPRNT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPrihNaklImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TIntegerField * TDMDocPrihNaklImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPrihNaklImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPrihNaklImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPrihNaklImpl::get_DocTNAC_DPRNT(void)
{
return Object->DocTNAC_DPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTNAC_DPRNT(TFIBBCDField * DocTNAC_DPRNT)
{
Object->DocTNAC_DPRNT=DocTNAC_DPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPrihNaklImpl::get_DocTRPRICE_DPRNT(void)
{
return Object->DocTRPRICE_DPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTRPRICE_DPRNT(TFIBBCDField * DocTRPRICE_DPRNT)
{
Object->DocTRPRICE_DPRNT=DocTRPRICE_DPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPrihNaklImpl::get_DocTRSUM_DPRNT(void)
{
return Object->DocTRSUM_DPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTRSUM_DPRNT(TFIBBCDField * DocTRSUM_DPRNT)
{
Object->DocTRSUM_DPRNT=DocTRSUM_DPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPrihNaklImpl::get_DocRSUM_DPRN(void)
{
return Object->DocRSUM_DPRN;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocRSUM_DPRN(TFIBBCDField * DocRSUM_DPRN)
{
Object->DocRSUM_DPRN=DocRSUM_DPRN;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocPrihNaklImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocPrihNaklImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocPrihNaklImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocPrihNaklImpl::get_DocPOSDOCPOST_DPRN(void)
{
return Object->DocPOSDOCPOST_DPRN;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocPOSDOCPOST_DPRN(TFIBDateTimeField * DocPOSDOCPOST_DPRN)
{
Object->DocPOSDOCPOST_DPRN=DocPOSDOCPOST_DPRN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPrihNaklImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocIDPRN(void)
{
return Object->DocIDPRN;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocIDPRN(TFIBLargeIntField * DocIDPRN)
{
Object->DocIDPRN=DocIDPRN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocIDDOCPRN(void)
{
return Object->DocIDDOCPRN;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocIDDOCPRN(TFIBLargeIntField * DocIDDOCPRN)
{
Object->DocIDDOCPRN=DocIDDOCPRN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocPRIMDOC(void)
{
return Object->DocPRIMDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocPRIMDOC(TFIBWideStringField * DocPRIMDOC)
{
Object->DocPRIMDOC=DocPRIMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocIDTPRICE(void)
{
return Object->DocIDTPRICE;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocIDTPRICE(TFIBLargeIntField * DocIDTPRICE)
{
Object->DocIDTPRICE=DocIDTPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocGID_DPRN(void)
{
return Object->DocGID_DPRN;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocGID_DPRN(TFIBWideStringField * DocGID_DPRN)
{
Object->DocGID_DPRN=DocGID_DPRN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocIDRTPRICE_DPRN(void)
{
return Object->DocIDRTPRICE_DPRN;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocIDRTPRICE_DPRN(TFIBLargeIntField * DocIDRTPRICE_DPRN)
{
Object->DocIDRTPRICE_DPRN=DocIDRTPRICE_DPRN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocIDBASE_DPRN(void)
{
return Object->DocIDBASE_DPRN;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocIDBASE_DPRN(TFIBLargeIntField * DocIDBASE_DPRN)
{
Object->DocIDBASE_DPRN=DocIDBASE_DPRN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocTIDPRNT(void)
{
return Object->DocTIDPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTIDPRNT(TFIBLargeIntField * DocTIDPRNT)
{
Object->DocTIDPRNT=DocTIDPRNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocTIDDOCPRNT(void)
{
return Object->DocTIDDOCPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTIDDOCPRNT(TFIBLargeIntField * DocTIDDOCPRNT)
{
Object->DocTIDDOCPRNT=DocTIDDOCPRNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocTIDNOMPRNT(void)
{
return Object->DocTIDNOMPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTIDNOMPRNT(TFIBLargeIntField * DocTIDNOMPRNT)
{
Object->DocTIDNOMPRNT=DocTIDNOMPRNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocTIDEDPRNT(void)
{
return Object->DocTIDEDPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTIDEDPRNT(TFIBLargeIntField * DocTIDEDPRNT)
{
Object->DocTIDEDPRNT=DocTIDEDPRNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocTIDPARTPRNT(void)
{
return Object->DocTIDPARTPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTIDPARTPRNT(TFIBLargeIntField * DocTIDPARTPRNT)
{
Object->DocTIDPARTPRNT=DocTIDPARTPRNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocTGID_DPRNT(void)
{
return Object->DocTGID_DPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTGID_DPRNT(TFIBWideStringField * DocTGID_DPRNT)
{
Object->DocTGID_DPRNT=DocTGID_DPRNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocTIDBASE_DPRNT(void)
{
return Object->DocTIDBASE_DPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTIDBASE_DPRNT(TFIBLargeIntField * DocTIDBASE_DPRNT)
{
Object->DocTIDBASE_DPRNT=DocTIDBASE_DPRNT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPrihNaklImpl::get_DocTNDS_DPRNT(void)
{
return Object->DocTNDS_DPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTNDS_DPRNT(TFIBIntegerField * DocTNDS_DPRNT)
{
Object->DocTNDS_DPRNT=DocTNDS_DPRNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPrihNaklImpl::get_DocTSUMNDS_DPRNT(void)
{
return Object->DocTSUMNDS_DPRNT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTSUMNDS_DPRNT(TFIBBCDField * DocTSUMNDS_DPRNT)
{
Object->DocTSUMNDS_DPRNT=DocTSUMNDS_DPRNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocTGTDPART(void)
{
return Object->DocTGTDPART;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTGTDPART(TFIBWideStringField * DocTGTDPART)
{
Object->DocTGTDPART=DocTGTDPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocTSERTPART(void)
{
return Object->DocTSERTPART;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTSERTPART(TFIBWideStringField * DocTSERTPART)
{
Object->DocTSERTPART=DocTSERTPART;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocPrihNaklImpl::get_DocTSRGODNPART(void)
{
return Object->DocTSRGODNPART;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTSRGODNPART(TFIBDateTimeField * DocTSRGODNPART)
{
Object->DocTSRGODNPART=DocTSRGODNPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocNUMDOCPOST_DPRN(void)
{
return Object->DocNUMDOCPOST_DPRN;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocNUMDOCPOST_DPRN(TFIBWideStringField * DocNUMDOCPOST_DPRN)
{
Object->DocNUMDOCPOST_DPRN=DocNUMDOCPOST_DPRN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPrihNaklImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPrihNaklImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPrihNaklImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPrihNaklImpl::get_DocTNAC_SUM_ED(void)
{
return Object->DocTNAC_SUM_ED;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTNAC_SUM_ED(TFIBBCDField * DocTNAC_SUM_ED)
{
Object->DocTNAC_SUM_ED=DocTNAC_SUM_ED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPrihNaklImpl::get_DocTNAC_SUM(void)
{
return Object->DocTNAC_SUM;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_DocTNAC_SUM(TFIBBCDField * DocTNAC_SUM)
{
Object->DocTNAC_SUM=DocTNAC_SUM;
}
//---------------------------------------------------------------
bool TDMDocPrihNaklImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocPrihNaklImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMDocPrihNaklImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TDMDocPrihNaklImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
__int64 TDMDocPrihNaklImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
bool TDMDocPrihNaklImpl::get_IsmPrice(void)
{
return Object->IsmPrice;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_IsmPrice(bool IsmPrice)
{
Object->IsmPrice=IsmPrice;
}
//---------------------------------------------------------------
bool TDMDocPrihNaklImpl::get_IsmSum(void)
{
return Object->IsmSum;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_IsmSum(bool IsmSum)
{
Object->IsmSum=IsmSum;
}
//---------------------------------------------------------------
bool TDMDocPrihNaklImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocPrihNaklImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::CopyDoc(__int64 id_doc)
{
return Object->CopyDoc(id_doc);
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TDMDocPrihNaklImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocPrihNaklImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocPrihNaklImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TDMDocPrihNaklImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
double TDMDocPrihNaklImpl::Summa(void)
{
return Object->Summa();
}
//---------------------------------------------------------------
void TDMDocPrihNaklImpl::CreateNewPart(void)
{
return Object->CreateNewPart();
}
//---------------------------------------------------------------
__int64 TDMDocPrihNaklImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc,date_doc);
}
//---------------------------------------------------------------
bool TDMDocPrihNaklImpl::UpdatePrice(void)
{
return Object->UpdatePrice();
}
//---------------------------------------------------------------
int TDMDocPrihNaklImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
