#include "vcl.h"
#pragma hdrstop


#include "UDMDocRKORoznImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRKORoznImpl::TDMDocRKORoznImpl()           
{                                            
Object=new TDMDocRKORozn(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRKORoznImpl::~TDMDocRKORoznImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRKORoznImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRKORoznImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRKORozn)                        
   {                                                                     
   *ppv=static_cast<IDMDocRKORozn*> (this);                                
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
int TDMDocRKORoznImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRKORoznImpl::kanRelease(void)                                  
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
int  TDMDocRKORoznImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRKORoznImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRKORoznImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRKORoznImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRKORoznImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRKORozn
TDataSource * TDMDocRKORoznImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRKORoznImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRKORoznImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRKORoznImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRKORoznImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRKORoznImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRKORoznImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRKORoznImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRKORoznImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRKORoznImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRKORoznImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKORoznImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRKORoznImpl::get_DocOPERATION_DRKOROZN(void)
{
return Object->DocOPERATION_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocOPERATION_DRKOROZN(TFIBIntegerField * DocOPERATION_DRKOROZN)
{
Object->DocOPERATION_DRKOROZN=DocOPERATION_DRKOROZN;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRKORoznImpl::get_pFIBQAdvance(void)
{
return Object->pFIBQAdvance;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_pFIBQAdvance(TpFIBDataSet * pFIBQAdvance)
{
Object->pFIBQAdvance=pFIBQAdvance;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKORoznImpl::get_pFIBQAdvanceSUM_RGADVCUST(void)
{
return Object->pFIBQAdvanceSUM_RGADVCUST;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_pFIBQAdvanceSUM_RGADVCUST(TFIBBCDField * pFIBQAdvanceSUM_RGADVCUST)
{
Object->pFIBQAdvanceSUM_RGADVCUST=pFIBQAdvanceSUM_RGADVCUST;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRKORoznImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRKORoznImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRKORoznImpl::get_DocNDS_DRKOROZN(void)
{
return Object->DocNDS_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocNDS_DRKOROZN(TFIBIntegerField * DocNDS_DRKOROZN)
{
Object->DocNDS_DRKOROZN=DocNDS_DRKOROZN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKORoznImpl::get_DocSUMNDS_DRKOROZN(void)
{
return Object->DocSUMNDS_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocSUMNDS_DRKOROZN(TFIBBCDField * DocSUMNDS_DRKOROZN)
{
Object->DocSUMNDS_DRKOROZN=DocSUMNDS_DRKOROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocID_DRKOROZN(void)
{
return Object->DocID_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocID_DRKOROZN(TFIBLargeIntField * DocID_DRKOROZN)
{
Object->DocID_DRKOROZN=DocID_DRKOROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocIDDOC_DRKOROZN(void)
{
return Object->DocIDDOC_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocIDDOC_DRKOROZN(TFIBLargeIntField * DocIDDOC_DRKOROZN)
{
Object->DocIDDOC_DRKOROZN=DocIDDOC_DRKOROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocIDKKM_DRKOROZN(void)
{
return Object->DocIDKKM_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocIDKKM_DRKOROZN(TFIBLargeIntField * DocIDKKM_DRKOROZN)
{
Object->DocIDKKM_DRKOROZN=DocIDKKM_DRKOROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocIDBASE_DRKOROZN(void)
{
return Object->DocIDBASE_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocIDBASE_DRKOROZN(TFIBLargeIntField * DocIDBASE_DRKOROZN)
{
Object->DocIDBASE_DRKOROZN=DocIDBASE_DRKOROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocIDCARD_DRKOROZN(void)
{
return Object->DocIDCARD_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocIDCARD_DRKOROZN(TFIBLargeIntField * DocIDCARD_DRKOROZN)
{
Object->DocIDCARD_DRKOROZN=DocIDCARD_DRKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRKORoznImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocAllNAME_SDOG(void)
{
return Object->DocAllNAME_SDOG;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG)
{
Object->DocAllNAME_SDOG=DocAllNAME_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocGID_DRKOROZN(void)
{
return Object->DocGID_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocGID_DRKOROZN(TFIBWideStringField * DocGID_DRKOROZN)
{
Object->DocGID_DRKOROZN=DocGID_DRKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocVIDAT_DRKOROZN(void)
{
return Object->DocVIDAT_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocVIDAT_DRKOROZN(TFIBWideStringField * DocVIDAT_DRKOROZN)
{
Object->DocVIDAT_DRKOROZN=DocVIDAT_DRKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocOSN_DRKOROZN(void)
{
return Object->DocOSN_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocOSN_DRKOROZN(TFIBWideStringField * DocOSN_DRKOROZN)
{
Object->DocOSN_DRKOROZN=DocOSN_DRKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocPRIM_DRKOROZN(void)
{
return Object->DocPRIM_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocPRIM_DRKOROZN(TFIBWideStringField * DocPRIM_DRKOROZN)
{
Object->DocPRIM_DRKOROZN=DocPRIM_DRKOROZN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRKORoznImpl::get_DocNCHECK_DRKOROZN(void)
{
return Object->DocNCHECK_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocNCHECK_DRKOROZN(TFIBIntegerField * DocNCHECK_DRKOROZN)
{
Object->DocNCHECK_DRKOROZN=DocNCHECK_DRKOROZN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRKORoznImpl::get_DocNKL_DRKOROZN(void)
{
return Object->DocNKL_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocNKL_DRKOROZN(TFIBIntegerField * DocNKL_DRKOROZN)
{
Object->DocNKL_DRKOROZN=DocNKL_DRKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocMODEL_DRKOROZN(void)
{
return Object->DocMODEL_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocMODEL_DRKOROZN(TFIBWideStringField * DocMODEL_DRKOROZN)
{
Object->DocMODEL_DRKOROZN=DocMODEL_DRKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocREGNUM_DRKOROZN(void)
{
return Object->DocREGNUM_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocREGNUM_DRKOROZN(TFIBWideStringField * DocREGNUM_DRKOROZN)
{
Object->DocREGNUM_DRKOROZN=DocREGNUM_DRKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocSAVNUM_DRKOROZN(void)
{
return Object->DocSAVNUM_DRKOROZN;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocSAVNUM_DRKOROZN(TFIBWideStringField * DocSAVNUM_DRKOROZN)
{
Object->DocSAVNUM_DRKOROZN=DocSAVNUM_DRKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocNAMEKKM(void)
{
return Object->DocNAMEKKM;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM)
{
Object->DocNAMEKKM=DocNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocNAME_SDISCOUNT_CARD(void)
{
return Object->DocNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD)
{
Object->DocNAME_SDISCOUNT_CARD=DocNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRKORoznImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKORoznImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
bool TDMDocRKORoznImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocRKORoznImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocRKORoznImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocRKORoznImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRKORoznImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRKORoznImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRKORoznImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRKORoznImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocRKORoznImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
int TDMDocRKORoznImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
