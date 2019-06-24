#include "vcl.h"
#pragma hdrstop


#include "UDMDocPKORoznImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocPKORoznImpl::TDMDocPKORoznImpl()           
{                                            
Object=new TDMDocPKORozn(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocPKORoznImpl::~TDMDocPKORoznImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocPKORoznImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocPKORoznImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocPKORozn)                        
   {                                                                     
   *ppv=static_cast<IDMDocPKORozn*> (this);                                
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
int TDMDocPKORoznImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocPKORoznImpl::kanRelease(void)                                  
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
int  TDMDocPKORoznImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocPKORoznImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocPKORoznImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocPKORoznImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocPKORoznImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocPKORozn
TDataSource * TDMDocPKORoznImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocPKORoznImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPKORoznImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPKORoznImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPKORoznImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPKORoznImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocPKORoznImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocPKORoznImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKORoznImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPKORoznImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKORoznImpl::get_DocOPERATION_DPKOROZN(void)
{
return Object->DocOPERATION_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocOPERATION_DPKOROZN(TFIBIntegerField * DocOPERATION_DPKOROZN)
{
Object->DocOPERATION_DPKOROZN=DocOPERATION_DPKOROZN;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPKORoznImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPKORoznImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocPKORoznImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocPKORoznImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKORoznImpl::get_DocNDS_DPKOROZN(void)
{
return Object->DocNDS_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocNDS_DPKOROZN(TFIBIntegerField * DocNDS_DPKOROZN)
{
Object->DocNDS_DPKOROZN=DocNDS_DPKOROZN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPKORoznImpl::get_DocSUMNDS_DPKOROZN(void)
{
return Object->DocSUMNDS_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocSUMNDS_DPKOROZN(TFIBBCDField * DocSUMNDS_DPKOROZN)
{
Object->DocSUMNDS_DPKOROZN=DocSUMNDS_DPKOROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKORoznImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocAllNAME_SDOG(void)
{
return Object->DocAllNAME_SDOG;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG)
{
Object->DocAllNAME_SDOG=DocAllNAME_SDOG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocID_DPKOROZN(void)
{
return Object->DocID_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocID_DPKOROZN(TFIBLargeIntField * DocID_DPKOROZN)
{
Object->DocID_DPKOROZN=DocID_DPKOROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocIDDOC_DPKOROZN(void)
{
return Object->DocIDDOC_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocIDDOC_DPKOROZN(TFIBLargeIntField * DocIDDOC_DPKOROZN)
{
Object->DocIDDOC_DPKOROZN=DocIDDOC_DPKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocGID_DPKOROZN(void)
{
return Object->DocGID_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocGID_DPKOROZN(TFIBWideStringField * DocGID_DPKOROZN)
{
Object->DocGID_DPKOROZN=DocGID_DPKOROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocIDKKM_DPKOROZN(void)
{
return Object->DocIDKKM_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocIDKKM_DPKOROZN(TFIBLargeIntField * DocIDKKM_DPKOROZN)
{
Object->DocIDKKM_DPKOROZN=DocIDKKM_DPKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocPRIM_DPKOROZN(void)
{
return Object->DocPRIM_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocPRIM_DPKOROZN(TFIBWideStringField * DocPRIM_DPKOROZN)
{
Object->DocPRIM_DPKOROZN=DocPRIM_DPKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocPROT_DPKOROZN(void)
{
return Object->DocPROT_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocPROT_DPKOROZN(TFIBWideStringField * DocPROT_DPKOROZN)
{
Object->DocPROT_DPKOROZN=DocPROT_DPKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocOSN_DPKOROZN(void)
{
return Object->DocOSN_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocOSN_DPKOROZN(TFIBWideStringField * DocOSN_DPKOROZN)
{
Object->DocOSN_DPKOROZN=DocOSN_DPKOROZN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKORoznImpl::get_DocNUMCHECK_DPKOROZN(void)
{
return Object->DocNUMCHECK_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocNUMCHECK_DPKOROZN(TFIBIntegerField * DocNUMCHECK_DPKOROZN)
{
Object->DocNUMCHECK_DPKOROZN=DocNUMCHECK_DPKOROZN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKORoznImpl::get_DocNUMKL_DPKOROZN(void)
{
return Object->DocNUMKL_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocNUMKL_DPKOROZN(TFIBIntegerField * DocNUMKL_DPKOROZN)
{
Object->DocNUMKL_DPKOROZN=DocNUMKL_DPKOROZN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKORoznImpl::get_DocNKL_DPKOROZN(void)
{
return Object->DocNKL_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocNKL_DPKOROZN(TFIBIntegerField * DocNKL_DPKOROZN)
{
Object->DocNKL_DPKOROZN=DocNKL_DPKOROZN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKORoznImpl::get_DocNCHECK_DPKOROZN(void)
{
return Object->DocNCHECK_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocNCHECK_DPKOROZN(TFIBIntegerField * DocNCHECK_DPKOROZN)
{
Object->DocNCHECK_DPKOROZN=DocNCHECK_DPKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocMODEL_DPKOROZN(void)
{
return Object->DocMODEL_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocMODEL_DPKOROZN(TFIBWideStringField * DocMODEL_DPKOROZN)
{
Object->DocMODEL_DPKOROZN=DocMODEL_DPKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocREGNUM_DPKOROZN(void)
{
return Object->DocREGNUM_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocREGNUM_DPKOROZN(TFIBWideStringField * DocREGNUM_DPKOROZN)
{
Object->DocREGNUM_DPKOROZN=DocREGNUM_DPKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocSAVNUM_DPKOROZN(void)
{
return Object->DocSAVNUM_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocSAVNUM_DPKOROZN(TFIBWideStringField * DocSAVNUM_DPKOROZN)
{
Object->DocSAVNUM_DPKOROZN=DocSAVNUM_DPKOROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocIDBASE_DPKOROZN(void)
{
return Object->DocIDBASE_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocIDBASE_DPKOROZN(TFIBLargeIntField * DocIDBASE_DPKOROZN)
{
Object->DocIDBASE_DPKOROZN=DocIDBASE_DPKOROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocIDCARD_DPKOROZN(void)
{
return Object->DocIDCARD_DPKOROZN;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocIDCARD_DPKOROZN(TFIBLargeIntField * DocIDCARD_DPKOROZN)
{
Object->DocIDCARD_DPKOROZN=DocIDCARD_DPKOROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocNAMEKKM(void)
{
return Object->DocNAMEKKM;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM)
{
Object->DocNAMEKKM=DocNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocNAME_SDISCOUNT_CARD(void)
{
return Object->DocNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD)
{
Object->DocNAME_SDISCOUNT_CARD=DocNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKORoznImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKORoznImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
bool TDMDocPKORoznImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocPKORoznImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocPKORoznImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocPKORoznImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocPKORoznImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocPKORoznImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocPKORoznImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocPKORoznImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocPKORoznImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
int TDMDocPKORoznImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
