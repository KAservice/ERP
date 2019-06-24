#include "vcl.h"
#pragma hdrstop


#include "UDMDocPerImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocPerImpl::TDMDocPerImpl()           
{                                            
Object=new TDMDocPer(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocPerImpl::~TDMDocPerImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocPerImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocPerImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocPer)                        
   {                                                                     
   *ppv=static_cast<IDMDocPer*> (this);                                
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
int TDMDocPerImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocPerImpl::kanRelease(void)                                  
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
int  TDMDocPerImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocPerImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocPerImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocPerImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocPerImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocPerImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocPerImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocPer
TDataSource * TDMDocPerImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocPerImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocPerImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPerImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPerImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPerImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPerImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPerImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocPerImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocPerImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPerImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPerImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPerImpl::get_DocTKOLPERT(void)
{
return Object->DocTKOLPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTKOLPERT(TFIBBCDField * DocTKOLPERT)
{
Object->DocTKOLPERT=DocTKOLPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPerImpl::get_DocTKFPERT(void)
{
return Object->DocTKFPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTKFPERT(TFIBBCDField * DocTKFPERT)
{
Object->DocTKFPERT=DocTKFPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPerImpl::get_DocTPRICEPERT(void)
{
return Object->DocTPRICEPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTPRICEPERT(TFIBBCDField * DocTPRICEPERT)
{
Object->DocTPRICEPERT=DocTPRICEPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPerImpl::get_DocTSUMPERT(void)
{
return Object->DocTSUMPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTSUMPERT(TFIBBCDField * DocTSUMPERT)
{
Object->DocTSUMPERT=DocTSUMPERT;
}
//---------------------------------------------------------------
TIntegerField * TDMDocPerImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPerImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPerImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPerImpl::get_Firma(void)
{
return Object->Firma;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_Firma(TpFIBDataSet * Firma)
{
Object->Firma=Firma;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPerImpl::get_Sklad(void)
{
return Object->Sklad;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_Sklad(TpFIBDataSet * Sklad)
{
Object->Sklad=Sklad;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPerImpl::get_SkladPol(void)
{
return Object->SkladPol;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_SkladPol(TpFIBDataSet * SkladPol)
{
Object->SkladPol=SkladPol;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocPerImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocPerImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocPerImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPerImpl::get_DocTNAC_DPERT(void)
{
return Object->DocTNAC_DPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTNAC_DPERT(TFIBBCDField * DocTNAC_DPERT)
{
Object->DocTNAC_DPERT=DocTNAC_DPERT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPerImpl::get_DocTNDS_DPERT(void)
{
return Object->DocTNDS_DPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTNDS_DPERT(TFIBIntegerField * DocTNDS_DPERT)
{
Object->DocTNDS_DPERT=DocTNDS_DPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPerImpl::get_DocTSUMNDS_DPERT(void)
{
return Object->DocTSUMNDS_DPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTSUMNDS_DPERT(TFIBBCDField * DocTSUMNDS_DPERT)
{
Object->DocTSUMNDS_DPERT=DocTSUMNDS_DPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_SkladPolIDSKLAD(void)
{
return Object->SkladPolIDSKLAD;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_SkladPolIDSKLAD(TFIBLargeIntField * SkladPolIDSKLAD)
{
Object->SkladPolIDSKLAD=SkladPolIDSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_SkladPolNAMESKLAD(void)
{
return Object->SkladPolNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_SkladPolNAMESKLAD(TFIBWideStringField * SkladPolNAMESKLAD)
{
Object->SkladPolNAMESKLAD=SkladPolNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_SkladPolMOLSKLAD(void)
{
return Object->SkladPolMOLSKLAD;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_SkladPolMOLSKLAD(TFIBWideStringField * SkladPolMOLSKLAD)
{
Object->SkladPolMOLSKLAD=SkladPolMOLSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_SkladPolADRSKLAD(void)
{
return Object->SkladPolADRSKLAD;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_SkladPolADRSKLAD(TFIBWideStringField * SkladPolADRSKLAD)
{
Object->SkladPolADRSKLAD=SkladPolADRSKLAD;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPerImpl::get_SkladPolTSKLAD(void)
{
return Object->SkladPolTSKLAD;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_SkladPolTSKLAD(TFIBIntegerField * SkladPolTSKLAD)
{
Object->SkladPolTSKLAD=SkladPolTSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_SkladPolGID_SSKLAD(void)
{
return Object->SkladPolGID_SSKLAD;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_SkladPolGID_SSKLAD(TFIBWideStringField * SkladPolGID_SSKLAD)
{
Object->SkladPolGID_SSKLAD=SkladPolGID_SSKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPerImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocIDPER(void)
{
return Object->DocIDPER;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocIDPER(TFIBLargeIntField * DocIDPER)
{
Object->DocIDPER=DocIDPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocIDDOCPER(void)
{
return Object->DocIDDOCPER;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocIDDOCPER(TFIBLargeIntField * DocIDDOCPER)
{
Object->DocIDDOCPER=DocIDDOCPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocIDSKLPOLPER(void)
{
return Object->DocIDSKLPOLPER;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocIDSKLPOLPER(TFIBLargeIntField * DocIDSKLPOLPER)
{
Object->DocIDSKLPOLPER=DocIDSKLPOLPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocPRIMPER(void)
{
return Object->DocPRIMPER;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocPRIMPER(TFIBWideStringField * DocPRIMPER)
{
Object->DocPRIMPER=DocPRIMPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocGID_DPER(void)
{
return Object->DocGID_DPER;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocGID_DPER(TFIBWideStringField * DocGID_DPER)
{
Object->DocGID_DPER=DocGID_DPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocIDRTPRICE_DPER(void)
{
return Object->DocIDRTPRICE_DPER;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocIDRTPRICE_DPER(TFIBLargeIntField * DocIDRTPRICE_DPER)
{
Object->DocIDRTPRICE_DPER=DocIDRTPRICE_DPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocIDBASE_DPER(void)
{
return Object->DocIDBASE_DPER;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocIDBASE_DPER(TFIBLargeIntField * DocIDBASE_DPER)
{
Object->DocIDBASE_DPER=DocIDBASE_DPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocNAMESKLAD(void)
{
return Object->DocNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocNAMESKLAD(TFIBWideStringField * DocNAMESKLAD)
{
Object->DocNAMESKLAD=DocNAMESKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocTIDPERT(void)
{
return Object->DocTIDPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTIDPERT(TFIBLargeIntField * DocTIDPERT)
{
Object->DocTIDPERT=DocTIDPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocTIDDOCPERT(void)
{
return Object->DocTIDDOCPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTIDDOCPERT(TFIBLargeIntField * DocTIDDOCPERT)
{
Object->DocTIDDOCPERT=DocTIDDOCPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocTIDNOMPERT(void)
{
return Object->DocTIDNOMPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTIDNOMPERT(TFIBLargeIntField * DocTIDNOMPERT)
{
Object->DocTIDNOMPERT=DocTIDNOMPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocTIDEDPERT(void)
{
return Object->DocTIDEDPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTIDEDPERT(TFIBLargeIntField * DocTIDEDPERT)
{
Object->DocTIDEDPERT=DocTIDEDPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocTGID_DPERT(void)
{
return Object->DocTGID_DPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTGID_DPERT(TFIBWideStringField * DocTGID_DPERT)
{
Object->DocTGID_DPERT=DocTGID_DPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocTIDBASE_DPERT(void)
{
return Object->DocTIDBASE_DPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTIDBASE_DPERT(TFIBLargeIntField * DocTIDBASE_DPERT)
{
Object->DocTIDBASE_DPERT=DocTIDBASE_DPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocPerImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTTNOM(TFIBSmallIntField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPerImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPerImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPerImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPerImpl::get_DocTSEB_PRICE_DPERT(void)
{
return Object->DocTSEB_PRICE_DPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTSEB_PRICE_DPERT(TFIBBCDField * DocTSEB_PRICE_DPERT)
{
Object->DocTSEB_PRICE_DPERT=DocTSEB_PRICE_DPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPerImpl::get_DocTSEB_SUM_DPERT(void)
{
return Object->DocTSEB_SUM_DPERT;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTSEB_SUM_DPERT(TFIBBCDField * DocTSEB_SUM_DPERT)
{
Object->DocTSEB_SUM_DPERT=DocTSEB_SUM_DPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPerImpl::get_DocTNAC_SUM_ED(void)
{
return Object->DocTNAC_SUM_ED;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTNAC_SUM_ED(TFIBBCDField * DocTNAC_SUM_ED)
{
Object->DocTNAC_SUM_ED=DocTNAC_SUM_ED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPerImpl::get_DocTNAC_SUM(void)
{
return Object->DocTNAC_SUM;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_DocTNAC_SUM(TFIBBCDField * DocTNAC_SUM)
{
Object->DocTNAC_SUM=DocTNAC_SUM;
}
//---------------------------------------------------------------
bool TDMDocPerImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocPerImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocPerImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMDocPerImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TDMDocPerImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
bool TDMDocPerImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocPerImpl::get_SkladPolRozn(void)
{
return Object->SkladPolRozn;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_SkladPolRozn(bool SkladPolRozn)
{
Object->SkladPolRozn=SkladPolRozn;
}
//---------------------------------------------------------------
bool TDMDocPerImpl::get_SkladOtprRozn(void)
{
return Object->SkladOtprRozn;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_SkladOtprRozn(bool SkladOtprRozn)
{
Object->SkladOtprRozn=SkladOtprRozn;
}
//---------------------------------------------------------------
bool TDMDocPerImpl::get_NoOtrOstatok(void)
{
return Object->NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMDocPerImpl::set_NoOtrOstatok(bool NoOtrOstatok)
{
Object->NoOtrOstatok=NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMDocPerImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocPerImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocPerImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocPerImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocPerImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocPerImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocPerImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TDMDocPerImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void TDMDocPerImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
__int64 TDMDocPerImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc, date_doc);
}
//---------------------------------------------------------------
int TDMDocPerImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
