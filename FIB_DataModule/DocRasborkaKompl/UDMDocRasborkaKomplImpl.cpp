#include "vcl.h"
#pragma hdrstop


#include "UDMDocRasborkaKomplImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRasborkaKomplImpl::TDMDocRasborkaKomplImpl()           
{                                            
Object=new TDMDocRasborkaKompl(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRasborkaKomplImpl::~TDMDocRasborkaKomplImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRasborkaKomplImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRasborkaKompl)                        
   {                                                                     
   *ppv=static_cast<IDMDocRasborkaKompl*> (this);                                
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
int TDMDocRasborkaKomplImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRasborkaKomplImpl::kanRelease(void)                                  
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
int  TDMDocRasborkaKomplImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRasborkaKomplImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRasborkaKomplImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRasborkaKomplImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRasborkaKomplImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRasborkaKompl
TDataSource * TDMDocRasborkaKomplImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRasborkaKomplImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocRasborkaKomplImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRasborkaKomplImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRasborkaKomplImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRasborkaKomplImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRasborkaKomplImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRasborkaKomplImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRasborkaKomplImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRasborkaKomplImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRasborkaKomplImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRasborkaKomplImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRasborkaKomplImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRasborkaKomplImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRasborkaKomplImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRasborkaKomplImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRasborkaKomplImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRasborkaKomplImpl::get_DocKF_DRASBKOMPL(void)
{
return Object->DocKF_DRASBKOMPL;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocKF_DRASBKOMPL(TFIBBCDField * DocKF_DRASBKOMPL)
{
Object->DocKF_DRASBKOMPL=DocKF_DRASBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRasborkaKomplImpl::get_DocKOL_DRASBKOMPL(void)
{
return Object->DocKOL_DRASBKOMPL;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocKOL_DRASBKOMPL(TFIBBCDField * DocKOL_DRASBKOMPL)
{
Object->DocKOL_DRASBKOMPL=DocKOL_DRASBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRasborkaKomplImpl::get_DocRPRICE_DRASBKOMPL(void)
{
return Object->DocRPRICE_DRASBKOMPL;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocRPRICE_DRASBKOMPL(TFIBBCDField * DocRPRICE_DRASBKOMPL)
{
Object->DocRPRICE_DRASBKOMPL=DocRPRICE_DRASBKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRasborkaKomplImpl::get_DocTKF_DRASBKOMPLT(void)
{
return Object->DocTKF_DRASBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTKF_DRASBKOMPLT(TFIBBCDField * DocTKF_DRASBKOMPLT)
{
Object->DocTKF_DRASBKOMPLT=DocTKF_DRASBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRasborkaKomplImpl::get_DocTKOL_DRASBKOMPLT(void)
{
return Object->DocTKOL_DRASBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTKOL_DRASBKOMPLT(TFIBBCDField * DocTKOL_DRASBKOMPLT)
{
Object->DocTKOL_DRASBKOMPLT=DocTKOL_DRASBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRasborkaKomplImpl::get_DocTRPRICE_DRASBKOMPLT(void)
{
return Object->DocTRPRICE_DRASBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTRPRICE_DRASBKOMPLT(TFIBBCDField * DocTRPRICE_DRASBKOMPLT)
{
Object->DocTRPRICE_DRASBKOMPLT=DocTRPRICE_DRASBKOMPLT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRasborkaKomplImpl::get_DocTRSUM_DRASBKOMPLT(void)
{
return Object->DocTRSUM_DRASBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTRSUM_DRASBKOMPLT(TFIBBCDField * DocTRSUM_DRASBKOMPLT)
{
Object->DocTRSUM_DRASBKOMPLT=DocTRSUM_DRASBKOMPLT;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRasborkaKomplImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRasborkaKomplImpl::get_DocTKFSEB_DRASBKOMPLT(void)
{
return Object->DocTKFSEB_DRASBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTKFSEB_DRASBKOMPLT(TFIBBCDField * DocTKFSEB_DRASBKOMPLT)
{
Object->DocTKFSEB_DRASBKOMPLT=DocTKFSEB_DRASBKOMPLT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRasborkaKomplImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocID_DRASBKOMPL(void)
{
return Object->DocID_DRASBKOMPL;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocID_DRASBKOMPL(TFIBLargeIntField * DocID_DRASBKOMPL)
{
Object->DocID_DRASBKOMPL=DocID_DRASBKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocIDBASE_DRASBKOMPL(void)
{
return Object->DocIDBASE_DRASBKOMPL;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocIDBASE_DRASBKOMPL(TFIBLargeIntField * DocIDBASE_DRASBKOMPL)
{
Object->DocIDBASE_DRASBKOMPL=DocIDBASE_DRASBKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocIDDOC_DRASBKOMPL(void)
{
return Object->DocIDDOC_DRASBKOMPL;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocIDDOC_DRASBKOMPL(TFIBLargeIntField * DocIDDOC_DRASBKOMPL)
{
Object->DocIDDOC_DRASBKOMPL=DocIDDOC_DRASBKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocIDNOM_DRASBKOMPL(void)
{
return Object->DocIDNOM_DRASBKOMPL;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocIDNOM_DRASBKOMPL(TFIBLargeIntField * DocIDNOM_DRASBKOMPL)
{
Object->DocIDNOM_DRASBKOMPL=DocIDNOM_DRASBKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocIDED_DRASBKOMPL(void)
{
return Object->DocIDED_DRASBKOMPL;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocIDED_DRASBKOMPL(TFIBLargeIntField * DocIDED_DRASBKOMPL)
{
Object->DocIDED_DRASBKOMPL=DocIDED_DRASBKOMPL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocDESCR_DRASBKOMPL(void)
{
return Object->DocDESCR_DRASBKOMPL;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocDESCR_DRASBKOMPL(TFIBWideStringField * DocDESCR_DRASBKOMPL)
{
Object->DocDESCR_DRASBKOMPL=DocDESCR_DRASBKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocIDRTPRICE_DRASBKOMPL(void)
{
return Object->DocIDRTPRICE_DRASBKOMPL;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocIDRTPRICE_DRASBKOMPL(TFIBLargeIntField * DocIDRTPRICE_DRASBKOMPL)
{
Object->DocIDRTPRICE_DRASBKOMPL=DocIDRTPRICE_DRASBKOMPL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocNAMENOM(void)
{
return Object->DocNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocNAMENOM(TFIBWideStringField * DocNAMENOM)
{
Object->DocNAMENOM=DocNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocNAMEED(void)
{
return Object->DocNAMEED;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocNAMEED(TFIBWideStringField * DocNAMEED)
{
Object->DocNAMEED=DocNAMEED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocTID_DRASBKOMPLT(void)
{
return Object->DocTID_DRASBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTID_DRASBKOMPLT(TFIBLargeIntField * DocTID_DRASBKOMPLT)
{
Object->DocTID_DRASBKOMPLT=DocTID_DRASBKOMPLT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocTIDBASE_DRASBKOMPLT(void)
{
return Object->DocTIDBASE_DRASBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTIDBASE_DRASBKOMPLT(TFIBLargeIntField * DocTIDBASE_DRASBKOMPLT)
{
Object->DocTIDBASE_DRASBKOMPLT=DocTIDBASE_DRASBKOMPLT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocTIDDOC_DRASBKOMPLT(void)
{
return Object->DocTIDDOC_DRASBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTIDDOC_DRASBKOMPLT(TFIBLargeIntField * DocTIDDOC_DRASBKOMPLT)
{
Object->DocTIDDOC_DRASBKOMPLT=DocTIDDOC_DRASBKOMPLT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocTIDNOM_DRASBKOMPLT(void)
{
return Object->DocTIDNOM_DRASBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTIDNOM_DRASBKOMPLT(TFIBLargeIntField * DocTIDNOM_DRASBKOMPLT)
{
Object->DocTIDNOM_DRASBKOMPLT=DocTIDNOM_DRASBKOMPLT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocTIDED_DRASBKOMPLT(void)
{
return Object->DocTIDED_DRASBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTIDED_DRASBKOMPLT(TFIBLargeIntField * DocTIDED_DRASBKOMPLT)
{
Object->DocTIDED_DRASBKOMPLT=DocTIDED_DRASBKOMPLT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocTIDPART_DRASBKOMPLT(void)
{
return Object->DocTIDPART_DRASBKOMPLT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTIDPART_DRASBKOMPLT(TFIBLargeIntField * DocTIDPART_DRASBKOMPLT)
{
Object->DocTIDPART_DRASBKOMPLT=DocTIDPART_DRASBKOMPLT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRasborkaKomplImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRasborkaKomplImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRasborkaKomplImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
__int64 TDMDocRasborkaKomplImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocRasborkaKomplImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocRasborkaKomplImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocRasborkaKomplImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocRasborkaKomplImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocRasborkaKomplImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRasborkaKomplImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRasborkaKomplImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TDMDocRasborkaKomplImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRasborkaKomplImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TDMDocRasborkaKomplImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
__int64 TDMDocRasborkaKomplImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc, date_doc);
}
//---------------------------------------------------------------
int TDMDocRasborkaKomplImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
