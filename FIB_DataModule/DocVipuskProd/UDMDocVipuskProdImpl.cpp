#include "vcl.h"
#pragma hdrstop


#include "UDMDocVipuskProdImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocVipuskProdImpl::TDMDocVipuskProdImpl()           
{                                            
Object=new TDMDocVipuskProd(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocVipuskProdImpl::~TDMDocVipuskProdImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocVipuskProdImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocVipuskProd)                        
   {                                                                     
   *ppv=static_cast<IDMDocVipuskProd*> (this);                                
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
int TDMDocVipuskProdImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocVipuskProdImpl::kanRelease(void)                                  
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
int  TDMDocVipuskProdImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocVipuskProdImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocVipuskProdImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocVipuskProdImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocVipuskProdImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocVipuskProd
TDataSource * TDMDocVipuskProdImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocVipuskProdImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocVipuskProdImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVipuskProdImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVipuskProdImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVipuskProdImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocVipuskProdImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocVipuskProdImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocVipuskProdImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVipuskProdImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocVipuskProdImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocVipuskProdImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocVipuskProdImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TIntegerField * TDMDocVipuskProdImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocVipuskProdImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocVipuskProdImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVipuskProdImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipuskProdImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVipuskProdImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocID_DVIPPROD(void)
{
return Object->DocID_DVIPPROD;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocID_DVIPPROD(TFIBLargeIntField * DocID_DVIPPROD)
{
Object->DocID_DVIPPROD=DocID_DVIPPROD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocIDDOC_DVIPPROD(void)
{
return Object->DocIDDOC_DVIPPROD;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocIDDOC_DVIPPROD(TFIBLargeIntField * DocIDDOC_DVIPPROD)
{
Object->DocIDDOC_DVIPPROD=DocIDDOC_DVIPPROD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocIDBASE_DVIPPROD(void)
{
return Object->DocIDBASE_DVIPPROD;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocIDBASE_DVIPPROD(TFIBLargeIntField * DocIDBASE_DVIPPROD)
{
Object->DocIDBASE_DVIPPROD=DocIDBASE_DVIPPROD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocPRIM_DVIPPROD(void)
{
return Object->DocPRIM_DVIPPROD;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocPRIM_DVIPPROD(TFIBWideStringField * DocPRIM_DVIPPROD)
{
Object->DocPRIM_DVIPPROD=DocPRIM_DVIPPROD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocIDRTPRICE_DVIPPROD(void)
{
return Object->DocIDRTPRICE_DVIPPROD;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocIDRTPRICE_DVIPPROD(TFIBLargeIntField * DocIDRTPRICE_DVIPPROD)
{
Object->DocIDRTPRICE_DVIPPROD=DocIDRTPRICE_DVIPPROD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocTID_DVIPPRODT(void)
{
return Object->DocTID_DVIPPRODT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTID_DVIPPRODT(TFIBLargeIntField * DocTID_DVIPPRODT)
{
Object->DocTID_DVIPPRODT=DocTID_DVIPPRODT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocTIDDOC_DVIPPRODT(void)
{
return Object->DocTIDDOC_DVIPPRODT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTIDDOC_DVIPPRODT(TFIBLargeIntField * DocTIDDOC_DVIPPRODT)
{
Object->DocTIDDOC_DVIPPRODT=DocTIDDOC_DVIPPRODT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocTIDBASE_DVIPPRODT(void)
{
return Object->DocTIDBASE_DVIPPRODT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTIDBASE_DVIPPRODT(TFIBLargeIntField * DocTIDBASE_DVIPPRODT)
{
Object->DocTIDBASE_DVIPPRODT=DocTIDBASE_DVIPPRODT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocTIDNOM_DVIPPRODT(void)
{
return Object->DocTIDNOM_DVIPPRODT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTIDNOM_DVIPPRODT(TFIBLargeIntField * DocTIDNOM_DVIPPRODT)
{
Object->DocTIDNOM_DVIPPRODT=DocTIDNOM_DVIPPRODT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocTIDED_DVIPPRODT(void)
{
return Object->DocTIDED_DVIPPRODT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTIDED_DVIPPRODT(TFIBLargeIntField * DocTIDED_DVIPPRODT)
{
Object->DocTIDED_DVIPPRODT=DocTIDED_DVIPPRODT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVipuskProdImpl::get_DocTIDPART_DVIPPRODT(void)
{
return Object->DocTIDPART_DVIPPRODT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTIDPART_DVIPPRODT(TFIBLargeIntField * DocTIDPART_DVIPPRODT)
{
Object->DocTIDPART_DVIPPRODT=DocTIDPART_DVIPPRODT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipuskProdImpl::get_DocTKOL_DVIPPRODT(void)
{
return Object->DocTKOL_DVIPPRODT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTKOL_DVIPPRODT(TFIBBCDField * DocTKOL_DVIPPRODT)
{
Object->DocTKOL_DVIPPRODT=DocTKOL_DVIPPRODT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipuskProdImpl::get_DocTKF_DVIPPRODT(void)
{
return Object->DocTKF_DVIPPRODT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTKF_DVIPPRODT(TFIBBCDField * DocTKF_DVIPPRODT)
{
Object->DocTKF_DVIPPRODT=DocTKF_DVIPPRODT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipuskProdImpl::get_DocTRPRICE_DVIPPRODT(void)
{
return Object->DocTRPRICE_DVIPPRODT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTRPRICE_DVIPPRODT(TFIBBCDField * DocTRPRICE_DVIPPRODT)
{
Object->DocTRPRICE_DVIPPRODT=DocTRPRICE_DVIPPRODT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVipuskProdImpl::get_DocTRSUM_DVIPPRODT(void)
{
return Object->DocTRSUM_DVIPPRODT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTRSUM_DVIPPRODT(TFIBBCDField * DocTRSUM_DVIPPRODT)
{
Object->DocTRSUM_DVIPPRODT=DocTRSUM_DVIPPRODT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVipuskProdImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVipuskProdImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
__int64 TDMDocVipuskProdImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocVipuskProdImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocVipuskProdImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocVipuskProdImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocVipuskProdImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocVipuskProdImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocVipuskProdImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocVipuskProdImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TDMDocVipuskProdImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocVipuskProdImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TDMDocVipuskProdImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
__int64 TDMDocVipuskProdImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc,date_doc);
}
//---------------------------------------------------------------
int TDMDocVipuskProdImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
