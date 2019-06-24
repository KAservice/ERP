#include "vcl.h"
#pragma hdrstop


#include "UDMDocVosvratPostImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocVosvratPostImpl::TDMDocVosvratPostImpl()           
{                                            
Object=new TDMDocVosvratPost(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocVosvratPostImpl::~TDMDocVosvratPostImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocVosvratPostImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocVosvratPost)                        
   {                                                                     
   *ppv=static_cast<IDMDocVosvratPost*> (this);                                
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
int TDMDocVosvratPostImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocVosvratPostImpl::kanRelease(void)                                  
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
int  TDMDocVosvratPostImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocVosvratPostImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocVosvratPostImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocVosvratPostImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocVosvratPostImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocVosvratPost
TDataSource * TDMDocVosvratPostImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocVosvratPostImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocVosvratPostImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVosvratPostImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVosvratPostImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVosvratPostImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocVosvratPostImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocVosvratPostImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMDocVosvratPostImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVosvratPostImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocVosvratPostImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocVosvratPostImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocVosvratPostImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocVosvratPostImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocVosvratPostImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVosvratPostImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPostImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVosvratPostImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocAllTDOC_OSN(void)
{
return Object->DocAllTDOC_OSN;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllTDOC_OSN(TFIBWideStringField * DocAllTDOC_OSN)
{
Object->DocAllTDOC_OSN=DocAllTDOC_OSN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVosvratPostImpl::get_DocAllNUMDOC_OSN(void)
{
return Object->DocAllNUMDOC_OSN;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllNUMDOC_OSN(TFIBIntegerField * DocAllNUMDOC_OSN)
{
Object->DocAllNUMDOC_OSN=DocAllNUMDOC_OSN;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocVosvratPostImpl::get_DocAllPOSDOC_OSN(void)
{
return Object->DocAllPOSDOC_OSN;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllPOSDOC_OSN(TFIBDateTimeField * DocAllPOSDOC_OSN)
{
Object->DocAllPOSDOC_OSN=DocAllPOSDOC_OSN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocIDVPO(void)
{
return Object->DocIDVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocIDVPO(TFIBLargeIntField * DocIDVPO)
{
Object->DocIDVPO=DocIDVPO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocIDDOCVPO(void)
{
return Object->DocIDDOCVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocIDDOCVPO(TFIBLargeIntField * DocIDDOCVPO)
{
Object->DocIDDOCVPO=DocIDDOCVPO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocPRIMVPO(void)
{
return Object->DocPRIMVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocPRIMVPO(TFIBWideStringField * DocPRIMVPO)
{
Object->DocPRIMVPO=DocPRIMVPO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocGID_DVPO(void)
{
return Object->DocGID_DVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocGID_DVPO(TFIBWideStringField * DocGID_DVPO)
{
Object->DocGID_DVPO=DocGID_DVPO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocIDTPRICE_DVPO(void)
{
return Object->DocIDTPRICE_DVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocIDTPRICE_DVPO(TFIBLargeIntField * DocIDTPRICE_DVPO)
{
Object->DocIDTPRICE_DVPO=DocIDTPRICE_DVPO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocIDBASE_DVPO(void)
{
return Object->DocIDBASE_DVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocIDBASE_DVPO(TFIBLargeIntField * DocIDBASE_DVPO)
{
Object->DocIDBASE_DVPO=DocIDBASE_DVPO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocIDRTPRICE_DVPO(void)
{
return Object->DocIDRTPRICE_DVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocIDRTPRICE_DVPO(TFIBLargeIntField * DocIDRTPRICE_DVPO)
{
Object->DocIDRTPRICE_DVPO=DocIDRTPRICE_DVPO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVosvratPostImpl::get_DocOPER_DVPO(void)
{
return Object->DocOPER_DVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocOPER_DVPO(TFIBIntegerField * DocOPER_DVPO)
{
Object->DocOPER_DVPO=DocOPER_DVPO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocNUMDOCPOST_DVPO(void)
{
return Object->DocNUMDOCPOST_DVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocNUMDOCPOST_DVPO(TFIBWideStringField * DocNUMDOCPOST_DVPO)
{
Object->DocNUMDOCPOST_DVPO=DocNUMDOCPOST_DVPO;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocVosvratPostImpl::get_DocPOSDOCPOST_DVPO(void)
{
return Object->DocPOSDOCPOST_DVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocPOSDOCPOST_DVPO(TFIBDateTimeField * DocPOSDOCPOST_DVPO)
{
Object->DocPOSDOCPOST_DVPO=DocPOSDOCPOST_DVPO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocNAME_TPRICE(void)
{
return Object->DocNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)
{
Object->DocNAME_TPRICE=DocNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocTIDVPOT(void)
{
return Object->DocTIDVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTIDVPOT(TFIBLargeIntField * DocTIDVPOT)
{
Object->DocTIDVPOT=DocTIDVPOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocTIDDOCVPOT(void)
{
return Object->DocTIDDOCVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTIDDOCVPOT(TFIBLargeIntField * DocTIDDOCVPOT)
{
Object->DocTIDDOCVPOT=DocTIDDOCVPOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocTIDNOMVPOT(void)
{
return Object->DocTIDNOMVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTIDNOMVPOT(TFIBLargeIntField * DocTIDNOMVPOT)
{
Object->DocTIDNOMVPOT=DocTIDNOMVPOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocTIDEDVPOT(void)
{
return Object->DocTIDEDVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTIDEDVPOT(TFIBLargeIntField * DocTIDEDVPOT)
{
Object->DocTIDEDVPOT=DocTIDEDVPOT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPostImpl::get_DocTKOLVPOT(void)
{
return Object->DocTKOLVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTKOLVPOT(TFIBBCDField * DocTKOLVPOT)
{
Object->DocTKOLVPOT=DocTKOLVPOT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPostImpl::get_DocTKFVPOT(void)
{
return Object->DocTKFVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTKFVPOT(TFIBBCDField * DocTKFVPOT)
{
Object->DocTKFVPOT=DocTKFVPOT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPostImpl::get_DocTPRICEVPOT(void)
{
return Object->DocTPRICEVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTPRICEVPOT(TFIBBCDField * DocTPRICEVPOT)
{
Object->DocTPRICEVPOT=DocTPRICEVPOT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPostImpl::get_DocTSUMVPOT(void)
{
return Object->DocTSUMVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTSUMVPOT(TFIBBCDField * DocTSUMVPOT)
{
Object->DocTSUMVPOT=DocTSUMVPOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocTGID_DVPOT(void)
{
return Object->DocTGID_DVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTGID_DVPOT(TFIBWideStringField * DocTGID_DVPOT)
{
Object->DocTGID_DVPOT=DocTGID_DVPOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocTIDBASE_DVPOT(void)
{
return Object->DocTIDBASE_DVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTIDBASE_DVPOT(TFIBLargeIntField * DocTIDBASE_DVPOT)
{
Object->DocTIDBASE_DVPOT=DocTIDBASE_DVPOT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPostImpl::get_DocTRPRICE_DVPOT(void)
{
return Object->DocTRPRICE_DVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTRPRICE_DVPOT(TFIBBCDField * DocTRPRICE_DVPOT)
{
Object->DocTRPRICE_DVPOT=DocTRPRICE_DVPOT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPostImpl::get_DocTRSUM_DVPOT(void)
{
return Object->DocTRSUM_DVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTRSUM_DVPOT(TFIBBCDField * DocTRSUM_DVPOT)
{
Object->DocTRSUM_DVPOT=DocTRSUM_DVPOT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVosvratPostImpl::get_DocTNDS_DVPOT(void)
{
return Object->DocTNDS_DVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTNDS_DVPOT(TFIBIntegerField * DocTNDS_DVPOT)
{
Object->DocTNDS_DVPOT=DocTNDS_DVPOT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPostImpl::get_DocTSUMNDS_DVPOT(void)
{
return Object->DocTSUMNDS_DVPOT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTSUMNDS_DVPOT(TFIBBCDField * DocTSUMNDS_DVPOT)
{
Object->DocTSUMNDS_DVPOT=DocTSUMNDS_DVPOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocVosvratPostImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTTNOM(TFIBSmallIntField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocIDGRPOL_DVPO(void)
{
return Object->DocIDGRPOL_DVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocIDGRPOL_DVPO(TFIBLargeIntField * DocIDGRPOL_DVPO)
{
Object->DocIDGRPOL_DVPO=DocIDGRPOL_DVPO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocIDBSCHET_DVPO(void)
{
return Object->DocIDBSCHET_DVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocIDBSCHET_DVPO(TFIBLargeIntField * DocIDBSCHET_DVPO)
{
Object->DocIDBSCHET_DVPO=DocIDBSCHET_DVPO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocIDRSCHETKLIENT_DVPO(void)
{
return Object->DocIDRSCHETKLIENT_DVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocIDRSCHETKLIENT_DVPO(TFIBLargeIntField * DocIDRSCHETKLIENT_DVPO)
{
Object->DocIDRSCHETKLIENT_DVPO=DocIDRSCHETKLIENT_DVPO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPostImpl::get_DocIDRSCHETGRPOL_DVPO(void)
{
return Object->DocIDRSCHETGRPOL_DVPO;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocIDRSCHETGRPOL_DVPO(TFIBLargeIntField * DocIDRSCHETGRPOL_DVPO)
{
Object->DocIDRSCHETGRPOL_DVPO=DocIDRSCHETGRPOL_DVPO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocNAMEKLIENT(void)
{
return Object->DocNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT)
{
Object->DocNAMEKLIENT=DocNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocNAMEBSCHET(void)
{
return Object->DocNAMEBSCHET;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)
{
Object->DocNAMEBSCHET=DocNAMEBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocNAME_RSCHET_KLIENT(void)
{
return Object->DocNAME_RSCHET_KLIENT;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocNAME_RSCHET_KLIENT(TFIBWideStringField * DocNAME_RSCHET_KLIENT)
{
Object->DocNAME_RSCHET_KLIENT=DocNAME_RSCHET_KLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocNAME_RSCHET_GRPOL(void)
{
return Object->DocNAME_RSCHET_GRPOL;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocNAME_RSCHET_GRPOL(TFIBWideStringField * DocNAME_RSCHET_GRPOL)
{
Object->DocNAME_RSCHET_GRPOL=DocNAME_RSCHET_GRPOL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVosvratPostImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPostImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
bool TDMDocVosvratPostImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocVosvratPostImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocVosvratPostImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocVosvratPostImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocVosvratPostImpl::get_NoOtrOstatok(void)
{
return Object->NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_NoOtrOstatok(bool NoOtrOstatok)
{
Object->NoOtrOstatok=NoOtrOstatok;
}
//---------------------------------------------------------------
bool TDMDocVosvratPostImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocVosvratPostImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocVosvratPostImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocVosvratPostImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
void TDMDocVosvratPostImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocVosvratPostImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
int TDMDocVosvratPostImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
