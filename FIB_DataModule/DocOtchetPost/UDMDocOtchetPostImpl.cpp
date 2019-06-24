#include "vcl.h"
#pragma hdrstop


#include "UDMDocOtchetPostImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocOtchetPostImpl::TDMDocOtchetPostImpl()           
{                                            
Object=new TDMDocOtchetPost(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocOtchetPostImpl::~TDMDocOtchetPostImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocOtchetPostImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocOtchetPost)                        
   {                                                                     
   *ppv=static_cast<IDMDocOtchetPost*> (this);                                
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
int TDMDocOtchetPostImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocOtchetPostImpl::kanRelease(void)                                  
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
int  TDMDocOtchetPostImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocOtchetPostImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocOtchetPostImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocOtchetPostImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocOtchetPostImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocOtchetPost
TDataSource * TDMDocOtchetPostImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocOtchetPostImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocOtchetPostImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOtchetPostImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOtchetPostImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOtchetPostImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocOtchetPostImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocOtchetPostImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocOtchetPostImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocOtchetPostImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocOtchetPostImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOtchetPostImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TIntegerField * TDMDocOtchetPostImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocOtchetPostImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOtchetPostImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocOtchetPostImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocOtchetPostImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocOtchetPostImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocOtchetPostImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocID_DOTCHPOST(void)
{
return Object->DocID_DOTCHPOST;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocID_DOTCHPOST(TFIBLargeIntField * DocID_DOTCHPOST)
{
Object->DocID_DOTCHPOST=DocID_DOTCHPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocIDBASE_DOTCHPOST(void)
{
return Object->DocIDBASE_DOTCHPOST;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocIDBASE_DOTCHPOST(TFIBLargeIntField * DocIDBASE_DOTCHPOST)
{
Object->DocIDBASE_DOTCHPOST=DocIDBASE_DOTCHPOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocGID_DOTCHPOST(void)
{
return Object->DocGID_DOTCHPOST;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocGID_DOTCHPOST(TFIBWideStringField * DocGID_DOTCHPOST)
{
Object->DocGID_DOTCHPOST=DocGID_DOTCHPOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocPRIM_DOTCHPOST(void)
{
return Object->DocPRIM_DOTCHPOST;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocPRIM_DOTCHPOST(TFIBWideStringField * DocPRIM_DOTCHPOST)
{
Object->DocPRIM_DOTCHPOST=DocPRIM_DOTCHPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocIDDOC_DOTCHPOST(void)
{
return Object->DocIDDOC_DOTCHPOST;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocIDDOC_DOTCHPOST(TFIBLargeIntField * DocIDDOC_DOTCHPOST)
{
Object->DocIDDOC_DOTCHPOST=DocIDDOC_DOTCHPOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocTID_DOTCHPOSTT(void)
{
return Object->DocTID_DOTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTID_DOTCHPOSTT(TFIBLargeIntField * DocTID_DOTCHPOSTT)
{
Object->DocTID_DOTCHPOSTT=DocTID_DOTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocTIDBASE_DOTCHPOSTT(void)
{
return Object->DocTIDBASE_DOTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTIDBASE_DOTCHPOSTT(TFIBLargeIntField * DocTIDBASE_DOTCHPOSTT)
{
Object->DocTIDBASE_DOTCHPOSTT=DocTIDBASE_DOTCHPOSTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocTGID_DOTCHPOSTT(void)
{
return Object->DocTGID_DOTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTGID_DOTCHPOSTT(TFIBWideStringField * DocTGID_DOTCHPOSTT)
{
Object->DocTGID_DOTCHPOSTT=DocTGID_DOTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocTIDDOC_DOTCHPOSTT(void)
{
return Object->DocTIDDOC_DOTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTIDDOC_DOTCHPOSTT(TFIBLargeIntField * DocTIDDOC_DOTCHPOSTT)
{
Object->DocTIDDOC_DOTCHPOSTT=DocTIDDOC_DOTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocTIDNOM_DOTCHPOSTT(void)
{
return Object->DocTIDNOM_DOTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTIDNOM_DOTCHPOSTT(TFIBLargeIntField * DocTIDNOM_DOTCHPOSTT)
{
Object->DocTIDNOM_DOTCHPOSTT=DocTIDNOM_DOTCHPOSTT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocTIDED_DOTCHPOSTT(void)
{
return Object->DocTIDED_DOTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTIDED_DOTCHPOSTT(TFIBLargeIntField * DocTIDED_DOTCHPOSTT)
{
Object->DocTIDED_DOTCHPOSTT=DocTIDED_DOTCHPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOtchetPostImpl::get_DocTKOL_DOTCHPOSTT(void)
{
return Object->DocTKOL_DOTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTKOL_DOTCHPOSTT(TFIBBCDField * DocTKOL_DOTCHPOSTT)
{
Object->DocTKOL_DOTCHPOSTT=DocTKOL_DOTCHPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOtchetPostImpl::get_DocTKF_DOTCHPOSTT(void)
{
return Object->DocTKF_DOTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTKF_DOTCHPOSTT(TFIBBCDField * DocTKF_DOTCHPOSTT)
{
Object->DocTKF_DOTCHPOSTT=DocTKF_DOTCHPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOtchetPostImpl::get_DocTPRICE_DOTCHPOSTT(void)
{
return Object->DocTPRICE_DOTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTPRICE_DOTCHPOSTT(TFIBBCDField * DocTPRICE_DOTCHPOSTT)
{
Object->DocTPRICE_DOTCHPOSTT=DocTPRICE_DOTCHPOSTT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOtchetPostImpl::get_DocTSUM_DOTCHPOSTT(void)
{
return Object->DocTSUM_DOTCHPOSTT;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTSUM_DOTCHPOSTT(TFIBBCDField * DocTSUM_DOTCHPOSTT)
{
Object->DocTSUM_DOTCHPOSTT=DocTSUM_DOTCHPOSTT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocOtchetPostImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTTNOM(TFIBSmallIntField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocOtchetPostImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOtchetPostImpl::get_DocIDTPRICE_DOTCHPOST(void)
{
return Object->DocIDTPRICE_DOTCHPOST;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocIDTPRICE_DOTCHPOST(TFIBLargeIntField * DocIDTPRICE_DOTCHPOST)
{
Object->DocIDTPRICE_DOTCHPOST=DocIDTPRICE_DOTCHPOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOtchetPostImpl::get_DocNAME_TPRICE(void)
{
return Object->DocNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)
{
Object->DocNAME_TPRICE=DocNAME_TPRICE;
}
//---------------------------------------------------------------
bool TDMDocOtchetPostImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocOtchetPostImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMDocOtchetPostImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TDMDocOtchetPostImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
__int64 TDMDocOtchetPostImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
bool TDMDocOtchetPostImpl::get_IsmPrice(void)
{
return Object->IsmPrice;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_IsmPrice(bool IsmPrice)
{
Object->IsmPrice=IsmPrice;
}
//---------------------------------------------------------------
bool TDMDocOtchetPostImpl::get_IsmSum(void)
{
return Object->IsmSum;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_IsmSum(bool IsmSum)
{
Object->IsmSum=IsmSum;
}
//---------------------------------------------------------------
bool TDMDocOtchetPostImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocOtchetPostImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::CopyDoc(__int64 id_doc)
{
return Object->CopyDoc(id_doc);
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TDMDocOtchetPostImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocOtchetPostImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocOtchetPostImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocOtchetPostImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TDMDocOtchetPostImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
double TDMDocOtchetPostImpl::Summa(void)
{
return Object->Summa();
}
//---------------------------------------------------------------
__int64 TDMDocOtchetPostImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc, date_doc);
}
//---------------------------------------------------------------
bool TDMDocOtchetPostImpl::UpdatePrice(void)
{
return Object->UpdatePrice();
}
//---------------------------------------------------------------
int TDMDocOtchetPostImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
