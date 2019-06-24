#include "vcl.h"
#pragma hdrstop


#include "UDMDocSborkaKomplImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocSborkaKomplImpl::TDMDocSborkaKomplImpl()           
{                                            
Object=new TDMDocSborkaKompl(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocSborkaKomplImpl::~TDMDocSborkaKomplImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocSborkaKomplImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocSborkaKompl)                        
   {                                                                     
   *ppv=static_cast<IDMDocSborkaKompl*> (this);                                
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
int TDMDocSborkaKomplImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocSborkaKomplImpl::kanRelease(void)                                  
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
int  TDMDocSborkaKomplImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocSborkaKomplImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocSborkaKomplImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocSborkaKomplImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocSborkaKomplImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocSborkaKompl
TDataSource * TDMDocSborkaKomplImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocSborkaKomplImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocSborkaKomplImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSborkaKomplImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSborkaKomplImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSborkaKomplImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSborkaKomplImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSborkaKomplImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSborkaKomplImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSborkaKomplImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSborkaKomplImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSborkaKomplImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSborkaKomplImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllIDDOC(TFIBBCDField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocSborkaKomplImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocSborkaKomplImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSborkaKomplImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllIDFIRMDOC(TFIBBCDField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllIDSKLDOC(TFIBBCDField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllIDKLDOC(TFIBBCDField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllIDDOGDOC(TFIBBCDField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllIDDOCOSNDOC(TFIBBCDField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocID_DSBKOMPL(void)
{
return Object->DocID_DSBKOMPL;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocID_DSBKOMPL(TFIBBCDField * DocID_DSBKOMPL)
{
Object->DocID_DSBKOMPL=DocID_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocIDBASE_DSBKOMPL(void)
{
return Object->DocIDBASE_DSBKOMPL;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocIDBASE_DSBKOMPL(TFIBBCDField * DocIDBASE_DSBKOMPL)
{
Object->DocIDBASE_DSBKOMPL=DocIDBASE_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocIDDOC_DSBKOMPL(void)
{
return Object->DocIDDOC_DSBKOMPL;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocIDDOC_DSBKOMPL(TFIBBCDField * DocIDDOC_DSBKOMPL)
{
Object->DocIDDOC_DSBKOMPL=DocIDDOC_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocIDNOM_DSBKOMPL(void)
{
return Object->DocIDNOM_DSBKOMPL;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocIDNOM_DSBKOMPL(TFIBBCDField * DocIDNOM_DSBKOMPL)
{
Object->DocIDNOM_DSBKOMPL=DocIDNOM_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocIDED_DSBKOMPL(void)
{
return Object->DocIDED_DSBKOMPL;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocIDED_DSBKOMPL(TFIBBCDField * DocIDED_DSBKOMPL)
{
Object->DocIDED_DSBKOMPL=DocIDED_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocKF_DSBKOMPL(void)
{
return Object->DocKF_DSBKOMPL;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocKF_DSBKOMPL(TFIBBCDField * DocKF_DSBKOMPL)
{
Object->DocKF_DSBKOMPL=DocKF_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocKOL_DSBKOMPL(void)
{
return Object->DocKOL_DSBKOMPL;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocKOL_DSBKOMPL(TFIBBCDField * DocKOL_DSBKOMPL)
{
Object->DocKOL_DSBKOMPL=DocKOL_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocRPRICE_DSBKOMPL(void)
{
return Object->DocRPRICE_DSBKOMPL;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocRPRICE_DSBKOMPL(TFIBBCDField * DocRPRICE_DSBKOMPL)
{
Object->DocRPRICE_DSBKOMPL=DocRPRICE_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocTID_DSBKOMPLT(void)
{
return Object->DocTID_DSBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTID_DSBKOMPLT(TFIBBCDField * DocTID_DSBKOMPLT)
{
Object->DocTID_DSBKOMPLT=DocTID_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocTIDBASE_DSBKOMPLT(void)
{
return Object->DocTIDBASE_DSBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTIDBASE_DSBKOMPLT(TFIBBCDField * DocTIDBASE_DSBKOMPLT)
{
Object->DocTIDBASE_DSBKOMPLT=DocTIDBASE_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocTIDDOC_DSBKOMPLT(void)
{
return Object->DocTIDDOC_DSBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTIDDOC_DSBKOMPLT(TFIBBCDField * DocTIDDOC_DSBKOMPLT)
{
Object->DocTIDDOC_DSBKOMPLT=DocTIDDOC_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocTIDNOM_DSBKOMPLT(void)
{
return Object->DocTIDNOM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTIDNOM_DSBKOMPLT(TFIBBCDField * DocTIDNOM_DSBKOMPLT)
{
Object->DocTIDNOM_DSBKOMPLT=DocTIDNOM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocTIDED_DSBKOMPLT(void)
{
return Object->DocTIDED_DSBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTIDED_DSBKOMPLT(TFIBBCDField * DocTIDED_DSBKOMPLT)
{
Object->DocTIDED_DSBKOMPLT=DocTIDED_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocTKF_DSBKOMPLT(void)
{
return Object->DocTKF_DSBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTKF_DSBKOMPLT(TFIBBCDField * DocTKF_DSBKOMPLT)
{
Object->DocTKF_DSBKOMPLT=DocTKF_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocTKOL_DSBKOMPLT(void)
{
return Object->DocTKOL_DSBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTKOL_DSBKOMPLT(TFIBBCDField * DocTKOL_DSBKOMPLT)
{
Object->DocTKOL_DSBKOMPLT=DocTKOL_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocTRPRICE_DSBKOMPLT(void)
{
return Object->DocTRPRICE_DSBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTRPRICE_DSBKOMPLT(TFIBBCDField * DocTRPRICE_DSBKOMPLT)
{
Object->DocTRPRICE_DSBKOMPLT=DocTRPRICE_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocTRSUM_DSBKOMPLT(void)
{
return Object->DocTRSUM_DSBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTRSUM_DSBKOMPLT(TFIBBCDField * DocTRSUM_DSBKOMPLT)
{
Object->DocTRSUM_DSBKOMPLT=DocTRSUM_DSBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocIDRTPRICE_DSBKOMPL(void)
{
return Object->DocIDRTPRICE_DSBKOMPL;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocIDRTPRICE_DSBKOMPL(TFIBBCDField * DocIDRTPRICE_DSBKOMPL)
{
Object->DocIDRTPRICE_DSBKOMPL=DocIDRTPRICE_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocIDPART_DSBKOMPL(void)
{
return Object->DocIDPART_DSBKOMPL;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocIDPART_DSBKOMPL(TFIBBCDField * DocIDPART_DSBKOMPL)
{
Object->DocIDPART_DSBKOMPL=DocIDPART_DSBKOMPL;
}
//---------------------------------------------------------------
TIntegerField * TDMDocSborkaKomplImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSborkaKomplImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocDESCR_DSBKOMPL(void)
{
return Object->DocDESCR_DSBKOMPL;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocDESCR_DSBKOMPL(TFIBWideStringField * DocDESCR_DSBKOMPL)
{
Object->DocDESCR_DSBKOMPL=DocDESCR_DSBKOMPL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocNAMENOM(void)
{
return Object->DocNAMENOM;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocNAMENOM(TFIBWideStringField * DocNAMENOM)
{
Object->DocNAMENOM=DocNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocNAMEED(void)
{
return Object->DocNAMEED;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocNAMEED(TFIBWideStringField * DocNAMEED)
{
Object->DocNAMEED=DocNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllIDPROJECT_GALLDOC(TFIBBCDField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSborkaKomplImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBBCDField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSborkaKomplImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSborkaKomplImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
__int64 TDMDocSborkaKomplImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocSborkaKomplImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocSborkaKomplImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocSborkaKomplImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------

//---------------------------------------------------------------
bool TDMDocSborkaKomplImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocSborkaKomplImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocSborkaKomplImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocSborkaKomplImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TDMDocSborkaKomplImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocSborkaKomplImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TDMDocSborkaKomplImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
__int64 TDMDocSborkaKomplImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc,date_doc);
}
//---------------------------------------------------------------
int TDMDocSborkaKomplImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
