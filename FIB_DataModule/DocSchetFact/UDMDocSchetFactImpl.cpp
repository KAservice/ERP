#include "vcl.h"
#pragma hdrstop


#include "UDMDocSchetFactImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocSchetFactImpl::TDMDocSchetFactImpl()           
{                                            
Object=new TDMDocSchetFact(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocSchetFactImpl::~TDMDocSchetFactImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocSchetFactImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocSchetFactImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocSchetFact)                        
   {                                                                     
   *ppv=static_cast<IDMDocSchetFact*> (this);                                
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
int TDMDocSchetFactImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocSchetFactImpl::kanRelease(void)                                  
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
int  TDMDocSchetFactImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocSchetFactImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocSchetFactImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocSchetFactImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocSchetFactImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocSchetFact
TDataSource * TDMDocSchetFactImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocSchetFactImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocSchetFactImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSchetFactImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSchetFactImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSchetFactImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSchetFactImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSchetFactImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocSchetFactImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocSchetFactImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSchetFactImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocTKOL_DSCHFACTT(void)
{
return Object->DocTKOL_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTKOL_DSCHFACTT(TFIBBCDField * DocTKOL_DSCHFACTT)
{
Object->DocTKOL_DSCHFACTT=DocTKOL_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocTKF_DSCHFACTT(void)
{
return Object->DocTKF_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTKF_DSCHFACTT(TFIBBCDField * DocTKF_DSCHFACTT)
{
Object->DocTKF_DSCHFACTT=DocTKF_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocTPRICE_DSCHFACTT(void)
{
return Object->DocTPRICE_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTPRICE_DSCHFACTT(TFIBBCDField * DocTPRICE_DSCHFACTT)
{
Object->DocTPRICE_DSCHFACTT=DocTPRICE_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocTSUM_DSCHFACTT(void)
{
return Object->DocTSUM_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTSUM_DSCHFACTT(TFIBBCDField * DocTSUM_DSCHFACTT)
{
Object->DocTSUM_DSCHFACTT=DocTSUM_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSchetFactImpl::get_DocTSTNDS_DSCHFACTT(void)
{
return Object->DocTSTNDS_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTSTNDS_DSCHFACTT(TFIBIntegerField * DocTSTNDS_DSCHFACTT)
{
Object->DocTSTNDS_DSCHFACTT=DocTSTNDS_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocTSUMNDS_DSCHFACTT(void)
{
return Object->DocTSUMNDS_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTSUMNDS_DSCHFACTT(TFIBBCDField * DocTSUMNDS_DSCHFACTT)
{
Object->DocTSUMNDS_DSCHFACTT=DocTSUMNDS_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSchetFactImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TIntegerField * TDMDocSchetFactImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSchetFactImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocSchetFactImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocSchetFactImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSchetFactImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSchetFactImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllIDDOC(TFIBBCDField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllIDFIRMDOC(TFIBBCDField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllIDSKLDOC(TFIBBCDField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllIDKLDOC(TFIBBCDField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllIDDOGDOC(TFIBBCDField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllIDDOCOSNDOC(TFIBBCDField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocID_DSCHFACT(void)
{
return Object->DocID_DSCHFACT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocID_DSCHFACT(TFIBBCDField * DocID_DSCHFACT)
{
Object->DocID_DSCHFACT=DocID_DSCHFACT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocIDDOC_DSCHFACT(void)
{
return Object->DocIDDOC_DSCHFACT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocIDDOC_DSCHFACT(TFIBBCDField * DocIDDOC_DSCHFACT)
{
Object->DocIDDOC_DSCHFACT=DocIDDOC_DSCHFACT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocIDTPRICE_DSCHFACT(void)
{
return Object->DocIDTPRICE_DSCHFACT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocIDTPRICE_DSCHFACT(TFIBBCDField * DocIDTPRICE_DSCHFACT)
{
Object->DocIDTPRICE_DSCHFACT=DocIDTPRICE_DSCHFACT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocTID_DSCHFACTT(void)
{
return Object->DocTID_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTID_DSCHFACTT(TFIBBCDField * DocTID_DSCHFACTT)
{
Object->DocTID_DSCHFACTT=DocTID_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocTIDDOC_DSCHFACTT(void)
{
return Object->DocTIDDOC_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTIDDOC_DSCHFACTT(TFIBBCDField * DocTIDDOC_DSCHFACTT)
{
Object->DocTIDDOC_DSCHFACTT=DocTIDDOC_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocTIDNOM_DSCHFACTT(void)
{
return Object->DocTIDNOM_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTIDNOM_DSCHFACTT(TFIBBCDField * DocTIDNOM_DSCHFACTT)
{
Object->DocTIDNOM_DSCHFACTT=DocTIDNOM_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocTIDED_DSCHFACTT(void)
{
return Object->DocTIDED_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTIDED_DSCHFACTT(TFIBBCDField * DocTIDED_DSCHFACTT)
{
Object->DocTIDED_DSCHFACTT=DocTIDED_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocIDGRPOL_DSCHFACT(void)
{
return Object->DocIDGRPOL_DSCHFACT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocIDGRPOL_DSCHFACT(TFIBBCDField * DocIDGRPOL_DSCHFACT)
{
Object->DocIDGRPOL_DSCHFACT=DocIDGRPOL_DSCHFACT;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocSchetFactImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocIDBASE_DSCHFACT(void)
{
return Object->DocIDBASE_DSCHFACT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocIDBASE_DSCHFACT(TFIBBCDField * DocIDBASE_DSCHFACT)
{
Object->DocIDBASE_DSCHFACT=DocIDBASE_DSCHFACT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocTIDBASE_DSCHFACTT(void)
{
return Object->DocTIDBASE_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTIDBASE_DSCHFACTT(TFIBBCDField * DocTIDBASE_DSCHFACTT)
{
Object->DocTIDBASE_DSCHFACTT=DocTIDBASE_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSchetFactImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocGID_DSCHFACT(void)
{
return Object->DocGID_DSCHFACT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocGID_DSCHFACT(TFIBWideStringField * DocGID_DSCHFACT)
{
Object->DocGID_DSCHFACT=DocGID_DSCHFACT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocPRIM_DSCHFACT(void)
{
return Object->DocPRIM_DSCHFACT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocPRIM_DSCHFACT(TFIBWideStringField * DocPRIM_DSCHFACT)
{
Object->DocPRIM_DSCHFACT=DocPRIM_DSCHFACT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocNAMEKLIENT(void)
{
return Object->DocNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT)
{
Object->DocNAMEKLIENT=DocNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocTGID_DSCHFACTT(void)
{
return Object->DocTGID_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTGID_DSCHFACTT(TFIBWideStringField * DocTGID_DSCHFACTT)
{
Object->DocTGID_DSCHFACTT=DocTGID_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSchetFactImpl::get_DocTNDS_DSCHFACTT(void)
{
return Object->DocTNDS_DSCHFACTT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTNDS_DSCHFACTT(TFIBIntegerField * DocTNDS_DSCHFACTT)
{
Object->DocTNDS_DSCHFACTT=DocTNDS_DSCHFACTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllIDPROJECT_GALLDOC(TFIBBCDField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocSchetFactImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBBCDField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocNUMPLAT_RASCH_DOC_DSCHFACT(void)
{
return Object->DocNUMPLAT_RASCH_DOC_DSCHFACT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocNUMPLAT_RASCH_DOC_DSCHFACT(TFIBWideStringField * DocNUMPLAT_RASCH_DOC_DSCHFACT)
{
Object->DocNUMPLAT_RASCH_DOC_DSCHFACT=DocNUMPLAT_RASCH_DOC_DSCHFACT;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocSchetFactImpl::get_DocDATEPLAT_RASCH_DOC_DSCHFACT(void)
{
return Object->DocDATEPLAT_RASCH_DOC_DSCHFACT;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocDATEPLAT_RASCH_DOC_DSCHFACT(TFIBDateTimeField * DocDATEPLAT_RASCH_DOC_DSCHFACT)
{
Object->DocDATEPLAT_RASCH_DOC_DSCHFACT=DocDATEPLAT_RASCH_DOC_DSCHFACT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocSchetFactImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocSchetFactImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
bool TDMDocSchetFactImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocSchetFactImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocSchetFactImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocSchetFactImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocSchetFactImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocSchetFactImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocSchetFactImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
void TDMDocSchetFactImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocSchetFactImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc( id);
}
//---------------------------------------------------------------
int TDMDocSchetFactImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
