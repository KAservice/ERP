#include "vcl.h"
#pragma hdrstop


#include "UDMDocZamenaImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocZamenaImpl::TDMDocZamenaImpl()           
{                                            
Object=new TDMDocZamena(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocZamenaImpl::~TDMDocZamenaImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocZamenaImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocZamenaImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocZamena)                        
   {                                                                     
   *ppv=static_cast<IDMDocZamena*> (this);                                
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
int TDMDocZamenaImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocZamenaImpl::kanRelease(void)                                  
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
int  TDMDocZamenaImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocZamenaImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocZamenaImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocZamenaImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocZamenaImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocZamena
TDataSource * TDMDocZamenaImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocZamenaImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocZamenaImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocZamenaImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocZamenaImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocZamenaImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocZamenaImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocZamenaImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocZamenaImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocZamenaImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocZamenaImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocZamenaImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocZamenaImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TIntegerField * TDMDocZamenaImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocZamenaImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocZamenaImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocZamenaImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocZamenaImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocZamenaImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocID_DZAMENA(void)
{
return Object->DocID_DZAMENA;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocID_DZAMENA(TFIBLargeIntField * DocID_DZAMENA)
{
Object->DocID_DZAMENA=DocID_DZAMENA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocIDBASE_DZAMENA(void)
{
return Object->DocIDBASE_DZAMENA;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocIDBASE_DZAMENA(TFIBLargeIntField * DocIDBASE_DZAMENA)
{
Object->DocIDBASE_DZAMENA=DocIDBASE_DZAMENA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocIDDOC_DZAMENA(void)
{
return Object->DocIDDOC_DZAMENA;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocIDDOC_DZAMENA(TFIBLargeIntField * DocIDDOC_DZAMENA)
{
Object->DocIDDOC_DZAMENA=DocIDDOC_DZAMENA;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocZamenaImpl::get_DocOPER_DZAMENA(void)
{
return Object->DocOPER_DZAMENA;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocOPER_DZAMENA(TFIBIntegerField * DocOPER_DZAMENA)
{
Object->DocOPER_DZAMENA=DocOPER_DZAMENA;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocDESCR_DZAMENA(void)
{
return Object->DocDESCR_DZAMENA;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocDESCR_DZAMENA(TFIBWideStringField * DocDESCR_DZAMENA)
{
Object->DocDESCR_DZAMENA=DocDESCR_DZAMENA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocIDRTPRICE_DZAMENA(void)
{
return Object->DocIDRTPRICE_DZAMENA;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocIDRTPRICE_DZAMENA(TFIBLargeIntField * DocIDRTPRICE_DZAMENA)
{
Object->DocIDRTPRICE_DZAMENA=DocIDRTPRICE_DZAMENA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocZamenaImpl::get_DocS_RSUM_DZAMENA(void)
{
return Object->DocS_RSUM_DZAMENA;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocS_RSUM_DZAMENA(TFIBBCDField * DocS_RSUM_DZAMENA)
{
Object->DocS_RSUM_DZAMENA=DocS_RSUM_DZAMENA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocZamenaImpl::get_DocP_RSUM_DZAMENA(void)
{
return Object->DocP_RSUM_DZAMENA;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocP_RSUM_DZAMENA(TFIBBCDField * DocP_RSUM_DZAMENA)
{
Object->DocP_RSUM_DZAMENA=DocP_RSUM_DZAMENA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocTID_DZAMENAT(void)
{
return Object->DocTID_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTID_DZAMENAT(TFIBLargeIntField * DocTID_DZAMENAT)
{
Object->DocTID_DZAMENAT=DocTID_DZAMENAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocTIDBASE_DZAMENAT(void)
{
return Object->DocTIDBASE_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTIDBASE_DZAMENAT(TFIBLargeIntField * DocTIDBASE_DZAMENAT)
{
Object->DocTIDBASE_DZAMENAT=DocTIDBASE_DZAMENAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocTIDDOC_DZAMENAT(void)
{
return Object->DocTIDDOC_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTIDDOC_DZAMENAT(TFIBLargeIntField * DocTIDDOC_DZAMENAT)
{
Object->DocTIDDOC_DZAMENAT=DocTIDDOC_DZAMENAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocTS_IDNOM_DZAMENAT(void)
{
return Object->DocTS_IDNOM_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTS_IDNOM_DZAMENAT(TFIBLargeIntField * DocTS_IDNOM_DZAMENAT)
{
Object->DocTS_IDNOM_DZAMENAT=DocTS_IDNOM_DZAMENAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocTS_IDED_DZAMENAT(void)
{
return Object->DocTS_IDED_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTS_IDED_DZAMENAT(TFIBLargeIntField * DocTS_IDED_DZAMENAT)
{
Object->DocTS_IDED_DZAMENAT=DocTS_IDED_DZAMENAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocZamenaImpl::get_DocTS_KF_DZAMENAT(void)
{
return Object->DocTS_KF_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTS_KF_DZAMENAT(TFIBBCDField * DocTS_KF_DZAMENAT)
{
Object->DocTS_KF_DZAMENAT=DocTS_KF_DZAMENAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocZamenaImpl::get_DocTS_KOL_DZAMENAT(void)
{
return Object->DocTS_KOL_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTS_KOL_DZAMENAT(TFIBBCDField * DocTS_KOL_DZAMENAT)
{
Object->DocTS_KOL_DZAMENAT=DocTS_KOL_DZAMENAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocZamenaImpl::get_DocTS_RPRICE_DZAMENAT(void)
{
return Object->DocTS_RPRICE_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTS_RPRICE_DZAMENAT(TFIBBCDField * DocTS_RPRICE_DZAMENAT)
{
Object->DocTS_RPRICE_DZAMENAT=DocTS_RPRICE_DZAMENAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocZamenaImpl::get_DocTS_RSUM_DZAMENAT(void)
{
return Object->DocTS_RSUM_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTS_RSUM_DZAMENAT(TFIBBCDField * DocTS_RSUM_DZAMENAT)
{
Object->DocTS_RSUM_DZAMENAT=DocTS_RSUM_DZAMENAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocTP_IDNOM_DZAMENAT(void)
{
return Object->DocTP_IDNOM_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTP_IDNOM_DZAMENAT(TFIBLargeIntField * DocTP_IDNOM_DZAMENAT)
{
Object->DocTP_IDNOM_DZAMENAT=DocTP_IDNOM_DZAMENAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocTP_IDED_DZAMENAT(void)
{
return Object->DocTP_IDED_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTP_IDED_DZAMENAT(TFIBLargeIntField * DocTP_IDED_DZAMENAT)
{
Object->DocTP_IDED_DZAMENAT=DocTP_IDED_DZAMENAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocZamenaImpl::get_DocTP_IDPART_DZAMENAT(void)
{
return Object->DocTP_IDPART_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTP_IDPART_DZAMENAT(TFIBLargeIntField * DocTP_IDPART_DZAMENAT)
{
Object->DocTP_IDPART_DZAMENAT=DocTP_IDPART_DZAMENAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocZamenaImpl::get_DocTP_KF_DZAMENAT(void)
{
return Object->DocTP_KF_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTP_KF_DZAMENAT(TFIBBCDField * DocTP_KF_DZAMENAT)
{
Object->DocTP_KF_DZAMENAT=DocTP_KF_DZAMENAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocZamenaImpl::get_DocTP_KOL_DZAMENAT(void)
{
return Object->DocTP_KOL_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTP_KOL_DZAMENAT(TFIBBCDField * DocTP_KOL_DZAMENAT)
{
Object->DocTP_KOL_DZAMENAT=DocTP_KOL_DZAMENAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocZamenaImpl::get_DocTP_RPRICE_DZAMENAT(void)
{
return Object->DocTP_RPRICE_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTP_RPRICE_DZAMENAT(TFIBBCDField * DocTP_RPRICE_DZAMENAT)
{
Object->DocTP_RPRICE_DZAMENAT=DocTP_RPRICE_DZAMENAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocZamenaImpl::get_DocTP_RSUM_DZAMENAT(void)
{
return Object->DocTP_RSUM_DZAMENAT;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTP_RSUM_DZAMENAT(TFIBBCDField * DocTP_RSUM_DZAMENAT)
{
Object->DocTP_RSUM_DZAMENAT=DocTP_RSUM_DZAMENAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocTS_NAMENOM(void)
{
return Object->DocTS_NAMENOM;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTS_NAMENOM(TFIBWideStringField * DocTS_NAMENOM)
{
Object->DocTS_NAMENOM=DocTS_NAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocTS_NAMEED(void)
{
return Object->DocTS_NAMEED;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTS_NAMEED(TFIBWideStringField * DocTS_NAMEED)
{
Object->DocTS_NAMEED=DocTS_NAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocTP_NAMENOM(void)
{
return Object->DocTP_NAMENOM;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTP_NAMENOM(TFIBWideStringField * DocTP_NAMENOM)
{
Object->DocTP_NAMENOM=DocTP_NAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocTP_NAMEED(void)
{
return Object->DocTP_NAMEED;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocTP_NAMEED(TFIBWideStringField * DocTP_NAMEED)
{
Object->DocTP_NAMEED=DocTP_NAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocZamenaImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
__int64 TDMDocZamenaImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocZamenaImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocZamenaImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocZamenaImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocZamenaImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocZamenaImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocZamenaImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocZamenaImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TDMDocZamenaImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocZamenaImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TDMDocZamenaImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
__int64 TDMDocZamenaImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc,date_doc);
}
//---------------------------------------------------------------
int TDMDocZamenaImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
