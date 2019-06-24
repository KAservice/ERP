#include "vcl.h"
#pragma hdrstop


#include "UDMDocRKOImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRKOImpl::TDMDocRKOImpl()           
{                                            
Object=new TDMDocRKO(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRKOImpl::~TDMDocRKOImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRKOImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRKOImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRKO)                        
   {                                                                     
   *ppv=static_cast<IDMDocRKO*> (this);                                
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
int TDMDocRKOImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRKOImpl::kanRelease(void)                                  
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
int  TDMDocRKOImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRKOImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRKOImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRKOImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRKOImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRKOImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRKOImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRKO
TDataSource * TDMDocRKOImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRKOImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRKOImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRKOImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRKOImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRKOImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRKOImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRKOImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRKOImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRKOImpl::get_DocADDKDRRKO(void)
{
return Object->DocADDKDRRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocADDKDRRKO(TFIBSmallIntField * DocADDKDRRKO)
{
Object->DocADDKDRRKO=DocADDKDRRKO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocSUMUSNRKO(void)
{
return Object->DocSUMUSNRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocSUMUSNRKO(TFIBBCDField * DocSUMUSNRKO)
{
Object->DocSUMUSNRKO=DocSUMUSNRKO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRKOImpl::get_DocOPERATIONRKO(void)
{
return Object->DocOPERATIONRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocOPERATIONRKO(TFIBSmallIntField * DocOPERATIONRKO)
{
Object->DocOPERATIONRKO=DocOPERATIONRKO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRKOImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRKOImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRKOImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRKOImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllIDDOC(TFIBBCDField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllIDFIRMDOC(TFIBBCDField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllIDSKLDOC(TFIBBCDField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllIDKLDOC(TFIBBCDField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllIDDOGDOC(TFIBBCDField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllIDDOCOSNDOC(TFIBBCDField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocIDRKO(void)
{
return Object->DocIDRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocIDRKO(TFIBBCDField * DocIDRKO)
{
Object->DocIDRKO=DocIDRKO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocIDDOCRKO(void)
{
return Object->DocIDDOCRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocIDDOCRKO(TFIBBCDField * DocIDDOCRKO)
{
Object->DocIDDOCRKO=DocIDDOCRKO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocIDKKMRKO(void)
{
return Object->DocIDKKMRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocIDKKMRKO(TFIBBCDField * DocIDKKMRKO)
{
Object->DocIDKKMRKO=DocIDKKMRKO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocIDKLRKO(void)
{
return Object->DocIDKLRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocIDKLRKO(TFIBBCDField * DocIDKLRKO)
{
Object->DocIDKLRKO=DocIDKLRKO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocIDBASE_DRKO(void)
{
return Object->DocIDBASE_DRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocIDBASE_DRKO(TFIBBCDField * DocIDBASE_DRKO)
{
Object->DocIDBASE_DRKO=DocIDBASE_DRKO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRKOImpl::get_DocNDS_DRKO(void)
{
return Object->DocNDS_DRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocNDS_DRKO(TFIBIntegerField * DocNDS_DRKO)
{
Object->DocNDS_DRKO=DocNDS_DRKO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocSUMNDS_DRKO(void)
{
return Object->DocSUMNDS_DRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocSUMNDS_DRKO(TFIBBCDField * DocSUMNDS_DRKO)
{
Object->DocSUMNDS_DRKO=DocSUMNDS_DRKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocVIDATRKO(void)
{
return Object->DocVIDATRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocVIDATRKO(TFIBWideStringField * DocVIDATRKO)
{
Object->DocVIDATRKO=DocVIDATRKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocOSNRKO(void)
{
return Object->DocOSNRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocOSNRKO(TFIBWideStringField * DocOSNRKO)
{
Object->DocOSNRKO=DocOSNRKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocPRILRKO(void)
{
return Object->DocPRILRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocPRILRKO(TFIBWideStringField * DocPRILRKO)
{
Object->DocPRILRKO=DocPRILRKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocDOCPOLRKO(void)
{
return Object->DocDOCPOLRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocDOCPOLRKO(TFIBWideStringField * DocDOCPOLRKO)
{
Object->DocDOCPOLRKO=DocDOCPOLRKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocGID_DRKO(void)
{
return Object->DocGID_DRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocGID_DRKO(TFIBWideStringField * DocGID_DRKO)
{
Object->DocGID_DRKO=DocGID_DRKO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRKOImpl::get_DocNKLRKO(void)
{
return Object->DocNKLRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocNKLRKO(TFIBIntegerField * DocNKLRKO)
{
Object->DocNKLRKO=DocNKLRKO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRKOImpl::get_DocNCHECKRKO(void)
{
return Object->DocNCHECKRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocNCHECKRKO(TFIBIntegerField * DocNCHECKRKO)
{
Object->DocNCHECKRKO=DocNCHECKRKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocMODELRKO(void)
{
return Object->DocMODELRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocMODELRKO(TFIBWideStringField * DocMODELRKO)
{
Object->DocMODELRKO=DocMODELRKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocREGNUMRKO(void)
{
return Object->DocREGNUMRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocREGNUMRKO(TFIBWideStringField * DocREGNUMRKO)
{
Object->DocREGNUMRKO=DocREGNUMRKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocSAVNUMRKO(void)
{
return Object->DocSAVNUMRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocSAVNUMRKO(TFIBWideStringField * DocSAVNUMRKO)
{
Object->DocSAVNUMRKO=DocSAVNUMRKO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocNAMEKKM(void)
{
return Object->DocNAMEKKM;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM)
{
Object->DocNAMEKKM=DocNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRKOImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllIDPROJECT_GALLDOC(TFIBBCDField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRKOImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBBCDField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRKOImpl::get_DocKORRSCHET_DRKO(void)
{
return Object->DocKORRSCHET_DRKO;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_DocKORRSCHET_DRKO(TFIBWideStringField * DocKORRSCHET_DRKO)
{
Object->DocKORRSCHET_DRKO=DocKORRSCHET_DRKO;
}
//---------------------------------------------------------------
bool TDMDocRKOImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocRKOImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocRKOImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocRKOImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRKOImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocRKOImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRKOImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRKOImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRKOImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRKOImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocRKOImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
int TDMDocRKOImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
