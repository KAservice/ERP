#include "vcl.h"
#pragma hdrstop


#include "UDMDocSpisNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocSpisNomImpl::TDMDocSpisNomImpl()           
{                                            
Object=new TDMDocSpisNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocSpisNomImpl::~TDMDocSpisNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocSpisNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocSpisNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocSpisNom)                        
   {                                                                     
   *ppv=static_cast<IDMDocSpisNom*> (this);                                
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
int TDMDocSpisNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocSpisNomImpl::kanRelease(void)                                  
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
int  TDMDocSpisNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocSpisNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocSpisNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocSpisNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocSpisNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocSpisNom
TDataSource * TDMDocSpisNomImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocSpisNomImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocSpisNomImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpisNomImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpisNomImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpisNomImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSpisNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSpisNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocSpisNomImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocSpisNomImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSpisNomImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocTKOLSPNT(void)
{
return Object->DocTKOLSPNT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTKOLSPNT(TFIBBCDField * DocTKOLSPNT)
{
Object->DocTKOLSPNT=DocTKOLSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocTKFSPNT(void)
{
return Object->DocTKFSPNT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTKFSPNT(TFIBBCDField * DocTKFSPNT)
{
Object->DocTKFSPNT=DocTKFSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocTPRICESPNT(void)
{
return Object->DocTPRICESPNT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTPRICESPNT(TFIBBCDField * DocTPRICESPNT)
{
Object->DocTPRICESPNT=DocTPRICESPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocTSUMSPNT(void)
{
return Object->DocTSUMSPNT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTSUMSPNT(TFIBBCDField * DocTSUMSPNT)
{
Object->DocTSUMSPNT=DocTSUMSPNT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSpisNomImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TIntegerField * TDMDocSpisNomImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSpisNomImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpisNomImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpisNomImpl::get_Grp(void)
{
return Object->Grp;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_Grp(TpFIBDataSet * Grp)
{
Object->Grp=Grp;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpisNomImpl::get_El(void)
{
return Object->El;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_El(TpFIBDataSet * El)
{
Object->El=El;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_GrpSUMMA(void)
{
return Object->GrpSUMMA;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_GrpSUMMA(TFIBBCDField * GrpSUMMA)
{
Object->GrpSUMMA=GrpSUMMA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_ElSUMMA(void)
{
return Object->ElSUMMA;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_ElSUMMA(TFIBBCDField * ElSUMMA)
{
Object->ElSUMMA=ElSUMMA;
}
//---------------------------------------------------------------
TFIBFloatField * TDMDocSpisNomImpl::get_ElSUMKOL(void)
{
return Object->ElSUMKOL;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_ElSUMKOL(TFIBFloatField * ElSUMKOL)
{
Object->ElSUMKOL=ElSUMKOL;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpisNomImpl::get_DocOsn(void)
{
return Object->DocOsn;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocOsn(TpFIBDataSet * DocOsn)
{
Object->DocOsn=DocOsn;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSpisNomImpl::get_DocOsnNUMDOC(void)
{
return Object->DocOsnNUMDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocOsnNUMDOC(TFIBIntegerField * DocOsnNUMDOC)
{
Object->DocOsnNUMDOC=DocOsnNUMDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocSpisNomImpl::get_DocOsnPOSDOC(void)
{
return Object->DocOsnPOSDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocOsnPOSDOC(TFIBDateTimeField * DocOsnPOSDOC)
{
Object->DocOsnPOSDOC=DocOsnPOSDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocRSUM_DSPN(void)
{
return Object->DocRSUM_DSPN;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocRSUM_DSPN(TFIBBCDField * DocRSUM_DSPN)
{
Object->DocRSUM_DSPN=DocRSUM_DSPN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocTRPRICE_DSPNT(void)
{
return Object->DocTRPRICE_DSPNT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTRPRICE_DSPNT(TFIBBCDField * DocTRPRICE_DSPNT)
{
Object->DocTRPRICE_DSPNT=DocTRPRICE_DSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocTRSUM_DSPNT(void)
{
return Object->DocTRSUM_DSPNT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTRSUM_DSPNT(TFIBBCDField * DocTRSUM_DSPNT)
{
Object->DocTRSUM_DSPNT=DocTRSUM_DSPNT;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSpisNomImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSpisNomImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSpisNomImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_GrpIDGN(void)
{
return Object->GrpIDGN;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_GrpIDGN(TFIBBCDField * GrpIDGN)
{
Object->GrpIDGN=GrpIDGN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllIDDOC(TFIBBCDField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllIDFIRMDOC(TFIBBCDField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllIDSKLDOC(TFIBBCDField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllIDKLDOC(TFIBBCDField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllIDDOGDOC(TFIBBCDField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllIDDOCOSNDOC(TFIBBCDField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocIDSPN(void)
{
return Object->DocIDSPN;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocIDSPN(TFIBBCDField * DocIDSPN)
{
Object->DocIDSPN=DocIDSPN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocIDDOCSPN(void)
{
return Object->DocIDDOCSPN;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocIDDOCSPN(TFIBBCDField * DocIDDOCSPN)
{
Object->DocIDDOCSPN=DocIDDOCSPN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocIDRTPRICE_DSPN(void)
{
return Object->DocIDRTPRICE_DSPN;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocIDRTPRICE_DSPN(TFIBBCDField * DocIDRTPRICE_DSPN)
{
Object->DocIDRTPRICE_DSPN=DocIDRTPRICE_DSPN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocTIDSPNT(void)
{
return Object->DocTIDSPNT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTIDSPNT(TFIBBCDField * DocTIDSPNT)
{
Object->DocTIDSPNT=DocTIDSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocTIDDOCSPNT(void)
{
return Object->DocTIDDOCSPNT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTIDDOCSPNT(TFIBBCDField * DocTIDDOCSPNT)
{
Object->DocTIDDOCSPNT=DocTIDDOCSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocTIDNOMSPNT(void)
{
return Object->DocTIDNOMSPNT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTIDNOMSPNT(TFIBBCDField * DocTIDNOMSPNT)
{
Object->DocTIDNOMSPNT=DocTIDNOMSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocTIDEDSPNT(void)
{
return Object->DocTIDEDSPNT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTIDEDSPNT(TFIBBCDField * DocTIDEDSPNT)
{
Object->DocTIDEDSPNT=DocTIDEDSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocIDBASE_DSPN(void)
{
return Object->DocIDBASE_DSPN;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocIDBASE_DSPN(TFIBBCDField * DocIDBASE_DSPN)
{
Object->DocIDBASE_DSPN=DocIDBASE_DSPN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocTIDBASE_DSPNT(void)
{
return Object->DocTIDBASE_DSPNT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTIDBASE_DSPNT(TFIBBCDField * DocTIDBASE_DSPNT)
{
Object->DocTIDBASE_DSPNT=DocTIDBASE_DSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocOsnTDOC(void)
{
return Object->DocOsnTDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocOsnTDOC(TFIBWideStringField * DocOsnTDOC)
{
Object->DocOsnTDOC=DocOsnTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_GrpNAMEGN(void)
{
return Object->GrpNAMEGN;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_GrpNAMEGN(TFIBWideStringField * GrpNAMEGN)
{
Object->GrpNAMEGN=GrpNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_ElNAMENOM(void)
{
return Object->ElNAMENOM;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_ElNAMENOM(TFIBWideStringField * ElNAMENOM)
{
Object->ElNAMENOM=ElNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_ElNAMEED(void)
{
return Object->ElNAMEED;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_ElNAMEED(TFIBWideStringField * ElNAMEED)
{
Object->ElNAMEED=ElNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSpisNomImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocPRIMSPN(void)
{
return Object->DocPRIMSPN;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocPRIMSPN(TFIBWideStringField * DocPRIMSPN)
{
Object->DocPRIMSPN=DocPRIMSPN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocGID_DSPN(void)
{
return Object->DocGID_DSPN;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocGID_DSPN(TFIBWideStringField * DocGID_DSPN)
{
Object->DocGID_DSPN=DocGID_DSPN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSpisNomImpl::get_DocOPER_DSPN(void)
{
return Object->DocOPER_DSPN;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocOPER_DSPN(TFIBIntegerField * DocOPER_DSPN)
{
Object->DocOPER_DSPN=DocOPER_DSPN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllIDPROJECT_GALLDOC(TFIBBCDField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpisNomImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBBCDField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSpisNomImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpisNomImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
bool TDMDocSpisNomImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocSpisNomImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocSpisNomImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
int TDMDocSpisNomImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_IdSklad(int IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
bool TDMDocSpisNomImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocSpisNomImpl::get_NoOtrOstatok(void)
{
return Object->NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_NoOtrOstatok(bool NoOtrOstatok)
{
Object->NoOtrOstatok=NoOtrOstatok;
}
//---------------------------------------------------------------
bool TDMDocSpisNomImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocSpisNomImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocSpisNomImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocSpisNomImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
void TDMDocSpisNomImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocSpisNomImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc( id);
}
//---------------------------------------------------------------
bool TDMDocSpisNomImpl::AddDataInv(void)
{
return Object->AddDataInv();
}
//---------------------------------------------------------------
bool TDMDocSpisNomImpl::SearchStringPoNom(__int64 id_nom)
{
return Object->SearchStringPoNom(id_nom);
}
//---------------------------------------------------------------
int TDMDocSpisNomImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
