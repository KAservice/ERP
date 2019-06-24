#include "vcl.h"
#pragma hdrstop


#include "UDMDocRegOtchetPostImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRegOtchetPostImpl::TDMDocRegOtchetPostImpl()           
{                                            
Object=new TDMDocRegOtchetPost(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRegOtchetPostImpl::~TDMDocRegOtchetPostImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRegOtchetPostImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRegOtchetPost)                        
   {                                                                     
   *ppv=static_cast<IDMDocRegOtchetPost*> (this);                                
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
int TDMDocRegOtchetPostImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRegOtchetPostImpl::kanRelease(void)                                  
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
int  TDMDocRegOtchetPostImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRegOtchetPostImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRegOtchetPostImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRegOtchetPostImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRegOtchetPostImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRegOtchetPost
TDataSource * TDMDocRegOtchetPostImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegOtchetPostImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegOtchetPostImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegOtchetPostImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegOtchetPostImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegOtchetPostImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegOtchetPostImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegOtchetPostImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegOtchetPostImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegOtchetPostImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegOtchetPostImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegOtchetPostImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegOtchetPostImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRegOtchetPostImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegOtchetPostImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegOtchetPostImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegOtchetPostImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRegOtchetPostImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegOtchetPostImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocID_DRG_OTCHPOST(void)
{
return Object->DocID_DRG_OTCHPOST;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocID_DRG_OTCHPOST(TFIBLargeIntField * DocID_DRG_OTCHPOST)
{
Object->DocID_DRG_OTCHPOST=DocID_DRG_OTCHPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocIDBASE_DRG_OTCHPOST(void)
{
return Object->DocIDBASE_DRG_OTCHPOST;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocIDBASE_DRG_OTCHPOST(TFIBLargeIntField * DocIDBASE_DRG_OTCHPOST)
{
Object->DocIDBASE_DRG_OTCHPOST=DocIDBASE_DRG_OTCHPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocIDDOC_DRG_OTCHPOST(void)
{
return Object->DocIDDOC_DRG_OTCHPOST;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocIDDOC_DRG_OTCHPOST(TFIBLargeIntField * DocIDDOC_DRG_OTCHPOST)
{
Object->DocIDDOC_DRG_OTCHPOST=DocIDDOC_DRG_OTCHPOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocDESCR_DRG_OTCHPOST(void)
{
return Object->DocDESCR_DRG_OTCHPOST;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocDESCR_DRG_OTCHPOST(TFIBWideStringField * DocDESCR_DRG_OTCHPOST)
{
Object->DocDESCR_DRG_OTCHPOST=DocDESCR_DRG_OTCHPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocTID_DRG_OTCHPOSTT(void)
{
return Object->DocTID_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTID_DRG_OTCHPOSTT(TFIBLargeIntField * DocTID_DRG_OTCHPOSTT)
{
Object->DocTID_DRG_OTCHPOSTT=DocTID_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocTIDBASE_DRG_OTCHPOSTT(void)
{
return Object->DocTIDBASE_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTIDBASE_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDBASE_DRG_OTCHPOSTT)
{
Object->DocTIDBASE_DRG_OTCHPOSTT=DocTIDBASE_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocTIDDOC_DRG_OTCHPOSTT(void)
{
return Object->DocTIDDOC_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTIDDOC_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDDOC_DRG_OTCHPOSTT)
{
Object->DocTIDDOC_DRG_OTCHPOSTT=DocTIDDOC_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegOtchetPostImpl::get_DocTTDV_DRG_OTCHPOSTT(void)
{
return Object->DocTTDV_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTTDV_DRG_OTCHPOSTT(TFIBSmallIntField * DocTTDV_DRG_OTCHPOSTT)
{
Object->DocTTDV_DRG_OTCHPOSTT=DocTTDV_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocTIDFIRM_DRG_OTCHPOSTT(void)
{
return Object->DocTIDFIRM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTIDFIRM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDFIRM_DRG_OTCHPOSTT)
{
Object->DocTIDFIRM_DRG_OTCHPOSTT=DocTIDFIRM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocTIDSKLAD_DRG_OTCHPOSTT(void)
{
return Object->DocTIDSKLAD_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTIDSKLAD_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDSKLAD_DRG_OTCHPOSTT)
{
Object->DocTIDSKLAD_DRG_OTCHPOSTT=DocTIDSKLAD_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocTIDPOST_DRG_OTCHPOSTT(void)
{
return Object->DocTIDPOST_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTIDPOST_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDPOST_DRG_OTCHPOSTT)
{
Object->DocTIDPOST_DRG_OTCHPOSTT=DocTIDPOST_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocTIDDOCPOST_DRG_OTCHPOSTT(void)
{
return Object->DocTIDDOCPOST_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTIDDOCPOST_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDDOCPOST_DRG_OTCHPOSTT)
{
Object->DocTIDDOCPOST_DRG_OTCHPOSTT=DocTIDDOCPOST_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOtchetPostImpl::get_DocTIDNOM_DRG_OTCHPOSTT(void)
{
return Object->DocTIDNOM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTIDNOM_DRG_OTCHPOSTT(TFIBLargeIntField * DocTIDNOM_DRG_OTCHPOSTT)
{
Object->DocTIDNOM_DRG_OTCHPOSTT=DocTIDNOM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegOtchetPostImpl::get_DocTKOL_DRG_OTCHPOSTT(void)
{
return Object->DocTKOL_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTKOL_DRG_OTCHPOSTT(TFIBBCDField * DocTKOL_DRG_OTCHPOSTT)
{
Object->DocTKOL_DRG_OTCHPOSTT=DocTKOL_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegOtchetPostImpl::get_DocTSUM_DRG_OTCHPOSTT(void)
{
return Object->DocTSUM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTSUM_DRG_OTCHPOSTT(TFIBBCDField * DocTSUM_DRG_OTCHPOSTT)
{
Object->DocTSUM_DRG_OTCHPOSTT=DocTSUM_DRG_OTCHPOSTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocTNAMEFIRM(void)
{
return Object->DocTNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM)
{
Object->DocTNAMEFIRM=DocTNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocTNAMESKLAD(void)
{
return Object->DocTNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTNAMESKLAD(TFIBWideStringField * DocTNAMESKLAD)
{
Object->DocTNAMESKLAD=DocTNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocTPREFIKS_NUM_GALLDOC(void)
{
return Object->DocTPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocTPREFIKS_NUM_GALLDOC)
{
Object->DocTPREFIKS_NUM_GALLDOC=DocTPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegOtchetPostImpl::get_DocTNUMDOC(void)
{
return Object->DocTNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTNUMDOC(TFIBIntegerField * DocTNUMDOC)
{
Object->DocTNUMDOC=DocTNUMDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRegOtchetPostImpl::get_DocTPOSDOC(void)
{
return Object->DocTPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTPOSDOC(TFIBDateTimeField * DocTPOSDOC)
{
Object->DocTPOSDOC=DocTPOSDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegOtchetPostImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOtchetPostImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
__int64 TDMDocRegOtchetPostImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocRegOtchetPostImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocRegOtchetPostImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocRegOtchetPostImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocRegOtchetPostImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRegOtchetPostImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRegOtchetPostImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TDMDocRegOtchetPostImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRegOtchetPostImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TDMDocRegOtchetPostImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
int TDMDocRegOtchetPostImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
