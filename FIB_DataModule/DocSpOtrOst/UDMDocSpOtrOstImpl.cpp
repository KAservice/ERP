#include "vcl.h"
#pragma hdrstop


#include "UDMDocSpOtrOstImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocSpOtrOstImpl::TDMDocSpOtrOstImpl()           
{                                            
Object=new TDMDocSpOtrOst(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocSpOtrOstImpl::~TDMDocSpOtrOstImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocSpOtrOstImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocSpOtrOst)                        
   {                                                                     
   *ppv=static_cast<IDMDocSpOtrOst*> (this);                                
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
int TDMDocSpOtrOstImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocSpOtrOstImpl::kanRelease(void)                                  
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
int  TDMDocSpOtrOstImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocSpOtrOstImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocSpOtrOstImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocSpOtrOstImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocSpOtrOstImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocSpOtrOst
TDataSource * TDMDocSpOtrOstImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocSpOtrOstImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocSpOtrOstImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpOtrOstImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpOtrOstImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSpOtrOstImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSpOtrOstImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpOtrOstImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSpOtrOstImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpOtrOstImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpOtrOstImpl::get_IBQPoGrp(void)
{
return Object->IBQPoGrp;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrp(TpFIBDataSet * IBQPoGrp)
{
Object->IBQPoGrp=IBQPoGrp;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSpOtrOstImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TIntegerField * TDMDocSpOtrOstImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSpOtrOstImpl::get_IBQPoGrpTNOM(void)
{
return Object->IBQPoGrpTNOM;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpTNOM(TFIBIntegerField * IBQPoGrpTNOM)
{
Object->IBQPoGrpTNOM=IBQPoGrpTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSpOtrOstImpl::get_IBQPoGrpCODENOM(void)
{
return Object->IBQPoGrpCODENOM;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpCODENOM(TFIBIntegerField * IBQPoGrpCODENOM)
{
Object->IBQPoGrpCODENOM=IBQPoGrpCODENOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_IBQPoGrpKOL_DSPOTROSTT(void)
{
return Object->IBQPoGrpKOL_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpKOL_DSPOTROSTT(TFIBBCDField * IBQPoGrpKOL_DSPOTROSTT)
{
Object->IBQPoGrpKOL_DSPOTROSTT=IBQPoGrpKOL_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_IBQPoGrpKF_DSPOTROSTT(void)
{
return Object->IBQPoGrpKF_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpKF_DSPOTROSTT(TFIBBCDField * IBQPoGrpKF_DSPOTROSTT)
{
Object->IBQPoGrpKF_DSPOTROSTT=IBQPoGrpKF_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_IBQPoGrpPRICE_DSPOTROSTT(void)
{
return Object->IBQPoGrpPRICE_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpPRICE_DSPOTROSTT(TFIBBCDField * IBQPoGrpPRICE_DSPOTROSTT)
{
Object->IBQPoGrpPRICE_DSPOTROSTT=IBQPoGrpPRICE_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_IBQPoGrpSUM_DSPOTROSTT(void)
{
return Object->IBQPoGrpSUM_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpSUM_DSPOTROSTT(TFIBBCDField * IBQPoGrpSUM_DSPOTROSTT)
{
Object->IBQPoGrpSUM_DSPOTROSTT=IBQPoGrpSUM_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_IBQPoGrpRPRICE_DSPOTROSTT(void)
{
return Object->IBQPoGrpRPRICE_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpRPRICE_DSPOTROSTT(TFIBBCDField * IBQPoGrpRPRICE_DSPOTROSTT)
{
Object->IBQPoGrpRPRICE_DSPOTROSTT=IBQPoGrpRPRICE_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_IBQPoGrpRSUM_DSPOTROSTT(void)
{
return Object->IBQPoGrpRSUM_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpRSUM_DSPOTROSTT(TFIBBCDField * IBQPoGrpRSUM_DSPOTROSTT)
{
Object->IBQPoGrpRSUM_DSPOTROSTT=IBQPoGrpRSUM_DSPOTROSTT;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSpOtrOstImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSpOtrOstImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_IBQPoGrpIDGN(void)
{
return Object->IBQPoGrpIDGN;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpIDGN(TFIBBCDField * IBQPoGrpIDGN)
{
Object->IBQPoGrpIDGN=IBQPoGrpIDGN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_IBQPoGrpID_DSPOTROSTT(void)
{
return Object->IBQPoGrpID_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpID_DSPOTROSTT(TFIBBCDField * IBQPoGrpID_DSPOTROSTT)
{
Object->IBQPoGrpID_DSPOTROSTT=IBQPoGrpID_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_IBQPoGrpIDDOC_DSPOTROSTT(void)
{
return Object->IBQPoGrpIDDOC_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpIDDOC_DSPOTROSTT(TFIBBCDField * IBQPoGrpIDDOC_DSPOTROSTT)
{
Object->IBQPoGrpIDDOC_DSPOTROSTT=IBQPoGrpIDDOC_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_IBQPoGrpIDNOM_DSPOTROSTT(void)
{
return Object->IBQPoGrpIDNOM_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpIDNOM_DSPOTROSTT(TFIBBCDField * IBQPoGrpIDNOM_DSPOTROSTT)
{
Object->IBQPoGrpIDNOM_DSPOTROSTT=IBQPoGrpIDNOM_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_IBQPoGrpIDED_DSPOTROSTT(void)
{
return Object->IBQPoGrpIDED_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpIDED_DSPOTROSTT(TFIBBCDField * IBQPoGrpIDED_DSPOTROSTT)
{
Object->IBQPoGrpIDED_DSPOTROSTT=IBQPoGrpIDED_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_IBQPoGrpIDPART_DSPOTROSTT(void)
{
return Object->IBQPoGrpIDPART_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpIDPART_DSPOTROSTT(TFIBBCDField * IBQPoGrpIDPART_DSPOTROSTT)
{
Object->IBQPoGrpIDPART_DSPOTROSTT=IBQPoGrpIDPART_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_IBQPoGrpNAMEGN(void)
{
return Object->IBQPoGrpNAMEGN;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpNAMEGN(TFIBWideStringField * IBQPoGrpNAMEGN)
{
Object->IBQPoGrpNAMEGN=IBQPoGrpNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_IBQPoGrpNAMENOM(void)
{
return Object->IBQPoGrpNAMENOM;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpNAMENOM(TFIBWideStringField * IBQPoGrpNAMENOM)
{
Object->IBQPoGrpNAMENOM=IBQPoGrpNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_IBQPoGrpNAMEED(void)
{
return Object->IBQPoGrpNAMEED;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IBQPoGrpNAMEED(TFIBWideStringField * IBQPoGrpNAMEED)
{
Object->IBQPoGrpNAMEED=IBQPoGrpNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocTNAMEGN(void)
{
return Object->DocTNAMEGN;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN)
{
Object->DocTNAMEGN=DocTNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocSpOtrOstImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocSpOtrOstImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSpOtrOstImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSpOtrOstImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocAllNAME_USER(void)
{
return Object->DocAllNAME_USER;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllNAME_USER(TFIBWideStringField * DocAllNAME_USER)
{
Object->DocAllNAME_USER=DocAllNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocID_DSPOTROST(void)
{
return Object->DocID_DSPOTROST;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocID_DSPOTROST(TFIBLargeIntField * DocID_DSPOTROST)
{
Object->DocID_DSPOTROST=DocID_DSPOTROST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocIDDOC_DSPOTROST(void)
{
return Object->DocIDDOC_DSPOTROST;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocIDDOC_DSPOTROST(TFIBLargeIntField * DocIDDOC_DSPOTROST)
{
Object->DocIDDOC_DSPOTROST=DocIDDOC_DSPOTROST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocGID_DSPOTROST(void)
{
return Object->DocGID_DSPOTROST;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocGID_DSPOTROST(TFIBWideStringField * DocGID_DSPOTROST)
{
Object->DocGID_DSPOTROST=DocGID_DSPOTROST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocDESCR_DSPOTROST(void)
{
return Object->DocDESCR_DSPOTROST;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocDESCR_DSPOTROST(TFIBWideStringField * DocDESCR_DSPOTROST)
{
Object->DocDESCR_DSPOTROST=DocDESCR_DSPOTROST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocIDRTPRICE_DSPOTROST(void)
{
return Object->DocIDRTPRICE_DSPOTROST;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocIDRTPRICE_DSPOTROST(TFIBLargeIntField * DocIDRTPRICE_DSPOTROST)
{
Object->DocIDRTPRICE_DSPOTROST=DocIDRTPRICE_DSPOTROST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_DocRSUM_DSPOTROST(void)
{
return Object->DocRSUM_DSPOTROST;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocRSUM_DSPOTROST(TFIBBCDField * DocRSUM_DSPOTROST)
{
Object->DocRSUM_DSPOTROST=DocRSUM_DSPOTROST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocIDBASE_DSPOTROST(void)
{
return Object->DocIDBASE_DSPOTROST;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocIDBASE_DSPOTROST(TFIBLargeIntField * DocIDBASE_DSPOTROST)
{
Object->DocIDBASE_DSPOTROST=DocIDBASE_DSPOTROST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocTIDGN(void)
{
return Object->DocTIDGN;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTIDGN(TFIBLargeIntField * DocTIDGN)
{
Object->DocTIDGN=DocTIDGN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSpOtrOstImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSpOtrOstImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocTID_DSPOTROSTT(void)
{
return Object->DocTID_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTID_DSPOTROSTT(TFIBLargeIntField * DocTID_DSPOTROSTT)
{
Object->DocTID_DSPOTROSTT=DocTID_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocTIDDOC_DSPOTROSTT(void)
{
return Object->DocTIDDOC_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTIDDOC_DSPOTROSTT(TFIBLargeIntField * DocTIDDOC_DSPOTROSTT)
{
Object->DocTIDDOC_DSPOTROSTT=DocTIDDOC_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocTGID_DSPOTROSTT(void)
{
return Object->DocTGID_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTGID_DSPOTROSTT(TFIBWideStringField * DocTGID_DSPOTROSTT)
{
Object->DocTGID_DSPOTROSTT=DocTGID_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocTIDNOM_DSPOTROSTT(void)
{
return Object->DocTIDNOM_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTIDNOM_DSPOTROSTT(TFIBLargeIntField * DocTIDNOM_DSPOTROSTT)
{
Object->DocTIDNOM_DSPOTROSTT=DocTIDNOM_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocTIDED_DSPOTROSTT(void)
{
return Object->DocTIDED_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTIDED_DSPOTROSTT(TFIBLargeIntField * DocTIDED_DSPOTROSTT)
{
Object->DocTIDED_DSPOTROSTT=DocTIDED_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocTIDPART_DSPOTROSTT(void)
{
return Object->DocTIDPART_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTIDPART_DSPOTROSTT(TFIBLargeIntField * DocTIDPART_DSPOTROSTT)
{
Object->DocTIDPART_DSPOTROSTT=DocTIDPART_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_DocTKOL_DSPOTROSTT(void)
{
return Object->DocTKOL_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTKOL_DSPOTROSTT(TFIBBCDField * DocTKOL_DSPOTROSTT)
{
Object->DocTKOL_DSPOTROSTT=DocTKOL_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_DocTKF_DSPOTROSTT(void)
{
return Object->DocTKF_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTKF_DSPOTROSTT(TFIBBCDField * DocTKF_DSPOTROSTT)
{
Object->DocTKF_DSPOTROSTT=DocTKF_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_DocTPRICE_DSPOTROSTT(void)
{
return Object->DocTPRICE_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTPRICE_DSPOTROSTT(TFIBBCDField * DocTPRICE_DSPOTROSTT)
{
Object->DocTPRICE_DSPOTROSTT=DocTPRICE_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_DocTSUM_DSPOTROSTT(void)
{
return Object->DocTSUM_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTSUM_DSPOTROSTT(TFIBBCDField * DocTSUM_DSPOTROSTT)
{
Object->DocTSUM_DSPOTROSTT=DocTSUM_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_DocTRPRICE_DSPOTROSTT(void)
{
return Object->DocTRPRICE_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTRPRICE_DSPOTROSTT(TFIBBCDField * DocTRPRICE_DSPOTROSTT)
{
Object->DocTRPRICE_DSPOTROSTT=DocTRPRICE_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSpOtrOstImpl::get_DocTRSUM_DSPOTROSTT(void)
{
return Object->DocTRSUM_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTRSUM_DSPOTROSTT(TFIBBCDField * DocTRSUM_DSPOTROSTT)
{
Object->DocTRSUM_DSPOTROSTT=DocTRSUM_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocSpOtrOstImpl::get_DocTIDBASE_DSPOTROSTT(void)
{
return Object->DocTIDBASE_DSPOTROSTT;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocTIDBASE_DSPOTROSTT(TFIBLargeIntField * DocTIDBASE_DSPOTROSTT)
{
Object->DocTIDBASE_DSPOTROSTT=DocTIDBASE_DSPOTROSTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSpOtrOstImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
bool TDMDocSpOtrOstImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocSpOtrOstImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocSpOtrOstImpl::get_NoEdit(void)
{
return Object->NoEdit;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_NoEdit(bool NoEdit)
{
Object->NoEdit=NoEdit;
}
//---------------------------------------------------------------
__int64 TDMDocSpOtrOstImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMDocSpOtrOstImpl::get_IdGrpNom(void)
{
return Object->IdGrpNom;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_IdGrpNom(__int64 IdGrpNom)
{
Object->IdGrpNom=IdGrpNom;
}
//---------------------------------------------------------------
bool TDMDocSpOtrOstImpl::get_ChangeTable(void)
{
return Object->ChangeTable;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_ChangeTable(bool ChangeTable)
{
Object->ChangeTable=ChangeTable;
}
//---------------------------------------------------------------
bool TDMDocSpOtrOstImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::OpenDoc(__int64 id_doc)
{
return Object->OpenDoc(id_doc);
}
//---------------------------------------------------------------
bool TDMDocSpOtrOstImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocSpOtrOstImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocSpOtrOstImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocSpOtrOstImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TDMDocSpOtrOstImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
__int64 TDMDocSpOtrOstImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc,date_doc);
}
//---------------------------------------------------------------
int TDMDocSpOtrOstImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
