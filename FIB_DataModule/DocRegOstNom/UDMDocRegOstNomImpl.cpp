#include "vcl.h"
#pragma hdrstop


#include "UDMDocRegOstNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRegOstNomImpl::TDMDocRegOstNomImpl()           
{                                            
Object=new TDMDocRegOstNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRegOstNomImpl::~TDMDocRegOstNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRegOstNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRegOstNom)                        
   {                                                                     
   *ppv=static_cast<IDMDocRegOstNom*> (this);                                
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
int TDMDocRegOstNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRegOstNomImpl::kanRelease(void)                                  
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
int  TDMDocRegOstNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRegOstNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRegOstNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRegOstNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRegOstNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRegOstNom
TDataSource * TDMDocRegOstNomImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegOstNomImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegOstNomImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegOstNomImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegOstNomImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegOstNomImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegOstNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegOstNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegOstNomImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegOstNomImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegOstNomImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegOstNomImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegOstNomImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRegOstNomImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegOstNomImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegOstNomImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegOstNomImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRegOstNomImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegOstNomImpl::get_DocTTDV_DRG_OSTNOMT(void)
{
return Object->DocTTDV_DRG_OSTNOMT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTTDV_DRG_OSTNOMT(TFIBSmallIntField * DocTTDV_DRG_OSTNOMT)
{
Object->DocTTDV_DRG_OSTNOMT=DocTTDV_DRG_OSTNOMT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegOstNomImpl::get_DocTKOL_DRG_OSTNOMT(void)
{
return Object->DocTKOL_DRG_OSTNOMT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTKOL_DRG_OSTNOMT(TFIBBCDField * DocTKOL_DRG_OSTNOMT)
{
Object->DocTKOL_DRG_OSTNOMT=DocTKOL_DRG_OSTNOMT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegOstNomImpl::get_DocTSUM_DRG_OSTNOMT(void)
{
return Object->DocTSUM_DRG_OSTNOMT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTSUM_DRG_OSTNOMT(TFIBBCDField * DocTSUM_DRG_OSTNOMT)
{
Object->DocTSUM_DRG_OSTNOMT=DocTSUM_DRG_OSTNOMT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegOstNomImpl::get_DocTOPER_DRG_OSTNOMT(void)
{
return Object->DocTOPER_DRG_OSTNOMT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTOPER_DRG_OSTNOMT(TFIBSmallIntField * DocTOPER_DRG_OSTNOMT)
{
Object->DocTOPER_DRG_OSTNOMT=DocTOPER_DRG_OSTNOMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegOstNomImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocID_DRG_OSTNOM(void)
{
return Object->DocID_DRG_OSTNOM;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocID_DRG_OSTNOM(TFIBLargeIntField * DocID_DRG_OSTNOM)
{
Object->DocID_DRG_OSTNOM=DocID_DRG_OSTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocIDDOC_DRG_OSTNOM(void)
{
return Object->DocIDDOC_DRG_OSTNOM;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocIDDOC_DRG_OSTNOM(TFIBLargeIntField * DocIDDOC_DRG_OSTNOM)
{
Object->DocIDDOC_DRG_OSTNOM=DocIDDOC_DRG_OSTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocDESCR_DRG_OSTNOM(void)
{
return Object->DocDESCR_DRG_OSTNOM;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocDESCR_DRG_OSTNOM(TFIBWideStringField * DocDESCR_DRG_OSTNOM)
{
Object->DocDESCR_DRG_OSTNOM=DocDESCR_DRG_OSTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocIDBASE_DRG_OSTNOM(void)
{
return Object->DocIDBASE_DRG_OSTNOM;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocIDBASE_DRG_OSTNOM(TFIBLargeIntField * DocIDBASE_DRG_OSTNOM)
{
Object->DocIDBASE_DRG_OSTNOM=DocIDBASE_DRG_OSTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocTID_DRG_OSTNOMT(void)
{
return Object->DocTID_DRG_OSTNOMT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTID_DRG_OSTNOMT(TFIBLargeIntField * DocTID_DRG_OSTNOMT)
{
Object->DocTID_DRG_OSTNOMT=DocTID_DRG_OSTNOMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocTIDDOC_DRG_OSTNOMT(void)
{
return Object->DocTIDDOC_DRG_OSTNOMT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTIDDOC_DRG_OSTNOMT(TFIBLargeIntField * DocTIDDOC_DRG_OSTNOMT)
{
Object->DocTIDDOC_DRG_OSTNOMT=DocTIDDOC_DRG_OSTNOMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocTIDFIRM_DRG_OSTNOMT(void)
{
return Object->DocTIDFIRM_DRG_OSTNOMT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTIDFIRM_DRG_OSTNOMT(TFIBLargeIntField * DocTIDFIRM_DRG_OSTNOMT)
{
Object->DocTIDFIRM_DRG_OSTNOMT=DocTIDFIRM_DRG_OSTNOMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocTIDSKLAD_DRG_OSTNOMT(void)
{
return Object->DocTIDSKLAD_DRG_OSTNOMT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTIDSKLAD_DRG_OSTNOMT(TFIBLargeIntField * DocTIDSKLAD_DRG_OSTNOMT)
{
Object->DocTIDSKLAD_DRG_OSTNOMT=DocTIDSKLAD_DRG_OSTNOMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocTIDNOM_DRG_OSTNOMT(void)
{
return Object->DocTIDNOM_DRG_OSTNOMT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTIDNOM_DRG_OSTNOMT(TFIBLargeIntField * DocTIDNOM_DRG_OSTNOMT)
{
Object->DocTIDNOM_DRG_OSTNOMT=DocTIDNOM_DRG_OSTNOMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocTIDPART_DRG_OSTNOMT(void)
{
return Object->DocTIDPART_DRG_OSTNOMT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTIDPART_DRG_OSTNOMT(TFIBLargeIntField * DocTIDPART_DRG_OSTNOMT)
{
Object->DocTIDPART_DRG_OSTNOMT=DocTIDPART_DRG_OSTNOMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocTIDBASE_DRG_OSTNOMT(void)
{
return Object->DocTIDBASE_DRG_OSTNOMT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTIDBASE_DRG_OSTNOMT(TFIBLargeIntField * DocTIDBASE_DRG_OSTNOMT)
{
Object->DocTIDBASE_DRG_OSTNOMT=DocTIDBASE_DRG_OSTNOMT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocTNAMEFIRM(void)
{
return Object->DocTNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM)
{
Object->DocTNAMEFIRM=DocTNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocTNAMESKLAD(void)
{
return Object->DocTNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTNAMESKLAD(TFIBWideStringField * DocTNAMESKLAD)
{
Object->DocTNAMESKLAD=DocTNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocTDOCPART(void)
{
return Object->DocTDOCPART;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocTDOCPART(TFIBWideStringField * DocTDOCPART)
{
Object->DocTDOCPART=DocTDOCPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegOstNomImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegOstNomImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
__int64 TDMDocRegOstNomImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocRegOstNomImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocRegOstNomImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocRegOstNomImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocRegOstNomImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRegOstNomImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRegOstNomImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TDMDocRegOstNomImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRegOstNomImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TDMDocRegOstNomImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
int TDMDocRegOstNomImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
