#include "vcl.h"
#pragma hdrstop


#include "UDMDocPKOImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocPKOImpl::TDMDocPKOImpl()           
{                                            
Object=new TDMDocPKO(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocPKOImpl::~TDMDocPKOImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocPKOImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocPKOImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocPKO)                        
   {                                                                     
   *ppv=static_cast<IDMDocPKO*> (this);                                
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
int TDMDocPKOImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocPKOImpl::kanRelease(void)                                  
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
int  TDMDocPKOImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocPKOImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocPKOImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocPKOImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocPKOImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocPKOImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocPKOImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocPKO
TDataSource * TDMDocPKOImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocPKOImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPKOImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPKOImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPKOImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPKOImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocPKOImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocPKOImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKOImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPKOImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocPKOImpl::get_DocADDKDRPKO(void)
{
return Object->DocADDKDRPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocADDKDRPKO(TFIBSmallIntField * DocADDKDRPKO)
{
Object->DocADDKDRPKO=DocADDKDRPKO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPKOImpl::get_DocSUMUSNPKO(void)
{
return Object->DocSUMUSNPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocSUMUSNPKO(TFIBBCDField * DocSUMUSNPKO)
{
Object->DocSUMUSNPKO=DocSUMUSNPKO;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPKOImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPKOImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKOImpl::get_DocNKLPKO(void)
{
return Object->DocNKLPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocNKLPKO(TFIBIntegerField * DocNKLPKO)
{
Object->DocNKLPKO=DocNKLPKO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKOImpl::get_DocNCHECKPKO(void)
{
return Object->DocNCHECKPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocNCHECKPKO(TFIBIntegerField * DocNCHECKPKO)
{
Object->DocNCHECKPKO=DocNCHECKPKO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocPKOImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocPKOImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKOImpl::get_DocNDS_DPKO(void)
{
return Object->DocNDS_DPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocNDS_DPKO(TFIBIntegerField * DocNDS_DPKO)
{
Object->DocNDS_DPKO=DocNDS_DPKO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPKOImpl::get_DocSUMNDS_DPKO(void)
{
return Object->DocSUMNDS_DPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocSUMNDS_DPKO(TFIBBCDField * DocSUMNDS_DPKO)
{
Object->DocSUMNDS_DPKO=DocSUMNDS_DPKO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKOImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocIDPKO(void)
{
return Object->DocIDPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocIDPKO(TFIBLargeIntField * DocIDPKO)
{
Object->DocIDPKO=DocIDPKO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocIDDOCPKO(void)
{
return Object->DocIDDOCPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocIDDOCPKO(TFIBLargeIntField * DocIDDOCPKO)
{
Object->DocIDDOCPKO=DocIDDOCPKO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocIDKKMPKO(void)
{
return Object->DocIDKKMPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocIDKKMPKO(TFIBLargeIntField * DocIDKKMPKO)
{
Object->DocIDKKMPKO=DocIDKKMPKO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocIDKLPKO(void)
{
return Object->DocIDKLPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocIDKLPKO(TFIBLargeIntField * DocIDKLPKO)
{
Object->DocIDKLPKO=DocIDKLPKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocPROTPKO(void)
{
return Object->DocPROTPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocPROTPKO(TFIBWideStringField * DocPROTPKO)
{
Object->DocPROTPKO=DocPROTPKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocOSNPKO(void)
{
return Object->DocOSNPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocOSNPKO(TFIBWideStringField * DocOSNPKO)
{
Object->DocOSNPKO=DocOSNPKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocPRILPKO(void)
{
return Object->DocPRILPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocPRILPKO(TFIBWideStringField * DocPRILPKO)
{
Object->DocPRILPKO=DocPRILPKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocGID_DPKO(void)
{
return Object->DocGID_DPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocGID_DPKO(TFIBWideStringField * DocGID_DPKO)
{
Object->DocGID_DPKO=DocGID_DPKO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPKOImpl::get_DocOPERATIONPKO(void)
{
return Object->DocOPERATIONPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocOPERATIONPKO(TFIBIntegerField * DocOPERATIONPKO)
{
Object->DocOPERATIONPKO=DocOPERATIONPKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocMODELPKO(void)
{
return Object->DocMODELPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocMODELPKO(TFIBWideStringField * DocMODELPKO)
{
Object->DocMODELPKO=DocMODELPKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocREGNUMPKO(void)
{
return Object->DocREGNUMPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocREGNUMPKO(TFIBWideStringField * DocREGNUMPKO)
{
Object->DocREGNUMPKO=DocREGNUMPKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocSAVNUMPKO(void)
{
return Object->DocSAVNUMPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocSAVNUMPKO(TFIBWideStringField * DocSAVNUMPKO)
{
Object->DocSAVNUMPKO=DocSAVNUMPKO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocIDBASE_DPKO(void)
{
return Object->DocIDBASE_DPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocIDBASE_DPKO(TFIBLargeIntField * DocIDBASE_DPKO)
{
Object->DocIDBASE_DPKO=DocIDBASE_DPKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocNAMEKKM(void)
{
return Object->DocNAMEKKM;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM)
{
Object->DocNAMEKKM=DocNAMEKKM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPKOImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPKOImpl::get_DocKORRSCHET_DPKO(void)
{
return Object->DocKORRSCHET_DPKO;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_DocKORRSCHET_DPKO(TFIBWideStringField * DocKORRSCHET_DPKO)
{
Object->DocKORRSCHET_DPKO=DocKORRSCHET_DPKO;
}
//---------------------------------------------------------------
bool TDMDocPKOImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocPKOImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocPKOImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMDocPKOImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TDMDocPKOImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
bool TDMDocPKOImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocPKOImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocPKOImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocPKOImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocPKOImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocPKOImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocPKOImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocPKOImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
int TDMDocPKOImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
