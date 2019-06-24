#include "vcl.h"
#pragma hdrstop


#include "UDMDocRevImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRevImpl::TDMDocRevImpl()           
{                                            
Object=new TDMDocRev(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRevImpl::~TDMDocRevImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRevImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRevImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRev)                        
   {                                                                     
   *ppv=static_cast<IDMDocRev*> (this);                                
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
int TDMDocRevImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRevImpl::kanRelease(void)                                  
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
int  TDMDocRevImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRevImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRevImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRevImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRevImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRevImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRevImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRev
TDataSource * TDMDocRevImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRevImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocRevImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRevImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRevImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRevImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRevImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRevImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRevImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRevImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRevImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRevImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRevImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRevImpl::get_IBQPoGrp(void)
{
return Object->IBQPoGrp;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrp(TpFIBDataSet * IBQPoGrp)
{
Object->IBQPoGrp=IBQPoGrp;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRevImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRevImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_DocTKOL_DREVT(void)
{
return Object->DocTKOL_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTKOL_DREVT(TFIBBCDField * DocTKOL_DREVT)
{
Object->DocTKOL_DREVT=DocTKOL_DREVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_DocTKF_DREVT(void)
{
return Object->DocTKF_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTKF_DREVT(TFIBBCDField * DocTKF_DREVT)
{
Object->DocTKF_DREVT=DocTKF_DREVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_DocTRPRICE_DREVT(void)
{
return Object->DocTRPRICE_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTRPRICE_DREVT(TFIBBCDField * DocTRPRICE_DREVT)
{
Object->DocTRPRICE_DREVT=DocTRPRICE_DREVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_DocTRSUM_DREVT(void)
{
return Object->DocTRSUM_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTRSUM_DREVT(TFIBBCDField * DocTRSUM_DREVT)
{
Object->DocTRSUM_DREVT=DocTRSUM_DREVT;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRevImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRevImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRevImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRevImpl::get_Ostatki(void)
{
return Object->Ostatki;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_Ostatki(TpFIBDataSet * Ostatki)
{
Object->Ostatki=Ostatki;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_OstatkiKFED(void)
{
return Object->OstatkiKFED;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_OstatkiKFED(TFIBBCDField * OstatkiKFED)
{
Object->OstatkiKFED=OstatkiKFED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_OstatkiSUM(void)
{
return Object->OstatkiSUM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_OstatkiSUM(TFIBBCDField * OstatkiSUM)
{
Object->OstatkiSUM=OstatkiSUM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_OstatkiIDNOM(void)
{
return Object->OstatkiIDNOM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_OstatkiIDNOM(TFIBLargeIntField * OstatkiIDNOM)
{
Object->OstatkiIDNOM=OstatkiIDNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRevImpl::get_OstatkiCODENOM(void)
{
return Object->OstatkiCODENOM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_OstatkiCODENOM(TFIBIntegerField * OstatkiCODENOM)
{
Object->OstatkiCODENOM=OstatkiCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_OstatkiNAMENOM(void)
{
return Object->OstatkiNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_OstatkiNAMENOM(TFIBWideStringField * OstatkiNAMENOM)
{
Object->OstatkiNAMENOM=OstatkiNAMENOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_OstatkiIDED(void)
{
return Object->OstatkiIDED;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_OstatkiIDED(TFIBLargeIntField * OstatkiIDED)
{
Object->OstatkiIDED=OstatkiIDED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_OstatkiNAMEED(void)
{
return Object->OstatkiNAMEED;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_OstatkiNAMEED(TFIBWideStringField * OstatkiNAMEED)
{
Object->OstatkiNAMEED=OstatkiNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_IBQPoGrpNAMEGN(void)
{
return Object->IBQPoGrpNAMEGN;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpNAMEGN(TFIBWideStringField * IBQPoGrpNAMEGN)
{
Object->IBQPoGrpNAMEGN=IBQPoGrpNAMEGN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_IBQPoGrpIDGN(void)
{
return Object->IBQPoGrpIDGN;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpIDGN(TFIBLargeIntField * IBQPoGrpIDGN)
{
Object->IBQPoGrpIDGN=IBQPoGrpIDGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_IBQPoGrpNAMENOM(void)
{
return Object->IBQPoGrpNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpNAMENOM(TFIBWideStringField * IBQPoGrpNAMENOM)
{
Object->IBQPoGrpNAMENOM=IBQPoGrpNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRevImpl::get_IBQPoGrpTNOM(void)
{
return Object->IBQPoGrpTNOM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpTNOM(TFIBIntegerField * IBQPoGrpTNOM)
{
Object->IBQPoGrpTNOM=IBQPoGrpTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRevImpl::get_IBQPoGrpCODENOM(void)
{
return Object->IBQPoGrpCODENOM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpCODENOM(TFIBIntegerField * IBQPoGrpCODENOM)
{
Object->IBQPoGrpCODENOM=IBQPoGrpCODENOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_IBQPoGrpID_DREVT(void)
{
return Object->IBQPoGrpID_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpID_DREVT(TFIBLargeIntField * IBQPoGrpID_DREVT)
{
Object->IBQPoGrpID_DREVT=IBQPoGrpID_DREVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_IBQPoGrpIDDOC_DREVT(void)
{
return Object->IBQPoGrpIDDOC_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpIDDOC_DREVT(TFIBLargeIntField * IBQPoGrpIDDOC_DREVT)
{
Object->IBQPoGrpIDDOC_DREVT=IBQPoGrpIDDOC_DREVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_IBQPoGrpIDNOM_DREVT(void)
{
return Object->IBQPoGrpIDNOM_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpIDNOM_DREVT(TFIBLargeIntField * IBQPoGrpIDNOM_DREVT)
{
Object->IBQPoGrpIDNOM_DREVT=IBQPoGrpIDNOM_DREVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_IBQPoGrpIDED_DREVT(void)
{
return Object->IBQPoGrpIDED_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpIDED_DREVT(TFIBLargeIntField * IBQPoGrpIDED_DREVT)
{
Object->IBQPoGrpIDED_DREVT=IBQPoGrpIDED_DREVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_IBQPoGrpKOL_DREVT(void)
{
return Object->IBQPoGrpKOL_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpKOL_DREVT(TFIBBCDField * IBQPoGrpKOL_DREVT)
{
Object->IBQPoGrpKOL_DREVT=IBQPoGrpKOL_DREVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_IBQPoGrpKF_DREVT(void)
{
return Object->IBQPoGrpKF_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpKF_DREVT(TFIBBCDField * IBQPoGrpKF_DREVT)
{
Object->IBQPoGrpKF_DREVT=IBQPoGrpKF_DREVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_IBQPoGrpRPRICE_DREVT(void)
{
return Object->IBQPoGrpRPRICE_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpRPRICE_DREVT(TFIBBCDField * IBQPoGrpRPRICE_DREVT)
{
Object->IBQPoGrpRPRICE_DREVT=IBQPoGrpRPRICE_DREVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_IBQPoGrpRSUM_DREVT(void)
{
return Object->IBQPoGrpRSUM_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpRSUM_DREVT(TFIBBCDField * IBQPoGrpRSUM_DREVT)
{
Object->IBQPoGrpRSUM_DREVT=IBQPoGrpRSUM_DREVT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_IBQPoGrpNAMEED(void)
{
return Object->IBQPoGrpNAMEED;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IBQPoGrpNAMEED(TFIBWideStringField * IBQPoGrpNAMEED)
{
Object->IBQPoGrpNAMEED=IBQPoGrpNAMEED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRevImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllNAME_USER(void)
{
return Object->DocAllNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllNAME_USER(TFIBWideStringField * DocAllNAME_USER)
{
Object->DocAllNAME_USER=DocAllNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocID_DREV(void)
{
return Object->DocID_DREV;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocID_DREV(TFIBLargeIntField * DocID_DREV)
{
Object->DocID_DREV=DocID_DREV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocGID_DREV(void)
{
return Object->DocGID_DREV;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocGID_DREV(TFIBWideStringField * DocGID_DREV)
{
Object->DocGID_DREV=DocGID_DREV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocIDDOC_DREV(void)
{
return Object->DocIDDOC_DREV;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocIDDOC_DREV(TFIBLargeIntField * DocIDDOC_DREV)
{
Object->DocIDDOC_DREV=DocIDDOC_DREV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocIDINV_DREV(void)
{
return Object->DocIDINV_DREV;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocIDINV_DREV(TFIBLargeIntField * DocIDINV_DREV)
{
Object->DocIDINV_DREV=DocIDINV_DREV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocDESCR_DREV(void)
{
return Object->DocDESCR_DREV;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocDESCR_DREV(TFIBWideStringField * DocDESCR_DREV)
{
Object->DocDESCR_DREV=DocDESCR_DREV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocIDRTPRICE_DREV(void)
{
return Object->DocIDRTPRICE_DREV;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocIDRTPRICE_DREV(TFIBLargeIntField * DocIDRTPRICE_DREV)
{
Object->DocIDRTPRICE_DREV=DocIDRTPRICE_DREV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocIDBASE_DREV(void)
{
return Object->DocIDBASE_DREV;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocIDBASE_DREV(TFIBLargeIntField * DocIDBASE_DREV)
{
Object->DocIDBASE_DREV=DocIDBASE_DREV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocNAME_SINV(void)
{
return Object->DocNAME_SINV;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocNAME_SINV(TFIBWideStringField * DocNAME_SINV)
{
Object->DocNAME_SINV=DocNAME_SINV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocTNAMEGN(void)
{
return Object->DocTNAMEGN;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN)
{
Object->DocTNAMEGN=DocTNAMEGN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocTIDGN(void)
{
return Object->DocTIDGN;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTIDGN(TFIBLargeIntField * DocTIDGN)
{
Object->DocTIDGN=DocTIDGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRevImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocTID_DREVT(void)
{
return Object->DocTID_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTID_DREVT(TFIBLargeIntField * DocTID_DREVT)
{
Object->DocTID_DREVT=DocTID_DREVT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocTGID_DREVT(void)
{
return Object->DocTGID_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTGID_DREVT(TFIBWideStringField * DocTGID_DREVT)
{
Object->DocTGID_DREVT=DocTGID_DREVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocTIDDOC_DREVT(void)
{
return Object->DocTIDDOC_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTIDDOC_DREVT(TFIBLargeIntField * DocTIDDOC_DREVT)
{
Object->DocTIDDOC_DREVT=DocTIDDOC_DREVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocTIDNOM_DREVT(void)
{
return Object->DocTIDNOM_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTIDNOM_DREVT(TFIBLargeIntField * DocTIDNOM_DREVT)
{
Object->DocTIDNOM_DREVT=DocTIDNOM_DREVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocTIDED_DREVT(void)
{
return Object->DocTIDED_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTIDED_DREVT(TFIBLargeIntField * DocTIDED_DREVT)
{
Object->DocTIDED_DREVT=DocTIDED_DREVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocTIDBASE_DREVT(void)
{
return Object->DocTIDBASE_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTIDBASE_DREVT(TFIBLargeIntField * DocTIDBASE_DREVT)
{
Object->DocTIDBASE_DREVT=DocTIDBASE_DREVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocTIDEXT_DOUT_DREVT(void)
{
return Object->DocTIDEXT_DOUT_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTIDEXT_DOUT_DREVT(TFIBLargeIntField * DocTIDEXT_DOUT_DREVT)
{
Object->DocTIDEXT_DOUT_DREVT=DocTIDEXT_DOUT_DREVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocTIDEXT_BASE_DREVT(void)
{
return Object->DocTIDEXT_BASE_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTIDEXT_BASE_DREVT(TFIBLargeIntField * DocTIDEXT_BASE_DREVT)
{
Object->DocTIDEXT_BASE_DREVT=DocTIDEXT_BASE_DREVT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllFNAMEFIRM(void)
{
return Object->DocAllFNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllFNAMEFIRM(TFIBWideStringField * DocAllFNAMEFIRM)
{
Object->DocAllFNAMEFIRM=DocAllFNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllPADRFIRM(void)
{
return Object->DocAllPADRFIRM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllPADRFIRM(TFIBWideStringField * DocAllPADRFIRM)
{
Object->DocAllPADRFIRM=DocAllPADRFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllINNFIRM(void)
{
return Object->DocAllINNFIRM;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllINNFIRM(TFIBWideStringField * DocAllINNFIRM)
{
Object->DocAllINNFIRM=DocAllINNFIRM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRevImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_DocTUCH_KOL_DREVT(void)
{
return Object->DocTUCH_KOL_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTUCH_KOL_DREVT(TFIBBCDField * DocTUCH_KOL_DREVT)
{
Object->DocTUCH_KOL_DREVT=DocTUCH_KOL_DREVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_DocTUCH_RSUM_DREVT(void)
{
return Object->DocTUCH_RSUM_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTUCH_RSUM_DREVT(TFIBBCDField * DocTUCH_RSUM_DREVT)
{
Object->DocTUCH_RSUM_DREVT=DocTUCH_RSUM_DREVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRevImpl::get_DocTUCH_SUM_DREVT(void)
{
return Object->DocTUCH_SUM_DREVT;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocTUCH_SUM_DREVT(TFIBBCDField * DocTUCH_SUM_DREVT)
{
Object->DocTUCH_SUM_DREVT=DocTUCH_SUM_DREVT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRevImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
bool TDMDocRevImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocRevImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocRevImpl::get_NoEdit(void)
{
return Object->NoEdit;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_NoEdit(bool NoEdit)
{
Object->NoEdit=NoEdit;
}
//---------------------------------------------------------------
__int64 TDMDocRevImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
int TDMDocRevImpl::get_IdGrpNom(void)
{
return Object->IdGrpNom;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_IdGrpNom(int IdGrpNom)
{
Object->IdGrpNom=IdGrpNom;
}
//---------------------------------------------------------------
bool TDMDocRevImpl::get_ChangeTable(void)
{
return Object->ChangeTable;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_ChangeTable(bool ChangeTable)
{
Object->ChangeTable=ChangeTable;
}
//---------------------------------------------------------------
bool TDMDocRevImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRevImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRevImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocRevImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRevImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRevImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRevImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRevImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocRevImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TDMDocRevImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
__int64 TDMDocRevImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc,date_doc);
}
//---------------------------------------------------------------
void TDMDocRevImpl::AddOstatkiNaSklade(__int64 id_firm, __int64 id_sklad)
{
return Object->AddOstatkiNaSklade(id_firm,id_sklad);
}
//---------------------------------------------------------------
int TDMDocRevImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
